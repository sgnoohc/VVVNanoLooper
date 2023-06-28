#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
XGBOOSTLIBDIR=${XGBOOST_PATH}/lib

cd $DIR/../

make cleansmall;
make clean;
make -j 12;

git status > gitversion.txt
git rev-parse HEAD >> gitversion.txt
git log >> gitversion.txt
git diff >> gitversion.txt

rm -rf /tmp/${USER}/tmptar
mkdir -p /tmp/${USER}/tmptar
cd /tmp/${USER}/tmptar
mkdir -p src/
mkdir -p src/data/external/TopLeptonMVA/
mkdir -p weights/
cp ${DIR}/../doVVVAnalysis .
cp -r ${DIR}/../src/scalefactors src/
cp -r ${DIR}/../config .
cp ${DIR}/../gitversion.txt .
cp ${DIR}/../weights/scaleLumis.txt weights/
cp ${DIR}/../rooutil/lib/* .
cp ${XGBOOSTLIBDIR}/* .
cp ${DIR}/../src/data/external/TopLeptonMVA/* src/data/external/TopLeptonMVA/.

tar -chJf $DIR/package.tar.xz .

rm gitversion.txt
