void makeHists(TString year){

     TString dir = "output_lepID/"+year+"/";
     TString signal = "output_signal.root";
     TString ZZ = "output_ZZ.root";

     TFile* file_signal = TFile::Open(dir+signal,"READ");
     TFile* file_ZZ = TFile::Open(dir+ZZ,"READ");

     THStack *hs_jetRelIso_mu = new THStack("hs_jetRelIso_mu","Muon jet relative isolation times p_{T} ("+year+");p_{T} * jetRelIso;Events / Total");
     THStack *hs_jetRelIso_el = new THStack("hs_jetRelIso_el","Electron jet relative isolation times p_{T} ("+year+");p_{T} * jetRelIso;Events / Total"); 
     THStack *hs_njets = new THStack("hs_njets","Number of jets ("+year+");N_{jets};Events / Total");
     THStack *hs_RelIso03_mu = new THStack("hs_RelIso03_mu","Muon relative isolation times p_{T} #Delta R = 0.3 ("+year+");p_{T} * PFRelIso03;Events / Total");
     THStack *hs_RelIso03_el = new THStack("hs_RelIso03_el","Electron relative isolation times p_{T} #Delta R = 0.3 ("+year+");p_{T} * PFRelIso03;Events / Total");

     TLegend* legend = new TLegend(0.60,0.60,0.90,0.90,"","NDC");
     legend->SetBorderSize(0);
     legend->SetTextFont(43);
     legend->SetTextAlign(12);
     legend->SetLineColor(1);
     legend->SetLineStyle(1);
     legend->SetLineWidth(1);
     legend->SetFillColor(0);
     legend->SetFillStyle(0);

     TLegend* legend1 = new TLegend(0.60,0.60,0.90,0.90,"","NDC");
     legend1->SetBorderSize(0);
     legend1->SetTextFont(43);
     legend1->SetTextAlign(12);
     legend1->SetLineColor(1);
     legend1->SetLineStyle(1);
     legend1->SetLineWidth(1);
     legend1->SetFillColor(0);
     legend1->SetFillStyle(0);

     TCanvas *cs1 = new TCanvas("cs1","cs1",10,10,1400,900);
     cs1->Divide(2,1); 

     TH1D *h_mu_jetRI_signal = (TH1D*)file_signal->Get("h_jetRelIso_mu");
     TH1D *h_mu_jetRI_ZZ = (TH1D*)file_ZZ->Get("h_jetRelIso_mu");
     TH1D *h_el_jetRI_signal = (TH1D*)file_signal->Get("h_jetRelIso_el");
     TH1D *h_el_jetRI_ZZ = (TH1D*)file_ZZ->Get("h_jetRelIso_el");
     TH1D *h_njets_signal = (TH1D*)file_signal->Get("h_njets");
     TH1D *h_njets_ZZ = (TH1D*)file_ZZ->Get("h_njets");
     TH1D *h_mu_RI_signal = (TH1D*)file_signal->Get("h_RelIso03_mu"); 
     TH1D *h_mu_RI_ZZ = (TH1D*)file_ZZ->Get("h_RelIso03_mu");  
     TH1D *h_el_RI_signal = (TH1D*)file_signal->Get("h_RelIso03_el");
     TH1D *h_el_RI_ZZ = (TH1D*)file_ZZ->Get("h_RelIso03_el");

     h_mu_jetRI_signal->Scale(1./h_mu_jetRI_signal->Integral());
     h_mu_jetRI_ZZ->Scale(1./h_mu_jetRI_ZZ->Integral());
     h_el_jetRI_signal->Scale(1./h_el_jetRI_signal->Integral());
     h_el_jetRI_ZZ->Scale(1./h_el_jetRI_ZZ->Integral());
     h_njets_signal->Scale(1./h_njets_signal->Integral());
     h_njets_ZZ->Scale(1./h_njets_ZZ->Integral());
     h_mu_RI_signal->Scale(1./h_mu_RI_signal->Integral());
     h_mu_RI_ZZ->Scale(1./h_mu_RI_ZZ->Integral());
     h_el_RI_signal->Scale(1./h_el_RI_signal->Integral());
     h_el_RI_ZZ->Scale(1./h_el_RI_ZZ->Integral());

     h_mu_jetRI_signal->SetLineColor(kBlue);
     hs_jetRelIso_mu->Add(h_mu_jetRI_signal);
     legend->AddEntry(h_mu_jetRI_signal,"WWZ","f");
     h_el_jetRI_signal->SetLineColor(kBlue);
     hs_jetRelIso_el->Add(h_el_jetRI_signal);
     legend1->AddEntry(h_el_jetRI_signal,"WWZ","f");
     h_mu_jetRI_ZZ->SetLineColor(kRed);
     hs_jetRelIso_mu->Add(h_mu_jetRI_ZZ);
     legend->AddEntry(h_mu_jetRI_ZZ,"ZZ","f");
     h_el_jetRI_ZZ->SetLineColor(kRed);
     hs_jetRelIso_el->Add(h_el_jetRI_ZZ);
     legend1->AddEntry(h_el_jetRI_ZZ,"ZZ","f");    

     cs1->cd(1);
     hs_jetRelIso_mu->Draw("nostack hist");
     legend->Draw();

     cs1->cd(2);
     hs_jetRelIso_el->Draw("nostack hist");
     legend1->Draw();

     cs1->Print("../../../public_html/WWZ/lepton_ID_study/efficiency/lepton_jetRelIso_"+year+".png");

     TCanvas *cs2 = new TCanvas("cs2","cs2",10,10,1400,900); 
     
     TLegend* legend2 = new TLegend(0.60,0.60,0.90,0.90,"","NDC");
     legend2->SetBorderSize(0);
     legend2->SetTextFont(43);
     legend2->SetTextAlign(12);
     legend2->SetLineColor(1);
     legend2->SetLineStyle(1);
     legend2->SetLineWidth(1);
     legend2->SetFillColor(0);
     legend2->SetFillStyle(0);   

     h_njets_signal->SetLineColor(kBlue);
     hs_njets->Add(h_njets_signal);
     legend2->AddEntry(h_njets_signal,"WWZ","f");
     h_njets_ZZ->SetLineColor(kRed);
     hs_njets->Add(h_njets_ZZ);
     legend2->AddEntry(h_njets_ZZ,"ZZ","f");

     cs2->cd();
     hs_njets->Draw("nostack hist");
     legend2->Draw();

     cs2->Print("../../../public_html/WWZ/lepton_ID_study/efficiency/njets_"+year+".png");
                      
     TCanvas *cs3 = new TCanvas("cs3","cs3",10,10,1400,900);
     cs3->Divide(2,1);

     TLegend* legend3 = new TLegend(0.60,0.60,0.90,0.90,"","NDC");
     legend3->SetBorderSize(0);
     legend3->SetTextFont(43);
     legend3->SetTextAlign(12);
     legend3->SetLineColor(1);
     legend3->SetLineStyle(1);
     legend3->SetLineWidth(1);
     legend3->SetFillColor(0);
     legend3->SetFillStyle(0);    

     h_mu_RI_signal->SetLineColor(kBlue);
     //h_mu_RI_signal->GetXaxis()->SetRange(0.,1.);
     hs_RelIso03_mu->Add(h_mu_RI_signal);
     legend3->AddEntry(h_mu_RI_signal,"WWZ","f");
     h_mu_RI_ZZ->SetLineColor(kRed);  
     //h_mu_RI_ZZ->GetXaxis()->SetRange(0.,1.);
     hs_RelIso03_mu->Add(h_mu_RI_ZZ);
     legend3->AddEntry(h_mu_RI_ZZ,"ZZ","f");   

     cs3->cd(1);
     hs_RelIso03_mu->Draw("nostack hist");
     legend3->Draw();  

     TLegend* legend4 = new TLegend(0.60,0.60,0.90,0.90,"","NDC");
     legend4->SetBorderSize(0);
     legend4->SetTextFont(43);
     legend4->SetTextAlign(12);
     legend4->SetLineColor(1);
     legend4->SetLineStyle(1);
     legend4->SetLineWidth(1);
     legend4->SetFillColor(0);
     legend4->SetFillStyle(0);

     h_el_RI_signal->SetLineColor(kBlue);
     hs_RelIso03_el->Add(h_el_RI_signal);
     legend4->AddEntry(h_el_RI_signal,"WWZ","f");
     h_el_RI_ZZ->SetLineColor(kRed);     
     hs_RelIso03_el->Add(h_el_RI_ZZ);
     legend4->AddEntry(h_el_RI_ZZ,"ZZ","f");

     cs3->cd(2);
     hs_RelIso03_el->Draw("nostack hist");
     legend4->Draw();  

     cs3->Print("../../../public_html/WWZ/lepton_ID_study/efficiency/lepton_relIso03_"+year+".png");

}
