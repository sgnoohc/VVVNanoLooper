#include "Begin_4LepMET.h"
#include "lester_mt2_bisect.h"
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iostream>

namespace fourlep{
    std::map<TString, float> scale1fbs;
}

void Begin_4LepMET()
{
    // Category flag
    Begin_4LepMET_Create_Branches();

    // Parse cross section
    Begin_4LepMET_Parse_Scale1fbs();

    // The framework may run over NanoAOD directly or, it may run over VVVTree.
    // ana.run_VVVTree boolean determines this.
    if (ana.run_VVVTree)
    {
        Begin_4LepMET_VVVTree();
    }
    else
    {
        Begin_4LepMET_NanoAOD();
    }

    // Add different channels
    ana.cutflow.getCut("Cut_4LepMET_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_emuChannel", [&]() { bool pass = (ana.tx.getBranch<int>("Var_4LepMET_other_lep_pdgid_0") * ana.tx.getBranch<int>("Var_4LepMET_other_lep_pdgid_1") == -143); ana.tx.setBranch<bool>("Cut_4LepMET_emuChannel", pass); return pass; }, UNITY);
    ana.cutflow.getCut("Cut_4LepMET_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_offzChannel", [&]() { bool pass = (ana.tx.getBranch<int>("Var_4LepMET_other_lep_pdgid_0") == -ana.tx.getBranch<int>("Var_4LepMET_other_lep_pdgid_1")) and (abs(ana.tx.getBranch<float>("Var_4LepMET_other_mll") - 91.1876) >= 10.); ana.tx.setBranch<bool>("Cut_4LepMET_offzChannel", pass); return pass; }, UNITY);
    ana.cutflow.getCut("Cut_4LepMET_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_onzChannel", [&]() { bool pass = (ana.tx.getBranch<int>("Var_4LepMET_other_lep_pdgid_0") == -ana.tx.getBranch<int>("Var_4LepMET_other_lep_pdgid_1")) and (abs(ana.tx.getBranch<float>("Var_4LepMET_other_mll") - 91.1876) < 10.); ana.tx.setBranch<bool>("Cut_4LepMET_onzChannel", pass); return pass; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_onzChannel_HighMET", [&]() { bool pass = ana.tx.getBranch<LorentzVector>("Common_met_p4").pt() > 120; ana.tx.setBranch<bool>("Cut_4LepMET_onzChannel_HighMET", pass); return pass; }, UNITY);

    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    ana.histograms.addHistogram("h_4LepMET_Zcand_pt_0", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_0").pt(); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_pt_1", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_1").pt(); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_sip3d_0", 180, 0, 10, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_sip3d")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_0")]); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_sip3d_1", 180, 0, 10, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_sip3d")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_1")]); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_sip3d_max", 180, 0, 10, [&]() { return std::max(fabs(ana.tx.getBranch<vector<float>>("Common_lep_sip3d")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_0")]), fabs(ana.tx.getBranch<vector<float>>("Common_lep_sip3d")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_1")])); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_ip3d_0", 180, 0, 0.02, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_ip3d")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_0")]); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_ip3d_1", 180, 0, 0.02, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_ip3d")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_1")]); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_ip3d_max", 180, 0, 0.02, [&]() { return std::max(fabs(ana.tx.getBranch<vector<float>>("Common_lep_ip3d")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_0")]), fabs(ana.tx.getBranch<vector<float>>("Common_lep_ip3d")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_1")])); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_dxy_max", 180, 0, 0.02, [&]() { return std::max(fabs(ana.tx.getBranch<vector<float>>("Common_lep_dxy")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_0")]), fabs(ana.tx.getBranch<vector<float>>("Common_lep_dxy")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_1")])); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_dz_max", 180, 0, 0.05, [&]() { return std::max(fabs(ana.tx.getBranch<vector<float>>("Common_lep_dz")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_0")]), fabs(ana.tx.getBranch<vector<float>>("Common_lep_dz")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_1")])); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_mll", 180, 0, 150, [&]() { return ana.tx.getBranch<float>("Var_4LepMET_Zcand_mll"); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_dphi", 180, 0, 3.1416, [&]() { return fabs(RooUtil::Calc::DeltaPhi(ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_0"), ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_1"))); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_pt", 180, 0, 150, [&]() { return (ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_0") + ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_1")).pt(); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_mll_wide", 180, 0, 350, [&]() { return ana.tx.getBranch<float>("Var_4LepMET_Zcand_mll"); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_mll_zoom", 180, 70, 110, [&]() { return ana.tx.getBranch<float>("Var_4LepMET_Zcand_mll"); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_leptight", 4, 0, 4, [&]() { return 2 * ana.tx.getBranch<vector<int>>("Common_lep_tight")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_0")] + ana.tx.getBranch<vector<int>>("Common_lep_tight")[ana.tx.getBranch<int>("Var_4LepMET_Zcand_lep_idx_1")]; } );
    ana.histograms.addHistogram("h_4LepMET_other_pt_0", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0").pt(); } );
    ana.histograms.addHistogram("h_4LepMET_other_pt_1", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1").pt(); } );
    ana.histograms.addHistogram("h_4LepMET_other_sip3d_0", 180, 0, 10, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_sip3d")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_0")]); } );
    ana.histograms.addHistogram("h_4LepMET_other_sip3d_1", 180, 0, 10, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_sip3d")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_1")]); } );
    ana.histograms.addHistogram("h_4LepMET_other_sip3d_max", 180, 0, 10, [&]() { return std::max(fabs(ana.tx.getBranch<vector<float>>("Common_lep_sip3d")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_0")]), fabs(ana.tx.getBranch<vector<float>>("Common_lep_sip3d")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_1")])); } );
    ana.histograms.addHistogram("h_4LepMET_other_ip3d_0", 180, 0, 0.02, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_ip3d")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_0")]); } );
    ana.histograms.addHistogram("h_4LepMET_other_ip3d_1", 180, 0, 0.02, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_ip3d")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_1")]); } );
    ana.histograms.addHistogram("h_4LepMET_other_ip3d_max", 180, 0, 0.02, [&]() { return std::max(fabs(ana.tx.getBranch<vector<float>>("Common_lep_ip3d")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_0")]), fabs(ana.tx.getBranch<vector<float>>("Common_lep_ip3d")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_1")])); } );
    ana.histograms.addHistogram("h_4LepMET_other_dxy_max", 180, 0, 0.02, [&]() { return std::max(fabs(ana.tx.getBranch<vector<float>>("Common_lep_dxy")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_0")]), fabs(ana.tx.getBranch<vector<float>>("Common_lep_dxy")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_1")])); } );
    ana.histograms.addHistogram("h_4LepMET_other_dz_max", 180, 0, 0.05, [&]() { return std::max(fabs(ana.tx.getBranch<vector<float>>("Common_lep_dz")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_0")]), fabs(ana.tx.getBranch<vector<float>>("Common_lep_dz")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_1")])); } );
    ana.histograms.addHistogram("h_4LepMET_other_mll", 180, 0, 150, [&]() { return ana.tx.getBranch<float>("Var_4LepMET_other_mll"); } );
    ana.histograms.addHistogram("h_4LepMET_other_dphi", 180, 0, 3.1416, [&]() { return fabs(RooUtil::Calc::DeltaPhi(ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0"), ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1"))); } );
    ana.histograms.addHistogram("h_4LepMET_other_pt", 180, 0, 150, [&]() { return (ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0") + ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1")).pt(); } );
    ana.histograms.addHistogram("h_4LepMET_other_mll_wide", 180, 0, 350, [&]() { return ana.tx.getBranch<float>("Var_4LepMET_other_mll"); } );
    ana.histograms.addHistogram("h_4LepMET_other_mll_zoom", 180, 70, 110, [&]() { return ana.tx.getBranch<float>("Var_4LepMET_other_mll"); } );
    ana.histograms.addHistogram("h_4LepMET_other_leptight", 4, 0, 4, [&]() { return 2 * ana.tx.getBranch<vector<int>>("Common_lep_tight")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_0")] + ana.tx.getBranch<vector<int>>("Common_lep_tight")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_1")]; } );
    ana.histograms.addHistogram("h_4LepMET_Z0W0_mll", 180, 0, 150, [&]() { return (ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_0") + ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0")).mass(); } );
    ana.histograms.addHistogram("h_4LepMET_Z0W0_dphi", 180, 0, 3.1416, [&]() { return fabs(RooUtil::Calc::DeltaPhi(ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_0"), ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0"))); } );
    ana.histograms.addHistogram("h_4LepMET_Z0W0_pt", 180, 0, 150, [&]() { return (ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_0") + ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0")).pt(); } );
    ana.histograms.addHistogram("h_4LepMET_Z0W1_mll", 180, 0, 150, [&]() { return (ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_0") + ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1")).mass(); } );
    ana.histograms.addHistogram("h_4LepMET_Z0W1_dphi", 180, 0, 3.1416, [&]() { return fabs(RooUtil::Calc::DeltaPhi(ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_0"), ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1"))); } );
    ana.histograms.addHistogram("h_4LepMET_Z0W1_pt", 180, 0, 150, [&]() { return (ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_0") + ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1")).pt(); } );
    ana.histograms.addHistogram("h_4LepMET_Z1W0_mll", 180, 0, 150, [&]() { return (ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_1") + ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0")).mass(); } );
    ana.histograms.addHistogram("h_4LepMET_Z1W0_dphi", 180, 0, 3.1416, [&]() { return fabs(RooUtil::Calc::DeltaPhi(ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_1"), ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0"))); } );
    ana.histograms.addHistogram("h_4LepMET_Z1W0_pt", 180, 0, 150, [&]() { return (ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_1") + ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0")).pt(); } );
    ana.histograms.addHistogram("h_4LepMET_Z1W1_mll", 180, 0, 150, [&]() { return (ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_1") + ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1")).mass(); } );
    ana.histograms.addHistogram("h_4LepMET_Z1W1_dphi", 180, 0, 3.1416, [&]() { return fabs(RooUtil::Calc::DeltaPhi(ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_1"), ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1"))); } );
    ana.histograms.addHistogram("h_4LepMET_Z1W1_pt", 180, 0, 150, [&]() { return (ana.tx.getBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_1") + ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1")).pt(); } );
    ana.histograms.addHistogram("h_4LepMET_met", 180, 0, 450, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4").pt(); } );
    ana.histograms.addHistogram("h_4LepMET_met_phi", 180, -3.1416, 3.1416, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4").phi(); } );
    ana.histograms.addHistogram("h_4LepMET_nb_loose", 8, 0, 8, [&]() { return ana.tx.getBranch<int>("Common_nb_loose"); } );
    ana.histograms.addHistogram("h_4LepMET_nb_medium", 8, 0, 8, [&]() { return ana.tx.getBranch<int>("Common_nb_medium"); } );
    ana.histograms.addHistogram("h_4LepMET_nb_tight", 8, 0, 8, [&]() { return ana.tx.getBranch<int>("Common_nb_tight"); } );
    ana.histograms.addHistogram("h_4LepMET_njet", 8, 0, 8, [&]() { return ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4").size(); } );
    ana.histograms.addHistogram("h_4LepMET_nfatjet", 8, 0, 8, [&]() { return ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size(); } );
    ana.histograms.addHistogram("h_4LepMET_mt2", 180, 0, 100, [&]() { return ana.tx.getBranch<float>("Var_4LepMET_mt2"); } );

    // Now book cutflow histogram (could be commented out if user does not want.)
    // N.B. Cutflow histogramming can be CPU consuming.
    // ana.cutflow.bookCutflows();

    // Book histograms to cuts that user wants for this category.
    // ana.cutflow.bookHistogramsForCutAndBelow(ana.histograms, "Cut_4LepMET_Preselection");

}

void Begin_4LepMET_NanoAOD()
{
    //==============================================
    // Begin_4LepMET:
    // This function gets called prior to the event looping.
    // This is where one declares variables, histograms, event selections for the category 4LepMET.
    //==============================================

    // Create variables used in this category.
    // Please follow the convention of <category>_<varname> structure.

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");

    // // If LHEReweightingWeight size == 0 then skip the event
    // ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_EFTBadEventVeto",
    //         [&]()
    //         {
    //             if (ana.is_EFT_sample)
    //             {
    //                 if (nt.nLHEReweightingWeight() != 0)
    //                     return false;
    //             }
    //             return true;
    //         }, UNITY);

    // Select 4 leptons
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_Has4Lepton",
            [&]()
            {
                // Needs to be 4 leptons
                if (not (ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size() == 4))
                    return false;
                return true;
            }, UNITY);

    // Select Z candidate
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_HasZCandidate",
            [&]()
            {

                auto [ has_sfos, idx1, idx2, mll ] = RooUtil::Calc::pickZcandidateIdxs(
                        ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid"),
                        ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4"));
                if (not (has_sfos)) return false;
                if (not (abs(mll - 91.1876) < 10.)) return false;

                // If found a Z then set the variables
                ana.tx.setBranch<int>          ("Var_4LepMET_Zcand_lep_idx_0"   , ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[idx1]);
                ana.tx.setBranch<int>          ("Var_4LepMET_Zcand_lep_pdgid_0" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[idx1]);
                ana.tx.setBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_0"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[idx1]);
                ana.tx.setBranch<int>          ("Var_4LepMET_Zcand_lep_idx_1"   , ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[idx2]);
                ana.tx.setBranch<int>          ("Var_4LepMET_Zcand_lep_pdgid_1" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[idx2]);
                ana.tx.setBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_1"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[idx2]);

                ana.tx.setBranch<float>("Var_4LepMET_Zcand_mll", mll);

                // The leading one has to pass 25 GeV
                if (not (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[idx1].pt() > 25.)) return false;

                return true;
            }, UNITY);

    // Apply lepton selection on the two extra leptons
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_OtherLeptons",
            [&]()
            {
                // The other two lepton indices
                vector<int> other_lep_idxs;
                vector<int> other_lep_pdgids;
                vector<LorentzVector> other_lep_p4s;

                // Loop over the indices and pdgid and if it is Z candidnate lepton then skip
                for (unsigned int ilep = 0; ilep < ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size(); ++ilep)
                {
                    int idx = ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[ilep];
                    int pdgid = ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[ilep];
                    if (idx == ana.tx.getBranchLazy<int>("Var_4LepMET_Zcand_lep_idx_0") and pdgid == ana.tx.getBranchLazy<int>("Var_4LepMET_Zcand_lep_pdgid_0")) continue;
                    if (idx == ana.tx.getBranchLazy<int>("Var_4LepMET_Zcand_lep_idx_1") and pdgid == ana.tx.getBranchLazy<int>("Var_4LepMET_Zcand_lep_pdgid_1")) continue;
                    other_lep_idxs  .push_back(ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[ilep]);
                    other_lep_pdgids.push_back(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[ilep]);
                    other_lep_p4s   .push_back(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[ilep]);
                }

                // Sanity check that it must be 2 leptons
                if (other_lep_idxs.size() != 2)
                    RooUtil::error("It should have been 4 leptons! how come you have != 2 other leptons here after accounting for the Z leptons??", __FILE__);

                // set the idxs
                ana.tx.setBranch<int>          ("Var_4LepMET_other_lep_idx_0"   , other_lep_idxs[0]);
                ana.tx.setBranch<int>          ("Var_4LepMET_other_lep_pdgid_0" , other_lep_pdgids[0]);
                ana.tx.setBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0"    , other_lep_p4s[0]);
                ana.tx.setBranch<int>          ("Var_4LepMET_other_lep_idx_1"   , other_lep_idxs[1]);
                ana.tx.setBranch<int>          ("Var_4LepMET_other_lep_pdgid_1" , other_lep_pdgids[1]);
                ana.tx.setBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1"    , other_lep_p4s[1]);

                ana.tx.setBranch<float>("Var_4LepMET_other_mll", (other_lep_p4s[0] + other_lep_p4s[1]).mass());

                // The leading one has to pass 25 GeV
                if (not (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[other_lep_idxs[0]].pt() > 25.)) return false;

                return true;
            }, UNITY);

    // Apply min Mll > 12 GeV selection on any opposite sign pair
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_VetoLowMassResonance",
            [&]()
            {

                // Loop over every pair of opposite sign charged lepton pairs and require that they have > 12 GeV mass
                for (unsigned int ilep = 0; ilep < ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size(); ++ilep)
                {
                    const LorentzVector& ip4 = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[ilep];
                    const int& ipdgid = ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[ilep];
                    for (unsigned int jlep = ilep + 1; jlep < ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size(); ++jlep)
                    {
                        const LorentzVector& jp4 = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[jlep];
                        const int& jpdgid = ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[jlep];

                        if (ipdgid * jpdgid < 0) // if opposite charge pair
                        {
                            if (not ((ip4 + jp4).mass() > 12))
                                return false;
                        }
                    }
                }

                // If made to this point than it passed
                return true;

            }, UNITY);

    // Apply b-tag veto
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_bVeto",
            [&]()
            {
                // for (unsigned int ijet = 0; ijet < ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size(); ++ijet)
                // {
                //     int jet_idx_nano = ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[ijet];
                //     float jet_deepflavb_score = nt.Jet_btagDeepFlavB()[jet_idx_nano];
                // }
                return true;
            },
            [&]() { return 1./* TODO: Implement b-tagging scalefactors */; });

    // Compute MT2 variable
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_Compute_Variables",
            [&]()
            {
                ana.tx.setBranch<float>("Var_4LepMET_mt2", Begin_4LepMET_MT2());
                return true;
            },
            UNITY);

    // Compute weight
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_Compute_Scale1fbs",
            [&]()
            {
                if (not ana.tx.getBranch<int>("Common_isData"))
                {
                    TString key = gSystem->DirName(ana.looper.getCurrentFileName());
                    ana.tx.setBranch<float>("Var_4LepMET_scale1fb", fourlep::scale1fbs.at(key));
                }
                else
                {
                    ana.tx.setBranch<float>("Var_4LepMET_scale1fb", 1);
                }
                return true;
            },
            UNITY);

    // Create a middle point of preselection
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_Preselection", [&]() { ana.tx.setBranch<bool>("Cut_4LepMET_Preselection", true); return true; }, UNITY); // This "cut" does not do anything. It works as a middle point

}

