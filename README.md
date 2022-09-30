# VVVNanoLooper

## Installation

    ssh uaf-10.t2.ucsd.edu
    cd your/favoriate/working/directory
    git clone --recursive --branch Run3_WWZ git@github.com:cmstas/VVVNanoLooper.git
    cd VVVNanoLooper/
    source setup.sh
    make cleansmall; // Clean only VVV looper related
    make clean; // Full clean include NanoTools/rooutil related objects
    make -j;

## Quick start

Below command will create ```debug.root``` output from the loop

     ./doVVVAnalysis --input /hadoop/cms/store/group/snt/nanoaod/GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8__RunIIAutumn18NanoAODv5-Nano1June2019_102X_upgrade2018_realistic_v19-v1/C91570D8-46E6-6A4F-B722-857B9C5FE1F4.root \
        --tree Events \
        --mode 0 \
        --debug

Alternatively, if you want to write it out to ```my_output.root```,

     ./doVVVAnalysis --input /hadoop/cms/store/group/snt/nanoaod/GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8__RunIIAutumn18NanoAODv5-Nano1June2019_102X_upgrade2018_realistic_v19-v1/C91570D8-46E6-6A4F-B722-857B9C5FE1F4.root \
        --tree Events \
        --mode 0 \
        --output my_output.root

This will create some dummy histograms with dummy variables with dummy selections.  See the actual source code to see what is going on.

## Submitting NanoSkimmer job

    source setup.sh
    cd condor/
    # Modify in the code the tag version
    python submitNanoSkimmerMetis.py

## Submitting VVVTree making job

    source setup.sh
    cd condor/
    # Update the version to the skimmer
    python submit4Lep.py -t TAG

## Running the analysis looper

    source setup.sh
    cd analysis/
    make -j
    python run.py
    python plot.py
