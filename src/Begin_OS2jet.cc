#include "Begin_OS2jet.h"

void Begin_OS2jet()
{
    //==============================================
    // Begin_OS2jet:
    // This function gets called prior to the event looping.
    // This is where one declares variables, histograms, event selections for the category OS2jet.
    //==============================================

    // Create variables used in this category.
    // Please follow the convention of <category>_<varname> structure.
                                        ana.tx.createBranch<int>  ("OS2jet_SFcontent"             );
                                        ana.tx.createBranch<int>  ("OS2jet_Jetcontent"            );
                                        ana.tx.createBranch<int>  ("OS2jet_Nfatjets"              );
                                        ana.tx.createBranch<int>  ("OS2jet_Njets"                 );
                                        ana.tx.createBranch<int>  ("OS2jet_Nbjetsv1"              );
                                        ana.tx.createBranch<int>  ("OS2jet_Nbjetsv2"              );
                                        ana.tx.createBranch<int>  ("OS2jet_Nbjetsmedv1"           );
                                        ana.tx.createBranch<int>  ("OS2jet_NfatjetsMinusNjets"    );
                                        ana.tx.createBranch<float>("OS2jet_lep1_pt"               );
                                        ana.tx.createBranch<float>("OS2jet_lep2_pt"               );
                                        ana.tx.createBranch<float>("OS2jet_lep12_ptvectorsum"     );
                                        ana.tx.createBranch<float>("OS2jet_lep12_ptscalarsum"     );
                                        ana.tx.createBranch<float>("OS2jet_lep12_ptscalarprod"    );
                                        ana.tx.createBranch<float>("OS2jet_lep12_mass"            );
                                        ana.tx.createBranch<float>("OS2jet_lep12_DR"              );
                                        ana.tx.createBranch<float>("OS2jet_lep12_DPhi"            );
                                        ana.tx.createBranch<float>("OS2jet_lep12_Deta"            );
                                        ana.tx.createBranch<int>  ("OS2jet_fatjet1_idx"           );   
                                        ana.tx.createBranch<int>  ("OS2jet_fatjet2_idx"           ); 
                                        ana.tx.createBranch<float>("OS2jet_fatjet1_pt"            );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet2_pt"            );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet1_mass"          );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet2_mass"          );     
                                        ana.tx.createBranch<float>("OS2jet_fatjet1_massSD"        );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet2_massSD"        );  
                                        ana.tx.createBranch<float>("OS2jet_fatjet1_tau21"         );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet2_tau21"         );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet1_tau32"         );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet2_tau32"         );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet1_ll_DR"         );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet2_ll_DR"         );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_ll_DRmax"     );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_ptvectorsum"  );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_ptscalarsum"  );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_ptscalarprod" );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_mass"         );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_masssum"      );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_massproduct"  );    
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_massSDsum"    );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_massSDproduct");  
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_DR"           );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_DPhi"         );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_DEta"         );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet1_toptag"        );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet2_toptag"        );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet1_Wtag"          );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet2_Wtag"          );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet1_Ztag"          );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet2_Ztag"          );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet1_Zbbtag"        );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet2_Zbbtag"        );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet1_WpZtag"        );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet1_WtZtag"        ); 
                                        ana.tx.createBranch<float>("OS2jet_fatjet2_WpZtag"        );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet2_WtZtag"        );    
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_WtWtag"       );    
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_WtZtag"       );    
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_ZtWtag"       );    
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_ZtZtag"       );    
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_WpWtag"       );    
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_WpZtag"       );    
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_ZpWtag"       );   
                                        ana.tx.createBranch<float>("OS2jet_fatjet12_ZpZtag"       );   
                                        ana.tx.createBranch<int>  ("OS2jet_jet1_idx"              );   
                                        ana.tx.createBranch<int>  ("OS2jet_jet2_idx"              ); 
                                        ana.tx.createBranch<float>("OS2jet_jet1_pt"               );   
                                        ana.tx.createBranch<float>("OS2jet_jet2_pt"               );   
                                        ana.tx.createBranch<float>("OS2jet_jet12_ptvectorsum"     );   
                                        ana.tx.createBranch<float>("OS2jet_jet12_ptscalarsum"     );   
                                        ana.tx.createBranch<float>("OS2jet_jet12_ptscalarprod"    );   
                                        ana.tx.createBranch<float>("OS2jet_jet12_mass"            );    
                                        ana.tx.createBranch<float>("OS2jet_jet12_DR"              );   
                                        ana.tx.createBranch<float>("OS2jet_jet12_DPhi"            );
                                        ana.tx.createBranch<float>("OS2jet_jet12_DEta"            );
                                        ana.tx.createBranch<float>("OS2jet_MET"                   );
                                        ana.tx.createBranch<float>("OS2jet_MET_fatjet1_DPhi"      );
                                        ana.tx.createBranch<float>("OS2jet_MET_ll_DPhi"           );
                                        ana.tx.createBranch<int>  ("OS2jet_fatjet1_genmatching"   );
                                        ana.tx.createBranch<int>  ("OS2jet_fatjet2_genmatching"   );


    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_Preselection",
                                      [&]()
                                      {
                                        bool isSFOSZ = false;
                                        bool isSFOS = false;
                                        //2 leptons
                                        if (not (ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size() == 2))
                                          return false;
                                        if(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt()<25)
                                          return false;
                                        if(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].Pt()<15)
                                          return false;
                                        //test for OS
                                        if(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]*ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1]>0)
                                          return false;
                                        //cout << ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0] << " " << ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1] << endl;
                                        //test for SFOSs
                                        if(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]==(-ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1])){
                                          isSFOS = true;
                                          //test if OS is a Z
                                          if( abs((ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]).M()-91.1876)<20.)
                                            isSFOSZ = true;
                                        }
                                        // test trigger bits
                                        //if (!nt.hasGenBranches()){// run only on data
                                        
                                        if (true){// run on data and simulation
                                          bool passtrigger = false;
                                          if(abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]*ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1])==121){
                                            //if exist HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL_DZ - does not exist 2018
                                            //           if exist HLT_Ele17_Ele12_CaloIdL_TrackIdL_IsoVL - does not exist 2018
                                            if(nt.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL()   ) passtrigger = true;
                                            if(nt.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ()) passtrigger = true;
                                          }
                                          if(abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]*ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1])==169){
                                            //HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8 - does not exist 2016
                                            //HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass8 - does not exist 2016
                                            if(nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ()) passtrigger = true;
                                            if(nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL()   ) passtrigger = true;
                                              //HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL_DZ - does not exist 2018
                                              //HLT_Mu17_TrkIsoVVL_TkMu8_TrkIsoVVL - does not exist 2018
                                          }
                                          if(abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]*ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1])==143){
                                            if(nt.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ()) passtrigger = true;
                                            if(nt.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL()   ) passtrigger = true;
                                              //HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL_DZ - does not exist 2018
                                              //HLT_Mu23_TrkIsoVVL_Ele8_CaloIdL_TrackIdL_IsoVL - does not exist 2018
                                            if(nt.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ()) passtrigger = true;
                                            if(nt.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL()   ) passtrigger = true;
                                          }
                                          if(!passtrigger) return false;
                                        }
                                        
                                        int njets = 0; int nbjets = 0; int nbjetsmed = 0;
                                        for (unsigned int ijet = 0; ijet < nt.Jet_p4().size(); ++ijet){
                                          if (nt.Jet_pt()[ijet] < 30.) continue;
                                          if(abs(nt.Jet_eta()[ijet]) > 2.5) continue;
                                          ++njets;
                                          if(nt.Jet_btagDeepFlavB()[ijet]>0.0494) ++nbjets;
                                          if(nt.Jet_btagDeepFlavB()[ijet]>0.2770) ++nbjetsmed;
                                        }
                                        int nfatjets = 0;
                                        for (unsigned int ijet = 0; ijet < nt.FatJet_p4().size(); ++ijet){
                                          if (nt.FatJet_pt()[ijet] < 200.) continue;
                                          if(abs(nt.FatJet_eta()[ijet]) > 2.5) continue;
                                          ++nfatjets;//was njets in <=v4c
                                        }
                                        //test if there are at least two jets, or one fat jet
                                        if(njets<2 && nfatjets < 1)
                                          return false;
                                        //if (nbjets>0)
                                        //  return false;//XXX undo this - implement a selection with >=1 b
                                        if(     isSFOSZ==true )  ana.tx.setBranch<int>("OS2jet_SFcontent"  ,2);
                                        else if(isSFOS ==true )  ana.tx.setBranch<int>("OS2jet_SFcontent"  ,1);
                                        else                     ana.tx.setBranch<int>("OS2jet_SFcontent"  ,0);
                                        //make some default setting - overwrite later
                                        ana.tx.setBranch<float>("OS2jet_lep1_pt",               ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt());
                                        ana.tx.setBranch<float>("OS2jet_lep2_pt",               ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].Pt());
                                        ana.tx.setBranch<float>("OS2jet_lep12_ptvectorsum",    (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]).Pt());
                                        ana.tx.setBranch<float>("OS2jet_lep12_ptscalarsum",     ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt()+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].Pt());
                                        ana.tx.setBranch<float>("OS2jet_lep12_ptscalarprod",    ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt()*ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].Pt());
                                        ana.tx.setBranch<float>("OS2jet_lep12_mass",           (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]).M());
                                        ana.tx.setBranch<float>("OS2jet_lep12_DR",              RooUtil::Calc::DeltaR(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]));
                                        ana.tx.setBranch<float>("OS2jet_lep12_DPhi",            abs(RooUtil::Calc::DeltaPhi(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1])));
                                        ana.tx.setBranch<float>("OS2jet_lep12_Deta",            abs(RooUtil::Calc::DeltaEta(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1])));
                                        ana.tx.setBranch<int>  ("OS2jet_Jetcontent",            -999);
                                        ana.tx.setBranch<int>  ("OS2jet_Nfatjets",              -999);
                                        ana.tx.setBranch<int>  ("OS2jet_Njets",                 -999);
                                        ana.tx.setBranch<int>  ("OS2jet_Nbjetsv1",              nbjets);
                                        ana.tx.setBranch<int>  ("OS2jet_Nbjetsmedv1",           nbjetsmed);
                                        ana.tx.setBranch<int>  ("OS2jet_Nbjetsv2",              -999);
                                        ana.tx.setBranch<int>  ("OS2jet_NfatjetsMinusNjets",    -999);
                                        ana.tx.setBranch<float>("OS2jet_MET",                   nt.MET_pt());
                                        ana.tx.setBranch<float>("OS2jet_MET_fatjet1_DPhi",      -999);
                                        // ana.tx.setBranch<float>("OS2jet_MET_ll_DPhi",           abs(RooUtil::Calc::DeltaPhi(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1],nt.MET_p4()));
                                        ana.tx.setBranch<float>("OS2jet_MET_ll_DPhi",           -999);
                                        ana.tx.setBranch<int>  ("OS2jet_fatjet1_idx",           -999);   
                                        ana.tx.setBranch<int>  ("OS2jet_fatjet2_idx",           -999); 
                                        ana.tx.setBranch<float>("OS2jet_fatjet1_pt",            -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet2_pt",            -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet1_mass",          -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet2_mass",          -999.);     
                                        ana.tx.setBranch<float>("OS2jet_fatjet1_massSD",        -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet2_massSD",        -999.);  
                                        ana.tx.setBranch<float>("OS2jet_fatjet1_tau21",         -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet2_tau21",         -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet1_tau32",         -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet2_tau32",         -999.); 
                                        ana.tx.setBranch<float>("OS2jet_fatjet1_ll_DR",         -999.); 
                                        ana.tx.setBranch<float>("OS2jet_fatjet2_ll_DR",         -999.); 
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_ll_DRmax",     -999.); 
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_ptvectorsum",  -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_ptscalarsum",  -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_ptscalarprod", -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_mass",         -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_masssum",      -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_massproduct",  -999.);  
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_massSDsum",    -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_massSDproduct",-999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_DR",           -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_DPhi",         -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_DEta",         -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet1_toptag",        -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet2_toptag",        -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet1_Wtag",          -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet2_Wtag",          -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet1_Ztag",          -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet2_Ztag",          -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet1_Zbbtag",        -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet2_Zbbtag",        -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet1_WpZtag",        -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet1_WtZtag",        -999.); 
                                        ana.tx.setBranch<float>("OS2jet_fatjet2_WpZtag",        -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet2_WtZtag",        -999.);    
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_WtWtag",       -999.);    
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_WtZtag",       -999.);    
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_ZtWtag",       -999.);    
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_ZtZtag",       -999.);    
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_WpWtag",       -999.);    
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_WpZtag",       -999.);    
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_ZpWtag",       -999.);   
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_ZpZtag",       -999.);   
                                        ana.tx.setBranch<int>  ("OS2jet_jet1_idx",              -999.);   
                                        ana.tx.setBranch<int>  ("OS2jet_jet2_idx",              -999.); 
                                        ana.tx.setBranch<float>("OS2jet_jet1_pt",               -999.);   
                                        ana.tx.setBranch<float>("OS2jet_jet2_pt",               -999.);   
                                        ana.tx.setBranch<float>("OS2jet_jet12_ptvectorsum",     -999.);   
                                        ana.tx.setBranch<float>("OS2jet_jet12_ptscalarsum",     -999.);   
                                        ana.tx.setBranch<float>("OS2jet_jet12_ptscalarprod",    -999.);   
                                        ana.tx.setBranch<float>("OS2jet_jet12_mass",            -999.);    
                                        ana.tx.setBranch<float>("OS2jet_jet12_DR",              -999.);   
                                        ana.tx.setBranch<float>("OS2jet_jet12_DPhi",            -999.);
                                        ana.tx.setBranch<float>("OS2jet_jet12_DEta",            -999.);
                                        ana.tx.setBranch<int>  ("OS2jet_fatjet1_genmatching",   -999.); 
                                        ana.tx.setBranch<int>  ("OS2jet_fatjet2_genmatching",   -999.); 
                                       //now fill branches already here
                                        int nfat= 0; int nnonfat = 0; int nbnonfat = 0;
                                        //start with fat jets
                                        int fatidx1 = -1; int fatidx2 = -1;
                                        for(unsigned int i = 0; i<nt.FatJet_pt().size(); ++i){
                                          if(    nt.FatJet_pt()[i]   < 200.) continue;
                                          if(abs(nt.FatJet_eta()[i]) > 2.5 ) continue;
                                          if(RooUtil::Calc::DeltaR(nt.FatJet_p4()[i],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]) < 0.8) continue;
                                          if(RooUtil::Calc::DeltaR(nt.FatJet_p4()[i],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]) < 0.8) continue;
                                          ++nfat;
                                          if(fatidx1<0) { fatidx1 = i; continue; }
                                          if(fatidx2<0) {
                                            if(nt.FatJet_pt()[i]>nt.FatJet_pt()[fatidx1]){
                                              fatidx2 = fatidx1;
                                              fatidx1 = i;
                                            }
                                            else {
                                              fatidx2 = i;
                                            }
                                            continue;
                                          }//first two fat jets
                                          if(nt.FatJet_pt()[i]>nt.FatJet_pt()[fatidx1]){
                                            fatidx2 = fatidx1;
                                            fatidx1 = i;
                                          }
                                          else if(nt.FatJet_pt()[i]>nt.FatJet_pt()[fatidx2]){
                                            fatidx2 = i;
                                          }
                                        }
                                        //do normal jets
                                        int jetidx1 = -1; int jetidx2 = -1;
                                        for(unsigned int ti = 0; ti<nt.Jet_pt().size(); ++ti){
                                          if(    nt.Jet_pt()[ti]   < 30.)  continue;
                                          if(abs(nt.Jet_eta()[ti]) > 2.5 ) continue;
                                          if(fatidx1>=0 &&  RooUtil::Calc::DeltaR(nt.Jet_p4()[ti],nt.Jet_p4()[fatidx1]) < 0.8) continue;
                                          if(fatidx2>=0 &&  RooUtil::Calc::DeltaR(nt.Jet_p4()[ti],nt.Jet_p4()[fatidx2]) < 0.8) continue;
                                          if(RooUtil::Calc::DeltaR(nt.Jet_p4()[ti],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]) < 0.4) continue;
                                          if(RooUtil::Calc::DeltaR(nt.Jet_p4()[ti],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]) < 0.4) continue;
                                          ++nnonfat;
                                          if(nt.Jet_btagDeepFlavB()[ti]>0.0494) ++nbnonfat;
                                          if(jetidx1<0) { jetidx1 = ti; continue; }
                                          if(jetidx2<0) {
                                            if(nt.Jet_pt()[ti]>nt.Jet_pt()[jetidx1]){
                                              jetidx2 = jetidx1;
                                              jetidx1 = ti;
                                            }
                                            else {
                                              jetidx2 = ti;
                                            }
                                            continue;
                                          }//first two fat jets
                                          if(nt.Jet_pt()[ti]>nt.Jet_pt()[jetidx1]){
                                            jetidx2 = jetidx1;
                                            jetidx1 = ti;
                                          }
                                          else if(nt.Jet_pt()[ti]>nt.Jet_pt()[jetidx2]){
                                            jetidx2 = ti;
                                          }
                                        }
                                        ana.tx.setBranch<int>  ("OS2jet_Nfatjets",              nfat);
                                        ana.tx.setBranch<int>  ("OS2jet_Njets",                 nnonfat);
                                        ana.tx.setBranch<int>  ("OS2jet_Nbjetsv2",              nbnonfat);
                                        ana.tx.setBranch<int>  ("OS2jet_NfatjetsMinusNjets",    nfat-nnonfat);
                                        if(     nfat>=2)     ana.tx.setBranch<int>("OS2jet_Jetcontent" ,2);
                                        else if(nfat==1)     ana.tx.setBranch<int>("OS2jet_Jetcontent" ,1);
                                        else if(nnonfat>=2)  ana.tx.setBranch<int>("OS2jet_Jetcontent" ,0);
                                        //do >=1fatjet
                                        if(fatidx1>=0){
                                          //ana.tx.setBranch<int>  ("OS2jet_MET_fatjet1_DPhi",      abs(RooUtil::Calc::DeltaPhi(nt.FatJet_pt()[fatidx1],nt.MET_p4()));
                                          ana.tx.setBranch<int>  ("OS2jet_fatjet1_idx",           fatidx1                                );   
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_pt",            nt.FatJet_pt                ()[fatidx1]);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_mass",          nt.FatJet_mass              ()[fatidx1]);       
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_massSD",        nt.FatJet_msoftdrop         ()[fatidx1]);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_tau21",         nt.FatJet_tau1()[fatidx1]!=0 ? nt.FatJet_tau2()[fatidx1]/nt.FatJet_tau1()[fatidx1] : -999.);
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_tau32",         nt.FatJet_tau2()[fatidx1]!=0 ? nt.FatJet_tau3()[fatidx1]/nt.FatJet_tau2()[fatidx1] : -999.);
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_toptag",        nt.FatJet_deepTagMD_TvsQCD  ()[fatidx1]);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_Wtag",          nt.FatJet_deepTagMD_WvsQCD  ()[fatidx1]);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_Ztag",          nt.FatJet_deepTagMD_ZvsQCD  ()[fatidx1]);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_Zbbtag",        nt.FatJet_deepTagMD_ZbbvsQCD()[fatidx1]);  
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_WpZtag",        nt.FatJet_deepTagMD_WvsQCD  ()[fatidx1]+nt.FatJet_deepTagMD_ZvsQCD  ()[fatidx1]);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_WtZtag",        nt.FatJet_deepTagMD_WvsQCD  ()[fatidx1]*nt.FatJet_deepTagMD_ZvsQCD  ()[fatidx1]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_ll_DR",         RooUtil::Calc::DeltaR(nt.FatJet_p4()[fatidx1],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]));
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ll_DRmax",     RooUtil::Calc::DeltaR(nt.FatJet_p4()[fatidx1],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1])); 
                                          for(unsigned int ig = 0; ig<=ana.tx.getBranchLazy<vector<int>>("Common_gen_idx").size(); ++ig){
                                            if(abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[ig])!=23 && abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[ig])!=24)
                                              continue;
                                            if(RooUtil::Calc::DeltaR(nt.FatJet_p4()[fatidx1],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_gen_p4s")[ig])<0.4){
                                              ana.tx.setBranch<int>  ("OS2jet_fatjet1_genmatching",  ig);
                                              break;
                                            }
                                          }
                                        }
                                        //do >=2 fatjet
                                        if(fatidx2>=0){
                                          ana.tx.setBranch<int>  ("OS2jet_fatjet2_idx",           fatidx2                                );   
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_pt",            nt.FatJet_pt                ()[fatidx2]);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_mass",          nt.FatJet_mass              ()[fatidx2]);      
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_massSD",        nt.FatJet_msoftdrop         ()[fatidx2]);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_tau21",         nt.FatJet_tau1()[fatidx2]!=0 ? nt.FatJet_tau2()[fatidx2]/nt.FatJet_tau1()[fatidx2] : -999.);
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_tau32",         nt.FatJet_tau2()[fatidx2]!=0 ? nt.FatJet_tau3()[fatidx2]/nt.FatJet_tau2()[fatidx2] : -999.);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_toptag",        nt.FatJet_deepTagMD_TvsQCD  ()[fatidx2]);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_Wtag",          nt.FatJet_deepTagMD_WvsQCD  ()[fatidx2]);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_Ztag",          nt.FatJet_deepTagMD_ZvsQCD  ()[fatidx2]);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_Zbbtag",        nt.FatJet_deepTagMD_ZbbvsQCD()[fatidx2]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_WpZtag",        nt.FatJet_deepTagMD_WvsQCD  ()[fatidx2]+nt.FatJet_deepTagMD_ZvsQCD  ()[fatidx2]);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_WtZtag",        nt.FatJet_deepTagMD_WvsQCD  ()[fatidx2]*nt.FatJet_deepTagMD_ZvsQCD  ()[fatidx2]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_ll_DR",         RooUtil::Calc::DeltaR(nt.FatJet_p4()[fatidx2],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]));   
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ll_DRmax",     std::max(RooUtil::Calc::DeltaR(nt.FatJet_p4()[fatidx2],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]),RooUtil::Calc::DeltaR(nt.FatJet_p4()[fatidx1],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1])));   
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ptvectorsum",  (nt.FatJet_p4()[fatidx1]+nt.FatJet_p4()[fatidx1]).Pt());
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ptscalarsum",   nt.FatJet_pt()[fatidx1]+nt.FatJet_pt()[fatidx2]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ptscalarprod",  nt.FatJet_pt()[fatidx1]*nt.FatJet_pt()[fatidx2]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_mass",         (nt.FatJet_p4()[fatidx1]+nt.FatJet_p4()[fatidx1]).M());
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_masssum",       nt.FatJet_mass()[fatidx1]+nt.FatJet_mass()[fatidx2]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_massproduct",   nt.FatJet_mass()[fatidx1]*nt.FatJet_mass()[fatidx2]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_massSDsum",     nt.FatJet_msoftdrop()[fatidx1]+nt.FatJet_msoftdrop()[fatidx2]);   
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_massSDproduct", nt.FatJet_msoftdrop()[fatidx1]*nt.FatJet_msoftdrop()[fatidx2]);  
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_DR",            RooUtil::Calc::DeltaR(  nt.FatJet_p4()[fatidx1],nt.FatJet_p4()[fatidx2]));
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_DPhi",          abs(RooUtil::Calc::DeltaPhi(nt.FatJet_p4()[fatidx1],nt.FatJet_p4()[fatidx2])));
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_DEta",          abs(RooUtil::Calc::DeltaEta(nt.FatJet_p4()[fatidx1],nt.FatJet_p4()[fatidx2])));
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_WtWtag",        nt.FatJet_deepTagMD_WvsQCD()[fatidx1]*nt.FatJet_deepTagMD_WvsQCD()[fatidx2]);    
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_WtZtag",        nt.FatJet_deepTagMD_WvsQCD()[fatidx1]*nt.FatJet_deepTagMD_ZvsQCD()[fatidx2]);    
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ZtWtag",        nt.FatJet_deepTagMD_ZvsQCD()[fatidx1]*nt.FatJet_deepTagMD_WvsQCD()[fatidx2]);    
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ZtZtag",        nt.FatJet_deepTagMD_ZvsQCD()[fatidx1]*nt.FatJet_deepTagMD_ZvsQCD()[fatidx2]);    
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_WpWtag",        nt.FatJet_deepTagMD_WvsQCD()[fatidx1]+nt.FatJet_deepTagMD_WvsQCD()[fatidx2]);    
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_WpZtag",        nt.FatJet_deepTagMD_WvsQCD()[fatidx1]+nt.FatJet_deepTagMD_ZvsQCD()[fatidx2]);    
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ZpWtag",        nt.FatJet_deepTagMD_ZvsQCD()[fatidx1]+nt.FatJet_deepTagMD_WvsQCD()[fatidx2]); 
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ZpZtag",        nt.FatJet_deepTagMD_ZvsQCD()[fatidx1]+nt.FatJet_deepTagMD_ZvsQCD()[fatidx2]); 
                                          for(unsigned int ig = 0; ig<=ana.tx.getBranchLazy<vector<int>>("Common_gen_idx").size(); ++ig){
                                            if(abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[ig])!=23 && abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[ig])!=24)
                                              continue;
                                            if(RooUtil::Calc::DeltaR(nt.FatJet_p4()[fatidx2],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_gen_p4s")[ig])<0.4){
                                              ana.tx.setBranch<int>  ("OS2jet_fatjet2_genmatching",  ig);
                                              break;
                                            }
                                          }
                                        }
                                        //do >=2 jets - do jets orthogonal to fatjets
                                        if(jetidx2>=0){  
                                          ana.tx.setBranch<int>  ("OS2jet_jet1_idx",              jetidx1);   
                                          ana.tx.setBranch<int>  ("OS2jet_jet2_idx",              jetidx2); 
                                          ana.tx.setBranch<float>("OS2jet_jet1_pt",               nt.Jet_pt()[jetidx1]);   
                                          ana.tx.setBranch<float>("OS2jet_jet2_pt",               nt.Jet_pt()[jetidx2]);   
                                          ana.tx.setBranch<float>("OS2jet_jet12_ptvectorsum",    (nt.Jet_p4()[jetidx1]+nt.Jet_p4()[jetidx1]).Pt());   
                                          ana.tx.setBranch<float>("OS2jet_jet12_ptscalarsum",     nt.Jet_pt()[jetidx1]+nt.Jet_pt()[jetidx2]);   
                                          ana.tx.setBranch<float>("OS2jet_jet12_ptscalarprod",    nt.Jet_pt()[jetidx1]*nt.Jet_pt()[jetidx2]);   
                                          ana.tx.setBranch<float>("OS2jet_jet12_mass",           (nt.Jet_p4()[jetidx1]+nt.Jet_p4()[jetidx2]).M());    
                                          ana.tx.setBranch<float>("OS2jet_jet12_DR",              RooUtil::Calc::DeltaR(  nt.Jet_p4()[jetidx1],nt.Jet_p4()[jetidx2]));   
                                          ana.tx.setBranch<float>("OS2jet_jet12_DPhi",            abs(RooUtil::Calc::DeltaPhi(nt.Jet_p4()[jetidx1],nt.Jet_p4()[jetidx2])));
                                          ana.tx.setBranch<float>("OS2jet_jet12_DEta",            abs(RooUtil::Calc::DeltaEta(nt.Jet_p4()[jetidx1],nt.Jet_p4()[jetidx2])));
                                        }


                                        return true;
                                      }, UNITY);// trigger SF would go in here instead of UNITY, in principle also btag weight
    // --------------------
    // ***      OF      ***
    // --------------------
    ana.cutflow.getCut("Cut_OS2jet_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OFPreselection",           [&]() { return ana.tx.getBranch<int>("OS2jet_SFcontent") ==0 && ana.tx.getBranch<int>("OS2jet_Nbjetsv1")==0;}, UNITY);
    // __________________
    // *** OS2jet_OF2jets
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2jets",                  [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==0 && ana.tx.getBranch<int>("OS2jet_Njets")>=2;}, UNITY);
    // ____________________
    // *** OS2jet_OF1fatjet
    ana.cutflow.getCut("Cut_OS2jet_OFPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet",                [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==1;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_masscuts",       [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_mass")>50 && ana.tx.getBranch<float>("OS2jet_fatjet1_mass")<110;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_masstagcuts",    [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.5 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_massSDcuts",     [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")>60 && ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")<110;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_massSDtagcuts",  [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.5 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_tagcuts",        [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.5 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6;}, UNITY);
    // _____________________
    // *** OS2jet_OF2fatjets
    // note: did full chain only for tag12plus/tag1and2 as well as M12/M12SD
    ana.cutflow.getCut("Cut_OS2jet_OFPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets",                     [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==2;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_tag12pluscuts",       [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_WpWtag")>0.6 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.65;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_tag12M12cuts",        [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")>100 && ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")<220 && ana.tx.getBranch<float>("OS2jet_fatjet12_ptvectorsum")>650;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets_tag12pluscuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_tag12MSD12cuts",      [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_massSDsum")>120 && ana.tx.getBranch<float>("OS2jet_fatjet12_massSDsum")<220 && ana.tx.getBranch<float>("OS2jet_fatjet12_ptvectorsum")>650;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_tag12multcuts",       [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_WtWtag")>0.1 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.65;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_tag1and2cuts",        [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.35 && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6) && (ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag")>0.35 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.6);}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_tag1and2M12cuts",     [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")>100 && ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")<220 && ana.tx.getBranch<float>("OS2jet_fatjet12_ptvectorsum")>650;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets_tag1and2cuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_tag1and2MSD12cuts",   [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_massSDsum")>120 && ana.tx.getBranch<float>("OS2jet_fatjet12_massSDsum")<220 && ana.tx.getBranch<float>("OS2jet_fatjet12_ptvectorsum")>650;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets_tag1and2cuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_tag12plusandcuts",    [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_WpWtag")>0.6 && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.6;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_tag1or2cuts",         [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.35 && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6) || (ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag")>0.35 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.6);}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_tag12orcuts",         [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.65 || ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.5) && (ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag")>0.65 || ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.5);}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_mass12cuts",          [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")>100 && ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")<220 && ana.tx.getBranch<float>("OS2jet_fatjet12_ptvectorsum")>650;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_mass1and2cuts",       [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_mass")>50 && ana.tx.getBranch<float>("OS2jet_fatjet2_mass")>50 && ana.tx.getBranch<float>("OS2jet_fatjet1_pt")>350 && ana.tx.getBranch<float>("OS2jet_fatjet2_pt")>250;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_massSD12cuts",        [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_massSDsum")>120 && ana.tx.getBranch<float>("OS2jet_fatjet12_massSDsum")<220 && ana.tx.getBranch<float>("OS2jet_fatjet12_ptvectorsum")>650;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_massSD1and2cuts",     [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")>65 && ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")<100 && ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")>65 && ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")<100 && ana.tx.getBranch<float>("OS2jet_fatjet1_pt")>350 && ana.tx.getBranch<float>("OS2jet_fatjet2_pt")>250;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_massSD1or2cuts",      [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")>65. && ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")<105.)||(ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")>65. && ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")<105.);}, UNITY);


    // --------------------
    // *** SF without Z ***
    // --------------------
    ana.cutflow.getCut("Cut_OS2jet_Preselection");
    // _____________________
    // *** OS2jet_SFnoZ2jets
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZPreselection", [&]() { return ana.tx.getBranch<int>("OS2jet_SFcontent") ==1 && ana.tx.getBranch<int>("OS2jet_Nbjetsv1")==0;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2jets",        [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==0 && ana.tx.getBranch<int>("OS2jet_Njets")>=3;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2jets_sel",    [&]() { return ana.tx.getBranch<float>("OS2jet_lep12_DR")<2.1 && ana.tx.getBranch<float>("OS2jet_jet12_DR")<2.1;}, UNITY);
    // _______________________
    // *** OS2jet_SFnoZ1fatjet
    ana.cutflow.getCut("Cut_OS2jet_SFnoZPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet",                    [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==1;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_masscuts",           [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_mass")>65;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_masstagcuts",        [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ1fatjet_masstagcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_massttagcuts",       [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Ztag")>0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_massSDcuts",         [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")>65 && ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")<110;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_massSDtagcuts",      [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ1fatjet_massSDtagcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_massSDttagcuts",     [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Ztag")>0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_tagcuts",            [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ1fatjet_tagcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_ttagcuts",           [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Ztag")>0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6;}, UNITY);

    // ________________________
    // *** OS2jet_SFnoZ2fatjets
    ana.cutflow.getCut("Cut_OS2jet_SFnoZPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets",                       [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==2;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_tag12pluscuts",         [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_WpWtag")>0.7 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_tag12M12cuts",          [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")>120 && ana.tx.getBranch<float>("OS2jet_fatjet12_mass")>100;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets_tag12pluscuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_tag12MSD12cuts",        [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")>80 && ana.tx.getBranch<float>("OS2jet_fatjet12_mass")>100;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_tag12multcuts",         [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_WtWtag")>0.15 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_tag1and2cuts",          [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.5 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.65) && (ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag")>0.5 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.65) && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_tag1and2M12cuts",       [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")>120 && ana.tx.getBranch<float>("OS2jet_fatjet12_mass")>100;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets_tag1and2cuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_tag1and2MSD12cuts",     [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")>80 && ana.tx.getBranch<float>("OS2jet_fatjet12_mass")>100;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_tag12plusandcuts",      [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_WpWtag")>0.7;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_tag1or2cuts",           [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.5 && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.65) || (ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag")>0.5 && ana.tx.getBranch<float>("OS2jet_fatjet1_toptag")<0.65 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.65);}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_tag12orcuts",           [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.65 || ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.5) && (ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag")>0.65 || ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.5);}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_mass12cuts",            [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")>120 && ana.tx.getBranch<float>("OS2jet_fatjet12_mass")>100;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_mass1and2cuts",         [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_mass")>60 && ana.tx.getBranch<float>("OS2jet_fatjet2_mass")>60 && ana.tx.getBranch<float>("OS2jet_fatjet1_mass")<120 && ana.tx.getBranch<float>("OS2jet_fatjet2_mass")<120;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_massSD12cuts",          [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_massSDsum")>80;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_massSD1and2cuts",       [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")>70 && ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")<120 && ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")>70 && ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")<120;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_massSD1or2cuts",        [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")>65. && ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")<105.)||(ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")>65. && ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")<105.);}, UNITY);

    // --------------------
    // ***   SF with Z  ***
    // --------------------
    ana.cutflow.getCut("Cut_OS2jet_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZPreselection",   [&]() { return ana.tx.getBranch<int>("OS2jet_SFcontent") ==2 && ana.tx.getBranch<int>("OS2jet_Nbjetsv1")==0;}, UNITY);
    // ___________________
    // *** OS2jet_SFZ2jets
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2jets",          [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==0;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2jets_sel",      [&]() { return ana.tx.getBranch<float>("OS2jet_lep12_DR")<2.1 && ana.tx.getBranch<float>("OS2jet_jet12_DR")<1.57;}, UNITY);
    // _____________________
    // *** OS2jet_SFZ1fatjet
    ana.cutflow.getCut("Cut_OS2jet_SFZPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet",                    [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==1;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_masscuts",           [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_mass")>70 && ana.tx.getBranch<float>("OS2jet_fatjet1_mass")<110;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_masstagcuts",        [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.75 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.5;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ1fatjet_masstagcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_massttagcuts",       [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Ztag")==0.8;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_massSDcuts",         [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")>70 && ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")<110;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_massSDtagcuts",      [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.75 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.5;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_massSDttagcuts",     [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Ztag")==0.8;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_tagcuts",            [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.75 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.5;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ1fatjet_tagcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_ttagcuts",           [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Ztag")==0.8;}, UNITY);
    // ______________________
    // *** OS2jet_SFZ2fatjets
    ana.cutflow.getCut("Cut_OS2jet_SFZPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets",                       [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==2;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_tag12pluscuts",         [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_WpWtag")>0.8  && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.5 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.5;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_tag12M12cuts",          [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")>120 && ana.tx.getBranch<float>("OS2jet_fatjet12_mass")>100;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets_tag12pluscuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_tag12MSD12cuts",        [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")>80 && ana.tx.getBranch<float>("OS2jet_fatjet12_mass")>100;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_tag12multcuts",         [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_WtWtag")>0.25 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.5 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.5;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_tag1and2cuts",          [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.75 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.5) && (ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag")>0.75 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.5);}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_tag1and2M12cuts",       [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")>120 && ana.tx.getBranch<float>("OS2jet_fatjet12_mass")>100;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets_tag1and2cuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_tag1and2MSD12cuts",     [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")>80 && ana.tx.getBranch<float>("OS2jet_fatjet12_mass")>100;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_tag1or2cuts",           [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.75 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.5) || (ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag")>0.75 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.5);}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_tag12orcuts",           [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.65 || ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.5) && (ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag")>0.65 || ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.5);}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_mass12cuts",            [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet12_masssum")>120 && ana.tx.getBranch<float>("OS2jet_fatjet12_mass")>100;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_mass1and2cuts",         [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_mass")>70 && ana.tx.getBranch<float>("OS2jet_fatjet2_mass")>70 && ana.tx.getBranch<float>("OS2jet_fatjet1_pt")>350 && ana.tx.getBranch<float>("OS2jet_fatjet2_pt")>250;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_massSD1or2cuts",        [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")>65. && ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")<105.)||(ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")>65. && ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")<105.);}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_massSD1and2cuts",       [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")>65 && ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")<110 && ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")>65 && ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")<110 && ana.tx.getBranch<float>("OS2jet_fatjet1_pt")>350 && ana.tx.getBranch<float>("OS2jet_fatjet2_pt")>250;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_othcuts",               [&]() { return ana.tx.getBranch<float>("OS2jet_lep12_DR")<1.57 && ana.tx.getBranch<int>("OS2jet_Njets")>=2;}, UNITY);

    //top CR
    ana.cutflow.getCut("Cut_OS2jet_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR",                           [&]() { return ana.tx.getBranch<int>("OS2jet_Nbjetsmedv1")>=1;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2jets",                      [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==0;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR1fatjet",                    [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==1;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR1fatjet_massSDcut",          [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")>65 && ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")<105;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR1fatjet_tagcut",             [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets",                   [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==2;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_massSDorcut",       [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")>65 && ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")<105) || (ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")>65 && ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")<105);}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_massSDandcut",      [&]() { return  (ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")>65 && ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")<105) && (ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")>65 && ana.tx.getBranch<float>("OS2jet_fatjet2_massSD")<105);}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_tagorcut",          [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6) || (ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag")>0.65 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.6);}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_tagandcut",         [&]() { return (ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6) && (ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag")>0.65 && ana.tx.getBranch<float>("OS2jet_fatjet2_tau21")<0.6);}, UNITY);

    //DY CR
    ana.cutflow.getCut("Cut_OS2jet_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR",                             [&]() { return ana.tx.getBranch<int>("OS2jet_Njets")==0;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2jets",                        [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==0;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR1fatjet",                      [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==1;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR1fatjet_massSDcut",            [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")>65 && ana.tx.getBranch<float>("OS2jet_fatjet1_massSD")<105;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR1fatjet_tagcut",               [&]() { return ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag")>0.65 && ana.tx.getBranch<float>("OS2jet_fatjet1_tau21")<0.6;}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR");

    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    ana.histograms.addHistogram("SFcontent"    ,   3,   0,     3, [&]() { return      ana.tx.getBranch<int>  ("OS2jet_SFcontent"               )   ; } );
    ana.histograms.addHistogram("Jetcontent"   ,   3,   0,     3, [&]() { return      ana.tx.getBranch<int>  ("OS2jet_Jetcontent"              )   ; } );
    ana.histograms.addHistogram("Nfatjets"     ,   5,   0,     5, [&]() { return      ana.tx.getBranch<int>  ("OS2jet_Nfatjets"                )   ; } );
    ana.histograms.addHistogram("Njets"        ,  10,   0,    10, [&]() { return      ana.tx.getBranch<int>  ("OS2jet_Njets"                   )   ; } );
    ana.histograms.addHistogram("NfatMnorm"    ,  15, -10,     5, [&]() { return      ana.tx.getBranch<int>  ("OS2jet_NfatjetsMinusNjets"      )   ; } );
    ana.histograms.addHistogram("Lep1_pt"      , 300,   0,   900, [&]() { return      ana.tx.getBranch<float>("OS2jet_lep1_pt"                 )   ; } );
    ana.histograms.addHistogram("Lep2_pt"      , 300,   0,   900, [&]() { return      ana.tx.getBranch<float>("OS2jet_lep2_pt"                 )   ; } );
    ana.histograms.addHistogram("Lep12_vecpt"  , 300,   0,   600, [&]() { return      ana.tx.getBranch<float>("OS2jet_lep12_ptvectorsum"       )   ; } );
    ana.histograms.addHistogram("Lep12_avept"  , 300,   0,   600, [&]() { return      ana.tx.getBranch<float>("OS2jet_lep12_ptscalarsum"       )/2.; } );
    ana.histograms.addHistogram("Lep12_geopt"  , 300,   0,   600, [&]() { return sqrt(ana.tx.getBranch<float>("OS2jet_lep12_ptscalarprod"     ))   ; } );
    ana.histograms.addHistogram("Lep12_mass"   , 300,   0,  1200, [&]() { return      ana.tx.getBranch<float>("OS2jet_lep12_mass"              )   ; } );
    ana.histograms.addHistogram("Lep12_DR"     , 300,   0,     6, [&]() { return      ana.tx.getBranch<float>("OS2jet_lep12_DR"                )   ; } );
    ana.histograms.addHistogram("Lep12_DEta"   , 300,   0,     5, [&]() { return      ana.tx.getBranch<float>("OS2jet_lep12_DPhi"              )   ; } );
    ana.histograms.addHistogram("Lep12_DPhi"   , 320,   0,   3.2, [&]() { return      ana.tx.getBranch<float>("OS2jet_lep12_Deta"              )   ; } );
    ana.histograms.addHistogram("Fat1_pt"      , 300, 200,  2000, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_pt"              )   ; } );
    ana.histograms.addHistogram("Fat1_ll_DR"   , 300,   0,     6, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_ll_DR"           )   ; } );
    ana.histograms.addHistogram("Fat1_mass"    , 300,   0,   300, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_mass"            )   ; } );
    ana.histograms.addHistogram("Fat1_massSD"  , 300,   0,   300, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_massSD"          )   ; } );
    ana.histograms.addHistogram("Fat1_tau21oW" , 400,   0,    10, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            )>0 ? ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           )/ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            ) : -999.   ; } );
    ana.histograms.addHistogram("Fat1_tau21"   , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           )   ; } );
    ana.histograms.addHistogram("Fat1_tau32"   , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_tau32"           )   ; } );
    ana.histograms.addHistogram("Fat1_Wtag"    , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            )   ; } );
    ana.histograms.addHistogram("Fat1_Ztag"    , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_Ztag"            )   ; } );
    ana.histograms.addHistogram("Fat1_Zbbtag"  , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_Zbbtag"          )   ; } );
    ana.histograms.addHistogram("Fat1_toptag"  , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_toptag"          )   ; } );
    ana.histograms.addHistogram("Fat1_WpZtag"  , 400,  -2,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_WpZtag"          )   ; } );
    ana.histograms.addHistogram("Fat1_WtZtag"  , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_WtZtag"          )   ; } );
    ana.histograms.addHistogram("Fat2_pt"      , 300, 200,  2000, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_pt"              )   ; } );
    ana.histograms.addHistogram("Fat2_ll_DR"   , 300,   0,     6, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_ll_DR"           )   ; } );
    ana.histograms.addHistogram("Fat2_mass"    , 300,   0,   300, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_mass"            )   ; } );
    ana.histograms.addHistogram("Fat2_massSD"  , 300,   0,   300, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_massSD"          )   ; } );
    ana.histograms.addHistogram("Fat2_tau21oW" , 400,   0,    10, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            )>0 ? ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )/ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            ) : -999.   ; } );
    ana.histograms.addHistogram("Fat2_tau21"   , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )   ; } );
    ana.histograms.addHistogram("Fat2_tau32"   , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_tau32"           )   ; } );
    ana.histograms.addHistogram("Fat2_Wtag"    , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            )   ; } );
    ana.histograms.addHistogram("Fat2_Ztag"    , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_Ztag"            )   ; } );
    ana.histograms.addHistogram("Fat2_Zbbtag"  , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_Zbbtag"          )   ; } );
    ana.histograms.addHistogram("Fat2_toptag"  , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_toptag"          )   ; } );
    ana.histograms.addHistogram("Fat2_WpZtag"  , 400,  -2,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_WpZtag"          )   ; } );
    ana.histograms.addHistogram("Fat2_WtZtag"  , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_WtZtag"          )   ; } );
    ana.histograms.addHistogram("Fat12_vecpt"  , 300,   0,  3000, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_ptvectorsum"    )   ; } );
    ana.histograms.addHistogram("Fat12_avept"  , 300, 200,  2000, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_ptscalarsum"    )/2.; } );
    ana.histograms.addHistogram("Fat12_geopt"  , 300, 200,  2000, [&]() { return sqrt(ana.tx.getBranch<float>("OS2jet_fatjet12_ptscalarprod"  ))   ; } );
    ana.histograms.addHistogram("Fat12_ll_DRmax",300,   0,     6, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_ll_DRmax"       )   ; } );
    ana.histograms.addHistogram("Fat12_mass"   , 300,   0,  3000, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_mass"           )   ; } );
    ana.histograms.addHistogram("Fat12_aveM"   , 300,   0,   300, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_masssum"        )/2.; } );
    ana.histograms.addHistogram("Fat12_aveMSD" , 300,   0,   300, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_massSDsum"      )/2.; } );
    ana.histograms.addHistogram("Fat12_geoM"   , 300,   0,   300, [&]() { return sqrt(ana.tx.getBranch<float>("OS2jet_fatjet12_massproduct"   ))   ; } );
    ana.histograms.addHistogram("Fat12_geoMSD" , 300,   0,   300, [&]() { return sqrt(ana.tx.getBranch<float>("OS2jet_fatjet12_massSDproduct" ))   ; } );
    ana.histograms.addHistogram("Fat12_DR"     , 300,   0,     6, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_DR"             )   ; } );
    ana.histograms.addHistogram("Fat12_DPhi"   , 320,   0,   3.2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_DPhi"           )   ; } );
    ana.histograms.addHistogram("Fat12_DEta"   , 300,   0,     5, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_DEta"           )   ; } );
    ana.histograms.addHistogram("Fat12_t21sum" , 400,  -2,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           )+ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )   ; } );
    ana.histograms.addHistogram("Fat12_t21prod", 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           )*ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )   ; } );
    ana.histograms.addHistogram("Fat12_WtWtag" , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_WtWtag"         )   ; } );
    ana.histograms.addHistogram("Fat12_WtZtag" , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_WtZtag"         )   ; } );
    ana.histograms.addHistogram("Fat12_ZtWtag" , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_ZtWtag"         )   ; } );
    ana.histograms.addHistogram("Fat12_ZtZtag" , 400,  -1,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_ZtZtag"         )   ; } );
    ana.histograms.addHistogram("Fat12_WpWtag" , 400,  -2,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_WpWtag"         )   ; } );
    ana.histograms.addHistogram("Fat12_WpZtag" , 400,  -2,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_WpZtag"         )   ; } );
    ana.histograms.addHistogram("Fat12_ZpWtag" , 400,  -2,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_ZpWtag"         )   ; } );
    ana.histograms.addHistogram("Fat12_ZpZtag" , 400,  -2,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_ZpZtag"         )   ; } );
    ana.histograms.addHistogram("Jet1_pt"      , 300,   0,   900, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet1_pt"                 )   ; } );
    ana.histograms.addHistogram("Jet2_pt"      , 300,   0,   900, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet2_pt"                 )   ; } );
    ana.histograms.addHistogram("Jet12_pt"     , 300,   0,  1800, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet12_ptvectorsum"       )   ; } );
    ana.histograms.addHistogram("Jet12_avept"  , 300,   0,   900, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet12_ptscalarsum"       )/2.; } );
    ana.histograms.addHistogram("Jet12_geopt"  , 300,   0,   900, [&]() { return sqrt(ana.tx.getBranch<float>("OS2jet_jet12_ptscalarprod"     ))   ; } );
    ana.histograms.addHistogram("Jet12_mass"   , 300,   0,  1800, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet12_mass"              )   ; } );
    ana.histograms.addHistogram("Jet12_DR"     , 300,   0,     6, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet12_DR"                )   ; } );
    ana.histograms.addHistogram("Jet12_DPhi"   , 320,   0,   3.2, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet12_DPhi"              )   ; } );
    ana.histograms.addHistogram("Jet12_DEta"   , 300,   0,     5, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet12_DEta"              )   ; } );

    ana.histograms.addHistogram("Fat1_massSDgenmatch"  , 300,   0,   300, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_massSD"          ) : -999.   ; } );
    ana.histograms.addHistogram("Fat1_tau21oWgenmatch" , 400,   0,    10, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    (ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            )>0 ? ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           )/ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            ) : -999.) : -999.   ; } );
    ana.histograms.addHistogram("Fat1_tau21genmatch"   , 400,  -1,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           ) : -999.   ; } );
    ana.histograms.addHistogram("Fat1_Wtaggenmatch"    , 400,  -1,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            ) : -999.   ; } );
    ana.histograms.addHistogram("Fat2_massSDgenmatch"  , 300,   0,   300, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_massSD"          ) : -999.   ; } );
    ana.histograms.addHistogram("Fat2_tau21oWgenmatch" , 400,   0,    10, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    (ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            )>0 ? ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )/ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            ) : -999.) : -999.   ; } );
    ana.histograms.addHistogram("Fat2_tau21genmatch"   , 400,  -1,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           ) : -999.   ; } );
    ana.histograms.addHistogram("Fat2_Wtaggenmatch"    , 400,  -1,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            ) : -999.   ; } );

    ana.histograms.add2DHistogram("Fat1_massSDgenmatch"  , 100,   0,   200, "Fat1_tau21genmatch"  , 100,   0,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_massSD"        ) : -999.   ; }, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           ) : -999.   ; } );
    ana.histograms.add2DHistogram("Fat1_massSDgenmatch"  , 100,   0,   200, "Fat1_Wtaggenmatch"   , 100,   0,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_massSD"        ) : -999.   ; }, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            ) : -999.   ; } );
    ana.histograms.add2DHistogram("Fat1_Wtaggenmatch"    , 100,   0,     1, "Fat1_tau21genmatch"  , 100,   0,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"          ) : -999.   ; }, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           ) : -999.   ; } );
    ana.histograms.add2DHistogram("Fat1_massSD"  , 100,   0,   200, "Fat1_tau21"  , 100,   0,     1, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet1_massSD"        )   ; }, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           )   ; } );
    ana.histograms.add2DHistogram("Fat1_massSD"  , 100,   0,   200, "Fat1_Wtag"   , 100,   0,     1, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet1_massSD"        )   ; }, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            )   ; } );
    ana.histograms.add2DHistogram("Fat1_Wtag"    , 100,   0,     1, "Fat1_tau21"  , 100,   0,     1, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"          )   ; }, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           )   ; } );
    ana.histograms.add2DHistogram("Fat2_massSDgenmatch"  , 100,   0,   200, "Fat2_tau21genmatch"  , 100,   0,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_massSD"        ) : -999.   ; }, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           ) : -999.   ; } );
    ana.histograms.add2DHistogram("Fat2_massSDgenmatch"  , 100,   0,   200, "Fat2_Wtaggenmatch"   , 100,   0,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_massSD"        ) : -999.   ; }, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            ) : -999.   ; } );
    ana.histograms.add2DHistogram("Fat2_Wtaggenmatch"    , 100,   0,     1, "Fat2_tau21genmatch"  , 100,   0,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"          ) : -999.   ; }, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           ) : -999.   ; } );
    ana.histograms.add2DHistogram("Fat2_massSD"  , 100,   0,   200, "Fat2_tau21"  , 100,   0,     1, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet2_massSD"        )   ; }, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )   ; } );
    ana.histograms.add2DHistogram("Fat2_massSD"  , 100,   0,   200, "Fat2_Wtag"   , 100,   0,     1, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet2_massSD"        )   ; }, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            )   ; } );
    ana.histograms.add2DHistogram("Fat2_Wtag"    , 100,   0,     1, "Fat2_tau21"  , 100,   0,     1, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"          )   ; }, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )   ; } );


    RooUtil::Histograms hists_OS2jet;

    // Now book cutflow histogram (could be commented out if user does not want.)
    // N.B. Cutflow histogramming can be CPU consuming.
    ana.cutflow.bookCutflows();

    // Book histograms to cuts that user wants for this category.
    ana.cutflow.bookHistogramsForCutAndBelow(ana.histograms, "Cut_OS2jet_Preselection");
}
