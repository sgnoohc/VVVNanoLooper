#include "Begin.h"

void Begin()
{
    //==============================================
    // Begin:
    // This function gets called prior to the event looping.
    // This function gets called regardless of the looper mode
    //==============================================

    // Begin_Common is always called regardless of the category
    Begin_Common();

    // Then depending on the analysis mode, different "Begin" runs

    switch (ana.looperMode)
    {
        case AnalysisConfig::k4LepMET: Begin_4LepMET(); break;
        case AnalysisConfig::k4Lep2jet: Begin_4Lep2jet(); break;
        case AnalysisConfig::k3LepMET: Begin_3LepMET(); break;
        case AnalysisConfig::k3Lep2jet: Begin_3Lep2jet(); break;
        case AnalysisConfig::kOS4jet: Begin_OS4jet(); break;
        case AnalysisConfig::kOS2jet: Begin_OS2jet(); break;
        case AnalysisConfig::kSS2jet: Begin_SS2jet(); break;
        case AnalysisConfig::k1Lep4jet: Begin_1Lep4jet(); break;
        case AnalysisConfig::kallHad: Begin_allHad(); break;
        case AnalysisConfig::k1Lep2fatJets: Begin_1Lep2fatjet(); break;
    }

    // At this point, the variables, histograms, selections are all defined and booked.

    // Print cut structure
    ana.cutflow.printCuts();

}
