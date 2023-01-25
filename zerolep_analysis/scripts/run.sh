#!/bin/bash


#________________________________________________________________________________________________________________________
rm -f .jobs.txt
for i in $(ls 2018/*.root); do
    echo "rm -f histograms/${i}; ./doAnalysis -t t -i ${i} -o histograms/${i} > histograms/${i/.root/.log} 2>&1" >> .jobs.txt
done
xargs.sh .jobs.txt


#________________________________________________________________________________________________________________________
rm -f .haddjobs.txt
echo "hadd -f hadds/JetHT_2018.root histograms/2018/JetHT_2018*.root                                                                    >  hadds/JetHT_2018.log  2>&1" >> .haddjobs.txt
echo "hadd -f hadds/QCD.root        histograms/2018/QCD*.root                                                                           >  hadds/QCD.log         2>&1" >> .haddjobs.txt
echo "hadd -f hadds/ST.root         histograms/2018/ST*.root                                                                            >  hadds/ST.log          2>&1" >> .haddjobs.txt
echo "hadd -f hadds/TT.root         histograms/2018/TTHad.root histograms/2018/TTSL.root                                                >  hadds/TT.log          2>&1" >> .haddjobs.txt
echo "hadd -f hadds/TTV.root        histograms/2018/TTW*.root histograms/2018/TTZ*.root                                                 >  hadds/TTV.log         2>&1" >> .haddjobs.txt
echo "hadd -f hadds/W.root          histograms/2018/WJ*.root                                                                            >  hadds/W.log           2>&1" >> .haddjobs.txt
echo "hadd -f hadds/Z.root          histograms/2018/ZJ*.root                                                                            >  hadds/Z.log           2>&1" >> .haddjobs.txt
echo "hadd -f hadds/VV.root         histograms/2018/WWTo*.root histograms/2018/WZ.root histograms/2018/ZZTo*.root                       >  hadds/VV.log          2>&1" >> .haddjobs.txt
echo "hadd -f hadds/WWW.root        histograms/2018/WWW.root                                                                            >  hadds/WWW.log         2>&1" >> .haddjobs.txt
echo "hadd -f hadds/WWZ.root        histograms/2018/WWZ.root                                                                            >  hadds/WWZ.log         2>&1" >> .haddjobs.txt
echo "hadd -f hadds/WZZ.root        histograms/2018/WZZ.root                                                                            >  hadds/WZZ.log         2>&1" >> .haddjobs.txt
echo "hadd -f hadds/ZZZ.root        histograms/2018/ZZZ.root                                                                            >  hadds/ZZZ.log         2>&1" >> .haddjobs.txt
echo "hadd -f hadds/VVV.root        histograms/2018/WWW.root histograms/2018/WWZ.root histograms/2018/WZZ.root histograms/2018/ZZZ.root >  hadds/VVV.log         2>&1" >> .haddjobs.txt
echo "hadd -f hadds/Dim6_WWW.root   histograms/2018/Dim6_WWW.root                                                                       >  hadds/Dim6_WWW.log    2>&1" >> .haddjobs.txt
echo "hadd -f hadds/Dim6_WWZ.root   histograms/2018/Dim6_WWZ.root                                                                       >  hadds/Dim6_WWZ.log    2>&1" >> .haddjobs.txt
echo "hadd -f hadds/Dim6_WZZ.root   histograms/2018/Dim6_WZZ.root                                                                       >  hadds/Dim6_WZZ.log    2>&1" >> .haddjobs.txt
echo "hadd -f hadds/Dim6_ZZZ.root   histograms/2018/Dim6_ZZZ.root                                                                       >  hadds/Dim6_ZZZ.log    2>&1" >> .haddjobs.txt
echo "hadd -f hadds/Dim6.root       histograms/2018/Dim6_???.root                                                                       >  hadds/Dim6.log        2>&1" >> .haddjobs.txt
echo "hadd -f hadds/Bkg.root        histograms/2018/QCD*.root histograms/2018/ST*.root histograms/2018/TTHad.root histograms/2018/TTSL.root histograms/2018/TTW*.root histograms/2018/TTZ*.root histograms/2018/WJ*.root histograms/2018/ZJ*.root histograms/2018/WWTo*.root histograms/2018/WZ.root histograms/2018/ZZTo*.root >  hadds/Bkg.log 2>&1" >> .haddjobs.txt
echo "hadd -f hadds/NonQCD.root     histograms/2018/ST*.root histograms/2018/TTHad.root histograms/2018/TTSL.root histograms/2018/TTW*.root histograms/2018/TTZ*.root histograms/2018/WJ*.root histograms/2018/ZJ*.root histograms/2018/WWTo*.root histograms/2018/WZ.root histograms/2018/ZZTo*.root >  hadds/NonQCD.log 2>&1" >> .haddjobs.txt
xargs.sh .haddjobs.txt

#________________________________________________________________________________________________________________________
# plotting
python scripts/compute_abcd_sphere.py
xargs.sh scripts/makeplots.sh
python scripts/compute_v1sf.py
python scripts/plot_abcd_closure.py
