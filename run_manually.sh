#!/bin/bash

echo "*********************************"
echo "*                               *"
echo "*                               *"
echo "* doVVVAnalysis Production Test *"
echo "*                               *"
echo "*                               *"
echo "*********************************"


INPUTDIR=/ceph/cms/store/user/kdownham/skimOutput/3LepTau_4Lep
PROCESS=WWZJetsTo4L2Nu_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11-v2_NANOAODSIM_3LepTau_4Lep
#OUTPUTDIR=/ceph/cms/store/user/kdownham/VVVAnalysis/120222/${PROCESS}_120222
OUTPUTDIR=/home/users/kdownham/Triboson/VVVNanoLooper
NAME=output_WWZJets_16APV_sync_Oct19.root

#for i in $(seq 1 7); do
#./doVVVAnalysis -i ${INPUTDIR}/${PROCESS}/output_${i}.root -t Events -o ${OUTPUTDIR}/output_${i}.root --mode 0 -w
#done

./doVVVAnalysis -i ${INPUTDIR}/${PROCESS}/output_8.root --tree Events --mode 0 --output ${OUTPUTDIR}/${NAME} -w 1
