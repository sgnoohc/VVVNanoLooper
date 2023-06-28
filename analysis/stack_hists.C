void stack_hists(){

     THStack *hs = new THStack("hs","Stacked histogram");
     TString filename = "outputs/Run2/data.root";
     TFile *file = TFile::Open(filename,"READ");
     TH1D *h = (TH1D*)file->Get("CutEMuMT2__SRBin"); 

     hs->Add(h);

     TCanvas *cs = new TCanvas("cs","cs",10,10,1400,900);

     cs->cd();

     hs->Draw("hist");
     
}
