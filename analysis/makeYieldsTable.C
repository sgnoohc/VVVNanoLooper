#include <iostream>
#include <fstream>

using namespace std;

void makeYieldsTable(TString period){

     std::vector<TString> filenames = {"WWZ", "ZZ", "TTZ", "Higgs", "WZ", "data"};
     TString dir = "outputs/"+period+"/";

     std::vector<std::tuple<double,double>> signal_yield_error_of;
     std::vector<std::tuple<double,double>> bkgd_yield_error_of;
     std::vector<std::tuple<double,double>> data_yield_error_of;
     std::vector<std::tuple<double,double>> signal_yield_error_sf;
     std::vector<std::tuple<double,double>> bkgd_yield_error_sf;
     std::vector<std::tuple<double,double>> data_yield_error_sf;
     
     std::vector<double> bkgd_yield_of;
     std::vector<double> bkgd_error_of;
     std::vector<double> bkgd_yield_sf;
     std::vector<double> bkgd_error_sf;

     double b1_bkgd = 0.;
     double b2_bkgd = 0.;
     double b3_bkgd = 0.;
     double b4_bkgd = 0.;
     double b5_bkgd = 0.;
     double b6_bkgd = 0.;
     double b7_bkgd = 0.;

     double b1_bkgd_err = 0.;
     double b2_bkgd_err = 0.;
     double b3_bkgd_err = 0.;
     double b4_bkgd_err = 0.;
     double b5_bkgd_err = 0.;
     double b6_bkgd_err = 0.;
     double b7_bkgd_err = 0.;
    

     // Loop through file names and store per-bin yields and errors
     for (auto name : filenames){
	  std::cout << "File name = " << name << std::endl;
	  TFile *file = TFile::Open(dir+name+".root","READ");
	  TH1D *h_of = (TH1D*)file->Get("CutEMuMT2__SRBin");
	  TH1D *h_sf = (TH1D*)file->Get("CutOffZ__SRBin");
	  
	  int h_of_bins = h_of->GetNbinsX();
	  int h_sf_bins = h_sf->GetNbinsX();	  
	

	  for (int i = 1; i < 5; i++){
	       std::cout << "i = " << i << std::endl;
	       double yield = h_of->GetBinContent(i);
	       double error = h_of->GetBinError(i);
	       std::cout << "Debug 1" << std::endl;
	       if ( name == "WWZ" ){
		    std::cout << "i = " << i << " , signal yield (of) = " << yield << std::endl;
		    signal_yield_error_of.push_back({yield, error});
	       }
	       else if ( name == "data" ){
		    data_yield_error_of.push_back({yield, error});
	       }
	       else {
		    if ( i == 1 ){
		         b1_bkgd += yield;
			 b1_bkgd_err += std::pow(error,2);
		    }
		    if ( i == 2 ){
                         b2_bkgd += yield;
                         b2_bkgd_err += std::pow(error,2);
                    }
		    if ( i == 3 ){
                         b3_bkgd += yield;
                         b3_bkgd_err += std::pow(error,2);
                    }
		    if ( i == 4 ){
                         b4_bkgd += yield;
                         b4_bkgd_err += std::pow(error,2);
                    }  
	       }
	       
	       
	  }

	  for (int i = 5; i < 8; i++){
	       std::cout << "same flavor loop" << std::endl;
               double yield = h_sf->GetBinContent(i);
               double error = h_sf->GetBinError(i);
               if ( name == "WWZ" ){
                    signal_yield_error_sf.push_back({yield, error});
               }
               else if ( name == "data" ){
		    std::cout << "i = " << i << " , data yield (sf) = " << yield << std::endl;
                    data_yield_error_sf.push_back({yield, error});
               }
               else {
	            if ( i == 5 ){
                         b5_bkgd += yield;
                         b5_bkgd_err += std::pow(error,2);
                    }
                    if ( i == 6 ){
                         b6_bkgd += yield;
                         b6_bkgd_err += std::pow(error,2);
                    }
                    if ( i == 7 ){
                         b7_bkgd += yield;
                         b7_bkgd_err += std::pow(error,2);
                    }
	
               }
           
          }     
	  
     }

     //std::cout << "Made it out of the loops" << std::endl;

     bkgd_yield_of.push_back(b1_bkgd);
     bkgd_yield_of.push_back(b2_bkgd);
     bkgd_yield_of.push_back(b3_bkgd);
     bkgd_yield_of.push_back(b4_bkgd);
     bkgd_yield_sf.push_back(b5_bkgd);
     bkgd_yield_sf.push_back(b6_bkgd);
     bkgd_yield_sf.push_back(b7_bkgd);

     bkgd_error_of.push_back(b1_bkgd_err);
     bkgd_error_of.push_back(b2_bkgd_err);
     bkgd_error_of.push_back(b3_bkgd_err);
     bkgd_error_of.push_back(b4_bkgd_err);
     bkgd_error_sf.push_back(b5_bkgd_err);
     bkgd_error_sf.push_back(b6_bkgd_err);
     bkgd_error_sf.push_back(b7_bkgd_err);

     //std::cout << "Filled histograms" << std::endl;

     for (int j = 0; j < 4; j++){
     	bkgd_yield_error_of.push_back({bkgd_yield_of[j],std::sqrt(bkgd_error_of[j])});
     }
     //std::cout << "Filled of vector" << std::endl;
     for (int n = 0; n < 3; n++){
        bkgd_yield_error_sf.push_back({bkgd_yield_sf[n],std::sqrt(bkgd_error_sf[n])});
     }
     //std::cout << "Filled sf vector" << std::endl;
    
     // Print Bin Yields and Errors in a nice format (eventually LateX)
     
     for ( int k = 0; k < 7; k++ ){    
     	std::cout << "-------------------------------------------------------------------------------------------------" << std::endl;
        if ( k < 4 ){
	     std::cout << "----------------------------Opposite Flavor Channel-----------------------------------------" << std::endl;
             double s = std::get<0>(signal_yield_error_of[k]);
	     double s_err = std::get<1>(signal_yield_error_of[k]);
	     double b = std::get<0>(bkgd_yield_error_of[k]);
	     double b_err = std::get<1>(signal_yield_error_of[k]);
	     double sig = ( s / std::sqrt(b) );
	     double sig_err = std::sqrt(std::pow((s_err/s),2)+(0.25*std::pow((b_err/std::sqrt(b)),2)))*sig;
	     double d = std::get<0>(data_yield_error_of[k]);
	     double d_err = std::get<1>(data_yield_error_of[k]);
	     double ratio = (d / (s+b)); 
	     double ratio_err = ratio*std::sqrt(std::pow((d_err/d),2)+((std::pow(s_err,2)+std::pow(b_err,2))/(std::pow(s+b,2))));

	     std::cout << "Bin = " << k+1 << std::endl;
	     std::cout << "Signal = " << s << " +/- " << s_err << std::endl;
	     std::cout << "Background = " << b << " +/- " << b_err << std::endl;
	     std::cout << "Significance = " << sig << " +/- " << sig_err << std::endl;
	     std::cout << "Data = " << d << " +/- " << d_err << std::endl;
	     std::cout << "Data/MC = " << ratio << " +/- " << ratio_err << std::endl;
     	}
	else if ( k >= 4 ){
	     std::cout << "----------------------------Same Flavor Channel-----------------------------------------" << std::endl;
             double s_sf = std::get<0>(signal_yield_error_sf[k-4]);
             double s_err = std::get<1>(signal_yield_error_sf[k-4]);
             double b = std::get<0>(bkgd_yield_error_sf[k-4]);
             double b_err = std::get<1>(signal_yield_error_sf[k-4]);
             double sig = ( s_sf / std::sqrt(b) );
             double sig_err = std::sqrt(std::pow((s_err/s_sf),2)+(0.25*std::pow((b_err/std::sqrt(b)),2)))*sig;
             double d = std::get<0>(data_yield_error_sf[k-4]);
             double d_err = std::get<1>(data_yield_error_sf[k-4]);
             double ratio = (d / (s_sf+b));
             double ratio_err = ratio*std::sqrt(std::pow((d_err/d),2)+((std::pow(s_err,2)+std::pow(b_err,2))/(std::pow(s_sf+b,2))));

	     std::cout << "Bin = " << k+1 << std::endl;
             std::cout << "Signal = " << s_sf << " +/- " << s_err << std::endl;
             std::cout << "Background = " << b << " +/- " << b_err << std::endl;
             std::cout << "Significance = " << sig << " +/- " << sig_err << std::endl;
             std::cout << "Data = " << d << " +/- " << d_err << std::endl;
             std::cout << "Data/MC ratio = " << ratio << " +/- " << ratio_err << std::endl;             

	}
     }
}
