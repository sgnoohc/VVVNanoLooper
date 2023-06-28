#include <stdio.h>

TFile *convert_txt_to_root(TString input, TString output, int nlines){

      Int_t isSignal;
      Int_t Njets;
      Int_t Njets_in;
      Int_t Njets_out;
      Double_t leading_jet_pt;
      Double_t leading_jet_eta;
      Double_t min_mlj;
      Float_t evt_weight;
      Int_t SRBin;

      TString dir = "output_newID_jetCounting/Run2/";
      TString filename = output+".root";
      FILE *fp = fopen(dir+input,"r");

      TFile *hfile = TFile::Open(filename,"RECREATE");
      //std::cout << "Opened file with name " << filename << std::endl;
      TTree *tree = new TTree("T","Jet variables");
      //std::cout << "Initialized tree T" << std::endl;
      tree->Branch("isSignal",&isSignal,"isSignal/I");
      tree->Branch("Njets",&Njets,"Njets/I");
      tree->Branch("Njets_in",&Njets_in,"Njets_in/I");
      tree->Branch("Njets_out",&Njets_out,"Njets_out/I");
      tree->Branch("leading_jet_pt",&leading_jet_pt,"leading_jet_pt/D");
      tree->Branch("leading_jet_eta",&leading_jet_eta,"leading_jet_eta/D");
      tree->Branch("min_mlj",&min_mlj,"min_mlj/D");
      tree->Branch("SRBin",&SRBin,"SRBin/I");
      tree->Branch("evt_weight",&evt_weight,"evt_weight/F");
      //std::cout << "Defined branches in tree" << std::endl;
      char line[nlines];
      //std::cout << "Defined line[nlines]" << std::endl;
      int i = 0;
      while (fgets(line,nlines,fp)){
	 i++;
	 //std::cout << "i = " << i << std::endl;
	 sscanf(line,"%i  %i  %i  %i  %lf  %lf  %lf  %i  %f",&isSignal,&Njets,&Njets_in,&Njets_out,&leading_jet_pt,&leading_jet_eta,&min_mlj,&SRBin,&evt_weight);
	 //std::cout << "line = " << line << std::endl;
	 //std::cout << " is Signal = " << &isSignal << std::endl; 
	 tree->Fill();
      }

      tree->Print();
      tree->Write();

      fclose(fp);
      return hfile;

}
