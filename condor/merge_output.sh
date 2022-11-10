#!/bin/bash
year=0
tag=""
isData=0
POSITIONAL=()
while [[ $# -gt 0 ]]; do
  key="$1"

  case $key in
    -d)
      isData=1
      shift # past argument
      ;;
    -y)
      year="$2"
      shift # past argument
      shift # past value
      ;;
    -t)
      tag="$2"
      shift # past argument
      shift # past value
      ;;
    *)    # unknown option
      POSITIONAL+=("$1") # save it in an array for later
      shift # past argument
      ;;
  esac
done

if [ $year -ne 2018 ] && [ $year -ne 2017 ] && [ $year -ne 2016 ]
then
  echo "ERROR: wrong year argument $year, should be (2018,2017,2016)"
  return
fi

inputdir="/store/group/lpcvvv/$USER/VVVAnalysis/$tag/$year"

if [ -z "$(eosls $inputdir)" ]
then
  echo "ERROR: wrong tag argument, no output file exist in $inputdir"
  return
fi

if [ $isData -eq 1 ]
then 
  list=$(python merge.py -d -y $year -t $tag)
else 
  list=$(python merge.py -y $year -t $tag)
fi
dir=($list)

merged_dir="/store/group/lpcvvv/$USER/merged/VVV/$tag/output/$year/"

if [ -z "$(eosls $merged_dir)" ]
then
  eosmkdir -p $merged_dir
fi

for ((i=0;i< ${#dir[@]} ;i+=2));
do
  shortname=${dir[i]}
  src=${dir[i+1]}
  des="${merged_dir}${shortname}.root"
  if [ -z "$(eosls $des)" ] && [ ! -z "$(eosls $src)" ]
  then
    hadd ~/nobackup/${shortname}.root `xrdfsls -u $src | grep '\.root'`
    xrdcp ~/nobackup/${shortname}.root root://cmseos.fnal.gov/$des
    rm ~/nobackup/${shortname}.root
  fi
done

