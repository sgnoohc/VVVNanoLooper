#include "VVVTree.h"
VVVTree vvv;

void VVVTree::Init(TTree *tree) {
//---------------------------------------------------------------------------------
/*                           Common_met_p4*/  Common_met_p4_branch = tree->GetBranch("Common_met_p4");
/*                           Common_met_p4*/  if (Common_met_p4_branch) Common_met_p4_branch->SetAddress(&Common_met_p4_);
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesup*/  Common_met_p4_jesup_branch = tree->GetBranch("Common_met_p4_jesup");
/*                     Common_met_p4_jesup*/  if (Common_met_p4_jesup_branch) Common_met_p4_jesup_branch->SetAddress(&Common_met_p4_jesup_);
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesdn*/  Common_met_p4_jesdn_branch = tree->GetBranch("Common_met_p4_jesdn");
/*                     Common_met_p4_jesdn*/  if (Common_met_p4_jesdn_branch) Common_met_p4_jesdn_branch->SetAddress(&Common_met_p4_jesdn_);
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerup*/  Common_met_p4_jerup_branch = tree->GetBranch("Common_met_p4_jerup");
/*                     Common_met_p4_jerup*/  if (Common_met_p4_jerup_branch) Common_met_p4_jerup_branch->SetAddress(&Common_met_p4_jerup_);
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerdn*/  Common_met_p4_jerdn_branch = tree->GetBranch("Common_met_p4_jerdn");
/*                     Common_met_p4_jerdn*/  if (Common_met_p4_jerdn_branch) Common_met_p4_jerdn_branch->SetAddress(&Common_met_p4_jerdn_);
//---------------------------------------------------------------------------------
/*                           Common_lep_p4*/  Common_lep_p4_branch = tree->GetBranch("Common_lep_p4");
/*                           Common_lep_p4*/  if (Common_lep_p4_branch) Common_lep_p4_branch->SetAddress(&Common_lep_p4_);
//---------------------------------------------------------------------------------
/*                           Common_jet_p4*/  Common_jet_p4_branch = tree->GetBranch("Common_jet_p4");
/*                           Common_jet_p4*/  if (Common_jet_p4_branch) Common_jet_p4_branch->SetAddress(&Common_jet_p4_);
//---------------------------------------------------------------------------------
/*                        Common_fatjet_p4*/  Common_fatjet_p4_branch = tree->GetBranch("Common_fatjet_p4");
/*                        Common_fatjet_p4*/  if (Common_fatjet_p4_branch) Common_fatjet_p4_branch->SetAddress(&Common_fatjet_p4_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_p4*/  Common_fatjet_subjet0_p4_branch = tree->GetBranch("Common_fatjet_subjet0_p4");
/*                Common_fatjet_subjet0_p4*/  if (Common_fatjet_subjet0_p4_branch) Common_fatjet_subjet0_p4_branch->SetAddress(&Common_fatjet_subjet0_p4_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_p4*/  Common_fatjet_subjet1_p4_branch = tree->GetBranch("Common_fatjet_subjet1_p4");
/*                Common_fatjet_subjet1_p4*/  if (Common_fatjet_subjet1_p4_branch) Common_fatjet_subjet1_p4_branch->SetAddress(&Common_fatjet_subjet1_p4_);
//---------------------------------------------------------------------------------
/*                          Common_gen_p4s*/  Common_gen_p4s_branch = tree->GetBranch("Common_gen_p4s");
/*                          Common_gen_p4s*/  if (Common_gen_p4s_branch) Common_gen_p4s_branch->SetAddress(&Common_gen_p4s_);
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_p4s*/  Common_gen_vvvdecay_p4s_branch = tree->GetBranch("Common_gen_vvvdecay_p4s");
/*                 Common_gen_vvvdecay_p4s*/  if (Common_gen_vvvdecay_p4s_branch) Common_gen_vvvdecay_p4s_branch->SetAddress(&Common_gen_vvvdecay_p4s_);
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_0*/  Var_4LepMET_Zcand_lep_p4_0_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_p4_0");
/*              Var_4LepMET_Zcand_lep_p4_0*/  if (Var_4LepMET_Zcand_lep_p4_0_branch) Var_4LepMET_Zcand_lep_p4_0_branch->SetAddress(&Var_4LepMET_Zcand_lep_p4_0_);
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_1*/  Var_4LepMET_Zcand_lep_p4_1_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_p4_1");
/*              Var_4LepMET_Zcand_lep_p4_1*/  if (Var_4LepMET_Zcand_lep_p4_1_branch) Var_4LepMET_Zcand_lep_p4_1_branch->SetAddress(&Var_4LepMET_Zcand_lep_p4_1_);
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_0*/  Var_4LepMET_other_lep_p4_0_branch = tree->GetBranch("Var_4LepMET_other_lep_p4_0");
/*              Var_4LepMET_other_lep_p4_0*/  if (Var_4LepMET_other_lep_p4_0_branch) Var_4LepMET_other_lep_p4_0_branch->SetAddress(&Var_4LepMET_other_lep_p4_0_);
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_1*/  Var_4LepMET_other_lep_p4_1_branch = tree->GetBranch("Var_4LepMET_other_lep_p4_1");
/*              Var_4LepMET_other_lep_p4_1*/  if (Var_4LepMET_other_lep_p4_1_branch) Var_4LepMET_other_lep_p4_1_branch->SetAddress(&Var_4LepMET_other_lep_p4_1_);
//---------------------------------------------------------------------------------

  tree->SetMakeClass(1);

//---------------------------------------------------------------------------------
/*                           Common_isData*/  Common_isData_branch = tree->GetBranch("Common_isData");
/*                           Common_isData*/  if (Common_isData_branch) Common_isData_branch->SetAddress(&Common_isData_);
//---------------------------------------------------------------------------------
/*                              Common_run*/  Common_run_branch = tree->GetBranch("Common_run");
/*                              Common_run*/  if (Common_run_branch) Common_run_branch->SetAddress(&Common_run_);
//---------------------------------------------------------------------------------
/*                             Common_lumi*/  Common_lumi_branch = tree->GetBranch("Common_lumi");
/*                             Common_lumi*/  if (Common_lumi_branch) Common_lumi_branch->SetAddress(&Common_lumi_);
//---------------------------------------------------------------------------------
/*                              Common_evt*/  Common_evt_branch = tree->GetBranch("Common_evt");
/*                              Common_evt*/  if (Common_evt_branch) Common_evt_branch->SetAddress(&Common_evt_);
//---------------------------------------------------------------------------------
/*                        Common_genWeight*/  Common_genWeight_branch = tree->GetBranch("Common_genWeight");
/*                        Common_genWeight*/  if (Common_genWeight_branch) Common_genWeight_branch->SetAddress(&Common_genWeight_);
//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/  Common_btagWeight_DeepCSVB_branch = tree->GetBranch("Common_btagWeight_DeepCSVB");
/*              Common_btagWeight_DeepCSVB*/  if (Common_btagWeight_DeepCSVB_branch) Common_btagWeight_DeepCSVB_branch->SetAddress(&Common_btagWeight_DeepCSVB_);
//---------------------------------------------------------------------------------
/*                              Common_wgt*/  Common_wgt_branch = tree->GetBranch("Common_wgt");
/*                              Common_wgt*/  if (Common_wgt_branch) Common_wgt_branch->SetAddress(&Common_wgt_);
//---------------------------------------------------------------------------------
/*         Common_LHEWeight_mg_reweighting*/  Common_LHEWeight_mg_reweighting_branch = tree->GetBranch("Common_LHEWeight_mg_reweighting");
/*         Common_LHEWeight_mg_reweighting*/  if (Common_LHEWeight_mg_reweighting_branch) Common_LHEWeight_mg_reweighting_branch->SetAddress(&Common_LHEWeight_mg_reweighting_);
//---------------------------------------------------------------------------------
/*                   Common_event_puWeight*/  Common_event_puWeight_branch = tree->GetBranch("Common_event_puWeight");
/*                   Common_event_puWeight*/  if (Common_event_puWeight_branch) Common_event_puWeight_branch->SetAddress(&Common_event_puWeight_);
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightup*/  Common_event_puWeightup_branch = tree->GetBranch("Common_event_puWeightup");
/*                 Common_event_puWeightup*/  if (Common_event_puWeightup_branch) Common_event_puWeightup_branch->SetAddress(&Common_event_puWeightup_);
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightdn*/  Common_event_puWeightdn_branch = tree->GetBranch("Common_event_puWeightdn");
/*                 Common_event_puWeightdn*/  if (Common_event_puWeightdn_branch) Common_event_puWeightdn_branch->SetAddress(&Common_event_puWeightdn_);
//---------------------------------------------------------------------------------
/*              Common_event_prefireWeight*/  Common_event_prefireWeight_branch = tree->GetBranch("Common_event_prefireWeight");
/*              Common_event_prefireWeight*/  if (Common_event_prefireWeight_branch) Common_event_prefireWeight_branch->SetAddress(&Common_event_prefireWeight_);
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightup*/  Common_event_prefireWeightup_branch = tree->GetBranch("Common_event_prefireWeightup");
/*            Common_event_prefireWeightup*/  if (Common_event_prefireWeightup_branch) Common_event_prefireWeightup_branch->SetAddress(&Common_event_prefireWeightup_);
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightdn*/  Common_event_prefireWeightdn_branch = tree->GetBranch("Common_event_prefireWeightdn");
/*            Common_event_prefireWeightdn*/  if (Common_event_prefireWeightdn_branch) Common_event_prefireWeightdn_branch->SetAddress(&Common_event_prefireWeightdn_);
//---------------------------------------------------------------------------------
/*              Common_event_triggerWeight*/  Common_event_triggerWeight_branch = tree->GetBranch("Common_event_triggerWeight");
/*              Common_event_triggerWeight*/  if (Common_event_triggerWeight_branch) Common_event_triggerWeight_branch->SetAddress(&Common_event_triggerWeight_);
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightup*/  Common_event_triggerWeightup_branch = tree->GetBranch("Common_event_triggerWeightup");
/*            Common_event_triggerWeightup*/  if (Common_event_triggerWeightup_branch) Common_event_triggerWeightup_branch->SetAddress(&Common_event_triggerWeightup_);
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightdn*/  Common_event_triggerWeightdn_branch = tree->GetBranch("Common_event_triggerWeightdn");
/*            Common_event_triggerWeightdn*/  if (Common_event_triggerWeightdn_branch) Common_event_triggerWeightdn_branch->SetAddress(&Common_event_triggerWeightdn_);
//---------------------------------------------------------------------------------
/*             Common_LHEReweightingWeight*/  Common_LHEReweightingWeight_branch = tree->GetBranch("Common_LHEReweightingWeight");
/*             Common_LHEReweightingWeight*/  if (Common_LHEReweightingWeight_branch) Common_LHEReweightingWeight_branch->SetAddress(&Common_LHEReweightingWeight_);
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch = tree->GetBranch("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ");
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch->SetAddress(&Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_);
//---------------------------------------------------------------------------------
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch = tree->GetBranch("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL");
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch->SetAddress(&Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_);
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch = tree->GetBranch("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8");
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch->SetAddress(&Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_);
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch = tree->GetBranch("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch->SetAddress(&Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_);
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch = tree->GetBranch("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL");
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch->SetAddress(&Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_);
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch = tree->GetBranch("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch->SetAddress(&Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_);
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch = tree->GetBranch("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL");
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch->SetAddress(&Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_);
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch = tree->GetBranch("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ");
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch->SetAddress(&Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_);
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch = tree->GetBranch("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL");
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch->SetAddress(&Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_);
//---------------------------------------------------------------------------------
/*                      Common_HLT_IsoMu24*/  Common_HLT_IsoMu24_branch = tree->GetBranch("Common_HLT_IsoMu24");
/*                      Common_HLT_IsoMu24*/  if (Common_HLT_IsoMu24_branch) Common_HLT_IsoMu24_branch->SetAddress(&Common_HLT_IsoMu24_);
//---------------------------------------------------------------------------------
/*                Common_HLT_Ele32_WPTight*/  Common_HLT_Ele32_WPTight_branch = tree->GetBranch("Common_HLT_Ele32_WPTight");
/*                Common_HLT_Ele32_WPTight*/  if (Common_HLT_Ele32_WPTight_branch) Common_HLT_Ele32_WPTight_branch->SetAddress(&Common_HLT_Ele32_WPTight_);
//---------------------------------------------------------------------------------
/*                     Common_HLT_PFHT1050*/  Common_HLT_PFHT1050_branch = tree->GetBranch("Common_HLT_PFHT1050");
/*                     Common_HLT_PFHT1050*/  if (Common_HLT_PFHT1050_branch) Common_HLT_PFHT1050_branch->SetAddress(&Common_HLT_PFHT1050_);
//---------------------------------------------------------------------------------
/*                  Common_HLT_AK8PFJet500*/  Common_HLT_AK8PFJet500_branch = tree->GetBranch("Common_HLT_AK8PFJet500");
/*                  Common_HLT_AK8PFJet500*/  if (Common_HLT_AK8PFJet500_branch) Common_HLT_AK8PFJet500_branch->SetAddress(&Common_HLT_AK8PFJet500_);
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet380_TrimMass30*/  Common_HLT_AK8PFJet380_TrimMass30_branch = tree->GetBranch("Common_HLT_AK8PFJet380_TrimMass30");
/*       Common_HLT_AK8PFJet380_TrimMass30*/  if (Common_HLT_AK8PFJet380_TrimMass30_branch) Common_HLT_AK8PFJet380_TrimMass30_branch->SetAddress(&Common_HLT_AK8PFJet380_TrimMass30_);
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet360_TrimMass30*/  Common_HLT_AK8PFJet360_TrimMass30_branch = tree->GetBranch("Common_HLT_AK8PFJet360_TrimMass30");
/*       Common_HLT_AK8PFJet360_TrimMass30*/  if (Common_HLT_AK8PFJet360_TrimMass30_branch) Common_HLT_AK8PFJet360_TrimMass30_branch->SetAddress(&Common_HLT_AK8PFJet360_TrimMass30_);
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet400_TrimMass30*/  Common_HLT_AK8PFJet400_TrimMass30_branch = tree->GetBranch("Common_HLT_AK8PFJet400_TrimMass30");
/*       Common_HLT_AK8PFJet400_TrimMass30*/  if (Common_HLT_AK8PFJet400_TrimMass30_branch) Common_HLT_AK8PFJet400_TrimMass30_branch->SetAddress(&Common_HLT_AK8PFJet400_TrimMass30_);
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet420_TrimMass30*/  Common_HLT_AK8PFJet420_TrimMass30_branch = tree->GetBranch("Common_HLT_AK8PFJet420_TrimMass30");
/*       Common_HLT_AK8PFJet420_TrimMass30*/  if (Common_HLT_AK8PFJet420_TrimMass30_branch) Common_HLT_AK8PFJet420_TrimMass30_branch->SetAddress(&Common_HLT_AK8PFJet420_TrimMass30_);
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT750_TrimMass50*/  Common_HLT_AK8PFHT750_TrimMass50_branch = tree->GetBranch("Common_HLT_AK8PFHT750_TrimMass50");
/*        Common_HLT_AK8PFHT750_TrimMass50*/  if (Common_HLT_AK8PFHT750_TrimMass50_branch) Common_HLT_AK8PFHT750_TrimMass50_branch->SetAddress(&Common_HLT_AK8PFHT750_TrimMass50_);
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT800_TrimMass50*/  Common_HLT_AK8PFHT800_TrimMass50_branch = tree->GetBranch("Common_HLT_AK8PFHT800_TrimMass50");
/*        Common_HLT_AK8PFHT800_TrimMass50*/  if (Common_HLT_AK8PFHT800_TrimMass50_branch) Common_HLT_AK8PFHT800_TrimMass50_branch->SetAddress(&Common_HLT_AK8PFHT800_TrimMass50_);
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT850_TrimMass50*/  Common_HLT_AK8PFHT850_TrimMass50_branch = tree->GetBranch("Common_HLT_AK8PFHT850_TrimMass50");
/*        Common_HLT_AK8PFHT850_TrimMass50*/  if (Common_HLT_AK8PFHT850_TrimMass50_branch) Common_HLT_AK8PFHT850_TrimMass50_branch->SetAddress(&Common_HLT_AK8PFHT850_TrimMass50_);
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT900_TrimMass50*/  Common_HLT_AK8PFHT900_TrimMass50_branch = tree->GetBranch("Common_HLT_AK8PFHT900_TrimMass50");
/*        Common_HLT_AK8PFHT900_TrimMass50*/  if (Common_HLT_AK8PFHT900_TrimMass50_branch) Common_HLT_AK8PFHT900_TrimMass50_branch->SetAddress(&Common_HLT_AK8PFHT900_TrimMass50_);
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleEl*/  Common_HLT_DoubleEl_branch = tree->GetBranch("Common_HLT_DoubleEl");
/*                     Common_HLT_DoubleEl*/  if (Common_HLT_DoubleEl_branch) Common_HLT_DoubleEl_branch->SetAddress(&Common_HLT_DoubleEl_);
//---------------------------------------------------------------------------------
/*                         Common_HLT_MuEG*/  Common_HLT_MuEG_branch = tree->GetBranch("Common_HLT_MuEG");
/*                         Common_HLT_MuEG*/  if (Common_HLT_MuEG_branch) Common_HLT_MuEG_branch->SetAddress(&Common_HLT_MuEG_);
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleMu*/  Common_HLT_DoubleMu_branch = tree->GetBranch("Common_HLT_DoubleMu");
/*                     Common_HLT_DoubleMu*/  if (Common_HLT_DoubleMu_branch) Common_HLT_DoubleMu_branch->SetAddress(&Common_HLT_DoubleMu_);
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_ee_em_mm*/  Common_pass_duplicate_removal_ee_em_mm_branch = tree->GetBranch("Common_pass_duplicate_removal_ee_em_mm");
/*  Common_pass_duplicate_removal_ee_em_mm*/  if (Common_pass_duplicate_removal_ee_em_mm_branch) Common_pass_duplicate_removal_ee_em_mm_branch->SetAddress(&Common_pass_duplicate_removal_ee_em_mm_);
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_mm_em_ee*/  Common_pass_duplicate_removal_mm_em_ee_branch = tree->GetBranch("Common_pass_duplicate_removal_mm_em_ee");
/*  Common_pass_duplicate_removal_mm_em_ee*/  if (Common_pass_duplicate_removal_mm_em_ee_branch) Common_pass_duplicate_removal_mm_em_ee_branch->SetAddress(&Common_pass_duplicate_removal_mm_em_ee_);
//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/  Common_noiseFlag_branch = tree->GetBranch("Common_noiseFlag");
/*                        Common_noiseFlag*/  if (Common_noiseFlag_branch) Common_noiseFlag_branch->SetAddress(&Common_noiseFlag_);
//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/  Common_noiseFlagMC_branch = tree->GetBranch("Common_noiseFlagMC");
/*                      Common_noiseFlagMC*/  if (Common_noiseFlagMC_branch) Common_noiseFlagMC_branch->SetAddress(&Common_noiseFlagMC_);
//---------------------------------------------------------------------------------
/*                      Common_passGoodRun*/  Common_passGoodRun_branch = tree->GetBranch("Common_passGoodRun");
/*                      Common_passGoodRun*/  if (Common_passGoodRun_branch) Common_passGoodRun_branch->SetAddress(&Common_passGoodRun_);
//---------------------------------------------------------------------------------
/*                      Common_event_lepSF*/  Common_event_lepSF_branch = tree->GetBranch("Common_event_lepSF");
/*                      Common_event_lepSF*/  if (Common_event_lepSF_branch) Common_event_lepSF_branch->SetAddress(&Common_event_lepSF_);
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFelup*/  Common_event_lepSFelup_branch = tree->GetBranch("Common_event_lepSFelup");
/*                  Common_event_lepSFelup*/  if (Common_event_lepSFelup_branch) Common_event_lepSFelup_branch->SetAddress(&Common_event_lepSFelup_);
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFeldn*/  Common_event_lepSFeldn_branch = tree->GetBranch("Common_event_lepSFeldn");
/*                  Common_event_lepSFeldn*/  if (Common_event_lepSFeldn_branch) Common_event_lepSFeldn_branch->SetAddress(&Common_event_lepSFeldn_);
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmuup*/  Common_event_lepSFmuup_branch = tree->GetBranch("Common_event_lepSFmuup");
/*                  Common_event_lepSFmuup*/  if (Common_event_lepSFmuup_branch) Common_event_lepSFmuup_branch->SetAddress(&Common_event_lepSFmuup_);
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmudn*/  Common_event_lepSFmudn_branch = tree->GetBranch("Common_event_lepSFmudn");
/*                  Common_event_lepSFmudn*/  if (Common_event_lepSFmudn_branch) Common_event_lepSFmudn_branch->SetAddress(&Common_event_lepSFmudn_);
//---------------------------------------------------------------------------------
/*                 Common_event_lepSFTight*/  Common_event_lepSFTight_branch = tree->GetBranch("Common_event_lepSFTight");
/*                 Common_event_lepSFTight*/  if (Common_event_lepSFTight_branch) Common_event_lepSFTight_branch->SetAddress(&Common_event_lepSFTight_);
//---------------------------------------------------------------------------------
/*             Common_event_lepSFelupTight*/  Common_event_lepSFelupTight_branch = tree->GetBranch("Common_event_lepSFelupTight");
/*             Common_event_lepSFelupTight*/  if (Common_event_lepSFelupTight_branch) Common_event_lepSFelupTight_branch->SetAddress(&Common_event_lepSFelupTight_);
//---------------------------------------------------------------------------------
/*             Common_event_lepSFeldnTight*/  Common_event_lepSFeldnTight_branch = tree->GetBranch("Common_event_lepSFeldnTight");
/*             Common_event_lepSFeldnTight*/  if (Common_event_lepSFeldnTight_branch) Common_event_lepSFeldnTight_branch->SetAddress(&Common_event_lepSFeldnTight_);
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmuupTight*/  Common_event_lepSFmuupTight_branch = tree->GetBranch("Common_event_lepSFmuupTight");
/*             Common_event_lepSFmuupTight*/  if (Common_event_lepSFmuupTight_branch) Common_event_lepSFmuupTight_branch->SetAddress(&Common_event_lepSFmuupTight_);
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmudnTight*/  Common_event_lepSFmudnTight_branch = tree->GetBranch("Common_event_lepSFmudnTight");
/*             Common_event_lepSFmudnTight*/  if (Common_event_lepSFmudnTight_branch) Common_event_lepSFmudnTight_branch->SetAddress(&Common_event_lepSFmudnTight_);
//---------------------------------------------------------------------------------
/*                Common_event_tightBtagSF*/  Common_event_tightBtagSF_branch = tree->GetBranch("Common_event_tightBtagSF");
/*                Common_event_tightBtagSF*/  if (Common_event_tightBtagSF_branch) Common_event_tightBtagSF_branch->SetAddress(&Common_event_tightBtagSF_);
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFup*/  Common_event_tightBtagSFup_branch = tree->GetBranch("Common_event_tightBtagSFup");
/*              Common_event_tightBtagSFup*/  if (Common_event_tightBtagSFup_branch) Common_event_tightBtagSFup_branch->SetAddress(&Common_event_tightBtagSFup_);
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFdn*/  Common_event_tightBtagSFdn_branch = tree->GetBranch("Common_event_tightBtagSFdn");
/*              Common_event_tightBtagSFdn*/  if (Common_event_tightBtagSFdn_branch) Common_event_tightBtagSFdn_branch->SetAddress(&Common_event_tightBtagSFdn_);
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFup*/  Common_event_tightBtagSFHFup_branch = tree->GetBranch("Common_event_tightBtagSFHFup");
/*            Common_event_tightBtagSFHFup*/  if (Common_event_tightBtagSFHFup_branch) Common_event_tightBtagSFHFup_branch->SetAddress(&Common_event_tightBtagSFHFup_);
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFdn*/  Common_event_tightBtagSFHFdn_branch = tree->GetBranch("Common_event_tightBtagSFHFdn");
/*            Common_event_tightBtagSFHFdn*/  if (Common_event_tightBtagSFHFdn_branch) Common_event_tightBtagSFHFdn_branch->SetAddress(&Common_event_tightBtagSFHFdn_);
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFup*/  Common_event_tightBtagSFLFup_branch = tree->GetBranch("Common_event_tightBtagSFLFup");
/*            Common_event_tightBtagSFLFup*/  if (Common_event_tightBtagSFLFup_branch) Common_event_tightBtagSFLFup_branch->SetAddress(&Common_event_tightBtagSFLFup_);
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFdn*/  Common_event_tightBtagSFLFdn_branch = tree->GetBranch("Common_event_tightBtagSFLFdn");
/*            Common_event_tightBtagSFLFdn*/  if (Common_event_tightBtagSFLFdn_branch) Common_event_tightBtagSFLFdn_branch->SetAddress(&Common_event_tightBtagSFLFdn_);
//---------------------------------------------------------------------------------
/*               Common_event_mediumBtagSF*/  Common_event_mediumBtagSF_branch = tree->GetBranch("Common_event_mediumBtagSF");
/*               Common_event_mediumBtagSF*/  if (Common_event_mediumBtagSF_branch) Common_event_mediumBtagSF_branch->SetAddress(&Common_event_mediumBtagSF_);
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFup*/  Common_event_mediumBtagSFup_branch = tree->GetBranch("Common_event_mediumBtagSFup");
/*             Common_event_mediumBtagSFup*/  if (Common_event_mediumBtagSFup_branch) Common_event_mediumBtagSFup_branch->SetAddress(&Common_event_mediumBtagSFup_);
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFdn*/  Common_event_mediumBtagSFdn_branch = tree->GetBranch("Common_event_mediumBtagSFdn");
/*             Common_event_mediumBtagSFdn*/  if (Common_event_mediumBtagSFdn_branch) Common_event_mediumBtagSFdn_branch->SetAddress(&Common_event_mediumBtagSFdn_);
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFup*/  Common_event_mediumBtagSFHFup_branch = tree->GetBranch("Common_event_mediumBtagSFHFup");
/*           Common_event_mediumBtagSFHFup*/  if (Common_event_mediumBtagSFHFup_branch) Common_event_mediumBtagSFHFup_branch->SetAddress(&Common_event_mediumBtagSFHFup_);
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFdn*/  Common_event_mediumBtagSFHFdn_branch = tree->GetBranch("Common_event_mediumBtagSFHFdn");
/*           Common_event_mediumBtagSFHFdn*/  if (Common_event_mediumBtagSFHFdn_branch) Common_event_mediumBtagSFHFdn_branch->SetAddress(&Common_event_mediumBtagSFHFdn_);
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFup*/  Common_event_mediumBtagSFLFup_branch = tree->GetBranch("Common_event_mediumBtagSFLFup");
/*           Common_event_mediumBtagSFLFup*/  if (Common_event_mediumBtagSFLFup_branch) Common_event_mediumBtagSFLFup_branch->SetAddress(&Common_event_mediumBtagSFLFup_);
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFdn*/  Common_event_mediumBtagSFLFdn_branch = tree->GetBranch("Common_event_mediumBtagSFLFdn");
/*           Common_event_mediumBtagSFLFdn*/  if (Common_event_mediumBtagSFLFdn_branch) Common_event_mediumBtagSFLFdn_branch->SetAddress(&Common_event_mediumBtagSFLFdn_);
//---------------------------------------------------------------------------------
/*                Common_event_looseBtagSF*/  Common_event_looseBtagSF_branch = tree->GetBranch("Common_event_looseBtagSF");
/*                Common_event_looseBtagSF*/  if (Common_event_looseBtagSF_branch) Common_event_looseBtagSF_branch->SetAddress(&Common_event_looseBtagSF_);
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFup*/  Common_event_looseBtagSFup_branch = tree->GetBranch("Common_event_looseBtagSFup");
/*              Common_event_looseBtagSFup*/  if (Common_event_looseBtagSFup_branch) Common_event_looseBtagSFup_branch->SetAddress(&Common_event_looseBtagSFup_);
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFdn*/  Common_event_looseBtagSFdn_branch = tree->GetBranch("Common_event_looseBtagSFdn");
/*              Common_event_looseBtagSFdn*/  if (Common_event_looseBtagSFdn_branch) Common_event_looseBtagSFdn_branch->SetAddress(&Common_event_looseBtagSFdn_);
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFup*/  Common_event_looseBtagSFHFup_branch = tree->GetBranch("Common_event_looseBtagSFHFup");
/*            Common_event_looseBtagSFHFup*/  if (Common_event_looseBtagSFHFup_branch) Common_event_looseBtagSFHFup_branch->SetAddress(&Common_event_looseBtagSFHFup_);
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFdn*/  Common_event_looseBtagSFHFdn_branch = tree->GetBranch("Common_event_looseBtagSFHFdn");
/*            Common_event_looseBtagSFHFdn*/  if (Common_event_looseBtagSFHFdn_branch) Common_event_looseBtagSFHFdn_branch->SetAddress(&Common_event_looseBtagSFHFdn_);
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFup*/  Common_event_looseBtagSFLFup_branch = tree->GetBranch("Common_event_looseBtagSFLFup");
/*            Common_event_looseBtagSFLFup*/  if (Common_event_looseBtagSFLFup_branch) Common_event_looseBtagSFLFup_branch->SetAddress(&Common_event_looseBtagSFLFup_);
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFdn*/  Common_event_looseBtagSFLFdn_branch = tree->GetBranch("Common_event_looseBtagSFLFdn");
/*            Common_event_looseBtagSFLFdn*/  if (Common_event_looseBtagSFLFdn_branch) Common_event_looseBtagSFLFdn_branch->SetAddress(&Common_event_looseBtagSFLFdn_);
//---------------------------------------------------------------------------------
/*                         Common_lep_idxs*/  Common_lep_idxs_branch = tree->GetBranch("Common_lep_idxs");
/*                         Common_lep_idxs*/  if (Common_lep_idxs_branch) Common_lep_idxs_branch->SetAddress(&Common_lep_idxs_);
//---------------------------------------------------------------------------------
/*                        Common_lep_pdgid*/  Common_lep_pdgid_branch = tree->GetBranch("Common_lep_pdgid");
/*                        Common_lep_pdgid*/  if (Common_lep_pdgid_branch) Common_lep_pdgid_branch->SetAddress(&Common_lep_pdgid_);
//---------------------------------------------------------------------------------
/*                        Common_lep_tight*/  Common_lep_tight_branch = tree->GetBranch("Common_lep_tight");
/*                        Common_lep_tight*/  if (Common_lep_tight_branch) Common_lep_tight_branch->SetAddress(&Common_lep_tight_);
//---------------------------------------------------------------------------------
/*                          Common_lep_dxy*/  Common_lep_dxy_branch = tree->GetBranch("Common_lep_dxy");
/*                          Common_lep_dxy*/  if (Common_lep_dxy_branch) Common_lep_dxy_branch->SetAddress(&Common_lep_dxy_);
//---------------------------------------------------------------------------------
/*                           Common_lep_dz*/  Common_lep_dz_branch = tree->GetBranch("Common_lep_dz");
/*                           Common_lep_dz*/  if (Common_lep_dz_branch) Common_lep_dz_branch->SetAddress(&Common_lep_dz_);
//---------------------------------------------------------------------------------
/*                         Common_lep_ip3d*/  Common_lep_ip3d_branch = tree->GetBranch("Common_lep_ip3d");
/*                         Common_lep_ip3d*/  if (Common_lep_ip3d_branch) Common_lep_ip3d_branch->SetAddress(&Common_lep_ip3d_);
//---------------------------------------------------------------------------------
/*                        Common_lep_sip3d*/  Common_lep_sip3d_branch = tree->GetBranch("Common_lep_sip3d");
/*                        Common_lep_sip3d*/  if (Common_lep_sip3d_branch) Common_lep_sip3d_branch->SetAddress(&Common_lep_sip3d_);
//---------------------------------------------------------------------------------
/*                           Common_lep_SF*/  Common_lep_SF_branch = tree->GetBranch("Common_lep_SF");
/*                           Common_lep_SF*/  if (Common_lep_SF_branch) Common_lep_SF_branch->SetAddress(&Common_lep_SF_);
//---------------------------------------------------------------------------------
/*                      Common_lep_SFTight*/  Common_lep_SFTight_branch = tree->GetBranch("Common_lep_SFTight");
/*                      Common_lep_SFTight*/  if (Common_lep_SFTight_branch) Common_lep_SFTight_branch->SetAddress(&Common_lep_SFTight_);
//---------------------------------------------------------------------------------
/*                         Common_lep_SFdn*/  Common_lep_SFdn_branch = tree->GetBranch("Common_lep_SFdn");
/*                         Common_lep_SFdn*/  if (Common_lep_SFdn_branch) Common_lep_SFdn_branch->SetAddress(&Common_lep_SFdn_);
//---------------------------------------------------------------------------------
/*                    Common_lep_SFdnTight*/  Common_lep_SFdnTight_branch = tree->GetBranch("Common_lep_SFdnTight");
/*                    Common_lep_SFdnTight*/  if (Common_lep_SFdnTight_branch) Common_lep_SFdnTight_branch->SetAddress(&Common_lep_SFdnTight_);
//---------------------------------------------------------------------------------
/*                         Common_lep_SFup*/  Common_lep_SFup_branch = tree->GetBranch("Common_lep_SFup");
/*                         Common_lep_SFup*/  if (Common_lep_SFup_branch) Common_lep_SFup_branch->SetAddress(&Common_lep_SFup_);
//---------------------------------------------------------------------------------
/*                    Common_lep_SFupTight*/  Common_lep_SFupTight_branch = tree->GetBranch("Common_lep_SFupTight");
/*                    Common_lep_SFupTight*/  if (Common_lep_SFupTight_branch) Common_lep_SFupTight_branch->SetAddress(&Common_lep_SFupTight_);
//---------------------------------------------------------------------------------
/*                         Common_jet_idxs*/  Common_jet_idxs_branch = tree->GetBranch("Common_jet_idxs");
/*                         Common_jet_idxs*/  if (Common_jet_idxs_branch) Common_jet_idxs_branch->SetAddress(&Common_jet_idxs_);
//---------------------------------------------------------------------------------
/*                   Common_jet_passBloose*/  Common_jet_passBloose_branch = tree->GetBranch("Common_jet_passBloose");
/*                   Common_jet_passBloose*/  if (Common_jet_passBloose_branch) Common_jet_passBloose_branch->SetAddress(&Common_jet_passBloose_);
//---------------------------------------------------------------------------------
/*                  Common_jet_passBmedium*/  Common_jet_passBmedium_branch = tree->GetBranch("Common_jet_passBmedium");
/*                  Common_jet_passBmedium*/  if (Common_jet_passBmedium_branch) Common_jet_passBmedium_branch->SetAddress(&Common_jet_passBmedium_);
//---------------------------------------------------------------------------------
/*                   Common_jet_passBtight*/  Common_jet_passBtight_branch = tree->GetBranch("Common_jet_passBtight");
/*                   Common_jet_passBtight*/  if (Common_jet_passBtight_branch) Common_jet_passBtight_branch->SetAddress(&Common_jet_passBtight_);
//---------------------------------------------------------------------------------
/*                           Common_jet_id*/  Common_jet_id_branch = tree->GetBranch("Common_jet_id");
/*                           Common_jet_id*/  if (Common_jet_id_branch) Common_jet_id_branch->SetAddress(&Common_jet_id_);
//---------------------------------------------------------------------------------
/*                Common_jet_overlapfatjet*/  Common_jet_overlapfatjet_branch = tree->GetBranch("Common_jet_overlapfatjet");
/*                Common_jet_overlapfatjet*/  if (Common_jet_overlapfatjet_branch) Common_jet_overlapfatjet_branch->SetAddress(&Common_jet_overlapfatjet_);
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesup*/  Common_jet_pt_jesup_branch = tree->GetBranch("Common_jet_pt_jesup");
/*                     Common_jet_pt_jesup*/  if (Common_jet_pt_jesup_branch) Common_jet_pt_jesup_branch->SetAddress(&Common_jet_pt_jesup_);
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesdn*/  Common_jet_pt_jesdn_branch = tree->GetBranch("Common_jet_pt_jesdn");
/*                     Common_jet_pt_jesdn*/  if (Common_jet_pt_jesdn_branch) Common_jet_pt_jesdn_branch->SetAddress(&Common_jet_pt_jesdn_);
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerup*/  Common_jet_pt_jerup_branch = tree->GetBranch("Common_jet_pt_jerup");
/*                     Common_jet_pt_jerup*/  if (Common_jet_pt_jerup_branch) Common_jet_pt_jerup_branch->SetAddress(&Common_jet_pt_jerup_);
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerdn*/  Common_jet_pt_jerdn_branch = tree->GetBranch("Common_jet_pt_jerdn");
/*                     Common_jet_pt_jerdn*/  if (Common_jet_pt_jerdn_branch) Common_jet_pt_jerdn_branch->SetAddress(&Common_jet_pt_jerdn_);
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesup*/  Common_jet_mass_jesup_branch = tree->GetBranch("Common_jet_mass_jesup");
/*                   Common_jet_mass_jesup*/  if (Common_jet_mass_jesup_branch) Common_jet_mass_jesup_branch->SetAddress(&Common_jet_mass_jesup_);
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesdn*/  Common_jet_mass_jesdn_branch = tree->GetBranch("Common_jet_mass_jesdn");
/*                   Common_jet_mass_jesdn*/  if (Common_jet_mass_jesdn_branch) Common_jet_mass_jesdn_branch->SetAddress(&Common_jet_mass_jesdn_);
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerup*/  Common_jet_mass_jerup_branch = tree->GetBranch("Common_jet_mass_jerup");
/*                   Common_jet_mass_jerup*/  if (Common_jet_mass_jerup_branch) Common_jet_mass_jerup_branch->SetAddress(&Common_jet_mass_jerup_);
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerdn*/  Common_jet_mass_jerdn_branch = tree->GetBranch("Common_jet_mass_jerdn");
/*                   Common_jet_mass_jerdn*/  if (Common_jet_mass_jerdn_branch) Common_jet_mass_jerdn_branch->SetAddress(&Common_jet_mass_jerdn_);
//---------------------------------------------------------------------------------
/*                      Common_fatjet_idxs*/  Common_fatjet_idxs_branch = tree->GetBranch("Common_fatjet_idxs");
/*                      Common_fatjet_idxs*/  if (Common_fatjet_idxs_branch) Common_fatjet_idxs_branch->SetAddress(&Common_fatjet_idxs_);
//---------------------------------------------------------------------------------
/*                        Common_fatjet_id*/  Common_fatjet_id_branch = tree->GetBranch("Common_fatjet_id");
/*                        Common_fatjet_id*/  if (Common_fatjet_id_branch) Common_fatjet_id_branch->SetAddress(&Common_fatjet_id_);
//---------------------------------------------------------------------------------
/*                 Common_fatjet_msoftdrop*/  Common_fatjet_msoftdrop_branch = tree->GetBranch("Common_fatjet_msoftdrop");
/*                 Common_fatjet_msoftdrop*/  if (Common_fatjet_msoftdrop_branch) Common_fatjet_msoftdrop_branch->SetAddress(&Common_fatjet_msoftdrop_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_W*/  Common_fatjet_deepMD_W_branch = tree->GetBranch("Common_fatjet_deepMD_W");
/*                  Common_fatjet_deepMD_W*/  if (Common_fatjet_deepMD_W_branch) Common_fatjet_deepMD_W_branch->SetAddress(&Common_fatjet_deepMD_W_);
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_W*/  Common_fatjet_deep_W_branch = tree->GetBranch("Common_fatjet_deep_W");
/*                    Common_fatjet_deep_W*/  if (Common_fatjet_deep_W_branch) Common_fatjet_deep_W_branch->SetAddress(&Common_fatjet_deep_W_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_Z*/  Common_fatjet_deepMD_Z_branch = tree->GetBranch("Common_fatjet_deepMD_Z");
/*                  Common_fatjet_deepMD_Z*/  if (Common_fatjet_deepMD_Z_branch) Common_fatjet_deepMD_Z_branch->SetAddress(&Common_fatjet_deepMD_Z_);
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_Z*/  Common_fatjet_deep_Z_branch = tree->GetBranch("Common_fatjet_deep_Z");
/*                    Common_fatjet_deep_Z*/  if (Common_fatjet_deep_Z_branch) Common_fatjet_deep_Z_branch->SetAddress(&Common_fatjet_deep_Z_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_T*/  Common_fatjet_deepMD_T_branch = tree->GetBranch("Common_fatjet_deepMD_T");
/*                  Common_fatjet_deepMD_T*/  if (Common_fatjet_deepMD_T_branch) Common_fatjet_deepMD_T_branch->SetAddress(&Common_fatjet_deepMD_T_);
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_T*/  Common_fatjet_deep_T_branch = tree->GetBranch("Common_fatjet_deep_T");
/*                    Common_fatjet_deep_T*/  if (Common_fatjet_deep_T_branch) Common_fatjet_deep_T_branch->SetAddress(&Common_fatjet_deep_T_);
//---------------------------------------------------------------------------------
/*                 Common_fatjet_deepMD_bb*/  Common_fatjet_deepMD_bb_branch = tree->GetBranch("Common_fatjet_deepMD_bb");
/*                 Common_fatjet_deepMD_bb*/  if (Common_fatjet_deepMD_bb_branch) Common_fatjet_deepMD_bb_branch->SetAddress(&Common_fatjet_deepMD_bb_);
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNetMD_W*/  Common_fatjet_particleNetMD_W_branch = tree->GetBranch("Common_fatjet_particleNetMD_W");
/*           Common_fatjet_particleNetMD_W*/  if (Common_fatjet_particleNetMD_W_branch) Common_fatjet_particleNetMD_W_branch->SetAddress(&Common_fatjet_particleNetMD_W_);
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xqq*/  Common_fatjet_particleNetMD_Xqq_branch = tree->GetBranch("Common_fatjet_particleNetMD_Xqq");
/*         Common_fatjet_particleNetMD_Xqq*/  if (Common_fatjet_particleNetMD_Xqq_branch) Common_fatjet_particleNetMD_Xqq_branch->SetAddress(&Common_fatjet_particleNetMD_Xqq_);
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xcc*/  Common_fatjet_particleNetMD_Xcc_branch = tree->GetBranch("Common_fatjet_particleNetMD_Xcc");
/*         Common_fatjet_particleNetMD_Xcc*/  if (Common_fatjet_particleNetMD_Xcc_branch) Common_fatjet_particleNetMD_Xcc_branch->SetAddress(&Common_fatjet_particleNetMD_Xcc_);
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xbb*/  Common_fatjet_particleNetMD_Xbb_branch = tree->GetBranch("Common_fatjet_particleNetMD_Xbb");
/*         Common_fatjet_particleNetMD_Xbb*/  if (Common_fatjet_particleNetMD_Xbb_branch) Common_fatjet_particleNetMD_Xbb_branch->SetAddress(&Common_fatjet_particleNetMD_Xbb_);
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_QCD*/  Common_fatjet_particleNetMD_QCD_branch = tree->GetBranch("Common_fatjet_particleNetMD_QCD");
/*         Common_fatjet_particleNetMD_QCD*/  if (Common_fatjet_particleNetMD_QCD_branch) Common_fatjet_particleNetMD_QCD_branch->SetAddress(&Common_fatjet_particleNetMD_QCD_);
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNet_QCD*/  Common_fatjet_particleNet_QCD_branch = tree->GetBranch("Common_fatjet_particleNet_QCD");
/*           Common_fatjet_particleNet_QCD*/  if (Common_fatjet_particleNet_QCD_branch) Common_fatjet_particleNet_QCD_branch->SetAddress(&Common_fatjet_particleNet_QCD_);
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_W*/  Common_fatjet_particleNet_W_branch = tree->GetBranch("Common_fatjet_particleNet_W");
/*             Common_fatjet_particleNet_W*/  if (Common_fatjet_particleNet_W_branch) Common_fatjet_particleNet_W_branch->SetAddress(&Common_fatjet_particleNet_W_);
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_Z*/  Common_fatjet_particleNet_Z_branch = tree->GetBranch("Common_fatjet_particleNet_Z");
/*             Common_fatjet_particleNet_Z*/  if (Common_fatjet_particleNet_Z_branch) Common_fatjet_particleNet_Z_branch->SetAddress(&Common_fatjet_particleNet_Z_);
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_T*/  Common_fatjet_particleNet_T_branch = tree->GetBranch("Common_fatjet_particleNet_T");
/*             Common_fatjet_particleNet_T*/  if (Common_fatjet_particleNet_T_branch) Common_fatjet_particleNet_T_branch->SetAddress(&Common_fatjet_particleNet_T_);
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau3*/  Common_fatjet_tau3_branch = tree->GetBranch("Common_fatjet_tau3");
/*                      Common_fatjet_tau3*/  if (Common_fatjet_tau3_branch) Common_fatjet_tau3_branch->SetAddress(&Common_fatjet_tau3_);
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau2*/  Common_fatjet_tau2_branch = tree->GetBranch("Common_fatjet_tau2");
/*                      Common_fatjet_tau2*/  if (Common_fatjet_tau2_branch) Common_fatjet_tau2_branch->SetAddress(&Common_fatjet_tau2_);
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau1*/  Common_fatjet_tau1_branch = tree->GetBranch("Common_fatjet_tau1");
/*                      Common_fatjet_tau1*/  if (Common_fatjet_tau1_branch) Common_fatjet_tau1_branch->SetAddress(&Common_fatjet_tau1_);
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau32*/  Common_fatjet_tau32_branch = tree->GetBranch("Common_fatjet_tau32");
/*                     Common_fatjet_tau32*/  if (Common_fatjet_tau32_branch) Common_fatjet_tau32_branch->SetAddress(&Common_fatjet_tau32_);
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau21*/  Common_fatjet_tau21_branch = tree->GetBranch("Common_fatjet_tau21");
/*                     Common_fatjet_tau21*/  if (Common_fatjet_tau21_branch) Common_fatjet_tau21_branch->SetAddress(&Common_fatjet_tau21_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_pt*/  Common_fatjet_subjet0_pt_branch = tree->GetBranch("Common_fatjet_subjet0_pt");
/*                Common_fatjet_subjet0_pt*/  if (Common_fatjet_subjet0_pt_branch) Common_fatjet_subjet0_pt_branch->SetAddress(&Common_fatjet_subjet0_pt_);
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_eta*/  Common_fatjet_subjet0_eta_branch = tree->GetBranch("Common_fatjet_subjet0_eta");
/*               Common_fatjet_subjet0_eta*/  if (Common_fatjet_subjet0_eta_branch) Common_fatjet_subjet0_eta_branch->SetAddress(&Common_fatjet_subjet0_eta_);
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_phi*/  Common_fatjet_subjet0_phi_branch = tree->GetBranch("Common_fatjet_subjet0_phi");
/*               Common_fatjet_subjet0_phi*/  if (Common_fatjet_subjet0_phi_branch) Common_fatjet_subjet0_phi_branch->SetAddress(&Common_fatjet_subjet0_phi_);
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet0_mass*/  Common_fatjet_subjet0_mass_branch = tree->GetBranch("Common_fatjet_subjet0_mass");
/*              Common_fatjet_subjet0_mass*/  if (Common_fatjet_subjet0_mass_branch) Common_fatjet_subjet0_mass_branch->SetAddress(&Common_fatjet_subjet0_mass_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_pt*/  Common_fatjet_subjet1_pt_branch = tree->GetBranch("Common_fatjet_subjet1_pt");
/*                Common_fatjet_subjet1_pt*/  if (Common_fatjet_subjet1_pt_branch) Common_fatjet_subjet1_pt_branch->SetAddress(&Common_fatjet_subjet1_pt_);
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_eta*/  Common_fatjet_subjet1_eta_branch = tree->GetBranch("Common_fatjet_subjet1_eta");
/*               Common_fatjet_subjet1_eta*/  if (Common_fatjet_subjet1_eta_branch) Common_fatjet_subjet1_eta_branch->SetAddress(&Common_fatjet_subjet1_eta_);
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_phi*/  Common_fatjet_subjet1_phi_branch = tree->GetBranch("Common_fatjet_subjet1_phi");
/*               Common_fatjet_subjet1_phi*/  if (Common_fatjet_subjet1_phi_branch) Common_fatjet_subjet1_phi_branch->SetAddress(&Common_fatjet_subjet1_phi_);
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet1_mass*/  Common_fatjet_subjet1_mass_branch = tree->GetBranch("Common_fatjet_subjet1_mass");
/*              Common_fatjet_subjet1_mass*/  if (Common_fatjet_subjet1_mass_branch) Common_fatjet_subjet1_mass_branch->SetAddress(&Common_fatjet_subjet1_mass_);
//---------------------------------------------------------------------------------
/*                        Common_fatjet_WP*/  Common_fatjet_WP_branch = tree->GetBranch("Common_fatjet_WP");
/*                        Common_fatjet_WP*/  if (Common_fatjet_WP_branch) Common_fatjet_WP_branch->SetAddress(&Common_fatjet_WP_);
//---------------------------------------------------------------------------------
/*                     Common_fatjet_WP_MD*/  Common_fatjet_WP_MD_branch = tree->GetBranch("Common_fatjet_WP_MD");
/*                     Common_fatjet_WP_MD*/  if (Common_fatjet_WP_MD_branch) Common_fatjet_WP_MD_branch->SetAddress(&Common_fatjet_WP_MD_);
//---------------------------------------------------------------------------------
/*            Common_fatjet_WP_antimasscut*/  Common_fatjet_WP_antimasscut_branch = tree->GetBranch("Common_fatjet_WP_antimasscut");
/*            Common_fatjet_WP_antimasscut*/  if (Common_fatjet_WP_antimasscut_branch) Common_fatjet_WP_antimasscut_branch->SetAddress(&Common_fatjet_WP_antimasscut_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFVLoose*/  Common_fatjet_SFVLoose_branch = tree->GetBranch("Common_fatjet_SFVLoose");
/*                  Common_fatjet_SFVLoose*/  if (Common_fatjet_SFVLoose_branch) Common_fatjet_SFVLoose_branch->SetAddress(&Common_fatjet_SFVLoose_);
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFLoose*/  Common_fatjet_SFLoose_branch = tree->GetBranch("Common_fatjet_SFLoose");
/*                   Common_fatjet_SFLoose*/  if (Common_fatjet_SFLoose_branch) Common_fatjet_SFLoose_branch->SetAddress(&Common_fatjet_SFLoose_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFMedium*/  Common_fatjet_SFMedium_branch = tree->GetBranch("Common_fatjet_SFMedium");
/*                  Common_fatjet_SFMedium*/  if (Common_fatjet_SFMedium_branch) Common_fatjet_SFMedium_branch->SetAddress(&Common_fatjet_SFMedium_);
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFTight*/  Common_fatjet_SFTight_branch = tree->GetBranch("Common_fatjet_SFTight");
/*                   Common_fatjet_SFTight*/  if (Common_fatjet_SFTight_branch) Common_fatjet_SFTight_branch->SetAddress(&Common_fatjet_SFTight_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnVLoose*/  Common_fatjet_SFdnVLoose_branch = tree->GetBranch("Common_fatjet_SFdnVLoose");
/*                Common_fatjet_SFdnVLoose*/  if (Common_fatjet_SFdnVLoose_branch) Common_fatjet_SFdnVLoose_branch->SetAddress(&Common_fatjet_SFdnVLoose_);
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnLoose*/  Common_fatjet_SFdnLoose_branch = tree->GetBranch("Common_fatjet_SFdnLoose");
/*                 Common_fatjet_SFdnLoose*/  if (Common_fatjet_SFdnLoose_branch) Common_fatjet_SFdnLoose_branch->SetAddress(&Common_fatjet_SFdnLoose_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnMedium*/  Common_fatjet_SFdnMedium_branch = tree->GetBranch("Common_fatjet_SFdnMedium");
/*                Common_fatjet_SFdnMedium*/  if (Common_fatjet_SFdnMedium_branch) Common_fatjet_SFdnMedium_branch->SetAddress(&Common_fatjet_SFdnMedium_);
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnTight*/  Common_fatjet_SFdnTight_branch = tree->GetBranch("Common_fatjet_SFdnTight");
/*                 Common_fatjet_SFdnTight*/  if (Common_fatjet_SFdnTight_branch) Common_fatjet_SFdnTight_branch->SetAddress(&Common_fatjet_SFdnTight_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupVLoose*/  Common_fatjet_SFupVLoose_branch = tree->GetBranch("Common_fatjet_SFupVLoose");
/*                Common_fatjet_SFupVLoose*/  if (Common_fatjet_SFupVLoose_branch) Common_fatjet_SFupVLoose_branch->SetAddress(&Common_fatjet_SFupVLoose_);
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupLoose*/  Common_fatjet_SFupLoose_branch = tree->GetBranch("Common_fatjet_SFupLoose");
/*                 Common_fatjet_SFupLoose*/  if (Common_fatjet_SFupLoose_branch) Common_fatjet_SFupLoose_branch->SetAddress(&Common_fatjet_SFupLoose_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupMedium*/  Common_fatjet_SFupMedium_branch = tree->GetBranch("Common_fatjet_SFupMedium");
/*                Common_fatjet_SFupMedium*/  if (Common_fatjet_SFupMedium_branch) Common_fatjet_SFupMedium_branch->SetAddress(&Common_fatjet_SFupMedium_);
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupTight*/  Common_fatjet_SFupTight_branch = tree->GetBranch("Common_fatjet_SFupTight");
/*                 Common_fatjet_SFupTight*/  if (Common_fatjet_SFupTight_branch) Common_fatjet_SFupTight_branch->SetAddress(&Common_fatjet_SFupTight_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesup*/  Common_fatjet_pt_jesup_branch = tree->GetBranch("Common_fatjet_pt_jesup");
/*                  Common_fatjet_pt_jesup*/  if (Common_fatjet_pt_jesup_branch) Common_fatjet_pt_jesup_branch->SetAddress(&Common_fatjet_pt_jesup_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesdn*/  Common_fatjet_pt_jesdn_branch = tree->GetBranch("Common_fatjet_pt_jesdn");
/*                  Common_fatjet_pt_jesdn*/  if (Common_fatjet_pt_jesdn_branch) Common_fatjet_pt_jesdn_branch->SetAddress(&Common_fatjet_pt_jesdn_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerup*/  Common_fatjet_pt_jerup_branch = tree->GetBranch("Common_fatjet_pt_jerup");
/*                  Common_fatjet_pt_jerup*/  if (Common_fatjet_pt_jerup_branch) Common_fatjet_pt_jerup_branch->SetAddress(&Common_fatjet_pt_jerup_);
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerdn*/  Common_fatjet_pt_jerdn_branch = tree->GetBranch("Common_fatjet_pt_jerdn");
/*                  Common_fatjet_pt_jerdn*/  if (Common_fatjet_pt_jerdn_branch) Common_fatjet_pt_jerdn_branch->SetAddress(&Common_fatjet_pt_jerdn_);
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesup*/  Common_fatjet_msoftdrop_jesup_branch = tree->GetBranch("Common_fatjet_msoftdrop_jesup");
/*           Common_fatjet_msoftdrop_jesup*/  if (Common_fatjet_msoftdrop_jesup_branch) Common_fatjet_msoftdrop_jesup_branch->SetAddress(&Common_fatjet_msoftdrop_jesup_);
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesdn*/  Common_fatjet_msoftdrop_jesdn_branch = tree->GetBranch("Common_fatjet_msoftdrop_jesdn");
/*           Common_fatjet_msoftdrop_jesdn*/  if (Common_fatjet_msoftdrop_jesdn_branch) Common_fatjet_msoftdrop_jesdn_branch->SetAddress(&Common_fatjet_msoftdrop_jesdn_);
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerup*/  Common_fatjet_msoftdrop_jerup_branch = tree->GetBranch("Common_fatjet_msoftdrop_jerup");
/*           Common_fatjet_msoftdrop_jerup*/  if (Common_fatjet_msoftdrop_jerup_branch) Common_fatjet_msoftdrop_jerup_branch->SetAddress(&Common_fatjet_msoftdrop_jerup_);
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerdn*/  Common_fatjet_msoftdrop_jerdn_branch = tree->GetBranch("Common_fatjet_msoftdrop_jerdn");
/*           Common_fatjet_msoftdrop_jerdn*/  if (Common_fatjet_msoftdrop_jerdn_branch) Common_fatjet_msoftdrop_jerdn_branch->SetAddress(&Common_fatjet_msoftdrop_jerdn_);
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsup*/  Common_fatjet_msoftdrop_jmsup_branch = tree->GetBranch("Common_fatjet_msoftdrop_jmsup");
/*           Common_fatjet_msoftdrop_jmsup*/  if (Common_fatjet_msoftdrop_jmsup_branch) Common_fatjet_msoftdrop_jmsup_branch->SetAddress(&Common_fatjet_msoftdrop_jmsup_);
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsdn*/  Common_fatjet_msoftdrop_jmsdn_branch = tree->GetBranch("Common_fatjet_msoftdrop_jmsdn");
/*           Common_fatjet_msoftdrop_jmsdn*/  if (Common_fatjet_msoftdrop_jmsdn_branch) Common_fatjet_msoftdrop_jmsdn_branch->SetAddress(&Common_fatjet_msoftdrop_jmsdn_);
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrup*/  Common_fatjet_msoftdrop_jmrup_branch = tree->GetBranch("Common_fatjet_msoftdrop_jmrup");
/*           Common_fatjet_msoftdrop_jmrup*/  if (Common_fatjet_msoftdrop_jmrup_branch) Common_fatjet_msoftdrop_jmrup_branch->SetAddress(&Common_fatjet_msoftdrop_jmrup_);
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrdn*/  Common_fatjet_msoftdrop_jmrdn_branch = tree->GetBranch("Common_fatjet_msoftdrop_jmrdn");
/*           Common_fatjet_msoftdrop_jmrdn*/  if (Common_fatjet_msoftdrop_jmrdn_branch) Common_fatjet_msoftdrop_jmrdn_branch->SetAddress(&Common_fatjet_msoftdrop_jmrdn_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesup*/  Common_fatjet_mass_jesup_branch = tree->GetBranch("Common_fatjet_mass_jesup");
/*                Common_fatjet_mass_jesup*/  if (Common_fatjet_mass_jesup_branch) Common_fatjet_mass_jesup_branch->SetAddress(&Common_fatjet_mass_jesup_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesdn*/  Common_fatjet_mass_jesdn_branch = tree->GetBranch("Common_fatjet_mass_jesdn");
/*                Common_fatjet_mass_jesdn*/  if (Common_fatjet_mass_jesdn_branch) Common_fatjet_mass_jesdn_branch->SetAddress(&Common_fatjet_mass_jesdn_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerup*/  Common_fatjet_mass_jerup_branch = tree->GetBranch("Common_fatjet_mass_jerup");
/*                Common_fatjet_mass_jerup*/  if (Common_fatjet_mass_jerup_branch) Common_fatjet_mass_jerup_branch->SetAddress(&Common_fatjet_mass_jerup_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerdn*/  Common_fatjet_mass_jerdn_branch = tree->GetBranch("Common_fatjet_mass_jerdn");
/*                Common_fatjet_mass_jerdn*/  if (Common_fatjet_mass_jerdn_branch) Common_fatjet_mass_jerdn_branch->SetAddress(&Common_fatjet_mass_jerdn_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsup*/  Common_fatjet_mass_jmsup_branch = tree->GetBranch("Common_fatjet_mass_jmsup");
/*                Common_fatjet_mass_jmsup*/  if (Common_fatjet_mass_jmsup_branch) Common_fatjet_mass_jmsup_branch->SetAddress(&Common_fatjet_mass_jmsup_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsdn*/  Common_fatjet_mass_jmsdn_branch = tree->GetBranch("Common_fatjet_mass_jmsdn");
/*                Common_fatjet_mass_jmsdn*/  if (Common_fatjet_mass_jmsdn_branch) Common_fatjet_mass_jmsdn_branch->SetAddress(&Common_fatjet_mass_jmsdn_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrup*/  Common_fatjet_mass_jmrup_branch = tree->GetBranch("Common_fatjet_mass_jmrup");
/*                Common_fatjet_mass_jmrup*/  if (Common_fatjet_mass_jmrup_branch) Common_fatjet_mass_jmrup_branch->SetAddress(&Common_fatjet_mass_jmrup_);
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrdn*/  Common_fatjet_mass_jmrdn_branch = tree->GetBranch("Common_fatjet_mass_jmrdn");
/*                Common_fatjet_mass_jmrdn*/  if (Common_fatjet_mass_jmrdn_branch) Common_fatjet_mass_jmrdn_branch->SetAddress(&Common_fatjet_mass_jmrdn_);
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFVLoose*/  Common_eventweight_fatjet_SFVLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFVLoose");
/*      Common_eventweight_fatjet_SFVLoose*/  if (Common_eventweight_fatjet_SFVLoose_branch) Common_eventweight_fatjet_SFVLoose_branch->SetAddress(&Common_eventweight_fatjet_SFVLoose_);
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFLoose*/  Common_eventweight_fatjet_SFLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFLoose");
/*       Common_eventweight_fatjet_SFLoose*/  if (Common_eventweight_fatjet_SFLoose_branch) Common_eventweight_fatjet_SFLoose_branch->SetAddress(&Common_eventweight_fatjet_SFLoose_);
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFMedium*/  Common_eventweight_fatjet_SFMedium_branch = tree->GetBranch("Common_eventweight_fatjet_SFMedium");
/*      Common_eventweight_fatjet_SFMedium*/  if (Common_eventweight_fatjet_SFMedium_branch) Common_eventweight_fatjet_SFMedium_branch->SetAddress(&Common_eventweight_fatjet_SFMedium_);
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFTight*/  Common_eventweight_fatjet_SFTight_branch = tree->GetBranch("Common_eventweight_fatjet_SFTight");
/*       Common_eventweight_fatjet_SFTight*/  if (Common_eventweight_fatjet_SFTight_branch) Common_eventweight_fatjet_SFTight_branch->SetAddress(&Common_eventweight_fatjet_SFTight_);
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnVLoose*/  Common_eventweight_fatjet_SFdnVLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFdnVLoose");
/*    Common_eventweight_fatjet_SFdnVLoose*/  if (Common_eventweight_fatjet_SFdnVLoose_branch) Common_eventweight_fatjet_SFdnVLoose_branch->SetAddress(&Common_eventweight_fatjet_SFdnVLoose_);
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnLoose*/  Common_eventweight_fatjet_SFdnLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFdnLoose");
/*     Common_eventweight_fatjet_SFdnLoose*/  if (Common_eventweight_fatjet_SFdnLoose_branch) Common_eventweight_fatjet_SFdnLoose_branch->SetAddress(&Common_eventweight_fatjet_SFdnLoose_);
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnMedium*/  Common_eventweight_fatjet_SFdnMedium_branch = tree->GetBranch("Common_eventweight_fatjet_SFdnMedium");
/*    Common_eventweight_fatjet_SFdnMedium*/  if (Common_eventweight_fatjet_SFdnMedium_branch) Common_eventweight_fatjet_SFdnMedium_branch->SetAddress(&Common_eventweight_fatjet_SFdnMedium_);
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnTight*/  Common_eventweight_fatjet_SFdnTight_branch = tree->GetBranch("Common_eventweight_fatjet_SFdnTight");
/*     Common_eventweight_fatjet_SFdnTight*/  if (Common_eventweight_fatjet_SFdnTight_branch) Common_eventweight_fatjet_SFdnTight_branch->SetAddress(&Common_eventweight_fatjet_SFdnTight_);
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupVLoose*/  Common_eventweight_fatjet_SFupVLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFupVLoose");
/*    Common_eventweight_fatjet_SFupVLoose*/  if (Common_eventweight_fatjet_SFupVLoose_branch) Common_eventweight_fatjet_SFupVLoose_branch->SetAddress(&Common_eventweight_fatjet_SFupVLoose_);
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupLoose*/  Common_eventweight_fatjet_SFupLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFupLoose");
/*     Common_eventweight_fatjet_SFupLoose*/  if (Common_eventweight_fatjet_SFupLoose_branch) Common_eventweight_fatjet_SFupLoose_branch->SetAddress(&Common_eventweight_fatjet_SFupLoose_);
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupMedium*/  Common_eventweight_fatjet_SFupMedium_branch = tree->GetBranch("Common_eventweight_fatjet_SFupMedium");
/*    Common_eventweight_fatjet_SFupMedium*/  if (Common_eventweight_fatjet_SFupMedium_branch) Common_eventweight_fatjet_SFupMedium_branch->SetAddress(&Common_eventweight_fatjet_SFupMedium_);
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupTight*/  Common_eventweight_fatjet_SFupTight_branch = tree->GetBranch("Common_eventweight_fatjet_SFupTight");
/*     Common_eventweight_fatjet_SFupTight*/  if (Common_eventweight_fatjet_SFupTight_branch) Common_eventweight_fatjet_SFupTight_branch->SetAddress(&Common_eventweight_fatjet_SFupTight_);
//---------------------------------------------------------------------------------
/*                         Common_nb_loose*/  Common_nb_loose_branch = tree->GetBranch("Common_nb_loose");
/*                         Common_nb_loose*/  if (Common_nb_loose_branch) Common_nb_loose_branch->SetAddress(&Common_nb_loose_);
//---------------------------------------------------------------------------------
/*                        Common_nb_medium*/  Common_nb_medium_branch = tree->GetBranch("Common_nb_medium");
/*                        Common_nb_medium*/  if (Common_nb_medium_branch) Common_nb_medium_branch->SetAddress(&Common_nb_medium_);
//---------------------------------------------------------------------------------
/*                         Common_nb_tight*/  Common_nb_tight_branch = tree->GetBranch("Common_nb_tight");
/*                         Common_nb_tight*/  if (Common_nb_tight_branch) Common_nb_tight_branch->SetAddress(&Common_nb_tight_);
//---------------------------------------------------------------------------------
/*                          Common_gen_idx*/  Common_gen_idx_branch = tree->GetBranch("Common_gen_idx");
/*                          Common_gen_idx*/  if (Common_gen_idx_branch) Common_gen_idx_branch->SetAddress(&Common_gen_idx_);
//---------------------------------------------------------------------------------
/*                   Common_gen_mother_idx*/  Common_gen_mother_idx_branch = tree->GetBranch("Common_gen_mother_idx");
/*                   Common_gen_mother_idx*/  if (Common_gen_mother_idx_branch) Common_gen_mother_idx_branch->SetAddress(&Common_gen_mother_idx_);
//---------------------------------------------------------------------------------
/*                    Common_gen_mother_id*/  Common_gen_mother_id_branch = tree->GetBranch("Common_gen_mother_id");
/*                    Common_gen_mother_id*/  if (Common_gen_mother_id_branch) Common_gen_mother_id_branch->SetAddress(&Common_gen_mother_id_);
//---------------------------------------------------------------------------------
/*                        Common_gen_pdgid*/  Common_gen_pdgid_branch = tree->GetBranch("Common_gen_pdgid");
/*                        Common_gen_pdgid*/  if (Common_gen_pdgid_branch) Common_gen_pdgid_branch->SetAddress(&Common_gen_pdgid_);
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_idx*/  Common_gen_vvvdecay_idx_branch = tree->GetBranch("Common_gen_vvvdecay_idx");
/*                 Common_gen_vvvdecay_idx*/  if (Common_gen_vvvdecay_idx_branch) Common_gen_vvvdecay_idx_branch->SetAddress(&Common_gen_vvvdecay_idx_);
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_mother_idx*/  Common_gen_vvvdecay_mother_idx_branch = tree->GetBranch("Common_gen_vvvdecay_mother_idx");
/*          Common_gen_vvvdecay_mother_idx*/  if (Common_gen_vvvdecay_mother_idx_branch) Common_gen_vvvdecay_mother_idx_branch->SetAddress(&Common_gen_vvvdecay_mother_idx_);
//---------------------------------------------------------------------------------
/*           Common_gen_vvvdecay_mother_id*/  Common_gen_vvvdecay_mother_id_branch = tree->GetBranch("Common_gen_vvvdecay_mother_id");
/*           Common_gen_vvvdecay_mother_id*/  if (Common_gen_vvvdecay_mother_id_branch) Common_gen_vvvdecay_mother_id_branch->SetAddress(&Common_gen_vvvdecay_mother_id_);
//---------------------------------------------------------------------------------
/*               Common_gen_vvvdecay_pdgid*/  Common_gen_vvvdecay_pdgid_branch = tree->GetBranch("Common_gen_vvvdecay_pdgid");
/*               Common_gen_vvvdecay_pdgid*/  if (Common_gen_vvvdecay_pdgid_branch) Common_gen_vvvdecay_pdgid_branch->SetAddress(&Common_gen_vvvdecay_pdgid_);
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_taudecayid*/  Common_gen_vvvdecay_taudecayid_branch = tree->GetBranch("Common_gen_vvvdecay_taudecayid");
/*          Common_gen_vvvdecay_taudecayid*/  if (Common_gen_vvvdecay_taudecayid_branch) Common_gen_vvvdecay_taudecayid_branch->SetAddress(&Common_gen_vvvdecay_taudecayid_);
//---------------------------------------------------------------------------------
/*                         Common_isSignal*/  Common_isSignal_branch = tree->GetBranch("Common_isSignal");
/*                         Common_isSignal*/  if (Common_isSignal_branch) Common_isSignal_branch->SetAddress(&Common_isSignal_);
//---------------------------------------------------------------------------------
/*                              Common_n_W*/  Common_n_W_branch = tree->GetBranch("Common_n_W");
/*                              Common_n_W*/  if (Common_n_W_branch) Common_n_W_branch->SetAddress(&Common_n_W_);
//---------------------------------------------------------------------------------
/*                              Common_n_Z*/  Common_n_Z_branch = tree->GetBranch("Common_n_Z");
/*                              Common_n_Z*/  if (Common_n_Z_branch) Common_n_Z_branch->SetAddress(&Common_n_Z_);
//---------------------------------------------------------------------------------
/*                          Common_n_lep_Z*/  Common_n_lep_Z_branch = tree->GetBranch("Common_n_lep_Z");
/*                          Common_n_lep_Z*/  if (Common_n_lep_Z_branch) Common_n_lep_Z_branch->SetAddress(&Common_n_lep_Z_);
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_Z*/  Common_n_leptau_Z_branch = tree->GetBranch("Common_n_leptau_Z");
/*                       Common_n_leptau_Z*/  if (Common_n_leptau_Z_branch) Common_n_leptau_Z_branch->SetAddress(&Common_n_leptau_Z_);
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_Z*/  Common_n_hadtau_Z_branch = tree->GetBranch("Common_n_hadtau_Z");
/*                       Common_n_hadtau_Z*/  if (Common_n_hadtau_Z_branch) Common_n_hadtau_Z_branch->SetAddress(&Common_n_hadtau_Z_);
//---------------------------------------------------------------------------------
/*                           Common_n_nu_Z*/  Common_n_nu_Z_branch = tree->GetBranch("Common_n_nu_Z");
/*                           Common_n_nu_Z*/  if (Common_n_nu_Z_branch) Common_n_nu_Z_branch->SetAddress(&Common_n_nu_Z_);
//---------------------------------------------------------------------------------
/*                            Common_n_b_Z*/  Common_n_b_Z_branch = tree->GetBranch("Common_n_b_Z");
/*                            Common_n_b_Z*/  if (Common_n_b_Z_branch) Common_n_b_Z_branch->SetAddress(&Common_n_b_Z_);
//---------------------------------------------------------------------------------
/*                          Common_n_lep_W*/  Common_n_lep_W_branch = tree->GetBranch("Common_n_lep_W");
/*                          Common_n_lep_W*/  if (Common_n_lep_W_branch) Common_n_lep_W_branch->SetAddress(&Common_n_lep_W_);
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_W*/  Common_n_leptau_W_branch = tree->GetBranch("Common_n_leptau_W");
/*                       Common_n_leptau_W*/  if (Common_n_leptau_W_branch) Common_n_leptau_W_branch->SetAddress(&Common_n_leptau_W_);
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_W*/  Common_n_hadtau_W_branch = tree->GetBranch("Common_n_hadtau_W");
/*                       Common_n_hadtau_W*/  if (Common_n_hadtau_W_branch) Common_n_hadtau_W_branch->SetAddress(&Common_n_hadtau_W_);
//---------------------------------------------------------------------------------
/*                        Common_haslepWSS*/  Common_haslepWSS_branch = tree->GetBranch("Common_haslepWSS");
/*                        Common_haslepWSS*/  if (Common_haslepWSS_branch) Common_haslepWSS_branch->SetAddress(&Common_haslepWSS_);
//---------------------------------------------------------------------------------
/*                            Common_genHT*/  Common_genHT_branch = tree->GetBranch("Common_genHT");
/*                            Common_genHT*/  if (Common_genHT_branch) Common_genHT_branch->SetAddress(&Common_genHT_);
//---------------------------------------------------------------------------------
/*                  Common_gen_n_light_lep*/  Common_gen_n_light_lep_branch = tree->GetBranch("Common_gen_n_light_lep");
/*                  Common_gen_n_light_lep*/  if (Common_gen_n_light_lep_branch) Common_gen_n_light_lep_branch->SetAddress(&Common_gen_n_light_lep_);
//---------------------------------------------------------------------------------
/*                   Common_gen_VH_channel*/  Common_gen_VH_channel_branch = tree->GetBranch("Common_gen_VH_channel");
/*                   Common_gen_VH_channel*/  if (Common_gen_VH_channel_branch) Common_gen_VH_channel_branch->SetAddress(&Common_gen_VH_channel_);
//---------------------------------------------------------------------------------
/*                Cut_4LepMET_Preselection*/  Cut_4LepMET_Preselection_branch = tree->GetBranch("Cut_4LepMET_Preselection");
/*                Cut_4LepMET_Preselection*/  if (Cut_4LepMET_Preselection_branch) Cut_4LepMET_Preselection_branch->SetAddress(&Cut_4LepMET_Preselection_);
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/  Cut_4LepMET_emuChannel_branch = tree->GetBranch("Cut_4LepMET_emuChannel");
/*                  Cut_4LepMET_emuChannel*/  if (Cut_4LepMET_emuChannel_branch) Cut_4LepMET_emuChannel_branch->SetAddress(&Cut_4LepMET_emuChannel_);
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/  Cut_4LepMET_offzChannel_branch = tree->GetBranch("Cut_4LepMET_offzChannel");
/*                 Cut_4LepMET_offzChannel*/  if (Cut_4LepMET_offzChannel_branch) Cut_4LepMET_offzChannel_branch->SetAddress(&Cut_4LepMET_offzChannel_);
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/  Cut_4LepMET_onzChannel_branch = tree->GetBranch("Cut_4LepMET_onzChannel");
/*                  Cut_4LepMET_onzChannel*/  if (Cut_4LepMET_onzChannel_branch) Cut_4LepMET_onzChannel_branch->SetAddress(&Cut_4LepMET_onzChannel_);
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/  Cut_4LepMET_onzChannel_HighMET_branch = tree->GetBranch("Cut_4LepMET_onzChannel_HighMET");
/*          Cut_4LepMET_onzChannel_HighMET*/  if (Cut_4LepMET_onzChannel_HighMET_branch) Cut_4LepMET_onzChannel_HighMET_branch->SetAddress(&Cut_4LepMET_onzChannel_HighMET_);
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/  Var_4LepMET_Zcand_lep_idx_0_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_idx_0");
/*             Var_4LepMET_Zcand_lep_idx_0*/  if (Var_4LepMET_Zcand_lep_idx_0_branch) Var_4LepMET_Zcand_lep_idx_0_branch->SetAddress(&Var_4LepMET_Zcand_lep_idx_0_);
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  Var_4LepMET_Zcand_lep_pdgid_0_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_pdgid_0");
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  if (Var_4LepMET_Zcand_lep_pdgid_0_branch) Var_4LepMET_Zcand_lep_pdgid_0_branch->SetAddress(&Var_4LepMET_Zcand_lep_pdgid_0_);
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_1*/  Var_4LepMET_Zcand_lep_idx_1_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_idx_1");
/*             Var_4LepMET_Zcand_lep_idx_1*/  if (Var_4LepMET_Zcand_lep_idx_1_branch) Var_4LepMET_Zcand_lep_idx_1_branch->SetAddress(&Var_4LepMET_Zcand_lep_idx_1_);
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  Var_4LepMET_Zcand_lep_pdgid_1_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_pdgid_1");
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  if (Var_4LepMET_Zcand_lep_pdgid_1_branch) Var_4LepMET_Zcand_lep_pdgid_1_branch->SetAddress(&Var_4LepMET_Zcand_lep_pdgid_1_);
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_Zcand_mll*/  Var_4LepMET_Zcand_mll_branch = tree->GetBranch("Var_4LepMET_Zcand_mll");
/*                   Var_4LepMET_Zcand_mll*/  if (Var_4LepMET_Zcand_mll_branch) Var_4LepMET_Zcand_mll_branch->SetAddress(&Var_4LepMET_Zcand_mll_);
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_0*/  Var_4LepMET_other_lep_idx_0_branch = tree->GetBranch("Var_4LepMET_other_lep_idx_0");
/*             Var_4LepMET_other_lep_idx_0*/  if (Var_4LepMET_other_lep_idx_0_branch) Var_4LepMET_other_lep_idx_0_branch->SetAddress(&Var_4LepMET_other_lep_idx_0_);
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_0*/  Var_4LepMET_other_lep_pdgid_0_branch = tree->GetBranch("Var_4LepMET_other_lep_pdgid_0");
/*           Var_4LepMET_other_lep_pdgid_0*/  if (Var_4LepMET_other_lep_pdgid_0_branch) Var_4LepMET_other_lep_pdgid_0_branch->SetAddress(&Var_4LepMET_other_lep_pdgid_0_);
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_1*/  Var_4LepMET_other_lep_idx_1_branch = tree->GetBranch("Var_4LepMET_other_lep_idx_1");
/*             Var_4LepMET_other_lep_idx_1*/  if (Var_4LepMET_other_lep_idx_1_branch) Var_4LepMET_other_lep_idx_1_branch->SetAddress(&Var_4LepMET_other_lep_idx_1_);
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_1*/  Var_4LepMET_other_lep_pdgid_1_branch = tree->GetBranch("Var_4LepMET_other_lep_pdgid_1");
/*           Var_4LepMET_other_lep_pdgid_1*/  if (Var_4LepMET_other_lep_pdgid_1_branch) Var_4LepMET_other_lep_pdgid_1_branch->SetAddress(&Var_4LepMET_other_lep_pdgid_1_);
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_other_mll*/  Var_4LepMET_other_mll_branch = tree->GetBranch("Var_4LepMET_other_mll");
/*                   Var_4LepMET_other_mll*/  if (Var_4LepMET_other_mll_branch) Var_4LepMET_other_mll_branch->SetAddress(&Var_4LepMET_other_mll_);
//---------------------------------------------------------------------------------
/*                         Var_4LepMET_mt2*/  Var_4LepMET_mt2_branch = tree->GetBranch("Var_4LepMET_mt2");
/*                         Var_4LepMET_mt2*/  if (Var_4LepMET_mt2_branch) Var_4LepMET_mt2_branch->SetAddress(&Var_4LepMET_mt2_);
//---------------------------------------------------------------------------------

  tree->SetMakeClass(0);
}

void VVVTree::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
//---------------------------------------------------------------------------------
/*                           Common_isData*/  Common_isData_isLoaded = false;
//---------------------------------------------------------------------------------
/*                              Common_run*/  Common_run_isLoaded = false;
//---------------------------------------------------------------------------------
/*                             Common_lumi*/  Common_lumi_isLoaded = false;
//---------------------------------------------------------------------------------
/*                              Common_evt*/  Common_evt_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_genWeight*/  Common_genWeight_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/  Common_btagWeight_DeepCSVB_isLoaded = false;
//---------------------------------------------------------------------------------
/*                              Common_wgt*/  Common_wgt_isLoaded = false;
//---------------------------------------------------------------------------------
/*         Common_LHEWeight_mg_reweighting*/  Common_LHEWeight_mg_reweighting_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_event_puWeight*/  Common_event_puWeight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightup*/  Common_event_puWeightup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightdn*/  Common_event_puWeightdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Common_event_prefireWeight*/  Common_event_prefireWeight_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightup*/  Common_event_prefireWeightup_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightdn*/  Common_event_prefireWeightdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Common_event_triggerWeight*/  Common_event_triggerWeight_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightup*/  Common_event_triggerWeightup_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightdn*/  Common_event_triggerWeightdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Common_LHEReweightingWeight*/  Common_LHEReweightingWeight_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_isLoaded = false;
//---------------------------------------------------------------------------------
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = false;
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_HLT_IsoMu24*/  Common_HLT_IsoMu24_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_HLT_Ele32_WPTight*/  Common_HLT_Ele32_WPTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_HLT_PFHT1050*/  Common_HLT_PFHT1050_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_HLT_AK8PFJet500*/  Common_HLT_AK8PFJet500_isLoaded = false;
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet380_TrimMass30*/  Common_HLT_AK8PFJet380_TrimMass30_isLoaded = false;
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet360_TrimMass30*/  Common_HLT_AK8PFJet360_TrimMass30_isLoaded = false;
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet400_TrimMass30*/  Common_HLT_AK8PFJet400_TrimMass30_isLoaded = false;
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet420_TrimMass30*/  Common_HLT_AK8PFJet420_TrimMass30_isLoaded = false;
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT750_TrimMass50*/  Common_HLT_AK8PFHT750_TrimMass50_isLoaded = false;
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT800_TrimMass50*/  Common_HLT_AK8PFHT800_TrimMass50_isLoaded = false;
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT850_TrimMass50*/  Common_HLT_AK8PFHT850_TrimMass50_isLoaded = false;
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT900_TrimMass50*/  Common_HLT_AK8PFHT900_TrimMass50_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleEl*/  Common_HLT_DoubleEl_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_HLT_MuEG*/  Common_HLT_MuEG_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleMu*/  Common_HLT_DoubleMu_isLoaded = false;
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_ee_em_mm*/  Common_pass_duplicate_removal_ee_em_mm_isLoaded = false;
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_mm_em_ee*/  Common_pass_duplicate_removal_mm_em_ee_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/  Common_noiseFlag_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/  Common_noiseFlagMC_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_passGoodRun*/  Common_passGoodRun_isLoaded = false;
//---------------------------------------------------------------------------------
/*                           Common_met_p4*/  Common_met_p4_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesup*/  Common_met_p4_jesup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesdn*/  Common_met_p4_jesdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerup*/  Common_met_p4_jerup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerdn*/  Common_met_p4_jerdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_event_lepSF*/  Common_event_lepSF_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFelup*/  Common_event_lepSFelup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFeldn*/  Common_event_lepSFeldn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmuup*/  Common_event_lepSFmuup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmudn*/  Common_event_lepSFmudn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_event_lepSFTight*/  Common_event_lepSFTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Common_event_lepSFelupTight*/  Common_event_lepSFelupTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Common_event_lepSFeldnTight*/  Common_event_lepSFeldnTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmuupTight*/  Common_event_lepSFmuupTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmudnTight*/  Common_event_lepSFmudnTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_event_tightBtagSF*/  Common_event_tightBtagSF_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFup*/  Common_event_tightBtagSFup_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFdn*/  Common_event_tightBtagSFdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFup*/  Common_event_tightBtagSFHFup_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFdn*/  Common_event_tightBtagSFHFdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFup*/  Common_event_tightBtagSFLFup_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFdn*/  Common_event_tightBtagSFLFdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*               Common_event_mediumBtagSF*/  Common_event_mediumBtagSF_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFup*/  Common_event_mediumBtagSFup_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFdn*/  Common_event_mediumBtagSFdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFup*/  Common_event_mediumBtagSFHFup_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFdn*/  Common_event_mediumBtagSFHFdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFup*/  Common_event_mediumBtagSFLFup_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFdn*/  Common_event_mediumBtagSFLFdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_event_looseBtagSF*/  Common_event_looseBtagSF_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFup*/  Common_event_looseBtagSFup_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFdn*/  Common_event_looseBtagSFdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFup*/  Common_event_looseBtagSFHFup_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFdn*/  Common_event_looseBtagSFHFdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFup*/  Common_event_looseBtagSFLFup_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFdn*/  Common_event_looseBtagSFLFdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                           Common_lep_p4*/  Common_lep_p4_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_lep_idxs*/  Common_lep_idxs_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_lep_pdgid*/  Common_lep_pdgid_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_lep_tight*/  Common_lep_tight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                          Common_lep_dxy*/  Common_lep_dxy_isLoaded = false;
//---------------------------------------------------------------------------------
/*                           Common_lep_dz*/  Common_lep_dz_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_lep_ip3d*/  Common_lep_ip3d_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_lep_sip3d*/  Common_lep_sip3d_isLoaded = false;
//---------------------------------------------------------------------------------
/*                           Common_lep_SF*/  Common_lep_SF_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_lep_SFTight*/  Common_lep_SFTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_lep_SFdn*/  Common_lep_SFdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                    Common_lep_SFdnTight*/  Common_lep_SFdnTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_lep_SFup*/  Common_lep_SFup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                    Common_lep_SFupTight*/  Common_lep_SFupTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                           Common_jet_p4*/  Common_jet_p4_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_jet_idxs*/  Common_jet_idxs_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_jet_passBloose*/  Common_jet_passBloose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_jet_passBmedium*/  Common_jet_passBmedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_jet_passBtight*/  Common_jet_passBtight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                           Common_jet_id*/  Common_jet_id_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_jet_overlapfatjet*/  Common_jet_overlapfatjet_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesup*/  Common_jet_pt_jesup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesdn*/  Common_jet_pt_jesdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerup*/  Common_jet_pt_jerup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerdn*/  Common_jet_pt_jerdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesup*/  Common_jet_mass_jesup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesdn*/  Common_jet_mass_jesdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerup*/  Common_jet_mass_jerup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerdn*/  Common_jet_mass_jerdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_fatjet_p4*/  Common_fatjet_p4_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_fatjet_idxs*/  Common_fatjet_idxs_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_fatjet_id*/  Common_fatjet_id_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_msoftdrop*/  Common_fatjet_msoftdrop_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_W*/  Common_fatjet_deepMD_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_W*/  Common_fatjet_deep_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_Z*/  Common_fatjet_deepMD_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_Z*/  Common_fatjet_deep_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_T*/  Common_fatjet_deepMD_T_isLoaded = false;
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_T*/  Common_fatjet_deep_T_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_deepMD_bb*/  Common_fatjet_deepMD_bb_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNetMD_W*/  Common_fatjet_particleNetMD_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xqq*/  Common_fatjet_particleNetMD_Xqq_isLoaded = false;
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xcc*/  Common_fatjet_particleNetMD_Xcc_isLoaded = false;
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xbb*/  Common_fatjet_particleNetMD_Xbb_isLoaded = false;
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_QCD*/  Common_fatjet_particleNetMD_QCD_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNet_QCD*/  Common_fatjet_particleNet_QCD_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_W*/  Common_fatjet_particleNet_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_Z*/  Common_fatjet_particleNet_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_T*/  Common_fatjet_particleNet_T_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau3*/  Common_fatjet_tau3_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau2*/  Common_fatjet_tau2_isLoaded = false;
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau1*/  Common_fatjet_tau1_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau32*/  Common_fatjet_tau32_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau21*/  Common_fatjet_tau21_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_pt*/  Common_fatjet_subjet0_pt_isLoaded = false;
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_eta*/  Common_fatjet_subjet0_eta_isLoaded = false;
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_phi*/  Common_fatjet_subjet0_phi_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet0_mass*/  Common_fatjet_subjet0_mass_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_pt*/  Common_fatjet_subjet1_pt_isLoaded = false;
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_eta*/  Common_fatjet_subjet1_eta_isLoaded = false;
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_phi*/  Common_fatjet_subjet1_phi_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet1_mass*/  Common_fatjet_subjet1_mass_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_p4*/  Common_fatjet_subjet0_p4_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_p4*/  Common_fatjet_subjet1_p4_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_fatjet_WP*/  Common_fatjet_WP_isLoaded = false;
//---------------------------------------------------------------------------------
/*                     Common_fatjet_WP_MD*/  Common_fatjet_WP_MD_isLoaded = false;
//---------------------------------------------------------------------------------
/*            Common_fatjet_WP_antimasscut*/  Common_fatjet_WP_antimasscut_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFVLoose*/  Common_fatjet_SFVLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFLoose*/  Common_fatjet_SFLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFMedium*/  Common_fatjet_SFMedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFTight*/  Common_fatjet_SFTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnVLoose*/  Common_fatjet_SFdnVLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnLoose*/  Common_fatjet_SFdnLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnMedium*/  Common_fatjet_SFdnMedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnTight*/  Common_fatjet_SFdnTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupVLoose*/  Common_fatjet_SFupVLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupLoose*/  Common_fatjet_SFupLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupMedium*/  Common_fatjet_SFupMedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupTight*/  Common_fatjet_SFupTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesup*/  Common_fatjet_pt_jesup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesdn*/  Common_fatjet_pt_jesdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerup*/  Common_fatjet_pt_jerup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerdn*/  Common_fatjet_pt_jerdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesup*/  Common_fatjet_msoftdrop_jesup_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesdn*/  Common_fatjet_msoftdrop_jesdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerup*/  Common_fatjet_msoftdrop_jerup_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerdn*/  Common_fatjet_msoftdrop_jerdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsup*/  Common_fatjet_msoftdrop_jmsup_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsdn*/  Common_fatjet_msoftdrop_jmsdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrup*/  Common_fatjet_msoftdrop_jmrup_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrdn*/  Common_fatjet_msoftdrop_jmrdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesup*/  Common_fatjet_mass_jesup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesdn*/  Common_fatjet_mass_jesdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerup*/  Common_fatjet_mass_jerup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerdn*/  Common_fatjet_mass_jerdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsup*/  Common_fatjet_mass_jmsup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsdn*/  Common_fatjet_mass_jmsdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrup*/  Common_fatjet_mass_jmrup_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrdn*/  Common_fatjet_mass_jmrdn_isLoaded = false;
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFVLoose*/  Common_eventweight_fatjet_SFVLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFLoose*/  Common_eventweight_fatjet_SFLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFMedium*/  Common_eventweight_fatjet_SFMedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFTight*/  Common_eventweight_fatjet_SFTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnVLoose*/  Common_eventweight_fatjet_SFdnVLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnLoose*/  Common_eventweight_fatjet_SFdnLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnMedium*/  Common_eventweight_fatjet_SFdnMedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnTight*/  Common_eventweight_fatjet_SFdnTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupVLoose*/  Common_eventweight_fatjet_SFupVLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupLoose*/  Common_eventweight_fatjet_SFupLoose_isLoaded = false;
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupMedium*/  Common_eventweight_fatjet_SFupMedium_isLoaded = false;
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupTight*/  Common_eventweight_fatjet_SFupTight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_nb_loose*/  Common_nb_loose_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_nb_medium*/  Common_nb_medium_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_nb_tight*/  Common_nb_tight_isLoaded = false;
//---------------------------------------------------------------------------------
/*                          Common_gen_idx*/  Common_gen_idx_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_gen_mother_idx*/  Common_gen_mother_idx_isLoaded = false;
//---------------------------------------------------------------------------------
/*                    Common_gen_mother_id*/  Common_gen_mother_id_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_gen_pdgid*/  Common_gen_pdgid_isLoaded = false;
//---------------------------------------------------------------------------------
/*                          Common_gen_p4s*/  Common_gen_p4s_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_idx*/  Common_gen_vvvdecay_idx_isLoaded = false;
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_mother_idx*/  Common_gen_vvvdecay_mother_idx_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Common_gen_vvvdecay_mother_id*/  Common_gen_vvvdecay_mother_id_isLoaded = false;
//---------------------------------------------------------------------------------
/*               Common_gen_vvvdecay_pdgid*/  Common_gen_vvvdecay_pdgid_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_p4s*/  Common_gen_vvvdecay_p4s_isLoaded = false;
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_taudecayid*/  Common_gen_vvvdecay_taudecayid_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Common_isSignal*/  Common_isSignal_isLoaded = false;
//---------------------------------------------------------------------------------
/*                              Common_n_W*/  Common_n_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*                              Common_n_Z*/  Common_n_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                          Common_n_lep_Z*/  Common_n_lep_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_Z*/  Common_n_leptau_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_Z*/  Common_n_hadtau_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                           Common_n_nu_Z*/  Common_n_nu_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                            Common_n_b_Z*/  Common_n_b_Z_isLoaded = false;
//---------------------------------------------------------------------------------
/*                          Common_n_lep_W*/  Common_n_lep_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_W*/  Common_n_leptau_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_W*/  Common_n_hadtau_W_isLoaded = false;
//---------------------------------------------------------------------------------
/*                        Common_haslepWSS*/  Common_haslepWSS_isLoaded = false;
//---------------------------------------------------------------------------------
/*                            Common_genHT*/  Common_genHT_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Common_gen_n_light_lep*/  Common_gen_n_light_lep_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Common_gen_VH_channel*/  Common_gen_VH_channel_isLoaded = false;
//---------------------------------------------------------------------------------
/*                Cut_4LepMET_Preselection*/  Cut_4LepMET_Preselection_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/  Cut_4LepMET_emuChannel_isLoaded = false;
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/  Cut_4LepMET_offzChannel_isLoaded = false;
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/  Cut_4LepMET_onzChannel_isLoaded = false;
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/  Cut_4LepMET_onzChannel_HighMET_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/  Var_4LepMET_Zcand_lep_idx_0_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  Var_4LepMET_Zcand_lep_pdgid_0_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_0*/  Var_4LepMET_Zcand_lep_p4_0_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_1*/  Var_4LepMET_Zcand_lep_idx_1_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  Var_4LepMET_Zcand_lep_pdgid_1_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_1*/  Var_4LepMET_Zcand_lep_p4_1_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_Zcand_mll*/  Var_4LepMET_Zcand_mll_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_0*/  Var_4LepMET_other_lep_idx_0_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_0*/  Var_4LepMET_other_lep_pdgid_0_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_0*/  Var_4LepMET_other_lep_p4_0_isLoaded = false;
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_1*/  Var_4LepMET_other_lep_idx_1_isLoaded = false;
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_1*/  Var_4LepMET_other_lep_pdgid_1_isLoaded = false;
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_1*/  Var_4LepMET_other_lep_p4_1_isLoaded = false;
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_other_mll*/  Var_4LepMET_other_mll_isLoaded = false;
//---------------------------------------------------------------------------------
/*                         Var_4LepMET_mt2*/  Var_4LepMET_mt2_isLoaded = false;
//---------------------------------------------------------------------------------
}

void VVVTree::LoadAllBranches() {
  // load all branches
//---------------------------------------------------------------------------------
/*                           Common_isData*/  if (Common_isData_branch != 0) Common_isData();
//---------------------------------------------------------------------------------
/*                              Common_run*/  if (Common_run_branch != 0) Common_run();
//---------------------------------------------------------------------------------
/*                             Common_lumi*/  if (Common_lumi_branch != 0) Common_lumi();
//---------------------------------------------------------------------------------
/*                              Common_evt*/  if (Common_evt_branch != 0) Common_evt();
//---------------------------------------------------------------------------------
/*                        Common_genWeight*/  if (Common_genWeight_branch != 0) Common_genWeight();
//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/  if (Common_btagWeight_DeepCSVB_branch != 0) Common_btagWeight_DeepCSVB();
//---------------------------------------------------------------------------------
/*                              Common_wgt*/  if (Common_wgt_branch != 0) Common_wgt();
//---------------------------------------------------------------------------------
/*         Common_LHEWeight_mg_reweighting*/  if (Common_LHEWeight_mg_reweighting_branch != 0) Common_LHEWeight_mg_reweighting();
//---------------------------------------------------------------------------------
/*                   Common_event_puWeight*/  if (Common_event_puWeight_branch != 0) Common_event_puWeight();
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightup*/  if (Common_event_puWeightup_branch != 0) Common_event_puWeightup();
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightdn*/  if (Common_event_puWeightdn_branch != 0) Common_event_puWeightdn();
//---------------------------------------------------------------------------------
/*              Common_event_prefireWeight*/  if (Common_event_prefireWeight_branch != 0) Common_event_prefireWeight();
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightup*/  if (Common_event_prefireWeightup_branch != 0) Common_event_prefireWeightup();
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightdn*/  if (Common_event_prefireWeightdn_branch != 0) Common_event_prefireWeightdn();
//---------------------------------------------------------------------------------
/*              Common_event_triggerWeight*/  if (Common_event_triggerWeight_branch != 0) Common_event_triggerWeight();
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightup*/  if (Common_event_triggerWeightup_branch != 0) Common_event_triggerWeightup();
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightdn*/  if (Common_event_triggerWeightdn_branch != 0) Common_event_triggerWeightdn();
//---------------------------------------------------------------------------------
/*             Common_LHEReweightingWeight*/  if (Common_LHEReweightingWeight_branch != 0) Common_LHEReweightingWeight();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch != 0) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ();
//---------------------------------------------------------------------------------
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch != 0) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch != 0) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8();
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ();
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch != 0) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL();
//---------------------------------------------------------------------------------
/*                      Common_HLT_IsoMu24*/  if (Common_HLT_IsoMu24_branch != 0) Common_HLT_IsoMu24();
//---------------------------------------------------------------------------------
/*                Common_HLT_Ele32_WPTight*/  if (Common_HLT_Ele32_WPTight_branch != 0) Common_HLT_Ele32_WPTight();
//---------------------------------------------------------------------------------
/*                     Common_HLT_PFHT1050*/  if (Common_HLT_PFHT1050_branch != 0) Common_HLT_PFHT1050();
//---------------------------------------------------------------------------------
/*                  Common_HLT_AK8PFJet500*/  if (Common_HLT_AK8PFJet500_branch != 0) Common_HLT_AK8PFJet500();
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet380_TrimMass30*/  if (Common_HLT_AK8PFJet380_TrimMass30_branch != 0) Common_HLT_AK8PFJet380_TrimMass30();
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet360_TrimMass30*/  if (Common_HLT_AK8PFJet360_TrimMass30_branch != 0) Common_HLT_AK8PFJet360_TrimMass30();
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet400_TrimMass30*/  if (Common_HLT_AK8PFJet400_TrimMass30_branch != 0) Common_HLT_AK8PFJet400_TrimMass30();
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet420_TrimMass30*/  if (Common_HLT_AK8PFJet420_TrimMass30_branch != 0) Common_HLT_AK8PFJet420_TrimMass30();
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT750_TrimMass50*/  if (Common_HLT_AK8PFHT750_TrimMass50_branch != 0) Common_HLT_AK8PFHT750_TrimMass50();
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT800_TrimMass50*/  if (Common_HLT_AK8PFHT800_TrimMass50_branch != 0) Common_HLT_AK8PFHT800_TrimMass50();
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT850_TrimMass50*/  if (Common_HLT_AK8PFHT850_TrimMass50_branch != 0) Common_HLT_AK8PFHT850_TrimMass50();
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT900_TrimMass50*/  if (Common_HLT_AK8PFHT900_TrimMass50_branch != 0) Common_HLT_AK8PFHT900_TrimMass50();
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleEl*/  if (Common_HLT_DoubleEl_branch != 0) Common_HLT_DoubleEl();
//---------------------------------------------------------------------------------
/*                         Common_HLT_MuEG*/  if (Common_HLT_MuEG_branch != 0) Common_HLT_MuEG();
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleMu*/  if (Common_HLT_DoubleMu_branch != 0) Common_HLT_DoubleMu();
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_ee_em_mm*/  if (Common_pass_duplicate_removal_ee_em_mm_branch != 0) Common_pass_duplicate_removal_ee_em_mm();
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_mm_em_ee*/  if (Common_pass_duplicate_removal_mm_em_ee_branch != 0) Common_pass_duplicate_removal_mm_em_ee();
//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/  if (Common_noiseFlag_branch != 0) Common_noiseFlag();
//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/  if (Common_noiseFlagMC_branch != 0) Common_noiseFlagMC();
//---------------------------------------------------------------------------------
/*                      Common_passGoodRun*/  if (Common_passGoodRun_branch != 0) Common_passGoodRun();
//---------------------------------------------------------------------------------
/*                           Common_met_p4*/  if (Common_met_p4_branch != 0) Common_met_p4();
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesup*/  if (Common_met_p4_jesup_branch != 0) Common_met_p4_jesup();
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesdn*/  if (Common_met_p4_jesdn_branch != 0) Common_met_p4_jesdn();
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerup*/  if (Common_met_p4_jerup_branch != 0) Common_met_p4_jerup();
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerdn*/  if (Common_met_p4_jerdn_branch != 0) Common_met_p4_jerdn();
//---------------------------------------------------------------------------------
/*                      Common_event_lepSF*/  if (Common_event_lepSF_branch != 0) Common_event_lepSF();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFelup*/  if (Common_event_lepSFelup_branch != 0) Common_event_lepSFelup();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFeldn*/  if (Common_event_lepSFeldn_branch != 0) Common_event_lepSFeldn();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmuup*/  if (Common_event_lepSFmuup_branch != 0) Common_event_lepSFmuup();
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmudn*/  if (Common_event_lepSFmudn_branch != 0) Common_event_lepSFmudn();
//---------------------------------------------------------------------------------
/*                 Common_event_lepSFTight*/  if (Common_event_lepSFTight_branch != 0) Common_event_lepSFTight();
//---------------------------------------------------------------------------------
/*             Common_event_lepSFelupTight*/  if (Common_event_lepSFelupTight_branch != 0) Common_event_lepSFelupTight();
//---------------------------------------------------------------------------------
/*             Common_event_lepSFeldnTight*/  if (Common_event_lepSFeldnTight_branch != 0) Common_event_lepSFeldnTight();
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmuupTight*/  if (Common_event_lepSFmuupTight_branch != 0) Common_event_lepSFmuupTight();
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmudnTight*/  if (Common_event_lepSFmudnTight_branch != 0) Common_event_lepSFmudnTight();
//---------------------------------------------------------------------------------
/*                Common_event_tightBtagSF*/  if (Common_event_tightBtagSF_branch != 0) Common_event_tightBtagSF();
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFup*/  if (Common_event_tightBtagSFup_branch != 0) Common_event_tightBtagSFup();
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFdn*/  if (Common_event_tightBtagSFdn_branch != 0) Common_event_tightBtagSFdn();
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFup*/  if (Common_event_tightBtagSFHFup_branch != 0) Common_event_tightBtagSFHFup();
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFdn*/  if (Common_event_tightBtagSFHFdn_branch != 0) Common_event_tightBtagSFHFdn();
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFup*/  if (Common_event_tightBtagSFLFup_branch != 0) Common_event_tightBtagSFLFup();
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFdn*/  if (Common_event_tightBtagSFLFdn_branch != 0) Common_event_tightBtagSFLFdn();
//---------------------------------------------------------------------------------
/*               Common_event_mediumBtagSF*/  if (Common_event_mediumBtagSF_branch != 0) Common_event_mediumBtagSF();
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFup*/  if (Common_event_mediumBtagSFup_branch != 0) Common_event_mediumBtagSFup();
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFdn*/  if (Common_event_mediumBtagSFdn_branch != 0) Common_event_mediumBtagSFdn();
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFup*/  if (Common_event_mediumBtagSFHFup_branch != 0) Common_event_mediumBtagSFHFup();
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFdn*/  if (Common_event_mediumBtagSFHFdn_branch != 0) Common_event_mediumBtagSFHFdn();
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFup*/  if (Common_event_mediumBtagSFLFup_branch != 0) Common_event_mediumBtagSFLFup();
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFdn*/  if (Common_event_mediumBtagSFLFdn_branch != 0) Common_event_mediumBtagSFLFdn();
//---------------------------------------------------------------------------------
/*                Common_event_looseBtagSF*/  if (Common_event_looseBtagSF_branch != 0) Common_event_looseBtagSF();
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFup*/  if (Common_event_looseBtagSFup_branch != 0) Common_event_looseBtagSFup();
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFdn*/  if (Common_event_looseBtagSFdn_branch != 0) Common_event_looseBtagSFdn();
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFup*/  if (Common_event_looseBtagSFHFup_branch != 0) Common_event_looseBtagSFHFup();
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFdn*/  if (Common_event_looseBtagSFHFdn_branch != 0) Common_event_looseBtagSFHFdn();
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFup*/  if (Common_event_looseBtagSFLFup_branch != 0) Common_event_looseBtagSFLFup();
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFdn*/  if (Common_event_looseBtagSFLFdn_branch != 0) Common_event_looseBtagSFLFdn();
//---------------------------------------------------------------------------------
/*                           Common_lep_p4*/  if (Common_lep_p4_branch != 0) Common_lep_p4();
//---------------------------------------------------------------------------------
/*                         Common_lep_idxs*/  if (Common_lep_idxs_branch != 0) Common_lep_idxs();
//---------------------------------------------------------------------------------
/*                        Common_lep_pdgid*/  if (Common_lep_pdgid_branch != 0) Common_lep_pdgid();
//---------------------------------------------------------------------------------
/*                        Common_lep_tight*/  if (Common_lep_tight_branch != 0) Common_lep_tight();
//---------------------------------------------------------------------------------
/*                          Common_lep_dxy*/  if (Common_lep_dxy_branch != 0) Common_lep_dxy();
//---------------------------------------------------------------------------------
/*                           Common_lep_dz*/  if (Common_lep_dz_branch != 0) Common_lep_dz();
//---------------------------------------------------------------------------------
/*                         Common_lep_ip3d*/  if (Common_lep_ip3d_branch != 0) Common_lep_ip3d();
//---------------------------------------------------------------------------------
/*                        Common_lep_sip3d*/  if (Common_lep_sip3d_branch != 0) Common_lep_sip3d();
//---------------------------------------------------------------------------------
/*                           Common_lep_SF*/  if (Common_lep_SF_branch != 0) Common_lep_SF();
//---------------------------------------------------------------------------------
/*                      Common_lep_SFTight*/  if (Common_lep_SFTight_branch != 0) Common_lep_SFTight();
//---------------------------------------------------------------------------------
/*                         Common_lep_SFdn*/  if (Common_lep_SFdn_branch != 0) Common_lep_SFdn();
//---------------------------------------------------------------------------------
/*                    Common_lep_SFdnTight*/  if (Common_lep_SFdnTight_branch != 0) Common_lep_SFdnTight();
//---------------------------------------------------------------------------------
/*                         Common_lep_SFup*/  if (Common_lep_SFup_branch != 0) Common_lep_SFup();
//---------------------------------------------------------------------------------
/*                    Common_lep_SFupTight*/  if (Common_lep_SFupTight_branch != 0) Common_lep_SFupTight();
//---------------------------------------------------------------------------------
/*                           Common_jet_p4*/  if (Common_jet_p4_branch != 0) Common_jet_p4();
//---------------------------------------------------------------------------------
/*                         Common_jet_idxs*/  if (Common_jet_idxs_branch != 0) Common_jet_idxs();
//---------------------------------------------------------------------------------
/*                   Common_jet_passBloose*/  if (Common_jet_passBloose_branch != 0) Common_jet_passBloose();
//---------------------------------------------------------------------------------
/*                  Common_jet_passBmedium*/  if (Common_jet_passBmedium_branch != 0) Common_jet_passBmedium();
//---------------------------------------------------------------------------------
/*                   Common_jet_passBtight*/  if (Common_jet_passBtight_branch != 0) Common_jet_passBtight();
//---------------------------------------------------------------------------------
/*                           Common_jet_id*/  if (Common_jet_id_branch != 0) Common_jet_id();
//---------------------------------------------------------------------------------
/*                Common_jet_overlapfatjet*/  if (Common_jet_overlapfatjet_branch != 0) Common_jet_overlapfatjet();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesup*/  if (Common_jet_pt_jesup_branch != 0) Common_jet_pt_jesup();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesdn*/  if (Common_jet_pt_jesdn_branch != 0) Common_jet_pt_jesdn();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerup*/  if (Common_jet_pt_jerup_branch != 0) Common_jet_pt_jerup();
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerdn*/  if (Common_jet_pt_jerdn_branch != 0) Common_jet_pt_jerdn();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesup*/  if (Common_jet_mass_jesup_branch != 0) Common_jet_mass_jesup();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesdn*/  if (Common_jet_mass_jesdn_branch != 0) Common_jet_mass_jesdn();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerup*/  if (Common_jet_mass_jerup_branch != 0) Common_jet_mass_jerup();
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerdn*/  if (Common_jet_mass_jerdn_branch != 0) Common_jet_mass_jerdn();
//---------------------------------------------------------------------------------
/*                        Common_fatjet_p4*/  if (Common_fatjet_p4_branch != 0) Common_fatjet_p4();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_idxs*/  if (Common_fatjet_idxs_branch != 0) Common_fatjet_idxs();
//---------------------------------------------------------------------------------
/*                        Common_fatjet_id*/  if (Common_fatjet_id_branch != 0) Common_fatjet_id();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_msoftdrop*/  if (Common_fatjet_msoftdrop_branch != 0) Common_fatjet_msoftdrop();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_W*/  if (Common_fatjet_deepMD_W_branch != 0) Common_fatjet_deepMD_W();
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_W*/  if (Common_fatjet_deep_W_branch != 0) Common_fatjet_deep_W();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_Z*/  if (Common_fatjet_deepMD_Z_branch != 0) Common_fatjet_deepMD_Z();
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_Z*/  if (Common_fatjet_deep_Z_branch != 0) Common_fatjet_deep_Z();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_T*/  if (Common_fatjet_deepMD_T_branch != 0) Common_fatjet_deepMD_T();
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_T*/  if (Common_fatjet_deep_T_branch != 0) Common_fatjet_deep_T();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_deepMD_bb*/  if (Common_fatjet_deepMD_bb_branch != 0) Common_fatjet_deepMD_bb();
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNetMD_W*/  if (Common_fatjet_particleNetMD_W_branch != 0) Common_fatjet_particleNetMD_W();
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xqq*/  if (Common_fatjet_particleNetMD_Xqq_branch != 0) Common_fatjet_particleNetMD_Xqq();
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xcc*/  if (Common_fatjet_particleNetMD_Xcc_branch != 0) Common_fatjet_particleNetMD_Xcc();
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xbb*/  if (Common_fatjet_particleNetMD_Xbb_branch != 0) Common_fatjet_particleNetMD_Xbb();
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_QCD*/  if (Common_fatjet_particleNetMD_QCD_branch != 0) Common_fatjet_particleNetMD_QCD();
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNet_QCD*/  if (Common_fatjet_particleNet_QCD_branch != 0) Common_fatjet_particleNet_QCD();
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_W*/  if (Common_fatjet_particleNet_W_branch != 0) Common_fatjet_particleNet_W();
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_Z*/  if (Common_fatjet_particleNet_Z_branch != 0) Common_fatjet_particleNet_Z();
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_T*/  if (Common_fatjet_particleNet_T_branch != 0) Common_fatjet_particleNet_T();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau3*/  if (Common_fatjet_tau3_branch != 0) Common_fatjet_tau3();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau2*/  if (Common_fatjet_tau2_branch != 0) Common_fatjet_tau2();
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau1*/  if (Common_fatjet_tau1_branch != 0) Common_fatjet_tau1();
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau32*/  if (Common_fatjet_tau32_branch != 0) Common_fatjet_tau32();
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau21*/  if (Common_fatjet_tau21_branch != 0) Common_fatjet_tau21();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_pt*/  if (Common_fatjet_subjet0_pt_branch != 0) Common_fatjet_subjet0_pt();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_eta*/  if (Common_fatjet_subjet0_eta_branch != 0) Common_fatjet_subjet0_eta();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_phi*/  if (Common_fatjet_subjet0_phi_branch != 0) Common_fatjet_subjet0_phi();
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet0_mass*/  if (Common_fatjet_subjet0_mass_branch != 0) Common_fatjet_subjet0_mass();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_pt*/  if (Common_fatjet_subjet1_pt_branch != 0) Common_fatjet_subjet1_pt();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_eta*/  if (Common_fatjet_subjet1_eta_branch != 0) Common_fatjet_subjet1_eta();
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_phi*/  if (Common_fatjet_subjet1_phi_branch != 0) Common_fatjet_subjet1_phi();
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet1_mass*/  if (Common_fatjet_subjet1_mass_branch != 0) Common_fatjet_subjet1_mass();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_p4*/  if (Common_fatjet_subjet0_p4_branch != 0) Common_fatjet_subjet0_p4();
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_p4*/  if (Common_fatjet_subjet1_p4_branch != 0) Common_fatjet_subjet1_p4();
//---------------------------------------------------------------------------------
/*                        Common_fatjet_WP*/  if (Common_fatjet_WP_branch != 0) Common_fatjet_WP();
//---------------------------------------------------------------------------------
/*                     Common_fatjet_WP_MD*/  if (Common_fatjet_WP_MD_branch != 0) Common_fatjet_WP_MD();
//---------------------------------------------------------------------------------
/*            Common_fatjet_WP_antimasscut*/  if (Common_fatjet_WP_antimasscut_branch != 0) Common_fatjet_WP_antimasscut();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFVLoose*/  if (Common_fatjet_SFVLoose_branch != 0) Common_fatjet_SFVLoose();
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFLoose*/  if (Common_fatjet_SFLoose_branch != 0) Common_fatjet_SFLoose();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFMedium*/  if (Common_fatjet_SFMedium_branch != 0) Common_fatjet_SFMedium();
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFTight*/  if (Common_fatjet_SFTight_branch != 0) Common_fatjet_SFTight();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnVLoose*/  if (Common_fatjet_SFdnVLoose_branch != 0) Common_fatjet_SFdnVLoose();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnLoose*/  if (Common_fatjet_SFdnLoose_branch != 0) Common_fatjet_SFdnLoose();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnMedium*/  if (Common_fatjet_SFdnMedium_branch != 0) Common_fatjet_SFdnMedium();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnTight*/  if (Common_fatjet_SFdnTight_branch != 0) Common_fatjet_SFdnTight();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupVLoose*/  if (Common_fatjet_SFupVLoose_branch != 0) Common_fatjet_SFupVLoose();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupLoose*/  if (Common_fatjet_SFupLoose_branch != 0) Common_fatjet_SFupLoose();
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupMedium*/  if (Common_fatjet_SFupMedium_branch != 0) Common_fatjet_SFupMedium();
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupTight*/  if (Common_fatjet_SFupTight_branch != 0) Common_fatjet_SFupTight();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesup*/  if (Common_fatjet_pt_jesup_branch != 0) Common_fatjet_pt_jesup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesdn*/  if (Common_fatjet_pt_jesdn_branch != 0) Common_fatjet_pt_jesdn();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerup*/  if (Common_fatjet_pt_jerup_branch != 0) Common_fatjet_pt_jerup();
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerdn*/  if (Common_fatjet_pt_jerdn_branch != 0) Common_fatjet_pt_jerdn();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesup*/  if (Common_fatjet_msoftdrop_jesup_branch != 0) Common_fatjet_msoftdrop_jesup();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesdn*/  if (Common_fatjet_msoftdrop_jesdn_branch != 0) Common_fatjet_msoftdrop_jesdn();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerup*/  if (Common_fatjet_msoftdrop_jerup_branch != 0) Common_fatjet_msoftdrop_jerup();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerdn*/  if (Common_fatjet_msoftdrop_jerdn_branch != 0) Common_fatjet_msoftdrop_jerdn();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsup*/  if (Common_fatjet_msoftdrop_jmsup_branch != 0) Common_fatjet_msoftdrop_jmsup();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsdn*/  if (Common_fatjet_msoftdrop_jmsdn_branch != 0) Common_fatjet_msoftdrop_jmsdn();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrup*/  if (Common_fatjet_msoftdrop_jmrup_branch != 0) Common_fatjet_msoftdrop_jmrup();
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrdn*/  if (Common_fatjet_msoftdrop_jmrdn_branch != 0) Common_fatjet_msoftdrop_jmrdn();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesup*/  if (Common_fatjet_mass_jesup_branch != 0) Common_fatjet_mass_jesup();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesdn*/  if (Common_fatjet_mass_jesdn_branch != 0) Common_fatjet_mass_jesdn();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerup*/  if (Common_fatjet_mass_jerup_branch != 0) Common_fatjet_mass_jerup();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerdn*/  if (Common_fatjet_mass_jerdn_branch != 0) Common_fatjet_mass_jerdn();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsup*/  if (Common_fatjet_mass_jmsup_branch != 0) Common_fatjet_mass_jmsup();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsdn*/  if (Common_fatjet_mass_jmsdn_branch != 0) Common_fatjet_mass_jmsdn();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrup*/  if (Common_fatjet_mass_jmrup_branch != 0) Common_fatjet_mass_jmrup();
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrdn*/  if (Common_fatjet_mass_jmrdn_branch != 0) Common_fatjet_mass_jmrdn();
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFVLoose*/  if (Common_eventweight_fatjet_SFVLoose_branch != 0) Common_eventweight_fatjet_SFVLoose();
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFLoose*/  if (Common_eventweight_fatjet_SFLoose_branch != 0) Common_eventweight_fatjet_SFLoose();
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFMedium*/  if (Common_eventweight_fatjet_SFMedium_branch != 0) Common_eventweight_fatjet_SFMedium();
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFTight*/  if (Common_eventweight_fatjet_SFTight_branch != 0) Common_eventweight_fatjet_SFTight();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnVLoose*/  if (Common_eventweight_fatjet_SFdnVLoose_branch != 0) Common_eventweight_fatjet_SFdnVLoose();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnLoose*/  if (Common_eventweight_fatjet_SFdnLoose_branch != 0) Common_eventweight_fatjet_SFdnLoose();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnMedium*/  if (Common_eventweight_fatjet_SFdnMedium_branch != 0) Common_eventweight_fatjet_SFdnMedium();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnTight*/  if (Common_eventweight_fatjet_SFdnTight_branch != 0) Common_eventweight_fatjet_SFdnTight();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupVLoose*/  if (Common_eventweight_fatjet_SFupVLoose_branch != 0) Common_eventweight_fatjet_SFupVLoose();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupLoose*/  if (Common_eventweight_fatjet_SFupLoose_branch != 0) Common_eventweight_fatjet_SFupLoose();
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupMedium*/  if (Common_eventweight_fatjet_SFupMedium_branch != 0) Common_eventweight_fatjet_SFupMedium();
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupTight*/  if (Common_eventweight_fatjet_SFupTight_branch != 0) Common_eventweight_fatjet_SFupTight();
//---------------------------------------------------------------------------------
/*                         Common_nb_loose*/  if (Common_nb_loose_branch != 0) Common_nb_loose();
//---------------------------------------------------------------------------------
/*                        Common_nb_medium*/  if (Common_nb_medium_branch != 0) Common_nb_medium();
//---------------------------------------------------------------------------------
/*                         Common_nb_tight*/  if (Common_nb_tight_branch != 0) Common_nb_tight();
//---------------------------------------------------------------------------------
/*                          Common_gen_idx*/  if (Common_gen_idx_branch != 0) Common_gen_idx();
//---------------------------------------------------------------------------------
/*                   Common_gen_mother_idx*/  if (Common_gen_mother_idx_branch != 0) Common_gen_mother_idx();
//---------------------------------------------------------------------------------
/*                    Common_gen_mother_id*/  if (Common_gen_mother_id_branch != 0) Common_gen_mother_id();
//---------------------------------------------------------------------------------
/*                        Common_gen_pdgid*/  if (Common_gen_pdgid_branch != 0) Common_gen_pdgid();
//---------------------------------------------------------------------------------
/*                          Common_gen_p4s*/  if (Common_gen_p4s_branch != 0) Common_gen_p4s();
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_idx*/  if (Common_gen_vvvdecay_idx_branch != 0) Common_gen_vvvdecay_idx();
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_mother_idx*/  if (Common_gen_vvvdecay_mother_idx_branch != 0) Common_gen_vvvdecay_mother_idx();
//---------------------------------------------------------------------------------
/*           Common_gen_vvvdecay_mother_id*/  if (Common_gen_vvvdecay_mother_id_branch != 0) Common_gen_vvvdecay_mother_id();
//---------------------------------------------------------------------------------
/*               Common_gen_vvvdecay_pdgid*/  if (Common_gen_vvvdecay_pdgid_branch != 0) Common_gen_vvvdecay_pdgid();
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_p4s*/  if (Common_gen_vvvdecay_p4s_branch != 0) Common_gen_vvvdecay_p4s();
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_taudecayid*/  if (Common_gen_vvvdecay_taudecayid_branch != 0) Common_gen_vvvdecay_taudecayid();
//---------------------------------------------------------------------------------
/*                         Common_isSignal*/  if (Common_isSignal_branch != 0) Common_isSignal();
//---------------------------------------------------------------------------------
/*                              Common_n_W*/  if (Common_n_W_branch != 0) Common_n_W();
//---------------------------------------------------------------------------------
/*                              Common_n_Z*/  if (Common_n_Z_branch != 0) Common_n_Z();
//---------------------------------------------------------------------------------
/*                          Common_n_lep_Z*/  if (Common_n_lep_Z_branch != 0) Common_n_lep_Z();
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_Z*/  if (Common_n_leptau_Z_branch != 0) Common_n_leptau_Z();
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_Z*/  if (Common_n_hadtau_Z_branch != 0) Common_n_hadtau_Z();
//---------------------------------------------------------------------------------
/*                           Common_n_nu_Z*/  if (Common_n_nu_Z_branch != 0) Common_n_nu_Z();
//---------------------------------------------------------------------------------
/*                            Common_n_b_Z*/  if (Common_n_b_Z_branch != 0) Common_n_b_Z();
//---------------------------------------------------------------------------------
/*                          Common_n_lep_W*/  if (Common_n_lep_W_branch != 0) Common_n_lep_W();
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_W*/  if (Common_n_leptau_W_branch != 0) Common_n_leptau_W();
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_W*/  if (Common_n_hadtau_W_branch != 0) Common_n_hadtau_W();
//---------------------------------------------------------------------------------
/*                        Common_haslepWSS*/  if (Common_haslepWSS_branch != 0) Common_haslepWSS();
//---------------------------------------------------------------------------------
/*                            Common_genHT*/  if (Common_genHT_branch != 0) Common_genHT();
//---------------------------------------------------------------------------------
/*                  Common_gen_n_light_lep*/  if (Common_gen_n_light_lep_branch != 0) Common_gen_n_light_lep();
//---------------------------------------------------------------------------------
/*                   Common_gen_VH_channel*/  if (Common_gen_VH_channel_branch != 0) Common_gen_VH_channel();
//---------------------------------------------------------------------------------
/*                Cut_4LepMET_Preselection*/  if (Cut_4LepMET_Preselection_branch != 0) Cut_4LepMET_Preselection();
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/  if (Cut_4LepMET_emuChannel_branch != 0) Cut_4LepMET_emuChannel();
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/  if (Cut_4LepMET_offzChannel_branch != 0) Cut_4LepMET_offzChannel();
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/  if (Cut_4LepMET_onzChannel_branch != 0) Cut_4LepMET_onzChannel();
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/  if (Cut_4LepMET_onzChannel_HighMET_branch != 0) Cut_4LepMET_onzChannel_HighMET();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/  if (Var_4LepMET_Zcand_lep_idx_0_branch != 0) Var_4LepMET_Zcand_lep_idx_0();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  if (Var_4LepMET_Zcand_lep_pdgid_0_branch != 0) Var_4LepMET_Zcand_lep_pdgid_0();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_0*/  if (Var_4LepMET_Zcand_lep_p4_0_branch != 0) Var_4LepMET_Zcand_lep_p4_0();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_1*/  if (Var_4LepMET_Zcand_lep_idx_1_branch != 0) Var_4LepMET_Zcand_lep_idx_1();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  if (Var_4LepMET_Zcand_lep_pdgid_1_branch != 0) Var_4LepMET_Zcand_lep_pdgid_1();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_1*/  if (Var_4LepMET_Zcand_lep_p4_1_branch != 0) Var_4LepMET_Zcand_lep_p4_1();
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_Zcand_mll*/  if (Var_4LepMET_Zcand_mll_branch != 0) Var_4LepMET_Zcand_mll();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_0*/  if (Var_4LepMET_other_lep_idx_0_branch != 0) Var_4LepMET_other_lep_idx_0();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_0*/  if (Var_4LepMET_other_lep_pdgid_0_branch != 0) Var_4LepMET_other_lep_pdgid_0();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_0*/  if (Var_4LepMET_other_lep_p4_0_branch != 0) Var_4LepMET_other_lep_p4_0();
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_1*/  if (Var_4LepMET_other_lep_idx_1_branch != 0) Var_4LepMET_other_lep_idx_1();
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_1*/  if (Var_4LepMET_other_lep_pdgid_1_branch != 0) Var_4LepMET_other_lep_pdgid_1();
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_1*/  if (Var_4LepMET_other_lep_p4_1_branch != 0) Var_4LepMET_other_lep_p4_1();
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_other_mll*/  if (Var_4LepMET_other_mll_branch != 0) Var_4LepMET_other_mll();
//---------------------------------------------------------------------------------
/*                         Var_4LepMET_mt2*/  if (Var_4LepMET_mt2_branch != 0) Var_4LepMET_mt2();
//---------------------------------------------------------------------------------
}

//---------------------------------------------------------------------------------
/*                           Common_isData*/const int &VVVTree::Common_isData() {
/*                           Common_isData*/  if (not Common_isData_isLoaded) {
/*                           Common_isData*/    if (Common_isData_branch != 0) {
/*                           Common_isData*/      Common_isData_branch->GetEntry(index);
/*                           Common_isData*/    } else {
/*                           Common_isData*/      printf("branch Common_isData_branch does not exist!\n");
/*                           Common_isData*/      exit(1);
/*                           Common_isData*/    }
/*                           Common_isData*/    Common_isData_isLoaded = true;
/*                           Common_isData*/  }
/*                           Common_isData*/  return Common_isData_;
/*                           Common_isData*/}

//---------------------------------------------------------------------------------
/*                              Common_run*/const int &VVVTree::Common_run() {
/*                              Common_run*/  if (not Common_run_isLoaded) {
/*                              Common_run*/    if (Common_run_branch != 0) {
/*                              Common_run*/      Common_run_branch->GetEntry(index);
/*                              Common_run*/    } else {
/*                              Common_run*/      printf("branch Common_run_branch does not exist!\n");
/*                              Common_run*/      exit(1);
/*                              Common_run*/    }
/*                              Common_run*/    Common_run_isLoaded = true;
/*                              Common_run*/  }
/*                              Common_run*/  return Common_run_;
/*                              Common_run*/}

//---------------------------------------------------------------------------------
/*                             Common_lumi*/const int &VVVTree::Common_lumi() {
/*                             Common_lumi*/  if (not Common_lumi_isLoaded) {
/*                             Common_lumi*/    if (Common_lumi_branch != 0) {
/*                             Common_lumi*/      Common_lumi_branch->GetEntry(index);
/*                             Common_lumi*/    } else {
/*                             Common_lumi*/      printf("branch Common_lumi_branch does not exist!\n");
/*                             Common_lumi*/      exit(1);
/*                             Common_lumi*/    }
/*                             Common_lumi*/    Common_lumi_isLoaded = true;
/*                             Common_lumi*/  }
/*                             Common_lumi*/  return Common_lumi_;
/*                             Common_lumi*/}

//---------------------------------------------------------------------------------
/*                              Common_evt*/const unsigned long long &VVVTree::Common_evt() {
/*                              Common_evt*/  if (not Common_evt_isLoaded) {
/*                              Common_evt*/    if (Common_evt_branch != 0) {
/*                              Common_evt*/      Common_evt_branch->GetEntry(index);
/*                              Common_evt*/    } else {
/*                              Common_evt*/      printf("branch Common_evt_branch does not exist!\n");
/*                              Common_evt*/      exit(1);
/*                              Common_evt*/    }
/*                              Common_evt*/    Common_evt_isLoaded = true;
/*                              Common_evt*/  }
/*                              Common_evt*/  return Common_evt_;
/*                              Common_evt*/}

//---------------------------------------------------------------------------------
/*                        Common_genWeight*/const float &VVVTree::Common_genWeight() {
/*                        Common_genWeight*/  if (not Common_genWeight_isLoaded) {
/*                        Common_genWeight*/    if (Common_genWeight_branch != 0) {
/*                        Common_genWeight*/      Common_genWeight_branch->GetEntry(index);
/*                        Common_genWeight*/    } else {
/*                        Common_genWeight*/      printf("branch Common_genWeight_branch does not exist!\n");
/*                        Common_genWeight*/      exit(1);
/*                        Common_genWeight*/    }
/*                        Common_genWeight*/    Common_genWeight_isLoaded = true;
/*                        Common_genWeight*/  }
/*                        Common_genWeight*/  return Common_genWeight_;
/*                        Common_genWeight*/}

//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/const float &VVVTree::Common_btagWeight_DeepCSVB() {
/*              Common_btagWeight_DeepCSVB*/  if (not Common_btagWeight_DeepCSVB_isLoaded) {
/*              Common_btagWeight_DeepCSVB*/    if (Common_btagWeight_DeepCSVB_branch != 0) {
/*              Common_btagWeight_DeepCSVB*/      Common_btagWeight_DeepCSVB_branch->GetEntry(index);
/*              Common_btagWeight_DeepCSVB*/    } else {
/*              Common_btagWeight_DeepCSVB*/      printf("branch Common_btagWeight_DeepCSVB_branch does not exist!\n");
/*              Common_btagWeight_DeepCSVB*/      exit(1);
/*              Common_btagWeight_DeepCSVB*/    }
/*              Common_btagWeight_DeepCSVB*/    Common_btagWeight_DeepCSVB_isLoaded = true;
/*              Common_btagWeight_DeepCSVB*/  }
/*              Common_btagWeight_DeepCSVB*/  return Common_btagWeight_DeepCSVB_;
/*              Common_btagWeight_DeepCSVB*/}

//---------------------------------------------------------------------------------
/*                              Common_wgt*/const float &VVVTree::Common_wgt() {
/*                              Common_wgt*/  if (not Common_wgt_isLoaded) {
/*                              Common_wgt*/    if (Common_wgt_branch != 0) {
/*                              Common_wgt*/      Common_wgt_branch->GetEntry(index);
/*                              Common_wgt*/    } else {
/*                              Common_wgt*/      printf("branch Common_wgt_branch does not exist!\n");
/*                              Common_wgt*/      exit(1);
/*                              Common_wgt*/    }
/*                              Common_wgt*/    Common_wgt_isLoaded = true;
/*                              Common_wgt*/  }
/*                              Common_wgt*/  return Common_wgt_;
/*                              Common_wgt*/}

//---------------------------------------------------------------------------------
/*         Common_LHEWeight_mg_reweighting*/const vector<float> &VVVTree::Common_LHEWeight_mg_reweighting() {
/*         Common_LHEWeight_mg_reweighting*/  if (not Common_LHEWeight_mg_reweighting_isLoaded) {
/*         Common_LHEWeight_mg_reweighting*/    if (Common_LHEWeight_mg_reweighting_branch != 0) {
/*         Common_LHEWeight_mg_reweighting*/      Common_LHEWeight_mg_reweighting_branch->GetEntry(index);
/*         Common_LHEWeight_mg_reweighting*/    } else {
/*         Common_LHEWeight_mg_reweighting*/      printf("branch Common_LHEWeight_mg_reweighting_branch does not exist!\n");
/*         Common_LHEWeight_mg_reweighting*/      exit(1);
/*         Common_LHEWeight_mg_reweighting*/    }
/*         Common_LHEWeight_mg_reweighting*/    Common_LHEWeight_mg_reweighting_isLoaded = true;
/*         Common_LHEWeight_mg_reweighting*/  }
/*         Common_LHEWeight_mg_reweighting*/  return *Common_LHEWeight_mg_reweighting_;
/*         Common_LHEWeight_mg_reweighting*/}

//---------------------------------------------------------------------------------
/*                   Common_event_puWeight*/const float &VVVTree::Common_event_puWeight() {
/*                   Common_event_puWeight*/  if (not Common_event_puWeight_isLoaded) {
/*                   Common_event_puWeight*/    if (Common_event_puWeight_branch != 0) {
/*                   Common_event_puWeight*/      Common_event_puWeight_branch->GetEntry(index);
/*                   Common_event_puWeight*/    } else {
/*                   Common_event_puWeight*/      printf("branch Common_event_puWeight_branch does not exist!\n");
/*                   Common_event_puWeight*/      exit(1);
/*                   Common_event_puWeight*/    }
/*                   Common_event_puWeight*/    Common_event_puWeight_isLoaded = true;
/*                   Common_event_puWeight*/  }
/*                   Common_event_puWeight*/  return Common_event_puWeight_;
/*                   Common_event_puWeight*/}

//---------------------------------------------------------------------------------
/*             Common_LHEReweightingWeight*/const vector<float> &VVVTree::Common_LHEReweightingWeight() {
/*             Common_LHEReweightingWeight*/  if (not Common_LHEReweightingWeight_isLoaded) {
/*             Common_LHEReweightingWeight*/    if (Common_LHEReweightingWeight_branch != 0) {
/*             Common_LHEReweightingWeight*/      Common_LHEReweightingWeight_branch->GetEntry(index);
/*             Common_LHEReweightingWeight*/    } else {
/*             Common_LHEReweightingWeight*/      printf("branch Common_LHEReweightingWeight_branch does not exist!\n");
/*             Common_LHEReweightingWeight*/      //exit(1);
/*             Common_LHEReweightingWeight*/    }
/*             Common_LHEReweightingWeight*/    Common_LHEReweightingWeight_isLoaded = true;
/*             Common_LHEReweightingWeight*/  }
/*             Common_LHEReweightingWeight*/  return *Common_LHEReweightingWeight_;
/*             Common_LHEReweightingWeight*/}

//---------------------------------------------------------------------------------
/*                 Common_event_puWeightup*/const float &VVVTree::Common_event_puWeightup() {
/*                 Common_event_puWeightup*/  if (not Common_event_puWeightup_isLoaded) {
/*                 Common_event_puWeightup*/    if (Common_event_puWeightup_branch != 0) {
/*                 Common_event_puWeightup*/      Common_event_puWeightup_branch->GetEntry(index);
/*                 Common_event_puWeightup*/    } else {
/*                 Common_event_puWeightup*/      printf("branch Common_event_puWeightup_branch does not exist!\n");
/*                 Common_event_puWeightup*/      exit(1);
/*                 Common_event_puWeightup*/    }
/*                 Common_event_puWeightup*/    Common_event_puWeightup_isLoaded = true;
/*                 Common_event_puWeightup*/  }
/*                 Common_event_puWeightup*/  return Common_event_puWeightup_;
/*                 Common_event_puWeightup*/}

//---------------------------------------------------------------------------------
/*                 Common_event_puWeightdn*/const float &VVVTree::Common_event_puWeightdn() {
/*                 Common_event_puWeightdn*/  if (not Common_event_puWeightdn_isLoaded) {
/*                 Common_event_puWeightdn*/    if (Common_event_puWeightdn_branch != 0) {
/*                 Common_event_puWeightdn*/      Common_event_puWeightdn_branch->GetEntry(index);
/*                 Common_event_puWeightdn*/    } else {
/*                 Common_event_puWeightdn*/      printf("branch Common_event_puWeightdn_branch does not exist!\n");
/*                 Common_event_puWeightdn*/      exit(1);
/*                 Common_event_puWeightdn*/    }
/*                 Common_event_puWeightdn*/    Common_event_puWeightdn_isLoaded = true;
/*                 Common_event_puWeightdn*/  }
/*                 Common_event_puWeightdn*/  return Common_event_puWeightdn_;
/*                 Common_event_puWeightdn*/}

//---------------------------------------------------------------------------------
/*              Common_event_prefireWeight*/const float &VVVTree::Common_event_prefireWeight() {
/*              Common_event_prefireWeight*/  if (not Common_event_prefireWeight_isLoaded) {
/*              Common_event_prefireWeight*/    if (Common_event_prefireWeight_branch != 0) {
/*              Common_event_prefireWeight*/      Common_event_prefireWeight_branch->GetEntry(index);
/*              Common_event_prefireWeight*/    } else {
/*              Common_event_prefireWeight*/      printf("branch Common_event_prefireWeight_branch does not exist!\n");
/*              Common_event_prefireWeight*/      exit(1);
/*              Common_event_prefireWeight*/    }
/*              Common_event_prefireWeight*/    Common_event_prefireWeight_isLoaded = true;
/*              Common_event_prefireWeight*/  }
/*              Common_event_prefireWeight*/  return Common_event_prefireWeight_;
/*              Common_event_prefireWeight*/}

//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightup*/const float &VVVTree::Common_event_prefireWeightup() {
/*            Common_event_prefireWeightup*/  if (not Common_event_prefireWeightup_isLoaded) {
/*            Common_event_prefireWeightup*/    if (Common_event_prefireWeightup_branch != 0) {
/*            Common_event_prefireWeightup*/      Common_event_prefireWeightup_branch->GetEntry(index);
/*            Common_event_prefireWeightup*/    } else {
/*            Common_event_prefireWeightup*/      printf("branch Common_event_prefireWeightup_branch does not exist!\n");
/*            Common_event_prefireWeightup*/      exit(1);
/*            Common_event_prefireWeightup*/    }
/*            Common_event_prefireWeightup*/    Common_event_prefireWeightup_isLoaded = true;
/*            Common_event_prefireWeightup*/  }
/*            Common_event_prefireWeightup*/  return Common_event_prefireWeightup_;
/*            Common_event_prefireWeightup*/}

//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightdn*/const float &VVVTree::Common_event_prefireWeightdn() {
/*            Common_event_prefireWeightdn*/  if (not Common_event_prefireWeightdn_isLoaded) {
/*            Common_event_prefireWeightdn*/    if (Common_event_prefireWeightdn_branch != 0) {
/*            Common_event_prefireWeightdn*/      Common_event_prefireWeightdn_branch->GetEntry(index);
/*            Common_event_prefireWeightdn*/    } else {
/*            Common_event_prefireWeightdn*/      printf("branch Common_event_prefireWeightdn_branch does not exist!\n");
/*            Common_event_prefireWeightdn*/      exit(1);
/*            Common_event_prefireWeightdn*/    }
/*            Common_event_prefireWeightdn*/    Common_event_prefireWeightdn_isLoaded = true;
/*            Common_event_prefireWeightdn*/  }
/*            Common_event_prefireWeightdn*/  return Common_event_prefireWeightdn_;
/*            Common_event_prefireWeightdn*/}

//---------------------------------------------------------------------------------
/*              Common_event_triggerWeight*/const float &VVVTree::Common_event_triggerWeight() {
/*              Common_event_triggerWeight*/  if (not Common_event_triggerWeight_isLoaded) {
/*              Common_event_triggerWeight*/    if (Common_event_triggerWeight_branch != 0) {
/*              Common_event_triggerWeight*/      Common_event_triggerWeight_branch->GetEntry(index);
/*              Common_event_triggerWeight*/    } else {
/*              Common_event_triggerWeight*/      printf("branch Common_event_triggerWeight_branch does not exist!\n");
/*              Common_event_triggerWeight*/      exit(1);
/*              Common_event_triggerWeight*/    }
/*              Common_event_triggerWeight*/    Common_event_triggerWeight_isLoaded = true;
/*              Common_event_triggerWeight*/  }
/*              Common_event_triggerWeight*/  return Common_event_triggerWeight_;
/*              Common_event_triggerWeight*/}

//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightup*/const float &VVVTree::Common_event_triggerWeightup() {
/*            Common_event_triggerWeightup*/  if (not Common_event_triggerWeightup_isLoaded) {
/*            Common_event_triggerWeightup*/    if (Common_event_triggerWeightup_branch != 0) {
/*            Common_event_triggerWeightup*/      Common_event_triggerWeightup_branch->GetEntry(index);
/*            Common_event_triggerWeightup*/    } else {
/*            Common_event_triggerWeightup*/      printf("branch Common_event_triggerWeightup_branch does not exist!\n");
/*            Common_event_triggerWeightup*/      exit(1);
/*            Common_event_triggerWeightup*/    }
/*            Common_event_triggerWeightup*/    Common_event_triggerWeightup_isLoaded = true;
/*            Common_event_triggerWeightup*/  }
/*            Common_event_triggerWeightup*/  return Common_event_triggerWeightup_;
/*            Common_event_triggerWeightup*/}

//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightdn*/const float &VVVTree::Common_event_triggerWeightdn() {
/*            Common_event_triggerWeightdn*/  if (not Common_event_triggerWeightdn_isLoaded) {
/*            Common_event_triggerWeightdn*/    if (Common_event_triggerWeightdn_branch != 0) {
/*            Common_event_triggerWeightdn*/      Common_event_triggerWeightdn_branch->GetEntry(index);
/*            Common_event_triggerWeightdn*/    } else {
/*            Common_event_triggerWeightdn*/      printf("branch Common_event_triggerWeightdn_branch does not exist!\n");
/*            Common_event_triggerWeightdn*/      exit(1);
/*            Common_event_triggerWeightdn*/    }
/*            Common_event_triggerWeightdn*/    Common_event_triggerWeightdn_isLoaded = true;
/*            Common_event_triggerWeightdn*/  }
/*            Common_event_triggerWeightdn*/  return Common_event_triggerWeightdn_;
/*            Common_event_triggerWeightdn*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/const bool &VVVTree::Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ() {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  if (not Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_isLoaded) {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/    if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch != 0) {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/      Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch->GetEntry(index);
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/    } else {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/      printf("branch Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch does not exist!\n");
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/      exit(1);
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/    }
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/    Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_isLoaded = true;
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  }
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/  return Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_;
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/}

//---------------------------------------------------------------------------------
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/const bool &VVVTree::Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL() {
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  if (not Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_isLoaded) {
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/    if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch != 0) {
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/      Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch->GetEntry(index);
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/    } else {
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/      printf("branch Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch does not exist!\n");
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/      exit(1);
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/    }
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/    Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_isLoaded = true;
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  }
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/  return Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_;
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/const bool &VVVTree::Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8() {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  if (not Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_isLoaded) {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/    if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch != 0) {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/      Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch->GetEntry(index);
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/    } else {
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/      printf("branch Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch does not exist!\n");
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/      exit(1);
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/    }
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/    Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_isLoaded = true;
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  }
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/  return Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_;
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/const bool &VVVTree::Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  if (not Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded) {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/      Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch->GetEntry(index);
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    } else {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/      printf("branch Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch does not exist!\n");
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/      exit(1);
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    }
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = true;
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  }
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  return Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_;
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/const bool &VVVTree::Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL() {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  if (not Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded) {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/    if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/      Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch->GetEntry(index);
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/    } else {
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/      printf("branch Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch does not exist!\n");
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/      exit(1);
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/    }
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/    Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = true;
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  }
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/  return Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_;
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/const bool &VVVTree::Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  if (not Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded) {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/      Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch->GetEntry(index);
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    } else {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/      printf("branch Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch does not exist!\n");
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/      exit(1);
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    }
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/    Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = true;
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  }
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/  return Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_;
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/const bool &VVVTree::Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL() {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  if (not Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded) {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/    if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/      Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch->GetEntry(index);
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/    } else {
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/      printf("branch Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch does not exist!\n");
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/      exit(1);
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/    }
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/    Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = true;
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  }
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/  return Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_;
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/const bool &VVVTree::Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ() {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  if (not Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded) {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/    if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/      Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch->GetEntry(index);
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/    } else {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/      printf("branch Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch does not exist!\n");
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/      exit(1);
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/    }
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/    Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = true;
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  }
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/  return Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_;
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/}

//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/const bool &VVVTree::Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL() {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  if (not Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_isLoaded) {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/    if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch != 0) {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/      Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch->GetEntry(index);
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/    } else {
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/      printf("branch Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch does not exist!\n");
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/      exit(1);
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/    }
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/    Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_isLoaded = true;
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  }
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/  return Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_;
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/}

//---------------------------------------------------------------------------------
/*                      Common_HLT_IsoMu24*/const bool &VVVTree::Common_HLT_IsoMu24() {
/*                      Common_HLT_IsoMu24*/  if (not Common_HLT_IsoMu24_isLoaded) {
/*                      Common_HLT_IsoMu24*/    if (Common_HLT_IsoMu24_branch != 0) {
/*                      Common_HLT_IsoMu24*/      Common_HLT_IsoMu24_branch->GetEntry(index);
/*                      Common_HLT_IsoMu24*/    } else {
/*                      Common_HLT_IsoMu24*/      printf("branch Common_HLT_IsoMu24_branch does not exist!\n");
/*                      Common_HLT_IsoMu24*/      exit(1);
/*                      Common_HLT_IsoMu24*/    }
/*                      Common_HLT_IsoMu24*/    Common_HLT_IsoMu24_isLoaded = true;
/*                      Common_HLT_IsoMu24*/  }
/*                      Common_HLT_IsoMu24*/  return Common_HLT_IsoMu24_;
/*                      Common_HLT_IsoMu24*/}

//---------------------------------------------------------------------------------
/*                Common_HLT_Ele32_WPTight*/const bool &VVVTree::Common_HLT_Ele32_WPTight() {
/*                Common_HLT_Ele32_WPTight*/  if (not Common_HLT_Ele32_WPTight_isLoaded) {
/*                Common_HLT_Ele32_WPTight*/    if (Common_HLT_Ele32_WPTight_branch != 0) {
/*                Common_HLT_Ele32_WPTight*/      Common_HLT_Ele32_WPTight_branch->GetEntry(index);
/*                Common_HLT_Ele32_WPTight*/    } else {
/*                Common_HLT_Ele32_WPTight*/      printf("branch Common_HLT_Ele32_WPTight_branch does not exist!\n");
/*                Common_HLT_Ele32_WPTight*/      exit(1);
/*                Common_HLT_Ele32_WPTight*/    }
/*                Common_HLT_Ele32_WPTight*/    Common_HLT_Ele32_WPTight_isLoaded = true;
/*                Common_HLT_Ele32_WPTight*/  }
/*                Common_HLT_Ele32_WPTight*/  return Common_HLT_Ele32_WPTight_;
/*                Common_HLT_Ele32_WPTight*/}

//---------------------------------------------------------------------------------
/*                     Common_HLT_PFHT1050*/const bool &VVVTree::Common_HLT_PFHT1050() {
/*                     Common_HLT_PFHT1050*/  if (not Common_HLT_PFHT1050_isLoaded) {
/*                     Common_HLT_PFHT1050*/    if (Common_HLT_PFHT1050_branch != 0) {
/*                     Common_HLT_PFHT1050*/      Common_HLT_PFHT1050_branch->GetEntry(index);
/*                     Common_HLT_PFHT1050*/    } else {
/*                     Common_HLT_PFHT1050*/      printf("branch Common_HLT_PFHT1050_branch does not exist!\n");
/*                     Common_HLT_PFHT1050*/      exit(1);
/*                     Common_HLT_PFHT1050*/    }
/*                     Common_HLT_PFHT1050*/    Common_HLT_PFHT1050_isLoaded = true;
/*                     Common_HLT_PFHT1050*/  }
/*                     Common_HLT_PFHT1050*/  return Common_HLT_PFHT1050_;
/*                     Common_HLT_PFHT1050*/}

//---------------------------------------------------------------------------------
/*                  Common_HLT_AK8PFJet500*/const bool &VVVTree::Common_HLT_AK8PFJet500() {
/*                  Common_HLT_AK8PFJet500*/  if (not Common_HLT_AK8PFJet500_isLoaded) {
/*                  Common_HLT_AK8PFJet500*/    if (Common_HLT_AK8PFJet500_branch != 0) {
/*                  Common_HLT_AK8PFJet500*/      Common_HLT_AK8PFJet500_branch->GetEntry(index);
/*                  Common_HLT_AK8PFJet500*/    } else {
/*                  Common_HLT_AK8PFJet500*/      printf("branch Common_HLT_AK8PFJet500_branch does not exist!\n");
/*                  Common_HLT_AK8PFJet500*/      exit(1);
/*                  Common_HLT_AK8PFJet500*/    }
/*                  Common_HLT_AK8PFJet500*/    Common_HLT_AK8PFJet500_isLoaded = true;
/*                  Common_HLT_AK8PFJet500*/  }
/*                  Common_HLT_AK8PFJet500*/  return Common_HLT_AK8PFJet500_;
/*                  Common_HLT_AK8PFJet500*/}

//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet380_TrimMass30*/const bool &VVVTree::Common_HLT_AK8PFJet380_TrimMass30() {
/*       Common_HLT_AK8PFJet380_TrimMass30*/  if (not Common_HLT_AK8PFJet380_TrimMass30_isLoaded) {
/*       Common_HLT_AK8PFJet380_TrimMass30*/    if (Common_HLT_AK8PFJet380_TrimMass30_branch != 0) {
/*       Common_HLT_AK8PFJet380_TrimMass30*/      Common_HLT_AK8PFJet380_TrimMass30_branch->GetEntry(index);
/*       Common_HLT_AK8PFJet380_TrimMass30*/    } else {
/*       Common_HLT_AK8PFJet380_TrimMass30*/      printf("branch Common_HLT_AK8PFJet380_TrimMass30_branch does not exist!\n");
/*       Common_HLT_AK8PFJet380_TrimMass30*/      exit(1);
/*       Common_HLT_AK8PFJet380_TrimMass30*/    }
/*       Common_HLT_AK8PFJet380_TrimMass30*/    Common_HLT_AK8PFJet380_TrimMass30_isLoaded = true;
/*       Common_HLT_AK8PFJet380_TrimMass30*/  }
/*       Common_HLT_AK8PFJet380_TrimMass30*/  return Common_HLT_AK8PFJet380_TrimMass30_;
/*       Common_HLT_AK8PFJet380_TrimMass30*/}

//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet360_TrimMass30*/const bool &VVVTree::Common_HLT_AK8PFJet360_TrimMass30() {
/*       Common_HLT_AK8PFJet360_TrimMass30*/  if (not Common_HLT_AK8PFJet360_TrimMass30_isLoaded) {
/*       Common_HLT_AK8PFJet360_TrimMass30*/    if (Common_HLT_AK8PFJet360_TrimMass30_branch != 0) {
/*       Common_HLT_AK8PFJet360_TrimMass30*/      Common_HLT_AK8PFJet360_TrimMass30_branch->GetEntry(index);
/*       Common_HLT_AK8PFJet360_TrimMass30*/    } else {
/*       Common_HLT_AK8PFJet360_TrimMass30*/      printf("branch Common_HLT_AK8PFJet360_TrimMass30_branch does not exist!\n");
/*       Common_HLT_AK8PFJet360_TrimMass30*/      exit(1);
/*       Common_HLT_AK8PFJet360_TrimMass30*/    }
/*       Common_HLT_AK8PFJet360_TrimMass30*/    Common_HLT_AK8PFJet360_TrimMass30_isLoaded = true;
/*       Common_HLT_AK8PFJet360_TrimMass30*/  }
/*       Common_HLT_AK8PFJet360_TrimMass30*/  return Common_HLT_AK8PFJet360_TrimMass30_;
/*       Common_HLT_AK8PFJet360_TrimMass30*/}

//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet400_TrimMass30*/const bool &VVVTree::Common_HLT_AK8PFJet400_TrimMass30() {
/*       Common_HLT_AK8PFJet400_TrimMass30*/  if (not Common_HLT_AK8PFJet400_TrimMass30_isLoaded) {
/*       Common_HLT_AK8PFJet400_TrimMass30*/    if (Common_HLT_AK8PFJet400_TrimMass30_branch != 0) {
/*       Common_HLT_AK8PFJet400_TrimMass30*/      Common_HLT_AK8PFJet400_TrimMass30_branch->GetEntry(index);
/*       Common_HLT_AK8PFJet400_TrimMass30*/    } else {
/*       Common_HLT_AK8PFJet400_TrimMass30*/      printf("branch Common_HLT_AK8PFJet400_TrimMass30_branch does not exist!\n");
/*       Common_HLT_AK8PFJet400_TrimMass30*/      exit(1);
/*       Common_HLT_AK8PFJet400_TrimMass30*/    }
/*       Common_HLT_AK8PFJet400_TrimMass30*/    Common_HLT_AK8PFJet400_TrimMass30_isLoaded = true;
/*       Common_HLT_AK8PFJet400_TrimMass30*/  }
/*       Common_HLT_AK8PFJet400_TrimMass30*/  return Common_HLT_AK8PFJet400_TrimMass30_;
/*       Common_HLT_AK8PFJet400_TrimMass30*/}

//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet420_TrimMass30*/const bool &VVVTree::Common_HLT_AK8PFJet420_TrimMass30() {
/*       Common_HLT_AK8PFJet420_TrimMass30*/  if (not Common_HLT_AK8PFJet420_TrimMass30_isLoaded) {
/*       Common_HLT_AK8PFJet420_TrimMass30*/    if (Common_HLT_AK8PFJet420_TrimMass30_branch != 0) {
/*       Common_HLT_AK8PFJet420_TrimMass30*/      Common_HLT_AK8PFJet420_TrimMass30_branch->GetEntry(index);
/*       Common_HLT_AK8PFJet420_TrimMass30*/    } else {
/*       Common_HLT_AK8PFJet420_TrimMass30*/      printf("branch Common_HLT_AK8PFJet420_TrimMass30_branch does not exist!\n");
/*       Common_HLT_AK8PFJet420_TrimMass30*/      exit(1);
/*       Common_HLT_AK8PFJet420_TrimMass30*/    }
/*       Common_HLT_AK8PFJet420_TrimMass30*/    Common_HLT_AK8PFJet420_TrimMass30_isLoaded = true;
/*       Common_HLT_AK8PFJet420_TrimMass30*/  }
/*       Common_HLT_AK8PFJet420_TrimMass30*/  return Common_HLT_AK8PFJet420_TrimMass30_;
/*       Common_HLT_AK8PFJet420_TrimMass30*/}

//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT750_TrimMass50*/const bool &VVVTree::Common_HLT_AK8PFHT750_TrimMass50() {
/*        Common_HLT_AK8PFHT750_TrimMass50*/  if (not Common_HLT_AK8PFHT750_TrimMass50_isLoaded) {
/*        Common_HLT_AK8PFHT750_TrimMass50*/    if (Common_HLT_AK8PFHT750_TrimMass50_branch != 0) {
/*        Common_HLT_AK8PFHT750_TrimMass50*/      Common_HLT_AK8PFHT750_TrimMass50_branch->GetEntry(index);
/*        Common_HLT_AK8PFHT750_TrimMass50*/    } else {
/*        Common_HLT_AK8PFHT750_TrimMass50*/      printf("branch Common_HLT_AK8PFHT750_TrimMass50_branch does not exist!\n");
/*        Common_HLT_AK8PFHT750_TrimMass50*/      exit(1);
/*        Common_HLT_AK8PFHT750_TrimMass50*/    }
/*        Common_HLT_AK8PFHT750_TrimMass50*/    Common_HLT_AK8PFHT750_TrimMass50_isLoaded = true;
/*        Common_HLT_AK8PFHT750_TrimMass50*/  }
/*        Common_HLT_AK8PFHT750_TrimMass50*/  return Common_HLT_AK8PFHT750_TrimMass50_;
/*        Common_HLT_AK8PFHT750_TrimMass50*/}

//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT800_TrimMass50*/const bool &VVVTree::Common_HLT_AK8PFHT800_TrimMass50() {
/*        Common_HLT_AK8PFHT800_TrimMass50*/  if (not Common_HLT_AK8PFHT800_TrimMass50_isLoaded) {
/*        Common_HLT_AK8PFHT800_TrimMass50*/    if (Common_HLT_AK8PFHT800_TrimMass50_branch != 0) {
/*        Common_HLT_AK8PFHT800_TrimMass50*/      Common_HLT_AK8PFHT800_TrimMass50_branch->GetEntry(index);
/*        Common_HLT_AK8PFHT800_TrimMass50*/    } else {
/*        Common_HLT_AK8PFHT800_TrimMass50*/      printf("branch Common_HLT_AK8PFHT800_TrimMass50_branch does not exist!\n");
/*        Common_HLT_AK8PFHT800_TrimMass50*/      exit(1);
/*        Common_HLT_AK8PFHT800_TrimMass50*/    }
/*        Common_HLT_AK8PFHT800_TrimMass50*/    Common_HLT_AK8PFHT800_TrimMass50_isLoaded = true;
/*        Common_HLT_AK8PFHT800_TrimMass50*/  }
/*        Common_HLT_AK8PFHT800_TrimMass50*/  return Common_HLT_AK8PFHT800_TrimMass50_;
/*        Common_HLT_AK8PFHT800_TrimMass50*/}

//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT850_TrimMass50*/const bool &VVVTree::Common_HLT_AK8PFHT850_TrimMass50() {
/*        Common_HLT_AK8PFHT850_TrimMass50*/  if (not Common_HLT_AK8PFHT850_TrimMass50_isLoaded) {
/*        Common_HLT_AK8PFHT850_TrimMass50*/    if (Common_HLT_AK8PFHT850_TrimMass50_branch != 0) {
/*        Common_HLT_AK8PFHT850_TrimMass50*/      Common_HLT_AK8PFHT850_TrimMass50_branch->GetEntry(index);
/*        Common_HLT_AK8PFHT850_TrimMass50*/    } else {
/*        Common_HLT_AK8PFHT850_TrimMass50*/      printf("branch Common_HLT_AK8PFHT850_TrimMass50_branch does not exist!\n");
/*        Common_HLT_AK8PFHT850_TrimMass50*/      exit(1);
/*        Common_HLT_AK8PFHT850_TrimMass50*/    }
/*        Common_HLT_AK8PFHT850_TrimMass50*/    Common_HLT_AK8PFHT850_TrimMass50_isLoaded = true;
/*        Common_HLT_AK8PFHT850_TrimMass50*/  }
/*        Common_HLT_AK8PFHT850_TrimMass50*/  return Common_HLT_AK8PFHT850_TrimMass50_;
/*        Common_HLT_AK8PFHT850_TrimMass50*/}

//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT900_TrimMass50*/const bool &VVVTree::Common_HLT_AK8PFHT900_TrimMass50() {
/*        Common_HLT_AK8PFHT900_TrimMass50*/  if (not Common_HLT_AK8PFHT900_TrimMass50_isLoaded) {
/*        Common_HLT_AK8PFHT900_TrimMass50*/    if (Common_HLT_AK8PFHT900_TrimMass50_branch != 0) {
/*        Common_HLT_AK8PFHT900_TrimMass50*/      Common_HLT_AK8PFHT900_TrimMass50_branch->GetEntry(index);
/*        Common_HLT_AK8PFHT900_TrimMass50*/    } else {
/*        Common_HLT_AK8PFHT900_TrimMass50*/      printf("branch Common_HLT_AK8PFHT900_TrimMass50_branch does not exist!\n");
/*        Common_HLT_AK8PFHT900_TrimMass50*/      exit(1);
/*        Common_HLT_AK8PFHT900_TrimMass50*/    }
/*        Common_HLT_AK8PFHT900_TrimMass50*/    Common_HLT_AK8PFHT900_TrimMass50_isLoaded = true;
/*        Common_HLT_AK8PFHT900_TrimMass50*/  }
/*        Common_HLT_AK8PFHT900_TrimMass50*/  return Common_HLT_AK8PFHT900_TrimMass50_;
/*        Common_HLT_AK8PFHT900_TrimMass50*/}

//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleEl*/const bool &VVVTree::Common_HLT_DoubleEl() {
/*                     Common_HLT_DoubleEl*/  if (not Common_HLT_DoubleEl_isLoaded) {
/*                     Common_HLT_DoubleEl*/    if (Common_HLT_DoubleEl_branch != 0) {
/*                     Common_HLT_DoubleEl*/      Common_HLT_DoubleEl_branch->GetEntry(index);
/*                     Common_HLT_DoubleEl*/    } else {
/*                     Common_HLT_DoubleEl*/      printf("branch Common_HLT_DoubleEl_branch does not exist!\n");
/*                     Common_HLT_DoubleEl*/      exit(1);
/*                     Common_HLT_DoubleEl*/    }
/*                     Common_HLT_DoubleEl*/    Common_HLT_DoubleEl_isLoaded = true;
/*                     Common_HLT_DoubleEl*/  }
/*                     Common_HLT_DoubleEl*/  return Common_HLT_DoubleEl_;
/*                     Common_HLT_DoubleEl*/}

//---------------------------------------------------------------------------------
/*                         Common_HLT_MuEG*/const bool &VVVTree::Common_HLT_MuEG() {
/*                         Common_HLT_MuEG*/  if (not Common_HLT_MuEG_isLoaded) {
/*                         Common_HLT_MuEG*/    if (Common_HLT_MuEG_branch != 0) {
/*                         Common_HLT_MuEG*/      Common_HLT_MuEG_branch->GetEntry(index);
/*                         Common_HLT_MuEG*/    } else {
/*                         Common_HLT_MuEG*/      printf("branch Common_HLT_MuEG_branch does not exist!\n");
/*                         Common_HLT_MuEG*/      exit(1);
/*                         Common_HLT_MuEG*/    }
/*                         Common_HLT_MuEG*/    Common_HLT_MuEG_isLoaded = true;
/*                         Common_HLT_MuEG*/  }
/*                         Common_HLT_MuEG*/  return Common_HLT_MuEG_;
/*                         Common_HLT_MuEG*/}

//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleMu*/const bool &VVVTree::Common_HLT_DoubleMu() {
/*                     Common_HLT_DoubleMu*/  if (not Common_HLT_DoubleMu_isLoaded) {
/*                     Common_HLT_DoubleMu*/    if (Common_HLT_DoubleMu_branch != 0) {
/*                     Common_HLT_DoubleMu*/      Common_HLT_DoubleMu_branch->GetEntry(index);
/*                     Common_HLT_DoubleMu*/    } else {
/*                     Common_HLT_DoubleMu*/      printf("branch Common_HLT_DoubleMu_branch does not exist!\n");
/*                     Common_HLT_DoubleMu*/      exit(1);
/*                     Common_HLT_DoubleMu*/    }
/*                     Common_HLT_DoubleMu*/    Common_HLT_DoubleMu_isLoaded = true;
/*                     Common_HLT_DoubleMu*/  }
/*                     Common_HLT_DoubleMu*/  return Common_HLT_DoubleMu_;
/*                     Common_HLT_DoubleMu*/}

//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_ee_em_mm*/const bool &VVVTree::Common_pass_duplicate_removal_ee_em_mm() {
/*  Common_pass_duplicate_removal_ee_em_mm*/  if (not Common_pass_duplicate_removal_ee_em_mm_isLoaded) {
/*  Common_pass_duplicate_removal_ee_em_mm*/    if (Common_pass_duplicate_removal_ee_em_mm_branch != 0) {
/*  Common_pass_duplicate_removal_ee_em_mm*/      Common_pass_duplicate_removal_ee_em_mm_branch->GetEntry(index);
/*  Common_pass_duplicate_removal_ee_em_mm*/    } else {
/*  Common_pass_duplicate_removal_ee_em_mm*/      printf("branch Common_pass_duplicate_removal_ee_em_mm_branch does not exist!\n");
/*  Common_pass_duplicate_removal_ee_em_mm*/      exit(1);
/*  Common_pass_duplicate_removal_ee_em_mm*/    }
/*  Common_pass_duplicate_removal_ee_em_mm*/    Common_pass_duplicate_removal_ee_em_mm_isLoaded = true;
/*  Common_pass_duplicate_removal_ee_em_mm*/  }
/*  Common_pass_duplicate_removal_ee_em_mm*/  return Common_pass_duplicate_removal_ee_em_mm_;
/*  Common_pass_duplicate_removal_ee_em_mm*/}
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_mm_em_ee*/const bool &VVVTree::Common_pass_duplicate_removal_mm_em_ee() {
/*  Common_pass_duplicate_removal_mm_em_ee*/  if (not Common_pass_duplicate_removal_mm_em_ee_isLoaded) {
/*  Common_pass_duplicate_removal_mm_em_ee*/    if (Common_pass_duplicate_removal_mm_em_ee_branch != 0) {
/*  Common_pass_duplicate_removal_mm_em_ee*/      Common_pass_duplicate_removal_mm_em_ee_branch->GetEntry(index);
/*  Common_pass_duplicate_removal_mm_em_ee*/    } else {
/*  Common_pass_duplicate_removal_mm_em_ee*/      printf("branch Common_pass_duplicate_removal_mm_em_ee_branch does not exist!\n");
/*  Common_pass_duplicate_removal_mm_em_ee*/      exit(1);
/*  Common_pass_duplicate_removal_mm_em_ee*/    }
/*  Common_pass_duplicate_removal_mm_em_ee*/    Common_pass_duplicate_removal_mm_em_ee_isLoaded = true;
/*  Common_pass_duplicate_removal_mm_em_ee*/  }
/*  Common_pass_duplicate_removal_mm_em_ee*/  return Common_pass_duplicate_removal_mm_em_ee_;
/*  Common_pass_duplicate_removal_mm_em_ee*/}

//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/const bool &VVVTree::Common_noiseFlag() {
/*                        Common_noiseFlag*/  if (not Common_noiseFlag_isLoaded) {
/*                        Common_noiseFlag*/    if (Common_noiseFlag_branch != 0) {
/*                        Common_noiseFlag*/      Common_noiseFlag_branch->GetEntry(index);
/*                        Common_noiseFlag*/    } else {
/*                        Common_noiseFlag*/      printf("branch Common_noiseFlag_branch does not exist!\n");
/*                        Common_noiseFlag*/      exit(1);
/*                        Common_noiseFlag*/    }
/*                        Common_noiseFlag*/    Common_noiseFlag_isLoaded = true;
/*                        Common_noiseFlag*/  }
/*                        Common_noiseFlag*/  return Common_noiseFlag_;
/*                        Common_noiseFlag*/}

//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/const bool &VVVTree::Common_noiseFlagMC() {
/*                      Common_noiseFlagMC*/  if (not Common_noiseFlagMC_isLoaded) {
/*                      Common_noiseFlagMC*/    if (Common_noiseFlagMC_branch != 0) {
/*                      Common_noiseFlagMC*/      Common_noiseFlagMC_branch->GetEntry(index);
/*                      Common_noiseFlagMC*/    } else {
/*                      Common_noiseFlagMC*/      printf("branch Common_noiseFlagMC_branch does not exist!\n");
/*                      Common_noiseFlagMC*/      exit(1);
/*                      Common_noiseFlagMC*/    }
/*                      Common_noiseFlagMC*/    Common_noiseFlagMC_isLoaded = true;
/*                      Common_noiseFlagMC*/  }
/*                      Common_noiseFlagMC*/  return Common_noiseFlagMC_;
/*                      Common_noiseFlagMC*/}


//---------------------------------------------------------------------------------
/*                      Common_passGoodRun*/const bool &VVVTree::Common_passGoodRun() {
/*                      Common_passGoodRun*/  if (not Common_passGoodRun_isLoaded) {
/*                      Common_passGoodRun*/    if (Common_passGoodRun_branch != 0) {
/*                      Common_passGoodRun*/      Common_passGoodRun_branch->GetEntry(index);
/*                      Common_passGoodRun*/    } else {
/*                      Common_passGoodRun*/      printf("branch Common_passGoodRun_branch does not exist!\n");
/*                      Common_passGoodRun*/      exit(1);
/*                      Common_passGoodRun*/    }
/*                      Common_passGoodRun*/    Common_passGoodRun_isLoaded = true;
/*                      Common_passGoodRun*/  }
/*                      Common_passGoodRun*/  return Common_passGoodRun_;
/*                      Common_passGoodRun*/}

//---------------------------------------------------------------------------------
/*                           Common_met_p4*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Common_met_p4() {
/*                           Common_met_p4*/  if (not Common_met_p4_isLoaded) {
/*                           Common_met_p4*/    if (Common_met_p4_branch != 0) {
/*                           Common_met_p4*/      Common_met_p4_branch->GetEntry(index);
/*                           Common_met_p4*/    } else {
/*                           Common_met_p4*/      printf("branch Common_met_p4_branch does not exist!\n");
/*                           Common_met_p4*/      exit(1);
/*                           Common_met_p4*/    }
/*                           Common_met_p4*/    Common_met_p4_isLoaded = true;
/*                           Common_met_p4*/  }
/*                           Common_met_p4*/  return *Common_met_p4_;
/*                           Common_met_p4*/}

//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesup*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Common_met_p4_jesup() {
/*                     Common_met_p4_jesup*/  if (not Common_met_p4_jesup_isLoaded) {
/*                     Common_met_p4_jesup*/    if (Common_met_p4_jesup_branch != 0) {
/*                     Common_met_p4_jesup*/      Common_met_p4_jesup_branch->GetEntry(index);
/*                     Common_met_p4_jesup*/    } else {
/*                     Common_met_p4_jesup*/      printf("branch Common_met_p4_jesup_branch does not exist!\n");
/*                     Common_met_p4_jesup*/      exit(1);
/*                     Common_met_p4_jesup*/    }
/*                     Common_met_p4_jesup*/    Common_met_p4_jesup_isLoaded = true;
/*                     Common_met_p4_jesup*/  }
/*                     Common_met_p4_jesup*/  return *Common_met_p4_jesup_;
/*                     Common_met_p4_jesup*/}

//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesdn*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Common_met_p4_jesdn() {
/*                     Common_met_p4_jesdn*/  if (not Common_met_p4_jesdn_isLoaded) {
/*                     Common_met_p4_jesdn*/    if (Common_met_p4_jesdn_branch != 0) {
/*                     Common_met_p4_jesdn*/      Common_met_p4_jesdn_branch->GetEntry(index);
/*                     Common_met_p4_jesdn*/    } else {
/*                     Common_met_p4_jesdn*/      printf("branch Common_met_p4_jesdn_branch does not exist!\n");
/*                     Common_met_p4_jesdn*/      exit(1);
/*                     Common_met_p4_jesdn*/    }
/*                     Common_met_p4_jesdn*/    Common_met_p4_jesdn_isLoaded = true;
/*                     Common_met_p4_jesdn*/  }
/*                     Common_met_p4_jesdn*/  return *Common_met_p4_jesdn_;
/*                     Common_met_p4_jesdn*/}

//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerup*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Common_met_p4_jerup() {
/*                     Common_met_p4_jerup*/  if (not Common_met_p4_jerup_isLoaded) {
/*                     Common_met_p4_jerup*/    if (Common_met_p4_jerup_branch != 0) {
/*                     Common_met_p4_jerup*/      Common_met_p4_jerup_branch->GetEntry(index);
/*                     Common_met_p4_jerup*/    } else {
/*                     Common_met_p4_jerup*/      printf("branch Common_met_p4_jerup_branch does not exist!\n");
/*                     Common_met_p4_jerup*/      exit(1);
/*                     Common_met_p4_jerup*/    }
/*                     Common_met_p4_jerup*/    Common_met_p4_jerup_isLoaded = true;
/*                     Common_met_p4_jerup*/  }
/*                     Common_met_p4_jerup*/  return *Common_met_p4_jerup_;
/*                     Common_met_p4_jerup*/}

//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerdn*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Common_met_p4_jerdn() {
/*                     Common_met_p4_jerdn*/  if (not Common_met_p4_jerdn_isLoaded) {
/*                     Common_met_p4_jerdn*/    if (Common_met_p4_jerdn_branch != 0) {
/*                     Common_met_p4_jerdn*/      Common_met_p4_jerdn_branch->GetEntry(index);
/*                     Common_met_p4_jerdn*/    } else {
/*                     Common_met_p4_jerdn*/      printf("branch Common_met_p4_jerdn_branch does not exist!\n");
/*                     Common_met_p4_jerdn*/      exit(1);
/*                     Common_met_p4_jerdn*/    }
/*                     Common_met_p4_jerdn*/    Common_met_p4_jerdn_isLoaded = true;
/*                     Common_met_p4_jerdn*/  }
/*                     Common_met_p4_jerdn*/  return *Common_met_p4_jerdn_;
/*                     Common_met_p4_jerdn*/}

//---------------------------------------------------------------------------------
/*                      Common_event_lepSF*/const float &VVVTree::Common_event_lepSF() {
/*                      Common_event_lepSF*/  if (not Common_event_lepSF_isLoaded) {
/*                      Common_event_lepSF*/    if (Common_event_lepSF_branch != 0) {
/*                      Common_event_lepSF*/      Common_event_lepSF_branch->GetEntry(index);
/*                      Common_event_lepSF*/    } else {
/*                      Common_event_lepSF*/      printf("branch Common_event_lepSF_branch does not exist!\n");
/*                      Common_event_lepSF*/      exit(1);
/*                      Common_event_lepSF*/    }
/*                      Common_event_lepSF*/    Common_event_lepSF_isLoaded = true;
/*                      Common_event_lepSF*/  }
/*                      Common_event_lepSF*/  return Common_event_lepSF_;
/*                      Common_event_lepSF*/}

//---------------------------------------------------------------------------------
/*                  Common_event_lepSFelup*/const float &VVVTree::Common_event_lepSFelup() {
/*                  Common_event_lepSFelup*/  if (not Common_event_lepSFelup_isLoaded) {
/*                  Common_event_lepSFelup*/    if (Common_event_lepSFelup_branch != 0) {
/*                  Common_event_lepSFelup*/      Common_event_lepSFelup_branch->GetEntry(index);
/*                  Common_event_lepSFelup*/    } else {
/*                  Common_event_lepSFelup*/      printf("branch Common_event_lepSFelup_branch does not exist!\n");
/*                  Common_event_lepSFelup*/      exit(1);
/*                  Common_event_lepSFelup*/    }
/*                  Common_event_lepSFelup*/    Common_event_lepSFelup_isLoaded = true;
/*                  Common_event_lepSFelup*/  }
/*                  Common_event_lepSFelup*/  return Common_event_lepSFelup_;
/*                  Common_event_lepSFelup*/}

//---------------------------------------------------------------------------------
/*                  Common_event_lepSFeldn*/const float &VVVTree::Common_event_lepSFeldn() {
/*                  Common_event_lepSFeldn*/  if (not Common_event_lepSFeldn_isLoaded) {
/*                  Common_event_lepSFeldn*/    if (Common_event_lepSFeldn_branch != 0) {
/*                  Common_event_lepSFeldn*/      Common_event_lepSFeldn_branch->GetEntry(index);
/*                  Common_event_lepSFeldn*/    } else {
/*                  Common_event_lepSFeldn*/      printf("branch Common_event_lepSFeldn_branch does not exist!\n");
/*                  Common_event_lepSFeldn*/      exit(1);
/*                  Common_event_lepSFeldn*/    }
/*                  Common_event_lepSFeldn*/    Common_event_lepSFeldn_isLoaded = true;
/*                  Common_event_lepSFeldn*/  }
/*                  Common_event_lepSFeldn*/  return Common_event_lepSFeldn_;
/*                  Common_event_lepSFeldn*/}

//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmuup*/const float &VVVTree::Common_event_lepSFmuup() {
/*                  Common_event_lepSFmuup*/  if (not Common_event_lepSFmuup_isLoaded) {
/*                  Common_event_lepSFmuup*/    if (Common_event_lepSFmuup_branch != 0) {
/*                  Common_event_lepSFmuup*/      Common_event_lepSFmuup_branch->GetEntry(index);
/*                  Common_event_lepSFmuup*/    } else {
/*                  Common_event_lepSFmuup*/      printf("branch Common_event_lepSFmuup_branch does not exist!\n");
/*                  Common_event_lepSFmuup*/      exit(1);
/*                  Common_event_lepSFmuup*/    }
/*                  Common_event_lepSFmuup*/    Common_event_lepSFmuup_isLoaded = true;
/*                  Common_event_lepSFmuup*/  }
/*                  Common_event_lepSFmuup*/  return Common_event_lepSFmuup_;
/*                  Common_event_lepSFmuup*/}

//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmudn*/const float &VVVTree::Common_event_lepSFmudn() {
/*                  Common_event_lepSFmudn*/  if (not Common_event_lepSFmudn_isLoaded) {
/*                  Common_event_lepSFmudn*/    if (Common_event_lepSFmudn_branch != 0) {
/*                  Common_event_lepSFmudn*/      Common_event_lepSFmudn_branch->GetEntry(index);
/*                  Common_event_lepSFmudn*/    } else {
/*                  Common_event_lepSFmudn*/      printf("branch Common_event_lepSFmudn_branch does not exist!\n");
/*                  Common_event_lepSFmudn*/      exit(1);
/*                  Common_event_lepSFmudn*/    }
/*                  Common_event_lepSFmudn*/    Common_event_lepSFmudn_isLoaded = true;
/*                  Common_event_lepSFmudn*/  }
/*                  Common_event_lepSFmudn*/  return Common_event_lepSFmudn_;
/*                  Common_event_lepSFmudn*/}

//---------------------------------------------------------------------------------
/*                 Common_event_lepSFTight*/const float &VVVTree::Common_event_lepSFTight() {
/*                 Common_event_lepSFTight*/  if (not Common_event_lepSFTight_isLoaded) {
/*                 Common_event_lepSFTight*/    if (Common_event_lepSFTight_branch != 0) {
/*                 Common_event_lepSFTight*/      Common_event_lepSFTight_branch->GetEntry(index);
/*                 Common_event_lepSFTight*/    } else {
/*                 Common_event_lepSFTight*/      printf("branch Common_event_lepSFTight_branch does not exist!\n");
/*                 Common_event_lepSFTight*/      exit(1);
/*                 Common_event_lepSFTight*/    }
/*                 Common_event_lepSFTight*/    Common_event_lepSFTight_isLoaded = true;
/*                 Common_event_lepSFTight*/  }
/*                 Common_event_lepSFTight*/  return Common_event_lepSFTight_;
/*                 Common_event_lepSFTight*/}

//---------------------------------------------------------------------------------
/*             Common_event_lepSFelupTight*/const float &VVVTree::Common_event_lepSFelupTight() {
/*             Common_event_lepSFelupTight*/  if (not Common_event_lepSFelupTight_isLoaded) {
/*             Common_event_lepSFelupTight*/    if (Common_event_lepSFelupTight_branch != 0) {
/*             Common_event_lepSFelupTight*/      Common_event_lepSFelupTight_branch->GetEntry(index);
/*             Common_event_lepSFelupTight*/    } else {
/*             Common_event_lepSFelupTight*/      printf("branch Common_event_lepSFelupTight_branch does not exist!\n");
/*             Common_event_lepSFelupTight*/      exit(1);
/*             Common_event_lepSFelupTight*/    }
/*             Common_event_lepSFelupTight*/    Common_event_lepSFelupTight_isLoaded = true;
/*             Common_event_lepSFelupTight*/  }
/*             Common_event_lepSFelupTight*/  return Common_event_lepSFelupTight_;
/*             Common_event_lepSFelupTight*/}

//---------------------------------------------------------------------------------
/*             Common_event_lepSFeldnTight*/const float &VVVTree::Common_event_lepSFeldnTight() {
/*             Common_event_lepSFeldnTight*/  if (not Common_event_lepSFeldnTight_isLoaded) {
/*             Common_event_lepSFeldnTight*/    if (Common_event_lepSFeldnTight_branch != 0) {
/*             Common_event_lepSFeldnTight*/      Common_event_lepSFeldnTight_branch->GetEntry(index);
/*             Common_event_lepSFeldnTight*/    } else {
/*             Common_event_lepSFeldnTight*/      printf("branch Common_event_lepSFeldnTight_branch does not exist!\n");
/*             Common_event_lepSFeldnTight*/      exit(1);
/*             Common_event_lepSFeldnTight*/    }
/*             Common_event_lepSFeldnTight*/    Common_event_lepSFeldnTight_isLoaded = true;
/*             Common_event_lepSFeldnTight*/  }
/*             Common_event_lepSFeldnTight*/  return Common_event_lepSFeldnTight_;
/*             Common_event_lepSFeldnTight*/}

//---------------------------------------------------------------------------------
/*             Common_event_lepSFmuupTight*/const float &VVVTree::Common_event_lepSFmuupTight() {
/*             Common_event_lepSFmuupTight*/  if (not Common_event_lepSFmuupTight_isLoaded) {
/*             Common_event_lepSFmuupTight*/    if (Common_event_lepSFmuupTight_branch != 0) {
/*             Common_event_lepSFmuupTight*/      Common_event_lepSFmuupTight_branch->GetEntry(index);
/*             Common_event_lepSFmuupTight*/    } else {
/*             Common_event_lepSFmuupTight*/      printf("branch Common_event_lepSFmuupTight_branch does not exist!\n");
/*             Common_event_lepSFmuupTight*/      exit(1);
/*             Common_event_lepSFmuupTight*/    }
/*             Common_event_lepSFmuupTight*/    Common_event_lepSFmuupTight_isLoaded = true;
/*             Common_event_lepSFmuupTight*/  }
/*             Common_event_lepSFmuupTight*/  return Common_event_lepSFmuupTight_;
/*             Common_event_lepSFmuupTight*/}

//---------------------------------------------------------------------------------
/*             Common_event_lepSFmudnTight*/const float &VVVTree::Common_event_lepSFmudnTight() {
/*             Common_event_lepSFmudnTight*/  if (not Common_event_lepSFmudnTight_isLoaded) {
/*             Common_event_lepSFmudnTight*/    if (Common_event_lepSFmudnTight_branch != 0) {
/*             Common_event_lepSFmudnTight*/      Common_event_lepSFmudnTight_branch->GetEntry(index);
/*             Common_event_lepSFmudnTight*/    } else {
/*             Common_event_lepSFmudnTight*/      printf("branch Common_event_lepSFmudnTight_branch does not exist!\n");
/*             Common_event_lepSFmudnTight*/      exit(1);
/*             Common_event_lepSFmudnTight*/    }
/*             Common_event_lepSFmudnTight*/    Common_event_lepSFmudnTight_isLoaded = true;
/*             Common_event_lepSFmudnTight*/  }
/*             Common_event_lepSFmudnTight*/  return Common_event_lepSFmudnTight_;
/*             Common_event_lepSFmudnTight*/}

//---------------------------------------------------------------------------------
/*                Common_event_tightBtagSF*/const float &VVVTree::Common_event_tightBtagSF() {
/*                Common_event_tightBtagSF*/  if (not Common_event_tightBtagSF_isLoaded) {
/*                Common_event_tightBtagSF*/    if (Common_event_tightBtagSF_branch != 0) {
/*                Common_event_tightBtagSF*/      Common_event_tightBtagSF_branch->GetEntry(index);
/*                Common_event_tightBtagSF*/    } else {
/*                Common_event_tightBtagSF*/      printf("branch Common_event_tightBtagSF_branch does not exist!\n");
/*                Common_event_tightBtagSF*/      exit(1);
/*                Common_event_tightBtagSF*/    }
/*                Common_event_tightBtagSF*/    Common_event_tightBtagSF_isLoaded = true;
/*                Common_event_tightBtagSF*/  }
/*                Common_event_tightBtagSF*/  return Common_event_tightBtagSF_;
/*                Common_event_tightBtagSF*/}

//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFup*/const float &VVVTree::Common_event_tightBtagSFup() {
/*              Common_event_tightBtagSFup*/  if (not Common_event_tightBtagSFup_isLoaded) {
/*              Common_event_tightBtagSFup*/    if (Common_event_tightBtagSFup_branch != 0) {
/*              Common_event_tightBtagSFup*/      Common_event_tightBtagSFup_branch->GetEntry(index);
/*              Common_event_tightBtagSFup*/    } else {
/*              Common_event_tightBtagSFup*/      printf("branch Common_event_tightBtagSFup_branch does not exist!\n");
/*              Common_event_tightBtagSFup*/      exit(1);
/*              Common_event_tightBtagSFup*/    }
/*              Common_event_tightBtagSFup*/    Common_event_tightBtagSFup_isLoaded = true;
/*              Common_event_tightBtagSFup*/  }
/*              Common_event_tightBtagSFup*/  return Common_event_tightBtagSFup_;
/*              Common_event_tightBtagSFup*/}

//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFdn*/const float &VVVTree::Common_event_tightBtagSFdn() {
/*              Common_event_tightBtagSFdn*/  if (not Common_event_tightBtagSFdn_isLoaded) {
/*              Common_event_tightBtagSFdn*/    if (Common_event_tightBtagSFdn_branch != 0) {
/*              Common_event_tightBtagSFdn*/      Common_event_tightBtagSFdn_branch->GetEntry(index);
/*              Common_event_tightBtagSFdn*/    } else {
/*              Common_event_tightBtagSFdn*/      printf("branch Common_event_tightBtagSFdn_branch does not exist!\n");
/*              Common_event_tightBtagSFdn*/      exit(1);
/*              Common_event_tightBtagSFdn*/    }
/*              Common_event_tightBtagSFdn*/    Common_event_tightBtagSFdn_isLoaded = true;
/*              Common_event_tightBtagSFdn*/  }
/*              Common_event_tightBtagSFdn*/  return Common_event_tightBtagSFdn_;
/*              Common_event_tightBtagSFdn*/}

//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFup*/const float &VVVTree::Common_event_tightBtagSFHFup() {
/*            Common_event_tightBtagSFHFup*/  if (not Common_event_tightBtagSFHFup_isLoaded) {
/*            Common_event_tightBtagSFHFup*/    if (Common_event_tightBtagSFHFup_branch != 0) {
/*            Common_event_tightBtagSFHFup*/      Common_event_tightBtagSFHFup_branch->GetEntry(index);
/*            Common_event_tightBtagSFHFup*/    } else {
/*            Common_event_tightBtagSFHFup*/      printf("branch Common_event_tightBtagSFHFup_branch does not exist!\n");
/*            Common_event_tightBtagSFHFup*/      exit(1);
/*            Common_event_tightBtagSFHFup*/    }
/*            Common_event_tightBtagSFHFup*/    Common_event_tightBtagSFHFup_isLoaded = true;
/*            Common_event_tightBtagSFHFup*/  }
/*            Common_event_tightBtagSFHFup*/  return Common_event_tightBtagSFHFup_;
/*            Common_event_tightBtagSFHFup*/}

//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFdn*/const float &VVVTree::Common_event_tightBtagSFHFdn() {
/*            Common_event_tightBtagSFHFdn*/  if (not Common_event_tightBtagSFHFdn_isLoaded) {
/*            Common_event_tightBtagSFHFdn*/    if (Common_event_tightBtagSFHFdn_branch != 0) {
/*            Common_event_tightBtagSFHFdn*/      Common_event_tightBtagSFHFdn_branch->GetEntry(index);
/*            Common_event_tightBtagSFHFdn*/    } else {
/*            Common_event_tightBtagSFHFdn*/      printf("branch Common_event_tightBtagSFHFdn_branch does not exist!\n");
/*            Common_event_tightBtagSFHFdn*/      exit(1);
/*            Common_event_tightBtagSFHFdn*/    }
/*            Common_event_tightBtagSFHFdn*/    Common_event_tightBtagSFHFdn_isLoaded = true;
/*            Common_event_tightBtagSFHFdn*/  }
/*            Common_event_tightBtagSFHFdn*/  return Common_event_tightBtagSFHFdn_;
/*            Common_event_tightBtagSFHFdn*/}

//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFup*/const float &VVVTree::Common_event_tightBtagSFLFup() {
/*            Common_event_tightBtagSFLFup*/  if (not Common_event_tightBtagSFLFup_isLoaded) {
/*            Common_event_tightBtagSFLFup*/    if (Common_event_tightBtagSFLFup_branch != 0) {
/*            Common_event_tightBtagSFLFup*/      Common_event_tightBtagSFLFup_branch->GetEntry(index);
/*            Common_event_tightBtagSFLFup*/    } else {
/*            Common_event_tightBtagSFLFup*/      printf("branch Common_event_tightBtagSFLFup_branch does not exist!\n");
/*            Common_event_tightBtagSFLFup*/      exit(1);
/*            Common_event_tightBtagSFLFup*/    }
/*            Common_event_tightBtagSFLFup*/    Common_event_tightBtagSFLFup_isLoaded = true;
/*            Common_event_tightBtagSFLFup*/  }
/*            Common_event_tightBtagSFLFup*/  return Common_event_tightBtagSFLFup_;
/*            Common_event_tightBtagSFLFup*/}

//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFdn*/const float &VVVTree::Common_event_tightBtagSFLFdn() {
/*            Common_event_tightBtagSFLFdn*/  if (not Common_event_tightBtagSFLFdn_isLoaded) {
/*            Common_event_tightBtagSFLFdn*/    if (Common_event_tightBtagSFLFdn_branch != 0) {
/*            Common_event_tightBtagSFLFdn*/      Common_event_tightBtagSFLFdn_branch->GetEntry(index);
/*            Common_event_tightBtagSFLFdn*/    } else {
/*            Common_event_tightBtagSFLFdn*/      printf("branch Common_event_tightBtagSFLFdn_branch does not exist!\n");
/*            Common_event_tightBtagSFLFdn*/      exit(1);
/*            Common_event_tightBtagSFLFdn*/    }
/*            Common_event_tightBtagSFLFdn*/    Common_event_tightBtagSFLFdn_isLoaded = true;
/*            Common_event_tightBtagSFLFdn*/  }
/*            Common_event_tightBtagSFLFdn*/  return Common_event_tightBtagSFLFdn_;
/*            Common_event_tightBtagSFLFdn*/}

//---------------------------------------------------------------------------------
/*               Common_event_mediumBtagSF*/const float &VVVTree::Common_event_mediumBtagSF() {
/*               Common_event_mediumBtagSF*/  if (not Common_event_mediumBtagSF_isLoaded) {
/*               Common_event_mediumBtagSF*/    if (Common_event_mediumBtagSF_branch != 0) {
/*               Common_event_mediumBtagSF*/      Common_event_mediumBtagSF_branch->GetEntry(index);
/*               Common_event_mediumBtagSF*/    } else {
/*               Common_event_mediumBtagSF*/      printf("branch Common_event_mediumBtagSF_branch does not exist!\n");
/*               Common_event_mediumBtagSF*/      exit(1);
/*               Common_event_mediumBtagSF*/    }
/*               Common_event_mediumBtagSF*/    Common_event_mediumBtagSF_isLoaded = true;
/*               Common_event_mediumBtagSF*/  }
/*               Common_event_mediumBtagSF*/  return Common_event_mediumBtagSF_;
/*               Common_event_mediumBtagSF*/}

//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFup*/const float &VVVTree::Common_event_mediumBtagSFup() {
/*             Common_event_mediumBtagSFup*/  if (not Common_event_mediumBtagSFup_isLoaded) {
/*             Common_event_mediumBtagSFup*/    if (Common_event_mediumBtagSFup_branch != 0) {
/*             Common_event_mediumBtagSFup*/      Common_event_mediumBtagSFup_branch->GetEntry(index);
/*             Common_event_mediumBtagSFup*/    } else {
/*             Common_event_mediumBtagSFup*/      printf("branch Common_event_mediumBtagSFup_branch does not exist!\n");
/*             Common_event_mediumBtagSFup*/      exit(1);
/*             Common_event_mediumBtagSFup*/    }
/*             Common_event_mediumBtagSFup*/    Common_event_mediumBtagSFup_isLoaded = true;
/*             Common_event_mediumBtagSFup*/  }
/*             Common_event_mediumBtagSFup*/  return Common_event_mediumBtagSFup_;
/*             Common_event_mediumBtagSFup*/}

//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFdn*/const float &VVVTree::Common_event_mediumBtagSFdn() {
/*             Common_event_mediumBtagSFdn*/  if (not Common_event_mediumBtagSFdn_isLoaded) {
/*             Common_event_mediumBtagSFdn*/    if (Common_event_mediumBtagSFdn_branch != 0) {
/*             Common_event_mediumBtagSFdn*/      Common_event_mediumBtagSFdn_branch->GetEntry(index);
/*             Common_event_mediumBtagSFdn*/    } else {
/*             Common_event_mediumBtagSFdn*/      printf("branch Common_event_mediumBtagSFdn_branch does not exist!\n");
/*             Common_event_mediumBtagSFdn*/      exit(1);
/*             Common_event_mediumBtagSFdn*/    }
/*             Common_event_mediumBtagSFdn*/    Common_event_mediumBtagSFdn_isLoaded = true;
/*             Common_event_mediumBtagSFdn*/  }
/*             Common_event_mediumBtagSFdn*/  return Common_event_mediumBtagSFdn_;
/*             Common_event_mediumBtagSFdn*/}

//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFup*/const float &VVVTree::Common_event_mediumBtagSFHFup() {
/*           Common_event_mediumBtagSFHFup*/  if (not Common_event_mediumBtagSFHFup_isLoaded) {
/*           Common_event_mediumBtagSFHFup*/    if (Common_event_mediumBtagSFHFup_branch != 0) {
/*           Common_event_mediumBtagSFHFup*/      Common_event_mediumBtagSFHFup_branch->GetEntry(index);
/*           Common_event_mediumBtagSFHFup*/    } else {
/*           Common_event_mediumBtagSFHFup*/      printf("branch Common_event_mediumBtagSFHFup_branch does not exist!\n");
/*           Common_event_mediumBtagSFHFup*/      exit(1);
/*           Common_event_mediumBtagSFHFup*/    }
/*           Common_event_mediumBtagSFHFup*/    Common_event_mediumBtagSFHFup_isLoaded = true;
/*           Common_event_mediumBtagSFHFup*/  }
/*           Common_event_mediumBtagSFHFup*/  return Common_event_mediumBtagSFHFup_;
/*           Common_event_mediumBtagSFHFup*/}

//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFdn*/const float &VVVTree::Common_event_mediumBtagSFHFdn() {
/*           Common_event_mediumBtagSFHFdn*/  if (not Common_event_mediumBtagSFHFdn_isLoaded) {
/*           Common_event_mediumBtagSFHFdn*/    if (Common_event_mediumBtagSFHFdn_branch != 0) {
/*           Common_event_mediumBtagSFHFdn*/      Common_event_mediumBtagSFHFdn_branch->GetEntry(index);
/*           Common_event_mediumBtagSFHFdn*/    } else {
/*           Common_event_mediumBtagSFHFdn*/      printf("branch Common_event_mediumBtagSFHFdn_branch does not exist!\n");
/*           Common_event_mediumBtagSFHFdn*/      exit(1);
/*           Common_event_mediumBtagSFHFdn*/    }
/*           Common_event_mediumBtagSFHFdn*/    Common_event_mediumBtagSFHFdn_isLoaded = true;
/*           Common_event_mediumBtagSFHFdn*/  }
/*           Common_event_mediumBtagSFHFdn*/  return Common_event_mediumBtagSFHFdn_;
/*           Common_event_mediumBtagSFHFdn*/}

//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFup*/const float &VVVTree::Common_event_mediumBtagSFLFup() {
/*           Common_event_mediumBtagSFLFup*/  if (not Common_event_mediumBtagSFLFup_isLoaded) {
/*           Common_event_mediumBtagSFLFup*/    if (Common_event_mediumBtagSFLFup_branch != 0) {
/*           Common_event_mediumBtagSFLFup*/      Common_event_mediumBtagSFLFup_branch->GetEntry(index);
/*           Common_event_mediumBtagSFLFup*/    } else {
/*           Common_event_mediumBtagSFLFup*/      printf("branch Common_event_mediumBtagSFLFup_branch does not exist!\n");
/*           Common_event_mediumBtagSFLFup*/      exit(1);
/*           Common_event_mediumBtagSFLFup*/    }
/*           Common_event_mediumBtagSFLFup*/    Common_event_mediumBtagSFLFup_isLoaded = true;
/*           Common_event_mediumBtagSFLFup*/  }
/*           Common_event_mediumBtagSFLFup*/  return Common_event_mediumBtagSFLFup_;
/*           Common_event_mediumBtagSFLFup*/}

//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFdn*/const float &VVVTree::Common_event_mediumBtagSFLFdn() {
/*           Common_event_mediumBtagSFLFdn*/  if (not Common_event_mediumBtagSFLFdn_isLoaded) {
/*           Common_event_mediumBtagSFLFdn*/    if (Common_event_mediumBtagSFLFdn_branch != 0) {
/*           Common_event_mediumBtagSFLFdn*/      Common_event_mediumBtagSFLFdn_branch->GetEntry(index);
/*           Common_event_mediumBtagSFLFdn*/    } else {
/*           Common_event_mediumBtagSFLFdn*/      printf("branch Common_event_mediumBtagSFLFdn_branch does not exist!\n");
/*           Common_event_mediumBtagSFLFdn*/      exit(1);
/*           Common_event_mediumBtagSFLFdn*/    }
/*           Common_event_mediumBtagSFLFdn*/    Common_event_mediumBtagSFLFdn_isLoaded = true;
/*           Common_event_mediumBtagSFLFdn*/  }
/*           Common_event_mediumBtagSFLFdn*/  return Common_event_mediumBtagSFLFdn_;
/*           Common_event_mediumBtagSFLFdn*/}

//---------------------------------------------------------------------------------
/*                Common_event_looseBtagSF*/const float &VVVTree::Common_event_looseBtagSF() {
/*                Common_event_looseBtagSF*/  if (not Common_event_looseBtagSF_isLoaded) {
/*                Common_event_looseBtagSF*/    if (Common_event_looseBtagSF_branch != 0) {
/*                Common_event_looseBtagSF*/      Common_event_looseBtagSF_branch->GetEntry(index);
/*                Common_event_looseBtagSF*/    } else {
/*                Common_event_looseBtagSF*/      printf("branch Common_event_looseBtagSF_branch does not exist!\n");
/*                Common_event_looseBtagSF*/      exit(1);
/*                Common_event_looseBtagSF*/    }
/*                Common_event_looseBtagSF*/    Common_event_looseBtagSF_isLoaded = true;
/*                Common_event_looseBtagSF*/  }
/*                Common_event_looseBtagSF*/  return Common_event_looseBtagSF_;
/*                Common_event_looseBtagSF*/}

//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFup*/const float &VVVTree::Common_event_looseBtagSFup() {
/*              Common_event_looseBtagSFup*/  if (not Common_event_looseBtagSFup_isLoaded) {
/*              Common_event_looseBtagSFup*/    if (Common_event_looseBtagSFup_branch != 0) {
/*              Common_event_looseBtagSFup*/      Common_event_looseBtagSFup_branch->GetEntry(index);
/*              Common_event_looseBtagSFup*/    } else {
/*              Common_event_looseBtagSFup*/      printf("branch Common_event_looseBtagSFup_branch does not exist!\n");
/*              Common_event_looseBtagSFup*/      exit(1);
/*              Common_event_looseBtagSFup*/    }
/*              Common_event_looseBtagSFup*/    Common_event_looseBtagSFup_isLoaded = true;
/*              Common_event_looseBtagSFup*/  }
/*              Common_event_looseBtagSFup*/  return Common_event_looseBtagSFup_;
/*              Common_event_looseBtagSFup*/}

//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFdn*/const float &VVVTree::Common_event_looseBtagSFdn() {
/*              Common_event_looseBtagSFdn*/  if (not Common_event_looseBtagSFdn_isLoaded) {
/*              Common_event_looseBtagSFdn*/    if (Common_event_looseBtagSFdn_branch != 0) {
/*              Common_event_looseBtagSFdn*/      Common_event_looseBtagSFdn_branch->GetEntry(index);
/*              Common_event_looseBtagSFdn*/    } else {
/*              Common_event_looseBtagSFdn*/      printf("branch Common_event_looseBtagSFdn_branch does not exist!\n");
/*              Common_event_looseBtagSFdn*/      exit(1);
/*              Common_event_looseBtagSFdn*/    }
/*              Common_event_looseBtagSFdn*/    Common_event_looseBtagSFdn_isLoaded = true;
/*              Common_event_looseBtagSFdn*/  }
/*              Common_event_looseBtagSFdn*/  return Common_event_looseBtagSFdn_;
/*              Common_event_looseBtagSFdn*/}

//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFup*/const float &VVVTree::Common_event_looseBtagSFHFup() {
/*            Common_event_looseBtagSFHFup*/  if (not Common_event_looseBtagSFHFup_isLoaded) {
/*            Common_event_looseBtagSFHFup*/    if (Common_event_looseBtagSFHFup_branch != 0) {
/*            Common_event_looseBtagSFHFup*/      Common_event_looseBtagSFHFup_branch->GetEntry(index);
/*            Common_event_looseBtagSFHFup*/    } else {
/*            Common_event_looseBtagSFHFup*/      printf("branch Common_event_looseBtagSFHFup_branch does not exist!\n");
/*            Common_event_looseBtagSFHFup*/      exit(1);
/*            Common_event_looseBtagSFHFup*/    }
/*            Common_event_looseBtagSFHFup*/    Common_event_looseBtagSFHFup_isLoaded = true;
/*            Common_event_looseBtagSFHFup*/  }
/*            Common_event_looseBtagSFHFup*/  return Common_event_looseBtagSFHFup_;
/*            Common_event_looseBtagSFHFup*/}

//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFdn*/const float &VVVTree::Common_event_looseBtagSFHFdn() {
/*            Common_event_looseBtagSFHFdn*/  if (not Common_event_looseBtagSFHFdn_isLoaded) {
/*            Common_event_looseBtagSFHFdn*/    if (Common_event_looseBtagSFHFdn_branch != 0) {
/*            Common_event_looseBtagSFHFdn*/      Common_event_looseBtagSFHFdn_branch->GetEntry(index);
/*            Common_event_looseBtagSFHFdn*/    } else {
/*            Common_event_looseBtagSFHFdn*/      printf("branch Common_event_looseBtagSFHFdn_branch does not exist!\n");
/*            Common_event_looseBtagSFHFdn*/      exit(1);
/*            Common_event_looseBtagSFHFdn*/    }
/*            Common_event_looseBtagSFHFdn*/    Common_event_looseBtagSFHFdn_isLoaded = true;
/*            Common_event_looseBtagSFHFdn*/  }
/*            Common_event_looseBtagSFHFdn*/  return Common_event_looseBtagSFHFdn_;
/*            Common_event_looseBtagSFHFdn*/}

//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFup*/const float &VVVTree::Common_event_looseBtagSFLFup() {
/*            Common_event_looseBtagSFLFup*/  if (not Common_event_looseBtagSFLFup_isLoaded) {
/*            Common_event_looseBtagSFLFup*/    if (Common_event_looseBtagSFLFup_branch != 0) {
/*            Common_event_looseBtagSFLFup*/      Common_event_looseBtagSFLFup_branch->GetEntry(index);
/*            Common_event_looseBtagSFLFup*/    } else {
/*            Common_event_looseBtagSFLFup*/      printf("branch Common_event_looseBtagSFLFup_branch does not exist!\n");
/*            Common_event_looseBtagSFLFup*/      exit(1);
/*            Common_event_looseBtagSFLFup*/    }
/*            Common_event_looseBtagSFLFup*/    Common_event_looseBtagSFLFup_isLoaded = true;
/*            Common_event_looseBtagSFLFup*/  }
/*            Common_event_looseBtagSFLFup*/  return Common_event_looseBtagSFLFup_;
/*            Common_event_looseBtagSFLFup*/}

//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFdn*/const float &VVVTree::Common_event_looseBtagSFLFdn() {
/*            Common_event_looseBtagSFLFdn*/  if (not Common_event_looseBtagSFLFdn_isLoaded) {
/*            Common_event_looseBtagSFLFdn*/    if (Common_event_looseBtagSFLFdn_branch != 0) {
/*            Common_event_looseBtagSFLFdn*/      Common_event_looseBtagSFLFdn_branch->GetEntry(index);
/*            Common_event_looseBtagSFLFdn*/    } else {
/*            Common_event_looseBtagSFLFdn*/      printf("branch Common_event_looseBtagSFLFdn_branch does not exist!\n");
/*            Common_event_looseBtagSFLFdn*/      exit(1);
/*            Common_event_looseBtagSFLFdn*/    }
/*            Common_event_looseBtagSFLFdn*/    Common_event_looseBtagSFLFdn_isLoaded = true;
/*            Common_event_looseBtagSFLFdn*/  }
/*            Common_event_looseBtagSFLFdn*/  return Common_event_looseBtagSFLFdn_;
/*            Common_event_looseBtagSFLFdn*/}

//---------------------------------------------------------------------------------
/*                           Common_lep_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_lep_p4() {
/*                           Common_lep_p4*/  if (not Common_lep_p4_isLoaded) {
/*                           Common_lep_p4*/    if (Common_lep_p4_branch != 0) {
/*                           Common_lep_p4*/      Common_lep_p4_branch->GetEntry(index);
/*                           Common_lep_p4*/    } else {
/*                           Common_lep_p4*/      printf("branch Common_lep_p4_branch does not exist!\n");
/*                           Common_lep_p4*/      exit(1);
/*                           Common_lep_p4*/    }
/*                           Common_lep_p4*/    Common_lep_p4_isLoaded = true;
/*                           Common_lep_p4*/  }
/*                           Common_lep_p4*/  return *Common_lep_p4_;
/*                           Common_lep_p4*/}

//---------------------------------------------------------------------------------
/*                         Common_lep_idxs*/const vector<int> &VVVTree::Common_lep_idxs() {
/*                         Common_lep_idxs*/  if (not Common_lep_idxs_isLoaded) {
/*                         Common_lep_idxs*/    if (Common_lep_idxs_branch != 0) {
/*                         Common_lep_idxs*/      Common_lep_idxs_branch->GetEntry(index);
/*                         Common_lep_idxs*/    } else {
/*                         Common_lep_idxs*/      printf("branch Common_lep_idxs_branch does not exist!\n");
/*                         Common_lep_idxs*/      exit(1);
/*                         Common_lep_idxs*/    }
/*                         Common_lep_idxs*/    Common_lep_idxs_isLoaded = true;
/*                         Common_lep_idxs*/  }
/*                         Common_lep_idxs*/  return *Common_lep_idxs_;
/*                         Common_lep_idxs*/}

//---------------------------------------------------------------------------------
/*                        Common_lep_pdgid*/const vector<int> &VVVTree::Common_lep_pdgid() {
/*                        Common_lep_pdgid*/  if (not Common_lep_pdgid_isLoaded) {
/*                        Common_lep_pdgid*/    if (Common_lep_pdgid_branch != 0) {
/*                        Common_lep_pdgid*/      Common_lep_pdgid_branch->GetEntry(index);
/*                        Common_lep_pdgid*/    } else {
/*                        Common_lep_pdgid*/      printf("branch Common_lep_pdgid_branch does not exist!\n");
/*                        Common_lep_pdgid*/      exit(1);
/*                        Common_lep_pdgid*/    }
/*                        Common_lep_pdgid*/    Common_lep_pdgid_isLoaded = true;
/*                        Common_lep_pdgid*/  }
/*                        Common_lep_pdgid*/  return *Common_lep_pdgid_;
/*                        Common_lep_pdgid*/}

//---------------------------------------------------------------------------------
/*                        Common_lep_tight*/const vector<int> &VVVTree::Common_lep_tight() {
/*                        Common_lep_tight*/  if (not Common_lep_tight_isLoaded) {
/*                        Common_lep_tight*/    if (Common_lep_tight_branch != 0) {
/*                        Common_lep_tight*/      Common_lep_tight_branch->GetEntry(index);
/*                        Common_lep_tight*/    } else {
/*                        Common_lep_tight*/      printf("branch Common_lep_tight_branch does not exist!\n");
/*                        Common_lep_tight*/      exit(1);
/*                        Common_lep_tight*/    }
/*                        Common_lep_tight*/    Common_lep_tight_isLoaded = true;
/*                        Common_lep_tight*/  }
/*                        Common_lep_tight*/  return *Common_lep_tight_;
/*                        Common_lep_tight*/}

//---------------------------------------------------------------------------------
/*                          Common_lep_dxy*/const vector<float> &VVVTree::Common_lep_dxy() {
/*                          Common_lep_dxy*/  if (not Common_lep_dxy_isLoaded) {
/*                          Common_lep_dxy*/    if (Common_lep_dxy_branch != 0) {
/*                          Common_lep_dxy*/      Common_lep_dxy_branch->GetEntry(index);
/*                          Common_lep_dxy*/    } else {
/*                          Common_lep_dxy*/      printf("branch Common_lep_dxy_branch does not exist!\n");
/*                          Common_lep_dxy*/      exit(1);
/*                          Common_lep_dxy*/    }
/*                          Common_lep_dxy*/    Common_lep_dxy_isLoaded = true;
/*                          Common_lep_dxy*/  }
/*                          Common_lep_dxy*/  return *Common_lep_dxy_;
/*                          Common_lep_dxy*/}

//---------------------------------------------------------------------------------
/*                           Common_lep_dz*/const vector<float> &VVVTree::Common_lep_dz() {
/*                           Common_lep_dz*/  if (not Common_lep_dz_isLoaded) {
/*                           Common_lep_dz*/    if (Common_lep_dz_branch != 0) {
/*                           Common_lep_dz*/      Common_lep_dz_branch->GetEntry(index);
/*                           Common_lep_dz*/    } else {
/*                           Common_lep_dz*/      printf("branch Common_lep_dz_branch does not exist!\n");
/*                           Common_lep_dz*/      exit(1);
/*                           Common_lep_dz*/    }
/*                           Common_lep_dz*/    Common_lep_dz_isLoaded = true;
/*                           Common_lep_dz*/  }
/*                           Common_lep_dz*/  return *Common_lep_dz_;
/*                           Common_lep_dz*/}

//---------------------------------------------------------------------------------
/*                         Common_lep_ip3d*/const vector<float> &VVVTree::Common_lep_ip3d() {
/*                         Common_lep_ip3d*/  if (not Common_lep_ip3d_isLoaded) {
/*                         Common_lep_ip3d*/    if (Common_lep_ip3d_branch != 0) {
/*                         Common_lep_ip3d*/      Common_lep_ip3d_branch->GetEntry(index);
/*                         Common_lep_ip3d*/    } else {
/*                         Common_lep_ip3d*/      printf("branch Common_lep_ip3d_branch does not exist!\n");
/*                         Common_lep_ip3d*/      exit(1);
/*                         Common_lep_ip3d*/    }
/*                         Common_lep_ip3d*/    Common_lep_ip3d_isLoaded = true;
/*                         Common_lep_ip3d*/  }
/*                         Common_lep_ip3d*/  return *Common_lep_ip3d_;
/*                         Common_lep_ip3d*/}

//---------------------------------------------------------------------------------
/*                        Common_lep_sip3d*/const vector<float> &VVVTree::Common_lep_sip3d() {
/*                        Common_lep_sip3d*/  if (not Common_lep_sip3d_isLoaded) {
/*                        Common_lep_sip3d*/    if (Common_lep_sip3d_branch != 0) {
/*                        Common_lep_sip3d*/      Common_lep_sip3d_branch->GetEntry(index);
/*                        Common_lep_sip3d*/    } else {
/*                        Common_lep_sip3d*/      printf("branch Common_lep_sip3d_branch does not exist!\n");
/*                        Common_lep_sip3d*/      exit(1);
/*                        Common_lep_sip3d*/    }
/*                        Common_lep_sip3d*/    Common_lep_sip3d_isLoaded = true;
/*                        Common_lep_sip3d*/  }
/*                        Common_lep_sip3d*/  return *Common_lep_sip3d_;
/*                        Common_lep_sip3d*/}

//---------------------------------------------------------------------------------
/*                           Common_lep_SF*/const vector<float> &VVVTree::Common_lep_SF() {
/*                           Common_lep_SF*/  if (not Common_lep_SF_isLoaded) {
/*                           Common_lep_SF*/    if (Common_lep_SF_branch != 0) {
/*                           Common_lep_SF*/      Common_lep_SF_branch->GetEntry(index);
/*                           Common_lep_SF*/    } else {
/*                           Common_lep_SF*/      printf("branch Common_lep_SF_branch does not exist!\n");
/*                           Common_lep_SF*/      exit(1);
/*                           Common_lep_SF*/    }
/*                           Common_lep_SF*/    Common_lep_SF_isLoaded = true;
/*                           Common_lep_SF*/  }
/*                           Common_lep_SF*/  return *Common_lep_SF_;
/*                           Common_lep_SF*/}

//---------------------------------------------------------------------------------
/*                      Common_lep_SFTight*/const vector<float> &VVVTree::Common_lep_SFTight() {
/*                      Common_lep_SFTight*/  if (not Common_lep_SFTight_isLoaded) {
/*                      Common_lep_SFTight*/    if (Common_lep_SFTight_branch != 0) {
/*                      Common_lep_SFTight*/      Common_lep_SFTight_branch->GetEntry(index);
/*                      Common_lep_SFTight*/    } else {
/*                      Common_lep_SFTight*/      printf("branch Common_lep_SFTight_branch does not exist!\n");
/*                      Common_lep_SFTight*/      exit(1);
/*                      Common_lep_SFTight*/    }
/*                      Common_lep_SFTight*/    Common_lep_SFTight_isLoaded = true;
/*                      Common_lep_SFTight*/  }
/*                      Common_lep_SFTight*/  return *Common_lep_SFTight_;
/*                      Common_lep_SFTight*/}

//---------------------------------------------------------------------------------
/*                         Common_lep_SFdn*/const vector<float> &VVVTree::Common_lep_SFdn() {
/*                         Common_lep_SFdn*/  if (not Common_lep_SFdn_isLoaded) {
/*                         Common_lep_SFdn*/    if (Common_lep_SFdn_branch != 0) {
/*                         Common_lep_SFdn*/      Common_lep_SFdn_branch->GetEntry(index);
/*                         Common_lep_SFdn*/    } else {
/*                         Common_lep_SFdn*/      printf("branch Common_lep_SFdn_branch does not exist!\n");
/*                         Common_lep_SFdn*/      exit(1);
/*                         Common_lep_SFdn*/    }
/*                         Common_lep_SFdn*/    Common_lep_SFdn_isLoaded = true;
/*                         Common_lep_SFdn*/  }
/*                         Common_lep_SFdn*/  return *Common_lep_SFdn_;
/*                         Common_lep_SFdn*/}

//---------------------------------------------------------------------------------
/*                    Common_lep_SFdnTight*/const vector<float> &VVVTree::Common_lep_SFdnTight() {
/*                    Common_lep_SFdnTight*/  if (not Common_lep_SFdnTight_isLoaded) {
/*                    Common_lep_SFdnTight*/    if (Common_lep_SFdnTight_branch != 0) {
/*                    Common_lep_SFdnTight*/      Common_lep_SFdnTight_branch->GetEntry(index);
/*                    Common_lep_SFdnTight*/    } else {
/*                    Common_lep_SFdnTight*/      printf("branch Common_lep_SFdnTight_branch does not exist!\n");
/*                    Common_lep_SFdnTight*/      exit(1);
/*                    Common_lep_SFdnTight*/    }
/*                    Common_lep_SFdnTight*/    Common_lep_SFdnTight_isLoaded = true;
/*                    Common_lep_SFdnTight*/  }
/*                    Common_lep_SFdnTight*/  return *Common_lep_SFdnTight_;
/*                    Common_lep_SFdnTight*/}

//---------------------------------------------------------------------------------
/*                         Common_lep_SFup*/const vector<float> &VVVTree::Common_lep_SFup() {
/*                         Common_lep_SFup*/  if (not Common_lep_SFup_isLoaded) {
/*                         Common_lep_SFup*/    if (Common_lep_SFup_branch != 0) {
/*                         Common_lep_SFup*/      Common_lep_SFup_branch->GetEntry(index);
/*                         Common_lep_SFup*/    } else {
/*                         Common_lep_SFup*/      printf("branch Common_lep_SFup_branch does not exist!\n");
/*                         Common_lep_SFup*/      exit(1);
/*                         Common_lep_SFup*/    }
/*                         Common_lep_SFup*/    Common_lep_SFup_isLoaded = true;
/*                         Common_lep_SFup*/  }
/*                         Common_lep_SFup*/  return *Common_lep_SFup_;
/*                         Common_lep_SFup*/}

//---------------------------------------------------------------------------------
/*                    Common_lep_SFupTight*/const vector<float> &VVVTree::Common_lep_SFupTight() {
/*                    Common_lep_SFupTight*/  if (not Common_lep_SFupTight_isLoaded) {
/*                    Common_lep_SFupTight*/    if (Common_lep_SFupTight_branch != 0) {
/*                    Common_lep_SFupTight*/      Common_lep_SFupTight_branch->GetEntry(index);
/*                    Common_lep_SFupTight*/    } else {
/*                    Common_lep_SFupTight*/      printf("branch Common_lep_SFupTight_branch does not exist!\n");
/*                    Common_lep_SFupTight*/      exit(1);
/*                    Common_lep_SFupTight*/    }
/*                    Common_lep_SFupTight*/    Common_lep_SFupTight_isLoaded = true;
/*                    Common_lep_SFupTight*/  }
/*                    Common_lep_SFupTight*/  return *Common_lep_SFupTight_;
/*                    Common_lep_SFupTight*/}

//---------------------------------------------------------------------------------
/*                           Common_jet_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_jet_p4() {
/*                           Common_jet_p4*/  if (not Common_jet_p4_isLoaded) {
/*                           Common_jet_p4*/    if (Common_jet_p4_branch != 0) {
/*                           Common_jet_p4*/      Common_jet_p4_branch->GetEntry(index);
/*                           Common_jet_p4*/    } else {
/*                           Common_jet_p4*/      printf("branch Common_jet_p4_branch does not exist!\n");
/*                           Common_jet_p4*/      exit(1);
/*                           Common_jet_p4*/    }
/*                           Common_jet_p4*/    Common_jet_p4_isLoaded = true;
/*                           Common_jet_p4*/  }
/*                           Common_jet_p4*/  return *Common_jet_p4_;
/*                           Common_jet_p4*/}

//---------------------------------------------------------------------------------
/*                         Common_jet_idxs*/const vector<int> &VVVTree::Common_jet_idxs() {
/*                         Common_jet_idxs*/  if (not Common_jet_idxs_isLoaded) {
/*                         Common_jet_idxs*/    if (Common_jet_idxs_branch != 0) {
/*                         Common_jet_idxs*/      Common_jet_idxs_branch->GetEntry(index);
/*                         Common_jet_idxs*/    } else {
/*                         Common_jet_idxs*/      printf("branch Common_jet_idxs_branch does not exist!\n");
/*                         Common_jet_idxs*/      exit(1);
/*                         Common_jet_idxs*/    }
/*                         Common_jet_idxs*/    Common_jet_idxs_isLoaded = true;
/*                         Common_jet_idxs*/  }
/*                         Common_jet_idxs*/  return *Common_jet_idxs_;
/*                         Common_jet_idxs*/}

//---------------------------------------------------------------------------------
/*                   Common_jet_passBloose*/const vector<bool> &VVVTree::Common_jet_passBloose() {
/*                   Common_jet_passBloose*/  if (not Common_jet_passBloose_isLoaded) {
/*                   Common_jet_passBloose*/    if (Common_jet_passBloose_branch != 0) {
/*                   Common_jet_passBloose*/      Common_jet_passBloose_branch->GetEntry(index);
/*                   Common_jet_passBloose*/    } else {
/*                   Common_jet_passBloose*/      printf("branch Common_jet_passBloose_branch does not exist!\n");
/*                   Common_jet_passBloose*/      exit(1);
/*                   Common_jet_passBloose*/    }
/*                   Common_jet_passBloose*/    Common_jet_passBloose_isLoaded = true;
/*                   Common_jet_passBloose*/  }
/*                   Common_jet_passBloose*/  return *Common_jet_passBloose_;
/*                   Common_jet_passBloose*/}

//---------------------------------------------------------------------------------
/*                  Common_jet_passBmedium*/const vector<bool> &VVVTree::Common_jet_passBmedium() {
/*                  Common_jet_passBmedium*/  if (not Common_jet_passBmedium_isLoaded) {
/*                  Common_jet_passBmedium*/    if (Common_jet_passBmedium_branch != 0) {
/*                  Common_jet_passBmedium*/      Common_jet_passBmedium_branch->GetEntry(index);
/*                  Common_jet_passBmedium*/    } else {
/*                  Common_jet_passBmedium*/      printf("branch Common_jet_passBmedium_branch does not exist!\n");
/*                  Common_jet_passBmedium*/      exit(1);
/*                  Common_jet_passBmedium*/    }
/*                  Common_jet_passBmedium*/    Common_jet_passBmedium_isLoaded = true;
/*                  Common_jet_passBmedium*/  }
/*                  Common_jet_passBmedium*/  return *Common_jet_passBmedium_;
/*                  Common_jet_passBmedium*/}

//---------------------------------------------------------------------------------
/*                   Common_jet_passBtight*/const vector<bool> &VVVTree::Common_jet_passBtight() {
/*                   Common_jet_passBtight*/  if (not Common_jet_passBtight_isLoaded) {
/*                   Common_jet_passBtight*/    if (Common_jet_passBtight_branch != 0) {
/*                   Common_jet_passBtight*/      Common_jet_passBtight_branch->GetEntry(index);
/*                   Common_jet_passBtight*/    } else {
/*                   Common_jet_passBtight*/      printf("branch Common_jet_passBtight_branch does not exist!\n");
/*                   Common_jet_passBtight*/      exit(1);
/*                   Common_jet_passBtight*/    }
/*                   Common_jet_passBtight*/    Common_jet_passBtight_isLoaded = true;
/*                   Common_jet_passBtight*/  }
/*                   Common_jet_passBtight*/  return *Common_jet_passBtight_;
/*                   Common_jet_passBtight*/}

//---------------------------------------------------------------------------------
/*                           Common_jet_id*/const vector<int> &VVVTree::Common_jet_id() {
/*                           Common_jet_id*/  if (not Common_jet_id_isLoaded) {
/*                           Common_jet_id*/    if (Common_jet_id_branch != 0) {
/*                           Common_jet_id*/      Common_jet_id_branch->GetEntry(index);
/*                           Common_jet_id*/    } else {
/*                           Common_jet_id*/      printf("branch Common_jet_id_branch does not exist!\n");
/*                           Common_jet_id*/      exit(1);
/*                           Common_jet_id*/    }
/*                           Common_jet_id*/    Common_jet_id_isLoaded = true;
/*                           Common_jet_id*/  }
/*                           Common_jet_id*/  return *Common_jet_id_;
/*                           Common_jet_id*/}

//---------------------------------------------------------------------------------
/*                Common_jet_overlapfatjet*/const vector<int> &VVVTree::Common_jet_overlapfatjet() {
/*                Common_jet_overlapfatjet*/  if (not Common_jet_overlapfatjet_isLoaded) {
/*                Common_jet_overlapfatjet*/    if (Common_jet_overlapfatjet_branch != 0) {
/*                Common_jet_overlapfatjet*/      Common_jet_overlapfatjet_branch->GetEntry(index);
/*                Common_jet_overlapfatjet*/    } else {
/*                Common_jet_overlapfatjet*/      printf("branch Common_jet_overlapfatjet_branch does not exist!\n");
/*                Common_jet_overlapfatjet*/      exit(1);
/*                Common_jet_overlapfatjet*/    }
/*                Common_jet_overlapfatjet*/    Common_jet_overlapfatjet_isLoaded = true;
/*                Common_jet_overlapfatjet*/  }
/*                Common_jet_overlapfatjet*/  return *Common_jet_overlapfatjet_;
/*                Common_jet_overlapfatjet*/}

//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesup*/const vector<float> &VVVTree::Common_jet_pt_jesup() {
/*                     Common_jet_pt_jesup*/  if (not Common_jet_pt_jesup_isLoaded) {
/*                     Common_jet_pt_jesup*/    if (Common_jet_pt_jesup_branch != 0) {
/*                     Common_jet_pt_jesup*/      Common_jet_pt_jesup_branch->GetEntry(index);
/*                     Common_jet_pt_jesup*/    } else {
/*                     Common_jet_pt_jesup*/      printf("branch Common_jet_pt_jesup_branch does not exist!\n");
/*                     Common_jet_pt_jesup*/      exit(1);
/*                     Common_jet_pt_jesup*/    }
/*                     Common_jet_pt_jesup*/    Common_jet_pt_jesup_isLoaded = true;
/*                     Common_jet_pt_jesup*/  }
/*                     Common_jet_pt_jesup*/  return *Common_jet_pt_jesup_;
/*                     Common_jet_pt_jesup*/}

//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesdn*/const vector<float> &VVVTree::Common_jet_pt_jesdn() {
/*                     Common_jet_pt_jesdn*/  if (not Common_jet_pt_jesdn_isLoaded) {
/*                     Common_jet_pt_jesdn*/    if (Common_jet_pt_jesdn_branch != 0) {
/*                     Common_jet_pt_jesdn*/      Common_jet_pt_jesdn_branch->GetEntry(index);
/*                     Common_jet_pt_jesdn*/    } else {
/*                     Common_jet_pt_jesdn*/      printf("branch Common_jet_pt_jesdn_branch does not exist!\n");
/*                     Common_jet_pt_jesdn*/      exit(1);
/*                     Common_jet_pt_jesdn*/    }
/*                     Common_jet_pt_jesdn*/    Common_jet_pt_jesdn_isLoaded = true;
/*                     Common_jet_pt_jesdn*/  }
/*                     Common_jet_pt_jesdn*/  return *Common_jet_pt_jesdn_;
/*                     Common_jet_pt_jesdn*/}

//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerup*/const vector<float> &VVVTree::Common_jet_pt_jerup() {
/*                     Common_jet_pt_jerup*/  if (not Common_jet_pt_jerup_isLoaded) {
/*                     Common_jet_pt_jerup*/    if (Common_jet_pt_jerup_branch != 0) {
/*                     Common_jet_pt_jerup*/      Common_jet_pt_jerup_branch->GetEntry(index);
/*                     Common_jet_pt_jerup*/    } else {
/*                     Common_jet_pt_jerup*/      printf("branch Common_jet_pt_jerup_branch does not exist!\n");
/*                     Common_jet_pt_jerup*/      exit(1);
/*                     Common_jet_pt_jerup*/    }
/*                     Common_jet_pt_jerup*/    Common_jet_pt_jerup_isLoaded = true;
/*                     Common_jet_pt_jerup*/  }
/*                     Common_jet_pt_jerup*/  return *Common_jet_pt_jerup_;
/*                     Common_jet_pt_jerup*/}

//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerdn*/const vector<float> &VVVTree::Common_jet_pt_jerdn() {
/*                     Common_jet_pt_jerdn*/  if (not Common_jet_pt_jerdn_isLoaded) {
/*                     Common_jet_pt_jerdn*/    if (Common_jet_pt_jerdn_branch != 0) {
/*                     Common_jet_pt_jerdn*/      Common_jet_pt_jerdn_branch->GetEntry(index);
/*                     Common_jet_pt_jerdn*/    } else {
/*                     Common_jet_pt_jerdn*/      printf("branch Common_jet_pt_jerdn_branch does not exist!\n");
/*                     Common_jet_pt_jerdn*/      exit(1);
/*                     Common_jet_pt_jerdn*/    }
/*                     Common_jet_pt_jerdn*/    Common_jet_pt_jerdn_isLoaded = true;
/*                     Common_jet_pt_jerdn*/  }
/*                     Common_jet_pt_jerdn*/  return *Common_jet_pt_jerdn_;
/*                     Common_jet_pt_jerdn*/}

//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesup*/const vector<float> &VVVTree::Common_jet_mass_jesup() {
/*                   Common_jet_mass_jesup*/  if (not Common_jet_mass_jesup_isLoaded) {
/*                   Common_jet_mass_jesup*/    if (Common_jet_mass_jesup_branch != 0) {
/*                   Common_jet_mass_jesup*/      Common_jet_mass_jesup_branch->GetEntry(index);
/*                   Common_jet_mass_jesup*/    } else {
/*                   Common_jet_mass_jesup*/      printf("branch Common_jet_mass_jesup_branch does not exist!\n");
/*                   Common_jet_mass_jesup*/      exit(1);
/*                   Common_jet_mass_jesup*/    }
/*                   Common_jet_mass_jesup*/    Common_jet_mass_jesup_isLoaded = true;
/*                   Common_jet_mass_jesup*/  }
/*                   Common_jet_mass_jesup*/  return *Common_jet_mass_jesup_;
/*                   Common_jet_mass_jesup*/}

//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesdn*/const vector<float> &VVVTree::Common_jet_mass_jesdn() {
/*                   Common_jet_mass_jesdn*/  if (not Common_jet_mass_jesdn_isLoaded) {
/*                   Common_jet_mass_jesdn*/    if (Common_jet_mass_jesdn_branch != 0) {
/*                   Common_jet_mass_jesdn*/      Common_jet_mass_jesdn_branch->GetEntry(index);
/*                   Common_jet_mass_jesdn*/    } else {
/*                   Common_jet_mass_jesdn*/      printf("branch Common_jet_mass_jesdn_branch does not exist!\n");
/*                   Common_jet_mass_jesdn*/      exit(1);
/*                   Common_jet_mass_jesdn*/    }
/*                   Common_jet_mass_jesdn*/    Common_jet_mass_jesdn_isLoaded = true;
/*                   Common_jet_mass_jesdn*/  }
/*                   Common_jet_mass_jesdn*/  return *Common_jet_mass_jesdn_;
/*                   Common_jet_mass_jesdn*/}

//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerup*/const vector<float> &VVVTree::Common_jet_mass_jerup() {
/*                   Common_jet_mass_jerup*/  if (not Common_jet_mass_jerup_isLoaded) {
/*                   Common_jet_mass_jerup*/    if (Common_jet_mass_jerup_branch != 0) {
/*                   Common_jet_mass_jerup*/      Common_jet_mass_jerup_branch->GetEntry(index);
/*                   Common_jet_mass_jerup*/    } else {
/*                   Common_jet_mass_jerup*/      printf("branch Common_jet_mass_jerup_branch does not exist!\n");
/*                   Common_jet_mass_jerup*/      exit(1);
/*                   Common_jet_mass_jerup*/    }
/*                   Common_jet_mass_jerup*/    Common_jet_mass_jerup_isLoaded = true;
/*                   Common_jet_mass_jerup*/  }
/*                   Common_jet_mass_jerup*/  return *Common_jet_mass_jerup_;
/*                   Common_jet_mass_jerup*/}

//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerdn*/const vector<float> &VVVTree::Common_jet_mass_jerdn() {
/*                   Common_jet_mass_jerdn*/  if (not Common_jet_mass_jerdn_isLoaded) {
/*                   Common_jet_mass_jerdn*/    if (Common_jet_mass_jerdn_branch != 0) {
/*                   Common_jet_mass_jerdn*/      Common_jet_mass_jerdn_branch->GetEntry(index);
/*                   Common_jet_mass_jerdn*/    } else {
/*                   Common_jet_mass_jerdn*/      printf("branch Common_jet_mass_jerdn_branch does not exist!\n");
/*                   Common_jet_mass_jerdn*/      exit(1);
/*                   Common_jet_mass_jerdn*/    }
/*                   Common_jet_mass_jerdn*/    Common_jet_mass_jerdn_isLoaded = true;
/*                   Common_jet_mass_jerdn*/  }
/*                   Common_jet_mass_jerdn*/  return *Common_jet_mass_jerdn_;
/*                   Common_jet_mass_jerdn*/}

//---------------------------------------------------------------------------------
/*                        Common_fatjet_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_fatjet_p4() {
/*                        Common_fatjet_p4*/  if (not Common_fatjet_p4_isLoaded) {
/*                        Common_fatjet_p4*/    if (Common_fatjet_p4_branch != 0) {
/*                        Common_fatjet_p4*/      Common_fatjet_p4_branch->GetEntry(index);
/*                        Common_fatjet_p4*/    } else {
/*                        Common_fatjet_p4*/      printf("branch Common_fatjet_p4_branch does not exist!\n");
/*                        Common_fatjet_p4*/      exit(1);
/*                        Common_fatjet_p4*/    }
/*                        Common_fatjet_p4*/    Common_fatjet_p4_isLoaded = true;
/*                        Common_fatjet_p4*/  }
/*                        Common_fatjet_p4*/  return *Common_fatjet_p4_;
/*                        Common_fatjet_p4*/}

//---------------------------------------------------------------------------------
/*                      Common_fatjet_idxs*/const vector<int> &VVVTree::Common_fatjet_idxs() {
/*                      Common_fatjet_idxs*/  if (not Common_fatjet_idxs_isLoaded) {
/*                      Common_fatjet_idxs*/    if (Common_fatjet_idxs_branch != 0) {
/*                      Common_fatjet_idxs*/      Common_fatjet_idxs_branch->GetEntry(index);
/*                      Common_fatjet_idxs*/    } else {
/*                      Common_fatjet_idxs*/      printf("branch Common_fatjet_idxs_branch does not exist!\n");
/*                      Common_fatjet_idxs*/      exit(1);
/*                      Common_fatjet_idxs*/    }
/*                      Common_fatjet_idxs*/    Common_fatjet_idxs_isLoaded = true;
/*                      Common_fatjet_idxs*/  }
/*                      Common_fatjet_idxs*/  return *Common_fatjet_idxs_;
/*                      Common_fatjet_idxs*/}

//---------------------------------------------------------------------------------
/*                        Common_fatjet_id*/const vector<int> &VVVTree::Common_fatjet_id() {
/*                        Common_fatjet_id*/  if (not Common_fatjet_id_isLoaded) {
/*                        Common_fatjet_id*/    if (Common_fatjet_id_branch != 0) {
/*                        Common_fatjet_id*/      Common_fatjet_id_branch->GetEntry(index);
/*                        Common_fatjet_id*/    } else {
/*                        Common_fatjet_id*/      printf("branch Common_fatjet_id_branch does not exist!\n");
/*                        Common_fatjet_id*/      exit(1);
/*                        Common_fatjet_id*/    }
/*                        Common_fatjet_id*/    Common_fatjet_id_isLoaded = true;
/*                        Common_fatjet_id*/  }
/*                        Common_fatjet_id*/  return *Common_fatjet_id_;
/*                        Common_fatjet_id*/}

//---------------------------------------------------------------------------------
/*                 Common_fatjet_msoftdrop*/const vector<float> &VVVTree::Common_fatjet_msoftdrop() {
/*                 Common_fatjet_msoftdrop*/  if (not Common_fatjet_msoftdrop_isLoaded) {
/*                 Common_fatjet_msoftdrop*/    if (Common_fatjet_msoftdrop_branch != 0) {
/*                 Common_fatjet_msoftdrop*/      Common_fatjet_msoftdrop_branch->GetEntry(index);
/*                 Common_fatjet_msoftdrop*/    } else {
/*                 Common_fatjet_msoftdrop*/      printf("branch Common_fatjet_msoftdrop_branch does not exist!\n");
/*                 Common_fatjet_msoftdrop*/      exit(1);
/*                 Common_fatjet_msoftdrop*/    }
/*                 Common_fatjet_msoftdrop*/    Common_fatjet_msoftdrop_isLoaded = true;
/*                 Common_fatjet_msoftdrop*/  }
/*                 Common_fatjet_msoftdrop*/  return *Common_fatjet_msoftdrop_;
/*                 Common_fatjet_msoftdrop*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_W*/const vector<float> &VVVTree::Common_fatjet_deepMD_W() {
/*                  Common_fatjet_deepMD_W*/  if (not Common_fatjet_deepMD_W_isLoaded) {
/*                  Common_fatjet_deepMD_W*/    if (Common_fatjet_deepMD_W_branch != 0) {
/*                  Common_fatjet_deepMD_W*/      Common_fatjet_deepMD_W_branch->GetEntry(index);
/*                  Common_fatjet_deepMD_W*/    } else {
/*                  Common_fatjet_deepMD_W*/      printf("branch Common_fatjet_deepMD_W_branch does not exist!\n");
/*                  Common_fatjet_deepMD_W*/      exit(1);
/*                  Common_fatjet_deepMD_W*/    }
/*                  Common_fatjet_deepMD_W*/    Common_fatjet_deepMD_W_isLoaded = true;
/*                  Common_fatjet_deepMD_W*/  }
/*                  Common_fatjet_deepMD_W*/  return *Common_fatjet_deepMD_W_;
/*                  Common_fatjet_deepMD_W*/}

//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_W*/const vector<float> &VVVTree::Common_fatjet_deep_W() {
/*                    Common_fatjet_deep_W*/  if (not Common_fatjet_deep_W_isLoaded) {
/*                    Common_fatjet_deep_W*/    if (Common_fatjet_deep_W_branch != 0) {
/*                    Common_fatjet_deep_W*/      Common_fatjet_deep_W_branch->GetEntry(index);
/*                    Common_fatjet_deep_W*/    } else {
/*                    Common_fatjet_deep_W*/      printf("branch Common_fatjet_deep_W_branch does not exist!\n");
/*                    Common_fatjet_deep_W*/      exit(1);
/*                    Common_fatjet_deep_W*/    }
/*                    Common_fatjet_deep_W*/    Common_fatjet_deep_W_isLoaded = true;
/*                    Common_fatjet_deep_W*/  }
/*                    Common_fatjet_deep_W*/  return *Common_fatjet_deep_W_;
/*                    Common_fatjet_deep_W*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_Z*/const vector<float> &VVVTree::Common_fatjet_deepMD_Z() {
/*                  Common_fatjet_deepMD_Z*/  if (not Common_fatjet_deepMD_Z_isLoaded) {
/*                  Common_fatjet_deepMD_Z*/    if (Common_fatjet_deepMD_Z_branch != 0) {
/*                  Common_fatjet_deepMD_Z*/      Common_fatjet_deepMD_Z_branch->GetEntry(index);
/*                  Common_fatjet_deepMD_Z*/    } else {
/*                  Common_fatjet_deepMD_Z*/      printf("branch Common_fatjet_deepMD_Z_branch does not exist!\n");
/*                  Common_fatjet_deepMD_Z*/      exit(1);
/*                  Common_fatjet_deepMD_Z*/    }
/*                  Common_fatjet_deepMD_Z*/    Common_fatjet_deepMD_Z_isLoaded = true;
/*                  Common_fatjet_deepMD_Z*/  }
/*                  Common_fatjet_deepMD_Z*/  return *Common_fatjet_deepMD_Z_;
/*                  Common_fatjet_deepMD_Z*/}

//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_Z*/const vector<float> &VVVTree::Common_fatjet_deep_Z() {
/*                    Common_fatjet_deep_Z*/  if (not Common_fatjet_deep_Z_isLoaded) {
/*                    Common_fatjet_deep_Z*/    if (Common_fatjet_deep_Z_branch != 0) {
/*                    Common_fatjet_deep_Z*/      Common_fatjet_deep_Z_branch->GetEntry(index);
/*                    Common_fatjet_deep_Z*/    } else {
/*                    Common_fatjet_deep_Z*/      printf("branch Common_fatjet_deep_Z_branch does not exist!\n");
/*                    Common_fatjet_deep_Z*/      exit(1);
/*                    Common_fatjet_deep_Z*/    }
/*                    Common_fatjet_deep_Z*/    Common_fatjet_deep_Z_isLoaded = true;
/*                    Common_fatjet_deep_Z*/  }
/*                    Common_fatjet_deep_Z*/  return *Common_fatjet_deep_Z_;
/*                    Common_fatjet_deep_Z*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_T*/const vector<float> &VVVTree::Common_fatjet_deepMD_T() {
/*                  Common_fatjet_deepMD_T*/  if (not Common_fatjet_deepMD_T_isLoaded) {
/*                  Common_fatjet_deepMD_T*/    if (Common_fatjet_deepMD_T_branch != 0) {
/*                  Common_fatjet_deepMD_T*/      Common_fatjet_deepMD_T_branch->GetEntry(index);
/*                  Common_fatjet_deepMD_T*/    } else {
/*                  Common_fatjet_deepMD_T*/      printf("branch Common_fatjet_deepMD_T_branch does not exist!\n");
/*                  Common_fatjet_deepMD_T*/      exit(1);
/*                  Common_fatjet_deepMD_T*/    }
/*                  Common_fatjet_deepMD_T*/    Common_fatjet_deepMD_T_isLoaded = true;
/*                  Common_fatjet_deepMD_T*/  }
/*                  Common_fatjet_deepMD_T*/  return *Common_fatjet_deepMD_T_;
/*                  Common_fatjet_deepMD_T*/}

//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_T*/const vector<float> &VVVTree::Common_fatjet_deep_T() {
/*                    Common_fatjet_deep_T*/  if (not Common_fatjet_deep_T_isLoaded) {
/*                    Common_fatjet_deep_T*/    if (Common_fatjet_deep_T_branch != 0) {
/*                    Common_fatjet_deep_T*/      Common_fatjet_deep_T_branch->GetEntry(index);
/*                    Common_fatjet_deep_T*/    } else {
/*                    Common_fatjet_deep_T*/      printf("branch Common_fatjet_deep_T_branch does not exist!\n");
/*                    Common_fatjet_deep_T*/      exit(1);
/*                    Common_fatjet_deep_T*/    }
/*                    Common_fatjet_deep_T*/    Common_fatjet_deep_T_isLoaded = true;
/*                    Common_fatjet_deep_T*/  }
/*                    Common_fatjet_deep_T*/  return *Common_fatjet_deep_T_;
/*                    Common_fatjet_deep_T*/}

//---------------------------------------------------------------------------------
/*                 Common_fatjet_deepMD_bb*/const vector<float> &VVVTree::Common_fatjet_deepMD_bb() {
/*                 Common_fatjet_deepMD_bb*/  if (not Common_fatjet_deepMD_bb_isLoaded) {
/*                 Common_fatjet_deepMD_bb*/    if (Common_fatjet_deepMD_bb_branch != 0) {
/*                 Common_fatjet_deepMD_bb*/      Common_fatjet_deepMD_bb_branch->GetEntry(index);
/*                 Common_fatjet_deepMD_bb*/    } else {
/*                 Common_fatjet_deepMD_bb*/      printf("branch Common_fatjet_deepMD_bb_branch does not exist!\n");
/*                 Common_fatjet_deepMD_bb*/      exit(1);
/*                 Common_fatjet_deepMD_bb*/    }
/*                 Common_fatjet_deepMD_bb*/    Common_fatjet_deepMD_bb_isLoaded = true;
/*                 Common_fatjet_deepMD_bb*/  }
/*                 Common_fatjet_deepMD_bb*/  return *Common_fatjet_deepMD_bb_;
/*                 Common_fatjet_deepMD_bb*/}

//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNetMD_W*/const vector<float> &VVVTree::Common_fatjet_particleNetMD_W() {
/*           Common_fatjet_particleNetMD_W*/  if (not Common_fatjet_particleNetMD_W_isLoaded) {
/*           Common_fatjet_particleNetMD_W*/    if (Common_fatjet_particleNetMD_W_branch != 0) {
/*           Common_fatjet_particleNetMD_W*/      Common_fatjet_particleNetMD_W_branch->GetEntry(index);
/*           Common_fatjet_particleNetMD_W*/    } else {
/*           Common_fatjet_particleNetMD_W*/      printf("branch Common_fatjet_particleNetMD_W_branch does not exist!\n");
/*           Common_fatjet_particleNetMD_W*/      exit(1);
/*           Common_fatjet_particleNetMD_W*/    }
/*           Common_fatjet_particleNetMD_W*/    Common_fatjet_particleNetMD_W_isLoaded = true;
/*           Common_fatjet_particleNetMD_W*/  }
/*           Common_fatjet_particleNetMD_W*/  return *Common_fatjet_particleNetMD_W_;
/*           Common_fatjet_particleNetMD_W*/}

//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xqq*/const vector<float> &VVVTree::Common_fatjet_particleNetMD_Xqq() {
/*         Common_fatjet_particleNetMD_Xqq*/  if (not Common_fatjet_particleNetMD_Xqq_isLoaded) {
/*         Common_fatjet_particleNetMD_Xqq*/    if (Common_fatjet_particleNetMD_Xqq_branch != 0) {
/*         Common_fatjet_particleNetMD_Xqq*/      Common_fatjet_particleNetMD_Xqq_branch->GetEntry(index);
/*         Common_fatjet_particleNetMD_Xqq*/    } else {
/*         Common_fatjet_particleNetMD_Xqq*/      printf("branch Common_fatjet_particleNetMD_Xqq_branch does not exist!\n");
/*         Common_fatjet_particleNetMD_Xqq*/      exit(1);
/*         Common_fatjet_particleNetMD_Xqq*/    }
/*         Common_fatjet_particleNetMD_Xqq*/    Common_fatjet_particleNetMD_Xqq_isLoaded = true;
/*         Common_fatjet_particleNetMD_Xqq*/  }
/*         Common_fatjet_particleNetMD_Xqq*/  return *Common_fatjet_particleNetMD_Xqq_;
/*         Common_fatjet_particleNetMD_Xqq*/}

//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xcc*/const vector<float> &VVVTree::Common_fatjet_particleNetMD_Xcc() {
/*         Common_fatjet_particleNetMD_Xcc*/  if (not Common_fatjet_particleNetMD_Xcc_isLoaded) {
/*         Common_fatjet_particleNetMD_Xcc*/    if (Common_fatjet_particleNetMD_Xcc_branch != 0) {
/*         Common_fatjet_particleNetMD_Xcc*/      Common_fatjet_particleNetMD_Xcc_branch->GetEntry(index);
/*         Common_fatjet_particleNetMD_Xcc*/    } else {
/*         Common_fatjet_particleNetMD_Xcc*/      printf("branch Common_fatjet_particleNetMD_Xcc_branch does not exist!\n");
/*         Common_fatjet_particleNetMD_Xcc*/      exit(1);
/*         Common_fatjet_particleNetMD_Xcc*/    }
/*         Common_fatjet_particleNetMD_Xcc*/    Common_fatjet_particleNetMD_Xcc_isLoaded = true;
/*         Common_fatjet_particleNetMD_Xcc*/  }
/*         Common_fatjet_particleNetMD_Xcc*/  return *Common_fatjet_particleNetMD_Xcc_;
/*         Common_fatjet_particleNetMD_Xcc*/}

//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xbb*/const vector<float> &VVVTree::Common_fatjet_particleNetMD_Xbb() {
/*         Common_fatjet_particleNetMD_Xbb*/  if (not Common_fatjet_particleNetMD_Xbb_isLoaded) {
/*         Common_fatjet_particleNetMD_Xbb*/    if (Common_fatjet_particleNetMD_Xbb_branch != 0) {
/*         Common_fatjet_particleNetMD_Xbb*/      Common_fatjet_particleNetMD_Xbb_branch->GetEntry(index);
/*         Common_fatjet_particleNetMD_Xbb*/    } else {
/*         Common_fatjet_particleNetMD_Xbb*/      printf("branch Common_fatjet_particleNetMD_Xbb_branch does not exist!\n");
/*         Common_fatjet_particleNetMD_Xbb*/      exit(1);
/*         Common_fatjet_particleNetMD_Xbb*/    }
/*         Common_fatjet_particleNetMD_Xbb*/    Common_fatjet_particleNetMD_Xbb_isLoaded = true;
/*         Common_fatjet_particleNetMD_Xbb*/  }
/*         Common_fatjet_particleNetMD_Xbb*/  return *Common_fatjet_particleNetMD_Xbb_;
/*         Common_fatjet_particleNetMD_Xbb*/}

//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_QCD*/const vector<float> &VVVTree::Common_fatjet_particleNetMD_QCD() {
/*         Common_fatjet_particleNetMD_QCD*/  if (not Common_fatjet_particleNetMD_QCD_isLoaded) {
/*         Common_fatjet_particleNetMD_QCD*/    if (Common_fatjet_particleNetMD_QCD_branch != 0) {
/*         Common_fatjet_particleNetMD_QCD*/      Common_fatjet_particleNetMD_QCD_branch->GetEntry(index);
/*         Common_fatjet_particleNetMD_QCD*/    } else {
/*         Common_fatjet_particleNetMD_QCD*/      printf("branch Common_fatjet_particleNetMD_QCD_branch does not exist!\n");
/*         Common_fatjet_particleNetMD_QCD*/      exit(1);
/*         Common_fatjet_particleNetMD_QCD*/    }
/*         Common_fatjet_particleNetMD_QCD*/    Common_fatjet_particleNetMD_QCD_isLoaded = true;
/*         Common_fatjet_particleNetMD_QCD*/  }
/*         Common_fatjet_particleNetMD_QCD*/  return *Common_fatjet_particleNetMD_QCD_;
/*         Common_fatjet_particleNetMD_QCD*/}

//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNet_QCD*/const vector<float> &VVVTree::Common_fatjet_particleNet_QCD() {
/*           Common_fatjet_particleNet_QCD*/  if (not Common_fatjet_particleNet_QCD_isLoaded) {
/*           Common_fatjet_particleNet_QCD*/    if (Common_fatjet_particleNet_QCD_branch != 0) {
/*           Common_fatjet_particleNet_QCD*/      Common_fatjet_particleNet_QCD_branch->GetEntry(index);
/*           Common_fatjet_particleNet_QCD*/    } else {
/*           Common_fatjet_particleNet_QCD*/      printf("branch Common_fatjet_particleNet_QCD_branch does not exist!\n");
/*           Common_fatjet_particleNet_QCD*/      exit(1);
/*           Common_fatjet_particleNet_QCD*/    }
/*           Common_fatjet_particleNet_QCD*/    Common_fatjet_particleNet_QCD_isLoaded = true;
/*           Common_fatjet_particleNet_QCD*/  }
/*           Common_fatjet_particleNet_QCD*/  return *Common_fatjet_particleNet_QCD_;
/*           Common_fatjet_particleNet_QCD*/}

//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_W*/const vector<float> &VVVTree::Common_fatjet_particleNet_W() {
/*             Common_fatjet_particleNet_W*/  if (not Common_fatjet_particleNet_W_isLoaded) {
/*             Common_fatjet_particleNet_W*/    if (Common_fatjet_particleNet_W_branch != 0) {
/*             Common_fatjet_particleNet_W*/      Common_fatjet_particleNet_W_branch->GetEntry(index);
/*             Common_fatjet_particleNet_W*/    } else {
/*             Common_fatjet_particleNet_W*/      printf("branch Common_fatjet_particleNet_W_branch does not exist!\n");
/*             Common_fatjet_particleNet_W*/      exit(1);
/*             Common_fatjet_particleNet_W*/    }
/*             Common_fatjet_particleNet_W*/    Common_fatjet_particleNet_W_isLoaded = true;
/*             Common_fatjet_particleNet_W*/  }
/*             Common_fatjet_particleNet_W*/  return *Common_fatjet_particleNet_W_;
/*             Common_fatjet_particleNet_W*/}

//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_Z*/const vector<float> &VVVTree::Common_fatjet_particleNet_Z() {
/*             Common_fatjet_particleNet_Z*/  if (not Common_fatjet_particleNet_Z_isLoaded) {
/*             Common_fatjet_particleNet_Z*/    if (Common_fatjet_particleNet_Z_branch != 0) {
/*             Common_fatjet_particleNet_Z*/      Common_fatjet_particleNet_Z_branch->GetEntry(index);
/*             Common_fatjet_particleNet_Z*/    } else {
/*             Common_fatjet_particleNet_Z*/      printf("branch Common_fatjet_particleNet_Z_branch does not exist!\n");
/*             Common_fatjet_particleNet_Z*/      exit(1);
/*             Common_fatjet_particleNet_Z*/    }
/*             Common_fatjet_particleNet_Z*/    Common_fatjet_particleNet_Z_isLoaded = true;
/*             Common_fatjet_particleNet_Z*/  }
/*             Common_fatjet_particleNet_Z*/  return *Common_fatjet_particleNet_Z_;
/*             Common_fatjet_particleNet_Z*/}

//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_T*/const vector<float> &VVVTree::Common_fatjet_particleNet_T() {
/*             Common_fatjet_particleNet_T*/  if (not Common_fatjet_particleNet_T_isLoaded) {
/*             Common_fatjet_particleNet_T*/    if (Common_fatjet_particleNet_T_branch != 0) {
/*             Common_fatjet_particleNet_T*/      Common_fatjet_particleNet_T_branch->GetEntry(index);
/*             Common_fatjet_particleNet_T*/    } else {
/*             Common_fatjet_particleNet_T*/      printf("branch Common_fatjet_particleNet_T_branch does not exist!\n");
/*             Common_fatjet_particleNet_T*/      exit(1);
/*             Common_fatjet_particleNet_T*/    }
/*             Common_fatjet_particleNet_T*/    Common_fatjet_particleNet_T_isLoaded = true;
/*             Common_fatjet_particleNet_T*/  }
/*             Common_fatjet_particleNet_T*/  return *Common_fatjet_particleNet_T_;
/*             Common_fatjet_particleNet_T*/}

//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau3*/const vector<float> &VVVTree::Common_fatjet_tau3() {
/*                      Common_fatjet_tau3*/  if (not Common_fatjet_tau3_isLoaded) {
/*                      Common_fatjet_tau3*/    if (Common_fatjet_tau3_branch != 0) {
/*                      Common_fatjet_tau3*/      Common_fatjet_tau3_branch->GetEntry(index);
/*                      Common_fatjet_tau3*/    } else {
/*                      Common_fatjet_tau3*/      printf("branch Common_fatjet_tau3_branch does not exist!\n");
/*                      Common_fatjet_tau3*/      exit(1);
/*                      Common_fatjet_tau3*/    }
/*                      Common_fatjet_tau3*/    Common_fatjet_tau3_isLoaded = true;
/*                      Common_fatjet_tau3*/  }
/*                      Common_fatjet_tau3*/  return *Common_fatjet_tau3_;
/*                      Common_fatjet_tau3*/}

//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau2*/const vector<float> &VVVTree::Common_fatjet_tau2() {
/*                      Common_fatjet_tau2*/  if (not Common_fatjet_tau2_isLoaded) {
/*                      Common_fatjet_tau2*/    if (Common_fatjet_tau2_branch != 0) {
/*                      Common_fatjet_tau2*/      Common_fatjet_tau2_branch->GetEntry(index);
/*                      Common_fatjet_tau2*/    } else {
/*                      Common_fatjet_tau2*/      printf("branch Common_fatjet_tau2_branch does not exist!\n");
/*                      Common_fatjet_tau2*/      exit(1);
/*                      Common_fatjet_tau2*/    }
/*                      Common_fatjet_tau2*/    Common_fatjet_tau2_isLoaded = true;
/*                      Common_fatjet_tau2*/  }
/*                      Common_fatjet_tau2*/  return *Common_fatjet_tau2_;
/*                      Common_fatjet_tau2*/}

//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau1*/const vector<float> &VVVTree::Common_fatjet_tau1() {
/*                      Common_fatjet_tau1*/  if (not Common_fatjet_tau1_isLoaded) {
/*                      Common_fatjet_tau1*/    if (Common_fatjet_tau1_branch != 0) {
/*                      Common_fatjet_tau1*/      Common_fatjet_tau1_branch->GetEntry(index);
/*                      Common_fatjet_tau1*/    } else {
/*                      Common_fatjet_tau1*/      printf("branch Common_fatjet_tau1_branch does not exist!\n");
/*                      Common_fatjet_tau1*/      exit(1);
/*                      Common_fatjet_tau1*/    }
/*                      Common_fatjet_tau1*/    Common_fatjet_tau1_isLoaded = true;
/*                      Common_fatjet_tau1*/  }
/*                      Common_fatjet_tau1*/  return *Common_fatjet_tau1_;
/*                      Common_fatjet_tau1*/}

//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau32*/const vector<float> &VVVTree::Common_fatjet_tau32() {
/*                     Common_fatjet_tau32*/  if (not Common_fatjet_tau32_isLoaded) {
/*                     Common_fatjet_tau32*/    if (Common_fatjet_tau32_branch != 0) {
/*                     Common_fatjet_tau32*/      Common_fatjet_tau32_branch->GetEntry(index);
/*                     Common_fatjet_tau32*/    } else {
/*                     Common_fatjet_tau32*/      printf("branch Common_fatjet_tau32_branch does not exist!\n");
/*                     Common_fatjet_tau32*/      exit(1);
/*                     Common_fatjet_tau32*/    }
/*                     Common_fatjet_tau32*/    Common_fatjet_tau32_isLoaded = true;
/*                     Common_fatjet_tau32*/  }
/*                     Common_fatjet_tau32*/  return *Common_fatjet_tau32_;
/*                     Common_fatjet_tau32*/}

//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau21*/const vector<float> &VVVTree::Common_fatjet_tau21() {
/*                     Common_fatjet_tau21*/  if (not Common_fatjet_tau21_isLoaded) {
/*                     Common_fatjet_tau21*/    if (Common_fatjet_tau21_branch != 0) {
/*                     Common_fatjet_tau21*/      Common_fatjet_tau21_branch->GetEntry(index);
/*                     Common_fatjet_tau21*/    } else {
/*                     Common_fatjet_tau21*/      printf("branch Common_fatjet_tau21_branch does not exist!\n");
/*                     Common_fatjet_tau21*/      exit(1);
/*                     Common_fatjet_tau21*/    }
/*                     Common_fatjet_tau21*/    Common_fatjet_tau21_isLoaded = true;
/*                     Common_fatjet_tau21*/  }
/*                     Common_fatjet_tau21*/  return *Common_fatjet_tau21_;
/*                     Common_fatjet_tau21*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_pt*/const vector<float> &VVVTree::Common_fatjet_subjet0_pt() {
/*                Common_fatjet_subjet0_pt*/  if (not Common_fatjet_subjet0_pt_isLoaded) {
/*                Common_fatjet_subjet0_pt*/    if (Common_fatjet_subjet0_pt_branch != 0) {
/*                Common_fatjet_subjet0_pt*/      Common_fatjet_subjet0_pt_branch->GetEntry(index);
/*                Common_fatjet_subjet0_pt*/    } else {
/*                Common_fatjet_subjet0_pt*/      printf("branch Common_fatjet_subjet0_pt_branch does not exist!\n");
/*                Common_fatjet_subjet0_pt*/      exit(1);
/*                Common_fatjet_subjet0_pt*/    }
/*                Common_fatjet_subjet0_pt*/    Common_fatjet_subjet0_pt_isLoaded = true;
/*                Common_fatjet_subjet0_pt*/  }
/*                Common_fatjet_subjet0_pt*/  return *Common_fatjet_subjet0_pt_;
/*                Common_fatjet_subjet0_pt*/}

//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_eta*/const vector<float> &VVVTree::Common_fatjet_subjet0_eta() {
/*               Common_fatjet_subjet0_eta*/  if (not Common_fatjet_subjet0_eta_isLoaded) {
/*               Common_fatjet_subjet0_eta*/    if (Common_fatjet_subjet0_eta_branch != 0) {
/*               Common_fatjet_subjet0_eta*/      Common_fatjet_subjet0_eta_branch->GetEntry(index);
/*               Common_fatjet_subjet0_eta*/    } else {
/*               Common_fatjet_subjet0_eta*/      printf("branch Common_fatjet_subjet0_eta_branch does not exist!\n");
/*               Common_fatjet_subjet0_eta*/      exit(1);
/*               Common_fatjet_subjet0_eta*/    }
/*               Common_fatjet_subjet0_eta*/    Common_fatjet_subjet0_eta_isLoaded = true;
/*               Common_fatjet_subjet0_eta*/  }
/*               Common_fatjet_subjet0_eta*/  return *Common_fatjet_subjet0_eta_;
/*               Common_fatjet_subjet0_eta*/}

//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_phi*/const vector<float> &VVVTree::Common_fatjet_subjet0_phi() {
/*               Common_fatjet_subjet0_phi*/  if (not Common_fatjet_subjet0_phi_isLoaded) {
/*               Common_fatjet_subjet0_phi*/    if (Common_fatjet_subjet0_phi_branch != 0) {
/*               Common_fatjet_subjet0_phi*/      Common_fatjet_subjet0_phi_branch->GetEntry(index);
/*               Common_fatjet_subjet0_phi*/    } else {
/*               Common_fatjet_subjet0_phi*/      printf("branch Common_fatjet_subjet0_phi_branch does not exist!\n");
/*               Common_fatjet_subjet0_phi*/      exit(1);
/*               Common_fatjet_subjet0_phi*/    }
/*               Common_fatjet_subjet0_phi*/    Common_fatjet_subjet0_phi_isLoaded = true;
/*               Common_fatjet_subjet0_phi*/  }
/*               Common_fatjet_subjet0_phi*/  return *Common_fatjet_subjet0_phi_;
/*               Common_fatjet_subjet0_phi*/}

//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet0_mass*/const vector<float> &VVVTree::Common_fatjet_subjet0_mass() {
/*              Common_fatjet_subjet0_mass*/  if (not Common_fatjet_subjet0_mass_isLoaded) {
/*              Common_fatjet_subjet0_mass*/    if (Common_fatjet_subjet0_mass_branch != 0) {
/*              Common_fatjet_subjet0_mass*/      Common_fatjet_subjet0_mass_branch->GetEntry(index);
/*              Common_fatjet_subjet0_mass*/    } else {
/*              Common_fatjet_subjet0_mass*/      printf("branch Common_fatjet_subjet0_mass_branch does not exist!\n");
/*              Common_fatjet_subjet0_mass*/      exit(1);
/*              Common_fatjet_subjet0_mass*/    }
/*              Common_fatjet_subjet0_mass*/    Common_fatjet_subjet0_mass_isLoaded = true;
/*              Common_fatjet_subjet0_mass*/  }
/*              Common_fatjet_subjet0_mass*/  return *Common_fatjet_subjet0_mass_;
/*              Common_fatjet_subjet0_mass*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_pt*/const vector<float> &VVVTree::Common_fatjet_subjet1_pt() {
/*                Common_fatjet_subjet1_pt*/  if (not Common_fatjet_subjet1_pt_isLoaded) {
/*                Common_fatjet_subjet1_pt*/    if (Common_fatjet_subjet1_pt_branch != 0) {
/*                Common_fatjet_subjet1_pt*/      Common_fatjet_subjet1_pt_branch->GetEntry(index);
/*                Common_fatjet_subjet1_pt*/    } else {
/*                Common_fatjet_subjet1_pt*/      printf("branch Common_fatjet_subjet1_pt_branch does not exist!\n");
/*                Common_fatjet_subjet1_pt*/      exit(1);
/*                Common_fatjet_subjet1_pt*/    }
/*                Common_fatjet_subjet1_pt*/    Common_fatjet_subjet1_pt_isLoaded = true;
/*                Common_fatjet_subjet1_pt*/  }
/*                Common_fatjet_subjet1_pt*/  return *Common_fatjet_subjet1_pt_;
/*                Common_fatjet_subjet1_pt*/}

//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_eta*/const vector<float> &VVVTree::Common_fatjet_subjet1_eta() {
/*               Common_fatjet_subjet1_eta*/  if (not Common_fatjet_subjet1_eta_isLoaded) {
/*               Common_fatjet_subjet1_eta*/    if (Common_fatjet_subjet1_eta_branch != 0) {
/*               Common_fatjet_subjet1_eta*/      Common_fatjet_subjet1_eta_branch->GetEntry(index);
/*               Common_fatjet_subjet1_eta*/    } else {
/*               Common_fatjet_subjet1_eta*/      printf("branch Common_fatjet_subjet1_eta_branch does not exist!\n");
/*               Common_fatjet_subjet1_eta*/      exit(1);
/*               Common_fatjet_subjet1_eta*/    }
/*               Common_fatjet_subjet1_eta*/    Common_fatjet_subjet1_eta_isLoaded = true;
/*               Common_fatjet_subjet1_eta*/  }
/*               Common_fatjet_subjet1_eta*/  return *Common_fatjet_subjet1_eta_;
/*               Common_fatjet_subjet1_eta*/}

//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_phi*/const vector<float> &VVVTree::Common_fatjet_subjet1_phi() {
/*               Common_fatjet_subjet1_phi*/  if (not Common_fatjet_subjet1_phi_isLoaded) {
/*               Common_fatjet_subjet1_phi*/    if (Common_fatjet_subjet1_phi_branch != 0) {
/*               Common_fatjet_subjet1_phi*/      Common_fatjet_subjet1_phi_branch->GetEntry(index);
/*               Common_fatjet_subjet1_phi*/    } else {
/*               Common_fatjet_subjet1_phi*/      printf("branch Common_fatjet_subjet1_phi_branch does not exist!\n");
/*               Common_fatjet_subjet1_phi*/      exit(1);
/*               Common_fatjet_subjet1_phi*/    }
/*               Common_fatjet_subjet1_phi*/    Common_fatjet_subjet1_phi_isLoaded = true;
/*               Common_fatjet_subjet1_phi*/  }
/*               Common_fatjet_subjet1_phi*/  return *Common_fatjet_subjet1_phi_;
/*               Common_fatjet_subjet1_phi*/}

//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet1_mass*/const vector<float> &VVVTree::Common_fatjet_subjet1_mass() {
/*              Common_fatjet_subjet1_mass*/  if (not Common_fatjet_subjet1_mass_isLoaded) {
/*              Common_fatjet_subjet1_mass*/    if (Common_fatjet_subjet1_mass_branch != 0) {
/*              Common_fatjet_subjet1_mass*/      Common_fatjet_subjet1_mass_branch->GetEntry(index);
/*              Common_fatjet_subjet1_mass*/    } else {
/*              Common_fatjet_subjet1_mass*/      printf("branch Common_fatjet_subjet1_mass_branch does not exist!\n");
/*              Common_fatjet_subjet1_mass*/      exit(1);
/*              Common_fatjet_subjet1_mass*/    }
/*              Common_fatjet_subjet1_mass*/    Common_fatjet_subjet1_mass_isLoaded = true;
/*              Common_fatjet_subjet1_mass*/  }
/*              Common_fatjet_subjet1_mass*/  return *Common_fatjet_subjet1_mass_;
/*              Common_fatjet_subjet1_mass*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_fatjet_subjet0_p4() {
/*                Common_fatjet_subjet0_p4*/  if (not Common_fatjet_subjet0_p4_isLoaded) {
/*                Common_fatjet_subjet0_p4*/    if (Common_fatjet_subjet0_p4_branch != 0) {
/*                Common_fatjet_subjet0_p4*/      Common_fatjet_subjet0_p4_branch->GetEntry(index);
/*                Common_fatjet_subjet0_p4*/    } else {
/*                Common_fatjet_subjet0_p4*/      printf("branch Common_fatjet_subjet0_p4_branch does not exist!\n");
/*                Common_fatjet_subjet0_p4*/      exit(1);
/*                Common_fatjet_subjet0_p4*/    }
/*                Common_fatjet_subjet0_p4*/    Common_fatjet_subjet0_p4_isLoaded = true;
/*                Common_fatjet_subjet0_p4*/  }
/*                Common_fatjet_subjet0_p4*/  return *Common_fatjet_subjet0_p4_;
/*                Common_fatjet_subjet0_p4*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_fatjet_subjet1_p4() {
/*                Common_fatjet_subjet1_p4*/  if (not Common_fatjet_subjet1_p4_isLoaded) {
/*                Common_fatjet_subjet1_p4*/    if (Common_fatjet_subjet1_p4_branch != 0) {
/*                Common_fatjet_subjet1_p4*/      Common_fatjet_subjet1_p4_branch->GetEntry(index);
/*                Common_fatjet_subjet1_p4*/    } else {
/*                Common_fatjet_subjet1_p4*/      printf("branch Common_fatjet_subjet1_p4_branch does not exist!\n");
/*                Common_fatjet_subjet1_p4*/      exit(1);
/*                Common_fatjet_subjet1_p4*/    }
/*                Common_fatjet_subjet1_p4*/    Common_fatjet_subjet1_p4_isLoaded = true;
/*                Common_fatjet_subjet1_p4*/  }
/*                Common_fatjet_subjet1_p4*/  return *Common_fatjet_subjet1_p4_;
/*                Common_fatjet_subjet1_p4*/}

//---------------------------------------------------------------------------------
/*                        Common_fatjet_WP*/const vector<int> &VVVTree::Common_fatjet_WP() {
/*                        Common_fatjet_WP*/  if (not Common_fatjet_WP_isLoaded) {
/*                        Common_fatjet_WP*/    if (Common_fatjet_WP_branch != 0) {
/*                        Common_fatjet_WP*/      Common_fatjet_WP_branch->GetEntry(index);
/*                        Common_fatjet_WP*/    } else {
/*                        Common_fatjet_WP*/      printf("branch Common_fatjet_WP_branch does not exist!\n");
/*                        Common_fatjet_WP*/      exit(1);
/*                        Common_fatjet_WP*/    }
/*                        Common_fatjet_WP*/    Common_fatjet_WP_isLoaded = true;
/*                        Common_fatjet_WP*/  }
/*                        Common_fatjet_WP*/  return *Common_fatjet_WP_;
/*                        Common_fatjet_WP*/}

//---------------------------------------------------------------------------------
/*                     Common_fatjet_WP_MD*/const vector<int> &VVVTree::Common_fatjet_WP_MD() {
/*                     Common_fatjet_WP_MD*/  if (not Common_fatjet_WP_MD_isLoaded) {
/*                     Common_fatjet_WP_MD*/    if (Common_fatjet_WP_MD_branch != 0) {
/*                     Common_fatjet_WP_MD*/      Common_fatjet_WP_MD_branch->GetEntry(index);
/*                     Common_fatjet_WP_MD*/    } else {
/*                     Common_fatjet_WP_MD*/      printf("branch Common_fatjet_WP_MD_branch does not exist!\n");
/*                     Common_fatjet_WP_MD*/      exit(1);
/*                     Common_fatjet_WP_MD*/    }
/*                     Common_fatjet_WP_MD*/    Common_fatjet_WP_MD_isLoaded = true;
/*                     Common_fatjet_WP_MD*/  }
/*                     Common_fatjet_WP_MD*/  return *Common_fatjet_WP_MD_;
/*                     Common_fatjet_WP_MD*/}

//---------------------------------------------------------------------------------
/*            Common_fatjet_WP_antimasscut*/const vector<int> &VVVTree::Common_fatjet_WP_antimasscut() {
/*            Common_fatjet_WP_antimasscut*/  if (not Common_fatjet_WP_antimasscut_isLoaded) {
/*            Common_fatjet_WP_antimasscut*/    if (Common_fatjet_WP_antimasscut_branch != 0) {
/*            Common_fatjet_WP_antimasscut*/      Common_fatjet_WP_antimasscut_branch->GetEntry(index);
/*            Common_fatjet_WP_antimasscut*/    } else {
/*            Common_fatjet_WP_antimasscut*/      printf("branch Common_fatjet_WP_antimasscut_branch does not exist!\n");
/*            Common_fatjet_WP_antimasscut*/      exit(1);
/*            Common_fatjet_WP_antimasscut*/    }
/*            Common_fatjet_WP_antimasscut*/    Common_fatjet_WP_antimasscut_isLoaded = true;
/*            Common_fatjet_WP_antimasscut*/  }
/*            Common_fatjet_WP_antimasscut*/  return *Common_fatjet_WP_antimasscut_;
/*            Common_fatjet_WP_antimasscut*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFVLoose*/const vector<float> &VVVTree::Common_fatjet_SFVLoose() {
/*                  Common_fatjet_SFVLoose*/  if (not Common_fatjet_SFVLoose_isLoaded) {
/*                  Common_fatjet_SFVLoose*/    if (Common_fatjet_SFVLoose_branch != 0) {
/*                  Common_fatjet_SFVLoose*/      Common_fatjet_SFVLoose_branch->GetEntry(index);
/*                  Common_fatjet_SFVLoose*/    } else {
/*                  Common_fatjet_SFVLoose*/      printf("branch Common_fatjet_SFVLoose_branch does not exist!\n");
/*                  Common_fatjet_SFVLoose*/      exit(1);
/*                  Common_fatjet_SFVLoose*/    }
/*                  Common_fatjet_SFVLoose*/    Common_fatjet_SFVLoose_isLoaded = true;
/*                  Common_fatjet_SFVLoose*/  }
/*                  Common_fatjet_SFVLoose*/  return *Common_fatjet_SFVLoose_;
/*                  Common_fatjet_SFVLoose*/}

//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFLoose*/const vector<float> &VVVTree::Common_fatjet_SFLoose() {
/*                   Common_fatjet_SFLoose*/  if (not Common_fatjet_SFLoose_isLoaded) {
/*                   Common_fatjet_SFLoose*/    if (Common_fatjet_SFLoose_branch != 0) {
/*                   Common_fatjet_SFLoose*/      Common_fatjet_SFLoose_branch->GetEntry(index);
/*                   Common_fatjet_SFLoose*/    } else {
/*                   Common_fatjet_SFLoose*/      printf("branch Common_fatjet_SFLoose_branch does not exist!\n");
/*                   Common_fatjet_SFLoose*/      exit(1);
/*                   Common_fatjet_SFLoose*/    }
/*                   Common_fatjet_SFLoose*/    Common_fatjet_SFLoose_isLoaded = true;
/*                   Common_fatjet_SFLoose*/  }
/*                   Common_fatjet_SFLoose*/  return *Common_fatjet_SFLoose_;
/*                   Common_fatjet_SFLoose*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFMedium*/const vector<float> &VVVTree::Common_fatjet_SFMedium() {
/*                  Common_fatjet_SFMedium*/  if (not Common_fatjet_SFMedium_isLoaded) {
/*                  Common_fatjet_SFMedium*/    if (Common_fatjet_SFMedium_branch != 0) {
/*                  Common_fatjet_SFMedium*/      Common_fatjet_SFMedium_branch->GetEntry(index);
/*                  Common_fatjet_SFMedium*/    } else {
/*                  Common_fatjet_SFMedium*/      printf("branch Common_fatjet_SFMedium_branch does not exist!\n");
/*                  Common_fatjet_SFMedium*/      exit(1);
/*                  Common_fatjet_SFMedium*/    }
/*                  Common_fatjet_SFMedium*/    Common_fatjet_SFMedium_isLoaded = true;
/*                  Common_fatjet_SFMedium*/  }
/*                  Common_fatjet_SFMedium*/  return *Common_fatjet_SFMedium_;
/*                  Common_fatjet_SFMedium*/}

//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFTight*/const vector<float> &VVVTree::Common_fatjet_SFTight() {
/*                   Common_fatjet_SFTight*/  if (not Common_fatjet_SFTight_isLoaded) {
/*                   Common_fatjet_SFTight*/    if (Common_fatjet_SFTight_branch != 0) {
/*                   Common_fatjet_SFTight*/      Common_fatjet_SFTight_branch->GetEntry(index);
/*                   Common_fatjet_SFTight*/    } else {
/*                   Common_fatjet_SFTight*/      printf("branch Common_fatjet_SFTight_branch does not exist!\n");
/*                   Common_fatjet_SFTight*/      exit(1);
/*                   Common_fatjet_SFTight*/    }
/*                   Common_fatjet_SFTight*/    Common_fatjet_SFTight_isLoaded = true;
/*                   Common_fatjet_SFTight*/  }
/*                   Common_fatjet_SFTight*/  return *Common_fatjet_SFTight_;
/*                   Common_fatjet_SFTight*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnVLoose*/const vector<float> &VVVTree::Common_fatjet_SFdnVLoose() {
/*                Common_fatjet_SFdnVLoose*/  if (not Common_fatjet_SFdnVLoose_isLoaded) {
/*                Common_fatjet_SFdnVLoose*/    if (Common_fatjet_SFdnVLoose_branch != 0) {
/*                Common_fatjet_SFdnVLoose*/      Common_fatjet_SFdnVLoose_branch->GetEntry(index);
/*                Common_fatjet_SFdnVLoose*/    } else {
/*                Common_fatjet_SFdnVLoose*/      printf("branch Common_fatjet_SFdnVLoose_branch does not exist!\n");
/*                Common_fatjet_SFdnVLoose*/      exit(1);
/*                Common_fatjet_SFdnVLoose*/    }
/*                Common_fatjet_SFdnVLoose*/    Common_fatjet_SFdnVLoose_isLoaded = true;
/*                Common_fatjet_SFdnVLoose*/  }
/*                Common_fatjet_SFdnVLoose*/  return *Common_fatjet_SFdnVLoose_;
/*                Common_fatjet_SFdnVLoose*/}

//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnLoose*/const vector<float> &VVVTree::Common_fatjet_SFdnLoose() {
/*                 Common_fatjet_SFdnLoose*/  if (not Common_fatjet_SFdnLoose_isLoaded) {
/*                 Common_fatjet_SFdnLoose*/    if (Common_fatjet_SFdnLoose_branch != 0) {
/*                 Common_fatjet_SFdnLoose*/      Common_fatjet_SFdnLoose_branch->GetEntry(index);
/*                 Common_fatjet_SFdnLoose*/    } else {
/*                 Common_fatjet_SFdnLoose*/      printf("branch Common_fatjet_SFdnLoose_branch does not exist!\n");
/*                 Common_fatjet_SFdnLoose*/      exit(1);
/*                 Common_fatjet_SFdnLoose*/    }
/*                 Common_fatjet_SFdnLoose*/    Common_fatjet_SFdnLoose_isLoaded = true;
/*                 Common_fatjet_SFdnLoose*/  }
/*                 Common_fatjet_SFdnLoose*/  return *Common_fatjet_SFdnLoose_;
/*                 Common_fatjet_SFdnLoose*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnMedium*/const vector<float> &VVVTree::Common_fatjet_SFdnMedium() {
/*                Common_fatjet_SFdnMedium*/  if (not Common_fatjet_SFdnMedium_isLoaded) {
/*                Common_fatjet_SFdnMedium*/    if (Common_fatjet_SFdnMedium_branch != 0) {
/*                Common_fatjet_SFdnMedium*/      Common_fatjet_SFdnMedium_branch->GetEntry(index);
/*                Common_fatjet_SFdnMedium*/    } else {
/*                Common_fatjet_SFdnMedium*/      printf("branch Common_fatjet_SFdnMedium_branch does not exist!\n");
/*                Common_fatjet_SFdnMedium*/      exit(1);
/*                Common_fatjet_SFdnMedium*/    }
/*                Common_fatjet_SFdnMedium*/    Common_fatjet_SFdnMedium_isLoaded = true;
/*                Common_fatjet_SFdnMedium*/  }
/*                Common_fatjet_SFdnMedium*/  return *Common_fatjet_SFdnMedium_;
/*                Common_fatjet_SFdnMedium*/}

//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnTight*/const vector<float> &VVVTree::Common_fatjet_SFdnTight() {
/*                 Common_fatjet_SFdnTight*/  if (not Common_fatjet_SFdnTight_isLoaded) {
/*                 Common_fatjet_SFdnTight*/    if (Common_fatjet_SFdnTight_branch != 0) {
/*                 Common_fatjet_SFdnTight*/      Common_fatjet_SFdnTight_branch->GetEntry(index);
/*                 Common_fatjet_SFdnTight*/    } else {
/*                 Common_fatjet_SFdnTight*/      printf("branch Common_fatjet_SFdnTight_branch does not exist!\n");
/*                 Common_fatjet_SFdnTight*/      exit(1);
/*                 Common_fatjet_SFdnTight*/    }
/*                 Common_fatjet_SFdnTight*/    Common_fatjet_SFdnTight_isLoaded = true;
/*                 Common_fatjet_SFdnTight*/  }
/*                 Common_fatjet_SFdnTight*/  return *Common_fatjet_SFdnTight_;
/*                 Common_fatjet_SFdnTight*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupVLoose*/const vector<float> &VVVTree::Common_fatjet_SFupVLoose() {
/*                Common_fatjet_SFupVLoose*/  if (not Common_fatjet_SFupVLoose_isLoaded) {
/*                Common_fatjet_SFupVLoose*/    if (Common_fatjet_SFupVLoose_branch != 0) {
/*                Common_fatjet_SFupVLoose*/      Common_fatjet_SFupVLoose_branch->GetEntry(index);
/*                Common_fatjet_SFupVLoose*/    } else {
/*                Common_fatjet_SFupVLoose*/      printf("branch Common_fatjet_SFupVLoose_branch does not exist!\n");
/*                Common_fatjet_SFupVLoose*/      exit(1);
/*                Common_fatjet_SFupVLoose*/    }
/*                Common_fatjet_SFupVLoose*/    Common_fatjet_SFupVLoose_isLoaded = true;
/*                Common_fatjet_SFupVLoose*/  }
/*                Common_fatjet_SFupVLoose*/  return *Common_fatjet_SFupVLoose_;
/*                Common_fatjet_SFupVLoose*/}

//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupLoose*/const vector<float> &VVVTree::Common_fatjet_SFupLoose() {
/*                 Common_fatjet_SFupLoose*/  if (not Common_fatjet_SFupLoose_isLoaded) {
/*                 Common_fatjet_SFupLoose*/    if (Common_fatjet_SFupLoose_branch != 0) {
/*                 Common_fatjet_SFupLoose*/      Common_fatjet_SFupLoose_branch->GetEntry(index);
/*                 Common_fatjet_SFupLoose*/    } else {
/*                 Common_fatjet_SFupLoose*/      printf("branch Common_fatjet_SFupLoose_branch does not exist!\n");
/*                 Common_fatjet_SFupLoose*/      exit(1);
/*                 Common_fatjet_SFupLoose*/    }
/*                 Common_fatjet_SFupLoose*/    Common_fatjet_SFupLoose_isLoaded = true;
/*                 Common_fatjet_SFupLoose*/  }
/*                 Common_fatjet_SFupLoose*/  return *Common_fatjet_SFupLoose_;
/*                 Common_fatjet_SFupLoose*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupMedium*/const vector<float> &VVVTree::Common_fatjet_SFupMedium() {
/*                Common_fatjet_SFupMedium*/  if (not Common_fatjet_SFupMedium_isLoaded) {
/*                Common_fatjet_SFupMedium*/    if (Common_fatjet_SFupMedium_branch != 0) {
/*                Common_fatjet_SFupMedium*/      Common_fatjet_SFupMedium_branch->GetEntry(index);
/*                Common_fatjet_SFupMedium*/    } else {
/*                Common_fatjet_SFupMedium*/      printf("branch Common_fatjet_SFupMedium_branch does not exist!\n");
/*                Common_fatjet_SFupMedium*/      exit(1);
/*                Common_fatjet_SFupMedium*/    }
/*                Common_fatjet_SFupMedium*/    Common_fatjet_SFupMedium_isLoaded = true;
/*                Common_fatjet_SFupMedium*/  }
/*                Common_fatjet_SFupMedium*/  return *Common_fatjet_SFupMedium_;
/*                Common_fatjet_SFupMedium*/}

//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupTight*/const vector<float> &VVVTree::Common_fatjet_SFupTight() {
/*                 Common_fatjet_SFupTight*/  if (not Common_fatjet_SFupTight_isLoaded) {
/*                 Common_fatjet_SFupTight*/    if (Common_fatjet_SFupTight_branch != 0) {
/*                 Common_fatjet_SFupTight*/      Common_fatjet_SFupTight_branch->GetEntry(index);
/*                 Common_fatjet_SFupTight*/    } else {
/*                 Common_fatjet_SFupTight*/      printf("branch Common_fatjet_SFupTight_branch does not exist!\n");
/*                 Common_fatjet_SFupTight*/      exit(1);
/*                 Common_fatjet_SFupTight*/    }
/*                 Common_fatjet_SFupTight*/    Common_fatjet_SFupTight_isLoaded = true;
/*                 Common_fatjet_SFupTight*/  }
/*                 Common_fatjet_SFupTight*/  return *Common_fatjet_SFupTight_;
/*                 Common_fatjet_SFupTight*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesup*/const vector<float> &VVVTree::Common_fatjet_pt_jesup() {
/*                  Common_fatjet_pt_jesup*/  if (not Common_fatjet_pt_jesup_isLoaded) {
/*                  Common_fatjet_pt_jesup*/    if (Common_fatjet_pt_jesup_branch != 0) {
/*                  Common_fatjet_pt_jesup*/      Common_fatjet_pt_jesup_branch->GetEntry(index);
/*                  Common_fatjet_pt_jesup*/    } else {
/*                  Common_fatjet_pt_jesup*/      printf("branch Common_fatjet_pt_jesup_branch does not exist!\n");
/*                  Common_fatjet_pt_jesup*/      exit(1);
/*                  Common_fatjet_pt_jesup*/    }
/*                  Common_fatjet_pt_jesup*/    Common_fatjet_pt_jesup_isLoaded = true;
/*                  Common_fatjet_pt_jesup*/  }
/*                  Common_fatjet_pt_jesup*/  return *Common_fatjet_pt_jesup_;
/*                  Common_fatjet_pt_jesup*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesdn*/const vector<float> &VVVTree::Common_fatjet_pt_jesdn() {
/*                  Common_fatjet_pt_jesdn*/  if (not Common_fatjet_pt_jesdn_isLoaded) {
/*                  Common_fatjet_pt_jesdn*/    if (Common_fatjet_pt_jesdn_branch != 0) {
/*                  Common_fatjet_pt_jesdn*/      Common_fatjet_pt_jesdn_branch->GetEntry(index);
/*                  Common_fatjet_pt_jesdn*/    } else {
/*                  Common_fatjet_pt_jesdn*/      printf("branch Common_fatjet_pt_jesdn_branch does not exist!\n");
/*                  Common_fatjet_pt_jesdn*/      exit(1);
/*                  Common_fatjet_pt_jesdn*/    }
/*                  Common_fatjet_pt_jesdn*/    Common_fatjet_pt_jesdn_isLoaded = true;
/*                  Common_fatjet_pt_jesdn*/  }
/*                  Common_fatjet_pt_jesdn*/  return *Common_fatjet_pt_jesdn_;
/*                  Common_fatjet_pt_jesdn*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerup*/const vector<float> &VVVTree::Common_fatjet_pt_jerup() {
/*                  Common_fatjet_pt_jerup*/  if (not Common_fatjet_pt_jerup_isLoaded) {
/*                  Common_fatjet_pt_jerup*/    if (Common_fatjet_pt_jerup_branch != 0) {
/*                  Common_fatjet_pt_jerup*/      Common_fatjet_pt_jerup_branch->GetEntry(index);
/*                  Common_fatjet_pt_jerup*/    } else {
/*                  Common_fatjet_pt_jerup*/      printf("branch Common_fatjet_pt_jerup_branch does not exist!\n");
/*                  Common_fatjet_pt_jerup*/      exit(1);
/*                  Common_fatjet_pt_jerup*/    }
/*                  Common_fatjet_pt_jerup*/    Common_fatjet_pt_jerup_isLoaded = true;
/*                  Common_fatjet_pt_jerup*/  }
/*                  Common_fatjet_pt_jerup*/  return *Common_fatjet_pt_jerup_;
/*                  Common_fatjet_pt_jerup*/}

//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerdn*/const vector<float> &VVVTree::Common_fatjet_pt_jerdn() {
/*                  Common_fatjet_pt_jerdn*/  if (not Common_fatjet_pt_jerdn_isLoaded) {
/*                  Common_fatjet_pt_jerdn*/    if (Common_fatjet_pt_jerdn_branch != 0) {
/*                  Common_fatjet_pt_jerdn*/      Common_fatjet_pt_jerdn_branch->GetEntry(index);
/*                  Common_fatjet_pt_jerdn*/    } else {
/*                  Common_fatjet_pt_jerdn*/      printf("branch Common_fatjet_pt_jerdn_branch does not exist!\n");
/*                  Common_fatjet_pt_jerdn*/      exit(1);
/*                  Common_fatjet_pt_jerdn*/    }
/*                  Common_fatjet_pt_jerdn*/    Common_fatjet_pt_jerdn_isLoaded = true;
/*                  Common_fatjet_pt_jerdn*/  }
/*                  Common_fatjet_pt_jerdn*/  return *Common_fatjet_pt_jerdn_;
/*                  Common_fatjet_pt_jerdn*/}

//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesup*/const vector<float> &VVVTree::Common_fatjet_msoftdrop_jesup() {
/*           Common_fatjet_msoftdrop_jesup*/  if (not Common_fatjet_msoftdrop_jesup_isLoaded) {
/*           Common_fatjet_msoftdrop_jesup*/    if (Common_fatjet_msoftdrop_jesup_branch != 0) {
/*           Common_fatjet_msoftdrop_jesup*/      Common_fatjet_msoftdrop_jesup_branch->GetEntry(index);
/*           Common_fatjet_msoftdrop_jesup*/    } else {
/*           Common_fatjet_msoftdrop_jesup*/      printf("branch Common_fatjet_msoftdrop_jesup_branch does not exist!\n");
/*           Common_fatjet_msoftdrop_jesup*/      exit(1);
/*           Common_fatjet_msoftdrop_jesup*/    }
/*           Common_fatjet_msoftdrop_jesup*/    Common_fatjet_msoftdrop_jesup_isLoaded = true;
/*           Common_fatjet_msoftdrop_jesup*/  }
/*           Common_fatjet_msoftdrop_jesup*/  return *Common_fatjet_msoftdrop_jesup_;
/*           Common_fatjet_msoftdrop_jesup*/}

//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesdn*/const vector<float> &VVVTree::Common_fatjet_msoftdrop_jesdn() {
/*           Common_fatjet_msoftdrop_jesdn*/  if (not Common_fatjet_msoftdrop_jesdn_isLoaded) {
/*           Common_fatjet_msoftdrop_jesdn*/    if (Common_fatjet_msoftdrop_jesdn_branch != 0) {
/*           Common_fatjet_msoftdrop_jesdn*/      Common_fatjet_msoftdrop_jesdn_branch->GetEntry(index);
/*           Common_fatjet_msoftdrop_jesdn*/    } else {
/*           Common_fatjet_msoftdrop_jesdn*/      printf("branch Common_fatjet_msoftdrop_jesdn_branch does not exist!\n");
/*           Common_fatjet_msoftdrop_jesdn*/      exit(1);
/*           Common_fatjet_msoftdrop_jesdn*/    }
/*           Common_fatjet_msoftdrop_jesdn*/    Common_fatjet_msoftdrop_jesdn_isLoaded = true;
/*           Common_fatjet_msoftdrop_jesdn*/  }
/*           Common_fatjet_msoftdrop_jesdn*/  return *Common_fatjet_msoftdrop_jesdn_;
/*           Common_fatjet_msoftdrop_jesdn*/}

//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerup*/const vector<float> &VVVTree::Common_fatjet_msoftdrop_jerup() {
/*           Common_fatjet_msoftdrop_jerup*/  if (not Common_fatjet_msoftdrop_jerup_isLoaded) {
/*           Common_fatjet_msoftdrop_jerup*/    if (Common_fatjet_msoftdrop_jerup_branch != 0) {
/*           Common_fatjet_msoftdrop_jerup*/      Common_fatjet_msoftdrop_jerup_branch->GetEntry(index);
/*           Common_fatjet_msoftdrop_jerup*/    } else {
/*           Common_fatjet_msoftdrop_jerup*/      printf("branch Common_fatjet_msoftdrop_jerup_branch does not exist!\n");
/*           Common_fatjet_msoftdrop_jerup*/      exit(1);
/*           Common_fatjet_msoftdrop_jerup*/    }
/*           Common_fatjet_msoftdrop_jerup*/    Common_fatjet_msoftdrop_jerup_isLoaded = true;
/*           Common_fatjet_msoftdrop_jerup*/  }
/*           Common_fatjet_msoftdrop_jerup*/  return *Common_fatjet_msoftdrop_jerup_;
/*           Common_fatjet_msoftdrop_jerup*/}

//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerdn*/const vector<float> &VVVTree::Common_fatjet_msoftdrop_jerdn() {
/*           Common_fatjet_msoftdrop_jerdn*/  if (not Common_fatjet_msoftdrop_jerdn_isLoaded) {
/*           Common_fatjet_msoftdrop_jerdn*/    if (Common_fatjet_msoftdrop_jerdn_branch != 0) {
/*           Common_fatjet_msoftdrop_jerdn*/      Common_fatjet_msoftdrop_jerdn_branch->GetEntry(index);
/*           Common_fatjet_msoftdrop_jerdn*/    } else {
/*           Common_fatjet_msoftdrop_jerdn*/      printf("branch Common_fatjet_msoftdrop_jerdn_branch does not exist!\n");
/*           Common_fatjet_msoftdrop_jerdn*/      exit(1);
/*           Common_fatjet_msoftdrop_jerdn*/    }
/*           Common_fatjet_msoftdrop_jerdn*/    Common_fatjet_msoftdrop_jerdn_isLoaded = true;
/*           Common_fatjet_msoftdrop_jerdn*/  }
/*           Common_fatjet_msoftdrop_jerdn*/  return *Common_fatjet_msoftdrop_jerdn_;
/*           Common_fatjet_msoftdrop_jerdn*/}

//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsup*/const vector<float> &VVVTree::Common_fatjet_msoftdrop_jmsup() {
/*           Common_fatjet_msoftdrop_jmsup*/  if (not Common_fatjet_msoftdrop_jmsup_isLoaded) {
/*           Common_fatjet_msoftdrop_jmsup*/    if (Common_fatjet_msoftdrop_jmsup_branch != 0) {
/*           Common_fatjet_msoftdrop_jmsup*/      Common_fatjet_msoftdrop_jmsup_branch->GetEntry(index);
/*           Common_fatjet_msoftdrop_jmsup*/    } else {
/*           Common_fatjet_msoftdrop_jmsup*/      printf("branch Common_fatjet_msoftdrop_jmsup_branch does not exist!\n");
/*           Common_fatjet_msoftdrop_jmsup*/      exit(1);
/*           Common_fatjet_msoftdrop_jmsup*/    }
/*           Common_fatjet_msoftdrop_jmsup*/    Common_fatjet_msoftdrop_jmsup_isLoaded = true;
/*           Common_fatjet_msoftdrop_jmsup*/  }
/*           Common_fatjet_msoftdrop_jmsup*/  return *Common_fatjet_msoftdrop_jmsup_;
/*           Common_fatjet_msoftdrop_jmsup*/}

//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsdn*/const vector<float> &VVVTree::Common_fatjet_msoftdrop_jmsdn() {
/*           Common_fatjet_msoftdrop_jmsdn*/  if (not Common_fatjet_msoftdrop_jmsdn_isLoaded) {
/*           Common_fatjet_msoftdrop_jmsdn*/    if (Common_fatjet_msoftdrop_jmsdn_branch != 0) {
/*           Common_fatjet_msoftdrop_jmsdn*/      Common_fatjet_msoftdrop_jmsdn_branch->GetEntry(index);
/*           Common_fatjet_msoftdrop_jmsdn*/    } else {
/*           Common_fatjet_msoftdrop_jmsdn*/      printf("branch Common_fatjet_msoftdrop_jmsdn_branch does not exist!\n");
/*           Common_fatjet_msoftdrop_jmsdn*/      exit(1);
/*           Common_fatjet_msoftdrop_jmsdn*/    }
/*           Common_fatjet_msoftdrop_jmsdn*/    Common_fatjet_msoftdrop_jmsdn_isLoaded = true;
/*           Common_fatjet_msoftdrop_jmsdn*/  }
/*           Common_fatjet_msoftdrop_jmsdn*/  return *Common_fatjet_msoftdrop_jmsdn_;
/*           Common_fatjet_msoftdrop_jmsdn*/}

//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrup*/const vector<float> &VVVTree::Common_fatjet_msoftdrop_jmrup() {
/*           Common_fatjet_msoftdrop_jmrup*/  if (not Common_fatjet_msoftdrop_jmrup_isLoaded) {
/*           Common_fatjet_msoftdrop_jmrup*/    if (Common_fatjet_msoftdrop_jmrup_branch != 0) {
/*           Common_fatjet_msoftdrop_jmrup*/      Common_fatjet_msoftdrop_jmrup_branch->GetEntry(index);
/*           Common_fatjet_msoftdrop_jmrup*/    } else {
/*           Common_fatjet_msoftdrop_jmrup*/      printf("branch Common_fatjet_msoftdrop_jmrup_branch does not exist!\n");
/*           Common_fatjet_msoftdrop_jmrup*/      exit(1);
/*           Common_fatjet_msoftdrop_jmrup*/    }
/*           Common_fatjet_msoftdrop_jmrup*/    Common_fatjet_msoftdrop_jmrup_isLoaded = true;
/*           Common_fatjet_msoftdrop_jmrup*/  }
/*           Common_fatjet_msoftdrop_jmrup*/  return *Common_fatjet_msoftdrop_jmrup_;
/*           Common_fatjet_msoftdrop_jmrup*/}

//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrdn*/const vector<float> &VVVTree::Common_fatjet_msoftdrop_jmrdn() {
/*           Common_fatjet_msoftdrop_jmrdn*/  if (not Common_fatjet_msoftdrop_jmrdn_isLoaded) {
/*           Common_fatjet_msoftdrop_jmrdn*/    if (Common_fatjet_msoftdrop_jmrdn_branch != 0) {
/*           Common_fatjet_msoftdrop_jmrdn*/      Common_fatjet_msoftdrop_jmrdn_branch->GetEntry(index);
/*           Common_fatjet_msoftdrop_jmrdn*/    } else {
/*           Common_fatjet_msoftdrop_jmrdn*/      printf("branch Common_fatjet_msoftdrop_jmrdn_branch does not exist!\n");
/*           Common_fatjet_msoftdrop_jmrdn*/      exit(1);
/*           Common_fatjet_msoftdrop_jmrdn*/    }
/*           Common_fatjet_msoftdrop_jmrdn*/    Common_fatjet_msoftdrop_jmrdn_isLoaded = true;
/*           Common_fatjet_msoftdrop_jmrdn*/  }
/*           Common_fatjet_msoftdrop_jmrdn*/  return *Common_fatjet_msoftdrop_jmrdn_;
/*           Common_fatjet_msoftdrop_jmrdn*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesup*/const vector<float> &VVVTree::Common_fatjet_mass_jesup() {
/*                Common_fatjet_mass_jesup*/  if (not Common_fatjet_mass_jesup_isLoaded) {
/*                Common_fatjet_mass_jesup*/    if (Common_fatjet_mass_jesup_branch != 0) {
/*                Common_fatjet_mass_jesup*/      Common_fatjet_mass_jesup_branch->GetEntry(index);
/*                Common_fatjet_mass_jesup*/    } else {
/*                Common_fatjet_mass_jesup*/      printf("branch Common_fatjet_mass_jesup_branch does not exist!\n");
/*                Common_fatjet_mass_jesup*/      exit(1);
/*                Common_fatjet_mass_jesup*/    }
/*                Common_fatjet_mass_jesup*/    Common_fatjet_mass_jesup_isLoaded = true;
/*                Common_fatjet_mass_jesup*/  }
/*                Common_fatjet_mass_jesup*/  return *Common_fatjet_mass_jesup_;
/*                Common_fatjet_mass_jesup*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesdn*/const vector<float> &VVVTree::Common_fatjet_mass_jesdn() {
/*                Common_fatjet_mass_jesdn*/  if (not Common_fatjet_mass_jesdn_isLoaded) {
/*                Common_fatjet_mass_jesdn*/    if (Common_fatjet_mass_jesdn_branch != 0) {
/*                Common_fatjet_mass_jesdn*/      Common_fatjet_mass_jesdn_branch->GetEntry(index);
/*                Common_fatjet_mass_jesdn*/    } else {
/*                Common_fatjet_mass_jesdn*/      printf("branch Common_fatjet_mass_jesdn_branch does not exist!\n");
/*                Common_fatjet_mass_jesdn*/      exit(1);
/*                Common_fatjet_mass_jesdn*/    }
/*                Common_fatjet_mass_jesdn*/    Common_fatjet_mass_jesdn_isLoaded = true;
/*                Common_fatjet_mass_jesdn*/  }
/*                Common_fatjet_mass_jesdn*/  return *Common_fatjet_mass_jesdn_;
/*                Common_fatjet_mass_jesdn*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerup*/const vector<float> &VVVTree::Common_fatjet_mass_jerup() {
/*                Common_fatjet_mass_jerup*/  if (not Common_fatjet_mass_jerup_isLoaded) {
/*                Common_fatjet_mass_jerup*/    if (Common_fatjet_mass_jerup_branch != 0) {
/*                Common_fatjet_mass_jerup*/      Common_fatjet_mass_jerup_branch->GetEntry(index);
/*                Common_fatjet_mass_jerup*/    } else {
/*                Common_fatjet_mass_jerup*/      printf("branch Common_fatjet_mass_jerup_branch does not exist!\n");
/*                Common_fatjet_mass_jerup*/      exit(1);
/*                Common_fatjet_mass_jerup*/    }
/*                Common_fatjet_mass_jerup*/    Common_fatjet_mass_jerup_isLoaded = true;
/*                Common_fatjet_mass_jerup*/  }
/*                Common_fatjet_mass_jerup*/  return *Common_fatjet_mass_jerup_;
/*                Common_fatjet_mass_jerup*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerdn*/const vector<float> &VVVTree::Common_fatjet_mass_jerdn() {
/*                Common_fatjet_mass_jerdn*/  if (not Common_fatjet_mass_jerdn_isLoaded) {
/*                Common_fatjet_mass_jerdn*/    if (Common_fatjet_mass_jerdn_branch != 0) {
/*                Common_fatjet_mass_jerdn*/      Common_fatjet_mass_jerdn_branch->GetEntry(index);
/*                Common_fatjet_mass_jerdn*/    } else {
/*                Common_fatjet_mass_jerdn*/      printf("branch Common_fatjet_mass_jerdn_branch does not exist!\n");
/*                Common_fatjet_mass_jerdn*/      exit(1);
/*                Common_fatjet_mass_jerdn*/    }
/*                Common_fatjet_mass_jerdn*/    Common_fatjet_mass_jerdn_isLoaded = true;
/*                Common_fatjet_mass_jerdn*/  }
/*                Common_fatjet_mass_jerdn*/  return *Common_fatjet_mass_jerdn_;
/*                Common_fatjet_mass_jerdn*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsup*/const vector<float> &VVVTree::Common_fatjet_mass_jmsup() {
/*                Common_fatjet_mass_jmsup*/  if (not Common_fatjet_mass_jmsup_isLoaded) {
/*                Common_fatjet_mass_jmsup*/    if (Common_fatjet_mass_jmsup_branch != 0) {
/*                Common_fatjet_mass_jmsup*/      Common_fatjet_mass_jmsup_branch->GetEntry(index);
/*                Common_fatjet_mass_jmsup*/    } else {
/*                Common_fatjet_mass_jmsup*/      printf("branch Common_fatjet_mass_jmsup_branch does not exist!\n");
/*                Common_fatjet_mass_jmsup*/      exit(1);
/*                Common_fatjet_mass_jmsup*/    }
/*                Common_fatjet_mass_jmsup*/    Common_fatjet_mass_jmsup_isLoaded = true;
/*                Common_fatjet_mass_jmsup*/  }
/*                Common_fatjet_mass_jmsup*/  return *Common_fatjet_mass_jmsup_;
/*                Common_fatjet_mass_jmsup*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsdn*/const vector<float> &VVVTree::Common_fatjet_mass_jmsdn() {
/*                Common_fatjet_mass_jmsdn*/  if (not Common_fatjet_mass_jmsdn_isLoaded) {
/*                Common_fatjet_mass_jmsdn*/    if (Common_fatjet_mass_jmsdn_branch != 0) {
/*                Common_fatjet_mass_jmsdn*/      Common_fatjet_mass_jmsdn_branch->GetEntry(index);
/*                Common_fatjet_mass_jmsdn*/    } else {
/*                Common_fatjet_mass_jmsdn*/      printf("branch Common_fatjet_mass_jmsdn_branch does not exist!\n");
/*                Common_fatjet_mass_jmsdn*/      exit(1);
/*                Common_fatjet_mass_jmsdn*/    }
/*                Common_fatjet_mass_jmsdn*/    Common_fatjet_mass_jmsdn_isLoaded = true;
/*                Common_fatjet_mass_jmsdn*/  }
/*                Common_fatjet_mass_jmsdn*/  return *Common_fatjet_mass_jmsdn_;
/*                Common_fatjet_mass_jmsdn*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrup*/const vector<float> &VVVTree::Common_fatjet_mass_jmrup() {
/*                Common_fatjet_mass_jmrup*/  if (not Common_fatjet_mass_jmrup_isLoaded) {
/*                Common_fatjet_mass_jmrup*/    if (Common_fatjet_mass_jmrup_branch != 0) {
/*                Common_fatjet_mass_jmrup*/      Common_fatjet_mass_jmrup_branch->GetEntry(index);
/*                Common_fatjet_mass_jmrup*/    } else {
/*                Common_fatjet_mass_jmrup*/      printf("branch Common_fatjet_mass_jmrup_branch does not exist!\n");
/*                Common_fatjet_mass_jmrup*/      exit(1);
/*                Common_fatjet_mass_jmrup*/    }
/*                Common_fatjet_mass_jmrup*/    Common_fatjet_mass_jmrup_isLoaded = true;
/*                Common_fatjet_mass_jmrup*/  }
/*                Common_fatjet_mass_jmrup*/  return *Common_fatjet_mass_jmrup_;
/*                Common_fatjet_mass_jmrup*/}

//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrdn*/const vector<float> &VVVTree::Common_fatjet_mass_jmrdn() {
/*                Common_fatjet_mass_jmrdn*/  if (not Common_fatjet_mass_jmrdn_isLoaded) {
/*                Common_fatjet_mass_jmrdn*/    if (Common_fatjet_mass_jmrdn_branch != 0) {
/*                Common_fatjet_mass_jmrdn*/      Common_fatjet_mass_jmrdn_branch->GetEntry(index);
/*                Common_fatjet_mass_jmrdn*/    } else {
/*                Common_fatjet_mass_jmrdn*/      printf("branch Common_fatjet_mass_jmrdn_branch does not exist!\n");
/*                Common_fatjet_mass_jmrdn*/      exit(1);
/*                Common_fatjet_mass_jmrdn*/    }
/*                Common_fatjet_mass_jmrdn*/    Common_fatjet_mass_jmrdn_isLoaded = true;
/*                Common_fatjet_mass_jmrdn*/  }
/*                Common_fatjet_mass_jmrdn*/  return *Common_fatjet_mass_jmrdn_;
/*                Common_fatjet_mass_jmrdn*/}

//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFVLoose*/const float &VVVTree::Common_eventweight_fatjet_SFVLoose() {
/*      Common_eventweight_fatjet_SFVLoose*/  if (not Common_eventweight_fatjet_SFVLoose_isLoaded) {
/*      Common_eventweight_fatjet_SFVLoose*/    if (Common_eventweight_fatjet_SFVLoose_branch != 0) {
/*      Common_eventweight_fatjet_SFVLoose*/      Common_eventweight_fatjet_SFVLoose_branch->GetEntry(index);
/*      Common_eventweight_fatjet_SFVLoose*/    } else {
/*      Common_eventweight_fatjet_SFVLoose*/      printf("branch Common_eventweight_fatjet_SFVLoose_branch does not exist!\n");
/*      Common_eventweight_fatjet_SFVLoose*/      exit(1);
/*      Common_eventweight_fatjet_SFVLoose*/    }
/*      Common_eventweight_fatjet_SFVLoose*/    Common_eventweight_fatjet_SFVLoose_isLoaded = true;
/*      Common_eventweight_fatjet_SFVLoose*/  }
/*      Common_eventweight_fatjet_SFVLoose*/  return Common_eventweight_fatjet_SFVLoose_;
/*      Common_eventweight_fatjet_SFVLoose*/}

//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFLoose*/const float &VVVTree::Common_eventweight_fatjet_SFLoose() {
/*       Common_eventweight_fatjet_SFLoose*/  if (not Common_eventweight_fatjet_SFLoose_isLoaded) {
/*       Common_eventweight_fatjet_SFLoose*/    if (Common_eventweight_fatjet_SFLoose_branch != 0) {
/*       Common_eventweight_fatjet_SFLoose*/      Common_eventweight_fatjet_SFLoose_branch->GetEntry(index);
/*       Common_eventweight_fatjet_SFLoose*/    } else {
/*       Common_eventweight_fatjet_SFLoose*/      printf("branch Common_eventweight_fatjet_SFLoose_branch does not exist!\n");
/*       Common_eventweight_fatjet_SFLoose*/      exit(1);
/*       Common_eventweight_fatjet_SFLoose*/    }
/*       Common_eventweight_fatjet_SFLoose*/    Common_eventweight_fatjet_SFLoose_isLoaded = true;
/*       Common_eventweight_fatjet_SFLoose*/  }
/*       Common_eventweight_fatjet_SFLoose*/  return Common_eventweight_fatjet_SFLoose_;
/*       Common_eventweight_fatjet_SFLoose*/}

//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFMedium*/const float &VVVTree::Common_eventweight_fatjet_SFMedium() {
/*      Common_eventweight_fatjet_SFMedium*/  if (not Common_eventweight_fatjet_SFMedium_isLoaded) {
/*      Common_eventweight_fatjet_SFMedium*/    if (Common_eventweight_fatjet_SFMedium_branch != 0) {
/*      Common_eventweight_fatjet_SFMedium*/      Common_eventweight_fatjet_SFMedium_branch->GetEntry(index);
/*      Common_eventweight_fatjet_SFMedium*/    } else {
/*      Common_eventweight_fatjet_SFMedium*/      printf("branch Common_eventweight_fatjet_SFMedium_branch does not exist!\n");
/*      Common_eventweight_fatjet_SFMedium*/      exit(1);
/*      Common_eventweight_fatjet_SFMedium*/    }
/*      Common_eventweight_fatjet_SFMedium*/    Common_eventweight_fatjet_SFMedium_isLoaded = true;
/*      Common_eventweight_fatjet_SFMedium*/  }
/*      Common_eventweight_fatjet_SFMedium*/  return Common_eventweight_fatjet_SFMedium_;
/*      Common_eventweight_fatjet_SFMedium*/}

//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFTight*/const float &VVVTree::Common_eventweight_fatjet_SFTight() {
/*       Common_eventweight_fatjet_SFTight*/  if (not Common_eventweight_fatjet_SFTight_isLoaded) {
/*       Common_eventweight_fatjet_SFTight*/    if (Common_eventweight_fatjet_SFTight_branch != 0) {
/*       Common_eventweight_fatjet_SFTight*/      Common_eventweight_fatjet_SFTight_branch->GetEntry(index);
/*       Common_eventweight_fatjet_SFTight*/    } else {
/*       Common_eventweight_fatjet_SFTight*/      printf("branch Common_eventweight_fatjet_SFTight_branch does not exist!\n");
/*       Common_eventweight_fatjet_SFTight*/      exit(1);
/*       Common_eventweight_fatjet_SFTight*/    }
/*       Common_eventweight_fatjet_SFTight*/    Common_eventweight_fatjet_SFTight_isLoaded = true;
/*       Common_eventweight_fatjet_SFTight*/  }
/*       Common_eventweight_fatjet_SFTight*/  return Common_eventweight_fatjet_SFTight_;
/*       Common_eventweight_fatjet_SFTight*/}

//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnVLoose*/const float &VVVTree::Common_eventweight_fatjet_SFdnVLoose() {
/*    Common_eventweight_fatjet_SFdnVLoose*/  if (not Common_eventweight_fatjet_SFdnVLoose_isLoaded) {
/*    Common_eventweight_fatjet_SFdnVLoose*/    if (Common_eventweight_fatjet_SFdnVLoose_branch != 0) {
/*    Common_eventweight_fatjet_SFdnVLoose*/      Common_eventweight_fatjet_SFdnVLoose_branch->GetEntry(index);
/*    Common_eventweight_fatjet_SFdnVLoose*/    } else {
/*    Common_eventweight_fatjet_SFdnVLoose*/      printf("branch Common_eventweight_fatjet_SFdnVLoose_branch does not exist!\n");
/*    Common_eventweight_fatjet_SFdnVLoose*/      exit(1);
/*    Common_eventweight_fatjet_SFdnVLoose*/    }
/*    Common_eventweight_fatjet_SFdnVLoose*/    Common_eventweight_fatjet_SFdnVLoose_isLoaded = true;
/*    Common_eventweight_fatjet_SFdnVLoose*/  }
/*    Common_eventweight_fatjet_SFdnVLoose*/  return Common_eventweight_fatjet_SFdnVLoose_;
/*    Common_eventweight_fatjet_SFdnVLoose*/}

//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnLoose*/const float &VVVTree::Common_eventweight_fatjet_SFdnLoose() {
/*     Common_eventweight_fatjet_SFdnLoose*/  if (not Common_eventweight_fatjet_SFdnLoose_isLoaded) {
/*     Common_eventweight_fatjet_SFdnLoose*/    if (Common_eventweight_fatjet_SFdnLoose_branch != 0) {
/*     Common_eventweight_fatjet_SFdnLoose*/      Common_eventweight_fatjet_SFdnLoose_branch->GetEntry(index);
/*     Common_eventweight_fatjet_SFdnLoose*/    } else {
/*     Common_eventweight_fatjet_SFdnLoose*/      printf("branch Common_eventweight_fatjet_SFdnLoose_branch does not exist!\n");
/*     Common_eventweight_fatjet_SFdnLoose*/      exit(1);
/*     Common_eventweight_fatjet_SFdnLoose*/    }
/*     Common_eventweight_fatjet_SFdnLoose*/    Common_eventweight_fatjet_SFdnLoose_isLoaded = true;
/*     Common_eventweight_fatjet_SFdnLoose*/  }
/*     Common_eventweight_fatjet_SFdnLoose*/  return Common_eventweight_fatjet_SFdnLoose_;
/*     Common_eventweight_fatjet_SFdnLoose*/}

//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnMedium*/const float &VVVTree::Common_eventweight_fatjet_SFdnMedium() {
/*    Common_eventweight_fatjet_SFdnMedium*/  if (not Common_eventweight_fatjet_SFdnMedium_isLoaded) {
/*    Common_eventweight_fatjet_SFdnMedium*/    if (Common_eventweight_fatjet_SFdnMedium_branch != 0) {
/*    Common_eventweight_fatjet_SFdnMedium*/      Common_eventweight_fatjet_SFdnMedium_branch->GetEntry(index);
/*    Common_eventweight_fatjet_SFdnMedium*/    } else {
/*    Common_eventweight_fatjet_SFdnMedium*/      printf("branch Common_eventweight_fatjet_SFdnMedium_branch does not exist!\n");
/*    Common_eventweight_fatjet_SFdnMedium*/      exit(1);
/*    Common_eventweight_fatjet_SFdnMedium*/    }
/*    Common_eventweight_fatjet_SFdnMedium*/    Common_eventweight_fatjet_SFdnMedium_isLoaded = true;
/*    Common_eventweight_fatjet_SFdnMedium*/  }
/*    Common_eventweight_fatjet_SFdnMedium*/  return Common_eventweight_fatjet_SFdnMedium_;
/*    Common_eventweight_fatjet_SFdnMedium*/}

//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnTight*/const float &VVVTree::Common_eventweight_fatjet_SFdnTight() {
/*     Common_eventweight_fatjet_SFdnTight*/  if (not Common_eventweight_fatjet_SFdnTight_isLoaded) {
/*     Common_eventweight_fatjet_SFdnTight*/    if (Common_eventweight_fatjet_SFdnTight_branch != 0) {
/*     Common_eventweight_fatjet_SFdnTight*/      Common_eventweight_fatjet_SFdnTight_branch->GetEntry(index);
/*     Common_eventweight_fatjet_SFdnTight*/    } else {
/*     Common_eventweight_fatjet_SFdnTight*/      printf("branch Common_eventweight_fatjet_SFdnTight_branch does not exist!\n");
/*     Common_eventweight_fatjet_SFdnTight*/      exit(1);
/*     Common_eventweight_fatjet_SFdnTight*/    }
/*     Common_eventweight_fatjet_SFdnTight*/    Common_eventweight_fatjet_SFdnTight_isLoaded = true;
/*     Common_eventweight_fatjet_SFdnTight*/  }
/*     Common_eventweight_fatjet_SFdnTight*/  return Common_eventweight_fatjet_SFdnTight_;
/*     Common_eventweight_fatjet_SFdnTight*/}

//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupVLoose*/const float &VVVTree::Common_eventweight_fatjet_SFupVLoose() {
/*    Common_eventweight_fatjet_SFupVLoose*/  if (not Common_eventweight_fatjet_SFupVLoose_isLoaded) {
/*    Common_eventweight_fatjet_SFupVLoose*/    if (Common_eventweight_fatjet_SFupVLoose_branch != 0) {
/*    Common_eventweight_fatjet_SFupVLoose*/      Common_eventweight_fatjet_SFupVLoose_branch->GetEntry(index);
/*    Common_eventweight_fatjet_SFupVLoose*/    } else {
/*    Common_eventweight_fatjet_SFupVLoose*/      printf("branch Common_eventweight_fatjet_SFupVLoose_branch does not exist!\n");
/*    Common_eventweight_fatjet_SFupVLoose*/      exit(1);
/*    Common_eventweight_fatjet_SFupVLoose*/    }
/*    Common_eventweight_fatjet_SFupVLoose*/    Common_eventweight_fatjet_SFupVLoose_isLoaded = true;
/*    Common_eventweight_fatjet_SFupVLoose*/  }
/*    Common_eventweight_fatjet_SFupVLoose*/  return Common_eventweight_fatjet_SFupVLoose_;
/*    Common_eventweight_fatjet_SFupVLoose*/}

//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupLoose*/const float &VVVTree::Common_eventweight_fatjet_SFupLoose() {
/*     Common_eventweight_fatjet_SFupLoose*/  if (not Common_eventweight_fatjet_SFupLoose_isLoaded) {
/*     Common_eventweight_fatjet_SFupLoose*/    if (Common_eventweight_fatjet_SFupLoose_branch != 0) {
/*     Common_eventweight_fatjet_SFupLoose*/      Common_eventweight_fatjet_SFupLoose_branch->GetEntry(index);
/*     Common_eventweight_fatjet_SFupLoose*/    } else {
/*     Common_eventweight_fatjet_SFupLoose*/      printf("branch Common_eventweight_fatjet_SFupLoose_branch does not exist!\n");
/*     Common_eventweight_fatjet_SFupLoose*/      exit(1);
/*     Common_eventweight_fatjet_SFupLoose*/    }
/*     Common_eventweight_fatjet_SFupLoose*/    Common_eventweight_fatjet_SFupLoose_isLoaded = true;
/*     Common_eventweight_fatjet_SFupLoose*/  }
/*     Common_eventweight_fatjet_SFupLoose*/  return Common_eventweight_fatjet_SFupLoose_;
/*     Common_eventweight_fatjet_SFupLoose*/}

//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupMedium*/const float &VVVTree::Common_eventweight_fatjet_SFupMedium() {
/*    Common_eventweight_fatjet_SFupMedium*/  if (not Common_eventweight_fatjet_SFupMedium_isLoaded) {
/*    Common_eventweight_fatjet_SFupMedium*/    if (Common_eventweight_fatjet_SFupMedium_branch != 0) {
/*    Common_eventweight_fatjet_SFupMedium*/      Common_eventweight_fatjet_SFupMedium_branch->GetEntry(index);
/*    Common_eventweight_fatjet_SFupMedium*/    } else {
/*    Common_eventweight_fatjet_SFupMedium*/      printf("branch Common_eventweight_fatjet_SFupMedium_branch does not exist!\n");
/*    Common_eventweight_fatjet_SFupMedium*/      exit(1);
/*    Common_eventweight_fatjet_SFupMedium*/    }
/*    Common_eventweight_fatjet_SFupMedium*/    Common_eventweight_fatjet_SFupMedium_isLoaded = true;
/*    Common_eventweight_fatjet_SFupMedium*/  }
/*    Common_eventweight_fatjet_SFupMedium*/  return Common_eventweight_fatjet_SFupMedium_;
/*    Common_eventweight_fatjet_SFupMedium*/}

//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupTight*/const float &VVVTree::Common_eventweight_fatjet_SFupTight() {
/*     Common_eventweight_fatjet_SFupTight*/  if (not Common_eventweight_fatjet_SFupTight_isLoaded) {
/*     Common_eventweight_fatjet_SFupTight*/    if (Common_eventweight_fatjet_SFupTight_branch != 0) {
/*     Common_eventweight_fatjet_SFupTight*/      Common_eventweight_fatjet_SFupTight_branch->GetEntry(index);
/*     Common_eventweight_fatjet_SFupTight*/    } else {
/*     Common_eventweight_fatjet_SFupTight*/      printf("branch Common_eventweight_fatjet_SFupTight_branch does not exist!\n");
/*     Common_eventweight_fatjet_SFupTight*/      exit(1);
/*     Common_eventweight_fatjet_SFupTight*/    }
/*     Common_eventweight_fatjet_SFupTight*/    Common_eventweight_fatjet_SFupTight_isLoaded = true;
/*     Common_eventweight_fatjet_SFupTight*/  }
/*     Common_eventweight_fatjet_SFupTight*/  return Common_eventweight_fatjet_SFupTight_;
/*     Common_eventweight_fatjet_SFupTight*/}

//---------------------------------------------------------------------------------
/*                         Common_nb_loose*/const int &VVVTree::Common_nb_loose() {
/*                         Common_nb_loose*/  if (not Common_nb_loose_isLoaded) {
/*                         Common_nb_loose*/    if (Common_nb_loose_branch != 0) {
/*                         Common_nb_loose*/      Common_nb_loose_branch->GetEntry(index);
/*                         Common_nb_loose*/    } else {
/*                         Common_nb_loose*/      printf("branch Common_nb_loose_branch does not exist!\n");
/*                         Common_nb_loose*/      exit(1);
/*                         Common_nb_loose*/    }
/*                         Common_nb_loose*/    Common_nb_loose_isLoaded = true;
/*                         Common_nb_loose*/  }
/*                         Common_nb_loose*/  return Common_nb_loose_;
/*                         Common_nb_loose*/}

//---------------------------------------------------------------------------------
/*                        Common_nb_medium*/const int &VVVTree::Common_nb_medium() {
/*                        Common_nb_medium*/  if (not Common_nb_medium_isLoaded) {
/*                        Common_nb_medium*/    if (Common_nb_medium_branch != 0) {
/*                        Common_nb_medium*/      Common_nb_medium_branch->GetEntry(index);
/*                        Common_nb_medium*/    } else {
/*                        Common_nb_medium*/      printf("branch Common_nb_medium_branch does not exist!\n");
/*                        Common_nb_medium*/      exit(1);
/*                        Common_nb_medium*/    }
/*                        Common_nb_medium*/    Common_nb_medium_isLoaded = true;
/*                        Common_nb_medium*/  }
/*                        Common_nb_medium*/  return Common_nb_medium_;
/*                        Common_nb_medium*/}

//---------------------------------------------------------------------------------
/*                         Common_nb_tight*/const int &VVVTree::Common_nb_tight() {
/*                         Common_nb_tight*/  if (not Common_nb_tight_isLoaded) {
/*                         Common_nb_tight*/    if (Common_nb_tight_branch != 0) {
/*                         Common_nb_tight*/      Common_nb_tight_branch->GetEntry(index);
/*                         Common_nb_tight*/    } else {
/*                         Common_nb_tight*/      printf("branch Common_nb_tight_branch does not exist!\n");
/*                         Common_nb_tight*/      exit(1);
/*                         Common_nb_tight*/    }
/*                         Common_nb_tight*/    Common_nb_tight_isLoaded = true;
/*                         Common_nb_tight*/  }
/*                         Common_nb_tight*/  return Common_nb_tight_;
/*                         Common_nb_tight*/}

//---------------------------------------------------------------------------------
/*                          Common_gen_idx*/const vector<int> &VVVTree::Common_gen_idx() {
/*                          Common_gen_idx*/  if (not Common_gen_idx_isLoaded) {
/*                          Common_gen_idx*/    if (Common_gen_idx_branch != 0) {
/*                          Common_gen_idx*/      Common_gen_idx_branch->GetEntry(index);
/*                          Common_gen_idx*/    } else {
/*                          Common_gen_idx*/      printf("branch Common_gen_idx_branch does not exist!\n");
/*                          Common_gen_idx*/      exit(1);
/*                          Common_gen_idx*/    }
/*                          Common_gen_idx*/    Common_gen_idx_isLoaded = true;
/*                          Common_gen_idx*/  }
/*                          Common_gen_idx*/  return *Common_gen_idx_;
/*                          Common_gen_idx*/}

//---------------------------------------------------------------------------------
/*                   Common_gen_mother_idx*/const vector<int> &VVVTree::Common_gen_mother_idx() {
/*                   Common_gen_mother_idx*/  if (not Common_gen_mother_idx_isLoaded) {
/*                   Common_gen_mother_idx*/    if (Common_gen_mother_idx_branch != 0) {
/*                   Common_gen_mother_idx*/      Common_gen_mother_idx_branch->GetEntry(index);
/*                   Common_gen_mother_idx*/    } else {
/*                   Common_gen_mother_idx*/      printf("branch Common_gen_mother_idx_branch does not exist!\n");
/*                   Common_gen_mother_idx*/      exit(1);
/*                   Common_gen_mother_idx*/    }
/*                   Common_gen_mother_idx*/    Common_gen_mother_idx_isLoaded = true;
/*                   Common_gen_mother_idx*/  }
/*                   Common_gen_mother_idx*/  return *Common_gen_mother_idx_;
/*                   Common_gen_mother_idx*/}

//---------------------------------------------------------------------------------
/*                    Common_gen_mother_id*/const vector<int> &VVVTree::Common_gen_mother_id() {
/*                    Common_gen_mother_id*/  if (not Common_gen_mother_id_isLoaded) {
/*                    Common_gen_mother_id*/    if (Common_gen_mother_id_branch != 0) {
/*                    Common_gen_mother_id*/      Common_gen_mother_id_branch->GetEntry(index);
/*                    Common_gen_mother_id*/    } else {
/*                    Common_gen_mother_id*/      printf("branch Common_gen_mother_id_branch does not exist!\n");
/*                    Common_gen_mother_id*/      exit(1);
/*                    Common_gen_mother_id*/    }
/*                    Common_gen_mother_id*/    Common_gen_mother_id_isLoaded = true;
/*                    Common_gen_mother_id*/  }
/*                    Common_gen_mother_id*/  return *Common_gen_mother_id_;
/*                    Common_gen_mother_id*/}

//---------------------------------------------------------------------------------
/*                        Common_gen_pdgid*/const vector<int> &VVVTree::Common_gen_pdgid() {
/*                        Common_gen_pdgid*/  if (not Common_gen_pdgid_isLoaded) {
/*                        Common_gen_pdgid*/    if (Common_gen_pdgid_branch != 0) {
/*                        Common_gen_pdgid*/      Common_gen_pdgid_branch->GetEntry(index);
/*                        Common_gen_pdgid*/    } else {
/*                        Common_gen_pdgid*/      printf("branch Common_gen_pdgid_branch does not exist!\n");
/*                        Common_gen_pdgid*/      exit(1);
/*                        Common_gen_pdgid*/    }
/*                        Common_gen_pdgid*/    Common_gen_pdgid_isLoaded = true;
/*                        Common_gen_pdgid*/  }
/*                        Common_gen_pdgid*/  return *Common_gen_pdgid_;
/*                        Common_gen_pdgid*/}

//---------------------------------------------------------------------------------
/*                          Common_gen_p4s*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_gen_p4s() {
/*                          Common_gen_p4s*/  if (not Common_gen_p4s_isLoaded) {
/*                          Common_gen_p4s*/    if (Common_gen_p4s_branch != 0) {
/*                          Common_gen_p4s*/      Common_gen_p4s_branch->GetEntry(index);
/*                          Common_gen_p4s*/    } else {
/*                          Common_gen_p4s*/      printf("branch Common_gen_p4s_branch does not exist!\n");
/*                          Common_gen_p4s*/      exit(1);
/*                          Common_gen_p4s*/    }
/*                          Common_gen_p4s*/    Common_gen_p4s_isLoaded = true;
/*                          Common_gen_p4s*/  }
/*                          Common_gen_p4s*/  return *Common_gen_p4s_;
/*                          Common_gen_p4s*/}

//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_idx*/const vector<int> &VVVTree::Common_gen_vvvdecay_idx() {
/*                 Common_gen_vvvdecay_idx*/  if (not Common_gen_vvvdecay_idx_isLoaded) {
/*                 Common_gen_vvvdecay_idx*/    if (Common_gen_vvvdecay_idx_branch != 0) {
/*                 Common_gen_vvvdecay_idx*/      Common_gen_vvvdecay_idx_branch->GetEntry(index);
/*                 Common_gen_vvvdecay_idx*/    } else {
/*                 Common_gen_vvvdecay_idx*/      printf("branch Common_gen_vvvdecay_idx_branch does not exist!\n");
/*                 Common_gen_vvvdecay_idx*/      exit(1);
/*                 Common_gen_vvvdecay_idx*/    }
/*                 Common_gen_vvvdecay_idx*/    Common_gen_vvvdecay_idx_isLoaded = true;
/*                 Common_gen_vvvdecay_idx*/  }
/*                 Common_gen_vvvdecay_idx*/  return *Common_gen_vvvdecay_idx_;
/*                 Common_gen_vvvdecay_idx*/}

//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_mother_idx*/const vector<int> &VVVTree::Common_gen_vvvdecay_mother_idx() {
/*          Common_gen_vvvdecay_mother_idx*/  if (not Common_gen_vvvdecay_mother_idx_isLoaded) {
/*          Common_gen_vvvdecay_mother_idx*/    if (Common_gen_vvvdecay_mother_idx_branch != 0) {
/*          Common_gen_vvvdecay_mother_idx*/      Common_gen_vvvdecay_mother_idx_branch->GetEntry(index);
/*          Common_gen_vvvdecay_mother_idx*/    } else {
/*          Common_gen_vvvdecay_mother_idx*/      printf("branch Common_gen_vvvdecay_mother_idx_branch does not exist!\n");
/*          Common_gen_vvvdecay_mother_idx*/      exit(1);
/*          Common_gen_vvvdecay_mother_idx*/    }
/*          Common_gen_vvvdecay_mother_idx*/    Common_gen_vvvdecay_mother_idx_isLoaded = true;
/*          Common_gen_vvvdecay_mother_idx*/  }
/*          Common_gen_vvvdecay_mother_idx*/  return *Common_gen_vvvdecay_mother_idx_;
/*          Common_gen_vvvdecay_mother_idx*/}

//---------------------------------------------------------------------------------
/*           Common_gen_vvvdecay_mother_id*/const vector<int> &VVVTree::Common_gen_vvvdecay_mother_id() {
/*           Common_gen_vvvdecay_mother_id*/  if (not Common_gen_vvvdecay_mother_id_isLoaded) {
/*           Common_gen_vvvdecay_mother_id*/    if (Common_gen_vvvdecay_mother_id_branch != 0) {
/*           Common_gen_vvvdecay_mother_id*/      Common_gen_vvvdecay_mother_id_branch->GetEntry(index);
/*           Common_gen_vvvdecay_mother_id*/    } else {
/*           Common_gen_vvvdecay_mother_id*/      printf("branch Common_gen_vvvdecay_mother_id_branch does not exist!\n");
/*           Common_gen_vvvdecay_mother_id*/      exit(1);
/*           Common_gen_vvvdecay_mother_id*/    }
/*           Common_gen_vvvdecay_mother_id*/    Common_gen_vvvdecay_mother_id_isLoaded = true;
/*           Common_gen_vvvdecay_mother_id*/  }
/*           Common_gen_vvvdecay_mother_id*/  return *Common_gen_vvvdecay_mother_id_;
/*           Common_gen_vvvdecay_mother_id*/}

//---------------------------------------------------------------------------------
/*               Common_gen_vvvdecay_pdgid*/const vector<int> &VVVTree::Common_gen_vvvdecay_pdgid() {
/*               Common_gen_vvvdecay_pdgid*/  if (not Common_gen_vvvdecay_pdgid_isLoaded) {
/*               Common_gen_vvvdecay_pdgid*/    if (Common_gen_vvvdecay_pdgid_branch != 0) {
/*               Common_gen_vvvdecay_pdgid*/      Common_gen_vvvdecay_pdgid_branch->GetEntry(index);
/*               Common_gen_vvvdecay_pdgid*/    } else {
/*               Common_gen_vvvdecay_pdgid*/      printf("branch Common_gen_vvvdecay_pdgid_branch does not exist!\n");
/*               Common_gen_vvvdecay_pdgid*/      exit(1);
/*               Common_gen_vvvdecay_pdgid*/    }
/*               Common_gen_vvvdecay_pdgid*/    Common_gen_vvvdecay_pdgid_isLoaded = true;
/*               Common_gen_vvvdecay_pdgid*/  }
/*               Common_gen_vvvdecay_pdgid*/  return *Common_gen_vvvdecay_pdgid_;
/*               Common_gen_vvvdecay_pdgid*/}

//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_p4s*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_gen_vvvdecay_p4s() {
/*                 Common_gen_vvvdecay_p4s*/  if (not Common_gen_vvvdecay_p4s_isLoaded) {
/*                 Common_gen_vvvdecay_p4s*/    if (Common_gen_vvvdecay_p4s_branch != 0) {
/*                 Common_gen_vvvdecay_p4s*/      Common_gen_vvvdecay_p4s_branch->GetEntry(index);
/*                 Common_gen_vvvdecay_p4s*/    } else {
/*                 Common_gen_vvvdecay_p4s*/      printf("branch Common_gen_vvvdecay_p4s_branch does not exist!\n");
/*                 Common_gen_vvvdecay_p4s*/      exit(1);
/*                 Common_gen_vvvdecay_p4s*/    }
/*                 Common_gen_vvvdecay_p4s*/    Common_gen_vvvdecay_p4s_isLoaded = true;
/*                 Common_gen_vvvdecay_p4s*/  }
/*                 Common_gen_vvvdecay_p4s*/  return *Common_gen_vvvdecay_p4s_;
/*                 Common_gen_vvvdecay_p4s*/}

//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_taudecayid*/const vector<int> &VVVTree::Common_gen_vvvdecay_taudecayid() {
/*          Common_gen_vvvdecay_taudecayid*/  if (not Common_gen_vvvdecay_taudecayid_isLoaded) {
/*          Common_gen_vvvdecay_taudecayid*/    if (Common_gen_vvvdecay_taudecayid_branch != 0) {
/*          Common_gen_vvvdecay_taudecayid*/      Common_gen_vvvdecay_taudecayid_branch->GetEntry(index);
/*          Common_gen_vvvdecay_taudecayid*/    } else {
/*          Common_gen_vvvdecay_taudecayid*/      printf("branch Common_gen_vvvdecay_taudecayid_branch does not exist!\n");
/*          Common_gen_vvvdecay_taudecayid*/      exit(1);
/*          Common_gen_vvvdecay_taudecayid*/    }
/*          Common_gen_vvvdecay_taudecayid*/    Common_gen_vvvdecay_taudecayid_isLoaded = true;
/*          Common_gen_vvvdecay_taudecayid*/  }
/*          Common_gen_vvvdecay_taudecayid*/  return *Common_gen_vvvdecay_taudecayid_;
/*          Common_gen_vvvdecay_taudecayid*/}

//---------------------------------------------------------------------------------
/*                         Common_isSignal*/const bool &VVVTree::Common_isSignal() {
/*                         Common_isSignal*/  if (not Common_isSignal_isLoaded) {
/*                         Common_isSignal*/    if (Common_isSignal_branch != 0) {
/*                         Common_isSignal*/      Common_isSignal_branch->GetEntry(index);
/*                         Common_isSignal*/    } else {
/*                         Common_isSignal*/      printf("branch Common_isSignal_branch does not exist!\n");
/*                         Common_isSignal*/      exit(1);
/*                         Common_isSignal*/    }
/*                         Common_isSignal*/    Common_isSignal_isLoaded = true;
/*                         Common_isSignal*/  }
/*                         Common_isSignal*/  return Common_isSignal_;
/*                         Common_isSignal*/}

//---------------------------------------------------------------------------------
/*                              Common_n_W*/const int &VVVTree::Common_n_W() {
/*                              Common_n_W*/  if (not Common_n_W_isLoaded) {
/*                              Common_n_W*/    if (Common_n_W_branch != 0) {
/*                              Common_n_W*/      Common_n_W_branch->GetEntry(index);
/*                              Common_n_W*/    } else {
/*                              Common_n_W*/      printf("branch Common_n_W_branch does not exist!\n");
/*                              Common_n_W*/      exit(1);
/*                              Common_n_W*/    }
/*                              Common_n_W*/    Common_n_W_isLoaded = true;
/*                              Common_n_W*/  }
/*                              Common_n_W*/  return Common_n_W_;
/*                              Common_n_W*/}

//---------------------------------------------------------------------------------
/*                              Common_n_Z*/const int &VVVTree::Common_n_Z() {
/*                              Common_n_Z*/  if (not Common_n_Z_isLoaded) {
/*                              Common_n_Z*/    if (Common_n_Z_branch != 0) {
/*                              Common_n_Z*/      Common_n_Z_branch->GetEntry(index);
/*                              Common_n_Z*/    } else {
/*                              Common_n_Z*/      printf("branch Common_n_Z_branch does not exist!\n");
/*                              Common_n_Z*/      exit(1);
/*                              Common_n_Z*/    }
/*                              Common_n_Z*/    Common_n_Z_isLoaded = true;
/*                              Common_n_Z*/  }
/*                              Common_n_Z*/  return Common_n_Z_;
/*                              Common_n_Z*/}

//---------------------------------------------------------------------------------
/*                          Common_n_lep_Z*/const int &VVVTree::Common_n_lep_Z() {
/*                          Common_n_lep_Z*/  if (not Common_n_lep_Z_isLoaded) {
/*                          Common_n_lep_Z*/    if (Common_n_lep_Z_branch != 0) {
/*                          Common_n_lep_Z*/      Common_n_lep_Z_branch->GetEntry(index);
/*                          Common_n_lep_Z*/    } else {
/*                          Common_n_lep_Z*/      printf("branch Common_n_lep_Z_branch does not exist!\n");
/*                          Common_n_lep_Z*/      exit(1);
/*                          Common_n_lep_Z*/    }
/*                          Common_n_lep_Z*/    Common_n_lep_Z_isLoaded = true;
/*                          Common_n_lep_Z*/  }
/*                          Common_n_lep_Z*/  return Common_n_lep_Z_;
/*                          Common_n_lep_Z*/}

//---------------------------------------------------------------------------------
/*                       Common_n_leptau_Z*/const int &VVVTree::Common_n_leptau_Z() {
/*                       Common_n_leptau_Z*/  if (not Common_n_leptau_Z_isLoaded) {
/*                       Common_n_leptau_Z*/    if (Common_n_leptau_Z_branch != 0) {
/*                       Common_n_leptau_Z*/      Common_n_leptau_Z_branch->GetEntry(index);
/*                       Common_n_leptau_Z*/    } else {
/*                       Common_n_leptau_Z*/      printf("branch Common_n_leptau_Z_branch does not exist!\n");
/*                       Common_n_leptau_Z*/      exit(1);
/*                       Common_n_leptau_Z*/    }
/*                       Common_n_leptau_Z*/    Common_n_leptau_Z_isLoaded = true;
/*                       Common_n_leptau_Z*/  }
/*                       Common_n_leptau_Z*/  return Common_n_leptau_Z_;
/*                       Common_n_leptau_Z*/}

//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_Z*/const int &VVVTree::Common_n_hadtau_Z() {
/*                       Common_n_hadtau_Z*/  if (not Common_n_hadtau_Z_isLoaded) {
/*                       Common_n_hadtau_Z*/    if (Common_n_hadtau_Z_branch != 0) {
/*                       Common_n_hadtau_Z*/      Common_n_hadtau_Z_branch->GetEntry(index);
/*                       Common_n_hadtau_Z*/    } else {
/*                       Common_n_hadtau_Z*/      printf("branch Common_n_hadtau_Z_branch does not exist!\n");
/*                       Common_n_hadtau_Z*/      exit(1);
/*                       Common_n_hadtau_Z*/    }
/*                       Common_n_hadtau_Z*/    Common_n_hadtau_Z_isLoaded = true;
/*                       Common_n_hadtau_Z*/  }
/*                       Common_n_hadtau_Z*/  return Common_n_hadtau_Z_;
/*                       Common_n_hadtau_Z*/}

//---------------------------------------------------------------------------------
/*                           Common_n_nu_Z*/const int &VVVTree::Common_n_nu_Z() {
/*                           Common_n_nu_Z*/  if (not Common_n_nu_Z_isLoaded) {
/*                           Common_n_nu_Z*/    if (Common_n_nu_Z_branch != 0) {
/*                           Common_n_nu_Z*/      Common_n_nu_Z_branch->GetEntry(index);
/*                           Common_n_nu_Z*/    } else {
/*                           Common_n_nu_Z*/      printf("branch Common_n_nu_Z_branch does not exist!\n");
/*                           Common_n_nu_Z*/      exit(1);
/*                           Common_n_nu_Z*/    }
/*                           Common_n_nu_Z*/    Common_n_nu_Z_isLoaded = true;
/*                           Common_n_nu_Z*/  }
/*                           Common_n_nu_Z*/  return Common_n_nu_Z_;
/*                           Common_n_nu_Z*/}

//---------------------------------------------------------------------------------
/*                            Common_n_b_Z*/const int &VVVTree::Common_n_b_Z() {
/*                            Common_n_b_Z*/  if (not Common_n_b_Z_isLoaded) {
/*                            Common_n_b_Z*/    if (Common_n_b_Z_branch != 0) {
/*                            Common_n_b_Z*/      Common_n_b_Z_branch->GetEntry(index);
/*                            Common_n_b_Z*/    } else {
/*                            Common_n_b_Z*/      printf("branch Common_n_b_Z_branch does not exist!\n");
/*                            Common_n_b_Z*/      exit(1);
/*                            Common_n_b_Z*/    }
/*                            Common_n_b_Z*/    Common_n_b_Z_isLoaded = true;
/*                            Common_n_b_Z*/  }
/*                            Common_n_b_Z*/  return Common_n_b_Z_;
/*                            Common_n_b_Z*/}

//---------------------------------------------------------------------------------
/*                          Common_n_lep_W*/const int &VVVTree::Common_n_lep_W() {
/*                          Common_n_lep_W*/  if (not Common_n_lep_W_isLoaded) {
/*                          Common_n_lep_W*/    if (Common_n_lep_W_branch != 0) {
/*                          Common_n_lep_W*/      Common_n_lep_W_branch->GetEntry(index);
/*                          Common_n_lep_W*/    } else {
/*                          Common_n_lep_W*/      printf("branch Common_n_lep_W_branch does not exist!\n");
/*                          Common_n_lep_W*/      exit(1);
/*                          Common_n_lep_W*/    }
/*                          Common_n_lep_W*/    Common_n_lep_W_isLoaded = true;
/*                          Common_n_lep_W*/  }
/*                          Common_n_lep_W*/  return Common_n_lep_W_;
/*                          Common_n_lep_W*/}

//---------------------------------------------------------------------------------
/*                       Common_n_leptau_W*/const int &VVVTree::Common_n_leptau_W() {
/*                       Common_n_leptau_W*/  if (not Common_n_leptau_W_isLoaded) {
/*                       Common_n_leptau_W*/    if (Common_n_leptau_W_branch != 0) {
/*                       Common_n_leptau_W*/      Common_n_leptau_W_branch->GetEntry(index);
/*                       Common_n_leptau_W*/    } else {
/*                       Common_n_leptau_W*/      printf("branch Common_n_leptau_W_branch does not exist!\n");
/*                       Common_n_leptau_W*/      exit(1);
/*                       Common_n_leptau_W*/    }
/*                       Common_n_leptau_W*/    Common_n_leptau_W_isLoaded = true;
/*                       Common_n_leptau_W*/  }
/*                       Common_n_leptau_W*/  return Common_n_leptau_W_;
/*                       Common_n_leptau_W*/}

//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_W*/const int &VVVTree::Common_n_hadtau_W() {
/*                       Common_n_hadtau_W*/  if (not Common_n_hadtau_W_isLoaded) {
/*                       Common_n_hadtau_W*/    if (Common_n_hadtau_W_branch != 0) {
/*                       Common_n_hadtau_W*/      Common_n_hadtau_W_branch->GetEntry(index);
/*                       Common_n_hadtau_W*/    } else {
/*                       Common_n_hadtau_W*/      printf("branch Common_n_hadtau_W_branch does not exist!\n");
/*                       Common_n_hadtau_W*/      exit(1);
/*                       Common_n_hadtau_W*/    }
/*                       Common_n_hadtau_W*/    Common_n_hadtau_W_isLoaded = true;
/*                       Common_n_hadtau_W*/  }
/*                       Common_n_hadtau_W*/  return Common_n_hadtau_W_;
/*                       Common_n_hadtau_W*/}

//---------------------------------------------------------------------------------
/*                        Common_haslepWSS*/const bool &VVVTree::Common_haslepWSS() {
/*                        Common_haslepWSS*/  if (not Common_haslepWSS_isLoaded) {
/*                        Common_haslepWSS*/    if (Common_haslepWSS_branch != 0) {
/*                        Common_haslepWSS*/      Common_haslepWSS_branch->GetEntry(index);
/*                        Common_haslepWSS*/    } else {
/*                        Common_haslepWSS*/      printf("branch Common_haslepWSS_branch does not exist!\n");
/*                        Common_haslepWSS*/      exit(1);
/*                        Common_haslepWSS*/    }
/*                        Common_haslepWSS*/    Common_haslepWSS_isLoaded = true;
/*                        Common_haslepWSS*/  }
/*                        Common_haslepWSS*/  return Common_haslepWSS_;
/*                        Common_haslepWSS*/}

//---------------------------------------------------------------------------------
/*                            Common_genHT*/const float &VVVTree::Common_genHT() {
/*                            Common_genHT*/  if (not Common_genHT_isLoaded) {
/*                            Common_genHT*/    if (Common_genHT_branch != 0) {
/*                            Common_genHT*/      Common_genHT_branch->GetEntry(index);
/*                            Common_genHT*/    } else {
/*                            Common_genHT*/      printf("branch Common_genHT_branch does not exist!\n");
/*                            Common_genHT*/      exit(1);
/*                            Common_genHT*/    }
/*                            Common_genHT*/    Common_genHT_isLoaded = true;
/*                            Common_genHT*/  }
/*                            Common_genHT*/  return Common_genHT_;
/*                            Common_genHT*/}

//---------------------------------------------------------------------------------
/*                  Common_gen_n_light_lep*/const int &VVVTree::Common_gen_n_light_lep() {
/*                  Common_gen_n_light_lep*/  if (not Common_gen_n_light_lep_isLoaded) {
/*                  Common_gen_n_light_lep*/    if (Common_gen_n_light_lep_branch != 0) {
/*                  Common_gen_n_light_lep*/      Common_gen_n_light_lep_branch->GetEntry(index);
/*                  Common_gen_n_light_lep*/    } else {
/*                  Common_gen_n_light_lep*/      printf("branch Common_gen_n_light_lep_branch does not exist!\n");
/*                  Common_gen_n_light_lep*/      exit(1);
/*                  Common_gen_n_light_lep*/    }
/*                  Common_gen_n_light_lep*/    Common_gen_n_light_lep_isLoaded = true;
/*                  Common_gen_n_light_lep*/  }
/*                  Common_gen_n_light_lep*/  return Common_gen_n_light_lep_;
/*                  Common_gen_n_light_lep*/}

//---------------------------------------------------------------------------------
/*                   Common_gen_VH_channel*/const int &VVVTree::Common_gen_VH_channel() {
/*                   Common_gen_VH_channel*/  if (not Common_gen_VH_channel_isLoaded) {
/*                   Common_gen_VH_channel*/    if (Common_gen_VH_channel_branch != 0) {
/*                   Common_gen_VH_channel*/      Common_gen_VH_channel_branch->GetEntry(index);
/*                   Common_gen_VH_channel*/    } else {
/*                   Common_gen_VH_channel*/      printf("branch Common_gen_VH_channel_branch does not exist!\n");
/*                   Common_gen_VH_channel*/      exit(1);
/*                   Common_gen_VH_channel*/    }
/*                   Common_gen_VH_channel*/    Common_gen_VH_channel_isLoaded = true;
/*                   Common_gen_VH_channel*/  }
/*                   Common_gen_VH_channel*/  return Common_gen_VH_channel_;
/*                   Common_gen_VH_channel*/}

//---------------------------------------------------------------------------------
/*                Cut_4LepMET_Preselection*/const bool &VVVTree::Cut_4LepMET_Preselection() {
/*                Cut_4LepMET_Preselection*/  if (not Cut_4LepMET_Preselection_isLoaded) {
/*                Cut_4LepMET_Preselection*/    if (Cut_4LepMET_Preselection_branch != 0) {
/*                Cut_4LepMET_Preselection*/      Cut_4LepMET_Preselection_branch->GetEntry(index);
/*                Cut_4LepMET_Preselection*/    } else {
/*                Cut_4LepMET_Preselection*/      printf("branch Cut_4LepMET_Preselection_branch does not exist!\n");
/*                Cut_4LepMET_Preselection*/      exit(1);
/*                Cut_4LepMET_Preselection*/    }
/*                Cut_4LepMET_Preselection*/    Cut_4LepMET_Preselection_isLoaded = true;
/*                Cut_4LepMET_Preselection*/  }
/*                Cut_4LepMET_Preselection*/  return Cut_4LepMET_Preselection_;
/*                Cut_4LepMET_Preselection*/}

//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/const bool &VVVTree::Cut_4LepMET_emuChannel() {
/*                  Cut_4LepMET_emuChannel*/  if (not Cut_4LepMET_emuChannel_isLoaded) {
/*                  Cut_4LepMET_emuChannel*/    if (Cut_4LepMET_emuChannel_branch != 0) {
/*                  Cut_4LepMET_emuChannel*/      Cut_4LepMET_emuChannel_branch->GetEntry(index);
/*                  Cut_4LepMET_emuChannel*/    } else {
/*                  Cut_4LepMET_emuChannel*/      printf("branch Cut_4LepMET_emuChannel_branch does not exist!\n");
/*                  Cut_4LepMET_emuChannel*/      exit(1);
/*                  Cut_4LepMET_emuChannel*/    }
/*                  Cut_4LepMET_emuChannel*/    Cut_4LepMET_emuChannel_isLoaded = true;
/*                  Cut_4LepMET_emuChannel*/  }
/*                  Cut_4LepMET_emuChannel*/  return Cut_4LepMET_emuChannel_;
/*                  Cut_4LepMET_emuChannel*/}

//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/const bool &VVVTree::Cut_4LepMET_offzChannel() {
/*                 Cut_4LepMET_offzChannel*/  if (not Cut_4LepMET_offzChannel_isLoaded) {
/*                 Cut_4LepMET_offzChannel*/    if (Cut_4LepMET_offzChannel_branch != 0) {
/*                 Cut_4LepMET_offzChannel*/      Cut_4LepMET_offzChannel_branch->GetEntry(index);
/*                 Cut_4LepMET_offzChannel*/    } else {
/*                 Cut_4LepMET_offzChannel*/      printf("branch Cut_4LepMET_offzChannel_branch does not exist!\n");
/*                 Cut_4LepMET_offzChannel*/      exit(1);
/*                 Cut_4LepMET_offzChannel*/    }
/*                 Cut_4LepMET_offzChannel*/    Cut_4LepMET_offzChannel_isLoaded = true;
/*                 Cut_4LepMET_offzChannel*/  }
/*                 Cut_4LepMET_offzChannel*/  return Cut_4LepMET_offzChannel_;
/*                 Cut_4LepMET_offzChannel*/}

//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/const bool &VVVTree::Cut_4LepMET_onzChannel() {
/*                  Cut_4LepMET_onzChannel*/  if (not Cut_4LepMET_onzChannel_isLoaded) {
/*                  Cut_4LepMET_onzChannel*/    if (Cut_4LepMET_onzChannel_branch != 0) {
/*                  Cut_4LepMET_onzChannel*/      Cut_4LepMET_onzChannel_branch->GetEntry(index);
/*                  Cut_4LepMET_onzChannel*/    } else {
/*                  Cut_4LepMET_onzChannel*/      printf("branch Cut_4LepMET_onzChannel_branch does not exist!\n");
/*                  Cut_4LepMET_onzChannel*/      exit(1);
/*                  Cut_4LepMET_onzChannel*/    }
/*                  Cut_4LepMET_onzChannel*/    Cut_4LepMET_onzChannel_isLoaded = true;
/*                  Cut_4LepMET_onzChannel*/  }
/*                  Cut_4LepMET_onzChannel*/  return Cut_4LepMET_onzChannel_;
/*                  Cut_4LepMET_onzChannel*/}

//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/const bool &VVVTree::Cut_4LepMET_onzChannel_HighMET() {
/*          Cut_4LepMET_onzChannel_HighMET*/  if (not Cut_4LepMET_onzChannel_HighMET_isLoaded) {
/*          Cut_4LepMET_onzChannel_HighMET*/    if (Cut_4LepMET_onzChannel_HighMET_branch != 0) {
/*          Cut_4LepMET_onzChannel_HighMET*/      Cut_4LepMET_onzChannel_HighMET_branch->GetEntry(index);
/*          Cut_4LepMET_onzChannel_HighMET*/    } else {
/*          Cut_4LepMET_onzChannel_HighMET*/      printf("branch Cut_4LepMET_onzChannel_HighMET_branch does not exist!\n");
/*          Cut_4LepMET_onzChannel_HighMET*/      exit(1);
/*          Cut_4LepMET_onzChannel_HighMET*/    }
/*          Cut_4LepMET_onzChannel_HighMET*/    Cut_4LepMET_onzChannel_HighMET_isLoaded = true;
/*          Cut_4LepMET_onzChannel_HighMET*/  }
/*          Cut_4LepMET_onzChannel_HighMET*/  return Cut_4LepMET_onzChannel_HighMET_;
/*          Cut_4LepMET_onzChannel_HighMET*/}

//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/const int &VVVTree::Var_4LepMET_Zcand_lep_idx_0() {
/*             Var_4LepMET_Zcand_lep_idx_0*/  if (not Var_4LepMET_Zcand_lep_idx_0_isLoaded) {
/*             Var_4LepMET_Zcand_lep_idx_0*/    if (Var_4LepMET_Zcand_lep_idx_0_branch != 0) {
/*             Var_4LepMET_Zcand_lep_idx_0*/      Var_4LepMET_Zcand_lep_idx_0_branch->GetEntry(index);
/*             Var_4LepMET_Zcand_lep_idx_0*/    } else {
/*             Var_4LepMET_Zcand_lep_idx_0*/      printf("branch Var_4LepMET_Zcand_lep_idx_0_branch does not exist!\n");
/*             Var_4LepMET_Zcand_lep_idx_0*/      exit(1);
/*             Var_4LepMET_Zcand_lep_idx_0*/    }
/*             Var_4LepMET_Zcand_lep_idx_0*/    Var_4LepMET_Zcand_lep_idx_0_isLoaded = true;
/*             Var_4LepMET_Zcand_lep_idx_0*/  }
/*             Var_4LepMET_Zcand_lep_idx_0*/  return Var_4LepMET_Zcand_lep_idx_0_;
/*             Var_4LepMET_Zcand_lep_idx_0*/}

//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/const int &VVVTree::Var_4LepMET_Zcand_lep_pdgid_0() {
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  if (not Var_4LepMET_Zcand_lep_pdgid_0_isLoaded) {
/*           Var_4LepMET_Zcand_lep_pdgid_0*/    if (Var_4LepMET_Zcand_lep_pdgid_0_branch != 0) {
/*           Var_4LepMET_Zcand_lep_pdgid_0*/      Var_4LepMET_Zcand_lep_pdgid_0_branch->GetEntry(index);
/*           Var_4LepMET_Zcand_lep_pdgid_0*/    } else {
/*           Var_4LepMET_Zcand_lep_pdgid_0*/      printf("branch Var_4LepMET_Zcand_lep_pdgid_0_branch does not exist!\n");
/*           Var_4LepMET_Zcand_lep_pdgid_0*/      exit(1);
/*           Var_4LepMET_Zcand_lep_pdgid_0*/    }
/*           Var_4LepMET_Zcand_lep_pdgid_0*/    Var_4LepMET_Zcand_lep_pdgid_0_isLoaded = true;
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  }
/*           Var_4LepMET_Zcand_lep_pdgid_0*/  return Var_4LepMET_Zcand_lep_pdgid_0_;
/*           Var_4LepMET_Zcand_lep_pdgid_0*/}

//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_0*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Var_4LepMET_Zcand_lep_p4_0() {
/*              Var_4LepMET_Zcand_lep_p4_0*/  if (not Var_4LepMET_Zcand_lep_p4_0_isLoaded) {
/*              Var_4LepMET_Zcand_lep_p4_0*/    if (Var_4LepMET_Zcand_lep_p4_0_branch != 0) {
/*              Var_4LepMET_Zcand_lep_p4_0*/      Var_4LepMET_Zcand_lep_p4_0_branch->GetEntry(index);
/*              Var_4LepMET_Zcand_lep_p4_0*/    } else {
/*              Var_4LepMET_Zcand_lep_p4_0*/      printf("branch Var_4LepMET_Zcand_lep_p4_0_branch does not exist!\n");
/*              Var_4LepMET_Zcand_lep_p4_0*/      exit(1);
/*              Var_4LepMET_Zcand_lep_p4_0*/    }
/*              Var_4LepMET_Zcand_lep_p4_0*/    Var_4LepMET_Zcand_lep_p4_0_isLoaded = true;
/*              Var_4LepMET_Zcand_lep_p4_0*/  }
/*              Var_4LepMET_Zcand_lep_p4_0*/  return *Var_4LepMET_Zcand_lep_p4_0_;
/*              Var_4LepMET_Zcand_lep_p4_0*/}

//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_1*/const int &VVVTree::Var_4LepMET_Zcand_lep_idx_1() {
/*             Var_4LepMET_Zcand_lep_idx_1*/  if (not Var_4LepMET_Zcand_lep_idx_1_isLoaded) {
/*             Var_4LepMET_Zcand_lep_idx_1*/    if (Var_4LepMET_Zcand_lep_idx_1_branch != 0) {
/*             Var_4LepMET_Zcand_lep_idx_1*/      Var_4LepMET_Zcand_lep_idx_1_branch->GetEntry(index);
/*             Var_4LepMET_Zcand_lep_idx_1*/    } else {
/*             Var_4LepMET_Zcand_lep_idx_1*/      printf("branch Var_4LepMET_Zcand_lep_idx_1_branch does not exist!\n");
/*             Var_4LepMET_Zcand_lep_idx_1*/      exit(1);
/*             Var_4LepMET_Zcand_lep_idx_1*/    }
/*             Var_4LepMET_Zcand_lep_idx_1*/    Var_4LepMET_Zcand_lep_idx_1_isLoaded = true;
/*             Var_4LepMET_Zcand_lep_idx_1*/  }
/*             Var_4LepMET_Zcand_lep_idx_1*/  return Var_4LepMET_Zcand_lep_idx_1_;
/*             Var_4LepMET_Zcand_lep_idx_1*/}

//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_1*/const int &VVVTree::Var_4LepMET_Zcand_lep_pdgid_1() {
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  if (not Var_4LepMET_Zcand_lep_pdgid_1_isLoaded) {
/*           Var_4LepMET_Zcand_lep_pdgid_1*/    if (Var_4LepMET_Zcand_lep_pdgid_1_branch != 0) {
/*           Var_4LepMET_Zcand_lep_pdgid_1*/      Var_4LepMET_Zcand_lep_pdgid_1_branch->GetEntry(index);
/*           Var_4LepMET_Zcand_lep_pdgid_1*/    } else {
/*           Var_4LepMET_Zcand_lep_pdgid_1*/      printf("branch Var_4LepMET_Zcand_lep_pdgid_1_branch does not exist!\n");
/*           Var_4LepMET_Zcand_lep_pdgid_1*/      exit(1);
/*           Var_4LepMET_Zcand_lep_pdgid_1*/    }
/*           Var_4LepMET_Zcand_lep_pdgid_1*/    Var_4LepMET_Zcand_lep_pdgid_1_isLoaded = true;
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  }
/*           Var_4LepMET_Zcand_lep_pdgid_1*/  return Var_4LepMET_Zcand_lep_pdgid_1_;
/*           Var_4LepMET_Zcand_lep_pdgid_1*/}

//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_1*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Var_4LepMET_Zcand_lep_p4_1() {
/*              Var_4LepMET_Zcand_lep_p4_1*/  if (not Var_4LepMET_Zcand_lep_p4_1_isLoaded) {
/*              Var_4LepMET_Zcand_lep_p4_1*/    if (Var_4LepMET_Zcand_lep_p4_1_branch != 0) {
/*              Var_4LepMET_Zcand_lep_p4_1*/      Var_4LepMET_Zcand_lep_p4_1_branch->GetEntry(index);
/*              Var_4LepMET_Zcand_lep_p4_1*/    } else {
/*              Var_4LepMET_Zcand_lep_p4_1*/      printf("branch Var_4LepMET_Zcand_lep_p4_1_branch does not exist!\n");
/*              Var_4LepMET_Zcand_lep_p4_1*/      exit(1);
/*              Var_4LepMET_Zcand_lep_p4_1*/    }
/*              Var_4LepMET_Zcand_lep_p4_1*/    Var_4LepMET_Zcand_lep_p4_1_isLoaded = true;
/*              Var_4LepMET_Zcand_lep_p4_1*/  }
/*              Var_4LepMET_Zcand_lep_p4_1*/  return *Var_4LepMET_Zcand_lep_p4_1_;
/*              Var_4LepMET_Zcand_lep_p4_1*/}

//---------------------------------------------------------------------------------
/*                   Var_4LepMET_Zcand_mll*/const float &VVVTree::Var_4LepMET_Zcand_mll() {
/*                   Var_4LepMET_Zcand_mll*/  if (not Var_4LepMET_Zcand_mll_isLoaded) {
/*                   Var_4LepMET_Zcand_mll*/    if (Var_4LepMET_Zcand_mll_branch != 0) {
/*                   Var_4LepMET_Zcand_mll*/      Var_4LepMET_Zcand_mll_branch->GetEntry(index);
/*                   Var_4LepMET_Zcand_mll*/    } else {
/*                   Var_4LepMET_Zcand_mll*/      printf("branch Var_4LepMET_Zcand_mll_branch does not exist!\n");
/*                   Var_4LepMET_Zcand_mll*/      exit(1);
/*                   Var_4LepMET_Zcand_mll*/    }
/*                   Var_4LepMET_Zcand_mll*/    Var_4LepMET_Zcand_mll_isLoaded = true;
/*                   Var_4LepMET_Zcand_mll*/  }
/*                   Var_4LepMET_Zcand_mll*/  return Var_4LepMET_Zcand_mll_;
/*                   Var_4LepMET_Zcand_mll*/}

//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_0*/const int &VVVTree::Var_4LepMET_other_lep_idx_0() {
/*             Var_4LepMET_other_lep_idx_0*/  if (not Var_4LepMET_other_lep_idx_0_isLoaded) {
/*             Var_4LepMET_other_lep_idx_0*/    if (Var_4LepMET_other_lep_idx_0_branch != 0) {
/*             Var_4LepMET_other_lep_idx_0*/      Var_4LepMET_other_lep_idx_0_branch->GetEntry(index);
/*             Var_4LepMET_other_lep_idx_0*/    } else {
/*             Var_4LepMET_other_lep_idx_0*/      printf("branch Var_4LepMET_other_lep_idx_0_branch does not exist!\n");
/*             Var_4LepMET_other_lep_idx_0*/      exit(1);
/*             Var_4LepMET_other_lep_idx_0*/    }
/*             Var_4LepMET_other_lep_idx_0*/    Var_4LepMET_other_lep_idx_0_isLoaded = true;
/*             Var_4LepMET_other_lep_idx_0*/  }
/*             Var_4LepMET_other_lep_idx_0*/  return Var_4LepMET_other_lep_idx_0_;
/*             Var_4LepMET_other_lep_idx_0*/}

//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_0*/const int &VVVTree::Var_4LepMET_other_lep_pdgid_0() {
/*           Var_4LepMET_other_lep_pdgid_0*/  if (not Var_4LepMET_other_lep_pdgid_0_isLoaded) {
/*           Var_4LepMET_other_lep_pdgid_0*/    if (Var_4LepMET_other_lep_pdgid_0_branch != 0) {
/*           Var_4LepMET_other_lep_pdgid_0*/      Var_4LepMET_other_lep_pdgid_0_branch->GetEntry(index);
/*           Var_4LepMET_other_lep_pdgid_0*/    } else {
/*           Var_4LepMET_other_lep_pdgid_0*/      printf("branch Var_4LepMET_other_lep_pdgid_0_branch does not exist!\n");
/*           Var_4LepMET_other_lep_pdgid_0*/      exit(1);
/*           Var_4LepMET_other_lep_pdgid_0*/    }
/*           Var_4LepMET_other_lep_pdgid_0*/    Var_4LepMET_other_lep_pdgid_0_isLoaded = true;
/*           Var_4LepMET_other_lep_pdgid_0*/  }
/*           Var_4LepMET_other_lep_pdgid_0*/  return Var_4LepMET_other_lep_pdgid_0_;
/*           Var_4LepMET_other_lep_pdgid_0*/}

//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_0*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Var_4LepMET_other_lep_p4_0() {
/*              Var_4LepMET_other_lep_p4_0*/  if (not Var_4LepMET_other_lep_p4_0_isLoaded) {
/*              Var_4LepMET_other_lep_p4_0*/    if (Var_4LepMET_other_lep_p4_0_branch != 0) {
/*              Var_4LepMET_other_lep_p4_0*/      Var_4LepMET_other_lep_p4_0_branch->GetEntry(index);
/*              Var_4LepMET_other_lep_p4_0*/    } else {
/*              Var_4LepMET_other_lep_p4_0*/      printf("branch Var_4LepMET_other_lep_p4_0_branch does not exist!\n");
/*              Var_4LepMET_other_lep_p4_0*/      exit(1);
/*              Var_4LepMET_other_lep_p4_0*/    }
/*              Var_4LepMET_other_lep_p4_0*/    Var_4LepMET_other_lep_p4_0_isLoaded = true;
/*              Var_4LepMET_other_lep_p4_0*/  }
/*              Var_4LepMET_other_lep_p4_0*/  return *Var_4LepMET_other_lep_p4_0_;
/*              Var_4LepMET_other_lep_p4_0*/}

//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_1*/const int &VVVTree::Var_4LepMET_other_lep_idx_1() {
/*             Var_4LepMET_other_lep_idx_1*/  if (not Var_4LepMET_other_lep_idx_1_isLoaded) {
/*             Var_4LepMET_other_lep_idx_1*/    if (Var_4LepMET_other_lep_idx_1_branch != 0) {
/*             Var_4LepMET_other_lep_idx_1*/      Var_4LepMET_other_lep_idx_1_branch->GetEntry(index);
/*             Var_4LepMET_other_lep_idx_1*/    } else {
/*             Var_4LepMET_other_lep_idx_1*/      printf("branch Var_4LepMET_other_lep_idx_1_branch does not exist!\n");
/*             Var_4LepMET_other_lep_idx_1*/      exit(1);
/*             Var_4LepMET_other_lep_idx_1*/    }
/*             Var_4LepMET_other_lep_idx_1*/    Var_4LepMET_other_lep_idx_1_isLoaded = true;
/*             Var_4LepMET_other_lep_idx_1*/  }
/*             Var_4LepMET_other_lep_idx_1*/  return Var_4LepMET_other_lep_idx_1_;
/*             Var_4LepMET_other_lep_idx_1*/}

//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_1*/const int &VVVTree::Var_4LepMET_other_lep_pdgid_1() {
/*           Var_4LepMET_other_lep_pdgid_1*/  if (not Var_4LepMET_other_lep_pdgid_1_isLoaded) {
/*           Var_4LepMET_other_lep_pdgid_1*/    if (Var_4LepMET_other_lep_pdgid_1_branch != 0) {
/*           Var_4LepMET_other_lep_pdgid_1*/      Var_4LepMET_other_lep_pdgid_1_branch->GetEntry(index);
/*           Var_4LepMET_other_lep_pdgid_1*/    } else {
/*           Var_4LepMET_other_lep_pdgid_1*/      printf("branch Var_4LepMET_other_lep_pdgid_1_branch does not exist!\n");
/*           Var_4LepMET_other_lep_pdgid_1*/      exit(1);
/*           Var_4LepMET_other_lep_pdgid_1*/    }
/*           Var_4LepMET_other_lep_pdgid_1*/    Var_4LepMET_other_lep_pdgid_1_isLoaded = true;
/*           Var_4LepMET_other_lep_pdgid_1*/  }
/*           Var_4LepMET_other_lep_pdgid_1*/  return Var_4LepMET_other_lep_pdgid_1_;
/*           Var_4LepMET_other_lep_pdgid_1*/}

//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_1*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Var_4LepMET_other_lep_p4_1() {
/*              Var_4LepMET_other_lep_p4_1*/  if (not Var_4LepMET_other_lep_p4_1_isLoaded) {
/*              Var_4LepMET_other_lep_p4_1*/    if (Var_4LepMET_other_lep_p4_1_branch != 0) {
/*              Var_4LepMET_other_lep_p4_1*/      Var_4LepMET_other_lep_p4_1_branch->GetEntry(index);
/*              Var_4LepMET_other_lep_p4_1*/    } else {
/*              Var_4LepMET_other_lep_p4_1*/      printf("branch Var_4LepMET_other_lep_p4_1_branch does not exist!\n");
/*              Var_4LepMET_other_lep_p4_1*/      exit(1);
/*              Var_4LepMET_other_lep_p4_1*/    }
/*              Var_4LepMET_other_lep_p4_1*/    Var_4LepMET_other_lep_p4_1_isLoaded = true;
/*              Var_4LepMET_other_lep_p4_1*/  }
/*              Var_4LepMET_other_lep_p4_1*/  return *Var_4LepMET_other_lep_p4_1_;
/*              Var_4LepMET_other_lep_p4_1*/}

//---------------------------------------------------------------------------------
/*                   Var_4LepMET_other_mll*/const float &VVVTree::Var_4LepMET_other_mll() {
/*                   Var_4LepMET_other_mll*/  if (not Var_4LepMET_other_mll_isLoaded) {
/*                   Var_4LepMET_other_mll*/    if (Var_4LepMET_other_mll_branch != 0) {
/*                   Var_4LepMET_other_mll*/      Var_4LepMET_other_mll_branch->GetEntry(index);
/*                   Var_4LepMET_other_mll*/    } else {
/*                   Var_4LepMET_other_mll*/      printf("branch Var_4LepMET_other_mll_branch does not exist!\n");
/*                   Var_4LepMET_other_mll*/      exit(1);
/*                   Var_4LepMET_other_mll*/    }
/*                   Var_4LepMET_other_mll*/    Var_4LepMET_other_mll_isLoaded = true;
/*                   Var_4LepMET_other_mll*/  }
/*                   Var_4LepMET_other_mll*/  return Var_4LepMET_other_mll_;
/*                   Var_4LepMET_other_mll*/}

//---------------------------------------------------------------------------------
/*                         Var_4LepMET_mt2*/const float &VVVTree::Var_4LepMET_mt2() {
/*                         Var_4LepMET_mt2*/  if (not Var_4LepMET_mt2_isLoaded) {
/*                         Var_4LepMET_mt2*/    if (Var_4LepMET_mt2_branch != 0) {
/*                         Var_4LepMET_mt2*/      Var_4LepMET_mt2_branch->GetEntry(index);
/*                         Var_4LepMET_mt2*/    } else {
/*                         Var_4LepMET_mt2*/      printf("branch Var_4LepMET_mt2_branch does not exist!\n");
/*                         Var_4LepMET_mt2*/      exit(1);
/*                         Var_4LepMET_mt2*/    }
/*                         Var_4LepMET_mt2*/    Var_4LepMET_mt2_isLoaded = true;
/*                         Var_4LepMET_mt2*/  }
/*                         Var_4LepMET_mt2*/  return Var_4LepMET_mt2_;
/*                         Var_4LepMET_mt2*/}

//---------------------------------------------------------------------------------

void VVVTree::progress( int nEventsTotal, int nEventsChain ){
  int period = 1000;
  if (nEventsTotal%1000 == 0) {
    // xterm magic from L. Vacavant and A. Cerri
    if (isatty(1)) {
      if ((nEventsChain - nEventsTotal) > period) {
        float frac = (float)nEventsTotal/(nEventsChain*0.01);
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
             "\033[0m\033[32m <---\033[0m\015", frac);
        fflush(stdout);
      }
      else {
        printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", 100.);
        cout << endl;
      }
    }
  }
}

namespace tas {

//---------------------------------------------------------------------------------
/*                           Common_isData*/const int &Common_isData() { return vvv.Common_isData(); }
//---------------------------------------------------------------------------------
/*                              Common_run*/const int &Common_run() { return vvv.Common_run(); }
//---------------------------------------------------------------------------------
/*                             Common_lumi*/const int &Common_lumi() { return vvv.Common_lumi(); }
//---------------------------------------------------------------------------------
/*                              Common_evt*/const unsigned long long &Common_evt() { return vvv.Common_evt(); }
//---------------------------------------------------------------------------------
/*                        Common_genWeight*/const float &Common_genWeight() { return vvv.Common_genWeight(); }
//---------------------------------------------------------------------------------
/*              Common_btagWeight_DeepCSVB*/const float &Common_btagWeight_DeepCSVB() { return vvv.Common_btagWeight_DeepCSVB(); }
//---------------------------------------------------------------------------------
/*                              Common_wgt*/const float &Common_wgt() { return vvv.Common_wgt(); }
//---------------------------------------------------------------------------------
/*         Common_LHEWeight_mg_reweighting*/const vector<float> &Common_LHEWeight_mg_reweighting() { return vvv.Common_LHEWeight_mg_reweighting(); }
//---------------------------------------------------------------------------------
/*                   Common_event_puWeight*/const float &Common_event_puWeight() { return vvv.Common_event_puWeight(); }
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightup*/const float &Common_event_puWeightup() { return vvv.Common_event_puWeightup(); }
//---------------------------------------------------------------------------------
/*                 Common_event_puWeightdn*/const float &Common_event_puWeightdn() { return vvv.Common_event_puWeightdn(); }
//---------------------------------------------------------------------------------
/*              Common_event_prefireWeight*/const float &Common_event_prefireWeight() { return vvv.Common_event_prefireWeight(); }
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightup*/const float &Common_event_prefireWeightup() { return vvv.Common_event_prefireWeightup(); }
//---------------------------------------------------------------------------------
/*            Common_event_prefireWeightdn*/const float &Common_event_prefireWeightdn() { return vvv.Common_event_prefireWeightdn(); }
//---------------------------------------------------------------------------------
/*              Common_event_triggerWeight*/const float &Common_event_triggerWeight() { return vvv.Common_event_triggerWeight(); }
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightup*/const float &Common_event_triggerWeightup() { return vvv.Common_event_triggerWeightup(); }
//---------------------------------------------------------------------------------
/*            Common_event_triggerWeightdn*/const float &Common_event_triggerWeightdn() { return vvv.Common_event_triggerWeightdn(); }
//---------------------------------------------------------------------------------
/*             Common_LHEReweightingWeight*/const vector<float> &Common_LHEReweightingWeight() { return vvv.Common_LHEReweightingWeight(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ*/const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ() { return vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ(); }
//---------------------------------------------------------------------------------
/* Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL*/const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL() { return vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8*/const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8() { return vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/const bool &Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() { return vvv.Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL*/const bool &Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL() { return vvv.Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ*/const bool &Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() { return vvv.Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL*/const bool &Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL() { return vvv.Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ*/const bool &Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ() { return vvv.Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ(); }
//---------------------------------------------------------------------------------
/*Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL*/const bool &Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL() { return vvv.Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL(); }
//---------------------------------------------------------------------------------
/*                      Common_HLT_IsoMu24*/const bool &Common_HLT_IsoMu24() { return vvv.Common_HLT_IsoMu24(); }
//---------------------------------------------------------------------------------
/*                Common_HLT_Ele32_WPTight*/const bool &Common_HLT_Ele32_WPTight() { return vvv.Common_HLT_Ele32_WPTight(); }
//---------------------------------------------------------------------------------
/*                     Common_HLT_PFHT1050*/const bool &Common_HLT_PFHT1050() { return vvv.Common_HLT_PFHT1050(); }
//---------------------------------------------------------------------------------
/*                  Common_HLT_AK8PFJet500*/const bool &Common_HLT_AK8PFJet500() { return vvv.Common_HLT_AK8PFJet500(); }
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet380_TrimMass30*/const bool &Common_HLT_AK8PFJet380_TrimMass30() { return vvv.Common_HLT_AK8PFJet380_TrimMass30(); }
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet360_TrimMass30*/const bool &Common_HLT_AK8PFJet360_TrimMass30() { return vvv.Common_HLT_AK8PFJet360_TrimMass30(); }
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet400_TrimMass30*/const bool &Common_HLT_AK8PFJet400_TrimMass30() { return vvv.Common_HLT_AK8PFJet400_TrimMass30(); }
//---------------------------------------------------------------------------------
/*       Common_HLT_AK8PFJet420_TrimMass30*/const bool &Common_HLT_AK8PFJet420_TrimMass30() { return vvv.Common_HLT_AK8PFJet420_TrimMass30(); }
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT750_TrimMass50*/const bool &Common_HLT_AK8PFHT750_TrimMass50() { return vvv.Common_HLT_AK8PFHT750_TrimMass50(); }
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT800_TrimMass50*/const bool &Common_HLT_AK8PFHT800_TrimMass50() { return vvv.Common_HLT_AK8PFHT800_TrimMass50(); }
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT850_TrimMass50*/const bool &Common_HLT_AK8PFHT850_TrimMass50() { return vvv.Common_HLT_AK8PFHT850_TrimMass50(); }
//---------------------------------------------------------------------------------
/*        Common_HLT_AK8PFHT900_TrimMass50*/const bool &Common_HLT_AK8PFHT900_TrimMass50() { return vvv.Common_HLT_AK8PFHT900_TrimMass50(); }
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleEl*/const bool &Common_HLT_DoubleEl() { return vvv.Common_HLT_DoubleEl(); }
//---------------------------------------------------------------------------------
/*                         Common_HLT_MuEG*/const bool &Common_HLT_MuEG() { return vvv.Common_HLT_MuEG(); }
//---------------------------------------------------------------------------------
/*                     Common_HLT_DoubleMu*/const bool &Common_HLT_DoubleMu() { return vvv.Common_HLT_DoubleMu(); }
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_ee_em_mm*/const bool &Common_pass_duplicate_removal_ee_em_mm() { return vvv.Common_pass_duplicate_removal_ee_em_mm(); }
//---------------------------------------------------------------------------------
/*  Common_pass_duplicate_removal_mm_em_ee*/const bool &Common_pass_duplicate_removal_mm_em_ee() { return vvv.Common_pass_duplicate_removal_mm_em_ee(); }
//---------------------------------------------------------------------------------
/*                        Common_noiseFlag*/const bool &Common_noiseFlag() { return vvv.Common_noiseFlag(); }
//---------------------------------------------------------------------------------
/*                      Common_noiseFlagMC*/const bool &Common_noiseFlagMC() { return vvv.Common_noiseFlagMC(); }
//---------------------------------------------------------------------------------
/*                      Common_passGoodRun*/const bool &Common_passGoodRun() { return vvv.Common_passGoodRun(); }
//---------------------------------------------------------------------------------
/*                           Common_met_p4*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4() { return vvv.Common_met_p4(); }
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesup*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesup() { return vvv.Common_met_p4_jesup(); }
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jesdn*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesdn() { return vvv.Common_met_p4_jesdn(); }
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerup*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jerup() { return vvv.Common_met_p4_jerup(); }
//---------------------------------------------------------------------------------
/*                     Common_met_p4_jerdn*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jerdn() { return vvv.Common_met_p4_jerdn(); }
//---------------------------------------------------------------------------------
/*                      Common_event_lepSF*/const float &Common_event_lepSF() { return vvv.Common_event_lepSF(); }
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFelup*/const float &Common_event_lepSFelup() { return vvv.Common_event_lepSFelup(); }
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFeldn*/const float &Common_event_lepSFeldn() { return vvv.Common_event_lepSFeldn(); }
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmuup*/const float &Common_event_lepSFmuup() { return vvv.Common_event_lepSFmuup(); }
//---------------------------------------------------------------------------------
/*                  Common_event_lepSFmudn*/const float &Common_event_lepSFmudn() { return vvv.Common_event_lepSFmudn(); }
//---------------------------------------------------------------------------------
/*                 Common_event_lepSFTight*/const float &Common_event_lepSFTight() { return vvv.Common_event_lepSFTight(); }
//---------------------------------------------------------------------------------
/*             Common_event_lepSFelupTight*/const float &Common_event_lepSFelupTight() { return vvv.Common_event_lepSFelupTight(); }
//---------------------------------------------------------------------------------
/*             Common_event_lepSFeldnTight*/const float &Common_event_lepSFeldnTight() { return vvv.Common_event_lepSFeldnTight(); }
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmuupTight*/const float &Common_event_lepSFmuupTight() { return vvv.Common_event_lepSFmuupTight(); }
//---------------------------------------------------------------------------------
/*             Common_event_lepSFmudnTight*/const float &Common_event_lepSFmudnTight() { return vvv.Common_event_lepSFmudnTight(); }
//---------------------------------------------------------------------------------
/*                Common_event_tightBtagSF*/const float &Common_event_tightBtagSF() { return vvv.Common_event_tightBtagSF(); }
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFup*/const float &Common_event_tightBtagSFup() { return vvv.Common_event_tightBtagSFup(); }
//---------------------------------------------------------------------------------
/*              Common_event_tightBtagSFdn*/const float &Common_event_tightBtagSFdn() { return vvv.Common_event_tightBtagSFdn(); }
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFup*/const float &Common_event_tightBtagSFHFup() { return vvv.Common_event_tightBtagSFHFup(); }
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFHFdn*/const float &Common_event_tightBtagSFHFdn() { return vvv.Common_event_tightBtagSFHFdn(); }
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFup*/const float &Common_event_tightBtagSFLFup() { return vvv.Common_event_tightBtagSFLFup(); }
//---------------------------------------------------------------------------------
/*            Common_event_tightBtagSFLFdn*/const float &Common_event_tightBtagSFLFdn() { return vvv.Common_event_tightBtagSFLFdn(); }
//---------------------------------------------------------------------------------
/*               Common_event_mediumBtagSF*/const float &Common_event_mediumBtagSF() { return vvv.Common_event_mediumBtagSF(); }
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFup*/const float &Common_event_mediumBtagSFup() { return vvv.Common_event_mediumBtagSFup(); }
//---------------------------------------------------------------------------------
/*             Common_event_mediumBtagSFdn*/const float &Common_event_mediumBtagSFdn() { return vvv.Common_event_mediumBtagSFdn(); }
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFup*/const float &Common_event_mediumBtagSFHFup() { return vvv.Common_event_mediumBtagSFHFup(); }
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFHFdn*/const float &Common_event_mediumBtagSFHFdn() { return vvv.Common_event_mediumBtagSFHFdn(); }
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFup*/const float &Common_event_mediumBtagSFLFup() { return vvv.Common_event_mediumBtagSFLFup(); }
//---------------------------------------------------------------------------------
/*           Common_event_mediumBtagSFLFdn*/const float &Common_event_mediumBtagSFLFdn() { return vvv.Common_event_mediumBtagSFLFdn(); }
//---------------------------------------------------------------------------------
/*                Common_event_looseBtagSF*/const float &Common_event_looseBtagSF() { return vvv.Common_event_looseBtagSF(); }
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFup*/const float &Common_event_looseBtagSFup() { return vvv.Common_event_looseBtagSFup(); }
//---------------------------------------------------------------------------------
/*              Common_event_looseBtagSFdn*/const float &Common_event_looseBtagSFdn() { return vvv.Common_event_looseBtagSFdn(); }
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFup*/const float &Common_event_looseBtagSFHFup() { return vvv.Common_event_looseBtagSFHFup(); }
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFHFdn*/const float &Common_event_looseBtagSFHFdn() { return vvv.Common_event_looseBtagSFHFdn(); }
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFup*/const float &Common_event_looseBtagSFLFup() { return vvv.Common_event_looseBtagSFLFup(); }
//---------------------------------------------------------------------------------
/*            Common_event_looseBtagSFLFdn*/const float &Common_event_looseBtagSFLFdn() { return vvv.Common_event_looseBtagSFLFdn(); }
//---------------------------------------------------------------------------------
/*                           Common_lep_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_lep_p4() { return vvv.Common_lep_p4(); }
//---------------------------------------------------------------------------------
/*                         Common_lep_idxs*/const vector<int> &Common_lep_idxs() { return vvv.Common_lep_idxs(); }
//---------------------------------------------------------------------------------
/*                        Common_lep_pdgid*/const vector<int> &Common_lep_pdgid() { return vvv.Common_lep_pdgid(); }
//---------------------------------------------------------------------------------
/*                        Common_lep_tight*/const vector<int> &Common_lep_tight() { return vvv.Common_lep_tight(); }
//---------------------------------------------------------------------------------
/*                          Common_lep_dxy*/const vector<float> &Common_lep_dxy() { return vvv.Common_lep_dxy(); }
//---------------------------------------------------------------------------------
/*                           Common_lep_dz*/const vector<float> &Common_lep_dz() { return vvv.Common_lep_dz(); }
//---------------------------------------------------------------------------------
/*                         Common_lep_ip3d*/const vector<float> &Common_lep_ip3d() { return vvv.Common_lep_ip3d(); }
//---------------------------------------------------------------------------------
/*                        Common_lep_sip3d*/const vector<float> &Common_lep_sip3d() { return vvv.Common_lep_sip3d(); }
//---------------------------------------------------------------------------------
/*                           Common_lep_SF*/const vector<float> &Common_lep_SF() { return vvv.Common_lep_SF(); }
//---------------------------------------------------------------------------------
/*                      Common_lep_SFTight*/const vector<float> &Common_lep_SFTight() { return vvv.Common_lep_SFTight(); }
//---------------------------------------------------------------------------------
/*                         Common_lep_SFdn*/const vector<float> &Common_lep_SFdn() { return vvv.Common_lep_SFdn(); }
//---------------------------------------------------------------------------------
/*                    Common_lep_SFdnTight*/const vector<float> &Common_lep_SFdnTight() { return vvv.Common_lep_SFdnTight(); }
//---------------------------------------------------------------------------------
/*                         Common_lep_SFup*/const vector<float> &Common_lep_SFup() { return vvv.Common_lep_SFup(); }
//---------------------------------------------------------------------------------
/*                    Common_lep_SFupTight*/const vector<float> &Common_lep_SFupTight() { return vvv.Common_lep_SFupTight(); }
//---------------------------------------------------------------------------------
/*                           Common_jet_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4() { return vvv.Common_jet_p4(); }
//---------------------------------------------------------------------------------
/*                         Common_jet_idxs*/const vector<int> &Common_jet_idxs() { return vvv.Common_jet_idxs(); }
//---------------------------------------------------------------------------------
/*                   Common_jet_passBloose*/const vector<bool> &Common_jet_passBloose() { return vvv.Common_jet_passBloose(); }
//---------------------------------------------------------------------------------
/*                  Common_jet_passBmedium*/const vector<bool> &Common_jet_passBmedium() { return vvv.Common_jet_passBmedium(); }
//---------------------------------------------------------------------------------
/*                   Common_jet_passBtight*/const vector<bool> &Common_jet_passBtight() { return vvv.Common_jet_passBtight(); }
//---------------------------------------------------------------------------------
/*                           Common_jet_id*/const vector<int> &Common_jet_id() { return vvv.Common_jet_id(); }
//---------------------------------------------------------------------------------
/*                Common_jet_overlapfatjet*/const vector<int> &Common_jet_overlapfatjet() { return vvv.Common_jet_overlapfatjet(); }
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesup*/const vector<float> &Common_jet_pt_jesup() { return vvv.Common_jet_pt_jesup(); }
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jesdn*/const vector<float> &Common_jet_pt_jesdn() { return vvv.Common_jet_pt_jesdn(); }
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerup*/const vector<float> &Common_jet_pt_jerup() { return vvv.Common_jet_pt_jerup(); }
//---------------------------------------------------------------------------------
/*                     Common_jet_pt_jerdn*/const vector<float> &Common_jet_pt_jerdn() { return vvv.Common_jet_pt_jerdn(); }
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesup*/const vector<float> &Common_jet_mass_jesup() { return vvv.Common_jet_mass_jesup(); }
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jesdn*/const vector<float> &Common_jet_mass_jesdn() { return vvv.Common_jet_mass_jesdn(); }
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerup*/const vector<float> &Common_jet_mass_jerup() { return vvv.Common_jet_mass_jerup(); }
//---------------------------------------------------------------------------------
/*                   Common_jet_mass_jerdn*/const vector<float> &Common_jet_mass_jerdn() { return vvv.Common_jet_mass_jerdn(); }
//---------------------------------------------------------------------------------
/*                        Common_fatjet_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4() { return vvv.Common_fatjet_p4(); }
//---------------------------------------------------------------------------------
/*                      Common_fatjet_idxs*/const vector<int> &Common_fatjet_idxs() { return vvv.Common_fatjet_idxs(); }
//---------------------------------------------------------------------------------
/*                        Common_fatjet_id*/const vector<int> &Common_fatjet_id() { return vvv.Common_fatjet_id(); }
//---------------------------------------------------------------------------------
/*                 Common_fatjet_msoftdrop*/const vector<float> &Common_fatjet_msoftdrop() { return vvv.Common_fatjet_msoftdrop(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_W*/const vector<float> &Common_fatjet_deepMD_W() { return vvv.Common_fatjet_deepMD_W(); }
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_W*/const vector<float> &Common_fatjet_deep_W() { return vvv.Common_fatjet_deep_W(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_Z*/const vector<float> &Common_fatjet_deepMD_Z() { return vvv.Common_fatjet_deepMD_Z(); }
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_Z*/const vector<float> &Common_fatjet_deep_Z() { return vvv.Common_fatjet_deep_Z(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_deepMD_T*/const vector<float> &Common_fatjet_deepMD_T() { return vvv.Common_fatjet_deepMD_T(); }
//---------------------------------------------------------------------------------
/*                    Common_fatjet_deep_T*/const vector<float> &Common_fatjet_deep_T() { return vvv.Common_fatjet_deep_T(); }
//---------------------------------------------------------------------------------
/*                 Common_fatjet_deepMD_bb*/const vector<float> &Common_fatjet_deepMD_bb() { return vvv.Common_fatjet_deepMD_bb(); }
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNetMD_W*/const vector<float> &Common_fatjet_particleNetMD_W() { return vvv.Common_fatjet_particleNetMD_W(); }
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xqq*/const vector<float> &Common_fatjet_particleNetMD_Xqq() { return vvv.Common_fatjet_particleNetMD_Xqq(); }
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xcc*/const vector<float> &Common_fatjet_particleNetMD_Xcc() { return vvv.Common_fatjet_particleNetMD_Xcc(); }
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_Xbb*/const vector<float> &Common_fatjet_particleNetMD_Xbb() { return vvv.Common_fatjet_particleNetMD_Xbb(); }
//---------------------------------------------------------------------------------
/*         Common_fatjet_particleNetMD_QCD*/const vector<float> &Common_fatjet_particleNetMD_QCD() { return vvv.Common_fatjet_particleNetMD_QCD(); }
//---------------------------------------------------------------------------------
/*           Common_fatjet_particleNet_QCD*/const vector<float> &Common_fatjet_particleNet_QCD() { return vvv.Common_fatjet_particleNet_QCD(); }
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_W*/const vector<float> &Common_fatjet_particleNet_W() { return vvv.Common_fatjet_particleNet_W(); }
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_Z*/const vector<float> &Common_fatjet_particleNet_Z() { return vvv.Common_fatjet_particleNet_Z(); }
//---------------------------------------------------------------------------------
/*             Common_fatjet_particleNet_T*/const vector<float> &Common_fatjet_particleNet_T() { return vvv.Common_fatjet_particleNet_T(); }
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau3*/const vector<float> &Common_fatjet_tau3() { return vvv.Common_fatjet_tau3(); }
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau2*/const vector<float> &Common_fatjet_tau2() { return vvv.Common_fatjet_tau2(); }
//---------------------------------------------------------------------------------
/*                      Common_fatjet_tau1*/const vector<float> &Common_fatjet_tau1() { return vvv.Common_fatjet_tau1(); }
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau32*/const vector<float> &Common_fatjet_tau32() { return vvv.Common_fatjet_tau32(); }
//---------------------------------------------------------------------------------
/*                     Common_fatjet_tau21*/const vector<float> &Common_fatjet_tau21() { return vvv.Common_fatjet_tau21(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_pt*/const vector<float> &Common_fatjet_subjet0_pt() { return vvv.Common_fatjet_subjet0_pt(); }
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_eta*/const vector<float> &Common_fatjet_subjet0_eta() { return vvv.Common_fatjet_subjet0_eta(); }
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet0_phi*/const vector<float> &Common_fatjet_subjet0_phi() { return vvv.Common_fatjet_subjet0_phi(); }
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet0_mass*/const vector<float> &Common_fatjet_subjet0_mass() { return vvv.Common_fatjet_subjet0_mass(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_pt*/const vector<float> &Common_fatjet_subjet1_pt() { return vvv.Common_fatjet_subjet1_pt(); }
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_eta*/const vector<float> &Common_fatjet_subjet1_eta() { return vvv.Common_fatjet_subjet1_eta(); }
//---------------------------------------------------------------------------------
/*               Common_fatjet_subjet1_phi*/const vector<float> &Common_fatjet_subjet1_phi() { return vvv.Common_fatjet_subjet1_phi(); }
//---------------------------------------------------------------------------------
/*              Common_fatjet_subjet1_mass*/const vector<float> &Common_fatjet_subjet1_mass() { return vvv.Common_fatjet_subjet1_mass(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet0_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_subjet0_p4() { return vvv.Common_fatjet_subjet0_p4(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_subjet1_p4*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_subjet1_p4() { return vvv.Common_fatjet_subjet1_p4(); }
//---------------------------------------------------------------------------------
/*                        Common_fatjet_WP*/const vector<int> &Common_fatjet_WP() { return vvv.Common_fatjet_WP(); }
//---------------------------------------------------------------------------------
/*                     Common_fatjet_WP_MD*/const vector<int> &Common_fatjet_WP_MD() { return vvv.Common_fatjet_WP_MD(); }
//---------------------------------------------------------------------------------
/*            Common_fatjet_WP_antimasscut*/const vector<int> &Common_fatjet_WP_antimasscut() { return vvv.Common_fatjet_WP_antimasscut(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFVLoose*/const vector<float> &Common_fatjet_SFVLoose() { return vvv.Common_fatjet_SFVLoose(); }
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFLoose*/const vector<float> &Common_fatjet_SFLoose() { return vvv.Common_fatjet_SFLoose(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_SFMedium*/const vector<float> &Common_fatjet_SFMedium() { return vvv.Common_fatjet_SFMedium(); }
//---------------------------------------------------------------------------------
/*                   Common_fatjet_SFTight*/const vector<float> &Common_fatjet_SFTight() { return vvv.Common_fatjet_SFTight(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnVLoose*/const vector<float> &Common_fatjet_SFdnVLoose() { return vvv.Common_fatjet_SFdnVLoose(); }
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnLoose*/const vector<float> &Common_fatjet_SFdnLoose() { return vvv.Common_fatjet_SFdnLoose(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFdnMedium*/const vector<float> &Common_fatjet_SFdnMedium() { return vvv.Common_fatjet_SFdnMedium(); }
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFdnTight*/const vector<float> &Common_fatjet_SFdnTight() { return vvv.Common_fatjet_SFdnTight(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupVLoose*/const vector<float> &Common_fatjet_SFupVLoose() { return vvv.Common_fatjet_SFupVLoose(); }
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupLoose*/const vector<float> &Common_fatjet_SFupLoose() { return vvv.Common_fatjet_SFupLoose(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_SFupMedium*/const vector<float> &Common_fatjet_SFupMedium() { return vvv.Common_fatjet_SFupMedium(); }
//---------------------------------------------------------------------------------
/*                 Common_fatjet_SFupTight*/const vector<float> &Common_fatjet_SFupTight() { return vvv.Common_fatjet_SFupTight(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesup*/const vector<float> &Common_fatjet_pt_jesup() { return vvv.Common_fatjet_pt_jesup(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jesdn*/const vector<float> &Common_fatjet_pt_jesdn() { return vvv.Common_fatjet_pt_jesdn(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerup*/const vector<float> &Common_fatjet_pt_jerup() { return vvv.Common_fatjet_pt_jerup(); }
//---------------------------------------------------------------------------------
/*                  Common_fatjet_pt_jerdn*/const vector<float> &Common_fatjet_pt_jerdn() { return vvv.Common_fatjet_pt_jerdn(); }
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesup*/const vector<float> &Common_fatjet_msoftdrop_jesup() { return vvv.Common_fatjet_msoftdrop_jesup(); }
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jesdn*/const vector<float> &Common_fatjet_msoftdrop_jesdn() { return vvv.Common_fatjet_msoftdrop_jesdn(); }
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerup*/const vector<float> &Common_fatjet_msoftdrop_jerup() { return vvv.Common_fatjet_msoftdrop_jerup(); }
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jerdn*/const vector<float> &Common_fatjet_msoftdrop_jerdn() { return vvv.Common_fatjet_msoftdrop_jerdn(); }
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsup*/const vector<float> &Common_fatjet_msoftdrop_jmsup() { return vvv.Common_fatjet_msoftdrop_jmsup(); }
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmsdn*/const vector<float> &Common_fatjet_msoftdrop_jmsdn() { return vvv.Common_fatjet_msoftdrop_jmsdn(); }
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrup*/const vector<float> &Common_fatjet_msoftdrop_jmrup() { return vvv.Common_fatjet_msoftdrop_jmrup(); }
//---------------------------------------------------------------------------------
/*           Common_fatjet_msoftdrop_jmrdn*/const vector<float> &Common_fatjet_msoftdrop_jmrdn() { return vvv.Common_fatjet_msoftdrop_jmrdn(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesup*/const vector<float> &Common_fatjet_mass_jesup() { return vvv.Common_fatjet_mass_jesup(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jesdn*/const vector<float> &Common_fatjet_mass_jesdn() { return vvv.Common_fatjet_mass_jesdn(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerup*/const vector<float> &Common_fatjet_mass_jerup() { return vvv.Common_fatjet_mass_jerup(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jerdn*/const vector<float> &Common_fatjet_mass_jerdn() { return vvv.Common_fatjet_mass_jerdn(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsup*/const vector<float> &Common_fatjet_mass_jmsup() { return vvv.Common_fatjet_mass_jmsup(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmsdn*/const vector<float> &Common_fatjet_mass_jmsdn() { return vvv.Common_fatjet_mass_jmsdn(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrup*/const vector<float> &Common_fatjet_mass_jmrup() { return vvv.Common_fatjet_mass_jmrup(); }
//---------------------------------------------------------------------------------
/*                Common_fatjet_mass_jmrdn*/const vector<float> &Common_fatjet_mass_jmrdn() { return vvv.Common_fatjet_mass_jmrdn(); }
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFVLoose*/const float &Common_eventweight_fatjet_SFVLoose() { return vvv.Common_eventweight_fatjet_SFVLoose(); }
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFLoose*/const float &Common_eventweight_fatjet_SFLoose() { return vvv.Common_eventweight_fatjet_SFLoose(); }
//---------------------------------------------------------------------------------
/*      Common_eventweight_fatjet_SFMedium*/const float &Common_eventweight_fatjet_SFMedium() { return vvv.Common_eventweight_fatjet_SFMedium(); }
//---------------------------------------------------------------------------------
/*       Common_eventweight_fatjet_SFTight*/const float &Common_eventweight_fatjet_SFTight() { return vvv.Common_eventweight_fatjet_SFTight(); }
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnVLoose*/const float &Common_eventweight_fatjet_SFdnVLoose() { return vvv.Common_eventweight_fatjet_SFdnVLoose(); }
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnLoose*/const float &Common_eventweight_fatjet_SFdnLoose() { return vvv.Common_eventweight_fatjet_SFdnLoose(); }
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFdnMedium*/const float &Common_eventweight_fatjet_SFdnMedium() { return vvv.Common_eventweight_fatjet_SFdnMedium(); }
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFdnTight*/const float &Common_eventweight_fatjet_SFdnTight() { return vvv.Common_eventweight_fatjet_SFdnTight(); }
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupVLoose*/const float &Common_eventweight_fatjet_SFupVLoose() { return vvv.Common_eventweight_fatjet_SFupVLoose(); }
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupLoose*/const float &Common_eventweight_fatjet_SFupLoose() { return vvv.Common_eventweight_fatjet_SFupLoose(); }
//---------------------------------------------------------------------------------
/*    Common_eventweight_fatjet_SFupMedium*/const float &Common_eventweight_fatjet_SFupMedium() { return vvv.Common_eventweight_fatjet_SFupMedium(); }
//---------------------------------------------------------------------------------
/*     Common_eventweight_fatjet_SFupTight*/const float &Common_eventweight_fatjet_SFupTight() { return vvv.Common_eventweight_fatjet_SFupTight(); }
//---------------------------------------------------------------------------------
/*                         Common_nb_loose*/const int &Common_nb_loose() { return vvv.Common_nb_loose(); }
//---------------------------------------------------------------------------------
/*                        Common_nb_medium*/const int &Common_nb_medium() { return vvv.Common_nb_medium(); }
//---------------------------------------------------------------------------------
/*                         Common_nb_tight*/const int &Common_nb_tight() { return vvv.Common_nb_tight(); }
//---------------------------------------------------------------------------------
/*                          Common_gen_idx*/const vector<int> &Common_gen_idx() { return vvv.Common_gen_idx(); }
//---------------------------------------------------------------------------------
/*                   Common_gen_mother_idx*/const vector<int> &Common_gen_mother_idx() { return vvv.Common_gen_mother_idx(); }
//---------------------------------------------------------------------------------
/*                    Common_gen_mother_id*/const vector<int> &Common_gen_mother_id() { return vvv.Common_gen_mother_id(); }
//---------------------------------------------------------------------------------
/*                        Common_gen_pdgid*/const vector<int> &Common_gen_pdgid() { return vvv.Common_gen_pdgid(); }
//---------------------------------------------------------------------------------
/*                          Common_gen_p4s*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_gen_p4s() { return vvv.Common_gen_p4s(); }
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_idx*/const vector<int> &Common_gen_vvvdecay_idx() { return vvv.Common_gen_vvvdecay_idx(); }
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_mother_idx*/const vector<int> &Common_gen_vvvdecay_mother_idx() { return vvv.Common_gen_vvvdecay_mother_idx(); }
//---------------------------------------------------------------------------------
/*           Common_gen_vvvdecay_mother_id*/const vector<int> &Common_gen_vvvdecay_mother_id() { return vvv.Common_gen_vvvdecay_mother_id(); }
//---------------------------------------------------------------------------------
/*               Common_gen_vvvdecay_pdgid*/const vector<int> &Common_gen_vvvdecay_pdgid() { return vvv.Common_gen_vvvdecay_pdgid(); }
//---------------------------------------------------------------------------------
/*                 Common_gen_vvvdecay_p4s*/const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_gen_vvvdecay_p4s() { return vvv.Common_gen_vvvdecay_p4s(); }
//---------------------------------------------------------------------------------
/*          Common_gen_vvvdecay_taudecayid*/const vector<int> &Common_gen_vvvdecay_taudecayid() { return vvv.Common_gen_vvvdecay_taudecayid(); }
//---------------------------------------------------------------------------------
/*                         Common_isSignal*/const bool &Common_isSignal() { return vvv.Common_isSignal(); }
//---------------------------------------------------------------------------------
/*                              Common_n_W*/const int &Common_n_W() { return vvv.Common_n_W(); }
//---------------------------------------------------------------------------------
/*                              Common_n_Z*/const int &Common_n_Z() { return vvv.Common_n_Z(); }
//---------------------------------------------------------------------------------
/*                          Common_n_lep_Z*/const int &Common_n_lep_Z() { return vvv.Common_n_lep_Z(); }
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_Z*/const int &Common_n_leptau_Z() { return vvv.Common_n_leptau_Z(); }
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_Z*/const int &Common_n_hadtau_Z() { return vvv.Common_n_hadtau_Z(); }
//---------------------------------------------------------------------------------
/*                           Common_n_nu_Z*/const int &Common_n_nu_Z() { return vvv.Common_n_nu_Z(); }
//---------------------------------------------------------------------------------
/*                            Common_n_b_Z*/const int &Common_n_b_Z() { return vvv.Common_n_b_Z(); }
//---------------------------------------------------------------------------------
/*                          Common_n_lep_W*/const int &Common_n_lep_W() { return vvv.Common_n_lep_W(); }
//---------------------------------------------------------------------------------
/*                       Common_n_leptau_W*/const int &Common_n_leptau_W() { return vvv.Common_n_leptau_W(); }
//---------------------------------------------------------------------------------
/*                       Common_n_hadtau_W*/const int &Common_n_hadtau_W() { return vvv.Common_n_hadtau_W(); }
//---------------------------------------------------------------------------------
/*                        Common_haslepWSS*/const bool &Common_haslepWSS() { return vvv.Common_haslepWSS(); }
//---------------------------------------------------------------------------------
/*                            Common_genHT*/const float &Common_genHT() { return vvv.Common_genHT(); }
//---------------------------------------------------------------------------------
/*                  Common_gen_n_light_lep*/const int &Common_gen_n_light_lep() { return vvv.Common_gen_n_light_lep(); }
//---------------------------------------------------------------------------------
/*                   Common_gen_VH_channel*/const int &Common_gen_VH_channel() { return vvv.Common_gen_VH_channel(); }
//---------------------------------------------------------------------------------
/*                Cut_4LepMET_Preselection*/const bool &Cut_4LepMET_Preselection() { return vvv.Cut_4LepMET_Preselection(); }
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_emuChannel*/const bool &Cut_4LepMET_emuChannel() { return vvv.Cut_4LepMET_emuChannel(); }
//---------------------------------------------------------------------------------
/*                 Cut_4LepMET_offzChannel*/const bool &Cut_4LepMET_offzChannel() { return vvv.Cut_4LepMET_offzChannel(); }
//---------------------------------------------------------------------------------
/*                  Cut_4LepMET_onzChannel*/const bool &Cut_4LepMET_onzChannel() { return vvv.Cut_4LepMET_onzChannel(); }
//---------------------------------------------------------------------------------
/*          Cut_4LepMET_onzChannel_HighMET*/const bool &Cut_4LepMET_onzChannel_HighMET() { return vvv.Cut_4LepMET_onzChannel_HighMET(); }
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_0*/const int &Var_4LepMET_Zcand_lep_idx_0() { return vvv.Var_4LepMET_Zcand_lep_idx_0(); }
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_0*/const int &Var_4LepMET_Zcand_lep_pdgid_0() { return vvv.Var_4LepMET_Zcand_lep_pdgid_0(); }
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_0*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_Zcand_lep_p4_0() { return vvv.Var_4LepMET_Zcand_lep_p4_0(); }
//---------------------------------------------------------------------------------
/*             Var_4LepMET_Zcand_lep_idx_1*/const int &Var_4LepMET_Zcand_lep_idx_1() { return vvv.Var_4LepMET_Zcand_lep_idx_1(); }
//---------------------------------------------------------------------------------
/*           Var_4LepMET_Zcand_lep_pdgid_1*/const int &Var_4LepMET_Zcand_lep_pdgid_1() { return vvv.Var_4LepMET_Zcand_lep_pdgid_1(); }
//---------------------------------------------------------------------------------
/*              Var_4LepMET_Zcand_lep_p4_1*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_Zcand_lep_p4_1() { return vvv.Var_4LepMET_Zcand_lep_p4_1(); }
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_Zcand_mll*/const float &Var_4LepMET_Zcand_mll() { return vvv.Var_4LepMET_Zcand_mll(); }
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_0*/const int &Var_4LepMET_other_lep_idx_0() { return vvv.Var_4LepMET_other_lep_idx_0(); }
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_0*/const int &Var_4LepMET_other_lep_pdgid_0() { return vvv.Var_4LepMET_other_lep_pdgid_0(); }
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_0*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_other_lep_p4_0() { return vvv.Var_4LepMET_other_lep_p4_0(); }
//---------------------------------------------------------------------------------
/*             Var_4LepMET_other_lep_idx_1*/const int &Var_4LepMET_other_lep_idx_1() { return vvv.Var_4LepMET_other_lep_idx_1(); }
//---------------------------------------------------------------------------------
/*           Var_4LepMET_other_lep_pdgid_1*/const int &Var_4LepMET_other_lep_pdgid_1() { return vvv.Var_4LepMET_other_lep_pdgid_1(); }
//---------------------------------------------------------------------------------
/*              Var_4LepMET_other_lep_p4_1*/const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_other_lep_p4_1() { return vvv.Var_4LepMET_other_lep_p4_1(); }
//---------------------------------------------------------------------------------
/*                   Var_4LepMET_other_mll*/const float &Var_4LepMET_other_mll() { return vvv.Var_4LepMET_other_mll(); }
//---------------------------------------------------------------------------------
/*                         Var_4LepMET_mt2*/const float &Var_4LepMET_mt2() { return vvv.Var_4LepMET_mt2(); }
//---------------------------------------------------------------------------------

}
