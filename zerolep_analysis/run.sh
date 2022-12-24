#!/bin/bash


#________________________________________________________________________________________________________________________
rm -f .jobs.txt
for i in $(ls 2018/*.root); do
    echo "rm -f histograms/${i}; ./doAnalysis -t t -i ${i} -o histograms/${i} > histograms/${i/.root/.log} 2>&1" >> .jobs.txt
done
xargs.sh .jobs.txt


#________________________________________________________________________________________________________________________
rm -f .haddjobs.txt
echo "hadd -f hadds/JetHT_2018.root histograms/2018/JetHT_2018*.root                                                >  hadds/JetHT_2018.log  2>&1" >> .haddjobs.txt
echo "hadd -f hadds/QCD.root        histograms/2018/QCD*.root                                                       >  hadds/QCD.log         2>&1" >> .haddjobs.txt
echo "hadd -f hadds/ST.root         histograms/2018/ST*.root                                                        >  hadds/ST.log          2>&1" >> .haddjobs.txt
echo "hadd -f hadds/TT.root         histograms/2018/TTHad.root histograms/2018/TTSL.root                            >  hadds/TT.log          2>&1" >> .haddjobs.txt
echo "hadd -f hadds/TTV.root        histograms/2018/TTW*.root histograms/2018/TTZ*.root                             >  hadds/TTV.log         2>&1" >> .haddjobs.txt
echo "hadd -f hadds/W.root          histograms/2018/WJ*.root                                                        >  hadds/W.log           2>&1" >> .haddjobs.txt
echo "hadd -f hadds/Z.root          histograms/2018/ZJ*.root                                                        >  hadds/Z.log           2>&1" >> .haddjobs.txt
echo "hadd -f hadds/VV.root         histograms/2018/WWTo*.root histograms/2018/WZ.root histograms/2018/ZZTo*.root   >  hadds/VV.log          2>&1" >> .haddjobs.txt
echo "hadd -f hadds/WWW.root        histograms/2018/WWW.root                                                        >  hadds/WWW.log         2>&1" >> .haddjobs.txt
echo "hadd -f hadds/WWZ.root        histograms/2018/WWZ.root                                                        >  hadds/WWZ.log         2>&1" >> .haddjobs.txt
echo "hadd -f hadds/WZZ.root        histograms/2018/WZZ.root                                                        >  hadds/WZZ.log         2>&1" >> .haddjobs.txt
echo "hadd -f hadds/ZZZ.root        histograms/2018/ZZZ.root                                                        >  hadds/ZZZ.log         2>&1" >> .haddjobs.txt
echo "hadd -f hadds/WWW_Dim6.root   histograms/2018/WWW_Dim6.root                                                   >  hadds/WWW_Dim6.log    2>&1" >> .haddjobs.txt
echo "hadd -f hadds/WWZ_Dim6.root   histograms/2018/WWZ_Dim6.root                                                   >  hadds/WWZ_Dim6.log    2>&1" >> .haddjobs.txt
echo "hadd -f hadds/WZZ_Dim6.root   histograms/2018/WZZ_Dim6.root                                                   >  hadds/WZZ_Dim6.log    2>&1" >> .haddjobs.txt
echo "hadd -f hadds/ZZZ_Dim6.root   histograms/2018/ZZZ_Dim6.root                                                   >  hadds/ZZZ_Dim6.log    2>&1" >> .haddjobs.txt
xargs.sh .haddjobs.txt


#________________________________________________________________________________________________________________________
python plot.py
