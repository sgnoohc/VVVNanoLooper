#ifndef Begin_allHad_h
#define Begin_allHad_h

#include "AnalysisConfig.h"

void Begin_allHad();
void Begin_allHad_NanoAOD();
void Begin_1L_NanoAOD();
void Begin_allHad_VVVTree();
void Begin_1L_VVVTree();
bool is_baseline_jet(unsigned int i);
bool is_baseline_fatjet(unsigned int i, bool firstPTcut, bool SDcut);
float getMT();
float get_weight();
#endif
