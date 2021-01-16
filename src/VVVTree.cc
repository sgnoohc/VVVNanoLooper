#include "VVVTree.h"
VVVTree vvv;

void VVVTree::Init(TTree *tree) {
  Common_met_p4_branch = tree->GetBranch("Common_met_p4");
  if (Common_met_p4_branch) Common_met_p4_branch->SetAddress(&Common_met_p4_);
  Common_lep_p4_branch = tree->GetBranch("Common_lep_p4");
  if (Common_lep_p4_branch) Common_lep_p4_branch->SetAddress(&Common_lep_p4_);
  Common_jet_p4_branch = tree->GetBranch("Common_jet_p4");
  if (Common_jet_p4_branch) Common_jet_p4_branch->SetAddress(&Common_jet_p4_);
  Common_fatjet_p4_branch = tree->GetBranch("Common_fatjet_p4");
  if (Common_fatjet_p4_branch) Common_fatjet_p4_branch->SetAddress(&Common_fatjet_p4_);
  Common_fatjet_subjet0_p4_branch = tree->GetBranch("Common_fatjet_subjet0_p4");
  if (Common_fatjet_subjet0_p4_branch) Common_fatjet_subjet0_p4_branch->SetAddress(&Common_fatjet_subjet0_p4_);
  Common_fatjet_subjet1_p4_branch = tree->GetBranch("Common_fatjet_subjet1_p4");
  if (Common_fatjet_subjet1_p4_branch) Common_fatjet_subjet1_p4_branch->SetAddress(&Common_fatjet_subjet1_p4_);
  Common_gen_p4s_branch = tree->GetBranch("Common_gen_p4s");
  if (Common_gen_p4s_branch) Common_gen_p4s_branch->SetAddress(&Common_gen_p4s_);
  Common_gen_vvvdecay_p4s_branch = tree->GetBranch("Common_gen_vvvdecay_p4s");
  if (Common_gen_vvvdecay_p4s_branch) Common_gen_vvvdecay_p4s_branch->SetAddress(&Common_gen_vvvdecay_p4s_);
  Var_4LepMET_Zcand_lep_p4_0_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_p4_0");
  if (Var_4LepMET_Zcand_lep_p4_0_branch) Var_4LepMET_Zcand_lep_p4_0_branch->SetAddress(&Var_4LepMET_Zcand_lep_p4_0_);
  Var_4LepMET_Zcand_lep_p4_1_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_p4_1");
  if (Var_4LepMET_Zcand_lep_p4_1_branch) Var_4LepMET_Zcand_lep_p4_1_branch->SetAddress(&Var_4LepMET_Zcand_lep_p4_1_);
  Var_4LepMET_other_lep_p4_0_branch = tree->GetBranch("Var_4LepMET_other_lep_p4_0");
  if (Var_4LepMET_other_lep_p4_0_branch) Var_4LepMET_other_lep_p4_0_branch->SetAddress(&Var_4LepMET_other_lep_p4_0_);
  Var_4LepMET_other_lep_p4_1_branch = tree->GetBranch("Var_4LepMET_other_lep_p4_1");
  if (Var_4LepMET_other_lep_p4_1_branch) Var_4LepMET_other_lep_p4_1_branch->SetAddress(&Var_4LepMET_other_lep_p4_1_);

  tree->SetMakeClass(1);

  Common_isData_branch = tree->GetBranch("Common_isData");
  if (Common_isData_branch) Common_isData_branch->SetAddress(&Common_isData_);
  Common_run_branch = tree->GetBranch("Common_run");
  if (Common_run_branch) Common_run_branch->SetAddress(&Common_run_);
  Common_lumi_branch = tree->GetBranch("Common_lumi");
  if (Common_lumi_branch) Common_lumi_branch->SetAddress(&Common_lumi_);
  Common_evt_branch = tree->GetBranch("Common_evt");
  if (Common_evt_branch) Common_evt_branch->SetAddress(&Common_evt_);
  Common_genWeight_branch = tree->GetBranch("Common_genWeight");
  if (Common_genWeight_branch) Common_genWeight_branch->SetAddress(&Common_genWeight_);
  Common_btagWeight_DeepCSVB_branch = tree->GetBranch("Common_btagWeight_DeepCSVB");
  if (Common_btagWeight_DeepCSVB_branch) Common_btagWeight_DeepCSVB_branch->SetAddress(&Common_btagWeight_DeepCSVB_);
  Common_LHEWeight_mg_reweighting_branch = tree->GetBranch("Common_LHEWeight_mg_reweighting");
  if (Common_LHEWeight_mg_reweighting_branch) Common_LHEWeight_mg_reweighting_branch->SetAddress(&Common_LHEWeight_mg_reweighting_);
  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch = tree->GetBranch("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ");
  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch->SetAddress(&Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_);
  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch = tree->GetBranch("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL");
  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch->SetAddress(&Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_);
  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch = tree->GetBranch("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8");
  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch->SetAddress(&Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_);
  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch = tree->GetBranch("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");
  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch->SetAddress(&Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_);
  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch = tree->GetBranch("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL");
  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch->SetAddress(&Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_);
  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch = tree->GetBranch("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");
  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch->SetAddress(&Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_);
  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch = tree->GetBranch("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL");
  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch->SetAddress(&Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_);
  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch = tree->GetBranch("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ");
  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch->SetAddress(&Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_);
  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch = tree->GetBranch("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL");
  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch->SetAddress(&Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_);
  Common_HLT_DoubleEl_branch = tree->GetBranch("Common_HLT_DoubleEl");
  if (Common_HLT_DoubleEl_branch) Common_HLT_DoubleEl_branch->SetAddress(&Common_HLT_DoubleEl_);
  Common_HLT_MuEG_branch = tree->GetBranch("Common_HLT_MuEG");
  if (Common_HLT_MuEG_branch) Common_HLT_MuEG_branch->SetAddress(&Common_HLT_MuEG_);
  Common_HLT_DoubleMu_branch = tree->GetBranch("Common_HLT_DoubleMu");
  if (Common_HLT_DoubleMu_branch) Common_HLT_DoubleMu_branch->SetAddress(&Common_HLT_DoubleMu_);
  Common_pass_duplicate_removal_ee_em_mm_branch = tree->GetBranch("Common_pass_duplicate_removal_ee_em_mm");
  if (Common_pass_duplicate_removal_ee_em_mm_branch) Common_pass_duplicate_removal_ee_em_mm_branch->SetAddress(&Common_pass_duplicate_removal_ee_em_mm_);
  Common_pass_duplicate_removal_mm_em_ee_branch = tree->GetBranch("Common_pass_duplicate_removal_mm_em_ee");
  if (Common_pass_duplicate_removal_mm_em_ee_branch) Common_pass_duplicate_removal_mm_em_ee_branch->SetAddress(&Common_pass_duplicate_removal_mm_em_ee_);
  Common_noiseFlag_branch = tree->GetBranch("Common_noiseFlag");
  if (Common_noiseFlag_branch) Common_noiseFlag_branch->SetAddress(&Common_noiseFlag_);
  Common_noiseFlagMC_branch = tree->GetBranch("Common_noiseFlagMC");
  if (Common_noiseFlagMC_branch) Common_noiseFlagMC_branch->SetAddress(&Common_noiseFlagMC_);
  Common_event_lepSF_branch = tree->GetBranch("Common_event_lepSF");
  if (Common_event_lepSF_branch) Common_event_lepSF_branch->SetAddress(&Common_event_lepSF_);
  Common_event_lepSFelup_branch = tree->GetBranch("Common_event_lepSFelup");
  if (Common_event_lepSFelup_branch) Common_event_lepSFelup_branch->SetAddress(&Common_event_lepSFelup_);
  Common_event_lepSFeldn_branch = tree->GetBranch("Common_event_lepSFeldn");
  if (Common_event_lepSFeldn_branch) Common_event_lepSFeldn_branch->SetAddress(&Common_event_lepSFeldn_);
  Common_event_lepSFmuup_branch = tree->GetBranch("Common_event_lepSFmuup");
  if (Common_event_lepSFmuup_branch) Common_event_lepSFmuup_branch->SetAddress(&Common_event_lepSFmuup_);
  Common_event_lepSFmudn_branch = tree->GetBranch("Common_event_lepSFmudn");
  if (Common_event_lepSFmudn_branch) Common_event_lepSFmudn_branch->SetAddress(&Common_event_lepSFmudn_);
  Common_lep_idxs_branch = tree->GetBranch("Common_lep_idxs");
  if (Common_lep_idxs_branch) Common_lep_idxs_branch->SetAddress(&Common_lep_idxs_);
  Common_lep_pdgid_branch = tree->GetBranch("Common_lep_pdgid");
  if (Common_lep_pdgid_branch) Common_lep_pdgid_branch->SetAddress(&Common_lep_pdgid_);
  Common_lep_tight_branch = tree->GetBranch("Common_lep_tight");
  if (Common_lep_tight_branch) Common_lep_tight_branch->SetAddress(&Common_lep_tight_);
  Common_lep_dxy_branch = tree->GetBranch("Common_lep_dxy");
  if (Common_lep_dxy_branch) Common_lep_dxy_branch->SetAddress(&Common_lep_dxy_);
  Common_lep_dz_branch = tree->GetBranch("Common_lep_dz");
  if (Common_lep_dz_branch) Common_lep_dz_branch->SetAddress(&Common_lep_dz_);
  Common_lep_SF_branch = tree->GetBranch("Common_lep_SF");
  if (Common_lep_SF_branch) Common_lep_SF_branch->SetAddress(&Common_lep_SF_);
  Common_lep_SFTight_branch = tree->GetBranch("Common_lep_SFTight");
  if (Common_lep_SFTight_branch) Common_lep_SFTight_branch->SetAddress(&Common_lep_SFTight_);
  Common_lep_SFdn_branch = tree->GetBranch("Common_lep_SFdn");
  if (Common_lep_SFdn_branch) Common_lep_SFdn_branch->SetAddress(&Common_lep_SFdn_);
  Common_lep_SFdnTight_branch = tree->GetBranch("Common_lep_SFdnTight");
  if (Common_lep_SFdnTight_branch) Common_lep_SFdnTight_branch->SetAddress(&Common_lep_SFdnTight_);
  Common_lep_SFup_branch = tree->GetBranch("Common_lep_SFup");
  if (Common_lep_SFup_branch) Common_lep_SFup_branch->SetAddress(&Common_lep_SFup_);
  Common_lep_SFupTight_branch = tree->GetBranch("Common_lep_SFupTight");
  if (Common_lep_SFupTight_branch) Common_lep_SFupTight_branch->SetAddress(&Common_lep_SFupTight_);
  Common_jet_idxs_branch = tree->GetBranch("Common_jet_idxs");
  if (Common_jet_idxs_branch) Common_jet_idxs_branch->SetAddress(&Common_jet_idxs_);
  Common_jet_passBloose_branch = tree->GetBranch("Common_jet_passBloose");
  if (Common_jet_passBloose_branch) Common_jet_passBloose_branch->SetAddress(&Common_jet_passBloose_);
  Common_jet_passBmedium_branch = tree->GetBranch("Common_jet_passBmedium");
  if (Common_jet_passBmedium_branch) Common_jet_passBmedium_branch->SetAddress(&Common_jet_passBmedium_);
  Common_jet_passBtight_branch = tree->GetBranch("Common_jet_passBtight");
  if (Common_jet_passBtight_branch) Common_jet_passBtight_branch->SetAddress(&Common_jet_passBtight_);
  Common_jet_overlapfatjet_branch = tree->GetBranch("Common_jet_overlapfatjet");
  if (Common_jet_overlapfatjet_branch) Common_jet_overlapfatjet_branch->SetAddress(&Common_jet_overlapfatjet_);
  Common_fatjet_idxs_branch = tree->GetBranch("Common_fatjet_idxs");
  if (Common_fatjet_idxs_branch) Common_fatjet_idxs_branch->SetAddress(&Common_fatjet_idxs_);
  Common_fatjet_msoftdrop_branch = tree->GetBranch("Common_fatjet_msoftdrop");
  if (Common_fatjet_msoftdrop_branch) Common_fatjet_msoftdrop_branch->SetAddress(&Common_fatjet_msoftdrop_);
  Common_fatjet_deepMD_W_branch = tree->GetBranch("Common_fatjet_deepMD_W");
  if (Common_fatjet_deepMD_W_branch) Common_fatjet_deepMD_W_branch->SetAddress(&Common_fatjet_deepMD_W_);
  Common_fatjet_deep_W_branch = tree->GetBranch("Common_fatjet_deep_W");
  if (Common_fatjet_deep_W_branch) Common_fatjet_deep_W_branch->SetAddress(&Common_fatjet_deep_W_);
  Common_fatjet_deepMD_Z_branch = tree->GetBranch("Common_fatjet_deepMD_Z");
  if (Common_fatjet_deepMD_Z_branch) Common_fatjet_deepMD_Z_branch->SetAddress(&Common_fatjet_deepMD_Z_);
  Common_fatjet_deep_Z_branch = tree->GetBranch("Common_fatjet_deep_Z");
  if (Common_fatjet_deep_Z_branch) Common_fatjet_deep_Z_branch->SetAddress(&Common_fatjet_deep_Z_);
  Common_fatjet_deepMD_T_branch = tree->GetBranch("Common_fatjet_deepMD_T");
  if (Common_fatjet_deepMD_T_branch) Common_fatjet_deepMD_T_branch->SetAddress(&Common_fatjet_deepMD_T_);
  Common_fatjet_deep_T_branch = tree->GetBranch("Common_fatjet_deep_T");
  if (Common_fatjet_deep_T_branch) Common_fatjet_deep_T_branch->SetAddress(&Common_fatjet_deep_T_);
  Common_fatjet_deepMD_bb_branch = tree->GetBranch("Common_fatjet_deepMD_bb");
  if (Common_fatjet_deepMD_bb_branch) Common_fatjet_deepMD_bb_branch->SetAddress(&Common_fatjet_deepMD_bb_);
  Common_fatjet_tau3_branch = tree->GetBranch("Common_fatjet_tau3");
  if (Common_fatjet_tau3_branch) Common_fatjet_tau3_branch->SetAddress(&Common_fatjet_tau3_);
  Common_fatjet_tau2_branch = tree->GetBranch("Common_fatjet_tau2");
  if (Common_fatjet_tau2_branch) Common_fatjet_tau2_branch->SetAddress(&Common_fatjet_tau2_);
  Common_fatjet_tau1_branch = tree->GetBranch("Common_fatjet_tau1");
  if (Common_fatjet_tau1_branch) Common_fatjet_tau1_branch->SetAddress(&Common_fatjet_tau1_);
  Common_fatjet_tau32_branch = tree->GetBranch("Common_fatjet_tau32");
  if (Common_fatjet_tau32_branch) Common_fatjet_tau32_branch->SetAddress(&Common_fatjet_tau32_);
  Common_fatjet_tau21_branch = tree->GetBranch("Common_fatjet_tau21");
  if (Common_fatjet_tau21_branch) Common_fatjet_tau21_branch->SetAddress(&Common_fatjet_tau21_);
  Common_fatjet_subjet0_pt_branch = tree->GetBranch("Common_fatjet_subjet0_pt");
  if (Common_fatjet_subjet0_pt_branch) Common_fatjet_subjet0_pt_branch->SetAddress(&Common_fatjet_subjet0_pt_);
  Common_fatjet_subjet0_eta_branch = tree->GetBranch("Common_fatjet_subjet0_eta");
  if (Common_fatjet_subjet0_eta_branch) Common_fatjet_subjet0_eta_branch->SetAddress(&Common_fatjet_subjet0_eta_);
  Common_fatjet_subjet0_phi_branch = tree->GetBranch("Common_fatjet_subjet0_phi");
  if (Common_fatjet_subjet0_phi_branch) Common_fatjet_subjet0_phi_branch->SetAddress(&Common_fatjet_subjet0_phi_);
  Common_fatjet_subjet0_mass_branch = tree->GetBranch("Common_fatjet_subjet0_mass");
  if (Common_fatjet_subjet0_mass_branch) Common_fatjet_subjet0_mass_branch->SetAddress(&Common_fatjet_subjet0_mass_);
  Common_fatjet_subjet1_pt_branch = tree->GetBranch("Common_fatjet_subjet1_pt");
  if (Common_fatjet_subjet1_pt_branch) Common_fatjet_subjet1_pt_branch->SetAddress(&Common_fatjet_subjet1_pt_);
  Common_fatjet_subjet1_eta_branch = tree->GetBranch("Common_fatjet_subjet1_eta");
  if (Common_fatjet_subjet1_eta_branch) Common_fatjet_subjet1_eta_branch->SetAddress(&Common_fatjet_subjet1_eta_);
  Common_fatjet_subjet1_phi_branch = tree->GetBranch("Common_fatjet_subjet1_phi");
  if (Common_fatjet_subjet1_phi_branch) Common_fatjet_subjet1_phi_branch->SetAddress(&Common_fatjet_subjet1_phi_);
  Common_fatjet_subjet1_mass_branch = tree->GetBranch("Common_fatjet_subjet1_mass");
  if (Common_fatjet_subjet1_mass_branch) Common_fatjet_subjet1_mass_branch->SetAddress(&Common_fatjet_subjet1_mass_);
  Common_fatjet_WP_branch = tree->GetBranch("Common_fatjet_WP");
  if (Common_fatjet_WP_branch) Common_fatjet_WP_branch->SetAddress(&Common_fatjet_WP_);
  Common_fatjet_WP_antimasscut_branch = tree->GetBranch("Common_fatjet_WP_antimasscut");
  if (Common_fatjet_WP_antimasscut_branch) Common_fatjet_WP_antimasscut_branch->SetAddress(&Common_fatjet_WP_antimasscut_);
  Common_fatjet_SFVLoose_branch = tree->GetBranch("Common_fatjet_SFVLoose");
  if (Common_fatjet_SFVLoose_branch) Common_fatjet_SFVLoose_branch->SetAddress(&Common_fatjet_SFVLoose_);
  Common_fatjet_SFLoose_branch = tree->GetBranch("Common_fatjet_SFLoose");
  if (Common_fatjet_SFLoose_branch) Common_fatjet_SFLoose_branch->SetAddress(&Common_fatjet_SFLoose_);
  Common_fatjet_SFMedium_branch = tree->GetBranch("Common_fatjet_SFMedium");
  if (Common_fatjet_SFMedium_branch) Common_fatjet_SFMedium_branch->SetAddress(&Common_fatjet_SFMedium_);
  Common_fatjet_SFTight_branch = tree->GetBranch("Common_fatjet_SFTight");
  if (Common_fatjet_SFTight_branch) Common_fatjet_SFTight_branch->SetAddress(&Common_fatjet_SFTight_);
  Common_fatjet_SFdnVLoose_branch = tree->GetBranch("Common_fatjet_SFdnVLoose");
  if (Common_fatjet_SFdnVLoose_branch) Common_fatjet_SFdnVLoose_branch->SetAddress(&Common_fatjet_SFdnVLoose_);
  Common_fatjet_SFdnLoose_branch = tree->GetBranch("Common_fatjet_SFdnLoose");
  if (Common_fatjet_SFdnLoose_branch) Common_fatjet_SFdnLoose_branch->SetAddress(&Common_fatjet_SFdnLoose_);
  Common_fatjet_SFdnMedium_branch = tree->GetBranch("Common_fatjet_SFdnMedium");
  if (Common_fatjet_SFdnMedium_branch) Common_fatjet_SFdnMedium_branch->SetAddress(&Common_fatjet_SFdnMedium_);
  Common_fatjet_SFdnTight_branch = tree->GetBranch("Common_fatjet_SFdnTight");
  if (Common_fatjet_SFdnTight_branch) Common_fatjet_SFdnTight_branch->SetAddress(&Common_fatjet_SFdnTight_);
  Common_fatjet_SFupVLoose_branch = tree->GetBranch("Common_fatjet_SFupVLoose");
  if (Common_fatjet_SFupVLoose_branch) Common_fatjet_SFupVLoose_branch->SetAddress(&Common_fatjet_SFupVLoose_);
  Common_fatjet_SFupLoose_branch = tree->GetBranch("Common_fatjet_SFupLoose");
  if (Common_fatjet_SFupLoose_branch) Common_fatjet_SFupLoose_branch->SetAddress(&Common_fatjet_SFupLoose_);
  Common_fatjet_SFupMedium_branch = tree->GetBranch("Common_fatjet_SFupMedium");
  if (Common_fatjet_SFupMedium_branch) Common_fatjet_SFupMedium_branch->SetAddress(&Common_fatjet_SFupMedium_);
  Common_fatjet_SFupTight_branch = tree->GetBranch("Common_fatjet_SFupTight");
  if (Common_fatjet_SFupTight_branch) Common_fatjet_SFupTight_branch->SetAddress(&Common_fatjet_SFupTight_);
  Common_eventweight_fatjet_SFVLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFVLoose");
  if (Common_eventweight_fatjet_SFVLoose_branch) Common_eventweight_fatjet_SFVLoose_branch->SetAddress(&Common_eventweight_fatjet_SFVLoose_);
  Common_eventweight_fatjet_SFLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFLoose");
  if (Common_eventweight_fatjet_SFLoose_branch) Common_eventweight_fatjet_SFLoose_branch->SetAddress(&Common_eventweight_fatjet_SFLoose_);
  Common_eventweight_fatjet_SFMedium_branch = tree->GetBranch("Common_eventweight_fatjet_SFMedium");
  if (Common_eventweight_fatjet_SFMedium_branch) Common_eventweight_fatjet_SFMedium_branch->SetAddress(&Common_eventweight_fatjet_SFMedium_);
  Common_eventweight_fatjet_SFTight_branch = tree->GetBranch("Common_eventweight_fatjet_SFTight");
  if (Common_eventweight_fatjet_SFTight_branch) Common_eventweight_fatjet_SFTight_branch->SetAddress(&Common_eventweight_fatjet_SFTight_);
  Common_eventweight_fatjet_SFdnVLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFdnVLoose");
  if (Common_eventweight_fatjet_SFdnVLoose_branch) Common_eventweight_fatjet_SFdnVLoose_branch->SetAddress(&Common_eventweight_fatjet_SFdnVLoose_);
  Common_eventweight_fatjet_SFdnLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFdnLoose");
  if (Common_eventweight_fatjet_SFdnLoose_branch) Common_eventweight_fatjet_SFdnLoose_branch->SetAddress(&Common_eventweight_fatjet_SFdnLoose_);
  Common_eventweight_fatjet_SFdnMedium_branch = tree->GetBranch("Common_eventweight_fatjet_SFdnMedium");
  if (Common_eventweight_fatjet_SFdnMedium_branch) Common_eventweight_fatjet_SFdnMedium_branch->SetAddress(&Common_eventweight_fatjet_SFdnMedium_);
  Common_eventweight_fatjet_SFdnTight_branch = tree->GetBranch("Common_eventweight_fatjet_SFdnTight");
  if (Common_eventweight_fatjet_SFdnTight_branch) Common_eventweight_fatjet_SFdnTight_branch->SetAddress(&Common_eventweight_fatjet_SFdnTight_);
  Common_eventweight_fatjet_SFupVLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFupVLoose");
  if (Common_eventweight_fatjet_SFupVLoose_branch) Common_eventweight_fatjet_SFupVLoose_branch->SetAddress(&Common_eventweight_fatjet_SFupVLoose_);
  Common_eventweight_fatjet_SFupLoose_branch = tree->GetBranch("Common_eventweight_fatjet_SFupLoose");
  if (Common_eventweight_fatjet_SFupLoose_branch) Common_eventweight_fatjet_SFupLoose_branch->SetAddress(&Common_eventweight_fatjet_SFupLoose_);
  Common_eventweight_fatjet_SFupMedium_branch = tree->GetBranch("Common_eventweight_fatjet_SFupMedium");
  if (Common_eventweight_fatjet_SFupMedium_branch) Common_eventweight_fatjet_SFupMedium_branch->SetAddress(&Common_eventweight_fatjet_SFupMedium_);
  Common_eventweight_fatjet_SFupTight_branch = tree->GetBranch("Common_eventweight_fatjet_SFupTight");
  if (Common_eventweight_fatjet_SFupTight_branch) Common_eventweight_fatjet_SFupTight_branch->SetAddress(&Common_eventweight_fatjet_SFupTight_);
  Common_nb_loose_branch = tree->GetBranch("Common_nb_loose");
  if (Common_nb_loose_branch) Common_nb_loose_branch->SetAddress(&Common_nb_loose_);
  Common_nb_medium_branch = tree->GetBranch("Common_nb_medium");
  if (Common_nb_medium_branch) Common_nb_medium_branch->SetAddress(&Common_nb_medium_);
  Common_nb_tight_branch = tree->GetBranch("Common_nb_tight");
  if (Common_nb_tight_branch) Common_nb_tight_branch->SetAddress(&Common_nb_tight_);
  Common_gen_idx_branch = tree->GetBranch("Common_gen_idx");
  if (Common_gen_idx_branch) Common_gen_idx_branch->SetAddress(&Common_gen_idx_);
  Common_gen_mother_idx_branch = tree->GetBranch("Common_gen_mother_idx");
  if (Common_gen_mother_idx_branch) Common_gen_mother_idx_branch->SetAddress(&Common_gen_mother_idx_);
  Common_gen_mother_id_branch = tree->GetBranch("Common_gen_mother_id");
  if (Common_gen_mother_id_branch) Common_gen_mother_id_branch->SetAddress(&Common_gen_mother_id_);
  Common_gen_pdgid_branch = tree->GetBranch("Common_gen_pdgid");
  if (Common_gen_pdgid_branch) Common_gen_pdgid_branch->SetAddress(&Common_gen_pdgid_);
  Common_gen_vvvdecay_idx_branch = tree->GetBranch("Common_gen_vvvdecay_idx");
  if (Common_gen_vvvdecay_idx_branch) Common_gen_vvvdecay_idx_branch->SetAddress(&Common_gen_vvvdecay_idx_);
  Common_gen_vvvdecay_mother_idx_branch = tree->GetBranch("Common_gen_vvvdecay_mother_idx");
  if (Common_gen_vvvdecay_mother_idx_branch) Common_gen_vvvdecay_mother_idx_branch->SetAddress(&Common_gen_vvvdecay_mother_idx_);
  Common_gen_vvvdecay_mother_id_branch = tree->GetBranch("Common_gen_vvvdecay_mother_id");
  if (Common_gen_vvvdecay_mother_id_branch) Common_gen_vvvdecay_mother_id_branch->SetAddress(&Common_gen_vvvdecay_mother_id_);
  Common_gen_vvvdecay_pdgid_branch = tree->GetBranch("Common_gen_vvvdecay_pdgid");
  if (Common_gen_vvvdecay_pdgid_branch) Common_gen_vvvdecay_pdgid_branch->SetAddress(&Common_gen_vvvdecay_pdgid_);
  Common_gen_vvvdecay_taudecayid_branch = tree->GetBranch("Common_gen_vvvdecay_taudecayid");
  if (Common_gen_vvvdecay_taudecayid_branch) Common_gen_vvvdecay_taudecayid_branch->SetAddress(&Common_gen_vvvdecay_taudecayid_);
  Common_n_W_branch = tree->GetBranch("Common_n_W");
  if (Common_n_W_branch) Common_n_W_branch->SetAddress(&Common_n_W_);
  Common_n_Z_branch = tree->GetBranch("Common_n_Z");
  if (Common_n_Z_branch) Common_n_Z_branch->SetAddress(&Common_n_Z_);
  Common_n_lep_Z_branch = tree->GetBranch("Common_n_lep_Z");
  if (Common_n_lep_Z_branch) Common_n_lep_Z_branch->SetAddress(&Common_n_lep_Z_);
  Common_n_leptau_Z_branch = tree->GetBranch("Common_n_leptau_Z");
  if (Common_n_leptau_Z_branch) Common_n_leptau_Z_branch->SetAddress(&Common_n_leptau_Z_);
  Common_n_hadtau_Z_branch = tree->GetBranch("Common_n_hadtau_Z");
  if (Common_n_hadtau_Z_branch) Common_n_hadtau_Z_branch->SetAddress(&Common_n_hadtau_Z_);
  Common_n_nu_Z_branch = tree->GetBranch("Common_n_nu_Z");
  if (Common_n_nu_Z_branch) Common_n_nu_Z_branch->SetAddress(&Common_n_nu_Z_);
  Common_n_b_Z_branch = tree->GetBranch("Common_n_b_Z");
  if (Common_n_b_Z_branch) Common_n_b_Z_branch->SetAddress(&Common_n_b_Z_);
  Common_n_lep_W_branch = tree->GetBranch("Common_n_lep_W");
  if (Common_n_lep_W_branch) Common_n_lep_W_branch->SetAddress(&Common_n_lep_W_);
  Common_n_leptau_W_branch = tree->GetBranch("Common_n_leptau_W");
  if (Common_n_leptau_W_branch) Common_n_leptau_W_branch->SetAddress(&Common_n_leptau_W_);
  Common_n_hadtau_W_branch = tree->GetBranch("Common_n_hadtau_W");
  if (Common_n_hadtau_W_branch) Common_n_hadtau_W_branch->SetAddress(&Common_n_hadtau_W_);
  Common_haslepWSS_branch = tree->GetBranch("Common_haslepWSS");
  if (Common_haslepWSS_branch) Common_haslepWSS_branch->SetAddress(&Common_haslepWSS_);
  Common_genHT_branch = tree->GetBranch("Common_genHT");
  if (Common_genHT_branch) Common_genHT_branch->SetAddress(&Common_genHT_);
  Common_gen_n_light_lep_branch = tree->GetBranch("Common_gen_n_light_lep");
  if (Common_gen_n_light_lep_branch) Common_gen_n_light_lep_branch->SetAddress(&Common_gen_n_light_lep_);
  Cut_4LepMET_Preselection_branch = tree->GetBranch("Cut_4LepMET_Preselection");
  if (Cut_4LepMET_Preselection_branch) Cut_4LepMET_Preselection_branch->SetAddress(&Cut_4LepMET_Preselection_);
  Cut_4LepMET_emuChannel_branch = tree->GetBranch("Cut_4LepMET_emuChannel");
  if (Cut_4LepMET_emuChannel_branch) Cut_4LepMET_emuChannel_branch->SetAddress(&Cut_4LepMET_emuChannel_);
  Cut_4LepMET_offzChannel_branch = tree->GetBranch("Cut_4LepMET_offzChannel");
  if (Cut_4LepMET_offzChannel_branch) Cut_4LepMET_offzChannel_branch->SetAddress(&Cut_4LepMET_offzChannel_);
  Cut_4LepMET_onzChannel_branch = tree->GetBranch("Cut_4LepMET_onzChannel");
  if (Cut_4LepMET_onzChannel_branch) Cut_4LepMET_onzChannel_branch->SetAddress(&Cut_4LepMET_onzChannel_);
  Cut_4LepMET_onzChannel_HighMET_branch = tree->GetBranch("Cut_4LepMET_onzChannel_HighMET");
  if (Cut_4LepMET_onzChannel_HighMET_branch) Cut_4LepMET_onzChannel_HighMET_branch->SetAddress(&Cut_4LepMET_onzChannel_HighMET_);
  Var_4LepMET_Zcand_lep_idx_0_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_idx_0");
  if (Var_4LepMET_Zcand_lep_idx_0_branch) Var_4LepMET_Zcand_lep_idx_0_branch->SetAddress(&Var_4LepMET_Zcand_lep_idx_0_);
  Var_4LepMET_Zcand_lep_pdgid_0_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_pdgid_0");
  if (Var_4LepMET_Zcand_lep_pdgid_0_branch) Var_4LepMET_Zcand_lep_pdgid_0_branch->SetAddress(&Var_4LepMET_Zcand_lep_pdgid_0_);
  Var_4LepMET_Zcand_lep_idx_1_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_idx_1");
  if (Var_4LepMET_Zcand_lep_idx_1_branch) Var_4LepMET_Zcand_lep_idx_1_branch->SetAddress(&Var_4LepMET_Zcand_lep_idx_1_);
  Var_4LepMET_Zcand_lep_pdgid_1_branch = tree->GetBranch("Var_4LepMET_Zcand_lep_pdgid_1");
  if (Var_4LepMET_Zcand_lep_pdgid_1_branch) Var_4LepMET_Zcand_lep_pdgid_1_branch->SetAddress(&Var_4LepMET_Zcand_lep_pdgid_1_);
  Var_4LepMET_Zcand_mll_branch = tree->GetBranch("Var_4LepMET_Zcand_mll");
  if (Var_4LepMET_Zcand_mll_branch) Var_4LepMET_Zcand_mll_branch->SetAddress(&Var_4LepMET_Zcand_mll_);
  Var_4LepMET_other_lep_idx_0_branch = tree->GetBranch("Var_4LepMET_other_lep_idx_0");
  if (Var_4LepMET_other_lep_idx_0_branch) Var_4LepMET_other_lep_idx_0_branch->SetAddress(&Var_4LepMET_other_lep_idx_0_);
  Var_4LepMET_other_lep_pdgid_0_branch = tree->GetBranch("Var_4LepMET_other_lep_pdgid_0");
  if (Var_4LepMET_other_lep_pdgid_0_branch) Var_4LepMET_other_lep_pdgid_0_branch->SetAddress(&Var_4LepMET_other_lep_pdgid_0_);
  Var_4LepMET_other_lep_idx_1_branch = tree->GetBranch("Var_4LepMET_other_lep_idx_1");
  if (Var_4LepMET_other_lep_idx_1_branch) Var_4LepMET_other_lep_idx_1_branch->SetAddress(&Var_4LepMET_other_lep_idx_1_);
  Var_4LepMET_other_lep_pdgid_1_branch = tree->GetBranch("Var_4LepMET_other_lep_pdgid_1");
  if (Var_4LepMET_other_lep_pdgid_1_branch) Var_4LepMET_other_lep_pdgid_1_branch->SetAddress(&Var_4LepMET_other_lep_pdgid_1_);
  Var_4LepMET_other_mll_branch = tree->GetBranch("Var_4LepMET_other_mll");
  if (Var_4LepMET_other_mll_branch) Var_4LepMET_other_mll_branch->SetAddress(&Var_4LepMET_other_mll_);

  tree->SetMakeClass(0);
}

