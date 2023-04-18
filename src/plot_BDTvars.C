void plot_BDTvars(TString hist, TString year, TString lep){
 
     TString dir = "output_checkBDT/"+year+"/";
     TString signal = "output_signal.root";
     TString ZZ = "output_ZZ.root";

     TFile* file_signal = TFile::Open(dir+signal,"READ");
     TFile* file_ZZ = TFile::Open(dir+ZZ,"READ");

     THStack *hs_raw = new THStack("hs_raw","Normalized Histogram Raw ("+year+");"+hist+" "+lep+";Events / Total"); 
     THStack *hs_old = new THStack("hs_old","Normalized Histogram Old ID ("+year+");"+hist+" "+lep+";Events / Total");
     THStack *hs_new = new THStack("hs_new","Normalized Histogram New ID ("+year+");"+hist+" "+lep+";Events / Total");
     THStack *hs_ratio = new THStack("hs_ratio","Ratio (old/new) ("+year+");"+hist+" "+lep+";Ratio (old/new)");

     TH1D *h_raw_signal = (TH1D*)file_signal->Get("h_"+lep+"_"+hist+"_raw");
     TH1D *h_old_signal = (TH1D*)file_signal->Get("h_"+lep+"_"+hist+"_old");
     TH1D *h_new_signal = (TH1D*)file_signal->Get("h_"+lep+"_"+hist+"_new");

     TH1D *h_raw_ZZ = (TH1D*)file_ZZ->Get("h_"+lep+"_"+hist+"_raw"); 
     TH1D *h_old_ZZ = (TH1D*)file_ZZ->Get("h_"+lep+"_"+hist+"_old");
     TH1D *h_new_ZZ = (TH1D*)file_ZZ->Get("h_"+lep+"_"+hist+"_new");

     TCanvas *cs1 = new TCanvas("cs1","cs1",10,10,1400,900);
     cs1->Divide(2,2); 

     TLegend* legend = new TLegend(0.60,0.60,0.90,0.90,"","NDC");
     legend->SetBorderSize(0);
     legend->SetTextFont(43);
     legend->SetTextAlign(12);
     legend->SetLineColor(1);
     legend->SetLineStyle(1);
     legend->SetLineWidth(1);
     legend->SetFillColor(0);
     legend->SetFillStyle(0);

     double raw_signal_yield = h_raw_signal->Integral();
     double raw_ZZ_yield = h_raw_ZZ->Integral();

     h_raw_signal->Scale(1./h_raw_signal->Integral());
     h_raw_signal->SetLineColor(kBlue);
     hs_raw->Add(h_raw_signal);
     legend->AddEntry(h_raw_signal,TString::Format("WWZ (%g)",raw_signal_yield),"f");
     h_raw_ZZ->Scale(1./h_raw_ZZ->Integral());
     h_raw_ZZ->SetLineColor(kRed);
     hs_raw->Add(h_raw_ZZ);
     legend->AddEntry(h_raw_ZZ,TString::Format("ZZ (%g)",raw_ZZ_yield),"f");

     cs1->cd(3);
     hs_raw->Draw("nostack hist");
     legend->Draw();

     TLegend* legend1 = new TLegend(0.60,0.60,0.90,0.90,"","NDC");
     legend1->SetBorderSize(0);
     legend1->SetTextFont(43);
     legend1->SetTextAlign(12);
     legend1->SetLineColor(1);
     legend1->SetLineStyle(1);
     legend1->SetLineWidth(1);
     legend1->SetFillColor(0);
     legend1->SetFillStyle(0);

     double old_signal_yield = h_old_signal->Integral();
     double old_ZZ_yield = h_old_ZZ->Integral();
 
     TH1D* h_ratio_signal = (TH1D*)h_old_signal->Clone("h_ratio_signal");
     h_ratio_signal->Divide(h_new_signal);
     TH1D* h_ratio_ZZ = (TH1D*)h_old_ZZ->Clone("h_ratio_ZZ");
     h_ratio_ZZ->Divide(h_new_ZZ);
     h_old_signal->Scale(1./h_old_signal->Integral());
     h_old_signal->SetLineColor(kBlue);
     hs_old->Add(h_old_signal);
     legend1->AddEntry(h_old_signal,TString::Format("WWZ (%g)",old_signal_yield),"f");
     h_old_ZZ->Scale(1./h_old_ZZ->Integral());
     h_old_ZZ->SetLineColor(kRed);
     hs_old->Add(h_old_ZZ);
     legend1->AddEntry(h_old_ZZ,TString::Format("ZZ (%g)",old_ZZ_yield),"f");

     cs1->cd(1);
     hs_old->Draw("nostack hist");
     legend1->Draw();

     TLegend* legend2 = new TLegend(0.60,0.60,0.90,0.90,"","NDC");
     legend2->SetBorderSize(0);
     legend2->SetTextFont(43);
     legend2->SetTextAlign(12);
     legend2->SetLineColor(1);
     legend2->SetLineStyle(1);
     legend2->SetLineWidth(1);
     legend2->SetFillColor(0);
     legend2->SetFillStyle(0);

     double new_signal_yield = h_new_signal->Integral();
     double new_ZZ_yield = h_new_ZZ->Integral();

     h_new_signal->Scale(1./h_new_signal->Integral());
     h_new_signal->SetLineColor(kBlue);
     hs_new->Add(h_new_signal);
     legend2->AddEntry(h_new_signal,TString::Format("WWZ (%g)",new_signal_yield),"f");
     h_new_ZZ->Scale(1./h_new_ZZ->Integral());
     h_new_ZZ->SetLineColor(kRed);
     hs_new->Add(h_new_ZZ);
     legend2->AddEntry(h_new_ZZ,TString::Format("ZZ (%g)",new_ZZ_yield),"f");

     cs1->cd(2);
     hs_new->Draw("nostack hist");
     legend2->Draw();

     TLegend* legend3 = new TLegend(0.60,0.10,0.90,0.40,"","NDC");
     legend3->SetBorderSize(0);
     legend3->SetTextFont(43);
     legend3->SetTextAlign(12);
     legend3->SetLineColor(1);
     legend3->SetLineStyle(1);
     legend3->SetLineWidth(1);
     legend3->SetFillColor(0);
     legend3->SetFillStyle(0);

     double ratio_signal_yield = (old_signal_yield/new_signal_yield);
     double ratio_ZZ_yield = (old_ZZ_yield/new_ZZ_yield); 

     //TH1D* h_ratio_signal = (TH1D*)h_old_signal->Clone("h_ratio_signal");
     //h_ratio_signal->Divide(h_new_signal);
     h_ratio_signal->SetLineColor(kBlue);
     hs_ratio->Add(h_ratio_signal);
     legend3->AddEntry(h_ratio_signal,TString::Format("WWZ (%g)",ratio_signal_yield),"f");     
     //TH1D* h_ratio_ZZ = (TH1D*)h_old_ZZ->Clone("h_ratio_ZZ");
     //h_ratio_ZZ->Divide(h_new_ZZ);
     h_ratio_ZZ->SetLineColor(kRed);
     hs_ratio->Add(h_ratio_ZZ);
     legend3->AddEntry(h_ratio_ZZ,TString::Format("ZZ (%g)",ratio_ZZ_yield),"f");

     cs1->cd(4);
     hs_ratio->SetMinimum(0.5);
     hs_ratio->SetMaximum(1.5);
     hs_ratio->Draw("nostack hist");
     legend3->Draw();    

     cs1->Print("../../../public_html/WWZ/lepton_ID_study/checkBDT_overlapRemoval/"+year+"/"+hist+"_"+lep+"_unitNorm.png");    
 
}
