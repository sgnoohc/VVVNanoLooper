#ifndef Process_E_h
#define Process_E_h

#include "AnalysisConfig.h"

void Process_E_Event();
void Process_E_Leptons();
void Process_E_Trigger();
void Process_E_FatJets();
void Process_E();
void PostProcess_E();
LV getNeutrinoP4(LV MET, LV lep);

#endif
