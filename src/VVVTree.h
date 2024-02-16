// -*- C++ -*-
// This is a header file generated with the command:
// makeCMS3ClassFiles("/uscms/home/ymiao/nobackup/VVV/EFTAnalysisLooper/ForPullRequest/VVVNanoLooper/test.root", "t", "VVVTree", "tas", "vvv")

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
/*         Common_LHEWeight_mg_reweighting*/  vector<float> *Common_LHEWeight_mg_reweighting_;
/*         Common_LHEWeight_mg_reweighting*/  TBranch *Common_LHEWeight_mg_reweighting_branch;
/*         Common_LHEWeight_mg_reweighting*/  bool     Common_LHEWeight_mg_reweighting_isLoaded;
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
/*                        Common_passGoodRun*/  bool     Common_passGoodRun_;
/*                        Common_passGoodRun*/  TBranch *Common_passGoodRun_branch;
/*                        Common_passGoodRun*/  bool     Common_passGoodRun_isLoaded;
//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/  bool     Common_noiseFlag_;
/*                        Common_noiseFlag*/  TBranch *Common_noiseFlag_branch;
/*                        Common_noiseFlag*/  bool     Common_noiseFlag_isLoaded;
//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/  bool     Common_noiseFlagMC_;
/*                      Common_noiseFlagMC*/  TBranch *Common_noiseFlagMC_branch;
/*                      Common_noiseFlagMC*/  bool     Common_noiseFlagMC_isLoaded;
//---------------------------------------------------------------------------------
/*                           Common_met_p4*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_;
/*                           Common_met_p4*/  TBranch *Common_met_p4_branch;
/*                           Common_met_p4*/  bool     Common_met_p4_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesAbsoluteStatup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesAbsoluteStatup_;
/*         Common_met_p4_jesAbsoluteStatup*/  TBranch *Common_met_p4_jesAbsoluteStatup_branch;
/*         Common_met_p4_jesAbsoluteStatup*/  bool     Common_met_p4_jesAbsoluteStatup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesAbsoluteStatdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesAbsoluteStatdn_;
/*         Common_met_p4_jesAbsoluteStatdn*/  TBranch *Common_met_p4_jesAbsoluteStatdn_branch;
/*         Common_met_p4_jesAbsoluteStatdn*/  bool     Common_met_p4_jesAbsoluteStatdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesAbsoluteScaleup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesAbsoluteScaleup_;
/*        Common_met_p4_jesAbsoluteScaleup*/  TBranch *Common_met_p4_jesAbsoluteScaleup_branch;
/*        Common_met_p4_jesAbsoluteScaleup*/  bool     Common_met_p4_jesAbsoluteScaleup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesAbsoluteScaledn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesAbsoluteScaledn_;
/*        Common_met_p4_jesAbsoluteScaledn*/  TBranch *Common_met_p4_jesAbsoluteScaledn_branch;
/*        Common_met_p4_jesAbsoluteScaledn*/  bool     Common_met_p4_jesAbsoluteScaledn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_met_p4_jesAbsoluteMPFBiasup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesAbsoluteMPFBiasup_;
/*      Common_met_p4_jesAbsoluteMPFBiasup*/  TBranch *Common_met_p4_jesAbsoluteMPFBiasup_branch;
/*      Common_met_p4_jesAbsoluteMPFBiasup*/  bool     Common_met_p4_jesAbsoluteMPFBiasup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_met_p4_jesAbsoluteMPFBiasdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesAbsoluteMPFBiasdn_;
/*      Common_met_p4_jesAbsoluteMPFBiasdn*/  TBranch *Common_met_p4_jesAbsoluteMPFBiasdn_branch;
/*      Common_met_p4_jesAbsoluteMPFBiasdn*/  bool     Common_met_p4_jesAbsoluteMPFBiasdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesFragmentationup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesFragmentationup_;
/*        Common_met_p4_jesFragmentationup*/  TBranch *Common_met_p4_jesFragmentationup_branch;
/*        Common_met_p4_jesFragmentationup*/  bool     Common_met_p4_jesFragmentationup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesFragmentationdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesFragmentationdn_;
/*        Common_met_p4_jesFragmentationdn*/  TBranch *Common_met_p4_jesFragmentationdn_branch;
/*        Common_met_p4_jesFragmentationdn*/  bool     Common_met_p4_jesFragmentationdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesSinglePionECALup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesSinglePionECALup_;
/*       Common_met_p4_jesSinglePionECALup*/  TBranch *Common_met_p4_jesSinglePionECALup_branch;
/*       Common_met_p4_jesSinglePionECALup*/  bool     Common_met_p4_jesSinglePionECALup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesSinglePionECALdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesSinglePionECALdn_;
/*       Common_met_p4_jesSinglePionECALdn*/  TBranch *Common_met_p4_jesSinglePionECALdn_branch;
/*       Common_met_p4_jesSinglePionECALdn*/  bool     Common_met_p4_jesSinglePionECALdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesSinglePionHCALup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesSinglePionHCALup_;
/*       Common_met_p4_jesSinglePionHCALup*/  TBranch *Common_met_p4_jesSinglePionHCALup_branch;
/*       Common_met_p4_jesSinglePionHCALup*/  bool     Common_met_p4_jesSinglePionHCALup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesSinglePionHCALdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesSinglePionHCALdn_;
/*       Common_met_p4_jesSinglePionHCALdn*/  TBranch *Common_met_p4_jesSinglePionHCALdn_branch;
/*       Common_met_p4_jesSinglePionHCALdn*/  bool     Common_met_p4_jesSinglePionHCALdn_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_met_p4_jesFlavorQCDup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesFlavorQCDup_;
/*            Common_met_p4_jesFlavorQCDup*/  TBranch *Common_met_p4_jesFlavorQCDup_branch;
/*            Common_met_p4_jesFlavorQCDup*/  bool     Common_met_p4_jesFlavorQCDup_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_met_p4_jesFlavorQCDdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesFlavorQCDdn_;
/*            Common_met_p4_jesFlavorQCDdn*/  TBranch *Common_met_p4_jesFlavorQCDdn_branch;
/*            Common_met_p4_jesFlavorQCDdn*/  bool     Common_met_p4_jesFlavorQCDdn_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_met_p4_jesTimePtEtaup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesTimePtEtaup_;
/*            Common_met_p4_jesTimePtEtaup*/  TBranch *Common_met_p4_jesTimePtEtaup_branch;
/*            Common_met_p4_jesTimePtEtaup*/  bool     Common_met_p4_jesTimePtEtaup_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_met_p4_jesTimePtEtadn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesTimePtEtadn_;
/*            Common_met_p4_jesTimePtEtadn*/  TBranch *Common_met_p4_jesTimePtEtadn_branch;
/*            Common_met_p4_jesTimePtEtadn*/  bool     Common_met_p4_jesTimePtEtadn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeJEREC1up*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeJEREC1up_;
/*       Common_met_p4_jesRelativeJEREC1up*/  TBranch *Common_met_p4_jesRelativeJEREC1up_branch;
/*       Common_met_p4_jesRelativeJEREC1up*/  bool     Common_met_p4_jesRelativeJEREC1up_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeJEREC1dn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeJEREC1dn_;
/*       Common_met_p4_jesRelativeJEREC1dn*/  TBranch *Common_met_p4_jesRelativeJEREC1dn_branch;
/*       Common_met_p4_jesRelativeJEREC1dn*/  bool     Common_met_p4_jesRelativeJEREC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeJEREC2up*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeJEREC2up_;
/*       Common_met_p4_jesRelativeJEREC2up*/  TBranch *Common_met_p4_jesRelativeJEREC2up_branch;
/*       Common_met_p4_jesRelativeJEREC2up*/  bool     Common_met_p4_jesRelativeJEREC2up_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeJEREC2dn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeJEREC2dn_;
/*       Common_met_p4_jesRelativeJEREC2dn*/  TBranch *Common_met_p4_jesRelativeJEREC2dn_branch;
/*       Common_met_p4_jesRelativeJEREC2dn*/  bool     Common_met_p4_jesRelativeJEREC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativeJERHFup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeJERHFup_;
/*        Common_met_p4_jesRelativeJERHFup*/  TBranch *Common_met_p4_jesRelativeJERHFup_branch;
/*        Common_met_p4_jesRelativeJERHFup*/  bool     Common_met_p4_jesRelativeJERHFup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativeJERHFdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeJERHFdn_;
/*        Common_met_p4_jesRelativeJERHFdn*/  TBranch *Common_met_p4_jesRelativeJERHFdn_branch;
/*        Common_met_p4_jesRelativeJERHFdn*/  bool     Common_met_p4_jesRelativeJERHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesRelativePtBBup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativePtBBup_;
/*         Common_met_p4_jesRelativePtBBup*/  TBranch *Common_met_p4_jesRelativePtBBup_branch;
/*         Common_met_p4_jesRelativePtBBup*/  bool     Common_met_p4_jesRelativePtBBup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesRelativePtBBdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativePtBBdn_;
/*         Common_met_p4_jesRelativePtBBdn*/  TBranch *Common_met_p4_jesRelativePtBBdn_branch;
/*         Common_met_p4_jesRelativePtBBdn*/  bool     Common_met_p4_jesRelativePtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativePtEC1up*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativePtEC1up_;
/*        Common_met_p4_jesRelativePtEC1up*/  TBranch *Common_met_p4_jesRelativePtEC1up_branch;
/*        Common_met_p4_jesRelativePtEC1up*/  bool     Common_met_p4_jesRelativePtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativePtEC1dn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativePtEC1dn_;
/*        Common_met_p4_jesRelativePtEC1dn*/  TBranch *Common_met_p4_jesRelativePtEC1dn_branch;
/*        Common_met_p4_jesRelativePtEC1dn*/  bool     Common_met_p4_jesRelativePtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativePtEC2up*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativePtEC2up_;
/*        Common_met_p4_jesRelativePtEC2up*/  TBranch *Common_met_p4_jesRelativePtEC2up_branch;
/*        Common_met_p4_jesRelativePtEC2up*/  bool     Common_met_p4_jesRelativePtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativePtEC2dn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativePtEC2dn_;
/*        Common_met_p4_jesRelativePtEC2dn*/  TBranch *Common_met_p4_jesRelativePtEC2dn_branch;
/*        Common_met_p4_jesRelativePtEC2dn*/  bool     Common_met_p4_jesRelativePtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesRelativePtHFup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativePtHFup_;
/*         Common_met_p4_jesRelativePtHFup*/  TBranch *Common_met_p4_jesRelativePtHFup_branch;
/*         Common_met_p4_jesRelativePtHFup*/  bool     Common_met_p4_jesRelativePtHFup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesRelativePtHFdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativePtHFdn_;
/*         Common_met_p4_jesRelativePtHFdn*/  TBranch *Common_met_p4_jesRelativePtHFdn_branch;
/*         Common_met_p4_jesRelativePtHFdn*/  bool     Common_met_p4_jesRelativePtHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesRelativeBalup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeBalup_;
/*          Common_met_p4_jesRelativeBalup*/  TBranch *Common_met_p4_jesRelativeBalup_branch;
/*          Common_met_p4_jesRelativeBalup*/  bool     Common_met_p4_jesRelativeBalup_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesRelativeBaldn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeBaldn_;
/*          Common_met_p4_jesRelativeBaldn*/  TBranch *Common_met_p4_jesRelativeBaldn_branch;
/*          Common_met_p4_jesRelativeBaldn*/  bool     Common_met_p4_jesRelativeBaldn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeSampleup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeSampleup_;
/*       Common_met_p4_jesRelativeSampleup*/  TBranch *Common_met_p4_jesRelativeSampleup_branch;
/*       Common_met_p4_jesRelativeSampleup*/  bool     Common_met_p4_jesRelativeSampleup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeSampledn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeSampledn_;
/*       Common_met_p4_jesRelativeSampledn*/  TBranch *Common_met_p4_jesRelativeSampledn_branch;
/*       Common_met_p4_jesRelativeSampledn*/  bool     Common_met_p4_jesRelativeSampledn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesRelativeFSRup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeFSRup_;
/*          Common_met_p4_jesRelativeFSRup*/  TBranch *Common_met_p4_jesRelativeFSRup_branch;
/*          Common_met_p4_jesRelativeFSRup*/  bool     Common_met_p4_jesRelativeFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesRelativeFSRdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeFSRdn_;
/*          Common_met_p4_jesRelativeFSRdn*/  TBranch *Common_met_p4_jesRelativeFSRdn_branch;
/*          Common_met_p4_jesRelativeFSRdn*/  bool     Common_met_p4_jesRelativeFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_met_p4_jesRelativeStatFSRup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeStatFSRup_;
/*      Common_met_p4_jesRelativeStatFSRup*/  TBranch *Common_met_p4_jesRelativeStatFSRup_branch;
/*      Common_met_p4_jesRelativeStatFSRup*/  bool     Common_met_p4_jesRelativeStatFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_met_p4_jesRelativeStatFSRdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeStatFSRdn_;
/*      Common_met_p4_jesRelativeStatFSRdn*/  TBranch *Common_met_p4_jesRelativeStatFSRdn_branch;
/*      Common_met_p4_jesRelativeStatFSRdn*/  bool     Common_met_p4_jesRelativeStatFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeStatECup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeStatECup_;
/*       Common_met_p4_jesRelativeStatECup*/  TBranch *Common_met_p4_jesRelativeStatECup_branch;
/*       Common_met_p4_jesRelativeStatECup*/  bool     Common_met_p4_jesRelativeStatECup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeStatECdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeStatECdn_;
/*       Common_met_p4_jesRelativeStatECdn*/  TBranch *Common_met_p4_jesRelativeStatECdn_branch;
/*       Common_met_p4_jesRelativeStatECdn*/  bool     Common_met_p4_jesRelativeStatECdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeStatHFup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeStatHFup_;
/*       Common_met_p4_jesRelativeStatHFup*/  TBranch *Common_met_p4_jesRelativeStatHFup_branch;
/*       Common_met_p4_jesRelativeStatHFup*/  bool     Common_met_p4_jesRelativeStatHFup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeStatHFdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesRelativeStatHFdn_;
/*       Common_met_p4_jesRelativeStatHFdn*/  TBranch *Common_met_p4_jesRelativeStatHFdn_branch;
/*       Common_met_p4_jesRelativeStatHFdn*/  bool     Common_met_p4_jesRelativeStatHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesPileUpDataMCup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesPileUpDataMCup_;
/*         Common_met_p4_jesPileUpDataMCup*/  TBranch *Common_met_p4_jesPileUpDataMCup_branch;
/*         Common_met_p4_jesPileUpDataMCup*/  bool     Common_met_p4_jesPileUpDataMCup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesPileUpDataMCdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesPileUpDataMCdn_;
/*         Common_met_p4_jesPileUpDataMCdn*/  TBranch *Common_met_p4_jesPileUpDataMCdn_branch;
/*         Common_met_p4_jesPileUpDataMCdn*/  bool     Common_met_p4_jesPileUpDataMCdn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtRefup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesPileUpPtRefup_;
/*          Common_met_p4_jesPileUpPtRefup*/  TBranch *Common_met_p4_jesPileUpPtRefup_branch;
/*          Common_met_p4_jesPileUpPtRefup*/  bool     Common_met_p4_jesPileUpPtRefup_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtRefdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesPileUpPtRefdn_;
/*          Common_met_p4_jesPileUpPtRefdn*/  TBranch *Common_met_p4_jesPileUpPtRefdn_branch;
/*          Common_met_p4_jesPileUpPtRefdn*/  bool     Common_met_p4_jesPileUpPtRefdn_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_met_p4_jesPileUpPtBBup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesPileUpPtBBup_;
/*           Common_met_p4_jesPileUpPtBBup*/  TBranch *Common_met_p4_jesPileUpPtBBup_branch;
/*           Common_met_p4_jesPileUpPtBBup*/  bool     Common_met_p4_jesPileUpPtBBup_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_met_p4_jesPileUpPtBBdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesPileUpPtBBdn_;
/*           Common_met_p4_jesPileUpPtBBdn*/  TBranch *Common_met_p4_jesPileUpPtBBdn_branch;
/*           Common_met_p4_jesPileUpPtBBdn*/  bool     Common_met_p4_jesPileUpPtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtEC1up*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesPileUpPtEC1up_;
/*          Common_met_p4_jesPileUpPtEC1up*/  TBranch *Common_met_p4_jesPileUpPtEC1up_branch;
/*          Common_met_p4_jesPileUpPtEC1up*/  bool     Common_met_p4_jesPileUpPtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtEC1dn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesPileUpPtEC1dn_;
/*          Common_met_p4_jesPileUpPtEC1dn*/  TBranch *Common_met_p4_jesPileUpPtEC1dn_branch;
/*          Common_met_p4_jesPileUpPtEC1dn*/  bool     Common_met_p4_jesPileUpPtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtEC2up*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesPileUpPtEC2up_;
/*          Common_met_p4_jesPileUpPtEC2up*/  TBranch *Common_met_p4_jesPileUpPtEC2up_branch;
/*          Common_met_p4_jesPileUpPtEC2up*/  bool     Common_met_p4_jesPileUpPtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtEC2dn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesPileUpPtEC2dn_;
/*          Common_met_p4_jesPileUpPtEC2dn*/  TBranch *Common_met_p4_jesPileUpPtEC2dn_branch;
/*          Common_met_p4_jesPileUpPtEC2dn*/  bool     Common_met_p4_jesPileUpPtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_met_p4_jesPileUpPtHFup*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesPileUpPtHFup_;
/*           Common_met_p4_jesPileUpPtHFup*/  TBranch *Common_met_p4_jesPileUpPtHFup_branch;
/*           Common_met_p4_jesPileUpPtHFup*/  bool     Common_met_p4_jesPileUpPtHFup_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_met_p4_jesPileUpPtHFdn*/  ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > *Common_met_p4_jesPileUpPtHFdn_;
/*           Common_met_p4_jesPileUpPtHFdn*/  TBranch *Common_met_p4_jesPileUpPtHFdn_branch;
/*           Common_met_p4_jesPileUpPtHFdn*/  bool     Common_met_p4_jesPileUpPtHFdn_isLoaded;
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
/*         Common_jet_p4_jesAbsoluteStatup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesAbsoluteStatup_;
/*         Common_jet_p4_jesAbsoluteStatup*/  TBranch *Common_jet_p4_jesAbsoluteStatup_branch;
/*         Common_jet_p4_jesAbsoluteStatup*/  bool     Common_jet_p4_jesAbsoluteStatup_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesdn*/  vector<float> *Common_jet_pt_jesdn_;
/*                     Common_jet_pt_jesdn*/  TBranch *Common_jet_pt_jesdn_branch;
/*                     Common_jet_pt_jesdn*/  bool     Common_jet_pt_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesAbsoluteStatdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesAbsoluteStatdn_;
/*         Common_jet_p4_jesAbsoluteStatdn*/  TBranch *Common_jet_p4_jesAbsoluteStatdn_branch;
/*         Common_jet_p4_jesAbsoluteStatdn*/  bool     Common_jet_p4_jesAbsoluteStatdn_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerup*/  vector<float> *Common_jet_pt_jerup_;
/*                     Common_jet_pt_jerup*/  TBranch *Common_jet_pt_jerup_branch;
/*                     Common_jet_pt_jerup*/  bool     Common_jet_pt_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesAbsoluteScaleup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesAbsoluteScaleup_;
/*        Common_jet_p4_jesAbsoluteScaleup*/  TBranch *Common_jet_p4_jesAbsoluteScaleup_branch;
/*        Common_jet_p4_jesAbsoluteScaleup*/  bool     Common_jet_p4_jesAbsoluteScaleup_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerdn*/  vector<float> *Common_jet_pt_jerdn_;
/*                     Common_jet_pt_jerdn*/  TBranch *Common_jet_pt_jerdn_branch;
/*                     Common_jet_pt_jerdn*/  bool     Common_jet_pt_jerdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesAbsoluteScaledn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesAbsoluteScaledn_;
/*        Common_jet_p4_jesAbsoluteScaledn*/  TBranch *Common_jet_p4_jesAbsoluteScaledn_branch;
/*        Common_jet_p4_jesAbsoluteScaledn*/  bool     Common_jet_p4_jesAbsoluteScaledn_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesup*/  vector<float> *Common_jet_mass_jesup_;
/*                   Common_jet_mass_jesup*/  TBranch *Common_jet_mass_jesup_branch;
/*                   Common_jet_mass_jesup*/  bool     Common_jet_mass_jesup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_jet_p4_jesAbsoluteMPFBiasup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesAbsoluteMPFBiasup_;
/*      Common_jet_p4_jesAbsoluteMPFBiasup*/  TBranch *Common_jet_p4_jesAbsoluteMPFBiasup_branch;
/*      Common_jet_p4_jesAbsoluteMPFBiasup*/  bool     Common_jet_p4_jesAbsoluteMPFBiasup_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesdn*/  vector<float> *Common_jet_mass_jesdn_;
/*                   Common_jet_mass_jesdn*/  TBranch *Common_jet_mass_jesdn_branch;
/*                   Common_jet_mass_jesdn*/  bool     Common_jet_mass_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_jet_p4_jesAbsoluteMPFBiasdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesAbsoluteMPFBiasdn_;
/*      Common_jet_p4_jesAbsoluteMPFBiasdn*/  TBranch *Common_jet_p4_jesAbsoluteMPFBiasdn_branch;
/*      Common_jet_p4_jesAbsoluteMPFBiasdn*/  bool     Common_jet_p4_jesAbsoluteMPFBiasdn_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerup*/  vector<float> *Common_jet_mass_jerup_;
/*                   Common_jet_mass_jerup*/  TBranch *Common_jet_mass_jerup_branch;
/*                   Common_jet_mass_jerup*/  bool     Common_jet_mass_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesFragmentationup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesFragmentationup_;
/*        Common_jet_p4_jesFragmentationup*/  TBranch *Common_jet_p4_jesFragmentationup_branch;
/*        Common_jet_p4_jesFragmentationup*/  bool     Common_jet_p4_jesFragmentationup_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerdn*/  vector<float> *Common_jet_mass_jerdn_;
/*                   Common_jet_mass_jerdn*/  TBranch *Common_jet_mass_jerdn_branch;
/*                   Common_jet_mass_jerdn*/  bool     Common_jet_mass_jerdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesFragmentationdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesFragmentationdn_;
/*        Common_jet_p4_jesFragmentationdn*/  TBranch *Common_jet_p4_jesFragmentationdn_branch;
/*        Common_jet_p4_jesFragmentationdn*/  bool     Common_jet_p4_jesFragmentationdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesSinglePionECALup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesSinglePionECALup_;
/*       Common_jet_p4_jesSinglePionECALup*/  TBranch *Common_jet_p4_jesSinglePionECALup_branch;
/*       Common_jet_p4_jesSinglePionECALup*/  bool     Common_jet_p4_jesSinglePionECALup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesSinglePionECALdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesSinglePionECALdn_;
/*       Common_jet_p4_jesSinglePionECALdn*/  TBranch *Common_jet_p4_jesSinglePionECALdn_branch;
/*       Common_jet_p4_jesSinglePionECALdn*/  bool     Common_jet_p4_jesSinglePionECALdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesSinglePionHCALup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesSinglePionHCALup_;
/*       Common_jet_p4_jesSinglePionHCALup*/  TBranch *Common_jet_p4_jesSinglePionHCALup_branch;
/*       Common_jet_p4_jesSinglePionHCALup*/  bool     Common_jet_p4_jesSinglePionHCALup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesSinglePionHCALdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesSinglePionHCALdn_;
/*       Common_jet_p4_jesSinglePionHCALdn*/  TBranch *Common_jet_p4_jesSinglePionHCALdn_branch;
/*       Common_jet_p4_jesSinglePionHCALdn*/  bool     Common_jet_p4_jesSinglePionHCALdn_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_jet_p4_jesFlavorQCDup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesFlavorQCDup_;
/*            Common_jet_p4_jesFlavorQCDup*/  TBranch *Common_jet_p4_jesFlavorQCDup_branch;
/*            Common_jet_p4_jesFlavorQCDup*/  bool     Common_jet_p4_jesFlavorQCDup_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_jet_p4_jesFlavorQCDdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesFlavorQCDdn_;
/*            Common_jet_p4_jesFlavorQCDdn*/  TBranch *Common_jet_p4_jesFlavorQCDdn_branch;
/*            Common_jet_p4_jesFlavorQCDdn*/  bool     Common_jet_p4_jesFlavorQCDdn_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_jet_p4_jesTimePtEtaup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesTimePtEtaup_;
/*            Common_jet_p4_jesTimePtEtaup*/  TBranch *Common_jet_p4_jesTimePtEtaup_branch;
/*            Common_jet_p4_jesTimePtEtaup*/  bool     Common_jet_p4_jesTimePtEtaup_isLoaded;
//---------------------------------------------------------------------------------
/*            Common_jet_p4_jesTimePtEtadn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesTimePtEtadn_;
/*            Common_jet_p4_jesTimePtEtadn*/  TBranch *Common_jet_p4_jesTimePtEtadn_branch;
/*            Common_jet_p4_jesTimePtEtadn*/  bool     Common_jet_p4_jesTimePtEtadn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeJEREC1up*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeJEREC1up_;
/*       Common_jet_p4_jesRelativeJEREC1up*/  TBranch *Common_jet_p4_jesRelativeJEREC1up_branch;
/*       Common_jet_p4_jesRelativeJEREC1up*/  bool     Common_jet_p4_jesRelativeJEREC1up_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeJEREC1dn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeJEREC1dn_;
/*       Common_jet_p4_jesRelativeJEREC1dn*/  TBranch *Common_jet_p4_jesRelativeJEREC1dn_branch;
/*       Common_jet_p4_jesRelativeJEREC1dn*/  bool     Common_jet_p4_jesRelativeJEREC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeJEREC2up*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeJEREC2up_;
/*       Common_jet_p4_jesRelativeJEREC2up*/  TBranch *Common_jet_p4_jesRelativeJEREC2up_branch;
/*       Common_jet_p4_jesRelativeJEREC2up*/  bool     Common_jet_p4_jesRelativeJEREC2up_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeJEREC2dn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeJEREC2dn_;
/*       Common_jet_p4_jesRelativeJEREC2dn*/  TBranch *Common_jet_p4_jesRelativeJEREC2dn_branch;
/*       Common_jet_p4_jesRelativeJEREC2dn*/  bool     Common_jet_p4_jesRelativeJEREC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativeJERHFup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeJERHFup_;
/*        Common_jet_p4_jesRelativeJERHFup*/  TBranch *Common_jet_p4_jesRelativeJERHFup_branch;
/*        Common_jet_p4_jesRelativeJERHFup*/  bool     Common_jet_p4_jesRelativeJERHFup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativeJERHFdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeJERHFdn_;
/*        Common_jet_p4_jesRelativeJERHFdn*/  TBranch *Common_jet_p4_jesRelativeJERHFdn_branch;
/*        Common_jet_p4_jesRelativeJERHFdn*/  bool     Common_jet_p4_jesRelativeJERHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesRelativePtBBup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativePtBBup_;
/*         Common_jet_p4_jesRelativePtBBup*/  TBranch *Common_jet_p4_jesRelativePtBBup_branch;
/*         Common_jet_p4_jesRelativePtBBup*/  bool     Common_jet_p4_jesRelativePtBBup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesRelativePtBBdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativePtBBdn_;
/*         Common_jet_p4_jesRelativePtBBdn*/  TBranch *Common_jet_p4_jesRelativePtBBdn_branch;
/*         Common_jet_p4_jesRelativePtBBdn*/  bool     Common_jet_p4_jesRelativePtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativePtEC1up*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativePtEC1up_;
/*        Common_jet_p4_jesRelativePtEC1up*/  TBranch *Common_jet_p4_jesRelativePtEC1up_branch;
/*        Common_jet_p4_jesRelativePtEC1up*/  bool     Common_jet_p4_jesRelativePtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativePtEC1dn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativePtEC1dn_;
/*        Common_jet_p4_jesRelativePtEC1dn*/  TBranch *Common_jet_p4_jesRelativePtEC1dn_branch;
/*        Common_jet_p4_jesRelativePtEC1dn*/  bool     Common_jet_p4_jesRelativePtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativePtEC2up*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativePtEC2up_;
/*        Common_jet_p4_jesRelativePtEC2up*/  TBranch *Common_jet_p4_jesRelativePtEC2up_branch;
/*        Common_jet_p4_jesRelativePtEC2up*/  bool     Common_jet_p4_jesRelativePtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativePtEC2dn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativePtEC2dn_;
/*        Common_jet_p4_jesRelativePtEC2dn*/  TBranch *Common_jet_p4_jesRelativePtEC2dn_branch;
/*        Common_jet_p4_jesRelativePtEC2dn*/  bool     Common_jet_p4_jesRelativePtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesRelativePtHFup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativePtHFup_;
/*         Common_jet_p4_jesRelativePtHFup*/  TBranch *Common_jet_p4_jesRelativePtHFup_branch;
/*         Common_jet_p4_jesRelativePtHFup*/  bool     Common_jet_p4_jesRelativePtHFup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesRelativePtHFdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativePtHFdn_;
/*         Common_jet_p4_jesRelativePtHFdn*/  TBranch *Common_jet_p4_jesRelativePtHFdn_branch;
/*         Common_jet_p4_jesRelativePtHFdn*/  bool     Common_jet_p4_jesRelativePtHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesRelativeBalup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeBalup_;
/*          Common_jet_p4_jesRelativeBalup*/  TBranch *Common_jet_p4_jesRelativeBalup_branch;
/*          Common_jet_p4_jesRelativeBalup*/  bool     Common_jet_p4_jesRelativeBalup_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesRelativeBaldn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeBaldn_;
/*          Common_jet_p4_jesRelativeBaldn*/  TBranch *Common_jet_p4_jesRelativeBaldn_branch;
/*          Common_jet_p4_jesRelativeBaldn*/  bool     Common_jet_p4_jesRelativeBaldn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeSampleup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeSampleup_;
/*       Common_jet_p4_jesRelativeSampleup*/  TBranch *Common_jet_p4_jesRelativeSampleup_branch;
/*       Common_jet_p4_jesRelativeSampleup*/  bool     Common_jet_p4_jesRelativeSampleup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeSampledn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeSampledn_;
/*       Common_jet_p4_jesRelativeSampledn*/  TBranch *Common_jet_p4_jesRelativeSampledn_branch;
/*       Common_jet_p4_jesRelativeSampledn*/  bool     Common_jet_p4_jesRelativeSampledn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesRelativeFSRup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeFSRup_;
/*          Common_jet_p4_jesRelativeFSRup*/  TBranch *Common_jet_p4_jesRelativeFSRup_branch;
/*          Common_jet_p4_jesRelativeFSRup*/  bool     Common_jet_p4_jesRelativeFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesRelativeFSRdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeFSRdn_;
/*          Common_jet_p4_jesRelativeFSRdn*/  TBranch *Common_jet_p4_jesRelativeFSRdn_branch;
/*          Common_jet_p4_jesRelativeFSRdn*/  bool     Common_jet_p4_jesRelativeFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_jet_p4_jesRelativeStatFSRup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeStatFSRup_;
/*      Common_jet_p4_jesRelativeStatFSRup*/  TBranch *Common_jet_p4_jesRelativeStatFSRup_branch;
/*      Common_jet_p4_jesRelativeStatFSRup*/  bool     Common_jet_p4_jesRelativeStatFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_jet_p4_jesRelativeStatFSRdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeStatFSRdn_;
/*      Common_jet_p4_jesRelativeStatFSRdn*/  TBranch *Common_jet_p4_jesRelativeStatFSRdn_branch;
/*      Common_jet_p4_jesRelativeStatFSRdn*/  bool     Common_jet_p4_jesRelativeStatFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeStatECup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeStatECup_;
/*       Common_jet_p4_jesRelativeStatECup*/  TBranch *Common_jet_p4_jesRelativeStatECup_branch;
/*       Common_jet_p4_jesRelativeStatECup*/  bool     Common_jet_p4_jesRelativeStatECup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeStatECdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeStatECdn_;
/*       Common_jet_p4_jesRelativeStatECdn*/  TBranch *Common_jet_p4_jesRelativeStatECdn_branch;
/*       Common_jet_p4_jesRelativeStatECdn*/  bool     Common_jet_p4_jesRelativeStatECdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeStatHFup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeStatHFup_;
/*       Common_jet_p4_jesRelativeStatHFup*/  TBranch *Common_jet_p4_jesRelativeStatHFup_branch;
/*       Common_jet_p4_jesRelativeStatHFup*/  bool     Common_jet_p4_jesRelativeStatHFup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeStatHFdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesRelativeStatHFdn_;
/*       Common_jet_p4_jesRelativeStatHFdn*/  TBranch *Common_jet_p4_jesRelativeStatHFdn_branch;
/*       Common_jet_p4_jesRelativeStatHFdn*/  bool     Common_jet_p4_jesRelativeStatHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesPileUpDataMCup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesPileUpDataMCup_;
/*         Common_jet_p4_jesPileUpDataMCup*/  TBranch *Common_jet_p4_jesPileUpDataMCup_branch;
/*         Common_jet_p4_jesPileUpDataMCup*/  bool     Common_jet_p4_jesPileUpDataMCup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesPileUpDataMCdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesPileUpDataMCdn_;
/*         Common_jet_p4_jesPileUpDataMCdn*/  TBranch *Common_jet_p4_jesPileUpDataMCdn_branch;
/*         Common_jet_p4_jesPileUpDataMCdn*/  bool     Common_jet_p4_jesPileUpDataMCdn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtRefup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesPileUpPtRefup_;
/*          Common_jet_p4_jesPileUpPtRefup*/  TBranch *Common_jet_p4_jesPileUpPtRefup_branch;
/*          Common_jet_p4_jesPileUpPtRefup*/  bool     Common_jet_p4_jesPileUpPtRefup_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtRefdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesPileUpPtRefdn_;
/*          Common_jet_p4_jesPileUpPtRefdn*/  TBranch *Common_jet_p4_jesPileUpPtRefdn_branch;
/*          Common_jet_p4_jesPileUpPtRefdn*/  bool     Common_jet_p4_jesPileUpPtRefdn_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_jet_p4_jesPileUpPtBBup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesPileUpPtBBup_;
/*           Common_jet_p4_jesPileUpPtBBup*/  TBranch *Common_jet_p4_jesPileUpPtBBup_branch;
/*           Common_jet_p4_jesPileUpPtBBup*/  bool     Common_jet_p4_jesPileUpPtBBup_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_jet_p4_jesPileUpPtBBdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesPileUpPtBBdn_;
/*           Common_jet_p4_jesPileUpPtBBdn*/  TBranch *Common_jet_p4_jesPileUpPtBBdn_branch;
/*           Common_jet_p4_jesPileUpPtBBdn*/  bool     Common_jet_p4_jesPileUpPtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtEC1up*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesPileUpPtEC1up_;
/*          Common_jet_p4_jesPileUpPtEC1up*/  TBranch *Common_jet_p4_jesPileUpPtEC1up_branch;
/*          Common_jet_p4_jesPileUpPtEC1up*/  bool     Common_jet_p4_jesPileUpPtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtEC1dn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesPileUpPtEC1dn_;
/*          Common_jet_p4_jesPileUpPtEC1dn*/  TBranch *Common_jet_p4_jesPileUpPtEC1dn_branch;
/*          Common_jet_p4_jesPileUpPtEC1dn*/  bool     Common_jet_p4_jesPileUpPtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtEC2up*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesPileUpPtEC2up_;
/*          Common_jet_p4_jesPileUpPtEC2up*/  TBranch *Common_jet_p4_jesPileUpPtEC2up_branch;
/*          Common_jet_p4_jesPileUpPtEC2up*/  bool     Common_jet_p4_jesPileUpPtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtEC2dn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesPileUpPtEC2dn_;
/*          Common_jet_p4_jesPileUpPtEC2dn*/  TBranch *Common_jet_p4_jesPileUpPtEC2dn_branch;
/*          Common_jet_p4_jesPileUpPtEC2dn*/  bool     Common_jet_p4_jesPileUpPtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_jet_p4_jesPileUpPtHFup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesPileUpPtHFup_;
/*           Common_jet_p4_jesPileUpPtHFup*/  TBranch *Common_jet_p4_jesPileUpPtHFup_branch;
/*           Common_jet_p4_jesPileUpPtHFup*/  bool     Common_jet_p4_jesPileUpPtHFup_isLoaded;
//---------------------------------------------------------------------------------
/*           Common_jet_p4_jesPileUpPtHFdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesPileUpPtHFdn_;
/*           Common_jet_p4_jesPileUpPtHFdn*/  TBranch *Common_jet_p4_jesPileUpPtHFdn_branch;
/*           Common_jet_p4_jesPileUpPtHFdn*/  bool     Common_jet_p4_jesPileUpPtHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_jet_p4_jesup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesup_;
/*                     Common_jet_p4_jesup*/  TBranch *Common_jet_p4_jesup_branch;
/*                     Common_jet_p4_jesup*/  bool     Common_jet_p4_jesup_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_jet_p4_jesdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jesdn_;
/*                     Common_jet_p4_jesdn*/  TBranch *Common_jet_p4_jesdn_branch;
/*                     Common_jet_p4_jesdn*/  bool     Common_jet_p4_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_jet_p4_jerup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jerup_;
/*                     Common_jet_p4_jerup*/  TBranch *Common_jet_p4_jerup_branch;
/*                     Common_jet_p4_jerup*/  bool     Common_jet_p4_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*                     Common_jet_p4_jerdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_jet_p4_jerdn_;
/*                     Common_jet_p4_jerdn*/  TBranch *Common_jet_p4_jerdn_branch;
/*                     Common_jet_p4_jerdn*/  bool     Common_jet_p4_jerdn_isLoaded;
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
/*      Common_fatjet_p4_jesAbsoluteStatup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesAbsoluteStatup_;
/*      Common_fatjet_p4_jesAbsoluteStatup*/  TBranch *Common_fatjet_p4_jesAbsoluteStatup_branch;
/*      Common_fatjet_p4_jesAbsoluteStatup*/  bool     Common_fatjet_p4_jesAbsoluteStatup_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesdn*/  vector<float> *Common_fatjet_pt_jesdn_;
/*                  Common_fatjet_pt_jesdn*/  TBranch *Common_fatjet_pt_jesdn_branch;
/*                  Common_fatjet_pt_jesdn*/  bool     Common_fatjet_pt_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesAbsoluteStatdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesAbsoluteStatdn_;
/*      Common_fatjet_p4_jesAbsoluteStatdn*/  TBranch *Common_fatjet_p4_jesAbsoluteStatdn_branch;
/*      Common_fatjet_p4_jesAbsoluteStatdn*/  bool     Common_fatjet_p4_jesAbsoluteStatdn_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerup*/  vector<float> *Common_fatjet_pt_jerup_;
/*                  Common_fatjet_pt_jerup*/  TBranch *Common_fatjet_pt_jerup_branch;
/*                  Common_fatjet_pt_jerup*/  bool     Common_fatjet_pt_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesAbsoluteScaleup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesAbsoluteScaleup_;
/*     Common_fatjet_p4_jesAbsoluteScaleup*/  TBranch *Common_fatjet_p4_jesAbsoluteScaleup_branch;
/*     Common_fatjet_p4_jesAbsoluteScaleup*/  bool     Common_fatjet_p4_jesAbsoluteScaleup_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerdn*/  vector<float> *Common_fatjet_pt_jerdn_;
/*                  Common_fatjet_pt_jerdn*/  TBranch *Common_fatjet_pt_jerdn_branch;
/*                  Common_fatjet_pt_jerdn*/  bool     Common_fatjet_pt_jerdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesAbsoluteScaledn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesAbsoluteScaledn_;
/*     Common_fatjet_p4_jesAbsoluteScaledn*/  TBranch *Common_fatjet_p4_jesAbsoluteScaledn_branch;
/*     Common_fatjet_p4_jesAbsoluteScaledn*/  bool     Common_fatjet_p4_jesAbsoluteScaledn_isLoaded;
//---------------------------------------------------------------------------------
/*   Common_fatjet_p4_jesAbsoluteMPFBiasup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesAbsoluteMPFBiasup_;
/*   Common_fatjet_p4_jesAbsoluteMPFBiasup*/  TBranch *Common_fatjet_p4_jesAbsoluteMPFBiasup_branch;
/*   Common_fatjet_p4_jesAbsoluteMPFBiasup*/  bool     Common_fatjet_p4_jesAbsoluteMPFBiasup_isLoaded;
//---------------------------------------------------------------------------------
/*   Common_fatjet_p4_jesAbsoluteMPFBiasdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesAbsoluteMPFBiasdn_;
/*   Common_fatjet_p4_jesAbsoluteMPFBiasdn*/  TBranch *Common_fatjet_p4_jesAbsoluteMPFBiasdn_branch;
/*   Common_fatjet_p4_jesAbsoluteMPFBiasdn*/  bool     Common_fatjet_p4_jesAbsoluteMPFBiasdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesFragmentationup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesFragmentationup_;
/*     Common_fatjet_p4_jesFragmentationup*/  TBranch *Common_fatjet_p4_jesFragmentationup_branch;
/*     Common_fatjet_p4_jesFragmentationup*/  bool     Common_fatjet_p4_jesFragmentationup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesFragmentationdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesFragmentationdn_;
/*     Common_fatjet_p4_jesFragmentationdn*/  TBranch *Common_fatjet_p4_jesFragmentationdn_branch;
/*     Common_fatjet_p4_jesFragmentationdn*/  bool     Common_fatjet_p4_jesFragmentationdn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesSinglePionECALup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesSinglePionECALup_;
/*    Common_fatjet_p4_jesSinglePionECALup*/  TBranch *Common_fatjet_p4_jesSinglePionECALup_branch;
/*    Common_fatjet_p4_jesSinglePionECALup*/  bool     Common_fatjet_p4_jesSinglePionECALup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesSinglePionECALdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesSinglePionECALdn_;
/*    Common_fatjet_p4_jesSinglePionECALdn*/  TBranch *Common_fatjet_p4_jesSinglePionECALdn_branch;
/*    Common_fatjet_p4_jesSinglePionECALdn*/  bool     Common_fatjet_p4_jesSinglePionECALdn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesSinglePionHCALup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesSinglePionHCALup_;
/*    Common_fatjet_p4_jesSinglePionHCALup*/  TBranch *Common_fatjet_p4_jesSinglePionHCALup_branch;
/*    Common_fatjet_p4_jesSinglePionHCALup*/  bool     Common_fatjet_p4_jesSinglePionHCALup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesSinglePionHCALdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesSinglePionHCALdn_;
/*    Common_fatjet_p4_jesSinglePionHCALdn*/  TBranch *Common_fatjet_p4_jesSinglePionHCALdn_branch;
/*    Common_fatjet_p4_jesSinglePionHCALdn*/  bool     Common_fatjet_p4_jesSinglePionHCALdn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_fatjet_p4_jesFlavorQCDup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesFlavorQCDup_;
/*         Common_fatjet_p4_jesFlavorQCDup*/  TBranch *Common_fatjet_p4_jesFlavorQCDup_branch;
/*         Common_fatjet_p4_jesFlavorQCDup*/  bool     Common_fatjet_p4_jesFlavorQCDup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_fatjet_p4_jesFlavorQCDdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesFlavorQCDdn_;
/*         Common_fatjet_p4_jesFlavorQCDdn*/  TBranch *Common_fatjet_p4_jesFlavorQCDdn_branch;
/*         Common_fatjet_p4_jesFlavorQCDdn*/  bool     Common_fatjet_p4_jesFlavorQCDdn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_fatjet_p4_jesTimePtEtaup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesTimePtEtaup_;
/*         Common_fatjet_p4_jesTimePtEtaup*/  TBranch *Common_fatjet_p4_jesTimePtEtaup_branch;
/*         Common_fatjet_p4_jesTimePtEtaup*/  bool     Common_fatjet_p4_jesTimePtEtaup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_fatjet_p4_jesTimePtEtadn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesTimePtEtadn_;
/*         Common_fatjet_p4_jesTimePtEtadn*/  TBranch *Common_fatjet_p4_jesTimePtEtadn_branch;
/*         Common_fatjet_p4_jesTimePtEtadn*/  bool     Common_fatjet_p4_jesTimePtEtadn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeJEREC1up*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeJEREC1up_;
/*    Common_fatjet_p4_jesRelativeJEREC1up*/  TBranch *Common_fatjet_p4_jesRelativeJEREC1up_branch;
/*    Common_fatjet_p4_jesRelativeJEREC1up*/  bool     Common_fatjet_p4_jesRelativeJEREC1up_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeJEREC1dn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeJEREC1dn_;
/*    Common_fatjet_p4_jesRelativeJEREC1dn*/  TBranch *Common_fatjet_p4_jesRelativeJEREC1dn_branch;
/*    Common_fatjet_p4_jesRelativeJEREC1dn*/  bool     Common_fatjet_p4_jesRelativeJEREC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeJEREC2up*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeJEREC2up_;
/*    Common_fatjet_p4_jesRelativeJEREC2up*/  TBranch *Common_fatjet_p4_jesRelativeJEREC2up_branch;
/*    Common_fatjet_p4_jesRelativeJEREC2up*/  bool     Common_fatjet_p4_jesRelativeJEREC2up_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeJEREC2dn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeJEREC2dn_;
/*    Common_fatjet_p4_jesRelativeJEREC2dn*/  TBranch *Common_fatjet_p4_jesRelativeJEREC2dn_branch;
/*    Common_fatjet_p4_jesRelativeJEREC2dn*/  bool     Common_fatjet_p4_jesRelativeJEREC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativeJERHFup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeJERHFup_;
/*     Common_fatjet_p4_jesRelativeJERHFup*/  TBranch *Common_fatjet_p4_jesRelativeJERHFup_branch;
/*     Common_fatjet_p4_jesRelativeJERHFup*/  bool     Common_fatjet_p4_jesRelativeJERHFup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativeJERHFdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeJERHFdn_;
/*     Common_fatjet_p4_jesRelativeJERHFdn*/  TBranch *Common_fatjet_p4_jesRelativeJERHFdn_branch;
/*     Common_fatjet_p4_jesRelativeJERHFdn*/  bool     Common_fatjet_p4_jesRelativeJERHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesRelativePtBBup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativePtBBup_;
/*      Common_fatjet_p4_jesRelativePtBBup*/  TBranch *Common_fatjet_p4_jesRelativePtBBup_branch;
/*      Common_fatjet_p4_jesRelativePtBBup*/  bool     Common_fatjet_p4_jesRelativePtBBup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesRelativePtBBdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativePtBBdn_;
/*      Common_fatjet_p4_jesRelativePtBBdn*/  TBranch *Common_fatjet_p4_jesRelativePtBBdn_branch;
/*      Common_fatjet_p4_jesRelativePtBBdn*/  bool     Common_fatjet_p4_jesRelativePtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativePtEC1up*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativePtEC1up_;
/*     Common_fatjet_p4_jesRelativePtEC1up*/  TBranch *Common_fatjet_p4_jesRelativePtEC1up_branch;
/*     Common_fatjet_p4_jesRelativePtEC1up*/  bool     Common_fatjet_p4_jesRelativePtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativePtEC1dn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativePtEC1dn_;
/*     Common_fatjet_p4_jesRelativePtEC1dn*/  TBranch *Common_fatjet_p4_jesRelativePtEC1dn_branch;
/*     Common_fatjet_p4_jesRelativePtEC1dn*/  bool     Common_fatjet_p4_jesRelativePtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativePtEC2up*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativePtEC2up_;
/*     Common_fatjet_p4_jesRelativePtEC2up*/  TBranch *Common_fatjet_p4_jesRelativePtEC2up_branch;
/*     Common_fatjet_p4_jesRelativePtEC2up*/  bool     Common_fatjet_p4_jesRelativePtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativePtEC2dn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativePtEC2dn_;
/*     Common_fatjet_p4_jesRelativePtEC2dn*/  TBranch *Common_fatjet_p4_jesRelativePtEC2dn_branch;
/*     Common_fatjet_p4_jesRelativePtEC2dn*/  bool     Common_fatjet_p4_jesRelativePtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesRelativePtHFup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativePtHFup_;
/*      Common_fatjet_p4_jesRelativePtHFup*/  TBranch *Common_fatjet_p4_jesRelativePtHFup_branch;
/*      Common_fatjet_p4_jesRelativePtHFup*/  bool     Common_fatjet_p4_jesRelativePtHFup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesRelativePtHFdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativePtHFdn_;
/*      Common_fatjet_p4_jesRelativePtHFdn*/  TBranch *Common_fatjet_p4_jesRelativePtHFdn_branch;
/*      Common_fatjet_p4_jesRelativePtHFdn*/  bool     Common_fatjet_p4_jesRelativePtHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesRelativeBalup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeBalup_;
/*       Common_fatjet_p4_jesRelativeBalup*/  TBranch *Common_fatjet_p4_jesRelativeBalup_branch;
/*       Common_fatjet_p4_jesRelativeBalup*/  bool     Common_fatjet_p4_jesRelativeBalup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesRelativeBaldn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeBaldn_;
/*       Common_fatjet_p4_jesRelativeBaldn*/  TBranch *Common_fatjet_p4_jesRelativeBaldn_branch;
/*       Common_fatjet_p4_jesRelativeBaldn*/  bool     Common_fatjet_p4_jesRelativeBaldn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeSampleup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeSampleup_;
/*    Common_fatjet_p4_jesRelativeSampleup*/  TBranch *Common_fatjet_p4_jesRelativeSampleup_branch;
/*    Common_fatjet_p4_jesRelativeSampleup*/  bool     Common_fatjet_p4_jesRelativeSampleup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeSampledn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeSampledn_;
/*    Common_fatjet_p4_jesRelativeSampledn*/  TBranch *Common_fatjet_p4_jesRelativeSampledn_branch;
/*    Common_fatjet_p4_jesRelativeSampledn*/  bool     Common_fatjet_p4_jesRelativeSampledn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesRelativeFSRup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeFSRup_;
/*       Common_fatjet_p4_jesRelativeFSRup*/  TBranch *Common_fatjet_p4_jesRelativeFSRup_branch;
/*       Common_fatjet_p4_jesRelativeFSRup*/  bool     Common_fatjet_p4_jesRelativeFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesRelativeFSRdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeFSRdn_;
/*       Common_fatjet_p4_jesRelativeFSRdn*/  TBranch *Common_fatjet_p4_jesRelativeFSRdn_branch;
/*       Common_fatjet_p4_jesRelativeFSRdn*/  bool     Common_fatjet_p4_jesRelativeFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*   Common_fatjet_p4_jesRelativeStatFSRup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeStatFSRup_;
/*   Common_fatjet_p4_jesRelativeStatFSRup*/  TBranch *Common_fatjet_p4_jesRelativeStatFSRup_branch;
/*   Common_fatjet_p4_jesRelativeStatFSRup*/  bool     Common_fatjet_p4_jesRelativeStatFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*   Common_fatjet_p4_jesRelativeStatFSRdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeStatFSRdn_;
/*   Common_fatjet_p4_jesRelativeStatFSRdn*/  TBranch *Common_fatjet_p4_jesRelativeStatFSRdn_branch;
/*   Common_fatjet_p4_jesRelativeStatFSRdn*/  bool     Common_fatjet_p4_jesRelativeStatFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeStatECup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeStatECup_;
/*    Common_fatjet_p4_jesRelativeStatECup*/  TBranch *Common_fatjet_p4_jesRelativeStatECup_branch;
/*    Common_fatjet_p4_jesRelativeStatECup*/  bool     Common_fatjet_p4_jesRelativeStatECup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeStatECdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeStatECdn_;
/*    Common_fatjet_p4_jesRelativeStatECdn*/  TBranch *Common_fatjet_p4_jesRelativeStatECdn_branch;
/*    Common_fatjet_p4_jesRelativeStatECdn*/  bool     Common_fatjet_p4_jesRelativeStatECdn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeStatHFup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeStatHFup_;
/*    Common_fatjet_p4_jesRelativeStatHFup*/  TBranch *Common_fatjet_p4_jesRelativeStatHFup_branch;
/*    Common_fatjet_p4_jesRelativeStatHFup*/  bool     Common_fatjet_p4_jesRelativeStatHFup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeStatHFdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesRelativeStatHFdn_;
/*    Common_fatjet_p4_jesRelativeStatHFdn*/  TBranch *Common_fatjet_p4_jesRelativeStatHFdn_branch;
/*    Common_fatjet_p4_jesRelativeStatHFdn*/  bool     Common_fatjet_p4_jesRelativeStatHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesPileUpDataMCup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesPileUpDataMCup_;
/*      Common_fatjet_p4_jesPileUpDataMCup*/  TBranch *Common_fatjet_p4_jesPileUpDataMCup_branch;
/*      Common_fatjet_p4_jesPileUpDataMCup*/  bool     Common_fatjet_p4_jesPileUpDataMCup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesPileUpDataMCdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesPileUpDataMCdn_;
/*      Common_fatjet_p4_jesPileUpDataMCdn*/  TBranch *Common_fatjet_p4_jesPileUpDataMCdn_branch;
/*      Common_fatjet_p4_jesPileUpDataMCdn*/  bool     Common_fatjet_p4_jesPileUpDataMCdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtRefup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesPileUpPtRefup_;
/*       Common_fatjet_p4_jesPileUpPtRefup*/  TBranch *Common_fatjet_p4_jesPileUpPtRefup_branch;
/*       Common_fatjet_p4_jesPileUpPtRefup*/  bool     Common_fatjet_p4_jesPileUpPtRefup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtRefdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesPileUpPtRefdn_;
/*       Common_fatjet_p4_jesPileUpPtRefdn*/  TBranch *Common_fatjet_p4_jesPileUpPtRefdn_branch;
/*       Common_fatjet_p4_jesPileUpPtRefdn*/  bool     Common_fatjet_p4_jesPileUpPtRefdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_fatjet_p4_jesPileUpPtBBup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesPileUpPtBBup_;
/*        Common_fatjet_p4_jesPileUpPtBBup*/  TBranch *Common_fatjet_p4_jesPileUpPtBBup_branch;
/*        Common_fatjet_p4_jesPileUpPtBBup*/  bool     Common_fatjet_p4_jesPileUpPtBBup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_fatjet_p4_jesPileUpPtBBdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesPileUpPtBBdn_;
/*        Common_fatjet_p4_jesPileUpPtBBdn*/  TBranch *Common_fatjet_p4_jesPileUpPtBBdn_branch;
/*        Common_fatjet_p4_jesPileUpPtBBdn*/  bool     Common_fatjet_p4_jesPileUpPtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtEC1up*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesPileUpPtEC1up_;
/*       Common_fatjet_p4_jesPileUpPtEC1up*/  TBranch *Common_fatjet_p4_jesPileUpPtEC1up_branch;
/*       Common_fatjet_p4_jesPileUpPtEC1up*/  bool     Common_fatjet_p4_jesPileUpPtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtEC1dn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesPileUpPtEC1dn_;
/*       Common_fatjet_p4_jesPileUpPtEC1dn*/  TBranch *Common_fatjet_p4_jesPileUpPtEC1dn_branch;
/*       Common_fatjet_p4_jesPileUpPtEC1dn*/  bool     Common_fatjet_p4_jesPileUpPtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtEC2up*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesPileUpPtEC2up_;
/*       Common_fatjet_p4_jesPileUpPtEC2up*/  TBranch *Common_fatjet_p4_jesPileUpPtEC2up_branch;
/*       Common_fatjet_p4_jesPileUpPtEC2up*/  bool     Common_fatjet_p4_jesPileUpPtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtEC2dn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesPileUpPtEC2dn_;
/*       Common_fatjet_p4_jesPileUpPtEC2dn*/  TBranch *Common_fatjet_p4_jesPileUpPtEC2dn_branch;
/*       Common_fatjet_p4_jesPileUpPtEC2dn*/  bool     Common_fatjet_p4_jesPileUpPtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_fatjet_p4_jesPileUpPtHFup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesPileUpPtHFup_;
/*        Common_fatjet_p4_jesPileUpPtHFup*/  TBranch *Common_fatjet_p4_jesPileUpPtHFup_branch;
/*        Common_fatjet_p4_jesPileUpPtHFup*/  bool     Common_fatjet_p4_jesPileUpPtHFup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_fatjet_p4_jesPileUpPtHFdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesPileUpPtHFdn_;
/*        Common_fatjet_p4_jesPileUpPtHFdn*/  TBranch *Common_fatjet_p4_jesPileUpPtHFdn_branch;
/*        Common_fatjet_p4_jesPileUpPtHFdn*/  bool     Common_fatjet_p4_jesPileUpPtHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_p4_jesup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesup_;
/*                  Common_fatjet_p4_jesup*/  TBranch *Common_fatjet_p4_jesup_branch;
/*                  Common_fatjet_p4_jesup*/  bool     Common_fatjet_p4_jesup_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_p4_jesdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jesdn_;
/*                  Common_fatjet_p4_jesdn*/  TBranch *Common_fatjet_p4_jesdn_branch;
/*                  Common_fatjet_p4_jesdn*/  bool     Common_fatjet_p4_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_p4_jerup*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jerup_;
/*                  Common_fatjet_p4_jerup*/  TBranch *Common_fatjet_p4_jerup_branch;
/*                  Common_fatjet_p4_jerup*/  bool     Common_fatjet_p4_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_p4_jerdn*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *Common_fatjet_p4_jerdn_;
/*                  Common_fatjet_p4_jerdn*/  TBranch *Common_fatjet_p4_jerdn_branch;
/*                  Common_fatjet_p4_jerdn*/  bool     Common_fatjet_p4_jerdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteStatup*/  vector<float> *Common_fatjet_msoftdrop_jesAbsoluteStatup_;
/*Common_fatjet_msoftdrop_jesAbsoluteStatup*/  TBranch *Common_fatjet_msoftdrop_jesAbsoluteStatup_branch;
/*Common_fatjet_msoftdrop_jesAbsoluteStatup*/  bool     Common_fatjet_msoftdrop_jesAbsoluteStatup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteStatdn*/  vector<float> *Common_fatjet_msoftdrop_jesAbsoluteStatdn_;
/*Common_fatjet_msoftdrop_jesAbsoluteStatdn*/  TBranch *Common_fatjet_msoftdrop_jesAbsoluteStatdn_branch;
/*Common_fatjet_msoftdrop_jesAbsoluteStatdn*/  bool     Common_fatjet_msoftdrop_jesAbsoluteStatdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteScaleup*/  vector<float> *Common_fatjet_msoftdrop_jesAbsoluteScaleup_;
/*Common_fatjet_msoftdrop_jesAbsoluteScaleup*/  TBranch *Common_fatjet_msoftdrop_jesAbsoluteScaleup_branch;
/*Common_fatjet_msoftdrop_jesAbsoluteScaleup*/  bool     Common_fatjet_msoftdrop_jesAbsoluteScaleup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteScaledn*/  vector<float> *Common_fatjet_msoftdrop_jesAbsoluteScaledn_;
/*Common_fatjet_msoftdrop_jesAbsoluteScaledn*/  TBranch *Common_fatjet_msoftdrop_jesAbsoluteScaledn_branch;
/*Common_fatjet_msoftdrop_jesAbsoluteScaledn*/  bool     Common_fatjet_msoftdrop_jesAbsoluteScaledn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteMPFBiasup*/  vector<float> *Common_fatjet_msoftdrop_jesAbsoluteMPFBiasup_;
/*Common_fatjet_msoftdrop_jesAbsoluteMPFBiasup*/  TBranch *Common_fatjet_msoftdrop_jesAbsoluteMPFBiasup_branch;
/*Common_fatjet_msoftdrop_jesAbsoluteMPFBiasup*/  bool     Common_fatjet_msoftdrop_jesAbsoluteMPFBiasup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteMPFBiasdn*/  vector<float> *Common_fatjet_msoftdrop_jesAbsoluteMPFBiasdn_;
/*Common_fatjet_msoftdrop_jesAbsoluteMPFBiasdn*/  TBranch *Common_fatjet_msoftdrop_jesAbsoluteMPFBiasdn_branch;
/*Common_fatjet_msoftdrop_jesAbsoluteMPFBiasdn*/  bool     Common_fatjet_msoftdrop_jesAbsoluteMPFBiasdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesFragmentationup*/  vector<float> *Common_fatjet_msoftdrop_jesFragmentationup_;
/*Common_fatjet_msoftdrop_jesFragmentationup*/  TBranch *Common_fatjet_msoftdrop_jesFragmentationup_branch;
/*Common_fatjet_msoftdrop_jesFragmentationup*/  bool     Common_fatjet_msoftdrop_jesFragmentationup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesFragmentationdn*/  vector<float> *Common_fatjet_msoftdrop_jesFragmentationdn_;
/*Common_fatjet_msoftdrop_jesFragmentationdn*/  TBranch *Common_fatjet_msoftdrop_jesFragmentationdn_branch;
/*Common_fatjet_msoftdrop_jesFragmentationdn*/  bool     Common_fatjet_msoftdrop_jesFragmentationdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesSinglePionECALup*/  vector<float> *Common_fatjet_msoftdrop_jesSinglePionECALup_;
/*Common_fatjet_msoftdrop_jesSinglePionECALup*/  TBranch *Common_fatjet_msoftdrop_jesSinglePionECALup_branch;
/*Common_fatjet_msoftdrop_jesSinglePionECALup*/  bool     Common_fatjet_msoftdrop_jesSinglePionECALup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesSinglePionECALdn*/  vector<float> *Common_fatjet_msoftdrop_jesSinglePionECALdn_;
/*Common_fatjet_msoftdrop_jesSinglePionECALdn*/  TBranch *Common_fatjet_msoftdrop_jesSinglePionECALdn_branch;
/*Common_fatjet_msoftdrop_jesSinglePionECALdn*/  bool     Common_fatjet_msoftdrop_jesSinglePionECALdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesSinglePionHCALup*/  vector<float> *Common_fatjet_msoftdrop_jesSinglePionHCALup_;
/*Common_fatjet_msoftdrop_jesSinglePionHCALup*/  TBranch *Common_fatjet_msoftdrop_jesSinglePionHCALup_branch;
/*Common_fatjet_msoftdrop_jesSinglePionHCALup*/  bool     Common_fatjet_msoftdrop_jesSinglePionHCALup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesSinglePionHCALdn*/  vector<float> *Common_fatjet_msoftdrop_jesSinglePionHCALdn_;
/*Common_fatjet_msoftdrop_jesSinglePionHCALdn*/  TBranch *Common_fatjet_msoftdrop_jesSinglePionHCALdn_branch;
/*Common_fatjet_msoftdrop_jesSinglePionHCALdn*/  bool     Common_fatjet_msoftdrop_jesSinglePionHCALdn_isLoaded;
//---------------------------------------------------------------------------------
/*  Common_fatjet_msoftdrop_jesFlavorQCDup*/  vector<float> *Common_fatjet_msoftdrop_jesFlavorQCDup_;
/*  Common_fatjet_msoftdrop_jesFlavorQCDup*/  TBranch *Common_fatjet_msoftdrop_jesFlavorQCDup_branch;
/*  Common_fatjet_msoftdrop_jesFlavorQCDup*/  bool     Common_fatjet_msoftdrop_jesFlavorQCDup_isLoaded;
//---------------------------------------------------------------------------------
/*  Common_fatjet_msoftdrop_jesFlavorQCDdn*/  vector<float> *Common_fatjet_msoftdrop_jesFlavorQCDdn_;
/*  Common_fatjet_msoftdrop_jesFlavorQCDdn*/  TBranch *Common_fatjet_msoftdrop_jesFlavorQCDdn_branch;
/*  Common_fatjet_msoftdrop_jesFlavorQCDdn*/  bool     Common_fatjet_msoftdrop_jesFlavorQCDdn_isLoaded;
//---------------------------------------------------------------------------------
/*  Common_fatjet_msoftdrop_jesTimePtEtaup*/  vector<float> *Common_fatjet_msoftdrop_jesTimePtEtaup_;
/*  Common_fatjet_msoftdrop_jesTimePtEtaup*/  TBranch *Common_fatjet_msoftdrop_jesTimePtEtaup_branch;
/*  Common_fatjet_msoftdrop_jesTimePtEtaup*/  bool     Common_fatjet_msoftdrop_jesTimePtEtaup_isLoaded;
//---------------------------------------------------------------------------------
/*  Common_fatjet_msoftdrop_jesTimePtEtadn*/  vector<float> *Common_fatjet_msoftdrop_jesTimePtEtadn_;
/*  Common_fatjet_msoftdrop_jesTimePtEtadn*/  TBranch *Common_fatjet_msoftdrop_jesTimePtEtadn_branch;
/*  Common_fatjet_msoftdrop_jesTimePtEtadn*/  bool     Common_fatjet_msoftdrop_jesTimePtEtadn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJEREC1up*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeJEREC1up_;
/*Common_fatjet_msoftdrop_jesRelativeJEREC1up*/  TBranch *Common_fatjet_msoftdrop_jesRelativeJEREC1up_branch;
/*Common_fatjet_msoftdrop_jesRelativeJEREC1up*/  bool     Common_fatjet_msoftdrop_jesRelativeJEREC1up_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJEREC1dn*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeJEREC1dn_;
/*Common_fatjet_msoftdrop_jesRelativeJEREC1dn*/  TBranch *Common_fatjet_msoftdrop_jesRelativeJEREC1dn_branch;
/*Common_fatjet_msoftdrop_jesRelativeJEREC1dn*/  bool     Common_fatjet_msoftdrop_jesRelativeJEREC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJEREC2up*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeJEREC2up_;
/*Common_fatjet_msoftdrop_jesRelativeJEREC2up*/  TBranch *Common_fatjet_msoftdrop_jesRelativeJEREC2up_branch;
/*Common_fatjet_msoftdrop_jesRelativeJEREC2up*/  bool     Common_fatjet_msoftdrop_jesRelativeJEREC2up_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJEREC2dn*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeJEREC2dn_;
/*Common_fatjet_msoftdrop_jesRelativeJEREC2dn*/  TBranch *Common_fatjet_msoftdrop_jesRelativeJEREC2dn_branch;
/*Common_fatjet_msoftdrop_jesRelativeJEREC2dn*/  bool     Common_fatjet_msoftdrop_jesRelativeJEREC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJERHFup*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeJERHFup_;
/*Common_fatjet_msoftdrop_jesRelativeJERHFup*/  TBranch *Common_fatjet_msoftdrop_jesRelativeJERHFup_branch;
/*Common_fatjet_msoftdrop_jesRelativeJERHFup*/  bool     Common_fatjet_msoftdrop_jesRelativeJERHFup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJERHFdn*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeJERHFdn_;
/*Common_fatjet_msoftdrop_jesRelativeJERHFdn*/  TBranch *Common_fatjet_msoftdrop_jesRelativeJERHFdn_branch;
/*Common_fatjet_msoftdrop_jesRelativeJERHFdn*/  bool     Common_fatjet_msoftdrop_jesRelativeJERHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtBBup*/  vector<float> *Common_fatjet_msoftdrop_jesRelativePtBBup_;
/*Common_fatjet_msoftdrop_jesRelativePtBBup*/  TBranch *Common_fatjet_msoftdrop_jesRelativePtBBup_branch;
/*Common_fatjet_msoftdrop_jesRelativePtBBup*/  bool     Common_fatjet_msoftdrop_jesRelativePtBBup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtBBdn*/  vector<float> *Common_fatjet_msoftdrop_jesRelativePtBBdn_;
/*Common_fatjet_msoftdrop_jesRelativePtBBdn*/  TBranch *Common_fatjet_msoftdrop_jesRelativePtBBdn_branch;
/*Common_fatjet_msoftdrop_jesRelativePtBBdn*/  bool     Common_fatjet_msoftdrop_jesRelativePtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtEC1up*/  vector<float> *Common_fatjet_msoftdrop_jesRelativePtEC1up_;
/*Common_fatjet_msoftdrop_jesRelativePtEC1up*/  TBranch *Common_fatjet_msoftdrop_jesRelativePtEC1up_branch;
/*Common_fatjet_msoftdrop_jesRelativePtEC1up*/  bool     Common_fatjet_msoftdrop_jesRelativePtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtEC1dn*/  vector<float> *Common_fatjet_msoftdrop_jesRelativePtEC1dn_;
/*Common_fatjet_msoftdrop_jesRelativePtEC1dn*/  TBranch *Common_fatjet_msoftdrop_jesRelativePtEC1dn_branch;
/*Common_fatjet_msoftdrop_jesRelativePtEC1dn*/  bool     Common_fatjet_msoftdrop_jesRelativePtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtEC2up*/  vector<float> *Common_fatjet_msoftdrop_jesRelativePtEC2up_;
/*Common_fatjet_msoftdrop_jesRelativePtEC2up*/  TBranch *Common_fatjet_msoftdrop_jesRelativePtEC2up_branch;
/*Common_fatjet_msoftdrop_jesRelativePtEC2up*/  bool     Common_fatjet_msoftdrop_jesRelativePtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtEC2dn*/  vector<float> *Common_fatjet_msoftdrop_jesRelativePtEC2dn_;
/*Common_fatjet_msoftdrop_jesRelativePtEC2dn*/  TBranch *Common_fatjet_msoftdrop_jesRelativePtEC2dn_branch;
/*Common_fatjet_msoftdrop_jesRelativePtEC2dn*/  bool     Common_fatjet_msoftdrop_jesRelativePtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtHFup*/  vector<float> *Common_fatjet_msoftdrop_jesRelativePtHFup_;
/*Common_fatjet_msoftdrop_jesRelativePtHFup*/  TBranch *Common_fatjet_msoftdrop_jesRelativePtHFup_branch;
/*Common_fatjet_msoftdrop_jesRelativePtHFup*/  bool     Common_fatjet_msoftdrop_jesRelativePtHFup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtHFdn*/  vector<float> *Common_fatjet_msoftdrop_jesRelativePtHFdn_;
/*Common_fatjet_msoftdrop_jesRelativePtHFdn*/  TBranch *Common_fatjet_msoftdrop_jesRelativePtHFdn_branch;
/*Common_fatjet_msoftdrop_jesRelativePtHFdn*/  bool     Common_fatjet_msoftdrop_jesRelativePtHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeBalup*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeBalup_;
/*Common_fatjet_msoftdrop_jesRelativeBalup*/  TBranch *Common_fatjet_msoftdrop_jesRelativeBalup_branch;
/*Common_fatjet_msoftdrop_jesRelativeBalup*/  bool     Common_fatjet_msoftdrop_jesRelativeBalup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeBaldn*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeBaldn_;
/*Common_fatjet_msoftdrop_jesRelativeBaldn*/  TBranch *Common_fatjet_msoftdrop_jesRelativeBaldn_branch;
/*Common_fatjet_msoftdrop_jesRelativeBaldn*/  bool     Common_fatjet_msoftdrop_jesRelativeBaldn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeSampleup*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeSampleup_;
/*Common_fatjet_msoftdrop_jesRelativeSampleup*/  TBranch *Common_fatjet_msoftdrop_jesRelativeSampleup_branch;
/*Common_fatjet_msoftdrop_jesRelativeSampleup*/  bool     Common_fatjet_msoftdrop_jesRelativeSampleup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeSampledn*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeSampledn_;
/*Common_fatjet_msoftdrop_jesRelativeSampledn*/  TBranch *Common_fatjet_msoftdrop_jesRelativeSampledn_branch;
/*Common_fatjet_msoftdrop_jesRelativeSampledn*/  bool     Common_fatjet_msoftdrop_jesRelativeSampledn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeFSRup*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeFSRup_;
/*Common_fatjet_msoftdrop_jesRelativeFSRup*/  TBranch *Common_fatjet_msoftdrop_jesRelativeFSRup_branch;
/*Common_fatjet_msoftdrop_jesRelativeFSRup*/  bool     Common_fatjet_msoftdrop_jesRelativeFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeFSRdn*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeFSRdn_;
/*Common_fatjet_msoftdrop_jesRelativeFSRdn*/  TBranch *Common_fatjet_msoftdrop_jesRelativeFSRdn_branch;
/*Common_fatjet_msoftdrop_jesRelativeFSRdn*/  bool     Common_fatjet_msoftdrop_jesRelativeFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatFSRup*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeStatFSRup_;
/*Common_fatjet_msoftdrop_jesRelativeStatFSRup*/  TBranch *Common_fatjet_msoftdrop_jesRelativeStatFSRup_branch;
/*Common_fatjet_msoftdrop_jesRelativeStatFSRup*/  bool     Common_fatjet_msoftdrop_jesRelativeStatFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatFSRdn*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeStatFSRdn_;
/*Common_fatjet_msoftdrop_jesRelativeStatFSRdn*/  TBranch *Common_fatjet_msoftdrop_jesRelativeStatFSRdn_branch;
/*Common_fatjet_msoftdrop_jesRelativeStatFSRdn*/  bool     Common_fatjet_msoftdrop_jesRelativeStatFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatECup*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeStatECup_;
/*Common_fatjet_msoftdrop_jesRelativeStatECup*/  TBranch *Common_fatjet_msoftdrop_jesRelativeStatECup_branch;
/*Common_fatjet_msoftdrop_jesRelativeStatECup*/  bool     Common_fatjet_msoftdrop_jesRelativeStatECup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatECdn*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeStatECdn_;
/*Common_fatjet_msoftdrop_jesRelativeStatECdn*/  TBranch *Common_fatjet_msoftdrop_jesRelativeStatECdn_branch;
/*Common_fatjet_msoftdrop_jesRelativeStatECdn*/  bool     Common_fatjet_msoftdrop_jesRelativeStatECdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatHFup*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeStatHFup_;
/*Common_fatjet_msoftdrop_jesRelativeStatHFup*/  TBranch *Common_fatjet_msoftdrop_jesRelativeStatHFup_branch;
/*Common_fatjet_msoftdrop_jesRelativeStatHFup*/  bool     Common_fatjet_msoftdrop_jesRelativeStatHFup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatHFdn*/  vector<float> *Common_fatjet_msoftdrop_jesRelativeStatHFdn_;
/*Common_fatjet_msoftdrop_jesRelativeStatHFdn*/  TBranch *Common_fatjet_msoftdrop_jesRelativeStatHFdn_branch;
/*Common_fatjet_msoftdrop_jesRelativeStatHFdn*/  bool     Common_fatjet_msoftdrop_jesRelativeStatHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpDataMCup*/  vector<float> *Common_fatjet_msoftdrop_jesPileUpDataMCup_;
/*Common_fatjet_msoftdrop_jesPileUpDataMCup*/  TBranch *Common_fatjet_msoftdrop_jesPileUpDataMCup_branch;
/*Common_fatjet_msoftdrop_jesPileUpDataMCup*/  bool     Common_fatjet_msoftdrop_jesPileUpDataMCup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpDataMCdn*/  vector<float> *Common_fatjet_msoftdrop_jesPileUpDataMCdn_;
/*Common_fatjet_msoftdrop_jesPileUpDataMCdn*/  TBranch *Common_fatjet_msoftdrop_jesPileUpDataMCdn_branch;
/*Common_fatjet_msoftdrop_jesPileUpDataMCdn*/  bool     Common_fatjet_msoftdrop_jesPileUpDataMCdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtRefup*/  vector<float> *Common_fatjet_msoftdrop_jesPileUpPtRefup_;
/*Common_fatjet_msoftdrop_jesPileUpPtRefup*/  TBranch *Common_fatjet_msoftdrop_jesPileUpPtRefup_branch;
/*Common_fatjet_msoftdrop_jesPileUpPtRefup*/  bool     Common_fatjet_msoftdrop_jesPileUpPtRefup_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtRefdn*/  vector<float> *Common_fatjet_msoftdrop_jesPileUpPtRefdn_;
/*Common_fatjet_msoftdrop_jesPileUpPtRefdn*/  TBranch *Common_fatjet_msoftdrop_jesPileUpPtRefdn_branch;
/*Common_fatjet_msoftdrop_jesPileUpPtRefdn*/  bool     Common_fatjet_msoftdrop_jesPileUpPtRefdn_isLoaded;
//---------------------------------------------------------------------------------
/* Common_fatjet_msoftdrop_jesPileUpPtBBup*/  vector<float> *Common_fatjet_msoftdrop_jesPileUpPtBBup_;
/* Common_fatjet_msoftdrop_jesPileUpPtBBup*/  TBranch *Common_fatjet_msoftdrop_jesPileUpPtBBup_branch;
/* Common_fatjet_msoftdrop_jesPileUpPtBBup*/  bool     Common_fatjet_msoftdrop_jesPileUpPtBBup_isLoaded;
//---------------------------------------------------------------------------------
/* Common_fatjet_msoftdrop_jesPileUpPtBBdn*/  vector<float> *Common_fatjet_msoftdrop_jesPileUpPtBBdn_;
/* Common_fatjet_msoftdrop_jesPileUpPtBBdn*/  TBranch *Common_fatjet_msoftdrop_jesPileUpPtBBdn_branch;
/* Common_fatjet_msoftdrop_jesPileUpPtBBdn*/  bool     Common_fatjet_msoftdrop_jesPileUpPtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtEC1up*/  vector<float> *Common_fatjet_msoftdrop_jesPileUpPtEC1up_;
/*Common_fatjet_msoftdrop_jesPileUpPtEC1up*/  TBranch *Common_fatjet_msoftdrop_jesPileUpPtEC1up_branch;
/*Common_fatjet_msoftdrop_jesPileUpPtEC1up*/  bool     Common_fatjet_msoftdrop_jesPileUpPtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtEC1dn*/  vector<float> *Common_fatjet_msoftdrop_jesPileUpPtEC1dn_;
/*Common_fatjet_msoftdrop_jesPileUpPtEC1dn*/  TBranch *Common_fatjet_msoftdrop_jesPileUpPtEC1dn_branch;
/*Common_fatjet_msoftdrop_jesPileUpPtEC1dn*/  bool     Common_fatjet_msoftdrop_jesPileUpPtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtEC2up*/  vector<float> *Common_fatjet_msoftdrop_jesPileUpPtEC2up_;
/*Common_fatjet_msoftdrop_jesPileUpPtEC2up*/  TBranch *Common_fatjet_msoftdrop_jesPileUpPtEC2up_branch;
/*Common_fatjet_msoftdrop_jesPileUpPtEC2up*/  bool     Common_fatjet_msoftdrop_jesPileUpPtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtEC2dn*/  vector<float> *Common_fatjet_msoftdrop_jesPileUpPtEC2dn_;
/*Common_fatjet_msoftdrop_jesPileUpPtEC2dn*/  TBranch *Common_fatjet_msoftdrop_jesPileUpPtEC2dn_branch;
/*Common_fatjet_msoftdrop_jesPileUpPtEC2dn*/  bool     Common_fatjet_msoftdrop_jesPileUpPtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/* Common_fatjet_msoftdrop_jesPileUpPtHFup*/  vector<float> *Common_fatjet_msoftdrop_jesPileUpPtHFup_;
/* Common_fatjet_msoftdrop_jesPileUpPtHFup*/  TBranch *Common_fatjet_msoftdrop_jesPileUpPtHFup_branch;
/* Common_fatjet_msoftdrop_jesPileUpPtHFup*/  bool     Common_fatjet_msoftdrop_jesPileUpPtHFup_isLoaded;
//---------------------------------------------------------------------------------
/* Common_fatjet_msoftdrop_jesPileUpPtHFdn*/  vector<float> *Common_fatjet_msoftdrop_jesPileUpPtHFdn_;
/* Common_fatjet_msoftdrop_jesPileUpPtHFdn*/  TBranch *Common_fatjet_msoftdrop_jesPileUpPtHFdn_branch;
/* Common_fatjet_msoftdrop_jesPileUpPtHFdn*/  bool     Common_fatjet_msoftdrop_jesPileUpPtHFdn_isLoaded;
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
/*       Common_nb_loose_jesAbsoluteStatup*/  int      Common_nb_loose_jesAbsoluteStatup_;
/*       Common_nb_loose_jesAbsoluteStatup*/  TBranch *Common_nb_loose_jesAbsoluteStatup_branch;
/*       Common_nb_loose_jesAbsoluteStatup*/  bool     Common_nb_loose_jesAbsoluteStatup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesAbsoluteStatdn*/  int      Common_nb_loose_jesAbsoluteStatdn_;
/*       Common_nb_loose_jesAbsoluteStatdn*/  TBranch *Common_nb_loose_jesAbsoluteStatdn_branch;
/*       Common_nb_loose_jesAbsoluteStatdn*/  bool     Common_nb_loose_jesAbsoluteStatdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesAbsoluteScaleup*/  int      Common_nb_loose_jesAbsoluteScaleup_;
/*      Common_nb_loose_jesAbsoluteScaleup*/  TBranch *Common_nb_loose_jesAbsoluteScaleup_branch;
/*      Common_nb_loose_jesAbsoluteScaleup*/  bool     Common_nb_loose_jesAbsoluteScaleup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesAbsoluteScaledn*/  int      Common_nb_loose_jesAbsoluteScaledn_;
/*      Common_nb_loose_jesAbsoluteScaledn*/  TBranch *Common_nb_loose_jesAbsoluteScaledn_branch;
/*      Common_nb_loose_jesAbsoluteScaledn*/  bool     Common_nb_loose_jesAbsoluteScaledn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_loose_jesAbsoluteMPFBiasup*/  int      Common_nb_loose_jesAbsoluteMPFBiasup_;
/*    Common_nb_loose_jesAbsoluteMPFBiasup*/  TBranch *Common_nb_loose_jesAbsoluteMPFBiasup_branch;
/*    Common_nb_loose_jesAbsoluteMPFBiasup*/  bool     Common_nb_loose_jesAbsoluteMPFBiasup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_loose_jesAbsoluteMPFBiasdn*/  int      Common_nb_loose_jesAbsoluteMPFBiasdn_;
/*    Common_nb_loose_jesAbsoluteMPFBiasdn*/  TBranch *Common_nb_loose_jesAbsoluteMPFBiasdn_branch;
/*    Common_nb_loose_jesAbsoluteMPFBiasdn*/  bool     Common_nb_loose_jesAbsoluteMPFBiasdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesFragmentationup*/  int      Common_nb_loose_jesFragmentationup_;
/*      Common_nb_loose_jesFragmentationup*/  TBranch *Common_nb_loose_jesFragmentationup_branch;
/*      Common_nb_loose_jesFragmentationup*/  bool     Common_nb_loose_jesFragmentationup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesFragmentationdn*/  int      Common_nb_loose_jesFragmentationdn_;
/*      Common_nb_loose_jesFragmentationdn*/  TBranch *Common_nb_loose_jesFragmentationdn_branch;
/*      Common_nb_loose_jesFragmentationdn*/  bool     Common_nb_loose_jesFragmentationdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesSinglePionECALup*/  int      Common_nb_loose_jesSinglePionECALup_;
/*     Common_nb_loose_jesSinglePionECALup*/  TBranch *Common_nb_loose_jesSinglePionECALup_branch;
/*     Common_nb_loose_jesSinglePionECALup*/  bool     Common_nb_loose_jesSinglePionECALup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesSinglePionECALdn*/  int      Common_nb_loose_jesSinglePionECALdn_;
/*     Common_nb_loose_jesSinglePionECALdn*/  TBranch *Common_nb_loose_jesSinglePionECALdn_branch;
/*     Common_nb_loose_jesSinglePionECALdn*/  bool     Common_nb_loose_jesSinglePionECALdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesSinglePionHCALup*/  int      Common_nb_loose_jesSinglePionHCALup_;
/*     Common_nb_loose_jesSinglePionHCALup*/  TBranch *Common_nb_loose_jesSinglePionHCALup_branch;
/*     Common_nb_loose_jesSinglePionHCALup*/  bool     Common_nb_loose_jesSinglePionHCALup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesSinglePionHCALdn*/  int      Common_nb_loose_jesSinglePionHCALdn_;
/*     Common_nb_loose_jesSinglePionHCALdn*/  TBranch *Common_nb_loose_jesSinglePionHCALdn_branch;
/*     Common_nb_loose_jesSinglePionHCALdn*/  bool     Common_nb_loose_jesSinglePionHCALdn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_nb_loose_jesFlavorQCDup*/  int      Common_nb_loose_jesFlavorQCDup_;
/*          Common_nb_loose_jesFlavorQCDup*/  TBranch *Common_nb_loose_jesFlavorQCDup_branch;
/*          Common_nb_loose_jesFlavorQCDup*/  bool     Common_nb_loose_jesFlavorQCDup_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_nb_loose_jesFlavorQCDdn*/  int      Common_nb_loose_jesFlavorQCDdn_;
/*          Common_nb_loose_jesFlavorQCDdn*/  TBranch *Common_nb_loose_jesFlavorQCDdn_branch;
/*          Common_nb_loose_jesFlavorQCDdn*/  bool     Common_nb_loose_jesFlavorQCDdn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_nb_loose_jesTimePtEtaup*/  int      Common_nb_loose_jesTimePtEtaup_;
/*          Common_nb_loose_jesTimePtEtaup*/  TBranch *Common_nb_loose_jesTimePtEtaup_branch;
/*          Common_nb_loose_jesTimePtEtaup*/  bool     Common_nb_loose_jesTimePtEtaup_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_nb_loose_jesTimePtEtadn*/  int      Common_nb_loose_jesTimePtEtadn_;
/*          Common_nb_loose_jesTimePtEtadn*/  TBranch *Common_nb_loose_jesTimePtEtadn_branch;
/*          Common_nb_loose_jesTimePtEtadn*/  bool     Common_nb_loose_jesTimePtEtadn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeJEREC1up*/  int      Common_nb_loose_jesRelativeJEREC1up_;
/*     Common_nb_loose_jesRelativeJEREC1up*/  TBranch *Common_nb_loose_jesRelativeJEREC1up_branch;
/*     Common_nb_loose_jesRelativeJEREC1up*/  bool     Common_nb_loose_jesRelativeJEREC1up_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeJEREC1dn*/  int      Common_nb_loose_jesRelativeJEREC1dn_;
/*     Common_nb_loose_jesRelativeJEREC1dn*/  TBranch *Common_nb_loose_jesRelativeJEREC1dn_branch;
/*     Common_nb_loose_jesRelativeJEREC1dn*/  bool     Common_nb_loose_jesRelativeJEREC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeJEREC2up*/  int      Common_nb_loose_jesRelativeJEREC2up_;
/*     Common_nb_loose_jesRelativeJEREC2up*/  TBranch *Common_nb_loose_jesRelativeJEREC2up_branch;
/*     Common_nb_loose_jesRelativeJEREC2up*/  bool     Common_nb_loose_jesRelativeJEREC2up_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeJEREC2dn*/  int      Common_nb_loose_jesRelativeJEREC2dn_;
/*     Common_nb_loose_jesRelativeJEREC2dn*/  TBranch *Common_nb_loose_jesRelativeJEREC2dn_branch;
/*     Common_nb_loose_jesRelativeJEREC2dn*/  bool     Common_nb_loose_jesRelativeJEREC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativeJERHFup*/  int      Common_nb_loose_jesRelativeJERHFup_;
/*      Common_nb_loose_jesRelativeJERHFup*/  TBranch *Common_nb_loose_jesRelativeJERHFup_branch;
/*      Common_nb_loose_jesRelativeJERHFup*/  bool     Common_nb_loose_jesRelativeJERHFup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativeJERHFdn*/  int      Common_nb_loose_jesRelativeJERHFdn_;
/*      Common_nb_loose_jesRelativeJERHFdn*/  TBranch *Common_nb_loose_jesRelativeJERHFdn_branch;
/*      Common_nb_loose_jesRelativeJERHFdn*/  bool     Common_nb_loose_jesRelativeJERHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesRelativePtBBup*/  int      Common_nb_loose_jesRelativePtBBup_;
/*       Common_nb_loose_jesRelativePtBBup*/  TBranch *Common_nb_loose_jesRelativePtBBup_branch;
/*       Common_nb_loose_jesRelativePtBBup*/  bool     Common_nb_loose_jesRelativePtBBup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesRelativePtBBdn*/  int      Common_nb_loose_jesRelativePtBBdn_;
/*       Common_nb_loose_jesRelativePtBBdn*/  TBranch *Common_nb_loose_jesRelativePtBBdn_branch;
/*       Common_nb_loose_jesRelativePtBBdn*/  bool     Common_nb_loose_jesRelativePtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativePtEC1up*/  int      Common_nb_loose_jesRelativePtEC1up_;
/*      Common_nb_loose_jesRelativePtEC1up*/  TBranch *Common_nb_loose_jesRelativePtEC1up_branch;
/*      Common_nb_loose_jesRelativePtEC1up*/  bool     Common_nb_loose_jesRelativePtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativePtEC1dn*/  int      Common_nb_loose_jesRelativePtEC1dn_;
/*      Common_nb_loose_jesRelativePtEC1dn*/  TBranch *Common_nb_loose_jesRelativePtEC1dn_branch;
/*      Common_nb_loose_jesRelativePtEC1dn*/  bool     Common_nb_loose_jesRelativePtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativePtEC2up*/  int      Common_nb_loose_jesRelativePtEC2up_;
/*      Common_nb_loose_jesRelativePtEC2up*/  TBranch *Common_nb_loose_jesRelativePtEC2up_branch;
/*      Common_nb_loose_jesRelativePtEC2up*/  bool     Common_nb_loose_jesRelativePtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativePtEC2dn*/  int      Common_nb_loose_jesRelativePtEC2dn_;
/*      Common_nb_loose_jesRelativePtEC2dn*/  TBranch *Common_nb_loose_jesRelativePtEC2dn_branch;
/*      Common_nb_loose_jesRelativePtEC2dn*/  bool     Common_nb_loose_jesRelativePtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesRelativePtHFup*/  int      Common_nb_loose_jesRelativePtHFup_;
/*       Common_nb_loose_jesRelativePtHFup*/  TBranch *Common_nb_loose_jesRelativePtHFup_branch;
/*       Common_nb_loose_jesRelativePtHFup*/  bool     Common_nb_loose_jesRelativePtHFup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesRelativePtHFdn*/  int      Common_nb_loose_jesRelativePtHFdn_;
/*       Common_nb_loose_jesRelativePtHFdn*/  TBranch *Common_nb_loose_jesRelativePtHFdn_branch;
/*       Common_nb_loose_jesRelativePtHFdn*/  bool     Common_nb_loose_jesRelativePtHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesRelativeBalup*/  int      Common_nb_loose_jesRelativeBalup_;
/*        Common_nb_loose_jesRelativeBalup*/  TBranch *Common_nb_loose_jesRelativeBalup_branch;
/*        Common_nb_loose_jesRelativeBalup*/  bool     Common_nb_loose_jesRelativeBalup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesRelativeBaldn*/  int      Common_nb_loose_jesRelativeBaldn_;
/*        Common_nb_loose_jesRelativeBaldn*/  TBranch *Common_nb_loose_jesRelativeBaldn_branch;
/*        Common_nb_loose_jesRelativeBaldn*/  bool     Common_nb_loose_jesRelativeBaldn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeSampleup*/  int      Common_nb_loose_jesRelativeSampleup_;
/*     Common_nb_loose_jesRelativeSampleup*/  TBranch *Common_nb_loose_jesRelativeSampleup_branch;
/*     Common_nb_loose_jesRelativeSampleup*/  bool     Common_nb_loose_jesRelativeSampleup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeSampledn*/  int      Common_nb_loose_jesRelativeSampledn_;
/*     Common_nb_loose_jesRelativeSampledn*/  TBranch *Common_nb_loose_jesRelativeSampledn_branch;
/*     Common_nb_loose_jesRelativeSampledn*/  bool     Common_nb_loose_jesRelativeSampledn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesRelativeFSRup*/  int      Common_nb_loose_jesRelativeFSRup_;
/*        Common_nb_loose_jesRelativeFSRup*/  TBranch *Common_nb_loose_jesRelativeFSRup_branch;
/*        Common_nb_loose_jesRelativeFSRup*/  bool     Common_nb_loose_jesRelativeFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesRelativeFSRdn*/  int      Common_nb_loose_jesRelativeFSRdn_;
/*        Common_nb_loose_jesRelativeFSRdn*/  TBranch *Common_nb_loose_jesRelativeFSRdn_branch;
/*        Common_nb_loose_jesRelativeFSRdn*/  bool     Common_nb_loose_jesRelativeFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_loose_jesRelativeStatFSRup*/  int      Common_nb_loose_jesRelativeStatFSRup_;
/*    Common_nb_loose_jesRelativeStatFSRup*/  TBranch *Common_nb_loose_jesRelativeStatFSRup_branch;
/*    Common_nb_loose_jesRelativeStatFSRup*/  bool     Common_nb_loose_jesRelativeStatFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_loose_jesRelativeStatFSRdn*/  int      Common_nb_loose_jesRelativeStatFSRdn_;
/*    Common_nb_loose_jesRelativeStatFSRdn*/  TBranch *Common_nb_loose_jesRelativeStatFSRdn_branch;
/*    Common_nb_loose_jesRelativeStatFSRdn*/  bool     Common_nb_loose_jesRelativeStatFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeStatECup*/  int      Common_nb_loose_jesRelativeStatECup_;
/*     Common_nb_loose_jesRelativeStatECup*/  TBranch *Common_nb_loose_jesRelativeStatECup_branch;
/*     Common_nb_loose_jesRelativeStatECup*/  bool     Common_nb_loose_jesRelativeStatECup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeStatECdn*/  int      Common_nb_loose_jesRelativeStatECdn_;
/*     Common_nb_loose_jesRelativeStatECdn*/  TBranch *Common_nb_loose_jesRelativeStatECdn_branch;
/*     Common_nb_loose_jesRelativeStatECdn*/  bool     Common_nb_loose_jesRelativeStatECdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeStatHFup*/  int      Common_nb_loose_jesRelativeStatHFup_;
/*     Common_nb_loose_jesRelativeStatHFup*/  TBranch *Common_nb_loose_jesRelativeStatHFup_branch;
/*     Common_nb_loose_jesRelativeStatHFup*/  bool     Common_nb_loose_jesRelativeStatHFup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeStatHFdn*/  int      Common_nb_loose_jesRelativeStatHFdn_;
/*     Common_nb_loose_jesRelativeStatHFdn*/  TBranch *Common_nb_loose_jesRelativeStatHFdn_branch;
/*     Common_nb_loose_jesRelativeStatHFdn*/  bool     Common_nb_loose_jesRelativeStatHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesPileUpDataMCup*/  int      Common_nb_loose_jesPileUpDataMCup_;
/*       Common_nb_loose_jesPileUpDataMCup*/  TBranch *Common_nb_loose_jesPileUpDataMCup_branch;
/*       Common_nb_loose_jesPileUpDataMCup*/  bool     Common_nb_loose_jesPileUpDataMCup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesPileUpDataMCdn*/  int      Common_nb_loose_jesPileUpDataMCdn_;
/*       Common_nb_loose_jesPileUpDataMCdn*/  TBranch *Common_nb_loose_jesPileUpDataMCdn_branch;
/*       Common_nb_loose_jesPileUpDataMCdn*/  bool     Common_nb_loose_jesPileUpDataMCdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtRefup*/  int      Common_nb_loose_jesPileUpPtRefup_;
/*        Common_nb_loose_jesPileUpPtRefup*/  TBranch *Common_nb_loose_jesPileUpPtRefup_branch;
/*        Common_nb_loose_jesPileUpPtRefup*/  bool     Common_nb_loose_jesPileUpPtRefup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtRefdn*/  int      Common_nb_loose_jesPileUpPtRefdn_;
/*        Common_nb_loose_jesPileUpPtRefdn*/  TBranch *Common_nb_loose_jesPileUpPtRefdn_branch;
/*        Common_nb_loose_jesPileUpPtRefdn*/  bool     Common_nb_loose_jesPileUpPtRefdn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_nb_loose_jesPileUpPtBBup*/  int      Common_nb_loose_jesPileUpPtBBup_;
/*         Common_nb_loose_jesPileUpPtBBup*/  TBranch *Common_nb_loose_jesPileUpPtBBup_branch;
/*         Common_nb_loose_jesPileUpPtBBup*/  bool     Common_nb_loose_jesPileUpPtBBup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_nb_loose_jesPileUpPtBBdn*/  int      Common_nb_loose_jesPileUpPtBBdn_;
/*         Common_nb_loose_jesPileUpPtBBdn*/  TBranch *Common_nb_loose_jesPileUpPtBBdn_branch;
/*         Common_nb_loose_jesPileUpPtBBdn*/  bool     Common_nb_loose_jesPileUpPtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtEC1up*/  int      Common_nb_loose_jesPileUpPtEC1up_;
/*        Common_nb_loose_jesPileUpPtEC1up*/  TBranch *Common_nb_loose_jesPileUpPtEC1up_branch;
/*        Common_nb_loose_jesPileUpPtEC1up*/  bool     Common_nb_loose_jesPileUpPtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtEC1dn*/  int      Common_nb_loose_jesPileUpPtEC1dn_;
/*        Common_nb_loose_jesPileUpPtEC1dn*/  TBranch *Common_nb_loose_jesPileUpPtEC1dn_branch;
/*        Common_nb_loose_jesPileUpPtEC1dn*/  bool     Common_nb_loose_jesPileUpPtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtEC2up*/  int      Common_nb_loose_jesPileUpPtEC2up_;
/*        Common_nb_loose_jesPileUpPtEC2up*/  TBranch *Common_nb_loose_jesPileUpPtEC2up_branch;
/*        Common_nb_loose_jesPileUpPtEC2up*/  bool     Common_nb_loose_jesPileUpPtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtEC2dn*/  int      Common_nb_loose_jesPileUpPtEC2dn_;
/*        Common_nb_loose_jesPileUpPtEC2dn*/  TBranch *Common_nb_loose_jesPileUpPtEC2dn_branch;
/*        Common_nb_loose_jesPileUpPtEC2dn*/  bool     Common_nb_loose_jesPileUpPtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_nb_loose_jesPileUpPtHFup*/  int      Common_nb_loose_jesPileUpPtHFup_;
/*         Common_nb_loose_jesPileUpPtHFup*/  TBranch *Common_nb_loose_jesPileUpPtHFup_branch;
/*         Common_nb_loose_jesPileUpPtHFup*/  bool     Common_nb_loose_jesPileUpPtHFup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_nb_loose_jesPileUpPtHFdn*/  int      Common_nb_loose_jesPileUpPtHFdn_;
/*         Common_nb_loose_jesPileUpPtHFdn*/  TBranch *Common_nb_loose_jesPileUpPtHFdn_branch;
/*         Common_nb_loose_jesPileUpPtHFdn*/  bool     Common_nb_loose_jesPileUpPtHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_nb_loose_jesup*/  int      Common_nb_loose_jesup_;
/*                   Common_nb_loose_jesup*/  TBranch *Common_nb_loose_jesup_branch;
/*                   Common_nb_loose_jesup*/  bool     Common_nb_loose_jesup_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_nb_loose_jesdn*/  int      Common_nb_loose_jesdn_;
/*                   Common_nb_loose_jesdn*/  TBranch *Common_nb_loose_jesdn_branch;
/*                   Common_nb_loose_jesdn*/  bool     Common_nb_loose_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_nb_loose_jerup*/  int      Common_nb_loose_jerup_;
/*                   Common_nb_loose_jerup*/  TBranch *Common_nb_loose_jerup_branch;
/*                   Common_nb_loose_jerup*/  bool     Common_nb_loose_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_nb_loose_jerdn*/  int      Common_nb_loose_jerdn_;
/*                   Common_nb_loose_jerdn*/  TBranch *Common_nb_loose_jerdn_branch;
/*                   Common_nb_loose_jerdn*/  bool     Common_nb_loose_jerdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesAbsoluteStatup*/  int      Common_nb_medium_jesAbsoluteStatup_;
/*      Common_nb_medium_jesAbsoluteStatup*/  TBranch *Common_nb_medium_jesAbsoluteStatup_branch;
/*      Common_nb_medium_jesAbsoluteStatup*/  bool     Common_nb_medium_jesAbsoluteStatup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesAbsoluteStatdn*/  int      Common_nb_medium_jesAbsoluteStatdn_;
/*      Common_nb_medium_jesAbsoluteStatdn*/  TBranch *Common_nb_medium_jesAbsoluteStatdn_branch;
/*      Common_nb_medium_jesAbsoluteStatdn*/  bool     Common_nb_medium_jesAbsoluteStatdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesAbsoluteScaleup*/  int      Common_nb_medium_jesAbsoluteScaleup_;
/*     Common_nb_medium_jesAbsoluteScaleup*/  TBranch *Common_nb_medium_jesAbsoluteScaleup_branch;
/*     Common_nb_medium_jesAbsoluteScaleup*/  bool     Common_nb_medium_jesAbsoluteScaleup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesAbsoluteScaledn*/  int      Common_nb_medium_jesAbsoluteScaledn_;
/*     Common_nb_medium_jesAbsoluteScaledn*/  TBranch *Common_nb_medium_jesAbsoluteScaledn_branch;
/*     Common_nb_medium_jesAbsoluteScaledn*/  bool     Common_nb_medium_jesAbsoluteScaledn_isLoaded;
//---------------------------------------------------------------------------------
/*   Common_nb_medium_jesAbsoluteMPFBiasup*/  int      Common_nb_medium_jesAbsoluteMPFBiasup_;
/*   Common_nb_medium_jesAbsoluteMPFBiasup*/  TBranch *Common_nb_medium_jesAbsoluteMPFBiasup_branch;
/*   Common_nb_medium_jesAbsoluteMPFBiasup*/  bool     Common_nb_medium_jesAbsoluteMPFBiasup_isLoaded;
//---------------------------------------------------------------------------------
/*   Common_nb_medium_jesAbsoluteMPFBiasdn*/  int      Common_nb_medium_jesAbsoluteMPFBiasdn_;
/*   Common_nb_medium_jesAbsoluteMPFBiasdn*/  TBranch *Common_nb_medium_jesAbsoluteMPFBiasdn_branch;
/*   Common_nb_medium_jesAbsoluteMPFBiasdn*/  bool     Common_nb_medium_jesAbsoluteMPFBiasdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesFragmentationup*/  int      Common_nb_medium_jesFragmentationup_;
/*     Common_nb_medium_jesFragmentationup*/  TBranch *Common_nb_medium_jesFragmentationup_branch;
/*     Common_nb_medium_jesFragmentationup*/  bool     Common_nb_medium_jesFragmentationup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesFragmentationdn*/  int      Common_nb_medium_jesFragmentationdn_;
/*     Common_nb_medium_jesFragmentationdn*/  TBranch *Common_nb_medium_jesFragmentationdn_branch;
/*     Common_nb_medium_jesFragmentationdn*/  bool     Common_nb_medium_jesFragmentationdn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesSinglePionECALup*/  int      Common_nb_medium_jesSinglePionECALup_;
/*    Common_nb_medium_jesSinglePionECALup*/  TBranch *Common_nb_medium_jesSinglePionECALup_branch;
/*    Common_nb_medium_jesSinglePionECALup*/  bool     Common_nb_medium_jesSinglePionECALup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesSinglePionECALdn*/  int      Common_nb_medium_jesSinglePionECALdn_;
/*    Common_nb_medium_jesSinglePionECALdn*/  TBranch *Common_nb_medium_jesSinglePionECALdn_branch;
/*    Common_nb_medium_jesSinglePionECALdn*/  bool     Common_nb_medium_jesSinglePionECALdn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesSinglePionHCALup*/  int      Common_nb_medium_jesSinglePionHCALup_;
/*    Common_nb_medium_jesSinglePionHCALup*/  TBranch *Common_nb_medium_jesSinglePionHCALup_branch;
/*    Common_nb_medium_jesSinglePionHCALup*/  bool     Common_nb_medium_jesSinglePionHCALup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesSinglePionHCALdn*/  int      Common_nb_medium_jesSinglePionHCALdn_;
/*    Common_nb_medium_jesSinglePionHCALdn*/  TBranch *Common_nb_medium_jesSinglePionHCALdn_branch;
/*    Common_nb_medium_jesSinglePionHCALdn*/  bool     Common_nb_medium_jesSinglePionHCALdn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_nb_medium_jesFlavorQCDup*/  int      Common_nb_medium_jesFlavorQCDup_;
/*         Common_nb_medium_jesFlavorQCDup*/  TBranch *Common_nb_medium_jesFlavorQCDup_branch;
/*         Common_nb_medium_jesFlavorQCDup*/  bool     Common_nb_medium_jesFlavorQCDup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_nb_medium_jesFlavorQCDdn*/  int      Common_nb_medium_jesFlavorQCDdn_;
/*         Common_nb_medium_jesFlavorQCDdn*/  TBranch *Common_nb_medium_jesFlavorQCDdn_branch;
/*         Common_nb_medium_jesFlavorQCDdn*/  bool     Common_nb_medium_jesFlavorQCDdn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_nb_medium_jesTimePtEtaup*/  int      Common_nb_medium_jesTimePtEtaup_;
/*         Common_nb_medium_jesTimePtEtaup*/  TBranch *Common_nb_medium_jesTimePtEtaup_branch;
/*         Common_nb_medium_jesTimePtEtaup*/  bool     Common_nb_medium_jesTimePtEtaup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_nb_medium_jesTimePtEtadn*/  int      Common_nb_medium_jesTimePtEtadn_;
/*         Common_nb_medium_jesTimePtEtadn*/  TBranch *Common_nb_medium_jesTimePtEtadn_branch;
/*         Common_nb_medium_jesTimePtEtadn*/  bool     Common_nb_medium_jesTimePtEtadn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeJEREC1up*/  int      Common_nb_medium_jesRelativeJEREC1up_;
/*    Common_nb_medium_jesRelativeJEREC1up*/  TBranch *Common_nb_medium_jesRelativeJEREC1up_branch;
/*    Common_nb_medium_jesRelativeJEREC1up*/  bool     Common_nb_medium_jesRelativeJEREC1up_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeJEREC1dn*/  int      Common_nb_medium_jesRelativeJEREC1dn_;
/*    Common_nb_medium_jesRelativeJEREC1dn*/  TBranch *Common_nb_medium_jesRelativeJEREC1dn_branch;
/*    Common_nb_medium_jesRelativeJEREC1dn*/  bool     Common_nb_medium_jesRelativeJEREC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeJEREC2up*/  int      Common_nb_medium_jesRelativeJEREC2up_;
/*    Common_nb_medium_jesRelativeJEREC2up*/  TBranch *Common_nb_medium_jesRelativeJEREC2up_branch;
/*    Common_nb_medium_jesRelativeJEREC2up*/  bool     Common_nb_medium_jesRelativeJEREC2up_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeJEREC2dn*/  int      Common_nb_medium_jesRelativeJEREC2dn_;
/*    Common_nb_medium_jesRelativeJEREC2dn*/  TBranch *Common_nb_medium_jesRelativeJEREC2dn_branch;
/*    Common_nb_medium_jesRelativeJEREC2dn*/  bool     Common_nb_medium_jesRelativeJEREC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativeJERHFup*/  int      Common_nb_medium_jesRelativeJERHFup_;
/*     Common_nb_medium_jesRelativeJERHFup*/  TBranch *Common_nb_medium_jesRelativeJERHFup_branch;
/*     Common_nb_medium_jesRelativeJERHFup*/  bool     Common_nb_medium_jesRelativeJERHFup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativeJERHFdn*/  int      Common_nb_medium_jesRelativeJERHFdn_;
/*     Common_nb_medium_jesRelativeJERHFdn*/  TBranch *Common_nb_medium_jesRelativeJERHFdn_branch;
/*     Common_nb_medium_jesRelativeJERHFdn*/  bool     Common_nb_medium_jesRelativeJERHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesRelativePtBBup*/  int      Common_nb_medium_jesRelativePtBBup_;
/*      Common_nb_medium_jesRelativePtBBup*/  TBranch *Common_nb_medium_jesRelativePtBBup_branch;
/*      Common_nb_medium_jesRelativePtBBup*/  bool     Common_nb_medium_jesRelativePtBBup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesRelativePtBBdn*/  int      Common_nb_medium_jesRelativePtBBdn_;
/*      Common_nb_medium_jesRelativePtBBdn*/  TBranch *Common_nb_medium_jesRelativePtBBdn_branch;
/*      Common_nb_medium_jesRelativePtBBdn*/  bool     Common_nb_medium_jesRelativePtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativePtEC1up*/  int      Common_nb_medium_jesRelativePtEC1up_;
/*     Common_nb_medium_jesRelativePtEC1up*/  TBranch *Common_nb_medium_jesRelativePtEC1up_branch;
/*     Common_nb_medium_jesRelativePtEC1up*/  bool     Common_nb_medium_jesRelativePtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativePtEC1dn*/  int      Common_nb_medium_jesRelativePtEC1dn_;
/*     Common_nb_medium_jesRelativePtEC1dn*/  TBranch *Common_nb_medium_jesRelativePtEC1dn_branch;
/*     Common_nb_medium_jesRelativePtEC1dn*/  bool     Common_nb_medium_jesRelativePtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativePtEC2up*/  int      Common_nb_medium_jesRelativePtEC2up_;
/*     Common_nb_medium_jesRelativePtEC2up*/  TBranch *Common_nb_medium_jesRelativePtEC2up_branch;
/*     Common_nb_medium_jesRelativePtEC2up*/  bool     Common_nb_medium_jesRelativePtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativePtEC2dn*/  int      Common_nb_medium_jesRelativePtEC2dn_;
/*     Common_nb_medium_jesRelativePtEC2dn*/  TBranch *Common_nb_medium_jesRelativePtEC2dn_branch;
/*     Common_nb_medium_jesRelativePtEC2dn*/  bool     Common_nb_medium_jesRelativePtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesRelativePtHFup*/  int      Common_nb_medium_jesRelativePtHFup_;
/*      Common_nb_medium_jesRelativePtHFup*/  TBranch *Common_nb_medium_jesRelativePtHFup_branch;
/*      Common_nb_medium_jesRelativePtHFup*/  bool     Common_nb_medium_jesRelativePtHFup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesRelativePtHFdn*/  int      Common_nb_medium_jesRelativePtHFdn_;
/*      Common_nb_medium_jesRelativePtHFdn*/  TBranch *Common_nb_medium_jesRelativePtHFdn_branch;
/*      Common_nb_medium_jesRelativePtHFdn*/  bool     Common_nb_medium_jesRelativePtHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesRelativeBalup*/  int      Common_nb_medium_jesRelativeBalup_;
/*       Common_nb_medium_jesRelativeBalup*/  TBranch *Common_nb_medium_jesRelativeBalup_branch;
/*       Common_nb_medium_jesRelativeBalup*/  bool     Common_nb_medium_jesRelativeBalup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesRelativeBaldn*/  int      Common_nb_medium_jesRelativeBaldn_;
/*       Common_nb_medium_jesRelativeBaldn*/  TBranch *Common_nb_medium_jesRelativeBaldn_branch;
/*       Common_nb_medium_jesRelativeBaldn*/  bool     Common_nb_medium_jesRelativeBaldn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeSampleup*/  int      Common_nb_medium_jesRelativeSampleup_;
/*    Common_nb_medium_jesRelativeSampleup*/  TBranch *Common_nb_medium_jesRelativeSampleup_branch;
/*    Common_nb_medium_jesRelativeSampleup*/  bool     Common_nb_medium_jesRelativeSampleup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeSampledn*/  int      Common_nb_medium_jesRelativeSampledn_;
/*    Common_nb_medium_jesRelativeSampledn*/  TBranch *Common_nb_medium_jesRelativeSampledn_branch;
/*    Common_nb_medium_jesRelativeSampledn*/  bool     Common_nb_medium_jesRelativeSampledn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesRelativeFSRup*/  int      Common_nb_medium_jesRelativeFSRup_;
/*       Common_nb_medium_jesRelativeFSRup*/  TBranch *Common_nb_medium_jesRelativeFSRup_branch;
/*       Common_nb_medium_jesRelativeFSRup*/  bool     Common_nb_medium_jesRelativeFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesRelativeFSRdn*/  int      Common_nb_medium_jesRelativeFSRdn_;
/*       Common_nb_medium_jesRelativeFSRdn*/  TBranch *Common_nb_medium_jesRelativeFSRdn_branch;
/*       Common_nb_medium_jesRelativeFSRdn*/  bool     Common_nb_medium_jesRelativeFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*   Common_nb_medium_jesRelativeStatFSRup*/  int      Common_nb_medium_jesRelativeStatFSRup_;
/*   Common_nb_medium_jesRelativeStatFSRup*/  TBranch *Common_nb_medium_jesRelativeStatFSRup_branch;
/*   Common_nb_medium_jesRelativeStatFSRup*/  bool     Common_nb_medium_jesRelativeStatFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*   Common_nb_medium_jesRelativeStatFSRdn*/  int      Common_nb_medium_jesRelativeStatFSRdn_;
/*   Common_nb_medium_jesRelativeStatFSRdn*/  TBranch *Common_nb_medium_jesRelativeStatFSRdn_branch;
/*   Common_nb_medium_jesRelativeStatFSRdn*/  bool     Common_nb_medium_jesRelativeStatFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeStatECup*/  int      Common_nb_medium_jesRelativeStatECup_;
/*    Common_nb_medium_jesRelativeStatECup*/  TBranch *Common_nb_medium_jesRelativeStatECup_branch;
/*    Common_nb_medium_jesRelativeStatECup*/  bool     Common_nb_medium_jesRelativeStatECup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeStatECdn*/  int      Common_nb_medium_jesRelativeStatECdn_;
/*    Common_nb_medium_jesRelativeStatECdn*/  TBranch *Common_nb_medium_jesRelativeStatECdn_branch;
/*    Common_nb_medium_jesRelativeStatECdn*/  bool     Common_nb_medium_jesRelativeStatECdn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeStatHFup*/  int      Common_nb_medium_jesRelativeStatHFup_;
/*    Common_nb_medium_jesRelativeStatHFup*/  TBranch *Common_nb_medium_jesRelativeStatHFup_branch;
/*    Common_nb_medium_jesRelativeStatHFup*/  bool     Common_nb_medium_jesRelativeStatHFup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeStatHFdn*/  int      Common_nb_medium_jesRelativeStatHFdn_;
/*    Common_nb_medium_jesRelativeStatHFdn*/  TBranch *Common_nb_medium_jesRelativeStatHFdn_branch;
/*    Common_nb_medium_jesRelativeStatHFdn*/  bool     Common_nb_medium_jesRelativeStatHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesPileUpDataMCup*/  int      Common_nb_medium_jesPileUpDataMCup_;
/*      Common_nb_medium_jesPileUpDataMCup*/  TBranch *Common_nb_medium_jesPileUpDataMCup_branch;
/*      Common_nb_medium_jesPileUpDataMCup*/  bool     Common_nb_medium_jesPileUpDataMCup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesPileUpDataMCdn*/  int      Common_nb_medium_jesPileUpDataMCdn_;
/*      Common_nb_medium_jesPileUpDataMCdn*/  TBranch *Common_nb_medium_jesPileUpDataMCdn_branch;
/*      Common_nb_medium_jesPileUpDataMCdn*/  bool     Common_nb_medium_jesPileUpDataMCdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtRefup*/  int      Common_nb_medium_jesPileUpPtRefup_;
/*       Common_nb_medium_jesPileUpPtRefup*/  TBranch *Common_nb_medium_jesPileUpPtRefup_branch;
/*       Common_nb_medium_jesPileUpPtRefup*/  bool     Common_nb_medium_jesPileUpPtRefup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtRefdn*/  int      Common_nb_medium_jesPileUpPtRefdn_;
/*       Common_nb_medium_jesPileUpPtRefdn*/  TBranch *Common_nb_medium_jesPileUpPtRefdn_branch;
/*       Common_nb_medium_jesPileUpPtRefdn*/  bool     Common_nb_medium_jesPileUpPtRefdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_medium_jesPileUpPtBBup*/  int      Common_nb_medium_jesPileUpPtBBup_;
/*        Common_nb_medium_jesPileUpPtBBup*/  TBranch *Common_nb_medium_jesPileUpPtBBup_branch;
/*        Common_nb_medium_jesPileUpPtBBup*/  bool     Common_nb_medium_jesPileUpPtBBup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_medium_jesPileUpPtBBdn*/  int      Common_nb_medium_jesPileUpPtBBdn_;
/*        Common_nb_medium_jesPileUpPtBBdn*/  TBranch *Common_nb_medium_jesPileUpPtBBdn_branch;
/*        Common_nb_medium_jesPileUpPtBBdn*/  bool     Common_nb_medium_jesPileUpPtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtEC1up*/  int      Common_nb_medium_jesPileUpPtEC1up_;
/*       Common_nb_medium_jesPileUpPtEC1up*/  TBranch *Common_nb_medium_jesPileUpPtEC1up_branch;
/*       Common_nb_medium_jesPileUpPtEC1up*/  bool     Common_nb_medium_jesPileUpPtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtEC1dn*/  int      Common_nb_medium_jesPileUpPtEC1dn_;
/*       Common_nb_medium_jesPileUpPtEC1dn*/  TBranch *Common_nb_medium_jesPileUpPtEC1dn_branch;
/*       Common_nb_medium_jesPileUpPtEC1dn*/  bool     Common_nb_medium_jesPileUpPtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtEC2up*/  int      Common_nb_medium_jesPileUpPtEC2up_;
/*       Common_nb_medium_jesPileUpPtEC2up*/  TBranch *Common_nb_medium_jesPileUpPtEC2up_branch;
/*       Common_nb_medium_jesPileUpPtEC2up*/  bool     Common_nb_medium_jesPileUpPtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtEC2dn*/  int      Common_nb_medium_jesPileUpPtEC2dn_;
/*       Common_nb_medium_jesPileUpPtEC2dn*/  TBranch *Common_nb_medium_jesPileUpPtEC2dn_branch;
/*       Common_nb_medium_jesPileUpPtEC2dn*/  bool     Common_nb_medium_jesPileUpPtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_medium_jesPileUpPtHFup*/  int      Common_nb_medium_jesPileUpPtHFup_;
/*        Common_nb_medium_jesPileUpPtHFup*/  TBranch *Common_nb_medium_jesPileUpPtHFup_branch;
/*        Common_nb_medium_jesPileUpPtHFup*/  bool     Common_nb_medium_jesPileUpPtHFup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_medium_jesPileUpPtHFdn*/  int      Common_nb_medium_jesPileUpPtHFdn_;
/*        Common_nb_medium_jesPileUpPtHFdn*/  TBranch *Common_nb_medium_jesPileUpPtHFdn_branch;
/*        Common_nb_medium_jesPileUpPtHFdn*/  bool     Common_nb_medium_jesPileUpPtHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_nb_medium_jesup*/  int      Common_nb_medium_jesup_;
/*                  Common_nb_medium_jesup*/  TBranch *Common_nb_medium_jesup_branch;
/*                  Common_nb_medium_jesup*/  bool     Common_nb_medium_jesup_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_nb_medium_jesdn*/  int      Common_nb_medium_jesdn_;
/*                  Common_nb_medium_jesdn*/  TBranch *Common_nb_medium_jesdn_branch;
/*                  Common_nb_medium_jesdn*/  bool     Common_nb_medium_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_nb_medium_jerup*/  int      Common_nb_medium_jerup_;
/*                  Common_nb_medium_jerup*/  TBranch *Common_nb_medium_jerup_branch;
/*                  Common_nb_medium_jerup*/  bool     Common_nb_medium_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*                  Common_nb_medium_jerdn*/  int      Common_nb_medium_jerdn_;
/*                  Common_nb_medium_jerdn*/  TBranch *Common_nb_medium_jerdn_branch;
/*                  Common_nb_medium_jerdn*/  bool     Common_nb_medium_jerdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesAbsoluteStatup*/  int      Common_nb_tight_jesAbsoluteStatup_;
/*       Common_nb_tight_jesAbsoluteStatup*/  TBranch *Common_nb_tight_jesAbsoluteStatup_branch;
/*       Common_nb_tight_jesAbsoluteStatup*/  bool     Common_nb_tight_jesAbsoluteStatup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesAbsoluteStatdn*/  int      Common_nb_tight_jesAbsoluteStatdn_;
/*       Common_nb_tight_jesAbsoluteStatdn*/  TBranch *Common_nb_tight_jesAbsoluteStatdn_branch;
/*       Common_nb_tight_jesAbsoluteStatdn*/  bool     Common_nb_tight_jesAbsoluteStatdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesAbsoluteScaleup*/  int      Common_nb_tight_jesAbsoluteScaleup_;
/*      Common_nb_tight_jesAbsoluteScaleup*/  TBranch *Common_nb_tight_jesAbsoluteScaleup_branch;
/*      Common_nb_tight_jesAbsoluteScaleup*/  bool     Common_nb_tight_jesAbsoluteScaleup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesAbsoluteScaledn*/  int      Common_nb_tight_jesAbsoluteScaledn_;
/*      Common_nb_tight_jesAbsoluteScaledn*/  TBranch *Common_nb_tight_jesAbsoluteScaledn_branch;
/*      Common_nb_tight_jesAbsoluteScaledn*/  bool     Common_nb_tight_jesAbsoluteScaledn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_tight_jesAbsoluteMPFBiasup*/  int      Common_nb_tight_jesAbsoluteMPFBiasup_;
/*    Common_nb_tight_jesAbsoluteMPFBiasup*/  TBranch *Common_nb_tight_jesAbsoluteMPFBiasup_branch;
/*    Common_nb_tight_jesAbsoluteMPFBiasup*/  bool     Common_nb_tight_jesAbsoluteMPFBiasup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_tight_jesAbsoluteMPFBiasdn*/  int      Common_nb_tight_jesAbsoluteMPFBiasdn_;
/*    Common_nb_tight_jesAbsoluteMPFBiasdn*/  TBranch *Common_nb_tight_jesAbsoluteMPFBiasdn_branch;
/*    Common_nb_tight_jesAbsoluteMPFBiasdn*/  bool     Common_nb_tight_jesAbsoluteMPFBiasdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesFragmentationup*/  int      Common_nb_tight_jesFragmentationup_;
/*      Common_nb_tight_jesFragmentationup*/  TBranch *Common_nb_tight_jesFragmentationup_branch;
/*      Common_nb_tight_jesFragmentationup*/  bool     Common_nb_tight_jesFragmentationup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesFragmentationdn*/  int      Common_nb_tight_jesFragmentationdn_;
/*      Common_nb_tight_jesFragmentationdn*/  TBranch *Common_nb_tight_jesFragmentationdn_branch;
/*      Common_nb_tight_jesFragmentationdn*/  bool     Common_nb_tight_jesFragmentationdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesSinglePionECALup*/  int      Common_nb_tight_jesSinglePionECALup_;
/*     Common_nb_tight_jesSinglePionECALup*/  TBranch *Common_nb_tight_jesSinglePionECALup_branch;
/*     Common_nb_tight_jesSinglePionECALup*/  bool     Common_nb_tight_jesSinglePionECALup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesSinglePionECALdn*/  int      Common_nb_tight_jesSinglePionECALdn_;
/*     Common_nb_tight_jesSinglePionECALdn*/  TBranch *Common_nb_tight_jesSinglePionECALdn_branch;
/*     Common_nb_tight_jesSinglePionECALdn*/  bool     Common_nb_tight_jesSinglePionECALdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesSinglePionHCALup*/  int      Common_nb_tight_jesSinglePionHCALup_;
/*     Common_nb_tight_jesSinglePionHCALup*/  TBranch *Common_nb_tight_jesSinglePionHCALup_branch;
/*     Common_nb_tight_jesSinglePionHCALup*/  bool     Common_nb_tight_jesSinglePionHCALup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesSinglePionHCALdn*/  int      Common_nb_tight_jesSinglePionHCALdn_;
/*     Common_nb_tight_jesSinglePionHCALdn*/  TBranch *Common_nb_tight_jesSinglePionHCALdn_branch;
/*     Common_nb_tight_jesSinglePionHCALdn*/  bool     Common_nb_tight_jesSinglePionHCALdn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_nb_tight_jesFlavorQCDup*/  int      Common_nb_tight_jesFlavorQCDup_;
/*          Common_nb_tight_jesFlavorQCDup*/  TBranch *Common_nb_tight_jesFlavorQCDup_branch;
/*          Common_nb_tight_jesFlavorQCDup*/  bool     Common_nb_tight_jesFlavorQCDup_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_nb_tight_jesFlavorQCDdn*/  int      Common_nb_tight_jesFlavorQCDdn_;
/*          Common_nb_tight_jesFlavorQCDdn*/  TBranch *Common_nb_tight_jesFlavorQCDdn_branch;
/*          Common_nb_tight_jesFlavorQCDdn*/  bool     Common_nb_tight_jesFlavorQCDdn_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_nb_tight_jesTimePtEtaup*/  int      Common_nb_tight_jesTimePtEtaup_;
/*          Common_nb_tight_jesTimePtEtaup*/  TBranch *Common_nb_tight_jesTimePtEtaup_branch;
/*          Common_nb_tight_jesTimePtEtaup*/  bool     Common_nb_tight_jesTimePtEtaup_isLoaded;
//---------------------------------------------------------------------------------
/*          Common_nb_tight_jesTimePtEtadn*/  int      Common_nb_tight_jesTimePtEtadn_;
/*          Common_nb_tight_jesTimePtEtadn*/  TBranch *Common_nb_tight_jesTimePtEtadn_branch;
/*          Common_nb_tight_jesTimePtEtadn*/  bool     Common_nb_tight_jesTimePtEtadn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeJEREC1up*/  int      Common_nb_tight_jesRelativeJEREC1up_;
/*     Common_nb_tight_jesRelativeJEREC1up*/  TBranch *Common_nb_tight_jesRelativeJEREC1up_branch;
/*     Common_nb_tight_jesRelativeJEREC1up*/  bool     Common_nb_tight_jesRelativeJEREC1up_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeJEREC1dn*/  int      Common_nb_tight_jesRelativeJEREC1dn_;
/*     Common_nb_tight_jesRelativeJEREC1dn*/  TBranch *Common_nb_tight_jesRelativeJEREC1dn_branch;
/*     Common_nb_tight_jesRelativeJEREC1dn*/  bool     Common_nb_tight_jesRelativeJEREC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeJEREC2up*/  int      Common_nb_tight_jesRelativeJEREC2up_;
/*     Common_nb_tight_jesRelativeJEREC2up*/  TBranch *Common_nb_tight_jesRelativeJEREC2up_branch;
/*     Common_nb_tight_jesRelativeJEREC2up*/  bool     Common_nb_tight_jesRelativeJEREC2up_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeJEREC2dn*/  int      Common_nb_tight_jesRelativeJEREC2dn_;
/*     Common_nb_tight_jesRelativeJEREC2dn*/  TBranch *Common_nb_tight_jesRelativeJEREC2dn_branch;
/*     Common_nb_tight_jesRelativeJEREC2dn*/  bool     Common_nb_tight_jesRelativeJEREC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativeJERHFup*/  int      Common_nb_tight_jesRelativeJERHFup_;
/*      Common_nb_tight_jesRelativeJERHFup*/  TBranch *Common_nb_tight_jesRelativeJERHFup_branch;
/*      Common_nb_tight_jesRelativeJERHFup*/  bool     Common_nb_tight_jesRelativeJERHFup_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativeJERHFdn*/  int      Common_nb_tight_jesRelativeJERHFdn_;
/*      Common_nb_tight_jesRelativeJERHFdn*/  TBranch *Common_nb_tight_jesRelativeJERHFdn_branch;
/*      Common_nb_tight_jesRelativeJERHFdn*/  bool     Common_nb_tight_jesRelativeJERHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesRelativePtBBup*/  int      Common_nb_tight_jesRelativePtBBup_;
/*       Common_nb_tight_jesRelativePtBBup*/  TBranch *Common_nb_tight_jesRelativePtBBup_branch;
/*       Common_nb_tight_jesRelativePtBBup*/  bool     Common_nb_tight_jesRelativePtBBup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesRelativePtBBdn*/  int      Common_nb_tight_jesRelativePtBBdn_;
/*       Common_nb_tight_jesRelativePtBBdn*/  TBranch *Common_nb_tight_jesRelativePtBBdn_branch;
/*       Common_nb_tight_jesRelativePtBBdn*/  bool     Common_nb_tight_jesRelativePtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativePtEC1up*/  int      Common_nb_tight_jesRelativePtEC1up_;
/*      Common_nb_tight_jesRelativePtEC1up*/  TBranch *Common_nb_tight_jesRelativePtEC1up_branch;
/*      Common_nb_tight_jesRelativePtEC1up*/  bool     Common_nb_tight_jesRelativePtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativePtEC1dn*/  int      Common_nb_tight_jesRelativePtEC1dn_;
/*      Common_nb_tight_jesRelativePtEC1dn*/  TBranch *Common_nb_tight_jesRelativePtEC1dn_branch;
/*      Common_nb_tight_jesRelativePtEC1dn*/  bool     Common_nb_tight_jesRelativePtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativePtEC2up*/  int      Common_nb_tight_jesRelativePtEC2up_;
/*      Common_nb_tight_jesRelativePtEC2up*/  TBranch *Common_nb_tight_jesRelativePtEC2up_branch;
/*      Common_nb_tight_jesRelativePtEC2up*/  bool     Common_nb_tight_jesRelativePtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativePtEC2dn*/  int      Common_nb_tight_jesRelativePtEC2dn_;
/*      Common_nb_tight_jesRelativePtEC2dn*/  TBranch *Common_nb_tight_jesRelativePtEC2dn_branch;
/*      Common_nb_tight_jesRelativePtEC2dn*/  bool     Common_nb_tight_jesRelativePtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesRelativePtHFup*/  int      Common_nb_tight_jesRelativePtHFup_;
/*       Common_nb_tight_jesRelativePtHFup*/  TBranch *Common_nb_tight_jesRelativePtHFup_branch;
/*       Common_nb_tight_jesRelativePtHFup*/  bool     Common_nb_tight_jesRelativePtHFup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesRelativePtHFdn*/  int      Common_nb_tight_jesRelativePtHFdn_;
/*       Common_nb_tight_jesRelativePtHFdn*/  TBranch *Common_nb_tight_jesRelativePtHFdn_branch;
/*       Common_nb_tight_jesRelativePtHFdn*/  bool     Common_nb_tight_jesRelativePtHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesRelativeBalup*/  int      Common_nb_tight_jesRelativeBalup_;
/*        Common_nb_tight_jesRelativeBalup*/  TBranch *Common_nb_tight_jesRelativeBalup_branch;
/*        Common_nb_tight_jesRelativeBalup*/  bool     Common_nb_tight_jesRelativeBalup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesRelativeBaldn*/  int      Common_nb_tight_jesRelativeBaldn_;
/*        Common_nb_tight_jesRelativeBaldn*/  TBranch *Common_nb_tight_jesRelativeBaldn_branch;
/*        Common_nb_tight_jesRelativeBaldn*/  bool     Common_nb_tight_jesRelativeBaldn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeSampleup*/  int      Common_nb_tight_jesRelativeSampleup_;
/*     Common_nb_tight_jesRelativeSampleup*/  TBranch *Common_nb_tight_jesRelativeSampleup_branch;
/*     Common_nb_tight_jesRelativeSampleup*/  bool     Common_nb_tight_jesRelativeSampleup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeSampledn*/  int      Common_nb_tight_jesRelativeSampledn_;
/*     Common_nb_tight_jesRelativeSampledn*/  TBranch *Common_nb_tight_jesRelativeSampledn_branch;
/*     Common_nb_tight_jesRelativeSampledn*/  bool     Common_nb_tight_jesRelativeSampledn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesRelativeFSRup*/  int      Common_nb_tight_jesRelativeFSRup_;
/*        Common_nb_tight_jesRelativeFSRup*/  TBranch *Common_nb_tight_jesRelativeFSRup_branch;
/*        Common_nb_tight_jesRelativeFSRup*/  bool     Common_nb_tight_jesRelativeFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesRelativeFSRdn*/  int      Common_nb_tight_jesRelativeFSRdn_;
/*        Common_nb_tight_jesRelativeFSRdn*/  TBranch *Common_nb_tight_jesRelativeFSRdn_branch;
/*        Common_nb_tight_jesRelativeFSRdn*/  bool     Common_nb_tight_jesRelativeFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_tight_jesRelativeStatFSRup*/  int      Common_nb_tight_jesRelativeStatFSRup_;
/*    Common_nb_tight_jesRelativeStatFSRup*/  TBranch *Common_nb_tight_jesRelativeStatFSRup_branch;
/*    Common_nb_tight_jesRelativeStatFSRup*/  bool     Common_nb_tight_jesRelativeStatFSRup_isLoaded;
//---------------------------------------------------------------------------------
/*    Common_nb_tight_jesRelativeStatFSRdn*/  int      Common_nb_tight_jesRelativeStatFSRdn_;
/*    Common_nb_tight_jesRelativeStatFSRdn*/  TBranch *Common_nb_tight_jesRelativeStatFSRdn_branch;
/*    Common_nb_tight_jesRelativeStatFSRdn*/  bool     Common_nb_tight_jesRelativeStatFSRdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeStatECup*/  int      Common_nb_tight_jesRelativeStatECup_;
/*     Common_nb_tight_jesRelativeStatECup*/  TBranch *Common_nb_tight_jesRelativeStatECup_branch;
/*     Common_nb_tight_jesRelativeStatECup*/  bool     Common_nb_tight_jesRelativeStatECup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeStatECdn*/  int      Common_nb_tight_jesRelativeStatECdn_;
/*     Common_nb_tight_jesRelativeStatECdn*/  TBranch *Common_nb_tight_jesRelativeStatECdn_branch;
/*     Common_nb_tight_jesRelativeStatECdn*/  bool     Common_nb_tight_jesRelativeStatECdn_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeStatHFup*/  int      Common_nb_tight_jesRelativeStatHFup_;
/*     Common_nb_tight_jesRelativeStatHFup*/  TBranch *Common_nb_tight_jesRelativeStatHFup_branch;
/*     Common_nb_tight_jesRelativeStatHFup*/  bool     Common_nb_tight_jesRelativeStatHFup_isLoaded;
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeStatHFdn*/  int      Common_nb_tight_jesRelativeStatHFdn_;
/*     Common_nb_tight_jesRelativeStatHFdn*/  TBranch *Common_nb_tight_jesRelativeStatHFdn_branch;
/*     Common_nb_tight_jesRelativeStatHFdn*/  bool     Common_nb_tight_jesRelativeStatHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesPileUpDataMCup*/  int      Common_nb_tight_jesPileUpDataMCup_;
/*       Common_nb_tight_jesPileUpDataMCup*/  TBranch *Common_nb_tight_jesPileUpDataMCup_branch;
/*       Common_nb_tight_jesPileUpDataMCup*/  bool     Common_nb_tight_jesPileUpDataMCup_isLoaded;
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesPileUpDataMCdn*/  int      Common_nb_tight_jesPileUpDataMCdn_;
/*       Common_nb_tight_jesPileUpDataMCdn*/  TBranch *Common_nb_tight_jesPileUpDataMCdn_branch;
/*       Common_nb_tight_jesPileUpDataMCdn*/  bool     Common_nb_tight_jesPileUpDataMCdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtRefup*/  int      Common_nb_tight_jesPileUpPtRefup_;
/*        Common_nb_tight_jesPileUpPtRefup*/  TBranch *Common_nb_tight_jesPileUpPtRefup_branch;
/*        Common_nb_tight_jesPileUpPtRefup*/  bool     Common_nb_tight_jesPileUpPtRefup_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtRefdn*/  int      Common_nb_tight_jesPileUpPtRefdn_;
/*        Common_nb_tight_jesPileUpPtRefdn*/  TBranch *Common_nb_tight_jesPileUpPtRefdn_branch;
/*        Common_nb_tight_jesPileUpPtRefdn*/  bool     Common_nb_tight_jesPileUpPtRefdn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_nb_tight_jesPileUpPtBBup*/  int      Common_nb_tight_jesPileUpPtBBup_;
/*         Common_nb_tight_jesPileUpPtBBup*/  TBranch *Common_nb_tight_jesPileUpPtBBup_branch;
/*         Common_nb_tight_jesPileUpPtBBup*/  bool     Common_nb_tight_jesPileUpPtBBup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_nb_tight_jesPileUpPtBBdn*/  int      Common_nb_tight_jesPileUpPtBBdn_;
/*         Common_nb_tight_jesPileUpPtBBdn*/  TBranch *Common_nb_tight_jesPileUpPtBBdn_branch;
/*         Common_nb_tight_jesPileUpPtBBdn*/  bool     Common_nb_tight_jesPileUpPtBBdn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtEC1up*/  int      Common_nb_tight_jesPileUpPtEC1up_;
/*        Common_nb_tight_jesPileUpPtEC1up*/  TBranch *Common_nb_tight_jesPileUpPtEC1up_branch;
/*        Common_nb_tight_jesPileUpPtEC1up*/  bool     Common_nb_tight_jesPileUpPtEC1up_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtEC1dn*/  int      Common_nb_tight_jesPileUpPtEC1dn_;
/*        Common_nb_tight_jesPileUpPtEC1dn*/  TBranch *Common_nb_tight_jesPileUpPtEC1dn_branch;
/*        Common_nb_tight_jesPileUpPtEC1dn*/  bool     Common_nb_tight_jesPileUpPtEC1dn_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtEC2up*/  int      Common_nb_tight_jesPileUpPtEC2up_;
/*        Common_nb_tight_jesPileUpPtEC2up*/  TBranch *Common_nb_tight_jesPileUpPtEC2up_branch;
/*        Common_nb_tight_jesPileUpPtEC2up*/  bool     Common_nb_tight_jesPileUpPtEC2up_isLoaded;
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtEC2dn*/  int      Common_nb_tight_jesPileUpPtEC2dn_;
/*        Common_nb_tight_jesPileUpPtEC2dn*/  TBranch *Common_nb_tight_jesPileUpPtEC2dn_branch;
/*        Common_nb_tight_jesPileUpPtEC2dn*/  bool     Common_nb_tight_jesPileUpPtEC2dn_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_nb_tight_jesPileUpPtHFup*/  int      Common_nb_tight_jesPileUpPtHFup_;
/*         Common_nb_tight_jesPileUpPtHFup*/  TBranch *Common_nb_tight_jesPileUpPtHFup_branch;
/*         Common_nb_tight_jesPileUpPtHFup*/  bool     Common_nb_tight_jesPileUpPtHFup_isLoaded;
//---------------------------------------------------------------------------------
/*         Common_nb_tight_jesPileUpPtHFdn*/  int      Common_nb_tight_jesPileUpPtHFdn_;
/*         Common_nb_tight_jesPileUpPtHFdn*/  TBranch *Common_nb_tight_jesPileUpPtHFdn_branch;
/*         Common_nb_tight_jesPileUpPtHFdn*/  bool     Common_nb_tight_jesPileUpPtHFdn_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_nb_tight_jesup*/  int      Common_nb_tight_jesup_;
/*                   Common_nb_tight_jesup*/  TBranch *Common_nb_tight_jesup_branch;
/*                   Common_nb_tight_jesup*/  bool     Common_nb_tight_jesup_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_nb_tight_jesdn*/  int      Common_nb_tight_jesdn_;
/*                   Common_nb_tight_jesdn*/  TBranch *Common_nb_tight_jesdn_branch;
/*                   Common_nb_tight_jesdn*/  bool     Common_nb_tight_jesdn_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_nb_tight_jerup*/  int      Common_nb_tight_jerup_;
/*                   Common_nb_tight_jerup*/  TBranch *Common_nb_tight_jerup_branch;
/*                   Common_nb_tight_jerup*/  bool     Common_nb_tight_jerup_isLoaded;
//---------------------------------------------------------------------------------
/*                   Common_nb_tight_jerdn*/  int      Common_nb_tight_jerdn_;
/*                   Common_nb_tight_jerdn*/  TBranch *Common_nb_tight_jerdn_branch;
/*                   Common_nb_tight_jerdn*/  bool     Common_nb_tight_jerdn_isLoaded;
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
/*                      SS2jet_raw_gen_idx*/  vector<int> *SS2jet_raw_gen_idx_;
/*                      SS2jet_raw_gen_idx*/  TBranch *SS2jet_raw_gen_idx_branch;
/*                      SS2jet_raw_gen_idx*/  bool     SS2jet_raw_gen_idx_isLoaded;
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/  bool     Cut_4LepMET_emuChannel_;
/*                  Cut_4LepMET_emuChannel*/  TBranch *Cut_4LepMET_emuChannel_branch;
/*                  Cut_4LepMET_emuChannel*/  bool     Cut_4LepMET_emuChannel_isLoaded;
//---------------------------------------------------------------------------------
/*               SS2jet_raw_gen_mother_idx*/  vector<int> *SS2jet_raw_gen_mother_idx_;
/*               SS2jet_raw_gen_mother_idx*/  TBranch *SS2jet_raw_gen_mother_idx_branch;
/*               SS2jet_raw_gen_mother_idx*/  bool     SS2jet_raw_gen_mother_idx_isLoaded;
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/  bool     Cut_4LepMET_offzChannel_;
/*                 Cut_4LepMET_offzChannel*/  TBranch *Cut_4LepMET_offzChannel_branch;
/*                 Cut_4LepMET_offzChannel*/  bool     Cut_4LepMET_offzChannel_isLoaded;
//---------------------------------------------------------------------------------
/*                SS2jet_raw_gen_mother_id*/  vector<int> *SS2jet_raw_gen_mother_id_;
/*                SS2jet_raw_gen_mother_id*/  TBranch *SS2jet_raw_gen_mother_id_branch;
/*                SS2jet_raw_gen_mother_id*/  bool     SS2jet_raw_gen_mother_id_isLoaded;
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/  bool     Cut_4LepMET_onzChannel_;
/*                  Cut_4LepMET_onzChannel*/  TBranch *Cut_4LepMET_onzChannel_branch;
/*                  Cut_4LepMET_onzChannel*/  bool     Cut_4LepMET_onzChannel_isLoaded;
//---------------------------------------------------------------------------------
/*                    SS2jet_raw_gen_pdgid*/  vector<int> *SS2jet_raw_gen_pdgid_;
/*                    SS2jet_raw_gen_pdgid*/  TBranch *SS2jet_raw_gen_pdgid_branch;
/*                    SS2jet_raw_gen_pdgid*/  bool     SS2jet_raw_gen_pdgid_isLoaded;
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/  bool     Cut_4LepMET_onzChannel_HighMET_;
/*          Cut_4LepMET_onzChannel_HighMET*/  TBranch *Cut_4LepMET_onzChannel_HighMET_branch;
/*          Cut_4LepMET_onzChannel_HighMET*/  bool     Cut_4LepMET_onzChannel_HighMET_isLoaded;
//---------------------------------------------------------------------------------
/*                      SS2jet_raw_gen_p4s*/  vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > *SS2jet_raw_gen_p4s_;
/*                      SS2jet_raw_gen_p4s*/  TBranch *SS2jet_raw_gen_p4s_branch;
/*                      SS2jet_raw_gen_p4s*/  bool     SS2jet_raw_gen_p4s_isLoaded;
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/  int      Var_4LepMET_Zcand_lep_idx_0_;
/*             Var_4LepMET_Zcand_lep_idx_0*/  TBranch *Var_4LepMET_Zcand_lep_idx_0_branch;
/*             Var_4LepMET_Zcand_lep_idx_0*/  bool     Var_4LepMET_Zcand_lep_idx_0_isLoaded;
//---------------------------------------------------------------------------------
/*                   SS2jet_raw_gen_status*/  vector<int> *SS2jet_raw_gen_status_;
/*                   SS2jet_raw_gen_status*/  TBranch *SS2jet_raw_gen_status_branch;
/*                   SS2jet_raw_gen_status*/  bool     SS2jet_raw_gen_status_isLoaded;
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  int      Var_4LepMET_Zcand_lep_pdgid_0_;
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  TBranch *Var_4LepMET_Zcand_lep_pdgid_0_branch;
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  bool     Var_4LepMET_Zcand_lep_pdgid_0_isLoaded;
//---------------------------------------------------------------------------------
/*              SS2jet_raw_gen_statusFlags*/  vector<int> *SS2jet_raw_gen_statusFlags_;
/*              SS2jet_raw_gen_statusFlags*/  TBranch *SS2jet_raw_gen_statusFlags_branch;
/*              SS2jet_raw_gen_statusFlags*/  bool     SS2jet_raw_gen_statusFlags_isLoaded;
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
/*                        Common_genWeight*/  const float &Common_genWeight();
//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/  const float &Common_btagWeight_DeepCSVB();
//---------------------------------------------------------------------------------
/*                              Common_wgt*/  const float &Common_wgt();
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
/*         Common_LHEWeight_mg_reweighting*/  const vector<float> &Common_LHEWeight_mg_reweighting();
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
/*         Common_met_p4_jesAbsoluteStatup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesAbsoluteStatdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesAbsoluteScaleup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesAbsoluteScaledn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*      Common_met_p4_jesAbsoluteMPFBiasup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*      Common_met_p4_jesAbsoluteMPFBiasdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesFragmentationup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesFragmentationup();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesFragmentationdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesSinglePionECALup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesSinglePionECALdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesSinglePionHCALup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesSinglePionHCALdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*            Common_met_p4_jesFlavorQCDup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*            Common_met_p4_jesFlavorQCDdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*            Common_met_p4_jesTimePtEtaup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*            Common_met_p4_jesTimePtEtadn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeJEREC1up*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeJEREC1dn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeJEREC2up*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeJEREC2dn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativeJERHFup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativeJERHFdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesRelativePtBBup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesRelativePtBBdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativePtEC1up*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativePtEC1dn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativePtEC2up*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativePtEC2dn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesRelativePtHFup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesRelativePtHFdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesRelativeBalup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesRelativeBaldn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeSampleup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeSampledn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesRelativeFSRup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesRelativeFSRdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*      Common_met_p4_jesRelativeStatFSRup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*      Common_met_p4_jesRelativeStatFSRdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeStatECup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeStatECdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeStatHFup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeStatHFdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesPileUpDataMCup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesPileUpDataMCdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtRefup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtRefdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/*           Common_met_p4_jesPileUpPtBBup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/*           Common_met_p4_jesPileUpPtBBdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtEC1up*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtEC1dn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtEC2up*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtEC2dn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/*           Common_met_p4_jesPileUpPtHFup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/*           Common_met_p4_jesPileUpPtHFdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtHFdn();
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
/*         Common_jet_p4_jesAbsoluteStatup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesdn*/  const vector<float> &Common_jet_pt_jesdn();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesAbsoluteStatdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerup*/  const vector<float> &Common_jet_pt_jerup();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesAbsoluteScaleup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerdn*/  const vector<float> &Common_jet_pt_jerdn();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesAbsoluteScaledn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesup*/  const vector<float> &Common_jet_mass_jesup();
//---------------------------------------------------------------------------------
/*      Common_jet_p4_jesAbsoluteMPFBiasup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesdn*/  const vector<float> &Common_jet_mass_jesdn();
//---------------------------------------------------------------------------------
/*      Common_jet_p4_jesAbsoluteMPFBiasdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerup*/  const vector<float> &Common_jet_mass_jerup();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesFragmentationup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesFragmentationup();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerdn*/  const vector<float> &Common_jet_mass_jerdn();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesFragmentationdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesSinglePionECALup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesSinglePionECALdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesSinglePionHCALup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesSinglePionHCALdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*            Common_jet_p4_jesFlavorQCDup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*            Common_jet_p4_jesFlavorQCDdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*            Common_jet_p4_jesTimePtEtaup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*            Common_jet_p4_jesTimePtEtadn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeJEREC1up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeJEREC1dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeJEREC2up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeJEREC2dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativeJERHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativeJERHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesRelativePtBBup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesRelativePtBBdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativePtEC1up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativePtEC1dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativePtEC2up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativePtEC2dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesRelativePtHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesRelativePtHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesRelativeBalup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesRelativeBaldn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeSampleup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeSampledn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesRelativeFSRup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesRelativeFSRdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*      Common_jet_p4_jesRelativeStatFSRup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*      Common_jet_p4_jesRelativeStatFSRdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeStatECup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeStatECdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeStatHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeStatHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesPileUpDataMCup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesPileUpDataMCdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtRefup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtRefdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/*           Common_jet_p4_jesPileUpPtBBup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/*           Common_jet_p4_jesPileUpPtBBdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtEC1up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtEC1dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtEC2up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtEC2dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/*           Common_jet_p4_jesPileUpPtHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/*           Common_jet_p4_jesPileUpPtHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtHFdn();
//---------------------------------------------------------------------------------
/*                     Common_jet_p4_jesup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesup();
//---------------------------------------------------------------------------------
/*                     Common_jet_p4_jesdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesdn();
//---------------------------------------------------------------------------------
/*                     Common_jet_p4_jerup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jerup();
//---------------------------------------------------------------------------------
/*                     Common_jet_p4_jerdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jerdn();
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
/*      Common_fatjet_p4_jesAbsoluteStatup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesdn*/  const vector<float> &Common_fatjet_pt_jesdn();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesAbsoluteStatdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerup*/  const vector<float> &Common_fatjet_pt_jerup();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesAbsoluteScaleup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerdn*/  const vector<float> &Common_fatjet_pt_jerdn();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesAbsoluteScaledn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*   Common_fatjet_p4_jesAbsoluteMPFBiasup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*   Common_fatjet_p4_jesAbsoluteMPFBiasdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesFragmentationup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesFragmentationup();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesFragmentationdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesSinglePionECALup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesSinglePionECALdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesSinglePionHCALup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesSinglePionHCALdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*         Common_fatjet_p4_jesFlavorQCDup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*         Common_fatjet_p4_jesFlavorQCDdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*         Common_fatjet_p4_jesTimePtEtaup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*         Common_fatjet_p4_jesTimePtEtadn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeJEREC1up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeJEREC1dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeJEREC2up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeJEREC2dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativeJERHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativeJERHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesRelativePtBBup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesRelativePtBBdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativePtEC1up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativePtEC1dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativePtEC2up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativePtEC2dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesRelativePtHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesRelativePtHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesRelativeBalup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesRelativeBaldn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeSampleup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeSampledn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesRelativeFSRup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesRelativeFSRdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*   Common_fatjet_p4_jesRelativeStatFSRup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*   Common_fatjet_p4_jesRelativeStatFSRdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeStatECup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeStatECdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeStatHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeStatHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesPileUpDataMCup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesPileUpDataMCdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtRefup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtRefdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/*        Common_fatjet_p4_jesPileUpPtBBup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/*        Common_fatjet_p4_jesPileUpPtBBdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtEC1up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtEC1dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtEC2up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtEC2dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/*        Common_fatjet_p4_jesPileUpPtHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/*        Common_fatjet_p4_jesPileUpPtHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtHFdn();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_p4_jesup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_p4_jesdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesdn();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_p4_jerup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jerup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_p4_jerdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jerdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteStatup*/  const vector<float> &Common_fatjet_msoftdrop_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteStatdn*/  const vector<float> &Common_fatjet_msoftdrop_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteScaleup*/  const vector<float> &Common_fatjet_msoftdrop_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteScaledn*/  const vector<float> &Common_fatjet_msoftdrop_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteMPFBiasup*/  const vector<float> &Common_fatjet_msoftdrop_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteMPFBiasdn*/  const vector<float> &Common_fatjet_msoftdrop_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesFragmentationup*/  const vector<float> &Common_fatjet_msoftdrop_jesFragmentationup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesFragmentationdn*/  const vector<float> &Common_fatjet_msoftdrop_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesSinglePionECALup*/  const vector<float> &Common_fatjet_msoftdrop_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesSinglePionECALdn*/  const vector<float> &Common_fatjet_msoftdrop_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesSinglePionHCALup*/  const vector<float> &Common_fatjet_msoftdrop_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesSinglePionHCALdn*/  const vector<float> &Common_fatjet_msoftdrop_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*  Common_fatjet_msoftdrop_jesFlavorQCDup*/  const vector<float> &Common_fatjet_msoftdrop_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*  Common_fatjet_msoftdrop_jesFlavorQCDdn*/  const vector<float> &Common_fatjet_msoftdrop_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*  Common_fatjet_msoftdrop_jesTimePtEtaup*/  const vector<float> &Common_fatjet_msoftdrop_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*  Common_fatjet_msoftdrop_jesTimePtEtadn*/  const vector<float> &Common_fatjet_msoftdrop_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJEREC1up*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJEREC1dn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJEREC2up*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJEREC2dn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJERHFup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJERHFdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtBBup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtBBdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtEC1up*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtEC1dn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtEC2up*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtEC2dn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtHFup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtHFdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeBalup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeBaldn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeSampleup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeSampledn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeFSRup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeFSRdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatFSRup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatFSRdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatECup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatECdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatHFup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatHFdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpDataMCup*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpDataMCdn*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtRefup*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtRefdn*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/* Common_fatjet_msoftdrop_jesPileUpPtBBup*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/* Common_fatjet_msoftdrop_jesPileUpPtBBdn*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtEC1up*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtEC1dn*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtEC2up*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtEC2dn*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/* Common_fatjet_msoftdrop_jesPileUpPtHFup*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/* Common_fatjet_msoftdrop_jesPileUpPtHFdn*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtHFdn();
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
/*       Common_nb_loose_jesAbsoluteStatup*/  const int &Common_nb_loose_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesAbsoluteStatdn*/  const int &Common_nb_loose_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesAbsoluteScaleup*/  const int &Common_nb_loose_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesAbsoluteScaledn*/  const int &Common_nb_loose_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*    Common_nb_loose_jesAbsoluteMPFBiasup*/  const int &Common_nb_loose_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*    Common_nb_loose_jesAbsoluteMPFBiasdn*/  const int &Common_nb_loose_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesFragmentationup*/  const int &Common_nb_loose_jesFragmentationup();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesFragmentationdn*/  const int &Common_nb_loose_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesSinglePionECALup*/  const int &Common_nb_loose_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesSinglePionECALdn*/  const int &Common_nb_loose_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesSinglePionHCALup*/  const int &Common_nb_loose_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesSinglePionHCALdn*/  const int &Common_nb_loose_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*          Common_nb_loose_jesFlavorQCDup*/  const int &Common_nb_loose_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*          Common_nb_loose_jesFlavorQCDdn*/  const int &Common_nb_loose_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*          Common_nb_loose_jesTimePtEtaup*/  const int &Common_nb_loose_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*          Common_nb_loose_jesTimePtEtadn*/  const int &Common_nb_loose_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeJEREC1up*/  const int &Common_nb_loose_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeJEREC1dn*/  const int &Common_nb_loose_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeJEREC2up*/  const int &Common_nb_loose_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeJEREC2dn*/  const int &Common_nb_loose_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativeJERHFup*/  const int &Common_nb_loose_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativeJERHFdn*/  const int &Common_nb_loose_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesRelativePtBBup*/  const int &Common_nb_loose_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesRelativePtBBdn*/  const int &Common_nb_loose_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativePtEC1up*/  const int &Common_nb_loose_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativePtEC1dn*/  const int &Common_nb_loose_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativePtEC2up*/  const int &Common_nb_loose_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativePtEC2dn*/  const int &Common_nb_loose_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesRelativePtHFup*/  const int &Common_nb_loose_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesRelativePtHFdn*/  const int &Common_nb_loose_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesRelativeBalup*/  const int &Common_nb_loose_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesRelativeBaldn*/  const int &Common_nb_loose_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeSampleup*/  const int &Common_nb_loose_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeSampledn*/  const int &Common_nb_loose_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesRelativeFSRup*/  const int &Common_nb_loose_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesRelativeFSRdn*/  const int &Common_nb_loose_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*    Common_nb_loose_jesRelativeStatFSRup*/  const int &Common_nb_loose_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*    Common_nb_loose_jesRelativeStatFSRdn*/  const int &Common_nb_loose_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeStatECup*/  const int &Common_nb_loose_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeStatECdn*/  const int &Common_nb_loose_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeStatHFup*/  const int &Common_nb_loose_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeStatHFdn*/  const int &Common_nb_loose_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesPileUpDataMCup*/  const int &Common_nb_loose_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesPileUpDataMCdn*/  const int &Common_nb_loose_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtRefup*/  const int &Common_nb_loose_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtRefdn*/  const int &Common_nb_loose_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/*         Common_nb_loose_jesPileUpPtBBup*/  const int &Common_nb_loose_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/*         Common_nb_loose_jesPileUpPtBBdn*/  const int &Common_nb_loose_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtEC1up*/  const int &Common_nb_loose_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtEC1dn*/  const int &Common_nb_loose_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtEC2up*/  const int &Common_nb_loose_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtEC2dn*/  const int &Common_nb_loose_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/*         Common_nb_loose_jesPileUpPtHFup*/  const int &Common_nb_loose_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/*         Common_nb_loose_jesPileUpPtHFdn*/  const int &Common_nb_loose_jesPileUpPtHFdn();
//---------------------------------------------------------------------------------
/*                   Common_nb_loose_jesup*/  const int &Common_nb_loose_jesup();
//---------------------------------------------------------------------------------
/*                   Common_nb_loose_jesdn*/  const int &Common_nb_loose_jesdn();
//---------------------------------------------------------------------------------
/*                   Common_nb_loose_jerup*/  const int &Common_nb_loose_jerup();
//---------------------------------------------------------------------------------
/*                   Common_nb_loose_jerdn*/  const int &Common_nb_loose_jerdn();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesAbsoluteStatup*/  const int &Common_nb_medium_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesAbsoluteStatdn*/  const int &Common_nb_medium_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesAbsoluteScaleup*/  const int &Common_nb_medium_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesAbsoluteScaledn*/  const int &Common_nb_medium_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*   Common_nb_medium_jesAbsoluteMPFBiasup*/  const int &Common_nb_medium_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*   Common_nb_medium_jesAbsoluteMPFBiasdn*/  const int &Common_nb_medium_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesFragmentationup*/  const int &Common_nb_medium_jesFragmentationup();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesFragmentationdn*/  const int &Common_nb_medium_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesSinglePionECALup*/  const int &Common_nb_medium_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesSinglePionECALdn*/  const int &Common_nb_medium_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesSinglePionHCALup*/  const int &Common_nb_medium_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesSinglePionHCALdn*/  const int &Common_nb_medium_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*         Common_nb_medium_jesFlavorQCDup*/  const int &Common_nb_medium_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*         Common_nb_medium_jesFlavorQCDdn*/  const int &Common_nb_medium_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*         Common_nb_medium_jesTimePtEtaup*/  const int &Common_nb_medium_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*         Common_nb_medium_jesTimePtEtadn*/  const int &Common_nb_medium_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeJEREC1up*/  const int &Common_nb_medium_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeJEREC1dn*/  const int &Common_nb_medium_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeJEREC2up*/  const int &Common_nb_medium_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeJEREC2dn*/  const int &Common_nb_medium_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativeJERHFup*/  const int &Common_nb_medium_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativeJERHFdn*/  const int &Common_nb_medium_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesRelativePtBBup*/  const int &Common_nb_medium_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesRelativePtBBdn*/  const int &Common_nb_medium_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativePtEC1up*/  const int &Common_nb_medium_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativePtEC1dn*/  const int &Common_nb_medium_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativePtEC2up*/  const int &Common_nb_medium_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativePtEC2dn*/  const int &Common_nb_medium_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesRelativePtHFup*/  const int &Common_nb_medium_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesRelativePtHFdn*/  const int &Common_nb_medium_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesRelativeBalup*/  const int &Common_nb_medium_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesRelativeBaldn*/  const int &Common_nb_medium_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeSampleup*/  const int &Common_nb_medium_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeSampledn*/  const int &Common_nb_medium_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesRelativeFSRup*/  const int &Common_nb_medium_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesRelativeFSRdn*/  const int &Common_nb_medium_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*   Common_nb_medium_jesRelativeStatFSRup*/  const int &Common_nb_medium_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*   Common_nb_medium_jesRelativeStatFSRdn*/  const int &Common_nb_medium_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeStatECup*/  const int &Common_nb_medium_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeStatECdn*/  const int &Common_nb_medium_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeStatHFup*/  const int &Common_nb_medium_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeStatHFdn*/  const int &Common_nb_medium_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesPileUpDataMCup*/  const int &Common_nb_medium_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesPileUpDataMCdn*/  const int &Common_nb_medium_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtRefup*/  const int &Common_nb_medium_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtRefdn*/  const int &Common_nb_medium_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/*        Common_nb_medium_jesPileUpPtBBup*/  const int &Common_nb_medium_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/*        Common_nb_medium_jesPileUpPtBBdn*/  const int &Common_nb_medium_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtEC1up*/  const int &Common_nb_medium_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtEC1dn*/  const int &Common_nb_medium_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtEC2up*/  const int &Common_nb_medium_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtEC2dn*/  const int &Common_nb_medium_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/*        Common_nb_medium_jesPileUpPtHFup*/  const int &Common_nb_medium_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/*        Common_nb_medium_jesPileUpPtHFdn*/  const int &Common_nb_medium_jesPileUpPtHFdn();
//---------------------------------------------------------------------------------
/*                  Common_nb_medium_jesup*/  const int &Common_nb_medium_jesup();
//---------------------------------------------------------------------------------
/*                  Common_nb_medium_jesdn*/  const int &Common_nb_medium_jesdn();
//---------------------------------------------------------------------------------
/*                  Common_nb_medium_jerup*/  const int &Common_nb_medium_jerup();
//---------------------------------------------------------------------------------
/*                  Common_nb_medium_jerdn*/  const int &Common_nb_medium_jerdn();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesAbsoluteStatup*/  const int &Common_nb_tight_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesAbsoluteStatdn*/  const int &Common_nb_tight_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesAbsoluteScaleup*/  const int &Common_nb_tight_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesAbsoluteScaledn*/  const int &Common_nb_tight_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*    Common_nb_tight_jesAbsoluteMPFBiasup*/  const int &Common_nb_tight_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*    Common_nb_tight_jesAbsoluteMPFBiasdn*/  const int &Common_nb_tight_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesFragmentationup*/  const int &Common_nb_tight_jesFragmentationup();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesFragmentationdn*/  const int &Common_nb_tight_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesSinglePionECALup*/  const int &Common_nb_tight_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesSinglePionECALdn*/  const int &Common_nb_tight_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesSinglePionHCALup*/  const int &Common_nb_tight_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesSinglePionHCALdn*/  const int &Common_nb_tight_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*          Common_nb_tight_jesFlavorQCDup*/  const int &Common_nb_tight_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*          Common_nb_tight_jesFlavorQCDdn*/  const int &Common_nb_tight_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*          Common_nb_tight_jesTimePtEtaup*/  const int &Common_nb_tight_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*          Common_nb_tight_jesTimePtEtadn*/  const int &Common_nb_tight_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeJEREC1up*/  const int &Common_nb_tight_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeJEREC1dn*/  const int &Common_nb_tight_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeJEREC2up*/  const int &Common_nb_tight_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeJEREC2dn*/  const int &Common_nb_tight_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativeJERHFup*/  const int &Common_nb_tight_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativeJERHFdn*/  const int &Common_nb_tight_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesRelativePtBBup*/  const int &Common_nb_tight_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesRelativePtBBdn*/  const int &Common_nb_tight_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativePtEC1up*/  const int &Common_nb_tight_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativePtEC1dn*/  const int &Common_nb_tight_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativePtEC2up*/  const int &Common_nb_tight_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativePtEC2dn*/  const int &Common_nb_tight_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesRelativePtHFup*/  const int &Common_nb_tight_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesRelativePtHFdn*/  const int &Common_nb_tight_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesRelativeBalup*/  const int &Common_nb_tight_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesRelativeBaldn*/  const int &Common_nb_tight_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeSampleup*/  const int &Common_nb_tight_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeSampledn*/  const int &Common_nb_tight_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesRelativeFSRup*/  const int &Common_nb_tight_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesRelativeFSRdn*/  const int &Common_nb_tight_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*    Common_nb_tight_jesRelativeStatFSRup*/  const int &Common_nb_tight_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*    Common_nb_tight_jesRelativeStatFSRdn*/  const int &Common_nb_tight_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeStatECup*/  const int &Common_nb_tight_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeStatECdn*/  const int &Common_nb_tight_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeStatHFup*/  const int &Common_nb_tight_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeStatHFdn*/  const int &Common_nb_tight_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesPileUpDataMCup*/  const int &Common_nb_tight_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesPileUpDataMCdn*/  const int &Common_nb_tight_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtRefup*/  const int &Common_nb_tight_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtRefdn*/  const int &Common_nb_tight_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/*         Common_nb_tight_jesPileUpPtBBup*/  const int &Common_nb_tight_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/*         Common_nb_tight_jesPileUpPtBBdn*/  const int &Common_nb_tight_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtEC1up*/  const int &Common_nb_tight_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtEC1dn*/  const int &Common_nb_tight_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtEC2up*/  const int &Common_nb_tight_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtEC2dn*/  const int &Common_nb_tight_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/*         Common_nb_tight_jesPileUpPtHFup*/  const int &Common_nb_tight_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/*         Common_nb_tight_jesPileUpPtHFdn*/  const int &Common_nb_tight_jesPileUpPtHFdn();
//---------------------------------------------------------------------------------
/*                   Common_nb_tight_jesup*/  const int &Common_nb_tight_jesup();
//---------------------------------------------------------------------------------
/*                   Common_nb_tight_jesdn*/  const int &Common_nb_tight_jesdn();
//---------------------------------------------------------------------------------
/*                   Common_nb_tight_jerup*/  const int &Common_nb_tight_jerup();
//---------------------------------------------------------------------------------
/*                   Common_nb_tight_jerdn*/  const int &Common_nb_tight_jerdn();
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
/*                      SS2jet_raw_gen_idx*/  const vector<int> &SS2jet_raw_gen_idx();
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/  const bool &Cut_4LepMET_emuChannel();
//---------------------------------------------------------------------------------
/*               SS2jet_raw_gen_mother_idx*/  const vector<int> &SS2jet_raw_gen_mother_idx();
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/  const bool &Cut_4LepMET_offzChannel();
//---------------------------------------------------------------------------------
/*                SS2jet_raw_gen_mother_id*/  const vector<int> &SS2jet_raw_gen_mother_id();
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/  const bool &Cut_4LepMET_onzChannel();
//---------------------------------------------------------------------------------
/*                    SS2jet_raw_gen_pdgid*/  const vector<int> &SS2jet_raw_gen_pdgid();
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/  const bool &Cut_4LepMET_onzChannel_HighMET();
//---------------------------------------------------------------------------------
/*                      SS2jet_raw_gen_p4s*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &SS2jet_raw_gen_p4s();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/  const int &Var_4LepMET_Zcand_lep_idx_0();
//---------------------------------------------------------------------------------
/*                   SS2jet_raw_gen_status*/  const vector<int> &SS2jet_raw_gen_status();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  const int &Var_4LepMET_Zcand_lep_pdgid_0();
//---------------------------------------------------------------------------------
/*              SS2jet_raw_gen_statusFlags*/  const vector<int> &SS2jet_raw_gen_statusFlags();
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
/*                        Common_genWeight*/  const float &Common_genWeight();
//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/  const float &Common_btagWeight_DeepCSVB();
//---------------------------------------------------------------------------------
/*                              Common_wgt*/  const float &Common_wgt();
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
/*         Common_LHEWeight_mg_reweighting*/  const vector<float> &Common_LHEWeight_mg_reweighting();
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
/*                        Common_passGoodRun*/  const bool &Common_passGoodRun();
//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/  const bool &Common_noiseFlag();
//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/  const bool &Common_noiseFlagMC();
//---------------------------------------------------------------------------------
/*                      Common_passGoodRun*/  const bool &Common_passGoodRun();
//---------------------------------------------------------------------------------
/*                           Common_met_p4*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesAbsoluteStatup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesAbsoluteStatdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesAbsoluteScaleup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesAbsoluteScaledn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*      Common_met_p4_jesAbsoluteMPFBiasup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*      Common_met_p4_jesAbsoluteMPFBiasdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesFragmentationup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesFragmentationup();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesFragmentationdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesSinglePionECALup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesSinglePionECALdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesSinglePionHCALup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesSinglePionHCALdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*            Common_met_p4_jesFlavorQCDup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*            Common_met_p4_jesFlavorQCDdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*            Common_met_p4_jesTimePtEtaup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*            Common_met_p4_jesTimePtEtadn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeJEREC1up*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeJEREC1dn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeJEREC2up*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeJEREC2dn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativeJERHFup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativeJERHFdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesRelativePtBBup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesRelativePtBBdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativePtEC1up*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativePtEC1dn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativePtEC2up*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*        Common_met_p4_jesRelativePtEC2dn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesRelativePtHFup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesRelativePtHFdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesRelativeBalup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesRelativeBaldn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeSampleup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeSampledn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesRelativeFSRup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesRelativeFSRdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*      Common_met_p4_jesRelativeStatFSRup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*      Common_met_p4_jesRelativeStatFSRdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeStatECup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeStatECdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeStatHFup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*       Common_met_p4_jesRelativeStatHFdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesPileUpDataMCup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*         Common_met_p4_jesPileUpDataMCdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtRefup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtRefdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/*           Common_met_p4_jesPileUpPtBBup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/*           Common_met_p4_jesPileUpPtBBdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtEC1up*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtEC1dn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtEC2up*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*          Common_met_p4_jesPileUpPtEC2dn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/*           Common_met_p4_jesPileUpPtHFup*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/*           Common_met_p4_jesPileUpPtHFdn*/  const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesPileUpPtHFdn();
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
/*         Common_jet_p4_jesAbsoluteStatup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesdn*/  const vector<float> &Common_jet_pt_jesdn();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesAbsoluteStatdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerup*/  const vector<float> &Common_jet_pt_jerup();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesAbsoluteScaleup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerdn*/  const vector<float> &Common_jet_pt_jerdn();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesAbsoluteScaledn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesup*/  const vector<float> &Common_jet_mass_jesup();
//---------------------------------------------------------------------------------
/*      Common_jet_p4_jesAbsoluteMPFBiasup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesdn*/  const vector<float> &Common_jet_mass_jesdn();
//---------------------------------------------------------------------------------
/*      Common_jet_p4_jesAbsoluteMPFBiasdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerup*/  const vector<float> &Common_jet_mass_jerup();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesFragmentationup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesFragmentationup();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerdn*/  const vector<float> &Common_jet_mass_jerdn();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesFragmentationdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesSinglePionECALup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesSinglePionECALdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesSinglePionHCALup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesSinglePionHCALdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*            Common_jet_p4_jesFlavorQCDup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*            Common_jet_p4_jesFlavorQCDdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*            Common_jet_p4_jesTimePtEtaup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*            Common_jet_p4_jesTimePtEtadn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeJEREC1up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeJEREC1dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeJEREC2up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeJEREC2dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativeJERHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativeJERHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesRelativePtBBup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesRelativePtBBdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativePtEC1up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativePtEC1dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativePtEC2up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*        Common_jet_p4_jesRelativePtEC2dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesRelativePtHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesRelativePtHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesRelativeBalup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesRelativeBaldn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeSampleup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeSampledn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesRelativeFSRup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesRelativeFSRdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*      Common_jet_p4_jesRelativeStatFSRup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*      Common_jet_p4_jesRelativeStatFSRdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeStatECup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeStatECdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeStatHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*       Common_jet_p4_jesRelativeStatHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesPileUpDataMCup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*         Common_jet_p4_jesPileUpDataMCdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtRefup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtRefdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/*           Common_jet_p4_jesPileUpPtBBup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/*           Common_jet_p4_jesPileUpPtBBdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtEC1up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtEC1dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtEC2up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*          Common_jet_p4_jesPileUpPtEC2dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/*           Common_jet_p4_jesPileUpPtHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/*           Common_jet_p4_jesPileUpPtHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesPileUpPtHFdn();
//---------------------------------------------------------------------------------
/*                     Common_jet_p4_jesup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesup();
//---------------------------------------------------------------------------------
/*                     Common_jet_p4_jesdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jesdn();
//---------------------------------------------------------------------------------
/*                     Common_jet_p4_jerup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jerup();
//---------------------------------------------------------------------------------
/*                     Common_jet_p4_jerdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4_jerdn();
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
/*      Common_fatjet_p4_jesAbsoluteStatup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesdn*/  const vector<float> &Common_fatjet_pt_jesdn();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesAbsoluteStatdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerup*/  const vector<float> &Common_fatjet_pt_jerup();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesAbsoluteScaleup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerdn*/  const vector<float> &Common_fatjet_pt_jerdn();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesAbsoluteScaledn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*   Common_fatjet_p4_jesAbsoluteMPFBiasup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*   Common_fatjet_p4_jesAbsoluteMPFBiasdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesFragmentationup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesFragmentationup();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesFragmentationdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesSinglePionECALup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesSinglePionECALdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesSinglePionHCALup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesSinglePionHCALdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*         Common_fatjet_p4_jesFlavorQCDup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*         Common_fatjet_p4_jesFlavorQCDdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*         Common_fatjet_p4_jesTimePtEtaup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*         Common_fatjet_p4_jesTimePtEtadn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeJEREC1up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeJEREC1dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeJEREC2up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeJEREC2dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativeJERHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativeJERHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesRelativePtBBup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesRelativePtBBdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativePtEC1up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativePtEC1dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativePtEC2up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*     Common_fatjet_p4_jesRelativePtEC2dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesRelativePtHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesRelativePtHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesRelativeBalup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesRelativeBaldn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeSampleup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeSampledn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesRelativeFSRup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesRelativeFSRdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*   Common_fatjet_p4_jesRelativeStatFSRup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*   Common_fatjet_p4_jesRelativeStatFSRdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeStatECup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeStatECdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeStatHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*    Common_fatjet_p4_jesRelativeStatHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesPileUpDataMCup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*      Common_fatjet_p4_jesPileUpDataMCdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtRefup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtRefdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/*        Common_fatjet_p4_jesPileUpPtBBup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/*        Common_fatjet_p4_jesPileUpPtBBdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtEC1up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtEC1dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtEC2up*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*       Common_fatjet_p4_jesPileUpPtEC2dn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/*        Common_fatjet_p4_jesPileUpPtHFup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/*        Common_fatjet_p4_jesPileUpPtHFdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesPileUpPtHFdn();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_p4_jesup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_p4_jesdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jesdn();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_p4_jerup*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jerup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_p4_jerdn*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4_jerdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteStatup*/  const vector<float> &Common_fatjet_msoftdrop_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteStatdn*/  const vector<float> &Common_fatjet_msoftdrop_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteScaleup*/  const vector<float> &Common_fatjet_msoftdrop_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteScaledn*/  const vector<float> &Common_fatjet_msoftdrop_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteMPFBiasup*/  const vector<float> &Common_fatjet_msoftdrop_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesAbsoluteMPFBiasdn*/  const vector<float> &Common_fatjet_msoftdrop_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesFragmentationup*/  const vector<float> &Common_fatjet_msoftdrop_jesFragmentationup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesFragmentationdn*/  const vector<float> &Common_fatjet_msoftdrop_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesSinglePionECALup*/  const vector<float> &Common_fatjet_msoftdrop_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesSinglePionECALdn*/  const vector<float> &Common_fatjet_msoftdrop_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesSinglePionHCALup*/  const vector<float> &Common_fatjet_msoftdrop_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesSinglePionHCALdn*/  const vector<float> &Common_fatjet_msoftdrop_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*  Common_fatjet_msoftdrop_jesFlavorQCDup*/  const vector<float> &Common_fatjet_msoftdrop_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*  Common_fatjet_msoftdrop_jesFlavorQCDdn*/  const vector<float> &Common_fatjet_msoftdrop_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*  Common_fatjet_msoftdrop_jesTimePtEtaup*/  const vector<float> &Common_fatjet_msoftdrop_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*  Common_fatjet_msoftdrop_jesTimePtEtadn*/  const vector<float> &Common_fatjet_msoftdrop_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJEREC1up*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJEREC1dn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJEREC2up*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJEREC2dn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJERHFup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeJERHFdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtBBup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtBBdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtEC1up*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtEC1dn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtEC2up*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtEC2dn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtHFup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativePtHFdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeBalup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeBaldn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeSampleup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeSampledn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeFSRup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeFSRdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatFSRup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatFSRdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatECup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatECdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatHFup*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesRelativeStatHFdn*/  const vector<float> &Common_fatjet_msoftdrop_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpDataMCup*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpDataMCdn*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtRefup*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtRefdn*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/* Common_fatjet_msoftdrop_jesPileUpPtBBup*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/* Common_fatjet_msoftdrop_jesPileUpPtBBdn*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtEC1up*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtEC1dn*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtEC2up*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*Common_fatjet_msoftdrop_jesPileUpPtEC2dn*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/* Common_fatjet_msoftdrop_jesPileUpPtHFup*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/* Common_fatjet_msoftdrop_jesPileUpPtHFdn*/  const vector<float> &Common_fatjet_msoftdrop_jesPileUpPtHFdn();
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
/*       Common_nb_loose_jesAbsoluteStatup*/  const int &Common_nb_loose_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesAbsoluteStatdn*/  const int &Common_nb_loose_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesAbsoluteScaleup*/  const int &Common_nb_loose_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesAbsoluteScaledn*/  const int &Common_nb_loose_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*    Common_nb_loose_jesAbsoluteMPFBiasup*/  const int &Common_nb_loose_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*    Common_nb_loose_jesAbsoluteMPFBiasdn*/  const int &Common_nb_loose_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesFragmentationup*/  const int &Common_nb_loose_jesFragmentationup();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesFragmentationdn*/  const int &Common_nb_loose_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesSinglePionECALup*/  const int &Common_nb_loose_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesSinglePionECALdn*/  const int &Common_nb_loose_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesSinglePionHCALup*/  const int &Common_nb_loose_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesSinglePionHCALdn*/  const int &Common_nb_loose_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*          Common_nb_loose_jesFlavorQCDup*/  const int &Common_nb_loose_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*          Common_nb_loose_jesFlavorQCDdn*/  const int &Common_nb_loose_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*          Common_nb_loose_jesTimePtEtaup*/  const int &Common_nb_loose_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*          Common_nb_loose_jesTimePtEtadn*/  const int &Common_nb_loose_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeJEREC1up*/  const int &Common_nb_loose_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeJEREC1dn*/  const int &Common_nb_loose_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeJEREC2up*/  const int &Common_nb_loose_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeJEREC2dn*/  const int &Common_nb_loose_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativeJERHFup*/  const int &Common_nb_loose_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativeJERHFdn*/  const int &Common_nb_loose_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesRelativePtBBup*/  const int &Common_nb_loose_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesRelativePtBBdn*/  const int &Common_nb_loose_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativePtEC1up*/  const int &Common_nb_loose_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativePtEC1dn*/  const int &Common_nb_loose_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativePtEC2up*/  const int &Common_nb_loose_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*      Common_nb_loose_jesRelativePtEC2dn*/  const int &Common_nb_loose_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesRelativePtHFup*/  const int &Common_nb_loose_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesRelativePtHFdn*/  const int &Common_nb_loose_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesRelativeBalup*/  const int &Common_nb_loose_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesRelativeBaldn*/  const int &Common_nb_loose_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeSampleup*/  const int &Common_nb_loose_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeSampledn*/  const int &Common_nb_loose_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesRelativeFSRup*/  const int &Common_nb_loose_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesRelativeFSRdn*/  const int &Common_nb_loose_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*    Common_nb_loose_jesRelativeStatFSRup*/  const int &Common_nb_loose_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*    Common_nb_loose_jesRelativeStatFSRdn*/  const int &Common_nb_loose_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeStatECup*/  const int &Common_nb_loose_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeStatECdn*/  const int &Common_nb_loose_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeStatHFup*/  const int &Common_nb_loose_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*     Common_nb_loose_jesRelativeStatHFdn*/  const int &Common_nb_loose_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesPileUpDataMCup*/  const int &Common_nb_loose_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*       Common_nb_loose_jesPileUpDataMCdn*/  const int &Common_nb_loose_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtRefup*/  const int &Common_nb_loose_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtRefdn*/  const int &Common_nb_loose_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/*         Common_nb_loose_jesPileUpPtBBup*/  const int &Common_nb_loose_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/*         Common_nb_loose_jesPileUpPtBBdn*/  const int &Common_nb_loose_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtEC1up*/  const int &Common_nb_loose_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtEC1dn*/  const int &Common_nb_loose_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtEC2up*/  const int &Common_nb_loose_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*        Common_nb_loose_jesPileUpPtEC2dn*/  const int &Common_nb_loose_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/*         Common_nb_loose_jesPileUpPtHFup*/  const int &Common_nb_loose_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/*         Common_nb_loose_jesPileUpPtHFdn*/  const int &Common_nb_loose_jesPileUpPtHFdn();
//---------------------------------------------------------------------------------
/*                   Common_nb_loose_jesup*/  const int &Common_nb_loose_jesup();
//---------------------------------------------------------------------------------
/*                   Common_nb_loose_jesdn*/  const int &Common_nb_loose_jesdn();
//---------------------------------------------------------------------------------
/*                   Common_nb_loose_jerup*/  const int &Common_nb_loose_jerup();
//---------------------------------------------------------------------------------
/*                   Common_nb_loose_jerdn*/  const int &Common_nb_loose_jerdn();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesAbsoluteStatup*/  const int &Common_nb_medium_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesAbsoluteStatdn*/  const int &Common_nb_medium_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesAbsoluteScaleup*/  const int &Common_nb_medium_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesAbsoluteScaledn*/  const int &Common_nb_medium_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*   Common_nb_medium_jesAbsoluteMPFBiasup*/  const int &Common_nb_medium_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*   Common_nb_medium_jesAbsoluteMPFBiasdn*/  const int &Common_nb_medium_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesFragmentationup*/  const int &Common_nb_medium_jesFragmentationup();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesFragmentationdn*/  const int &Common_nb_medium_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesSinglePionECALup*/  const int &Common_nb_medium_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesSinglePionECALdn*/  const int &Common_nb_medium_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesSinglePionHCALup*/  const int &Common_nb_medium_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesSinglePionHCALdn*/  const int &Common_nb_medium_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*         Common_nb_medium_jesFlavorQCDup*/  const int &Common_nb_medium_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*         Common_nb_medium_jesFlavorQCDdn*/  const int &Common_nb_medium_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*         Common_nb_medium_jesTimePtEtaup*/  const int &Common_nb_medium_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*         Common_nb_medium_jesTimePtEtadn*/  const int &Common_nb_medium_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeJEREC1up*/  const int &Common_nb_medium_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeJEREC1dn*/  const int &Common_nb_medium_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeJEREC2up*/  const int &Common_nb_medium_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeJEREC2dn*/  const int &Common_nb_medium_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativeJERHFup*/  const int &Common_nb_medium_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativeJERHFdn*/  const int &Common_nb_medium_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesRelativePtBBup*/  const int &Common_nb_medium_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesRelativePtBBdn*/  const int &Common_nb_medium_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativePtEC1up*/  const int &Common_nb_medium_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativePtEC1dn*/  const int &Common_nb_medium_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativePtEC2up*/  const int &Common_nb_medium_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*     Common_nb_medium_jesRelativePtEC2dn*/  const int &Common_nb_medium_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesRelativePtHFup*/  const int &Common_nb_medium_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesRelativePtHFdn*/  const int &Common_nb_medium_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesRelativeBalup*/  const int &Common_nb_medium_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesRelativeBaldn*/  const int &Common_nb_medium_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeSampleup*/  const int &Common_nb_medium_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeSampledn*/  const int &Common_nb_medium_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesRelativeFSRup*/  const int &Common_nb_medium_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesRelativeFSRdn*/  const int &Common_nb_medium_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*   Common_nb_medium_jesRelativeStatFSRup*/  const int &Common_nb_medium_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*   Common_nb_medium_jesRelativeStatFSRdn*/  const int &Common_nb_medium_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeStatECup*/  const int &Common_nb_medium_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeStatECdn*/  const int &Common_nb_medium_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeStatHFup*/  const int &Common_nb_medium_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*    Common_nb_medium_jesRelativeStatHFdn*/  const int &Common_nb_medium_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesPileUpDataMCup*/  const int &Common_nb_medium_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*      Common_nb_medium_jesPileUpDataMCdn*/  const int &Common_nb_medium_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtRefup*/  const int &Common_nb_medium_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtRefdn*/  const int &Common_nb_medium_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/*        Common_nb_medium_jesPileUpPtBBup*/  const int &Common_nb_medium_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/*        Common_nb_medium_jesPileUpPtBBdn*/  const int &Common_nb_medium_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtEC1up*/  const int &Common_nb_medium_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtEC1dn*/  const int &Common_nb_medium_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtEC2up*/  const int &Common_nb_medium_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*       Common_nb_medium_jesPileUpPtEC2dn*/  const int &Common_nb_medium_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/*        Common_nb_medium_jesPileUpPtHFup*/  const int &Common_nb_medium_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/*        Common_nb_medium_jesPileUpPtHFdn*/  const int &Common_nb_medium_jesPileUpPtHFdn();
//---------------------------------------------------------------------------------
/*                  Common_nb_medium_jesup*/  const int &Common_nb_medium_jesup();
//---------------------------------------------------------------------------------
/*                  Common_nb_medium_jesdn*/  const int &Common_nb_medium_jesdn();
//---------------------------------------------------------------------------------
/*                  Common_nb_medium_jerup*/  const int &Common_nb_medium_jerup();
//---------------------------------------------------------------------------------
/*                  Common_nb_medium_jerdn*/  const int &Common_nb_medium_jerdn();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesAbsoluteStatup*/  const int &Common_nb_tight_jesAbsoluteStatup();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesAbsoluteStatdn*/  const int &Common_nb_tight_jesAbsoluteStatdn();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesAbsoluteScaleup*/  const int &Common_nb_tight_jesAbsoluteScaleup();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesAbsoluteScaledn*/  const int &Common_nb_tight_jesAbsoluteScaledn();
//---------------------------------------------------------------------------------
/*    Common_nb_tight_jesAbsoluteMPFBiasup*/  const int &Common_nb_tight_jesAbsoluteMPFBiasup();
//---------------------------------------------------------------------------------
/*    Common_nb_tight_jesAbsoluteMPFBiasdn*/  const int &Common_nb_tight_jesAbsoluteMPFBiasdn();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesFragmentationup*/  const int &Common_nb_tight_jesFragmentationup();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesFragmentationdn*/  const int &Common_nb_tight_jesFragmentationdn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesSinglePionECALup*/  const int &Common_nb_tight_jesSinglePionECALup();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesSinglePionECALdn*/  const int &Common_nb_tight_jesSinglePionECALdn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesSinglePionHCALup*/  const int &Common_nb_tight_jesSinglePionHCALup();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesSinglePionHCALdn*/  const int &Common_nb_tight_jesSinglePionHCALdn();
//---------------------------------------------------------------------------------
/*          Common_nb_tight_jesFlavorQCDup*/  const int &Common_nb_tight_jesFlavorQCDup();
//---------------------------------------------------------------------------------
/*          Common_nb_tight_jesFlavorQCDdn*/  const int &Common_nb_tight_jesFlavorQCDdn();
//---------------------------------------------------------------------------------
/*          Common_nb_tight_jesTimePtEtaup*/  const int &Common_nb_tight_jesTimePtEtaup();
//---------------------------------------------------------------------------------
/*          Common_nb_tight_jesTimePtEtadn*/  const int &Common_nb_tight_jesTimePtEtadn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeJEREC1up*/  const int &Common_nb_tight_jesRelativeJEREC1up();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeJEREC1dn*/  const int &Common_nb_tight_jesRelativeJEREC1dn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeJEREC2up*/  const int &Common_nb_tight_jesRelativeJEREC2up();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeJEREC2dn*/  const int &Common_nb_tight_jesRelativeJEREC2dn();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativeJERHFup*/  const int &Common_nb_tight_jesRelativeJERHFup();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativeJERHFdn*/  const int &Common_nb_tight_jesRelativeJERHFdn();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesRelativePtBBup*/  const int &Common_nb_tight_jesRelativePtBBup();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesRelativePtBBdn*/  const int &Common_nb_tight_jesRelativePtBBdn();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativePtEC1up*/  const int &Common_nb_tight_jesRelativePtEC1up();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativePtEC1dn*/  const int &Common_nb_tight_jesRelativePtEC1dn();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativePtEC2up*/  const int &Common_nb_tight_jesRelativePtEC2up();
//---------------------------------------------------------------------------------
/*      Common_nb_tight_jesRelativePtEC2dn*/  const int &Common_nb_tight_jesRelativePtEC2dn();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesRelativePtHFup*/  const int &Common_nb_tight_jesRelativePtHFup();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesRelativePtHFdn*/  const int &Common_nb_tight_jesRelativePtHFdn();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesRelativeBalup*/  const int &Common_nb_tight_jesRelativeBalup();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesRelativeBaldn*/  const int &Common_nb_tight_jesRelativeBaldn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeSampleup*/  const int &Common_nb_tight_jesRelativeSampleup();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeSampledn*/  const int &Common_nb_tight_jesRelativeSampledn();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesRelativeFSRup*/  const int &Common_nb_tight_jesRelativeFSRup();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesRelativeFSRdn*/  const int &Common_nb_tight_jesRelativeFSRdn();
//---------------------------------------------------------------------------------
/*    Common_nb_tight_jesRelativeStatFSRup*/  const int &Common_nb_tight_jesRelativeStatFSRup();
//---------------------------------------------------------------------------------
/*    Common_nb_tight_jesRelativeStatFSRdn*/  const int &Common_nb_tight_jesRelativeStatFSRdn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeStatECup*/  const int &Common_nb_tight_jesRelativeStatECup();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeStatECdn*/  const int &Common_nb_tight_jesRelativeStatECdn();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeStatHFup*/  const int &Common_nb_tight_jesRelativeStatHFup();
//---------------------------------------------------------------------------------
/*     Common_nb_tight_jesRelativeStatHFdn*/  const int &Common_nb_tight_jesRelativeStatHFdn();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesPileUpDataMCup*/  const int &Common_nb_tight_jesPileUpDataMCup();
//---------------------------------------------------------------------------------
/*       Common_nb_tight_jesPileUpDataMCdn*/  const int &Common_nb_tight_jesPileUpDataMCdn();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtRefup*/  const int &Common_nb_tight_jesPileUpPtRefup();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtRefdn*/  const int &Common_nb_tight_jesPileUpPtRefdn();
//---------------------------------------------------------------------------------
/*         Common_nb_tight_jesPileUpPtBBup*/  const int &Common_nb_tight_jesPileUpPtBBup();
//---------------------------------------------------------------------------------
/*         Common_nb_tight_jesPileUpPtBBdn*/  const int &Common_nb_tight_jesPileUpPtBBdn();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtEC1up*/  const int &Common_nb_tight_jesPileUpPtEC1up();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtEC1dn*/  const int &Common_nb_tight_jesPileUpPtEC1dn();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtEC2up*/  const int &Common_nb_tight_jesPileUpPtEC2up();
//---------------------------------------------------------------------------------
/*        Common_nb_tight_jesPileUpPtEC2dn*/  const int &Common_nb_tight_jesPileUpPtEC2dn();
//---------------------------------------------------------------------------------
/*         Common_nb_tight_jesPileUpPtHFup*/  const int &Common_nb_tight_jesPileUpPtHFup();
//---------------------------------------------------------------------------------
/*         Common_nb_tight_jesPileUpPtHFdn*/  const int &Common_nb_tight_jesPileUpPtHFdn();
//---------------------------------------------------------------------------------
/*                   Common_nb_tight_jesup*/  const int &Common_nb_tight_jesup();
//---------------------------------------------------------------------------------
/*                   Common_nb_tight_jesdn*/  const int &Common_nb_tight_jesdn();
//---------------------------------------------------------------------------------
/*                   Common_nb_tight_jerup*/  const int &Common_nb_tight_jerup();
//---------------------------------------------------------------------------------
/*                   Common_nb_tight_jerdn*/  const int &Common_nb_tight_jerdn();
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
/*                      SS2jet_raw_gen_idx*/  const vector<int> &SS2jet_raw_gen_idx();
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/  const bool &Cut_4LepMET_emuChannel();
//---------------------------------------------------------------------------------
/*               SS2jet_raw_gen_mother_idx*/  const vector<int> &SS2jet_raw_gen_mother_idx();
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/  const bool &Cut_4LepMET_offzChannel();
//---------------------------------------------------------------------------------
/*                SS2jet_raw_gen_mother_id*/  const vector<int> &SS2jet_raw_gen_mother_id();
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/  const bool &Cut_4LepMET_onzChannel();
//---------------------------------------------------------------------------------
/*                    SS2jet_raw_gen_pdgid*/  const vector<int> &SS2jet_raw_gen_pdgid();
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/  const bool &Cut_4LepMET_onzChannel_HighMET();
//---------------------------------------------------------------------------------
/*                      SS2jet_raw_gen_p4s*/  const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &SS2jet_raw_gen_p4s();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/  const int &Var_4LepMET_Zcand_lep_idx_0();
//---------------------------------------------------------------------------------
/*                   SS2jet_raw_gen_status*/  const vector<int> &SS2jet_raw_gen_status();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  const int &Var_4LepMET_Zcand_lep_pdgid_0();
//---------------------------------------------------------------------------------
/*              SS2jet_raw_gen_statusFlags*/  const vector<int> &SS2jet_raw_gen_statusFlags();
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
