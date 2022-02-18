#for proc in "WWW" "WWZ" "WZZ" "ZZZ"; do
for proc in "WWW" ; do
#for proc in "WZZ" "ZZZ"; do
    rm $proc.root
    ./doVVVAnalysis --input /eos/uscms/store/group/lpcvvv/ULSignalSamples/NoFilter/${proc}_RunIISummer20UL18/  --tree Events --mode 8  --output ${proc}.root  -w
done