void Begin_4LepMET_Create_Branches()
{
    ana.tx.createBranch<bool>         ("Cut_4LepMET_Preselection");
    ana.tx.createBranch<bool>         ("Cut_4LepMET_emuChannel");
    ana.tx.createBranch<bool>         ("Cut_4LepMET_offzChannel");
    ana.tx.createBranch<bool>         ("Cut_4LepMET_onzChannel");
    ana.tx.createBranch<bool>         ("Cut_4LepMET_onzChannel_HighMET");

    // Z candidate idxs, pdgid, and 4 vectors
    // The Z candidate is the SFOS pair that is closest to the Z mass
    ana.tx.createBranch<int>          ("Var_4LepMET_Zcand_lep_idx_0");    // idxs to the NanoAOD
    ana.tx.createBranch<int>          ("Var_4LepMET_Zcand_lep_pdgid_0");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.createBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_0");     // p4 of the lepton
    ana.tx.createBranch<int>          ("Var_4LepMET_Zcand_lep_idx_1");    // idxs to the NanoAOD
    ana.tx.createBranch<int>          ("Var_4LepMET_Zcand_lep_pdgid_1");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.createBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_1");     // p4 of the lepton
    ana.tx.createBranch<float>        ("Var_4LepMET_Zcand_mll");          // Invariant mass of the Z candidate

    // The other two leptons from the 4 lepton event (they must be oppositely charged)
    ana.tx.createBranch<int>          ("Var_4LepMET_other_lep_idx_0");    // idxs to the NanoAOD
    ana.tx.createBranch<int>          ("Var_4LepMET_other_lep_pdgid_0");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.createBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0");     // p4 of the lepton
    ana.tx.createBranch<int>          ("Var_4LepMET_other_lep_idx_1");    // idxs to the NanoAOD
    ana.tx.createBranch<int>          ("Var_4LepMET_other_lep_pdgid_1");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.createBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1");     // p4 of the lepton
    ana.tx.createBranch<float>        ("Var_4LepMET_other_mll");          // Invariant mass of the Z candidate

    // Additional variables
    ana.tx.createBranch<float>        ("Var_4LepMET_mt2");                // Invariant mass of the Z candidate

    // Cross section related info
    ana.tx.createBranch<float>        ("Var_4LepMET_scale1fb");           // Scale 1fb
}

