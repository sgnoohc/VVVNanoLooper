# Four Lepton Analysis

## Quick start

Copy paste the following and it should work right away to produce the plots

    ssh uaf-10.t2.ucsd.edu
    cd your/favoriate/working/directory
    git clone --recursive --branch Run3_WWZ git@github.com:cmstas/VVVNanoLooper.git
    cd VVVNanoLooper/
    source setup.sh
    cd analysis/
    make -j
    python run.py
    python plot.py

## Nano Skimmer

### Submitting NanoSkimmer job

    source setup.sh
    cd condor/
    # Modify in the code the tag version
    python submitNanoSkimmerMetis.py

### Existing NanoSkimmed output (v9)

    /ceph/cms/store/user/phchang/FourLepNanoSkim/v9/

## VVVNanoLooper

### Installation

    ssh uaf-10.t2.ucsd.edu
    cd your/favoriate/working/directory
    git clone --recursive --branch Run3_WWZ git@github.com:cmstas/VVVNanoLooper.git
    cd VVVNanoLooper/
    source setup.sh
    make cleansmall; // Clean only VVV looper related
    make clean; // Full clean include NanoTools/rooutil related objects
    make -j;

### Submitting VVVNanoLooper jobs (This makes VVVTree ntuple)

    source setup.sh
    sh condor/maketar.sh # Tar up the code
    cd condor/
    # Update the version to the skimmer
    python submit4Lep.py -t TAG

### Existing vvvtree ntuple (v9)

    /ceph/cms/store/user/phchang/VVVTree/v9/

or

    /home/users/phchang/work/vvv/WWZRun3NanoLooper/vvvtree/v9

### Running the analysis looper on VVVTree ntuple

    source setup.sh
    cd analysis/
    make -j
    python run.py
    python plot.py
