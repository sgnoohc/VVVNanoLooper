#!/bin/bash

SAMPLES="/ceph/cms/store/user/phchang/Dim6VVV/RunIISummer20UL18/group/lpcvvv/ULSignalSamples/Dim6Merged/WWW_NoFilter_Dim6_merged.root \
/ceph/cms/store/user/phchang/Dim6VVV/RunIISummer20UL18/group/lpcvvv/ULSignalSamples/Dim6Merged/WWZ_NoFilter_Dim6_merged.root \
/ceph/cms/store/user/phchang/Dim6VVV/RunIISummer20UL18/group/lpcvvv/ULSignalSamples/Dim6Merged/WZZ_NoFilter_Dim6_merged.root \
/ceph/cms/store/user/phchang/Dim6VVV/RunIISummer20UL18/group/lpcvvv/ULSignalSamples/Dim6Merged/ZZZ_NoFilter_Dim6_merged.root"

#____________________________________________________________________________________________________________________
mkdir -p dim6_vvvtree
rm -f .dim6jobs.txt
for SAMPLE in ${SAMPLES}; do
    BASENAME=$(basename ${SAMPLE})
    SAMPLENAME=${BASENAME/%.*}
    for IDX in $(seq 0 9); do
        echo "./doVVVAnalysis -j 10 -I ${IDX} -w --tree Events --mode 8 --input ${SAMPLE} -o dim6_vvvtree/${SAMPLENAME}_${IDX}.root > dim6_vvvtree/${SAMPLENAME}_${IDX}.log 2>&1" >> .dim6jobs.txt
    done
done
#xargs.sh .dim6jobs.txt

#____________________________________________________________________________________________________________________
mkdir -p dim6_vvvtree/merged
rm -f .dim6haddjobs.txt
echo "hadd -f dim6_vvvtree/merged/Dim6_WWW.root dim6_vvvtree/WWW_*.root > dim6_vvvtree/merged/Dim6_WWW.log 2>&1" >> .dim6haddjobs.txt
echo "hadd -f dim6_vvvtree/merged/Dim6_WWZ.root dim6_vvvtree/WWZ_*.root > dim6_vvvtree/merged/Dim6_WWZ.log 2>&1" >> .dim6haddjobs.txt
echo "hadd -f dim6_vvvtree/merged/Dim6_WZZ.root dim6_vvvtree/WZZ_*.root > dim6_vvvtree/merged/Dim6_WZZ.log 2>&1" >> .dim6haddjobs.txt
echo "hadd -f dim6_vvvtree/merged/Dim6_ZZZ.root dim6_vvvtree/ZZZ_*.root > dim6_vvvtree/merged/Dim6_ZZZ.log 2>&1" >> .dim6haddjobs.txt
xargs.sh .dim6haddjobs.txt
