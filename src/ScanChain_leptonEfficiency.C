#pragma GCC diagnostic ignored "-Wsign-compare"
#include "TFile.h"
#include "TH1F.h"
#include "TTree.h"
#include "TChain.h"
#include "TTreeCache.h"
#include "TTreeCacheUnzip.h"
#include "TTreePerfStats.h"
#include "TH2.h"

#include "../NanoTools/NanoCORE/Nano.h"
#include "../NanoTools/NanoCORE/Base.h"
#include "../NanoTools/NanoCORE/tqdm.h"

// For.. gconf?
#include "../NanoTools/NanoCORE/SSSelections.cc"
#include "../NanoTools/NanoCORE/MetSelections.cc"

#include "MuonIDHelper.h"
#include "ElectronIDHelper.h"

#include <iostream>
#include <iomanip>

#define SUM(vec) std::accumulate((vec).begin(), (vec).end(), 0);
#define SUM_GT(vec,num) std::accumulate((vec).begin(), (vec).end(), 0, [](float x,float y){return ((y > (num)) ? x+y : x); });
#define COUNT_GT(vec,num) std::count_if((vec).begin(), (vec).end(), [](float x) { return x > (num); });
#define COUNT_LT(vec,num) std::count_if((vec).begin(), (vec).end(), [](float x) { return x < (num); });

#define H1(name,nbins,low,high) TH1F *h_##name = new TH1F(#name,#name,nbins,low,high);

// #define DEBUG

struct debugger { template<typename T> debugger& operator , (const T& v) { cerr<<v<<" "; return *this; } } dbg;
#ifdef DEBUG
    #define debug(args...) do {cerr << #args << ": "; dbg,args; cerr << endl;} while(0)
#else
    #define debug(args...)
#endif

using namespace std;
using namespace tas;

