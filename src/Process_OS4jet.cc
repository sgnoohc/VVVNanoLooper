#include "Process_OS4jet.h"

void Process_OS4jet()
{
    //==============================================
    // Process_OS4jet:
    // This function gets called during the event looping.
    // This is where one sets the variables used for the category OS4jet.
    //==============================================

    // Set variables used in this category.
    // If histograms are booked with these variables the histograms will be filled automatically.
    // Please follow the convention of <category>_<varname> structure.
    // N.B. PLEASE USE float TYPE FOR EVERYTHING, UNLESS IT IS LORENTZVECTOR (which is also done in float).
    ana.tx.setBranch<float>("OS4jet_intVar1", -999);
    ana.tx.setBranch<float>("OS4jet_floatVar1", -999);

    LorentzVector LV_OS4jet_LVVar1 = RooUtil::Calc::getLV(34.5, 1.2, 3.123, 0.105); // RooUtil::Calc::getLV() creates 4 vector

    ana.tx.setBranch<LorentzVector>("OS4jet_LVVar1", LV_OS4jet_LVVar1);
}
