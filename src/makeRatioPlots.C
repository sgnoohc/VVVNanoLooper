void makeRatioPlots(TString year){

     TString dir = "output_lepID/"+year+"/";
     TString signal = "output_signal.root";
     TString ZZ = "output_ZZ.root";

     TLegend* legend = new TLegend(0.60,0.10,0.90,0.40,"","NDC");
     legend->SetBorderSize(0);
     legend->SetTextFont(43);
     legend->SetTextAlign(12);
     legend->SetLineColor(1);
     legend->SetLineStyle(1);
     legend->SetLineWidth(1);
     legend->SetFillColor(0);
     legend->SetFillStyle(0);

     THStack *hs_mu_new_pt = new THStack("hs_mu_new_pt","Muon efficiency for new ID ("+year+");p_{T} [GeV];Efficiency / bin");
     THStack *hs_mu_old_pt = new THStack("hs_mu_old_pt","Muon efficiency for old ID ("+year+");p_{T} [GeV];Efficiency / bin");
     THStack *hs_el_new_pt = new THStack("hs_el_new_pt","Electron efficiency for new ID ("+year+");p_{T} [GeV];Efficiency / bin");
     THStack *hs_el_old_pt = new THStack("hs_el_old_pt","Electron efficiency for old ID ("+year+");p_{T} [GeV];Efficiency / bin");
     THStack *hs_mu_new_eta = new THStack("hs_mu_new_eta","Muon efficiency for new ID ("+year+");#eta;Efficiency / bin");
     THStack *hs_mu_old_eta = new THStack("hs_mu_old_eta","Muon efficiency for old ID ("+year+");#eta;Efficiency / bin");
     THStack *hs_el_new_eta = new THStack("hs_el_new_eta","Electron efficiency for new ID ("+year+");#eta;Efficiency / bin");
     THStack *hs_el_old_eta = new THStack("hs_el_old_eta","Electron efficiency for old ID ("+year+");#eta;Efficiency / bin");

     TFile* file_signal = TFile::Open(dir+signal,"READ");
     TFile* file_ZZ = TFile::Open(dir+ZZ,"READ");

     TH1D *h_gen_mu_pt_signal = (TH1D*)file_signal->Get("h_gen_mu_pt");
     TH1D *h_gen_mu_pt_ZZ = (TH1D*)file_ZZ->Get("h_gen_mu_pt");
     TH1D *h_gen_el_pt_signal = (TH1D*)file_signal->Get("h_gen_el_pt");
     TH1D *h_gen_el_pt_ZZ = (TH1D*)file_ZZ->Get("h_gen_el_pt");
     TH1D *h_gen_mu_eta_signal = (TH1D*)file_signal->Get("h_gen_mu_eta");
     TH1D *h_gen_mu_eta_ZZ = (TH1D*)file_ZZ->Get("h_gen_mu_eta");
     TH1D *h_gen_el_eta_signal = (TH1D*)file_signal->Get("h_gen_el_eta");
     TH1D *h_gen_el_eta_ZZ = (TH1D*)file_ZZ->Get("h_gen_el_eta");

     TH1D *h_old_mu_pt_signal = (TH1D*)file_signal->Get("h_oldID_gen_mu_pt");
     TH1D *h_old_mu_pt_ZZ = (TH1D*)file_ZZ->Get("h_oldID_gen_mu_pt");
     TH1D *h_old_el_pt_signal = (TH1D*)file_signal->Get("h_oldID_gen_el_pt");
     TH1D *h_old_el_pt_ZZ = (TH1D*)file_ZZ->Get("h_oldID_gen_el_pt");
     TH1D *h_old_mu_eta_signal = (TH1D*)file_signal->Get("h_oldID_gen_mu_eta");
     TH1D *h_old_mu_eta_ZZ = (TH1D*)file_ZZ->Get("h_oldID_gen_mu_eta");
     TH1D *h_old_el_eta_signal = (TH1D*)file_signal->Get("h_oldID_gen_el_eta");
     TH1D *h_old_el_eta_ZZ = (TH1D*)file_ZZ->Get("h_oldID_gen_el_eta"); 

     TH1D *h_new_mu_pt_signal = (TH1D*)file_signal->Get("h_newID_gen_mu_pt");
     TH1D *h_new_mu_pt_ZZ = (TH1D*)file_ZZ->Get("h_newID_gen_mu_pt");
     TH1D *h_new_el_pt_signal = (TH1D*)file_signal->Get("h_newID_gen_el_pt");
     TH1D *h_new_el_pt_ZZ = (TH1D*)file_ZZ->Get("h_newID_gen_el_pt");
     TH1D *h_new_mu_eta_signal = (TH1D*)file_signal->Get("h_newID_gen_mu_eta");
     TH1D *h_new_mu_eta_ZZ = (TH1D*)file_ZZ->Get("h_newID_gen_mu_eta");
     TH1D *h_new_el_eta_signal = (TH1D*)file_signal->Get("h_newID_gen_el_eta");
     TH1D *h_new_el_eta_ZZ = (TH1D*)file_ZZ->Get("h_newID_gen_el_eta");

     TCanvas *cs1 = new TCanvas("cs","cs",10,10,1400,900);
     cs1->Divide(2,2);

     h_old_mu_pt_signal->Divide(h_gen_mu_pt_signal);
     h_old_mu_pt_signal->SetLineColor(kBlue);
     h_old_mu_pt_ZZ->Divide(h_gen_mu_pt_ZZ);
     h_old_mu_pt_ZZ->SetLineColor(kRed);
     hs_mu_old_pt->Add(h_old_mu_pt_signal);
     legend->AddEntry(h_old_mu_pt_signal,"WWZ","f");
     hs_mu_old_pt->Add(h_old_mu_pt_ZZ);
     legend->AddEntry(h_old_mu_pt_ZZ,"ZZ","f");       

     cs1->cd(1);
     hs_mu_old_pt->SetMinimum(0.);
     hs_mu_old_pt->SetMaximum(1.);
     hs_mu_old_pt->Draw("nostack hist"); 
     legend->Draw();

     TLegend* legend1 = new TLegend(0.60,0.10,0.90,0.40,"","NDC");
     legend1->SetBorderSize(0);
     legend1->SetTextFont(43);
     legend1->SetTextAlign(12);
     legend1->SetLineColor(1);
     legend1->SetLineStyle(1);
     legend1->SetLineWidth(1);
     legend1->SetFillColor(0);
     legend1->SetFillStyle(0);
     
     h_new_mu_pt_signal->Divide(h_gen_mu_pt_signal);
     h_new_mu_pt_signal->SetLineColor(kBlue);
     h_new_mu_pt_ZZ->Divide(h_gen_mu_pt_ZZ);
     h_new_mu_pt_ZZ->SetLineColor(kRed);
     hs_mu_new_pt->Add(h_new_mu_pt_signal);
     legend1->AddEntry(h_new_mu_pt_signal,"WWZ","f");
     hs_mu_new_pt->Add(h_new_mu_pt_ZZ);
     legend1->AddEntry(h_new_mu_pt_ZZ,"ZZ","f");

     cs1->cd(2);
     hs_mu_new_pt->SetMinimum(0.);
     hs_mu_new_pt->SetMaximum(1.);
     hs_mu_new_pt->Draw("nostack hist");
     legend1->Draw();

     TLegend* legend2 = new TLegend(0.60,0.10,0.90,0.40,"","NDC");
     legend2->SetBorderSize(0);
     legend2->SetTextFont(43);
     legend2->SetTextAlign(12);
     legend2->SetLineColor(1);
     legend2->SetLineStyle(1);
     legend2->SetLineWidth(1);
     legend2->SetFillColor(0);
     legend2->SetFillStyle(0);

     h_old_el_pt_signal->Divide(h_gen_el_pt_signal);
     h_old_el_pt_signal->SetLineColor(kBlue);
     h_old_el_pt_ZZ->Divide(h_gen_el_pt_ZZ);
     h_old_el_pt_ZZ->SetLineColor(kRed);
     hs_el_old_pt->Add(h_old_el_pt_signal);
     legend2->AddEntry(h_old_el_pt_signal,"WWZ","f");
     hs_el_old_pt->Add(h_old_el_pt_ZZ);
     legend2->AddEntry(h_old_el_pt_ZZ,"ZZ","f");

     cs1->cd(3);
     hs_el_old_pt->SetMinimum(0.);
     hs_el_old_pt->SetMaximum(1.);
     hs_el_old_pt->Draw("nostack hist");
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

     h_new_el_pt_signal->Divide(h_gen_el_pt_signal);
     h_new_el_pt_signal->SetLineColor(kBlue);
     h_new_el_pt_ZZ->Divide(h_gen_el_pt_ZZ);
     h_new_el_pt_ZZ->SetLineColor(kRed);
     hs_el_new_pt->Add(h_new_el_pt_signal);
     legend3->AddEntry(h_new_el_pt_signal,"WWZ","f");
     hs_el_new_pt->Add(h_new_el_pt_ZZ);
     legend3->AddEntry(h_new_el_pt_ZZ,"ZZ","f");

     cs1->cd(4);
     hs_el_new_pt->SetMinimum(0.);
     hs_el_new_pt->SetMaximum(1.);
     hs_el_new_pt->Draw("nostack hist");
     legend3->Draw();

     cs1->Print("../../../public_html/WWZ/lepton_ID_study/efficiency/lepton_eff_pt_"+year+".png");

     TCanvas *cs2 = new TCanvas("cs2","cs2",10,10,1400,900);
     cs2->Divide(2,2);

     TLegend* legend4 = new TLegend(0.60,0.10,0.90,0.40,"","NDC");
     legend4->SetBorderSize(0);
     legend4->SetTextFont(43);
     legend4->SetTextAlign(12);
     legend4->SetLineColor(1);
     legend4->SetLineStyle(1);
     legend4->SetLineWidth(1);
     legend4->SetFillColor(0);
     legend4->SetFillStyle(0);

     h_old_mu_eta_signal->Divide(h_gen_mu_eta_signal);
     h_old_mu_eta_signal->SetLineColor(kBlue);
     h_old_mu_eta_ZZ->Divide(h_gen_mu_eta_ZZ);
     h_old_mu_eta_ZZ->SetLineColor(kRed);
     hs_mu_old_eta->Add(h_old_mu_eta_signal);
     legend4->AddEntry(h_old_mu_eta_signal,"WWZ","f");
     hs_mu_old_eta->Add(h_old_mu_eta_ZZ);
     legend4->AddEntry(h_old_mu_eta_ZZ,"ZZ","f");

     cs2->cd(1);
     hs_mu_old_eta->SetMinimum(0.);
     hs_mu_old_eta->SetMaximum(1.);
     hs_mu_old_eta->Draw("nostack hist");
     legend4->Draw();

     TLegend* legend5 = new TLegend(0.60,0.10,0.90,0.40,"","NDC");
     legend5->SetBorderSize(0);
     legend5->SetTextFont(43);
     legend5->SetTextAlign(12);
     legend5->SetLineColor(1);
     legend5->SetLineStyle(1);
     legend5->SetLineWidth(1);
     legend5->SetFillColor(0);
     legend5->SetFillStyle(0);

     h_new_mu_eta_signal->Divide(h_gen_mu_eta_signal);
     h_new_mu_eta_signal->SetLineColor(kBlue);
     h_new_mu_eta_ZZ->Divide(h_gen_mu_eta_ZZ);
     h_new_mu_eta_ZZ->SetLineColor(kRed);
     hs_mu_new_eta->Add(h_new_mu_eta_signal);
     legend5->AddEntry(h_new_mu_eta_signal,"WWZ","f");
     hs_mu_new_eta->Add(h_new_mu_eta_ZZ);
     legend5->AddEntry(h_new_mu_eta_ZZ,"ZZ","f");

     cs2->cd(2);
     hs_mu_new_eta->SetMinimum(0.);
     hs_mu_new_eta->SetMaximum(1.);
     hs_mu_new_eta->Draw("nostack hist");
     legend5->Draw();

     TLegend* legend6 = new TLegend(0.60,0.10,0.90,0.40,"","NDC");
     legend6->SetBorderSize(0);
     legend6->SetTextFont(43);
     legend6->SetTextAlign(12);
     legend6->SetLineColor(1);
     legend6->SetLineStyle(1);
     legend6->SetLineWidth(1);
     legend6->SetFillColor(0);
     legend6->SetFillStyle(0);

     h_old_el_eta_signal->Divide(h_gen_el_eta_signal);
     h_old_el_eta_signal->SetLineColor(kBlue);
     h_old_el_eta_ZZ->Divide(h_gen_el_eta_ZZ);
     h_old_el_eta_ZZ->SetLineColor(kRed);
     hs_el_old_eta->Add(h_old_el_eta_signal);
     legend6->AddEntry(h_old_el_eta_signal,"WWZ","f");
     hs_el_old_eta->Add(h_old_el_eta_ZZ);
     legend6->AddEntry(h_old_el_eta_ZZ,"ZZ","f");

     cs2->cd(3);
     hs_el_old_eta->SetMinimum(0.);
     hs_el_old_eta->SetMaximum(1.);
     hs_el_old_eta->Draw("nostack hist");
     legend6->Draw();

     TLegend* legend7 = new TLegend(0.60,0.10,0.90,0.40,"","NDC");
     legend7->SetBorderSize(0);
     legend7->SetTextFont(43);
     legend7->SetTextAlign(12);
     legend7->SetLineColor(1);
     legend7->SetLineStyle(1);
     legend7->SetLineWidth(1);
     legend7->SetFillColor(0);
     legend7->SetFillStyle(0);

     h_new_el_eta_signal->Divide(h_gen_el_eta_signal);
     h_new_el_eta_signal->SetLineColor(kBlue);
     h_new_el_eta_ZZ->Divide(h_gen_el_eta_ZZ);
     h_new_el_eta_ZZ->SetLineColor(kRed);
     hs_el_new_eta->Add(h_new_el_eta_signal);
     legend7->AddEntry(h_new_el_eta_signal,"WWZ","f");
     hs_el_new_eta->Add(h_new_el_eta_ZZ);
     legend7->AddEntry(h_new_el_eta_ZZ,"ZZ","f");

     cs2->cd(4);
     hs_el_new_eta->SetMinimum(0.);
     hs_el_new_eta->SetMaximum(1.);
     hs_el_new_eta->Draw("nostack hist");
     legend7->Draw();

     cs2->Print("../../../public_html/WWZ/lepton_ID_study/efficiency/lepton_eff_eta_"+year+".png");

     TCanvas *cs3 = new TCanvas("cs3","cs3",10,10,1400,900);
     cs3->Divide(2,2);

     TLegend* legend8 = new TLegend(0.60,0.10,0.90,0.40,"","NDC");
     legend8->SetBorderSize(0);
     legend8->SetTextFont(43);
     legend8->SetTextAlign(12);
     legend8->SetLineColor(1);
     legend8->SetLineStyle(1);
     legend8->SetLineWidth(1);
     legend8->SetFillColor(0);
     legend8->SetFillStyle(0);
 
     //THStack
     THStack *hs_ratio_mu_pt = new THStack("hs_ratio_mu_pt","Muon efficiency ratio (old/new) ("+year+");p_{T} [GeV]; #epsilon (old/new) / bin"); 
     THStack *hs_ratio_el_pt = new THStack("hs_ratio_el_pt","Electron efficiency ratio (old/new) ("+year+");p_{T} [GeV]; #epsilon (old/new) / bin");   
     THStack *hs_ratio_mu_eta = new THStack("hs_ratio_mu_eta","Muon efficiency ratio (old/new) ("+year+");#eta; #epsilon (old/new) / bin");
     THStack *hs_ratio_el_eta = new THStack("hs_ratio_el_eta","Electron efficiency ratio (old/new) ("+year+");#eta; #epsilon (old/new) / bin");

     TH1D *h_ratio_mu_pt_signal = (TH1D*)h_old_mu_pt_signal->Clone("h_ratio_mu_pt_signal");
     h_ratio_mu_pt_signal->Divide(h_new_mu_pt_signal);
     TH1D *h_ratio_mu_pt_ZZ = (TH1D*)h_old_mu_pt_ZZ->Clone("h_ratio_mu_pt_ZZ"); 
     h_ratio_mu_pt_ZZ->Divide(h_new_mu_pt_ZZ);

     h_ratio_mu_pt_signal->SetLineColor(kBlue);
     h_ratio_mu_pt_ZZ->SetLineColor(kRed); 
     hs_ratio_mu_pt->Add(h_ratio_mu_pt_signal);
     legend8->AddEntry(h_ratio_mu_pt_signal,"WWZ","f");
     hs_ratio_mu_pt->Add(h_ratio_mu_pt_ZZ);
     legend8->AddEntry(h_ratio_mu_pt_ZZ,"ZZ","f");      

     cs3->cd(1);
     hs_ratio_mu_pt->Draw("nostack hist");
     legend8->Draw();

     TLegend* legend9 = new TLegend(0.60,0.10,0.90,0.40,"","NDC");
     legend9->SetBorderSize(0);
     legend9->SetTextFont(43);
     legend9->SetTextAlign(12);
     legend9->SetLineColor(1);
     legend9->SetLineStyle(1);
     legend9->SetLineWidth(1);
     legend9->SetFillColor(0);
     legend9->SetFillStyle(0); 

     TH1D *h_ratio_el_pt_signal = (TH1D*)h_old_el_pt_signal->Clone("h_ratio_el_pt_signal");
     h_ratio_el_pt_signal->Divide(h_new_el_pt_signal);
     TH1D *h_ratio_el_pt_ZZ = (TH1D*)h_old_el_pt_ZZ->Clone("h_ratio_el_pt_ZZ");
     h_ratio_el_pt_ZZ->Divide(h_new_el_pt_ZZ);    
 
     h_ratio_el_pt_signal->SetLineColor(kBlue);
     h_ratio_el_pt_ZZ->SetLineColor(kRed);
     hs_ratio_el_pt->Add(h_ratio_el_pt_signal);
     legend9->AddEntry(h_ratio_el_pt_signal,"WWZ","f");
     hs_ratio_el_pt->Add(h_ratio_el_pt_ZZ);
     legend9->AddEntry(h_ratio_el_pt_ZZ,"ZZ","f"); 

     cs3->cd(2);
     hs_ratio_el_pt->Draw("nostack hist");
     legend9->Draw();

     TLegend* legend10 = new TLegend(0.60,0.10,0.90,0.40,"","NDC");
     legend10->SetBorderSize(0);
     legend10->SetTextFont(43);
     legend10->SetTextAlign(12);
     legend10->SetLineColor(1);
     legend10->SetLineStyle(1);
     legend10->SetLineWidth(1);
     legend10->SetFillColor(0);
     legend10->SetFillStyle(0);

     TH1D *h_ratio_mu_eta_signal = (TH1D*)h_old_mu_eta_signal->Clone("h_ratio_mu_eta_signal");
     h_ratio_mu_eta_signal->Divide(h_new_mu_eta_signal);
     TH1D *h_ratio_mu_eta_ZZ = (TH1D*)h_old_mu_eta_ZZ->Clone("h_ratio_mu_eta_ZZ");
     h_ratio_mu_eta_ZZ->Divide(h_new_mu_eta_ZZ);

     h_ratio_mu_eta_signal->SetLineColor(kBlue);
     h_ratio_mu_eta_ZZ->SetLineColor(kRed);
     hs_ratio_mu_eta->Add(h_ratio_mu_eta_signal);
     legend10->AddEntry(h_ratio_mu_eta_signal,"WWZ","f");
     hs_ratio_mu_eta->Add(h_ratio_mu_eta_ZZ);
     legend10->AddEntry(h_ratio_mu_eta_ZZ,"ZZ","f");  

     cs3->cd(3);
     hs_ratio_mu_eta->Draw("nostack hist");
     legend10->Draw();

     TLegend* legend11 = new TLegend(0.60,0.10,0.90,0.40,"","NDC");
     legend11->SetBorderSize(0);
     legend11->SetTextFont(43);
     legend11->SetTextAlign(12);
     legend11->SetLineColor(1);
     legend11->SetLineStyle(1);
     legend11->SetLineWidth(1);
     legend11->SetFillColor(0);
     legend11->SetFillStyle(0);

     TH1D *h_ratio_el_eta_signal = (TH1D*)h_old_el_eta_signal->Clone("h_ratio_el_eta_signal");
     h_ratio_el_eta_signal->Divide(h_new_el_eta_signal);
     TH1D *h_ratio_el_eta_ZZ = (TH1D*)h_old_el_eta_ZZ->Clone("h_ratio_el_eta_ZZ");
     h_ratio_el_eta_ZZ->Divide(h_new_el_eta_ZZ);

     h_ratio_el_eta_signal->SetLineColor(kBlue);
     h_ratio_el_eta_ZZ->SetLineColor(kRed);
     hs_ratio_el_eta->Add(h_ratio_el_eta_signal);
     legend11->AddEntry(h_ratio_el_eta_signal,"WWZ","f");
     hs_ratio_el_eta->Add(h_ratio_el_eta_ZZ);
     legend11->AddEntry(h_ratio_el_eta_ZZ,"ZZ","f");

     cs3->cd(4);
     hs_ratio_el_eta->Draw("nostack hist");
     legend11->Draw();

     cs3->Print("../../../public_html/WWZ/lepton_ID_study/efficiency/lepton_ratio_pt_eta_"+year+".png");

}
