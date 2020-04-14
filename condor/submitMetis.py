import os

from metis.Sample import DBSSample
from metis.LocalMergeTask import LocalMergeTask
from metis.CondorTask import CondorTask
from metis.StatsParser import StatsParser
import samples

from time import sleep
import sys

condorpath = os.path.dirname(os.path.realpath(__file__))

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

    # Specify a dataset name and a short name for the output root file on nfs
    sample_map = samples.mc_2018 # See condor/samples.py

    # submission tag
    tag = "test"

    # Where the merged output will go
    merged_dir = "/nfs-7/userdata/{}/tupler_babies/merged/VVV/{}/output/".format(os.getenv("USER"),tag)

    # Task summary for printing out msummary
    task_summary = {}

    # Boolean to aggregate whether all tasks are complete
    all_tasks_complete = True

    # Infinite loop until all tasks are complete
    # It will sleep every 10 minutes (600 seconds) and re-check automatically
    while True:

        # Loop over the dataset provided by the user few lines above, and do the Metis magic
        for dsname,shortname in sample_map.items():
            # skip_tail = True
            skip_tail = False
            task = CondorTask(
                    sample = DBSSample(
                        dataset=dsname,
                        ),
                    files_per_output = split_func(dsname),
                    output_name = "output.root",
                    tag = tag,
                    condor_submit_params = {
                        "sites": "T2_US_UCSD,UAF",
                        "use_xrootd":True,
                        "classads": [
                            ["metis_extraargs", "--mode 7"]
                            ]
                        },
                    cmssw_version = "CMSSW_9_2_0",
                    scram_arch = "slc6_amd64_gcc700",
                    input_executable = "{}/condor_executable_metis.sh".format(condorpath), # your condor executable here
                    tarfile = "{}/package.tar.xz".format(condorpath), # your tarfile with assorted goodies here
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
        StatsParser(data=task_summary, webdir="~/public_html/VVVNanoLooperDashboard").do()
        os.system("chmod -R 755 ~/public_html/VVVNanoLooperDashboard")
        os.system("msummary -r | tee summary.txt")

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

