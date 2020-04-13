#include "Begin_4LepMET.h"

void Begin_4LepMET()
{
    //==============================================
    // Begin_4LepMET:
    // This function gets called prior to the event looping.
    // This is where one declares variables, histograms, event selections for the category 4LepMET.
    //==============================================

    // Create variables used in this category.
    // Please follow the convention of <category>_<varname> structure.

    // Z candidate idxs, pdgid, and 4 vectors
    // The Z candidate is the SFOS pair that is closest to the Z mass
    ana.tx.createBranch<int>          ("4LepMET_Zcand_lep_idx_0");    // idxs to the NanoAOD
    ana.tx.createBranch<int>          ("4LepMET_Zcand_lep_pdgid_0");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.createBranch<LorentzVector>("4LepMET_Zcand_lep_p4_0");     // p4 of the lepton
    ana.tx.createBranch<int>          ("4LepMET_Zcand_lep_idx_1");    // idxs to the NanoAOD
    ana.tx.createBranch<int>          ("4LepMET_Zcand_lep_pdgid_1");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.createBranch<LorentzVector>("4LepMET_Zcand_lep_p4_1");     // p4 of the lepton
    ana.tx.createBranch<float>        ("4LepMET_Zcand_mll");          // Invariant mass of the Z candidate

    // The other two leptons from the 4 lepton event (they must be oppositely charged)
    ana.tx.createBranch<int>          ("4LepMET_other_lep_idx_0");    // idxs to the NanoAOD
    ana.tx.createBranch<int>          ("4LepMET_other_lep_pdgid_0");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.createBranch<LorentzVector>("4LepMET_other_lep_p4_0");     // p4 of the lepton
    ana.tx.createBranch<int>          ("4LepMET_other_lep_idx_1");    // idxs to the NanoAOD
    ana.tx.createBranch<int>          ("4LepMET_other_lep_pdgid_1");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.createBranch<LorentzVector>("4LepMET_other_lep_p4_1");     // p4 of the lepton
    ana.tx.createBranch<float>        ("4LepMET_other_mll");          // Invariant mass of the Z candidate

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");

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
                ana.tx.setBranch<int>          ("4LepMET_Zcand_lep_idx_0"   , ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[idx1]);
                ana.tx.setBranch<int>          ("4LepMET_Zcand_lep_pdgid_0" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[idx1]);
                ana.tx.setBranch<LorentzVector>("4LepMET_Zcand_lep_p4_0"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[idx1]);
                ana.tx.setBranch<int>          ("4LepMET_Zcand_lep_idx_1"   , ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[idx2]);
                ana.tx.setBranch<int>          ("4LepMET_Zcand_lep_pdgid_1" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[idx2]);
                ana.tx.setBranch<LorentzVector>("4LepMET_Zcand_lep_p4_1"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[idx2]);

                ana.tx.setBranch<float>("4LepMET_Zcand_mll", mll);

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
                    if (idx == ana.tx.getBranchLazy<int>("4LepMET_Zcand_lep_idx_0") and pdgid == ana.tx.getBranchLazy<int>("4LepMET_Zcand_lep_pdgid_0")) continue;
                    if (idx == ana.tx.getBranchLazy<int>("4LepMET_Zcand_lep_idx_1") and pdgid == ana.tx.getBranchLazy<int>("4LepMET_Zcand_lep_pdgid_1")) continue;
                    other_lep_idxs  .push_back(ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[ilep]);
                    other_lep_pdgids.push_back(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[ilep]);
                    other_lep_p4s   .push_back(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[ilep]);
                }

                // Sanity check that it must be 2 leptons
                if (other_lep_idxs.size() != 2)
                    RooUtil::error("It should have been 4 leptons! how come you have != 2 other leptons here after accounting for the Z leptons??", __FILE__);

                // set the idxs
                ana.tx.setBranch<int>          ("4LepMET_other_lep_idx_0"   , other_lep_idxs[0]);
                ana.tx.setBranch<int>          ("4LepMET_other_lep_pdgid_0" , other_lep_pdgids[0]);
                ana.tx.setBranch<LorentzVector>("4LepMET_other_lep_p4_0"    , other_lep_p4s[0]);
                ana.tx.setBranch<int>          ("4LepMET_other_lep_idx_1"   , other_lep_idxs[1]);
                ana.tx.setBranch<int>          ("4LepMET_other_lep_pdgid_1" , other_lep_pdgids[1]);
                ana.tx.setBranch<LorentzVector>("4LepMET_other_lep_p4_1"    , other_lep_p4s[1]);

                ana.tx.setBranch<float>("4LepMET_other_mll", (other_lep_p4s[0] + other_lep_p4s[1]).mass());

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

    // Create a middle point of preselection
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_Preselection", UNITY, UNITY); // This "cut" does not do anything. It works as a middle point

    // Add different channels
    ana.cutflow.getCut("Cut_4LepMET_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_emuChannel", [&]() { return (ana.tx.getBranch<int>("4LepMET_other_lep_pdgid_0") * ana.tx.getBranch<int>("4LepMET_other_lep_pdgid_1") == -143); }, UNITY);
    ana.cutflow.getCut("Cut_4LepMET_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_offzChannel", [&]() { return (ana.tx.getBranch<int>("4LepMET_other_lep_pdgid_0") == -ana.tx.getBranch<int>("4LepMET_other_lep_pdgid_1")) and (abs(ana.tx.getBranch<float>("4LepMET_other_mll") - 91.1876) < 10.); }, UNITY);
    ana.cutflow.getCut("Cut_4LepMET_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_4LepMET_onzChannel", [&]() { return (ana.tx.getBranch<int>("4LepMET_other_lep_pdgid_0") == -ana.tx.getBranch<int>("4LepMET_other_lep_pdgid_1")) and (abs(ana.tx.getBranch<float>("4LepMET_other_mll") - 91.1876) >= 10.); }, UNITY);

    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    ana.histograms.addHistogram("h_4LepMET_Zcand_pt_0", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("4LepMET_Zcand_lep_p4_0").pt(); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_pt_1", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("4LepMET_Zcand_lep_p4_1").pt(); } );
    ana.histograms.addHistogram("h_4LepMET_Zcand_mll", 180, 0, 150, [&]() { return ana.tx.getBranch<float>("4LepMET_Zcand_mll"); } );
    ana.histograms.addHistogram("h_4LepMET_other_pt_0", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("4LepMET_other_lep_p4_0").pt(); } );
    ana.histograms.addHistogram("h_4LepMET_other_pt_1", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("4LepMET_other_lep_p4_1").pt(); } );
    ana.histograms.addHistogram("h_4LepMET_other_mll", 180, 0, 150, [&]() { return ana.tx.getBranch<float>("4LepMET_other_mll"); } );
    ana.histograms.addHistogram("h_4LepMET_met", 180, 0, 450, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4").pt(); } );
    ana.histograms.addHistogram("h_4LepMET_met_phi", 180, -3.1416, 3.1416, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4").phi(); } );

    // Now book cutflow histogram (could be commented out if user does not want.)
    // N.B. Cutflow histogramming can be CPU consuming.
    ana.cutflow.bookCutflows();

    // Book histograms to cuts that user wants for this category.
    ana.cutflow.bookHistogramsForCutAndBelow(ana.histograms, "4LepMET_Preselection");
}
