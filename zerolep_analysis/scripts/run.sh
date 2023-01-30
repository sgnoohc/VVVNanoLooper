#!/bin/bash

YEARS="2006 2016 2017 2018"

mkdir -p histograms/
for YEAR in ${YEARS}; do
    mkdir -p histograms/merged/${YEAR}
done

FT0s="m3p0 m1p5 m1p0 m0p8 m0p4 m0p2 p0p2 p0p4 p0p8 p1p0 p1p5 p3p0"

get_WWW_FT0()
{
    if [[ $1 == "85" ]]; then echo "m3p0"; fi
    if [[ $1 == "86" ]]; then echo "m1p5"; fi
    if [[ $1 == "87" ]]; then echo "m1p0"; fi
    if [[ $1 == "88" ]]; then echo "m0p8"; fi
    if [[ $1 == "89" ]]; then echo "m0p4"; fi
    if [[ $1 == "90" ]]; then echo "m0p2"; fi
    if [[ $1 == "91" ]]; then echo "p0p2"; fi
    if [[ $1 == "92" ]]; then echo "p0p4"; fi
    if [[ $1 == "93" ]]; then echo "p0p8"; fi
    if [[ $1 == "94" ]]; then echo "p1p0"; fi
    if [[ $1 == "95" ]]; then echo "p1p5"; fi
    if [[ $1 == "96" ]]; then echo "p3p0"; fi
}

get_ZVV_FT0()
{
    if [[ $1 == "133" ]]; then echo "m3p0"; fi
    if [[ $1 == "134" ]]; then echo "m1p5"; fi
    if [[ $1 == "135" ]]; then echo "m1p0"; fi
    if [[ $1 == "136" ]]; then echo "m0p8"; fi
    if [[ $1 == "137" ]]; then echo "m0p4"; fi
    if [[ $1 == "138" ]]; then echo "m0p2"; fi
    if [[ $1 == "139" ]]; then echo "p0p2"; fi
    if [[ $1 == "140" ]]; then echo "p0p4"; fi
    if [[ $1 == "141" ]]; then echo "p0p8"; fi
    if [[ $1 == "142" ]]; then echo "p1p0"; fi
    if [[ $1 == "143" ]]; then echo "p1p5"; fi
    if [[ $1 == "144" ]]; then echo "p3p0"; fi
}

