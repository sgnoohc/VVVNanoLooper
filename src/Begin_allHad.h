#ifndef Begin_allHad_h
#define Begin_allHad_h

#include "AnalysisConfig.h"

void Begin_allHad();
void Begin_allHad_NanoAOD();
void Begin_allHad_VVVTree();
bool is_baseline_jet(unsigned int i);
bool is_baseline_fatjet(unsigned int i, bool firstPTcut, bool SDcut);

#endif
