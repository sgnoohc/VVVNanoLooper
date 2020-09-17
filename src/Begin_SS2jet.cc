#include "Begin_SS2jet.h"
bool SS2jet_SR(){
    cout<<"The signal region for SS2jet channel"<<endl;
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");
    //ana.cutflow.addCutToLastActiveCut("Cut_SS2jet_Preselection", [&]() { return ana.tx.getBranch<LorentzVector>("SS2jet_LVVar1").pt() > 25.;}, [&]() { return ana.tx.getBranch<float>("SS2jet_floatVar1"); } );
    // This preselction cut is to get the events with no less than 2 leptons and 1 fatjet
    ana.cutflow.addCutToLastActiveCut("SS2jet_Preselection",
					[&](){
					int nlep=nt.Muon_p4().size()+nt.Electron_p4().size();
					int nfatjet=nt.FatJet_p4().size();

					if(nlep>=2 && nfatjet>=1) return true;
					return false;
					},UNITY);
    //This cut is to get the events with exact two same sign isolated leptons with pt>25.
    ana.cutflow.addCutToLastActiveCut("SS2jet_LeptonCut",
					[&](){
					vector<int>	pdgid=	ana.tx.getBranchLazy<vector<int>	>("SS2jet_lep_pdgid");
					int 		nloose=	ana.tx.getBranchLazy<int		>("SS2jet_nloose");

					if(nloose==2 && pdgid.size()==2 && pdgid.at(0)*pdgid.at(1)>0) return true;
					return false;
					},UNITY);
    //This cut is to get the events with no b-tagged jet
    ana.cutflow.addCutToLastActiveCut("SS2jet_bCut",
					[&](){
					int		nb=	ana.tx.getBranchLazy<int	>("SS2jet_nb_medium");
					if(nb==0) return true;
					return false;
					},UNITY);
    //This cut is to get the events with 1 fat jet
    ana.cutflow.addCutToLastActiveCut("SS2jet_FatJetCut",
					[&](){
					vector<int>     idx=  ana.tx.getBranchLazy<vector<int>        >("SS2jet_fatjet_idx");	
					if(idx.size()==1) return true;
					return false;
					},UNITY);
    return true;
}

bool SS2jet_CR_WZ(){
    cout<<"The WZ control region for SS2jet channel"<<endl;

    return false;
}

bool SS2jet_CR_ttbar(){
    cout<<"The ttbar control region for SS2jet channel"<<endl;
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");
    //ana.cutflow.addCutToLastActiveCut("Cut_SS2jet_Preselection", [&]() { return ana.tx.getBranch<LorentzVector>("SS2jet_LVVar1").pt() > 25.;}, [&]() { return ana.tx.getBranch<float>("SS2jet_floatVar1"); } );
    // This preselction cut is to get the events with no less than 2 leptons and 1 fatjet
    ana.cutflow.addCutToLastActiveCut("SS2jet_Preselection",
					[&](){
					int nlep=nt.Muon_p4().size()+nt.Electron_p4().size();
					int nfatjet=nt.FatJet_p4().size();

					if(nlep>=2 && nfatjet>=1) return true;
					return false;
					},UNITY);
    //This cut is to get the events with exact two same sign isolated leptons with pt>25.
    ana.cutflow.addCutToLastActiveCut("SS2jet_LeptonCut",
					[&](){
					vector<int>	pdgid=	ana.tx.getBranchLazy<vector<int>	>("SS2jet_lep_pdgid");
					int 		nloose=	ana.tx.getBranchLazy<int		>("SS2jet_nloose");

					if(nloose==2 && pdgid.size()==2 && pdgid.at(0)*pdgid.at(1)>0) return true;
					return false;
					},UNITY);
    //This cut is to get the events with at least 1 b-tagged jet
    ana.cutflow.addCutToLastActiveCut("SS2jet_bCut",
					[&](){
					int		nb=	ana.tx.getBranchLazy<int	>("SS2jet_nb_medium");
					if(nb!=0) return true;
					return false;
					},UNITY);
    //This cut is to get the events with at least 1 fat jet
    ana.cutflow.addCutToLastActiveCut("SS2jet_FatJetCut",
					[&](){
					vector<int>     idx=  ana.tx.getBranchLazy<vector<int>        >("SS2jet_fatjet_idx");	
					if(idx.size()==1) return true;
					return false;
					},UNITY);
    return true;
}
 
