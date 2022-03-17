#include "Begin_1Lep2fatjet.h"


void Begin_1Lep2fatjet()
{
    //==============================================
    // Begin_1Lep2fatjet:
    // This function gets called prior to the event looping.
    // This is where one declares variables, histograms, event selections for the category 1Lep2fatjet.
    //==============================================


    // Create variables used in this category.
    // Please follow the convention of <category>_<varname> structure.


    // ana.tx.createBranch<>("");



    // Lepton
    ana.tx.createBranch<float>("Lep1fatJet2_LeptonPt" );
    ana.tx.createBranch<float>("Lep1fatJet2_LeptonEta" );
    ana.tx.createBranch<float>("Lep1fatJet2_LeptonPhi" );
    ana.tx.createBranch<float>("Lep1fatJet2_LeptonE" );
    ana.tx.createBranch<int>("Lep1fatJet2_LeptonPDGID" );
    ana.tx.createBranch<float>("Lep1fatJet2_Muon_pfRelIso04_all" );

    // MET
    ana.tx.createBranch<float>("Lep1fatJet2_MET_pt" );
    ana.tx.createBranch<float>("Lep1fatJet2_MET_phi" );
    ana.tx.createBranch<float>("Common_MET_pt_JER" );
    ana.tx.createBranch<float>("Common_MET_phi_JER" );

    // neutrino
    ana.tx.createBranch<float>("Lep1fatJet2_NeutrinoPt" );
    ana.tx.createBranch<float>("Lep1fatJet2_NeutrinoEta" );
    ana.tx.createBranch<float>("Lep1fatJet2_Neutrinophi" );
    ana.tx.createBranch<float>("Lep1fatJet2_NeutrinoE" );

    // Leptonic W
    ana.tx.createBranch<float>("Lep1fatJet2_LeptonicWPt" );
    ana.tx.createBranch<float>("Lep1fatJet2_LeptonicWEta" );
    ana.tx.createBranch<float>("Lep1fatJet2_LeptonicWPhi" );
    ana.tx.createBranch<float>("Lep1fatJet2_LeptonicWM" );
    ana.tx.createBranch<float>("Lep1fatJet2_LeptonicWMt" );

    // Jet
    ana.tx.createBranch<vector<float>>("Lep1fatJet2_Jet_btagDeepB");
    ana.tx.createBranch<vector<float>>("Lep1fatJet2_Jet_btagDeepC");
    ana.tx.createBranch<vector<float>>("Lep1fatJet2_Jet_btagDeepFlavC");
    ana.tx.createBranch<vector<float>>("Lep1fatJet2_Jet_btagDeepFlavB");
    ana.tx.createBranch<vector<float>>("Lep1fatJet2_Jet_qgl");
    ana.tx.createBranch<vector<int>>("Lep1fatJet2_Jet_jetId");
    ana.tx.createBranch<vector<int>>("Lep1fatJet2_Jet_hadronFlavour");
    ana.tx.createBranch<vector<int>>("Lep1fatJet2_Jet_partonFlavour");
    ana.tx.createBranch<vector<float>>("Lep1fatJet2_Jet_pt");
    ana.tx.createBranch<vector<float>>("Lep1fatJet2_Jet_eta");
    ana.tx.createBranch<vector<float>>("Lep1fatJet2_Jet_phi");
    ana.tx.createBranch<vector<float>>("Lep1fatJet2_Jet_e");
   
    // fatJet

    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_pt");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_eta");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_phi");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_msoftdrop");
    ana.tx.createBranch<int>("Lep1fatJet2_FatJet_jetId");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_tau1");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_tau2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_tau3");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_tau4");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_H4qvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_HbbvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_TvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_WvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZHbbvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZHccvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZbbvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_bbvsLight");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ccvsLight");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTag_H");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTag_QCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTag_QCDothers");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTag_TvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTag_WvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTag_ZvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNetMD_QCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNetMD_Xbb");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNetMD_Xcc");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNetMD_Xqq");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_H4qvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_HbbvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_HccvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_QCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_TvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_WvsQCD");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_ZvsQCD");

    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_pt_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_eta_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_phi_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_msoftdrop_2");
    ana.tx.createBranch<int>("Lep1fatJet2_FatJet_jetId_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_tau1_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_tau2_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_tau3_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_tau4_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_H4qvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_HbbvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_TvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_WvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZHbbvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZHccvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZbbvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_bbvsLight_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ccvsLight_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTag_H_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTag_QCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTag_QCDothers_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTag_TvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTag_WvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_deepTag_ZvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNetMD_QCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNetMD_Xbb_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNetMD_Xcc_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNetMD_Xqq_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_H4qvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_HbbvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_HccvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_QCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_TvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_WvsQCD_2");
    ana.tx.createBranch<float>("Lep1fatJet2_FatJet_particleNet_ZvsQCD_2");

    // Gen
    ana.tx.createBranch<vector<float>>          ("Lep1fatJet2_GenPart_eta");
    ana.tx.createBranch<vector<int>>          ("Lep1fatJet2_GenPart_genPartIdxMother");
    ana.tx.createBranch<vector<float>>          ("Lep1fatJet2_GenPart_mass");
    ana.tx.createBranch<vector<int>>          ("Lep1fatJet2_GenPart_pdgId");
    ana.tx.createBranch<vector<float>>          ("Lep1fatJet2_GenPart_phi");
    ana.tx.createBranch<vector<float>>          ("Lep1fatJet2_GenPart_pt");
    ana.tx.createBranch<vector<int>>          ("Lep1fatJet2_GenPart_status");
    ana.tx.createBranch<vector<int>>          ("Lep1fatJet2_GenPart_statusFlags");
    ana.tx.createBranch<int>          ("Lep1fatJet2_nGenPart");


    // weight, HLT
    ana.tx.createBranch<float>("Lep1fatJet2_Pileup_nTrueInt");
    ana.tx.createBranch<float>("Lep1fatJet2_Pileup_nPU");

    ana.tx.createBranch<int>("Lep1fatJet2_HLT_Mu50");
    ana.tx.createBranch<int>("Lep1fatJet2_HLT_IsoMu24");
    ana.tx.createBranch<int>("Lep1fatJet2_HLT_OldMu100");
    ana.tx.createBranch<int>("Lep1fatJet2_HLT_TkMu100");
    ana.tx.createBranch<int>("Lep1fatJet2_HLT_IsoMu27");
    ana.tx.createBranch<int>("Lep1fatJet2_HLT_Ele27_WPTight_Gsf");
    ana.tx.createBranch<int>("Lep1fatJet2_HLT_Ele32_WPTight_Gsf_L1DoubleEG");
    ana.tx.createBranch<int>("Lep1fatJet2_HLT_Ele35_WPTight_Gsf");
    ana.tx.createBranch<int>("Lep1fatJet2_HLT_Photon200");
    ana.tx.createBranch<int>("Lep1fatJet2_HLT_Ele32_WPTight_Gsf");

   
    // Test aQGC sample
    ana.tx.createBranch<float>("Process_1Lep2fatjet_ST");
    ana.tx.createBranch<int>("Process_1Lep2fatjet_Common_LeptonSize");
    ana.tx.createBranch<int>("Process_1Lep2fatjet_Common_jetSize");
    ana.tx.createBranch<int>("Process_1Lep2fatjet_Common_fatJetSize");
    ana.tx.createBranch<vector<float>>("Process_1Lep2fatjet_LHEWeight_Central_scale_variation");
    ana.tx.createBranch<float>                  ("Process_1Lep2fatjet_LHE_Invariant_Mass");
    ana.tx.createBranch<float>                  ("Process_1Lep2fatjet_LHE_HT");

    // ana.res.loadResolutionFile("Summer16_25nsV1_MC_PtResolution_AK4PFchs.txt");
    // ana.res.loadScaleFactorFile("Summer16_25nsV1_MC_SF_AK4PFchs.txt");

    // ana.resfatJet.loadResolutionFile("Summer16_25nsV1_MC_PtResolution_AK8PFPuppi.txt");
    // ana.resfatJet.loadScaleFactorFile("Summer16_25nsV1_MC_SF_AK8PFPuppi.txt");

    
    

    ana.cutflow.getCut("CommonCut");
    
    ana.cutflow.getCut("CommonCut");
    
}
