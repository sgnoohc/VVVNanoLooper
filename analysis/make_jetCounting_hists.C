void make_jetCounting_hists(TString option, TString year){

     TString dir = "output_newID_jetCounting/"+year+"/";
     std::vector<TString> files = {"WWZ.root","ZZ.root","TTZ.root","WZ.root","Higgs.root","Other.root"};

     // 5 mutually exclusive categories
     std::vector<TString> categories = {"CutJetIn","CutJetOut","CutBJetIn","CutBJetOut"};

     // For each category, loop over all files and add each hist to a single hist
     
     TString title_modifier = "";

     if (option == "in"){
	 title_modifier += "all jets with |#eta| < 2.4";
     }
     else if (option == "out"){
	 title_modifier += "all jets with 2.4 < |#eta| < 4.7";
     }
     else if (option == "all"){
	 title_modifier += "all jets with |#eta| < 4.7";
     }

     THStack *hs = new THStack("hs","Minimum m_lj using "+title_modifier+";min(m_{lj}) [GeV];Events / Bin");

     TLegend* legend = new TLegend(0.60,0.60,0.90,0.90,"","NDC");
     legend->SetBorderSize(0);
     legend->SetTextFont(43);
     legend->SetTextAlign(12);
     legend->SetLineColor(1);
     legend->SetLineStyle(1);
     legend->SetLineWidth(1);
     legend->SetFillColor(0);
     legend->SetFillStyle(0);
  
     int color = 0;    
 
     for (auto cat: categories){
	  if (cat == "CutJetOut" && option == "in") continue;
          TH1D* h = new TH1D("h","h", 180, 0., 300.);
	  for (auto f: files){
	       //std::cout << "file path = " << dir+f << std::endl; 
	       TFile *file = TFile::Open(dir+f,"READ");
	       //std::cout << "hist name = " << cat+"__Min_mlj_"+option << std::endl;
	       TH1D *hist = (TH1D*)file->Get(cat+"__Min_mlj_"+option);
	       h->Add(hist);
	  } // file loop
	  hs->Add(h);
	  h->SetFillColor(kBlue+color);
	  h->SetLineColor(kBlue+color);
          double yield = h->Integral();
          std::string yield_str = std::to_string(yield);
	  std::cout << "Category = " << cat << ", Yield = " << yield << std::endl;
	  std::string cat_string = "";
	  if ( cat == "CutJetIn" ) cat_string += "CutJetIn ("+yield_str+")";
	  else if ( cat == "CutJetOut" ) cat_string += "CutJetOut ("+yield_str+")";
	  else if ( cat == "CutBJetIn" ) cat_string += "CutBJetIn ("+yield_str+")";
	  else if ( cat == "CutBJetOut" ) cat_string += "CutBJetOut ("+yield_str+")";
          const char * label = cat_string.c_str();	  
	  legend->AddEntry(h,label,"f");
	  color += 10;
     } // category loop

     TCanvas *cs = new TCanvas("cs","cs",10,10,1400,900);
     cs->cd();

     hs->Draw("hist");
     legend->Draw();

     cs->Print("/home/users/kdownham/public_html/WWZ/jet_Counting/"+year+"/Min_mlj_byCategory_"+option+".png");

}