#________________________________________________________________________________________________________________________
rm -f .jobs.txt
for YEAR in ${YEARS}; do
    for i in $(ls merged/${YEAR}/*.root); do
        #_________________________________________________________________
        if [[ ${i} == *"WWW"* ]]; then
            for EFTIDX in $(seq 85 96); do
                SAMPLE=${i/.root/}
                EFT=$(get_WWW_FT0 ${EFTIDX})
                FN=${SAMPLE}_${EFT}.root
                echo "rm -f histograms/${FN}; ./doAnalysis --eftidx ${EFTIDX} -t t -i ${i} -o histograms/${FN} > histograms/${FN/.root/.log} 2>&1" >> .jobs.txt
            done
        #_________________________________________________________________
        elif [[ ${i} == *"WWZ"* ]] || [[ ${i} == *"WZZ"* ]] || [[ ${i} == *"ZZZ"* ]]; then
            for EFTIDX in $(seq 133 144); do
                SAMPLE=${i/.root/}
                EFT=$(get_ZVV_FT0 ${EFTIDX})
                FN=${SAMPLE}_${EFT}.root
                echo "rm -f histograms/${FN}; ./doAnalysis --eftidx ${EFTIDX} -t t -i ${i} -o histograms/${FN} > histograms/${FN/.root/.log} 2>&1" >> .jobs.txt
            done
        #_________________________________________________________________
        else
            echo "rm -f histograms/${i}; ./doAnalysis -t t -i ${i} -o histograms/${i} > histograms/${i/.root/.log} 2>&1" >> .jobs.txt
        fi
    done
done
# xargs.sh .jobs.txt


#________________________________________________________________________________________________________________________
rm -f .haddjobs.txt
for YEAR in ${YEARS}; do
    mkdir -p hadds/${YEAR}/
    HISTO=histograms/merged/${YEAR}
    if [[ ${YEAR} == *2006* ]]; then
        YR=2016
    else
        YR=${YEAR}
    fi
    echo "hadd -f hadds/${YEAR}/JetHT.root       ${HISTO}/JetHT_${YR}*.root                                                                 >  hadds/JetHT_2018.log  2>&1" >> .haddjobs.txt
    echo "hadd -f hadds/${YEAR}/QCD.root         ${HISTO}/QCD*.root                                                                         >  hadds/QCD.log         2>&1" >> .haddjobs.txt
    echo "hadd -f hadds/${YEAR}/ST.root          ${HISTO}/ST*.root                                                                          >  hadds/ST.log          2>&1" >> .haddjobs.txt
    echo "hadd -f hadds/${YEAR}/TT.root          ${HISTO}/TTHad.root ${HISTO}/TTSL.root                                                     >  hadds/TT.log          2>&1" >> .haddjobs.txt
    echo "hadd -f hadds/${YEAR}/TTV.root         ${HISTO}/TTW*.root ${HISTO}/TTZ*.root                                                      >  hadds/TTV.log         2>&1" >> .haddjobs.txt
    echo "hadd -f hadds/${YEAR}/W.root           ${HISTO}/WJ*.root                                                                          >  hadds/W.log           2>&1" >> .haddjobs.txt
    echo "hadd -f hadds/${YEAR}/Z.root           ${HISTO}/ZJ*.root                                                                          >  hadds/Z.log           2>&1" >> .haddjobs.txt
    echo "hadd -f hadds/${YEAR}/VV.root          ${HISTO}/WWTo*.root ${HISTO}/WZ.root ${HISTO}/ZZTo*.root                                   >  hadds/VV.log          2>&1" >> .haddjobs.txt
    echo "hadd -f hadds/${YEAR}/Bkg.root         ${HISTO}/QCD*.root ${HISTO}/ST*.root ${HISTO}/TTHad.root ${HISTO}/TTSL.root ${HISTO}/TTW*.root ${HISTO}/TTZ*.root ${HISTO}/WJ*.root ${HISTO}/ZJ*.root ${HISTO}/WWTo*.root ${HISTO}/WZ.root ${HISTO}/ZZTo*.root >  hadds/Bkg.log 2>&1" >> .haddjobs.txt
    echo "hadd -f hadds/${YEAR}/NonQCD.root      ${HISTO}/ST*.root ${HISTO}/TTHad.root ${HISTO}/TTSL.root ${HISTO}/TTW*.root ${HISTO}/TTZ*.root ${HISTO}/WJ*.root ${HISTO}/ZJ*.root ${HISTO}/WWTo*.root ${HISTO}/WZ.root ${HISTO}/ZZTo*.root >  hadds/NonQCD.log 2>&1" >> .haddjobs.txt
    for EFT in ${FT0s}; do
        echo "hadd -f hadds/${YEAR}/WWW_${EFT}.root ${HISTO}/WWW_${EFT}.root > hadds/WWW_${EFT}.log  2>&1" >> .haddjobs.txt
        echo "hadd -f hadds/${YEAR}/WWZ_${EFT}.root ${HISTO}/WWZ_${EFT}.root > hadds/WWZ_${EFT}.log  2>&1" >> .haddjobs.txt
        echo "hadd -f hadds/${YEAR}/WZZ_${EFT}.root ${HISTO}/WZZ_${EFT}.root > hadds/WZZ_${EFT}.log  2>&1" >> .haddjobs.txt
        echo "hadd -f hadds/${YEAR}/ZZZ_${EFT}.root ${HISTO}/ZZZ_${EFT}.root > hadds/ZZZ_${EFT}.log  2>&1" >> .haddjobs.txt
        echo "hadd -f hadds/${YEAR}/VVV_${EFT}.root ${HISTO}/WWW_${EFT}.root ${HISTO}/WWZ_${EFT}.root ${HISTO}/WZZ_${EFT}.root ${HISTO}/ZZZ_${EFT}.root >  hadds/VVV_${EFT}.log 2>&1" >> .haddjobs.txt
    done
done
# TODO: Add Dim6
# echo "hadd -f hadds/${YEAR}/Dim6_WWW.root   ${HISTO}/Dim6_WWW.root                                                                       >  hadds/Dim6_WWW.log    2>&1" >> .haddjobs.txt
# echo "hadd -f hadds/${YEAR}/Dim6_WWZ.root   ${HISTO}/Dim6_WWZ.root                                                                       >  hadds/Dim6_WWZ.log    2>&1" >> .haddjobs.txt
# echo "hadd -f hadds/${YEAR}/Dim6_WZZ.root   ${HISTO}/Dim6_WZZ.root                                                                       >  hadds/Dim6_WZZ.log    2>&1" >> .haddjobs.txt
# echo "hadd -f hadds/${YEAR}/Dim6_ZZZ.root   ${HISTO}/Dim6_ZZZ.root                                                                       >  hadds/Dim6_ZZZ.log    2>&1" >> .haddjobs.txt
# echo "hadd -f hadds/${YEAR}/Dim6.root       ${HISTO}/Dim6_???.root                                                                       >  hadds/Dim6.log        2>&1" >> .haddjobs.txt
# xargs.sh .haddjobs.txt



#________________________________________________________________________________________________________________________
rm -f .allyearhaddjobs.txt
mkdir -p hadds/all
echo "hadd -f hadds/all/JetHT.root   hadds/2*/JetHT.root     >  hadds/JetHT.log   2>&1" >> .allyearhaddjobs.txt
echo "hadd -f hadds/all/QCD.root     hadds/2*/QCD.root       >  hadds/QCD.log     2>&1" >> .allyearhaddjobs.txt
echo "hadd -f hadds/all/ST.root      hadds/2*/ST.root        >  hadds/ST.log      2>&1" >> .allyearhaddjobs.txt
echo "hadd -f hadds/all/TT.root      hadds/2*/TT.root        >  hadds/TT.log      2>&1" >> .allyearhaddjobs.txt
echo "hadd -f hadds/all/TTV.root     hadds/2*/TTV.root       >  hadds/TTV.log     2>&1" >> .allyearhaddjobs.txt
echo "hadd -f hadds/all/W.root       hadds/2*/W.root         >  hadds/W.log       2>&1" >> .allyearhaddjobs.txt
echo "hadd -f hadds/all/Z.root       hadds/2*/Z.root         >  hadds/Z.log       2>&1" >> .allyearhaddjobs.txt
echo "hadd -f hadds/all/VV.root      hadds/2*/VV.root        >  hadds/VV.log      2>&1" >> .allyearhaddjobs.txt
echo "hadd -f hadds/all/Bkg.root     hadds/2*/Bkg.root       >  hadds/Bkg.log     2>&1" >> .allyearhaddjobs.txt
echo "hadd -f hadds/all/NonQCD.root  hadds/2*/NonQCD.root    >  hadds/NonQCD.log  2>&1" >> .allyearhaddjobs.txt
for EFT in ${FT0s}; do
    echo "hadd -f hadds/all/WWW_${EFT}.root hadds/2*/WWW_${EFT}.root >  hadds/WWW_${EFT}.log 2>&1" >> .allyearhaddjobs.txt
    echo "hadd -f hadds/all/WWZ_${EFT}.root hadds/2*/WWZ_${EFT}.root >  hadds/WWZ_${EFT}.log 2>&1" >> .allyearhaddjobs.txt
    echo "hadd -f hadds/all/WZZ_${EFT}.root hadds/2*/WZZ_${EFT}.root >  hadds/WZZ_${EFT}.log 2>&1" >> .allyearhaddjobs.txt
    echo "hadd -f hadds/all/ZZZ_${EFT}.root hadds/2*/ZZZ_${EFT}.root >  hadds/ZZZ_${EFT}.log 2>&1" >> .allyearhaddjobs.txt
    echo "hadd -f hadds/all/VVV_${EFT}.root hadds/2*/VVV_${EFT}.root >  hadds/VVV_${EFT}.log 2>&1" >> .allyearhaddjobs.txt
done
# xargs.sh .allyearhaddjobs.txt



##________________________________________________________________________________________________________________________
## plotting
rm -f .plot.txt
YEARS="2006 2016 2017 2018 all"
for YEAR in ${YEARS}; do
    python scripts/compute_abcd_sphere.py ${YEAR}
    #                             Plot name pattern                    Blind?[0]  DoGrep?[1]  DoYLog?[0]  YEAR?
    echo "python  scripts/plot.py "NFJGeq3All__MSD0"                   0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3All__V0"                     0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3ClosePassWP__HT_FJSR3"       1          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3CloseFailWP__HT_FJSR3"       0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3ShellPassWP__HT_FJSR3"       0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3ShellFailWP__HT_FJSR3"       0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3OpenPassWP__HT_FJSR3"        0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3OpenFailWP__HT_FJSR3"        0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3__HT_FJ"                     0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3HTFJ__HT_FJ"                 0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3SF__HT_FJ"                   0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3SF__V0"                      0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3SF__V1"                      0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3SF__V2"                      0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJEq2MSD1__V1SF"                   0          1           0           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJEq2Pt1*0*__V1SF"                 0          1           0           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3Open__V0"                    0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3Open__V1"                    0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3Open__V2"                    0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3OpenPassWP__V0"              0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3OpenPassWP__V1"              0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3OpenPassWP__V2"              0          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3ClosePassWP__sphrad"         1          0           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3OpenPassWP__Pt"              0          1           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3OpenPassWP__Nb"              0          1           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3OpenPassWP__NJ"              0          1           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3OpenPassWP__NFJ"             0          1           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3OpenPassWP__HT_FJ"           0          1           1           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3OpenPassWP__NL"              0          0           0           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3ClosePassWP__NL"             1          0           0           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3ClosePassWPHT2000__NL"       1          0           0           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot.py "NFJGeq3Close__NL"                   1          0           0           ${YEAR}" >> .plot.txt
    echo "python  scripts/plot_abcd_closure.py ${YEAR}" >> .plot.txt
done
xargs.sh .plot.txt

#python scripts/compute_v1sf.py
