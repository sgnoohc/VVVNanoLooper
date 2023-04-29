#!/bin/bash

echo "*********************************"
echo "*                               *"
echo "*                               *"
echo "* doVVVAnalysis Production Test *"
echo "*                               *"
echo "*                               *"
echo "*********************************"

TESTBKGTTBAR=/ceph/cms/store/user/phchang/mc/RunIISummer20UL18NanoAODv9/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/130000/FF95F9A0-5DC8-A54A-B049-E9C958C001F7.root

./doVVVAnalysis -n 50000 -i ${TESTBKGTTBAR} -t Events -d -m 10 -w > debug.log 2>&1
