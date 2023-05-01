#!/bin/bash

OUTPUTDIR=$1
OUTPUTNAME=$2
INPUTFILENAMES=$3
IFILE=$4
CMSSWVERSION=$5
SCRAMARCH=$6

function getjobad {
    grep -i "^$1" "$_CONDOR_JOB_AD" | cut -d= -f2- | xargs echo
}
function setup_chirp {
    if [ -e ./condor_chirp ]; then
    # Note, in the home directory
        mkdir chirpdir
        mv condor_chirp chirpdir/
        export PATH="$PATH:$(pwd)/chirpdir"
        echo "[chirp] Found and put condor_chirp into $(pwd)/chirpdir"
    elif [ -e /usr/libexec/condor/condor_chirp ]; then
        export PATH="$PATH:/usr/libexec/condor"
        echo "[chirp] Found condor_chirp in /usr/libexec/condor"
    else
        echo "[chirp] No condor_chirp :("
    fi
}
function chirp {
    # Note, $1 (the classad name) must start with Chirp
    condor_chirp set_job_attr_delayed $1 $2
    ret=$?
    echo "[chirp] Chirped $1 => $2 with exit code $ret"
}

if [[ ${INPUTFILENAMES} == *"Run201"* ]]; then
    INPUTFILENAMES=${INPUTFILENAMES//\/store/root:\/\/cmsxrootd.fnal.gov\/\/store}
else
    INPUTFILENAMES=${INPUTFILENAMES//\/store/root:\/\/cmseos.fnal.gov\/\/store\/group\/lpcvvv\/NanoAODv9\/store}
fi

# Make sure OUTPUTNAME doesn't have .root since we add it manually
OUTPUTNAME=$(echo $OUTPUTNAME | sed 's/\.root//')

###UNCOMMENT TO COPY FAILING FILES DIRECTLY TO CONDOR NODE
#input=$(echo "${INPUTFILENAMES}" | sed 's/^.*\(\/store.*\).*$/\1/')
#dest="${input/\/store\//}"
#dest=$(dirname $dest)
#mkdir -p $dest
#xrdcp root://cms-xrd-global.cern.ch/$input $dest
#localpath=$(echo ${INPUTFILENAMES} | sed 's/^.*\(\/store.*\).*$/\1/')
#localpath="${localpath/\/store\//}"
#INPUTFILE=${localpath}

setup_chirp

echo -e "\n--- begin header output ---\n" #                     <----- section division
echo "OUTPUTDIR: $OUTPUTDIR"
echo "OUTPUTNAME: $OUTPUTNAME"
echo "INPUTFILENAMES: $INPUTFILENAMES"
echo "IFILE: $IFILE"
echo "CMSSWVERSION: $CMSSWVERSION"
echo "SCRAMARCH: $SCRAMARCH"

echo "GLIDEIN_CMSSite: $GLIDEIN_CMSSite"
echo "hostname: $(hostname)"
echo "uname -a: $(uname -a)"
echo "time: $(date +%s)"
echo "args: $@"

echo -e "\n--- end header output ---\n" #                       <----- section division

if [ -r "$OSGVO_CMSSW_Path"/cmsset_default.sh ]; then
    echo "sourcing environment: source $OSGVO_CMSSW_Path/cmsset_default.sh"
    source "$OSGVO_CMSSW_Path"/cmsset_default.sh
elif [ -r "$OSG_APP"/cmssoft/cms/cmsset_default.sh ]; then
    echo "sourcing environment: source $OSG_APP/cmssoft/cms/cmsset_default.sh"
    source "$OSG_APP"/cmssoft/cms/cmsset_default.sh
elif [ -r /cvmfs/cms.cern.ch/cmsset_default.sh ]; then
    echo "sourcing environment: source /cvmfs/cms.cern.ch/cmsset_default.sh"
    source /cvmfs/cms.cern.ch/cmsset_default.sh
else
    echo "ERROR! Couldn't find $OSGVO_CMSSW_Path/cmsset_default.sh or /cvmfs/cms.cern.ch/cmsset_default.sh or $OSG_APP/cmssoft/cms/cmsset_default.sh"
    exit 1
fi

export SCRAM_ARCH=${SCRAMARCH}

eval `scramv1 project CMSSW $CMSSWVERSION`
cd $CMSSWVERSION
eval `scramv1 runtime -sh`
mv ../package.tar.gz package.tar.gz
tar xf package.tar.gz

##########################################################
#UNCOMMENT TO COPY FAILING FILES DIRECTLY TO CONDOR NODE
echo "Before XRootD copy"
echo INPUTFILENAMES=${INPUTFILENAMES}
LOCALINPUTFILENAMES=""
for INPUTFILE in $(echo ${INPUTFILENAMES} | tr ',' ' '); do
    fulldest="${INPUTFILE/*\/store\//}"
    dest=$(dirname $fulldest)
    mkdir -p ${dest}
    echo ${dest}
    echo xrdcp ${INPUTFILE} ${dest}
    xrdcp ${INPUTFILE} ${dest}
    if [ -z ${LOCALINPUTFILENAMES} ]; then
        LOCALINPUTFILENAMES=${fulldest}
    else
        LOCALINPUTFILENAMES=${LOCALINPUTFILENAMES}","${fulldest}
    fi
done
INPUTFILENAMES=${LOCALINPUTFILENAMES}
echo "After XRootD copy"
echo INPUTFILENAMES=${INPUTFILENAMES}
##########################################################

cat gitversion.txt

# need this to find the .so files, even though they are in the same
# directory
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.

echo "before running: ls -lrth"
ls -lrth 

echo -e "\n--- begin running ---\n" #                           <----- section division

EXTRAARGS="$(getjobad metis_extraargs)"
# if [[ $(hostname) == *"t2.ucsd.edu"* ]] && [[ $INPUTFILENAMES == *"/hadoop"* ]]; then
#     : # Don't need to do anything
# else
#     INPUTFILENAMES=${INPUTFILENAMES/\/store/root:\/\/cmsxrootd.fnal.gov\/\/store}
# fi
echo Executing ./doVVVAnalysis -i $INPUTFILENAMES -t Events -o ${OUTPUTNAME}.root ${EXTRAARGS}
./doVVVAnalysis -i $INPUTFILENAMES -t Events -o ${OUTPUTNAME}.root ${EXTRAARGS}
RET=$?

if [ ${RET} != 0 ]; then
    if [[ "${EXTRAARGS}" = *"ignorebadfiles"* ]]; then
        echo "Ignoring exit code of ${RET}"
    else
        echo "Removing output file because ./doVVVAnalysis returned exit code ${RET}"
        rm ${OUTPUTNAME}.root
    fi
fi

# Rigorous sweeproot which checks ALL branches for ALL events.
# If GetEntry() returns -1, then there was an I/O problem, so we will delete it
python << EOL
import ROOT as r
import os
foundBad = False
try:
    f1 = r.TFile("${OUTPUTNAME}.root")
    t = f1.Get("t")
    nevts = t.GetEntries()
    for i in range(0,t.GetEntries(),1):
        if t.GetEntry(i) < 0:
            foundBad = True
            print "[RSR] found bad event %i" % i
            break
except: foundBad = True
if foundBad:
    print "[RSR] removing output file because it does not deserve to live"
    os.system("rm ${OUTPUTNAME}.root")
else: print "[RSR] passed the rigorous sweeproot"
EOL

echo -e "\n--- end running ---\n" #                             <----- section division

echo "after running: ls -lrth"
ls -lrth


if [[ $(hostname) == *"uaf-10"* ]]; then
    echo -e "\n--- begin copying output ---\n" #                    <----- section division
    echo "Sending output file output/${OUTPUTNAME}.root"
    OUTPUTDIRPATHNEW=$(echo ${OUTPUTDIR} | sed 's/^.*\(\/store.*\).*$/\1/')
    COPY_SRC="output/${OUTPUTNAME}.root"
    COPY_DEST_DIR="/ceph/cms/${OUTPUTDIRPATHNEW}/"
    COPY_DEST="${COPY_DEST_DIR}/${OUTPUTNAME}_${IFILE}.root"
    echo "Running: mkdir -p ${COPY_DEST_DIR}"
    mkdir -p ${COPY_DEST_DIR}
    echo "Running: cp ${COPY_SRC} ${COPY_DEST}"
    cp ${COPY_SRC} ${COPY_DEST}
    COPY_STATUS=$?
    if [[ $COPY_STATUS == 0 ]]; then
        echo "Copy success!"
    fi
else
    echo -e "\n--- begin copying output ---\n" #                    <----- section division
    echo "Sending output file output/${OUTPUTNAME}.root"
    OUTPUTDIRPATHNEW=$(echo ${OUTPUTDIR} | sed 's/^.*\(\/store.*\).*$/\1/')
    COPY_SRC="file://`pwd`/${OUTPUTNAME}.root"
    COPY_DEST="davs://redirector.t2.ucsd.edu:1095//${OUTPUTDIRPATHNEW}/${OUTPUTNAME}_${IFILE}.root"
    echo "Running: env -i X509_USER_PROXY=${X509_USER_PROXY} gfal-copy -p -f -t 4200 --verbose --checksum ADLER32 ${COPY_SRC} ${COPY_DEST}"
    env -i X509_USER_PROXY=${X509_USER_PROXY} gfal-copy -p -f -t 4200 --verbose --checksum ADLER32 ${COPY_SRC} ${COPY_DEST}
    COPY_STATUS=$?
    if [[ $COPY_STATUS != 0 ]]; then
        echo "Removing output file because gfal-copy crashed with code $COPY_STATUS"
        env -i X509_USER_PROXY=${X509_USER_PROXY} gfal-rm --verbose ${COPY_DEST}
        REMOVE_STATUS=$?
        if [[ $REMOVE_STATUS != 0 ]]; then
            echo "Uhh, gfal-copy crashed and then the gfal-rm also crashed with code $REMOVE_STATUS"
        fi
    fi
fi
