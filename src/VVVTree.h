// -*- C++ -*-
// This is a header file generated with the command:
<<<<<<< HEAD
// makeCMS3ClassFiles("/eos/uscms/store/user/lpcvvv/horyn/VVVAnalysis/Nov15_AllHad_allYears/2006/merged/WZ.root", "t", "VVVTree", "tas", "vvv")
=======
// makeCMS3ClassFiles("/uscms/home/ymiao/nobackup/VVV/EFTAnalysisLooper/uncertainty_type1/VVVNanoLooper/WWW_DIM6_1.root", "t", "VVVTree", "tas", "vvv")
>>>>>>> e7aa48f9a58bade6a661fc8a4a00319be7a69c69

#ifndef VVVTree_H
#define VVVTree_H

#include "Math/GenVector/PtEtaPhiM4D.h"
#include "Math/LorentzVector.h"
#include "Math/Point3D.h"
#include "TMath.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"
#include "TBits.h"
#include <vector> 
#include <unistd.h> 
typedef ROOT::Math::LorentzVector< ROOT::Math::PtEtaPhiM4D<float> > LorentzVector;

using namespace std; 
class VVVTree {
 private: 
 protected: 
  unsigned int index;
//---------------------------------------------------------------------------------
/*                           Common_isData*/  int      Common_isData_;
/*                           Common_isData*/  TBranch *Common_isData_branch;
/*                           Common_isData*/  bool     Common_isData_isLoaded;
//---------------------------------------------------------------------------------
/*                              Common_run*/  int      Common_run_;
/*                              Common_run*/  TBranch *Common_run_branch;
/*                              Common_run*/  bool     Common_run_isLoaded;
//---------------------------------------------------------------------------------
/*                             Common_lumi*/  int      Common_lumi_;
/*                             Common_lumi*/  TBranch *Common_lumi_branch;
/*                             Common_lumi*/  bool     Common_lumi_isLoaded;
//---------------------------------------------------------------------------------
/*                              Common_evt*/  unsigned long long Common_evt_;
/*                              Common_evt*/  TBranch *Common_evt_branch;
/*                              Common_evt*/  bool     Common_evt_isLoaded;
//---------------------------------------------------------------------------------
/*                             Common_year*/  int      Common_year_;
/*                             Common_year*/  TBranch *Common_year_branch;
/*                             Common_year*/  bool     Common_year_isLoaded;
//---------------------------------------------------------------------------------
/*                        Common_genWeight*/  float    Common_genWeight_;
/*                        Common_genWeight*/  TBranch *Common_genWeight_branch;
/*                        Common_genWeight*/  bool     Common_genWeight_isLoaded;
//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/  float    Common_btagWeight_DeepCSVB_;
/*              Common_btagWeight_DeepCSVB*/  TBranch *Common_btagWeight_DeepCSVB_branch;
/*              Common_btagWeight_DeepCSVB*/  bool     Common_btagWeight_DeepCSVB_isLoaded;
//---------------------------------------------------------------------------------
/*                              Common_wgt*/  float    Common_wgt_;
/*                              Common_wgt*/  TBranch *Common_wgt_branch;
/*                              Common_wgt*/  bool     Common_wgt_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_LHEWeight_mg_reweighting*/  vector<float> *Common_LHEWeight_mg_reweighting_;
/*         Common_LHEWeight_mg_reweighting*/  TBranch *Common_LHEWeight_mg_reweighting_branch;
/*         Common_LHEWeight_mg_reweighting*/  bool     Common_LHEWeight_mg_reweighting_isLoaded;
//---------------------------------------------------------------------------------
/*                        Common_event_PDF*/  vector<float> *Common_event_PDF_;
/*                        Common_event_PDF*/  TBranch *Common_event_PDF_branch;
/*                        Common_event_PDF*/  bool     Common_event_PDF_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_event_QCDScale*/  vector<float> *Common_event_QCDScale_;
/*                   Common_event_QCDScale*/  TBranch *Common_event_QCDScale_branch;
/*                   Common_event_QCDScale*/  bool     Common_event_QCDScale_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_event_puWeight*/  float    Common_event_puWeight_;
/*                   Common_event_puWeight*/  TBranch *Common_event_puWeight_branch;
/*                   Common_event_puWeight*/  bool     Common_event_puWeight_isLoaded;
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightup*/  float    Common_event_puWeightup_;
/*                 Common_event_puWeightup*/  TBranch *Common_event_puWeightup_branch;
/*                 Common_event_puWeightup*/  bool     Common_event_puWeightup_isLoaded;
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightdn*/  float    Common_event_puWeightdn_;
/*                 Common_event_puWeightdn*/  TBranch *Common_event_puWeightdn_branch;
/*                 Common_event_puWeightdn*/  bool     Common_event_puWeightdn_isLoaded;
//---------------------------------------------------------------------------------
/*              Common_event_prefireWeight*/  float    Common_event_prefireWeight_;
/*              Common_event_prefireWeight*/  TBranch *Common_event_prefireWeight_branch;
/*              Common_event_prefireWeight*/  bool     Common_event_prefireWeight_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightup*/  float    Common_event_prefireWeightup_;
/*            Common_event_prefireWeightup*/  TBranch *Common_event_prefireWeightup_branch;
/*            Common_event_prefireWeightup*/  bool     Common_event_prefireWeightup_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightdn*/  float    Common_event_prefireWeightdn_;
/*            Common_event_prefireWeightdn*/  TBranch *Common_event_prefireWeightdn_branch;
/*            Common_event_prefireWeightdn*/  bool     Common_event_prefireWeightdn_isLoaded;
//---------------------------------------------------------------------------------
/*              Common_event_triggerWeight*/  float    Common_event_triggerWeight_;
/*              Common_event_triggerWeight*/  TBranch *Common_event_triggerWeight_branch;
/*              Common_event_triggerWeight*/  bool     Common_event_triggerWeight_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightup*/  float    Common_event_triggerWeightup_;
/*            Common_event_triggerWeightup*/  TBranch *Common_event_triggerWeightup_branch;
/*            Common_event_triggerWeightup*/  bool     Common_event_triggerWeightup_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightdn*/  float    Common_event_triggerWeightdn_;
/*            Common_event_triggerWeightdn*/  TBranch *Common_event_triggerWeightdn_branch;
/*            Common_event_triggerWeightdn*/  bool     Common_event_triggerWeightdn_isLoaded;
//---------------------------------------------------------------------------------
/*             Common_LHEReweightingWeight*/  vector<float> *Common_LHEReweightingWeight_;
/*             Common_LHEReweightingWeight*/  TBranch *Common_LHEReweightingWeight_branch;
/*             Common_LHEReweightingWeight*/  bool     Common_LHEReweightingWeight_isLoaded;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  bool     Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_;
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  TBranch *Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch;
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  bool     Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_isLoaded;
//---------------------------------------------------------------------------------
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  bool     Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_;
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  TBranch *Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch;
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  bool     Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_isLoaded;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  bool     Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_;
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  TBranch *Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch;
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  bool     Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_isLoaded;
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  bool     Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_;
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  TBranch *Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch;
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  bool     Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded;
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  bool     Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_;
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  TBranch *Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch;
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  bool     Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  bool     Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_;
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  TBranch *Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch;
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  bool     Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  bool     Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_;
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  TBranch *Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch;
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  bool     Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  bool     Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_;
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  TBranch *Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch;
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  bool     Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  bool     Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_;
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  TBranch *Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch;
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  bool     Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_isLoaded;
//---------------------------------------------------------------------------------
/*                      Common_HLT_IsoMu24*/  bool     Common_HLT_IsoMu24_;
/*                      Common_HLT_IsoMu24*/  TBranch *Common_HLT_IsoMu24_branch;
/*                      Common_HLT_IsoMu24*/  bool     Common_HLT_IsoMu24_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_HLT_Ele32_WPTight*/  bool     Common_HLT_Ele32_WPTight_;
/*                Common_HLT_Ele32_WPTight*/  TBranch *Common_HLT_Ele32_WPTight_branch;
/*                Common_HLT_Ele32_WPTight*/  bool     Common_HLT_Ele32_WPTight_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_HLT_PFHT1050*/  bool     Common_HLT_PFHT1050_;
/*                     Common_HLT_PFHT1050*/  TBranch *Common_HLT_PFHT1050_branch;
/*                     Common_HLT_PFHT1050*/  bool     Common_HLT_PFHT1050_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_HLT_AK8PFJet500*/  bool     Common_HLT_AK8PFJet500_;
/*                  Common_HLT_AK8PFJet500*/  TBranch *Common_HLT_AK8PFJet500_branch;
/*                  Common_HLT_AK8PFJet500*/  bool     Common_HLT_AK8PFJet500_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet380_TrimMass30*/  bool     Common_HLT_AK8PFJet380_TrimMass30_;
/*       Common_HLT_AK8PFJet380_TrimMass30*/  TBranch *Common_HLT_AK8PFJet380_TrimMass30_branch;
/*       Common_HLT_AK8PFJet380_TrimMass30*/  bool     Common_HLT_AK8PFJet380_TrimMass30_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet360_TrimMass30*/  bool     Common_HLT_AK8PFJet360_TrimMass30_;
/*       Common_HLT_AK8PFJet360_TrimMass30*/  TBranch *Common_HLT_AK8PFJet360_TrimMass30_branch;
/*       Common_HLT_AK8PFJet360_TrimMass30*/  bool     Common_HLT_AK8PFJet360_TrimMass30_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet400_TrimMass30*/  bool     Common_HLT_AK8PFJet400_TrimMass30_;
/*       Common_HLT_AK8PFJet400_TrimMass30*/  TBranch *Common_HLT_AK8PFJet400_TrimMass30_branch;
/*       Common_HLT_AK8PFJet400_TrimMass30*/  bool     Common_HLT_AK8PFJet400_TrimMass30_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet420_TrimMass30*/  bool     Common_HLT_AK8PFJet420_TrimMass30_;
/*       Common_HLT_AK8PFJet420_TrimMass30*/  TBranch *Common_HLT_AK8PFJet420_TrimMass30_branch;
/*       Common_HLT_AK8PFJet420_TrimMass30*/  bool     Common_HLT_AK8PFJet420_TrimMass30_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT750_TrimMass50*/  bool     Common_HLT_AK8PFHT750_TrimMass50_;
/*        Common_HLT_AK8PFHT750_TrimMass50*/  TBranch *Common_HLT_AK8PFHT750_TrimMass50_branch;
/*        Common_HLT_AK8PFHT750_TrimMass50*/  bool     Common_HLT_AK8PFHT750_TrimMass50_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT800_TrimMass50*/  bool     Common_HLT_AK8PFHT800_TrimMass50_;
/*        Common_HLT_AK8PFHT800_TrimMass50*/  TBranch *Common_HLT_AK8PFHT800_TrimMass50_branch;
/*        Common_HLT_AK8PFHT800_TrimMass50*/  bool     Common_HLT_AK8PFHT800_TrimMass50_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT850_TrimMass50*/  bool     Common_HLT_AK8PFHT850_TrimMass50_;
/*        Common_HLT_AK8PFHT850_TrimMass50*/  TBranch *Common_HLT_AK8PFHT850_TrimMass50_branch;
/*        Common_HLT_AK8PFHT850_TrimMass50*/  bool     Common_HLT_AK8PFHT850_TrimMass50_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT900_TrimMass50*/  bool     Common_HLT_AK8PFHT900_TrimMass50_;
/*        Common_HLT_AK8PFHT900_TrimMass50*/  TBranch *Common_HLT_AK8PFHT900_TrimMass50_branch;
/*        Common_HLT_AK8PFHT900_TrimMass50*/  bool     Common_HLT_AK8PFHT900_TrimMass50_isLoaded;
//---------------------------------------------------------------------------------
/*Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5*/  bool     Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_;
/*Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5*/  TBranch *Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch;
/*Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5*/  bool     Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_isLoaded;
//---------------------------------------------------------------------------------
/*Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5*/  bool     Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_;
/*Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5*/  TBranch *Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch;
/*Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5*/  bool     Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_isLoaded;
//---------------------------------------------------------------------------------
/*                      Common_HLT_PFHT800*/  bool     Common_HLT_PFHT800_;
/*                      Common_HLT_PFHT800*/  TBranch *Common_HLT_PFHT800_branch;
/*                      Common_HLT_PFHT800*/  bool     Common_HLT_PFHT800_isLoaded;
//---------------------------------------------------------------------------------
/*                      Common_HLT_PFHT900*/  bool     Common_HLT_PFHT900_;
/*                      Common_HLT_PFHT900*/  TBranch *Common_HLT_PFHT900_branch;
/*                      Common_HLT_PFHT900*/  bool     Common_HLT_PFHT900_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_HLT_PFJet450*/  bool     Common_HLT_PFJet450_;
/*                     Common_HLT_PFJet450*/  TBranch *Common_HLT_PFJet450_branch;
/*                     Common_HLT_PFJet450*/  bool     Common_HLT_PFJet450_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_HLT_PFJet500*/  bool     Common_HLT_PFJet500_;
/*                     Common_HLT_PFJet500*/  TBranch *Common_HLT_PFJet500_branch;
/*                     Common_HLT_PFJet500*/  bool     Common_HLT_PFJet500_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_HLT_AK8PFJet450*/  bool     Common_HLT_AK8PFJet450_;
/*                  Common_HLT_AK8PFJet450*/  TBranch *Common_HLT_AK8PFJet450_branch;
/*                  Common_HLT_AK8PFJet450*/  bool     Common_HLT_AK8PFJet450_isLoaded;
//---------------------------------------------------------------------------------
/*Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50*/  bool     Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_;
/*Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50*/  TBranch *Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch;
/*Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50*/  bool     Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleEl*/  bool     Common_HLT_DoubleEl_;
/*                     Common_HLT_DoubleEl*/  TBranch *Common_HLT_DoubleEl_branch;
/*                     Common_HLT_DoubleEl*/  bool     Common_HLT_DoubleEl_isLoaded;
//---------------------------------------------------------------------------------
/*                         Common_HLT_MuEG*/  bool     Common_HLT_MuEG_;
/*                         Common_HLT_MuEG*/  TBranch *Common_HLT_MuEG_branch;
/*                         Common_HLT_MuEG*/  bool     Common_HLT_MuEG_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleMu*/  bool     Common_HLT_DoubleMu_;
/*                     Common_HLT_DoubleMu*/  TBranch *Common_HLT_DoubleMu_branch;
/*                     Common_HLT_DoubleMu*/  bool     Common_HLT_DoubleMu_isLoaded;
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_ee_em_mm*/  bool     Common_pass_duplicate_removal_ee_em_mm_;
/*  Common_pass_duplicate_removal_ee_em_mm*/  TBranch *Common_pass_duplicate_removal_ee_em_mm_branch;
/*  Common_pass_duplicate_removal_ee_em_mm*/  bool     Common_pass_duplicate_removal_ee_em_mm_isLoaded;
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_mm_em_ee*/  bool     Common_pass_duplicate_removal_mm_em_ee_;
/*  Common_pass_duplicate_removal_mm_em_ee*/  TBranch *Common_pass_duplicate_removal_mm_em_ee_branch;
/*  Common_pass_duplicate_removal_mm_em_ee*/  bool     Common_pass_duplicate_removal_mm_em_ee_isLoaded;
//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/  bool     Common_noiseFlag_;
/*                        Common_noiseFlag*/  TBranch *Common_noiseFlag_branch;
/*                        Common_noiseFlag*/  bool     Common_noiseFlag_isLoaded;
//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/  bool     Common_noiseFlagMC_;
/*                      Common_noiseFlagMC*/  TBranch *Common_noiseFlagMC_branch;
/*                      Common_noiseFlagMC*/  bool     Common_noiseFlagMC_isLoaded;
//---------------------------------------------------------------------------------
/*                      Common_passGoodRun*/  bool     Common_passGoodRun_;
/*                      Common_passGoodRun*/  TBranch *Common_passGoodRun_branch;
/*                      Common_passGoodRun*/  bool     Common_passGoodRun_isLoaded;
//---------------------------------------------------------------------------------
/*                           Common_met_p4*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_;
/*                           Common_met_p4*/  TBranch *Common_met_p4_branch;
/*                           Common_met_p4*/  bool     Common_met_p4_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesup_;
/*                     Common_met_p4_jesup*/  TBranch *Common_met_p4_jesup_branch;
/*                     Common_met_p4_jesup*/  bool     Common_met_p4_jesup_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesdn_;
/*                     Common_met_p4_jesdn*/  TBranch *Common_met_p4_jesdn_branch;
/*                     Common_met_p4_jesdn*/  bool     Common_met_p4_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jerup_;
/*                     Common_met_p4_jerup*/  TBranch *Common_met_p4_jerup_branch;
/*                     Common_met_p4_jerup*/  bool     Common_met_p4_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jerdn_;
/*                     Common_met_p4_jerdn*/  TBranch *Common_met_p4_jerdn_branch;
/*                     Common_met_p4_jerdn*/  bool     Common_met_p4_jerdn_isLoaded;
//---------------------------------------------------------------------------------
/*                      Common_event_lepSF*/  float    Common_event_lepSF_;
/*                      Common_event_lepSF*/  TBranch *Common_event_lepSF_branch;
/*                      Common_event_lepSF*/  bool     Common_event_lepSF_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFelup*/  float    Common_event_lepSFelup_;
/*                  Common_event_lepSFelup*/  TBranch *Common_event_lepSFelup_branch;
/*                  Common_event_lepSFelup*/  bool     Common_event_lepSFelup_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFeldn*/  float    Common_event_lepSFeldn_;
/*                  Common_event_lepSFeldn*/  TBranch *Common_event_lepSFeldn_branch;
/*                  Common_event_lepSFeldn*/  bool     Common_event_lepSFeldn_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmuup*/  float    Common_event_lepSFmuup_;
/*                  Common_event_lepSFmuup*/  TBranch *Common_event_lepSFmuup_branch;
/*                  Common_event_lepSFmuup*/  bool     Common_event_lepSFmuup_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmudn*/  float    Common_event_lepSFmudn_;
/*                  Common_event_lepSFmudn*/  TBranch *Common_event_lepSFmudn_branch;
/*                  Common_event_lepSFmudn*/  bool     Common_event_lepSFmudn_isLoaded;
//---------------------------------------------------------------------------------
/*                 Common_event_lepSFTight*/  float    Common_event_lepSFTight_;
/*                 Common_event_lepSFTight*/  TBranch *Common_event_lepSFTight_branch;
/*                 Common_event_lepSFTight*/  bool     Common_event_lepSFTight_isLoaded;
//---------------------------------------------------------------------------------
/*             Common_event_lepSFelupTight*/  float    Common_event_lepSFelupTight_;
/*             Common_event_lepSFelupTight*/  TBranch *Common_event_lepSFelupTight_branch;
/*             Common_event_lepSFelupTight*/  bool     Common_event_lepSFelupTight_isLoaded;
//---------------------------------------------------------------------------------
/*             Common_event_lepSFeldnTight*/  float    Common_event_lepSFeldnTight_;
/*             Common_event_lepSFeldnTight*/  TBranch *Common_event_lepSFeldnTight_branch;
/*             Common_event_lepSFeldnTight*/  bool     Common_event_lepSFeldnTight_isLoaded;
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmuupTight*/  float    Common_event_lepSFmuupTight_;
/*             Common_event_lepSFmuupTight*/  TBranch *Common_event_lepSFmuupTight_branch;
/*             Common_event_lepSFmuupTight*/  bool     Common_event_lepSFmuupTight_isLoaded;
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmudnTight*/  float    Common_event_lepSFmudnTight_;
/*             Common_event_lepSFmudnTight*/  TBranch *Common_event_lepSFmudnTight_branch;
/*             Common_event_lepSFmudnTight*/  bool     Common_event_lepSFmudnTight_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_event_tightBtagSF*/  float    Common_event_tightBtagSF_;
/*                Common_event_tightBtagSF*/  TBranch *Common_event_tightBtagSF_branch;
/*                Common_event_tightBtagSF*/  bool     Common_event_tightBtagSF_isLoaded;
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFup*/  float    Common_event_tightBtagSFup_;
/*              Common_event_tightBtagSFup*/  TBranch *Common_event_tightBtagSFup_branch;
/*              Common_event_tightBtagSFup*/  bool     Common_event_tightBtagSFup_isLoaded;
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFdn*/  float    Common_event_tightBtagSFdn_;
/*              Common_event_tightBtagSFdn*/  TBranch *Common_event_tightBtagSFdn_branch;
/*              Common_event_tightBtagSFdn*/  bool     Common_event_tightBtagSFdn_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFup*/  float    Common_event_tightBtagSFHFup_;
/*            Common_event_tightBtagSFHFup*/  TBranch *Common_event_tightBtagSFHFup_branch;
/*            Common_event_tightBtagSFHFup*/  bool     Common_event_tightBtagSFHFup_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFdn*/  float    Common_event_tightBtagSFHFdn_;
/*            Common_event_tightBtagSFHFdn*/  TBranch *Common_event_tightBtagSFHFdn_branch;
/*            Common_event_tightBtagSFHFdn*/  bool     Common_event_tightBtagSFHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFup*/  float    Common_event_tightBtagSFLFup_;
/*            Common_event_tightBtagSFLFup*/  TBranch *Common_event_tightBtagSFLFup_branch;
/*            Common_event_tightBtagSFLFup*/  bool     Common_event_tightBtagSFLFup_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFdn*/  float    Common_event_tightBtagSFLFdn_;
/*            Common_event_tightBtagSFLFdn*/  TBranch *Common_event_tightBtagSFLFdn_branch;
/*            Common_event_tightBtagSFLFdn*/  bool     Common_event_tightBtagSFLFdn_isLoaded;
//---------------------------------------------------------------------------------
/*               Common_event_mediumBtagSF*/  float    Common_event_mediumBtagSF_;
/*               Common_event_mediumBtagSF*/  TBranch *Common_event_mediumBtagSF_branch;
/*               Common_event_mediumBtagSF*/  bool     Common_event_mediumBtagSF_isLoaded;
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFup*/  float    Common_event_mediumBtagSFup_;
/*             Common_event_mediumBtagSFup*/  TBranch *Common_event_mediumBtagSFup_branch;
/*             Common_event_mediumBtagSFup*/  bool     Common_event_mediumBtagSFup_isLoaded;
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFdn*/  float    Common_event_mediumBtagSFdn_;
/*             Common_event_mediumBtagSFdn*/  TBranch *Common_event_mediumBtagSFdn_branch;
/*             Common_event_mediumBtagSFdn*/  bool     Common_event_mediumBtagSFdn_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFup*/  float    Common_event_mediumBtagSFHFup_;
/*           Common_event_mediumBtagSFHFup*/  TBranch *Common_event_mediumBtagSFHFup_branch;
/*           Common_event_mediumBtagSFHFup*/  bool     Common_event_mediumBtagSFHFup_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFdn*/  float    Common_event_mediumBtagSFHFdn_;
/*           Common_event_mediumBtagSFHFdn*/  TBranch *Common_event_mediumBtagSFHFdn_branch;
/*           Common_event_mediumBtagSFHFdn*/  bool     Common_event_mediumBtagSFHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFup*/  float    Common_event_mediumBtagSFLFup_;
/*           Common_event_mediumBtagSFLFup*/  TBranch *Common_event_mediumBtagSFLFup_branch;
/*           Common_event_mediumBtagSFLFup*/  bool     Common_event_mediumBtagSFLFup_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFdn*/  float    Common_event_mediumBtagSFLFdn_;
/*           Common_event_mediumBtagSFLFdn*/  TBranch *Common_event_mediumBtagSFLFdn_branch;
/*           Common_event_mediumBtagSFLFdn*/  bool     Common_event_mediumBtagSFLFdn_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_event_looseBtagSF*/  float    Common_event_looseBtagSF_;
/*                Common_event_looseBtagSF*/  TBranch *Common_event_looseBtagSF_branch;
/*                Common_event_looseBtagSF*/  bool     Common_event_looseBtagSF_isLoaded;
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFup*/  float    Common_event_looseBtagSFup_;
/*              Common_event_looseBtagSFup*/  TBranch *Common_event_looseBtagSFup_branch;
/*              Common_event_looseBtagSFup*/  bool     Common_event_looseBtagSFup_isLoaded;
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFdn*/  float    Common_event_looseBtagSFdn_;
/*              Common_event_looseBtagSFdn*/  TBranch *Common_event_looseBtagSFdn_branch;
/*              Common_event_looseBtagSFdn*/  bool     Common_event_looseBtagSFdn_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFup*/  float    Common_event_looseBtagSFHFup_;
/*            Common_event_looseBtagSFHFup*/  TBranch *Common_event_looseBtagSFHFup_branch;
/*            Common_event_looseBtagSFHFup*/  bool     Common_event_looseBtagSFHFup_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFdn*/  float    Common_event_looseBtagSFHFdn_;
/*            Common_event_looseBtagSFHFdn*/  TBranch *Common_event_looseBtagSFHFdn_branch;
/*            Common_event_looseBtagSFHFdn*/  bool     Common_event_looseBtagSFHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFup*/  float    Common_event_looseBtagSFLFup_;
/*            Common_event_looseBtagSFLFup*/  TBranch *Common_event_looseBtagSFLFup_branch;
/*            Common_event_looseBtagSFLFup*/  bool     Common_event_looseBtagSFLFup_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFdn*/  float    Common_event_looseBtagSFLFdn_;
/*            Common_event_looseBtagSFLFdn*/  TBranch *Common_event_looseBtagSFLFdn_branch;
/*            Common_event_looseBtagSFLFdn*/  bool     Common_event_looseBtagSFLFdn_isLoaded;
//---------------------------------------------------------------------------------
/*                           Common_lep_p4*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_lep_p4_;
/*                           Common_lep_p4*/  TBranch *Common_lep_p4_branch;
/*                           Common_lep_p4*/  bool     Common_lep_p4_isLoaded;
//---------------------------------------------------------------------------------
/*                         Common_lep_idxs*/  vector<int> *Common_lep_idxs_;
/*                         Common_lep_idxs*/  TBranch *Common_lep_idxs_branch;
/*                         Common_lep_idxs*/  bool     Common_lep_idxs_isLoaded;
//---------------------------------------------------------------------------------
/*                        Common_lep_pdgid*/  vector<int> *Common_lep_pdgid_;
/*                        Common_lep_pdgid*/  TBranch *Common_lep_pdgid_branch;
/*                        Common_lep_pdgid*/  bool     Common_lep_pdgid_isLoaded;
//---------------------------------------------------------------------------------
/*                        Common_lep_tight*/  vector<int> *Common_lep_tight_;
/*                        Common_lep_tight*/  TBranch *Common_lep_tight_branch;
/*                        Common_lep_tight*/  bool     Common_lep_tight_isLoaded;
//---------------------------------------------------------------------------------
/*                          Common_lep_dxy*/  vector<float> *Common_lep_dxy_;
/*                          Common_lep_dxy*/  TBranch *Common_lep_dxy_branch;
/*                          Common_lep_dxy*/  bool     Common_lep_dxy_isLoaded;
//---------------------------------------------------------------------------------
/*                           Common_lep_dz*/  vector<float> *Common_lep_dz_;
/*                           Common_lep_dz*/  TBranch *Common_lep_dz_branch;
/*                           Common_lep_dz*/  bool     Common_lep_dz_isLoaded;
//---------------------------------------------------------------------------------
/*                         Common_lep_ip3d*/  vector<float> *Common_lep_ip3d_;
/*                         Common_lep_ip3d*/  TBranch *Common_lep_ip3d_branch;
/*                         Common_lep_ip3d*/  bool     Common_lep_ip3d_isLoaded;
//---------------------------------------------------------------------------------
/*                        Common_lep_sip3d*/  vector<float> *Common_lep_sip3d_;
/*                        Common_lep_sip3d*/  TBranch *Common_lep_sip3d_branch;
/*                        Common_lep_sip3d*/  bool     Common_lep_sip3d_isLoaded;
//---------------------------------------------------------------------------------
/*                           Common_lep_SF*/  vector<float> *Common_lep_SF_;
/*                           Common_lep_SF*/  TBranch *Common_lep_SF_branch;
/*                           Common_lep_SF*/  bool     Common_lep_SF_isLoaded;
//---------------------------------------------------------------------------------
/*                      Common_lep_SFTight*/  vector<float> *Common_lep_SFTight_;
/*                      Common_lep_SFTight*/  TBranch *Common_lep_SFTight_branch;
/*                      Common_lep_SFTight*/  bool     Common_lep_SFTight_isLoaded;
//---------------------------------------------------------------------------------
/*                         Common_lep_SFdn*/  vector<float> *Common_lep_SFdn_;
/*                         Common_lep_SFdn*/  TBranch *Common_lep_SFdn_branch;
/*                         Common_lep_SFdn*/  bool     Common_lep_SFdn_isLoaded;
//---------------------------------------------------------------------------------
/*                    Common_lep_SFdnTight*/  vector<float> *Common_lep_SFdnTight_;
/*                    Common_lep_SFdnTight*/  TBranch *Common_lep_SFdnTight_branch;
/*                    Common_lep_SFdnTight*/  bool     Common_lep_SFdnTight_isLoaded;
//---------------------------------------------------------------------------------
/*                         Common_lep_SFup*/  vector<float> *Common_lep_SFup_;
/*                         Common_lep_SFup*/  TBranch *Common_lep_SFup_branch;
/*                         Common_lep_SFup*/  bool     Common_lep_SFup_isLoaded;
//---------------------------------------------------------------------------------
/*                    Common_lep_SFupTight*/  vector<float> *Common_lep_SFupTight_;
/*                    Common_lep_SFupTight*/  TBranch *Common_lep_SFupTight_branch;
/*                    Common_lep_SFupTight*/  bool     Common_lep_SFupTight_isLoaded;
//---------------------------------------------------------------------------------
/*                           Common_jet_p4*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_;
/*                           Common_jet_p4*/  TBranch *Common_jet_p4_branch;
/*                           Common_jet_p4*/  bool     Common_jet_p4_isLoaded;
//---------------------------------------------------------------------------------
/*                         Common_jet_idxs*/  vector<int> *Common_jet_idxs_;
/*                         Common_jet_idxs*/  TBranch *Common_jet_idxs_branch;
/*                         Common_jet_idxs*/  bool     Common_jet_idxs_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_jet_passBloose*/  vector<bool> *Common_jet_passBloose_;
/*                   Common_jet_passBloose*/  TBranch *Common_jet_passBloose_branch;
/*                   Common_jet_passBloose*/  bool     Common_jet_passBloose_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_jet_passBmedium*/  vector<bool> *Common_jet_passBmedium_;
/*                  Common_jet_passBmedium*/  TBranch *Common_jet_passBmedium_branch;
/*                  Common_jet_passBmedium*/  bool     Common_jet_passBmedium_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_jet_passBtight*/  vector<bool> *Common_jet_passBtight_;
/*                   Common_jet_passBtight*/  TBranch *Common_jet_passBtight_branch;
/*                   Common_jet_passBtight*/  bool     Common_jet_passBtight_isLoaded;
//---------------------------------------------------------------------------------
/*                           Common_jet_id*/  vector<int> *Common_jet_id_;
/*                           Common_jet_id*/  TBranch *Common_jet_id_branch;
/*                           Common_jet_id*/  bool     Common_jet_id_isLoaded;
//---------------------------------------------------------------------------------
/*                         Common_jet_puid*/  vector<int> *Common_jet_puid_;
/*                         Common_jet_puid*/  TBranch *Common_jet_puid_branch;
/*                         Common_jet_puid*/  bool     Common_jet_puid_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_jet_overlapfatjet*/  vector<int> *Common_jet_overlapfatjet_;
/*                Common_jet_overlapfatjet*/  TBranch *Common_jet_overlapfatjet_branch;
/*                Common_jet_overlapfatjet*/  bool     Common_jet_overlapfatjet_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesup*/  vector<float> *Common_jet_pt_jesup_;
/*                     Common_jet_pt_jesup*/  TBranch *Common_jet_pt_jesup_branch;
/*                     Common_jet_pt_jesup*/  bool     Common_jet_pt_jesup_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesdn*/  vector<float> *Common_jet_pt_jesdn_;
/*                     Common_jet_pt_jesdn*/  TBranch *Common_jet_pt_jesdn_branch;
/*                     Common_jet_pt_jesdn*/  bool     Common_jet_pt_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerup*/  vector<float> *Common_jet_pt_jerup_;
/*                     Common_jet_pt_jerup*/  TBranch *Common_jet_pt_jerup_branch;
/*                     Common_jet_pt_jerup*/  bool     Common_jet_pt_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerdn*/  vector<float> *Common_jet_pt_jerdn_;
/*                     Common_jet_pt_jerdn*/  TBranch *Common_jet_pt_jerdn_branch;
/*                     Common_jet_pt_jerdn*/  bool     Common_jet_pt_jerdn_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesup*/  vector<float> *Common_jet_mass_jesup_;
/*                   Common_jet_mass_jesup*/  TBranch *Common_jet_mass_jesup_branch;
/*                   Common_jet_mass_jesup*/  bool     Common_jet_mass_jesup_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesdn*/  vector<float> *Common_jet_mass_jesdn_;
/*                   Common_jet_mass_jesdn*/  TBranch *Common_jet_mass_jesdn_branch;
/*                   Common_jet_mass_jesdn*/  bool     Common_jet_mass_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerup*/  vector<float> *Common_jet_mass_jerup_;
/*                   Common_jet_mass_jerup*/  TBranch *Common_jet_mass_jerup_branch;
/*                   Common_jet_mass_jerup*/  bool     Common_jet_mass_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerdn*/  vector<float> *Common_jet_mass_jerdn_;
/*                   Common_jet_mass_jerdn*/  TBranch *Common_jet_mass_jerdn_branch;
/*                   Common_jet_mass_jerdn*/  bool     Common_jet_mass_jerdn_isLoaded;
//---------------------------------------------------------------------------------
/*                        Common_fatjet_p4*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_;
/*                        Common_fatjet_p4*/  TBranch *Common_fatjet_p4_branch;
/*                        Common_fatjet_p4*/  bool     Common_fatjet_p4_isLoaded;
//---------------------------------------------------------------------------------
/*                      Common_fatjet_idxs*/  vector<int> *Common_fatjet_idxs_;
/*                      Common_fatjet_idxs*/  TBranch *Common_fatjet_idxs_branch;
/*                      Common_fatjet_idxs*/  bool     Common_fatjet_idxs_isLoaded;
//---------------------------------------------------------------------------------
/*                        Common_fatjet_id*/  vector<int> *Common_fatjet_id_;
/*                        Common_fatjet_id*/  TBranch *Common_fatjet_id_branch;
/*                        Common_fatjet_id*/  bool     Common_fatjet_id_isLoaded;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_msoftdrop*/  vector<float> *Common_fatjet_msoftdrop_;
/*                 Common_fatjet_msoftdrop*/  TBranch *Common_fatjet_msoftdrop_branch;
/*                 Common_fatjet_msoftdrop*/  bool     Common_fatjet_msoftdrop_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_W*/  vector<float> *Common_fatjet_deepMD_W_;
/*                  Common_fatjet_deepMD_W*/  TBranch *Common_fatjet_deepMD_W_branch;
/*                  Common_fatjet_deepMD_W*/  bool     Common_fatjet_deepMD_W_isLoaded;
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_W*/  vector<float> *Common_fatjet_deep_W_;
/*                    Common_fatjet_deep_W*/  TBranch *Common_fatjet_deep_W_branch;
/*                    Common_fatjet_deep_W*/  bool     Common_fatjet_deep_W_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_Z*/  vector<float> *Common_fatjet_deepMD_Z_;
/*                  Common_fatjet_deepMD_Z*/  TBranch *Common_fatjet_deepMD_Z_branch;
/*                  Common_fatjet_deepMD_Z*/  bool     Common_fatjet_deepMD_Z_isLoaded;
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_Z*/  vector<float> *Common_fatjet_deep_Z_;
/*                    Common_fatjet_deep_Z*/  TBranch *Common_fatjet_deep_Z_branch;
/*                    Common_fatjet_deep_Z*/  bool     Common_fatjet_deep_Z_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_T*/  vector<float> *Common_fatjet_deepMD_T_;
/*                  Common_fatjet_deepMD_T*/  TBranch *Common_fatjet_deepMD_T_branch;
/*                  Common_fatjet_deepMD_T*/  bool     Common_fatjet_deepMD_T_isLoaded;
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_T*/  vector<float> *Common_fatjet_deep_T_;
/*                    Common_fatjet_deep_T*/  TBranch *Common_fatjet_deep_T_branch;
/*                    Common_fatjet_deep_T*/  bool     Common_fatjet_deep_T_isLoaded;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_deepMD_bb*/  vector<float> *Common_fatjet_deepMD_bb_;
/*                 Common_fatjet_deepMD_bb*/  TBranch *Common_fatjet_deepMD_bb_branch;
/*                 Common_fatjet_deepMD_bb*/  bool     Common_fatjet_deepMD_bb_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNetMD_W*/  vector<float> *Common_fatjet_particleNetMD_W_;
/*           Common_fatjet_particleNetMD_W*/  TBranch *Common_fatjet_particleNetMD_W_branch;
/*           Common_fatjet_particleNetMD_W*/  bool     Common_fatjet_particleNetMD_W_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xqq*/  vector<float> *Common_fatjet_particleNetMD_Xqq_;
/*         Common_fatjet_particleNetMD_Xqq*/  TBranch *Common_fatjet_particleNetMD_Xqq_branch;
/*         Common_fatjet_particleNetMD_Xqq*/  bool     Common_fatjet_particleNetMD_Xqq_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xcc*/  vector<float> *Common_fatjet_particleNetMD_Xcc_;
/*         Common_fatjet_particleNetMD_Xcc*/  TBranch *Common_fatjet_particleNetMD_Xcc_branch;
/*         Common_fatjet_particleNetMD_Xcc*/  bool     Common_fatjet_particleNetMD_Xcc_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xbb*/  vector<float> *Common_fatjet_particleNetMD_Xbb_;
/*         Common_fatjet_particleNetMD_Xbb*/  TBranch *Common_fatjet_particleNetMD_Xbb_branch;
/*         Common_fatjet_particleNetMD_Xbb*/  bool     Common_fatjet_particleNetMD_Xbb_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_QCD*/  vector<float> *Common_fatjet_particleNetMD_QCD_;
/*         Common_fatjet_particleNetMD_QCD*/  TBranch *Common_fatjet_particleNetMD_QCD_branch;
/*         Common_fatjet_particleNetMD_QCD*/  bool     Common_fatjet_particleNetMD_QCD_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNet_QCD*/  vector<float> *Common_fatjet_particleNet_QCD_;
/*           Common_fatjet_particleNet_QCD*/  TBranch *Common_fatjet_particleNet_QCD_branch;
/*           Common_fatjet_particleNet_QCD*/  bool     Common_fatjet_particleNet_QCD_isLoaded;
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_W*/  vector<float> *Common_fatjet_particleNet_W_;
/*             Common_fatjet_particleNet_W*/  TBranch *Common_fatjet_particleNet_W_branch;
/*             Common_fatjet_particleNet_W*/  bool     Common_fatjet_particleNet_W_isLoaded;
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_Z*/  vector<float> *Common_fatjet_particleNet_Z_;
/*             Common_fatjet_particleNet_Z*/  TBranch *Common_fatjet_particleNet_Z_branch;
/*             Common_fatjet_particleNet_Z*/  bool     Common_fatjet_particleNet_Z_isLoaded;
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_T*/  vector<float> *Common_fatjet_particleNet_T_;
/*             Common_fatjet_particleNet_T*/  TBranch *Common_fatjet_particleNet_T_branch;
/*             Common_fatjet_particleNet_T*/  bool     Common_fatjet_particleNet_T_isLoaded;
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau3*/  vector<float> *Common_fatjet_tau3_;
/*                      Common_fatjet_tau3*/  TBranch *Common_fatjet_tau3_branch;
/*                      Common_fatjet_tau3*/  bool     Common_fatjet_tau3_isLoaded;
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau2*/  vector<float> *Common_fatjet_tau2_;
/*                      Common_fatjet_tau2*/  TBranch *Common_fatjet_tau2_branch;
/*                      Common_fatjet_tau2*/  bool     Common_fatjet_tau2_isLoaded;
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau1*/  vector<float> *Common_fatjet_tau1_;
/*                      Common_fatjet_tau1*/  TBranch *Common_fatjet_tau1_branch;
/*                      Common_fatjet_tau1*/  bool     Common_fatjet_tau1_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau32*/  vector<float> *Common_fatjet_tau32_;
/*                     Common_fatjet_tau32*/  TBranch *Common_fatjet_tau32_branch;
/*                     Common_fatjet_tau32*/  bool     Common_fatjet_tau32_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau21*/  vector<float> *Common_fatjet_tau21_;
/*                     Common_fatjet_tau21*/  TBranch *Common_fatjet_tau21_branch;
/*                     Common_fatjet_tau21*/  bool     Common_fatjet_tau21_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_pt*/  vector<float> *Common_fatjet_subjet0_pt_;
/*                Common_fatjet_subjet0_pt*/  TBranch *Common_fatjet_subjet0_pt_branch;
/*                Common_fatjet_subjet0_pt*/  bool     Common_fatjet_subjet0_pt_isLoaded;
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_eta*/  vector<float> *Common_fatjet_subjet0_eta_;
/*               Common_fatjet_subjet0_eta*/  TBranch *Common_fatjet_subjet0_eta_branch;
/*               Common_fatjet_subjet0_eta*/  bool     Common_fatjet_subjet0_eta_isLoaded;
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_phi*/  vector<float> *Common_fatjet_subjet0_phi_;
/*               Common_fatjet_subjet0_phi*/  TBranch *Common_fatjet_subjet0_phi_branch;
/*               Common_fatjet_subjet0_phi*/  bool     Common_fatjet_subjet0_phi_isLoaded;
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet0_mass*/  vector<float> *Common_fatjet_subjet0_mass_;
/*              Common_fatjet_subjet0_mass*/  TBranch *Common_fatjet_subjet0_mass_branch;
/*              Common_fatjet_subjet0_mass*/  bool     Common_fatjet_subjet0_mass_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_pt*/  vector<float> *Common_fatjet_subjet1_pt_;
/*                Common_fatjet_subjet1_pt*/  TBranch *Common_fatjet_subjet1_pt_branch;
/*                Common_fatjet_subjet1_pt*/  bool     Common_fatjet_subjet1_pt_isLoaded;
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_eta*/  vector<float> *Common_fatjet_subjet1_eta_;
/*               Common_fatjet_subjet1_eta*/  TBranch *Common_fatjet_subjet1_eta_branch;
/*               Common_fatjet_subjet1_eta*/  bool     Common_fatjet_subjet1_eta_isLoaded;
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_phi*/  vector<float> *Common_fatjet_subjet1_phi_;
/*               Common_fatjet_subjet1_phi*/  TBranch *Common_fatjet_subjet1_phi_branch;
/*               Common_fatjet_subjet1_phi*/  bool     Common_fatjet_subjet1_phi_isLoaded;
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet1_mass*/  vector<float> *Common_fatjet_subjet1_mass_;
/*              Common_fatjet_subjet1_mass*/  TBranch *Common_fatjet_subjet1_mass_branch;
/*              Common_fatjet_subjet1_mass*/  bool     Common_fatjet_subjet1_mass_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_p4*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_subjet0_p4_;
/*                Common_fatjet_subjet0_p4*/  TBranch *Common_fatjet_subjet0_p4_branch;
/*                Common_fatjet_subjet0_p4*/  bool     Common_fatjet_subjet0_p4_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_p4*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_subjet1_p4_;
/*                Common_fatjet_subjet1_p4*/  TBranch *Common_fatjet_subjet1_p4_branch;
/*                Common_fatjet_subjet1_p4*/  bool     Common_fatjet_subjet1_p4_isLoaded;
//---------------------------------------------------------------------------------
/*                        Common_fatjet_WP*/  vector<int> *Common_fatjet_WP_;
/*                        Common_fatjet_WP*/  TBranch *Common_fatjet_WP_branch;
/*                        Common_fatjet_WP*/  bool     Common_fatjet_WP_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_fatjet_WP_MD*/  vector<int> *Common_fatjet_WP_MD_;
/*                     Common_fatjet_WP_MD*/  TBranch *Common_fatjet_WP_MD_branch;
/*                     Common_fatjet_WP_MD*/  bool     Common_fatjet_WP_MD_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_fatjet_WP_antimasscut*/  vector<int> *Common_fatjet_WP_antimasscut_;
/*            Common_fatjet_WP_antimasscut*/  TBranch *Common_fatjet_WP_antimasscut_branch;
/*            Common_fatjet_WP_antimasscut*/  bool     Common_fatjet_WP_antimasscut_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_fatjet_WP_MD_antimasscut*/  vector<int> *Common_fatjet_WP_MD_antimasscut_;
/*         Common_fatjet_WP_MD_antimasscut*/  TBranch *Common_fatjet_WP_MD_antimasscut_branch;
/*         Common_fatjet_WP_MD_antimasscut*/  bool     Common_fatjet_WP_MD_antimasscut_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFVLoose*/  vector<float> *Common_fatjet_SFVLoose_;
/*                  Common_fatjet_SFVLoose*/  TBranch *Common_fatjet_SFVLoose_branch;
/*                  Common_fatjet_SFVLoose*/  bool     Common_fatjet_SFVLoose_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFLoose*/  vector<float> *Common_fatjet_SFLoose_;
/*                   Common_fatjet_SFLoose*/  TBranch *Common_fatjet_SFLoose_branch;
/*                   Common_fatjet_SFLoose*/  bool     Common_fatjet_SFLoose_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFMedium*/  vector<float> *Common_fatjet_SFMedium_;
/*                  Common_fatjet_SFMedium*/  TBranch *Common_fatjet_SFMedium_branch;
/*                  Common_fatjet_SFMedium*/  bool     Common_fatjet_SFMedium_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFTight*/  vector<float> *Common_fatjet_SFTight_;
/*                   Common_fatjet_SFTight*/  TBranch *Common_fatjet_SFTight_branch;
/*                   Common_fatjet_SFTight*/  bool     Common_fatjet_SFTight_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnVLoose*/  vector<float> *Common_fatjet_SFdnVLoose_;
/*                Common_fatjet_SFdnVLoose*/  TBranch *Common_fatjet_SFdnVLoose_branch;
/*                Common_fatjet_SFdnVLoose*/  bool     Common_fatjet_SFdnVLoose_isLoaded;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnLoose*/  vector<float> *Common_fatjet_SFdnLoose_;
/*                 Common_fatjet_SFdnLoose*/  TBranch *Common_fatjet_SFdnLoose_branch;
/*                 Common_fatjet_SFdnLoose*/  bool     Common_fatjet_SFdnLoose_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnMedium*/  vector<float> *Common_fatjet_SFdnMedium_;
/*                Common_fatjet_SFdnMedium*/  TBranch *Common_fatjet_SFdnMedium_branch;
/*                Common_fatjet_SFdnMedium*/  bool     Common_fatjet_SFdnMedium_isLoaded;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnTight*/  vector<float> *Common_fatjet_SFdnTight_;
/*                 Common_fatjet_SFdnTight*/  TBranch *Common_fatjet_SFdnTight_branch;
/*                 Common_fatjet_SFdnTight*/  bool     Common_fatjet_SFdnTight_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupVLoose*/  vector<float> *Common_fatjet_SFupVLoose_;
/*                Common_fatjet_SFupVLoose*/  TBranch *Common_fatjet_SFupVLoose_branch;
/*                Common_fatjet_SFupVLoose*/  bool     Common_fatjet_SFupVLoose_isLoaded;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupLoose*/  vector<float> *Common_fatjet_SFupLoose_;
/*                 Common_fatjet_SFupLoose*/  TBranch *Common_fatjet_SFupLoose_branch;
/*                 Common_fatjet_SFupLoose*/  bool     Common_fatjet_SFupLoose_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupMedium*/  vector<float> *Common_fatjet_SFupMedium_;
/*                Common_fatjet_SFupMedium*/  TBranch *Common_fatjet_SFupMedium_branch;
/*                Common_fatjet_SFupMedium*/  bool     Common_fatjet_SFupMedium_isLoaded;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupTight*/  vector<float> *Common_fatjet_SFupTight_;
/*                 Common_fatjet_SFupTight*/  TBranch *Common_fatjet_SFupTight_branch;
/*                 Common_fatjet_SFupTight*/  bool     Common_fatjet_SFupTight_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_MD_SFLoose*/  vector<float> *Common_fatjet_MD_SFLoose_;
/*                Common_fatjet_MD_SFLoose*/  TBranch *Common_fatjet_MD_SFLoose_branch;
/*                Common_fatjet_MD_SFLoose*/  bool     Common_fatjet_MD_SFLoose_isLoaded;
//---------------------------------------------------------------------------------
/*               Common_fatjet_MD_SFMedium*/  vector<float> *Common_fatjet_MD_SFMedium_;
/*               Common_fatjet_MD_SFMedium*/  TBranch *Common_fatjet_MD_SFMedium_branch;
/*               Common_fatjet_MD_SFMedium*/  bool     Common_fatjet_MD_SFMedium_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_MD_SFTight*/  vector<float> *Common_fatjet_MD_SFTight_;
/*                Common_fatjet_MD_SFTight*/  TBranch *Common_fatjet_MD_SFTight_branch;
/*                Common_fatjet_MD_SFTight*/  bool     Common_fatjet_MD_SFTight_isLoaded;
//---------------------------------------------------------------------------------
/*              Common_fatjet_MD_SFdnLoose*/  vector<float> *Common_fatjet_MD_SFdnLoose_;
/*              Common_fatjet_MD_SFdnLoose*/  TBranch *Common_fatjet_MD_SFdnLoose_branch;
/*              Common_fatjet_MD_SFdnLoose*/  bool     Common_fatjet_MD_SFdnLoose_isLoaded;
//---------------------------------------------------------------------------------
/*             Common_fatjet_MD_SFdnMedium*/  vector<float> *Common_fatjet_MD_SFdnMedium_;
/*             Common_fatjet_MD_SFdnMedium*/  TBranch *Common_fatjet_MD_SFdnMedium_branch;
/*             Common_fatjet_MD_SFdnMedium*/  bool     Common_fatjet_MD_SFdnMedium_isLoaded;
//---------------------------------------------------------------------------------
/*              Common_fatjet_MD_SFdnTight*/  vector<float> *Common_fatjet_MD_SFdnTight_;
/*              Common_fatjet_MD_SFdnTight*/  TBranch *Common_fatjet_MD_SFdnTight_branch;
/*              Common_fatjet_MD_SFdnTight*/  bool     Common_fatjet_MD_SFdnTight_isLoaded;
//---------------------------------------------------------------------------------
/*              Common_fatjet_MD_SFupLoose*/  vector<float> *Common_fatjet_MD_SFupLoose_;
/*              Common_fatjet_MD_SFupLoose*/  TBranch *Common_fatjet_MD_SFupLoose_branch;
/*              Common_fatjet_MD_SFupLoose*/  bool     Common_fatjet_MD_SFupLoose_isLoaded;
//---------------------------------------------------------------------------------
/*             Common_fatjet_MD_SFupMedium*/  vector<float> *Common_fatjet_MD_SFupMedium_;
/*             Common_fatjet_MD_SFupMedium*/  TBranch *Common_fatjet_MD_SFupMedium_branch;
/*             Common_fatjet_MD_SFupMedium*/  bool     Common_fatjet_MD_SFupMedium_isLoaded;
//---------------------------------------------------------------------------------
/*              Common_fatjet_MD_SFupTight*/  vector<float> *Common_fatjet_MD_SFupTight_;
/*              Common_fatjet_MD_SFupTight*/  TBranch *Common_fatjet_MD_SFupTight_branch;
/*              Common_fatjet_MD_SFupTight*/  bool     Common_fatjet_MD_SFupTight_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesup*/  vector<float> *Common_fatjet_pt_jesup_;
/*                  Common_fatjet_pt_jesup*/  TBranch *Common_fatjet_pt_jesup_branch;
/*                  Common_fatjet_pt_jesup*/  bool     Common_fatjet_pt_jesup_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesdn*/  vector<float> *Common_fatjet_pt_jesdn_;
/*                  Common_fatjet_pt_jesdn*/  TBranch *Common_fatjet_pt_jesdn_branch;
/*                  Common_fatjet_pt_jesdn*/  bool     Common_fatjet_pt_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerup*/  vector<float> *Common_fatjet_pt_jerup_;
/*                  Common_fatjet_pt_jerup*/  TBranch *Common_fatjet_pt_jerup_branch;
/*                  Common_fatjet_pt_jerup*/  bool     Common_fatjet_pt_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerdn*/  vector<float> *Common_fatjet_pt_jerdn_;
/*                  Common_fatjet_pt_jerdn*/  TBranch *Common_fatjet_pt_jerdn_branch;
/*                  Common_fatjet_pt_jerdn*/  bool     Common_fatjet_pt_jerdn_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesup*/  vector<float> *Common_fatjet_msoftdrop_jesup_;
/*           Common_fatjet_msoftdrop_jesup*/  TBranch *Common_fatjet_msoftdrop_jesup_branch;
/*           Common_fatjet_msoftdrop_jesup*/  bool     Common_fatjet_msoftdrop_jesup_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesdn*/  vector<float> *Common_fatjet_msoftdrop_jesdn_;
/*           Common_fatjet_msoftdrop_jesdn*/  TBranch *Common_fatjet_msoftdrop_jesdn_branch;
/*           Common_fatjet_msoftdrop_jesdn*/  bool     Common_fatjet_msoftdrop_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerup*/  vector<float> *Common_fatjet_msoftdrop_jerup_;
/*           Common_fatjet_msoftdrop_jerup*/  TBranch *Common_fatjet_msoftdrop_jerup_branch;
/*           Common_fatjet_msoftdrop_jerup*/  bool     Common_fatjet_msoftdrop_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerdn*/  vector<float> *Common_fatjet_msoftdrop_jerdn_;
/*           Common_fatjet_msoftdrop_jerdn*/  TBranch *Common_fatjet_msoftdrop_jerdn_branch;
/*           Common_fatjet_msoftdrop_jerdn*/  bool     Common_fatjet_msoftdrop_jerdn_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsup*/  vector<float> *Common_fatjet_msoftdrop_jmsup_;
/*           Common_fatjet_msoftdrop_jmsup*/  TBranch *Common_fatjet_msoftdrop_jmsup_branch;
/*           Common_fatjet_msoftdrop_jmsup*/  bool     Common_fatjet_msoftdrop_jmsup_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsdn*/  vector<float> *Common_fatjet_msoftdrop_jmsdn_;
/*           Common_fatjet_msoftdrop_jmsdn*/  TBranch *Common_fatjet_msoftdrop_jmsdn_branch;
/*           Common_fatjet_msoftdrop_jmsdn*/  bool     Common_fatjet_msoftdrop_jmsdn_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrup*/  vector<float> *Common_fatjet_msoftdrop_jmrup_;
/*           Common_fatjet_msoftdrop_jmrup*/  TBranch *Common_fatjet_msoftdrop_jmrup_branch;
/*           Common_fatjet_msoftdrop_jmrup*/  bool     Common_fatjet_msoftdrop_jmrup_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrdn*/  vector<float> *Common_fatjet_msoftdrop_jmrdn_;
/*           Common_fatjet_msoftdrop_jmrdn*/  TBranch *Common_fatjet_msoftdrop_jmrdn_branch;
/*           Common_fatjet_msoftdrop_jmrdn*/  bool     Common_fatjet_msoftdrop_jmrdn_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesup*/  vector<float> *Common_fatjet_mass_jesup_;
/*                Common_fatjet_mass_jesup*/  TBranch *Common_fatjet_mass_jesup_branch;
/*                Common_fatjet_mass_jesup*/  bool     Common_fatjet_mass_jesup_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesdn*/  vector<float> *Common_fatjet_mass_jesdn_;
/*                Common_fatjet_mass_jesdn*/  TBranch *Common_fatjet_mass_jesdn_branch;
/*                Common_fatjet_mass_jesdn*/  bool     Common_fatjet_mass_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerup*/  vector<float> *Common_fatjet_mass_jerup_;
/*                Common_fatjet_mass_jerup*/  TBranch *Common_fatjet_mass_jerup_branch;
/*                Common_fatjet_mass_jerup*/  bool     Common_fatjet_mass_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerdn*/  vector<float> *Common_fatjet_mass_jerdn_;
/*                Common_fatjet_mass_jerdn*/  TBranch *Common_fatjet_mass_jerdn_branch;
/*                Common_fatjet_mass_jerdn*/  bool     Common_fatjet_mass_jerdn_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsup*/  vector<float> *Common_fatjet_mass_jmsup_;
/*                Common_fatjet_mass_jmsup*/  TBranch *Common_fatjet_mass_jmsup_branch;
/*                Common_fatjet_mass_jmsup*/  bool     Common_fatjet_mass_jmsup_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsdn*/  vector<float> *Common_fatjet_mass_jmsdn_;
/*                Common_fatjet_mass_jmsdn*/  TBranch *Common_fatjet_mass_jmsdn_branch;
/*                Common_fatjet_mass_jmsdn*/  bool     Common_fatjet_mass_jmsdn_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrup*/  vector<float> *Common_fatjet_mass_jmrup_;
/*                Common_fatjet_mass_jmrup*/  TBranch *Common_fatjet_mass_jmrup_branch;
/*                Common_fatjet_mass_jmrup*/  bool     Common_fatjet_mass_jmrup_isLoaded;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrdn*/  vector<float> *Common_fatjet_mass_jmrdn_;
/*                Common_fatjet_mass_jmrdn*/  TBranch *Common_fatjet_mass_jmrdn_branch;
/*                Common_fatjet_mass_jmrdn*/  bool     Common_fatjet_mass_jmrdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFVLoose*/  float    Common_eventweight_fatjet_SFVLoose_;
/*      Common_eventweight_fatjet_SFVLoose*/  TBranch *Common_eventweight_fatjet_SFVLoose_branch;
/*      Common_eventweight_fatjet_SFVLoose*/  bool     Common_eventweight_fatjet_SFVLoose_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFLoose*/  float    Common_eventweight_fatjet_SFLoose_;
/*       Common_eventweight_fatjet_SFLoose*/  TBranch *Common_eventweight_fatjet_SFLoose_branch;
/*       Common_eventweight_fatjet_SFLoose*/  bool     Common_eventweight_fatjet_SFLoose_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFMedium*/  float    Common_eventweight_fatjet_SFMedium_;
/*      Common_eventweight_fatjet_SFMedium*/  TBranch *Common_eventweight_fatjet_SFMedium_branch;
/*      Common_eventweight_fatjet_SFMedium*/  bool     Common_eventweight_fatjet_SFMedium_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFTight*/  float    Common_eventweight_fatjet_SFTight_;
/*       Common_eventweight_fatjet_SFTight*/  TBranch *Common_eventweight_fatjet_SFTight_branch;
/*       Common_eventweight_fatjet_SFTight*/  bool     Common_eventweight_fatjet_SFTight_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnVLoose*/  float    Common_eventweight_fatjet_SFdnVLoose_;
/*    Common_eventweight_fatjet_SFdnVLoose*/  TBranch *Common_eventweight_fatjet_SFdnVLoose_branch;
/*    Common_eventweight_fatjet_SFdnVLoose*/  bool     Common_eventweight_fatjet_SFdnVLoose_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnLoose*/  float    Common_eventweight_fatjet_SFdnLoose_;
/*     Common_eventweight_fatjet_SFdnLoose*/  TBranch *Common_eventweight_fatjet_SFdnLoose_branch;
/*     Common_eventweight_fatjet_SFdnLoose*/  bool     Common_eventweight_fatjet_SFdnLoose_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnMedium*/  float    Common_eventweight_fatjet_SFdnMedium_;
/*    Common_eventweight_fatjet_SFdnMedium*/  TBranch *Common_eventweight_fatjet_SFdnMedium_branch;
/*    Common_eventweight_fatjet_SFdnMedium*/  bool     Common_eventweight_fatjet_SFdnMedium_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnTight*/  float    Common_eventweight_fatjet_SFdnTight_;
/*     Common_eventweight_fatjet_SFdnTight*/  TBranch *Common_eventweight_fatjet_SFdnTight_branch;
/*     Common_eventweight_fatjet_SFdnTight*/  bool     Common_eventweight_fatjet_SFdnTight_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupVLoose*/  float    Common_eventweight_fatjet_SFupVLoose_;
/*    Common_eventweight_fatjet_SFupVLoose*/  TBranch *Common_eventweight_fatjet_SFupVLoose_branch;
/*    Common_eventweight_fatjet_SFupVLoose*/  bool     Common_eventweight_fatjet_SFupVLoose_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupLoose*/  float    Common_eventweight_fatjet_SFupLoose_;
/*     Common_eventweight_fatjet_SFupLoose*/  TBranch *Common_eventweight_fatjet_SFupLoose_branch;
/*     Common_eventweight_fatjet_SFupLoose*/  bool     Common_eventweight_fatjet_SFupLoose_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupMedium*/  float    Common_eventweight_fatjet_SFupMedium_;
/*    Common_eventweight_fatjet_SFupMedium*/  TBranch *Common_eventweight_fatjet_SFupMedium_branch;
/*    Common_eventweight_fatjet_SFupMedium*/  bool     Common_eventweight_fatjet_SFupMedium_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupTight*/  float    Common_eventweight_fatjet_SFupTight_;
/*     Common_eventweight_fatjet_SFupTight*/  TBranch *Common_eventweight_fatjet_SFupTight_branch;
/*     Common_eventweight_fatjet_SFupTight*/  bool     Common_eventweight_fatjet_SFupTight_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_MD_SFLoose*/  float    Common_eventweight_fatjet_MD_SFLoose_;
/*    Common_eventweight_fatjet_MD_SFLoose*/  TBranch *Common_eventweight_fatjet_MD_SFLoose_branch;
/*    Common_eventweight_fatjet_MD_SFLoose*/  bool     Common_eventweight_fatjet_MD_SFLoose_isLoaded;
//---------------------------------------------------------------------------------
/*   Common_eventweight_fatjet_MD_SFMedium*/  float    Common_eventweight_fatjet_MD_SFMedium_;
/*   Common_eventweight_fatjet_MD_SFMedium*/  TBranch *Common_eventweight_fatjet_MD_SFMedium_branch;
/*   Common_eventweight_fatjet_MD_SFMedium*/  bool     Common_eventweight_fatjet_MD_SFMedium_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_MD_SFTight*/  float    Common_eventweight_fatjet_MD_SFTight_;
/*    Common_eventweight_fatjet_MD_SFTight*/  TBranch *Common_eventweight_fatjet_MD_SFTight_branch;
/*    Common_eventweight_fatjet_MD_SFTight*/  bool     Common_eventweight_fatjet_MD_SFTight_isLoaded;
//---------------------------------------------------------------------------------
/*  Common_eventweight_fatjet_MD_SFdnLoose*/  float    Common_eventweight_fatjet_MD_SFdnLoose_;
/*  Common_eventweight_fatjet_MD_SFdnLoose*/  TBranch *Common_eventweight_fatjet_MD_SFdnLoose_branch;
/*  Common_eventweight_fatjet_MD_SFdnLoose*/  bool     Common_eventweight_fatjet_MD_SFdnLoose_isLoaded;
//---------------------------------------------------------------------------------
/* Common_eventweight_fatjet_MD_SFdnMedium*/  float    Common_eventweight_fatjet_MD_SFdnMedium_;
/* Common_eventweight_fatjet_MD_SFdnMedium*/  TBranch *Common_eventweight_fatjet_MD_SFdnMedium_branch;
/* Common_eventweight_fatjet_MD_SFdnMedium*/  bool     Common_eventweight_fatjet_MD_SFdnMedium_isLoaded;
//---------------------------------------------------------------------------------
/*  Common_eventweight_fatjet_MD_SFdnTight*/  float    Common_eventweight_fatjet_MD_SFdnTight_;
/*  Common_eventweight_fatjet_MD_SFdnTight*/  TBranch *Common_eventweight_fatjet_MD_SFdnTight_branch;
/*  Common_eventweight_fatjet_MD_SFdnTight*/  bool     Common_eventweight_fatjet_MD_SFdnTight_isLoaded;
//---------------------------------------------------------------------------------
/*  Common_eventweight_fatjet_MD_SFupLoose*/  float    Common_eventweight_fatjet_MD_SFupLoose_;
/*  Common_eventweight_fatjet_MD_SFupLoose*/  TBranch *Common_eventweight_fatjet_MD_SFupLoose_branch;
/*  Common_eventweight_fatjet_MD_SFupLoose*/  bool     Common_eventweight_fatjet_MD_SFupLoose_isLoaded;
//---------------------------------------------------------------------------------
/* Common_eventweight_fatjet_MD_SFupMedium*/  float    Common_eventweight_fatjet_MD_SFupMedium_;
/* Common_eventweight_fatjet_MD_SFupMedium*/  TBranch *Common_eventweight_fatjet_MD_SFupMedium_branch;
/* Common_eventweight_fatjet_MD_SFupMedium*/  bool     Common_eventweight_fatjet_MD_SFupMedium_isLoaded;
//---------------------------------------------------------------------------------
/*  Common_eventweight_fatjet_MD_SFupTight*/  float    Common_eventweight_fatjet_MD_SFupTight_;
/*  Common_eventweight_fatjet_MD_SFupTight*/  TBranch *Common_eventweight_fatjet_MD_SFupTight_branch;
/*  Common_eventweight_fatjet_MD_SFupTight*/  bool     Common_eventweight_fatjet_MD_SFupTight_isLoaded;
//---------------------------------------------------------------------------------
/*                         Common_nb_loose*/  int      Common_nb_loose_;
/*                         Common_nb_loose*/  TBranch *Common_nb_loose_branch;
/*                         Common_nb_loose*/  bool     Common_nb_loose_isLoaded;
//---------------------------------------------------------------------------------
/*                        Common_nb_medium*/  int      Common_nb_medium_;
/*                        Common_nb_medium*/  TBranch *Common_nb_medium_branch;
/*                        Common_nb_medium*/  bool     Common_nb_medium_isLoaded;
//---------------------------------------------------------------------------------
/*                         Common_nb_tight*/  int      Common_nb_tight_;
/*                         Common_nb_tight*/  TBranch *Common_nb_tight_branch;
/*                         Common_nb_tight*/  bool     Common_nb_tight_isLoaded;
//---------------------------------------------------------------------------------
/*                          Common_gen_idx*/  vector<int> *Common_gen_idx_;
/*                          Common_gen_idx*/  TBranch *Common_gen_idx_branch;
/*                          Common_gen_idx*/  bool     Common_gen_idx_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_gen_mother_idx*/  vector<int> *Common_gen_mother_idx_;
/*                   Common_gen_mother_idx*/  TBranch *Common_gen_mother_idx_branch;
/*                   Common_gen_mother_idx*/  bool     Common_gen_mother_idx_isLoaded;
//---------------------------------------------------------------------------------
/*                    Common_gen_mother_id*/  vector<int> *Common_gen_mother_id_;
/*                    Common_gen_mother_id*/  TBranch *Common_gen_mother_id_branch;
/*                    Common_gen_mother_id*/  bool     Common_gen_mother_id_isLoaded;
//---------------------------------------------------------------------------------
/*                        Common_gen_pdgid*/  vector<int> *Common_gen_pdgid_;
/*                        Common_gen_pdgid*/  TBranch *Common_gen_pdgid_branch;
/*                        Common_gen_pdgid*/  bool     Common_gen_pdgid_isLoaded;
//---------------------------------------------------------------------------------
/*                          Common_gen_p4s*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_gen_p4s_;
/*                          Common_gen_p4s*/  TBranch *Common_gen_p4s_branch;
/*                          Common_gen_p4s*/  bool     Common_gen_p4s_isLoaded;
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_idx*/  vector<int> *Common_gen_vvvdecay_idx_;
/*                 Common_gen_vvvdecay_idx*/  TBranch *Common_gen_vvvdecay_idx_branch;
/*                 Common_gen_vvvdecay_idx*/  bool     Common_gen_vvvdecay_idx_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_mother_idx*/  vector<int> *Common_gen_vvvdecay_mother_idx_;
/*          Common_gen_vvvdecay_mother_idx*/  TBranch *Common_gen_vvvdecay_mother_idx_branch;
/*          Common_gen_vvvdecay_mother_idx*/  bool     Common_gen_vvvdecay_mother_idx_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_gen_vvvdecay_mother_id*/  vector<int> *Common_gen_vvvdecay_mother_id_;
/*           Common_gen_vvvdecay_mother_id*/  TBranch *Common_gen_vvvdecay_mother_id_branch;
/*           Common_gen_vvvdecay_mother_id*/  bool     Common_gen_vvvdecay_mother_id_isLoaded;
//---------------------------------------------------------------------------------
/*               Common_gen_vvvdecay_pdgid*/  vector<int> *Common_gen_vvvdecay_pdgid_;
/*               Common_gen_vvvdecay_pdgid*/  TBranch *Common_gen_vvvdecay_pdgid_branch;
/*               Common_gen_vvvdecay_pdgid*/  bool     Common_gen_vvvdecay_pdgid_isLoaded;
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_p4s*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_gen_vvvdecay_p4s_;
/*                 Common_gen_vvvdecay_p4s*/  TBranch *Common_gen_vvvdecay_p4s_branch;
/*                 Common_gen_vvvdecay_p4s*/  bool     Common_gen_vvvdecay_p4s_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_taudecayid*/  vector<int> *Common_gen_vvvdecay_taudecayid_;
/*          Common_gen_vvvdecay_taudecayid*/  TBranch *Common_gen_vvvdecay_taudecayid_branch;
/*          Common_gen_vvvdecay_taudecayid*/  bool     Common_gen_vvvdecay_taudecayid_isLoaded;
//---------------------------------------------------------------------------------
/*                         Common_isSignal*/  bool     Common_isSignal_;
/*                         Common_isSignal*/  TBranch *Common_isSignal_branch;
/*                         Common_isSignal*/  bool     Common_isSignal_isLoaded;
//---------------------------------------------------------------------------------
/*                              Common_n_W*/  int      Common_n_W_;
/*                              Common_n_W*/  TBranch *Common_n_W_branch;
/*                              Common_n_W*/  bool     Common_n_W_isLoaded;
//---------------------------------------------------------------------------------
/*                              Common_n_Z*/  int      Common_n_Z_;
/*                              Common_n_Z*/  TBranch *Common_n_Z_branch;
/*                              Common_n_Z*/  bool     Common_n_Z_isLoaded;
//---------------------------------------------------------------------------------
/*                          Common_n_lep_Z*/  int      Common_n_lep_Z_;
/*                          Common_n_lep_Z*/  TBranch *Common_n_lep_Z_branch;
/*                          Common_n_lep_Z*/  bool     Common_n_lep_Z_isLoaded;
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_Z*/  int      Common_n_leptau_Z_;
/*                       Common_n_leptau_Z*/  TBranch *Common_n_leptau_Z_branch;
/*                       Common_n_leptau_Z*/  bool     Common_n_leptau_Z_isLoaded;
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_Z*/  int      Common_n_hadtau_Z_;
/*                       Common_n_hadtau_Z*/  TBranch *Common_n_hadtau_Z_branch;
/*                       Common_n_hadtau_Z*/  bool     Common_n_hadtau_Z_isLoaded;
//---------------------------------------------------------------------------------
/*                           Common_n_nu_Z*/  int      Common_n_nu_Z_;
/*                           Common_n_nu_Z*/  TBranch *Common_n_nu_Z_branch;
/*                           Common_n_nu_Z*/  bool     Common_n_nu_Z_isLoaded;
//---------------------------------------------------------------------------------
/*                            Common_n_b_Z*/  int      Common_n_b_Z_;
/*                            Common_n_b_Z*/  TBranch *Common_n_b_Z_branch;
/*                            Common_n_b_Z*/  bool     Common_n_b_Z_isLoaded;
//---------------------------------------------------------------------------------
/*                          Common_n_lep_W*/  int      Common_n_lep_W_;
/*                          Common_n_lep_W*/  TBranch *Common_n_lep_W_branch;
/*                          Common_n_lep_W*/  bool     Common_n_lep_W_isLoaded;
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_W*/  int      Common_n_leptau_W_;
/*                       Common_n_leptau_W*/  TBranch *Common_n_leptau_W_branch;
/*                       Common_n_leptau_W*/  bool     Common_n_leptau_W_isLoaded;
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_W*/  int      Common_n_hadtau_W_;
/*                       Common_n_hadtau_W*/  TBranch *Common_n_hadtau_W_branch;
/*                       Common_n_hadtau_W*/  bool     Common_n_hadtau_W_isLoaded;
//---------------------------------------------------------------------------------
/*                        Common_haslepWSS*/  bool     Common_haslepWSS_;
/*                        Common_haslepWSS*/  TBranch *Common_haslepWSS_branch;
/*                        Common_haslepWSS*/  bool     Common_haslepWSS_isLoaded;
//---------------------------------------------------------------------------------
/*                            Common_genHT*/  float    Common_genHT_;
/*                            Common_genHT*/  TBranch *Common_genHT_branch;
/*                            Common_genHT*/  bool     Common_genHT_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_gen_n_light_lep*/  int      Common_gen_n_light_lep_;
/*                  Common_gen_n_light_lep*/  TBranch *Common_gen_n_light_lep_branch;
/*                  Common_gen_n_light_lep*/  bool     Common_gen_n_light_lep_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_gen_VH_channel*/  int      Common_gen_VH_channel_;
/*                   Common_gen_VH_channel*/  TBranch *Common_gen_VH_channel_branch;
/*                   Common_gen_VH_channel*/  bool     Common_gen_VH_channel_isLoaded;
//---------------------------------------------------------------------------------
/*                Cut_4LepMET_Preselection*/  bool     Cut_4LepMET_Preselection_;
/*                Cut_4LepMET_Preselection*/  TBranch *Cut_4LepMET_Preselection_branch;
/*                Cut_4LepMET_Preselection*/  bool     Cut_4LepMET_Preselection_isLoaded;
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/  bool     Cut_4LepMET_emuChannel_;
/*                  Cut_4LepMET_emuChannel*/  TBranch *Cut_4LepMET_emuChannel_branch;
/*                  Cut_4LepMET_emuChannel*/  bool     Cut_4LepMET_emuChannel_isLoaded;
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/  bool     Cut_4LepMET_offzChannel_;
/*                 Cut_4LepMET_offzChannel*/  TBranch *Cut_4LepMET_offzChannel_branch;
/*                 Cut_4LepMET_offzChannel*/  bool     Cut_4LepMET_offzChannel_isLoaded;
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/  bool     Cut_4LepMET_onzChannel_;
/*                  Cut_4LepMET_onzChannel*/  TBranch *Cut_4LepMET_onzChannel_branch;
/*                  Cut_4LepMET_onzChannel*/  bool     Cut_4LepMET_onzChannel_isLoaded;
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/  bool     Cut_4LepMET_onzChannel_HighMET_;
/*          Cut_4LepMET_onzChannel_HighMET*/  TBranch *Cut_4LepMET_onzChannel_HighMET_branch;
/*          Cut_4LepMET_onzChannel_HighMET*/  bool     Cut_4LepMET_onzChannel_HighMET_isLoaded;
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/  int      Var_4LepMET_Zcand_lep_idx_0_;
/*             Var_4LepMET_Zcand_lep_idx_0*/  TBranch *Var_4LepMET_Zcand_lep_idx_0_branch;
/*             Var_4LepMET_Zcand_lep_idx_0*/  bool     Var_4LepMET_Zcand_lep_idx_0_isLoaded;
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  int      Var_4LepMET_Zcand_lep_pdgid_0_;
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  TBranch *Var_4LepMET_Zcand_lep_pdgid_0_branch;
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  bool     Var_4LepMET_Zcand_lep_pdgid_0_isLoaded;
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_0*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Var_4LepMET_Zcand_lep_p4_0_;
/*              Var_4LepMET_Zcand_lep_p4_0*/  TBranch *Var_4LepMET_Zcand_lep_p4_0_branch;
/*              Var_4LepMET_Zcand_lep_p4_0*/  bool     Var_4LepMET_Zcand_lep_p4_0_isLoaded;
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_1*/  int      Var_4LepMET_Zcand_lep_idx_1_;
/*             Var_4LepMET_Zcand_lep_idx_1*/  TBranch *Var_4LepMET_Zcand_lep_idx_1_branch;
/*             Var_4LepMET_Zcand_lep_idx_1*/  bool     Var_4LepMET_Zcand_lep_idx_1_isLoaded;
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  int      Var_4LepMET_Zcand_lep_pdgid_1_;
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  TBranch *Var_4LepMET_Zcand_lep_pdgid_1_branch;
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  bool     Var_4LepMET_Zcand_lep_pdgid_1_isLoaded;
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_1*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Var_4LepMET_Zcand_lep_p4_1_;
/*              Var_4LepMET_Zcand_lep_p4_1*/  TBranch *Var_4LepMET_Zcand_lep_p4_1_branch;
/*              Var_4LepMET_Zcand_lep_p4_1*/  bool     Var_4LepMET_Zcand_lep_p4_1_isLoaded;
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_Zcand_mll*/  float    Var_4LepMET_Zcand_mll_;
/*                   Var_4LepMET_Zcand_mll*/  TBranch *Var_4LepMET_Zcand_mll_branch;
/*                   Var_4LepMET_Zcand_mll*/  bool     Var_4LepMET_Zcand_mll_isLoaded;
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_0*/  int      Var_4LepMET_other_lep_idx_0_;
/*             Var_4LepMET_other_lep_idx_0*/  TBranch *Var_4LepMET_other_lep_idx_0_branch;
/*             Var_4LepMET_other_lep_idx_0*/  bool     Var_4LepMET_other_lep_idx_0_isLoaded;
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_0*/  int      Var_4LepMET_other_lep_pdgid_0_;
/*           Var_4LepMET_other_lep_pdgid_0*/  TBranch *Var_4LepMET_other_lep_pdgid_0_branch;
/*           Var_4LepMET_other_lep_pdgid_0*/  bool     Var_4LepMET_other_lep_pdgid_0_isLoaded;
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_0*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Var_4LepMET_other_lep_p4_0_;
/*              Var_4LepMET_other_lep_p4_0*/  TBranch *Var_4LepMET_other_lep_p4_0_branch;
/*              Var_4LepMET_other_lep_p4_0*/  bool     Var_4LepMET_other_lep_p4_0_isLoaded;
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_1*/  int      Var_4LepMET_other_lep_idx_1_;
/*             Var_4LepMET_other_lep_idx_1*/  TBranch *Var_4LepMET_other_lep_idx_1_branch;
/*             Var_4LepMET_other_lep_idx_1*/  bool     Var_4LepMET_other_lep_idx_1_isLoaded;
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_1*/  int      Var_4LepMET_other_lep_pdgid_1_;
/*           Var_4LepMET_other_lep_pdgid_1*/  TBranch *Var_4LepMET_other_lep_pdgid_1_branch;
/*           Var_4LepMET_other_lep_pdgid_1*/  bool     Var_4LepMET_other_lep_pdgid_1_isLoaded;
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_1*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Var_4LepMET_other_lep_p4_1_;
/*              Var_4LepMET_other_lep_p4_1*/  TBranch *Var_4LepMET_other_lep_p4_1_branch;
/*              Var_4LepMET_other_lep_p4_1*/  bool     Var_4LepMET_other_lep_p4_1_isLoaded;
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_other_mll*/  float    Var_4LepMET_other_mll_;
/*                   Var_4LepMET_other_mll*/  TBranch *Var_4LepMET_other_mll_branch;
/*                   Var_4LepMET_other_mll*/  bool     Var_4LepMET_other_mll_isLoaded;
//---------------------------------------------------------------------------------
/*                         Var_4LepMET_mt2*/  float    Var_4LepMET_mt2_;
/*                         Var_4LepMET_mt2*/  TBranch *Var_4LepMET_mt2_branch;
/*                         Var_4LepMET_mt2*/  bool     Var_4LepMET_mt2_isLoaded;
//---------------------------------------------------------------------------------
public: 
void Init(TTree *tree);
void GetEntry(unsigned int idx); 
void LoadAllBranches(); 
//---------------------------------------------------------------------------------
/*                           Common_isData*/  const int &Common_isData();
//---------------------------------------------------------------------------------
/*                              Common_run*/  const int &Common_run();
//---------------------------------------------------------------------------------
/*                             Common_lumi*/  const int &Common_lumi();
//---------------------------------------------------------------------------------
/*                              Common_evt*/  const unsigned long long &Common_evt();
//---------------------------------------------------------------------------------
/*                             Common_year*/  const int &Common_year();
//---------------------------------------------------------------------------------
/*                        Common_genWeight*/  const float &Common_genWeight();
//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/  const float &Common_btagWeight_DeepCSVB();
//---------------------------------------------------------------------------------
/*                              Common_wgt*/  const float &Common_wgt();
//---------------------------------------------------------------------------------
/*         Common_LHEWeight_mg_reweighting*/  const vector<float> &Common_LHEWeight_mg_reweighting();
//---------------------------------------------------------------------------------
/*                        Common_event_PDF*/  const vector<float> &Common_event_PDF();
//---------------------------------------------------------------------------------
/*                   Common_event_QCDScale*/  const vector<float> &Common_event_QCDScale();
//---------------------------------------------------------------------------------
/*                   Common_event_puWeight*/  const float &Common_event_puWeight();
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightup*/  const float &Common_event_puWeightup();
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightdn*/  const float &Common_event_puWeightdn();
//---------------------------------------------------------------------------------
/*              Common_event_prefireWeight*/  const float &Common_event_prefireWeight();
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightup*/  const float &Common_event_prefireWeightup();
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightdn*/  const float &Common_event_prefireWeightdn();
//---------------------------------------------------------------------------------
/*              Common_event_triggerWeight*/  const float &Common_event_triggerWeight();
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightup*/  const float &Common_event_triggerWeightup();
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightdn*/  const float &Common_event_triggerWeightdn();
//---------------------------------------------------------------------------------
/*             Common_LHEReweightingWeight*/  const vector<float> &Common_LHEReweightingWeight();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ();
//---------------------------------------------------------------------------------
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8();
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  const bool &Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  const bool &Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  const bool &Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  const bool &Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  const bool &Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  const bool &Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL();
//---------------------------------------------------------------------------------
/*                      Common_HLT_IsoMu24*/  const bool &Common_HLT_IsoMu24();
//---------------------------------------------------------------------------------
/*                Common_HLT_Ele32_WPTight*/  const bool &Common_HLT_Ele32_WPTight();
//---------------------------------------------------------------------------------
/*                     Common_HLT_PFHT1050*/  const bool &Common_HLT_PFHT1050();
//---------------------------------------------------------------------------------
/*                  Common_HLT_AK8PFJet500*/  const bool &Common_HLT_AK8PFJet500();
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet380_TrimMass30*/  const bool &Common_HLT_AK8PFJet380_TrimMass30();
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet360_TrimMass30*/  const bool &Common_HLT_AK8PFJet360_TrimMass30();
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet400_TrimMass30*/  const bool &Common_HLT_AK8PFJet400_TrimMass30();
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet420_TrimMass30*/  const bool &Common_HLT_AK8PFJet420_TrimMass30();
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT750_TrimMass50*/  const bool &Common_HLT_AK8PFHT750_TrimMass50();
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT800_TrimMass50*/  const bool &Common_HLT_AK8PFHT800_TrimMass50();
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT850_TrimMass50*/  const bool &Common_HLT_AK8PFHT850_TrimMass50();
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT900_TrimMass50*/  const bool &Common_HLT_AK8PFHT900_TrimMass50();
//---------------------------------------------------------------------------------
/*Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5*/  const bool &Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5();
//---------------------------------------------------------------------------------
/*Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5*/  const bool &Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5();
//---------------------------------------------------------------------------------
/*                      Common_HLT_PFHT800*/  const bool &Common_HLT_PFHT800();
//---------------------------------------------------------------------------------
/*                      Common_HLT_PFHT900*/  const bool &Common_HLT_PFHT900();
//---------------------------------------------------------------------------------
/*                     Common_HLT_PFJet450*/  const bool &Common_HLT_PFJet450();
//---------------------------------------------------------------------------------
/*                     Common_HLT_PFJet500*/  const bool &Common_HLT_PFJet500();
//---------------------------------------------------------------------------------
/*                  Common_HLT_AK8PFJet450*/  const bool &Common_HLT_AK8PFJet450();
//---------------------------------------------------------------------------------
/*Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50*/  const bool &Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50();
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleEl*/  const bool &Common_HLT_DoubleEl();
//---------------------------------------------------------------------------------
/*                         Common_HLT_MuEG*/  const bool &Common_HLT_MuEG();
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleMu*/  const bool &Common_HLT_DoubleMu();
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_ee_em_mm*/  const bool &Common_pass_duplicate_removal_ee_em_mm();
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_mm_em_ee*/  const bool &Common_pass_duplicate_removal_mm_em_ee();
//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/  const bool &Common_noiseFlag();
//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/  const bool &Common_noiseFlagMC();
//---------------------------------------------------------------------------------
/*                      Common_passGoodRun*/  const bool &Common_passGoodRun();
//---------------------------------------------------------------------------------
/*                           Common_met_p4*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4();
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesup();
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesdn();
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jerup();
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jerdn();
//---------------------------------------------------------------------------------
/*                      Common_event_lepSF*/  const float &Common_event_lepSF();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFelup*/  const float &Common_event_lepSFelup();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFeldn*/  const float &Common_event_lepSFeldn();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmuup*/  const float &Common_event_lepSFmuup();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmudn*/  const float &Common_event_lepSFmudn();
//---------------------------------------------------------------------------------
/*                 Common_event_lepSFTight*/  const float &Common_event_lepSFTight();
//---------------------------------------------------------------------------------
/*             Common_event_lepSFelupTight*/  const float &Common_event_lepSFelupTight();
//---------------------------------------------------------------------------------
/*             Common_event_lepSFeldnTight*/  const float &Common_event_lepSFeldnTight();
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmuupTight*/  const float &Common_event_lepSFmuupTight();
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmudnTight*/  const float &Common_event_lepSFmudnTight();
//---------------------------------------------------------------------------------
/*                Common_event_tightBtagSF*/  const float &Common_event_tightBtagSF();
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFup*/  const float &Common_event_tightBtagSFup();
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFdn*/  const float &Common_event_tightBtagSFdn();
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFup*/  const float &Common_event_tightBtagSFHFup();
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFdn*/  const float &Common_event_tightBtagSFHFdn();
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFup*/  const float &Common_event_tightBtagSFLFup();
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFdn*/  const float &Common_event_tightBtagSFLFdn();
//---------------------------------------------------------------------------------
/*               Common_event_mediumBtagSF*/  const float &Common_event_mediumBtagSF();
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFup*/  const float &Common_event_mediumBtagSFup();
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFdn*/  const float &Common_event_mediumBtagSFdn();
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFup*/  const float &Common_event_mediumBtagSFHFup();
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFdn*/  const float &Common_event_mediumBtagSFHFdn();
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFup*/  const float &Common_event_mediumBtagSFLFup();
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFdn*/  const float &Common_event_mediumBtagSFLFdn();
//---------------------------------------------------------------------------------
/*                Common_event_looseBtagSF*/  const float &Common_event_looseBtagSF();
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFup*/  const float &Common_event_looseBtagSFup();
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFdn*/  const float &Common_event_looseBtagSFdn();
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFup*/  const float &Common_event_looseBtagSFHFup();
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFdn*/  const float &Common_event_looseBtagSFHFdn();
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFup*/  const float &Common_event_looseBtagSFLFup();
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFdn*/  const float &Common_event_looseBtagSFLFdn();
//---------------------------------------------------------------------------------
/*                           Common_lep_p4*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_lep_p4();
//---------------------------------------------------------------------------------
/*                         Common_lep_idxs*/  const vector<int> &Common_lep_idxs();
//---------------------------------------------------------------------------------
/*                        Common_lep_pdgid*/  const vector<int> &Common_lep_pdgid();
//---------------------------------------------------------------------------------
/*                        Common_lep_tight*/  const vector<int> &Common_lep_tight();
//---------------------------------------------------------------------------------
/*                          Common_lep_dxy*/  const vector<float> &Common_lep_dxy();
//---------------------------------------------------------------------------------
/*                           Common_lep_dz*/  const vector<float> &Common_lep_dz();
//---------------------------------------------------------------------------------
/*                         Common_lep_ip3d*/  const vector<float> &Common_lep_ip3d();
//---------------------------------------------------------------------------------
/*                        Common_lep_sip3d*/  const vector<float> &Common_lep_sip3d();
//---------------------------------------------------------------------------------
/*                           Common_lep_SF*/  const vector<float> &Common_lep_SF();
//---------------------------------------------------------------------------------
/*                      Common_lep_SFTight*/  const vector<float> &Common_lep_SFTight();
//---------------------------------------------------------------------------------
/*                         Common_lep_SFdn*/  const vector<float> &Common_lep_SFdn();
//---------------------------------------------------------------------------------
/*                    Common_lep_SFdnTight*/  const vector<float> &Common_lep_SFdnTight();
//---------------------------------------------------------------------------------
/*                         Common_lep_SFup*/  const vector<float> &Common_lep_SFup();
//---------------------------------------------------------------------------------
/*                    Common_lep_SFupTight*/  const vector<float> &Common_lep_SFupTight();
//---------------------------------------------------------------------------------
/*                           Common_jet_p4*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4();
//---------------------------------------------------------------------------------
/*                         Common_jet_idxs*/  const vector<int> &Common_jet_idxs();
//---------------------------------------------------------------------------------
/*                   Common_jet_passBloose*/  const vector<bool> &Common_jet_passBloose();
//---------------------------------------------------------------------------------
/*                  Common_jet_passBmedium*/  const vector<bool> &Common_jet_passBmedium();
//---------------------------------------------------------------------------------
/*                   Common_jet_passBtight*/  const vector<bool> &Common_jet_passBtight();
//---------------------------------------------------------------------------------
/*                           Common_jet_id*/  const vector<int> &Common_jet_id();
//---------------------------------------------------------------------------------
/*                         Common_jet_puid*/  const vector<int> &Common_jet_puid();
//---------------------------------------------------------------------------------
/*                Common_jet_overlapfatjet*/  const vector<int> &Common_jet_overlapfatjet();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesup*/  const vector<float> &Common_jet_pt_jesup();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesdn*/  const vector<float> &Common_jet_pt_jesdn();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerup*/  const vector<float> &Common_jet_pt_jerup();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerdn*/  const vector<float> &Common_jet_pt_jerdn();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesup*/  const vector<float> &Common_jet_mass_jesup();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesdn*/  const vector<float> &Common_jet_mass_jesdn();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerup*/  const vector<float> &Common_jet_mass_jerup();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerdn*/  const vector<float> &Common_jet_mass_jerdn();
//---------------------------------------------------------------------------------
/*                        Common_fatjet_p4*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_idxs*/  const vector<int> &Common_fatjet_idxs();
//---------------------------------------------------------------------------------
/*                        Common_fatjet_id*/  const vector<int> &Common_fatjet_id();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_msoftdrop*/  const vector<float> &Common_fatjet_msoftdrop();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_W*/  const vector<float> &Common_fatjet_deepMD_W();
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_W*/  const vector<float> &Common_fatjet_deep_W();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_Z*/  const vector<float> &Common_fatjet_deepMD_Z();
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_Z*/  const vector<float> &Common_fatjet_deep_Z();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_T*/  const vector<float> &Common_fatjet_deepMD_T();
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_T*/  const vector<float> &Common_fatjet_deep_T();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_deepMD_bb*/  const vector<float> &Common_fatjet_deepMD_bb();
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNetMD_W*/  const vector<float> &Common_fatjet_particleNetMD_W();
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xqq*/  const vector<float> &Common_fatjet_particleNetMD_Xqq();
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xcc*/  const vector<float> &Common_fatjet_particleNetMD_Xcc();
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xbb*/  const vector<float> &Common_fatjet_particleNetMD_Xbb();
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_QCD*/  const vector<float> &Common_fatjet_particleNetMD_QCD();
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNet_QCD*/  const vector<float> &Common_fatjet_particleNet_QCD();
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_W*/  const vector<float> &Common_fatjet_particleNet_W();
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_Z*/  const vector<float> &Common_fatjet_particleNet_Z();
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_T*/  const vector<float> &Common_fatjet_particleNet_T();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau3*/  const vector<float> &Common_fatjet_tau3();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau2*/  const vector<float> &Common_fatjet_tau2();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau1*/  const vector<float> &Common_fatjet_tau1();
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau32*/  const vector<float> &Common_fatjet_tau32();
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau21*/  const vector<float> &Common_fatjet_tau21();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_pt*/  const vector<float> &Common_fatjet_subjet0_pt();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_eta*/  const vector<float> &Common_fatjet_subjet0_eta();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_phi*/  const vector<float> &Common_fatjet_subjet0_phi();
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet0_mass*/  const vector<float> &Common_fatjet_subjet0_mass();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_pt*/  const vector<float> &Common_fatjet_subjet1_pt();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_eta*/  const vector<float> &Common_fatjet_subjet1_eta();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_phi*/  const vector<float> &Common_fatjet_subjet1_phi();
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet1_mass*/  const vector<float> &Common_fatjet_subjet1_mass();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_p4*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_subjet0_p4();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_p4*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_subjet1_p4();
//---------------------------------------------------------------------------------
/*                        Common_fatjet_WP*/  const vector<int> &Common_fatjet_WP();
//---------------------------------------------------------------------------------
/*                     Common_fatjet_WP_MD*/  const vector<int> &Common_fatjet_WP_MD();
//---------------------------------------------------------------------------------
/*            Common_fatjet_WP_antimasscut*/  const vector<int> &Common_fatjet_WP_antimasscut();
//---------------------------------------------------------------------------------
/*         Common_fatjet_WP_MD_antimasscut*/  const vector<int> &Common_fatjet_WP_MD_antimasscut();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFVLoose*/  const vector<float> &Common_fatjet_SFVLoose();
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFLoose*/  const vector<float> &Common_fatjet_SFLoose();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFMedium*/  const vector<float> &Common_fatjet_SFMedium();
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFTight*/  const vector<float> &Common_fatjet_SFTight();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnVLoose*/  const vector<float> &Common_fatjet_SFdnVLoose();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnLoose*/  const vector<float> &Common_fatjet_SFdnLoose();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnMedium*/  const vector<float> &Common_fatjet_SFdnMedium();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnTight*/  const vector<float> &Common_fatjet_SFdnTight();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupVLoose*/  const vector<float> &Common_fatjet_SFupVLoose();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupLoose*/  const vector<float> &Common_fatjet_SFupLoose();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupMedium*/  const vector<float> &Common_fatjet_SFupMedium();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupTight*/  const vector<float> &Common_fatjet_SFupTight();
//---------------------------------------------------------------------------------
/*                Common_fatjet_MD_SFLoose*/  const vector<float> &Common_fatjet_MD_SFLoose();
//---------------------------------------------------------------------------------
/*               Common_fatjet_MD_SFMedium*/  const vector<float> &Common_fatjet_MD_SFMedium();
//---------------------------------------------------------------------------------
/*                Common_fatjet_MD_SFTight*/  const vector<float> &Common_fatjet_MD_SFTight();
//---------------------------------------------------------------------------------
/*              Common_fatjet_MD_SFdnLoose*/  const vector<float> &Common_fatjet_MD_SFdnLoose();
//---------------------------------------------------------------------------------
/*             Common_fatjet_MD_SFdnMedium*/  const vector<float> &Common_fatjet_MD_SFdnMedium();
//---------------------------------------------------------------------------------
/*              Common_fatjet_MD_SFdnTight*/  const vector<float> &Common_fatjet_MD_SFdnTight();
//---------------------------------------------------------------------------------
/*              Common_fatjet_MD_SFupLoose*/  const vector<float> &Common_fatjet_MD_SFupLoose();
//---------------------------------------------------------------------------------
/*             Common_fatjet_MD_SFupMedium*/  const vector<float> &Common_fatjet_MD_SFupMedium();
//---------------------------------------------------------------------------------
/*              Common_fatjet_MD_SFupTight*/  const vector<float> &Common_fatjet_MD_SFupTight();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesup*/  const vector<float> &Common_fatjet_pt_jesup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesdn*/  const vector<float> &Common_fatjet_pt_jesdn();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerup*/  const vector<float> &Common_fatjet_pt_jerup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerdn*/  const vector<float> &Common_fatjet_pt_jerdn();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesup*/  const vector<float> &Common_fatjet_msoftdrop_jesup();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesdn*/  const vector<float> &Common_fatjet_msoftdrop_jesdn();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerup*/  const vector<float> &Common_fatjet_msoftdrop_jerup();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerdn*/  const vector<float> &Common_fatjet_msoftdrop_jerdn();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsup*/  const vector<float> &Common_fatjet_msoftdrop_jmsup();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsdn*/  const vector<float> &Common_fatjet_msoftdrop_jmsdn();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrup*/  const vector<float> &Common_fatjet_msoftdrop_jmrup();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrdn*/  const vector<float> &Common_fatjet_msoftdrop_jmrdn();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesup*/  const vector<float> &Common_fatjet_mass_jesup();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesdn*/  const vector<float> &Common_fatjet_mass_jesdn();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerup*/  const vector<float> &Common_fatjet_mass_jerup();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerdn*/  const vector<float> &Common_fatjet_mass_jerdn();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsup*/  const vector<float> &Common_fatjet_mass_jmsup();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsdn*/  const vector<float> &Common_fatjet_mass_jmsdn();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrup*/  const vector<float> &Common_fatjet_mass_jmrup();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrdn*/  const vector<float> &Common_fatjet_mass_jmrdn();
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFVLoose*/  const float &Common_eventweight_fatjet_SFVLoose();
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFLoose*/  const float &Common_eventweight_fatjet_SFLoose();
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFMedium*/  const float &Common_eventweight_fatjet_SFMedium();
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFTight*/  const float &Common_eventweight_fatjet_SFTight();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnVLoose*/  const float &Common_eventweight_fatjet_SFdnVLoose();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnLoose*/  const float &Common_eventweight_fatjet_SFdnLoose();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnMedium*/  const float &Common_eventweight_fatjet_SFdnMedium();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnTight*/  const float &Common_eventweight_fatjet_SFdnTight();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupVLoose*/  const float &Common_eventweight_fatjet_SFupVLoose();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupLoose*/  const float &Common_eventweight_fatjet_SFupLoose();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupMedium*/  const float &Common_eventweight_fatjet_SFupMedium();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupTight*/  const float &Common_eventweight_fatjet_SFupTight();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_MD_SFLoose*/  const float &Common_eventweight_fatjet_MD_SFLoose();
//---------------------------------------------------------------------------------
/*   Common_eventweight_fatjet_MD_SFMedium*/  const float &Common_eventweight_fatjet_MD_SFMedium();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_MD_SFTight*/  const float &Common_eventweight_fatjet_MD_SFTight();
//---------------------------------------------------------------------------------
/*  Common_eventweight_fatjet_MD_SFdnLoose*/  const float &Common_eventweight_fatjet_MD_SFdnLoose();
//---------------------------------------------------------------------------------
/* Common_eventweight_fatjet_MD_SFdnMedium*/  const float &Common_eventweight_fatjet_MD_SFdnMedium();
//---------------------------------------------------------------------------------
/*  Common_eventweight_fatjet_MD_SFdnTight*/  const float &Common_eventweight_fatjet_MD_SFdnTight();
//---------------------------------------------------------------------------------
/*  Common_eventweight_fatjet_MD_SFupLoose*/  const float &Common_eventweight_fatjet_MD_SFupLoose();
//---------------------------------------------------------------------------------
/* Common_eventweight_fatjet_MD_SFupMedium*/  const float &Common_eventweight_fatjet_MD_SFupMedium();
//---------------------------------------------------------------------------------
/*  Common_eventweight_fatjet_MD_SFupTight*/  const float &Common_eventweight_fatjet_MD_SFupTight();
//---------------------------------------------------------------------------------
/*                         Common_nb_loose*/  const int &Common_nb_loose();
//---------------------------------------------------------------------------------
/*                        Common_nb_medium*/  const int &Common_nb_medium();
//---------------------------------------------------------------------------------
/*                         Common_nb_tight*/  const int &Common_nb_tight();
//---------------------------------------------------------------------------------
/*                          Common_gen_idx*/  const vector<int> &Common_gen_idx();
//---------------------------------------------------------------------------------
/*                   Common_gen_mother_idx*/  const vector<int> &Common_gen_mother_idx();
//---------------------------------------------------------------------------------
/*                    Common_gen_mother_id*/  const vector<int> &Common_gen_mother_id();
//---------------------------------------------------------------------------------
/*                        Common_gen_pdgid*/  const vector<int> &Common_gen_pdgid();
//---------------------------------------------------------------------------------
/*                          Common_gen_p4s*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_gen_p4s();
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_idx*/  const vector<int> &Common_gen_vvvdecay_idx();
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_mother_idx*/  const vector<int> &Common_gen_vvvdecay_mother_idx();
//---------------------------------------------------------------------------------
/*           Common_gen_vvvdecay_mother_id*/  const vector<int> &Common_gen_vvvdecay_mother_id();
//---------------------------------------------------------------------------------
/*               Common_gen_vvvdecay_pdgid*/  const vector<int> &Common_gen_vvvdecay_pdgid();
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_p4s*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_gen_vvvdecay_p4s();
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_taudecayid*/  const vector<int> &Common_gen_vvvdecay_taudecayid();
//---------------------------------------------------------------------------------
/*                         Common_isSignal*/  const bool &Common_isSignal();
//---------------------------------------------------------------------------------
/*                              Common_n_W*/  const int &Common_n_W();
//---------------------------------------------------------------------------------
/*                              Common_n_Z*/  const int &Common_n_Z();
//---------------------------------------------------------------------------------
/*                          Common_n_lep_Z*/  const int &Common_n_lep_Z();
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_Z*/  const int &Common_n_leptau_Z();
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_Z*/  const int &Common_n_hadtau_Z();
//---------------------------------------------------------------------------------
/*                           Common_n_nu_Z*/  const int &Common_n_nu_Z();
//---------------------------------------------------------------------------------
/*                            Common_n_b_Z*/  const int &Common_n_b_Z();
//---------------------------------------------------------------------------------
/*                          Common_n_lep_W*/  const int &Common_n_lep_W();
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_W*/  const int &Common_n_leptau_W();
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_W*/  const int &Common_n_hadtau_W();
//---------------------------------------------------------------------------------
/*                        Common_haslepWSS*/  const bool &Common_haslepWSS();
//---------------------------------------------------------------------------------
/*                            Common_genHT*/  const float &Common_genHT();
//---------------------------------------------------------------------------------
/*                  Common_gen_n_light_lep*/  const int &Common_gen_n_light_lep();
//---------------------------------------------------------------------------------
/*                   Common_gen_VH_channel*/  const int &Common_gen_VH_channel();
//---------------------------------------------------------------------------------
/*                Cut_4LepMET_Preselection*/  const bool &Cut_4LepMET_Preselection();
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/  const bool &Cut_4LepMET_emuChannel();
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/  const bool &Cut_4LepMET_offzChannel();
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/  const bool &Cut_4LepMET_onzChannel();
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/  const bool &Cut_4LepMET_onzChannel_HighMET();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/  const int &Var_4LepMET_Zcand_lep_idx_0();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  const int &Var_4LepMET_Zcand_lep_pdgid_0();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_0*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_Zcand_lep_p4_0();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_1*/  const int &Var_4LepMET_Zcand_lep_idx_1();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  const int &Var_4LepMET_Zcand_lep_pdgid_1();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_1*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_Zcand_lep_p4_1();
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_Zcand_mll*/  const float &Var_4LepMET_Zcand_mll();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_0*/  const int &Var_4LepMET_other_lep_idx_0();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_0*/  const int &Var_4LepMET_other_lep_pdgid_0();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_0*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_other_lep_p4_0();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_1*/  const int &Var_4LepMET_other_lep_idx_1();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_1*/  const int &Var_4LepMET_other_lep_pdgid_1();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_1*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_other_lep_p4_1();
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_other_mll*/  const float &Var_4LepMET_other_mll();
//---------------------------------------------------------------------------------
/*                         Var_4LepMET_mt2*/  const float &Var_4LepMET_mt2();
//---------------------------------------------------------------------------------

