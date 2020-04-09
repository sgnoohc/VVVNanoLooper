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
    // N.B. PLEASE USE float TYPE FOR EVERYTHING, UNLESS IT IS LORENTZVECTOR (which is also done in float).
    ana.tx.createBranch<vector<int>>("Common_electron_idxs");
    ana.tx.createBranch<vector<int>>("Common_muon_idxs");

    // Define selections
    // VVVCommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.addCut("Wgt", [&]() { return 1; }, [&]() { return 1/* TODO Implement common weight*/; } );
    ana.cutflow.addCutToLastActiveCut("VVVCommonCut", [&]() { return 1;}, [&]() { return 1; } );

    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    ana.histograms.addHistogram("h_Common_nLep", 10, 0, 10, [&]() { return ana.tx.getBranchLazy<vector<int>>("Common_electron_idxs").size() + ana.tx.getBranchLazy<vector<int>>("Common_muon_idxs").size(); } );

    // Book histograms to cuts that user wants for this category.
    ana.cutflow.bookHistogramsForCut(ana.histograms, "VVVCommonCut");
}
