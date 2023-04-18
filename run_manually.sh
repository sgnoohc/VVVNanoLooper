#!/bin/bash

echo "*********************************"
echo "*                               *"
echo "*                               *"
echo "* doVVVAnalysis Production Test *"
echo "*                               *"
echo "*                               *"
echo "*********************************"


INPUTDIR=/ceph/cms/store/user/kdownham/skimOutput/WWZ_newLepID
PROCESS=WWZJetsTo4L2Nu_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v2_NANOAODSIM_WWZ_newLepID
#OUTPUTDIR=/ceph/cms/store/user/kdownham/VVVAnalysis/120222/${PROCESS}_120222
OUTPUTDIR=/home/users/kdownham/Triboson/VVVNanoLooper

for i in $(seq 1 7); do
     ./doVVVAnalysis -i ${INPUTDIR}/${PROCESS}/output_${i}.root -t Events -o ${OUTPUTDIR}/output_${i}.root --mode 0 -w
done
