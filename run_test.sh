#!/bin/bash

echo "*********************************"
echo "*                               *"
echo "*                               *"
echo "* doVVVAnalysis Production Test *"
echo "*                               *"
echo "*                               *"
echo "*********************************"

TESTBKGTT0=/ceph/cms/store/user/phchang/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/130000/FF95F9A0-5DC8-A54A-B049-E9C958C001F7.root
TESTBKGTT1=/ceph/cms/store/user/phchang/mc/RunIISummer20UL18NanoAODv9/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/280000/FFCC36D1-EF5D-B542-95BE-AC701A03EB70.root
TESTSIGWWW=/ceph/cms/store/user/phchang/mc/signal/store/group/lpcvvv/ULSignalSamples/NoFilter/WWW_RunIISummer20UL18/WWW_All.root
DEBUGOUTPUTDIR=/ceph/cms/store/user/phchang/VVV0LepAnalysis/VVV0TreeDebug

rm -rf .jobs.txt
echo "rm -rf ${DEBUGOUTPUTDIR}/debug_tt0.root; ./doVVVAnalysis -n 10000 -i ${TESTBKGTT0} -t Events -o ${DEBUGOUTPUTDIR}/debug_tt0.root -m 10 -w > ${DEBUGOUTPUTDIR}/debug_tt0.log 2>&1" >> .jobs.txt
echo "rm -rf ${DEBUGOUTPUTDIR}/debug_tt1.root; ./doVVVAnalysis -n 10000 -i ${TESTBKGTT1} -t Events -o ${DEBUGOUTPUTDIR}/debug_tt1.root -m 10 -w > ${DEBUGOUTPUTDIR}/debug_tt1.log 2>&1" >> .jobs.txt
echo "rm -rf ${DEBUGOUTPUTDIR}/debug_www.root; ./doVVVAnalysis -n 10000 -i ${TESTSIGWWW} -t Events -o ${DEBUGOUTPUTDIR}/debug_www.root -m 10 -w > ${DEBUGOUTPUTDIR}/debug_www.log 2>&1" >> .jobs.txt

xargs.sh .jobs.txt
