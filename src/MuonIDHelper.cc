#include <cassert>
#include <cmath>
#include <limits>

#include "../NanoTools/NanoCORE/Config.h"

#include "MuonIDHelper.h"

namespace MuonIDHelper{

     bool muonIDscore(int year, unsigned int idx, std::string level, bool isAPV);

     bool muonPassPreselection(unsigned int idx, std::string level);

     //SelectionType selection_type = "kTopMVA_Run2";

     //std::unordered_map<SelectionType, std::shared_ptr<XGBoostInterface> > mvareader_map;
     std::shared_ptr<XGBoostInterface> mvareader_map;

     void muonLoadMVA(int year, bool isAPV);

     //float computeMVAScore(SelectionType const& type, unsigned int idx);
     float computeMVAScore(unsigned int idx);

}

using namespace std;

bool MuonIDHelper::muonIDscore(int year, unsigned int idx, std::string level, bool isAPV){

     bool pass_id;
     // Function to apply preselection cuts for muon
     bool pass_preselection = muonPassPreselection(idx,level);
     // Function to load MVA
     MuonIDHelper::muonLoadMVA(year,isAPV); 
     // Function to compute MVA using XGBoost
     float score = computeMVAScore(idx);    
     //std::cout << "MVA score = " << score << endl;
     //Require muon to pass preselection and cut on the MVA value
     if (!pass_preselection) pass_id = false;
     if (pass_preselection && level=="loose"){
	 pass_id = true;
     }
     if (pass_preselection && level=="tight"){
	 if ( score > 0.64 ) pass_id = true;
	 else pass_id = false;
     }
     // Fill corresponding bits for cuts, then return the int
     
     if (tas::event() == 1847002) std::cout << "MuonIDHelper Debug 5" << std::endl;
     
     return pass_id;

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
     return false;

}

void MuonIDHelper::muonLoadMVA(int year, bool isAPV){

     //auto& mvareader_xgb = mvareader_map.find(selection_type)->second;
     auto& mvareader_xgb = mvareader_map;

     std::string fname = "mu_TOP";
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
       "segmentComp",
     };

     // Now need to construct the mvareader_xgb object (done in XGBoostInterface)
     if ( !mvareader_xgb ){
     	mvareader_xgb = std::make_shared<XGBoostInterface>();
     	mvareader_xgb->build(fname, varnames, missing_entry_val);    
     }

}

float MuonIDHelper::computeMVAScore(unsigned int idx){

      float res = -999;
      //auto& mvareader_xgb = mvareader_map.find(type)->second;
      auto& mvareader_xgb = mvareader_map;
      if (mvareader_xgb){
        std::unordered_map<std::string, float> input_vars;
        
	// Need to implement this AK4JetObject class
	//
        //AK4JetObject* mother = nullptr;
	//for (auto const& mom:part.getMothers()){
	//  mother = dynamic_cast<AK4JetObject*>(mom);
	//  if (mother) break;
	//}

      

      auto const& vnames = mvareader_xgb->getVariableNames();
      for (auto const& vname:vnames){
	if (vname=="pt") input_vars[vname] = static_cast<float>(tas::Muon_pt().at(idx));
	else if (vname=="eta") input_vars[vname] = static_cast<float>(tas::Muon_eta().at(idx));
	else if (vname=="miniPFRelIso_diff_all_chg") input_vars[vname] = static_cast<float>(tas::Muon_miniPFRelIso_all().at(idx) - tas::Muon_miniPFRelIso_chg().at(idx));
	else if (vname=="jetPtRatio") input_vars[vname] = static_cast<float>(1./(tas::Muon_jetRelIso().at(idx)+1.));
	else if (vname=="log_abs_dxy") input_vars[vname] = static_cast<float>(std::log(std::abs(tas::Muon_dxy().at(idx))));
	else if (vname=="log_abs_dz") input_vars[vname] = static_cast<float>(std::log(std::abs(tas::Muon_dz().at(idx))));
	else if (vname=="sip3d") input_vars[vname] = static_cast<float>(tas::Muon_sip3d().at(idx));
	else if (vname=="segmentComp") input_vars[vname] = static_cast<float>(tas::Muon_segmentComp().at(idx));
	else if (vname=="miniPFRelIso_chg") input_vars[vname] = static_cast<float>(tas::Muon_miniPFRelIso_chg().at(idx));		
	else if (vname=="jetPtRelv2") input_vars[vname] = static_cast<float>(tas::Muon_jetPtRelv2().at(idx));
	else if (vname=="jetNDauCharged") input_vars[vname] = static_cast<int>(tas::Muon_jetNDauCharged().at(idx));
	else if (vname=="pfRelIso03_all") input_vars[vname] = static_cast<float>(tas::Muon_pfRelIso03_all().at(idx));
	//else if (vname="ak4jet:btagDeepFlavB") input_vars[vname] = (mother ? static_cast<float>(mother->xtras.btagDeepFlavB) : float(0));
	else if (vname=="ak4jet:btagDeepFlavB"){
		 if (tas::Muon_jetIdx().at(idx) == -1) input_vars[vname] = static_cast<float>(0.);
		 //std::cout << "Number of jets = " << tas::nJet() << std::endl;
		 //std::cout << "Muon jet index = " << tas::Muon_jetIdx().at(idx) << std::endl;
		 //if (tas::Muon_jetIdx().at(idx) != -1) input_vars[vname] = static_cast<float>(tas::Jet_btagDeepFlavB().at(tas::Muon_jetIdx().at(idx)));
	}
#define MUON_VARIABLE(TYPE, NAME, DEFVAL) else if (vname==#NAME) input_vars[vname] = static_cast<float>(tas::Muon_NAME().at(idx));
	//MUON_EXTRA_VARIABLES
#undef MUON_VARIABLE
	else{
	  std::cerr << "MuonIDHelper::computeMVAScore: Input variable name " << vname << " does not match to a corresponding variable" << endl;
	  assert(0);
        }
      }

      mvareader_xgb->eval(input_vars, res);

      }

      return res;     

}

