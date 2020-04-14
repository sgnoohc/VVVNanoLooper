#include "Begin_1Lep4jet.h"

void Begin_1Lep4jet()
{
    //==============================================
    // Begin_1Lep4jet:
    // This function gets called prior to the event looping.
    // This is where one declares variables, histograms, event selections for the category 1Lep4jet.
    //==============================================

    // Create variables used in this category.
    // Please follow the convention of <category>_<varname> structure.
    ana.tx.createBranch<LorentzVector>("1Lep4jet_lep_p4");
    ana.tx.createBranch<int>("1Lep4jet_lep_pdgid");

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");
    // ana.cutflow.addCutToLastActiveCut("Cut_1Lep4jet_GenHT", [&]() { return ana.tx.getBranch<float>("Common_genHT"); }, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_1Lep4jet_Has1Lepton", [&]()
            {
                if (not (ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size() == 1))
                    return false;
                ana.tx.setBranch<LorentzVector>("1Lep4jet_lep_p4", ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]);
                ana.tx.setBranch<int>("1Lep4jet_lep_pdgid", ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]);
                return true;
            }, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_1Lep4jet_Has2FatJet", [&]() { return (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() >= 2);}, UNITY);
    // ana.cutflow.addCutToLastActiveCut("Cut_1Lep4jet_nbVeto", [&]() { return (ana.tx.getBranch<int>("Common_nb_loose") == 0);}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_1Lep4jet_FatJetMassPresel", [&]() { return (nt.FatJet_msoftdrop()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]] > 40.) and (nt.FatJet_msoftdrop()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]] > 40.);}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_1Lep4jet_Preselection", UNITY, UNITY);

    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    RooUtil::Histograms hists_1Lep4jet;
    hists_1Lep4jet.addHistogram("h_1Lep4jet_lep_pt", 180, 0, 500, [&]() { return ana.tx.getBranch<LorentzVector>("1Lep4jet_lep_p4").pt(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_lep_eta", 180, -3, 3, [&]() { return ana.tx.getBranch<LorentzVector>("1Lep4jet_lep_p4").eta(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_mt", 180, 0, 250, [&]() { return RooUtil::Calc::mT(ana.tx.getBranch<LorentzVector>("1Lep4jet_lep_p4"), ana.tx.getBranch<LorentzVector>("Common_met_p4")); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_pt_lv", 180, 0, 1000, [&]() { return (ana.tx.getBranch<LorentzVector>("1Lep4jet_lep_p4") + ana.tx.getBranch<LorentzVector>("Common_met_p4")).pt(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_met_pt", 180, 0, 500, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4").pt(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_met_phi", 180, -3.1416, 3.1416, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4").phi(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_nb_loose", 8, 0, 8, [&]() { return ana.tx.getBranch<int>("Common_nb_loose"); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_nb_medium", 8, 0, 8, [&]() { return ana.tx.getBranch<int>("Common_nb_medium"); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_nb_tight", 8, 0, 8, [&]() { return ana.tx.getBranch<int>("Common_nb_tight"); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_njet", 15, 0, 15, [&]() { return ana.tx.getBranch<vector<int>>("Common_jet_idxs").size(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_nfatjet", 5, 0, 5, [&]() { return ana.tx.getBranch<vector<int>>("Common_fatjet_idxs").size(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_difatjet_mass", 180, 0, 3000, [&]() { return (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[0] + ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[1]).mass(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_difatjet_pt", 180, 0, 1000, [&]() { return (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[0] + ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[1]).pt(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_pt_0", 180, 0, 1000, [&]() { return ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[0].pt(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_pt_1", 180, 0, 750, [&]() { return ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[1].pt(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_msoftdrop_0", 180, 0, 250, [&]() { return nt.FatJet_msoftdrop()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_msoftdrop_1", 180, 0, 250, [&]() { return nt.FatJet_msoftdrop()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]]; } );
    // hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_genjetmass_0", 180, 0, 250, [&]() { return nt.GenJetAK8_mass()[nt.FatJet_genJetAK8Idx()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]]]; } );
    // hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_genjetmass_1", 180, 0, 250, [&]() { return nt.GenJetAK8_mass()[nt.FatJet_genJetAK8Idx()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_MDdeepW_0", 180, -1, 1, [&]() { return nt.FatJet_deepTagMD_WvsQCD()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_MDdeepW_1", 180, -1, 1, [&]() { return nt.FatJet_deepTagMD_WvsQCD()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_deepW_0", 180, -1, 1, [&]() { return nt.FatJet_deepTag_WvsQCD()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_deepW_1", 180, -1, 1, [&]() { return nt.FatJet_deepTag_WvsQCD()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_MDdeepT_0", 180, -1, 1, [&]() { return nt.FatJet_deepTagMD_TvsQCD()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_MDdeepT_1", 180, -1, 1, [&]() { return nt.FatJet_deepTagMD_TvsQCD()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_deepT_0", 180, -1, 1, [&]() { return nt.FatJet_deepTag_TvsQCD()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_deepT_1", 180, -1, 1, [&]() { return nt.FatJet_deepTag_TvsQCD()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_MDdeepbbvsL_0", 180, -1, 1, [&]() { return nt.FatJet_deepTagMD_bbvsLight()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_MDdeepbbvsL_1", 180, -1, 1, [&]() { return nt.FatJet_deepTagMD_bbvsLight()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]]; } );
    // hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_lsf3_0", 180, -1, 1, [&]() { return nt.FatJet_lsf3()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]]; } );
    // hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_lsf3_1", 180, -1, 1, [&]() { return nt.FatJet_lsf3()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]]; } );
    // hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_nBHadrons_0", 5, 0, 5, [&]() { return nt.FatJet_nBHadrons()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]]; } );
    // hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_nBHadrons_1", 5, 0, 5, [&]() { return nt.FatJet_nBHadrons()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]]; } );
    // hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_nCHadrons_0", 5, 0, 5, [&]() { return nt.FatJet_nCHadrons()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]]; } );
    // hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_nCHadrons_1", 5, 0, 5, [&]() { return nt.FatJet_nCHadrons()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_tau_21_0", 180, 0, 1, [&]() { return nt.FatJet_tau2()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]] / nt.FatJet_tau1()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_tau_21_1", 180, 0, 1, [&]() { return nt.FatJet_tau2()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]] / nt.FatJet_tau1()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]]; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_subjet_pt_0_0", 180, -20, 1000, [&]() { if (nt.FatJet_subJetIdx1()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]] >= 0) return nt.Jet_pt()[nt.FatJet_subJetIdx1()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]]]; else return -999.f; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_subjet_pt_1_0", 180, -20, 1000, [&]() { if (nt.FatJet_subJetIdx2()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]] >= 0) return nt.Jet_pt()[nt.FatJet_subJetIdx2()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[0]]]; else return -999.f; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_subjet_pt_0_1", 180, -20, 1000, [&]() { if (nt.FatJet_subJetIdx1()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]] >= 0) return nt.Jet_pt()[nt.FatJet_subJetIdx1()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]]]; else return -999.f; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_fatjet_subjet_pt_1_1", 180, -20, 1000, [&]() { if (nt.FatJet_subJetIdx2()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]] >= 0) return nt.Jet_pt()[nt.FatJet_subJetIdx2()[ana.tx.getBranch<vector<int>>("Common_fatjet_idxs")[1]]]; else return -999.f; } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_htSum", 180, 0, 4000, [&]() { return ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[0].pt() + ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[1].pt() + ana.tx.getBranch<LorentzVector>("1Lep4jet_lep_p4").pt() + ana.tx.getBranch<LorentzVector>("Common_met_p4").pt(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_mass_lvJJ", 180, 0, 4000, [&]() { return (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[0] + ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[1] + ana.tx.getBranch<LorentzVector>("1Lep4jet_lep_p4") + ana.tx.getBranch<LorentzVector>("Common_met_p4")).mass(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_mt_lvJJ", 180, 0, 4000, [&]() { return (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[0] + ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[1] + ana.tx.getBranch<LorentzVector>("1Lep4jet_lep_p4") + ana.tx.getBranch<LorentzVector>("Common_met_p4")).mt(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_mass_lvJ_0", 180, 0, 2000, [&]() { return (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[0] + ana.tx.getBranch<LorentzVector>("1Lep4jet_lep_p4") + ana.tx.getBranch<LorentzVector>("Common_met_p4")).mass(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_mass_lvJ_1", 180, 0, 2000, [&]() { return (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[1] + ana.tx.getBranch<LorentzVector>("1Lep4jet_lep_p4") + ana.tx.getBranch<LorentzVector>("Common_met_p4")).mass(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_mt_lvJ_0", 180, 0, 2000, [&]() { return (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[0] + ana.tx.getBranch<LorentzVector>("1Lep4jet_lep_p4") + ana.tx.getBranch<LorentzVector>("Common_met_p4")).mt(); } );
    hists_1Lep4jet.addHistogram("h_1Lep4jet_mt_lvJ_1", 180, 0, 2000, [&]() { return (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[1] + ana.tx.getBranch<LorentzVector>("1Lep4jet_lep_p4") + ana.tx.getBranch<LorentzVector>("Common_met_p4")).mt(); } );

    // Now book cutflow histogram (could be commented out if user does not want.)
    // N.B. Cutflow histogramming can be CPU consuming.
    ana.cutflow.bookCutflows();

    // Book histograms to cuts that user wants for this category.
    ana.cutflow.bookHistogramsForCut(hists_1Lep4jet, "Cut_1Lep4jet_Has2FatJet");
    ana.cutflow.bookHistogramsForCut(hists_1Lep4jet, "Cut_1Lep4jet_Preselection");
}
