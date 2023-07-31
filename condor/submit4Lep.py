import os

from metis.Sample import DirectorySample, DBSSample
from metis.LocalMergeTask import LocalMergeTask
from metis.CondorTask import CondorTask
from metis.StatsParser import StatsParser
import argparse
import glob

from time import sleep
import sys

#condorpath = os.path.dirname(os.path.realpath(__file__))
condorpath = os.environ["condorPath"]

print("Condor path: ")
print(condorpath)

# Avoid spamming too many short jobs to condor
# Less dileptn pairs = faster = more input files per job
def split_func(dsname):
    if "Run201" in dsname:
        return 7
    else:
        return 1
    # TODO: To be implemented later
    # if any(x in dsname for x in [
    #     "/W","/Z","/TTJets","/DY","/ST",
    #     ]):
    #     return 5
    # elif "Run201" in dsname:
    #     return 7
    # else:
    #     return 2

if __name__ == "__main__":

    parser = argparse.ArgumentParser(description="Submit jobs for VVV analysis")
    parser.add_argument('-t' , '--thetag' , dest='thetag' , help='tag' , type=str, required=True)
    # Argument parser
    args = parser.parse_args()
    
    sample_map = {}

    #sample_list = glob.glob("/ceph/cms/store/user/kdownham/skimOutput/WWZ_4L/*")  # this currently points towards running over all skimmed samples 
    print("Samples that are currently being run on: ")
    #sample_list = glob.glob("/ceph/cms/store/user/kdownham/skimOutput/test_2/*")
    sample_list = glob.glob(os.environ["skimDir"]+"/WWZJets*") # change the "*" to the sample names that you want to run over (currently runs over all skimmed samples)
    for sample in sample_list:
        sample_map[DirectorySample( location=sample, dataset="/"+os.path.basename(sample))] = os.path.basename(sample)
	print(sample)

    # submission tag
    tag = args.thetag 

    # Where the merged output will go
    merged_dir = "{}/../vvvtree/{}".format(condorpath, tag)


    # Task summary for printing out msummary
    task_summary = {}

    # Infinite loop until all tasks are complete
    # It will sleep every 10 minutes (600 seconds) and re-check automatically
    while True:

        # Boolean to aggregate whether all tasks are complete
        all_tasks_complete = True

        # Loop over the dataset provided by the user few lines above, and do the Metis magic
        for ds,shortname in sample_map.items():
            # skip_tail = True
            skip_tail = False
            task = CondorTask(
                    sample = ds,
                    files_per_output = split_func(ds.get_datasetname()),
                    output_name = "output.root",
                    tag = tag,
                    condor_submit_params = {
                        "sites": "T2_US_UCSD,UAF",
                        "use_xrootd":True,
                        "classads": [
                            ["metis_extraargs", "--mode 3 -w"]
                            ]
                        },
                    cmssw_version = "CMSSW_11_2_0_pre5",
                    scram_arch = "slc7_amd64_gcc900",
                    input_executable = "{}/condor_executable_metis.sh".format(condorpath), # your condor executable here
		    #tarfile = "/home/users/kdownham/Triboson/VVVNanoLooper/condor/package.tar.xz",
		    #additional_input_files = ["/home/users/kdownham/Triboson/VVVNanoLooper/condor/package.tar.xz"],
		    tarfile = os.environ["condorPath"]+"/package.tar.xz", # your tarfile with assorted goodies here
		    additional_input_files = [os.environ["condorPath"]+"/package.tar.xz"],
                    special_dir = "VVVAnalysis/{}".format(tag), # output files into /hadoop/cms/store/<user>/<special_dir>
                    min_completion_fraction = 0.50 if skip_tail else 1.0,
                    # max_jobs = 10,
            )
            # When babymaking task finishes, fire off a task that takes outputs and merges them locally (hadd)
            # into a file that ends up on nfs (specified by `merged_dir` above)
            merge_task = LocalMergeTask(
                    input_filenames=task.get_outputs(),
                    output_filename="{}/{}.root".format(merged_dir,shortname),
                    ignore_bad = skip_tail,
                    )
            # Straightforward logic
            if not task.complete():
                task.process()
            else:
                if not merge_task.complete():
                    merge_task.process()

            # Aggregate whether all tasks are complete
            all_tasks_complete = all_tasks_complete and task.complete()

            # Set task summary
            task_summary[task.get_sample().get_datasetname()] = task.get_task_summary()

        # Parse the summary and make a summary.txt that will be used to pretty status of the jobs
        os.system("rm web_summary.json")
        webdir="~/public_html/VVVNanoLooperDashboard"
        StatsParser(data=task_summary, webdir=webdir).do()
        os.system("chmod -R 755 {}".format(webdir))
        os.system("msummary -r -i {}/web_summary.json".format(webdir))

        # If all done exit the loop
        if all_tasks_complete:
            print("")
            print("All job finished")
            print("")
            break

        # Neat trick to not exit the script for force updating
        print('Press Ctrl-C to force update, otherwise will sleep for 600 seconds')
        try:
            for i in reversed(range(0, 600)):
                sleep(1) # could use a backward counter to be preeety :)
                sys.stdout.write("\r{} mins {} seconds till updating ...".format(i/60, i%60))
                sys.stdout.flush()
        except KeyboardInterrupt:
            raw_input("Press Enter to force update, or Ctrl-C to quit.")
            print("Force updating...")

