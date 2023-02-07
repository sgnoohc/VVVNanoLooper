#ifndef MUONIDHELPER_H
#define MUONIDHELPER_H
#include "../NanoTools/NanoCORE/Nano.h"
#include "../NanoTools/NanoCORE/Base.h"
#include "../interface/XGBoostInterface.h"

namespace MuonIDHelper {

    enum SelectionType{
      kCutbased_Run2 = 0,
      kTopMVA_Run2
    };

    extern SelectionType selection_type;

    bool muonIDscore(int year, unsigned int idx, std::string level, bool isAPV);
    bool muonPassPreselection(unsigned int idx, std::string level);
    void muonLoadMVA(int year, bool isAPV);
    float computeMVAScore(unsigned int idx); 
}

#endif
