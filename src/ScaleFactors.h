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
#include <map>
#include <algorithm>
#include <vector>
#include <unordered_set>

class LeptonScaleFactor {

  public:
    LeptonScaleFactor(std::string const& leptonsfpath="src/scalefactors/LeptonSF.csv");
    ~LeptonScaleFactor();
    float leptonSF(bool isdata, int year, int pdgid, float eta, float pt, int run = -1, int variation=0);

  private:
    std::map<string, TH2F*> hSFlep;
  
};

class FatJetScaleFactor {

  enum class SystematicVariation {
    Nominal = 0,
    Up = 1,
    Down = -1,
  };

  public:
    FatJetScaleFactor(std::string const& leptonsfpath="src/scalefactors/DeepAK8V2_Top_W_SFs.csv");
    ~FatJetScaleFactor();
    float operator()(int year, int WP, float eta, float pt, string period = "X", SystematicVariation = SystematicVariation::Nominal);

  private:
    std::vector<RooUtil::HistMap> histMapsID;
  
};

//might need to reconsider loading csv into cache instead of reading it out for every event.
namespace sf {
  float LeptonSF(int id, int WP, bool iso, int year, string period, bool isdata, int updown, float pt, float nonabseta);
  float LeptonSFtot(int id, int WP, int year, string period, bool isdata, int updown, float pt, float nonabseta);
  float BtagSF(  int WP, int year, bool isdata, int updown, float pt, float eta);//does the nanoAOD weight have only central value or all // don't implement for now
  float FatjetWSF(int WP, int year, bool isdata, int updown, float pt);
}

#endif
