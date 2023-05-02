#include <cassert>
#include <cmath>
#include <limits>

#include "../NanoTools/NanoCORE/Config.h"

#include "ElectronIDHelper.h"

namespace ElectronIDHelper{

     bool electronIDscore(int year, unsigned int idx, std::string level, bool isAPV);

     bool electronPassPreselection(unsigned int idx, std::string level);

     //SelectionType selection_type = "kTopMVA_Run2";

     //std::unordered_map<SelectionType, std::shared_ptr<XGBoostInterface> > mvareader_map;
     std::shared_ptr<XGBoostInterface> mvareader_map;

     void electronLoadMVA(int year, bool isAPV);

     //float computeMVAScore(SelectionType const& type, unsigned int idx);
     float computeMVAScore(unsigned int idx, int year);

     //float convert_BDTscore_raw(float const& mva);

}

using namespace std;

bool ElectronIDHelper::electronIDscore(int year, unsigned int idx, std::string level, bool isAPV){


     bool pass_id;
     // Function to apply preselection cuts for electron
     bool pass_preselection = electronPassPreselection(idx,level);
     // Function to load MVA
     ElectronIDHelper::electronLoadMVA(year,isAPV); 
     // Function to compute MVA using XGBoost
     float score = computeMVAScore(idx,year);    
     //std::cout << "MVA score = " << score << endl;
     //
     //Convert MVA score from raw to Unsquashed value
     //float new_score = convert_BDTscore_raw(old_score);
     //Require electron to pass preselection and cut on the MVA value
     if (!pass_preselection) pass_id = false;
     if (pass_preselection && level=="loose"){
	 pass_id = true;
     }
     if (pass_preselection && level=="tight"){
	 if ( score > 0.81 ) pass_id = true;
	 else pass_id = false;
     }
     // Fill corresponding bits for cuts, then return the int
     
     return pass_id;

}

bool ElectronIDHelper::electronPassPreselection(unsigned int idx, std::string level){

     // These cuts are common for all ID levels of Electron
     if (not (tas::Electron_pt().at(idx) > 10.)) { return false; }
     if (not (fabs(tas::Electron_eta().at(idx)) < 2.5)) { return false; }
     if (not (fabs(tas::Electron_dxy().at(idx)) < 0.05)) { return false; }
     if (not (fabs(tas::Electron_dz().at(idx)) < 0.1)) { return false; }
     if (not (fabs(tas::Electron_sip3d().at(idx)) < 8)) { return false; }
     if (not (tas::Electron_miniPFRelIso_all().at(idx) < 0.4)) { return false; }
     if (not (tas::Electron_lostHits().at(idx) <= 1)) { return false; }
     if ( level == "loose" ) { return true; }

     if ( level == "tight" ){
        if (not tas::Electron_convVeto().at(idx)) { return false; }  
	if (tas::Electron_tightCharge().at(idx) != 2) { return false; }
	return true;
     }
     // Fakable ID requirement -- will add this later
     // if ( level == "fakeable" ) {
     //      //DeepJet requirement for closest jet
     //      //P_T ratio requirement
     //      //EGamma POG MVA WP-loose
     // }
     return false;

}

void ElectronIDHelper::electronLoadMVA(int year, bool isAPV){

     //auto& mvareader_xgb = mvareader_map.find(selection_type)->second;
     auto& mvareader_xgb = mvareader_map;

     std::string fname = "el_TOP";
     std::vector<std::string> varnames;
     float missing_entry_val = std::numeric_limits<float>::quiet_NaN();
     //float missing_entry_val = 0.;
     if (year==2018) fname += "UL18";
     else if (year==2017) fname += "UL17";
     else if (year==2016){ 
	fname += "UL16";
	// Need to add option for APV as well....
	if (isAPV){
	    fname += "APV";
	}
     }
	
     fname += "_XGB.weights.bin";
     //fname = "/home/users/kdownham/Triboson/VVVNanoLooper/src/data/external/TopLeptonMVA/" + fname;
     fname = "src/data/external/TopLeptonMVA/" + fname;
 
     varnames = std::vector<std::string>{
       "pt",
       "eta",
       "jetNDauCharged",
       "miniPFRelIso_chg",
       "miniPFRelIso_diff_all_chg", // = miniPFRelIso_all - miniPFRelIso_chg
       "jetPtRelv2",
       "jetPtRatio", // = 1/(jetRelIso+1)
       "pfRelIso03_all",
       "ak4jet:btagDeepFlavB", // B tagging discriminant score
       "sip3d",
       "log_abs_dxy",
       "log_abs_dz",
     };
     if (year>=2016 && year<=2018) varnames.push_back("mvaFall17V2noIso");
     else if (year==2022) varnames.push_back("mvaNoIso");

     // Now need to construct the mvareader_xgb object (done in XGBoostInterface)
     if ( !mvareader_xgb ){
     	mvareader_xgb = std::make_shared<XGBoostInterface>();
     	mvareader_xgb->build(fname, varnames, missing_entry_val);    
     }
}