void VVVTree::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
  Common_isData_isLoaded = false;
  Common_run_isLoaded = false;
  Common_lumi_isLoaded = false;
  Common_evt_isLoaded = false;
  Common_genWeight_isLoaded = false;
  Common_btagWeight_DeepCSVB_isLoaded = false;
  Common_LHEWeight_mg_reweighting_isLoaded = false;
  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_isLoaded = false;
  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_isLoaded = false;
  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_isLoaded = false;
  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = false;
  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = false;
  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = false;
  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
  Common_HLT_DoubleEl_isLoaded = false;
  Common_HLT_MuEG_isLoaded = false;
  Common_HLT_DoubleMu_isLoaded = false;
  Common_pass_duplicate_removal_ee_em_mm_isLoaded = false;
  Common_pass_duplicate_removal_mm_em_ee_isLoaded = false;
  Common_noiseFlag_isLoaded = false;
  Common_noiseFlagMC_isLoaded = false;
  Common_met_p4_isLoaded = false;
  Common_event_lepSF_isLoaded = false;
  Common_event_lepSFelup_isLoaded = false;
  Common_event_lepSFeldn_isLoaded = false;
  Common_event_lepSFmuup_isLoaded = false;
  Common_event_lepSFmudn_isLoaded = false;
  Common_lep_p4_isLoaded = false;
  Common_lep_idxs_isLoaded = false;
  Common_lep_pdgid_isLoaded = false;
  Common_lep_tight_isLoaded = false;
  Common_lep_dxy_isLoaded = false;
  Common_lep_dz_isLoaded = false;
  Common_lep_SF_isLoaded = false;
  Common_lep_SFTight_isLoaded = false;
  Common_lep_SFdn_isLoaded = false;
  Common_lep_SFdnTight_isLoaded = false;
  Common_lep_SFup_isLoaded = false;
  Common_lep_SFupTight_isLoaded = false;
  Common_jet_p4_isLoaded = false;
  Common_jet_idxs_isLoaded = false;
  Common_jet_passBloose_isLoaded = false;
  Common_jet_passBmedium_isLoaded = false;
  Common_jet_passBtight_isLoaded = false;
  Common_jet_overlapfatjet_isLoaded = false;
  Common_fatjet_p4_isLoaded = false;
  Common_fatjet_idxs_isLoaded = false;
  Common_fatjet_msoftdrop_isLoaded = false;
  Common_fatjet_deepMD_W_isLoaded = false;
  Common_fatjet_deep_W_isLoaded = false;
  Common_fatjet_deepMD_Z_isLoaded = false;
  Common_fatjet_deep_Z_isLoaded = false;
  Common_fatjet_deepMD_T_isLoaded = false;
  Common_fatjet_deep_T_isLoaded = false;
  Common_fatjet_deepMD_bb_isLoaded = false;
  Common_fatjet_tau3_isLoaded = false;
  Common_fatjet_tau2_isLoaded = false;
  Common_fatjet_tau1_isLoaded = false;
  Common_fatjet_tau32_isLoaded = false;
  Common_fatjet_tau21_isLoaded = false;
  Common_fatjet_subjet0_pt_isLoaded = false;
  Common_fatjet_subjet0_eta_isLoaded = false;
  Common_fatjet_subjet0_phi_isLoaded = false;
  Common_fatjet_subjet0_mass_isLoaded = false;
  Common_fatjet_subjet1_pt_isLoaded = false;
  Common_fatjet_subjet1_eta_isLoaded = false;
  Common_fatjet_subjet1_phi_isLoaded = false;
  Common_fatjet_subjet1_mass_isLoaded = false;
  Common_fatjet_subjet0_p4_isLoaded = false;
  Common_fatjet_subjet1_p4_isLoaded = false;
  Common_fatjet_WP_isLoaded = false;
  Common_fatjet_WP_antimasscut_isLoaded = false;
  Common_fatjet_SFVLoose_isLoaded = false;
  Common_fatjet_SFLoose_isLoaded = false;
  Common_fatjet_SFMedium_isLoaded = false;
  Common_fatjet_SFTight_isLoaded = false;
  Common_fatjet_SFdnVLoose_isLoaded = false;
  Common_fatjet_SFdnLoose_isLoaded = false;
  Common_fatjet_SFdnMedium_isLoaded = false;
  Common_fatjet_SFdnTight_isLoaded = false;
  Common_fatjet_SFupVLoose_isLoaded = false;
  Common_fatjet_SFupLoose_isLoaded = false;
  Common_fatjet_SFupMedium_isLoaded = false;
  Common_fatjet_SFupTight_isLoaded = false;
  Common_eventweight_fatjet_SFVLoose_isLoaded = false;
  Common_eventweight_fatjet_SFLoose_isLoaded = false;
  Common_eventweight_fatjet_SFMedium_isLoaded = false;
  Common_eventweight_fatjet_SFTight_isLoaded = false;
  Common_eventweight_fatjet_SFdnVLoose_isLoaded = false;
  Common_eventweight_fatjet_SFdnLoose_isLoaded = false;
  Common_eventweight_fatjet_SFdnMedium_isLoaded = false;
  Common_eventweight_fatjet_SFdnTight_isLoaded = false;
  Common_eventweight_fatjet_SFupVLoose_isLoaded = false;
  Common_eventweight_fatjet_SFupLoose_isLoaded = false;
  Common_eventweight_fatjet_SFupMedium_isLoaded = false;
  Common_eventweight_fatjet_SFupTight_isLoaded = false;
  Common_nb_loose_isLoaded = false;
  Common_nb_medium_isLoaded = false;
  Common_nb_tight_isLoaded = false;
  Common_gen_idx_isLoaded = false;
  Common_gen_mother_idx_isLoaded = false;
  Common_gen_mother_id_isLoaded = false;
  Common_gen_pdgid_isLoaded = false;
  Common_gen_p4s_isLoaded = false;
  Common_gen_vvvdecay_idx_isLoaded = false;
  Common_gen_vvvdecay_mother_idx_isLoaded = false;
  Common_gen_vvvdecay_mother_id_isLoaded = false;
  Common_gen_vvvdecay_pdgid_isLoaded = false;
  Common_gen_vvvdecay_p4s_isLoaded = false;
  Common_gen_vvvdecay_taudecayid_isLoaded = false;
  Common_n_W_isLoaded = false;
  Common_n_Z_isLoaded = false;
  Common_n_lep_Z_isLoaded = false;
  Common_n_leptau_Z_isLoaded = false;
  Common_n_hadtau_Z_isLoaded = false;
  Common_n_nu_Z_isLoaded = false;
  Common_n_b_Z_isLoaded = false;
  Common_n_lep_W_isLoaded = false;
  Common_n_leptau_W_isLoaded = false;
  Common_n_hadtau_W_isLoaded = false;
  Common_haslepWSS_isLoaded = false;
  Common_genHT_isLoaded = false;
  Common_gen_n_light_lep_isLoaded = false;
  Cut_4LepMET_Preselection_isLoaded = false;
  Cut_4LepMET_emuChannel_isLoaded = false;
  Cut_4LepMET_offzChannel_isLoaded = false;
  Cut_4LepMET_onzChannel_isLoaded = false;
  Cut_4LepMET_onzChannel_HighMET_isLoaded = false;
  Var_4LepMET_Zcand_lep_idx_0_isLoaded = false;
  Var_4LepMET_Zcand_lep_pdgid_0_isLoaded = false;
  Var_4LepMET_Zcand_lep_p4_0_isLoaded = false;
  Var_4LepMET_Zcand_lep_idx_1_isLoaded = false;
  Var_4LepMET_Zcand_lep_pdgid_1_isLoaded = false;
  Var_4LepMET_Zcand_lep_p4_1_isLoaded = false;
  Var_4LepMET_Zcand_mll_isLoaded = false;
  Var_4LepMET_other_lep_idx_0_isLoaded = false;
  Var_4LepMET_other_lep_pdgid_0_isLoaded = false;
  Var_4LepMET_other_lep_p4_0_isLoaded = false;
  Var_4LepMET_other_lep_idx_1_isLoaded = false;
  Var_4LepMET_other_lep_pdgid_1_isLoaded = false;
  Var_4LepMET_other_lep_p4_1_isLoaded = false;
  Var_4LepMET_other_mll_isLoaded = false;
}

