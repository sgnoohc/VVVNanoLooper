#include "Begin_Common.h"

void Begin_Common()
{
    //==============================================
    // Begin_Common:
    // This function gets called prior to the event looping.
    // This is where one declares variables, histograms, event selections for the category Common.
    //==============================================

    // Create variables used in this category.
    // Please follow the convention of <category>_<varname> structure.

    // Summary 4 vectors of the objects selected
    ana.tx.createBranch<LorentzVector>        ("Common_met_p4");
    ana.tx.createBranch<vector<LorentzVector>>("Common_lep_p4");      // Pt sorted selected lepton p4s (electrons and muons together)
    ana.tx.createBranch<vector<int>>          ("Common_lep_idxs");    // Pt sorted selected lepton idxs (electrons and muons together)
    ana.tx.createBranch<vector<int>>          ("Common_lep_pdgid");   // Pt sorted selected lepton pdgids (so that Common_lep_idxs can be used to access NanoAOD)
    ana.tx.createBranch<vector<LorentzVector>>("Common_jet_p4");      // Pt sorted selected jet p4s
    ana.tx.createBranch<vector<int>>          ("Common_jet_idxs");    // Pt sorted selected jet idxs (To access rest of the jet variables in NanoAOD)
    ana.tx.createBranch<vector<LorentzVector>>("Common_fatjet_p4");   // Pt sorted selected fatjet p4s
    ana.tx.createBranch<vector<int>>          ("Common_fatjet_idxs"); // Pt sorted selected fatjet idxs (To access rest of the fatjet variables in NanoAOD)

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.addCut("Wgt", [&]() { return 1; }, [&]() { return 1/* TODO Implement common weight*/; } );
    ana.cutflow.addCutToLastActiveCut("CommonCut", [&]() { return 1;}, [&]() { return 1; } );

    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    ana.histograms.addHistogram("h_Common_nLep", 10, 0, 10, [&]() { return ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size(); } );
    ana.histograms.addHistogram("h_Common_nJet", 10, 0, 10, [&]() { return ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size(); } );
    ana.histograms.addHistogram("h_Common_nFatJet", 10, 0, 10, [&]() { return ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); } );

    // Book histograms to cuts that user wants for this category.
    ana.cutflow.bookHistogramsForCut(ana.histograms, "CommonCut");
}
