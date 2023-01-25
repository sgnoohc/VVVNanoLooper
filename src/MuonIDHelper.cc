#include <cassert>
#include <cmath>
#include <limits>

#include "../NanoTools/NanoCORE/Config.h"

#include "MuonIDHelper.h"

namespace MuonIDHelper{

     bool muonIDscore(int year, unsigned int idx, std::string level);

     bool muonPassPreselection(unsigned int idx, std::string level);

}

using namespace std;

bool MuonIDHelper::muonIDscore(int year, unsigned int idx, std::string level){

     // Function to apply preselection cuts for muon
     bool pass_preselection = muonPassPreselection(idx,level);
     // Function to load MVA
     
     // Function to compute MVA using XGBoost
     
     // Fill corresponding bits for cuts, then return the int
     
     return pass_preselection;

}

bool MuonIDHelper::muonPassPreselection(unsigned int idx, std::string level){

     // These cuts are common for all ID levels of Muon
     if (tas::Muon_pt().at(idx) < 10.) { return false; }
     if (fabs(tas::Muon_eta().at(idx)) > 2.4) { return false; }
     if (fabs(tas::Muon_dxy().at(idx)) > 0.05) { return false; }
     if (fabs(tas::Muon_dz().at(idx)) > 0.1) { return false; }
     if (fabs(tas::Muon_sip3d().at(idx)) >= 8) { return false; }
     if (tas::Muon_miniPFRelIso_all().at(idx) > 0.4) { return false; }
     if (!tas::Muon_mediumId().at(idx)) { return false; }
     
     // Loose ID requirement 
     if ( level == "loose" || level == "tight" ) { return true; }

     // Fakable ID requirement -- will add this later
     // if ( level == "fakeable" ) {
     //      //DeepJet requirement for closest jet
     //      //P_T ratio requirement
     // }

}