  static void progress(int nEventsTotal, int nEventsChain);
};

#ifndef __CINT__
extern VVVTree vvv;
#endif

namespace tas {
//---------------------------------------------------------------------------------
/*                           Common_isData*/  const int &Common_isData();
//---------------------------------------------------------------------------------
/*                              Common_run*/  const int &Common_run();
//---------------------------------------------------------------------------------
/*                             Common_lumi*/  const int &Common_lumi();
//---------------------------------------------------------------------------------
/*                              Common_evt*/  const unsigned long long &Common_evt();
//---------------------------------------------------------------------------------
/*                             Common_year*/  const int &Common_year();
//---------------------------------------------------------------------------------
/*                        Common_genWeight*/  const float &Common_genWeight();
//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/  const float &Common_btagWeight_DeepCSVB();
//---------------------------------------------------------------------------------
/*                              Common_wgt*/  const float &Common_wgt();
//---------------------------------------------------------------------------------
/*         Common_LHEWeight_mg_reweighting*/  const vector<float> &Common_LHEWeight_mg_reweighting();
//---------------------------------------------------------------------------------
/*                        Common_event_PDF*/  const vector<float> &Common_event_PDF();
//---------------------------------------------------------------------------------
/*                   Common_event_QCDScale*/  const vector<float> &Common_event_QCDScale();
//---------------------------------------------------------------------------------
/*                   Common_event_puWeight*/  const float &Common_event_puWeight();
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightup*/  const float &Common_event_puWeightup();
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightdn*/  const float &Common_event_puWeightdn();
//---------------------------------------------------------------------------------
/*              Common_event_prefireWeight*/  const float &Common_event_prefireWeight();
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightup*/  const float &Common_event_prefireWeightup();
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightdn*/  const float &Common_event_prefireWeightdn();
//---------------------------------------------------------------------------------
/*              Common_event_triggerWeight*/  const float &Common_event_triggerWeight();
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightup*/  const float &Common_event_triggerWeightup();
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightdn*/  const float &Common_event_triggerWeightdn();
//---------------------------------------------------------------------------------
/*             Common_LHEReweightingWeight*/  const vector<float> &Common_LHEReweightingWeight();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ();
//---------------------------------------------------------------------------------
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8();
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  const bool &Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  const bool &Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  const bool &Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  const bool &Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  const bool &Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  const bool &Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL();
//---------------------------------------------------------------------------------
/*                      Common_HLT_IsoMu24*/  const bool &Common_HLT_IsoMu24();
//---------------------------------------------------------------------------------
/*                Common_HLT_Ele32_WPTight*/  const bool &Common_HLT_Ele32_WPTight();
//---------------------------------------------------------------------------------
/*                     Common_HLT_PFHT1050*/  const bool &Common_HLT_PFHT1050();
//---------------------------------------------------------------------------------
/*                  Common_HLT_AK8PFJet500*/  const bool &Common_HLT_AK8PFJet500();
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet380_TrimMass30*/  const bool &Common_HLT_AK8PFJet380_TrimMass30();
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet360_TrimMass30*/  const bool &Common_HLT_AK8PFJet360_TrimMass30();
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet400_TrimMass30*/  const bool &Common_HLT_AK8PFJet400_TrimMass30();
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet420_TrimMass30*/  const bool &Common_HLT_AK8PFJet420_TrimMass30();
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT750_TrimMass50*/  const bool &Common_HLT_AK8PFHT750_TrimMass50();
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT800_TrimMass50*/  const bool &Common_HLT_AK8PFHT800_TrimMass50();
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT850_TrimMass50*/  const bool &Common_HLT_AK8PFHT850_TrimMass50();
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT900_TrimMass50*/  const bool &Common_HLT_AK8PFHT900_TrimMass50();
//---------------------------------------------------------------------------------
/*Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5*/  const bool &Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5();
//---------------------------------------------------------------------------------
/*Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5*/  const bool &Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5();
//---------------------------------------------------------------------------------
/*                      Common_HLT_PFHT800*/  const bool &Common_HLT_PFHT800();
//---------------------------------------------------------------------------------
/*                      Common_HLT_PFHT900*/  const bool &Common_HLT_PFHT900();
//---------------------------------------------------------------------------------
/*                     Common_HLT_PFJet450*/  const bool &Common_HLT_PFJet450();
//---------------------------------------------------------------------------------
/*                     Common_HLT_PFJet500*/  const bool &Common_HLT_PFJet500();
//---------------------------------------------------------------------------------
/*                  Common_HLT_AK8PFJet450*/  const bool &Common_HLT_AK8PFJet450();
//---------------------------------------------------------------------------------
/*Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50*/  const bool &Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50();
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleEl*/  const bool &Common_HLT_DoubleEl();
//---------------------------------------------------------------------------------
/*                         Common_HLT_MuEG*/  const bool &Common_HLT_MuEG();
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleMu*/  const bool &Common_HLT_DoubleMu();
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_ee_em_mm*/  const bool &Common_pass_duplicate_removal_ee_em_mm();
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_mm_em_ee*/  const bool &Common_pass_duplicate_removal_mm_em_ee();
//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/  const bool &Common_noiseFlag();
//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/  const bool &Common_noiseFlagMC();
//---------------------------------------------------------------------------------
/*                      Common_passGoodRun*/  const bool &Common_passGoodRun();
//---------------------------------------------------------------------------------
/*                           Common_met_p4*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4();
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesup();
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesdn();
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jerup();
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jerdn();
//---------------------------------------------------------------------------------
/*                      Common_event_lepSF*/  const float &Common_event_lepSF();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFelup*/  const float &Common_event_lepSFelup();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFeldn*/  const float &Common_event_lepSFeldn();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmuup*/  const float &Common_event_lepSFmuup();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmudn*/  const float &Common_event_lepSFmudn();
//---------------------------------------------------------------------------------
/*                 Common_event_lepSFTight*/  const float &Common_event_lepSFTight();
//---------------------------------------------------------------------------------
/*             Common_event_lepSFelupTight*/  const float &Common_event_lepSFelupTight();
//---------------------------------------------------------------------------------
/*             Common_event_lepSFeldnTight*/  const float &Common_event_lepSFeldnTight();
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmuupTight*/  const float &Common_event_lepSFmuupTight();
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmudnTight*/  const float &Common_event_lepSFmudnTight();
//---------------------------------------------------------------------------------
/*                Common_event_tightBtagSF*/  const float &Common_event_tightBtagSF();
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFup*/  const float &Common_event_tightBtagSFup();
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFdn*/  const float &Common_event_tightBtagSFdn();
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFup*/  const float &Common_event_tightBtagSFHFup();
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFdn*/  const float &Common_event_tightBtagSFHFdn();
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFup*/  const float &Common_event_tightBtagSFLFup();
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFdn*/  const float &Common_event_tightBtagSFLFdn();
//---------------------------------------------------------------------------------
/*               Common_event_mediumBtagSF*/  const float &Common_event_mediumBtagSF();
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFup*/  const float &Common_event_mediumBtagSFup();
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFdn*/  const float &Common_event_mediumBtagSFdn();
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFup*/  const float &Common_event_mediumBtagSFHFup();
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFdn*/  const float &Common_event_mediumBtagSFHFdn();
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFup*/  const float &Common_event_mediumBtagSFLFup();
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFdn*/  const float &Common_event_mediumBtagSFLFdn();
//---------------------------------------------------------------------------------
/*                Common_event_looseBtagSF*/  const float &Common_event_looseBtagSF();
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFup*/  const float &Common_event_looseBtagSFup();
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFdn*/  const float &Common_event_looseBtagSFdn();
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFup*/  const float &Common_event_looseBtagSFHFup();
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFdn*/  const float &Common_event_looseBtagSFHFdn();
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFup*/  const float &Common_event_looseBtagSFLFup();
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFdn*/  const float &Common_event_looseBtagSFLFdn();
//---------------------------------------------------------------------------------
/*                           Common_lep_p4*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_lep_p4();
//---------------------------------------------------------------------------------
/*                         Common_lep_idxs*/  const vector<int> &Common_lep_idxs();
//---------------------------------------------------------------------------------
/*                        Common_lep_pdgid*/  const vector<int> &Common_lep_pdgid();
//---------------------------------------------------------------------------------
/*                        Common_lep_tight*/  const vector<int> &Common_lep_tight();
//---------------------------------------------------------------------------------
/*                          Common_lep_dxy*/  const vector<float> &Common_lep_dxy();
//---------------------------------------------------------------------------------
/*                           Common_lep_dz*/  const vector<float> &Common_lep_dz();
//---------------------------------------------------------------------------------
/*                         Common_lep_ip3d*/  const vector<float> &Common_lep_ip3d();
//---------------------------------------------------------------------------------
/*                        Common_lep_sip3d*/  const vector<float> &Common_lep_sip3d();
//---------------------------------------------------------------------------------
/*                           Common_lep_SF*/  const vector<float> &Common_lep_SF();
//---------------------------------------------------------------------------------
/*                      Common_lep_SFTight*/  const vector<float> &Common_lep_SFTight();
//---------------------------------------------------------------------------------
/*                         Common_lep_SFdn*/  const vector<float> &Common_lep_SFdn();
//---------------------------------------------------------------------------------
/*                    Common_lep_SFdnTight*/  const vector<float> &Common_lep_SFdnTight();
//---------------------------------------------------------------------------------
/*                         Common_lep_SFup*/  const vector<float> &Common_lep_SFup();
//---------------------------------------------------------------------------------
/*                    Common_lep_SFupTight*/  const vector<float> &Common_lep_SFupTight();
//---------------------------------------------------------------------------------
/*                           Common_jet_p4*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4();
//---------------------------------------------------------------------------------
/*                         Common_jet_idxs*/  const vector<int> &Common_jet_idxs();
//---------------------------------------------------------------------------------
/*                   Common_jet_passBloose*/  const vector<bool> &Common_jet_passBloose();
//---------------------------------------------------------------------------------
/*                  Common_jet_passBmedium*/  const vector<bool> &Common_jet_passBmedium();
//---------------------------------------------------------------------------------
/*                   Common_jet_passBtight*/  const vector<bool> &Common_jet_passBtight();
//---------------------------------------------------------------------------------
/*                           Common_jet_id*/  const vector<int> &Common_jet_id();
//---------------------------------------------------------------------------------
/*                         Common_jet_puid*/  const vector<int> &Common_jet_puid();
//---------------------------------------------------------------------------------
/*                Common_jet_overlapfatjet*/  const vector<int> &Common_jet_overlapfatjet();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesup*/  const vector<float> &Common_jet_pt_jesup();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesdn*/  const vector<float> &Common_jet_pt_jesdn();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerup*/  const vector<float> &Common_jet_pt_jerup();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerdn*/  const vector<float> &Common_jet_pt_jerdn();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesup*/  const vector<float> &Common_jet_mass_jesup();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesdn*/  const vector<float> &Common_jet_mass_jesdn();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerup*/  const vector<float> &Common_jet_mass_jerup();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerdn*/  const vector<float> &Common_jet_mass_jerdn();
//---------------------------------------------------------------------------------
/*                        Common_fatjet_p4*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_idxs*/  const vector<int> &Common_fatjet_idxs();
//---------------------------------------------------------------------------------
/*                        Common_fatjet_id*/  const vector<int> &Common_fatjet_id();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_msoftdrop*/  const vector<float> &Common_fatjet_msoftdrop();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_W*/  const vector<float> &Common_fatjet_deepMD_W();
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_W*/  const vector<float> &Common_fatjet_deep_W();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_Z*/  const vector<float> &Common_fatjet_deepMD_Z();
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_Z*/  const vector<float> &Common_fatjet_deep_Z();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_T*/  const vector<float> &Common_fatjet_deepMD_T();
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_T*/  const vector<float> &Common_fatjet_deep_T();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_deepMD_bb*/  const vector<float> &Common_fatjet_deepMD_bb();
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNetMD_W*/  const vector<float> &Common_fatjet_particleNetMD_W();
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xqq*/  const vector<float> &Common_fatjet_particleNetMD_Xqq();
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xcc*/  const vector<float> &Common_fatjet_particleNetMD_Xcc();
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xbb*/  const vector<float> &Common_fatjet_particleNetMD_Xbb();
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_QCD*/  const vector<float> &Common_fatjet_particleNetMD_QCD();
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNet_QCD*/  const vector<float> &Common_fatjet_particleNet_QCD();
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_W*/  const vector<float> &Common_fatjet_particleNet_W();
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_Z*/  const vector<float> &Common_fatjet_particleNet_Z();
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_T*/  const vector<float> &Common_fatjet_particleNet_T();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau3*/  const vector<float> &Common_fatjet_tau3();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau2*/  const vector<float> &Common_fatjet_tau2();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau1*/  const vector<float> &Common_fatjet_tau1();
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau32*/  const vector<float> &Common_fatjet_tau32();
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau21*/  const vector<float> &Common_fatjet_tau21();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_pt*/  const vector<float> &Common_fatjet_subjet0_pt();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_eta*/  const vector<float> &Common_fatjet_subjet0_eta();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_phi*/  const vector<float> &Common_fatjet_subjet0_phi();
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet0_mass*/  const vector<float> &Common_fatjet_subjet0_mass();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_pt*/  const vector<float> &Common_fatjet_subjet1_pt();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_eta*/  const vector<float> &Common_fatjet_subjet1_eta();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_phi*/  const vector<float> &Common_fatjet_subjet1_phi();
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet1_mass*/  const vector<float> &Common_fatjet_subjet1_mass();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_p4*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_subjet0_p4();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_p4*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_subjet1_p4();
//---------------------------------------------------------------------------------
/*                        Common_fatjet_WP*/  const vector<int> &Common_fatjet_WP();
//---------------------------------------------------------------------------------
/*                     Common_fatjet_WP_MD*/  const vector<int> &Common_fatjet_WP_MD();
//---------------------------------------------------------------------------------
/*            Common_fatjet_WP_antimasscut*/  const vector<int> &Common_fatjet_WP_antimasscut();
//---------------------------------------------------------------------------------
/*         Common_fatjet_WP_MD_antimasscut*/  const vector<int> &Common_fatjet_WP_MD_antimasscut();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFVLoose*/  const vector<float> &Common_fatjet_SFVLoose();
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFLoose*/  const vector<float> &Common_fatjet_SFLoose();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFMedium*/  const vector<float> &Common_fatjet_SFMedium();
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFTight*/  const vector<float> &Common_fatjet_SFTight();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnVLoose*/  const vector<float> &Common_fatjet_SFdnVLoose();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnLoose*/  const vector<float> &Common_fatjet_SFdnLoose();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnMedium*/  const vector<float> &Common_fatjet_SFdnMedium();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnTight*/  const vector<float> &Common_fatjet_SFdnTight();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupVLoose*/  const vector<float> &Common_fatjet_SFupVLoose();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupLoose*/  const vector<float> &Common_fatjet_SFupLoose();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupMedium*/  const vector<float> &Common_fatjet_SFupMedium();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupTight*/  const vector<float> &Common_fatjet_SFupTight();
//---------------------------------------------------------------------------------
/*                Common_fatjet_MD_SFLoose*/  const vector<float> &Common_fatjet_MD_SFLoose();
//---------------------------------------------------------------------------------
/*               Common_fatjet_MD_SFMedium*/  const vector<float> &Common_fatjet_MD_SFMedium();
//---------------------------------------------------------------------------------
/*                Common_fatjet_MD_SFTight*/  const vector<float> &Common_fatjet_MD_SFTight();
//---------------------------------------------------------------------------------
/*              Common_fatjet_MD_SFdnLoose*/  const vector<float> &Common_fatjet_MD_SFdnLoose();
//---------------------------------------------------------------------------------
/*             Common_fatjet_MD_SFdnMedium*/  const vector<float> &Common_fatjet_MD_SFdnMedium();
//---------------------------------------------------------------------------------
/*              Common_fatjet_MD_SFdnTight*/  const vector<float> &Common_fatjet_MD_SFdnTight();
//---------------------------------------------------------------------------------
/*              Common_fatjet_MD_SFupLoose*/  const vector<float> &Common_fatjet_MD_SFupLoose();
//---------------------------------------------------------------------------------
/*             Common_fatjet_MD_SFupMedium*/  const vector<float> &Common_fatjet_MD_SFupMedium();
//---------------------------------------------------------------------------------
/*              Common_fatjet_MD_SFupTight*/  const vector<float> &Common_fatjet_MD_SFupTight();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesup*/  const vector<float> &Common_fatjet_pt_jesup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesdn*/  const vector<float> &Common_fatjet_pt_jesdn();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerup*/  const vector<float> &Common_fatjet_pt_jerup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerdn*/  const vector<float> &Common_fatjet_pt_jerdn();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesup*/  const vector<float> &Common_fatjet_msoftdrop_jesup();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesdn*/  const vector<float> &Common_fatjet_msoftdrop_jesdn();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerup*/  const vector<float> &Common_fatjet_msoftdrop_jerup();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerdn*/  const vector<float> &Common_fatjet_msoftdrop_jerdn();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsup*/  const vector<float> &Common_fatjet_msoftdrop_jmsup();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsdn*/  const vector<float> &Common_fatjet_msoftdrop_jmsdn();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrup*/  const vector<float> &Common_fatjet_msoftdrop_jmrup();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrdn*/  const vector<float> &Common_fatjet_msoftdrop_jmrdn();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesup*/  const vector<float> &Common_fatjet_mass_jesup();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesdn*/  const vector<float> &Common_fatjet_mass_jesdn();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerup*/  const vector<float> &Common_fatjet_mass_jerup();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerdn*/  const vector<float> &Common_fatjet_mass_jerdn();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsup*/  const vector<float> &Common_fatjet_mass_jmsup();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsdn*/  const vector<float> &Common_fatjet_mass_jmsdn();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrup*/  const vector<float> &Common_fatjet_mass_jmrup();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrdn*/  const vector<float> &Common_fatjet_mass_jmrdn();
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFVLoose*/  const float &Common_eventweight_fatjet_SFVLoose();
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFLoose*/  const float &Common_eventweight_fatjet_SFLoose();
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFMedium*/  const float &Common_eventweight_fatjet_SFMedium();
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFTight*/  const float &Common_eventweight_fatjet_SFTight();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnVLoose*/  const float &Common_eventweight_fatjet_SFdnVLoose();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnLoose*/  const float &Common_eventweight_fatjet_SFdnLoose();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnMedium*/  const float &Common_eventweight_fatjet_SFdnMedium();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnTight*/  const float &Common_eventweight_fatjet_SFdnTight();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupVLoose*/  const float &Common_eventweight_fatjet_SFupVLoose();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupLoose*/  const float &Common_eventweight_fatjet_SFupLoose();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupMedium*/  const float &Common_eventweight_fatjet_SFupMedium();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupTight*/  const float &Common_eventweight_fatjet_SFupTight();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_MD_SFLoose*/  const float &Common_eventweight_fatjet_MD_SFLoose();
//---------------------------------------------------------------------------------
/*   Common_eventweight_fatjet_MD_SFMedium*/  const float &Common_eventweight_fatjet_MD_SFMedium();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_MD_SFTight*/  const float &Common_eventweight_fatjet_MD_SFTight();
//---------------------------------------------------------------------------------
/*  Common_eventweight_fatjet_MD_SFdnLoose*/  const float &Common_eventweight_fatjet_MD_SFdnLoose();
//---------------------------------------------------------------------------------
/* Common_eventweight_fatjet_MD_SFdnMedium*/  const float &Common_eventweight_fatjet_MD_SFdnMedium();
//---------------------------------------------------------------------------------
/*  Common_eventweight_fatjet_MD_SFdnTight*/  const float &Common_eventweight_fatjet_MD_SFdnTight();
//---------------------------------------------------------------------------------
/*  Common_eventweight_fatjet_MD_SFupLoose*/  const float &Common_eventweight_fatjet_MD_SFupLoose();
//---------------------------------------------------------------------------------
/* Common_eventweight_fatjet_MD_SFupMedium*/  const float &Common_eventweight_fatjet_MD_SFupMedium();
//---------------------------------------------------------------------------------
/*  Common_eventweight_fatjet_MD_SFupTight*/  const float &Common_eventweight_fatjet_MD_SFupTight();
//---------------------------------------------------------------------------------
/*                         Common_nb_loose*/  const int &Common_nb_loose();
//---------------------------------------------------------------------------------
/*                        Common_nb_medium*/  const int &Common_nb_medium();
//---------------------------------------------------------------------------------
/*                         Common_nb_tight*/  const int &Common_nb_tight();
//---------------------------------------------------------------------------------
/*                          Common_gen_idx*/  const vector<int> &Common_gen_idx();
//---------------------------------------------------------------------------------
/*                   Common_gen_mother_idx*/  const vector<int> &Common_gen_mother_idx();
//---------------------------------------------------------------------------------
/*                    Common_gen_mother_id*/  const vector<int> &Common_gen_mother_id();
//---------------------------------------------------------------------------------
/*                        Common_gen_pdgid*/  const vector<int> &Common_gen_pdgid();
//---------------------------------------------------------------------------------
/*                          Common_gen_p4s*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_gen_p4s();
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_idx*/  const vector<int> &Common_gen_vvvdecay_idx();
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_mother_idx*/  const vector<int> &Common_gen_vvvdecay_mother_idx();
//---------------------------------------------------------------------------------
/*           Common_gen_vvvdecay_mother_id*/  const vector<int> &Common_gen_vvvdecay_mother_id();
//---------------------------------------------------------------------------------
/*               Common_gen_vvvdecay_pdgid*/  const vector<int> &Common_gen_vvvdecay_pdgid();
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_p4s*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_gen_vvvdecay_p4s();
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_taudecayid*/  const vector<int> &Common_gen_vvvdecay_taudecayid();
//---------------------------------------------------------------------------------
/*                         Common_isSignal*/  const bool &Common_isSignal();
//---------------------------------------------------------------------------------
/*                              Common_n_W*/  const int &Common_n_W();
//---------------------------------------------------------------------------------
/*                              Common_n_Z*/  const int &Common_n_Z();
//---------------------------------------------------------------------------------
/*                          Common_n_lep_Z*/  const int &Common_n_lep_Z();
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_Z*/  const int &Common_n_leptau_Z();
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_Z*/  const int &Common_n_hadtau_Z();
//---------------------------------------------------------------------------------
/*                           Common_n_nu_Z*/  const int &Common_n_nu_Z();
//---------------------------------------------------------------------------------
/*                            Common_n_b_Z*/  const int &Common_n_b_Z();
//---------------------------------------------------------------------------------
/*                          Common_n_lep_W*/  const int &Common_n_lep_W();
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_W*/  const int &Common_n_leptau_W();
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_W*/  const int &Common_n_hadtau_W();
//---------------------------------------------------------------------------------
/*                        Common_haslepWSS*/  const bool &Common_haslepWSS();
//---------------------------------------------------------------------------------
/*                            Common_genHT*/  const float &Common_genHT();
//---------------------------------------------------------------------------------
/*                  Common_gen_n_light_lep*/  const int &Common_gen_n_light_lep();
//---------------------------------------------------------------------------------
/*                   Common_gen_VH_channel*/  const int &Common_gen_VH_channel();
//---------------------------------------------------------------------------------
/*                Cut_4LepMET_Preselection*/  const bool &Cut_4LepMET_Preselection();
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/  const bool &Cut_4LepMET_emuChannel();
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/  const bool &Cut_4LepMET_offzChannel();
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/  const bool &Cut_4LepMET_onzChannel();
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/  const bool &Cut_4LepMET_onzChannel_HighMET();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/  const int &Var_4LepMET_Zcand_lep_idx_0();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  const int &Var_4LepMET_Zcand_lep_pdgid_0();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_0*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_Zcand_lep_p4_0();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_1*/  const int &Var_4LepMET_Zcand_lep_idx_1();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  const int &Var_4LepMET_Zcand_lep_pdgid_1();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_1*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_Zcand_lep_p4_1();
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_Zcand_mll*/  const float &Var_4LepMET_Zcand_mll();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_0*/  const int &Var_4LepMET_other_lep_idx_0();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_0*/  const int &Var_4LepMET_other_lep_pdgid_0();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_0*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_other_lep_p4_0();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_1*/  const int &Var_4LepMET_other_lep_idx_1();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_1*/  const int &Var_4LepMET_other_lep_pdgid_1();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_1*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_other_lep_p4_1();
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_other_mll*/  const float &Var_4LepMET_other_mll();
//---------------------------------------------------------------------------------
/*                         Var_4LepMET_mt2*/  const float &Var_4LepMET_mt2();
//---------------------------------------------------------------------------------
}
#endif
