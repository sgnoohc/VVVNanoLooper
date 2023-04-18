

void makePlots(TString year, std::string histname){

     TString dir_new = "output_newID/";
     TString dir_old = "output_oldID/";
     
     std::vector<TString> samples = {"NonResWWZ","ZHWWZ","ZZ"};
     //std::vector<TString> histnames = {"CutEMuMT2__Zcand_lep0_pt","CutEMuMT2__Zcand_lep1_pt","CutEMuMT2__other_lep0_pt","CutEMuMT2__other_lep1_pt"};
     TString hist_name(histname);
     std::vector<TString> histnames = {hist_name};

     TString name;

     if ( histname.find("CutEMuMT2") != string::npos ){
          name += "OF SR: ";
     }

     if ( histname.find("CutOffZ") != string::npos ){
	  name += "SF SR: ";
     }

     if ( histname.find("lep0") != string::npos ){
	  name += "Leading ";
     }

     if ( histname.find("lep1") != string::npos ){
          name += "Subleading ";
     }

     if ( histname.find("Zcand") != string::npos ){
          name += "Z cand lepton p_{T} [GeV] ";
     }

     if ( histname.find("other") != string::npos ){
          name += "W cand lepton p_{T} [GeV] ";
     }

     TLegend* legend = new TLegend(0.60,0.60,0.90,0.90,"","NDC");
     legend->SetBorderSize(0);
     legend->SetTextFont(43);
     legend->SetTextAlign(12);
     legend->SetLineColor(1);
     legend->SetLineStyle(1);
     legend->SetLineWidth(1);
     legend->SetFillColor(0);
     legend->SetFillStyle(0);
 
     TLegend* legend1 = new TLegend(0.10,0.70,0.48,0.90,"","NDC");
     legend1->SetBorderSize(0);
     legend1->SetTextFont(43);
     legend1->SetTextAlign(12);
     legend1->SetLineColor(1);
     legend1->SetLineStyle(1);
     legend1->SetLineWidth(1);
     legend1->SetFillColor(0);
     legend1->SetFillStyle(0);

     //Need a stack for new and old ID
     THStack *hs_norm_old = new THStack("hs_norm_old",name+"(old ID)");
     THStack *hs_norm_new = new THStack("hs_norm_new",name+"(new ID)");
     THStack *hs_ratio = new THStack("hs_ratio",name+"(ratio newID/oldID)");

     //Need a vector to store new and old hists
     std::vector<std::tuple<TString,TString,TH1D*>> old_hists;
     std::vector<std::tuple<TString,TString,TH1D*>> new_hists;
     std::vector<std::tuple<TString,TString,TH1D*>> ratio_hists;

     // Normalized plots (shape analysis)
     for (auto i : samples){

	  TFile* file_new = TFile::Open(dir_new+year+"/"+i+".root","READ");
	  TFile* file_old = TFile::Open(dir_old+year+"/"+i+".root","READ");

	  // create a vector here for ratio hists          

	  for (auto j : histnames){

	       TH1D *h_new = (TH1D*)file_new->Get(j);
	       TH1D *h_old = (TH1D*)file_old->Get(j);
	       //TH1D *h_ratio = (TH1D*)h_new->Clone("h_ratio");

	       h_new->Rebin(5);
	       h_old->Rebin(5);

               TH1D *h_ratio = (TH1D*)h_new->Clone("h_ratio");

	       h_ratio->SetTitle("");
	       h_ratio->Divide(h_old);

               //h_ratio->SetMaximum(1.2);
	       //h_ratio->SetMinimum(0.6);

	       h_new->Scale(1./h_new->Integral());
	       h_old->Scale(1./h_old->Integral());

	       if ( i == "NonResWWZ" ){
	 	    h_new->SetLineColor(kBlue);
		    h_old->SetLineColor(kBlue);
		    h_ratio->SetLineColor(kBlue);
               }

	       if ( i == "ZHWWZ" ){

		    h_new->SetLineColor(kRed);
                    h_old->SetLineColor(kRed);
		    h_ratio->SetLineColor(kRed);
	       }

               if ( i == "ZZ" ){

                    h_new->SetLineColor(kBlack);
                    h_old->SetLineColor(kBlack);
		    h_ratio->SetLineColor(kBlack);

               }

	       old_hists.push_back({i,j,h_old});
	       new_hists.push_back({i,j,h_new});
	       ratio_hists.push_back({i,j,h_ratio});

	  } 

     }

     for ( auto k: old_hists ){
	   //k is a tuple...
           hs_norm_old->Add(std::get<2>(k));
	   legend->AddEntry(std::get<2>(k),std::get<0>(k),"f");

     }

     for ( auto m: new_hists ){
	    
	   hs_norm_new->Add(std::get<2>(m));

     }

     for ( auto l: ratio_hists ){

           hs_ratio->Add(std::get<2>(l));
	   legend1->AddEntry(std::get<2>(l),std::get<0>(l),"f");

     }

     TCanvas *cs1 = new TCanvas("cs","cs",10,10,1400,900);
	
     cs1->Divide(2,1);

     cs1->cd(1);
     hs_norm_old->Draw("nostack hist");
     legend->Draw();

     cs1->cd(2);
     hs_norm_new->Draw("nostack hist");
     legend->Draw();
    
     cs1->Print("../../../public_html/WWZ/lepton_ID_study/newID_signal_study/"+year+"/"+hist_name+"_shape.png");        

     TCanvas *cs2 = new TCanvas("cs","cs",10,10,1400,900);
     cs2->cd();
     hs_ratio->SetMaximum(1.8);
     hs_ratio->SetMinimum(0.2);
     hs_ratio->Draw("nostack hist");
     legend1->Draw();

     cs2->Print("../../../public_html/WWZ/lepton_ID_study/newID_signal_study/"+year+"/"+hist_name+"_ratio.png");

}
