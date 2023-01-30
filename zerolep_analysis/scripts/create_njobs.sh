#!/bin/bash

YEARS="2006 2016 2017 2018"

for YEAR in ${YEARS}; do
    JSON=data/${YEAR}_njobs.json
    rm -f ${JSON} ${JSON}.tmp
    echo "{" >> ${JSON}.tmp
    DIR=../allhadtrees/${YEAR};
    for i in $(ls ${DIR}/*_0.root); do
        NAME=$(basename $i)
        SAMPLE=${NAME/_0.root/}
        NJOBS=$(ls ${DIR}/${SAMPLE}*.root | wc -l)
        echo \"${SAMPLE}\" : ${NJOBS}, >> ${JSON}.tmp
    done
    echo "}" >> ${JSON}.tmp
    sed 's/"ZZZ" : 1,/\"ZZZ\" : 1/g' ${JSON}.tmp > ${JSON}
    rm -f ${JSON}.tmp
done
