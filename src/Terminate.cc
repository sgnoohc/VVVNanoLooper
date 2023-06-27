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
	case AnalysisConfig::k3LepTauMET: Terminate_3LepTauMET(); break;
	case AnalysisConfig::kAll: Terminate_4LepMET(); Terminate_3LepTauMET(); break;
	case AnalysisConfig::k2LepRun3: Terminate_2LepRun3(); break;
    }


    // Writing output file
    ana.cutflow.saveOutput();

    // If write tree then save
    if (ana.write_tree)
    {
        ana.tx.write();
    }
    else
    {
        ana.output_tree->Fill(); // Fill an empty dummy event to pass rigorous sweep root. (So condor jobs don't delete it, because it's empty.)
        ana.output_tree->Write();
    }

    // The below can be sometimes crucial
    delete ana.output_tfile;
}