float ElectronIDHelper::computeMVAScore(unsigned int idx, int year){

      float res = -999;
      //auto& mvareader_xgb = mvareader_map.find(type)->second;
      auto& mvareader_xgb = mvareader_map;
      if (mvareader_xgb){
        std::unordered_map<std::string, float> input_vars;
        
      auto const& vnames = mvareader_xgb->getVariableNames();
      for (auto const& vname:vnames){
	if (vname=="pt") input_vars[vname] = static_cast<float>(tas::Electron_pt().at(idx));
	else if (vname=="eta") input_vars[vname] = static_cast<float>(tas::Electron_eta().at(idx));
	else if (vname=="miniPFRelIso_diff_all_chg") input_vars[vname] = static_cast<float>(tas::Electron_miniPFRelIso_all().at(idx) - tas::Electron_miniPFRelIso_chg().at(idx));
	else if (vname=="jetPtRatio") input_vars[vname] = static_cast<float>(1./(tas::Electron_jetRelIso().at(idx)+1.));
	else if (vname=="log_abs_dxy") input_vars[vname] = static_cast<float>(std::log(std::abs(tas::Electron_dxy().at(idx))));
	else if (vname=="log_abs_dz") input_vars[vname] = static_cast<float>(std::log(std::abs(tas::Electron_dz().at(idx))));
	else if (vname=="sip3d") input_vars[vname] = static_cast<float>(tas::Electron_sip3d().at(idx));
	else if (vname=="miniPFRelIso_chg") input_vars[vname] = static_cast<float>(tas::Electron_miniPFRelIso_chg().at(idx));		
	else if (vname=="jetPtRelv2") input_vars[vname] = static_cast<float>(tas::Electron_jetPtRelv2().at(idx));
	else if (vname=="jetNDauCharged") input_vars[vname] = static_cast<int>(tas::Electron_jetNDauCharged().at(idx));
	else if (vname=="pfRelIso03_all") input_vars[vname] = static_cast<float>(tas::Electron_pfRelIso03_all().at(idx));
	else if (vname=="ak4jet:btagDeepFlavB"){ input_vars[vname] = float(0);
		 if (tas::Electron_jetIdx().at(idx) == -1) input_vars[vname] = static_cast<float>(0.);
		 if (tas::Electron_jetIdx().at(idx) != -1) input_vars[vname] = static_cast<float>(tas::Jet_btagDeepFlavB().at(tas::Electron_jetIdx().at(idx)));
	}
	if (year>=2016 && year<=2018){
	    if (vname=="mvaFall17V2noIso") input_vars[vname] = static_cast<float>(tas::Electron_mvaFall17V2noIso().at(idx));
	}
	else if (year==2022){
	    //if (vname=="mvaNoIso") input_vars[vname] = static_cast<float>(tas::Electron_mvaNoIso().at(idx));
	}
#define MUON_VARIABLE(TYPE, NAME, DEFVAL) else if (vname==#NAME) input_vars[vname] = static_cast<float>(tas::Electron_NAME().at(idx));
	//MUON_EXTRA_VARIABLES
#undef MUON_VARIABLE
	else{
	  std::cerr << "ElectronIDHelper::computeMVAScore: Input variable name " << vname << " does not match to a corresponding variable" << endl;
	  assert(0);
        }
      }

      mvareader_xgb->eval(input_vars, res);

      }

      return res;     

}

//float ElectronIDHelper::convert_BDTscore_raw(float const& mva){
  //    return 0.5 * std::log((1. + mva)/(1. - mva)); 
//}
