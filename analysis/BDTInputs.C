TH1F* fillHists(TTree* tree, TString varname, float xmin, float xmax, float ymax, bool scaleUnity);

void plotHists(std::vector<TH1F*> wwz_hists, std::vector<TH1F*> zh_hists, std::vector<TH1F*> bkgd_hists, TString variable, TString proc);

void BDTInputs(TString var, TString proc, float xmin, float xmax, float ymax, bool scaleUnity=true){

     TString filepath = "output_090123_metFix/Run2/";
     std::vector<TString> procs = {"NonResWWZ","ZHWWZ","BDT_Backgrounds"};

     //if ( proc != "OF" && proc != "SF" ){
     //     std::cout << "You done fucked up!" << std::cout;
     //     //exit;
     //}

     TString t_train = "t_BDT_";
     TString t_test  = "t_BDT_";

     if ( proc == "OF" ){
	  t_train += "OF_train";
          t_test  += "OF_test";
     }

     if ( proc == "SF" ){
	  t_train += "SF_train";
	  t_test  += "SF_test";
     }

     std::vector<TH1F*> WWZ_hists;
     std::vector<TH1F*> ZH_hists;
     std::vector<TH1F*> Bkgd_hists;

     for ( auto f: procs ){

           TFile *file = TFile::Open(filepath+f+".root","READ");
           TTree *tree_train = (TTree*)file->Get(t_train);
           TTree *tree_test  = (TTree*)file->Get(t_test);

	   TH1F* hist_train = fillHists(tree_train, var, xmin, xmax, ymax, scaleUnity);           
	   TH1F* hist_test  = fillHists(tree_test , var, xmin, xmax, ymax, scaleUnity);
 
           if ( f == "NonResWWZ" ){
		WWZ_hists.push_back(hist_train);
	 	WWZ_hists.push_back(hist_test);
	   }

	   if ( f == "ZHWWZ" ){
                ZH_hists.push_back(hist_train);
                ZH_hists.push_back(hist_test);
           }

	   if ( f == "BDT_Backgrounds" ){
                Bkgd_hists.push_back(hist_train);
                Bkgd_hists.push_back(hist_test);
           }

     }

     plotHists(WWZ_hists,ZH_hists,Bkgd_hists,var,proc); 

}

TH1F* fillHists(TTree* tree, TString varname, float xmin, float xmax, float ymax, bool scaleUnity){

      int nbin = 100;

      float m_ll, dPhi_4Lep_MET, dPhi_Zcand_MET, dPhi_WW_MET, dR_Wcands, dR_Zcands, dR_WW_Z, MET, MT2, Pt4l, STLepHad, STLep, leading_Zcand_pt, subleading_Zcand_pt, leading_Wcand_pt, subleading_Wcand_pt, weight;

      tree->SetBranchAddress("m_ll",&m_ll);
      tree->SetBranchAddress("dPhi_4Lep_MET",&dPhi_4Lep_MET);
      tree->SetBranchAddress("dPhi_Zcand_MET",&dPhi_Zcand_MET);
      tree->SetBranchAddress("dPhi_WW_MET",&dPhi_WW_MET);
      tree->SetBranchAddress("dR_Wcands",&dR_Wcands);
      tree->SetBranchAddress("dR_Zcands",&dR_Zcands);
      tree->SetBranchAddress("dR_WW_Z",&dR_WW_Z);
      tree->SetBranchAddress("MET",&MET);
      tree->SetBranchAddress("MT2",&MT2);
      tree->SetBranchAddress("Pt4l",&Pt4l);
      tree->SetBranchAddress("STLepHad",&STLepHad);
      tree->SetBranchAddress("STLep",&STLep);
      tree->SetBranchAddress("leading_Zcand_pt",&leading_Zcand_pt);
      tree->SetBranchAddress("subleading_Zcand_pt",&subleading_Zcand_pt);
      tree->SetBranchAddress("leading_Wcand_pt",&leading_Wcand_pt);
      tree->SetBranchAddress("subleading_Wcand_pt",&subleading_Wcand_pt);
      tree->SetBranchAddress("weight",&weight);

      TH1F *h = new TH1F("h","h",nbin,xmin,xmax);

      float yield = 0.;
      float error = 0.;

      for (int i=0; i<tree->GetEntries(); i++){

           tree->GetEntry(i);

           yield += weight;
           error += std::pow(weight,2.0);
 
           if ( varname == "m_ll" )                 h->Fill(m_ll,weight);
	   if ( varname == "dPhi_4Lep_MET" )        h->Fill(dPhi_4Lep_MET,weight);
	   if ( varname == "dPhi_Zcand_MET" )       h->Fill(dPhi_Zcand_MET,weight);
	   if ( varname == "dPhi_WW_MET" )          h->Fill(dPhi_WW_MET,weight);
	   if ( varname == "dR_Wcands" )            h->Fill(dR_Wcands,weight);
           if ( varname == "dR_Zcands" )            h->Fill(dR_Zcands,weight);
	   if ( varname == "dR_WW_Z" )		    h->Fill(dR_WW_Z,weight);
	   if ( varname == "MET" )	            h->Fill(MET,weight);
	   if ( varname == "MT2" )		    h->Fill(MT2,weight);       
	   if ( varname == "Pt4l" )		    h->Fill(Pt4l,weight);
	   if ( varname == "STLepHad" )             h->Fill(STLepHad,weight);
	   if ( varname == "STLep" )                h->Fill(STLep,weight);
	   if ( varname == "leading_Zcand_pt" )     h->Fill(leading_Zcand_pt,weight);             
           if ( varname == "subleading_Zcand_pt" )  h->Fill(subleading_Zcand_pt,weight);
	   if ( varname == "leading_Wcand_pt" )     h->Fill(leading_Wcand_pt,weight);
	   if ( varname == "subleading_Wcand_pt" )  h->Fill(subleading_Wcand_pt,weight);

      }

      
      //std::cout << "=========================================" << std::endl;
      //std::cout << "Number of events in dataset" << std::endl;
      //std::cout << "Yield = " << yield << " +/- " << std::sqrt(error) << std::endl;

      if (scaleUnity){
          h->Scale(1./h->Integral());
	  h->GetYaxis()->SetRangeUser(0.,ymax);
      }

      return h;

      delete h;

}

