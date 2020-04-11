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
    ana.tx.createBranch<int>("4LepMET_Zcand_lep_idx_0");
    ana.tx.createBranch<int>("4LepMET_Zcand_lep_idx_1");
    ana.tx.createBranch<float>("4LepMET_Zcand_mll");
    ana.tx.createBranch<int>("4LepMET_other_lep_idx_0");
    ana.tx.createBranch<int>("4LepMET_other_lep_idx_1");

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");

    // Select 4 leptons
    ana.cutflow.addCutToLastActiveCut("4LepMET_Has4Lepton",
            [&]()
            {
                // Needs to be 4 leptons
                if (not (ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size() == 4))
                    return false;
                return true;
            }, UNITY);

    // Select Z candidate
    ana.cutflow.addCutToLastActiveCut("4LepMET_HasZCandidate",
            [&]()
            {

                auto [ has_sfos, idx1, idx2, mll ] = RooUtil::Calc::pickZcandidateIdxs(
                        ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs"),
                        ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid"),
                        ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4"));
                if (not (has_sfos)) return false;
                if (not (abs(mll - 91.1876) < 10.)) return false;

                // If found a Z then set the variables
                ana.tx.setBranch<int>("4LepMET_Zcand_lep_idx_0", idx1);
                ana.tx.setBranch<int>("4LepMET_Zcand_lep_idx_1", idx2);
                ana.tx.setBranch<float>("4LepMET_Zcand_mll", mll);

                // The leading one has to pass 25 GeV
                if (not (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[idx1].pt() > 25.)) return false;

                return true;
            }, UNITY);

    // Select Z candidate
    ana.cutflow.addCutToLastActiveCut("4LepMET_OtherLeptons",
            [&]()
            {
                // The other two lepton indices
                vector<int> other_lep_idxs;

                // Loop over the indices and if it is Z candidnate lepton idx then skip
                for (auto& ilep : ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs"))
                {
                    // If z cand lepton then skip
                    if (ilep == ana.tx.getBranchLazy<int>("4LepMET_firstZ_lep_idx_0")) continue;
                    if (ilep == ana.tx.getBranchLazy<int>("4LepMET_firstZ_lep_idx_1")) continue;

                    other_lep_idxs.push_back(ilep);
                }

                // Sanity check that it must be 2 leptons
                if (other_lep_idxs.size() != 2)
                    RooUtil::error("It should have been 4 leptons! how come you have != 2 other leptons here after accounting for the Z leptons??", __FILE__);

                // set the idxs
                ana.tx.setBranch<int>("4LepMET_other_lep_idx_0", other_lep_idxs[0]);
                ana.tx.setBranch<int>("4LepMET_other_lep_idx_1", other_lep_idxs[1]);

                // The leading one has to pass 25 GeV
                if (not (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[other_lep_idxs[0]].pt() > 25.)) return false;

                return true;
            }, UNITY);

    // Create a middle point of preselection
    ana.cutflow.addCutToLastActiveCut("4LepMET_Preselection", UNITY, UNITY); // This "cut" does not do anything. It works as a middle point

    // Add different channels
    ana.cutflow.getCut("4LepMET_Preselection");

    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    ana.histograms.addHistogram("h_4LepMET_intVar1", 10, 0, 10, [&]() { return ana.tx.getBranch<int>("4LepMET_intVar1"); } );
    ana.histograms.addHistogram("h_4LepMET_floatVar1", 180, 0, 500, [&]() { return ana.tx.getBranch<float>("4LepMET_floatVar1"); } );
    ana.histograms.addHistogram("h_4LepMET_LVVar1_Pt", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("4LepMET_LVVar1").pt(); } );

    // Now book cutflow histogram (could be commented out if user does not want.)
    // N.B. Cutflow histogramming can be CPU consuming.
    ana.cutflow.bookCutflows();

    // Book histograms to cuts that user wants for this category.
    ana.cutflow.bookHistogramsForCut(ana.histograms, "4LepMET_Preselection");
}
