#include <array>
#include "Riostream.h"

double get_xsec(TString sample){

     double xsec;
     std::ifstream f("xsecs.txt");
     std::string line;
     while (std::getline(f, line)){
        TString col1;
        double col2;
        std::istringstream ss(line);
        ss >> col1 >> col2;
        //std::cout << "Column 1 = " << col1 << " Column 2 = " << col2 << endl;
        if(sample == col1){
           xsec = 1000.*col2; // Convert from pb to fb
        } 
     }

     return xsec;
}

void plot_hists(TString histname, TString year){

     //read_file();

     TString dir = "/home/users/kdownham/Triboson/VVVNanoLooper/output/";
     TString fullpath = dir+year+"/";

     double lumi = 0;
     if ( year == "2016" ) lumi = 35.9;
     if ( year == "2017" ) lumi = 41.3;
     if ( year == "2018" ) lumi = 59.7;

     //std::vector<TString> samples = {"WWZ","ZZ","ZZContTo2e2mu","ZZContTo2e2nu","ZZContTo2e2tau","ZZContTo2mu2tau","ZZContTo4e","ZZContTo2mu2nu","ZZContTo4mu","ZZContTo4tau","ZZTo2L2Nu","ZZTo2Q2L","ZZTo2Q2Nu"};

     std::vector<TString> ZZ_samples = {"ZZ","ZZContTo2e2mu","ZZContTo2e2tau","ZZContTo2mu2tau","ZZContTo4mu","ZZContTo4e","ZZContTo4tau","ZZTo2L2Nu","ZZTo2Q2L"};


     //TH1D** array = new TH1D*[nhist];
     //std::vector<TH1D> hlist;
     THStack *hs = new THStack("hs", histname);
     TLegend *legend = new TLegend(0.60,0.60,0.90,0.90,"","NDC");
     legend->SetBorderSize(0);
     legend->SetTextFont(43);
     legend->SetTextAlign(12);
     legend->SetLineColor(1);
     legend->SetLineStyle(1);
     legend->SetLineWidth(1);
     legend->SetFillColor(0);
     legend->SetFillStyle(0);


     // Get and scale histogram for signal

     TFile *f_sig = new TFile(fullpath+"WWZ.root","READ");
     TH1D *h_wgt_sig = (TH1D*)f_sig->Get("Wgt__h_nevents");
     double n_eff_events_sig = h_wgt_sig->GetBinContent(1);
     TH1D *h_sig = (TH1D*)f_sig->Get(histname);
     double xsec_sig = get_xsec("WWZ");
     double factor_sig = xsec_sig * lumi / n_eff_events_sig;
     h_sig->SetFillColor(kRed);
     h_sig->Scale(factor_sig);
     double yield_sig = h_sig->Integral();
     hs->Add(h_sig);  
     legend->AddEntry(h_sig,"WWZ","f");

     double ZZ_yield = 0.0;

     // Get and scale histograms for ZZ backgrounds

     for ( auto i : ZZ_samples ){
           std::cout << "Sample = " << i << endl;
           TFile *f = new TFile(fullpath+i+".root","READ");
           TH1D *h_wgt = (TH1D*)f->Get("Wgt__h_nevents");
           double n_eff_evts = h_wgt->GetBinContent(1);
           TH1D *h = (TH1D*)f->Get(histname);
           // Do scaling here
           double x_sec = get_xsec(i);
           double factor = x_sec * lumi / n_eff_evts;
           h->SetFillColor(kBlue);
           h->Scale(factor);
           double yield = h->Integral();
           hs->Add(h);
           if (i == "ZZ") legend->AddEntry(h,i,"f");
           ZZ_yield += yield;
           
     }


     hs->Draw("hist");
     legend->Draw();

     std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
     std::cout << " Signal yield = " << yield_sig << endl;
     std::cout << " ZZ background yield = " << ZZ_yield << endl;
     std::cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;    


     return 0;
}

