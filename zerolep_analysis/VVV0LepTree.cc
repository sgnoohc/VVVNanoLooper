#include "VVV0LepTree.h"
VVV0LepTree vvv;

void VVV0LepTree::Init(TTree *tree) {
  Common_met_p4_branch = tree->GetBranch("Common_met_p4");
  if (Common_met_p4_branch) Common_met_p4_branch->SetAddress(&Common_met_p4_);
  Common_met_p4_jesup_branch = tree->GetBranch("Common_met_p4_jesup");
  if (Common_met_p4_jesup_branch) Common_met_p4_jesup_branch->SetAddress(&Common_met_p4_jesup_);
  Common_met_p4_jesdn_branch = tree->GetBranch("Common_met_p4_jesdn");
  if (Common_met_p4_jesdn_branch) Common_met_p4_jesdn_branch->SetAddress(&Common_met_p4_jesdn_);
  Common_met_p4_jerup_branch = tree->GetBranch("Common_met_p4_jerup");
  if (Common_met_p4_jerup_branch) Common_met_p4_jerup_branch->SetAddress(&Common_met_p4_jerup_);
  Common_met_p4_jerdn_branch = tree->GetBranch("Common_met_p4_jerdn");
  if (Common_met_p4_jerdn_branch) Common_met_p4_jerdn_branch->SetAddress(&Common_met_p4_jerdn_);
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
  allHad_jets_p4_branch = tree->GetBranch("allHad_jets_p4");
  if (allHad_jets_p4_branch) allHad_jets_p4_branch->SetAddress(&allHad_jets_p4_);
  allHad_fatjets_mSD_p4_branch = tree->GetBranch("allHad_fatjets_mSD_p4");
  if (allHad_fatjets_mSD_p4_branch) allHad_fatjets_mSD_p4_branch->SetAddress(&allHad_fatjets_mSD_p4_);
  allHad_FJ0_mSD_p4_branch = tree->GetBranch("allHad_FJ0_mSD_p4");
  if (allHad_FJ0_mSD_p4_branch) allHad_FJ0_mSD_p4_branch->SetAddress(&allHad_FJ0_mSD_p4_);
  allHad_FJ1_mSD_p4_branch = tree->GetBranch("allHad_FJ1_mSD_p4");
  if (allHad_FJ1_mSD_p4_branch) allHad_FJ1_mSD_p4_branch->SetAddress(&allHad_FJ1_mSD_p4_);
  allHad_FJ2_mSD_p4_branch = tree->GetBranch("allHad_FJ2_mSD_p4");
  if (allHad_FJ2_mSD_p4_branch) allHad_FJ2_mSD_p4_branch->SetAddress(&allHad_FJ2_mSD_p4_);
  allHad_VVV_mSD_p4_branch = tree->GetBranch("allHad_VVV_mSD_p4");
  if (allHad_VVV_mSD_p4_branch) allHad_VVV_mSD_p4_branch->SetAddress(&allHad_VVV_mSD_p4_);

  tree->SetMakeClass(1);

  Common_isData_branch = tree->GetBranch("Common_isData");
  if (Common_isData_branch) Common_isData_branch->SetAddress(&Common_isData_);
  Common_run_branch = tree->GetBranch("Common_run");
  if (Common_run_branch) Common_run_branch->SetAddress(&Common_run_);
  Common_lumi_branch = tree->GetBranch("Common_lumi");
  if (Common_lumi_branch) Common_lumi_branch->SetAddress(&Common_lumi_);
  Common_evt_branch = tree->GetBranch("Common_evt");
  if (Common_evt_branch) Common_evt_branch->SetAddress(&Common_evt_);
  Common_year_branch = tree->GetBranch("Common_year");
  if (Common_year_branch) Common_year_branch->SetAddress(&Common_year_);
  Common_genWeight_branch = tree->GetBranch("Common_genWeight");
  if (Common_genWeight_branch) Common_genWeight_branch->SetAddress(&Common_genWeight_);
  Common_btagWeight_DeepCSVB_branch = tree->GetBranch("Common_btagWeight_DeepCSVB");
  if (Common_btagWeight_DeepCSVB_branch) Common_btagWeight_DeepCSVB_branch->SetAddress(&Common_btagWeight_DeepCSVB_);
  Common_wgt_branch = tree->GetBranch("Common_wgt");
  if (Common_wgt_branch) Common_wgt_branch->SetAddress(&Common_wgt_);
  Common_event_puWeight_branch = tree->GetBranch("Common_event_puWeight");
  if (Common_event_puWeight_branch) Common_event_puWeight_branch->SetAddress(&Common_event_puWeight_);
  Common_event_puWeightup_branch = tree->GetBranch("Common_event_puWeightup");
  if (Common_event_puWeightup_branch) Common_event_puWeightup_branch->SetAddress(&Common_event_puWeightup_);
  Common_event_puWeightdn_branch = tree->GetBranch("Common_event_puWeightdn");
  if (Common_event_puWeightdn_branch) Common_event_puWeightdn_branch->SetAddress(&Common_event_puWeightdn_);
  Common_event_prefireWeight_branch = tree->GetBranch("Common_event_prefireWeight");
  if (Common_event_prefireWeight_branch) Common_event_prefireWeight_branch->SetAddress(&Common_event_prefireWeight_);
  Common_event_prefireWeightup_branch = tree->GetBranch("Common_event_prefireWeightup");
  if (Common_event_prefireWeightup_branch) Common_event_prefireWeightup_branch->SetAddress(&Common_event_prefireWeightup_);
  Common_event_prefireWeightdn_branch = tree->GetBranch("Common_event_prefireWeightdn");
  if (Common_event_prefireWeightdn_branch) Common_event_prefireWeightdn_branch->SetAddress(&Common_event_prefireWeightdn_);
  Common_event_triggerWeight_branch = tree->GetBranch("Common_event_triggerWeight");
  if (Common_event_triggerWeight_branch) Common_event_triggerWeight_branch->SetAddress(&Common_event_triggerWeight_);
  Common_event_triggerWeightup_branch = tree->GetBranch("Common_event_triggerWeightup");
  if (Common_event_triggerWeightup_branch) Common_event_triggerWeightup_branch->SetAddress(&Common_event_triggerWeightup_);
  Common_event_triggerWeightdn_branch = tree->GetBranch("Common_event_triggerWeightdn");
  if (Common_event_triggerWeightdn_branch) Common_event_triggerWeightdn_branch->SetAddress(&Common_event_triggerWeightdn_);
  Common_LHEReweightingWeight_branch = tree->GetBranch("Common_LHEReweightingWeight");
  if (Common_LHEReweightingWeight_branch) Common_LHEReweightingWeight_branch->SetAddress(&Common_LHEReweightingWeight_);
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
  Common_HLT_IsoMu24_branch = tree->GetBranch("Common_HLT_IsoMu24");
  if (Common_HLT_IsoMu24_branch) Common_HLT_IsoMu24_branch->SetAddress(&Common_HLT_IsoMu24_);
  Common_HLT_Ele32_WPTight_branch = tree->GetBranch("Common_HLT_Ele32_WPTight");
  if (Common_HLT_Ele32_WPTight_branch) Common_HLT_Ele32_WPTight_branch->SetAddress(&Common_HLT_Ele32_WPTight_);
  Common_HLT_PFHT1050_branch = tree->GetBranch("Common_HLT_PFHT1050");
  if (Common_HLT_PFHT1050_branch) Common_HLT_PFHT1050_branch->SetAddress(&Common_HLT_PFHT1050_);
  Common_HLT_AK8PFJet500_branch = tree->GetBranch("Common_HLT_AK8PFJet500");
  if (Common_HLT_AK8PFJet500_branch) Common_HLT_AK8PFJet500_branch->SetAddress(&Common_HLT_AK8PFJet500_);
  Common_HLT_AK8PFJet380_TrimMass30_branch = tree->GetBranch("Common_HLT_AK8PFJet380_TrimMass30");
  if (Common_HLT_AK8PFJet380_TrimMass30_branch) Common_HLT_AK8PFJet380_TrimMass30_branch->SetAddress(&Common_HLT_AK8PFJet380_TrimMass30_);
  Common_HLT_AK8PFJet360_TrimMass30_branch = tree->GetBranch("Common_HLT_AK8PFJet360_TrimMass30");
  if (Common_HLT_AK8PFJet360_TrimMass30_branch) Common_HLT_AK8PFJet360_TrimMass30_branch->SetAddress(&Common_HLT_AK8PFJet360_TrimMass30_);
  Common_HLT_AK8PFJet400_TrimMass30_branch = tree->GetBranch("Common_HLT_AK8PFJet400_TrimMass30");
  if (Common_HLT_AK8PFJet400_TrimMass30_branch) Common_HLT_AK8PFJet400_TrimMass30_branch->SetAddress(&Common_HLT_AK8PFJet400_TrimMass30_);
  Common_HLT_AK8PFJet420_TrimMass30_branch = tree->GetBranch("Common_HLT_AK8PFJet420_TrimMass30");
  if (Common_HLT_AK8PFJet420_TrimMass30_branch) Common_HLT_AK8PFJet420_TrimMass30_branch->SetAddress(&Common_HLT_AK8PFJet420_TrimMass30_);
  Common_HLT_AK8PFHT750_TrimMass50_branch = tree->GetBranch("Common_HLT_AK8PFHT750_TrimMass50");
  if (Common_HLT_AK8PFHT750_TrimMass50_branch) Common_HLT_AK8PFHT750_TrimMass50_branch->SetAddress(&Common_HLT_AK8PFHT750_TrimMass50_);
  Common_HLT_AK8PFHT800_TrimMass50_branch = tree->GetBranch("Common_HLT_AK8PFHT800_TrimMass50");
  if (Common_HLT_AK8PFHT800_TrimMass50_branch) Common_HLT_AK8PFHT800_TrimMass50_branch->SetAddress(&Common_HLT_AK8PFHT800_TrimMass50_);
  Common_HLT_AK8PFHT850_TrimMass50_branch = tree->GetBranch("Common_HLT_AK8PFHT850_TrimMass50");
  if (Common_HLT_AK8PFHT850_TrimMass50_branch) Common_HLT_AK8PFHT850_TrimMass50_branch->SetAddress(&Common_HLT_AK8PFHT850_TrimMass50_);
  Common_HLT_AK8PFHT900_TrimMass50_branch = tree->GetBranch("Common_HLT_AK8PFHT900_TrimMass50");
  if (Common_HLT_AK8PFHT900_TrimMass50_branch) Common_HLT_AK8PFHT900_TrimMass50_branch->SetAddress(&Common_HLT_AK8PFHT900_TrimMass50_);
  Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch = tree->GetBranch("Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5");
  if (Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch) Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch->SetAddress(&Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_);
  Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch = tree->GetBranch("Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5");
  if (Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch) Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch->SetAddress(&Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_);
  Common_HLT_PFHT800_branch = tree->GetBranch("Common_HLT_PFHT800");
  if (Common_HLT_PFHT800_branch) Common_HLT_PFHT800_branch->SetAddress(&Common_HLT_PFHT800_);
  Common_HLT_PFHT900_branch = tree->GetBranch("Common_HLT_PFHT900");
  if (Common_HLT_PFHT900_branch) Common_HLT_PFHT900_branch->SetAddress(&Common_HLT_PFHT900_);
  Common_HLT_PFJet450_branch = tree->GetBranch("Common_HLT_PFJet450");
  if (Common_HLT_PFJet450_branch) Common_HLT_PFJet450_branch->SetAddress(&Common_HLT_PFJet450_);
  Common_HLT_PFJet500_branch = tree->GetBranch("Common_HLT_PFJet500");
  if (Common_HLT_PFJet500_branch) Common_HLT_PFJet500_branch->SetAddress(&Common_HLT_PFJet500_);
  Common_HLT_AK8PFJet450_branch = tree->GetBranch("Common_HLT_AK8PFJet450");
  if (Common_HLT_AK8PFJet450_branch) Common_HLT_AK8PFJet450_branch->SetAddress(&Common_HLT_AK8PFJet450_);
  Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch = tree->GetBranch("Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50");
  if (Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch) Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch->SetAddress(&Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_);
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
  Common_passGoodRun_branch = tree->GetBranch("Common_passGoodRun");
  if (Common_passGoodRun_branch) Common_passGoodRun_branch->SetAddress(&Common_passGoodRun_);
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
  Common_event_lepSFTight_branch = tree->GetBranch("Common_event_lepSFTight");
  if (Common_event_lepSFTight_branch) Common_event_lepSFTight_branch->SetAddress(&Common_event_lepSFTight_);
  Common_event_lepSFelupTight_branch = tree->GetBranch("Common_event_lepSFelupTight");
  if (Common_event_lepSFelupTight_branch) Common_event_lepSFelupTight_branch->SetAddress(&Common_event_lepSFelupTight_);
  Common_event_lepSFeldnTight_branch = tree->GetBranch("Common_event_lepSFeldnTight");
  if (Common_event_lepSFeldnTight_branch) Common_event_lepSFeldnTight_branch->SetAddress(&Common_event_lepSFeldnTight_);
  Common_event_lepSFmuupTight_branch = tree->GetBranch("Common_event_lepSFmuupTight");
  if (Common_event_lepSFmuupTight_branch) Common_event_lepSFmuupTight_branch->SetAddress(&Common_event_lepSFmuupTight_);
  Common_event_lepSFmudnTight_branch = tree->GetBranch("Common_event_lepSFmudnTight");
  if (Common_event_lepSFmudnTight_branch) Common_event_lepSFmudnTight_branch->SetAddress(&Common_event_lepSFmudnTight_);
  Common_event_tightBtagSF_branch = tree->GetBranch("Common_event_tightBtagSF");
  if (Common_event_tightBtagSF_branch) Common_event_tightBtagSF_branch->SetAddress(&Common_event_tightBtagSF_);
  Common_event_tightBtagSFup_branch = tree->GetBranch("Common_event_tightBtagSFup");
  if (Common_event_tightBtagSFup_branch) Common_event_tightBtagSFup_branch->SetAddress(&Common_event_tightBtagSFup_);
  Common_event_tightBtagSFdn_branch = tree->GetBranch("Common_event_tightBtagSFdn");
  if (Common_event_tightBtagSFdn_branch) Common_event_tightBtagSFdn_branch->SetAddress(&Common_event_tightBtagSFdn_);
  Common_event_tightBtagSFHFup_branch = tree->GetBranch("Common_event_tightBtagSFHFup");
  if (Common_event_tightBtagSFHFup_branch) Common_event_tightBtagSFHFup_branch->SetAddress(&Common_event_tightBtagSFHFup_);
  Common_event_tightBtagSFHFdn_branch = tree->GetBranch("Common_event_tightBtagSFHFdn");
  if (Common_event_tightBtagSFHFdn_branch) Common_event_tightBtagSFHFdn_branch->SetAddress(&Common_event_tightBtagSFHFdn_);
  Common_event_tightBtagSFLFup_branch = tree->GetBranch("Common_event_tightBtagSFLFup");
  if (Common_event_tightBtagSFLFup_branch) Common_event_tightBtagSFLFup_branch->SetAddress(&Common_event_tightBtagSFLFup_);
  Common_event_tightBtagSFLFdn_branch = tree->GetBranch("Common_event_tightBtagSFLFdn");
  if (Common_event_tightBtagSFLFdn_branch) Common_event_tightBtagSFLFdn_branch->SetAddress(&Common_event_tightBtagSFLFdn_);
  Common_event_mediumBtagSF_branch = tree->GetBranch("Common_event_mediumBtagSF");
  if (Common_event_mediumBtagSF_branch) Common_event_mediumBtagSF_branch->SetAddress(&Common_event_mediumBtagSF_);
  Common_event_mediumBtagSFup_branch = tree->GetBranch("Common_event_mediumBtagSFup");
  if (Common_event_mediumBtagSFup_branch) Common_event_mediumBtagSFup_branch->SetAddress(&Common_event_mediumBtagSFup_);
  Common_event_mediumBtagSFdn_branch = tree->GetBranch("Common_event_mediumBtagSFdn");
  if (Common_event_mediumBtagSFdn_branch) Common_event_mediumBtagSFdn_branch->SetAddress(&Common_event_mediumBtagSFdn_);
  Common_event_mediumBtagSFHFup_branch = tree->GetBranch("Common_event_mediumBtagSFHFup");
  if (Common_event_mediumBtagSFHFup_branch) Common_event_mediumBtagSFHFup_branch->SetAddress(&Common_event_mediumBtagSFHFup_);
  Common_event_mediumBtagSFHFdn_branch = tree->GetBranch("Common_event_mediumBtagSFHFdn");
  if (Common_event_mediumBtagSFHFdn_branch) Common_event_mediumBtagSFHFdn_branch->SetAddress(&Common_event_mediumBtagSFHFdn_);
  Common_event_mediumBtagSFLFup_branch = tree->GetBranch("Common_event_mediumBtagSFLFup");
  if (Common_event_mediumBtagSFLFup_branch) Common_event_mediumBtagSFLFup_branch->SetAddress(&Common_event_mediumBtagSFLFup_);
  Common_event_mediumBtagSFLFdn_branch = tree->GetBranch("Common_event_mediumBtagSFLFdn");
  if (Common_event_mediumBtagSFLFdn_branch) Common_event_mediumBtagSFLFdn_branch->SetAddress(&Common_event_mediumBtagSFLFdn_);
  Common_event_looseBtagSF_branch = tree->GetBranch("Common_event_looseBtagSF");
  if (Common_event_looseBtagSF_branch) Common_event_looseBtagSF_branch->SetAddress(&Common_event_looseBtagSF_);
  Common_event_looseBtagSFup_branch = tree->GetBranch("Common_event_looseBtagSFup");
  if (Common_event_looseBtagSFup_branch) Common_event_looseBtagSFup_branch->SetAddress(&Common_event_looseBtagSFup_);
  Common_event_looseBtagSFdn_branch = tree->GetBranch("Common_event_looseBtagSFdn");
  if (Common_event_looseBtagSFdn_branch) Common_event_looseBtagSFdn_branch->SetAddress(&Common_event_looseBtagSFdn_);
  Common_event_looseBtagSFHFup_branch = tree->GetBranch("Common_event_looseBtagSFHFup");
  if (Common_event_looseBtagSFHFup_branch) Common_event_looseBtagSFHFup_branch->SetAddress(&Common_event_looseBtagSFHFup_);
  Common_event_looseBtagSFHFdn_branch = tree->GetBranch("Common_event_looseBtagSFHFdn");
  if (Common_event_looseBtagSFHFdn_branch) Common_event_looseBtagSFHFdn_branch->SetAddress(&Common_event_looseBtagSFHFdn_);
  Common_event_looseBtagSFLFup_branch = tree->GetBranch("Common_event_looseBtagSFLFup");
  if (Common_event_looseBtagSFLFup_branch) Common_event_looseBtagSFLFup_branch->SetAddress(&Common_event_looseBtagSFLFup_);
  Common_event_looseBtagSFLFdn_branch = tree->GetBranch("Common_event_looseBtagSFLFdn");
  if (Common_event_looseBtagSFLFdn_branch) Common_event_looseBtagSFLFdn_branch->SetAddress(&Common_event_looseBtagSFLFdn_);
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
  Common_lep_ip3d_branch = tree->GetBranch("Common_lep_ip3d");
  if (Common_lep_ip3d_branch) Common_lep_ip3d_branch->SetAddress(&Common_lep_ip3d_);
  Common_lep_sip3d_branch = tree->GetBranch("Common_lep_sip3d");
  if (Common_lep_sip3d_branch) Common_lep_sip3d_branch->SetAddress(&Common_lep_sip3d_);
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
  Common_jet_id_branch = tree->GetBranch("Common_jet_id");
  if (Common_jet_id_branch) Common_jet_id_branch->SetAddress(&Common_jet_id_);
  Common_jet_puid_branch = tree->GetBranch("Common_jet_puid");
  if (Common_jet_puid_branch) Common_jet_puid_branch->SetAddress(&Common_jet_puid_);
  Common_jet_overlapfatjet_branch = tree->GetBranch("Common_jet_overlapfatjet");
  if (Common_jet_overlapfatjet_branch) Common_jet_overlapfatjet_branch->SetAddress(&Common_jet_overlapfatjet_);
  Common_jet_pt_jesup_branch = tree->GetBranch("Common_jet_pt_jesup");
  if (Common_jet_pt_jesup_branch) Common_jet_pt_jesup_branch->SetAddress(&Common_jet_pt_jesup_);
  Common_jet_pt_jesdn_branch = tree->GetBranch("Common_jet_pt_jesdn");
  if (Common_jet_pt_jesdn_branch) Common_jet_pt_jesdn_branch->SetAddress(&Common_jet_pt_jesdn_);
  Common_jet_pt_jerup_branch = tree->GetBranch("Common_jet_pt_jerup");
  if (Common_jet_pt_jerup_branch) Common_jet_pt_jerup_branch->SetAddress(&Common_jet_pt_jerup_);
  Common_jet_pt_jerdn_branch = tree->GetBranch("Common_jet_pt_jerdn");
  if (Common_jet_pt_jerdn_branch) Common_jet_pt_jerdn_branch->SetAddress(&Common_jet_pt_jerdn_);
  Common_jet_mass_jesup_branch = tree->GetBranch("Common_jet_mass_jesup");
  if (Common_jet_mass_jesup_branch) Common_jet_mass_jesup_branch->SetAddress(&Common_jet_mass_jesup_);
  Common_jet_mass_jesdn_branch = tree->GetBranch("Common_jet_mass_jesdn");
  if (Common_jet_mass_jesdn_branch) Common_jet_mass_jesdn_branch->SetAddress(&Common_jet_mass_jesdn_);
  Common_jet_mass_jerup_branch = tree->GetBranch("Common_jet_mass_jerup");
  if (Common_jet_mass_jerup_branch) Common_jet_mass_jerup_branch->SetAddress(&Common_jet_mass_jerup_);
  Common_jet_mass_jerdn_branch = tree->GetBranch("Common_jet_mass_jerdn");
  if (Common_jet_mass_jerdn_branch) Common_jet_mass_jerdn_branch->SetAddress(&Common_jet_mass_jerdn_);
  Common_fatjet_idxs_branch = tree->GetBranch("Common_fatjet_idxs");
  if (Common_fatjet_idxs_branch) Common_fatjet_idxs_branch->SetAddress(&Common_fatjet_idxs_);
  Common_fatjet_id_branch = tree->GetBranch("Common_fatjet_id");
  if (Common_fatjet_id_branch) Common_fatjet_id_branch->SetAddress(&Common_fatjet_id_);
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
  Common_fatjet_particleNetMD_W_branch = tree->GetBranch("Common_fatjet_particleNetMD_W");
  if (Common_fatjet_particleNetMD_W_branch) Common_fatjet_particleNetMD_W_branch->SetAddress(&Common_fatjet_particleNetMD_W_);
  Common_fatjet_particleNetMD_Xqq_branch = tree->GetBranch("Common_fatjet_particleNetMD_Xqq");
  if (Common_fatjet_particleNetMD_Xqq_branch) Common_fatjet_particleNetMD_Xqq_branch->SetAddress(&Common_fatjet_particleNetMD_Xqq_);
  Common_fatjet_particleNetMD_Xcc_branch = tree->GetBranch("Common_fatjet_particleNetMD_Xcc");
  if (Common_fatjet_particleNetMD_Xcc_branch) Common_fatjet_particleNetMD_Xcc_branch->SetAddress(&Common_fatjet_particleNetMD_Xcc_);
  Common_fatjet_particleNetMD_Xbb_branch = tree->GetBranch("Common_fatjet_particleNetMD_Xbb");
  if (Common_fatjet_particleNetMD_Xbb_branch) Common_fatjet_particleNetMD_Xbb_branch->SetAddress(&Common_fatjet_particleNetMD_Xbb_);
  Common_fatjet_particleNetMD_QCD_branch = tree->GetBranch("Common_fatjet_particleNetMD_QCD");
  if (Common_fatjet_particleNetMD_QCD_branch) Common_fatjet_particleNetMD_QCD_branch->SetAddress(&Common_fatjet_particleNetMD_QCD_);
  Common_fatjet_particleNet_QCD_branch = tree->GetBranch("Common_fatjet_particleNet_QCD");
  if (Common_fatjet_particleNet_QCD_branch) Common_fatjet_particleNet_QCD_branch->SetAddress(&Common_fatjet_particleNet_QCD_);
  Common_fatjet_particleNet_W_branch = tree->GetBranch("Common_fatjet_particleNet_W");
  if (Common_fatjet_particleNet_W_branch) Common_fatjet_particleNet_W_branch->SetAddress(&Common_fatjet_particleNet_W_);
  Common_fatjet_particleNet_Z_branch = tree->GetBranch("Common_fatjet_particleNet_Z");
  if (Common_fatjet_particleNet_Z_branch) Common_fatjet_particleNet_Z_branch->SetAddress(&Common_fatjet_particleNet_Z_);
  Common_fatjet_particleNet_T_branch = tree->GetBranch("Common_fatjet_particleNet_T");
  if (Common_fatjet_particleNet_T_branch) Common_fatjet_particleNet_T_branch->SetAddress(&Common_fatjet_particleNet_T_);
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
  Common_fatjet_WP_MD_branch = tree->GetBranch("Common_fatjet_WP_MD");
  if (Common_fatjet_WP_MD_branch) Common_fatjet_WP_MD_branch->SetAddress(&Common_fatjet_WP_MD_);
  Common_fatjet_WP_antimasscut_branch = tree->GetBranch("Common_fatjet_WP_antimasscut");
  if (Common_fatjet_WP_antimasscut_branch) Common_fatjet_WP_antimasscut_branch->SetAddress(&Common_fatjet_WP_antimasscut_);
  Common_fatjet_WP_MD_antimasscut_branch = tree->GetBranch("Common_fatjet_WP_MD_antimasscut");
  if (Common_fatjet_WP_MD_antimasscut_branch) Common_fatjet_WP_MD_antimasscut_branch->SetAddress(&Common_fatjet_WP_MD_antimasscut_);
  Common_fatjet_SFVLoose_branch = tree->GetBranch("Common_fatjet_SFVLoose");
  if (Common_fatjet_SFVLoose_branch) Common_fatjet_SFVLoose_branch->SetAddress(&Common_fatjet_SFVLoose_);
  Common_fatjet_SFLoose_branch = tree->GetBranch("Common_fatjet_SFLoose");
  if (Common_fatjet_SFLoose_branch) Common_fatjet_SFLoose_branch->SetAddress(&Common_fatjet_SFLoose_);
  Common_fatjet_SFMedium_branch = tree->GetBranch("Common_fatjet_SFMedium");
  if (Common_fatjet_SFMedium_branch) Common_fatjet_SFMedium_branch->SetAddress(&Common_fatjet_SFMedium_);
  Common_fatjet_SFTight_branch = tree->GetBranch("Common_fatjet_SFTight");
  if (Common_fatjet_SFTight_branch) Common_fatjet_SFTight_branch->SetAddress(&Common_fatjet_SFTight_);
  Common_fatjet_SFdnLoose_branch = tree->GetBranch("Common_fatjet_SFdnLoose");
  if (Common_fatjet_SFdnLoose_branch) Common_fatjet_SFdnLoose_branch->SetAddress(&Common_fatjet_SFdnLoose_);
  Common_fatjet_SFdnVLoose_branch = tree->GetBranch("Common_fatjet_SFdnVLoose");
  if (Common_fatjet_SFdnVLoose_branch) Common_fatjet_SFdnVLoose_branch->SetAddress(&Common_fatjet_SFdnVLoose_);
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
  Common_fatjet_MD_SFLoose_branch = tree->GetBranch("Common_fatjet_MD_SFLoose");
  if (Common_fatjet_MD_SFLoose_branch) Common_fatjet_MD_SFLoose_branch->SetAddress(&Common_fatjet_MD_SFLoose_);
  Common_fatjet_MD_SFMedium_branch = tree->GetBranch("Common_fatjet_MD_SFMedium");
  if (Common_fatjet_MD_SFMedium_branch) Common_fatjet_MD_SFMedium_branch->SetAddress(&Common_fatjet_MD_SFMedium_);
  Common_fatjet_MD_SFTight_branch = tree->GetBranch("Common_fatjet_MD_SFTight");
  if (Common_fatjet_MD_SFTight_branch) Common_fatjet_MD_SFTight_branch->SetAddress(&Common_fatjet_MD_SFTight_);
  Common_fatjet_MD_SFdnLoose_branch = tree->GetBranch("Common_fatjet_MD_SFdnLoose");
  if (Common_fatjet_MD_SFdnLoose_branch) Common_fatjet_MD_SFdnLoose_branch->SetAddress(&Common_fatjet_MD_SFdnLoose_);
  Common_fatjet_MD_SFdnMedium_branch = tree->GetBranch("Common_fatjet_MD_SFdnMedium");
  if (Common_fatjet_MD_SFdnMedium_branch) Common_fatjet_MD_SFdnMedium_branch->SetAddress(&Common_fatjet_MD_SFdnMedium_);
  Common_fatjet_MD_SFdnTight_branch = tree->GetBranch("Common_fatjet_MD_SFdnTight");
  if (Common_fatjet_MD_SFdnTight_branch) Common_fatjet_MD_SFdnTight_branch->SetAddress(&Common_fatjet_MD_SFdnTight_);
  Common_fatjet_MD_SFupLoose_branch = tree->GetBranch("Common_fatjet_MD_SFupLoose");
  if (Common_fatjet_MD_SFupLoose_branch) Common_fatjet_MD_SFupLoose_branch->SetAddress(&Common_fatjet_MD_SFupLoose_);
  Common_fatjet_MD_SFupMedium_branch = tree->GetBranch("Common_fatjet_MD_SFupMedium");
  if (Common_fatjet_MD_SFupMedium_branch) Common_fatjet_MD_SFupMedium_branch->SetAddress(&Common_fatjet_MD_SFupMedium_);
  Common_fatjet_MD_SFupTight_branch = tree->GetBranch("Common_fatjet_MD_SFupTight");
  if (Common_fatjet_MD_SFupTight_branch) Common_fatjet_MD_SFupTight_branch->SetAddress(&Common_fatjet_MD_SFupTight_);
  Common_fatjet_pt_jesup_branch = tree->GetBranch("Common_fatjet_pt_jesup");
  if (Common_fatjet_pt_jesup_branch) Common_fatjet_pt_jesup_branch->SetAddress(&Common_fatjet_pt_jesup_);
  Common_fatjet_pt_jesdn_branch = tree->GetBranch("Common_fatjet_pt_jesdn");
  if (Common_fatjet_pt_jesdn_branch) Common_fatjet_pt_jesdn_branch->SetAddress(&Common_fatjet_pt_jesdn_);
  Common_fatjet_pt_jerup_branch = tree->GetBranch("Common_fatjet_pt_jerup");
  if (Common_fatjet_pt_jerup_branch) Common_fatjet_pt_jerup_branch->SetAddress(&Common_fatjet_pt_jerup_);
  Common_fatjet_pt_jerdn_branch = tree->GetBranch("Common_fatjet_pt_jerdn");
  if (Common_fatjet_pt_jerdn_branch) Common_fatjet_pt_jerdn_branch->SetAddress(&Common_fatjet_pt_jerdn_);
  Common_fatjet_msoftdrop_jesup_branch = tree->GetBranch("Common_fatjet_msoftdrop_jesup");
  if (Common_fatjet_msoftdrop_jesup_branch) Common_fatjet_msoftdrop_jesup_branch->SetAddress(&Common_fatjet_msoftdrop_jesup_);
  Common_fatjet_msoftdrop_jesdn_branch = tree->GetBranch("Common_fatjet_msoftdrop_jesdn");
  if (Common_fatjet_msoftdrop_jesdn_branch) Common_fatjet_msoftdrop_jesdn_branch->SetAddress(&Common_fatjet_msoftdrop_jesdn_);
  Common_fatjet_msoftdrop_jerup_branch = tree->GetBranch("Common_fatjet_msoftdrop_jerup");
  if (Common_fatjet_msoftdrop_jerup_branch) Common_fatjet_msoftdrop_jerup_branch->SetAddress(&Common_fatjet_msoftdrop_jerup_);
  Common_fatjet_msoftdrop_jerdn_branch = tree->GetBranch("Common_fatjet_msoftdrop_jerdn");
  if (Common_fatjet_msoftdrop_jerdn_branch) Common_fatjet_msoftdrop_jerdn_branch->SetAddress(&Common_fatjet_msoftdrop_jerdn_);
  Common_fatjet_msoftdrop_jmsup_branch = tree->GetBranch("Common_fatjet_msoftdrop_jmsup");
  if (Common_fatjet_msoftdrop_jmsup_branch) Common_fatjet_msoftdrop_jmsup_branch->SetAddress(&Common_fatjet_msoftdrop_jmsup_);
  Common_fatjet_msoftdrop_jmsdn_branch = tree->GetBranch("Common_fatjet_msoftdrop_jmsdn");
  if (Common_fatjet_msoftdrop_jmsdn_branch) Common_fatjet_msoftdrop_jmsdn_branch->SetAddress(&Common_fatjet_msoftdrop_jmsdn_);
  Common_fatjet_msoftdrop_jmrup_branch = tree->GetBranch("Common_fatjet_msoftdrop_jmrup");
  if (Common_fatjet_msoftdrop_jmrup_branch) Common_fatjet_msoftdrop_jmrup_branch->SetAddress(&Common_fatjet_msoftdrop_jmrup_);
  Common_fatjet_msoftdrop_jmrdn_branch = tree->GetBranch("Common_fatjet_msoftdrop_jmrdn");
  if (Common_fatjet_msoftdrop_jmrdn_branch) Common_fatjet_msoftdrop_jmrdn_branch->SetAddress(&Common_fatjet_msoftdrop_jmrdn_);
  Common_fatjet_mass_jesup_branch = tree->GetBranch("Common_fatjet_mass_jesup");
  if (Common_fatjet_mass_jesup_branch) Common_fatjet_mass_jesup_branch->SetAddress(&Common_fatjet_mass_jesup_);
  Common_fatjet_mass_jesdn_branch = tree->GetBranch("Common_fatjet_mass_jesdn");
  if (Common_fatjet_mass_jesdn_branch) Common_fatjet_mass_jesdn_branch->SetAddress(&Common_fatjet_mass_jesdn_);
  Common_fatjet_mass_jerup_branch = tree->GetBranch("Common_fatjet_mass_jerup");
  if (Common_fatjet_mass_jerup_branch) Common_fatjet_mass_jerup_branch->SetAddress(&Common_fatjet_mass_jerup_);
  Common_fatjet_mass_jerdn_branch = tree->GetBranch("Common_fatjet_mass_jerdn");
  if (Common_fatjet_mass_jerdn_branch) Common_fatjet_mass_jerdn_branch->SetAddress(&Common_fatjet_mass_jerdn_);
  Common_fatjet_mass_jmsup_branch = tree->GetBranch("Common_fatjet_mass_jmsup");
  if (Common_fatjet_mass_jmsup_branch) Common_fatjet_mass_jmsup_branch->SetAddress(&Common_fatjet_mass_jmsup_);
  Common_fatjet_mass_jmsdn_branch = tree->GetBranch("Common_fatjet_mass_jmsdn");
  if (Common_fatjet_mass_jmsdn_branch) Common_fatjet_mass_jmsdn_branch->SetAddress(&Common_fatjet_mass_jmsdn_);
  Common_fatjet_mass_jmrup_branch = tree->GetBranch("Common_fatjet_mass_jmrup");
  if (Common_fatjet_mass_jmrup_branch) Common_fatjet_mass_jmrup_branch->SetAddress(&Common_fatjet_mass_jmrup_);
  Common_fatjet_mass_jmrdn_branch = tree->GetBranch("Common_fatjet_mass_jmrdn");
  if (Common_fatjet_mass_jmrdn_branch) Common_fatjet_mass_jmrdn_branch->SetAddress(&Common_fatjet_mass_jmrdn_);
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
  Common_eventweight_fatjet_MD_SFLoose_branch = tree->GetBranch("Common_eventweight_fatjet_MD_SFLoose");
  if (Common_eventweight_fatjet_MD_SFLoose_branch) Common_eventweight_fatjet_MD_SFLoose_branch->SetAddress(&Common_eventweight_fatjet_MD_SFLoose_);
  Common_eventweight_fatjet_MD_SFMedium_branch = tree->GetBranch("Common_eventweight_fatjet_MD_SFMedium");
  if (Common_eventweight_fatjet_MD_SFMedium_branch) Common_eventweight_fatjet_MD_SFMedium_branch->SetAddress(&Common_eventweight_fatjet_MD_SFMedium_);
  Common_eventweight_fatjet_MD_SFTight_branch = tree->GetBranch("Common_eventweight_fatjet_MD_SFTight");
  if (Common_eventweight_fatjet_MD_SFTight_branch) Common_eventweight_fatjet_MD_SFTight_branch->SetAddress(&Common_eventweight_fatjet_MD_SFTight_);
  Common_eventweight_fatjet_MD_SFdnLoose_branch = tree->GetBranch("Common_eventweight_fatjet_MD_SFdnLoose");
  if (Common_eventweight_fatjet_MD_SFdnLoose_branch) Common_eventweight_fatjet_MD_SFdnLoose_branch->SetAddress(&Common_eventweight_fatjet_MD_SFdnLoose_);
  Common_eventweight_fatjet_MD_SFdnMedium_branch = tree->GetBranch("Common_eventweight_fatjet_MD_SFdnMedium");
  if (Common_eventweight_fatjet_MD_SFdnMedium_branch) Common_eventweight_fatjet_MD_SFdnMedium_branch->SetAddress(&Common_eventweight_fatjet_MD_SFdnMedium_);
  Common_eventweight_fatjet_MD_SFdnTight_branch = tree->GetBranch("Common_eventweight_fatjet_MD_SFdnTight");
  if (Common_eventweight_fatjet_MD_SFdnTight_branch) Common_eventweight_fatjet_MD_SFdnTight_branch->SetAddress(&Common_eventweight_fatjet_MD_SFdnTight_);
  Common_eventweight_fatjet_MD_SFupLoose_branch = tree->GetBranch("Common_eventweight_fatjet_MD_SFupLoose");
  if (Common_eventweight_fatjet_MD_SFupLoose_branch) Common_eventweight_fatjet_MD_SFupLoose_branch->SetAddress(&Common_eventweight_fatjet_MD_SFupLoose_);
  Common_eventweight_fatjet_MD_SFupMedium_branch = tree->GetBranch("Common_eventweight_fatjet_MD_SFupMedium");
  if (Common_eventweight_fatjet_MD_SFupMedium_branch) Common_eventweight_fatjet_MD_SFupMedium_branch->SetAddress(&Common_eventweight_fatjet_MD_SFupMedium_);
  Common_eventweight_fatjet_MD_SFupTight_branch = tree->GetBranch("Common_eventweight_fatjet_MD_SFupTight");
  if (Common_eventweight_fatjet_MD_SFupTight_branch) Common_eventweight_fatjet_MD_SFupTight_branch->SetAddress(&Common_eventweight_fatjet_MD_SFupTight_);
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
  Common_isSignal_branch = tree->GetBranch("Common_isSignal");
  if (Common_isSignal_branch) Common_isSignal_branch->SetAddress(&Common_isSignal_);
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
  Common_gen_VH_channel_branch = tree->GetBranch("Common_gen_VH_channel");
  if (Common_gen_VH_channel_branch) Common_gen_VH_channel_branch->SetAddress(&Common_gen_VH_channel_);
  allHad_fatjets_WP_MD_branch = tree->GetBranch("allHad_fatjets_WP_MD");
  if (allHad_fatjets_WP_MD_branch) allHad_fatjets_WP_MD_branch->SetAddress(&allHad_fatjets_WP_MD_);
  allHad_fatjets_commonFJIdxs_branch = tree->GetBranch("allHad_fatjets_commonFJIdxs");
  if (allHad_fatjets_commonFJIdxs_branch) allHad_fatjets_commonFJIdxs_branch->SetAddress(&allHad_fatjets_commonFJIdxs_);
  allHad_nFJ_branch = tree->GetBranch("allHad_nFJ");
  if (allHad_nFJ_branch) allHad_nFJ_branch->SetAddress(&allHad_nFJ_);
  allHad_FJ0_WP_MD_branch = tree->GetBranch("allHad_FJ0_WP_MD");
  if (allHad_FJ0_WP_MD_branch) allHad_FJ0_WP_MD_branch->SetAddress(&allHad_FJ0_WP_MD_);
  allHad_FJ1_WP_MD_branch = tree->GetBranch("allHad_FJ1_WP_MD");
  if (allHad_FJ1_WP_MD_branch) allHad_FJ1_WP_MD_branch->SetAddress(&allHad_FJ1_WP_MD_);
  allHad_FJ2_WP_MD_branch = tree->GetBranch("allHad_FJ2_WP_MD");
  if (allHad_FJ2_WP_MD_branch) allHad_FJ2_WP_MD_branch->SetAddress(&allHad_FJ2_WP_MD_);
  allHad_FJ0_WMD_branch = tree->GetBranch("allHad_FJ0_WMD");
  if (allHad_FJ0_WMD_branch) allHad_FJ0_WMD_branch->SetAddress(&allHad_FJ0_WMD_);
  allHad_FJ1_WMD_branch = tree->GetBranch("allHad_FJ1_WMD");
  if (allHad_FJ1_WMD_branch) allHad_FJ1_WMD_branch->SetAddress(&allHad_FJ1_WMD_);
  allHad_FJ2_WMD_branch = tree->GetBranch("allHad_FJ2_WMD");
  if (allHad_FJ2_WMD_branch) allHad_FJ2_WMD_branch->SetAddress(&allHad_FJ2_WMD_);
  allHad_FJ0_VMD_branch = tree->GetBranch("allHad_FJ0_VMD");
  if (allHad_FJ0_VMD_branch) allHad_FJ0_VMD_branch->SetAddress(&allHad_FJ0_VMD_);
  allHad_FJ1_VMD_branch = tree->GetBranch("allHad_FJ1_VMD");
  if (allHad_FJ1_VMD_branch) allHad_FJ1_VMD_branch->SetAddress(&allHad_FJ1_VMD_);
  allHad_FJ2_VMD_branch = tree->GetBranch("allHad_FJ2_VMD");
  if (allHad_FJ2_VMD_branch) allHad_FJ2_VMD_branch->SetAddress(&allHad_FJ2_VMD_);
  allHad_FJ0_Xqq_branch = tree->GetBranch("allHad_FJ0_Xqq");
  if (allHad_FJ0_Xqq_branch) allHad_FJ0_Xqq_branch->SetAddress(&allHad_FJ0_Xqq_);
  allHad_FJ1_Xqq_branch = tree->GetBranch("allHad_FJ1_Xqq");
  if (allHad_FJ1_Xqq_branch) allHad_FJ1_Xqq_branch->SetAddress(&allHad_FJ1_Xqq_);
  allHad_FJ2_Xqq_branch = tree->GetBranch("allHad_FJ2_Xqq");
  if (allHad_FJ2_Xqq_branch) allHad_FJ2_Xqq_branch->SetAddress(&allHad_FJ2_Xqq_);
  allHad_FJ0_Xcc_branch = tree->GetBranch("allHad_FJ0_Xcc");
  if (allHad_FJ0_Xcc_branch) allHad_FJ0_Xcc_branch->SetAddress(&allHad_FJ0_Xcc_);
  allHad_FJ1_Xcc_branch = tree->GetBranch("allHad_FJ1_Xcc");
  if (allHad_FJ1_Xcc_branch) allHad_FJ1_Xcc_branch->SetAddress(&allHad_FJ1_Xcc_);
  allHad_FJ2_Xcc_branch = tree->GetBranch("allHad_FJ2_Xcc");
  if (allHad_FJ2_Xcc_branch) allHad_FJ2_Xcc_branch->SetAddress(&allHad_FJ2_Xcc_);
  allHad_FJ0_Xbb_branch = tree->GetBranch("allHad_FJ0_Xbb");
  if (allHad_FJ0_Xbb_branch) allHad_FJ0_Xbb_branch->SetAddress(&allHad_FJ0_Xbb_);
  allHad_FJ1_Xbb_branch = tree->GetBranch("allHad_FJ1_Xbb");
  if (allHad_FJ1_Xbb_branch) allHad_FJ1_Xbb_branch->SetAddress(&allHad_FJ1_Xbb_);
  allHad_FJ2_Xbb_branch = tree->GetBranch("allHad_FJ2_Xbb");
  if (allHad_FJ2_Xbb_branch) allHad_FJ2_Xbb_branch->SetAddress(&allHad_FJ2_Xbb_);
  allHad_FJ0_QCD_branch = tree->GetBranch("allHad_FJ0_QCD");
  if (allHad_FJ0_QCD_branch) allHad_FJ0_QCD_branch->SetAddress(&allHad_FJ0_QCD_);
  allHad_FJ1_QCD_branch = tree->GetBranch("allHad_FJ1_QCD");
  if (allHad_FJ1_QCD_branch) allHad_FJ1_QCD_branch->SetAddress(&allHad_FJ1_QCD_);
  allHad_FJ2_QCD_branch = tree->GetBranch("allHad_FJ2_QCD");
  if (allHad_FJ2_QCD_branch) allHad_FJ2_QCD_branch->SetAddress(&allHad_FJ2_QCD_);
  allHad_FJ0_commonFJIdxs_branch = tree->GetBranch("allHad_FJ0_commonFJIdxs");
  if (allHad_FJ0_commonFJIdxs_branch) allHad_FJ0_commonFJIdxs_branch->SetAddress(&allHad_FJ0_commonFJIdxs_);
  allHad_FJ1_commonFJIdxs_branch = tree->GetBranch("allHad_FJ1_commonFJIdxs");
  if (allHad_FJ1_commonFJIdxs_branch) allHad_FJ1_commonFJIdxs_branch->SetAddress(&allHad_FJ1_commonFJIdxs_);
  allHad_FJ2_commonFJIdxs_branch = tree->GetBranch("allHad_FJ2_commonFJIdxs");
  if (allHad_FJ2_commonFJIdxs_branch) allHad_FJ2_commonFJIdxs_branch->SetAddress(&allHad_FJ2_commonFJIdxs_);
  allHad_mVVV_branch = tree->GetBranch("allHad_mVVV");
  if (allHad_mVVV_branch) allHad_mVVV_branch->SetAddress(&allHad_mVVV_);
  allHad_ptVVV_branch = tree->GetBranch("allHad_ptVVV");
  if (allHad_ptVVV_branch) allHad_ptVVV_branch->SetAddress(&allHad_ptVVV_);
  allHad_HT_branch = tree->GetBranch("allHad_HT");
  if (allHad_HT_branch) allHad_HT_branch->SetAddress(&allHad_HT_);
  allHad_HT_FJ_branch = tree->GetBranch("allHad_HT_FJ");
  if (allHad_HT_FJ_branch) allHad_HT_FJ_branch->SetAddress(&allHad_HT_FJ_);
  allHad_FJ01_dPhi_branch = tree->GetBranch("allHad_FJ01_dPhi");
  if (allHad_FJ01_dPhi_branch) allHad_FJ01_dPhi_branch->SetAddress(&allHad_FJ01_dPhi_);
  allHad_FJ01_dEta_branch = tree->GetBranch("allHad_FJ01_dEta");
  if (allHad_FJ01_dEta_branch) allHad_FJ01_dEta_branch->SetAddress(&allHad_FJ01_dEta_);
  allHad_FJ01_dR_branch = tree->GetBranch("allHad_FJ01_dR");
  if (allHad_FJ01_dR_branch) allHad_FJ01_dR_branch->SetAddress(&allHad_FJ01_dR_);
  allHad_FJ01_dPtFrac_branch = tree->GetBranch("allHad_FJ01_dPtFrac");
  if (allHad_FJ01_dPtFrac_branch) allHad_FJ01_dPtFrac_branch->SetAddress(&allHad_FJ01_dPtFrac_);
  allHad_FJ01_pPRel_branch = tree->GetBranch("allHad_FJ01_pPRel");
  if (allHad_FJ01_pPRel_branch) allHad_FJ01_pPRel_branch->SetAddress(&allHad_FJ01_pPRel_);
  allHad_FJ02_dPhi_branch = tree->GetBranch("allHad_FJ02_dPhi");
  if (allHad_FJ02_dPhi_branch) allHad_FJ02_dPhi_branch->SetAddress(&allHad_FJ02_dPhi_);
  allHad_FJ02_dEta_branch = tree->GetBranch("allHad_FJ02_dEta");
  if (allHad_FJ02_dEta_branch) allHad_FJ02_dEta_branch->SetAddress(&allHad_FJ02_dEta_);
  allHad_FJ02_dR_branch = tree->GetBranch("allHad_FJ02_dR");
  if (allHad_FJ02_dR_branch) allHad_FJ02_dR_branch->SetAddress(&allHad_FJ02_dR_);
  allHad_FJ02_dPtFrac_branch = tree->GetBranch("allHad_FJ02_dPtFrac");
  if (allHad_FJ02_dPtFrac_branch) allHad_FJ02_dPtFrac_branch->SetAddress(&allHad_FJ02_dPtFrac_);
  allHad_FJ02_pPRel_branch = tree->GetBranch("allHad_FJ02_pPRel");
  if (allHad_FJ02_pPRel_branch) allHad_FJ02_pPRel_branch->SetAddress(&allHad_FJ02_pPRel_);
  allHad_FJ12_dPhi_branch = tree->GetBranch("allHad_FJ12_dPhi");
  if (allHad_FJ12_dPhi_branch) allHad_FJ12_dPhi_branch->SetAddress(&allHad_FJ12_dPhi_);
  allHad_FJ12_dEta_branch = tree->GetBranch("allHad_FJ12_dEta");
  if (allHad_FJ12_dEta_branch) allHad_FJ12_dEta_branch->SetAddress(&allHad_FJ12_dEta_);
  allHad_FJ12_dR_branch = tree->GetBranch("allHad_FJ12_dR");
  if (allHad_FJ12_dR_branch) allHad_FJ12_dR_branch->SetAddress(&allHad_FJ12_dR_);
  allHad_FJ12_dPtFrac_branch = tree->GetBranch("allHad_FJ12_dPtFrac");
  if (allHad_FJ12_dPtFrac_branch) allHad_FJ12_dPtFrac_branch->SetAddress(&allHad_FJ12_dPtFrac_);
  allHad_FJ12_pPRel_branch = tree->GetBranch("allHad_FJ12_pPRel");
  if (allHad_FJ12_pPRel_branch) allHad_FJ12_pPRel_branch->SetAddress(&allHad_FJ12_pPRel_);

  tree->SetMakeClass(0);
}

