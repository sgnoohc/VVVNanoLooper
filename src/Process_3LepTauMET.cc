#include "Process_3LepTauMET.h"

void Process_3LepTauMET()
{
    Process_3LepTauMET_NanoAOD();
}

void Process_3LepTauMET_NanoAOD()
{

    //================================
    // Process_3LepTauMET:
    // This function gets called during the event looping
    // This is where one sets the variables used in the category 3LepMET
    //================================
    //
    // Set variables used in this category.
    // If histograms are booked with these variables the histograms will be filled automatically.
    // Please follow the convention of <category>_<varname> structure.

}

void PostProcess_3LepTauMET()
{
    //==============================================
    // Process_3LepTauMET
    // This function gets called during the event looping after the event processing has been carried out
    // This is where one may decide to write out TTree
    //==============================================

    // If it passes the preselection then decide to write the TTree

    if (ana.cutflow.getCut("Cut_3LepTauMET_Preselection").pass){
	ana.tx.fill();
    }
}
