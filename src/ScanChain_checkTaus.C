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

    TH1D *h_nLooseEl = new TH1D("h_nLooseEl","h_nLooseEl",8,0,8);
    TH1D *h_nLooseMu = new TH1D("h_nLooseMu","h_nLooseMu",8,0,8);
    TH1D *h_nLooseLep = new TH1D("h_nLooseLep","h_nLooseLep",8,0,8);
    TH1D *h_nTightEl = new TH1D("h_nTightEl","h_nTightEl",8,0,8);
    TH1D *h_nTightMu = new TH1D("h_nTightMu","h_nTightMu",8,0,8);
    TH1D *h_nTightLep = new TH1D("h_nTightLep","h_nTightLep",8,0,8);
    TH1D *h_nLNTEl = new TH1D("h_nLNTEl","h_nLNTEl",8,0,8);
    TH1D *h_nLNTMu = new TH1D("h_nLNTMu","h_nLNTMu",8,0,8);
    TH1D *h_nLNTLep = new TH1D("h_nLNTLep","h_nLNTLep",8,0,8);
    TH1D *h_nTNLEl = new TH1D("h_nTNLEl","h_nTNLEl",8,0,8);
    TH1D *h_nTNLMu = new TH1D("h_nTNLMu","h_nTNLMu",8,0,8);
    TH1D *h_nTNLLep = new TH1D("h_nTNLLep","h_nTNLLep",8,0,8);
    TH1D *h_nLTEl = new TH1D("h_nLTEl","h_nLTEl",8,0,8);
    TH1D *h_nLTMu = new TH1D("h_nLTMu","h_nLTMu",8,0,8);
    TH1D *h_nLTLep = new TH1D("h_nLTLep","h_nLTLep",8,0,8);
    TH1D *h_nTau = new TH1D("h_nTau","h_nTau",8,0,8);

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

    float nEvents_4lep = 0.;
    float nEvents_4lepTau = 0.;
    float nEvents_3lepTau = 0.;
    float nEvents_3lep = 0.;
    float nEvents_total = 0.;

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
	    float fill_weight = ((lumi*weight*xsec)/genWeightSum);

	    int nLooseEl = 0;
            int nTightEl = 0;
	    int nLNT_El = 0;
            int nTNL_El = 0;
	    int nLT_El = 0;
	    int nLooseMu = 0;
	    int nTightMu = 0;
            int nLNT_Mu = 0;
            int nTNL_Mu = 0;
            int nLT_Mu = 0;
	    int nTaus = 0;
	    for ( unsigned int iel = 0; iel < nt.nElectron(); iel++ ){
		  bool pass_loose = false;
		  bool pass_tight = false;
		  if (ElectronIDHelper::electronIDscore(2018,iel,"tight",isAPV)){
		      nTightEl++;
		      pass_tight = true;
		  }
		  if ( not (nt.Electron_pt()[iel] > 10.)) continue;
		  if ( not (std::abs(nt.Electron_eta()[iel]) < 2.5)) continue;
		  if ( not (nt.Electron_pfRelIso03_all()[iel] < 0.4)) continue;
		  if ( not (std::abs(nt.Electron_dz()[iel]) < 0.1)) continue;
		  if ( not (std::abs(nt.Electron_dxy()[iel]) < 0.05)) continue;
		  nLooseEl++;
		  pass_loose = true;

		  if ( pass_loose && !pass_tight ) nLNT_El++;
		  if ( !pass_loose && pass_tight ) nTNL_El++;
		  if ( pass_loose && pass_tight ) nLT_El++;

	    }
	    for ( unsigned int imu = 0; imu < nt.nMuon(); imu++ ){
		  bool pass_loose = false;
		  bool pass_tight = false;
		  if (MuonIDHelper::muonIDscore(2018,imu,"tight",isAPV)){
		      nTightMu++;
		      pass_tight = true;
		  }
		  if ( not (nt.Muon_pt()[imu] > 10.) ) continue;
		  if ( not (std::abs(nt.Muon_eta()[imu]) < 2.4) ) continue;
		  if ( not (std::abs(nt.Muon_dz()[imu]) < 0.1) ) continue;
		  if ( not (std::abs(nt.Muon_dxy()[imu]) < 0.05) ) continue;
		  if ( not (nt.Muon_mediumId()[imu]) ) continue;
		  nLooseMu++;
		  pass_loose = true;

		  if ( pass_loose && !pass_tight ) nLNT_Mu++;
		  if ( !pass_loose && pass_tight ) nTNL_Mu++;
		  if ( pass_loose && pass_tight ) nLT_Mu++;	  

	    }
	    for ( unsigned int itau = 0; itau < nt.nTau(); itau++ ){
	          if (not (nt.Tau_pt()[itau] > 20.)) continue;
	          if (not (std::abs(nt.Tau_eta()[itau]) < 2.3)) continue;
	          if (not (std::abs(nt.Tau_dz()[itau]) < 0.2)) continue;
                  if (not (nt.Tau_idDeepTau2017v2p1VSe()[itau] >= 0)) continue;
		  if (not (nt.Tau_idDeepTau2017v2p1VSmu()[itau] >= 0)) continue;
		  if (not (nt.Tau_idDeepTau2017v2p1VSjet()[itau] >= 0)) continue;
	          nTaus++;
	    }

	    int nLLs = nTightEl+nTightMu;

	    h_nLooseEl->Fill(nLooseEl,fill_weight);
	    h_nLooseMu->Fill(nLooseMu,fill_weight);
	    h_nLooseLep->Fill(nLooseEl+nLooseMu,fill_weight);
	    h_nTightEl->Fill(nTightEl,fill_weight);
	    h_nTightMu->Fill(nTightMu,fill_weight);
 	    h_nTightLep->Fill(nTightEl+nTightMu,fill_weight);
	    h_nLNTEl->Fill(nLNT_El,fill_weight);
	    h_nLNTMu->Fill(nLNT_Mu,fill_weight);
	    h_nLNTLep->Fill(nLNT_El+nLNT_Mu,fill_weight);
	    h_nTNLEl->Fill(nTNL_El,fill_weight);
            h_nTNLMu->Fill(nTNL_Mu,fill_weight);
            h_nTNLLep->Fill(nTNL_El+nTNL_Mu,fill_weight);
	    h_nLTEl->Fill(nLT_El,fill_weight);
            h_nLTMu->Fill(nLT_Mu,fill_weight);
            h_nLTLep->Fill(nLT_El+nLT_Mu,fill_weight);
	    h_nTau->Fill(nTaus,fill_weight);
	    
	    
	    nEvents_total += fill_weight;

	    if (nLLs==4 && nTaus==0) nEvents_4lep += fill_weight;
	    if (nLLs==4 && nTaus>0) nEvents_4lepTau += fill_weight;
	    if (nLLs==3 && nTaus>0) nEvents_3lepTau += fill_weight;
	    if (nLLs==3 && nTaus==0){ 
	        nEvents_3lep += fill_weight;
	        //std::cout << "Run = " << nt.run() << " , Lumi block = " << nt.luminosityBlock() << " , Event = " << nt.event() << std::endl;
	        //std::cout << "Weight = " << fill_weight << std::endl;
	        //std::cout << "nElectrons = " << nElectrons << " , nMuons = " << nMuons << std::endl;
	    }

        } // Event loop
	

        delete file;


    } // File loop
    bar.finish();

    TFile* f = new TFile("output_taus/output_checkTaus_"+process+".root", "RECREATE");

    h_nLooseEl->Write();
    h_nLooseMu->Write();
    h_nLooseLep->Write();
    h_nTightEl->Write();
    h_nTightMu->Write();
    h_nTightLep->Write();
    h_nLNTEl->Write();
    h_nLNTMu->Write();
    h_nLNTLep->Write();
    h_nTNLEl->Write();
    h_nTNLMu->Write();
    h_nTNLLep->Write();
    h_nLTEl->Write();
    h_nLTMu->Write();
    h_nLTLep->Write();
    h_nTau->Write();

    f->Write();
    f->Close();

    delete h_nLooseEl;
    delete h_nLooseMu;
    delete h_nLooseLep;
    delete h_nTightEl;
    delete h_nTightMu;
    delete h_nTightLep;
    delete h_nLNTEl;
    delete h_nLNTMu;
    delete h_nLNTLep;
    delete h_nTNLEl;
    delete h_nTNLMu;
    delete h_nTNLLep;
    delete h_nLTEl;
    delete h_nLTMu;
    delete h_nLTLep;
    delete h_nTau;

    std::cout << "Total number of events = " << nEvents_total << std::endl;
    std::cout << "Number of events with 4 leptons + taus = " << nEvents_4lepTau << std::endl;
    std::cout << "Number of events with 4 leptons = " << nEvents_4lep << std::endl;
    std::cout << "Number of events with 3 leptons + taus = " << nEvents_3lepTau << std::endl;
    std::cout << "Number of events with 3 leptons = " << nEvents_3lep << std::endl;

    return 0;
}