int ScanChain(TChain *ch,TString process,TString year,float genWeightSum,float xsec) {

    //TTree tree_out("tree","");
    // First, let's make a histogram in pT and eta of the generator level electrons and muons
    TH1D *h_gen_mu_pt = new TH1D("h_gen_mu_pt","h_gen_mu_pt",30.,0.,200.); 
    TH1D *h_gen_el_pt = new TH1D("h_gen_el_pt","h_gen_el_pt",30.,0.,200.);
    TH1D *h_oldID_gen_el_pt = new TH1D("h_oldID_gen_el_pt","h_oldID_gen_el_pt",30.,0.,200.);
    TH1D *h_oldID_gen_el_eta = new TH1D("h_oldID_gen_el_eta","h_oldID_gen_el_eta",30.,-2.5,2.5);
    TH1D *h_oldID_gen_mu_pt = new TH1D("h_oldID_gen_mu_pt","h_oldID_gen_mu_pt",30.,0.,200.);
    TH1D *h_oldID_gen_mu_eta = new TH1D("h_oldID_gen_mu_eta","h_oldID_gen_mu_eta",30.,-2.5,2.5);
    TH1D *h_newID_gen_el_pt = new TH1D("h_newID_gen_el_pt","h_newID_gen_el_pt",30.,0.,200.);
    TH1D *h_newID_gen_el_eta = new TH1D("h_newID_gen_el_eta","h_newID_gen_el_eta",30.,-2.5,2.5);
    TH1D *h_newID_gen_mu_pt = new TH1D("h_newID_gen_mu_pt","h_newID_gen_mu_pt",30.,0.,200.);
    TH1D *h_newID_gen_mu_eta = new TH1D("h_newID_gen_mu_eta","h_newID_gen_mu_eta",30.,-2.5,2.5);
    TH1D *h_gen_mu_eta = new TH1D("h_gen_mu_eta","h_gen_mu_eta",30.,-2.4,2.4);
    TH1D *h_gen_el_eta = new TH1D("h_gen_el_eta","h_gen_el_eta",30.,-2.5,2.5);
    TH1D *h_gen_mu_dRmin = new TH1D("h_gen_mu_dRmin","h_gen_mu_dRmin",30.,0.0,0.4);
    TH1D *h_gen_el_dRmin = new TH1D("h_gen_el_dRmin","h_gen_el_dRmin",30.,0.0,0.4);
    TH1D *h_jetRelIso_mu = new TH1D("h_jetRelIso_mu","h_jetRelIso_mu",30.,0.0,5.0);
    TH1D *h_jetRelIso_el = new TH1D("h_jetRelIso_el","h_jetRelIso_el",30.,0.0,5.0);
    TH1D *h_RelIso03_mu = new TH1D("h_RelIso03_mu","h_RelIso03_mu",30.,0.0,2.0);
    TH1D *h_RelIso03_el = new TH1D("h_RelIso03_el","h_RelIso03_el",30.,0.0,2.0);
    TH1D *h_njets = new TH1D("h_njets","h_njets",5,0.,5.);

    int nEventsTotal = 0;
    int nEventsChain = ch->GetEntries();
    TFile *currentFile = 0;
    TObjArray *listOfFiles = ch->GetListOfFiles();
    TIter fileIter(listOfFiles);
    tqdm bar;

    float lumi;
    bool isAPV = false;

    if ( year == "2018" ) lumi = 59.8;
    if ( year == "2017" ) lumi = 41.5;
    if ( year == "2016" ) lumi = 16.8;
    if ( year == "2016APV" ){ 
	 lumi = 19.5;
	 isAPV = true;
    }

    //gconf.year = 2018;
    while ( (currentFile = (TFile*)fileIter.Next()) ) {
        TFile *file = TFile::Open( currentFile->GetTitle() );
        TTree *tree = (TTree*)file->Get("Events");
        TString filename(currentFile->GetTitle());

        tree->SetCacheSize(128*1024*1024);
        tree->SetCacheLearnEntries(100);

        nt.Init(tree);

        for( unsigned int event = 0; event < tree->GetEntriesFast(); ++event) {

            nt.GetEntry(event);
            tree->LoadTree(event);


            nEventsTotal++;
            bar.progress(nEventsTotal, nEventsChain);

            float weight = nt.genWeight();
	    float fill_weight = ((weight*xsec)/genWeightSum);

            std::vector<int> lepton_jet_idxs;

	    for (unsigned int igen = 0; igen < nt.GenPart_pdgId().size(); ++igen){
		 // Go to next particle if the particle is not prompt or in the final state
		 if ( !(nt.GenPart_status().at(igen) == 1) || !((nt.GenPart_statusFlags().at(igen) >> 0) & 1) ) continue;
		 // Get gen-level electrons
		 int matched_el_idx;
	         if ( std::abs(nt.GenPart_pdgId().at(igen)) == 11 ){
		      h_gen_el_pt->Fill(nt.GenPart_pt().at(igen),fill_weight);
		      h_gen_el_eta->Fill(nt.GenPart_eta().at(igen),fill_weight);
		      // loop over electrons, see if the reco electron passes ID requirements
		      float dRmin_el = 9999999.;
		      //int matched_el_idx;
		      for ( int iel = 0; iel < nt.nElectron(); iel++ ){
			    if ( ROOT::Math::VectorUtil::DeltaR(nt.GenPart_p4().at(igen),nt.Electron_p4().at(iel)) < dRmin_el ){
				 dRmin_el = ROOT::Math::VectorUtil::DeltaR(nt.GenPart_p4().at(igen),nt.Electron_p4().at(iel));
				 matched_el_idx = iel;
			    }
                      }

		      // Plot the dR min to see where to place the cut
		      h_gen_el_dRmin->Fill(dRmin_el,fill_weight);
		      if ( dRmin_el > 0.05 ) continue;

	              if ( nt.Electron_jetIdx()[matched_el_idx] != -1 ){
			   lepton_jet_idxs.push_back(nt.Electron_jetIdx()[matched_el_idx]);
		      }

                      // Fill the electron jetRelIso histogram
                      h_jetRelIso_el->Fill(nt.Electron_pt()[matched_el_idx]*nt.Electron_jetRelIso()[matched_el_idx],fill_weight);
		      h_RelIso03_el->Fill(nt.Electron_pt()[matched_el_idx]*nt.Electron_pfRelIso03_all()[matched_el_idx],fill_weight);

		      bool el_pass_oldID = false;
		      bool el_pass_newID = false;

                      bool el_pt = ( nt.Electron_pt().at(matched_el_idx) > 15.);
		      bool el_eta = ( std::abs(nt.Electron_eta().at(matched_el_idx)) < 2.5 );
		      bool el_mva = ( nt.Electron_mvaFall17V2noIso_WPL().at(matched_el_idx) );
		      bool el_relIso = ( nt.Electron_pfRelIso03_all().at(matched_el_idx) < 0.4 );
		      bool el_forb = ( !(std::abs(nt.Electron_eta().at(matched_el_idx)) < 1.566 && std::abs(nt.Electron_eta().at(matched_el_idx)) > 1.444 ) );
		      bool el_dz = ( std::abs(nt.Electron_dz().at(matched_el_idx)) < 0.1 );
		      bool el_dxy = ( std::abs(nt.Electron_dxy().at(matched_el_idx)) < 0.05 );
		      bool el_Z_cand = ( nt.Electron_pfRelIso03_all().at(matched_el_idx) < 0.2 && nt.Electron_sip3d().at(matched_el_idx) < 4. );

		      int el_ID = 0;
		      el_ID |= Electron_mvaFall17V2noIso_WPL()[matched_el_idx] << 0;
                      el_ID |= Electron_mvaFall17V2noIso_WP90()[matched_el_idx] << 1;
                      el_ID |= Electron_mvaFall17V2noIso_WP80()[matched_el_idx] << 2;
                      el_ID |= Electron_mvaFall17V2Iso_WPL()[matched_el_idx] << 3;
                      el_ID |= Electron_mvaFall17V2Iso_WP90()[matched_el_idx] << 4;
                      el_ID |= Electron_mvaFall17V2Iso_WP80()[matched_el_idx] << 5; 

		      bool el_W_cand = ( (el_ID & (1 << 4)) && nt.Electron_pfRelIso03_all().at(matched_el_idx) < 0.2 && nt.Electron_sip3d().at(matched_el_idx) < 4. );

                      el_pass_oldID = ((el_pt && el_eta && el_mva && el_relIso && el_forb && el_dz && el_dxy) && (el_Z_cand || el_W_cand));

		      if ( el_pass_oldID ){
			   h_oldID_gen_el_pt->Fill(nt.GenPart_pt().at(igen),fill_weight);
			   h_oldID_gen_el_eta->Fill(nt.GenPart_eta().at(igen),fill_weight); 
		      }

		      bool el_newID_cut = ElectronIDHelper::electronIDscore(nt.year(),matched_el_idx,"tight",isAPV);
		      
		      el_pass_newID = ( el_newID_cut && el_Z_cand && el_pt);

		      if ( el_pass_newID ){
			   h_newID_gen_el_pt->Fill(nt.GenPart_pt().at(igen),fill_weight);
                           h_newID_gen_el_eta->Fill(nt.GenPart_eta().at(igen),fill_weight);
                      }
		      
                 }
		 // Get gen-level muons
		 int matched_mu_idx;
		 if ( std::abs(nt.GenPart_pdgId().at(igen)) == 13 ){
		      h_gen_mu_pt->Fill(nt.GenPart_pt().at(igen),fill_weight);
                      h_gen_mu_eta->Fill(nt.GenPart_eta().at(igen),fill_weight);
		      float dRmin_mu = 9999999.;
		      //int matched_mu_idx;
		      for ( int imu = 0; imu < nt.nMuon(); imu++ ){
			    if ( ROOT::Math::VectorUtil::DeltaR(nt.GenPart_p4().at(igen),nt.Muon_p4().at(imu)) < dRmin_mu ){
                                 dRmin_mu = ROOT::Math::VectorUtil::DeltaR(nt.GenPart_p4().at(igen),nt.Muon_p4().at(imu));
                                 matched_mu_idx = imu;
                            }
		      }

		      h_gen_mu_dRmin->Fill(dRmin_mu,fill_weight);
		      if ( dRmin_mu > 0.05 ) continue;

		      if ( nt.Muon_jetIdx()[matched_mu_idx] != 1 ){
		           lepton_jet_idxs.push_back(nt.Muon_jetIdx()[matched_mu_idx]);	   
		      }

                      // Fill the Muon jetRelIso histogram
		      h_jetRelIso_mu->Fill(nt.Muon_pt()[matched_mu_idx]*nt.Muon_jetRelIso()[matched_mu_idx],fill_weight);
		      h_RelIso03_mu->Fill(nt.Muon_pt()[matched_mu_idx]*nt.Muon_pfRelIso03_all()[matched_mu_idx],fill_weight);

		      bool mu_pass_oldID = false;
		      bool mu_pass_newID = false;

		      bool mu_pt = (nt.Muon_pt()[matched_mu_idx] > 15.);
		      bool mu_eta = (std::abs(nt.Muon_eta()[matched_mu_idx]) < 2.4);	      		    		   
                      bool mu_id = (nt.Muon_looseId()[matched_mu_idx]);  
		      bool mu_isoID = (nt.Muon_pfIsoId()[matched_mu_idx] >= 1);
		      bool mu_dz = (nt.Muon_dz()[matched_mu_idx] < 0.1);
		      bool mu_dxy = (nt.Muon_dxy()[matched_mu_idx] < 0.05);
		      bool mu_iso = (nt.Muon_pfRelIso03_all()[matched_mu_idx] < 0.4);
		      bool mu_sip3d = (nt.Muon_sip3d()[matched_mu_idx] < 4);
		      
		      // Define the lepton ID for W and Z lepton candidates
		      int mu_ID = 0;
        	      mu_ID |= nt.Muon_mediumId()[matched_mu_idx] << 0;
        	      mu_ID |= nt.Muon_tightId()[matched_mu_idx] << 1;
        	      mu_ID |= nt.Muon_pfIsoId()[matched_mu_idx] << 2;
 
		      bool mu_Zcand = ( mu_sip3d && ((mu_ID >> 2) >= 2));
		      bool mu_Wcand = ( mu_sip3d && ((mu_ID >> 2) >= 3));

                      mu_pass_oldID = (mu_pt && mu_eta && mu_id && mu_isoID && mu_dz && mu_dxy && mu_iso && ( mu_Zcand || mu_Wcand ));
		      if ( mu_pass_oldID ){
			   h_oldID_gen_mu_pt->Fill(nt.GenPart_pt()[igen],fill_weight);
			   h_oldID_gen_mu_eta->Fill(nt.GenPart_eta()[igen],fill_weight);
		      }

		      bool mu_newID_cut = MuonIDHelper::muonIDscore(nt.year(),matched_mu_idx,"tight",isAPV);
		      if ( mu_newID_cut && mu_sip3d && mu_pt){
			   h_newID_gen_mu_pt->Fill(nt.GenPart_pt()[igen],fill_weight);
                           h_newID_gen_mu_eta->Fill(nt.GenPart_eta()[igen],fill_weight);
		      }

		 }

		 
	    }  // gen particle loop

	    int njets = 0;
	    for ( int jet = 0; jet < nt.nJet(); jet++ ){
		  if ( not (nt.Jet_pt()[jet] > 25.) ) continue;
		  if ( not (std::abs(nt.Jet_eta()[jet]) < 2.4) ) continue;
		  if ( not ((nt.Jet_jetId()[jet] >> 1) & 1)) continue;
		  bool matched_to_lepton = false;
                  for ( int ilep = 0; ilep < lepton_jet_idxs.size(); ilep++ ){
			if ( jet == lepton_jet_idxs[ilep] ){
			     matched_to_lepton = true;
			}
		  }
		  if ( matched_to_lepton ) continue;  	
		  njets++;
	    }

	    h_njets->Fill(njets,fill_weight);	    


        } // Event loop

	

        delete file;


    } // File loop
    bar.finish();

    TFile* f1 = new TFile("output_lepID/"+year+"/output_"+process+".root", "RECREATE");

    h_gen_mu_pt->Write();
    h_gen_el_pt->Write();
    h_newID_gen_el_pt->Write();
    h_oldID_gen_el_pt->Write();
    h_newID_gen_el_eta->Write();
    h_oldID_gen_el_eta->Write();
    h_newID_gen_mu_pt->Write();
    h_oldID_gen_mu_pt->Write();
    h_newID_gen_mu_eta->Write();
    h_oldID_gen_mu_eta->Write();
    h_gen_mu_eta->Write();
    h_gen_el_eta->Write();
    h_gen_mu_dRmin->Write();
    h_gen_el_dRmin->Write();
    h_jetRelIso_mu->Write();       
    h_jetRelIso_el->Write();
    h_njets->Write();
    h_RelIso03_mu->Write();
    h_RelIso03_el->Write();

    f1->Write();
    f1->Close();

    delete h_gen_mu_pt;
    delete h_gen_mu_eta;
    delete h_gen_el_pt;
    delete h_gen_el_eta;
    delete h_gen_mu_dRmin;
    delete h_gen_el_dRmin;
    delete h_newID_gen_el_pt;
    delete h_oldID_gen_el_pt;
    delete h_newID_gen_el_eta;
    delete h_oldID_gen_el_eta;
    delete h_newID_gen_mu_pt;
    delete h_oldID_gen_mu_pt;
    delete h_newID_gen_mu_eta;
    delete h_oldID_gen_mu_eta;
    delete h_jetRelIso_mu;
    delete h_jetRelIso_el;
    delete h_njets;
    delete h_RelIso03_mu;
    delete h_RelIso03_el;
    return 0;
}
