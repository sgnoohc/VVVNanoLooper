#ifndef ELECTRONIDHELPER_H
#define ELECTRONIDHELPER_H
#include "../NanoTools/NanoCORE/Nano.h"
#include "../NanoTools/NanoCORE/Base.h"
#include "../interface/XGBoostInterface.h"

namespace ElectronIDHelper {

    enum SelectionType{
      kCutbased_Run2 = 0,
      kTopMVA_Run2
    };

    extern SelectionType selection_type;

    bool electronIDscore(int year, unsigned int idx, std::string level, bool isAPV);
    bool electronPassPreselection(unsigned int idx, std::string level);
    void electronLoadMVA(int year, bool isAPV);
    float computeMVAScore(unsigned int idx, int year); 
    //float convert_BDTscore_raw(float const& mva);
}

#endif
