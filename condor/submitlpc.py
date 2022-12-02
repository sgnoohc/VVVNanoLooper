import os

from metis.Sample import DBSSample
from metis.LocalMergeTask import LocalMergeTask
from metis.CondorTask import CondorTask
from metis.StatsParser import StatsParser
import metis.Utils
import samples
import argparse

from time import sleep
import sys

condorpath = os.path.dirname(os.path.realpath(__file__))

def get_proxy_file():
#   return "/tmp/x509up_u{0}".format(os.getuid())
    return os.getenv("X509_USER_PROXY")

metis.Utils.get_proxy_file = get_proxy_file

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
    parser.add_argument('-m' , '--mode'        , dest='mode'      , help='tag of the job'            , type=int, required=True                                     )
    parser.add_argument('-a' , '--addflags'    , dest='addflags'  , help='adding flags to metis'     , type=str,                default=""                         )
    parser.add_argument('-d' , '--datamc'      , dest='datamc'    , help='data or mc'                ,                          default=False , action='store_true')
    parser.add_argument('-y' , '--year'        , dest='year'      , help='data year'                 , type=int, required=True                                     )
    parser.add_argument('-t' , '--thetag'      , dest='thetag'    , help='tag'                       , type=str,                default="test"                     )
    parser.add_argument('-s' , '--mysample'    , dest='mysample'  , help='don\'t do autmoated sample',                          default=False , action='store_true')
    # Argument parser
    args = parser.parse_args()
    args.mode
    
    
    if args.year == 2018:    
        sample_map = samples.JetHT_2018
    #    sample_map.update(samples.QCD_2018)
    #    sample_map.update(samples.Vplusjets_2018)
    #    sample_map.update(samples.diboson_2018)
    #    sample_map.update(samples.top_2018)
    elif args.year == 2017:    
        sample_map = samples.JetHT_2017
        sample_map.update(samples.QCD_2017)
        sample_map.update(samples.Vplusjets_2017)
        sample_map.update(samples.diboson_2017)
        sample_map.update(samples.top_2017)
    elif args.year == 2016:    
        sample_map = samples.JetHT_2016
        sample_map.update(samples.QCD_2016)
        sample_map.update(samples.Vplusjets_2016)
        sample_map.update(samples.diboson_2016)
        sample_map.update(samples.top_2016)
    # submission tag
    tag = args.thetag 
    
    ### 1l samples
    #sample_map = samples.QCD_2018
    #sample_map.update(samples.Vplusjets_2018_1L)
    # submission tag
    tag = args.thetag 
    
    ### 1l samples
    #sample_map = samples.QCD_2018
    #sample_map.update(samples.Vplusjets_2018_1L)
    #sample_map.update(samples.Data_2018_1L)
    #sample_map.update(samples.top_2018_1L)
    #sample_map.update(samples.diboson_2018)
    

    # Where the merged output will go
    # merged_dir = "/store/group/lpcvvv/{}/merged/VVV/{}/output/{}".format(os.getenv("USER"),tag,args.year)


    # Task summary for printing out msummary
    task_summary = {}
        
    print sample_map

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
                            ["metis_extraargs", "--mode {} {} -w".format(args.mode,args.addflags)]
                            ]
                        },
                    cmssw_version = "CMSSW_10_2_13",
                    scram_arch = "slc7_amd64_gcc700",
                    input_executable = "{}/condor_executable_lpc.sh".format(condorpath), # your condor executable here
                    tarfile = "{}/package.tar.xz".format(condorpath), # your tarfile with assorted goodies here
                    #output_dir = "/store/user/{}/VVVAnalysis/{}/{}/{}_{}/".format(os.getenv("USER"),tag,args.year,ds.get_datasetname().replace("/", "_").lstrip("_"),tag), # output files path
		            output_dir = "/eos/uscms/store/group/lpcvvv/{}/VVVAnalysis/{}/{}/{}_{}/".format(os.getenv("USER"),tag,args.year,ds.get_datasetname().replace("/", "_").lstrip("_"),tag), # output files path to group space
                    min_completion_fraction = 0.50 if skip_tail else 1.0,
                    recopy_inputs = True,
                    # max_jobs = 10,
            )
            # When babymaking task finishes, fire off a task that takes outputs and merges them locally (hadd)
            # into a file that ends up on nfs (specified by `merged_dir` above)
            # merge_task = LocalMergeTask(
            #        input_filenames=task.get_outputs(),
            #        output_filename="{}/{}.root".format(merged_dir,shortname),
            #        ignore_bad = skip_tail,
            #        )
            # Straightforward logic
            if not task.complete():
                task.process()
            #else:
            #    if not merge_task.complete():
            #        merge_task.process()

            # Aggregate whether all tasks are complete
            all_tasks_complete = all_tasks_complete and task.complete()

            # Set task summary
            task_summary[task.get_sample().get_datasetname()] = task.get_task_summary()

        # Parse the summary and make a summary.txt that will be used to pretty status of the jobs
        #os.system("rm web_summary.json")
        #webdir="~/public_html/VVVNanoLooperDashboard{}".format(args.year)
        #StatsParser(data=task_summary, webdir=webdir).do()
        #os.system("chmod -R 755 {}".format(webdir))
        #os.system("msummary -r -i {}/web_summary.json".format(webdir))

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

