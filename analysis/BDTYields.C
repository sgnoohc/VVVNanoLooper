void BDTYields(TString channel){

     TString path = "output_090123_metFix/Run2/";
     std::vector<TString> files = {"NonResWWZ.root","ZHWWZ.root","ZZ.root","TTZ.root","Higgs.root","WZ.root","Other.root"};

     for ( auto f: files ){

	   TFile *proc = TFile::Open(path+f,"READ");
	   
	   // Define variables
           float m_ll;
	   float dPhi_4Lep_MET;
	   float dPhi_Zcand_MET;
	   float dPhi_WW_MET;
	   float dR_Wcands;
	   float dR_Zcands;
	   float dR_WW_Z;
	   float MET;
	   float MT2;
	   float Pt4l;
	   float STLepHad;
	   float STLep;
	   float leading_Zcand_pt;
	   float subleading_Zcand_pt;
	   float leading_Wcand_pt;
	   float subleading_Wcand_pt;
	   float weight;

	   TTree *t_OF = (TTree*)proc->Get("t_BDT_"+channel);

	   t_OF->SetBranchAddress("m_ll",&m_ll);
	   t_OF->SetBranchAddress("dPhi_4Lep_MET",&dPhi_4Lep_MET);           
	   t_OF->SetBranchAddress("dPhi_Zcand_MET",&dPhi_Zcand_MET);
	   t_OF->SetBranchAddress("dPhi_WW_MET",&dPhi_WW_MET);
	   t_OF->SetBranchAddress("dR_Wcands",&dR_Wcands);
	   t_OF->SetBranchAddress("dR_Zcands",&dR_Zcands);
           t_OF->SetBranchAddress("dR_WW_Z",&dR_WW_Z);
           t_OF->SetBranchAddress("MET",&MET);      
           t_OF->SetBranchAddress("MT2",&MT2);
           t_OF->SetBranchAddress("Pt4l",&Pt4l);
           t_OF->SetBranchAddress("STLepHad",&STLepHad);
           t_OF->SetBranchAddress("STLep",&STLep);
	   t_OF->SetBranchAddress("leading_Zcand_pt",&leading_Zcand_pt);
           t_OF->SetBranchAddress("subleading_Zcand_pt",&subleading_Zcand_pt);
           t_OF->SetBranchAddress("leading_Wcand_pt",&leading_Wcand_pt);
           t_OF->SetBranchAddress("subleading_Wcand_pt",&subleading_Wcand_pt);
           t_OF->SetBranchAddress("weight",&weight);

           float OF_yield = 0.;
	   float OF_error = 0.;
	   int   OF_entries = 0.;

           for ( int i=0; i<t_OF->GetEntries(); i++ ){
		 t_OF->GetEntry(i);
		 OF_yield += weight;
		 OF_error += std::pow(weight,2.);
		 OF_entries += 1;
	   }

	   std::cout << "=============================================================================" << std::endl;
	   std::cout << "Printing yields for file =====> " << f << std::endl;
	   std::cout << "Channel = " << channel << std::endl;
	   std::cout << "Yield = " << OF_yield << " +/- " << std::sqrt(OF_error) << std::endl;
	   std::cout << "N_entries = " << OF_entries << std::endl;

     }

}