void VVV0LepTree::GetEntry(unsigned int idx) {
  // this only marks branches as not loaded, saving a lot of time
  index = idx;
  Common_isData_isLoaded = false;
  Common_run_isLoaded = false;
  Common_lumi_isLoaded = false;
  Common_evt_isLoaded = false;
  Common_year_isLoaded = false;
  Common_genWeight_isLoaded = false;
  Common_btagWeight_DeepCSVB_isLoaded = false;
  Common_wgt_isLoaded = false;
  Common_event_puWeight_isLoaded = false;
  Common_event_puWeightup_isLoaded = false;
  Common_event_puWeightdn_isLoaded = false;
  Common_event_prefireWeight_isLoaded = false;
  Common_event_prefireWeightup_isLoaded = false;
  Common_event_prefireWeightdn_isLoaded = false;
  Common_event_triggerWeight_isLoaded = false;
  Common_event_triggerWeightup_isLoaded = false;
  Common_event_triggerWeightdn_isLoaded = false;
  Common_LHEReweightingWeight_isLoaded = false;
  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_isLoaded = false;
  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_isLoaded = false;
  Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_isLoaded = false;
  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = false;
  Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = false;
  Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_isLoaded = false;
  Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_isLoaded = false;
  Common_HLT_IsoMu24_isLoaded = false;
  Common_HLT_Ele32_WPTight_isLoaded = false;
  Common_HLT_PFHT1050_isLoaded = false;
  Common_HLT_AK8PFJet500_isLoaded = false;
  Common_HLT_AK8PFJet380_TrimMass30_isLoaded = false;
  Common_HLT_AK8PFJet360_TrimMass30_isLoaded = false;
  Common_HLT_AK8PFJet400_TrimMass30_isLoaded = false;
  Common_HLT_AK8PFJet420_TrimMass30_isLoaded = false;
  Common_HLT_AK8PFHT750_TrimMass50_isLoaded = false;
  Common_HLT_AK8PFHT800_TrimMass50_isLoaded = false;
  Common_HLT_AK8PFHT850_TrimMass50_isLoaded = false;
  Common_HLT_AK8PFHT900_TrimMass50_isLoaded = false;
  Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_isLoaded = false;
  Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_isLoaded = false;
  Common_HLT_PFHT800_isLoaded = false;
  Common_HLT_PFHT900_isLoaded = false;
  Common_HLT_PFJet450_isLoaded = false;
  Common_HLT_PFJet500_isLoaded = false;
  Common_HLT_AK8PFJet450_isLoaded = false;
  Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_isLoaded = false;
  Common_HLT_DoubleEl_isLoaded = false;
  Common_HLT_MuEG_isLoaded = false;
  Common_HLT_DoubleMu_isLoaded = false;
  Common_pass_duplicate_removal_ee_em_mm_isLoaded = false;
  Common_pass_duplicate_removal_mm_em_ee_isLoaded = false;
  Common_noiseFlag_isLoaded = false;
  Common_noiseFlagMC_isLoaded = false;
  Common_passGoodRun_isLoaded = false;
  Common_met_p4_isLoaded = false;
  Common_met_p4_jesup_isLoaded = false;
  Common_met_p4_jesdn_isLoaded = false;
  Common_met_p4_jerup_isLoaded = false;
  Common_met_p4_jerdn_isLoaded = false;
  Common_event_lepSF_isLoaded = false;
  Common_event_lepSFelup_isLoaded = false;
  Common_event_lepSFeldn_isLoaded = false;
  Common_event_lepSFmuup_isLoaded = false;
  Common_event_lepSFmudn_isLoaded = false;
  Common_event_lepSFTight_isLoaded = false;
  Common_event_lepSFelupTight_isLoaded = false;
  Common_event_lepSFeldnTight_isLoaded = false;
  Common_event_lepSFmuupTight_isLoaded = false;
  Common_event_lepSFmudnTight_isLoaded = false;
  Common_event_tightBtagSF_isLoaded = false;
  Common_event_tightBtagSFup_isLoaded = false;
  Common_event_tightBtagSFdn_isLoaded = false;
  Common_event_tightBtagSFHFup_isLoaded = false;
  Common_event_tightBtagSFHFdn_isLoaded = false;
  Common_event_tightBtagSFLFup_isLoaded = false;
  Common_event_tightBtagSFLFdn_isLoaded = false;
  Common_event_mediumBtagSF_isLoaded = false;
  Common_event_mediumBtagSFup_isLoaded = false;
  Common_event_mediumBtagSFdn_isLoaded = false;
  Common_event_mediumBtagSFHFup_isLoaded = false;
  Common_event_mediumBtagSFHFdn_isLoaded = false;
  Common_event_mediumBtagSFLFup_isLoaded = false;
  Common_event_mediumBtagSFLFdn_isLoaded = false;
  Common_event_looseBtagSF_isLoaded = false;
  Common_event_looseBtagSFup_isLoaded = false;
  Common_event_looseBtagSFdn_isLoaded = false;
  Common_event_looseBtagSFHFup_isLoaded = false;
  Common_event_looseBtagSFHFdn_isLoaded = false;
  Common_event_looseBtagSFLFup_isLoaded = false;
  Common_event_looseBtagSFLFdn_isLoaded = false;
  Common_lep_p4_isLoaded = false;
  Common_lep_idxs_isLoaded = false;
  Common_lep_pdgid_isLoaded = false;
  Common_lep_tight_isLoaded = false;
  Common_lep_dxy_isLoaded = false;
  Common_lep_dz_isLoaded = false;
  Common_lep_ip3d_isLoaded = false;
  Common_lep_sip3d_isLoaded = false;
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
  Common_jet_id_isLoaded = false;
  Common_jet_puid_isLoaded = false;
  Common_jet_overlapfatjet_isLoaded = false;
  Common_jet_pt_jesup_isLoaded = false;
  Common_jet_pt_jesdn_isLoaded = false;
  Common_jet_pt_jerup_isLoaded = false;
  Common_jet_pt_jerdn_isLoaded = false;
  Common_jet_mass_jesup_isLoaded = false;
  Common_jet_mass_jesdn_isLoaded = false;
  Common_jet_mass_jerup_isLoaded = false;
  Common_jet_mass_jerdn_isLoaded = false;
  Common_fatjet_p4_isLoaded = false;
  Common_fatjet_idxs_isLoaded = false;
  Common_fatjet_id_isLoaded = false;
  Common_fatjet_msoftdrop_isLoaded = false;
  Common_fatjet_deepMD_W_isLoaded = false;
  Common_fatjet_deep_W_isLoaded = false;
  Common_fatjet_deepMD_Z_isLoaded = false;
  Common_fatjet_deep_Z_isLoaded = false;
  Common_fatjet_deepMD_T_isLoaded = false;
  Common_fatjet_deep_T_isLoaded = false;
  Common_fatjet_deepMD_bb_isLoaded = false;
  Common_fatjet_particleNetMD_W_isLoaded = false;
  Common_fatjet_particleNetMD_Xqq_isLoaded = false;
  Common_fatjet_particleNetMD_Xcc_isLoaded = false;
  Common_fatjet_particleNetMD_Xbb_isLoaded = false;
  Common_fatjet_particleNetMD_QCD_isLoaded = false;
  Common_fatjet_particleNet_QCD_isLoaded = false;
  Common_fatjet_particleNet_W_isLoaded = false;
  Common_fatjet_particleNet_Z_isLoaded = false;
  Common_fatjet_particleNet_T_isLoaded = false;
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
  Common_fatjet_WP_MD_isLoaded = false;
  Common_fatjet_WP_antimasscut_isLoaded = false;
  Common_fatjet_WP_MD_antimasscut_isLoaded = false;
  Common_fatjet_SFVLoose_isLoaded = false;
  Common_fatjet_SFLoose_isLoaded = false;
  Common_fatjet_SFMedium_isLoaded = false;
  Common_fatjet_SFTight_isLoaded = false;
  Common_fatjet_SFdnLoose_isLoaded = false;
  Common_fatjet_SFdnVLoose_isLoaded = false;
  Common_fatjet_SFdnMedium_isLoaded = false;
  Common_fatjet_SFdnTight_isLoaded = false;
  Common_fatjet_SFupVLoose_isLoaded = false;
  Common_fatjet_SFupLoose_isLoaded = false;
  Common_fatjet_SFupMedium_isLoaded = false;
  Common_fatjet_SFupTight_isLoaded = false;
  Common_fatjet_MD_SFLoose_isLoaded = false;
  Common_fatjet_MD_SFMedium_isLoaded = false;
  Common_fatjet_MD_SFTight_isLoaded = false;
  Common_fatjet_MD_SFdnLoose_isLoaded = false;
  Common_fatjet_MD_SFdnMedium_isLoaded = false;
  Common_fatjet_MD_SFdnTight_isLoaded = false;
  Common_fatjet_MD_SFupLoose_isLoaded = false;
  Common_fatjet_MD_SFupMedium_isLoaded = false;
  Common_fatjet_MD_SFupTight_isLoaded = false;
  Common_fatjet_pt_jesup_isLoaded = false;
  Common_fatjet_pt_jesdn_isLoaded = false;
  Common_fatjet_pt_jerup_isLoaded = false;
  Common_fatjet_pt_jerdn_isLoaded = false;
  Common_fatjet_msoftdrop_jesup_isLoaded = false;
  Common_fatjet_msoftdrop_jesdn_isLoaded = false;
  Common_fatjet_msoftdrop_jerup_isLoaded = false;
  Common_fatjet_msoftdrop_jerdn_isLoaded = false;
  Common_fatjet_msoftdrop_jmsup_isLoaded = false;
  Common_fatjet_msoftdrop_jmsdn_isLoaded = false;
  Common_fatjet_msoftdrop_jmrup_isLoaded = false;
  Common_fatjet_msoftdrop_jmrdn_isLoaded = false;
  Common_fatjet_mass_jesup_isLoaded = false;
  Common_fatjet_mass_jesdn_isLoaded = false;
  Common_fatjet_mass_jerup_isLoaded = false;
  Common_fatjet_mass_jerdn_isLoaded = false;
  Common_fatjet_mass_jmsup_isLoaded = false;
  Common_fatjet_mass_jmsdn_isLoaded = false;
  Common_fatjet_mass_jmrup_isLoaded = false;
  Common_fatjet_mass_jmrdn_isLoaded = false;
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
  Common_eventweight_fatjet_MD_SFLoose_isLoaded = false;
  Common_eventweight_fatjet_MD_SFMedium_isLoaded = false;
  Common_eventweight_fatjet_MD_SFTight_isLoaded = false;
  Common_eventweight_fatjet_MD_SFdnLoose_isLoaded = false;
  Common_eventweight_fatjet_MD_SFdnMedium_isLoaded = false;
  Common_eventweight_fatjet_MD_SFdnTight_isLoaded = false;
  Common_eventweight_fatjet_MD_SFupLoose_isLoaded = false;
  Common_eventweight_fatjet_MD_SFupMedium_isLoaded = false;
  Common_eventweight_fatjet_MD_SFupTight_isLoaded = false;
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
  Common_isSignal_isLoaded = false;
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
  Common_gen_VH_channel_isLoaded = false;
  allHad_jets_p4_isLoaded = false;
  allHad_fatjets_mSD_p4_isLoaded = false;
  allHad_fatjets_WP_MD_isLoaded = false;
  allHad_fatjets_commonFJIdxs_isLoaded = false;
  allHad_nFJ_isLoaded = false;
  allHad_FJ0_mSD_p4_isLoaded = false;
  allHad_FJ1_mSD_p4_isLoaded = false;
  allHad_FJ2_mSD_p4_isLoaded = false;
  allHad_FJ0_WP_MD_isLoaded = false;
  allHad_FJ1_WP_MD_isLoaded = false;
  allHad_FJ2_WP_MD_isLoaded = false;
  allHad_FJ0_WMD_isLoaded = false;
  allHad_FJ1_WMD_isLoaded = false;
  allHad_FJ2_WMD_isLoaded = false;
  allHad_FJ0_VMD_isLoaded = false;
  allHad_FJ1_VMD_isLoaded = false;
  allHad_FJ2_VMD_isLoaded = false;
  allHad_FJ0_Xqq_isLoaded = false;
  allHad_FJ1_Xqq_isLoaded = false;
  allHad_FJ2_Xqq_isLoaded = false;
  allHad_FJ0_Xcc_isLoaded = false;
  allHad_FJ1_Xcc_isLoaded = false;
  allHad_FJ2_Xcc_isLoaded = false;
  allHad_FJ0_Xbb_isLoaded = false;
  allHad_FJ1_Xbb_isLoaded = false;
  allHad_FJ2_Xbb_isLoaded = false;
  allHad_FJ0_QCD_isLoaded = false;
  allHad_FJ1_QCD_isLoaded = false;
  allHad_FJ2_QCD_isLoaded = false;
  allHad_FJ0_commonFJIdxs_isLoaded = false;
  allHad_FJ1_commonFJIdxs_isLoaded = false;
  allHad_FJ2_commonFJIdxs_isLoaded = false;
  allHad_VVV_mSD_p4_isLoaded = false;
  allHad_mVVV_isLoaded = false;
  allHad_ptVVV_isLoaded = false;
  allHad_HT_isLoaded = false;
  allHad_HT_FJ_isLoaded = false;
  allHad_FJ01_dPhi_isLoaded = false;
  allHad_FJ01_dEta_isLoaded = false;
  allHad_FJ01_dR_isLoaded = false;
  allHad_FJ01_dPtFrac_isLoaded = false;
  allHad_FJ01_pPRel_isLoaded = false;
  allHad_FJ02_dPhi_isLoaded = false;
  allHad_FJ02_dEta_isLoaded = false;
  allHad_FJ02_dR_isLoaded = false;
  allHad_FJ02_dPtFrac_isLoaded = false;
  allHad_FJ02_pPRel_isLoaded = false;
  allHad_FJ12_dPhi_isLoaded = false;
  allHad_FJ12_dEta_isLoaded = false;
  allHad_FJ12_dR_isLoaded = false;
  allHad_FJ12_dPtFrac_isLoaded = false;
  allHad_FJ12_pPRel_isLoaded = false;
}

