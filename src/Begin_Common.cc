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

    ana.tx.createBranch<vector<int>>          ("Common_gen_idx");        // Selected gen-particle idx in NanoAOD
    ana.tx.createBranch<vector<int>>          ("Common_gen_mother_idx"); // Selected gen-particle mother idx in NanoAOD
    ana.tx.createBranch<vector<int>>          ("Common_gen_pdgid");      // Selected gen-particle pdgids
    ana.tx.createBranch<vector<LorentzVector>>("Common_gen_p4s");        // Selected gen-particle p4s

    ana.tx.createBranch<vector<int>>          ("Common_gen_lep_idx");        // Selected gen-particle idx in NanoAOD
    ana.tx.createBranch<vector<int>>          ("Common_gen_lep_mother_idx"); // Selected gen-particle mother idx in NanoAOD
    ana.tx.createBranch<vector<int>>          ("Common_gen_lep_pdgid");      // Selected gen-particle pdgids
    ana.tx.createBranch<vector<LorentzVector>>("Common_gen_lep_p4s");        // Selected gen-particle p4s

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.addCut("Wgt", [&]() { return 1; }, [&]() { if (nt.hasGenBranches()) return (nt.genWeight() > 0) - (nt.genWeight() < 0); else return 1; } );
    ana.cutflow.addCutToLastActiveCut("CommonCut", [&]() { return 1;}, [&]() { return 1; } );

    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    RooUtil::Histograms hists_Common;
    hists_Common.addHistogram("h_Common_nLep", 10, 0, 10, [&]() { return ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size(); } );
    hists_Common.addHistogram("h_Common_nJet", 10, 0, 10, [&]() { return ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size(); } );
    hists_Common.addHistogram("h_Common_nFatJet", 10, 0, 10, [&]() { return ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); } );

    // Book histograms to cuts that user wants for this category.
    ana.cutflow.bookHistogramsForCut(hists_Common, "CommonCut");

    // Book histograms to Root to count total number of events processed
    RooUtil::Histograms n_event_hist;
    n_event_hist.addHistogram("h_nevents", 1, 0, 1, [&]() { return 1; } );

    // Book the counter histogram to the Root
    ana.cutflow.bookHistogramsForCut(n_event_hist, "Root");
    ana.cutflow.bookHistogramsForCut(n_event_hist, "Wgt");
}
