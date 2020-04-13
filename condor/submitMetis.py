import os

from metis.Sample import DBSSample
from metis.LocalMergeTask import LocalMergeTask
from metis.CondorTask import CondorTask
import samples

# Avoid spamming too many short jobs to condor
# Less dileptn pairs = faster = more input files per job
def split_func(dsname):
    if any(x in dsname for x in [
        "/W","/Z","/TTJets","/DY","/ST",
        ]):
        return 5
    elif "Run201" in dsname:
        return 7
    else:
        return 2

if __name__ == "__main__":

    # Specify a dataset name and a short name for the output root file on nfs
    sample_map = samples.mc_2018 # See condor/samples.py

    # submission tag
    tag = "test"

    # Where the merged output will go
    merged_dir = "/nfs-7/userdata/{}/tupler_babies/merged/VVV/{}/output/".format(os.getenv("USER"),tag)

    # Loop over the dataset provided by the user few lines above, and do the Metis magic
    for dsname,shortname in sample_map.items():
        skip_tail = False
        task = CondorTask(
                sample = DBSSample(
                    dataset=dsname,
                    ),
                files_per_output = split_func(dsname),
                output_name = "output.root",
                tag = tag,
                condor_submit_params = {
                    "sites": "T2_US_UCSD",
                    "use_xrootd":True,
                    "classads": [
                        ["metis_extraargs", "--mode 0"]
                        ]
                    },
                cmssw_version = "CMSSW_9_2_0",
                scram_arch = "slc6_amd64_gcc700",
                input_executable = "condor/condor_executable_metis.sh", # your condor executable here
                tarfile = "condor/package.tar.xz", # your tarfile with assorted goodies here
                special_dir = "VVVAnalysis/{}".format(tag), # output files into /hadoop/cms/store/<user>/<special_dir>
                min_completion_fraction = 0.90 if skip_tail else 1.0,
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

