#!/bin/bash

putdir=src/data/external
mkdir -p $putdir


get_files(){
  odir=$1
  shift
  utmp=$1
  shift
  mkdir -p $putdir/$odir &> /dev/null
  cd $putdir/$odir
  for ff in "$@"; do
    if [[ ! -s $ff ]]; then
      wget ${utmp}/${ff}
    fi
  done
  cd - &> /dev/null
}



main_url="https://raw.githubusercontent.com/cmstas/TopLeptonMVAInputs/master/Run2_UL"
files=( \
  el_TOPUL16APV_XGB.weights.bin \
  el_TOPUL16_XGB.weights.bin \
  el_TOPUL17_XGB.weights.bin \
  el_TOPUL18_XGB.weights.bin \
  el_TOPv2UL16APV_XGB.weights.bin \
  el_TOPv2UL16_XGB.weights.bin \
  el_TOPv2UL17_XGB.weights.bin \
  el_TOPv2UL18_XGB.weights.bin \
  mu_TOPUL16APV_XGB.weights.bin \
  mu_TOPUL16_XGB.weights.bin \
  mu_TOPUL17_XGB.weights.bin \
  mu_TOPUL18_XGB.weights.bin \
  mu_TOPv2UL16APV_XGB.weights.bin \
  mu_TOPv2UL16_XGB.weights.bin \
  mu_TOPv2UL17_XGB.weights.bin \
  mu_TOPv2UL18_XGB.weights.bin \
)
get_files TopLeptonMVA ${main_url} "${files[@]}"

main_url=https://github.com/cms-jet/JECDatabase/raw/master/tarballs
files=( \
  Summer19UL16APV_V7_MC.tar.gz \
  Summer19UL16APV_RunBCD_V7_DATA.tar.gz \
  Summer19UL16APV_RunEF_V7_DATA.tar.gz \
  Summer19UL16_V7_MC.tar.gz \
  Summer19UL16_RunFGH_V7_DATA.tar.gz \
  Summer19UL17_V5_MC.tar.gz \
  Summer19UL17_RunB_V5_DATA.tar.gz \
  Summer19UL17_RunC_V5_DATA.tar.gz \
  Summer19UL17_RunD_V5_DATA.tar.gz \
  Summer19UL17_RunE_V5_DATA.tar.gz \
  Summer19UL17_RunF_V5_DATA.tar.gz \
  Summer19UL18_V5_MC.tar.gz \
  Summer19UL18_RunA_V5_DATA.tar.gz \
  Summer19UL18_RunB_V5_DATA.tar.gz \
  Summer19UL18_RunC_V5_DATA.tar.gz \
  Summer19UL18_RunD_V5_DATA.tar.gz \
)
get_files JetMET/JES ${main_url} "${files[@]}"
cd ${putdir}/JetMET/JES
for ff in $(ls *.tar*); do
  tar xvf $ff --exclude='\._*' --exclude='*UncertaintySources*' '*AK4PFchs*' '*AK8PFPuppi*'
  rm $ff
done
cd - &> /dev/null

main_url=https://github.com/cms-jet/JRDatabase/raw/master/tarballs
files=( \
  Summer20UL16APV_JRV3_MC.tar.gz \
  Summer20UL16_JRV3_MC.tar.gz \
  Summer19UL17_JRV2_MC.tar.gz \
  Summer19UL18_JRV2_MC.tar.gz \
)
get_files JetMET/JER ${main_url} "${files[@]}"
cd ${putdir}/JetMET/JER
for ff in $(ls *.tar*); do
  tar xvf $ff --exclude='\._*' '*AK4PFchs*' '*AK8PFPuppi*'
  rm $ff
done
cd - &> /dev/null

main_url=https://raw.githubusercontent.com/cmstas/CMSScaleFactors/master/BTV
files=(\
  wp_deepJet_106XUL16preVFP_v2.csv \
  wp_deepJet_106XUL16postVFP_v3.csv \
  wp_deepJet_106XUL17_v3.csv \
  wp_deepJet_106XUL18_v2.csv \
)
get_files BTagging/ScaleFactors ${main_url} "${files[@]}"
