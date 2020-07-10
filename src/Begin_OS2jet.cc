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
    //ana.tx.createBranch<float>("OS2jet_fatjet1_WpZtag"        );
    //ana.tx.createBranch<float>("OS2jet_fatjet1_WtZtag"        );
    //ana.tx.createBranch<float>("OS2jet_fatjet2_WpZtag"        );
    //ana.tx.createBranch<float>("OS2jet_fatjet2_WtZtag"        );
    ana.tx.createBranch<float>("OS2jet_fatjet12_WtWtag"       );
    //ana.tx.createBranch<float>("OS2jet_fatjet12_WtZtag"       );
    //ana.tx.createBranch<float>("OS2jet_fatjet12_ZtWtag"       );
    //ana.tx.createBranch<float>("OS2jet_fatjet12_ZtZtag"       );
    ana.tx.createBranch<float>("OS2jet_fatjet12_WpWtag"       );
    //ana.tx.createBranch<float>("OS2jet_fatjet12_WpZtag"       );
    //ana.tx.createBranch<float>("OS2jet_fatjet12_ZpWtag"       );
    //ana.tx.createBranch<float>("OS2jet_fatjet12_ZpZtag"       );
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
    ana.tx.createBranch<float>("OS2jet_genMVVV"               );
    ana.tx.createBranch<float>("OS2jet_genpTVVV"              );
    ana.tx.createBranch<float>("OS2jet_Mfatjetsleptons"       );
    ana.tx.createBranch<float>("OS2jet_MTfatjetsleptonsMET"   );
    ana.tx.createBranch<bool >("OS2jet_fatjet1_massSDcut"     );
    ana.tx.createBranch<bool >("OS2jet_fatjet1_WtagMcut"      );
    ana.tx.createBranch<bool >("OS2jet_fatjet1_WtagLcut"      );
    ana.tx.createBranch<bool >("OS2jet_fatjet1_tau21cut"      );
    ana.tx.createBranch<bool >("OS2jet_fatjet2_massSDcut"     );
    ana.tx.createBranch<bool >("OS2jet_fatjet2_WtagMcut"      );
    ana.tx.createBranch<bool >("OS2jet_fatjet2_WtagLcut"      );
    ana.tx.createBranch<bool >("OS2jet_fatjet2_tau21cut"      );
    ana.tx.createBranch<bool >("OS2jet_fatjet12_ANDmassSDcut" );
    ana.tx.createBranch<bool >("OS2jet_fatjet12_ANDWtagMcut"  );
    ana.tx.createBranch<bool >("OS2jet_fatjet12_ANDWtagLcut"  );
    ana.tx.createBranch<bool >("OS2jet_fatjet12_ANDtau21cut"  );
    ana.tx.createBranch<bool >("OS2jet_fatjet12_ORmassSDcut"  );
    ana.tx.createBranch<bool >("OS2jet_fatjet12_ORWtagMcut"   );
    ana.tx.createBranch<bool >("OS2jet_fatjet12_ORWtagLcut"   );
    ana.tx.createBranch<bool >("OS2jet_fatjet12_ORtau21cut"   );
    ana.tx.createBranch<int  >("OS2jet_Nfatjets_vloose"       );
    ana.tx.createBranch<int  >("OS2jet_Nfatjets_loose"        );
    ana.tx.createBranch<int  >("OS2jet_Nfatjets_medium"       );
    ana.tx.createBranch<float>("OS2jet_fatjetwgt_vloose"      );
    ana.tx.createBranch<float>("OS2jet_fatjetwgt_loose"       );
    ana.tx.createBranch<float>("OS2jet_fatjetwgt_medium"      );

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OSleps",
                                      [&]()
                                      {
                                         //2 leptons
                                        if (not (ana.tx.getBranchLazy<vector<int> >("Common_lep_pdgid").size() == 2))
                                          return false;
                                        if(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt()<25)
                                          return false;
                                        if(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].Pt()<15)
                                          return false;
                                        //test for OS
                                        if(ana.tx.getBranchLazy<vector<int> >("Common_lep_pdgid")[0]*ana.tx.getBranchLazy<vector<int> >("Common_lep_pdgid")[1]>0)
                                          return false;
                                        return true;
                                      }, [&]() { return ana.tx.getBranchLazy<float>("Common_event_lepSF"); });
                                    //}, UNITY );
    //ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_JetSelection",
    //                                  [&]()
    //                                  {
    //                                    //test if there are at least two jets, or one fat jet
    //                                    if(ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size()<2 && ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() < 1)
    //                                      return false;
    //                                    return true;
    //                                  }, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_Trigger",
                                      [&]()
                                      {
                                        // test trigger bits
                                        //if (nt.isData()){// run only on data
                                        if (true){// run on data and simulation
                                          if(nt.isData() && !(ana.tx.getBranchLazy<bool>("Common_pass_duplicate_removal_mm_em_ee"))) return false;
                                          if(abs(ana.tx.getBranchLazy<vector<int> >("Common_lep_pdgid")[0]*ana.tx.getBranchLazy<vector<int> >("Common_lep_pdgid")[1])==121){
                                            if(!ana.tx.getBranchLazy<bool>("Common_HLT_DoubleEl")) return false;
                                          }
                                          if(abs(ana.tx.getBranchLazy<vector<int> >("Common_lep_pdgid")[0]*ana.tx.getBranchLazy<vector<int> >("Common_lep_pdgid")[1])==169){
                                            if(!ana.tx.getBranchLazy<bool>("Common_HLT_DoubleMu")) return false;
                                          }
                                          if(abs(ana.tx.getBranchLazy<vector<int> >("Common_lep_pdgid")[0]*ana.tx.getBranchLazy<vector<int> >("Common_lep_pdgid")[1])==143){
                                            if(!ana.tx.getBranchLazy<bool>("Common_HLT_MuEG")) return false;
                                          }
                                        }
                                        return true;
                                      }, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_Preselection",
                                      [&]()
                                      {
                                        bool isSFOSZ = false;
                                        bool isSFOS = false;
                                        //cout << ana.tx.getBranchLazy<vector<int>>("Common_ana.tx.getBranchLazy<vector<int> >("Common_lep_pdgid")")[0] << " " << ana.tx.getBranchLazy<vector<int>>("Common_ana.tx.getBranchLazy<vector<int> >("Common_lep_pdgid")")[1] << endl;
                                        //test for SFOSs
                                        if(ana.tx.getBranchLazy<vector<int> >("Common_lep_pdgid")[0]==(-ana.tx.getBranchLazy<vector<int> >("Common_lep_pdgid")[1])){
                                          isSFOS = true;
                                          //test if OS is a Z
                                          if( abs((ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]).M()-91.1876)<20.)
                                            isSFOSZ = true;
                                        }
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
                                        ana.tx.setBranch<int>  ("OS2jet_Nbjetsv1",              ana.tx.getBranchLazy<int>("Common_nb_loose"));
                                        ana.tx.setBranch<int>  ("OS2jet_Nbjetsmedv1",           ana.tx.getBranchLazy<int>("Common_nb_medium"));
                                        ana.tx.setBranch<int>  ("OS2jet_Nbjetsv2",              -999);
                                        ana.tx.setBranch<int>  ("OS2jet_NfatjetsMinusNjets",    -999);
                                        ana.tx.setBranch<float>("OS2jet_MET",                   ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt());
                                        ana.tx.setBranch<float>("OS2jet_MET_fatjet1_DPhi",      -999.);
                                        ana.tx.setBranch<float>("OS2jet_MET_ll_DPhi",           abs(RooUtil::Calc::DeltaPhi(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1],ana.tx.getBranchLazy<LorentzVector>("Common_met_p4"))));
                                        ana.tx.setBranch<float>("OS2jet_MET_ll_DPhi",           -999);
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
                                        //ana.tx.setBranch<float>("OS2jet_fatjet1_WpZtag",        -999.);
                                        //ana.tx.setBranch<float>("OS2jet_fatjet1_WtZtag",        -999.);
                                        //ana.tx.setBranch<float>("OS2jet_fatjet2_WpZtag",        -999.);
                                        //ana.tx.setBranch<float>("OS2jet_fatjet2_WtZtag",        -999.);
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_WtWtag",       -999.);
                                        //ana.tx.setBranch<float>("OS2jet_fatjet12_WtZtag",       -999.);
                                        //ana.tx.setBranch<float>("OS2jet_fatjet12_ZtWtag",       -999.);
                                        //ana.tx.setBranch<float>("OS2jet_fatjet12_ZtZtag",       -999.);
                                        ana.tx.setBranch<float>("OS2jet_fatjet12_WpWtag",       -999.);
                                        //ana.tx.setBranch<float>("OS2jet_fatjet12_WpZtag",       -999.);
                                        //ana.tx.setBranch<float>("OS2jet_fatjet12_ZpWtag",       -999.);
                                        //ana.tx.setBranch<float>("OS2jet_fatjet12_ZpZtag",       -999.);
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
                                        ana.tx.setBranch<float>("OS2jet_genMVVV",               -999.);
                                        ana.tx.setBranch<float>("OS2jet_genpTVVV",              -999.);
                                        ana.tx.setBranch<float>("OS2jet_Mfatjetsleptons",       -999.);
                                        ana.tx.setBranch<float>("OS2jet_MTfatjetsleptonsMET",   -999.);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet1_massSDcut",     false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet1_WtagMcut",      false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet1_WtagLcut",      false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet1_tau21cut",      false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet2_massSDcut",     false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet2_WtagMcut",      false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet2_WtagLcut",      false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet2_tau21cut",      false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet12_ANDmassSDcut", false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet12_ANDWtagMcut",  false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet12_ANDWtagLcut",  false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet12_ANDtau21cut",  false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet12_ORmassSDcut",  false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet12_ORWtagMcut",   false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet12_ORWtagLcut",   false);
                                        ana.tx.setBranch<bool >("OS2jet_fatjet12_ORtau21cut",   false);
                                        ana.tx.setBranch<int>  ("OS2jet_Nfatjets_vloose",       -999.);
                                        ana.tx.setBranch<int>  ("OS2jet_Nfatjets_loose",        -999.);
                                        ana.tx.setBranch<int>  ("OS2jet_Nfatjets_medium",       -999.);
                                        ana.tx.setBranch<float>("OS2jet_fatjetwgt_vloose",      -999.);
                                        ana.tx.setBranch<float>("OS2jet_fatjetwgt_loose",       -999.);
                                        ana.tx.setBranch<float>("OS2jet_fatjetwgt_medium",      -999.);

                                        if(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_gen_vvvdecay_p4s").size()>=6){
                                          LorentzVector genVVV = LorentzVector(0.,0.,0.,0.);
                                          for(unsigned int gi = 0; gi < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_gen_vvvdecay_p4s").size(); ++gi){
                                            genVVV +=  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_gen_vvvdecay_p4s")[gi];
                                          }
                                          ana.tx.setBranch<float>("OS2jet_genMVVV",  genVVV.M() );
                                          ana.tx.setBranch<float>("OS2jet_genpTVVV", genVVV.Pt());
                                        }
                                        //mass variables
                                        LorentzVector LVfjl = LorentzVector(0.,0.,0.,0.);
                                        for(unsigned int ifj = 0; ifj<ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size(); ++ifj){
                                          LVfjl += ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[ifj];
                                        }
                                        for(unsigned int il = 0; il<ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4").size(); ++il){
                                          LVfjl += ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[il];
                                        }
                                        ana.tx.setBranch<float>("OS2jet_Mfatjetsleptons", LVfjl.M());
                                        ana.tx.setBranch<float>("OS2jet_MTfatjetsleptonsMET",RooUtil::Calc::mT(LVfjl,ana.tx.getBranchLazy<LorentzVector>("Common_met_p4")));
                                        //now fill branches already here
                                        int nfat= ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size();
                                        float evtwgtfjvl = 1; int nfjvl = 0;
                                        float evtwgtfjl  = 1; int nfjl  = 0;
                                        float evtwgtfjm  = 1; int nfjm  = 0;
                                        for(int ifj = 0; ifj<nfat; ++ifj){
                                          if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[ifj]>=0) { ++nfjvl; evtwgtfjvl *= ana.tx.getBranchLazy<vector<float>>("Common_fatjet_SFVLoose")[ifj]; }
                                          if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[ifj]>=1) {  ++nfjl; evtwgtfjl  *= ana.tx.getBranchLazy<vector<float>>("Common_fatjet_SFLoose" )[ifj]; }
                                          if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[ifj]>=2) {  ++nfjm; evtwgtfjm  *= ana.tx.getBranchLazy<vector<float>>("Common_fatjet_SFMedium")[ifj]; }
                                        }
                                        ana.tx.setBranch<int>  ("OS2jet_Nfatjets_vloose",       nfjvl);
                                        ana.tx.setBranch<int>  ("OS2jet_Nfatjets_loose",        nfjl );
                                        ana.tx.setBranch<int>  ("OS2jet_Nfatjets_medium",       nfjm );
                                        ana.tx.setBranch<float>("OS2jet_fatjetwgt_vloose",      evtwgtfjvl);
                                        ana.tx.setBranch<float>("OS2jet_fatjetwgt_loose",       evtwgtfjl );
                                        ana.tx.setBranch<float>("OS2jet_fatjetwgt_medium",      evtwgtfjm );
                                        int nnonfat = 0; int nbnonfat = 0;
                                        //start with fat jets
                                        //int fatidx1 = -1; int fatidx2 = -1; - to be replaced XX
                                        //do normal jets
                                        int jetidx1 = -1; int jetidx2 = -1;
                                        for(unsigned int ti = 0; ti<ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBloose").size(); ++ti){
                                          if(ana.tx.getBranchLazy<vector<int>>("Common_jet_overlapfatjet")[ti]>=0) continue;
                                          ++nnonfat;
                                          if(ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBloose")[ti]) ++nbnonfat;
                                          if(jetidx1<0) { jetidx1 = ti; continue; }
                                          if(jetidx2<0) { jetidx2 = ti; continue; }
                                        }
                                        ana.tx.setBranch<int>  ("OS2jet_Nfatjets",              nfat);
                                        ana.tx.setBranch<int>  ("OS2jet_Njets",                 nnonfat);
                                        ana.tx.setBranch<int>  ("OS2jet_Nbjetsv2",              nbnonfat);
                                        ana.tx.setBranch<int>  ("OS2jet_NfatjetsMinusNjets",    nfat-nnonfat);
                                        if(     nfat>=2)     ana.tx.setBranch<int>("OS2jet_Jetcontent" ,2);
                                        else if(nfat==1)     ana.tx.setBranch<int>("OS2jet_Jetcontent" ,1);
                                        else if(nnonfat>=2)  ana.tx.setBranch<int>("OS2jet_Jetcontent" ,0);
                                        //do >=1fatjet
                                        if(nfat>=1){
                                          ana.tx.setBranch<float>("OS2jet_MET_fatjet1_DPhi",      abs(RooUtil::Calc::DeltaPhi(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0],ana.tx.getBranchLazy<LorentzVector>("Common_met_p4"))));
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_pt",            ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0].Pt());
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_mass",          ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0].M());
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_massSD",        ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_tau21",         ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau21")[0]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_tau32",         ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau32")[0]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_toptag",        ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_T")[0]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_Wtag",          ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[0]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_Ztag",          ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_Z")[0]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_Zbbtag",        ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_bb")[0]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet1_ll_DR",         RooUtil::Calc::DeltaR(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]));
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ll_DRmax",     RooUtil::Calc::DeltaR(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]));
                                          if(!nt.isData()){
                                            for(unsigned int ig = 0; ig<=ana.tx.getBranchLazy<vector<int>>("Common_gen_idx").size(); ++ig){
                                              if(abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[ig])!=23 && abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[ig])!=24)
                                                continue;
                                              if(RooUtil::Calc::DeltaR(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_gen_p4s")[ig])<0.4){
                                                ana.tx.setBranch<int>  ("OS2jet_fatjet1_genmatching",  ig);
                                                break;
                                              }
                                            }
                                          }
                                          ana.tx.setBranch<bool >("OS2jet_fatjet1_massSDcut",     (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0]>65.&&ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0]<105.));
                                          ana.tx.setBranch<bool >("OS2jet_fatjet1_WtagMcut",      ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[0]>0.725);
                                          ana.tx.setBranch<bool >("OS2jet_fatjet1_WtagLcut",      ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[0]>0.500);
                                          ana.tx.setBranch<bool >("OS2jet_fatjet1_tau21cut",      ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau21")[0]<0.45);
                                        }
                                        //do >=2 fatjet
                                        if(nfat>=2){
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_pt",            ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1].Pt());
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_mass",          ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1].M());
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_massSD",        ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_tau21",         ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau21")[1]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_tau32",         ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau32")[1]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_toptag",        ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_T")[1]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_Wtag",          ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_Ztag",          ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_Z")[1]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_Zbbtag",        ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_bb")[1]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet2_ll_DR",         RooUtil::Calc::DeltaR(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]));
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ll_DRmax",     std::max(RooUtil::Calc::DeltaR(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]),RooUtil::Calc::DeltaR(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1])));
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ptvectorsum",  (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1]).Pt());
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ptscalarsum",   ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0].Pt()+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1].Pt());
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_ptscalarprod",  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0].Pt()*ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1].Pt());
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_mass",         (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1]).M());
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_masssum",       ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0].M()+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1].M());
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_massproduct",   ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0].M()*ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1].M());
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_massSDsum",     ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0]+ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_massSDproduct", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0]*ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_DR",                RooUtil::Calc::DeltaR(  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1]));
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_DPhi",          abs(RooUtil::Calc::DeltaPhi(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1])));
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_DEta",          abs(RooUtil::Calc::DeltaEta(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1])));
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_WtWtag",        ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[0]*ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1]);
                                          ana.tx.setBranch<float>("OS2jet_fatjet12_WpWtag",        ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[0]+ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1]);
                                          if(!nt.isData()){
                                            for(unsigned int ig = 0; ig<=ana.tx.getBranchLazy<vector<int>>("Common_gen_idx").size(); ++ig){
                                              if(abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[ig])!=23 && abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[ig])!=24)
                                                continue;
                                              if(RooUtil::Calc::DeltaR(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_gen_p4s")[ig])<0.4){
                                                ana.tx.setBranch<int>  ("OS2jet_fatjet2_genmatching",  ig);
                                                break;
                                              }
                                            }
                                          }
                                          ana.tx.setBranch<bool >("OS2jet_fatjet2_massSDcut",     (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1]>65.&&ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1]<105.));
                                          ana.tx.setBranch<bool >("OS2jet_fatjet2_WtagMcut",      ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1]>0.725);
                                          ana.tx.setBranch<bool >("OS2jet_fatjet2_WtagLcut",      ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1]>0.500);
                                          ana.tx.setBranch<bool >("OS2jet_fatjet2_tau21cut",      ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau21")[1]<0.45);
                                          ana.tx.setBranch<bool >("OS2jet_fatjet12_ANDmassSDcut", ((ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0]>65.&&ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0]<105.)&&(ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1]>65.&&ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1]<105.)));
                                          ana.tx.setBranch<bool >("OS2jet_fatjet12_ANDWtagMcut",  ((ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1]>0.725)&&(ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1]>0.725)));
                                          ana.tx.setBranch<bool >("OS2jet_fatjet12_ANDWtagLcut",  ((ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1]>0.500)&&(ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1]>0.500)));
                                          ana.tx.setBranch<bool >("OS2jet_fatjet12_ANDtau21cut",  ((ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau21")[1]<0.45)&&(ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau21")[1]<0.45)));
                                          ana.tx.setBranch<bool >("OS2jet_fatjet12_ORmassSDcut",  ((ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0]>65.&&ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0]<105.)||(ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1]>65.&&ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1]<105.)));
                                          ana.tx.setBranch<bool >("OS2jet_fatjet12_ORWtagMcut",   ((ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1]>0.725)||(ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1]>0.725)));
                                          ana.tx.setBranch<bool >("OS2jet_fatjet12_ORWtagLcut",   ((ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1]>0.500)||(ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1]>0.500)));
                                          ana.tx.setBranch<bool >("OS2jet_fatjet12_ORtau21cut",   ((ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau21")[1]<0.45)||(ana.tx.getBranchLazy<vector<float>>("Common_fatjet_tau21")[1]<0.45)));
                                        }
                                        //do >=2 jets - do jets orthogonal to fatjets
                                        if(jetidx2>=0){  
                                          ana.tx.setBranch<int>  ("OS2jet_jet1_idx",              jetidx1);
                                          ana.tx.setBranch<int>  ("OS2jet_jet2_idx",              jetidx2);
                                          ana.tx.setBranch<float>("OS2jet_jet1_pt",               ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx1].Pt());
                                          ana.tx.setBranch<float>("OS2jet_jet2_pt",               ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx2].Pt());
                                          ana.tx.setBranch<float>("OS2jet_jet12_ptvectorsum",    (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx1]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx1]).Pt());
                                          ana.tx.setBranch<float>("OS2jet_jet12_ptscalarsum",     ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx1].Pt()+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx2].Pt());
                                          ana.tx.setBranch<float>("OS2jet_jet12_ptscalarprod",    ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx1].Pt()*ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx2].Pt());
                                          ana.tx.setBranch<float>("OS2jet_jet12_mass",           (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx1]+ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx2]).M());
                                          ana.tx.setBranch<float>("OS2jet_jet12_DR",                  RooUtil::Calc::DeltaR(  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx1],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx2]));
                                          ana.tx.setBranch<float>("OS2jet_jet12_DPhi",            abs(RooUtil::Calc::DeltaPhi(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx1],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx2])));
                                          ana.tx.setBranch<float>("OS2jet_jet12_DEta",            abs(RooUtil::Calc::DeltaEta(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx1],ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[jetidx2])));
                                        }


                                        return true;
                                      }, UNITY);// trigger SF would go in here instead of UNITY, in principle also btag weight
    // --------------------
    // ***      OF      ***
    // --------------------
    ana.cutflow.getCut("Cut_OS2jet_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OFPreselection",               [&]() { return ana.tx.getBranch<int>("OS2jet_SFcontent") ==0 && ana.tx.getBranch<int>("OS2jet_Nbjetsv1")==0;}, UNITY);
    // __________________
    // *** OS2jet_OF2jets
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2jets",                      [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==0 && ana.tx.getBranch<int>("OS2jet_Njets")>=2;}, UNITY);
    // ____________________
    // *** OS2jet_OF1fatjet
    ana.cutflow.getCut("Cut_OS2jet_OFPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet",                    [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==1;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_massSDcuts",         [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_massSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_massSDtagcuts",      [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_WtagLcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF1fatjet_massSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_massSDnsubcuts",     [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_tagcuts",            [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_WtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_tagnsubcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_nsubcuts",           [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_vlooseWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_vloose")==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_vloose");});
    ana.cutflow.getCut("Cut_OS2jet_OF1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_looseWP",            [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_loose") ==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_loose"); });
    ana.cutflow.getCut("Cut_OS2jet_OF1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF1fatjet_mediumWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_medium")==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_medium"); });
    // _____________________
    // *** OS2jet_OF2fatjets
    // note: did full chain only for tag12plus/tag1and2 as well as M12/M12SD
    ana.cutflow.getCut("Cut_OS2jet_OFPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets",                   [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==2;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ANDmassSDcuts",     [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDmassSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ANDmassSDtagLcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ANDmassSDtagMcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagMcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets_ANDmassSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ANDmassSDnsubcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ANDtagMcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagMcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ANDtagMnsubcuts",   [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ANDtagLcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ANDtagLnsubcuts",   [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ANDnsubcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ORmassSDcuts",      [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORmassSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ORmassSDtagLcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ORmassSDtagMcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagMcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets_ORmassSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ORmassSDnsubcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ORtagMcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagMcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ORtagMnsubcuts",    [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ORtagLcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ORtagLnsubcuts",    [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_ORnsubcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_vlooseWP",          [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_vloose")>=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_vloose");});
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_looseWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_loose") >=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_loose"); });
    ana.cutflow.getCut("Cut_OS2jet_OF2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_OF2fatjets_mediumWP",          [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_medium")>=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_medium"); });


    // --------------------
    // *** SF without Z ***
    // --------------------
    ana.cutflow.getCut("Cut_OS2jet_Preselection");
    // _____________________
    // *** OS2jet_SFnoZ2jets
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZPreselection",               [&]() { return ana.tx.getBranch<int>("OS2jet_SFcontent") ==1 && ana.tx.getBranch<int>("OS2jet_Nbjetsv1")==0;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2jets",                      [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==0 && ana.tx.getBranch<int>("OS2jet_Njets")>=3;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2jets_sel",                  [&]() { return ana.tx.getBranch<float>("OS2jet_lep12_DR")<2.1 && ana.tx.getBranch<float>("OS2jet_jet12_DR")<2.1;}, UNITY);
    // ____________________
    // *** OS2jet_SFnoZ1fatjet
    ana.cutflow.getCut("Cut_OS2jet_SFnoZPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet",                    [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==1;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_massSDcuts",         [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_massSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_massSDtagcuts",      [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_WtagLcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ1fatjet_massSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_massSDnsubcuts",     [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_tagcuts",            [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_WtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_tagnsubcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_nsubcuts",           [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_vlooseWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_vloose")==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_vloose");});
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_looseWP",            [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_loose") ==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_loose"); });
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ1fatjet_mediumWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_medium")==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_medium"); });
    // _____________________
    // *** OS2jet_SFnoZ2fatjets
    // note: did full chain only for tag12plus/tag1and2 as well as M12/M12SD
    ana.cutflow.getCut("Cut_OS2jet_SFnoZPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets",                   [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==2;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ANDmassSDcuts",     [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDmassSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ANDmassSDtagLcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ANDmassSDtagMcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagMcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets_ANDmassSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ANDmassSDnsubcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ANDtagMcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagMcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ANDtagMnsubcuts",   [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ANDtagLcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ANDtagLnsubcuts",   [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ANDnsubcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ORmassSDcuts",      [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORmassSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ORmassSDtagLcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ORmassSDtagMcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagMcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets_ORmassSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ORmassSDnsubcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ORtagMcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagMcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ORtagMnsubcuts",    [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ORtagLcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ORtagLnsubcuts",    [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_ORnsubcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_vlooseWP",          [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_vloose")>=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_vloose");});
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_looseWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_loose") >=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_loose"); });
    ana.cutflow.getCut("Cut_OS2jet_SFnoZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFnoZ2fatjets_mediumWP",          [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_medium")>=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_medium"); });
    
    // --------------------
    // ***   SF with Z  ***
    // --------------------
    ana.cutflow.getCut("Cut_OS2jet_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZPreselection",               [&]() { return ana.tx.getBranch<int>("OS2jet_SFcontent") ==2 && ana.tx.getBranch<int>("OS2jet_Nbjetsv1")==0;}, UNITY);
    // ___________________
    // *** OS2jet_SFZ2jets
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2jets",                      [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==0;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2jets_sel",                  [&]() { return ana.tx.getBranch<float>("OS2jet_lep12_DR")<2.1 && ana.tx.getBranch<float>("OS2jet_jet12_DR")<1.57;}, UNITY);
    // ____________________
    // *** OS2jet_SFZ1fatjet
    ana.cutflow.getCut("Cut_OS2jet_SFZPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet",                    [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==1;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_massSDcuts",         [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_massSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_massSDtagcuts",      [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_WtagLcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ1fatjet_massSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_massSDnsubcuts",     [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_tagcuts",            [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_WtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_tagnsubcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_nsubcuts",           [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_vlooseWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_vloose")==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_vloose");});
    ana.cutflow.getCut("Cut_OS2jet_SFZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_looseWP",            [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_loose") ==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_loose"); });
    ana.cutflow.getCut("Cut_OS2jet_SFZ1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ1fatjet_mediumWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_medium")==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_medium"); });
    
    // _____________________
    // *** OS2jet_SFZ2fatjets
    // note: did full chain only for tag12plus/tag1and2 as well as M12/M12SD
    ana.cutflow.getCut("Cut_OS2jet_SFZPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets",                   [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==2;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ANDmassSDcuts",     [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDmassSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ANDmassSDtagLcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ANDmassSDtagMcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagMcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets_ANDmassSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ANDmassSDnsubcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ANDtagMcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagMcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ANDtagMnsubcuts",   [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ANDtagLcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ANDtagLnsubcuts",   [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ANDnsubcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ORmassSDcuts",      [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORmassSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ORmassSDtagLcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ORmassSDtagMcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagMcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets_ORmassSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ORmassSDnsubcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ORtagMcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagMcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ORtagMnsubcuts",    [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ORtagLcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ORtagLnsubcuts",    [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_ORnsubcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_vlooseWP",          [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_vloose")>=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_vloose");});
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_looseWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_loose") >=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_loose"); });
    ana.cutflow.getCut("Cut_OS2jet_SFZ2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_SFZ2fatjets_mediumWP",          [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_medium")>=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_medium"); });
    
    //top CR
    ana.cutflow.getCut("Cut_OS2jet_Preselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCRPreselection",               [&]() { return ana.tx.getBranch<int>("OS2jet_Nbjetsmedv1")>=1;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2jets",                      [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==0;}, UNITY);
    // ____________________
    // *** OS2jet_topCR1fatjet
    ana.cutflow.getCut("Cut_OS2jet_topCRPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR1fatjet",                    [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==1;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR1fatjet_massSDcuts",         [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_massSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR1fatjet_massSDtagcuts",      [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_WtagLcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR1fatjet_massSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR1fatjet_massSDnsubcuts",     [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR1fatjet_tagcuts",            [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_WtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR1fatjet_tagnsubcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR1fatjet_nsubcuts",           [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR1fatjet_vlooseWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_vloose")==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_vloose");});
    ana.cutflow.getCut("Cut_OS2jet_topCR1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR1fatjet_looseWP",            [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_loose") ==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_loose"); });
    ana.cutflow.getCut("Cut_OS2jet_topCR1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR1fatjet_mediumWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_medium")==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_medium"); });
    // _____________________
    // *** OS2jet_topCR2fatjets
    // note: did full chain only for tag12plus/tag1and2 as well as M12/M12SD
    ana.cutflow.getCut("Cut_OS2jet_topCRPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets",                   [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==2;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ANDmassSDcuts",     [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDmassSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ANDmassSDtagLcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ANDmassSDtagMcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagMcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR2fatjets_ANDmassSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ANDmassSDnsubcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ANDtagMcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagMcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ANDtagMnsubcuts",   [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ANDtagLcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ANDtagLnsubcuts",   [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ANDnsubcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ORmassSDcuts",      [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORmassSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ORmassSDtagLcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ORmassSDtagMcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagMcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR2fatjets_ORmassSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ORmassSDnsubcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ORtagMcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagMcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ORtagMnsubcuts",    [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ORtagLcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ORtagLnsubcuts",    [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_ORnsubcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_topCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_vlooseWP",          [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_vloose")>=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_vloose");});
    ana.cutflow.getCut("Cut_OS2jet_topCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_looseWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_loose") >=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_loose"); });
    ana.cutflow.getCut("Cut_OS2jet_topCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_topCR2fatjets_mediumWP",          [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_medium")>=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_medium"); });

    //DY CR
    ana.cutflow.getCut("Cut_OS2jet_SFZPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCRPreselection",               [&]() { return ana.tx.getBranch<int>("OS2jet_Njets")==0;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2jets",                      [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==0;}, UNITY);
    // ____________________
    // *** OS2jet_DYCR1fatjet
    ana.cutflow.getCut("Cut_OS2jet_DYCRPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR1fatjet",                    [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==1;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR1fatjet_massSDcuts",         [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_massSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR1fatjet_massSDtagcuts",      [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_WtagLcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR1fatjet_massSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR1fatjet_massSDnsubcuts",     [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR1fatjet_tagcuts",            [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_WtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR1fatjet_tagnsubcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR1fatjet_nsubcuts",           [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet1_tau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR1fatjet_vlooseWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_vloose")==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_vloose");});
    ana.cutflow.getCut("Cut_OS2jet_DYCR1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR1fatjet_looseWP",            [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_loose") ==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_loose"); });
    ana.cutflow.getCut("Cut_OS2jet_DYCR1fatjet");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR1fatjet_mediumWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_medium")==1;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_medium"); });
    // _____________________
    // *** OS2jet_DYCR2fatjets
    // note: did full chain only for tag12plus/tag1and2 as well as M12/M12SD
    ana.cutflow.getCut("Cut_OS2jet_DYCRPreselection");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets",                   [&]() { return ana.tx.getBranch<int>("OS2jet_Jetcontent")==2;}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ANDmassSDcuts",     [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDmassSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ANDmassSDtagLcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ANDmassSDtagMcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagMcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR2fatjets_ANDmassSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ANDmassSDnsubcuts", [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ANDtagMcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDWtagMcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ANDtagMnsubcuts",   [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ANDtagLcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ANDtagLnsubcuts",   [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ANDnsubcuts",       [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ANDtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ORmassSDcuts",      [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORmassSDcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ORmassSDtagLcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagLcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ORmassSDtagMcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagMcut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR2fatjets_ORmassSDcuts");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ORmassSDnsubcuts",  [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ORtagMcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORWtagMcut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ORtagMnsubcuts",    [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ORtagLcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ORtagLnsubcuts",    [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_ORnsubcuts",        [&]() { return ana.tx.getBranch<bool>("OS2jet_fatjet12_ORtau21cut");}, UNITY);
    ana.cutflow.getCut("Cut_OS2jet_DYCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_vlooseWP",          [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_vloose")>=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_vloose");});
    ana.cutflow.getCut("Cut_OS2jet_DYCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_looseWP",           [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_loose") >=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_loose"); });
    ana.cutflow.getCut("Cut_OS2jet_DYCR2fatjets");
    ana.cutflow.addCutToLastActiveCut("Cut_OS2jet_DYCR2fatjets_mediumWP",          [&]() { return ana.tx.getBranch<int>("OS2jet_Nfatjets_medium")>=2;}, [&]() { return ana.tx.getBranch<float>("OS2jet_fatjetwgt_medium"); });

    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    ana.histograms.addHistogram("LeptonSF"     , 500, -10,    10, [&]() { return      ana.tx.getBranch<float>("Common_event_lepSF"             )   ; } );
    ana.histograms.addHistogram("FatjetSFvl"   , 500, -10,    10, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjetwgt_vloose"        )   ; } );
    ana.histograms.addHistogram("FatjetSFl"    , 500, -10,    10, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjetwgt_loose"         )   ; } );
    ana.histograms.addHistogram("FatjetSFm"    , 500, -10,    10, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjetwgt_medium"        )   ; } );
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
    ana.histograms.addHistogram("Fat1_tau21"   , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           )   ; } );
    ana.histograms.addHistogram("Fat1_tau32"   , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_tau32"           )   ; } );
    ana.histograms.addHistogram("Fat1_Wtag"    , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            )   ; } );
    ana.histograms.addHistogram("Fat1_Ztag"    , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_Ztag"            )   ; } );
    ana.histograms.addHistogram("Fat1_Zbbtag"  , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_Zbbtag"          )   ; } );
    ana.histograms.addHistogram("Fat1_toptag"  , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_toptag"          )   ; } );
    //ana.histograms.addHistogram("Fat1_WpZtag"  , 400,   0,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_WpZtag"          )   ; } );
    //ana.histograms.addHistogram("Fat1_WtZtag"  , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_WtZtag"          )   ; } );
    ana.histograms.addHistogram("Fat2_pt"      , 300, 200,  2000, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_pt"              )   ; } );
    ana.histograms.addHistogram("Fat2_ll_DR"   , 300,   0,     6, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_ll_DR"           )   ; } );
    ana.histograms.addHistogram("Fat2_mass"    , 300,   0,   300, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_mass"            )   ; } );
    ana.histograms.addHistogram("Fat2_massSD"  , 300,   0,   300, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_massSD"          )   ; } );
    ana.histograms.addHistogram("Fat2_tau21oW" , 400,   0,    10, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            )>0 ? ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )/ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            ) : -999.   ; } );
    ana.histograms.addHistogram("Fat2_tau21"   , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )   ; } );
    ana.histograms.addHistogram("Fat2_tau32"   , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_tau32"           )   ; } );
    ana.histograms.addHistogram("Fat2_Wtag"    , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            )   ; } );
    ana.histograms.addHistogram("Fat2_Ztag"    , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_Ztag"            )   ; } );
    ana.histograms.addHistogram("Fat2_Zbbtag"  , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_Zbbtag"          )   ; } );
    ana.histograms.addHistogram("Fat2_toptag"  , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_toptag"          )   ; } );
    //ana.histograms.addHistogram("Fat2_WpZtag"  , 400,   0,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_WpZtag"          )   ; } );
    //ana.histograms.addHistogram("Fat2_WtZtag"  , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet2_WtZtag"          )   ; } );
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
    ana.histograms.addHistogram("Fat12_t21sum" , 400,   0,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           )+ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )   ; } );
    ana.histograms.addHistogram("Fat12_t21prod", 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           )*ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )   ; } );
    ana.histograms.addHistogram("Fat12_WtWtag" , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_WtWtag"         )   ; } );
    //ana.histograms.addHistogram("Fat12_WtZtag" , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_WtZtag"         )   ; } );
    //ana.histograms.addHistogram("Fat12_ZtWtag" , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_ZtWtag"         )   ; } );
    //ana.histograms.addHistogram("Fat12_ZtZtag" , 400,   0,     1, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_ZtZtag"         )   ; } );
    ana.histograms.addHistogram("Fat12_WpWtag" , 400,   0,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_WpWtag"         )   ; } );
    //ana.histograms.addHistogram("Fat12_WpZtag" , 400,   0,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_WpZtag"         )   ; } );
    //ana.histograms.addHistogram("Fat12_ZpWtag" , 400,   0,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_ZpWtag"         )   ; } );
    //ana.histograms.addHistogram("Fat12_ZpZtag" , 400,   0,     2, [&]() { return      ana.tx.getBranch<float>("OS2jet_fatjet12_ZpZtag"         )   ; } );
    ana.histograms.addHistogram("Jet1_pt"      , 300,   0,   900, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet1_pt"                 )   ; } );
    ana.histograms.addHistogram("Jet2_pt"      , 300,   0,   900, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet2_pt"                 )   ; } );
    ana.histograms.addHistogram("Jet12_pt"     , 300,   0,  1800, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet12_ptvectorsum"       )   ; } );
    ana.histograms.addHistogram("Jet12_avept"  , 300,   0,   900, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet12_ptscalarsum"       )/2.; } );
    ana.histograms.addHistogram("Jet12_geopt"  , 300,   0,   900, [&]() { return sqrt(ana.tx.getBranch<float>("OS2jet_jet12_ptscalarprod"     ))   ; } );
    ana.histograms.addHistogram("Jet12_mass"   , 300,   0,  1800, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet12_mass"              )   ; } );
    ana.histograms.addHistogram("Jet12_DR"     , 300,   0,     6, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet12_DR"                )   ; } );
    ana.histograms.addHistogram("Jet12_DPhi"   , 320,   0,   3.2, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet12_DPhi"              )   ; } );
    ana.histograms.addHistogram("Jet12_DEta"   , 300,   0,     5, [&]() { return      ana.tx.getBranch<float>("OS2jet_jet12_DEta"              )   ; } );
    ana.histograms.addHistogram("MET"          , 300,   0,  1500, [&]() { return      ana.tx.getBranch<float>("OS2jet_MET"                     )   ; } );
    ana.histograms.addHistogram("Fat1_MET_DPhi", 320,   0,   3.2, [&]() { return      ana.tx.getBranch<float>("OS2jet_MET_fatjet1_DPhi"        )   ; } );
    ana.histograms.addHistogram("MET_ll_DPhi"  , 320,   0,   3.2, [&]() { return      ana.tx.getBranch<float>("OS2jet_MET_ll_DPhi"             )   ; } );
    ana.histograms.addHistogram("genVVV_pt"    , 300,   0,  1500, [&]() { return      ana.tx.getBranch<float>("OS2jet_genpTVVV"                )   ; } );
    ana.histograms.addHistogram("genVVV_M"     , 450,   0,  4500, [&]() { return      ana.tx.getBranch<float>("OS2jet_genMVVV"                 )   ; } );
    ana.histograms.addHistogram("EvtMassNoMET" , 450,   0,  4500, [&]() { return      ana.tx.getBranch<float>("OS2jet_Mfatjetsleptons"         )   ; } );
    ana.histograms.addHistogram("EvtMT"        , 450,   0,  4500, [&]() { return      ana.tx.getBranch<float>("OS2jet_MTfatjetsleptonsMET"     )   ; } );

    ana.histograms.addHistogram("Fat1_massSDgenmatch"  , 300,   0,   300, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_massSD"          ) : -999.   ; } );
    ana.histograms.addHistogram("Fat1_tau21oWgenmatch" , 400,   0,    10, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    (ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            )>0 ? ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           )/ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            ) : -999.) : -999.   ; } );
    ana.histograms.addHistogram("Fat1_tau21genmatch"   , 400,   0,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           ) : -999.   ; } );
    ana.histograms.addHistogram("Fat1_Wtaggenmatch"    , 400,   0,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            ) : -999.   ; } );
    ana.histograms.addHistogram("Fat2_massSDgenmatch"  , 300,   0,   300, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_massSD"          ) : -999.   ; } );
    ana.histograms.addHistogram("Fat2_tau21oWgenmatch" , 400,   0,    10, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    (ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            )>0 ? ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )/ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            ) : -999.) : -999.   ; } );
    ana.histograms.addHistogram("Fat2_tau21genmatch"   , 400,   0,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           ) : -999.   ; } );
    ana.histograms.addHistogram("Fat2_Wtaggenmatch"    , 400,   0,     1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            ) : -999.   ; } );

    ana.histograms.add2DHistogram("Fat1_massSDgenmatch"  , 110,  -10,   210, "Fat1_tau21genmatch"  , 120, -0.1, 1.1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_massSD"        ) : -999.   ; }, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           ) : -999.   ; } );
    ana.histograms.add2DHistogram("Fat1_massSDgenmatch"  , 110,  -10,   210, "Fat1_Wtaggenmatch"   , 120, -0.1, 1.1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_massSD"        ) : -999.   ; }, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            ) : -999.   ; } );
    ana.histograms.add2DHistogram("Fat1_Wtaggenmatch"    , 120, -0.1,   1.1, "Fat1_tau21genmatch"  , 120, -0.1, 1.1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"          ) : -999.   ; }, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet1_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           ) : -999.   ; } );
    ana.histograms.add2DHistogram("Fat1_massSD"  , 110,  -10,   210, "Fat1_tau21"  , 120, -0.1, 1.1, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet1_massSD"        )   ; }, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           )   ; } );
    ana.histograms.add2DHistogram("Fat1_massSD"  , 110,  -10,   210, "Fat1_Wtag"   , 120, -0.1, 1.1, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet1_massSD"        )   ; }, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"            )   ; } );
    ana.histograms.add2DHistogram("Fat1_Wtag"    , 120, -0.1,   1.1, "Fat1_tau21"  , 120, -0.1, 1.1, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet1_Wtag"          )   ; }, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet1_tau21"           )   ; } );
    ana.histograms.add2DHistogram("Fat2_massSDgenmatch"  , 110,  -10,   210, "Fat2_tau21genmatch"  , 120, -0.1, 1.1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_massSD"        ) : -999.   ; }, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           ) : -999.   ; } );
    ana.histograms.add2DHistogram("Fat2_massSDgenmatch"  , 110,  -10,   210, "Fat2_Wtaggenmatch"   , 120, -0.1, 1.1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_massSD"        ) : -999.   ; }, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            ) : -999.   ; } );
    ana.histograms.add2DHistogram("Fat2_Wtaggenmatch"    , 120, -0.1,   1.1, "Fat2_tau21genmatch"  , 120, -0.1, 1.1, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"          ) : -999.   ; }, [&]() { return  ana.tx.getBranch<int>("OS2jet_fatjet2_genmatching")>=0 ?    ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           ) : -999.   ; } );
    ana.histograms.add2DHistogram("Fat2_massSD"  , 110,  -10,  210, "Fat2_tau21"  , 120, -0.1,  1.1, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet2_massSD"        )   ; }, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )   ; } );
    ana.histograms.add2DHistogram("Fat2_massSD"  , 110,  -10,  210, "Fat2_Wtag"   , 120, -0.1,  1.1, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet2_massSD"        )   ; }, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"            )   ; } );
    ana.histograms.add2DHistogram("Fat2_Wtag"    , 120, -0.1,  1.1, "Fat2_tau21"  , 120, -0.1,  1.1, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet2_Wtag"          )   ; }, [&]() { return  ana.tx.getBranch<float>("OS2jet_fatjet2_tau21"           )   ; } );


    RooUtil::Histograms hists_OS2jet;

    // Now book cutflow histogram (could be commented out if user does not want.)
    // N.B. Cutflow histogramming can be CPU consuming.
    ana.cutflow.bookCutflows();

    // Book histograms to cuts that user wants for this category.
    ana.cutflow.bookHistogramsForCutAndBelow(ana.histograms, "Cut_OS2jet_Preselection");
}
