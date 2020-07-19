#ifndef ScaleFactors_h
#define ScaleFactors_h

#include "rooutil.h"
#include "Nano.h"
#include "math.h"
#include "ScaleFactors.h"
#include <algorithm>
#include <fstream>
#include <string>
#include <stdio.h>

//might need to reconsider loading csv into cache instead of reading it out for every event.
namespace sf {
  float LeptonSF(int id, int WP, bool iso, int year, string period, bool isdata, int updown, float pt, float nonabseta);
  float LeptonSFtot(int id, int WP, int year, string period, bool isdata, int updown, float pt, float nonabseta);
  float BtagSF(  int WP, int year, bool isdata, int updown, float pt, float eta);//does the nanoAOD weight have only central value or all // don't implement for now
  float FatjetWSF(int WP, int year, bool isdata, int updown, float pt);
}

#endif
