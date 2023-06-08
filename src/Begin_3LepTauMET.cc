//==============================================
// Begin 3 Lepton + Hadronic Tau selection
// Preselection
//==============================================
// Author:
//	Keegan Downham, UCSB
//==============================================

#include "Begin_3LepTauMET.h"
#include "lester_mt2_bisect.h"
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iostream>

namespace threeleptau{
    std::map<TString, float> scaleLumis;
    std::map<TString, float> intLumis;
}

void Begin_3LepTauMET()
{

    // Category flag
    Begin_3LepTauMET_Create_Branches();

    // Parse cross section
    Begin_3LepTauMET_Parse_Scale1fbs();

    // Design the 3 lep + tau_h selection
    Begin_3LepTauMET_NanoAOD();

    // Add different channels
    ana.cutflow.getCut("Cut_3LepTauMET_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_3LepTauMET_etauChannel", [&]() { bool pass = std::abs(ana.tx.getBranch<int>("Var_3LepTauMET_other_lep_pdgid_0")) == 11; ana.tx.setBranch<bool>("Cut_3LepTauMET_etauChannel", pass); return pass; }, UNITY);
    ana.cutflow.getCut("Cut_3LepTauMET_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_3LepTauMET_mutauChannel", [&]() { bool pass = std::abs(ana.tx.getBranch<int>("Var_3LepTauMET_other_lep_pdgid_0")) == 13; ana.tx.setBranch<bool>("Cut_3LepTauMET_mutauChannel", pass); return pass; }, UNITY);

    // Create histograms used in this category
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_pt_0", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("Var_3LepTauMET_Zcand_lep_p4_0").pt(); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_pt_1", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("Var_3LepTauMET_Zcand_lep_p4_1").pt(); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_sip3d_0", 180, 0, 10, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_sip3d")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_0")]); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_sip3d_1", 180, 0, 10, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_sip3d")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_1")]); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_sip3d_max", 180, 0, 10, [&]() { return std::max(fabs(ana.tx.getBranch<vector<float>>("Common_lep_sip3d")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_0")]), fabs(ana.tx.getBranch<vector<float>>("Common_lep_sip3d")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_1")])); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_ip3d_0", 180, 0, 0.02, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_ip3d")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_0")]); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_ip3d_1", 180, 0, 0.02, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_ip3d")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_1")]); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_ip3d_max", 180, 0, 0.02, [&]() { return std::max(fabs(ana.tx.getBranch<vector<float>>("Common_lep_ip3d")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_0")]), fabs(ana.tx.getBranch<vector<float>>("Common_lep_ip3d")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_1")])); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_dxy_max", 180, 0, 0.02, [&]() { return std::max(fabs(ana.tx.getBranch<vector<float>>("Common_lep_dxy")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_0")]), fabs(ana.tx.getBranch<vector<float>>("Common_lep_dxy")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_1")])); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_dz_max", 180, 0, 0.05, [&]() { return std::max(fabs(ana.tx.getBranch<vector<float>>("Common_lep_dz")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_0")]), fabs(ana.tx.getBranch<vector<float>>("Common_lep_dz")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_1")])); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_mll", 180, 0, 150, [&]() { return ana.tx.getBranch<float>("Var_3LepTauMET_Zcand_mll"); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_dphi", 180, 0, 3.1416, [&]() { return fabs(RooUtil::Calc::DeltaPhi(ana.tx.getBranch<LorentzVector>("Var_3LepTauMET_Zcand_lep_p4_0"), ana.tx.getBranch<LorentzVector>("Var_3LepTauMET_Zcand_lep_p4_1"))); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_pt", 180, 0, 150, [&]() { return (ana.tx.getBranch<LorentzVector>("Var_3LepTauMET_Zcand_lep_p4_0") + ana.tx.getBranch<LorentzVector>("Var_3LepTauMET_Zcand_lep_p4_1")).pt(); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_mll_wide", 180, 0, 350, [&]() { return ana.tx.getBranch<float>("Var_3LepTauMET_Zcand_mll"); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_mll_zoom", 180, 70, 110, [&]() { return ana.tx.getBranch<float>("Var_3LepTauMET_Zcand_mll"); } );
    ana.histograms.addHistogram("h_3LepTauMET_Zcand_leptight", 4, 0, 4, [&]() { return 2 * ana.tx.getBranch<vector<int>>("Common_lep_tight")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_0")] + ana.tx.getBranch<vector<int>>("Common_lep_tight")[ana.tx.getBranch<int>("Var_3LepTauMET_Zcand_lep_idx_1")]; } );
    ana.histograms.addHistogram("h_3LepTauMET_other_pt_0", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("Var_3LepTauMET_other_lep_p4_0").pt(); } );
    ana.histograms.addHistogram("h_3LepTauMET_tau_pt_0", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("Var_3LepTauMET_tau_p4_0").pt(); } );
    ana.histograms.addHistogram("h_3LepTauMET_other_sip3d_0", 180, 0, 10, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_sip3d")[ana.tx.getBranch<int>("Var_3LepTauMET_other_lep_idx_0")]); } );
    ana.histograms.addHistogram("h_3LepTauMET_other_ip3d_0", 180, 0, 0.02, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_ip3d")[ana.tx.getBranch<int>("Var_3LepTauMET_other_lep_idx_0")]); } );
    ana.histograms.addHistogram("h_3LepTauMET_other_dxy_0",180,0,0.2, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_dxy")[ana.tx.getBranch<int>("Var_3LepTauMET_other_lep_idx_0")]); } );
    ana.histograms.addHistogram("h_3LepTauMET_other_dz_0",180,0,0.05, [&]() { return fabs(ana.tx.getBranch<vector<float>>("Common_lep_dz")[ana.tx.getBranch<int>("Var_3LepTauMET_other_lep_idx_0")]); } );
    ana.histograms.addHistogram("h_3LepTauMET_other_mll",180, 0, 150, [&]() { return ana.tx.getBranch<float>("Var_3LepTauMET_other_mll"); } );
    ana.histograms.addHistogram("h_3LepTauMET_met", 180, 0, 450, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4").pt(); } );
    ana.histograms.addHistogram("h_3LepTauMET_met_phi", 180, -3.1416, 3.1416, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4").phi(); } );
    ana.histograms.addHistogram("h_3LepTauMET_met_MET", 180, 0, 450, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4_MET").pt(); } );
    ana.histograms.addHistogram("h_3LepTauMET_met_MET_phi", 180, -3.1416, 3.1416, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4_MET").phi(); } );
    ana.histograms.addHistogram("h_3LepTauMET_met_PuppiMET", 180, 0, 450, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4_PuppiMET").pt(); } );
    ana.histograms.addHistogram("h_3LepTauMET_met_PuppiMET_phi", 180, -3.1416, 3.1416, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4_PuppiMET").phi(); } );
    ana.histograms.addHistogram("h_3LepTauMET_nb_loose", 8, 0, 8, [&]() { return ana.tx.getBranch<int>("Common_nb_loose"); } );
    ana.histograms.addHistogram("h_3LepTauMET_nb_medium", 8, 0, 8, [&]() { return ana.tx.getBranch<int>("Common_nb_medium"); } );
    ana.histograms.addHistogram("h_3LepTauMET_nb_tight", 8, 0, 8, [&]() { return ana.tx.getBranch<int>("Common_nb_tight"); } );
    ana.histograms.addHistogram("h_3LepTauMET_njet", 8, 0, 8, [&]() { return ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4").size(); } );
    ana.histograms.addHistogram("h_3LepTauMET_nfatjet", 8, 0, 8, [&]() { return ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size(); } );
    ana.histograms.addHistogram("h_3LepTauMET_mt2", 180, 0, 100, [&]() { return ana.tx.getBranch<float>("Var_3LepTauMET_mt2"); } );   
    ana.histograms.addHistogram("h_3LepTauMET_mt2_PuppiMET", 180, 0, 100, [&]() { return ana.tx.getBranch<float>("Var_3LepTauMET_mt2_PuppiMET"); } );
}

void Begin_3LepTauMET_NanoAOD()
{
    //===================================
    // Begin_3LepTau
    // This function gets called prior to the event looping
    // This is where one declares variables, histograms, event selections for the category 3LepTauMET.
    //===================================
    
    // Create variables used in this category.
    // Please follow the convention of <category>_<varname> structure.
    
    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");

    // Select 3 leptons + hadronic taus
    ana.cutflow.addCutToLastActiveCut("Cut_3LepTauMET_Has3LeptonPlusTau",
	    [&]()
	    {
		// Need 3 leptons passing common selection criteria, plus at least one hadronic tau
		if (not (ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size() == 3 && ana.tx.getBranchLazy<vector<int>>("Common_tau_idxs").size() > 0)){
		    ana.tx.setBranch<bool>("Cut_3LepTauMET_Has3LeptonPlusTau", false);
		    return false;
		}
		ana.tx.setBranch<bool>("Cut_3LepTauMET_Has3LeptonPlusTau", true);
		return true;
	    }, UNITY);

    // Select Z candidate
    int index1 = 0;
    int index2 = 0;
    ana.cutflow.addCutToLastActiveCut("Cut_3LepTauMET_HasZCandidate",
            [&]()
            {

                auto [ has_sfos, idx1, idx2, mll ] = RooUtil::Calc::pickZcandidateIdxs(
                        ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid"),
                        ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4"));
                index1 = idx1;
                index2 = idx2;
                if (not (has_sfos)){ 
		    ana.tx.setBranch<bool>("Cut_3LepTauMET_HasZCandidate", false);
		    return false;
		}
                if (not (abs(mll - 91.1876) < 10.)){ 
		    ana.tx.setBranch<bool>("Cut_3LepTauMET_HasZCandidate", false);
		    return false;
		}

		// If found a Z then set the variables
		ana.tx.setBranch<int>          ("Var_3LepTauMET_Zcand_lep_idx_0"   , idx1);
                ana.tx.setBranch<int>          ("Var_3LepTauMET_Zcand_lep_pdgid_0" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[idx1]);
                ana.tx.setBranch<LorentzVector>("Var_3LepTauMET_Zcand_lep_p4_0"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[idx1]);
	 	ana.tx.setBranch<int>          ("Var_3LepTauMET_Zcand_lep_idx_1"   , idx2);
                ana.tx.setBranch<int>          ("Var_3LepTauMET_Zcand_lep_pdgid_1" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[idx2]);
                ana.tx.setBranch<LorentzVector>("Var_3LepTauMET_Zcand_lep_p4_1"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[idx2]);

                ana.tx.setBranch<float>("Var_3LepTauMET_Zcand_mll", mll);

		// The leading lepton has to pass 25 GeV
		if (not (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[idx1].pt() > 25.)){ 
		    ana.tx.setBranch<bool>("Cut_3LepTauMET_HasZCandidate", false);
		    return false;
		}

		ana.tx.setBranch<bool>("Cut_3LepTauMET_HasZCandidate", true);
		return true;	
	    }, UNITY);

    ana.cutflow.addCutToLastActiveCut("Cut_3LepTauMET_OtherLeptons",
	    [&]()
	    {
		int idx;
		int idx_coll;
		std::vector<int> other_lep_idx;
		int other_lep_pdgid;
		int other_lep_ID;
		LorentzVector other_lep_p4;

		// Loop over the indices and pdgid and if it is a Z candidate lepton then skip
		for (unsigned int ilep = 0; ilep < ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size(); ++ilep)
                {
                    int idx_coll = ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[ilep];
                    int idx = ilep;
                    int pdgid = ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[ilep];
                    if (idx == ana.tx.getBranchLazy<int>("Var_3LepTauMET_Zcand_lep_idx_0") and pdgid == ana.tx.getBranchLazy<int>("Var_3LepTauMET_Zcand_lep_pdgid_0")) continue;
                    if (idx == ana.tx.getBranchLazy<int>("Var_3LepTauMET_Zcand_lep_idx_1") and pdgid == ana.tx.getBranchLazy<int>("Var_3LepTauMET_Zcand_lep_pdgid_1")) continue;
                    idx             = ilep;
                    idx_coll        = idx_coll;
                    other_lep_idx.push_back(ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[ilep]);
                    other_lep_pdgid = ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[ilep];
                    other_lep_p4    = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[ilep];

                }

		// Sanity check that it must be only 1 additional lepton
		if (other_lep_idx.size() != 1)
		    RooUtil::error("You should have 3 light leptons!", __FILE__);

		LorentzVector leading_tau_p4 = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_tau_p4")[0];

		// Set the idxs 
		ana.tx.setBranch<int>	       ("Var_3LepTauMET_other_lep_idx_0"   , idx);
		ana.tx.setBranch<int>	       ("Var_3LepTauMET_other_lep_pdgid_0" , other_lep_pdgid);
		ana.tx.setBranch<LorentzVector>("Var_3LepTauMET_other_lep_p4_0"	   , other_lep_p4);
		ana.tx.setBranch<int>	       ("Var_3LepTauMET_tau_idx_0"	   , ana.tx.getBranchLazy<vector<int>>("Common_tau_idxs")[0]);
		ana.tx.setBranch<int>	       ("Var_3LepTauMET_tau_pdgid_0"	   , 15*ana.tx.getBranchLazy<vector<int>>("Common_tau_charge")[0]);
		ana.tx.setBranch<LorentzVector>("Var_3LepTauMET_tau_p4_0"	   , leading_tau_p4);

		// Make sure that the tau and the other W candidate lepton have opposite charge
		if ( other_lep_pdgid * ana.tx.getBranchLazy<vector<int>>("Common_tau_charge")[0] < 0 ){
		     ana.tx.setBranch<bool>("Cut_3LepTauMET_OtherLeptons", false);	     
		     return false;
		}

		// Set the values for the Tau IDs
		ana.tx.setBranch<int>	       ("Var_3LepTauMET_tau_idVSe_0"	   , ana.tx.getBranchLazy<vector<int>>("Common_tau_idVSe")[0]);
		ana.tx.setBranch<int>          ("Var_3LepTauMET_tau_idVSmu_0"      , ana.tx.getBranchLazy<vector<int>>("Common_tau_idVSmu")[0]);
		ana.tx.setBranch<int>          ("Var_3LepTauMET_tau_idVSjet_0"     , ana.tx.getBranchLazy<vector<int>>("Common_tau_idVSjet")[0]);

		ana.tx.setBranch<float>("Var_3LepTauMET_other_mll", (other_lep_p4 + leading_tau_p4).mass());
				
		int W_lep_ID_0;
		int Z_lep_ID_0;
		int Z_lep_ID_1;

		// Perform another loop to match common_lep_IDs
		for (unsigned int i = 0; i < ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size(); ++i) // Loop over common lep indices
		{
		     if ( std::abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[i]) == 13 ){
			  for (int mu = 0; mu < nt.nMuon(); mu++){
			       if ( mu == ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[i] and nt.Muon_pdgId()[mu] == ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[i] ){
				    if ( idx_coll == i ){
					 W_lep_ID_0 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];
				    }
				    if ( ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[index1] == i ){
                                         Z_lep_ID_0 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];
                                    }
                                    if ( ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[index2] == i ){
                                         Z_lep_ID_1 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];
                                    }
			       }
			  }
		     }
		     // Do the same for electrons
		     if ( std::abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[i]) == 11 ){
                          for (int el = 0; el < nt.nElectron(); el++){
                               if ( el == ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[i] and nt.Electron_pdgId()[el] == ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[i] ){
                                    if ( idx_coll == i ){
                                         W_lep_ID_0 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];
                                    }
                                    if ( ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[index1] == i ){
                                         Z_lep_ID_0 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];
                                    }
                                    if ( ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[index2] == i ){
                                         Z_lep_ID_1 = ana.tx.getBranchLazy<vector<int>>("Common_lep_ID")[i];
                                    }

                               }
                          }
                     }    
		}

		ana.tx.setBranch<int>	("Var_3LepTauMET_Zcand_lep_ID_0" , Z_lep_ID_0 );
		ana.tx.setBranch<int>	("Var_3LepTauMET_Zcand_lep_ID_1" , Z_lep_ID_1 );
		ana.tx.setBranch<int>	("Var_3LepTauMET_other_lep_ID_0" , W_lep_ID_0 );

	        ana.tx.setBranch<bool>("Cut_3LepTauMET_OtherLeptons", true);

		return true;
	    }, UNITY);

     // Apply min M_ll > 12 GeV selection on any opposite sign pair
     ana.cutflow.addCutToLastActiveCut("Cut_3LepTauMET_VetoLowMassResonance",
	     [&]()
	     {
		 // Loop over every pair of opposite sign charged lepton pairs and require that they have > 12 GeV mass
		for (unsigned int ilep = 0; ilep < ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size(); ++ilep)
                {
                    const LorentzVector& ip4 = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[ilep];
                    const int& ipdgid = ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[ilep];
                    for (unsigned int jlep = ilep + 1; jlep < ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size(); ++jlep)
                    {
                        const LorentzVector& jp4 = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[jlep];
                        const int& jpdgid = ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[jlep];

                        if (ipdgid * jpdgid < 0) 
                        {
                            if (not ((ip4 + jp4).mass() > 12)){
                                ana.tx.setBranch<bool>("Cut_3LepTauMET_VetoLowMassResonance", false);
				return false;
			    }
                        }
                    }
                }
	
		ana.tx.setBranch<bool>("Cut_3LepTauMET_VetoLowMassResonance", true);	
		return true;

	     }, UNITY);

     // Compute MT2 variable
     ana.cutflow.addCutToLastActiveCut("Cut_3LepTauMET_Compute_Variables",
            [&]()
            {
                ana.tx.setBranch<float>("Var_3LepTauMET_mt2", Begin_3LepTauMET_MT2());
		ana.tx.setBranch<float>("Var_3LepTauMET_mt2_PuppiMET", Begin_3LepTauMET_MT2_PuppiMET());
                return true;
            },
            UNITY); 

     // Compute weight
     ana.cutflow.addCutToLastActiveCut("Cut_3LepTauMET_Compute_ScaleLumi",
	    [&]()
	    {
		if (not ana.tx.getBranch<int>("Common_isData"))
		{
		    TString key = gSystem->DirName(ana.looper.getCurrentFileName());
		    ana.tx.setBranch<float>("Var_3LepTauMET_scaleLumi", threeleptau::scaleLumis.at(key));
		    ana.tx.setBranch<float>("Var_3LepTauMET_intLumi", threeleptau::intLumis.at(key));     
		}
		else
		{
		    ana.tx.setBranch<float>("Var_3LepTauMET_scaleLumi", 1);
		}
		return true;
		
	    },
	    UNITY);

     // Create a middle point of preselection
     ana.cutflow.addCutToLastActiveCut("Cut_3LepTauMET_Preselection", [&]() { ana.tx.setBranch<bool>("Cut_3LepTauMET_Preselection", true); return true; }, UNITY); // This "cut" does not do anything. It works as a middle point

}

void Begin_3LepTauMET_Create_Branches()
{
    // Categories
    ana.tx.createBranch<bool>	      ("Cut_3LepTauMET_Preselection");
    ana.tx.createBranch<bool>	      ("Cut_3LepTauMET_etauChannel");
    ana.tx.createBranch<bool>	      ("Cut_3LepTauMET_mutauChannel");
    ana.tx.createBranch<bool>	      ("Cut_3LepTauMET_Has3LeptonPlusTau");
    ana.tx.createBranch<bool>	      ("Cut_3LepTauMET_HasZCandidate");
    ana.tx.createBranch<bool>	      ("Cut_3LepTauMET_OtherLeptons");
    ana.tx.createBranch<bool>	      ("Cut_3LepTauMET_VetoLowMassResonance");

    // Z candidate idxs, pdgid, and 4 vectors
    // The Z candidate is the SFOS pair that is closest to the Z mass
    ana.tx.createBranch<int>          ("Var_3LepTauMET_Zcand_lep_idx_0");     // idx in NanoAOD 
    ana.tx.createBranch<int>          ("Var_3LepTauMET_Zcand_lep_pdgid_0");   // pdgid of leading Z candidate lepton
    ana.tx.createBranch<LorentzVector>("Var_3LepTauMET_Zcand_lep_p4_0");	      // p4 of the leading Z candidate lepton
    ana.tx.createBranch<int>          ("Var_3LepTauMET_Zcand_lep_idx_1");     // idx in NanoAOD
    ana.tx.createBranch<int>          ("Var_3LepTauMET_Zcand_lep_pdgid_1");   // pdgid of subleading Z candidate lepton
    ana.tx.createBranch<LorentzVector>("Var_3LepTauMET_Zcand_lep_p4_1");          // p4 of the subleading Z candidate lepton
    ana.tx.createBranch<float>        ("Var_3LepTauMET_Zcand_mll");	      // Invariant mass of the Z candidate lepton pair
    ana.tx.createBranch<int>          ("Var_3LepTauMET_Zcand_lep_ID_0");      // ID of leading Z candidate lepton
    ana.tx.createBranch<int>          ("Var_3LepTauMET_Zcand_lep_ID_1");      // ID of subleading Z candidate lepton

    // The other two leptons from the 4 lepton event. One must be a hadronic tau
    ana.tx.createBranch<int>	      ("Var_3LepTauMET_other_lep_idx_0");     // idx in NanoAOD
    ana.tx.createBranch<int>          ("Var_3LepTauMET_other_lep_pdgid_0");   // pdgid of the non-tau W candidate lepton   
    ana.tx.createBranch<LorentzVector>("Var_3LepTauMET_other_lep_p4_0");      // p4 of the non-tau W candidate lepton    
    ana.tx.createBranch<int>	      ("Var_3LepTauMET_tau_idx_0");           // idx of leading hadronic tau in NanoAOD
    ana.tx.createBranch<int>	      ("Var_3LepTauMET_tau_pdgid_0");         // pdgid of leading hadronic tau in NanoAOD
    ana.tx.createBranch<LorentzVector>("Var_3LepTauMET_tau_p4_0");	      // p4 of the leading hadronic tau in NanoAOD
    ana.tx.createBranch<float>        ("Var_3LepTauMET_other_mll");	      // Invariant mass of the lepton-hadronic tau system from W's
    ana.tx.createBranch<int>	      ("Var_3LepTauMET_other_lep_ID_0");      // ID of non-tau W candidate lepton
    ana.tx.createBranch<int>	      ("Var_3LepTauMET_tau_idVSe_0");	      // ID vs electrons of leading hadronic tau candidate
    ana.tx.createBranch<int>	      ("Var_3LepTauMET_tau_idVSmu_0");	      // ID vs muons of leading hadronic tau candidate
    ana.tx.createBranch<int> 	      ("Var_3LepTauMET_tau_idVSjet_0");	      // ID vs jets of leading hadronic tau candidate

    // Additional variables
    ana.tx.createBranch<float>	      ("Var_3LepTauMET_mt2");		      // MT2 (PFMET)
    ana.tx.createBranch<float>	      ("Var_3LepTauMET_mt2_PuppiMET");	      // MT2 (PuppiMET)

    // Cross section related info
    ana.tx.createBranch<float>	      ("Var_3LepTauMET_scaleLumi");	      // Scale 1fb
    ana.tx.createBranch<float>	      ("Var_3LepTauMET_intLumi");	      // Integrated Luminosity

}

void Begin_3LepTauMET_Parse_Scale1fbs()
{
    threeleptau::scaleLumis.clear();
    ifstream ifile;
    ifile.open("weights/scaleLumis.txt");
    std::string line;
    while (std::getline(ifile, line))
    {
        TString rawline = line;
        std::vector<TString> list = RooUtil::StringUtil::split(rawline, ",");
        threeleptau::scaleLumis[list[0].Strip()] = list[1].Atof();
        threeleptau::intLumis[list[0].Strip()] = list[3].Atof();
    }
}

float Begin_3LepTauMET_MT2(int var)
{
    TLorentzVector lepton1 = RooUtil::Calc::getTLV(ana.tx.getBranch<LorentzVector>("Var_3LepTauMET_other_lep_p4_0"));
    TLorentzVector lepton2 = RooUtil::Calc::getTLV(ana.tx.getBranch<LorentzVector>("Var_3LepTauMET_tau_p4_0"));
    TLorentzVector misspart = RooUtil::Calc::getTLV(ana.tx.getBranch<LorentzVector>("Common_met_p4"));
    TLorentzVector rest_WW;
    rest_WW = lepton1 + lepton2 + misspart;
    TVector3 beta_from_miss_reverse(rest_WW.BoostVector());
    TVector3 beta_from_miss(-beta_from_miss_reverse.X(),-beta_from_miss_reverse.Y(),-beta_from_miss_reverse.Z());

    lepton1.Boost(beta_from_miss);
    lepton2.Boost(beta_from_miss);
    misspart.Boost(beta_from_miss);
    asymm_mt2_lester_bisect::disableCopyrightMessage();
    double MT2_0mass = asymm_mt2_lester_bisect::get_mT2(0,lepton1.Px(),lepton1.Py(),0,lepton2.Px(),lepton2.Py(),misspart.Px(), misspart.Py(),0,0,0);

    return MT2_0mass;
}

float Begin_3LepTauMET_MT2_PuppiMET(int var)
{
    TLorentzVector lepton1 = RooUtil::Calc::getTLV(ana.tx.getBranch<LorentzVector>("Var_3LepTauMET_other_lep_p4_0"));
    TLorentzVector lepton2 = RooUtil::Calc::getTLV(ana.tx.getBranch<LorentzVector>("Var_3LepTauMET_tau_p4_0"));
    TLorentzVector misspart = RooUtil::Calc::getTLV(ana.tx.getBranch<LorentzVector>("Common_met_p4_PuppiMET"));
    TLorentzVector rest_WW;
    rest_WW = lepton1 + lepton2 + misspart;
    TVector3 beta_from_miss_reverse(rest_WW.BoostVector());
    TVector3 beta_from_miss(-beta_from_miss_reverse.X(),-beta_from_miss_reverse.Y(),-beta_from_miss_reverse.Z());

    lepton1.Boost(beta_from_miss);
    lepton2.Boost(beta_from_miss);
    misspart.Boost(beta_from_miss);
    asymm_mt2_lester_bisect::disableCopyrightMessage();
    double MT2_0mass = asymm_mt2_lester_bisect::get_mT2(0,lepton1.Px(),lepton1.Py(),0,lepton2.Px(),lepton2.Py(),misspart.Px(), misspart.Py(),0,0,0);

    return MT2_0mass;
}
