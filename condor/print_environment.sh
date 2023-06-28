xgboost_cfg=${CMSSW_BASE}/config/toolbox/${SCRAM_ARCH}/tools/selected/py3-xgboost.xml
xgboost_version="$(grep -e 'tool name' ${xgboost_cfg} | grep 'py3-xgboost')"
xgboost_version="${xgboost_version##*=\"}"
xgboost_version="${xgboost_version%%\"*}"
xgboost_path="/cvmfs/cms.cern.ch/${SCRAM_ARCH}/external/py3-xgboost/${xgboost_version}/lib/python3.8/site-packages/xgboost"
#export LD_LIBRARY_PATH=${xgboost_path}/lib:$LD_LIBRARY_PATH

#<LD_LIBRARY_PATH>=<${xgboost_path}/lib:$LD_LIBRARY_PATH>

environment=LD_LIBRARY_PATH=${xgboost_path}/lib:$LD_LIBRARY_PATH

printenv