void plotHists(std::vector<TH1F*> wwz_hists, std::vector<TH1F*> zh_hists, std::vector<TH1F*> bkgd_hists, TString variable, TString proc){

     TLegend* legend = new TLegend(0.60,0.60,0.90,0.90,"","NDC");
     legend->SetBorderSize(0);
     legend->SetTextFont(43);
     legend->SetTextAlign(12);
     legend->SetLineColor(1);
     legend->SetLineStyle(1);
     legend->SetLineWidth(1);
     legend->SetFillColor(0);
     legend->SetFillStyle(0);

     TString label = "";

     if ( variable == "m_ll" )                label += "m_{ll} [GeV]";  
     if ( variable == "dPhi_4Lep_MET" )       label += "#Delta #phi (4l,p_{T}^{miss})";
     if ( variable == "dPhi_Zcand_MET" )      label += "#Delta #phi (Z,p_{T}^{miss})";
     if ( variable == "dPhi_WW_MET" )         label += "#Delta #phi (WW,p_{T}^{miss})";
     if ( variable == "dR_Wcands" )           label += "#Delta R (l^{W1},l^{W2})";
     if ( variable == "dR_Zcands" )           label += "#Delta R (l^{Z1},l^{Z2})";
     if ( variable == "dR_WW_Z" )             label += "#Delta R (WW,Z)";
     if ( variable == "MET" )                 label += "p_{T}^{miss} [GeV]";
     if ( variable == "MT2" )                 label += "m_{T2} [GeV]";
     if ( variable == "Pt4l" )                label += "p_{T}^{4l} [GeV]";
     if ( variable == "STLepHad" )            label += "#Sigma_{lep,jet,MET} p_{T} [GeV]";
     if ( variable == "STLep" )               label += "#Sigma_{lep,MET} p_{T} [GeV]";
     if ( variable == "leading_Zcand_pt" )    label += "p_{T}^{Z1} [GeV]"; 
     if ( variable == "subleading_Zcand_pt" ) label += "p_{T}^{Z2} [GeV]";
     if ( variable == "leading_Wcand_pt" )    label += "p_{T}^{W1} [GeV]";
     if ( variable == "subleading_Wcand_pt" ) label += "p_{T}^{W2} [GeV]";

     TCanvas *cs = new TCanvas("cs","cs",10,10,1400,900);
     cs->cd();       
     wwz_hists[0]->SetLineColor(kRed);
     legend->AddEntry(wwz_hists[0],"WWZ train","f");
     wwz_hists[1]->SetLineColor(kRed);
     wwz_hists[1]->SetLineWidth(3);
     wwz_hists[1]->SetLineStyle(2);
     legend->AddEntry(wwz_hists[1],"WWZ test","f");

     zh_hists[0]->SetLineColor(kBlue);
     legend->AddEntry(zh_hists[0],"ZH train","f");
     zh_hists[1]->SetLineColor(kBlue);
     zh_hists[1]->SetLineWidth(3);
     zh_hists[1]->SetLineStyle(2);
     legend->AddEntry(zh_hists[1],"ZH test","f");

     bkgd_hists[0]->SetLineColor(kGreen);
     legend->AddEntry(bkgd_hists[0],"Bkgd train","f");
     bkgd_hists[1]->SetLineColor(kGreen);
     bkgd_hists[1]->SetLineWidth(3);
     bkgd_hists[1]->SetLineStyle(2);
     legend->AddEntry(bkgd_hists[1],"Bkgd test","f");
 
     wwz_hists[0]->GetXaxis()->SetTitle(label);
     wwz_hists[0]->GetYaxis()->SetTitle("Fraction of events");
     wwz_hists[0]->SetStats(0);

     wwz_hists[0]->Draw("hist");    
     wwz_hists[1]->Draw("hist same");
     zh_hists[0]->Draw("hist same");
     zh_hists[1]->Draw("hist same");
     bkgd_hists[0]->Draw("hist same");
     bkgd_hists[1]->Draw("hist same");
     legend->Draw();

     cs->Print("plots/BDT/"+variable+"_"+proc+".png");

}
