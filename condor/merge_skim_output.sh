#!/bin/bash

for DIR in $(ls -d /ceph/cms/store/user/kdownham/VVVAnalysis/113022/*); do
    echo ""
    echo "---------------------------------------------------------------"
    if [ -f ${DIR}/merged/output.root ];then
        echo "Already Merged ${DIR}!"
    else
        echo "Merging ${DIR} ...."
        mkdir -p ${DIR}/merged/
        python haddnano.py ${DIR}/merged/output.root $(ls ${DIR}/*.root) > ${DIR}/merged/output_hadd.log 2>&1
    fi
    echo ""
done
