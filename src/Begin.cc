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
	case AnalysisConfig::k3LepTauMET: Begin_3LepTauMET(); break;
	case AnalysisConfig::kAll: Begin_4LepMET(); Begin_3LepTauMET(); break;
    }

    // At this point, the variables, histograms, selections are all defined and booked.

    // Print cut structure
    ana.cutflow.printCuts();

}
