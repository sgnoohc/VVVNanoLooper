#ifndef Begin_Common_h
#define Begin_Common_h

#include "AnalysisConfig.h"
#include <fstream>
#include <string>
#include "../NanoTools/NanoCORE/Tools/goodrun.h"

void Begin_Common();
void Begin_Common_Create_Branches();
void Begin_Common_Determine_Is_EFT();
void Begin_Common_Determine_Is_Postprocessed();
void Begin_Common_Set_Run_List();
void Begin_Common_Set_Config();
void Begin_Common_VVVTree();
void Begin_Common_NanoAOD();
void Begin_Common_Book_NEvent_Histograms();

#endif