void VVVTree::LoadAllBranches() {
  // load all branches
  if (Common_isData_branch != 0) Common_isData();
  if (Common_run_branch != 0) Common_run();
  if (Common_lumi_branch != 0) Common_lumi();
  if (Common_evt_branch != 0) Common_evt();
  if (Common_genWeight_branch != 0) Common_genWeight();
  if (Common_btagWeight_DeepCSVB_branch != 0) Common_btagWeight_DeepCSVB();
  if (Common_LHEWeight_mg_reweighting_branch != 0) Common_LHEWeight_mg_reweighting();
  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch != 0) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ();
  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch != 0) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL();
  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch != 0) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8();
  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();
  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL();
  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();
  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL();
  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ();
  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch != 0) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL();
  if (Common_HLT_DoubleEl_branch != 0) Common_HLT_DoubleEl();
  if (Common_HLT_MuEG_branch != 0) Common_HLT_MuEG();
  if (Common_HLT_DoubleMu_branch != 0) Common_HLT_DoubleMu();
  if (Common_pass_duplicate_removal_ee_em_mm_branch != 0) Common_pass_duplicate_removal_ee_em_mm();
  if (Common_pass_duplicate_removal_mm_em_ee_branch != 0) Common_pass_duplicate_removal_mm_em_ee();
  if (Common_noiseFlag_branch != 0) Common_noiseFlag();
  if (Common_noiseFlagMC_branch != 0) Common_noiseFlagMC();
  if (Common_met_p4_branch != 0) Common_met_p4();
  if (Common_event_lepSF_branch != 0) Common_event_lepSF();
  if (Common_event_lepSFelup_branch != 0) Common_event_lepSFelup();
  if (Common_event_lepSFeldn_branch != 0) Common_event_lepSFeldn();
  if (Common_event_lepSFmuup_branch != 0) Common_event_lepSFmuup();
  if (Common_event_lepSFmudn_branch != 0) Common_event_lepSFmudn();
  if (Common_lep_p4_branch != 0) Common_lep_p4();
  if (Common_lep_idxs_branch != 0) Common_lep_idxs();
  if (Common_lep_pdgid_branch != 0) Common_lep_pdgid();
  if (Common_lep_tight_branch != 0) Common_lep_tight();
  if (Common_lep_dxy_branch != 0) Common_lep_dxy();
  if (Common_lep_dz_branch != 0) Common_lep_dz();
  if (Common_lep_SF_branch != 0) Common_lep_SF();
  if (Common_lep_SFTight_branch != 0) Common_lep_SFTight();
  if (Common_lep_SFdn_branch != 0) Common_lep_SFdn();
  if (Common_lep_SFdnTight_branch != 0) Common_lep_SFdnTight();
  if (Common_lep_SFup_branch != 0) Common_lep_SFup();
  if (Common_lep_SFupTight_branch != 0) Common_lep_SFupTight();
  if (Common_jet_p4_branch != 0) Common_jet_p4();
  if (Common_jet_idxs_branch != 0) Common_jet_idxs();
  if (Common_jet_passBloose_branch != 0) Common_jet_passBloose();
  if (Common_jet_passBmedium_branch != 0) Common_jet_passBmedium();
  if (Common_jet_passBtight_branch != 0) Common_jet_passBtight();
  if (Common_jet_overlapfatjet_branch != 0) Common_jet_overlapfatjet();
  if (Common_fatjet_p4_branch != 0) Common_fatjet_p4();
  if (Common_fatjet_idxs_branch != 0) Common_fatjet_idxs();
  if (Common_fatjet_msoftdrop_branch != 0) Common_fatjet_msoftdrop();
  if (Common_fatjet_deepMD_W_branch != 0) Common_fatjet_deepMD_W();
  if (Common_fatjet_deep_W_branch != 0) Common_fatjet_deep_W();
  if (Common_fatjet_deepMD_Z_branch != 0) Common_fatjet_deepMD_Z();
  if (Common_fatjet_deep_Z_branch != 0) Common_fatjet_deep_Z();
  if (Common_fatjet_deepMD_T_branch != 0) Common_fatjet_deepMD_T();
  if (Common_fatjet_deep_T_branch != 0) Common_fatjet_deep_T();
  if (Common_fatjet_deepMD_bb_branch != 0) Common_fatjet_deepMD_bb();
  if (Common_fatjet_tau3_branch != 0) Common_fatjet_tau3();
  if (Common_fatjet_tau2_branch != 0) Common_fatjet_tau2();
  if (Common_fatjet_tau1_branch != 0) Common_fatjet_tau1();
  if (Common_fatjet_tau32_branch != 0) Common_fatjet_tau32();
  if (Common_fatjet_tau21_branch != 0) Common_fatjet_tau21();
  if (Common_fatjet_subjet0_pt_branch != 0) Common_fatjet_subjet0_pt();
  if (Common_fatjet_subjet0_eta_branch != 0) Common_fatjet_subjet0_eta();
  if (Common_fatjet_subjet0_phi_branch != 0) Common_fatjet_subjet0_phi();
  if (Common_fatjet_subjet0_mass_branch != 0) Common_fatjet_subjet0_mass();
  if (Common_fatjet_subjet1_pt_branch != 0) Common_fatjet_subjet1_pt();
  if (Common_fatjet_subjet1_eta_branch != 0) Common_fatjet_subjet1_eta();
  if (Common_fatjet_subjet1_phi_branch != 0) Common_fatjet_subjet1_phi();
  if (Common_fatjet_subjet1_mass_branch != 0) Common_fatjet_subjet1_mass();
  if (Common_fatjet_subjet0_p4_branch != 0) Common_fatjet_subjet0_p4();
  if (Common_fatjet_subjet1_p4_branch != 0) Common_fatjet_subjet1_p4();
  if (Common_fatjet_WP_branch != 0) Common_fatjet_WP();
  if (Common_fatjet_WP_antimasscut_branch != 0) Common_fatjet_WP_antimasscut();
  if (Common_fatjet_SFVLoose_branch != 0) Common_fatjet_SFVLoose();
  if (Common_fatjet_SFLoose_branch != 0) Common_fatjet_SFLoose();
  if (Common_fatjet_SFMedium_branch != 0) Common_fatjet_SFMedium();
  if (Common_fatjet_SFTight_branch != 0) Common_fatjet_SFTight();
  if (Common_fatjet_SFdnVLoose_branch != 0) Common_fatjet_SFdnVLoose();
  if (Common_fatjet_SFdnLoose_branch != 0) Common_fatjet_SFdnLoose();
  if (Common_fatjet_SFdnMedium_branch != 0) Common_fatjet_SFdnMedium();
  if (Common_fatjet_SFdnTight_branch != 0) Common_fatjet_SFdnTight();
  if (Common_fatjet_SFupVLoose_branch != 0) Common_fatjet_SFupVLoose();
  if (Common_fatjet_SFupLoose_branch != 0) Common_fatjet_SFupLoose();
  if (Common_fatjet_SFupMedium_branch != 0) Common_fatjet_SFupMedium();
  if (Common_fatjet_SFupTight_branch != 0) Common_fatjet_SFupTight();
  if (Common_eventweight_fatjet_SFVLoose_branch != 0) Common_eventweight_fatjet_SFVLoose();
  if (Common_eventweight_fatjet_SFLoose_branch != 0) Common_eventweight_fatjet_SFLoose();
  if (Common_eventweight_fatjet_SFMedium_branch != 0) Common_eventweight_fatjet_SFMedium();
  if (Common_eventweight_fatjet_SFTight_branch != 0) Common_eventweight_fatjet_SFTight();
  if (Common_eventweight_fatjet_SFdnVLoose_branch != 0) Common_eventweight_fatjet_SFdnVLoose();
  if (Common_eventweight_fatjet_SFdnLoose_branch != 0) Common_eventweight_fatjet_SFdnLoose();
  if (Common_eventweight_fatjet_SFdnMedium_branch != 0) Common_eventweight_fatjet_SFdnMedium();
  if (Common_eventweight_fatjet_SFdnTight_branch != 0) Common_eventweight_fatjet_SFdnTight();
  if (Common_eventweight_fatjet_SFupVLoose_branch != 0) Common_eventweight_fatjet_SFupVLoose();
  if (Common_eventweight_fatjet_SFupLoose_branch != 0) Common_eventweight_fatjet_SFupLoose();
  if (Common_eventweight_fatjet_SFupMedium_branch != 0) Common_eventweight_fatjet_SFupMedium();
  if (Common_eventweight_fatjet_SFupTight_branch != 0) Common_eventweight_fatjet_SFupTight();
  if (Common_nb_loose_branch != 0) Common_nb_loose();
  if (Common_nb_medium_branch != 0) Common_nb_medium();
  if (Common_nb_tight_branch != 0) Common_nb_tight();
  if (Common_gen_idx_branch != 0) Common_gen_idx();
  if (Common_gen_mother_idx_branch != 0) Common_gen_mother_idx();
  if (Common_gen_mother_id_branch != 0) Common_gen_mother_id();
  if (Common_gen_pdgid_branch != 0) Common_gen_pdgid();
  if (Common_gen_p4s_branch != 0) Common_gen_p4s();
  if (Common_gen_vvvdecay_idx_branch != 0) Common_gen_vvvdecay_idx();
  if (Common_gen_vvvdecay_mother_idx_branch != 0) Common_gen_vvvdecay_mother_idx();
  if (Common_gen_vvvdecay_mother_id_branch != 0) Common_gen_vvvdecay_mother_id();
  if (Common_gen_vvvdecay_pdgid_branch != 0) Common_gen_vvvdecay_pdgid();
  if (Common_gen_vvvdecay_p4s_branch != 0) Common_gen_vvvdecay_p4s();
  if (Common_gen_vvvdecay_taudecayid_branch != 0) Common_gen_vvvdecay_taudecayid();
  if (Common_n_W_branch != 0) Common_n_W();
  if (Common_n_Z_branch != 0) Common_n_Z();
  if (Common_n_lep_Z_branch != 0) Common_n_lep_Z();
  if (Common_n_leptau_Z_branch != 0) Common_n_leptau_Z();
  if (Common_n_hadtau_Z_branch != 0) Common_n_hadtau_Z();
  if (Common_n_nu_Z_branch != 0) Common_n_nu_Z();
  if (Common_n_b_Z_branch != 0) Common_n_b_Z();
  if (Common_n_lep_W_branch != 0) Common_n_lep_W();
  if (Common_n_leptau_W_branch != 0) Common_n_leptau_W();
  if (Common_n_hadtau_W_branch != 0) Common_n_hadtau_W();
  if (Common_haslepWSS_branch != 0) Common_haslepWSS();
  if (Common_genHT_branch != 0) Common_genHT();
  if (Common_gen_n_light_lep_branch != 0) Common_gen_n_light_lep();
  if (Cut_4LepMET_Preselection_branch != 0) Cut_4LepMET_Preselection();
  if (Cut_4LepMET_emuChannel_branch != 0) Cut_4LepMET_emuChannel();
  if (Cut_4LepMET_offzChannel_branch != 0) Cut_4LepMET_offzChannel();
  if (Cut_4LepMET_onzChannel_branch != 0) Cut_4LepMET_onzChannel();
  if (Cut_4LepMET_onzChannel_HighMET_branch != 0) Cut_4LepMET_onzChannel_HighMET();
  if (Var_4LepMET_Zcand_lep_idx_0_branch != 0) Var_4LepMET_Zcand_lep_idx_0();
  if (Var_4LepMET_Zcand_lep_pdgid_0_branch != 0) Var_4LepMET_Zcand_lep_pdgid_0();
  if (Var_4LepMET_Zcand_lep_p4_0_branch != 0) Var_4LepMET_Zcand_lep_p4_0();
  if (Var_4LepMET_Zcand_lep_idx_1_branch != 0) Var_4LepMET_Zcand_lep_idx_1();
  if (Var_4LepMET_Zcand_lep_pdgid_1_branch != 0) Var_4LepMET_Zcand_lep_pdgid_1();
  if (Var_4LepMET_Zcand_lep_p4_1_branch != 0) Var_4LepMET_Zcand_lep_p4_1();
  if (Var_4LepMET_Zcand_mll_branch != 0) Var_4LepMET_Zcand_mll();
  if (Var_4LepMET_other_lep_idx_0_branch != 0) Var_4LepMET_other_lep_idx_0();
  if (Var_4LepMET_other_lep_pdgid_0_branch != 0) Var_4LepMET_other_lep_pdgid_0();
  if (Var_4LepMET_other_lep_p4_0_branch != 0) Var_4LepMET_other_lep_p4_0();
  if (Var_4LepMET_other_lep_idx_1_branch != 0) Var_4LepMET_other_lep_idx_1();
  if (Var_4LepMET_other_lep_pdgid_1_branch != 0) Var_4LepMET_other_lep_pdgid_1();
  if (Var_4LepMET_other_lep_p4_1_branch != 0) Var_4LepMET_other_lep_p4_1();
  if (Var_4LepMET_other_mll_branch != 0) Var_4LepMET_other_mll();
}

