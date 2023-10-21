#include <iostream>
#include <fstream>

void makeJSON(bool includeWeights, bool singleFile){

     TString path = "";
     TString file = "";
     TString tag = "";

     if (!singleFile){ 
     	path += "output_101423_Synchronization/Run2/";
     	file += "NonResWWZ.root";
	tag += "";
     }
     else{
	path += "";
	file += "WWZJets_18_analyzed.root";
	tag += "_2018_singleFile";
     }

     ofstream signal_region_events;
     TString mod = "";
     if (includeWeights) mod += "_withWeights";
     if (!includeWeights) mod += "_noWeights";
     
     signal_region_events.open("sr_events"+mod+tag+".json");

     // Declare tree variables
     int event;
     int lumi;
     int run;
     float weight;
     int year;
     bool APV;
     int bin;

     TFile *input = TFile::Open( path+file );
     TTree *tree = (TTree*)input->Get("t_SR");
     tree->SetBranchAddress("event", &event);
     tree->SetBranchAddress("lumi", &lumi);
     tree->SetBranchAddress("run", &run);
     tree->SetBranchAddress("weight", &weight);
     tree->SetBranchAddress("year", &year);
     tree->SetBranchAddress("APV", &APV);
     tree->SetBranchAddress("bin", &bin);

     std::vector<TString> years;

     if (!singleFile){
     	//std::vector<TString> years = {"2018","2017","2016","2016APV"};
     	years.push_back("2018");
	years.push_back("2017");
	years.push_back("2016");
	years.push_back("2016APV");
     }
     else {
	years.push_back("2018");
     }
     std::vector<TString> bins = {"4l_wwz_sf_A","4l_wwz_sf_B","4l_wwz_sf_C","4l_wwz_of_1","4l_wwz_of_2","4l_wwz_of_3","4l_wwz_of_4"};  

     signal_region_events << "{" << " \n";
     for ( int y=0; y<years.size(); y++ ){
	   signal_region_events << "    "+years[y]+": {" << " \n";
	   for ( int p=0; p<bins.size(); p++ ){
                 signal_region_events << "       "+bins[p]+": [" << " \n";
		 int y_idx, b_idx;
                 bool APVflag;
                 if ( years[y] == "2018" ) y_idx = 2018;
                 else if ( years[y] == "2017" ) y_idx = 2017;
                 else if ( years[y] == "2016" ) y_idx = 2016;
                 else if ( years[y] == "2016APV" ){
                      y_idx = 2016;
                      APVflag = true;
                 }

		 if ( bins[p] == "4l_wwz_sf_A" ) b_idx = 5;
		 if ( bins[p] == "4l_wwz_sf_B" ) b_idx = 6;
  	         if ( bins[p] == "4l_wwz_sf_C" ) b_idx = 7;
		 if ( bins[p] == "4l_wwz_of_1" ) b_idx = 1;
		 if ( bins[p] == "4l_wwz_of_2" ) b_idx = 2;
		 if ( bins[p] == "4l_wwz_of_3" ) b_idx = 3;
		 if ( bins[p] == "4l_wwz_of_4" ) b_idx = 4;

                 //std::cout << "Number of entries = " << tree->GetEntries() << std::endl;

		 for ( int i=0; i<tree->GetEntries(); i++ ){
		       tree->GetEntry(i);
		       if ( year == y_idx && APV == APVflag && bin == b_idx ){
			    if (!includeWeights){
			        //std::cout << "event = " << event << std::endl;
			        signal_region_events << "        \""<< event <<"\":\""<< run << "\":\""<< lumi << "\"," << "\n";
			    }
			    else{
				signal_region_events << "        \""<< event << "\":\""<< run << "\":\"" << lumi << "\":\"" << weight << "\"," << "\n";
			    }
		       }
		       else{
			    continue;
		       }
		 }
	         signal_region_events << "       ]," << " \n";		 
	   }
	   signal_region_events << "    }," << " \n";
     }
     signal_region_events << "}" << " \n";

     signal_region_events.close();

     std::cout << "Wrote output to file: sr_events"+mod+tag+".json" << std::endl;

}