void VVV0LepTree::LoadAllBranches() {
  // load all branches
  if (Common_isData_branch != 0) Common_isData();
  if (Common_run_branch != 0) Common_run();
  if (Common_lumi_branch != 0) Common_lumi();
  if (Common_evt_branch != 0) Common_evt();
  if (Common_year_branch != 0) Common_year();
  if (Common_genWeight_branch != 0) Common_genWeight();
  if (Common_btagWeight_DeepCSVB_branch != 0) Common_btagWeight_DeepCSVB();
  if (Common_wgt_branch != 0) Common_wgt();
  if (Common_event_puWeight_branch != 0) Common_event_puWeight();
  if (Common_event_puWeightup_branch != 0) Common_event_puWeightup();
  if (Common_event_puWeightdn_branch != 0) Common_event_puWeightdn();
  if (Common_event_prefireWeight_branch != 0) Common_event_prefireWeight();
  if (Common_event_prefireWeightup_branch != 0) Common_event_prefireWeightup();
  if (Common_event_prefireWeightdn_branch != 0) Common_event_prefireWeightdn();
  if (Common_event_triggerWeight_branch != 0) Common_event_triggerWeight();
  if (Common_event_triggerWeightup_branch != 0) Common_event_triggerWeightup();
  if (Common_event_triggerWeightdn_branch != 0) Common_event_triggerWeightdn();
  if (Common_LHEReweightingWeight_branch != 0) Common_LHEReweightingWeight();
  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_branch != 0) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ();
  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_branch != 0) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL();
  if (Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8_branch != 0) Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8();
  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();
  if (Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL();
  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ();
  if (Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_branch != 0) Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL();
  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ_branch != 0) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ();
  if (Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_branch != 0) Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL();
  if (Common_HLT_IsoMu24_branch != 0) Common_HLT_IsoMu24();
  if (Common_HLT_Ele32_WPTight_branch != 0) Common_HLT_Ele32_WPTight();
  if (Common_HLT_PFHT1050_branch != 0) Common_HLT_PFHT1050();
  if (Common_HLT_AK8PFJet500_branch != 0) Common_HLT_AK8PFJet500();
  if (Common_HLT_AK8PFJet380_TrimMass30_branch != 0) Common_HLT_AK8PFJet380_TrimMass30();
  if (Common_HLT_AK8PFJet360_TrimMass30_branch != 0) Common_HLT_AK8PFJet360_TrimMass30();
  if (Common_HLT_AK8PFJet400_TrimMass30_branch != 0) Common_HLT_AK8PFJet400_TrimMass30();
  if (Common_HLT_AK8PFJet420_TrimMass30_branch != 0) Common_HLT_AK8PFJet420_TrimMass30();
  if (Common_HLT_AK8PFHT750_TrimMass50_branch != 0) Common_HLT_AK8PFHT750_TrimMass50();
  if (Common_HLT_AK8PFHT800_TrimMass50_branch != 0) Common_HLT_AK8PFHT800_TrimMass50();
  if (Common_HLT_AK8PFHT850_TrimMass50_branch != 0) Common_HLT_AK8PFHT850_TrimMass50();
  if (Common_HLT_AK8PFHT900_TrimMass50_branch != 0) Common_HLT_AK8PFHT900_TrimMass50();
  if (Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch != 0) Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5();
  if (Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch != 0) Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5();
  if (Common_HLT_PFHT800_branch != 0) Common_HLT_PFHT800();
  if (Common_HLT_PFHT900_branch != 0) Common_HLT_PFHT900();
  if (Common_HLT_PFJet450_branch != 0) Common_HLT_PFJet450();
  if (Common_HLT_PFJet500_branch != 0) Common_HLT_PFJet500();
  if (Common_HLT_AK8PFJet450_branch != 0) Common_HLT_AK8PFJet450();
  if (Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch != 0) Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50();
  if (Common_HLT_DoubleEl_branch != 0) Common_HLT_DoubleEl();
  if (Common_HLT_MuEG_branch != 0) Common_HLT_MuEG();
  if (Common_HLT_DoubleMu_branch != 0) Common_HLT_DoubleMu();
  if (Common_pass_duplicate_removal_ee_em_mm_branch != 0) Common_pass_duplicate_removal_ee_em_mm();
  if (Common_pass_duplicate_removal_mm_em_ee_branch != 0) Common_pass_duplicate_removal_mm_em_ee();
  if (Common_noiseFlag_branch != 0) Common_noiseFlag();
  if (Common_noiseFlagMC_branch != 0) Common_noiseFlagMC();
  if (Common_passGoodRun_branch != 0) Common_passGoodRun();
  if (Common_met_p4_branch != 0) Common_met_p4();
  if (Common_met_p4_jesup_branch != 0) Common_met_p4_jesup();
  if (Common_met_p4_jesdn_branch != 0) Common_met_p4_jesdn();
  if (Common_met_p4_jerup_branch != 0) Common_met_p4_jerup();
  if (Common_met_p4_jerdn_branch != 0) Common_met_p4_jerdn();
  if (Common_event_lepSF_branch != 0) Common_event_lepSF();
  if (Common_event_lepSFelup_branch != 0) Common_event_lepSFelup();
  if (Common_event_lepSFeldn_branch != 0) Common_event_lepSFeldn();
  if (Common_event_lepSFmuup_branch != 0) Common_event_lepSFmuup();
  if (Common_event_lepSFmudn_branch != 0) Common_event_lepSFmudn();
  if (Common_event_lepSFTight_branch != 0) Common_event_lepSFTight();
  if (Common_event_lepSFelupTight_branch != 0) Common_event_lepSFelupTight();
  if (Common_event_lepSFeldnTight_branch != 0) Common_event_lepSFeldnTight();
  if (Common_event_lepSFmuupTight_branch != 0) Common_event_lepSFmuupTight();
  if (Common_event_lepSFmudnTight_branch != 0) Common_event_lepSFmudnTight();
  if (Common_event_tightBtagSF_branch != 0) Common_event_tightBtagSF();
  if (Common_event_tightBtagSFup_branch != 0) Common_event_tightBtagSFup();
  if (Common_event_tightBtagSFdn_branch != 0) Common_event_tightBtagSFdn();
  if (Common_event_tightBtagSFHFup_branch != 0) Common_event_tightBtagSFHFup();
  if (Common_event_tightBtagSFHFdn_branch != 0) Common_event_tightBtagSFHFdn();
  if (Common_event_tightBtagSFLFup_branch != 0) Common_event_tightBtagSFLFup();
  if (Common_event_tightBtagSFLFdn_branch != 0) Common_event_tightBtagSFLFdn();
  if (Common_event_mediumBtagSF_branch != 0) Common_event_mediumBtagSF();
  if (Common_event_mediumBtagSFup_branch != 0) Common_event_mediumBtagSFup();
  if (Common_event_mediumBtagSFdn_branch != 0) Common_event_mediumBtagSFdn();
  if (Common_event_mediumBtagSFHFup_branch != 0) Common_event_mediumBtagSFHFup();
  if (Common_event_mediumBtagSFHFdn_branch != 0) Common_event_mediumBtagSFHFdn();
  if (Common_event_mediumBtagSFLFup_branch != 0) Common_event_mediumBtagSFLFup();
  if (Common_event_mediumBtagSFLFdn_branch != 0) Common_event_mediumBtagSFLFdn();
  if (Common_event_looseBtagSF_branch != 0) Common_event_looseBtagSF();
  if (Common_event_looseBtagSFup_branch != 0) Common_event_looseBtagSFup();
  if (Common_event_looseBtagSFdn_branch != 0) Common_event_looseBtagSFdn();
  if (Common_event_looseBtagSFHFup_branch != 0) Common_event_looseBtagSFHFup();
  if (Common_event_looseBtagSFHFdn_branch != 0) Common_event_looseBtagSFHFdn();
  if (Common_event_looseBtagSFLFup_branch != 0) Common_event_looseBtagSFLFup();
  if (Common_event_looseBtagSFLFdn_branch != 0) Common_event_looseBtagSFLFdn();
  if (Common_lep_p4_branch != 0) Common_lep_p4();
  if (Common_lep_idxs_branch != 0) Common_lep_idxs();
  if (Common_lep_pdgid_branch != 0) Common_lep_pdgid();
  if (Common_lep_tight_branch != 0) Common_lep_tight();
  if (Common_lep_dxy_branch != 0) Common_lep_dxy();
  if (Common_lep_dz_branch != 0) Common_lep_dz();
  if (Common_lep_ip3d_branch != 0) Common_lep_ip3d();
  if (Common_lep_sip3d_branch != 0) Common_lep_sip3d();
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
  if (Common_jet_id_branch != 0) Common_jet_id();
  if (Common_jet_puid_branch != 0) Common_jet_puid();
  if (Common_jet_overlapfatjet_branch != 0) Common_jet_overlapfatjet();
  if (Common_jet_pt_jesup_branch != 0) Common_jet_pt_jesup();
  if (Common_jet_pt_jesdn_branch != 0) Common_jet_pt_jesdn();
  if (Common_jet_pt_jerup_branch != 0) Common_jet_pt_jerup();
  if (Common_jet_pt_jerdn_branch != 0) Common_jet_pt_jerdn();
  if (Common_jet_mass_jesup_branch != 0) Common_jet_mass_jesup();
  if (Common_jet_mass_jesdn_branch != 0) Common_jet_mass_jesdn();
  if (Common_jet_mass_jerup_branch != 0) Common_jet_mass_jerup();
  if (Common_jet_mass_jerdn_branch != 0) Common_jet_mass_jerdn();
  if (Common_fatjet_p4_branch != 0) Common_fatjet_p4();
  if (Common_fatjet_idxs_branch != 0) Common_fatjet_idxs();
  if (Common_fatjet_id_branch != 0) Common_fatjet_id();
  if (Common_fatjet_msoftdrop_branch != 0) Common_fatjet_msoftdrop();
  if (Common_fatjet_deepMD_W_branch != 0) Common_fatjet_deepMD_W();
  if (Common_fatjet_deep_W_branch != 0) Common_fatjet_deep_W();
  if (Common_fatjet_deepMD_Z_branch != 0) Common_fatjet_deepMD_Z();
  if (Common_fatjet_deep_Z_branch != 0) Common_fatjet_deep_Z();
  if (Common_fatjet_deepMD_T_branch != 0) Common_fatjet_deepMD_T();
  if (Common_fatjet_deep_T_branch != 0) Common_fatjet_deep_T();
  if (Common_fatjet_deepMD_bb_branch != 0) Common_fatjet_deepMD_bb();
  if (Common_fatjet_particleNetMD_W_branch != 0) Common_fatjet_particleNetMD_W();
  if (Common_fatjet_particleNetMD_Xqq_branch != 0) Common_fatjet_particleNetMD_Xqq();
  if (Common_fatjet_particleNetMD_Xcc_branch != 0) Common_fatjet_particleNetMD_Xcc();
  if (Common_fatjet_particleNetMD_Xbb_branch != 0) Common_fatjet_particleNetMD_Xbb();
  if (Common_fatjet_particleNetMD_QCD_branch != 0) Common_fatjet_particleNetMD_QCD();
  if (Common_fatjet_particleNet_QCD_branch != 0) Common_fatjet_particleNet_QCD();
  if (Common_fatjet_particleNet_W_branch != 0) Common_fatjet_particleNet_W();
  if (Common_fatjet_particleNet_Z_branch != 0) Common_fatjet_particleNet_Z();
  if (Common_fatjet_particleNet_T_branch != 0) Common_fatjet_particleNet_T();
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
  if (Common_fatjet_WP_MD_branch != 0) Common_fatjet_WP_MD();
  if (Common_fatjet_WP_antimasscut_branch != 0) Common_fatjet_WP_antimasscut();
  if (Common_fatjet_WP_MD_antimasscut_branch != 0) Common_fatjet_WP_MD_antimasscut();
  if (Common_fatjet_SFVLoose_branch != 0) Common_fatjet_SFVLoose();
  if (Common_fatjet_SFLoose_branch != 0) Common_fatjet_SFLoose();
  if (Common_fatjet_SFMedium_branch != 0) Common_fatjet_SFMedium();
  if (Common_fatjet_SFTight_branch != 0) Common_fatjet_SFTight();
  if (Common_fatjet_SFdnLoose_branch != 0) Common_fatjet_SFdnLoose();
  if (Common_fatjet_SFdnVLoose_branch != 0) Common_fatjet_SFdnVLoose();
  if (Common_fatjet_SFdnMedium_branch != 0) Common_fatjet_SFdnMedium();
  if (Common_fatjet_SFdnTight_branch != 0) Common_fatjet_SFdnTight();
  if (Common_fatjet_SFupVLoose_branch != 0) Common_fatjet_SFupVLoose();
  if (Common_fatjet_SFupLoose_branch != 0) Common_fatjet_SFupLoose();
  if (Common_fatjet_SFupMedium_branch != 0) Common_fatjet_SFupMedium();
  if (Common_fatjet_SFupTight_branch != 0) Common_fatjet_SFupTight();
  if (Common_fatjet_MD_SFLoose_branch != 0) Common_fatjet_MD_SFLoose();
  if (Common_fatjet_MD_SFMedium_branch != 0) Common_fatjet_MD_SFMedium();
  if (Common_fatjet_MD_SFTight_branch != 0) Common_fatjet_MD_SFTight();
  if (Common_fatjet_MD_SFdnLoose_branch != 0) Common_fatjet_MD_SFdnLoose();
  if (Common_fatjet_MD_SFdnMedium_branch != 0) Common_fatjet_MD_SFdnMedium();
  if (Common_fatjet_MD_SFdnTight_branch != 0) Common_fatjet_MD_SFdnTight();
  if (Common_fatjet_MD_SFupLoose_branch != 0) Common_fatjet_MD_SFupLoose();
  if (Common_fatjet_MD_SFupMedium_branch != 0) Common_fatjet_MD_SFupMedium();
  if (Common_fatjet_MD_SFupTight_branch != 0) Common_fatjet_MD_SFupTight();
  if (Common_fatjet_pt_jesup_branch != 0) Common_fatjet_pt_jesup();
  if (Common_fatjet_pt_jesdn_branch != 0) Common_fatjet_pt_jesdn();
  if (Common_fatjet_pt_jerup_branch != 0) Common_fatjet_pt_jerup();
  if (Common_fatjet_pt_jerdn_branch != 0) Common_fatjet_pt_jerdn();
  if (Common_fatjet_msoftdrop_jesup_branch != 0) Common_fatjet_msoftdrop_jesup();
  if (Common_fatjet_msoftdrop_jesdn_branch != 0) Common_fatjet_msoftdrop_jesdn();
  if (Common_fatjet_msoftdrop_jerup_branch != 0) Common_fatjet_msoftdrop_jerup();
  if (Common_fatjet_msoftdrop_jerdn_branch != 0) Common_fatjet_msoftdrop_jerdn();
  if (Common_fatjet_msoftdrop_jmsup_branch != 0) Common_fatjet_msoftdrop_jmsup();
  if (Common_fatjet_msoftdrop_jmsdn_branch != 0) Common_fatjet_msoftdrop_jmsdn();
  if (Common_fatjet_msoftdrop_jmrup_branch != 0) Common_fatjet_msoftdrop_jmrup();
  if (Common_fatjet_msoftdrop_jmrdn_branch != 0) Common_fatjet_msoftdrop_jmrdn();
  if (Common_fatjet_mass_jesup_branch != 0) Common_fatjet_mass_jesup();
  if (Common_fatjet_mass_jesdn_branch != 0) Common_fatjet_mass_jesdn();
  if (Common_fatjet_mass_jerup_branch != 0) Common_fatjet_mass_jerup();
  if (Common_fatjet_mass_jerdn_branch != 0) Common_fatjet_mass_jerdn();
  if (Common_fatjet_mass_jmsup_branch != 0) Common_fatjet_mass_jmsup();
  if (Common_fatjet_mass_jmsdn_branch != 0) Common_fatjet_mass_jmsdn();
  if (Common_fatjet_mass_jmrup_branch != 0) Common_fatjet_mass_jmrup();
  if (Common_fatjet_mass_jmrdn_branch != 0) Common_fatjet_mass_jmrdn();
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
  if (Common_eventweight_fatjet_MD_SFLoose_branch != 0) Common_eventweight_fatjet_MD_SFLoose();
  if (Common_eventweight_fatjet_MD_SFMedium_branch != 0) Common_eventweight_fatjet_MD_SFMedium();
  if (Common_eventweight_fatjet_MD_SFTight_branch != 0) Common_eventweight_fatjet_MD_SFTight();
  if (Common_eventweight_fatjet_MD_SFdnLoose_branch != 0) Common_eventweight_fatjet_MD_SFdnLoose();
  if (Common_eventweight_fatjet_MD_SFdnMedium_branch != 0) Common_eventweight_fatjet_MD_SFdnMedium();
  if (Common_eventweight_fatjet_MD_SFdnTight_branch != 0) Common_eventweight_fatjet_MD_SFdnTight();
  if (Common_eventweight_fatjet_MD_SFupLoose_branch != 0) Common_eventweight_fatjet_MD_SFupLoose();
  if (Common_eventweight_fatjet_MD_SFupMedium_branch != 0) Common_eventweight_fatjet_MD_SFupMedium();
  if (Common_eventweight_fatjet_MD_SFupTight_branch != 0) Common_eventweight_fatjet_MD_SFupTight();
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
  if (Common_isSignal_branch != 0) Common_isSignal();
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
  if (Common_gen_VH_channel_branch != 0) Common_gen_VH_channel();
  if (allHad_jets_p4_branch != 0) allHad_jets_p4();
  if (allHad_fatjets_mSD_p4_branch != 0) allHad_fatjets_mSD_p4();
  if (allHad_fatjets_WP_MD_branch != 0) allHad_fatjets_WP_MD();
  if (allHad_fatjets_commonFJIdxs_branch != 0) allHad_fatjets_commonFJIdxs();
  if (allHad_nFJ_branch != 0) allHad_nFJ();
  if (allHad_FJ0_mSD_p4_branch != 0) allHad_FJ0_mSD_p4();
  if (allHad_FJ1_mSD_p4_branch != 0) allHad_FJ1_mSD_p4();
  if (allHad_FJ2_mSD_p4_branch != 0) allHad_FJ2_mSD_p4();
  if (allHad_FJ0_WP_MD_branch != 0) allHad_FJ0_WP_MD();
  if (allHad_FJ1_WP_MD_branch != 0) allHad_FJ1_WP_MD();
  if (allHad_FJ2_WP_MD_branch != 0) allHad_FJ2_WP_MD();
  if (allHad_FJ0_WMD_branch != 0) allHad_FJ0_WMD();
  if (allHad_FJ1_WMD_branch != 0) allHad_FJ1_WMD();
  if (allHad_FJ2_WMD_branch != 0) allHad_FJ2_WMD();
  if (allHad_FJ0_VMD_branch != 0) allHad_FJ0_VMD();
  if (allHad_FJ1_VMD_branch != 0) allHad_FJ1_VMD();
  if (allHad_FJ2_VMD_branch != 0) allHad_FJ2_VMD();
  if (allHad_FJ0_Xqq_branch != 0) allHad_FJ0_Xqq();
  if (allHad_FJ1_Xqq_branch != 0) allHad_FJ1_Xqq();
  if (allHad_FJ2_Xqq_branch != 0) allHad_FJ2_Xqq();
  if (allHad_FJ0_Xcc_branch != 0) allHad_FJ0_Xcc();
  if (allHad_FJ1_Xcc_branch != 0) allHad_FJ1_Xcc();
  if (allHad_FJ2_Xcc_branch != 0) allHad_FJ2_Xcc();
  if (allHad_FJ0_Xbb_branch != 0) allHad_FJ0_Xbb();
  if (allHad_FJ1_Xbb_branch != 0) allHad_FJ1_Xbb();
  if (allHad_FJ2_Xbb_branch != 0) allHad_FJ2_Xbb();
  if (allHad_FJ0_QCD_branch != 0) allHad_FJ0_QCD();
  if (allHad_FJ1_QCD_branch != 0) allHad_FJ1_QCD();
  if (allHad_FJ2_QCD_branch != 0) allHad_FJ2_QCD();
  if (allHad_FJ0_commonFJIdxs_branch != 0) allHad_FJ0_commonFJIdxs();
  if (allHad_FJ1_commonFJIdxs_branch != 0) allHad_FJ1_commonFJIdxs();
  if (allHad_FJ2_commonFJIdxs_branch != 0) allHad_FJ2_commonFJIdxs();
  if (allHad_VVV_mSD_p4_branch != 0) allHad_VVV_mSD_p4();
  if (allHad_mVVV_branch != 0) allHad_mVVV();
  if (allHad_ptVVV_branch != 0) allHad_ptVVV();
  if (allHad_HT_branch != 0) allHad_HT();
  if (allHad_HT_FJ_branch != 0) allHad_HT_FJ();
  if (allHad_FJ01_dPhi_branch != 0) allHad_FJ01_dPhi();
  if (allHad_FJ01_dEta_branch != 0) allHad_FJ01_dEta();
  if (allHad_FJ01_dR_branch != 0) allHad_FJ01_dR();
  if (allHad_FJ01_dPtFrac_branch != 0) allHad_FJ01_dPtFrac();
  if (allHad_FJ01_pPRel_branch != 0) allHad_FJ01_pPRel();
  if (allHad_FJ02_dPhi_branch != 0) allHad_FJ02_dPhi();
  if (allHad_FJ02_dEta_branch != 0) allHad_FJ02_dEta();
  if (allHad_FJ02_dR_branch != 0) allHad_FJ02_dR();
  if (allHad_FJ02_dPtFrac_branch != 0) allHad_FJ02_dPtFrac();
  if (allHad_FJ02_pPRel_branch != 0) allHad_FJ02_pPRel();
  if (allHad_FJ12_dPhi_branch != 0) allHad_FJ12_dPhi();
  if (allHad_FJ12_dEta_branch != 0) allHad_FJ12_dEta();
  if (allHad_FJ12_dR_branch != 0) allHad_FJ12_dR();
  if (allHad_FJ12_dPtFrac_branch != 0) allHad_FJ12_dPtFrac();
  if (allHad_FJ12_pPRel_branch != 0) allHad_FJ12_pPRel();
}

