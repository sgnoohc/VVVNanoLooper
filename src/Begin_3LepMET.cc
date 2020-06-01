#include "Begin_3LepMET.h"

void Begin_3LepMET()
{
    //==============================================
    // Begin_3LepMET:
    // This function gets called prior to the event looping.
    // This is where one declares variables, histograms, event selections for the category 3LepMET.
    //==============================================

    // Create variables used in this category.
    // Please follow the convention of <category>_<varname> structure.
    //3l+MET good for WWW and WZZ
    ana.tx.createBranch<int>           ("3LepMET_nSFOS");       
    ana.tx.createBranch<int>           ("3LepMET_nSFOSZ");    
    ana.tx.createBranch<int>           ("3LepMET_SF_lep1idx");    
    ana.tx.createBranch<int>           ("3LepMET_SF_lep2idx");    
    ana.tx.createBranch<int>           ("3LepMET_notSF_lep3idx");    
    ana.tx.createBranch<float>          ("3LepMET_0SFOSMTmaxSF");    // WWW - designed to kill WZ    
    ana.tx.createBranch<float>          ("3LepMET_0SFOSMTminSF");    // WWW - designed to kill WZ
    ana.tx.createBranch<float>          ("3LepMET_0SFOSMT3l");       // WWW - lll vs. pTmiss
    ana.tx.createBranch<float>          ("3LepMET_0SFOSHT3lMET");    // WWW - scalar sum of all objects
    ana.tx.createBranch<float>          ("3LepMET_1SFOSwoZMT3rd");      // WWW - designed to kill WZ  
    ana.tx.createBranch<float>          ("3LepMET_1SFOSwoZMT3l");       // WWW - lll vs. pTmiss
    ana.tx.createBranch<float>          ("3LepMET_1SFOSwoZHT3lMET");    // WWW - scalar sum of all objects  
    ana.tx.createBranch<float>          ("3LepMET_1SFOSwZMT3rd");      // WZZ - designed to kill WZ  
    ana.tx.createBranch<float>          ("3LepMET_1SFOSwZMT3l");       // WZZ - lll vs. pTmiss
    ana.tx.createBranch<float>          ("3LepMET_1SFOSwZHT3lMET");    // WZZ - scalar sum of all objects  

 

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("Cut_3LepMET_Preselection",
                                      [&]()
                                      {
                                        int nSFOS = 0;
                                        int nSFOSZ = 0;
                                        int lep1_idx = 0;
                                        int lep2_idx = 1;
                                        int lep3_idx = 2;
                                        // Needs to be 3 leptons
                                        if (not (ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size() == 3))
                                          return false;
                                        //test for SFOSs
                                        if(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]==(-ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1])){
                                            ++nSFOS;
                                            lep1_idx = 0;
                                            lep2_idx = 1;
                                            lep3_idx = 2;
                                            if( abs((ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]).M()-91.1876)<20.)
                                              ++nSFOSZ;
                                        }
                                        if(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]==(-ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[2])){
                                            ++nSFOS;
                                            lep1_idx = 0;
                                            lep2_idx = 2;
                                            lep3_idx = 1;
                                            if( abs((ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[2]).M()-91.1876)<20.)
                                              ++nSFOSZ;
                                        }
                                        if(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1]==(-ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[2])){
                                            ++nSFOS;
                                            lep1_idx = 1;
                                            lep2_idx = 2;
                                            lep3_idx = 0;
                                            if( abs((ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[2]).M()-91.1876)<20.)
                                              ++nSFOSZ;
                                        }
                                        if (nSFOS==0){
                                          if((ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0])==(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1])){
                                            lep1_idx = 0;
                                            lep2_idx = 1;
                                            lep3_idx = 2;
                                          }
                                          if((ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0])==(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[2])){
                                            lep1_idx = 0;
                                            lep2_idx = 2;
                                            lep3_idx = 1;
                                          }
                                          if((ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1])==(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[2])){
                                            lep1_idx = 1;
                                            lep2_idx = 2;
                                            lep3_idx = 0;
                                          }
                                        }
                                        ana.tx.setBranch<int>          ("3LepMET_nSFOS"        , nSFOS   );
                                        ana.tx.setBranch<int>          ("3LepMET_nSFOSZ"       , nSFOSZ  );
                                        ana.tx.setBranch<int>          ("3LepMET_SF_lep1idx"   , lep1_idx);
                                        ana.tx.setBranch<int>          ("3LepMET_SF_lep2idx"   , lep2_idx);
                                        ana.tx.setBranch<int>          ("3LepMET_notSF_lep3idx", lep3_idx);
                                        //make some default setting - overwrite later                                        
                                        ana.tx.setBranch<float>          ("3LepMET_0SFOSMTmaxSF",    -1.);   
                                        ana.tx.setBranch<float>          ("3LepMET_0SFOSMTminSF",    -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_0SFOSMT3l",       -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_0SFOSHT3lMET",    -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwoZMT3rd",   -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwoZMT3l",    -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwoZHT3lMET", -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwZMT3rd",    -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwZMT3l",     -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwZHT3lMET",  -1.);
                                        // Leading lepton pT > 25 GeV
                                        if (not (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt() >25))
                                          return false;
                                        // Subleading lepton pT > 20 GeV
                                        if (not (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].Pt() >20))
                                          return false;
                                        //remove low Mll for lep1-lep2 // should do what I want it to do
                                        if (lep1_idx>=0 && lep2_idx>=0){
                                          if( (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[lep1_idx]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[lep2_idx]).M()<20.)
                                            return false;
                                        }
                                        // Needs a minimum of MET, let's say 50 GeV
                                        if (not (ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt() >50))
                                          return false;
                                        return true;
                                      }, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_3LepMET_againstTT",
                                      [&]()
                                      {
                                        // No b-tagged jets
                                        if (not (ana.tx.getBranchLazy<int>("Common_nb_loose") == 0))
                                          return false;
                                        // at most one jet
                                        if (not (ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size()<=1))
                                          return false;
                                        return true;
                                      }, UNITY);
        ana.cutflow.addCutToLastActiveCut("Cut_3LepMET_0SFOS",
                                      [&]()
                                      {
                                        //SFOS check
                                        if (not (ana.tx.getBranch<int>("3LepMET_nSFOS") == 0))
                                          return false;
                                        float MT1 = RooUtil::Calc::mT(ana.tx.getBranchLazy<LorentzVector>("Common_met_p4"),ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[ana.tx.getBranch<int>("3LepMET_SF_lep1idx")]);
                                        float MT2 = RooUtil::Calc::mT(ana.tx.getBranchLazy<LorentzVector>("Common_met_p4"),ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[ana.tx.getBranch<int>("3LepMET_SF_lep2idx")]);
                                        float MTmax = MT1> MT2 ? MT1 : MT2;
                                        float MTmin = MT1<=MT2 ? MT1 : MT2;
                                        float MT3l = RooUtil::Calc::mT(ana.tx.getBranchLazy<LorentzVector>("Common_met_p4"),ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[2]);
                                        float HT = ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt()+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt()+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].Pt()+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[2].Pt();
                                        ana.tx.setBranch<float>          ("3LepMET_0SFOSMTmaxSF",    MTmax);   
                                        ana.tx.setBranch<float>          ("3LepMET_0SFOSMTminSF",    MTmin);
                                        ana.tx.setBranch<float>          ("3LepMET_0SFOSMT3l",       MT3l );
                                        ana.tx.setBranch<float>          ("3LepMET_0SFOSHT3lMET",    HT   );
                                        
                                        return true;
                                      }, UNITY);
        ana.cutflow.getCut("Cut_3LepMET_againstTT");
        ana.cutflow.addCutToLastActiveCut("Cut_3LepMET_1SFOSwoZ",
                                      [&]()
                                      {
                                        //SFOS check
                                        if (not (ana.tx.getBranch<int>("3LepMET_nSFOS") == 1))
                                          return false;
                                        if (not (ana.tx.getBranch<int>("3LepMET_nSFOSZ") == 0))
                                          return false;

                                        float MT3rd = RooUtil::Calc::mT(ana.tx.getBranchLazy<LorentzVector>("Common_met_p4"),ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[2]);
                                        float MT3l = RooUtil::Calc::mT(ana.tx.getBranchLazy<LorentzVector>("Common_met_p4"),ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[2]);
                                        float HT = ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt()+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt()+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].Pt()+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[2].Pt();
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwoZMT3rd",   MT3rd);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwoZMT3l",    MT3l );
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwoZHT3lMET", HT   );
                                        
                                        return true;
                                      }, UNITY);
        ana.cutflow.getCut("Cut_3LepMET_againstTT");
        ana.cutflow.addCutToLastActiveCut("Cut_3LepMET_1SFOSwZ",
                                      [&]()
                                      {
                                        //SFOS check
                                        if (not (ana.tx.getBranch<int>("3LepMET_nSFOS") == 1))
                                          return false;
                                        if (not (ana.tx.getBranch<int>("3LepMET_nSFOSZ") == 1))
                                          return false;
                                        
                                        float MT3rd = RooUtil::Calc::mT(ana.tx.getBranchLazy<LorentzVector>("Common_met_p4"),ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[2]);
                                        float MT3l = RooUtil::Calc::mT(ana.tx.getBranchLazy<LorentzVector>("Common_met_p4"),ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[2]);
                                        float HT = ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt()+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt()+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].Pt()+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[2].Pt();
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwZMT3rd",    MT3rd);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwZMT3l",     MT3l );
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwZHT3lMET",  HT   );
                                        return true;
                                      }, UNITY);
        

        /*
                                  
                                        ana.tx.setBranch<float>          ("3LepMET_0SFOSMTmaxSF",    -1.);   
                                        ana.tx.setBranch<float>          ("3LepMET_0SFOSMTminSF",    -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_0SFOSMT3l",       -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_0SFOSHT3lMET",    -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwoZMT3rd",   -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwoZMT3l",    -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwoZHT3lMET", -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwZMT3rd",    -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwZMT3l",     -1.);
                                        ana.tx.setBranch<float>          ("3LepMET_1SFOSwZHT3lMET",  -1.);
        */
        ana.histograms.addHistogram("h_3LepMET_0SFOSMTmaxSF"   , 300, 0, 1500, [&]() { return ana.tx.getBranch<float>("3LepMET_0SFOSMTmaxSF"   ); } );
        ana.histograms.addHistogram("h_3LepMET_0SFOSMTminSF"   , 300, 0, 1500, [&]() { return ana.tx.getBranch<float>("3LepMET_0SFOSMTminSF"   ); } );
        ana.histograms.addHistogram("h_3LepMET_0SFOSMT3l"      , 300, 0, 3000, [&]() { return ana.tx.getBranch<float>("3LepMET_0SFOSMT3l"      ); } );
        ana.histograms.addHistogram("h_3LepMET_0SFOSHT3lMET"   , 300, 0, 3000, [&]() { return ana.tx.getBranch<float>("3LepMET_0SFOSHT3lMET"   ); } );
        ana.histograms.addHistogram("h_3LepMET_1SFOSwoZMT3rd"  , 300, 0, 1500, [&]() { return ana.tx.getBranch<float>("3LepMET_1SFOSwoZMT3rd"  ); } );
        ana.histograms.addHistogram("h_3LepMET_1SFOSwoZMT3l"   , 300, 0, 3000, [&]() { return ana.tx.getBranch<float>("3LepMET_1SFOSwoZMT3l"   ); } );
        ana.histograms.addHistogram("h_3LepMET_1SFOSwoZHT3lMET", 300, 0, 3000, [&]() { return ana.tx.getBranch<float>("3LepMET_1SFOSwoZHT3lMET"); } );
        ana.histograms.addHistogram("h_3LepMET_1SFOSwZMT3rd"   , 300, 0, 1500, [&]() { return ana.tx.getBranch<float>("3LepMET_1SFOSwZMT3rd"   ); } );
        ana.histograms.addHistogram("h_3LepMET_1SFOSwZMT3l"    , 300, 0, 3000, [&]() { return ana.tx.getBranch<float>("3LepMET_1SFOSwZMT3l"    ); } );
        ana.histograms.addHistogram("h_3LepMET_1SFOSwZHT3lMET" , 300, 0, 3000, [&]() { return ana.tx.getBranch<float>("3LepMET_1SFOSwZHT3lMET" ); } );

    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    RooUtil::Histograms hists_3LepMET;
    // Now book cutflow histogram (could be commented out if user does not want.)
    // N.B. Cutflow histogramming can be CPU consuming.
    ana.cutflow.bookCutflows();

    // Book histograms to cuts that user wants for this category.
    ana.cutflow.bookHistogramsForCutAndBelow(ana.histograms, "Cut_3LepMET_Preselection");
}