const int &VVVTree::Common_isData() {
  if (not Common_isData_isLoaded) {
    if (Common_isData_branch != 0) {
      Common_isData_branch->GetEntry(index);
    } else {
      printf("branch Common_isData_branch does not exist!\n");
      exit(1);
    }
    Common_isData_isLoaded = true;
  }
  return Common_isData_;
}

const int &VVVTree::Common_run() {
  if (not Common_run_isLoaded) {
    if (Common_run_branch != 0) {
      Common_run_branch->GetEntry(index);
    } else {
      printf("branch Common_run_branch does not exist!\n");
      exit(1);
    }
    Common_run_isLoaded = true;
  }
  return Common_run_;
}

const int &VVVTree::Common_lumi() {
  if (not Common_lumi_isLoaded) {
    if (Common_lumi_branch != 0) {
      Common_lumi_branch->GetEntry(index);
    } else {
      printf("branch Common_lumi_branch does not exist!\n");
      exit(1);
    }
    Common_lumi_isLoaded = true;
  }
  return Common_lumi_;
}

const unsigned long long &VVVTree::Common_evt() {
  if (not Common_evt_isLoaded) {
    if (Common_evt_branch != 0) {
      Common_evt_branch->GetEntry(index);
    } else {
      printf("branch Common_evt_branch does not exist!\n");
      exit(1);
    }
    Common_evt_isLoaded = true;
  }
  return Common_evt_;
}

const float &VVVTree::Common_genWeight() {
  if (not Common_genWeight_isLoaded) {
    if (Common_genWeight_branch != 0) {
      Common_genWeight_branch->GetEntry(index);
    } else {
      printf("branch Common_genWeight_branch does not exist!\n");
      exit(1);
    }
    Common_genWeight_isLoaded = true;
  }
  return Common_genWeight_;
}

const float &VVVTree::Common_btagWeight_DeepCSVB() {
  if (not Common_btagWeight_DeepCSVB_isLoaded) {
    if (Common_btagWeight_DeepCSVB_branch != 0) {
      Common_btagWeight_DeepCSVB_branch->GetEntry(index);
    } else {
      printf("branch Common_btagWeight_DeepCSVB_branch does not exist!\n");
      exit(1);
    }
    Common_btagWeight_DeepCSVB_isLoaded = true;
  }
  return Common_btagWeight_DeepCSVB_;
}

const vector<float> &VVVTree::Common_LHEWeight_mg_reweighting() {
  if (not Common_LHEWeight_mg_reweighting_isLoaded) {
    if (Common_LHEWeight_mg_reweighting_branch != 0) {
      Common_LHEWeight_mg_reweighting_branch->GetEntry(index);
    } else {
      printf("branch Common_LHEWeight_mg_reweighting_branch does not exist!\n");
      exit(1);
    }
    Common_LHEWeight_mg_reweighting_isLoaded = true;
  }
  return *Common_LHEWeight_mg_reweighting_;
}

const bool &VVVTree::Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ() {
  if (not Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_isLoaded) {
    if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch != 0) {
      Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_isLoaded = true;
  }
  return Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_;
}

const bool &VVVTree::Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL() {
  if (not Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_isLoaded) {
    if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch != 0) {
      Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_isLoaded = true;
  }
  return Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_;
}

const bool &VVVTree::Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8() {
  if (not Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_isLoaded) {
    if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch != 0) {
      Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_isLoaded = true;
  }
  return Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_;
}

const bool &VVVTree::Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() {
  if (not Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded) {
    if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) {
      Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = true;
  }
  return Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_;
}

const bool &VVVTree::Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL() {
  if (not Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded) {
    if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) {
      Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = true;
  }
  return Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_;
}

const bool &VVVTree::Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() {
  if (not Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded) {
    if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) {
      Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = true;
  }
  return Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_;
}

const bool &VVVTree::Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL() {
  if (not Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded) {
    if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) {
      Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = true;
  }
  return Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_;
}

const bool &VVVTree::Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ() {
  if (not Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded) {
    if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) {
      Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = true;
  }
  return Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_;
}

const bool &VVVTree::Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL() {
  if (not Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_isLoaded) {
    if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch != 0) {
      Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_isLoaded = true;
  }
  return Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_;
}