void Begin_SS2jet()
{
    //==============================================
    // Begin_SS2jet:
    // This function gets called prior to the event looping.
    // This is where one declares variables, histograms, event selections for the category SS2jet.
    //==============================================

    // Create variables used in this category.
    // Please follow the convention of <category>_<varname> structure.
    //ana.tx.createBranch<int>("SS2jet_intVar1");
    //ana.tx.createBranch<float>("SS2jet_floatVar1");
    //ana.tx.createBranch<LorentzVector>("SS2jet_LVVar1");
    
    //raw gen info
    ana.tx.createBranch<vector<int>>		("SS2jet_raw_gen_idx");        // Selected gen-particle idx in NanoAOD
    ana.tx.createBranch<vector<int>>		("SS2jet_raw_gen_mother_idx"); // Selected gen-particle mother idx in NanoAOD
    ana.tx.createBranch<vector<int>>		("SS2jet_raw_gen_mother_id");  // Selected gen-particle mother id in NanoAOD
    ana.tx.createBranch<vector<int>>		("SS2jet_raw_gen_pdgid");      // Selected gen-particle pdgids
    ana.tx.createBranch<vector<LorentzVector>>	("SS2jet_raw_gen_p4s");        // Selected gen-particle p4s 
    ana.tx.createBranch<vector<int>>            ("SS2jet_raw_gen_status");
    ana.tx.createBranch<vector<int>>            ("SS2jet_raw_gen_statusFlags");

    //raw NanoAOD info    
    ana.tx.createBranch<int>			("SS2jet_raw_nlep");
    ana.tx.createBranch<int>			("SS2jet_raw_njet");
    ana.tx.createBranch<int>			("SS2jet_raw_nfatjet");
    //iso track info
    ana.tx.createBranch<int>			("SS2jet_nIsoTrack");	//number of isotrack    
    //lep info for SS1FatJet
    ana.tx.createBranch<int>		 	("SS2jet_nloose");	// number of loose leptons  
    ana.tx.createBranch<vector<LorentzVector>>	("SS2jet_lep_p4");      // Pt sorted selected lepton p4s (electrons and muons together)
    ana.tx.createBranch<vector<int>>          	("SS2jet_lep_idx");     // Pt sorted selected lepton idx (electrons and muons together)
    ana.tx.createBranch<vector<int>>          	("SS2jet_lep_pdgid");   // Pt sorted selected lepton pdgids (electrons and muons together)
    //b-tagging info
    ana.tx.createBranch<int>			("SS2jet_nb_loose");
    ana.tx.createBranch<int>			("SS2jet_nb_medium");
    ana.tx.createBranch<int>			("SS2jet_nb_tight");

    //jet info for SS1FatJet
    ana.tx.createBranch<vector<LorentzVector>>	("SS2jet_jet_p4");            // Pt sorted selected jet p4s
    ana.tx.createBranch<vector<int>>		("SS2jet_jet_idx");           // Pt sorted selected jet idx (To access rest of the jet variables in NanoAOD)
    ana.tx.createBranch<vector<bool>>		("SS2jet_jet_passBloose");    // Pt sorted boolean value jet pass loose b-tagging
    ana.tx.createBranch<vector<bool>>		("SS2jet_jet_passBmedium");   // Pt sorted boolean value jet pass medium b-tagging
    ana.tx.createBranch<vector<bool>>		("SS2jet_jet_passBtight");    // Pt sorted boolean value jet pass medium b-tagging
    //fatjet info for SS1FatJet
    ana.tx.createBranch<vector<LorentzVector>>	("SS2jet_fatjet_p4");            // Pt sorted selected fatjet p4s
    ana.tx.createBranch<vector<int>>          	("SS2jet_fatjet_idx");           // Pt sorted selected fatjet idx (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_msoftdrop");     // Pt sorted selected fatjet msoftdrop (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_deepMD_W");      // Pt sorted selected fatjet FatJet_deepTagMD_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_deep_W");        // Pt sorted selected fatjet FatJet_deepTag_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_deepMD_Z");      // Pt sorted selected fatjet FatJet_deepTagMD_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_deep_Z");        // Pt sorted selected fatjet FatJet_deepTag_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_deepMD_T");      // Pt sorted selected fatjet FatJet_deepTagMD_TvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>       	("SS2jet_fatjet_deep_T");        // Pt sorted selected fatjet FatJet_deepTag_TvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_deepMD_bb");     // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_tau3");          // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_tau2");          // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_tau1");          // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_tau32");         // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_tau21");         // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_subjet0_pt");    // Pt sorted selected fatjet subjet p4 0 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_subjet0_eta");   // Pt sorted selected fatjet subjet p4 0 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_subjet0_phi");   // Pt sorted selected fatjet subjet p4 0 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_subjet0_mass");  // Pt sorted selected fatjet subjet p4 0 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_subjet1_pt");    // Pt sorted selected fatjet subjet p4 1 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_subjet1_eta");   // Pt sorted selected fatjet subjet p4 2 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_subjet1_phi");   // Pt sorted selected fatjet subjet p4 3 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<float>>        	("SS2jet_fatjet_subjet1_mass");  // Pt sorted selected fatjet subjet p4 4 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.createBranch<vector<LorentzVector>>	("SS2jet_fatjet_subjet0_p4");    // Pt sorted selected fatjet p4s
    ana.tx.createBranch<vector<LorentzVector>>	("SS2jet_fatjet_subjet1_p4");    // Pt sorted selected fatjet p4s

    // Define selections
    bool status=false;
    switch(ana.region){
	case 0:status=SS2jet_SR();break;
	case 1:status=SS2jet_CR_WZ();break;
	case 2:status=SS2jet_CR_ttbar();break;
    }
    if(!status){
	std::cout<<"ERROR:This region is not set yet"<<endl;
	exit(1);
    }
    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    RooUtil::Histograms hists_SS2jet;
    //hists_SS2jet.addHistogram("h_SS2jet_intVar1", 10, 0, 10, [&]() { return ana.tx.getBranch<int>("SS2jet_intVar1"); } );
    //hists_SS2jet.addHistogram("h_SS2jet_floatVar1", 180, 0, 500, [&]() { return ana.tx.getBranch<float>("SS2jet_floatVar1"); } );
    //hists_SS2jet.addHistogram("h_SS2jet_LVVar1_Pt", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("SS2jet_LVVar1").pt(); } );
    // Now book cutflow histogram (could be commented out if user does not want.)
    // N.B. Cutflow histogramming can be CPU consuming.
    ana.cutflow.bookCutflows();
    //ana.cutflow.bookHistogramsForCutAndBelow(hists_SS2jet, "SS2jet_GenSS1FatJet");

    // Book histograms to cuts that user wants for this category.
    //ana.cutflow.bookHistogramsForCut(hists_SS2jet, "Cut_SS2jet_Preselection");

}