void Begin_4LepMET_Parse_Scale1fbs()
{
    fourlep::scale1fbs.clear();
    ifstream ifile;
    ifile.open("weights/scale1fbs.txt");
    std::string line;
    while (std::getline(ifile, line))
    {
        TString rawline = line;
        std::vector<TString> list = RooUtil::StringUtil::split(rawline, ",");
        fourlep::scale1fbs[list[0].Strip()] = list[1].Atof();
    }
}


void Begin_4LepMET_VVVTree()
{

    //___________________________________________________________________________________________________________________________________________________
    TFile* inputfile = TFile::Open(ana.input_file_list_tstring);
    TH1F* h_nevents = (TH1F*) inputfile->Get("Wgt__h_nevents"); // Should be "Wgt" to be accurate but the tree does not save event weight (i.e. the sign)
    float n_total_events = h_nevents->GetBinContent(1);

    //___________________________________________________________________________________________________________________________________________________
    int year = -1;
    if (ana.input_file_list_tstring.Contains("2016")) year = 2016;
    if (ana.input_file_list_tstring.Contains("2017")) year = 2017;
    if (ana.input_file_list_tstring.Contains("2018")) year = 2018;

    //___________________________________________________________________________________________________________________________________________________
    float lumi = 0;
    if (year == 2016) lumi = 35.9;
    if (year == 2017) lumi = 41.3;
    if (year == 2018) lumi = 59.74;

    //___________________________________________________________________________________________________________________________________________________
    // For samples that don't exist in other years
    if (year == 2018 and ana.input_file_list_tstring.Contains("/EFT_ZZZ_2l.root"))
        lumi = 136.94;

    //___________________________________________________________________________________________________________________________________________________
    float xsecbr = 0;
    if (ana.input_file_list_tstring.Contains("/DY_high.root"         )) xsecbr = 6197.9;
    if (ana.input_file_list_tstring.Contains("/DY_low.root"          )) xsecbr = 20657.0;
    if (ana.input_file_list_tstring.Contains("/DYzpt150.root"        )) xsecbr = 202.9;
    if (ana.input_file_list_tstring.Contains("/GGHtoZZto4L.root"     )) xsecbr = 0.011814 * 1.1287633316; // Difference between scale1fb and HXSWG twiki
    if (ana.input_file_list_tstring.Contains("/TTDL.root"            )) xsecbr = 72.1;
    if (ana.input_file_list_tstring.Contains("/TTHtoNonBB.root"      )) xsecbr = 0.215;
    if (ana.input_file_list_tstring.Contains("/TTSL.root"            )) xsecbr = 365.34;
    if (ana.input_file_list_tstring.Contains("/TTSLtop.root"         )) xsecbr = 182.96;
    if (ana.input_file_list_tstring.Contains("/TTSLtopbar.root"      )) xsecbr = 182.96;
    if (ana.input_file_list_tstring.Contains("/TTWH.root"            )) xsecbr = 0.001582;
    if (ana.input_file_list_tstring.Contains("/TTWW.root"            )) xsecbr = 0.0115;
    if (ana.input_file_list_tstring.Contains("/TTWZ.root"            )) xsecbr = 0.003884;
    if (ana.input_file_list_tstring.Contains("/TTWnlo.root"          )) xsecbr = 0.2043;
    if (ana.input_file_list_tstring.Contains("/TTZH.root"            )) xsecbr = 0.001535;
    if (ana.input_file_list_tstring.Contains("/TTZLOW.root"          )) xsecbr = 0.0493;
    if (ana.input_file_list_tstring.Contains("/TTZZ.root"            )) xsecbr = 0.001982;
    if (ana.input_file_list_tstring.Contains("/TTZnlo.root"          )) xsecbr = 0.2529 * 0.2728/0.2529; // cross section based on AN2018-025
    if (ana.input_file_list_tstring.Contains("/TWZ.root"             )) xsecbr = 0.01123;
    if (ana.input_file_list_tstring.Contains("/VHtoNonBB.root"       )) xsecbr = 0.952;
    if (ana.input_file_list_tstring.Contains("/WZ.root"              )) xsecbr = 4.4297;
    if (ana.input_file_list_tstring.Contains("/WZG.root"             )) xsecbr = 0.04123;
    if (ana.input_file_list_tstring.Contains("/ZZ.root"              )) xsecbr = 1.256 * 1.1; // missing K-factor
    if (ana.input_file_list_tstring.Contains("/ZZcontTo2e2mu.root"   )) xsecbr = 0.005423;
    if (ana.input_file_list_tstring.Contains("/ZZcontTo2e2tau.root"  )) xsecbr = 0.005423;
    if (ana.input_file_list_tstring.Contains("/ZZcontTo2mu2tau.root" )) xsecbr = 0.005423;
    if (ana.input_file_list_tstring.Contains("/ZZcontTo4e.root"      )) xsecbr = 0.002703;
    if (ana.input_file_list_tstring.Contains("/ZZcontTo4mu.root"     )) xsecbr = 0.002703;
    if (ana.input_file_list_tstring.Contains("/ZZcontTo4tau.root"    )) xsecbr = 0.002703;
    if (ana.input_file_list_tstring.Contains("/WWW_incl.root"        )) xsecbr = 0.2086;
    if (ana.input_file_list_tstring.Contains("/WWZ_incl.root"        )) xsecbr = 0.1651;
    if (ana.input_file_list_tstring.Contains("/WZZ_incl.root"        )) xsecbr = 0.05565;
    if (ana.input_file_list_tstring.Contains("/ZZZ_incl.root"        )) xsecbr = 0.01398;
    if (ana.input_file_list_tstring.Contains("/WWW_2l.root"          )) xsecbr = 0.051998;
    if (ana.input_file_list_tstring.Contains("/WWZ_4l.root"          )) xsecbr = 5.972e-04;
    if (ana.input_file_list_tstring.Contains("/WZZ_4l.root"          )) xsecbr = 0.0002692;
    if (ana.input_file_list_tstring.Contains("/ZZZ_4l.root"          )) xsecbr = 0.0001907;
    if (ana.input_file_list_tstring.Contains("/EFT_WWZ_4l.root"      )) xsecbr = 0.001785056782; // ((0.1071+0.1063+0.1138)^2*(0.03363+0.03366+0.03370))*0.1651
    if (ana.input_file_list_tstring.Contains("/ZHtoWW.root"          )) xsecbr = 0.0018639;
    if (ana.input_file_list_tstring.Contains("/GGZHtoWW.root"        )) xsecbr = 0.00029975;
    if (ana.input_file_list_tstring.Contains("/ZHtoWW.root"          ) and year == 2016) xsecbr = 0.0018639 * 9.9601593625; // Fixing BR due to what seems like McM config error. BR of Z->ll / Z->all (calculated from zh_ww_4l_powheg sample itself (is this the correct thing to do? maybe?))
    if (ana.input_file_list_tstring.Contains("/GGZHtoWW.root"        ) and year == 2016) xsecbr = 0.00029975 * 2.9735355337; // Fixing BR due to what seems like McM config error. BR of Z->ll / Z->ll/vv (calculated from ggzh_ww_4l_powheg sample itself (is this the correct thing to do? maybe?))
    if (ana.input_file_list_tstring.Contains("/EFT_ZZZ_2l.root"      )) xsecbr = 0.0103663118433 * 0.273160562; // 1 - (all had)
    if (ana.input_file_list_tstring.Contains("/EFT_WZZ_incl.root"    )) xsecbr = 0.05565; // Took same as WZZ_incl from other samples

    //___________________________________________________________________________________________________________________________________________________
    float wgt = xsecbr > 0 ? xsecbr / n_total_events * lumi * 1000.: 1;

    std::cout <<  " xsecbr: " << xsecbr <<  " n_total_events: " << n_total_events <<  " lumi: " << lumi <<  " year: " << year <<  std::endl;

    //___________________________________________________________________________________________________________________________________________________
    bool isEFT = (ana.input_file_list_tstring.Contains("/EFT_"));

    //___________________________________________________________________________________________________________________________________________________
    TH1F* h_mg_reweight;
    if (isEFT)
    {
        h_mg_reweight = (TH1F*) inputfile->Get("Root__h_Common_LHEWeight_mg_reweighting");
    }

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");

    ana.cutflow.addCutToLastActiveCut("CutGenStitch", [&, year, isEFT]()
            {
                if (not isEFT)
                {
                    if (year == 2017 or year == 2018)
                    {
                        if (ana.input_file_list_tstring.Contains("Z_incl.root")) // **Z_incl.root (viz. WWZ, WZZ, ZZZ)
                            return vvv.Common_gen_n_light_lep() < 4;
                    }
                    if (ana.input_file_list_tstring.Contains("WWW_incl.root"))
                        return vvv.Common_gen_n_light_lep() < 2;
                    return true;
                }
                else
                {
                    return true;
                }
            }, UNITY);

    // 0          EFT__FM0_1  set param_card anoinputs 4 1e-12 # orig: 0.0\n...
    // 1         EFT__FM0_m1  set param_card anoinputs 4 -1e-12 # orig: 0.0\...
    // 2          EFT__FM1_1  set param_card anoinputs 5 1e-12 # orig: 0.0\n...
    // 3         EFT__FM1_m1  set param_card anoinputs 5 -1e-12 # orig: 0.0\...
    // 4          EFT__FM2_1  set param_card anoinputs 6 1e-12 # orig: 0.0\n...
    // 5         EFT__FM2_m1  set param_card anoinputs 6 -1e-12 # orig: 0.0\...
    // 6          EFT__FM3_1  set param_card anoinputs 7 1e-12 # orig: 0.0\n...
    // 7         EFT__FM3_m1  set param_card anoinputs 7 -1e-12 # orig: 0.0\...
    // 8          EFT__FM4_1  set param_card anoinputs 8 1e-12 # orig: 0.0\n...
    // 9         EFT__FM4_m1  set param_card anoinputs 8 -1e-12 # orig: 0.0\...
    // 10         EFT__FM5_1  set param_card anoinputs 9 1e-12 # orig: 0.0\n...
    // 11        EFT__FM5_m1  set param_card anoinputs 9 -1e-12 # orig: 0.0\...
    // 12         EFT__FM6_1  set param_card anoinputs 10 1e-12 # orig: 0.0\...
    // 13        EFT__FM6_m1  set param_card anoinputs 10 -1e-12 # orig: 0.0...
    // 14         EFT__FM7_1  set param_card anoinputs 11 1e-12 # orig: 0.0\...
    // 15        EFT__FM7_m1  set param_card anoinputs 11 -1e-12 # orig: 0.0...
    // 16         EFT__FS0_1  set param_card anoinputs 1 1e-12 # orig: 0.0\n...
    // 17        EFT__FS0_m1  set param_card anoinputs 1 -1e-12 # orig: 0.0\...
    // 18         EFT__FS1_1  set param_card anoinputs 2 1e-12 # orig: 0.0\n...
    // 19        EFT__FS1_m1  set param_card anoinputs 2 -1e-12 # orig: 0.0\...
    // 20         EFT__FT0_1  set param_card anoinputs 12 1e-12 # orig: 5e-12\n
    // 21  EFT__FT0_1__FT1_1  set param_card anoinputs 12 1e-12 # orig: 5e-1...
    // 22  EFT__FT0_1__FT1_5  set param_card anoinputs 12 1e-12 # orig: 5e-1...
    // 23  EFT__FT0_1__FT2_1  set param_card anoinputs 12 1e-12 # orig: 5e-1...
    // 24  EFT__FT0_1__FT2_5  set param_card anoinputs 12 1e-12 # orig: 5e-1...
    // 25         EFT__FT0_5                                                NaN
    // 26  EFT__FT0_5__FT1_1    set param_card anoinputs 13 1e-12 # orig: 0.0\n
    // 27  EFT__FT0_5__FT1_5    set param_card anoinputs 13 5e-12 # orig: 0.0\n
    // 28  EFT__FT0_5__FT2_1    set param_card anoinputs 14 1e-12 # orig: 0.0\n
    // 29  EFT__FT0_5__FT2_5    set param_card anoinputs 14 5e-12 # orig: 0.0\n
    // 30        EFT__FT0_m1  set param_card anoinputs 12 -1e-12 # orig: 5e-...
    // 31        EFT__FT0_m5  set param_card anoinputs 12 -5e-12 # orig: 5e-...
    // 32         EFT__FT1_1  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 33  EFT__FT1_1__FT2_1  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 34  EFT__FT1_1__FT2_5  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 35         EFT__FT1_5  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 36  EFT__FT1_5__FT2_1  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 37  EFT__FT1_5__FT2_5  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 38        EFT__FT1_m1  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 39        EFT__FT1_m5  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 40         EFT__FT2_1  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 41         EFT__FT2_5  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 42        EFT__FT2_m1  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 43        EFT__FT2_m5  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 44         EFT__FT5_1  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 45        EFT__FT5_m1  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 46         EFT__FT6_1  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 47        EFT__FT6_m1  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 48         EFT__FT7_1  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 49        EFT__FT7_m1  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    // 50            EFT__SM    set param_card anoinputs 12 0.0 # orig: 5e-12\n

    // WZZ
    //id                                               text
    //    0        EFT_SM    set param_card anoinputs 12 0.0 # orig: 5e-12\n
    //    1  EFT_FT0_m100  set param_card anoinputs 12 -1e-10 # orig: 5e-...
    //    2   EFT_FT0_m50  set param_card anoinputs 12 -5e-11 # orig: 5e-...
    //    3   EFT_FT0_m10  set param_card anoinputs 12 -1e-11 # orig: 5e-...
    //    4    EFT_FT0_10  set param_card anoinputs 12 1e-11 # orig: 5e-12\n
    //    5    EFT_FT0_50  set param_card anoinputs 12 5e-11 # orig: 5e-12\n
    //    6   EFT_FT0_100  set param_card anoinputs 12 1e-10 # orig: 5e-12\n


    // ZZZ
    // id                                               text
    //     0               EFT_SM    set param_card anoinputs 12 0.0 # orig: 5e-12\n
    //     1         EFT_FT0_m100  set param_card anoinputs 12 -1e-10 # orig: 5e-...
    //     2          EFT_FT0_m50  set param_card anoinputs 12 -5e-11 # orig: 5e-...
    //     3          EFT_FT0_m10  set param_card anoinputs 12 -1e-11 # orig: 5e-...
    //     4           EFT_FT0_10  set param_card anoinputs 12 1e-11 # orig: 5e-12\n
    //     5           EFT_FT0_50  set param_card anoinputs 12 5e-11 # orig: 5e-12\n
    //     6          EFT_FT0_100  set param_card anoinputs 12 1e-10 # orig: 5e-12\n
    //     7         EFT_FT8_m100  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    //     8          EFT_FT8_m50  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    //     9          EFT_FT8_m10  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    //     10          EFT_FT8_10  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    //     11          EFT_FT8_50  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    //     12         EFT_FT8_100  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    //     13        EFT_FT9_m100  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    //     14         EFT_FT9_m50  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    //     15         EFT_FT9_m10  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    //     16          EFT_FT9_10  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    //     17          EFT_FT9_50  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    //     18         EFT_FT9_100  set param_card anoinputs 12 0.0 # orig: 5e-12\...
    //     19  EFT_FT8_50__FT9_50  set param_card anoinputs 12 0.0 # orig: 5e-12\...


    // const int eft_reweighting_idx = result["modifier"].as<int>();
    // const int eft_parameter_multiplication_factor = result["eftmultfac"].as<int>();
    const int eft_reweighting_idx = ana.eft_reweighting_idx;
    const int eft_parameter_multiplication_factor = 1;

    // WWZ:
    // WZZ:
    // ZZZ: SM index

    int eft_sm_idx = 0;
    if (ana.input_file_list_tstring.Contains("/EFT_WWZ"))
        eft_sm_idx = 50;

    ana.cutflow.addCutToLastActiveCut("CutEFTWeights", UNITY, [&, isEFT, eft_reweighting_idx, eft_parameter_multiplication_factor, n_total_events, h_mg_reweight, eft_sm_idx]()
            {
                if (isEFT)
                {
                    if (eft_reweighting_idx == 9999)
                    {
                        float SM_wgt = vvv.Common_LHEWeight_mg_reweighting()[eft_sm_idx];
                        float EFT_wgt_FT0 = vvv.Common_LHEWeight_mg_reweighting()[20];
                        float EFT_wgt_FT1 = vvv.Common_LHEWeight_mg_reweighting()[32];
                        float parameter = 5;
                        float growth_FT0 = EFT_wgt_FT0 / SM_wgt;
                        float growth_FT1 = EFT_wgt_FT1 / SM_wgt;
                        float change_FT0 = (growth_FT0 - 1);
                        float change_FT1 = (growth_FT1 - 1);
                        float newchange_FT0 = change_FT0 * parameter * parameter; // a * x^2;
                        float newchange_FT1 = change_FT1 * parameter * parameter; // a * x^2;
                        float new_EFT_wgt = (newchange_FT0 + newchange_FT1 + 1) * SM_wgt;
                        return (float) (new_EFT_wgt * n_total_events / h_mg_reweight->GetBinContent(eft_sm_idx + 1));
                    }
                    else
                    {
                        float SM_wgt = vvv.Common_LHEWeight_mg_reweighting()[eft_sm_idx];
                        float EFT_wgt = vvv.Common_LHEWeight_mg_reweighting()[eft_reweighting_idx];
                        float parameter = eft_parameter_multiplication_factor;
                        float growth = EFT_wgt / SM_wgt;
                        float change = (growth - 1);
                        float newchange = change * parameter * parameter; // a * x^2;
                        float new_EFT_wgt = (newchange + 1) * SM_wgt;
                        return (float) (new_EFT_wgt * n_total_events / h_mg_reweight->GetBinContent(eft_sm_idx + 1));
                    }
                }
                else
                {
                    return 1.f;
                }
            } );

    ana.cutflow.addCutToLastActiveCut("CutFourLeptons", [&]() { return vvv.Common_lep_pdgid().size() == 4; }, [&]() { return vvv.Common_event_lepSF(); });
    ana.cutflow.addCutToLastActiveCut("CutTrigger", [&]()
            {
                bool pass_trigger = vvv.Common_HLT_DoubleEl() or vvv.Common_HLT_DoubleMu() or vvv.Common_HLT_MuEG();
                bool duplicate = vvv.Common_isData() ? vvv.Common_pass_duplicate_removal_ee_em_mm() : 1.;
                return (pass_trigger and duplicate);
            }, UNITY);

    ana.cutflow.addCutToLastActiveCut("CutOSWlep", [&]() { return (vvv.Var_4LepMET_other_lep_pdgid_0() * vvv.Var_4LepMET_other_lep_pdgid_1()) < 0; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("CutLeptonPt", [&]()
            {
                return vvv.Var_4LepMET_Zcand_lep_p4_0().pt() > 25. and
                       vvv.Var_4LepMET_Zcand_lep_p4_1().pt() > 10. and
                       vvv.Var_4LepMET_other_lep_p4_0().pt() > 25. and
                       vvv.Var_4LepMET_other_lep_p4_1().pt() > 10.;
            }, UNITY);

    ana.cutflow.addCutToLastActiveCut("CutLeptonTight", [&]()
            {
                if (not ana.tx.getBranch<vector<int>>("Common_lep_tight")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_0")])
                    return false;
                if (not ana.tx.getBranch<vector<int>>("Common_lep_tight")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_1")])
                    return false;
                if (not (fabs(ana.tx.getBranch<vector<float>>("Common_lep_dz")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_0")]) < 0.03))
                    return false;
                if (not (fabs(ana.tx.getBranch<vector<float>>("Common_lep_dz")[ana.tx.getBranch<int>("Var_4LepMET_other_lep_idx_1")]) < 0.03))
                    return false;
                return true;
            }, UNITY);

    // ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_NbVeto", [&]() { return ana.tx.getBranch<int>("Common_nb_loose") == 0; }, UNITY);

    // Create a middle point of preselection
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_Preselection", [&]() { return ana.tx.getBranch<bool>("Cut_4LepMET_Preselection"); }, [&, wgt]() { return (vvv.Common_isData() ? 1. : wgt); } );

}

float Begin_4LepMET_MT2(int var)
{
    TLorentzVector lepton1 = RooUtil::Calc::getTLV(ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0"));
    TLorentzVector lepton2 = RooUtil::Calc::getTLV(ana.tx.getBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1"));
    TLorentzVector misspart = RooUtil::Calc::getTLV(ana.tx.getBranch<LorentzVector>("Common_met_p4"));
    TLorentzVector rest_WW;
    rest_WW = lepton1 + lepton2 + misspart;
    TVector3 beta_from_miss_reverse(rest_WW.BoostVector());
    TVector3 beta_from_miss(-beta_from_miss_reverse.X(),-beta_from_miss_reverse.Y(),-beta_from_miss_reverse.Z());

    lepton1.Boost(beta_from_miss);
    lepton2.Boost(beta_from_miss);
    misspart.Boost(beta_from_miss);
    asymm_mt2_lester_bisect::disableCopyrightMessage();
    double MT2_0mass = asymm_mt2_lester_bisect::get_mT2(0,lepton1.Px(),lepton1.Py(),0,lepton2.Px(),lepton2.Py(),misspart.Px(), misspart.Py(),0,0,0);

    return MT2_0mass;
}

