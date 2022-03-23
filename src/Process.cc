#include "Process.h"

void Process()
{
    //==============================================
    // Process:
    // This function gets called during the event looping.
    // This is where one sets the variables used for the category .
    //==============================================

    // Process_Common is always called regardless of the category
    Process_Common();

    // Then depending on the analysis mode, different "Process" runs

    switch (ana.looperMode)
    {
        case AnalysisConfig::k4LepMET: Process_4LepMET(); break;
        case AnalysisConfig::k4Lep2jet: Process_4Lep2jet(); break;
        case AnalysisConfig::k3LepMET: Process_3LepMET(); break;
        case AnalysisConfig::k3Lep2jet: Process_3Lep2jet(); break;
        case AnalysisConfig::kOS4jet: Process_OS4jet(); break;
        case AnalysisConfig::kOS2jet: Process_OS2jet(); break;
        case AnalysisConfig::kSS2jet: Process_SS2jet(); break;
        case AnalysisConfig::k1Lep4jet: Process_1Lep4jet(); break;
        case AnalysisConfig::kallHad: Process_allHad(); break;
        case AnalysisConfig::k1Lep2fatJets: Process_1Lep2fatjet(); break;
    }

    // At this point, variables are all computed and set

    // Now fill all the histograms that are booked!
    ana.cutflow.fill();

    // If there are certain things people wish to do "Post" processing of the cutflows and histogramming
    // For example this is where one would write out TTree
    if (ana.write_tree)
    {
        switch (ana.looperMode)
        {
            case AnalysisConfig::k4LepMET: PostProcess_4LepMET(); break;
            case AnalysisConfig::k4Lep2jet: break;
            case AnalysisConfig::k3LepMET: break;
            case AnalysisConfig::k3Lep2jet: break;
            case AnalysisConfig::kOS4jet: break;
            case AnalysisConfig::kOS2jet: break;
            case AnalysisConfig::kSS2jet: PostProcess_SS2jet(); break;
            case AnalysisConfig::k1Lep4jet: break;
<<<<<<< HEAD
            case AnalysisConfig::kallHad: PostProcess_allHad(); break;
=======
            case AnalysisConfig::k1Lep2fatJets: break;
>>>>>>> 57e37fa8006e2b8f7d125ac752abc4225e2cdb6a
        }
    }

    // Reset all the variables!
    ana.tx.clear();
}