const int &VVV0LepTree::Common_isData() {
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

const int &VVV0LepTree::Common_run() {
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

const int &VVV0LepTree::Common_lumi() {
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

const unsigned long long &VVV0LepTree::Common_evt() {
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

const int &VVV0LepTree::Common_year() {
  if (not Common_year_isLoaded) {
    if (Common_year_branch != 0) {
      Common_year_branch->GetEntry(index);
    } else {
      printf("branch Common_year_branch does not exist!\n");
      exit(1);
    }
    Common_year_isLoaded = true;
  }
  return Common_year_;
}

const float &VVV0LepTree::Common_genWeight() {
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

const float &VVV0LepTree::Common_btagWeight_DeepCSVB() {
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

const float &VVV0LepTree::Common_wgt() {
  if (not Common_wgt_isLoaded) {
    if (Common_wgt_branch != 0) {
      Common_wgt_branch->GetEntry(index);
    } else {
      printf("branch Common_wgt_branch does not exist!\n");
      exit(1);
    }
    Common_wgt_isLoaded = true;
  }
  return Common_wgt_;
}

const float &VVV0LepTree::Common_event_puWeight() {
  if (not Common_event_puWeight_isLoaded) {
    if (Common_event_puWeight_branch != 0) {
      Common_event_puWeight_branch->GetEntry(index);
    } else {
      printf("branch Common_event_puWeight_branch does not exist!\n");
      exit(1);
    }
    Common_event_puWeight_isLoaded = true;
  }
  return Common_event_puWeight_;
}

const float &VVV0LepTree::Common_event_puWeightup() {
  if (not Common_event_puWeightup_isLoaded) {
    if (Common_event_puWeightup_branch != 0) {
      Common_event_puWeightup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_puWeightup_branch does not exist!\n");
      exit(1);
    }
    Common_event_puWeightup_isLoaded = true;
  }
  return Common_event_puWeightup_;
}

const float &VVV0LepTree::Common_event_puWeightdn() {
  if (not Common_event_puWeightdn_isLoaded) {
    if (Common_event_puWeightdn_branch != 0) {
      Common_event_puWeightdn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_puWeightdn_branch does not exist!\n");
      exit(1);
    }
    Common_event_puWeightdn_isLoaded = true;
  }
  return Common_event_puWeightdn_;
}

const float &VVV0LepTree::Common_event_prefireWeight() {
  if (not Common_event_prefireWeight_isLoaded) {
    if (Common_event_prefireWeight_branch != 0) {
      Common_event_prefireWeight_branch->GetEntry(index);
    } else {
      printf("branch Common_event_prefireWeight_branch does not exist!\n");
      exit(1);
    }
    Common_event_prefireWeight_isLoaded = true;
  }
  return Common_event_prefireWeight_;
}

const float &VVV0LepTree::Common_event_prefireWeightup() {
  if (not Common_event_prefireWeightup_isLoaded) {
    if (Common_event_prefireWeightup_branch != 0) {
      Common_event_prefireWeightup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_prefireWeightup_branch does not exist!\n");
      exit(1);
    }
    Common_event_prefireWeightup_isLoaded = true;
  }
  return Common_event_prefireWeightup_;
}

const float &VVV0LepTree::Common_event_prefireWeightdn() {
  if (not Common_event_prefireWeightdn_isLoaded) {
    if (Common_event_prefireWeightdn_branch != 0) {
      Common_event_prefireWeightdn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_prefireWeightdn_branch does not exist!\n");
      exit(1);
    }
    Common_event_prefireWeightdn_isLoaded = true;
  }
  return Common_event_prefireWeightdn_;
}

const float &VVV0LepTree::Common_event_triggerWeight() {
  if (not Common_event_triggerWeight_isLoaded) {
    if (Common_event_triggerWeight_branch != 0) {
      Common_event_triggerWeight_branch->GetEntry(index);
    } else {
      printf("branch Common_event_triggerWeight_branch does not exist!\n");
      exit(1);
    }
    Common_event_triggerWeight_isLoaded = true;
  }
  return Common_event_triggerWeight_;
}

const float &VVV0LepTree::Common_event_triggerWeightup() {
  if (not Common_event_triggerWeightup_isLoaded) {
    if (Common_event_triggerWeightup_branch != 0) {
      Common_event_triggerWeightup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_triggerWeightup_branch does not exist!\n");
      exit(1);
    }
    Common_event_triggerWeightup_isLoaded = true;
  }
  return Common_event_triggerWeightup_;
}

const float &VVV0LepTree::Common_event_triggerWeightdn() {
  if (not Common_event_triggerWeightdn_isLoaded) {
    if (Common_event_triggerWeightdn_branch != 0) {
      Common_event_triggerWeightdn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_triggerWeightdn_branch does not exist!\n");
      exit(1);
    }
    Common_event_triggerWeightdn_isLoaded = true;
  }
  return Common_event_triggerWeightdn_;
}

const vector<float> &VVV0LepTree::Common_LHEReweightingWeight() {
  if (not Common_LHEReweightingWeight_isLoaded) {
    if (Common_LHEReweightingWeight_branch != 0) {
      Common_LHEReweightingWeight_branch->GetEntry(index);
    } else {
      printf("branch Common_LHEReweightingWeight_branch does not exist!\n");
      exit(1);
    }
    Common_LHEReweightingWeight_isLoaded = true;
  }
  return *Common_LHEReweightingWeight_;
}

const bool &VVV0LepTree::Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ() {
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

const bool &VVV0LepTree::Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL() {
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

const bool &VVV0LepTree::Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8() {
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

const bool &VVV0LepTree::Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() {
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

const bool &VVV0LepTree::Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL() {
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

const bool &VVV0LepTree::Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() {
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

const bool &VVV0LepTree::Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL() {
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

const bool &VVV0LepTree::Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ() {
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

const bool &VVV0LepTree::Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL() {
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

const bool &VVV0LepTree::Common_HLT_IsoMu24() {
  if (not Common_HLT_IsoMu24_isLoaded) {
    if (Common_HLT_IsoMu24_branch != 0) {
      Common_HLT_IsoMu24_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_IsoMu24_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_IsoMu24_isLoaded = true;
  }
  return Common_HLT_IsoMu24_;
}

const bool &VVV0LepTree::Common_HLT_Ele32_WPTight() {
  if (not Common_HLT_Ele32_WPTight_isLoaded) {
    if (Common_HLT_Ele32_WPTight_branch != 0) {
      Common_HLT_Ele32_WPTight_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_Ele32_WPTight_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_Ele32_WPTight_isLoaded = true;
  }
  return Common_HLT_Ele32_WPTight_;
}

const bool &VVV0LepTree::Common_HLT_PFHT1050() {
  if (not Common_HLT_PFHT1050_isLoaded) {
    if (Common_HLT_PFHT1050_branch != 0) {
      Common_HLT_PFHT1050_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_PFHT1050_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_PFHT1050_isLoaded = true;
  }
  return Common_HLT_PFHT1050_;
}

const bool &VVV0LepTree::Common_HLT_AK8PFJet500() {
  if (not Common_HLT_AK8PFJet500_isLoaded) {
    if (Common_HLT_AK8PFJet500_branch != 0) {
      Common_HLT_AK8PFJet500_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_AK8PFJet500_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_AK8PFJet500_isLoaded = true;
  }
  return Common_HLT_AK8PFJet500_;
}

const bool &VVV0LepTree::Common_HLT_AK8PFJet380_TrimMass30() {
  if (not Common_HLT_AK8PFJet380_TrimMass30_isLoaded) {
    if (Common_HLT_AK8PFJet380_TrimMass30_branch != 0) {
      Common_HLT_AK8PFJet380_TrimMass30_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_AK8PFJet380_TrimMass30_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_AK8PFJet380_TrimMass30_isLoaded = true;
  }
  return Common_HLT_AK8PFJet380_TrimMass30_;
}

const bool &VVV0LepTree::Common_HLT_AK8PFJet360_TrimMass30() {
  if (not Common_HLT_AK8PFJet360_TrimMass30_isLoaded) {
    if (Common_HLT_AK8PFJet360_TrimMass30_branch != 0) {
      Common_HLT_AK8PFJet360_TrimMass30_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_AK8PFJet360_TrimMass30_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_AK8PFJet360_TrimMass30_isLoaded = true;
  }
  return Common_HLT_AK8PFJet360_TrimMass30_;
}

const bool &VVV0LepTree::Common_HLT_AK8PFJet400_TrimMass30() {
  if (not Common_HLT_AK8PFJet400_TrimMass30_isLoaded) {
    if (Common_HLT_AK8PFJet400_TrimMass30_branch != 0) {
      Common_HLT_AK8PFJet400_TrimMass30_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_AK8PFJet400_TrimMass30_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_AK8PFJet400_TrimMass30_isLoaded = true;
  }
  return Common_HLT_AK8PFJet400_TrimMass30_;
}

const bool &VVV0LepTree::Common_HLT_AK8PFJet420_TrimMass30() {
  if (not Common_HLT_AK8PFJet420_TrimMass30_isLoaded) {
    if (Common_HLT_AK8PFJet420_TrimMass30_branch != 0) {
      Common_HLT_AK8PFJet420_TrimMass30_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_AK8PFJet420_TrimMass30_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_AK8PFJet420_TrimMass30_isLoaded = true;
  }
  return Common_HLT_AK8PFJet420_TrimMass30_;
}

const bool &VVV0LepTree::Common_HLT_AK8PFHT750_TrimMass50() {
  if (not Common_HLT_AK8PFHT750_TrimMass50_isLoaded) {
    if (Common_HLT_AK8PFHT750_TrimMass50_branch != 0) {
      Common_HLT_AK8PFHT750_TrimMass50_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_AK8PFHT750_TrimMass50_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_AK8PFHT750_TrimMass50_isLoaded = true;
  }
  return Common_HLT_AK8PFHT750_TrimMass50_;
}

const bool &VVV0LepTree::Common_HLT_AK8PFHT800_TrimMass50() {
  if (not Common_HLT_AK8PFHT800_TrimMass50_isLoaded) {
    if (Common_HLT_AK8PFHT800_TrimMass50_branch != 0) {
      Common_HLT_AK8PFHT800_TrimMass50_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_AK8PFHT800_TrimMass50_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_AK8PFHT800_TrimMass50_isLoaded = true;
  }
  return Common_HLT_AK8PFHT800_TrimMass50_;
}

const bool &VVV0LepTree::Common_HLT_AK8PFHT850_TrimMass50() {
  if (not Common_HLT_AK8PFHT850_TrimMass50_isLoaded) {
    if (Common_HLT_AK8PFHT850_TrimMass50_branch != 0) {
      Common_HLT_AK8PFHT850_TrimMass50_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_AK8PFHT850_TrimMass50_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_AK8PFHT850_TrimMass50_isLoaded = true;
  }
  return Common_HLT_AK8PFHT850_TrimMass50_;
}

const bool &VVV0LepTree::Common_HLT_AK8PFHT900_TrimMass50() {
  if (not Common_HLT_AK8PFHT900_TrimMass50_isLoaded) {
    if (Common_HLT_AK8PFHT900_TrimMass50_branch != 0) {
      Common_HLT_AK8PFHT900_TrimMass50_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_AK8PFHT900_TrimMass50_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_AK8PFHT900_TrimMass50_isLoaded = true;
  }
  return Common_HLT_AK8PFHT900_TrimMass50_;
}

const bool &VVV0LepTree::Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5() {
  if (not Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_isLoaded) {
    if (Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch != 0) {
      Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_isLoaded = true;
  }
  return Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5_;
}

const bool &VVV0LepTree::Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5() {
  if (not Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_isLoaded) {
    if (Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch != 0) {
      Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_isLoaded = true;
  }
  return Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5_;
}

const bool &VVV0LepTree::Common_HLT_PFHT800() {
  if (not Common_HLT_PFHT800_isLoaded) {
    if (Common_HLT_PFHT800_branch != 0) {
      Common_HLT_PFHT800_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_PFHT800_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_PFHT800_isLoaded = true;
  }
  return Common_HLT_PFHT800_;
}

const bool &VVV0LepTree::Common_HLT_PFHT900() {
  if (not Common_HLT_PFHT900_isLoaded) {
    if (Common_HLT_PFHT900_branch != 0) {
      Common_HLT_PFHT900_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_PFHT900_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_PFHT900_isLoaded = true;
  }
  return Common_HLT_PFHT900_;
}

const bool &VVV0LepTree::Common_HLT_PFJet450() {
  if (not Common_HLT_PFJet450_isLoaded) {
    if (Common_HLT_PFJet450_branch != 0) {
      Common_HLT_PFJet450_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_PFJet450_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_PFJet450_isLoaded = true;
  }
  return Common_HLT_PFJet450_;
}

const bool &VVV0LepTree::Common_HLT_PFJet500() {
  if (not Common_HLT_PFJet500_isLoaded) {
    if (Common_HLT_PFJet500_branch != 0) {
      Common_HLT_PFJet500_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_PFJet500_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_PFJet500_isLoaded = true;
  }
  return Common_HLT_PFJet500_;
}

const bool &VVV0LepTree::Common_HLT_AK8PFJet450() {
  if (not Common_HLT_AK8PFJet450_isLoaded) {
    if (Common_HLT_AK8PFJet450_branch != 0) {
      Common_HLT_AK8PFJet450_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_AK8PFJet450_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_AK8PFJet450_isLoaded = true;
  }
  return Common_HLT_AK8PFJet450_;
}

const bool &VVV0LepTree::Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50() {
  if (not Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_isLoaded) {
    if (Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch != 0) {
      Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch->GetEntry(index);
    } else {
      printf("branch Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_branch does not exist!\n");
      exit(1);
    }
    Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_isLoaded = true;
  }
  return Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50_;
}

const bool &VVV0LepTree::Common_HLT_DoubleEl() {
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

const bool &VVV0LepTree::Common_HLT_MuEG() {
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

const bool &VVV0LepTree::Common_HLT_DoubleMu() {
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

const bool &VVV0LepTree::Common_pass_duplicate_removal_ee_em_mm() {
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

const bool &VVV0LepTree::Common_pass_duplicate_removal_mm_em_ee() {
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

const bool &VVV0LepTree::Common_noiseFlag() {
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

const bool &VVV0LepTree::Common_noiseFlagMC() {
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

const bool &VVV0LepTree::Common_passGoodRun() {
  if (not Common_passGoodRun_isLoaded) {
    if (Common_passGoodRun_branch != 0) {
      Common_passGoodRun_branch->GetEntry(index);
    } else {
      printf("branch Common_passGoodRun_branch does not exist!\n");
      exit(1);
    }
    Common_passGoodRun_isLoaded = true;
  }
  return Common_passGoodRun_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVV0LepTree::Common_met_p4() {
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

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVV0LepTree::Common_met_p4_jesup() {
  if (not Common_met_p4_jesup_isLoaded) {
    if (Common_met_p4_jesup_branch != 0) {
      Common_met_p4_jesup_branch->GetEntry(index);
    } else {
      printf("branch Common_met_p4_jesup_branch does not exist!\n");
      exit(1);
    }
    Common_met_p4_jesup_isLoaded = true;
  }
  return *Common_met_p4_jesup_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVV0LepTree::Common_met_p4_jesdn() {
  if (not Common_met_p4_jesdn_isLoaded) {
    if (Common_met_p4_jesdn_branch != 0) {
      Common_met_p4_jesdn_branch->GetEntry(index);
    } else {
      printf("branch Common_met_p4_jesdn_branch does not exist!\n");
      exit(1);
    }
    Common_met_p4_jesdn_isLoaded = true;
  }
  return *Common_met_p4_jesdn_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVV0LepTree::Common_met_p4_jerup() {
  if (not Common_met_p4_jerup_isLoaded) {
    if (Common_met_p4_jerup_branch != 0) {
      Common_met_p4_jerup_branch->GetEntry(index);
    } else {
      printf("branch Common_met_p4_jerup_branch does not exist!\n");
      exit(1);
    }
    Common_met_p4_jerup_isLoaded = true;
  }
  return *Common_met_p4_jerup_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVV0LepTree::Common_met_p4_jerdn() {
  if (not Common_met_p4_jerdn_isLoaded) {
    if (Common_met_p4_jerdn_branch != 0) {
      Common_met_p4_jerdn_branch->GetEntry(index);
    } else {
      printf("branch Common_met_p4_jerdn_branch does not exist!\n");
      exit(1);
    }
    Common_met_p4_jerdn_isLoaded = true;
  }
  return *Common_met_p4_jerdn_;
}

const float &VVV0LepTree::Common_event_lepSF() {
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

const float &VVV0LepTree::Common_event_lepSFelup() {
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

const float &VVV0LepTree::Common_event_lepSFeldn() {
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

const float &VVV0LepTree::Common_event_lepSFmuup() {
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

const float &VVV0LepTree::Common_event_lepSFmudn() {
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

const float &VVV0LepTree::Common_event_lepSFTight() {
  if (not Common_event_lepSFTight_isLoaded) {
    if (Common_event_lepSFTight_branch != 0) {
      Common_event_lepSFTight_branch->GetEntry(index);
    } else {
      printf("branch Common_event_lepSFTight_branch does not exist!\n");
      exit(1);
    }
    Common_event_lepSFTight_isLoaded = true;
  }
  return Common_event_lepSFTight_;
}

const float &VVV0LepTree::Common_event_lepSFelupTight() {
  if (not Common_event_lepSFelupTight_isLoaded) {
    if (Common_event_lepSFelupTight_branch != 0) {
      Common_event_lepSFelupTight_branch->GetEntry(index);
    } else {
      printf("branch Common_event_lepSFelupTight_branch does not exist!\n");
      exit(1);
    }
    Common_event_lepSFelupTight_isLoaded = true;
  }
  return Common_event_lepSFelupTight_;
}

const float &VVV0LepTree::Common_event_lepSFeldnTight() {
  if (not Common_event_lepSFeldnTight_isLoaded) {
    if (Common_event_lepSFeldnTight_branch != 0) {
      Common_event_lepSFeldnTight_branch->GetEntry(index);
    } else {
      printf("branch Common_event_lepSFeldnTight_branch does not exist!\n");
      exit(1);
    }
    Common_event_lepSFeldnTight_isLoaded = true;
  }
  return Common_event_lepSFeldnTight_;
}

const float &VVV0LepTree::Common_event_lepSFmuupTight() {
  if (not Common_event_lepSFmuupTight_isLoaded) {
    if (Common_event_lepSFmuupTight_branch != 0) {
      Common_event_lepSFmuupTight_branch->GetEntry(index);
    } else {
      printf("branch Common_event_lepSFmuupTight_branch does not exist!\n");
      exit(1);
    }
    Common_event_lepSFmuupTight_isLoaded = true;
  }
  return Common_event_lepSFmuupTight_;
}

const float &VVV0LepTree::Common_event_lepSFmudnTight() {
  if (not Common_event_lepSFmudnTight_isLoaded) {
    if (Common_event_lepSFmudnTight_branch != 0) {
      Common_event_lepSFmudnTight_branch->GetEntry(index);
    } else {
      printf("branch Common_event_lepSFmudnTight_branch does not exist!\n");
      exit(1);
    }
    Common_event_lepSFmudnTight_isLoaded = true;
  }
  return Common_event_lepSFmudnTight_;
}

const float &VVV0LepTree::Common_event_tightBtagSF() {
  if (not Common_event_tightBtagSF_isLoaded) {
    if (Common_event_tightBtagSF_branch != 0) {
      Common_event_tightBtagSF_branch->GetEntry(index);
    } else {
      printf("branch Common_event_tightBtagSF_branch does not exist!\n");
      exit(1);
    }
    Common_event_tightBtagSF_isLoaded = true;
  }
  return Common_event_tightBtagSF_;
}

const float &VVV0LepTree::Common_event_tightBtagSFup() {
  if (not Common_event_tightBtagSFup_isLoaded) {
    if (Common_event_tightBtagSFup_branch != 0) {
      Common_event_tightBtagSFup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_tightBtagSFup_branch does not exist!\n");
      exit(1);
    }
    Common_event_tightBtagSFup_isLoaded = true;
  }
  return Common_event_tightBtagSFup_;
}

const float &VVV0LepTree::Common_event_tightBtagSFdn() {
  if (not Common_event_tightBtagSFdn_isLoaded) {
    if (Common_event_tightBtagSFdn_branch != 0) {
      Common_event_tightBtagSFdn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_tightBtagSFdn_branch does not exist!\n");
      exit(1);
    }
    Common_event_tightBtagSFdn_isLoaded = true;
  }
  return Common_event_tightBtagSFdn_;
}

const float &VVV0LepTree::Common_event_tightBtagSFHFup() {
  if (not Common_event_tightBtagSFHFup_isLoaded) {
    if (Common_event_tightBtagSFHFup_branch != 0) {
      Common_event_tightBtagSFHFup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_tightBtagSFHFup_branch does not exist!\n");
      exit(1);
    }
    Common_event_tightBtagSFHFup_isLoaded = true;
  }
  return Common_event_tightBtagSFHFup_;
}

const float &VVV0LepTree::Common_event_tightBtagSFHFdn() {
  if (not Common_event_tightBtagSFHFdn_isLoaded) {
    if (Common_event_tightBtagSFHFdn_branch != 0) {
      Common_event_tightBtagSFHFdn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_tightBtagSFHFdn_branch does not exist!\n");
      exit(1);
    }
    Common_event_tightBtagSFHFdn_isLoaded = true;
  }
  return Common_event_tightBtagSFHFdn_;
}

const float &VVV0LepTree::Common_event_tightBtagSFLFup() {
  if (not Common_event_tightBtagSFLFup_isLoaded) {
    if (Common_event_tightBtagSFLFup_branch != 0) {
      Common_event_tightBtagSFLFup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_tightBtagSFLFup_branch does not exist!\n");
      exit(1);
    }
    Common_event_tightBtagSFLFup_isLoaded = true;
  }
  return Common_event_tightBtagSFLFup_;
}

const float &VVV0LepTree::Common_event_tightBtagSFLFdn() {
  if (not Common_event_tightBtagSFLFdn_isLoaded) {
    if (Common_event_tightBtagSFLFdn_branch != 0) {
      Common_event_tightBtagSFLFdn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_tightBtagSFLFdn_branch does not exist!\n");
      exit(1);
    }
    Common_event_tightBtagSFLFdn_isLoaded = true;
  }
  return Common_event_tightBtagSFLFdn_;
}

const float &VVV0LepTree::Common_event_mediumBtagSF() {
  if (not Common_event_mediumBtagSF_isLoaded) {
    if (Common_event_mediumBtagSF_branch != 0) {
      Common_event_mediumBtagSF_branch->GetEntry(index);
    } else {
      printf("branch Common_event_mediumBtagSF_branch does not exist!\n");
      exit(1);
    }
    Common_event_mediumBtagSF_isLoaded = true;
  }
  return Common_event_mediumBtagSF_;
}

const float &VVV0LepTree::Common_event_mediumBtagSFup() {
  if (not Common_event_mediumBtagSFup_isLoaded) {
    if (Common_event_mediumBtagSFup_branch != 0) {
      Common_event_mediumBtagSFup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_mediumBtagSFup_branch does not exist!\n");
      exit(1);
    }
    Common_event_mediumBtagSFup_isLoaded = true;
  }
  return Common_event_mediumBtagSFup_;
}

const float &VVV0LepTree::Common_event_mediumBtagSFdn() {
  if (not Common_event_mediumBtagSFdn_isLoaded) {
    if (Common_event_mediumBtagSFdn_branch != 0) {
      Common_event_mediumBtagSFdn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_mediumBtagSFdn_branch does not exist!\n");
      exit(1);
    }
    Common_event_mediumBtagSFdn_isLoaded = true;
  }
  return Common_event_mediumBtagSFdn_;
}

const float &VVV0LepTree::Common_event_mediumBtagSFHFup() {
  if (not Common_event_mediumBtagSFHFup_isLoaded) {
    if (Common_event_mediumBtagSFHFup_branch != 0) {
      Common_event_mediumBtagSFHFup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_mediumBtagSFHFup_branch does not exist!\n");
      exit(1);
    }
    Common_event_mediumBtagSFHFup_isLoaded = true;
  }
  return Common_event_mediumBtagSFHFup_;
}

const float &VVV0LepTree::Common_event_mediumBtagSFHFdn() {
  if (not Common_event_mediumBtagSFHFdn_isLoaded) {
    if (Common_event_mediumBtagSFHFdn_branch != 0) {
      Common_event_mediumBtagSFHFdn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_mediumBtagSFHFdn_branch does not exist!\n");
      exit(1);
    }
    Common_event_mediumBtagSFHFdn_isLoaded = true;
  }
  return Common_event_mediumBtagSFHFdn_;
}

const float &VVV0LepTree::Common_event_mediumBtagSFLFup() {
  if (not Common_event_mediumBtagSFLFup_isLoaded) {
    if (Common_event_mediumBtagSFLFup_branch != 0) {
      Common_event_mediumBtagSFLFup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_mediumBtagSFLFup_branch does not exist!\n");
      exit(1);
    }
    Common_event_mediumBtagSFLFup_isLoaded = true;
  }
  return Common_event_mediumBtagSFLFup_;
}

const float &VVV0LepTree::Common_event_mediumBtagSFLFdn() {
  if (not Common_event_mediumBtagSFLFdn_isLoaded) {
    if (Common_event_mediumBtagSFLFdn_branch != 0) {
      Common_event_mediumBtagSFLFdn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_mediumBtagSFLFdn_branch does not exist!\n");
      exit(1);
    }
    Common_event_mediumBtagSFLFdn_isLoaded = true;
  }
  return Common_event_mediumBtagSFLFdn_;
}

const float &VVV0LepTree::Common_event_looseBtagSF() {
  if (not Common_event_looseBtagSF_isLoaded) {
    if (Common_event_looseBtagSF_branch != 0) {
      Common_event_looseBtagSF_branch->GetEntry(index);
    } else {
      printf("branch Common_event_looseBtagSF_branch does not exist!\n");
      exit(1);
    }
    Common_event_looseBtagSF_isLoaded = true;
  }
  return Common_event_looseBtagSF_;
}

const float &VVV0LepTree::Common_event_looseBtagSFup() {
  if (not Common_event_looseBtagSFup_isLoaded) {
    if (Common_event_looseBtagSFup_branch != 0) {
      Common_event_looseBtagSFup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_looseBtagSFup_branch does not exist!\n");
      exit(1);
    }
    Common_event_looseBtagSFup_isLoaded = true;
  }
  return Common_event_looseBtagSFup_;
}

const float &VVV0LepTree::Common_event_looseBtagSFdn() {
  if (not Common_event_looseBtagSFdn_isLoaded) {
    if (Common_event_looseBtagSFdn_branch != 0) {
      Common_event_looseBtagSFdn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_looseBtagSFdn_branch does not exist!\n");
      exit(1);
    }
    Common_event_looseBtagSFdn_isLoaded = true;
  }
  return Common_event_looseBtagSFdn_;
}

const float &VVV0LepTree::Common_event_looseBtagSFHFup() {
  if (not Common_event_looseBtagSFHFup_isLoaded) {
    if (Common_event_looseBtagSFHFup_branch != 0) {
      Common_event_looseBtagSFHFup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_looseBtagSFHFup_branch does not exist!\n");
      exit(1);
    }
    Common_event_looseBtagSFHFup_isLoaded = true;
  }
  return Common_event_looseBtagSFHFup_;
}

const float &VVV0LepTree::Common_event_looseBtagSFHFdn() {
  if (not Common_event_looseBtagSFHFdn_isLoaded) {
    if (Common_event_looseBtagSFHFdn_branch != 0) {
      Common_event_looseBtagSFHFdn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_looseBtagSFHFdn_branch does not exist!\n");
      exit(1);
    }
    Common_event_looseBtagSFHFdn_isLoaded = true;
  }
  return Common_event_looseBtagSFHFdn_;
}

const float &VVV0LepTree::Common_event_looseBtagSFLFup() {
  if (not Common_event_looseBtagSFLFup_isLoaded) {
    if (Common_event_looseBtagSFLFup_branch != 0) {
      Common_event_looseBtagSFLFup_branch->GetEntry(index);
    } else {
      printf("branch Common_event_looseBtagSFLFup_branch does not exist!\n");
      exit(1);
    }
    Common_event_looseBtagSFLFup_isLoaded = true;
  }
  return Common_event_looseBtagSFLFup_;
}

const float &VVV0LepTree::Common_event_looseBtagSFLFdn() {
  if (not Common_event_looseBtagSFLFdn_isLoaded) {
    if (Common_event_looseBtagSFLFdn_branch != 0) {
      Common_event_looseBtagSFLFdn_branch->GetEntry(index);
    } else {
      printf("branch Common_event_looseBtagSFLFdn_branch does not exist!\n");
      exit(1);
    }
    Common_event_looseBtagSFLFdn_isLoaded = true;
  }
  return Common_event_looseBtagSFLFdn_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVV0LepTree::Common_lep_p4() {
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

const vector<int> &VVV0LepTree::Common_lep_idxs() {
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

const vector<int> &VVV0LepTree::Common_lep_pdgid() {
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

const vector<int> &VVV0LepTree::Common_lep_tight() {
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

const vector<float> &VVV0LepTree::Common_lep_dxy() {
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

const vector<float> &VVV0LepTree::Common_lep_dz() {
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

const vector<float> &VVV0LepTree::Common_lep_ip3d() {
  if (not Common_lep_ip3d_isLoaded) {
    if (Common_lep_ip3d_branch != 0) {
      Common_lep_ip3d_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_ip3d_branch does not exist!\n");
      exit(1);
    }
    Common_lep_ip3d_isLoaded = true;
  }
  return *Common_lep_ip3d_;
}

const vector<float> &VVV0LepTree::Common_lep_sip3d() {
  if (not Common_lep_sip3d_isLoaded) {
    if (Common_lep_sip3d_branch != 0) {
      Common_lep_sip3d_branch->GetEntry(index);
    } else {
      printf("branch Common_lep_sip3d_branch does not exist!\n");
      exit(1);
    }
    Common_lep_sip3d_isLoaded = true;
  }
  return *Common_lep_sip3d_;
}

const vector<float> &VVV0LepTree::Common_lep_SF() {
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

const vector<float> &VVV0LepTree::Common_lep_SFTight() {
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

const vector<float> &VVV0LepTree::Common_lep_SFdn() {
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

const vector<float> &VVV0LepTree::Common_lep_SFdnTight() {
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

const vector<float> &VVV0LepTree::Common_lep_SFup() {
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

const vector<float> &VVV0LepTree::Common_lep_SFupTight() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVV0LepTree::Common_jet_p4() {
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

const vector<int> &VVV0LepTree::Common_jet_idxs() {
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

const vector<bool> &VVV0LepTree::Common_jet_passBloose() {
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

const vector<bool> &VVV0LepTree::Common_jet_passBmedium() {
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

const vector<bool> &VVV0LepTree::Common_jet_passBtight() {
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

const vector<int> &VVV0LepTree::Common_jet_id() {
  if (not Common_jet_id_isLoaded) {
    if (Common_jet_id_branch != 0) {
      Common_jet_id_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_id_branch does not exist!\n");
      exit(1);
    }
    Common_jet_id_isLoaded = true;
  }
  return *Common_jet_id_;
}

const vector<int> &VVV0LepTree::Common_jet_puid() {
  if (not Common_jet_puid_isLoaded) {
    if (Common_jet_puid_branch != 0) {
      Common_jet_puid_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_puid_branch does not exist!\n");
      exit(1);
    }
    Common_jet_puid_isLoaded = true;
  }
  return *Common_jet_puid_;
}

const vector<int> &VVV0LepTree::Common_jet_overlapfatjet() {
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

const vector<float> &VVV0LepTree::Common_jet_pt_jesup() {
  if (not Common_jet_pt_jesup_isLoaded) {
    if (Common_jet_pt_jesup_branch != 0) {
      Common_jet_pt_jesup_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_pt_jesup_branch does not exist!\n");
      exit(1);
    }
    Common_jet_pt_jesup_isLoaded = true;
  }
  return *Common_jet_pt_jesup_;
}

const vector<float> &VVV0LepTree::Common_jet_pt_jesdn() {
  if (not Common_jet_pt_jesdn_isLoaded) {
    if (Common_jet_pt_jesdn_branch != 0) {
      Common_jet_pt_jesdn_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_pt_jesdn_branch does not exist!\n");
      exit(1);
    }
    Common_jet_pt_jesdn_isLoaded = true;
  }
  return *Common_jet_pt_jesdn_;
}

const vector<float> &VVV0LepTree::Common_jet_pt_jerup() {
  if (not Common_jet_pt_jerup_isLoaded) {
    if (Common_jet_pt_jerup_branch != 0) {
      Common_jet_pt_jerup_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_pt_jerup_branch does not exist!\n");
      exit(1);
    }
    Common_jet_pt_jerup_isLoaded = true;
  }
  return *Common_jet_pt_jerup_;
}

const vector<float> &VVV0LepTree::Common_jet_pt_jerdn() {
  if (not Common_jet_pt_jerdn_isLoaded) {
    if (Common_jet_pt_jerdn_branch != 0) {
      Common_jet_pt_jerdn_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_pt_jerdn_branch does not exist!\n");
      exit(1);
    }
    Common_jet_pt_jerdn_isLoaded = true;
  }
  return *Common_jet_pt_jerdn_;
}

const vector<float> &VVV0LepTree::Common_jet_mass_jesup() {
  if (not Common_jet_mass_jesup_isLoaded) {
    if (Common_jet_mass_jesup_branch != 0) {
      Common_jet_mass_jesup_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_mass_jesup_branch does not exist!\n");
      exit(1);
    }
    Common_jet_mass_jesup_isLoaded = true;
  }
  return *Common_jet_mass_jesup_;
}

const vector<float> &VVV0LepTree::Common_jet_mass_jesdn() {
  if (not Common_jet_mass_jesdn_isLoaded) {
    if (Common_jet_mass_jesdn_branch != 0) {
      Common_jet_mass_jesdn_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_mass_jesdn_branch does not exist!\n");
      exit(1);
    }
    Common_jet_mass_jesdn_isLoaded = true;
  }
  return *Common_jet_mass_jesdn_;
}

const vector<float> &VVV0LepTree::Common_jet_mass_jerup() {
  if (not Common_jet_mass_jerup_isLoaded) {
    if (Common_jet_mass_jerup_branch != 0) {
      Common_jet_mass_jerup_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_mass_jerup_branch does not exist!\n");
      exit(1);
    }
    Common_jet_mass_jerup_isLoaded = true;
  }
  return *Common_jet_mass_jerup_;
}

const vector<float> &VVV0LepTree::Common_jet_mass_jerdn() {
  if (not Common_jet_mass_jerdn_isLoaded) {
    if (Common_jet_mass_jerdn_branch != 0) {
      Common_jet_mass_jerdn_branch->GetEntry(index);
    } else {
      printf("branch Common_jet_mass_jerdn_branch does not exist!\n");
      exit(1);
    }
    Common_jet_mass_jerdn_isLoaded = true;
  }
  return *Common_jet_mass_jerdn_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVV0LepTree::Common_fatjet_p4() {
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

const vector<int> &VVV0LepTree::Common_fatjet_idxs() {
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

const vector<int> &VVV0LepTree::Common_fatjet_id() {
  if (not Common_fatjet_id_isLoaded) {
    if (Common_fatjet_id_branch != 0) {
      Common_fatjet_id_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_id_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_id_isLoaded = true;
  }
  return *Common_fatjet_id_;
}

const vector<float> &VVV0LepTree::Common_fatjet_msoftdrop() {
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

const vector<float> &VVV0LepTree::Common_fatjet_deepMD_W() {
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

const vector<float> &VVV0LepTree::Common_fatjet_deep_W() {
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

const vector<float> &VVV0LepTree::Common_fatjet_deepMD_Z() {
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

const vector<float> &VVV0LepTree::Common_fatjet_deep_Z() {
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

const vector<float> &VVV0LepTree::Common_fatjet_deepMD_T() {
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

const vector<float> &VVV0LepTree::Common_fatjet_deep_T() {
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

const vector<float> &VVV0LepTree::Common_fatjet_deepMD_bb() {
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

const vector<float> &VVV0LepTree::Common_fatjet_particleNetMD_W() {
  if (not Common_fatjet_particleNetMD_W_isLoaded) {
    if (Common_fatjet_particleNetMD_W_branch != 0) {
      Common_fatjet_particleNetMD_W_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_particleNetMD_W_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_particleNetMD_W_isLoaded = true;
  }
  return *Common_fatjet_particleNetMD_W_;
}

const vector<float> &VVV0LepTree::Common_fatjet_particleNetMD_Xqq() {
  if (not Common_fatjet_particleNetMD_Xqq_isLoaded) {
    if (Common_fatjet_particleNetMD_Xqq_branch != 0) {
      Common_fatjet_particleNetMD_Xqq_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_particleNetMD_Xqq_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_particleNetMD_Xqq_isLoaded = true;
  }
  return *Common_fatjet_particleNetMD_Xqq_;
}

const vector<float> &VVV0LepTree::Common_fatjet_particleNetMD_Xcc() {
  if (not Common_fatjet_particleNetMD_Xcc_isLoaded) {
    if (Common_fatjet_particleNetMD_Xcc_branch != 0) {
      Common_fatjet_particleNetMD_Xcc_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_particleNetMD_Xcc_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_particleNetMD_Xcc_isLoaded = true;
  }
  return *Common_fatjet_particleNetMD_Xcc_;
}

const vector<float> &VVV0LepTree::Common_fatjet_particleNetMD_Xbb() {
  if (not Common_fatjet_particleNetMD_Xbb_isLoaded) {
    if (Common_fatjet_particleNetMD_Xbb_branch != 0) {
      Common_fatjet_particleNetMD_Xbb_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_particleNetMD_Xbb_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_particleNetMD_Xbb_isLoaded = true;
  }
  return *Common_fatjet_particleNetMD_Xbb_;
}

const vector<float> &VVV0LepTree::Common_fatjet_particleNetMD_QCD() {
  if (not Common_fatjet_particleNetMD_QCD_isLoaded) {
    if (Common_fatjet_particleNetMD_QCD_branch != 0) {
      Common_fatjet_particleNetMD_QCD_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_particleNetMD_QCD_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_particleNetMD_QCD_isLoaded = true;
  }
  return *Common_fatjet_particleNetMD_QCD_;
}

const vector<float> &VVV0LepTree::Common_fatjet_particleNet_QCD() {
  if (not Common_fatjet_particleNet_QCD_isLoaded) {
    if (Common_fatjet_particleNet_QCD_branch != 0) {
      Common_fatjet_particleNet_QCD_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_particleNet_QCD_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_particleNet_QCD_isLoaded = true;
  }
  return *Common_fatjet_particleNet_QCD_;
}

const vector<float> &VVV0LepTree::Common_fatjet_particleNet_W() {
  if (not Common_fatjet_particleNet_W_isLoaded) {
    if (Common_fatjet_particleNet_W_branch != 0) {
      Common_fatjet_particleNet_W_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_particleNet_W_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_particleNet_W_isLoaded = true;
  }
  return *Common_fatjet_particleNet_W_;
}

const vector<float> &VVV0LepTree::Common_fatjet_particleNet_Z() {
  if (not Common_fatjet_particleNet_Z_isLoaded) {
    if (Common_fatjet_particleNet_Z_branch != 0) {
      Common_fatjet_particleNet_Z_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_particleNet_Z_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_particleNet_Z_isLoaded = true;
  }
  return *Common_fatjet_particleNet_Z_;
}

const vector<float> &VVV0LepTree::Common_fatjet_particleNet_T() {
  if (not Common_fatjet_particleNet_T_isLoaded) {
    if (Common_fatjet_particleNet_T_branch != 0) {
      Common_fatjet_particleNet_T_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_particleNet_T_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_particleNet_T_isLoaded = true;
  }
  return *Common_fatjet_particleNet_T_;
}

const vector<float> &VVV0LepTree::Common_fatjet_tau3() {
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

const vector<float> &VVV0LepTree::Common_fatjet_tau2() {
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

const vector<float> &VVV0LepTree::Common_fatjet_tau1() {
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

const vector<float> &VVV0LepTree::Common_fatjet_tau32() {
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

const vector<float> &VVV0LepTree::Common_fatjet_tau21() {
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

const vector<float> &VVV0LepTree::Common_fatjet_subjet0_pt() {
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

const vector<float> &VVV0LepTree::Common_fatjet_subjet0_eta() {
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

const vector<float> &VVV0LepTree::Common_fatjet_subjet0_phi() {
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

const vector<float> &VVV0LepTree::Common_fatjet_subjet0_mass() {
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

const vector<float> &VVV0LepTree::Common_fatjet_subjet1_pt() {
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

const vector<float> &VVV0LepTree::Common_fatjet_subjet1_eta() {
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

const vector<float> &VVV0LepTree::Common_fatjet_subjet1_phi() {
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

const vector<float> &VVV0LepTree::Common_fatjet_subjet1_mass() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVV0LepTree::Common_fatjet_subjet0_p4() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVV0LepTree::Common_fatjet_subjet1_p4() {
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

const vector<int> &VVV0LepTree::Common_fatjet_WP() {
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

const vector<int> &VVV0LepTree::Common_fatjet_WP_MD() {
  if (not Common_fatjet_WP_MD_isLoaded) {
    if (Common_fatjet_WP_MD_branch != 0) {
      Common_fatjet_WP_MD_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_WP_MD_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_WP_MD_isLoaded = true;
  }
  return *Common_fatjet_WP_MD_;
}

const vector<int> &VVV0LepTree::Common_fatjet_WP_antimasscut() {
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

const vector<int> &VVV0LepTree::Common_fatjet_WP_MD_antimasscut() {
  if (not Common_fatjet_WP_MD_antimasscut_isLoaded) {
    if (Common_fatjet_WP_MD_antimasscut_branch != 0) {
      Common_fatjet_WP_MD_antimasscut_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_WP_MD_antimasscut_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_WP_MD_antimasscut_isLoaded = true;
  }
  return *Common_fatjet_WP_MD_antimasscut_;
}

const vector<float> &VVV0LepTree::Common_fatjet_SFVLoose() {
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

const vector<float> &VVV0LepTree::Common_fatjet_SFLoose() {
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

const vector<float> &VVV0LepTree::Common_fatjet_SFMedium() {
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

const vector<float> &VVV0LepTree::Common_fatjet_SFTight() {
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

const vector<float> &VVV0LepTree::Common_fatjet_SFdnLoose() {
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

const vector<float> &VVV0LepTree::Common_fatjet_SFdnVLoose() {
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

const vector<float> &VVV0LepTree::Common_fatjet_SFdnMedium() {
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

const vector<float> &VVV0LepTree::Common_fatjet_SFdnTight() {
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

const vector<float> &VVV0LepTree::Common_fatjet_SFupVLoose() {
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

const vector<float> &VVV0LepTree::Common_fatjet_SFupLoose() {
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

const vector<float> &VVV0LepTree::Common_fatjet_SFupMedium() {
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

const vector<float> &VVV0LepTree::Common_fatjet_SFupTight() {
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

const vector<float> &VVV0LepTree::Common_fatjet_MD_SFLoose() {
  if (not Common_fatjet_MD_SFLoose_isLoaded) {
    if (Common_fatjet_MD_SFLoose_branch != 0) {
      Common_fatjet_MD_SFLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_MD_SFLoose_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_MD_SFLoose_isLoaded = true;
  }
  return *Common_fatjet_MD_SFLoose_;
}

const vector<float> &VVV0LepTree::Common_fatjet_MD_SFMedium() {
  if (not Common_fatjet_MD_SFMedium_isLoaded) {
    if (Common_fatjet_MD_SFMedium_branch != 0) {
      Common_fatjet_MD_SFMedium_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_MD_SFMedium_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_MD_SFMedium_isLoaded = true;
  }
  return *Common_fatjet_MD_SFMedium_;
}

const vector<float> &VVV0LepTree::Common_fatjet_MD_SFTight() {
  if (not Common_fatjet_MD_SFTight_isLoaded) {
    if (Common_fatjet_MD_SFTight_branch != 0) {
      Common_fatjet_MD_SFTight_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_MD_SFTight_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_MD_SFTight_isLoaded = true;
  }
  return *Common_fatjet_MD_SFTight_;
}

const vector<float> &VVV0LepTree::Common_fatjet_MD_SFdnLoose() {
  if (not Common_fatjet_MD_SFdnLoose_isLoaded) {
    if (Common_fatjet_MD_SFdnLoose_branch != 0) {
      Common_fatjet_MD_SFdnLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_MD_SFdnLoose_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_MD_SFdnLoose_isLoaded = true;
  }
  return *Common_fatjet_MD_SFdnLoose_;
}

const vector<float> &VVV0LepTree::Common_fatjet_MD_SFdnMedium() {
  if (not Common_fatjet_MD_SFdnMedium_isLoaded) {
    if (Common_fatjet_MD_SFdnMedium_branch != 0) {
      Common_fatjet_MD_SFdnMedium_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_MD_SFdnMedium_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_MD_SFdnMedium_isLoaded = true;
  }
  return *Common_fatjet_MD_SFdnMedium_;
}

const vector<float> &VVV0LepTree::Common_fatjet_MD_SFdnTight() {
  if (not Common_fatjet_MD_SFdnTight_isLoaded) {
    if (Common_fatjet_MD_SFdnTight_branch != 0) {
      Common_fatjet_MD_SFdnTight_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_MD_SFdnTight_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_MD_SFdnTight_isLoaded = true;
  }
  return *Common_fatjet_MD_SFdnTight_;
}

const vector<float> &VVV0LepTree::Common_fatjet_MD_SFupLoose() {
  if (not Common_fatjet_MD_SFupLoose_isLoaded) {
    if (Common_fatjet_MD_SFupLoose_branch != 0) {
      Common_fatjet_MD_SFupLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_MD_SFupLoose_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_MD_SFupLoose_isLoaded = true;
  }
  return *Common_fatjet_MD_SFupLoose_;
}

const vector<float> &VVV0LepTree::Common_fatjet_MD_SFupMedium() {
  if (not Common_fatjet_MD_SFupMedium_isLoaded) {
    if (Common_fatjet_MD_SFupMedium_branch != 0) {
      Common_fatjet_MD_SFupMedium_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_MD_SFupMedium_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_MD_SFupMedium_isLoaded = true;
  }
  return *Common_fatjet_MD_SFupMedium_;
}

const vector<float> &VVV0LepTree::Common_fatjet_MD_SFupTight() {
  if (not Common_fatjet_MD_SFupTight_isLoaded) {
    if (Common_fatjet_MD_SFupTight_branch != 0) {
      Common_fatjet_MD_SFupTight_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_MD_SFupTight_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_MD_SFupTight_isLoaded = true;
  }
  return *Common_fatjet_MD_SFupTight_;
}

const vector<float> &VVV0LepTree::Common_fatjet_pt_jesup() {
  if (not Common_fatjet_pt_jesup_isLoaded) {
    if (Common_fatjet_pt_jesup_branch != 0) {
      Common_fatjet_pt_jesup_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_pt_jesup_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_pt_jesup_isLoaded = true;
  }
  return *Common_fatjet_pt_jesup_;
}

const vector<float> &VVV0LepTree::Common_fatjet_pt_jesdn() {
  if (not Common_fatjet_pt_jesdn_isLoaded) {
    if (Common_fatjet_pt_jesdn_branch != 0) {
      Common_fatjet_pt_jesdn_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_pt_jesdn_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_pt_jesdn_isLoaded = true;
  }
  return *Common_fatjet_pt_jesdn_;
}

const vector<float> &VVV0LepTree::Common_fatjet_pt_jerup() {
  if (not Common_fatjet_pt_jerup_isLoaded) {
    if (Common_fatjet_pt_jerup_branch != 0) {
      Common_fatjet_pt_jerup_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_pt_jerup_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_pt_jerup_isLoaded = true;
  }
  return *Common_fatjet_pt_jerup_;
}

const vector<float> &VVV0LepTree::Common_fatjet_pt_jerdn() {
  if (not Common_fatjet_pt_jerdn_isLoaded) {
    if (Common_fatjet_pt_jerdn_branch != 0) {
      Common_fatjet_pt_jerdn_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_pt_jerdn_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_pt_jerdn_isLoaded = true;
  }
  return *Common_fatjet_pt_jerdn_;
}

const vector<float> &VVV0LepTree::Common_fatjet_msoftdrop_jesup() {
  if (not Common_fatjet_msoftdrop_jesup_isLoaded) {
    if (Common_fatjet_msoftdrop_jesup_branch != 0) {
      Common_fatjet_msoftdrop_jesup_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_msoftdrop_jesup_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_msoftdrop_jesup_isLoaded = true;
  }
  return *Common_fatjet_msoftdrop_jesup_;
}

const vector<float> &VVV0LepTree::Common_fatjet_msoftdrop_jesdn() {
  if (not Common_fatjet_msoftdrop_jesdn_isLoaded) {
    if (Common_fatjet_msoftdrop_jesdn_branch != 0) {
      Common_fatjet_msoftdrop_jesdn_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_msoftdrop_jesdn_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_msoftdrop_jesdn_isLoaded = true;
  }
  return *Common_fatjet_msoftdrop_jesdn_;
}

const vector<float> &VVV0LepTree::Common_fatjet_msoftdrop_jerup() {
  if (not Common_fatjet_msoftdrop_jerup_isLoaded) {
    if (Common_fatjet_msoftdrop_jerup_branch != 0) {
      Common_fatjet_msoftdrop_jerup_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_msoftdrop_jerup_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_msoftdrop_jerup_isLoaded = true;
  }
  return *Common_fatjet_msoftdrop_jerup_;
}

const vector<float> &VVV0LepTree::Common_fatjet_msoftdrop_jerdn() {
  if (not Common_fatjet_msoftdrop_jerdn_isLoaded) {
    if (Common_fatjet_msoftdrop_jerdn_branch != 0) {
      Common_fatjet_msoftdrop_jerdn_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_msoftdrop_jerdn_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_msoftdrop_jerdn_isLoaded = true;
  }
  return *Common_fatjet_msoftdrop_jerdn_;
}

const vector<float> &VVV0LepTree::Common_fatjet_msoftdrop_jmsup() {
  if (not Common_fatjet_msoftdrop_jmsup_isLoaded) {
    if (Common_fatjet_msoftdrop_jmsup_branch != 0) {
      Common_fatjet_msoftdrop_jmsup_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_msoftdrop_jmsup_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_msoftdrop_jmsup_isLoaded = true;
  }
  return *Common_fatjet_msoftdrop_jmsup_;
}

const vector<float> &VVV0LepTree::Common_fatjet_msoftdrop_jmsdn() {
  if (not Common_fatjet_msoftdrop_jmsdn_isLoaded) {
    if (Common_fatjet_msoftdrop_jmsdn_branch != 0) {
      Common_fatjet_msoftdrop_jmsdn_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_msoftdrop_jmsdn_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_msoftdrop_jmsdn_isLoaded = true;
  }
  return *Common_fatjet_msoftdrop_jmsdn_;
}

const vector<float> &VVV0LepTree::Common_fatjet_msoftdrop_jmrup() {
  if (not Common_fatjet_msoftdrop_jmrup_isLoaded) {
    if (Common_fatjet_msoftdrop_jmrup_branch != 0) {
      Common_fatjet_msoftdrop_jmrup_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_msoftdrop_jmrup_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_msoftdrop_jmrup_isLoaded = true;
  }
  return *Common_fatjet_msoftdrop_jmrup_;
}

const vector<float> &VVV0LepTree::Common_fatjet_msoftdrop_jmrdn() {
  if (not Common_fatjet_msoftdrop_jmrdn_isLoaded) {
    if (Common_fatjet_msoftdrop_jmrdn_branch != 0) {
      Common_fatjet_msoftdrop_jmrdn_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_msoftdrop_jmrdn_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_msoftdrop_jmrdn_isLoaded = true;
  }
  return *Common_fatjet_msoftdrop_jmrdn_;
}

const vector<float> &VVV0LepTree::Common_fatjet_mass_jesup() {
  if (not Common_fatjet_mass_jesup_isLoaded) {
    if (Common_fatjet_mass_jesup_branch != 0) {
      Common_fatjet_mass_jesup_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_mass_jesup_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_mass_jesup_isLoaded = true;
  }
  return *Common_fatjet_mass_jesup_;
}

const vector<float> &VVV0LepTree::Common_fatjet_mass_jesdn() {
  if (not Common_fatjet_mass_jesdn_isLoaded) {
    if (Common_fatjet_mass_jesdn_branch != 0) {
      Common_fatjet_mass_jesdn_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_mass_jesdn_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_mass_jesdn_isLoaded = true;
  }
  return *Common_fatjet_mass_jesdn_;
}

const vector<float> &VVV0LepTree::Common_fatjet_mass_jerup() {
  if (not Common_fatjet_mass_jerup_isLoaded) {
    if (Common_fatjet_mass_jerup_branch != 0) {
      Common_fatjet_mass_jerup_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_mass_jerup_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_mass_jerup_isLoaded = true;
  }
  return *Common_fatjet_mass_jerup_;
}

const vector<float> &VVV0LepTree::Common_fatjet_mass_jerdn() {
  if (not Common_fatjet_mass_jerdn_isLoaded) {
    if (Common_fatjet_mass_jerdn_branch != 0) {
      Common_fatjet_mass_jerdn_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_mass_jerdn_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_mass_jerdn_isLoaded = true;
  }
  return *Common_fatjet_mass_jerdn_;
}

const vector<float> &VVV0LepTree::Common_fatjet_mass_jmsup() {
  if (not Common_fatjet_mass_jmsup_isLoaded) {
    if (Common_fatjet_mass_jmsup_branch != 0) {
      Common_fatjet_mass_jmsup_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_mass_jmsup_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_mass_jmsup_isLoaded = true;
  }
  return *Common_fatjet_mass_jmsup_;
}

const vector<float> &VVV0LepTree::Common_fatjet_mass_jmsdn() {
  if (not Common_fatjet_mass_jmsdn_isLoaded) {
    if (Common_fatjet_mass_jmsdn_branch != 0) {
      Common_fatjet_mass_jmsdn_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_mass_jmsdn_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_mass_jmsdn_isLoaded = true;
  }
  return *Common_fatjet_mass_jmsdn_;
}

const vector<float> &VVV0LepTree::Common_fatjet_mass_jmrup() {
  if (not Common_fatjet_mass_jmrup_isLoaded) {
    if (Common_fatjet_mass_jmrup_branch != 0) {
      Common_fatjet_mass_jmrup_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_mass_jmrup_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_mass_jmrup_isLoaded = true;
  }
  return *Common_fatjet_mass_jmrup_;
}

const vector<float> &VVV0LepTree::Common_fatjet_mass_jmrdn() {
  if (not Common_fatjet_mass_jmrdn_isLoaded) {
    if (Common_fatjet_mass_jmrdn_branch != 0) {
      Common_fatjet_mass_jmrdn_branch->GetEntry(index);
    } else {
      printf("branch Common_fatjet_mass_jmrdn_branch does not exist!\n");
      exit(1);
    }
    Common_fatjet_mass_jmrdn_isLoaded = true;
  }
  return *Common_fatjet_mass_jmrdn_;
}

const float &VVV0LepTree::Common_eventweight_fatjet_SFVLoose() {
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

const float &VVV0LepTree::Common_eventweight_fatjet_SFLoose() {
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

const float &VVV0LepTree::Common_eventweight_fatjet_SFMedium() {
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

const float &VVV0LepTree::Common_eventweight_fatjet_SFTight() {
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

const float &VVV0LepTree::Common_eventweight_fatjet_SFdnVLoose() {
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

const float &VVV0LepTree::Common_eventweight_fatjet_SFdnLoose() {
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

const float &VVV0LepTree::Common_eventweight_fatjet_SFdnMedium() {
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

const float &VVV0LepTree::Common_eventweight_fatjet_SFdnTight() {
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

const float &VVV0LepTree::Common_eventweight_fatjet_SFupVLoose() {
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

const float &VVV0LepTree::Common_eventweight_fatjet_SFupLoose() {
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

const float &VVV0LepTree::Common_eventweight_fatjet_SFupMedium() {
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

const float &VVV0LepTree::Common_eventweight_fatjet_SFupTight() {
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

const float &VVV0LepTree::Common_eventweight_fatjet_MD_SFLoose() {
  if (not Common_eventweight_fatjet_MD_SFLoose_isLoaded) {
    if (Common_eventweight_fatjet_MD_SFLoose_branch != 0) {
      Common_eventweight_fatjet_MD_SFLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_MD_SFLoose_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_MD_SFLoose_isLoaded = true;
  }
  return Common_eventweight_fatjet_MD_SFLoose_;
}

const float &VVV0LepTree::Common_eventweight_fatjet_MD_SFMedium() {
  if (not Common_eventweight_fatjet_MD_SFMedium_isLoaded) {
    if (Common_eventweight_fatjet_MD_SFMedium_branch != 0) {
      Common_eventweight_fatjet_MD_SFMedium_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_MD_SFMedium_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_MD_SFMedium_isLoaded = true;
  }
  return Common_eventweight_fatjet_MD_SFMedium_;
}

const float &VVV0LepTree::Common_eventweight_fatjet_MD_SFTight() {
  if (not Common_eventweight_fatjet_MD_SFTight_isLoaded) {
    if (Common_eventweight_fatjet_MD_SFTight_branch != 0) {
      Common_eventweight_fatjet_MD_SFTight_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_MD_SFTight_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_MD_SFTight_isLoaded = true;
  }
  return Common_eventweight_fatjet_MD_SFTight_;
}

const float &VVV0LepTree::Common_eventweight_fatjet_MD_SFdnLoose() {
  if (not Common_eventweight_fatjet_MD_SFdnLoose_isLoaded) {
    if (Common_eventweight_fatjet_MD_SFdnLoose_branch != 0) {
      Common_eventweight_fatjet_MD_SFdnLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_MD_SFdnLoose_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_MD_SFdnLoose_isLoaded = true;
  }
  return Common_eventweight_fatjet_MD_SFdnLoose_;
}

const float &VVV0LepTree::Common_eventweight_fatjet_MD_SFdnMedium() {
  if (not Common_eventweight_fatjet_MD_SFdnMedium_isLoaded) {
    if (Common_eventweight_fatjet_MD_SFdnMedium_branch != 0) {
      Common_eventweight_fatjet_MD_SFdnMedium_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_MD_SFdnMedium_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_MD_SFdnMedium_isLoaded = true;
  }
  return Common_eventweight_fatjet_MD_SFdnMedium_;
}

const float &VVV0LepTree::Common_eventweight_fatjet_MD_SFdnTight() {
  if (not Common_eventweight_fatjet_MD_SFdnTight_isLoaded) {
    if (Common_eventweight_fatjet_MD_SFdnTight_branch != 0) {
      Common_eventweight_fatjet_MD_SFdnTight_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_MD_SFdnTight_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_MD_SFdnTight_isLoaded = true;
  }
  return Common_eventweight_fatjet_MD_SFdnTight_;
}

const float &VVV0LepTree::Common_eventweight_fatjet_MD_SFupLoose() {
  if (not Common_eventweight_fatjet_MD_SFupLoose_isLoaded) {
    if (Common_eventweight_fatjet_MD_SFupLoose_branch != 0) {
      Common_eventweight_fatjet_MD_SFupLoose_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_MD_SFupLoose_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_MD_SFupLoose_isLoaded = true;
  }
  return Common_eventweight_fatjet_MD_SFupLoose_;
}

const float &VVV0LepTree::Common_eventweight_fatjet_MD_SFupMedium() {
  if (not Common_eventweight_fatjet_MD_SFupMedium_isLoaded) {
    if (Common_eventweight_fatjet_MD_SFupMedium_branch != 0) {
      Common_eventweight_fatjet_MD_SFupMedium_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_MD_SFupMedium_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_MD_SFupMedium_isLoaded = true;
  }
  return Common_eventweight_fatjet_MD_SFupMedium_;
}

const float &VVV0LepTree::Common_eventweight_fatjet_MD_SFupTight() {
  if (not Common_eventweight_fatjet_MD_SFupTight_isLoaded) {
    if (Common_eventweight_fatjet_MD_SFupTight_branch != 0) {
      Common_eventweight_fatjet_MD_SFupTight_branch->GetEntry(index);
    } else {
      printf("branch Common_eventweight_fatjet_MD_SFupTight_branch does not exist!\n");
      exit(1);
    }
    Common_eventweight_fatjet_MD_SFupTight_isLoaded = true;
  }
  return Common_eventweight_fatjet_MD_SFupTight_;
}

const int &VVV0LepTree::Common_nb_loose() {
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

const int &VVV0LepTree::Common_nb_medium() {
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

const int &VVV0LepTree::Common_nb_tight() {
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

const vector<int> &VVV0LepTree::Common_gen_idx() {
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

const vector<int> &VVV0LepTree::Common_gen_mother_idx() {
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

const vector<int> &VVV0LepTree::Common_gen_mother_id() {
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

const vector<int> &VVV0LepTree::Common_gen_pdgid() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVV0LepTree::Common_gen_p4s() {
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

const vector<int> &VVV0LepTree::Common_gen_vvvdecay_idx() {
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

const vector<int> &VVV0LepTree::Common_gen_vvvdecay_mother_idx() {
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

const vector<int> &VVV0LepTree::Common_gen_vvvdecay_mother_id() {
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

const vector<int> &VVV0LepTree::Common_gen_vvvdecay_pdgid() {
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

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVV0LepTree::Common_gen_vvvdecay_p4s() {
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

const vector<int> &VVV0LepTree::Common_gen_vvvdecay_taudecayid() {
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

const bool &VVV0LepTree::Common_isSignal() {
  if (not Common_isSignal_isLoaded) {
    if (Common_isSignal_branch != 0) {
      Common_isSignal_branch->GetEntry(index);
    } else {
      printf("branch Common_isSignal_branch does not exist!\n");
      exit(1);
    }
    Common_isSignal_isLoaded = true;
  }
  return Common_isSignal_;
}

const int &VVV0LepTree::Common_n_W() {
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

const int &VVV0LepTree::Common_n_Z() {
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

const int &VVV0LepTree::Common_n_lep_Z() {
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

const int &VVV0LepTree::Common_n_leptau_Z() {
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

const int &VVV0LepTree::Common_n_hadtau_Z() {
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

const int &VVV0LepTree::Common_n_nu_Z() {
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

const int &VVV0LepTree::Common_n_b_Z() {
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

const int &VVV0LepTree::Common_n_lep_W() {
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

const int &VVV0LepTree::Common_n_leptau_W() {
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

const int &VVV0LepTree::Common_n_hadtau_W() {
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

const bool &VVV0LepTree::Common_haslepWSS() {
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

const float &VVV0LepTree::Common_genHT() {
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

const int &VVV0LepTree::Common_gen_n_light_lep() {
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

const int &VVV0LepTree::Common_gen_VH_channel() {
  if (not Common_gen_VH_channel_isLoaded) {
    if (Common_gen_VH_channel_branch != 0) {
      Common_gen_VH_channel_branch->GetEntry(index);
    } else {
      printf("branch Common_gen_VH_channel_branch does not exist!\n");
      exit(1);
    }
    Common_gen_VH_channel_isLoaded = true;
  }
  return Common_gen_VH_channel_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVV0LepTree::allHad_jets_p4() {
  if (not allHad_jets_p4_isLoaded) {
    if (allHad_jets_p4_branch != 0) {
      allHad_jets_p4_branch->GetEntry(index);
    } else {
      printf("branch allHad_jets_p4_branch does not exist!\n");
      exit(1);
    }
    allHad_jets_p4_isLoaded = true;
  }
  return *allHad_jets_p4_;
}

const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &VVV0LepTree::allHad_fatjets_mSD_p4() {
  if (not allHad_fatjets_mSD_p4_isLoaded) {
    if (allHad_fatjets_mSD_p4_branch != 0) {
      allHad_fatjets_mSD_p4_branch->GetEntry(index);
    } else {
      printf("branch allHad_fatjets_mSD_p4_branch does not exist!\n");
      exit(1);
    }
    allHad_fatjets_mSD_p4_isLoaded = true;
  }
  return *allHad_fatjets_mSD_p4_;
}

const vector<int> &VVV0LepTree::allHad_fatjets_WP_MD() {
  if (not allHad_fatjets_WP_MD_isLoaded) {
    if (allHad_fatjets_WP_MD_branch != 0) {
      allHad_fatjets_WP_MD_branch->GetEntry(index);
    } else {
      printf("branch allHad_fatjets_WP_MD_branch does not exist!\n");
      exit(1);
    }
    allHad_fatjets_WP_MD_isLoaded = true;
  }
  return *allHad_fatjets_WP_MD_;
}

const vector<int> &VVV0LepTree::allHad_fatjets_commonFJIdxs() {
  if (not allHad_fatjets_commonFJIdxs_isLoaded) {
    if (allHad_fatjets_commonFJIdxs_branch != 0) {
      allHad_fatjets_commonFJIdxs_branch->GetEntry(index);
    } else {
      printf("branch allHad_fatjets_commonFJIdxs_branch does not exist!\n");
      exit(1);
    }
    allHad_fatjets_commonFJIdxs_isLoaded = true;
  }
  return *allHad_fatjets_commonFJIdxs_;
}

const int &VVV0LepTree::allHad_nFJ() {
  if (not allHad_nFJ_isLoaded) {
    if (allHad_nFJ_branch != 0) {
      allHad_nFJ_branch->GetEntry(index);
    } else {
      printf("branch allHad_nFJ_branch does not exist!\n");
      exit(1);
    }
    allHad_nFJ_isLoaded = true;
  }
  return allHad_nFJ_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVV0LepTree::allHad_FJ0_mSD_p4() {
  if (not allHad_FJ0_mSD_p4_isLoaded) {
    if (allHad_FJ0_mSD_p4_branch != 0) {
      allHad_FJ0_mSD_p4_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ0_mSD_p4_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ0_mSD_p4_isLoaded = true;
  }
  return *allHad_FJ0_mSD_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVV0LepTree::allHad_FJ1_mSD_p4() {
  if (not allHad_FJ1_mSD_p4_isLoaded) {
    if (allHad_FJ1_mSD_p4_branch != 0) {
      allHad_FJ1_mSD_p4_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ1_mSD_p4_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ1_mSD_p4_isLoaded = true;
  }
  return *allHad_FJ1_mSD_p4_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVV0LepTree::allHad_FJ2_mSD_p4() {
  if (not allHad_FJ2_mSD_p4_isLoaded) {
    if (allHad_FJ2_mSD_p4_branch != 0) {
      allHad_FJ2_mSD_p4_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ2_mSD_p4_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ2_mSD_p4_isLoaded = true;
  }
  return *allHad_FJ2_mSD_p4_;
}

const int &VVV0LepTree::allHad_FJ0_WP_MD() {
  if (not allHad_FJ0_WP_MD_isLoaded) {
    if (allHad_FJ0_WP_MD_branch != 0) {
      allHad_FJ0_WP_MD_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ0_WP_MD_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ0_WP_MD_isLoaded = true;
  }
  return allHad_FJ0_WP_MD_;
}

const int &VVV0LepTree::allHad_FJ1_WP_MD() {
  if (not allHad_FJ1_WP_MD_isLoaded) {
    if (allHad_FJ1_WP_MD_branch != 0) {
      allHad_FJ1_WP_MD_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ1_WP_MD_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ1_WP_MD_isLoaded = true;
  }
  return allHad_FJ1_WP_MD_;
}

const int &VVV0LepTree::allHad_FJ2_WP_MD() {
  if (not allHad_FJ2_WP_MD_isLoaded) {
    if (allHad_FJ2_WP_MD_branch != 0) {
      allHad_FJ2_WP_MD_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ2_WP_MD_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ2_WP_MD_isLoaded = true;
  }
  return allHad_FJ2_WP_MD_;
}

const float &VVV0LepTree::allHad_FJ0_WMD() {
  if (not allHad_FJ0_WMD_isLoaded) {
    if (allHad_FJ0_WMD_branch != 0) {
      allHad_FJ0_WMD_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ0_WMD_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ0_WMD_isLoaded = true;
  }
  return allHad_FJ0_WMD_;
}

const float &VVV0LepTree::allHad_FJ1_WMD() {
  if (not allHad_FJ1_WMD_isLoaded) {
    if (allHad_FJ1_WMD_branch != 0) {
      allHad_FJ1_WMD_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ1_WMD_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ1_WMD_isLoaded = true;
  }
  return allHad_FJ1_WMD_;
}

const float &VVV0LepTree::allHad_FJ2_WMD() {
  if (not allHad_FJ2_WMD_isLoaded) {
    if (allHad_FJ2_WMD_branch != 0) {
      allHad_FJ2_WMD_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ2_WMD_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ2_WMD_isLoaded = true;
  }
  return allHad_FJ2_WMD_;
}

const float &VVV0LepTree::allHad_FJ0_VMD() {
  if (not allHad_FJ0_VMD_isLoaded) {
    if (allHad_FJ0_VMD_branch != 0) {
      allHad_FJ0_VMD_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ0_VMD_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ0_VMD_isLoaded = true;
  }
  return allHad_FJ0_VMD_;
}

const float &VVV0LepTree::allHad_FJ1_VMD() {
  if (not allHad_FJ1_VMD_isLoaded) {
    if (allHad_FJ1_VMD_branch != 0) {
      allHad_FJ1_VMD_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ1_VMD_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ1_VMD_isLoaded = true;
  }
  return allHad_FJ1_VMD_;
}

const float &VVV0LepTree::allHad_FJ2_VMD() {
  if (not allHad_FJ2_VMD_isLoaded) {
    if (allHad_FJ2_VMD_branch != 0) {
      allHad_FJ2_VMD_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ2_VMD_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ2_VMD_isLoaded = true;
  }
  return allHad_FJ2_VMD_;
}

const float &VVV0LepTree::allHad_FJ0_Xqq() {
  if (not allHad_FJ0_Xqq_isLoaded) {
    if (allHad_FJ0_Xqq_branch != 0) {
      allHad_FJ0_Xqq_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ0_Xqq_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ0_Xqq_isLoaded = true;
  }
  return allHad_FJ0_Xqq_;
}

const float &VVV0LepTree::allHad_FJ1_Xqq() {
  if (not allHad_FJ1_Xqq_isLoaded) {
    if (allHad_FJ1_Xqq_branch != 0) {
      allHad_FJ1_Xqq_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ1_Xqq_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ1_Xqq_isLoaded = true;
  }
  return allHad_FJ1_Xqq_;
}

const float &VVV0LepTree::allHad_FJ2_Xqq() {
  if (not allHad_FJ2_Xqq_isLoaded) {
    if (allHad_FJ2_Xqq_branch != 0) {
      allHad_FJ2_Xqq_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ2_Xqq_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ2_Xqq_isLoaded = true;
  }
  return allHad_FJ2_Xqq_;
}

const float &VVV0LepTree::allHad_FJ0_Xcc() {
  if (not allHad_FJ0_Xcc_isLoaded) {
    if (allHad_FJ0_Xcc_branch != 0) {
      allHad_FJ0_Xcc_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ0_Xcc_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ0_Xcc_isLoaded = true;
  }
  return allHad_FJ0_Xcc_;
}

const float &VVV0LepTree::allHad_FJ1_Xcc() {
  if (not allHad_FJ1_Xcc_isLoaded) {
    if (allHad_FJ1_Xcc_branch != 0) {
      allHad_FJ1_Xcc_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ1_Xcc_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ1_Xcc_isLoaded = true;
  }
  return allHad_FJ1_Xcc_;
}

const float &VVV0LepTree::allHad_FJ2_Xcc() {
  if (not allHad_FJ2_Xcc_isLoaded) {
    if (allHad_FJ2_Xcc_branch != 0) {
      allHad_FJ2_Xcc_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ2_Xcc_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ2_Xcc_isLoaded = true;
  }
  return allHad_FJ2_Xcc_;
}

const float &VVV0LepTree::allHad_FJ0_Xbb() {
  if (not allHad_FJ0_Xbb_isLoaded) {
    if (allHad_FJ0_Xbb_branch != 0) {
      allHad_FJ0_Xbb_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ0_Xbb_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ0_Xbb_isLoaded = true;
  }
  return allHad_FJ0_Xbb_;
}

const float &VVV0LepTree::allHad_FJ1_Xbb() {
  if (not allHad_FJ1_Xbb_isLoaded) {
    if (allHad_FJ1_Xbb_branch != 0) {
      allHad_FJ1_Xbb_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ1_Xbb_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ1_Xbb_isLoaded = true;
  }
  return allHad_FJ1_Xbb_;
}

const float &VVV0LepTree::allHad_FJ2_Xbb() {
  if (not allHad_FJ2_Xbb_isLoaded) {
    if (allHad_FJ2_Xbb_branch != 0) {
      allHad_FJ2_Xbb_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ2_Xbb_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ2_Xbb_isLoaded = true;
  }
  return allHad_FJ2_Xbb_;
}

const float &VVV0LepTree::allHad_FJ0_QCD() {
  if (not allHad_FJ0_QCD_isLoaded) {
    if (allHad_FJ0_QCD_branch != 0) {
      allHad_FJ0_QCD_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ0_QCD_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ0_QCD_isLoaded = true;
  }
  return allHad_FJ0_QCD_;
}

const float &VVV0LepTree::allHad_FJ1_QCD() {
  if (not allHad_FJ1_QCD_isLoaded) {
    if (allHad_FJ1_QCD_branch != 0) {
      allHad_FJ1_QCD_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ1_QCD_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ1_QCD_isLoaded = true;
  }
  return allHad_FJ1_QCD_;
}

const float &VVV0LepTree::allHad_FJ2_QCD() {
  if (not allHad_FJ2_QCD_isLoaded) {
    if (allHad_FJ2_QCD_branch != 0) {
      allHad_FJ2_QCD_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ2_QCD_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ2_QCD_isLoaded = true;
  }
  return allHad_FJ2_QCD_;
}

const int &VVV0LepTree::allHad_FJ0_commonFJIdxs() {
  if (not allHad_FJ0_commonFJIdxs_isLoaded) {
    if (allHad_FJ0_commonFJIdxs_branch != 0) {
      allHad_FJ0_commonFJIdxs_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ0_commonFJIdxs_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ0_commonFJIdxs_isLoaded = true;
  }
  return allHad_FJ0_commonFJIdxs_;
}

const int &VVV0LepTree::allHad_FJ1_commonFJIdxs() {
  if (not allHad_FJ1_commonFJIdxs_isLoaded) {
    if (allHad_FJ1_commonFJIdxs_branch != 0) {
      allHad_FJ1_commonFJIdxs_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ1_commonFJIdxs_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ1_commonFJIdxs_isLoaded = true;
  }
  return allHad_FJ1_commonFJIdxs_;
}

const int &VVV0LepTree::allHad_FJ2_commonFJIdxs() {
  if (not allHad_FJ2_commonFJIdxs_isLoaded) {
    if (allHad_FJ2_commonFJIdxs_branch != 0) {
      allHad_FJ2_commonFJIdxs_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ2_commonFJIdxs_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ2_commonFJIdxs_isLoaded = true;
  }
  return allHad_FJ2_commonFJIdxs_;
}

const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &VVV0LepTree::allHad_VVV_mSD_p4() {
  if (not allHad_VVV_mSD_p4_isLoaded) {
    if (allHad_VVV_mSD_p4_branch != 0) {
      allHad_VVV_mSD_p4_branch->GetEntry(index);
    } else {
      printf("branch allHad_VVV_mSD_p4_branch does not exist!\n");
      exit(1);
    }
    allHad_VVV_mSD_p4_isLoaded = true;
  }
  return *allHad_VVV_mSD_p4_;
}

const float &VVV0LepTree::allHad_mVVV() {
  if (not allHad_mVVV_isLoaded) {
    if (allHad_mVVV_branch != 0) {
      allHad_mVVV_branch->GetEntry(index);
    } else {
      printf("branch allHad_mVVV_branch does not exist!\n");
      exit(1);
    }
    allHad_mVVV_isLoaded = true;
  }
  return allHad_mVVV_;
}

const float &VVV0LepTree::allHad_ptVVV() {
  if (not allHad_ptVVV_isLoaded) {
    if (allHad_ptVVV_branch != 0) {
      allHad_ptVVV_branch->GetEntry(index);
    } else {
      printf("branch allHad_ptVVV_branch does not exist!\n");
      exit(1);
    }
    allHad_ptVVV_isLoaded = true;
  }
  return allHad_ptVVV_;
}

const float &VVV0LepTree::allHad_HT() {
  if (not allHad_HT_isLoaded) {
    if (allHad_HT_branch != 0) {
      allHad_HT_branch->GetEntry(index);
    } else {
      printf("branch allHad_HT_branch does not exist!\n");
      exit(1);
    }
    allHad_HT_isLoaded = true;
  }
  return allHad_HT_;
}

const float &VVV0LepTree::allHad_HT_FJ() {
  if (not allHad_HT_FJ_isLoaded) {
    if (allHad_HT_FJ_branch != 0) {
      allHad_HT_FJ_branch->GetEntry(index);
    } else {
      printf("branch allHad_HT_FJ_branch does not exist!\n");
      exit(1);
    }
    allHad_HT_FJ_isLoaded = true;
  }
  return allHad_HT_FJ_;
}

const float &VVV0LepTree::allHad_FJ01_dPhi() {
  if (not allHad_FJ01_dPhi_isLoaded) {
    if (allHad_FJ01_dPhi_branch != 0) {
      allHad_FJ01_dPhi_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ01_dPhi_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ01_dPhi_isLoaded = true;
  }
  return allHad_FJ01_dPhi_;
}

const float &VVV0LepTree::allHad_FJ01_dEta() {
  if (not allHad_FJ01_dEta_isLoaded) {
    if (allHad_FJ01_dEta_branch != 0) {
      allHad_FJ01_dEta_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ01_dEta_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ01_dEta_isLoaded = true;
  }
  return allHad_FJ01_dEta_;
}

const float &VVV0LepTree::allHad_FJ01_dR() {
  if (not allHad_FJ01_dR_isLoaded) {
    if (allHad_FJ01_dR_branch != 0) {
      allHad_FJ01_dR_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ01_dR_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ01_dR_isLoaded = true;
  }
  return allHad_FJ01_dR_;
}

const float &VVV0LepTree::allHad_FJ01_dPtFrac() {
  if (not allHad_FJ01_dPtFrac_isLoaded) {
    if (allHad_FJ01_dPtFrac_branch != 0) {
      allHad_FJ01_dPtFrac_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ01_dPtFrac_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ01_dPtFrac_isLoaded = true;
  }
  return allHad_FJ01_dPtFrac_;
}

const float &VVV0LepTree::allHad_FJ01_pPRel() {
  if (not allHad_FJ01_pPRel_isLoaded) {
    if (allHad_FJ01_pPRel_branch != 0) {
      allHad_FJ01_pPRel_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ01_pPRel_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ01_pPRel_isLoaded = true;
  }
  return allHad_FJ01_pPRel_;
}

const float &VVV0LepTree::allHad_FJ02_dPhi() {
  if (not allHad_FJ02_dPhi_isLoaded) {
    if (allHad_FJ02_dPhi_branch != 0) {
      allHad_FJ02_dPhi_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ02_dPhi_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ02_dPhi_isLoaded = true;
  }
  return allHad_FJ02_dPhi_;
}

const float &VVV0LepTree::allHad_FJ02_dEta() {
  if (not allHad_FJ02_dEta_isLoaded) {
    if (allHad_FJ02_dEta_branch != 0) {
      allHad_FJ02_dEta_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ02_dEta_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ02_dEta_isLoaded = true;
  }
  return allHad_FJ02_dEta_;
}

const float &VVV0LepTree::allHad_FJ02_dR() {
  if (not allHad_FJ02_dR_isLoaded) {
    if (allHad_FJ02_dR_branch != 0) {
      allHad_FJ02_dR_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ02_dR_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ02_dR_isLoaded = true;
  }
  return allHad_FJ02_dR_;
}

const float &VVV0LepTree::allHad_FJ02_dPtFrac() {
  if (not allHad_FJ02_dPtFrac_isLoaded) {
    if (allHad_FJ02_dPtFrac_branch != 0) {
      allHad_FJ02_dPtFrac_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ02_dPtFrac_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ02_dPtFrac_isLoaded = true;
  }
  return allHad_FJ02_dPtFrac_;
}

const float &VVV0LepTree::allHad_FJ02_pPRel() {
  if (not allHad_FJ02_pPRel_isLoaded) {
    if (allHad_FJ02_pPRel_branch != 0) {
      allHad_FJ02_pPRel_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ02_pPRel_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ02_pPRel_isLoaded = true;
  }
  return allHad_FJ02_pPRel_;
}

const float &VVV0LepTree::allHad_FJ12_dPhi() {
  if (not allHad_FJ12_dPhi_isLoaded) {
    if (allHad_FJ12_dPhi_branch != 0) {
      allHad_FJ12_dPhi_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ12_dPhi_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ12_dPhi_isLoaded = true;
  }
  return allHad_FJ12_dPhi_;
}

const float &VVV0LepTree::allHad_FJ12_dEta() {
  if (not allHad_FJ12_dEta_isLoaded) {
    if (allHad_FJ12_dEta_branch != 0) {
      allHad_FJ12_dEta_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ12_dEta_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ12_dEta_isLoaded = true;
  }
  return allHad_FJ12_dEta_;
}

const float &VVV0LepTree::allHad_FJ12_dR() {
  if (not allHad_FJ12_dR_isLoaded) {
    if (allHad_FJ12_dR_branch != 0) {
      allHad_FJ12_dR_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ12_dR_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ12_dR_isLoaded = true;
  }
  return allHad_FJ12_dR_;
}

const float &VVV0LepTree::allHad_FJ12_dPtFrac() {
  if (not allHad_FJ12_dPtFrac_isLoaded) {
    if (allHad_FJ12_dPtFrac_branch != 0) {
      allHad_FJ12_dPtFrac_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ12_dPtFrac_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ12_dPtFrac_isLoaded = true;
  }
  return allHad_FJ12_dPtFrac_;
}

const float &VVV0LepTree::allHad_FJ12_pPRel() {
  if (not allHad_FJ12_pPRel_isLoaded) {
    if (allHad_FJ12_pPRel_branch != 0) {
      allHad_FJ12_pPRel_branch->GetEntry(index);
    } else {
      printf("branch allHad_FJ12_pPRel_branch does not exist!\n");
      exit(1);
    }
    allHad_FJ12_pPRel_isLoaded = true;
  }
  return allHad_FJ12_pPRel_;
}


void VVV0LepTree::progress( int nEventsTotal, int nEventsChain ){
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
const int &Common_year() { return vvv.Common_year(); }
const float &Common_genWeight() { return vvv.Common_genWeight(); }
const float &Common_btagWeight_DeepCSVB() { return vvv.Common_btagWeight_DeepCSVB(); }
const float &Common_wgt() { return vvv.Common_wgt(); }
const float &Common_event_puWeight() { return vvv.Common_event_puWeight(); }
const float &Common_event_puWeightup() { return vvv.Common_event_puWeightup(); }
const float &Common_event_puWeightdn() { return vvv.Common_event_puWeightdn(); }
const float &Common_event_prefireWeight() { return vvv.Common_event_prefireWeight(); }
const float &Common_event_prefireWeightup() { return vvv.Common_event_prefireWeightup(); }
const float &Common_event_prefireWeightdn() { return vvv.Common_event_prefireWeightdn(); }
const float &Common_event_triggerWeight() { return vvv.Common_event_triggerWeight(); }
const float &Common_event_triggerWeightup() { return vvv.Common_event_triggerWeightup(); }
const float &Common_event_triggerWeightdn() { return vvv.Common_event_triggerWeightdn(); }
const vector<float> &Common_LHEReweightingWeight() { return vvv.Common_LHEReweightingWeight(); }
const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ() { return vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ(); }
const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL() { return vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL(); }
const bool &Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8() { return vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8(); }
const bool &Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() { return vvv.Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ(); }
const bool &Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL() { return vvv.Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL(); }
const bool &Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() { return vvv.Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ(); }
const bool &Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL() { return vvv.Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL(); }
const bool &Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ() { return vvv.Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ(); }
const bool &Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL() { return vvv.Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL(); }
const bool &Common_HLT_IsoMu24() { return vvv.Common_HLT_IsoMu24(); }
const bool &Common_HLT_Ele32_WPTight() { return vvv.Common_HLT_Ele32_WPTight(); }
const bool &Common_HLT_PFHT1050() { return vvv.Common_HLT_PFHT1050(); }
const bool &Common_HLT_AK8PFJet500() { return vvv.Common_HLT_AK8PFJet500(); }
const bool &Common_HLT_AK8PFJet380_TrimMass30() { return vvv.Common_HLT_AK8PFJet380_TrimMass30(); }
const bool &Common_HLT_AK8PFJet360_TrimMass30() { return vvv.Common_HLT_AK8PFJet360_TrimMass30(); }
const bool &Common_HLT_AK8PFJet400_TrimMass30() { return vvv.Common_HLT_AK8PFJet400_TrimMass30(); }
const bool &Common_HLT_AK8PFJet420_TrimMass30() { return vvv.Common_HLT_AK8PFJet420_TrimMass30(); }
const bool &Common_HLT_AK8PFHT750_TrimMass50() { return vvv.Common_HLT_AK8PFHT750_TrimMass50(); }
const bool &Common_HLT_AK8PFHT800_TrimMass50() { return vvv.Common_HLT_AK8PFHT800_TrimMass50(); }
const bool &Common_HLT_AK8PFHT850_TrimMass50() { return vvv.Common_HLT_AK8PFHT850_TrimMass50(); }
const bool &Common_HLT_AK8PFHT900_TrimMass50() { return vvv.Common_HLT_AK8PFHT900_TrimMass50(); }
const bool &Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5() { return vvv.Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5(); }
const bool &Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5() { return vvv.Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5(); }
const bool &Common_HLT_PFHT800() { return vvv.Common_HLT_PFHT800(); }
const bool &Common_HLT_PFHT900() { return vvv.Common_HLT_PFHT900(); }
const bool &Common_HLT_PFJet450() { return vvv.Common_HLT_PFJet450(); }
const bool &Common_HLT_PFJet500() { return vvv.Common_HLT_PFJet500(); }
const bool &Common_HLT_AK8PFJet450() { return vvv.Common_HLT_AK8PFJet450(); }
const bool &Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50() { return vvv.Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50(); }
const bool &Common_HLT_DoubleEl() { return vvv.Common_HLT_DoubleEl(); }
const bool &Common_HLT_MuEG() { return vvv.Common_HLT_MuEG(); }
const bool &Common_HLT_DoubleMu() { return vvv.Common_HLT_DoubleMu(); }
const bool &Common_pass_duplicate_removal_ee_em_mm() { return vvv.Common_pass_duplicate_removal_ee_em_mm(); }
const bool &Common_pass_duplicate_removal_mm_em_ee() { return vvv.Common_pass_duplicate_removal_mm_em_ee(); }
const bool &Common_noiseFlag() { return vvv.Common_noiseFlag(); }
const bool &Common_noiseFlagMC() { return vvv.Common_noiseFlagMC(); }
const bool &Common_passGoodRun() { return vvv.Common_passGoodRun(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4() { return vvv.Common_met_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesup() { return vvv.Common_met_p4_jesup(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jesdn() { return vvv.Common_met_p4_jesdn(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jerup() { return vvv.Common_met_p4_jerup(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &Common_met_p4_jerdn() { return vvv.Common_met_p4_jerdn(); }
const float &Common_event_lepSF() { return vvv.Common_event_lepSF(); }
const float &Common_event_lepSFelup() { return vvv.Common_event_lepSFelup(); }
const float &Common_event_lepSFeldn() { return vvv.Common_event_lepSFeldn(); }
const float &Common_event_lepSFmuup() { return vvv.Common_event_lepSFmuup(); }
const float &Common_event_lepSFmudn() { return vvv.Common_event_lepSFmudn(); }
const float &Common_event_lepSFTight() { return vvv.Common_event_lepSFTight(); }
const float &Common_event_lepSFelupTight() { return vvv.Common_event_lepSFelupTight(); }
const float &Common_event_lepSFeldnTight() { return vvv.Common_event_lepSFeldnTight(); }
const float &Common_event_lepSFmuupTight() { return vvv.Common_event_lepSFmuupTight(); }
const float &Common_event_lepSFmudnTight() { return vvv.Common_event_lepSFmudnTight(); }
const float &Common_event_tightBtagSF() { return vvv.Common_event_tightBtagSF(); }
const float &Common_event_tightBtagSFup() { return vvv.Common_event_tightBtagSFup(); }
const float &Common_event_tightBtagSFdn() { return vvv.Common_event_tightBtagSFdn(); }
const float &Common_event_tightBtagSFHFup() { return vvv.Common_event_tightBtagSFHFup(); }
const float &Common_event_tightBtagSFHFdn() { return vvv.Common_event_tightBtagSFHFdn(); }
const float &Common_event_tightBtagSFLFup() { return vvv.Common_event_tightBtagSFLFup(); }
const float &Common_event_tightBtagSFLFdn() { return vvv.Common_event_tightBtagSFLFdn(); }
const float &Common_event_mediumBtagSF() { return vvv.Common_event_mediumBtagSF(); }
const float &Common_event_mediumBtagSFup() { return vvv.Common_event_mediumBtagSFup(); }
const float &Common_event_mediumBtagSFdn() { return vvv.Common_event_mediumBtagSFdn(); }
const float &Common_event_mediumBtagSFHFup() { return vvv.Common_event_mediumBtagSFHFup(); }
const float &Common_event_mediumBtagSFHFdn() { return vvv.Common_event_mediumBtagSFHFdn(); }
const float &Common_event_mediumBtagSFLFup() { return vvv.Common_event_mediumBtagSFLFup(); }
const float &Common_event_mediumBtagSFLFdn() { return vvv.Common_event_mediumBtagSFLFdn(); }
const float &Common_event_looseBtagSF() { return vvv.Common_event_looseBtagSF(); }
const float &Common_event_looseBtagSFup() { return vvv.Common_event_looseBtagSFup(); }
const float &Common_event_looseBtagSFdn() { return vvv.Common_event_looseBtagSFdn(); }
const float &Common_event_looseBtagSFHFup() { return vvv.Common_event_looseBtagSFHFup(); }
const float &Common_event_looseBtagSFHFdn() { return vvv.Common_event_looseBtagSFHFdn(); }
const float &Common_event_looseBtagSFLFup() { return vvv.Common_event_looseBtagSFLFup(); }
const float &Common_event_looseBtagSFLFdn() { return vvv.Common_event_looseBtagSFLFdn(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_lep_p4() { return vvv.Common_lep_p4(); }
const vector<int> &Common_lep_idxs() { return vvv.Common_lep_idxs(); }
const vector<int> &Common_lep_pdgid() { return vvv.Common_lep_pdgid(); }
const vector<int> &Common_lep_tight() { return vvv.Common_lep_tight(); }
const vector<float> &Common_lep_dxy() { return vvv.Common_lep_dxy(); }
const vector<float> &Common_lep_dz() { return vvv.Common_lep_dz(); }
const vector<float> &Common_lep_ip3d() { return vvv.Common_lep_ip3d(); }
const vector<float> &Common_lep_sip3d() { return vvv.Common_lep_sip3d(); }
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
const vector<int> &Common_jet_id() { return vvv.Common_jet_id(); }
const vector<int> &Common_jet_puid() { return vvv.Common_jet_puid(); }
const vector<int> &Common_jet_overlapfatjet() { return vvv.Common_jet_overlapfatjet(); }
const vector<float> &Common_jet_pt_jesup() { return vvv.Common_jet_pt_jesup(); }
const vector<float> &Common_jet_pt_jesdn() { return vvv.Common_jet_pt_jesdn(); }
const vector<float> &Common_jet_pt_jerup() { return vvv.Common_jet_pt_jerup(); }
const vector<float> &Common_jet_pt_jerdn() { return vvv.Common_jet_pt_jerdn(); }
const vector<float> &Common_jet_mass_jesup() { return vvv.Common_jet_mass_jesup(); }
const vector<float> &Common_jet_mass_jesdn() { return vvv.Common_jet_mass_jesdn(); }
const vector<float> &Common_jet_mass_jerup() { return vvv.Common_jet_mass_jerup(); }
const vector<float> &Common_jet_mass_jerdn() { return vvv.Common_jet_mass_jerdn(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &Common_fatjet_p4() { return vvv.Common_fatjet_p4(); }
const vector<int> &Common_fatjet_idxs() { return vvv.Common_fatjet_idxs(); }
const vector<int> &Common_fatjet_id() { return vvv.Common_fatjet_id(); }
const vector<float> &Common_fatjet_msoftdrop() { return vvv.Common_fatjet_msoftdrop(); }
const vector<float> &Common_fatjet_deepMD_W() { return vvv.Common_fatjet_deepMD_W(); }
const vector<float> &Common_fatjet_deep_W() { return vvv.Common_fatjet_deep_W(); }
const vector<float> &Common_fatjet_deepMD_Z() { return vvv.Common_fatjet_deepMD_Z(); }
const vector<float> &Common_fatjet_deep_Z() { return vvv.Common_fatjet_deep_Z(); }
const vector<float> &Common_fatjet_deepMD_T() { return vvv.Common_fatjet_deepMD_T(); }
const vector<float> &Common_fatjet_deep_T() { return vvv.Common_fatjet_deep_T(); }
const vector<float> &Common_fatjet_deepMD_bb() { return vvv.Common_fatjet_deepMD_bb(); }
const vector<float> &Common_fatjet_particleNetMD_W() { return vvv.Common_fatjet_particleNetMD_W(); }
const vector<float> &Common_fatjet_particleNetMD_Xqq() { return vvv.Common_fatjet_particleNetMD_Xqq(); }
const vector<float> &Common_fatjet_particleNetMD_Xcc() { return vvv.Common_fatjet_particleNetMD_Xcc(); }
const vector<float> &Common_fatjet_particleNetMD_Xbb() { return vvv.Common_fatjet_particleNetMD_Xbb(); }
const vector<float> &Common_fatjet_particleNetMD_QCD() { return vvv.Common_fatjet_particleNetMD_QCD(); }
const vector<float> &Common_fatjet_particleNet_QCD() { return vvv.Common_fatjet_particleNet_QCD(); }
const vector<float> &Common_fatjet_particleNet_W() { return vvv.Common_fatjet_particleNet_W(); }
const vector<float> &Common_fatjet_particleNet_Z() { return vvv.Common_fatjet_particleNet_Z(); }
const vector<float> &Common_fatjet_particleNet_T() { return vvv.Common_fatjet_particleNet_T(); }
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
const vector<int> &Common_fatjet_WP_MD() { return vvv.Common_fatjet_WP_MD(); }
const vector<int> &Common_fatjet_WP_antimasscut() { return vvv.Common_fatjet_WP_antimasscut(); }
const vector<int> &Common_fatjet_WP_MD_antimasscut() { return vvv.Common_fatjet_WP_MD_antimasscut(); }
const vector<float> &Common_fatjet_SFVLoose() { return vvv.Common_fatjet_SFVLoose(); }
const vector<float> &Common_fatjet_SFLoose() { return vvv.Common_fatjet_SFLoose(); }
const vector<float> &Common_fatjet_SFMedium() { return vvv.Common_fatjet_SFMedium(); }
const vector<float> &Common_fatjet_SFTight() { return vvv.Common_fatjet_SFTight(); }
const vector<float> &Common_fatjet_SFdnLoose() { return vvv.Common_fatjet_SFdnLoose(); }
const vector<float> &Common_fatjet_SFdnVLoose() { return vvv.Common_fatjet_SFdnVLoose(); }
const vector<float> &Common_fatjet_SFdnMedium() { return vvv.Common_fatjet_SFdnMedium(); }
const vector<float> &Common_fatjet_SFdnTight() { return vvv.Common_fatjet_SFdnTight(); }
const vector<float> &Common_fatjet_SFupVLoose() { return vvv.Common_fatjet_SFupVLoose(); }
const vector<float> &Common_fatjet_SFupLoose() { return vvv.Common_fatjet_SFupLoose(); }
const vector<float> &Common_fatjet_SFupMedium() { return vvv.Common_fatjet_SFupMedium(); }
const vector<float> &Common_fatjet_SFupTight() { return vvv.Common_fatjet_SFupTight(); }
const vector<float> &Common_fatjet_MD_SFLoose() { return vvv.Common_fatjet_MD_SFLoose(); }
const vector<float> &Common_fatjet_MD_SFMedium() { return vvv.Common_fatjet_MD_SFMedium(); }
const vector<float> &Common_fatjet_MD_SFTight() { return vvv.Common_fatjet_MD_SFTight(); }
const vector<float> &Common_fatjet_MD_SFdnLoose() { return vvv.Common_fatjet_MD_SFdnLoose(); }
const vector<float> &Common_fatjet_MD_SFdnMedium() { return vvv.Common_fatjet_MD_SFdnMedium(); }
const vector<float> &Common_fatjet_MD_SFdnTight() { return vvv.Common_fatjet_MD_SFdnTight(); }
const vector<float> &Common_fatjet_MD_SFupLoose() { return vvv.Common_fatjet_MD_SFupLoose(); }
const vector<float> &Common_fatjet_MD_SFupMedium() { return vvv.Common_fatjet_MD_SFupMedium(); }
const vector<float> &Common_fatjet_MD_SFupTight() { return vvv.Common_fatjet_MD_SFupTight(); }
const vector<float> &Common_fatjet_pt_jesup() { return vvv.Common_fatjet_pt_jesup(); }
const vector<float> &Common_fatjet_pt_jesdn() { return vvv.Common_fatjet_pt_jesdn(); }
const vector<float> &Common_fatjet_pt_jerup() { return vvv.Common_fatjet_pt_jerup(); }
const vector<float> &Common_fatjet_pt_jerdn() { return vvv.Common_fatjet_pt_jerdn(); }
const vector<float> &Common_fatjet_msoftdrop_jesup() { return vvv.Common_fatjet_msoftdrop_jesup(); }
const vector<float> &Common_fatjet_msoftdrop_jesdn() { return vvv.Common_fatjet_msoftdrop_jesdn(); }
const vector<float> &Common_fatjet_msoftdrop_jerup() { return vvv.Common_fatjet_msoftdrop_jerup(); }
const vector<float> &Common_fatjet_msoftdrop_jerdn() { return vvv.Common_fatjet_msoftdrop_jerdn(); }
const vector<float> &Common_fatjet_msoftdrop_jmsup() { return vvv.Common_fatjet_msoftdrop_jmsup(); }
const vector<float> &Common_fatjet_msoftdrop_jmsdn() { return vvv.Common_fatjet_msoftdrop_jmsdn(); }
const vector<float> &Common_fatjet_msoftdrop_jmrup() { return vvv.Common_fatjet_msoftdrop_jmrup(); }
const vector<float> &Common_fatjet_msoftdrop_jmrdn() { return vvv.Common_fatjet_msoftdrop_jmrdn(); }
const vector<float> &Common_fatjet_mass_jesup() { return vvv.Common_fatjet_mass_jesup(); }
const vector<float> &Common_fatjet_mass_jesdn() { return vvv.Common_fatjet_mass_jesdn(); }
const vector<float> &Common_fatjet_mass_jerup() { return vvv.Common_fatjet_mass_jerup(); }
const vector<float> &Common_fatjet_mass_jerdn() { return vvv.Common_fatjet_mass_jerdn(); }
const vector<float> &Common_fatjet_mass_jmsup() { return vvv.Common_fatjet_mass_jmsup(); }
const vector<float> &Common_fatjet_mass_jmsdn() { return vvv.Common_fatjet_mass_jmsdn(); }
const vector<float> &Common_fatjet_mass_jmrup() { return vvv.Common_fatjet_mass_jmrup(); }
const vector<float> &Common_fatjet_mass_jmrdn() { return vvv.Common_fatjet_mass_jmrdn(); }
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
const float &Common_eventweight_fatjet_MD_SFLoose() { return vvv.Common_eventweight_fatjet_MD_SFLoose(); }
const float &Common_eventweight_fatjet_MD_SFMedium() { return vvv.Common_eventweight_fatjet_MD_SFMedium(); }
const float &Common_eventweight_fatjet_MD_SFTight() { return vvv.Common_eventweight_fatjet_MD_SFTight(); }
const float &Common_eventweight_fatjet_MD_SFdnLoose() { return vvv.Common_eventweight_fatjet_MD_SFdnLoose(); }
const float &Common_eventweight_fatjet_MD_SFdnMedium() { return vvv.Common_eventweight_fatjet_MD_SFdnMedium(); }
const float &Common_eventweight_fatjet_MD_SFdnTight() { return vvv.Common_eventweight_fatjet_MD_SFdnTight(); }
const float &Common_eventweight_fatjet_MD_SFupLoose() { return vvv.Common_eventweight_fatjet_MD_SFupLoose(); }
const float &Common_eventweight_fatjet_MD_SFupMedium() { return vvv.Common_eventweight_fatjet_MD_SFupMedium(); }
const float &Common_eventweight_fatjet_MD_SFupTight() { return vvv.Common_eventweight_fatjet_MD_SFupTight(); }
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
const bool &Common_isSignal() { return vvv.Common_isSignal(); }
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
const int &Common_gen_VH_channel() { return vvv.Common_gen_VH_channel(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &allHad_jets_p4() { return vvv.allHad_jets_p4(); }
const vector<ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > > &allHad_fatjets_mSD_p4() { return vvv.allHad_fatjets_mSD_p4(); }
const vector<int> &allHad_fatjets_WP_MD() { return vvv.allHad_fatjets_WP_MD(); }
const vector<int> &allHad_fatjets_commonFJIdxs() { return vvv.allHad_fatjets_commonFJIdxs(); }
const int &allHad_nFJ() { return vvv.allHad_nFJ(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &allHad_FJ0_mSD_p4() { return vvv.allHad_FJ0_mSD_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &allHad_FJ1_mSD_p4() { return vvv.allHad_FJ1_mSD_p4(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &allHad_FJ2_mSD_p4() { return vvv.allHad_FJ2_mSD_p4(); }
const int &allHad_FJ0_WP_MD() { return vvv.allHad_FJ0_WP_MD(); }
const int &allHad_FJ1_WP_MD() { return vvv.allHad_FJ1_WP_MD(); }
const int &allHad_FJ2_WP_MD() { return vvv.allHad_FJ2_WP_MD(); }
const float &allHad_FJ0_WMD() { return vvv.allHad_FJ0_WMD(); }
const float &allHad_FJ1_WMD() { return vvv.allHad_FJ1_WMD(); }
const float &allHad_FJ2_WMD() { return vvv.allHad_FJ2_WMD(); }
const float &allHad_FJ0_VMD() { return vvv.allHad_FJ0_VMD(); }
const float &allHad_FJ1_VMD() { return vvv.allHad_FJ1_VMD(); }
const float &allHad_FJ2_VMD() { return vvv.allHad_FJ2_VMD(); }
const float &allHad_FJ0_Xqq() { return vvv.allHad_FJ0_Xqq(); }
const float &allHad_FJ1_Xqq() { return vvv.allHad_FJ1_Xqq(); }
const float &allHad_FJ2_Xqq() { return vvv.allHad_FJ2_Xqq(); }
const float &allHad_FJ0_Xcc() { return vvv.allHad_FJ0_Xcc(); }
const float &allHad_FJ1_Xcc() { return vvv.allHad_FJ1_Xcc(); }
const float &allHad_FJ2_Xcc() { return vvv.allHad_FJ2_Xcc(); }
const float &allHad_FJ0_Xbb() { return vvv.allHad_FJ0_Xbb(); }
const float &allHad_FJ1_Xbb() { return vvv.allHad_FJ1_Xbb(); }
const float &allHad_FJ2_Xbb() { return vvv.allHad_FJ2_Xbb(); }
const float &allHad_FJ0_QCD() { return vvv.allHad_FJ0_QCD(); }
const float &allHad_FJ1_QCD() { return vvv.allHad_FJ1_QCD(); }
const float &allHad_FJ2_QCD() { return vvv.allHad_FJ2_QCD(); }
const int &allHad_FJ0_commonFJIdxs() { return vvv.allHad_FJ0_commonFJIdxs(); }
const int &allHad_FJ1_commonFJIdxs() { return vvv.allHad_FJ1_commonFJIdxs(); }
const int &allHad_FJ2_commonFJIdxs() { return vvv.allHad_FJ2_commonFJIdxs(); }
const ROOT::Math::LorentzVector<ROOT::Math::PtEtaPhiM4D<float> > &allHad_VVV_mSD_p4() { return vvv.allHad_VVV_mSD_p4(); }
const float &allHad_mVVV() { return vvv.allHad_mVVV(); }
const float &allHad_ptVVV() { return vvv.allHad_ptVVV(); }
const float &allHad_HT() { return vvv.allHad_HT(); }
const float &allHad_HT_FJ() { return vvv.allHad_HT_FJ(); }
const float &allHad_FJ01_dPhi() { return vvv.allHad_FJ01_dPhi(); }
const float &allHad_FJ01_dEta() { return vvv.allHad_FJ01_dEta(); }
const float &allHad_FJ01_dR() { return vvv.allHad_FJ01_dR(); }
const float &allHad_FJ01_dPtFrac() { return vvv.allHad_FJ01_dPtFrac(); }
const float &allHad_FJ01_pPRel() { return vvv.allHad_FJ01_pPRel(); }
const float &allHad_FJ02_dPhi() { return vvv.allHad_FJ02_dPhi(); }
const float &allHad_FJ02_dEta() { return vvv.allHad_FJ02_dEta(); }
const float &allHad_FJ02_dR() { return vvv.allHad_FJ02_dR(); }
const float &allHad_FJ02_dPtFrac() { return vvv.allHad_FJ02_dPtFrac(); }
const float &allHad_FJ02_pPRel() { return vvv.allHad_FJ02_pPRel(); }
const float &allHad_FJ12_dPhi() { return vvv.allHad_FJ12_dPhi(); }
const float &allHad_FJ12_dEta() { return vvv.allHad_FJ12_dEta(); }
const float &allHad_FJ12_dR() { return vvv.allHad_FJ12_dR(); }
const float &allHad_FJ12_dPtFrac() { return vvv.allHad_FJ12_dPtFrac(); }
const float &allHad_FJ12_pPRel() { return vvv.allHad_FJ12_pPRel(); }

}

#include "rooutil.cc"