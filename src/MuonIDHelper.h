#ifndef MUONIDHELPER_H
#define MUONIDHELPER_H
#include "../NanoTools/NanoCORE/Nano.h"
#include "../NanoTools/NanoCORE/Base.h"

namespace MuonIDHelper {

    bool muonIDscore(int year, unsigned int idx, std::string level);
    bool muonPassPreselection(unsigned int idx, std::string level);

}

#endif
