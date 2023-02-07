#!/bin/bash

echo "*********************************"
echo "*                               *"
echo "*                               *"
echo "* doVVVAnalysis Production Test *"
echo "*                               *"
echo "*                               *"
echo "*********************************"


INPUTDIR=/ceph/cms/store/user/kdownham/skimOutput/WWZ_newLepID
PROCESS=SSWW_TuneCP5_13TeV-madgraph-pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v1_NANOAODSIM_WWZ_newLepID
#OUTPUTDIR=/ceph/cms/store/user/kdownham/VVVAnalysis/120222/${PROCESS}_120222
OUTPUTDIR=/home/users/kdownham/Triboson/VVVNanoLooper

for i in $(seq 1 2); do
     ./doVVVAnalysis -i ${INPUTDIR}/${PROCESS}/output_${i}.root -t Events -o ${OUTPUTDIR}/output_${i}.root --mode 0 -w
done
