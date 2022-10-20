#include "Begin_4LepMET.h"
#include "lester_mt2_bisect.h"
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iostream>

namespace fourlep{
    std::map<TString, float> scaleLumis;
    std::map<TString, float> intLumis;
}

void Begin_4LepMET()
{
    // Category flag
    Begin_4LepMET_Create_Branches();

    // Parse cross section
    Begin_4LepMET_Parse_Scale1fbs();

    Begin_4LepMET_NanoAOD();

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
    int index1 = 0;
    int index2 = 0;
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_HasZCandidate",
            [&]()
            {

                auto [ has_sfos, idx1, idx2, mll ] = RooUtil::Calc::pickZcandidateIdxs(
                        ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid"),
                        ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4"));
		index1 = idx1;
		index2 = idx2;
                if (not (has_sfos)) return false;
                if (not (abs(mll - 91.1876) < 10.)) return false;

                // If found a Z then set the variables
                //ana.tx.setBranch<int>          ("Var_4LepMET_Zcand_lep_idx_0"   , ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[idx1]);
                ana.tx.setBranch<int>	       ("Var_4LepMET_Zcand_lep_idx_0"   , idx1);
                ana.tx.setBranch<int>          ("Var_4LepMET_Zcand_lep_pdgid_0" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[idx1]);
                ana.tx.setBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_0"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[idx1]);
                //ana.tx.setBranch<int>          ("Var_4LepMET_Zcand_lep_idx_1"   , ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[idx2]);
                ana.tx.setBranch<int>	       ("Var_4LepMET_Zcand_lep_idx_1"   , idx2);
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
                vector<int> idxs;
		vector<int> idxs_coll;
                vector<int> other_lep_idxs;
                vector<int> other_lep_pdgids;
		vector<int> other_lep_IDs;
                vector<LorentzVector> other_lep_p4s;

                // Loop over the indices and pdgid and if it is Z candidnate lepton then skip
                for (unsigned int ilep = 0; ilep < ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size(); ++ilep)
                {
                    int idx_coll = ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[ilep];
                    int idx = ilep;
                    int pdgid = ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[ilep];
                    if (idx == ana.tx.getBranchLazy<int>("Var_4LepMET_Zcand_lep_idx_0") and pdgid == ana.tx.getBranchLazy<int>("Var_4LepMET_Zcand_lep_pdgid_0")) continue;
                    if (idx == ana.tx.getBranchLazy<int>("Var_4LepMET_Zcand_lep_idx_1") and pdgid == ana.tx.getBranchLazy<int>("Var_4LepMET_Zcand_lep_pdgid_1")) continue;
                    idxs            .push_back(ilep);
		    idxs_coll       .push_back(idx_coll);
                    other_lep_idxs  .push_back(ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[ilep]);
                    other_lep_pdgids.push_back(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[ilep]);
                    other_lep_p4s   .push_back(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[ilep]);   
		    
                }

                // Sanity check that it must be 2 leptons
                if (other_lep_idxs.size() != 2)
                    RooUtil::error("It should have been 4 leptons! how come you have != 2 other leptons here after accounting for the Z leptons??", __FILE__);

                // set the idxs
                ana.tx.setBranch<int>          ("Var_4LepMET_other_lep_idx_0"   , idxs[0]);
                ana.tx.setBranch<int>          ("Var_4LepMET_other_lep_pdgid_0" , other_lep_pdgids[0]);
                ana.tx.setBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0"    , other_lep_p4s[0]);
                ana.tx.setBranch<int>          ("Var_4LepMET_other_lep_idx_1"   , idxs[1]);
                ana.tx.setBranch<int>          ("Var_4LepMET_other_lep_pdgid_1" , other_lep_pdgids[1]);
                ana.tx.setBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1"    , other_lep_p4s[1]);

                ana.tx.setBranch<float>("Var_4LepMET_other_mll", (other_lep_p4s[0] + other_lep_p4s[1]).mass());

		int W_lep_ID_0;
		int W_lep_ID_1;
		int Z_lep_ID_0;
		int Z_lep_ID_1;

		// Perform another loop to match common_lep_IDs
		for (unsigned int i = 0; i < ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size(); ++i)  // Loop over common lep indices
                {
		     if ( std::abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[i]) == 13 ){     // If the pdg is muon
			  for (int mu = 0; mu < nt.nMuon(); mu++){					  // Loop over all muons in the collection, and pick the one that matches the index and pdgid 
			       if ( mu == ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[i] and nt.Muon_pdgId()[mu] == ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[i] ){
				    if ( idxs_coll[0] == i ){  // if the index matches the first W candidate lepton
					 // store the ith value of common lep ID as the corresponding lepton's ID
					 W_lep_ID_0 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];				 
				    }
				    if ( idxs_coll[1] == i ){
					 W_lep_ID_1 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];
				    }
				    if ( ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[index1] == i ){
					 Z_lep_ID_0 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];
				    }
				    if ( ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[index2] == i ){
					 Z_lep_ID_1 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];
				    }
			       }
			  }
		     }
		     // Do the same for electrons
		     if ( std::abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[i]) == 11 ){
			  for (int el = 0; el < nt.nElectron(); el++){
			       if ( el == ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[i] and nt.Electron_pdgId()[el] == ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[i] ){
				    if ( idxs_coll[0] == i ){
					 W_lep_ID_0 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];
				    }
				    if ( idxs_coll[1] == i ){
                                         W_lep_ID_1 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];
                                    }
                                    if ( ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[index1] == i ){
                                         Z_lep_ID_0 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];
                                    }
                                    if ( ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[index2] == i ){
                                         Z_lep_ID_1 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];
                                    }

			       }
			  }
		     }		     

		}


                ana.tx.setBranch<int>      ("Var_4LepMET_Zcand_lep_ID_0" , Z_lep_ID_0 );
		ana.tx.setBranch<int>      ("Var_4LepMET_Zcand_lep_ID_1" , Z_lep_ID_1 );
		ana.tx.setBranch<int>      ("Var_4LepMET_other_lep_ID_0" , W_lep_ID_0 );
		ana.tx.setBranch<int>      ("Var_4LepMET_other_lep_ID_1" , W_lep_ID_1 );


                // The leading one has to pass 25 GeV
                if (not (other_lep_p4s[0].pt() > 25.)) return false;

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
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_Compute_ScaleLumi",
            [&]()
            {
                if (not ana.tx.getBranch<int>("Common_isData"))
                {
                    TString key = gSystem->DirName(ana.looper.getCurrentFileName());
                    ana.tx.setBranch<float>("Var_4LepMET_scaleLumi", fourlep::scaleLumis.at(key));
                    ana.tx.setBranch<float>("Var_4LepMET_intLumi", fourlep::intLumis.at(key));
                }
                else
                {
                    ana.tx.setBranch<float>("Var_4LepMET_scaleLumi", 1);
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
    ana.tx.createBranch<int>          ("Var_4LepMET_Zcand_lep_ID_0");     // ID of leading lepton
    ana.tx.createBranch<int>	      ("Var_4LepMET_Zcand_lep_ID_1");     // ID of subleading lepton

    // The other two leptons from the 4 lepton event (they must be oppositely charged)
    ana.tx.createBranch<int>          ("Var_4LepMET_other_lep_idx_0");    // idxs to the NanoAOD
    ana.tx.createBranch<int>          ("Var_4LepMET_other_lep_pdgid_0");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.createBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0");     // p4 of the lepton
    ana.tx.createBranch<int>          ("Var_4LepMET_other_lep_idx_1");    // idxs to the NanoAOD
    ana.tx.createBranch<int>          ("Var_4LepMET_other_lep_pdgid_1");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.createBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1");     // p4 of the lepton
    ana.tx.createBranch<float>        ("Var_4LepMET_other_mll");          // Invariant mass of the Z candidate
    ana.tx.createBranch<int>          ("Var_4LepMET_other_lep_ID_0");     // ID of leading lepton
    ana.tx.createBranch<int>          ("Var_4LepMET_other_lep_ID_1");     // ID of subleading lepton

    // Additional variables
    ana.tx.createBranch<float>        ("Var_4LepMET_mt2");                // Invariant mass of the Z candidate

    // Cross section related info
    ana.tx.createBranch<float>        ("Var_4LepMET_scaleLumi");          // Scale 1fb
    ana.tx.createBranch<float>        ("Var_4LepMET_intLumi");            // Integrated Luminosity
}

void Begin_4LepMET_Parse_Scale1fbs()
{
    fourlep::scaleLumis.clear();
    ifstream ifile;
    ifile.open("weights/scaleLumis.txt");
    std::string line;
    while (std::getline(ifile, line))
    {
        TString rawline = line;
        std::vector<TString> list = RooUtil::StringUtil::split(rawline, ",");
        fourlep::scaleLumis[list[0].Strip()] = list[1].Atof();
        fourlep::intLumis[list[0].Strip()] = list[3].Atof();
    }
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

