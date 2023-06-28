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

    std::cout << "Process = " << process << std::endl;
    std::cout << "year = " << year << std::endl;
    std::cout << "genWeightSum = " << genWeightSum << std::endl;
    std::cout << "cross section = " << xsec << std::endl;
 
    //TTree tree_out("tree","");
    // First, let's make a histogram in pT and eta of the generator level electrons and muons
    //TH1D *h_mu_pt_raw = new TH1D("h_mu_pt_raw","h_mu_pt_raw",30.,0.,300.);
    //TH1D *h_mu_eta_raw = new TH1D("h_mu_eta_raw","h_mu_eta_raw",30,-2.4,2.4);
    //TH1D *h_mu_jetNDauCharged_raw = new TH1D("h_mu_jetNDauCharged_raw","h_mu_jetNDauCharged_raw",10,0.,10.);    
    //TH1D *h_mu_miniPFRelIso_chg_raw = new TH1D("h_mu_miniPFRelIso_chg_raw","h_mu_miniPFRmuIso_chg_raw",10,0.,0.2);
    //TH1D *h_mu_miniPFRelIso_diff_all_chg_raw = new TH1D("h_mu_miniPFRelIso_diff_all_chg_raw","h_mu_miniPFRmuIso_diff_all_chg_raw",10,0.,0.2);
    //TH1D *h_mu_jetPtRelv2_raw = new TH1D("h_mu_jetPtRelv2_raw","h_mu_jetPtRelv2_raw",50,0.,20.);
    //TH1D *h_mu_jetPtRatio_raw = new TH1D("h_mu_jetPtRatio_raw","h_mu_jetPtRatio_raw",30,0.,1.);
    //TH1D *h_mu_pfRelIso03_all_raw = new TH1D("h_mu_pfRelIso03_all_raw","h_mu_pfRelIso03_all_raw",10,0.,0.2);
    //TH1D *h_mu_btagDeepFlavB_raw = new TH1D("h_mu_btagDeepFlavB_raw","h_mu_btagDeepFlavB_raw",15,0.,0.7);
    //TH1D *h_mu_sip3d_raw = new TH1D("h_mu_sip3d_raw","h_mu_sip3d_raw",30,0.,12.);
    //TH1D *h_mu_logdxy_raw = new TH1D("h_mu_logdxy_raw","h_mu_logdxy_raw",30,-10.,10.);
    //TH1D *h_mu_logdz_raw = new TH1D("h_mu_logdz_raw","h_mu_logdz_raw",30,-10.,10.);
    //TH1D *h_mu_segmentComp_raw = new TH1D("h_mu_segmentComp_raw","h_mu_segmentComp_raw",30,0.,2.);

    //TH1D *h_mu_pt_old = new TH1D("h_mu_pt_old","h_mu_pt_old",30.,0.,300.);
    //TH1D *h_mu_eta_old = new TH1D("h_mu_eta_old","h_mu_eta_old",30,-2.4,2.4);
    //TH1D *h_mu_jetNDauCharged_old = new TH1D("h_mu_jetNDauCharged_old","h_mu_jetNDauCharged_old",10,0.,10.);
    //TH1D *h_mu_miniPFRelIso_chg_old = new TH1D("h_mu_miniPFRelIso_chg_old","h_mu_miniPFRelIso_chg_old",10,0.,0.2);
    //TH1D *h_mu_miniPFRelIso_diff_all_chg_old = new TH1D("h_mu_miniPFRelIso_diff_all_chg_old","h_mu_miniPFRelIso_diff_all_chg_old",10,0.,0.2);
    //TH1D *h_mu_jetPtRelv2_old = new TH1D("h_mu_jetPtRelv2_old","h_mu_jetPtRelv2_old",50,0.,20.);
    //TH1D *h_mu_jetPtRatio_old = new TH1D("h_mu_jetPtRatio_old","h_mu_jetPtRatio_old",30,0.,1.);
    //TH1D *h_mu_pfRelIso03_all_old = new TH1D("h_mu_pfRelIso03_all_old","h_mu_pfRelIso03_all_old",10,0.,0.2);
    //TH1D *h_mu_btagDeepFlavB_old = new TH1D("h_mu_btagDeepFlavB_old","h_mu_btagDeepFlavB_old",15,0.,0.7);
    //TH1D *h_mu_sip3d_old = new TH1D("h_mu_sip3d_old","h_mu_sip3d_old",30,0.,12.);
    //TH1D *h_mu_logdxy_old = new TH1D("h_mu_logdxy_old","h_mu_logdxy_old",30,-10.,10.);
    //TH1D *h_mu_logdz_old = new TH1D("h_mu_logdz_old","h_mu_logdz_old",30,-10.,10.);
    //TH1D *h_mu_segmentComp_old = new TH1D("h_mu_segmentComp_old","h_mu_segmentComp_old",30,0.,2.);
    //
    //TH1D *h_mu_pt_new = new TH1D("h_mu_pt_new","h_mu_pt_new",30.,0.,300.);
    //TH1D *h_mu_eta_new = new TH1D("h_mu_eta_new","h_mu_eta_new",30,-2.4,2.4);
    //TH1D *h_mu_jetNDauCharged_new = new TH1D("h_mu_jetNDauCharged_new","h_mu_jetNDauCharged_new",10,0.,10.);
    //TH1D *h_mu_miniPFRelIso_chg_new = new TH1D("h_mu_miniPFRelIso_chg_new","h_mu_miniPFRelIso_chg_new",10,0.,0.2);
    //TH1D *h_mu_miniPFRelIso_diff_all_chg_new = new TH1D("h_mu_miniPFRelIso_diff_all_chg_new","h_mu_miniPFRelIso_diff_all_chg_new",10,0.,0.2);
    //TH1D *h_mu_jetPtRelv2_new = new TH1D("h_mu_jetPtRelv2_new","h_mu_jetPtRelv2_new",50,0.,20.);
    //TH1D *h_mu_jetPtRatio_new = new TH1D("h_mu_jetPtRatio_new","h_mu_jetPtRatio_new",30,0.,1.);
    //TH1D *h_mu_pfRelIso03_all_new = new TH1D("h_mu_pfRelIso03_all_new","h_mu_pfRelIso03_all_new",10,0.,0.2);
    //TH1D *h_mu_btagDeepFlavB_new = new TH1D("h_mu_btagDeepFlavB_new","h_mu_btagDeepFlavB_new",15,0.,0.7);
    //TH1D *h_mu_sip3d_new = new TH1D("h_mu_sip3d_new","h_mu_sip3d_new",30,0.,12.);
    //TH1D *h_mu_logdxy_new = new TH1D("h_mu_logdxy_new","h_mu_logdxy_new",30,-10.,10.);
    //TH1D *h_mu_logdz_new = new TH1D("h_mu_logdz_new","h_mu_logdz_new",30,-10.,10.);
    //TH1D *h_mu_segmentComp_new = new TH1D("h_mu_segmentComp_new","h_mu_segmentComp_new",30,0.,2.);
    // 
    //TH1D *h_el_pt_raw = new TH1D("h_el_pt_raw","h_el_pt_raw",30.,0.,300.);
    //TH1D *h_el_eta_raw = new TH1D("h_el_eta_raw","h_el_eta_raw",30.,-2.5,2.5);
    //TH1D *h_el_jetNDauCharged_raw = new TH1D("h_el_jetNDauCharged_raw","h_el_jetNDauCharged_raw",10,0.,10.);
    //TH1D *h_el_miniPFRelIso_chg_raw = new TH1D("h_el_miniPFRelIso_chg_raw","h_el_miniPFRelIso_chg_raw",10,0.,0.2);
    //TH1D *h_el_miniPFRelIso_diff_all_chg_raw = new TH1D("h_el_miniPFRelIso_diff_all_chg_raw","h_el_miniPFRelIso_diff_all_chg_raw",10,0.,0.2);
    //TH1D *h_el_jetPtRelv2_raw = new TH1D("h_el_jetPtRelv2_raw","h_el_jetPtRelv2_raw",50,0.,20.);
    //TH1D *h_el_jetPtRatio_raw = new TH1D("h_el_jetPtRatio_raw","h_el_jetPtRatio_raw",30,0.,1.);
    //TH1D *h_el_pfRelIso03_all_raw = new TH1D("h_el_pfRelIso03_all_raw","h_el_pfRelIso03_all_raw",10,0.,0.2);
    //TH1D *h_el_btagDeepFlavB_raw = new TH1D("h_el_btagDeepFlavB_raw","h_el_btagDeepFlavB_raw",15,0.,0.7);
    //TH1D *h_el_sip3d_raw = new TH1D("h_el_sip3d_raw","h_el_sip3d_raw",30,0.,12.);
    //TH1D *h_el_logdxy_raw = new TH1D("h_el_logdxy_raw","h_el_logdxy_raw",30,-10.,10.);
    //TH1D *h_el_logdz_raw = new TH1D("h_el_logdz_raw","h_el_logdz_raw",30,-10.,10.);

    //TH1D *h_el_pt_old = new TH1D("h_el_pt_old","h_el_pt_old",30.,0.,300.);
    //TH1D *h_el_eta_old = new TH1D("h_el_eta_old","h_el_eta_old",30.,-2.5,2.5);
    //TH1D *h_el_jetNDauCharged_old = new TH1D("h_el_jetNDauCharged_old","h_el_jetNDauCharged_old",10,0.,10.);
    //TH1D *h_el_miniPFRelIso_chg_old = new TH1D("h_el_miniPFRelIso_chg_old","h_el_miniPFRelIso_chg_old",10,0.,0.2);
    //TH1D *h_el_miniPFRelIso_diff_all_chg_old = new TH1D("h_el_miniPFRelIso_diff_all_chg_old","h_el_miniPFRelIso_diff_all_chg_old",10,0.,0.2);
    //TH1D *h_el_jetPtRelv2_old = new TH1D("h_el_jetPtRelv2_old","h_el_jetPtRelv2_old",50,0.,20.);
    //TH1D *h_el_jetPtRatio_old = new TH1D("h_el_jetPtRatio_old","h_el_jetPtRatio_old",30,0.,1.);
    //TH1D *h_el_pfRelIso03_all_old = new TH1D("h_el_pfRelIso03_all_old","h_el_pfRelIso03_all_old",10,0.,0.2);
    //TH1D *h_el_btagDeepFlavB_old = new TH1D("h_el_btagDeepFlavB_old","h_el_btagDeepFlavB_old",15,0.,0.7);
    //TH1D *h_el_sip3d_old = new TH1D("h_el_sip3d_old","h_el_sip3d_old",30,0.,12.);
    //TH1D *h_el_logdxy_old = new TH1D("h_el_logdxy_old","h_el_logdxy_old",30,-10.,10.);
    //TH1D *h_el_logdz_old = new TH1D("h_el_logdz_old","h_el_logdz_old",30,-10.,10.);

    //TH1D *h_el_pt_new = new TH1D("h_el_pt_new","h_el_pt_new",30.,0.,300.);
    //TH1D *h_el_eta_new = new TH1D("h_el_eta_new","h_el_eta_new",30.,-2.5,2.5);
    //TH1D *h_el_jetNDauCharged_new = new TH1D("h_el_jetNDauCharged_new","h_el_jetNDauCharged_new",10,0.,10.);
    //TH1D *h_el_miniPFRelIso_chg_new = new TH1D("h_el_miniPFRelIso_chg_new","h_el_miniPFRelIso_chg_new",10,0.,0.2);
    //TH1D *h_el_miniPFRelIso_diff_all_chg_new = new TH1D("h_el_miniPFRelIso_diff_all_chg_new","h_el_miniPFRelIso_diff_all_chg_new",10,0.,0.2);
    //TH1D *h_el_jetPtRelv2_new = new TH1D("h_el_jetPtRelv2_new","h_el_jetPtRelv2_new",50,0.,20.);
    //TH1D *h_el_jetPtRatio_new = new TH1D("h_el_jetPtRatio_new","h_el_jetPtRatio_new",30,0.,1.);
    //TH1D *h_el_pfRelIso03_all_new = new TH1D("h_el_pfRelIso03_all_new","h_el_pfRelIso03_all_new",10,0.,0.2);
    //TH1D *h_el_btagDeepFlavB_new = new TH1D("h_el_btagDeepFlavB_new","h_el_btagDeepFlavB_new",15,0.,0.7);
    //TH1D *h_el_sip3d_new = new TH1D("h_el_sip3d_new","h_el_sip3d_new",30,0.,12.);
    //TH1D *h_el_logdxy_new = new TH1D("h_el_logdxy_new","h_el_logdxy_new",30,-10.,10.);
    //TH1D *h_el_logdz_new = new TH1D("h_el_logdz_new","h_el_logdz_new",30,-10.,10.);

    //TH1D *h_el_jet_dR = new TH1D("h_el_jet_dR","h_el_jet_dR",30.,0.,1.);
    //TH1D *h_mu_jet_dR = new TH1D("h_mu_jet_dR","h_mu_jet_dR",30.,0.,1.);
 
    //TH1D *h_weights = new TH1D("h_weights","h_weights",20.,-0.5,0.5);

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

    float total_events = 0;

    float nEvents_old_trg = 0.;
    float nEvents_old_notrg = 0.;
    float nEvents_new_trg = 0.;
    float nEvents_new_notrg = 0.;

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
	    float fill_weight = ((weight*xsec*lumi)/genWeightSum);

            bool trig;
 
            if ( year == "2016" || year == "2016APV" ){
		 trig = (nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL() || nt.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() || nt.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() || nt.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ() );
	    }
 
            if ( year == "2017" ){
		 trig = (nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ() || nt.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL() || nt.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() || nt.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ());
	    }
            
            if ( year == "2018" ){
		 trig = ( nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8() || nt.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL() || nt.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() || nt.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ() );
	    }

            total_events += fill_weight;

            //h_weights->Fill(fill_weight,fill_weight);

            int n_el_old = 0;
            int n_el_new = 0;
            int n_mu_old = 0;
            int n_mu_new = 0;

	    for (unsigned int iel = 0; iel < nt.Electron_pdgId().size(); ++iel){

		//h_el_pt_raw->Fill(nt.Electron_pt()[iel],fill_weight);
                //h_el_eta_raw->Fill(nt.Electron_eta()[iel],fill_weight);
                //h_el_jetNDauCharged_raw->Fill(nt.Electron_jetNDauCharged()[iel],fill_weight);
                //h_el_miniPFRelIso_chg_raw->Fill(nt.Electron_miniPFRelIso_chg()[iel],fill_weight);
                //h_el_miniPFRelIso_diff_all_chg_raw->Fill(nt.Electron_miniPFRelIso_all()[iel]-nt.Electron_miniPFRelIso_chg()[iel],fill_weight);
                //h_el_jetPtRelv2_raw->Fill(nt.Electron_jetPtRelv2()[iel],fill_weight);
		//h_el_jetPtRatio_raw->Fill(1./(nt.Electron_jetRelIso()[iel] + 1.),fill_weight);
		//h_el_pfRelIso03_all_raw->Fill(nt.Electron_pfRelIso03_all()[iel],fill_weight);
                //if ( nt.Electron_jetIdx()[iel] == -1 ){
		//     h_el_btagDeepFlavB_raw->Fill(0.,fill_weight);
		//}
		//else{
		//     h_el_btagDeepFlavB_raw->Fill(nt.Jet_btagDeepFlavB()[nt.Electron_jetIdx()[iel]],fill_weight);
		//}
		//h_el_sip3d_raw->Fill(nt.Electron_sip3d()[iel],fill_weight);
		//h_el_logdxy_raw->Fill(std::log(std::abs(nt.Electron_dxy()[iel])),fill_weight);
		//h_el_logdz_raw->Fill(std::log(std::abs(nt.Electron_dz()[iel])),fill_weight);

		bool el_pass_oldID = false;
		bool el_pass_newID = false;

                bool el_pt = ( nt.Electron_pt().at(iel) > 15.);
		bool el_eta = ( std::abs(nt.Electron_eta().at(iel)) < 2.5 );
		bool el_mva = ( nt.Electron_mvaFall17V2noIso_WPL().at(iel) );
		bool el_relIso = ( nt.Electron_pfRelIso03_all().at(iel) < 0.4 );
		bool el_forb = ( !(std::abs(nt.Electron_eta().at(iel)) < 1.566 && std::abs(nt.Electron_eta().at(iel)) > 1.444 ) );
		bool el_dz = ( std::abs(nt.Electron_dz().at(iel)) < 0.1 );
		bool el_dxy = ( std::abs(nt.Electron_dxy().at(iel)) < 0.05 );
		bool el_Z_cand = ( nt.Electron_pfRelIso03_all().at(iel) < 0.2 && nt.Electron_sip3d().at(iel) < 4. );

		int el_ID = 0;
		el_ID |= Electron_mvaFall17V2noIso_WPL()[iel] << 0;
                el_ID |= Electron_mvaFall17V2noIso_WP90()[iel] << 1;
                el_ID |= Electron_mvaFall17V2noIso_WP80()[iel] << 2;
                el_ID |= Electron_mvaFall17V2Iso_WPL()[iel] << 3;
                el_ID |= Electron_mvaFall17V2Iso_WP90()[iel] << 4;
                el_ID |= Electron_mvaFall17V2Iso_WP80()[iel] << 5; 

		bool el_W_cand = ( (el_ID & (1 << 4)) && nt.Electron_pfRelIso03_all().at(iel) < 0.2 && nt.Electron_sip3d().at(iel) < 4. );

                // Jet overlap removal
                int el_njet_overlap = 0;
		for ( int ijet = 0; ijet < nt.nJet(); ijet++ ){
		      double dR_el = ROOT::Math::VectorUtil::DeltaR(nt.Electron_p4()[iel],nt.Jet_p4()[ijet]);
		      //h_el_jet_dR->Fill(dR_el,fill_weight);
                      if ( dR_el < 0.4 ) el_njet_overlap++;
		}

 		if ( el_njet_overlap > 1 ) continue;

                el_pass_oldID = ((el_pt && el_eta && el_mva && el_relIso && el_forb && el_dz && el_dxy) && (el_Z_cand || el_W_cand));

		if ( el_pass_oldID ){
 		     n_el_old++;
                     //h_el_pt_old->Fill(nt.Electron_pt()[iel],fill_weight);
                     //h_el_eta_old->Fill(nt.Electron_eta()[iel],fill_weight);
                     //h_el_jetNDauCharged_old->Fill(nt.Electron_jetNDauCharged()[iel],fill_weight);
                     //h_el_miniPFRelIso_chg_old->Fill(nt.Electron_miniPFRelIso_chg()[iel],fill_weight);
                     //h_el_miniPFRelIso_diff_all_chg_old->Fill(nt.Electron_miniPFRelIso_all()[iel]-nt.Electron_miniPFRelIso_chg()[iel],fill_weight);
                     //h_el_jetPtRelv2_old->Fill(nt.Electron_jetPtRelv2()[iel],fill_weight);
                     //h_el_jetPtRatio_old->Fill(1./(nt.Electron_jetRelIso()[iel] + 1.),fill_weight);
                     //h_el_pfRelIso03_all_old->Fill(nt.Electron_pfRelIso03_all()[iel],fill_weight);
                     //if ( nt.Electron_jetIdx()[iel] == -1 ){
                     //     h_el_btagDeepFlavB_old->Fill(0.,fill_weight);
                     //}
                     //else{
                     //     h_el_btagDeepFlavB_old->Fill(nt.Jet_btagDeepFlavB()[nt.Electron_jetIdx()[iel]],fill_weight);
                     //}
                     //h_el_sip3d_old->Fill(nt.Electron_sip3d()[iel],fill_weight);
                     //h_el_logdxy_old->Fill(std::log(std::abs(nt.Electron_dxy()[iel])),fill_weight);
                     //h_el_logdz_old->Fill(std::log(std::abs(nt.Electron_dz()[iel])),fill_weight);
		}

		bool el_newID_cut = ElectronIDHelper::electronIDscore(nt.year(),iel,"tight",isAPV);
		
		el_pass_newID = ( el_newID_cut && el_Z_cand && el_pt );

		if ( el_pass_newID ){
                     n_el_new++;
		     //h_el_pt_new->Fill(nt.Electron_pt()[iel],fill_weight);
                     //h_el_eta_new->Fill(nt.Electron_eta()[iel],fill_weight);
                     //h_el_jetNDauCharged_new->Fill(nt.Electron_jetNDauCharged()[iel],fill_weight);
                     //h_el_miniPFRelIso_chg_new->Fill(nt.Electron_miniPFRelIso_chg()[iel],fill_weight);
                     //h_el_miniPFRelIso_diff_all_chg_new->Fill(nt.Electron_miniPFRelIso_all()[iel]-nt.Electron_miniPFRelIso_chg()[iel],fill_weight);
                     //h_el_jetPtRelv2_new->Fill(nt.Electron_jetPtRelv2()[iel],fill_weight);
                     //h_el_jetPtRatio_new->Fill(1./(nt.Electron_jetRelIso()[iel] + 1.),fill_weight);
                     //h_el_pfRelIso03_all_new->Fill(nt.Electron_pfRelIso03_all()[iel],fill_weight);
                     //if ( nt.Electron_jetIdx()[iel] == -1 ){
                     //     h_el_btagDeepFlavB_new->Fill(0.,fill_weight);
                     //}
                     //else{
                     //     h_el_btagDeepFlavB_new->Fill(nt.Jet_btagDeepFlavB()[nt.Electron_jetIdx()[iel]],fill_weight);
                     //}
                     //h_el_sip3d_new->Fill(nt.Electron_sip3d()[iel],fill_weight);
                     //h_el_logdxy_new->Fill(std::log(std::abs(nt.Electron_dxy()[iel])),fill_weight);
                     //h_el_logdz_new->Fill(std::log(std::abs(nt.Electron_dz()[iel])),fill_weight);
                }
		 
           }     
           
           for ( int imu = 0; imu < nt.Muon_pdgId().size(); imu++ ){

		//h_mu_pt_raw->Fill(nt.Muon_pt()[imu],fill_weight);
                //h_mu_eta_raw->Fill(nt.Muon_eta()[imu],fill_weight);
                //h_mu_jetNDauCharged_raw->Fill(nt.Muon_jetNDauCharged()[imu],fill_weight);
                //h_mu_miniPFRelIso_chg_raw->Fill(nt.Muon_miniPFRelIso_chg()[imu],fill_weight);
                //h_mu_miniPFRelIso_diff_all_chg_raw->Fill(nt.Muon_miniPFRelIso_all()[imu]-nt.Muon_miniPFRelIso_chg()[imu],fill_weight);
                //h_mu_jetPtRelv2_raw->Fill(nt.Muon_jetPtRelv2()[imu],fill_weight);
                //h_mu_jetPtRatio_raw->Fill(1./(nt.Muon_jetRelIso()[imu] + 1.),fill_weight);
                //h_mu_pfRelIso03_all_raw->Fill(nt.Muon_pfRelIso03_all()[imu],fill_weight);
                if ( nt.Muon_jetIdx()[imu] == -1 ){
                     //h_mu_btagDeepFlavB_raw->Fill(0.,fill_weight);
                }
                else{
                     //h_mu_btagDeepFlavB_raw->Fill(nt.Jet_btagDeepFlavB()[nt.Muon_jetIdx()[imu]],fill_weight);
                }
                //h_mu_sip3d_raw->Fill(nt.Muon_sip3d()[imu],fill_weight);
                //h_mu_logdxy_raw->Fill(std::log(std::abs(nt.Muon_dxy()[imu])),fill_weight);
                //h_mu_logdz_raw->Fill(std::log(std::abs(nt.Muon_dz()[imu])),fill_weight);		
		//h_mu_segmentComp_raw->Fill(nt.Muon_segmentComp()[imu],fill_weight);

		bool mu_pass_oldID = false;
		bool mu_pass_newID = false;

		bool mu_pt = (nt.Muon_pt()[imu] > 15.);
		bool mu_eta = (std::abs(nt.Muon_eta()[imu]) < 2.4);	      		    		   
                bool mu_id = (nt.Muon_looseId()[imu]);  
		bool mu_isoID = (nt.Muon_pfIsoId()[imu] >= 1);
		bool mu_dz = (nt.Muon_dz()[imu] < 0.1);
		bool mu_dxy = (nt.Muon_dxy()[imu] < 0.05);
		bool mu_iso = (nt.Muon_pfRelIso03_all()[imu] < 0.4);
		bool mu_sip3d = (nt.Muon_sip3d()[imu] < 4);
		
		// Define the lepton ID for W and Z lepton candidates
		int mu_ID = 0;
        	mu_ID |= nt.Muon_mediumId()[imu] << 0;
        	mu_ID |= nt.Muon_tightId()[imu] << 1;
        	mu_ID |= nt.Muon_pfIsoId()[imu] << 2;
 
		bool mu_Zcand = ( mu_sip3d && ((mu_ID >> 2) >= 2));
		bool mu_Wcand = ( mu_sip3d && ((mu_ID >> 2) >= 3));

		int mu_njet_overlap = 0;
		for ( int ijet = 0; ijet < nt.nJet(); ijet++ ){
		      double dR_mu = ROOT::Math::VectorUtil::DeltaR(nt.Muon_p4()[imu],nt.Jet_p4()[ijet]);
		      //h_mu_jet_dR->Fill(dR_mu,fill_weight);
		      if ( dR_mu < 0.4 ) mu_njet_overlap++;
		}

 		if ( mu_njet_overlap > 1 ) continue;

                mu_pass_oldID = (mu_pt && mu_eta && mu_id && mu_isoID && mu_dz && mu_dxy && mu_iso && ( mu_Zcand || mu_Wcand ));
		if ( mu_pass_oldID ){
		     n_mu_old++;
		     //h_mu_pt_old->Fill(nt.Muon_pt()[imu],fill_weight);
                     //h_mu_eta_old->Fill(nt.Muon_eta()[imu],fill_weight);
                     //h_mu_jetNDauCharged_old->Fill(nt.Muon_jetNDauCharged()[imu],fill_weight);
                     //h_mu_miniPFRelIso_chg_old->Fill(nt.Muon_miniPFRelIso_chg()[imu],fill_weight);
                     //h_mu_miniPFRelIso_diff_all_chg_old->Fill(nt.Muon_miniPFRelIso_all()[imu]-nt.Muon_miniPFRelIso_chg()[imu],fill_weight);
                     //h_mu_jetPtRelv2_old->Fill(nt.Muon_jetPtRelv2()[imu],fill_weight);
                     //h_mu_jetPtRatio_old->Fill(1./(nt.Muon_jetRelIso()[imu] + 1.),fill_weight);
                     //h_mu_pfRelIso03_all_old->Fill(nt.Muon_pfRelIso03_all()[imu],fill_weight);
                     if ( nt.Muon_jetIdx()[imu] == -1 ){
                          //h_mu_btagDeepFlavB_old->Fill(0.,fill_weight);
                     }
                     else{
                          //h_mu_btagDeepFlavB_old->Fill(nt.Jet_btagDeepFlavB()[nt.Muon_jetIdx()[imu]],fill_weight);
                     }
                     //h_mu_sip3d_old->Fill(nt.Muon_sip3d()[imu],fill_weight);
                     //h_mu_logdxy_old->Fill(std::log(std::abs(nt.Muon_dxy()[imu])),fill_weight);
                     //h_mu_logdz_old->Fill(std::log(std::abs(nt.Muon_dz()[imu])),fill_weight);    
                     //h_mu_segmentComp_old->Fill(nt.Muon_segmentComp()[imu],fill_weight);
		}

		bool mu_newID_cut = MuonIDHelper::muonIDscore(nt.year(),imu,"tight",isAPV);
		if ( mu_newID_cut && mu_sip3d && mu_pt ){
		     n_mu_new++;
		     //h_mu_pt_new->Fill(nt.Muon_pt()[imu],fill_weight);
                     //h_mu_eta_new->Fill(nt.Muon_eta()[imu],fill_weight);
                     //h_mu_jetNDauCharged_new->Fill(nt.Muon_jetNDauCharged()[imu],fill_weight);
                     //h_mu_miniPFRelIso_chg_new->Fill(nt.Muon_miniPFRelIso_chg()[imu],fill_weight);
                     //h_mu_miniPFRelIso_diff_all_chg_new->Fill(nt.Muon_miniPFRelIso_all()[imu]-nt.Muon_miniPFRelIso_chg()[imu],fill_weight);
                     //h_mu_jetPtRelv2_new->Fill(nt.Muon_jetPtRelv2()[imu],fill_weight);
                     //h_mu_jetPtRatio_new->Fill(1./(nt.Muon_jetRelIso()[imu] + 1.),fill_weight);
                     //h_mu_pfRelIso03_all_new->Fill(nt.Muon_pfRelIso03_all()[imu],fill_weight);
                     if ( nt.Muon_jetIdx()[imu] == -1 ){
                         // h_mu_btagDeepFlavB_new->Fill(0.,fill_weight);
                     }
                     else{
                       //   h_mu_btagDeepFlavB_new->Fill(nt.Jet_btagDeepFlavB()[nt.Muon_jetIdx()[imu]],fill_weight);
                     }
                     //h_mu_sip3d_new->Fill(nt.Muon_sip3d()[imu],fill_weight);
                     //h_mu_logdxy_new->Fill(std::log(std::abs(nt.Muon_dxy()[imu])),fill_weight);
                     //h_mu_logdz_new->Fill(std::log(std::abs(nt.Muon_dz()[imu])),fill_weight);
                     //h_mu_segmentComp_new->Fill(nt.Muon_segmentComp()[imu],fill_weight);
		}

            }

	    if ( n_el_old + n_mu_old == 4 ){
		 if ( trig ) nEvents_old_trg += fill_weight;
		 if ( !trig ) nEvents_old_notrg += fill_weight;
	    }

	    if ( n_el_new + n_mu_new == 4 ){
		 if ( trig ) nEvents_new_trg += fill_weight;
		 if ( !trig ) nEvents_new_notrg += fill_weight;
	    }

        } // Event loop

	

        delete file;


    } // File loop
    bar.finish();

    std::cout << "Total number of events = " << total_events << std::endl;

    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "N events with 4 leptons passing old ID and trigger requirements: " << nEvents_old_trg << std::endl;
    std::cout << "N events with 4 leptons passing old ID and failing trigger requirements: " << nEvents_old_notrg << std::endl;
    std::cout << "Trigger efficiency (old ID) = " << nEvents_old_trg/nEvents_old_notrg << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
    std::cout << "N events with 4 leptons passing new ID and trigger requirements: " << nEvents_new_trg << std::endl;
    std::cout << "N events with 4 leptons passing new ID and failing trigger requirements: " << nEvents_new_notrg << std::endl;
    std::cout << "Trigger efficiency (new ID) = " << nEvents_new_trg/nEvents_new_notrg << std::endl;
    std::cout << "--------------------------------------------------------------------------------------------" << std::endl;

    TFile* f1 = new TFile("output_checkBDT/"+year+"/output_"+process+".root", "RECREATE");

    //h_el_pt_raw->Write();
    //h_el_eta_raw->Write();
    //h_el_jetNDauCharged_raw->Write();
    //h_el_miniPFRelIso_chg_raw->Write();
    //h_el_miniPFRelIso_diff_all_chg_raw->Write();
    //h_el_jetPtRelv2_raw->Write();
    //h_el_jetPtRatio_raw->Write();
    //h_el_pfRelIso03_all_raw->Write();
    //h_el_btagDeepFlavB_raw->Write();
    //h_el_sip3d_raw->Write();
    //h_el_logdxy_raw->Write();
    //h_el_logdz_raw->Write();
 
    //h_el_pt_old->Write();
    //h_el_eta_old->Write();
    //h_el_jetNDauCharged_old->Write();
    //h_el_miniPFRelIso_chg_old->Write();
    //h_el_miniPFRelIso_diff_all_chg_old->Write();
    //h_el_jetPtRelv2_old->Write();
    //h_el_jetPtRatio_old->Write();
    //h_el_pfRelIso03_all_old->Write();
    //h_el_btagDeepFlavB_old->Write();
    //h_el_sip3d_old->Write();
    //h_el_logdxy_old->Write();
    //h_el_logdz_old->Write();   
 
    //h_el_pt_new->Write();
    //h_el_eta_new->Write();
    //h_el_jetNDauCharged_new->Write();
    //h_el_miniPFRelIso_chg_new->Write();
    //h_el_miniPFRelIso_diff_all_chg_new->Write();
    //h_el_jetPtRelv2_new->Write();
    //h_el_jetPtRatio_new->Write();
    //h_el_pfRelIso03_all_new->Write();
    //h_el_btagDeepFlavB_new->Write();
    //h_el_sip3d_new->Write();
    //h_el_logdxy_new->Write();
    //h_el_logdz_new->Write();

    //h_mu_pt_raw->Write();
    //h_mu_eta_raw->Write();
    //h_mu_jetNDauCharged_raw->Write();
    //h_mu_miniPFRelIso_chg_raw->Write();
    //h_mu_miniPFRelIso_diff_all_chg_raw->Write();
    //h_mu_jetPtRelv2_raw->Write();
    //h_mu_jetPtRatio_raw->Write();
    //h_mu_pfRelIso03_all_raw->Write();
    //h_mu_btagDeepFlavB_raw->Write();
    //h_mu_sip3d_raw->Write();
    //h_mu_logdxy_raw->Write();
    //h_mu_logdz_raw->Write();
    //h_mu_segmentComp_raw->Write();

    //h_mu_pt_old->Write();
    //h_mu_eta_old->Write();
    //h_mu_jetNDauCharged_old->Write();
    //h_mu_miniPFRelIso_chg_old->Write();
    //h_mu_miniPFRelIso_diff_all_chg_old->Write();
    //h_mu_jetPtRelv2_old->Write();
    //h_mu_jetPtRatio_old->Write();
    //h_mu_pfRelIso03_all_old->Write();
    //h_mu_btagDeepFlavB_old->Write();
    //h_mu_sip3d_old->Write();
    //h_mu_logdxy_old->Write();
    //h_mu_logdz_old->Write();
    //h_mu_segmentComp_old->Write();

    //h_mu_pt_new->Write();
    //h_mu_eta_new->Write();
    //h_mu_jetNDauCharged_new->Write();
    //h_mu_miniPFRelIso_chg_new->Write();
    //h_mu_miniPFRelIso_diff_all_chg_new->Write();
    //h_mu_jetPtRelv2_new->Write();
    //h_mu_jetPtRatio_new->Write();
    //h_mu_pfRelIso03_all_new->Write();
    //h_mu_btagDeepFlavB_new->Write();
    //h_mu_sip3d_new->Write();
    //h_mu_logdxy_new->Write();
    //h_mu_logdz_new->Write();
    //h_mu_segmentComp_new->Write();

    //h_el_jet_dR->Write();
    //h_mu_jet_dR->Write();
    //h_weights->Write();

    f1->Write();
    f1->Close();

    //delete h_el_pt_raw;
    //delete h_el_eta_raw;
    //delete h_el_jetNDauCharged_raw;
    //delete h_el_miniPFRelIso_chg_raw;
    //delete h_el_miniPFRelIso_diff_all_chg_raw;
    //delete h_el_jetPtRelv2_raw;
    //delete h_el_jetPtRatio_raw;
    //delete h_el_pfRelIso03_all_raw;
    //delete h_el_btagDeepFlavB_raw;
    //delete h_el_sip3d_raw;
    //delete h_el_logdxy_raw;
    //delete h_el_logdz_raw;   

    //delete h_el_pt_old;
    //delete h_el_eta_old;
    //delete h_el_jetNDauCharged_old;
    //delete h_el_miniPFRelIso_chg_old;
    //delete h_el_miniPFRelIso_diff_all_chg_old;
    //delete h_el_jetPtRelv2_old;
    //delete h_el_jetPtRatio_old;
    //delete h_el_pfRelIso03_all_old;
    //delete h_el_btagDeepFlavB_old;
    //delete h_el_sip3d_old;
    //delete h_el_logdxy_old;
    //delete h_el_logdz_old;

    //delete h_el_pt_new;
    //delete h_el_eta_new;
    //delete h_el_jetNDauCharged_new;
    //delete h_el_miniPFRelIso_chg_new;
    //delete h_el_miniPFRelIso_diff_all_chg_new;
    //delete h_el_jetPtRelv2_new;
    //delete h_el_jetPtRatio_new;
    //delete h_el_pfRelIso03_all_new;
    //delete h_el_btagDeepFlavB_new;
    //delete h_el_sip3d_new;
    //delete h_el_logdxy_new;
    //delete h_el_logdz_new;

    //delete h_mu_pt_raw;
    //delete h_mu_eta_raw;
    //delete h_mu_jetNDauCharged_raw;
    //delete h_mu_miniPFRelIso_chg_raw;
    //delete h_mu_miniPFRelIso_diff_all_chg_raw;
    //delete h_mu_jetPtRelv2_raw;
    //delete h_mu_jetPtRatio_raw;
    //delete h_mu_pfRelIso03_all_raw;
    //delete h_mu_btagDeepFlavB_raw;
    //delete h_mu_sip3d_raw;
    //delete h_mu_logdxy_raw;
    //delete h_mu_logdz_raw;  
    //delete h_mu_segmentComp_raw;

    //delete h_mu_pt_old;
    //delete h_mu_eta_old;
    //delete h_mu_jetNDauCharged_old;
    //delete h_mu_miniPFRelIso_chg_old;
    //delete h_mu_miniPFRelIso_diff_all_chg_old;
    //delete h_mu_jetPtRelv2_old;
    //delete h_mu_jetPtRatio_old;
    //delete h_mu_pfRelIso03_all_old;
    //delete h_mu_btagDeepFlavB_old;
    //delete h_mu_sip3d_old;
    //delete h_mu_logdxy_old;
    //delete h_mu_logdz_old;
    //delete h_mu_segmentComp_old;

    //delete h_mu_pt_new;
    //delete h_mu_eta_new;
    //delete h_mu_jetNDauCharged_new;
    //delete h_mu_miniPFRelIso_chg_new;
    //delete h_mu_miniPFRelIso_diff_all_chg_new;
    //delete h_mu_jetPtRelv2_new;
    //delete h_mu_jetPtRatio_new;
    //delete h_mu_pfRelIso03_all_new;
    //delete h_mu_btagDeepFlavB_new;
    //delete h_mu_sip3d_new;
    //delete h_mu_logdxy_new;
    //delete h_mu_logdz_new;
    //delete h_mu_segmentComp_new;

    //delete h_el_jet_dR;
    //delete h_mu_jet_dR;
    //delete h_weights;

    return 0;
}
