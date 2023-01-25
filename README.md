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

    /ceph/cms/store/user/kdownham/skimOutput/WWZ_4L/

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
    sh condor/maketar.sh # Tar up the code
    cd condor/
    # Update the version to the skimmer
    python submit4Lep.py -t TAG

### Existing vvvtree ntuple (v9)

    /ceph/cms/store/user/kdownham/VVVAnalysis/120222


### Running the analysis looper on VVVTree ntuple

Prior to sourcing setup.sh please follow the instructions given above in the section "Setting the correct Input/Output Paths".

    source setup.sh
    cd analysis/
    make -j
    python run_analyzer.py
    python plot.py
