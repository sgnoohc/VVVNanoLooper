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
        case AnalysisConfig::kallHad: Terminate_allHad(); break;
        case AnalysisConfig::k1Lep2fatJets: Terminate_1Lep2fatjet(); break;
        case AnalysisConfig::kE: Terminate_E(); break;
    }


    // Writing output file
    ana.cutflow.saveOutput();

    // If write tree then save
    if (ana.write_tree)
    {
        if (ana.looperMode == AnalysisConfig::kE)
            ana.txskim.write();
        else
            ana.tx.write();
    }
    else
    {
        ana.output_tree->Fill(); // Fill an empty dummy event to pass rigorous sweep root. (So condor jobs don't delete it, because it's empty.)
        ana.output_tree->Write();
    }
    if(ana.run_VVVTree){
        TFile* inputfile = TFile::Open(ana.input_file_list_tstring);
        TH1F* h_nevents = (TH1F*) inputfile->Get("Wgt__h_nevents"); // Should be "Wgt" to be accurate but the tree does not save event weight (i.e. the sign)
        TH1F* h_mg_reweight = (TH1F*) inputfile->Get("Root__h_Common_LHEWeight_mg_reweighting_times_genWeight");
        ana.output_tfile->cd();

        if(h_mg_reweight) h_mg_reweight->Write();
        h_nevents->Write();
    }

    // The below can be sometimes crucial
    delete ana.output_tfile;
}
