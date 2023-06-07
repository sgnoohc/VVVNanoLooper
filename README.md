# Four Lepton Analysis

## Setting the correct Input/Output Paths

After you clone the repo, the I/O paths for NanoLooper are set in `setup.sh`. Prior to sourcing `setup.sh`, you need to modify the `$condorPath` and 
the `$looperOutput` environment variables to correspond to the location of your `VVVNanoLooper/condor` directory and the location where you want the
VVVTrees (the output of the VVVNanoLooper) placed, respectively. The `skimDir` variable need not be changed unless you want to use a different set of 
skims. If you do not change these variables prior to sourcing `setup.sh` you will encounter errors!

## Quick start

Run the following commands to produce plots. Prior to sourcing setup.sh please follow the instructions given above in the section "Setting the correct
Input/Output Paths".

    ssh uaf-10.t2.ucsd.edu
    cd your/favoriate/working/directory
    git clone --recursive --branch WWZ_debug git@github.com:cmstas/VVVNanoLooper.git
    cd VVVNanoLooper/rooutil
    make -j
    cd ..
    source setup.sh
    cd analysis/
    make -j
    python run_analyzer.py
    python plot.py

## Nano Skimmer

### Submitting NanoSkimmer job

Prior to sourcing setup.sh please follow the instructions given above in the section "Setting the correct Input/Output Paths".

    source setup.sh
    cd condor/
    # Modify in the code the tag version
    python submitNanoSkimmerMetis.py

### Existing NanoSkimmed output (v9)

    /ceph/cms/store/user/kdownham/skimOutput/3LepTau_4Lep/

## VVVNanoLooper

### Installation

Prior to sourcing setup.sh please follow the instructions given above in the section "Setting the correct Input/Output Paths".

    ssh uaf-10.t2.ucsd.edu
    cd your/favoriate/working/directory
    git clone --recursive --branch Run3_WWZ git@github.com:cmstas/VVVNanoLooper.git
    cd VVVNanoLooper/
    source setup.sh
    make cleansmall; // Clean only VVV looper related
    make clean; // Full clean include NanoTools/rooutil related objects
    make -j;

### Submitting VVVNanoLooper jobs (This makes VVVTree ntuple)

Prior to sourcing setup.sh please follow the instructions given above in the section "Setting the correct Input/Output Paths".

    source setup.sh

Before making the tarball for the VVVNanoLooper jobs, you first must create the necessary text files containing the cross section information and scale1fb information for the samples you want to run on. You may need to modify these files slightly to point to the correct NanoSkims.

    cd weights/
    python parse_xsec.py > xsec.txt
    python parse_scale1fbs.py > scale1fbs.txt
    cd ../
    
Now that you have stored this information for the samples, you can now make the tarball and submit the condor jobs.

    sh condor/maketar.sh # Tar up the code
    cd condor/
    # Update the version to the skimmer
    python submit4Lep.py -t TAG
    
Once your jobs are finished, you need to hadd the outputs together (required to run the analysis looper). This is handled using the `merge_skim_output.sh` script in the `condor/` directory.

    # hadd the VVVNanoLooper outputs together
    ./merge_skim_output.sh

### Existing vvvtree ntuple (v9)

The most up-to-date version of the vvvtree is stored in Keegan's area on ceph:

    /ceph/cms/store/user/kdownham/VVVAnalysis/051723


### Running the analysis looper on VVVTree ntuple

Prior to sourcing setup.sh please follow the instructions given above in the section "Setting the correct Input/Output Paths".

    source setup.sh
    cd analysis/
    make -j
    python run_analyzer.py
    python plot.py
