#include "Terminate.h"

void Terminate()
{
    //==============================================
    // Terminate:
    // This function gets called after the event looping.
    // This is where one does stuff that needs to happen after the event looping.
    //==============================================

    // Terminate_Common is always called regardless of the category
    Terminate_Common();

    // Then depending on the analysis mode, different "Terminate" runs

    switch (ana.looperMode)
    {
        case AnalysisConfig::k4LepMET: Terminate_4LepMET(); break;
        case AnalysisConfig::k4Lep2jet: Terminate_4Lep2jet(); break;
        case AnalysisConfig::k3LepMET: Terminate_3LepMET(); break;
        case AnalysisConfig::k3Lep2jet: Terminate_3Lep2jet(); break;
        case AnalysisConfig::kOS4jet: Terminate_OS4jet(); break;
        case AnalysisConfig::kOS2jet: Terminate_OS2jet(); break;
        case AnalysisConfig::kSS2jet: Terminate_SS2jet(); break;
        case AnalysisConfig::k1Lep4jet: Terminate_1Lep4jet(); break;
    }

    // Writing output file
    ana.cutflow.saveOutput();

    // The output TTree is currently not implemented and not being used
    ana.output_tree->Fill(); // Fill an empty dummy event to pass rigorous sweep root. (So condor jobs don't delete it, because it's empty.)
    ana.output_tree->Write();

    // The below can be sometimes crucial
    delete ana.output_tfile;
}