const bool &VVVTree::Common_HLT_DoubleEl() {
  if (not Common_HLT_DoubleEl_isLoaded) {
    if (Common_HLT_DoubleEl_branch != 0) {
      Common_HLT_DoubleEl_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_DoubleEl_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_DoubleEl_isLoaded = true;
  }
  return Common_HLT_DoubleEl_;
}

const bool &VVVTree::Common_HLT_MuEG() {
  if (not Common_HLT_MuEG_isLoaded) {
    if (Common_HLT_MuEG_branch != 0) {
      Common_HLT_MuEG_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_MuEG_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_MuEG_isLoaded = true;
  }
  return Common_HLT_MuEG_;
}

const bool &VVVTree::Common_HLT_DoubleMu() {
  if (not Common_HLT_DoubleMu_isLoaded) {
    if (Common_HLT_DoubleMu_branch != 0) {
      Common_HLT_DoubleMu_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_DoubleMu_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_DoubleMu_isLoaded = true;
  }
  return Common_HLT_DoubleMu_;
}

const bool &VVVTree::Common_pass_duplicate_removal_ee_em_mm() {
  if (not Common_pass_duplicate_removal_ee_em_mm_isLoaded) {
    if (Common_pass_duplicate_removal_ee_em_mm_branch != 0) {
      Common_pass_duplicate_removal_ee_em_mm_branch->GetEntry(index);
    } else {
      printf("branch Common_pass_duplicate_removal_ee_em_mm_branch does not exist!\n");
      exit(1);
    }
    Common_pass_duplicate_removal_ee_em_mm_isLoaded = true;
  }
  return Common_pass_duplicate_removal_ee_em_mm_;
}

const bool &VVVTree::Common_pass_duplicate_removal_mm_em_ee() {
  if (not Common_pass_duplicate_removal_mm_em_ee_isLoaded) {
    if (Common_pass_duplicate_removal_mm_em_ee_branch != 0) {
      Common_pass_duplicate_removal_mm_em_ee_branch->GetEntry(index);
    } else {
      printf("branch Common_pass_duplicate_removal_mm_em_ee_branch does not exist!\n");
      exit(1);
    }
    Common_pass_duplicate_removal_mm_em_ee_isLoaded = true;
  }
  return Common_pass_duplicate_removal_mm_em_ee_;
}

const bool &VVVTree::Common_noiseFlag() {
  if (not Common_noiseFlag_isLoaded) {
    if (Common_noiseFlag_branch != 0) {
      Common_noiseFlag_branch->GetEntry(index);
    } else {
      printf("branch Common_noiseFlag_branch does not exist!\n");
      exit(1);
    }
    Common_noiseFlag_isLoaded = true;
  }
  return Common_noiseFlag_;
}

const bool &VVVTree::Common_noiseFlagMC() {
  if (not Common_noiseFlagMC_isLoaded) {
    if (Common_noiseFlagMC_branch != 0) {
      Common_noiseFlagMC_branch->GetEntry(index);
    } else {
      printf("branch Common_noiseFlagMC_branch does not exist!\n");
      exit(1);
    }
    Common_noiseFlagMC_isLoaded = true;
  }
  return Common_noiseFlagMC_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Common_met_p4() {
  if (not Common_met_p4_isLoaded) {
    if (Common_met_p4_branch != 0) {
      Common_met_p4_branch->GetEntry(index);
    } else {
      printf("branch Common_met_p4_branch does not exist!\n");
      exit(1);
    }
    Common_met_p4_isLoaded = true;
  }
  return *Common_met_p4_;
}

const float &VVVTree::Common_event_lepSF() {
  if (not Common_event_lepSF_isLoaded) {
    if (Common_event_lepSF_branch != 0) {
      Common_event_lepSF_branch->GetEntry(index);
    } else {
      printf("branch Common_event_lepSF_branch does not exist!\n");
      exit(1);
    }
    Common_event_lepSF_isLoaded = true;
  }
  return Common_event_lepSF_;
}

const float &VVVTree::Common_event_lepSFelup() {
  if (not Common_event_lepSFelup_isLoaded) {
    if (Common_event_lepSFelup_branch != 0) {
      Common_event_lepSFelup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_lepSFelup_branch does not exist!\n");
      exit(1);
    }
    Common_event_lepSFelup_isLoaded = true;
  }
  return Common_event_lepSFelup_;
}

const float &VVVTree::Common_event_lepSFeldn() {
  if (not Common_event_lepSFeldn_isLoaded) {
    if (Common_event_lepSFeldn_branch != 0) {
      Common_event_lepSFeldn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_lepSFeldn_branch does not exist!\n");
      exit(1);
    }
    Common_event_lepSFeldn_isLoaded = true;
  }
  return Common_event_lepSFeldn_;
}

const float &VVVTree::Common_event_lepSFmuup() {
  if (not Common_event_lepSFmuup_isLoaded) {
    if (Common_event_lepSFmuup_branch != 0) {
      Common_event_lepSFmuup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_lepSFmuup_branch does not exist!\n");
      exit(1);
    }
    Common_event_lepSFmuup_isLoaded = true;
  }
  return Common_event_lepSFmuup_;
}

const float &VVVTree::Common_event_lepSFmudn() {
  if (not Common_event_lepSFmudn_isLoaded) {
    if (Common_event_lepSFmudn_branch != 0) {
      Common_event_lepSFmudn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_lepSFmudn_branch does not exist!\n");
      exit(1);
    }
    Common_event_lepSFmudn_isLoaded = true;
  }
  return Common_event_lepSFmudn_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_lep_p4() {
  if (not Common_lep_p4_isLoaded) {
    if (Common_lep_p4_branch != 0) {
      Common_lep_p4_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_p4_branch does not exist!\n");
      exit(1);
    }
    Common_lep_p4_isLoaded = true;
  }
  return *Common_lep_p4_;
}

const vector<int> &VVVTree::Common_lep_idxs() {
  if (not Common_lep_idxs_isLoaded) {
    if (Common_lep_idxs_branch != 0) {
      Common_lep_idxs_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_idxs_branch does not exist!\n");
      exit(1);
    }
    Common_lep_idxs_isLoaded = true;
  }
  return *Common_lep_idxs_;
}

const vector<int> &VVVTree::Common_lep_pdgid() {
  if (not Common_lep_pdgid_isLoaded) {
    if (Common_lep_pdgid_branch != 0) {
      Common_lep_pdgid_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_pdgid_branch does not exist!\n");
      exit(1);
    }
    Common_lep_pdgid_isLoaded = true;
  }
  return *Common_lep_pdgid_;
}

const vector<int> &VVVTree::Common_lep_tight() {
  if (not Common_lep_tight_isLoaded) {
    if (Common_lep_tight_branch != 0) {
      Common_lep_tight_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_tight_branch does not exist!\n");
      exit(1);
    }
    Common_lep_tight_isLoaded = true;
  }
  return *Common_lep_tight_;
}

const vector<float> &VVVTree::Common_lep_dxy() {
  if (not Common_lep_dxy_isLoaded) {
    if (Common_lep_dxy_branch != 0) {
      Common_lep_dxy_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_dxy_branch does not exist!\n");
      exit(1);
    }
    Common_lep_dxy_isLoaded = true;
  }
  return *Common_lep_dxy_;
}

const vector<float> &VVVTree::Common_lep_dz() {
  if (not Common_lep_dz_isLoaded) {
    if (Common_lep_dz_branch != 0) {
      Common_lep_dz_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_dz_branch does not exist!\n");
      exit(1);
    }
    Common_lep_dz_isLoaded = true;
  }
  return *Common_lep_dz_;
}

const vector<float> &VVVTree::Common_lep_SF() {
  if (not Common_lep_SF_isLoaded) {
    if (Common_lep_SF_branch != 0) {
      Common_lep_SF_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_SF_branch does not exist!\n");
      exit(1);
    }
    Common_lep_SF_isLoaded = true;
  }
  return *Common_lep_SF_;
}

const vector<float> &VVVTree::Common_lep_SFTight() {
  if (not Common_lep_SFTight_isLoaded) {
    if (Common_lep_SFTight_branch != 0) {
      Common_lep_SFTight_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_SFTight_branch does not exist!\n");
      exit(1);
    }
    Common_lep_SFTight_isLoaded = true;
  }
  return *Common_lep_SFTight_;
}

const vector<float> &VVVTree::Common_lep_SFdn() {
  if (not Common_lep_SFdn_isLoaded) {
    if (Common_lep_SFdn_branch != 0) {
      Common_lep_SFdn_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_SFdn_branch does not exist!\n");
      exit(1);
    }
    Common_lep_SFdn_isLoaded = true;
  }
  return *Common_lep_SFdn_;
}

const vector<float> &VVVTree::Common_lep_SFdnTight() {
  if (not Common_lep_SFdnTight_isLoaded) {
    if (Common_lep_SFdnTight_branch != 0) {
      Common_lep_SFdnTight_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_SFdnTight_branch does not exist!\n");
      exit(1);
    }
    Common_lep_SFdnTight_isLoaded = true;
  }
  return *Common_lep_SFdnTight_;
}

const vector<float> &VVVTree::Common_lep_SFup() {
  if (not Common_lep_SFup_isLoaded) {
    if (Common_lep_SFup_branch != 0) {
      Common_lep_SFup_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_SFup_branch does not exist!\n");
      exit(1);
    }
    Common_lep_SFup_isLoaded = true;
  }
  return *Common_lep_SFup_;
}

const vector<float> &VVVTree::Common_lep_SFupTight() {
  if (not Common_lep_SFupTight_isLoaded) {
    if (Common_lep_SFupTight_branch != 0) {
      Common_lep_SFupTight_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_SFupTight_branch does not exist!\n");
      exit(1);
    }
    Common_lep_SFupTight_isLoaded = true;
  }
  return *Common_lep_SFupTight_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_jet_p4() {
  if (not Common_jet_p4_isLoaded) {
    if (Common_jet_p4_branch != 0) {
      Common_jet_p4_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_p4_branch does not exist!\n");
      exit(1);
    }
    Common_jet_p4_isLoaded = true;
  }
  return *Common_jet_p4_;
}

const vector<int> &VVVTree::Common_jet_idxs() {
  if (not Common_jet_idxs_isLoaded) {
    if (Common_jet_idxs_branch != 0) {
      Common_jet_idxs_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_idxs_branch does not exist!\n");
      exit(1);
    }
    Common_jet_idxs_isLoaded = true;
  }
  return *Common_jet_idxs_;
}

const vector<bool> &VVVTree::Common_jet_passBloose() {
  if (not Common_jet_passBloose_isLoaded) {
    if (Common_jet_passBloose_branch != 0) {
      Common_jet_passBloose_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_passBloose_branch does not exist!\n");
      exit(1);
    }
    Common_jet_passBloose_isLoaded = true;
  }
  return *Common_jet_passBloose_;
}

const vector<bool> &VVVTree::Common_jet_passBmedium() {
  if (not Common_jet_passBmedium_isLoaded) {
    if (Common_jet_passBmedium_branch != 0) {
      Common_jet_passBmedium_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_passBmedium_branch does not exist!\n");
      exit(1);
    }
    Common_jet_passBmedium_isLoaded = true;
  }
  return *Common_jet_passBmedium_;
}

const vector<bool> &VVVTree::Common_jet_passBtight() {
  if (not Common_jet_passBtight_isLoaded) {
    if (Common_jet_passBtight_branch != 0) {
      Common_jet_passBtight_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_passBtight_branch does not exist!\n");
      exit(1);
    }
    Common_jet_passBtight_isLoaded = true;
  }
  return *Common_jet_passBtight_;
}

const vector<int> &VVVTree::Common_jet_overlapfatjet() {
  if (not Common_jet_overlapfatjet_isLoaded) {
    if (Common_jet_overlapfatjet_branch != 0) {
      Common_jet_overlapfatjet_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_overlapfatjet_branch does not exist!\n");
      exit(1);
    }
    Common_jet_overlapfatjet_isLoaded = true;
  }
  return *Common_jet_overlapfatjet_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_fatjet_p4() {
  if (not Common_fatjet_p4_isLoaded) {
    if (Common_fatjet_p4_branch != 0) {
      Common_fatjet_p4_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_p4_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_p4_isLoaded = true;
  }
  return *Common_fatjet_p4_;
}

const vector<int> &VVVTree::Common_fatjet_idxs() {
  if (not Common_fatjet_idxs_isLoaded) {
    if (Common_fatjet_idxs_branch != 0) {
      Common_fatjet_idxs_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_idxs_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_idxs_isLoaded = true;
  }
  return *Common_fatjet_idxs_;
}

const vector<float> &VVVTree::Common_fatjet_msoftdrop() {
  if (not Common_fatjet_msoftdrop_isLoaded) {
    if (Common_fatjet_msoftdrop_branch != 0) {
      Common_fatjet_msoftdrop_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_msoftdrop_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_msoftdrop_isLoaded = true;
  }
  return *Common_fatjet_msoftdrop_;
}

const vector<float> &VVVTree::Common_fatjet_deepMD_W() {
  if (not Common_fatjet_deepMD_W_isLoaded) {
    if (Common_fatjet_deepMD_W_branch != 0) {
      Common_fatjet_deepMD_W_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_deepMD_W_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_deepMD_W_isLoaded = true;
  }
  return *Common_fatjet_deepMD_W_;
}

const vector<float> &VVVTree::Common_fatjet_deep_W() {
  if (not Common_fatjet_deep_W_isLoaded) {
    if (Common_fatjet_deep_W_branch != 0) {
      Common_fatjet_deep_W_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_deep_W_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_deep_W_isLoaded = true;
  }
  return *Common_fatjet_deep_W_;
}

const vector<float> &VVVTree::Common_fatjet_deepMD_Z() {
  if (not Common_fatjet_deepMD_Z_isLoaded) {
    if (Common_fatjet_deepMD_Z_branch != 0) {
      Common_fatjet_deepMD_Z_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_deepMD_Z_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_deepMD_Z_isLoaded = true;
  }
  return *Common_fatjet_deepMD_Z_;
}

const vector<float> &VVVTree::Common_fatjet_deep_Z() {
  if (not Common_fatjet_deep_Z_isLoaded) {
    if (Common_fatjet_deep_Z_branch != 0) {
      Common_fatjet_deep_Z_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_deep_Z_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_deep_Z_isLoaded = true;
  }
  return *Common_fatjet_deep_Z_;
}

const vector<float> &VVVTree::Common_fatjet_deepMD_T() {
  if (not Common_fatjet_deepMD_T_isLoaded) {
    if (Common_fatjet_deepMD_T_branch != 0) {
      Common_fatjet_deepMD_T_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_deepMD_T_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_deepMD_T_isLoaded = true;
  }
  return *Common_fatjet_deepMD_T_;
}

const vector<float> &VVVTree::Common_fatjet_deep_T() {
  if (not Common_fatjet_deep_T_isLoaded) {
    if (Common_fatjet_deep_T_branch != 0) {
      Common_fatjet_deep_T_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_deep_T_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_deep_T_isLoaded = true;
  }
  return *Common_fatjet_deep_T_;
}

const vector<float> &VVVTree::Common_fatjet_deepMD_bb() {
  if (not Common_fatjet_deepMD_bb_isLoaded) {
    if (Common_fatjet_deepMD_bb_branch != 0) {
      Common_fatjet_deepMD_bb_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_deepMD_bb_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_deepMD_bb_isLoaded = true;
  }
  return *Common_fatjet_deepMD_bb_;
}

const vector<float> &VVVTree::Common_fatjet_tau3() {
  if (not Common_fatjet_tau3_isLoaded) {
    if (Common_fatjet_tau3_branch != 0) {
      Common_fatjet_tau3_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_tau3_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_tau3_isLoaded = true;
  }
  return *Common_fatjet_tau3_;
}

const vector<float> &VVVTree::Common_fatjet_tau2() {
  if (not Common_fatjet_tau2_isLoaded) {
    if (Common_fatjet_tau2_branch != 0) {
      Common_fatjet_tau2_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_tau2_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_tau2_isLoaded = true;
  }
  return *Common_fatjet_tau2_;
}

const vector<float> &VVVTree::Common_fatjet_tau1() {
  if (not Common_fatjet_tau1_isLoaded) {
    if (Common_fatjet_tau1_branch != 0) {
      Common_fatjet_tau1_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_tau1_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_tau1_isLoaded = true;
  }
  return *Common_fatjet_tau1_;
}

const vector<float> &VVVTree::Common_fatjet_tau32() {
  if (not Common_fatjet_tau32_isLoaded) {
    if (Common_fatjet_tau32_branch != 0) {
      Common_fatjet_tau32_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_tau32_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_tau32_isLoaded = true;
  }
  return *Common_fatjet_tau32_;
}

const vector<float> &VVVTree::Common_fatjet_tau21() {
  if (not Common_fatjet_tau21_isLoaded) {
    if (Common_fatjet_tau21_branch != 0) {
      Common_fatjet_tau21_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_tau21_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_tau21_isLoaded = true;
  }
  return *Common_fatjet_tau21_;
}

const vector<float> &VVVTree::Common_fatjet_subjet0_pt() {
  if (not Common_fatjet_subjet0_pt_isLoaded) {
    if (Common_fatjet_subjet0_pt_branch != 0) {
      Common_fatjet_subjet0_pt_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_subjet0_pt_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_subjet0_pt_isLoaded = true;
  }
  return *Common_fatjet_subjet0_pt_;
}

const vector<float> &VVVTree::Common_fatjet_subjet0_eta() {
  if (not Common_fatjet_subjet0_eta_isLoaded) {
    if (Common_fatjet_subjet0_eta_branch != 0) {
      Common_fatjet_subjet0_eta_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_subjet0_eta_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_subjet0_eta_isLoaded = true;
  }
  return *Common_fatjet_subjet0_eta_;
}

const vector<float> &VVVTree::Common_fatjet_subjet0_phi() {
  if (not Common_fatjet_subjet0_phi_isLoaded) {
    if (Common_fatjet_subjet0_phi_branch != 0) {
      Common_fatjet_subjet0_phi_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_subjet0_phi_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_subjet0_phi_isLoaded = true;
  }
  return *Common_fatjet_subjet0_phi_;
}

const vector<float> &VVVTree::Common_fatjet_subjet0_mass() {
  if (not Common_fatjet_subjet0_mass_isLoaded) {
    if (Common_fatjet_subjet0_mass_branch != 0) {
      Common_fatjet_subjet0_mass_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_subjet0_mass_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_subjet0_mass_isLoaded = true;
  }
  return *Common_fatjet_subjet0_mass_;
}

const vector<float> &VVVTree::Common_fatjet_subjet1_pt() {
  if (not Common_fatjet_subjet1_pt_isLoaded) {
    if (Common_fatjet_subjet1_pt_branch != 0) {
      Common_fatjet_subjet1_pt_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_subjet1_pt_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_subjet1_pt_isLoaded = true;
  }
  return *Common_fatjet_subjet1_pt_;
}

const vector<float> &VVVTree::Common_fatjet_subjet1_eta() {
  if (not Common_fatjet_subjet1_eta_isLoaded) {
    if (Common_fatjet_subjet1_eta_branch != 0) {
      Common_fatjet_subjet1_eta_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_subjet1_eta_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_subjet1_eta_isLoaded = true;
  }
  return *Common_fatjet_subjet1_eta_;
}

const vector<float> &VVVTree::Common_fatjet_subjet1_phi() {
  if (not Common_fatjet_subjet1_phi_isLoaded) {
    if (Common_fatjet_subjet1_phi_branch != 0) {
      Common_fatjet_subjet1_phi_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_subjet1_phi_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_subjet1_phi_isLoaded = true;
  }
  return *Common_fatjet_subjet1_phi_;
}

const vector<float> &VVVTree::Common_fatjet_subjet1_mass() {
  if (not Common_fatjet_subjet1_mass_isLoaded) {
    if (Common_fatjet_subjet1_mass_branch != 0) {
      Common_fatjet_subjet1_mass_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_subjet1_mass_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_subjet1_mass_isLoaded = true;
  }
  return *Common_fatjet_subjet1_mass_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_fatjet_subjet0_p4() {
  if (not Common_fatjet_subjet0_p4_isLoaded) {
    if (Common_fatjet_subjet0_p4_branch != 0) {
      Common_fatjet_subjet0_p4_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_subjet0_p4_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_subjet0_p4_isLoaded = true;
  }
  return *Common_fatjet_subjet0_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_fatjet_subjet1_p4() {
  if (not Common_fatjet_subjet1_p4_isLoaded) {
    if (Common_fatjet_subjet1_p4_branch != 0) {
      Common_fatjet_subjet1_p4_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_subjet1_p4_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_subjet1_p4_isLoaded = true;
  }
  return *Common_fatjet_subjet1_p4_;
}

const vector<int> &VVVTree::Common_fatjet_WP() {
  if (not Common_fatjet_WP_isLoaded) {
    if (Common_fatjet_WP_branch != 0) {
      Common_fatjet_WP_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_WP_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_WP_isLoaded = true;
  }
  return *Common_fatjet_WP_;
}

const vector<int> &VVVTree::Common_fatjet_WP_antimasscut() {
  if (not Common_fatjet_WP_antimasscut_isLoaded) {
    if (Common_fatjet_WP_antimasscut_branch != 0) {
      Common_fatjet_WP_antimasscut_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_WP_antimasscut_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_WP_antimasscut_isLoaded = true;
  }
  return *Common_fatjet_WP_antimasscut_;
}

const vector<float> &VVVTree::Common_fatjet_SFVLoose() {
  if (not Common_fatjet_SFVLoose_isLoaded) {
    if (Common_fatjet_SFVLoose_branch != 0) {
      Common_fatjet_SFVLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_SFVLoose_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_SFVLoose_isLoaded = true;
  }
  return *Common_fatjet_SFVLoose_;
}

const vector<float> &VVVTree::Common_fatjet_SFLoose() {
  if (not Common_fatjet_SFLoose_isLoaded) {
    if (Common_fatjet_SFLoose_branch != 0) {
      Common_fatjet_SFLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_SFLoose_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_SFLoose_isLoaded = true;
  }
  return *Common_fatjet_SFLoose_;
}

const vector<float> &VVVTree::Common_fatjet_SFMedium() {
  if (not Common_fatjet_SFMedium_isLoaded) {
    if (Common_fatjet_SFMedium_branch != 0) {
      Common_fatjet_SFMedium_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_SFMedium_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_SFMedium_isLoaded = true;
  }
  return *Common_fatjet_SFMedium_;
}

const vector<float> &VVVTree::Common_fatjet_SFTight() {
  if (not Common_fatjet_SFTight_isLoaded) {
    if (Common_fatjet_SFTight_branch != 0) {
      Common_fatjet_SFTight_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_SFTight_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_SFTight_isLoaded = true;
  }
  return *Common_fatjet_SFTight_;
}

const vector<float> &VVVTree::Common_fatjet_SFdnVLoose() {
  if (not Common_fatjet_SFdnVLoose_isLoaded) {
    if (Common_fatjet_SFdnVLoose_branch != 0) {
      Common_fatjet_SFdnVLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_SFdnVLoose_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_SFdnVLoose_isLoaded = true;
  }
  return *Common_fatjet_SFdnVLoose_;
}

const vector<float> &VVVTree::Common_fatjet_SFdnLoose() {
  if (not Common_fatjet_SFdnLoose_isLoaded) {
    if (Common_fatjet_SFdnLoose_branch != 0) {
      Common_fatjet_SFdnLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_SFdnLoose_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_SFdnLoose_isLoaded = true;
  }
  return *Common_fatjet_SFdnLoose_;
}

const vector<float> &VVVTree::Common_fatjet_SFdnMedium() {
  if (not Common_fatjet_SFdnMedium_isLoaded) {
    if (Common_fatjet_SFdnMedium_branch != 0) {
      Common_fatjet_SFdnMedium_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_SFdnMedium_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_SFdnMedium_isLoaded = true;
  }
  return *Common_fatjet_SFdnMedium_;
}

const vector<float> &VVVTree::Common_fatjet_SFdnTight() {
  if (not Common_fatjet_SFdnTight_isLoaded) {
    if (Common_fatjet_SFdnTight_branch != 0) {
      Common_fatjet_SFdnTight_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_SFdnTight_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_SFdnTight_isLoaded = true;
  }
  return *Common_fatjet_SFdnTight_;
}

const vector<float> &VVVTree::Common_fatjet_SFupVLoose() {
  if (not Common_fatjet_SFupVLoose_isLoaded) {
    if (Common_fatjet_SFupVLoose_branch != 0) {
      Common_fatjet_SFupVLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_SFupVLoose_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_SFupVLoose_isLoaded = true;
  }
  return *Common_fatjet_SFupVLoose_;
}

const vector<float> &VVVTree::Common_fatjet_SFupLoose() {
  if (not Common_fatjet_SFupLoose_isLoaded) {
    if (Common_fatjet_SFupLoose_branch != 0) {
      Common_fatjet_SFupLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_SFupLoose_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_SFupLoose_isLoaded = true;
  }
  return *Common_fatjet_SFupLoose_;
}

const vector<float> &VVVTree::Common_fatjet_SFupMedium() {
  if (not Common_fatjet_SFupMedium_isLoaded) {
    if (Common_fatjet_SFupMedium_branch != 0) {
      Common_fatjet_SFupMedium_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_SFupMedium_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_SFupMedium_isLoaded = true;
  }
  return *Common_fatjet_SFupMedium_;
}

const vector<float> &VVVTree::Common_fatjet_SFupTight() {
  if (not Common_fatjet_SFupTight_isLoaded) {
    if (Common_fatjet_SFupTight_branch != 0) {
      Common_fatjet_SFupTight_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_SFupTight_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_SFupTight_isLoaded = true;
  }
  return *Common_fatjet_SFupTight_;
}

const float &VVVTree::Common_eventweight_fatjet_SFVLoose() {
  if (not Common_eventweight_fatjet_SFVLoose_isLoaded) {
    if (Common_eventweight_fatjet_SFVLoose_branch != 0) {
      Common_eventweight_fatjet_SFVLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_SFVLoose_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_SFVLoose_isLoaded = true;
  }
  return Common_eventweight_fatjet_SFVLoose_;
}

const float &VVVTree::Common_eventweight_fatjet_SFLoose() {
  if (not Common_eventweight_fatjet_SFLoose_isLoaded) {
    if (Common_eventweight_fatjet_SFLoose_branch != 0) {
      Common_eventweight_fatjet_SFLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_SFLoose_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_SFLoose_isLoaded = true;
  }
  return Common_eventweight_fatjet_SFLoose_;
}

const float &VVVTree::Common_eventweight_fatjet_SFMedium() {
  if (not Common_eventweight_fatjet_SFMedium_isLoaded) {
    if (Common_eventweight_fatjet_SFMedium_branch != 0) {
      Common_eventweight_fatjet_SFMedium_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_SFMedium_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_SFMedium_isLoaded = true;
  }
  return Common_eventweight_fatjet_SFMedium_;
}

const float &VVVTree::Common_eventweight_fatjet_SFTight() {
  if (not Common_eventweight_fatjet_SFTight_isLoaded) {
    if (Common_eventweight_fatjet_SFTight_branch != 0) {
      Common_eventweight_fatjet_SFTight_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_SFTight_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_SFTight_isLoaded = true;
  }
  return Common_eventweight_fatjet_SFTight_;
}

const float &VVVTree::Common_eventweight_fatjet_SFdnVLoose() {
  if (not Common_eventweight_fatjet_SFdnVLoose_isLoaded) {
    if (Common_eventweight_fatjet_SFdnVLoose_branch != 0) {
      Common_eventweight_fatjet_SFdnVLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_SFdnVLoose_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_SFdnVLoose_isLoaded = true;
  }
  return Common_eventweight_fatjet_SFdnVLoose_;
}

const float &VVVTree::Common_eventweight_fatjet_SFdnLoose() {
  if (not Common_eventweight_fatjet_SFdnLoose_isLoaded) {
    if (Common_eventweight_fatjet_SFdnLoose_branch != 0) {
      Common_eventweight_fatjet_SFdnLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_SFdnLoose_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_SFdnLoose_isLoaded = true;
  }
  return Common_eventweight_fatjet_SFdnLoose_;
}

const float &VVVTree::Common_eventweight_fatjet_SFdnMedium() {
  if (not Common_eventweight_fatjet_SFdnMedium_isLoaded) {
    if (Common_eventweight_fatjet_SFdnMedium_branch != 0) {
      Common_eventweight_fatjet_SFdnMedium_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_SFdnMedium_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_SFdnMedium_isLoaded = true;
  }
  return Common_eventweight_fatjet_SFdnMedium_;
}

const float &VVVTree::Common_eventweight_fatjet_SFdnTight() {
  if (not Common_eventweight_fatjet_SFdnTight_isLoaded) {
    if (Common_eventweight_fatjet_SFdnTight_branch != 0) {
      Common_eventweight_fatjet_SFdnTight_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_SFdnTight_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_SFdnTight_isLoaded = true;
  }
  return Common_eventweight_fatjet_SFdnTight_;
}

const float &VVVTree::Common_eventweight_fatjet_SFupVLoose() {
  if (not Common_eventweight_fatjet_SFupVLoose_isLoaded) {
    if (Common_eventweight_fatjet_SFupVLoose_branch != 0) {
      Common_eventweight_fatjet_SFupVLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_SFupVLoose_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_SFupVLoose_isLoaded = true;
  }
  return Common_eventweight_fatjet_SFupVLoose_;
}

const float &VVVTree::Common_eventweight_fatjet_SFupLoose() {
  if (not Common_eventweight_fatjet_SFupLoose_isLoaded) {
    if (Common_eventweight_fatjet_SFupLoose_branch != 0) {
      Common_eventweight_fatjet_SFupLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_SFupLoose_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_SFupLoose_isLoaded = true;
  }
  return Common_eventweight_fatjet_SFupLoose_;
}

const float &VVVTree::Common_eventweight_fatjet_SFupMedium() {
  if (not Common_eventweight_fatjet_SFupMedium_isLoaded) {
    if (Common_eventweight_fatjet_SFupMedium_branch != 0) {
      Common_eventweight_fatjet_SFupMedium_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_SFupMedium_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_SFupMedium_isLoaded = true;
  }
  return Common_eventweight_fatjet_SFupMedium_;
}

const float &VVVTree::Common_eventweight_fatjet_SFupTight() {
  if (not Common_eventweight_fatjet_SFupTight_isLoaded) {
    if (Common_eventweight_fatjet_SFupTight_branch != 0) {
      Common_eventweight_fatjet_SFupTight_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_SFupTight_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_SFupTight_isLoaded = true;
  }
  return Common_eventweight_fatjet_SFupTight_;
}

const int &VVVTree::Common_nb_loose() {
  if (not Common_nb_loose_isLoaded) {
    if (Common_nb_loose_branch != 0) {
      Common_nb_loose_branch->GetEntry(index);
    } else {
      printf("branch Common_nb_loose_branch does not exist!\n");
      exit(1);
    }
    Common_nb_loose_isLoaded = true;
  }
  return Common_nb_loose_;
}

const int &VVVTree::Common_nb_medium() {
  if (not Common_nb_medium_isLoaded) {
    if (Common_nb_medium_branch != 0) {
      Common_nb_medium_branch->GetEntry(index);
    } else {
      printf("branch Common_nb_medium_branch does not exist!\n");
      exit(1);
    }
    Common_nb_medium_isLoaded = true;
  }
  return Common_nb_medium_;
}

const int &VVVTree::Common_nb_tight() {
  if (not Common_nb_tight_isLoaded) {
    if (Common_nb_tight_branch != 0) {
      Common_nb_tight_branch->GetEntry(index);
    } else {
      printf("branch Common_nb_tight_branch does not exist!\n");
      exit(1);
    }
    Common_nb_tight_isLoaded = true;
  }
  return Common_nb_tight_;
}

const vector<int> &VVVTree::Common_gen_idx() {
  if (not Common_gen_idx_isLoaded) {
    if (Common_gen_idx_branch != 0) {
      Common_gen_idx_branch->GetEntry(index);
    } else {
      printf("branch Common_gen_idx_branch does not exist!\n");
      exit(1);
    }
    Common_gen_idx_isLoaded = true;
  }
  return *Common_gen_idx_;
}

const vector<int> &VVVTree::Common_gen_mother_idx() {
  if (not Common_gen_mother_idx_isLoaded) {
    if (Common_gen_mother_idx_branch != 0) {
      Common_gen_mother_idx_branch->GetEntry(index);
    } else {
      printf("branch Common_gen_mother_idx_branch does not exist!\n");
      exit(1);
    }
    Common_gen_mother_idx_isLoaded = true;
  }
  return *Common_gen_mother_idx_;
}

const vector<int> &VVVTree::Common_gen_mother_id() {
  if (not Common_gen_mother_id_isLoaded) {
    if (Common_gen_mother_id_branch != 0) {
      Common_gen_mother_id_branch->GetEntry(index);
    } else {
      printf("branch Common_gen_mother_id_branch does not exist!\n");
      exit(1);
    }
    Common_gen_mother_id_isLoaded = true;
  }
  return *Common_gen_mother_id_;
}

const vector<int> &VVVTree::Common_gen_pdgid() {
  if (not Common_gen_pdgid_isLoaded) {
    if (Common_gen_pdgid_branch != 0) {
      Common_gen_pdgid_branch->GetEntry(index);
    } else {
      printf("branch Common_gen_pdgid_branch does not exist!\n");
      exit(1);
    }
    Common_gen_pdgid_isLoaded = true;
  }
  return *Common_gen_pdgid_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_gen_p4s() {
  if (not Common_gen_p4s_isLoaded) {
    if (Common_gen_p4s_branch != 0) {
      Common_gen_p4s_branch->GetEntry(index);
    } else {
      printf("branch Common_gen_p4s_branch does not exist!\n");
      exit(1);
    }
    Common_gen_p4s_isLoaded = true;
  }
  return *Common_gen_p4s_;
}

const vector<int> &VVVTree::Common_gen_vvvdecay_idx() {
  if (not Common_gen_vvvdecay_idx_isLoaded) {
    if (Common_gen_vvvdecay_idx_branch != 0) {
      Common_gen_vvvdecay_idx_branch->GetEntry(index);
    } else {
      printf("branch Common_gen_vvvdecay_idx_branch does not exist!\n");
      exit(1);
    }
    Common_gen_vvvdecay_idx_isLoaded = true;
  }
  return *Common_gen_vvvdecay_idx_;
}

const vector<int> &VVVTree::Common_gen_vvvdecay_mother_idx() {
  if (not Common_gen_vvvdecay_mother_idx_isLoaded) {
    if (Common_gen_vvvdecay_mother_idx_branch != 0) {
      Common_gen_vvvdecay_mother_idx_branch->GetEntry(index);
    } else {
      printf("branch Common_gen_vvvdecay_mother_idx_branch does not exist!\n");
      exit(1);
    }
    Common_gen_vvvdecay_mother_idx_isLoaded = true;
  }
  return *Common_gen_vvvdecay_mother_idx_;
}

const vector<int> &VVVTree::Common_gen_vvvdecay_mother_id() {
  if (not Common_gen_vvvdecay_mother_id_isLoaded) {
    if (Common_gen_vvvdecay_mother_id_branch != 0) {
      Common_gen_vvvdecay_mother_id_branch->GetEntry(index);
    } else {
      printf("branch Common_gen_vvvdecay_mother_id_branch does not exist!\n");
      exit(1);
    }
    Common_gen_vvvdecay_mother_id_isLoaded = true;
  }
  return *Common_gen_vvvdecay_mother_id_;
}

const vector<int> &VVVTree::Common_gen_vvvdecay_pdgid() {
  if (not Common_gen_vvvdecay_pdgid_isLoaded) {
    if (Common_gen_vvvdecay_pdgid_branch != 0) {
      Common_gen_vvvdecay_pdgid_branch->GetEntry(index);
    } else {
      printf("branch Common_gen_vvvdecay_pdgid_branch does not exist!\n");
      exit(1);
    }
    Common_gen_vvvdecay_pdgid_isLoaded = true;
  }
  return *Common_gen_vvvdecay_pdgid_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVVTree::Common_gen_vvvdecay_p4s() {
  if (not Common_gen_vvvdecay_p4s_isLoaded) {
    if (Common_gen_vvvdecay_p4s_branch != 0) {
      Common_gen_vvvdecay_p4s_branch->GetEntry(index);
    } else {
      printf("branch Common_gen_vvvdecay_p4s_branch does not exist!\n");
      exit(1);
    }
    Common_gen_vvvdecay_p4s_isLoaded = true;
  }
  return *Common_gen_vvvdecay_p4s_;
}

const vector<int> &VVVTree::Common_gen_vvvdecay_taudecayid() {
  if (not Common_gen_vvvdecay_taudecayid_isLoaded) {
    if (Common_gen_vvvdecay_taudecayid_branch != 0) {
      Common_gen_vvvdecay_taudecayid_branch->GetEntry(index);
    } else {
      printf("branch Common_gen_vvvdecay_taudecayid_branch does not exist!\n");
      exit(1);
    }
    Common_gen_vvvdecay_taudecayid_isLoaded = true;
  }
  return *Common_gen_vvvdecay_taudecayid_;
}

const int &VVVTree::Common_n_W() {
  if (not Common_n_W_isLoaded) {
    if (Common_n_W_branch != 0) {
      Common_n_W_branch->GetEntry(index);
    } else {
      printf("branch Common_n_W_branch does not exist!\n");
      exit(1);
    }
    Common_n_W_isLoaded = true;
  }
  return Common_n_W_;
}

const int &VVVTree::Common_n_Z() {
  if (not Common_n_Z_isLoaded) {
    if (Common_n_Z_branch != 0) {
      Common_n_Z_branch->GetEntry(index);
    } else {
      printf("branch Common_n_Z_branch does not exist!\n");
      exit(1);
    }
    Common_n_Z_isLoaded = true;
  }
  return Common_n_Z_;
}

const int &VVVTree::Common_n_lep_Z() {
  if (not Common_n_lep_Z_isLoaded) {
    if (Common_n_lep_Z_branch != 0) {
      Common_n_lep_Z_branch->GetEntry(index);
    } else {
      printf("branch Common_n_lep_Z_branch does not exist!\n");
      exit(1);
    }
    Common_n_lep_Z_isLoaded = true;
  }
  return Common_n_lep_Z_;
}

const int &VVVTree::Common_n_leptau_Z() {
  if (not Common_n_leptau_Z_isLoaded) {
    if (Common_n_leptau_Z_branch != 0) {
      Common_n_leptau_Z_branch->GetEntry(index);
    } else {
      printf("branch Common_n_leptau_Z_branch does not exist!\n");
      exit(1);
    }
    Common_n_leptau_Z_isLoaded = true;
  }
  return Common_n_leptau_Z_;
}

const int &VVVTree::Common_n_hadtau_Z() {
  if (not Common_n_hadtau_Z_isLoaded) {
    if (Common_n_hadtau_Z_branch != 0) {
      Common_n_hadtau_Z_branch->GetEntry(index);
    } else {
      printf("branch Common_n_hadtau_Z_branch does not exist!\n");
      exit(1);
    }
    Common_n_hadtau_Z_isLoaded = true;
  }
  return Common_n_hadtau_Z_;
}

const int &VVVTree::Common_n_nu_Z() {
  if (not Common_n_nu_Z_isLoaded) {
    if (Common_n_nu_Z_branch != 0) {
      Common_n_nu_Z_branch->GetEntry(index);
    } else {
      printf("branch Common_n_nu_Z_branch does not exist!\n");
      exit(1);
    }
    Common_n_nu_Z_isLoaded = true;
  }
  return Common_n_nu_Z_;
}

const int &VVVTree::Common_n_b_Z() {
  if (not Common_n_b_Z_isLoaded) {
    if (Common_n_b_Z_branch != 0) {
      Common_n_b_Z_branch->GetEntry(index);
    } else {
      printf("branch Common_n_b_Z_branch does not exist!\n");
      exit(1);
    }
    Common_n_b_Z_isLoaded = true;
  }
  return Common_n_b_Z_;
}

const int &VVVTree::Common_n_lep_W() {
  if (not Common_n_lep_W_isLoaded) {
    if (Common_n_lep_W_branch != 0) {
      Common_n_lep_W_branch->GetEntry(index);
    } else {
      printf("branch Common_n_lep_W_branch does not exist!\n");
      exit(1);
    }
    Common_n_lep_W_isLoaded = true;
  }
  return Common_n_lep_W_;
}

const int &VVVTree::Common_n_leptau_W() {
  if (not Common_n_leptau_W_isLoaded) {
    if (Common_n_leptau_W_branch != 0) {
      Common_n_leptau_W_branch->GetEntry(index);
    } else {
      printf("branch Common_n_leptau_W_branch does not exist!\n");
      exit(1);
    }
    Common_n_leptau_W_isLoaded = true;
  }
  return Common_n_leptau_W_;
}

const int &VVVTree::Common_n_hadtau_W() {
  if (not Common_n_hadtau_W_isLoaded) {
    if (Common_n_hadtau_W_branch != 0) {
      Common_n_hadtau_W_branch->GetEntry(index);
    } else {
      printf("branch Common_n_hadtau_W_branch does not exist!\n");
      exit(1);
    }
    Common_n_hadtau_W_isLoaded = true;
  }
  return Common_n_hadtau_W_;
}

const bool &VVVTree::Common_haslepWSS() {
  if (not Common_haslepWSS_isLoaded) {
    if (Common_haslepWSS_branch != 0) {
      Common_haslepWSS_branch->GetEntry(index);
    } else {
      printf("branch Common_haslepWSS_branch does not exist!\n");
      exit(1);
    }
    Common_haslepWSS_isLoaded = true;
  }
  return Common_haslepWSS_;
}

const float &VVVTree::Common_genHT() {
  if (not Common_genHT_isLoaded) {
    if (Common_genHT_branch != 0) {
      Common_genHT_branch->GetEntry(index);
    } else {
      printf("branch Common_genHT_branch does not exist!\n");
      exit(1);
    }
    Common_genHT_isLoaded = true;
  }
  return Common_genHT_;
}

const int &VVVTree::Common_gen_n_light_lep() {
  if (not Common_gen_n_light_lep_isLoaded) {
    if (Common_gen_n_light_lep_branch != 0) {
      Common_gen_n_light_lep_branch->GetEntry(index);
    } else {
      printf("branch Common_gen_n_light_lep_branch does not exist!\n");
      exit(1);
    }
    Common_gen_n_light_lep_isLoaded = true;
  }
  return Common_gen_n_light_lep_;
}

const bool &VVVTree::Cut_4LepMET_Preselection() {
  if (not Cut_4LepMET_Preselection_isLoaded) {
    if (Cut_4LepMET_Preselection_branch != 0) {
      Cut_4LepMET_Preselection_branch->GetEntry(index);
    } else {
      printf("branch Cut_4LepMET_Preselection_branch does not exist!\n");
      exit(1);
    }
    Cut_4LepMET_Preselection_isLoaded = true;
  }
  return Cut_4LepMET_Preselection_;
}

const bool &VVVTree::Cut_4LepMET_emuChannel() {
  if (not Cut_4LepMET_emuChannel_isLoaded) {
    if (Cut_4LepMET_emuChannel_branch != 0) {
      Cut_4LepMET_emuChannel_branch->GetEntry(index);
    } else {
      printf("branch Cut_4LepMET_emuChannel_branch does not exist!\n");
      exit(1);
    }
    Cut_4LepMET_emuChannel_isLoaded = true;
  }
  return Cut_4LepMET_emuChannel_;
}

const bool &VVVTree::Cut_4LepMET_offzChannel() {
  if (not Cut_4LepMET_offzChannel_isLoaded) {
    if (Cut_4LepMET_offzChannel_branch != 0) {
      Cut_4LepMET_offzChannel_branch->GetEntry(index);
    } else {
      printf("branch Cut_4LepMET_offzChannel_branch does not exist!\n");
      exit(1);
    }
    Cut_4LepMET_offzChannel_isLoaded = true;
  }
  return Cut_4LepMET_offzChannel_;
}

const bool &VVVTree::Cut_4LepMET_onzChannel() {
  if (not Cut_4LepMET_onzChannel_isLoaded) {
    if (Cut_4LepMET_onzChannel_branch != 0) {
      Cut_4LepMET_onzChannel_branch->GetEntry(index);
    } else {
      printf("branch Cut_4LepMET_onzChannel_branch does not exist!\n");
      exit(1);
    }
    Cut_4LepMET_onzChannel_isLoaded = true;
  }
  return Cut_4LepMET_onzChannel_;
}

const bool &VVVTree::Cut_4LepMET_onzChannel_HighMET() {
  if (not Cut_4LepMET_onzChannel_HighMET_isLoaded) {
    if (Cut_4LepMET_onzChannel_HighMET_branch != 0) {
      Cut_4LepMET_onzChannel_HighMET_branch->GetEntry(index);
    } else {
      printf("branch Cut_4LepMET_onzChannel_HighMET_branch does not exist!\n");
      exit(1);
    }
    Cut_4LepMET_onzChannel_HighMET_isLoaded = true;
  }
  return Cut_4LepMET_onzChannel_HighMET_;
}

const int &VVVTree::Var_4LepMET_Zcand_lep_idx_0() {
  if (not Var_4LepMET_Zcand_lep_idx_0_isLoaded) {
    if (Var_4LepMET_Zcand_lep_idx_0_branch != 0) {
      Var_4LepMET_Zcand_lep_idx_0_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_Zcand_lep_idx_0_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_Zcand_lep_idx_0_isLoaded = true;
  }
  return Var_4LepMET_Zcand_lep_idx_0_;
}

const int &VVVTree::Var_4LepMET_Zcand_lep_pdgid_0() {
  if (not Var_4LepMET_Zcand_lep_pdgid_0_isLoaded) {
    if (Var_4LepMET_Zcand_lep_pdgid_0_branch != 0) {
      Var_4LepMET_Zcand_lep_pdgid_0_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_Zcand_lep_pdgid_0_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_Zcand_lep_pdgid_0_isLoaded = true;
  }
  return Var_4LepMET_Zcand_lep_pdgid_0_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Var_4LepMET_Zcand_lep_p4_0() {
  if (not Var_4LepMET_Zcand_lep_p4_0_isLoaded) {
    if (Var_4LepMET_Zcand_lep_p4_0_branch != 0) {
      Var_4LepMET_Zcand_lep_p4_0_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_Zcand_lep_p4_0_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_Zcand_lep_p4_0_isLoaded = true;
  }
  return *Var_4LepMET_Zcand_lep_p4_0_;
}

const int &VVVTree::Var_4LepMET_Zcand_lep_idx_1() {
  if (not Var_4LepMET_Zcand_lep_idx_1_isLoaded) {
    if (Var_4LepMET_Zcand_lep_idx_1_branch != 0) {
      Var_4LepMET_Zcand_lep_idx_1_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_Zcand_lep_idx_1_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_Zcand_lep_idx_1_isLoaded = true;
  }
  return Var_4LepMET_Zcand_lep_idx_1_;
}

const int &VVVTree::Var_4LepMET_Zcand_lep_pdgid_1() {
  if (not Var_4LepMET_Zcand_lep_pdgid_1_isLoaded) {
    if (Var_4LepMET_Zcand_lep_pdgid_1_branch != 0) {
      Var_4LepMET_Zcand_lep_pdgid_1_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_Zcand_lep_pdgid_1_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_Zcand_lep_pdgid_1_isLoaded = true;
  }
  return Var_4LepMET_Zcand_lep_pdgid_1_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Var_4LepMET_Zcand_lep_p4_1() {
  if (not Var_4LepMET_Zcand_lep_p4_1_isLoaded) {
    if (Var_4LepMET_Zcand_lep_p4_1_branch != 0) {
      Var_4LepMET_Zcand_lep_p4_1_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_Zcand_lep_p4_1_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_Zcand_lep_p4_1_isLoaded = true;
  }
  return *Var_4LepMET_Zcand_lep_p4_1_;
}

const float &VVVTree::Var_4LepMET_Zcand_mll() {
  if (not Var_4LepMET_Zcand_mll_isLoaded) {
    if (Var_4LepMET_Zcand_mll_branch != 0) {
      Var_4LepMET_Zcand_mll_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_Zcand_mll_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_Zcand_mll_isLoaded = true;
  }
  return Var_4LepMET_Zcand_mll_;
}

const int &VVVTree::Var_4LepMET_other_lep_idx_0() {
  if (not Var_4LepMET_other_lep_idx_0_isLoaded) {
    if (Var_4LepMET_other_lep_idx_0_branch != 0) {
      Var_4LepMET_other_lep_idx_0_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_other_lep_idx_0_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_other_lep_idx_0_isLoaded = true;
  }
  return Var_4LepMET_other_lep_idx_0_;
}

const int &VVVTree::Var_4LepMET_other_lep_pdgid_0() {
  if (not Var_4LepMET_other_lep_pdgid_0_isLoaded) {
    if (Var_4LepMET_other_lep_pdgid_0_branch != 0) {
      Var_4LepMET_other_lep_pdgid_0_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_other_lep_pdgid_0_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_other_lep_pdgid_0_isLoaded = true;
  }
  return Var_4LepMET_other_lep_pdgid_0_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Var_4LepMET_other_lep_p4_0() {
  if (not Var_4LepMET_other_lep_p4_0_isLoaded) {
    if (Var_4LepMET_other_lep_p4_0_branch != 0) {
      Var_4LepMET_other_lep_p4_0_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_other_lep_p4_0_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_other_lep_p4_0_isLoaded = true;
  }
  return *Var_4LepMET_other_lep_p4_0_;
}

const int &VVVTree::Var_4LepMET_other_lep_idx_1() {
  if (not Var_4LepMET_other_lep_idx_1_isLoaded) {
    if (Var_4LepMET_other_lep_idx_1_branch != 0) {
      Var_4LepMET_other_lep_idx_1_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_other_lep_idx_1_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_other_lep_idx_1_isLoaded = true;
  }
  return Var_4LepMET_other_lep_idx_1_;
}

const int &VVVTree::Var_4LepMET_other_lep_pdgid_1() {
  if (not Var_4LepMET_other_lep_pdgid_1_isLoaded) {
    if (Var_4LepMET_other_lep_pdgid_1_branch != 0) {
      Var_4LepMET_other_lep_pdgid_1_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_other_lep_pdgid_1_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_other_lep_pdgid_1_isLoaded = true;
  }
  return Var_4LepMET_other_lep_pdgid_1_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVVTree::Var_4LepMET_other_lep_p4_1() {
  if (not Var_4LepMET_other_lep_p4_1_isLoaded) {
    if (Var_4LepMET_other_lep_p4_1_branch != 0) {
      Var_4LepMET_other_lep_p4_1_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_other_lep_p4_1_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_other_lep_p4_1_isLoaded = true;
  }
  return *Var_4LepMET_other_lep_p4_1_;
}

const float &VVVTree::Var_4LepMET_other_mll() {
  if (not Var_4LepMET_other_mll_isLoaded) {
    if (Var_4LepMET_other_mll_branch != 0) {
      Var_4LepMET_other_mll_branch->GetEntry(index);
    } else {
      printf("branch Var_4LepMET_other_mll_branch does not exist!\n");
      exit(1);
    }
    Var_4LepMET_other_mll_isLoaded = true;
  }
  return Var_4LepMET_other_mll_;
}


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

const int &Common_isData() { return vvv.Common_isData(); }
const int &Common_run() { return vvv.Common_run(); }
const int &Common_lumi() { return vvv.Common_lumi(); }
const unsigned long long &Common_evt() { return vvv.Common_evt(); }
const float &Common_genWeight() { return vvv.Common_genWeight(); }
const float &Common_btagWeight_DeepCSVB() { return vvv.Common_btagWeight_DeepCSVB(); }
const vector<float> &Common_LHEWeight_mg_reweighting() { return vvv.Common_LHEWeight_mg_reweighting(); }
const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ() { return vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ(); }
const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL() { return vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL(); }
const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8() { return vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8(); }
const bool &Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() { return vvv.Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ(); }
const bool &Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL() { return vvv.Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL(); }
const bool &Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() { return vvv.Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ(); }
const bool &Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL() { return vvv.Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL(); }
const bool &Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ() { return vvv.Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ(); }
const bool &Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL() { return vvv.Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL(); }
const bool &Common_HLT_DoubleEl() { return vvv.Common_HLT_DoubleEl(); }
const bool &Common_HLT_MuEG() { return vvv.Common_HLT_MuEG(); }
const bool &Common_HLT_DoubleMu() { return vvv.Common_HLT_DoubleMu(); }
const bool &Common_pass_duplicate_removal_ee_em_mm() { return vvv.Common_pass_duplicate_removal_ee_em_mm(); }
const bool &Common_pass_duplicate_removal_mm_em_ee() { return vvv.Common_pass_duplicate_removal_mm_em_ee(); }
const bool &Common_noiseFlag() { return vvv.Common_noiseFlag(); }
const bool &Common_noiseFlagMC() { return vvv.Common_noiseFlagMC(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4() { return vvv.Common_met_p4(); }
const float &Common_event_lepSF() { return vvv.Common_event_lepSF(); }
const float &Common_event_lepSFelup() { return vvv.Common_event_lepSFelup(); }
const float &Common_event_lepSFeldn() { return vvv.Common_event_lepSFeldn(); }
const float &Common_event_lepSFmuup() { return vvv.Common_event_lepSFmuup(); }
const float &Common_event_lepSFmudn() { return vvv.Common_event_lepSFmudn(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_lep_p4() { return vvv.Common_lep_p4(); }
const vector<int> &Common_lep_idxs() { return vvv.Common_lep_idxs(); }
const vector<int> &Common_lep_pdgid() { return vvv.Common_lep_pdgid(); }
const vector<int> &Common_lep_tight() { return vvv.Common_lep_tight(); }
const vector<float> &Common_lep_dxy() { return vvv.Common_lep_dxy(); }
const vector<float> &Common_lep_dz() { return vvv.Common_lep_dz(); }
const vector<float> &Common_lep_SF() { return vvv.Common_lep_SF(); }
const vector<float> &Common_lep_SFTight() { return vvv.Common_lep_SFTight(); }
const vector<float> &Common_lep_SFdn() { return vvv.Common_lep_SFdn(); }
const vector<float> &Common_lep_SFdnTight() { return vvv.Common_lep_SFdnTight(); }
const vector<float> &Common_lep_SFup() { return vvv.Common_lep_SFup(); }
const vector<float> &Common_lep_SFupTight() { return vvv.Common_lep_SFupTight(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_jet_p4() { return vvv.Common_jet_p4(); }
const vector<int> &Common_jet_idxs() { return vvv.Common_jet_idxs(); }
const vector<bool> &Common_jet_passBloose() { return vvv.Common_jet_passBloose(); }
const vector<bool> &Common_jet_passBmedium() { return vvv.Common_jet_passBmedium(); }
const vector<bool> &Common_jet_passBtight() { return vvv.Common_jet_passBtight(); }
const vector<int> &Common_jet_overlapfatjet() { return vvv.Common_jet_overlapfatjet(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4() { return vvv.Common_fatjet_p4(); }
const vector<int> &Common_fatjet_idxs() { return vvv.Common_fatjet_idxs(); }
const vector<float> &Common_fatjet_msoftdrop() { return vvv.Common_fatjet_msoftdrop(); }
const vector<float> &Common_fatjet_deepMD_W() { return vvv.Common_fatjet_deepMD_W(); }
const vector<float> &Common_fatjet_deep_W() { return vvv.Common_fatjet_deep_W(); }
const vector<float> &Common_fatjet_deepMD_Z() { return vvv.Common_fatjet_deepMD_Z(); }
const vector<float> &Common_fatjet_deep_Z() { return vvv.Common_fatjet_deep_Z(); }
const vector<float> &Common_fatjet_deepMD_T() { return vvv.Common_fatjet_deepMD_T(); }
const vector<float> &Common_fatjet_deep_T() { return vvv.Common_fatjet_deep_T(); }
const vector<float> &Common_fatjet_deepMD_bb() { return vvv.Common_fatjet_deepMD_bb(); }
const vector<float> &Common_fatjet_tau3() { return vvv.Common_fatjet_tau3(); }
const vector<float> &Common_fatjet_tau2() { return vvv.Common_fatjet_tau2(); }
const vector<float> &Common_fatjet_tau1() { return vvv.Common_fatjet_tau1(); }
const vector<float> &Common_fatjet_tau32() { return vvv.Common_fatjet_tau32(); }
const vector<float> &Common_fatjet_tau21() { return vvv.Common_fatjet_tau21(); }
const vector<float> &Common_fatjet_subjet0_pt() { return vvv.Common_fatjet_subjet0_pt(); }
const vector<float> &Common_fatjet_subjet0_eta() { return vvv.Common_fatjet_subjet0_eta(); }
const vector<float> &Common_fatjet_subjet0_phi() { return vvv.Common_fatjet_subjet0_phi(); }
const vector<float> &Common_fatjet_subjet0_mass() { return vvv.Common_fatjet_subjet0_mass(); }
const vector<float> &Common_fatjet_subjet1_pt() { return vvv.Common_fatjet_subjet1_pt(); }
const vector<float> &Common_fatjet_subjet1_eta() { return vvv.Common_fatjet_subjet1_eta(); }
const vector<float> &Common_fatjet_subjet1_phi() { return vvv.Common_fatjet_subjet1_phi(); }
const vector<float> &Common_fatjet_subjet1_mass() { return vvv.Common_fatjet_subjet1_mass(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_subjet0_p4() { return vvv.Common_fatjet_subjet0_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_subjet1_p4() { return vvv.Common_fatjet_subjet1_p4(); }
const vector<int> &Common_fatjet_WP() { return vvv.Common_fatjet_WP(); }
const vector<int> &Common_fatjet_WP_antimasscut() { return vvv.Common_fatjet_WP_antimasscut(); }
const vector<float> &Common_fatjet_SFVLoose() { return vvv.Common_fatjet_SFVLoose(); }
const vector<float> &Common_fatjet_SFLoose() { return vvv.Common_fatjet_SFLoose(); }
const vector<float> &Common_fatjet_SFMedium() { return vvv.Common_fatjet_SFMedium(); }
const vector<float> &Common_fatjet_SFTight() { return vvv.Common_fatjet_SFTight(); }
const vector<float> &Common_fatjet_SFdnVLoose() { return vvv.Common_fatjet_SFdnVLoose(); }
const vector<float> &Common_fatjet_SFdnLoose() { return vvv.Common_fatjet_SFdnLoose(); }
const vector<float> &Common_fatjet_SFdnMedium() { return vvv.Common_fatjet_SFdnMedium(); }
const vector<float> &Common_fatjet_SFdnTight() { return vvv.Common_fatjet_SFdnTight(); }
const vector<float> &Common_fatjet_SFupVLoose() { return vvv.Common_fatjet_SFupVLoose(); }
const vector<float> &Common_fatjet_SFupLoose() { return vvv.Common_fatjet_SFupLoose(); }
const vector<float> &Common_fatjet_SFupMedium() { return vvv.Common_fatjet_SFupMedium(); }
const vector<float> &Common_fatjet_SFupTight() { return vvv.Common_fatjet_SFupTight(); }
const float &Common_eventweight_fatjet_SFVLoose() { return vvv.Common_eventweight_fatjet_SFVLoose(); }
const float &Common_eventweight_fatjet_SFLoose() { return vvv.Common_eventweight_fatjet_SFLoose(); }
const float &Common_eventweight_fatjet_SFMedium() { return vvv.Common_eventweight_fatjet_SFMedium(); }
const float &Common_eventweight_fatjet_SFTight() { return vvv.Common_eventweight_fatjet_SFTight(); }
const float &Common_eventweight_fatjet_SFdnVLoose() { return vvv.Common_eventweight_fatjet_SFdnVLoose(); }
const float &Common_eventweight_fatjet_SFdnLoose() { return vvv.Common_eventweight_fatjet_SFdnLoose(); }
const float &Common_eventweight_fatjet_SFdnMedium() { return vvv.Common_eventweight_fatjet_SFdnMedium(); }
const float &Common_eventweight_fatjet_SFdnTight() { return vvv.Common_eventweight_fatjet_SFdnTight(); }
const float &Common_eventweight_fatjet_SFupVLoose() { return vvv.Common_eventweight_fatjet_SFupVLoose(); }
const float &Common_eventweight_fatjet_SFupLoose() { return vvv.Common_eventweight_fatjet_SFupLoose(); }
const float &Common_eventweight_fatjet_SFupMedium() { return vvv.Common_eventweight_fatjet_SFupMedium(); }
const float &Common_eventweight_fatjet_SFupTight() { return vvv.Common_eventweight_fatjet_SFupTight(); }
const int &Common_nb_loose() { return vvv.Common_nb_loose(); }
const int &Common_nb_medium() { return vvv.Common_nb_medium(); }
const int &Common_nb_tight() { return vvv.Common_nb_tight(); }
const vector<int> &Common_gen_idx() { return vvv.Common_gen_idx(); }
const vector<int> &Common_gen_mother_idx() { return vvv.Common_gen_mother_idx(); }
const vector<int> &Common_gen_mother_id() { return vvv.Common_gen_mother_id(); }
const vector<int> &Common_gen_pdgid() { return vvv.Common_gen_pdgid(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_gen_p4s() { return vvv.Common_gen_p4s(); }
const vector<int> &Common_gen_vvvdecay_idx() { return vvv.Common_gen_vvvdecay_idx(); }
const vector<int> &Common_gen_vvvdecay_mother_idx() { return vvv.Common_gen_vvvdecay_mother_idx(); }
const vector<int> &Common_gen_vvvdecay_mother_id() { return vvv.Common_gen_vvvdecay_mother_id(); }
const vector<int> &Common_gen_vvvdecay_pdgid() { return vvv.Common_gen_vvvdecay_pdgid(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_gen_vvvdecay_p4s() { return vvv.Common_gen_vvvdecay_p4s(); }
const vector<int> &Common_gen_vvvdecay_taudecayid() { return vvv.Common_gen_vvvdecay_taudecayid(); }
const int &Common_n_W() { return vvv.Common_n_W(); }
const int &Common_n_Z() { return vvv.Common_n_Z(); }
const int &Common_n_lep_Z() { return vvv.Common_n_lep_Z(); }
const int &Common_n_leptau_Z() { return vvv.Common_n_leptau_Z(); }
const int &Common_n_hadtau_Z() { return vvv.Common_n_hadtau_Z(); }
const int &Common_n_nu_Z() { return vvv.Common_n_nu_Z(); }
const int &Common_n_b_Z() { return vvv.Common_n_b_Z(); }
const int &Common_n_lep_W() { return vvv.Common_n_lep_W(); }
const int &Common_n_leptau_W() { return vvv.Common_n_leptau_W(); }
const int &Common_n_hadtau_W() { return vvv.Common_n_hadtau_W(); }
const bool &Common_haslepWSS() { return vvv.Common_haslepWSS(); }
const float &Common_genHT() { return vvv.Common_genHT(); }
const int &Common_gen_n_light_lep() { return vvv.Common_gen_n_light_lep(); }
const bool &Cut_4LepMET_Preselection() { return vvv.Cut_4LepMET_Preselection(); }
const bool &Cut_4LepMET_emuChannel() { return vvv.Cut_4LepMET_emuChannel(); }
const bool &Cut_4LepMET_offzChannel() { return vvv.Cut_4LepMET_offzChannel(); }
const bool &Cut_4LepMET_onzChannel() { return vvv.Cut_4LepMET_onzChannel(); }
const bool &Cut_4LepMET_onzChannel_HighMET() { return vvv.Cut_4LepMET_onzChannel_HighMET(); }
const int &Var_4LepMET_Zcand_lep_idx_0() { return vvv.Var_4LepMET_Zcand_lep_idx_0(); }
const int &Var_4LepMET_Zcand_lep_pdgid_0() { return vvv.Var_4LepMET_Zcand_lep_pdgid_0(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_Zcand_lep_p4_0() { return vvv.Var_4LepMET_Zcand_lep_p4_0(); }
const int &Var_4LepMET_Zcand_lep_idx_1() { return vvv.Var_4LepMET_Zcand_lep_idx_1(); }
const int &Var_4LepMET_Zcand_lep_pdgid_1() { return vvv.Var_4LepMET_Zcand_lep_pdgid_1(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_Zcand_lep_p4_1() { return vvv.Var_4LepMET_Zcand_lep_p4_1(); }
const float &Var_4LepMET_Zcand_mll() { return vvv.Var_4LepMET_Zcand_mll(); }
const int &Var_4LepMET_other_lep_idx_0() { return vvv.Var_4LepMET_other_lep_idx_0(); }
const int &Var_4LepMET_other_lep_pdgid_0() { return vvv.Var_4LepMET_other_lep_pdgid_0(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_other_lep_p4_0() { return vvv.Var_4LepMET_other_lep_p4_0(); }
const int &Var_4LepMET_other_lep_idx_1() { return vvv.Var_4LepMET_other_lep_idx_1(); }
const int &Var_4LepMET_other_lep_pdgid_1() { return vvv.Var_4LepMET_other_lep_pdgid_1(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Var_4LepMET_other_lep_p4_1() { return vvv.Var_4LepMET_other_lep_p4_1(); }
const float &Var_4LepMET_other_mll() { return vvv.Var_4LepMET_other_mll(); }

}
