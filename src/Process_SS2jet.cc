#include "Process_SS2jet.h"

void Process_SS2jet(){
    //==============================================
    // Process_SS2jet:
    // This function gets called during the event looping.
    // This is where one sets the variables used for the category SS2jet.
    //==============================================

    // Set variables used in this category.
    // If histograms are booked with these variables the histograms will be filled automatically.
    // Please follow the convention of <category>_<varname> structure.
    //ana.tx.setBranch<int>("SS2jet_intVar1", -999);
    //ana.tx.setBranch<float>("SS2jet_floatVar1", -999);

    // Example of reading from Nano
    // std::vector<LorentzVector> electron_p4s = nt.Electron_p4(); // nt is a global variable that accesses NanoAOD
    // std::vector<float> electron_mvaTTH = nt.Electron_mvaTTH(); // electron ttH MVA scores from NanoAOD
    // Semi-complete list of NanoAOD for 102X can be found here: https://cms-nanoaod-integration.web.cern.ch/integration/master-102X/mc102X_doc.html
    // Also consult here: https://github.com/cmstas/NanoTools/blob/d641a6d6c1aa9ecc8094a1af73d5e1bd7d6502ab/NanoCORE/Nano.h#L4875 (if new variables are added they may show up in master)

    if(!nt.isData()){
	for(unsigned int igen=0;igen<nt.GenPart_p4().size();igen++){
		ana.tx.pushbackToBranch<int>		("SS2jet_raw_gen_idx", igen);                                                            // Selected gen-particle idx in NanoAOD
		ana.tx.pushbackToBranch<int>		("SS2jet_raw_gen_mother_idx", nt.GenPart_genPartIdxMother()[igen]);                      // Selected gen-particle mother idx in NanoAOD
		ana.tx.pushbackToBranch<int>		("SS2jet_raw_gen_mother_id",  nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[igen] ]); // Selected gen-particle mother idx in NanoAOD
		ana.tx.pushbackToBranch<int>		("SS2jet_raw_gen_pdgid", nt.GenPart_pdgId()[igen]);                                      // Selected gen-particle pdgids
		ana.tx.pushbackToBranch<LorentzVector>	("SS2jet_raw_gen_p4s", nt.GenPart_p4()[igen]);                                           // Selected gen-particle
		ana.tx.pushbackToBranch<int>	  	("SS2jet_raw_gen_status",nt.GenPart_status()[igen]);
		ana.tx.pushbackToBranch<int>		("SS2jet_raw_gen_statusFlags",nt.GenPart_statusFlags()[igen]);
	}
    }
    //LorentzVector LV_SS2jet_LVVar1 = RooUtil::Calc::getLV(34.5, 1.2, 3.123, 0.105); // RooUtil::Calc::getLV() creates 4 vector
    //ana.tx.setBranch<LorentzVector>("SS2jet_LVVar1", LV_SS2jet_LVVar1);
}

	

void PostProcess_SS2jet(){
    if (ana.cutflow.getCut("SS2jet_FatJetCut").pass){
                   ana.tx.fill(); 
    }
}
  
