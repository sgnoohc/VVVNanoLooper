#include "Begin_allHad.h"

void Begin_allHad()
{
    //region 1 for 1Lep CR
    if(ana.region == 1){
        if(ana.run_VVVTree)
            Begin_1L_VVVTree();
        else   
            Begin_1L_NanoAOD();
    }
    //signal selections
    else{
        if(ana.run_VVVTree)
            Begin_allHad_VVVTree();
        else
            Begin_allHad_NanoAOD();
    }
}

void Begin_allHad_NanoAOD()
{ 

    //define skimming selections -- require 0 leptons and trigger and HT pass
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("allHad", [&]() {

        if( ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size() > 0) return false; 
        if( ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size() < 2) return false;
        int nfj = 0;
        for(unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size(); i++){
            if( is_baseline_fatjet(i, true, false )) nfj++;
        }
        if(nfj < 2) return false;

        return true;
        }, [&]() { return  1;} );

    ana.cutflow.addCutToLastActiveCut("allHad_trigger", [&]() {

        if(   (ana.tx.getBranchLazy<bool>("Common_HLT_PFHT1050") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet500") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet360_TrimMass30") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet380_TrimMass30") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet400_TrimMass30") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet420_TrimMass30") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT750_TrimMass50") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT800_TrimMass50") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT850_TrimMass50") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT900_TrimMass50")  
        )) return true;

        return false;
    }, [&]() { return 1; } );

    ana.cutflow.addCutToLastActiveCut("allHad_HT", [&]() {

        float HT = 0;
        unsigned int nselect = 0;
        for( unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4").size(); i++){
            if ( is_baseline_jet(i) ){
                HT+= ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[i].Pt();
            }
        }
        
        for( unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size(); i++){
            if( is_baseline_fatjet(i, true, false) ){
                HT+= ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i].Pt();
                nselect ++;
            }
        }

        if( nselect != ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() ) return false;
        if(HT > 1100) return true;
        else return false;

    }, [&]() { return 1; } );

    
    ana.cutflow.bookCutflows(); 
    
}

void Begin_1L_NanoAOD()
{
        //for 1L skimming -- 1 lepton and 1 fatjet
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("oneLep", [&]() {

        if( ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size() != 1) return false; 
        if( ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size() < 1) return false;
        int nfj = 0;
        for(unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size(); i++){
            if( is_baseline_fatjet(i, false, false )) nfj++;
        }
        if(nfj < 1) return false;

        return true;
        }, [&]() { return  1;} );
    
    ana.cutflow.addCutToLastActiveCut("oneLep_trigger", [&]() {

        if( abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 11 &&  ana.tx.getBranchLazy<bool>("Common_HLT_Ele32_WPTight") ) return true;
        if( abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 13 &&  ana.tx.getBranchLazy<bool>("Common_HLT_IsoMu24") ) return true;

        return false;
        }, [&]() { return  1;} );

    ana.cutflow.addCutToLastActiveCut("oneLep_HT", [&]() {

        //Not going to include HT for now, since I want lower pT leptons, and that would bias this in a weird way
        // float HT = 0;
        // unsigned int nselect = 0;
        // for( unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4").size(); i++){
        //     if ( is_baseline_jet(i) ){
        //         HT+= ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[i].Pt();
        //     }
        // }
        
        // for( unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size(); i++){
        //     if( is_baseline_fatjet(i, false, false) ){
        //         HT+= ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i].Pt();
        //         nselect ++;
        //     }
        // }

        // HT+= ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt();

        //just make sure that all the fatjets are good ones and move on
        unsigned int nselect = 0;
        for( unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size(); i++){
            if( is_baseline_fatjet(i, false, false) ){
                nselect ++;
            }
        }

        if( nselect != ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() ) return false;

        return true;
        }, [&]() { return  1;} );
        
        ana.cutflow.bookCutflows();
}



void Begin_allHad_VVVTree()
{
   // float wgt = get_weight();
    float wgt = 1.0;


    //vector branches
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau1");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau2");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau3");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau21");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau32");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_msoftdrop");
    ana.tx.createBranch<vector<int>>    ("allHad_FatJet_WP");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_pt");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_M");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_eta");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_phi");
    ana.tx.createBranch<vector<LorentzVector>>  ("allHad_FatJet_p4");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_ID");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Zbbtag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Ztag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Ttag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Wtag");
    ana.tx.createBranch<float>  ("allHad_FatJet_SF");
    
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_pt");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_eta");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_phi");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_M");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_ID");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_puid");
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvvdecay_pdgid"); // for now these need to be floats bc addVecHistogram doesn't take ints
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvvdecay_pt"); 
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvv_pt"); 
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvv_eta"); 
    ana.tx.createBranch<vector<float>>  ("allHad_gen_pdgId");
    
    
    // Single var branches
    ana.tx.createBranch<float>  ("allHad_mindPhi_MetFJ");
    ana.tx.createBranch<float>  ("allHad_genHT");
    ana.tx.createBranch<float>  ("allHad_mVVV");
    ana.tx.createBranch<float>  ("allHad_HT");
    ana.tx.createBranch<float>  ("allHad_ST");
    ana.tx.createBranch<float>  ("allHad_mVVV_reco");
    ana.tx.createBranch<float>  ("allHad_ptVVV_reco");
    ana.tx.createBranch<float>  ("allHad_mVVV_reco_nomet");
    ana.tx.createBranch<float>  ("allHad_ptVVV_reco_nomet");
    
    ana.tx.createBranch<float>  ("allHad_fj_mVVV");
    ana.tx.createBranch<float>  ("allHad_fj_HT");
    ana.tx.createBranch<float>  ("allHad_fj_ST");
    ana.tx.createBranch<float>  ("allHad_fj_mVVV_reco");
    ana.tx.createBranch<float>  ("allHad_fj_ptVVV_reco");
    ana.tx.createBranch<float>  ("allHad_fj_mVVV_reco_nomet");
    ana.tx.createBranch<float>  ("allHad_fj_ptVVV_reco_nomet");
    ana.tx.createBranch<float>  ("allHad_fj_mVVV_reco_nomet_SD");
    ana.tx.createBranch<float>  ("allHad_fj_ptVVV_reco_nomet_SD");
    
    ana.tx.createBranch<float>  ("allHad_fj12_dPhi");
    ana.tx.createBranch<float>  ("allHad_fj12_dEta");
    ana.tx.createBranch<float>  ("allHad_fj12_dR");
    ana.tx.createBranch<float>  ("allHad_fj23_dPhi");
    ana.tx.createBranch<float>  ("allHad_fj23_dEta");
    ana.tx.createBranch<float>  ("allHad_fj23_dR");
    ana.tx.createBranch<float>  ("allHad_fj31_dPhi");
    ana.tx.createBranch<float>  ("allHad_fj31_dEta");
    ana.tx.createBranch<float>  ("allHad_fj31_dR");
    
    ana.tx.createBranch<float>  ("allHad_v12_dPhi");
    ana.tx.createBranch<float>  ("allHad_v12_dEta");
    ana.tx.createBranch<float>  ("allHad_v12_dR");
    ana.tx.createBranch<float>  ("allHad_v23_dPhi");
    ana.tx.createBranch<float>  ("allHad_v23_dEta");
    ana.tx.createBranch<float>  ("allHad_v23_dR");
    ana.tx.createBranch<float>  ("allHad_v31_dPhi");
    ana.tx.createBranch<float>  ("allHad_v31_dEta");
    ana.tx.createBranch<float>  ("allHad_v31_dR");
    
    ana.tx.createBranch<float>  ("allHad_j12_mass");
    ana.tx.createBranch<float>  ("allHad_j12_dPhi");
    ana.tx.createBranch<float>  ("allHad_j12_dEta");
    ana.tx.createBranch<float>  ("allHad_j12_dR");
    ana.tx.createBranch<float>  ("allHad_j23_mass");
    ana.tx.createBranch<float>  ("allHad_j23_dPhi");
    ana.tx.createBranch<float>  ("allHad_j23_dEta");
    ana.tx.createBranch<float>  ("allHad_j23_dR");
    ana.tx.createBranch<float>  ("allHad_j31_mass");
    ana.tx.createBranch<float>  ("allHad_j31_dPhi");
    ana.tx.createBranch<float>  ("allHad_j31_dEta");
    ana.tx.createBranch<float>  ("allHad_j31_dR");
    
    
    ana.tx.createBranch<vector<float>>  ("allHad_genV_status");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_nMatchedQuarks");
    
    
    
    ana.tx.createBranch<int>  ("allHad_nGenLeps");
    ana.tx.createBranch<int>  ("allHad_nGenQuarks");
    ana.tx.createBranch<int>  ("allHad_nGenV");
    ana.tx.createBranch<int>  ("allHad_nb_loose");
    ana.tx.createBranch<int>  ("allHad_nb_medium");
    ana.tx.createBranch<int>  ("allHad_nb_tight");
    ana.tx.createBranch<int>  ("allHad_NFatJet_loose");
    ana.tx.createBranch<int>  ("allHad_NFatJet_medium");
    ana.tx.createBranch<int>  ("allHad_NFatJet_tight");
    
    //////////////////////////////////////////
    // PRESELECTION
    //////////////////////////////////////////

    //at this point we've already skimmed
    ana.cutflow.getCut("CommonCut");

    const int eft_reweighting_idx = ana.eft_reweighting_idx;
    std::cout << "eft index " << eft_reweighting_idx;
    ana.cutflow.addCutToLastActiveCut("allHad_EFT", [&]() {
        return true;
        }, [&, eft_reweighting_idx]() { return  eft_reweighting_idx < 0 ? 1.0 : ana.tx.getBranchLazy<float>("Common_genWeight") * ana.tx.getBranchLazy<vector<float>>("Common_LHEReweightingWeight")[eft_reweighting_idx]; } );
    

    //This just adds in 1st fatjet pt > 500 signal cut
    ana.cutflow.addCutToLastActiveCut("allHad_fixedHT", [&]() {
        
        float HT = 0;
        unsigned int nselect = 0;

        if( ! (ana.tx.getBranchLazy<bool>("Common_HLT_PFHT1050") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet500") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet360_TrimMass30") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet380_TrimMass30") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet400_TrimMass30") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet420_TrimMass30") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT750_TrimMass50") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT800_TrimMass50") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT850_TrimMass50") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT900_TrimMass50")  
        )) return false;

        for( unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4").size(); i++){
            if(is_baseline_jet(i)){
                HT+= ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[i].Pt();
            }
        }

        for( unsigned int ij =0; ij < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); ij++  ){
            if(is_baseline_fatjet(ij, true, false)){
                HT += ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[ij].Pt();
                nselect ++;
            }
        }

        //want only events where the fatjets are all good
        if( nselect != ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() ) return false;
        if( HT < 1100) return false;
        return true;
        }, [&, wgt]() { return wgt; } );



    //////////////////////////////////////////
    // 1 MEDIUM 1 TIGHT
    ////////////////////////////////////////// 

    //build up to 1med1tight
    ana.cutflow.getCut("allHad_fixedHT");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_1med1tight_noB", [&]() {
        if (ana.tx.getBranchLazy<int>("allHad_nb_medium") > 0) return false;
        return true;
        }, [&]() { return 1; } );
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_1med1tight_2j", [&]() {
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() != 2 ) return false; 
        return true;
        }, [&]() { return 1; } );
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_1med1tight_2med", [&]() {
        if( ! (is_baseline_fatjet(0, true, true) && is_baseline_fatjet(1, true, true)) ) return false;

        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[0] < 2 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[1] < 2 ) return false;
        
        return true;
        }, [&]() { return 1; } );
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_1med1tight", [&]() {
        if( (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[0] == 2 && ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[1] == 3)
          ||(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[0] == 3 && ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[1] == 2)
        ) return true;
        return false;
        }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_2fj_1med1tight");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_1med1tight_SRBin_1", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") > 1000 && ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") <= 1500) return true;
        return false;
    }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_2fj_1med1tight");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_1med1tight_SRBin_2", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") > 1500 && ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") <= 3000) return true;
        return false;
    }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_2fj_1med1tight");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_1med1tight_SRBin_3", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") > 3000 ) return true;
        return false;
    }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_2fj_1med1tight");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_1med1tight_ptVV", [&]() {
        if (ana.tx.getBranchLazy<float>("allHad_fj_ptVVV_reco_nomet_SD") < 200) return false;
        return true;
        }, [&]() { return 1; } );
    



    //////////////////////////////////////////
    // MSD SIDEBAND
    //////////////////////////////////////////

    //build up to mSD cut to understand data/MC disagreement
    ana.cutflow.getCut("allHad_fixedHT");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_mSD_sideband_noB", [&]() {
        if (ana.tx.getBranchLazy<int>("allHad_nb_medium") > 0) return false;
        return true;
        }, [&]() { return 1; } );
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_mSD_sideband_2j", [&]() {
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() != 2 ) return false; 
        return true;
        }, [&]() { return 1; } );
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_mSD_sideband_2tight", [&]() {
        if( ! (is_baseline_fatjet(0, true, false) && is_baseline_fatjet(1, true, false)) ) return false;

        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[0] != 3 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[1] != 3 ) return false;
        
        return true;
        }, [&]() { return 1; } );
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_mSD_sideband", [&]() {
        if(  (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] < 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] > 40.)
            ||  (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] < 150. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] > 105.))
            
            {
                if( (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] < 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] > 40.)
                ||  (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] < 150. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] > 105.))
                    return true;
            }

        return false;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_2fj_mSD_sideband");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_mSD_sideband_SRBin_1", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") > 1000 && ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") <= 1500) return true;
        return false;
    }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_2fj_mSD_sideband");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_mSD_sideband_SRBin_2", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") > 1500 && ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") <= 3000) return true;
        return false;
    }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_2fj_mSD_sideband");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_mSD_sideband_SRBin_3", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") > 3000 ) return true;
        return false;
    }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_2fj_mSD_sideband");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_mSD_sideband_ptVV", [&]() {
        if (ana.tx.getBranchLazy<float>("allHad_fj_ptVVV_reco_nomet_SD") < 200) return false;
        return true;
        }, [&]() { return 1; } );


    

    //////////////////////////////////////////
    // 2/3 TIGHT FATJETS
    //////////////////////////////////////////


    ana.cutflow.getCut("allHad_fixedHT");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_tight_2j", [&]() {
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() !=2 ) return false;
        return true;
    }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_2fj_tight_2j");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_tight_jetID", [&]() {
        if( ! (is_baseline_fatjet(0, true, true) && is_baseline_fatjet(1, true, true)) ) return false;
        return true;
    }, [&]() { return 1; } );
  
    ana.cutflow.getCut("allHad_2fj_tight_jetID");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_tight_1sttight", [&]() {
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[0] != 3 ) return false;
        return true;
    }, [&]() { return 1; } );
    ana.cutflow.getCut("allHad_2fj_tight_1sttight");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_tight", [&]() {
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[1] != 3 ) return false;
        return true;
    }, [&]() { return 1; } );


    /*
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_tight", [&]() {

        //if (ana.tx.getBranchLazy<float>("allHad_fj_ptVVV_reco_nomet_SD") < 200 ) return false;

        //I want 2 fatjets, where both of them are tight
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() !=2 ) return false;
        //baseline fatjets passing first pt and mSD cuts
        if( ! (is_baseline_fatjet(0, true, true) && is_baseline_fatjet(1, true, true)) ) return false;
        
        //2 tight fatjets
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[0] != 3 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[1] != 3 ) return false;

        return true;
        }, [&]() { return 1; } );*/


    ana.cutflow.getCut("allHad_fixedHT");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_tight", [&]() {
        
        //I want 3 fatjets, where all of them are tight
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() !=3 ) return false;
        //baseline fatjets passing first pt and mSD cuts
        if( ! (is_baseline_fatjet(0, true, true) && is_baseline_fatjet(1, true, true) && is_baseline_fatjet(2, true, true)) ) return false;
        
        //3 tight fatjets
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[0] != 3 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[1] != 3 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[2] != 3 ) return false;

        return true;
        }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_fixedHT");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_ABCD", [&]() {

        //I want 2 fatjets, where both of them are tight
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() !=2 ) return false;
        
        // no b-jets
        if (ana.tx.getBranchLazy<int>("allHad_nb_medium") > 0 ) return false;
        //baseline fatjets passing first pt and mSD cuts
        if( ! (is_baseline_fatjet(0, true, false) && is_baseline_fatjet(1, true, false)) ) return false;
        

        return true;
        }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_2fj_ABCD");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_ABCD_A", [&]() {
        //signal region -- 2 tight, signal mSD
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[0] != 3 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[1] != 3 ) return false;

        if(  (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] <= 105.)
          && (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] <= 105.))
          return true;

        return false;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_2fj_ABCD");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_ABCD_B", [&]() {
        //1st jet medium
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[0] != 2 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[1] != 3 ) return false;

        if(  (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] <= 105.)
          && (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] <= 105.))
          return true;

        return false;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_2fj_ABCD");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_ABCD_C", [&]() {
        //2nd jet low mSD
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[0] != 3 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[1] != 3 ) return false;

        if(  (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] <= 105.)
          && (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] > 40. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] < 65.))
          return true;

        return false;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_2fj_ABCD");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_ABCD_D", [&]() {
        //2nd jet low mSD & 1st jet medium
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[0] != 2 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[1] != 3 ) return false;

        if(  (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] <= 105.)
          && (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] > 40. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] < 65.))
          return true;

        return false;
        }, [&]() { return 1; } );
    


        


    
    //////////////////////////////////////////
    // B-TAG CR
    //////////////////////////////////////////   
    // ana.cutflow.getCut("allHad_2fj_tight");
    // ana.cutflow.addCutToLastActiveCut("allHad_CRb_2fj", [&]() {
    //     if (ana.tx.getBranchLazy<int>("allHad_nb_medium") < 1 ) return false;
    //     return true;
    //     }, [&]() { return 1; } );

    //////////////////////////////////////////
    // SIGNAL REGION
    //////////////////////////////////////////
    ana.cutflow.getCut("allHad_2fj_tight");
    ana.cutflow.addCutToLastActiveCut("allHad_ORTrigger_2fj", [&]() {
        if (ana.tx.getBranchLazy<int>("allHad_nb_medium") > 0) return false;
        return true;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_ORTrigger_2fj");
    ana.cutflow.addCutToLastActiveCut("allHad_ORTrigger_2fj_SRBin_1", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") > 1000 && ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") <= 1500) return true;
        return false;
    }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_ORTrigger_2fj");
    ana.cutflow.addCutToLastActiveCut("allHad_ORTrigger_2fj_SRBin_2", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") > 1500 && ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") <= 3000) return true;
        return false;
    }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_ORTrigger_2fj");
    ana.cutflow.addCutToLastActiveCut("allHad_ORTrigger_2fj_SRBin_3", [&]() {
        if(ana.tx.getBranchLazy<float>("allHad_fj_mVVV_reco_nomet_SD") > 3000 ) return true;
        return false;
    }, [&]() { return 1; } );
    
    //////////////////////////////////////////
    // 3 Fatjets
    //////////////////////////////////////////
    
    ana.cutflow.getCut("allHad_3fj_tight");
    ana.cutflow.addCutToLastActiveCut("allHad_ORTrigger_3fj", [&]() {
        if (ana.tx.getBranchLazy<int>("allHad_nb_medium") > 0) return false;
        return true;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_3fj_tight");
    ana.cutflow.addCutToLastActiveCut("allHad_CRb_3fj", [&]() {
        if (ana.tx.getBranchLazy<int>("allHad_nb_medium") < 1 ) return false;
        return true;
        }, [&]() { return 1; } );
   
   
    
    vector<float> SR_bins{0,1000,1500, 3000, 6000};

    RooUtil::Histograms hists_allHad;

    //single value histograms
    hists_allHad.addHistogram("NJets"            ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt").size()    ; } );
    hists_allHad.addHistogram("NLeps"            ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size()   ; } );
    hists_allHad.addHistogram("NGenFatJets"       ,  10,   0,   10, [&]() { return      ana.tx.getBranchLazy<vector<LorentzVector>>("Common_genFatJet_p4").size()   ; } );
    hists_allHad.addHistogram("NFatJets"         ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_pt").size() ; } );
    hists_allHad.addHistogram("NW"               ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_n_W") ; } );
    //hists_allHad.addHistogram("gen_vvvdecay_n"               ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_idx").size() ; } );
    hists_allHad.addHistogram("n_b_loose"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_nb_loose") ; } );
    hists_allHad.addHistogram("n_b_medium"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_nb_medium") ; } );
    hists_allHad.addHistogram("n_b_tight"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_nb_tight") ; } );

    hists_allHad.addHistogram("nFatJet_loose"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_NFatJet_loose") ; } );
    hists_allHad.addHistogram("nFatJet_medium"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_NFatJet_medium") ; } );
    hists_allHad.addHistogram("nFatJet_tight"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_NFatJet_tight") ; } );  

    hists_allHad.addHistogram("MET"              ,  40,   0,    800, [&]() { return    ana.tx.getBranch<LorentzVector>  ("Common_met_p4").Pt(); } );

    hists_allHad.addHistogram("MET_phi"              ,  40,   -4,    4, [&]() { return    ana.tx.getBranch<LorentzVector>  ("Common_met_p4").Phi(); } );
    hists_allHad.addHistogram("METFJ_dPhi_min"       ,  40,   0,    4, [&]() { return    ana.tx.getBranch<float>  ("allHad_mindPhi_MetFJ"); } );
    ///hists_allHad.addHistogram("mVVV"               ,  60,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_mVVV"); } );
    hists_allHad.addHistogram("genHT"            ,  40,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_genHT"); } );
    hists_allHad.addHistogram("HT"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.addHistogram("ST"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_ST"); } );
    hists_allHad.addHistogram("mVVV_reco"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_mVVV_reco"); } );
    hists_allHad.addHistogram("ptVVV_reco"               ,  60,   0,    800, [&]() { return    ana.tx.getBranch<float>  ("allHad_ptVVV_reco"); } );
    hists_allHad.addHistogram("mVVV_reco_nomet"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_mVVV_reco_nomet"); } );
    hists_allHad.addHistogram("ptVVV_reco_nomet"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_ptVVV_reco_nomet"); } );
    
    hists_allHad.addHistogram("HT_fj"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_HT"); } );
    hists_allHad.addHistogram("ST_fj"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ST"); } );
    hists_allHad.addHistogram("mVVV_reco_fj"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco"); } );
    hists_allHad.addHistogram("ptVVV_reco_fj"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco"); } );
    hists_allHad.addHistogram("mVVV_reco_nomet_fj"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco_nomet"); } );
    hists_allHad.addHistogram("ptVVV_reco_nomet_fj"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco_nomet"); } );
    hists_allHad.addHistogram("mVVV_reco_nomet_fj_SD"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco_nomet_SD"); } );
    hists_allHad.addHistogram("ptVVV_reco_nomet_fj_SD"               ,  60,   0,    800, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco_nomet_SD"); } );
    
    hists_allHad.addHistogram("mVVV_SRbins"                        , SR_bins, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco_nomet_SD"); } );

    //hists_allHad.addHistogram("gen_vvv_pt0"       ,  20,   0,    2000,  [&]() { return (ana.tx.getBranch<vector<float>>("allHad_gen_vvv_pt").size() > 0) ?     ana.tx.getBranch<vector<float>>  ("allHad_gen_vvv_pt")[0] : -999; } );
    //hists_allHad.addHistogram("gen_vvv_eta0"       ,  20,  0,    3,  [&]() { return   (ana.tx.getBranch<vector<float>>("allHad_gen_vvv_eta").size() > 0) ?   ana.tx.getBranch<vector<float>>  ("allHad_gen_vvv_eta")[0] : -999; } );
    /*
    hists_allHad.add2DHistogram("genHT", 60,   0,    3000, "HT", 40,   0,    3000, [&]() { return ana.tx.getBranch<float>  ("allHad_genHT");}, [&]() { return ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.add2DHistogram("Njets", 6,   0,    6, "NFatjets", 6,   0,    6, [&]() { return ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt").size();}, [&]() { return ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_pt").size(); } );

    // compare to MET 
    //hists_allHad.add2DHistogram("mVVV", 60,   0,    3000,      "MET", 40,   0,    2000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV");}, [&]() { return ana.tx.getBranch<float>  ("allHad_MET"); } );
    //hists_allHad.add2DHistogram("HT", 60,   0,    5000,        "MET", 40,   0,    2000, [&]() { return ana.tx.getBranch<float>  ("allHad_HT");}, [&]() { return ana.tx.getBranch<float>  ("allHad_MET"); } );
    //hists_allHad.add2DHistogram("mVVV_reco", 60,   0,    5000, "MET", 40,   0,    2000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_MET"); } );
    hists_allHad.add2DHistogram("mVVV", 60,   0,    5000,      "ST", 60,   0,    5000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV");}, [&]() { return ana.tx.getBranch<float>  ("allHad_ST"); } );
    hists_allHad.add2DHistogram("mVVV_reco", 60,   0,    5000, "ST", 60,   0,    5000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_ST"); } );
    
    //event vars with all jets
    hists_allHad.add2DHistogram("mVVV", 60,   0,    5000,       "HT", 60,   0,    5000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV");}, [&]() { return ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.add2DHistogram("mVVV_reco", 60,   0,    5000,  "HT", 60,   0,    5000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.add2DHistogram("ptVVV_reco", 60,   0,    5000, "HT", 60,   0,    5000, [&]() { return ana.tx.getBranch<float>  ("allHad_ptVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.add2DHistogram("mVVV", 60,   0,    5000,       "mVVV_reco", 60,   0,    5000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV");}, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco"); } );
    hists_allHad.add2DHistogram("mVVV_reco", 60,   0,    5000, "ptVVV_reco", 60,   0,    5000, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_ptVVV_reco"); } );
    
    //event vars with fatjets


    //angular stuff
    hists_allHad.add2DHistogram("FatJet12_dPhi", 60,   0,    4, "FatJet12_dEta", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dEta"); } );
    hists_allHad.add2DHistogram("FatJet23_dPhi", 60,   0,    4, "FatJet23_dEta", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_fj23_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj23_dEta"); } );
    hists_allHad.add2DHistogram("FatJet31_dPhi", 60,   0,    4, "FatJet31_dEta", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_fj31_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj31_dEta"); } );
    hists_allHad.add2DHistogram("FatJet12_dR", 60,   0,    5, "FatJet23_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dR");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj23_dR"); } );
    hists_allHad.add2DHistogram("FatJet12_dR", 60,   0,    5, "FatJet31_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dR");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj31_dR"); } );
    hists_allHad.add2DHistogram("FatJet31_dR", 60,   0,    5, "FatJet23_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_fj31_dR");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj23_dR"); } );  
    hists_allHad.add2DHistogram("FatJet12_dPhi", 60,   0,    4, "FatJet23_dPhi", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj23_dPhi"); } );
    hists_allHad.add2DHistogram("FatJet12_dPhi", 60,   0,    4, "FatJet31_dPhi", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj31_dPhi"); } );
    hists_allHad.add2DHistogram("FatJet31_dPhi", 60,   0,    4, "FatJet23_dPhi", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_fj31_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj23_dPhi"); } );  
    
    
    hists_allHad.add2DHistogram("ptVVV_reco_fj", 60,   0,    1000, "FatJet12_dPhi", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dPhi"); } );
    hists_allHad.add2DHistogram("ptVVV_reco_fj", 60,   0,    1000, "FatJet12_dPhi_zoom", 60,   2,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dPhi"); } );
    hists_allHad.add2DHistogram("ptVVV_reco_fj", 60,   0,    1000, "FatJet12_dEta", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dEta"); } );   
    hists_allHad.add2DHistogram("ptVVV_reco_fj", 60,   0,    1000, "FatJet12_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dR"); } );
    hists_allHad.add2DHistogram("ptVVV_reco", 60,   0,    1000, "FatJet12_dPhi", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_ptVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dPhi"); } );
    hists_allHad.add2DHistogram("ptVVV_reco", 60,   0,    1000, "FatJet12_dEta", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_ptVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dEta"); } );   
    hists_allHad.add2DHistogram("ptVVV_reco", 60,   0,    1000, "FatJet12_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_ptVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dR"); } );
    hists_allHad.add2DHistogram("mVVV_reco_fj", 60,   0,    5000, "FatJet12_dPhi", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dPhi"); } );
    hists_allHad.add2DHistogram("mVVV_reco_fj", 60,   0,    5000, "FatJet12_dEta", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dEta"); } );   
    hists_allHad.add2DHistogram("mVVV_reco_fj", 60,   0,    5000, "FatJet12_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dR"); } );
    hists_allHad.add2DHistogram("mVVV_reco", 60,   0,    5000, "FatJet12_dPhi", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dPhi"); } );
    hists_allHad.add2DHistogram("mVVV_reco", 60,   0,    5000, "FatJet12_dEta", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dEta"); } );   
    hists_allHad.add2DHistogram("mVVV_reco", 60,   0,    5000, "FatJet12_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_mVVV_reco");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dR"); } );



    hists_allHad.add2DHistogram("fatjet_1_eta", 60,   -3,    3, "fatjet_2_eta", 60,   -3,    3, [&]() { return (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 1) ? ana.tx.getBranch<vector<float>>  ("allHad_FatJet_eta")[0] : -999;}, [&]() { return (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 1) ? ana.tx.getBranch<vector<float>>  ("allHad_FatJet_eta")[1] : -999; } );
    hists_allHad.add2DHistogram("fatjet_1_phi", 60,   -4,    4, "fatjet_2_phi", 60,   -4,    4, [&]() { return (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 1) ? ana.tx.getBranch<vector<float>>  ("allHad_FatJet_phi")[0] : -999;}, [&]() { return (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 1) ? ana.tx.getBranch<vector<float>>  ("allHad_FatJet_phi")[1] : -999; } );

    hists_allHad.add2DHistogram("fatjet_2_eta", 60,   -3,    3, "fatjet_3_eta", 60,   -3,    3, [&]() { return (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>  ("allHad_FatJet_eta")[1] : -999;}, [&]() { return (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>  ("allHad_FatJet_eta")[2] : -999; } );
    hists_allHad.add2DHistogram("fatjet_3_eta", 60,   -3,    3, "fatjet_1_eta", 60,   -3,    3, [&]() { return (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>  ("allHad_FatJet_eta")[2] : -999;}, [&]() { return (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>  ("allHad_FatJet_eta")[1] : -999; } );
    hists_allHad.add2DHistogram("fatjet_2_phi", 60,   -4,    4, "fatjet_3_phi", 60,   -4,    4, [&]() { return (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>  ("allHad_FatJet_phi")[1] : -999;}, [&]() { return (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>  ("allHad_FatJet_phi")[2] : -999; } );
    hists_allHad.add2DHistogram("fatjet_3_phi", 60,   -4,    4, "fatjet_1_phi", 60,   -4,    4, [&]() { return (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>  ("allHad_FatJet_phi")[2] : -999;}, [&]() { return (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>  ("allHad_FatJet_phi")[1] : -999; } );
    
    hists_allHad.add2DHistogram("jet12_mass", 60,   0,    1000, "jet12_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_j12_mass");}, [&]() { return ana.tx.getBranch<float>  ("allHad_j12_dR"); } );
    hists_allHad.add2DHistogram("jet23_mass", 60,   0,    1000, "jet23_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_j23_mass");}, [&]() { return ana.tx.getBranch<float>  ("allHad_j23_dR"); } );
    hists_allHad.add2DHistogram("jet31_mass", 60,   0,    1000, "jet31_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_j31_mass");}, [&]() { return ana.tx.getBranch<float>  ("allHad_j31_dR"); } );
    
    
    */

    hists_allHad.addHistogram("FatJet12_dPhi"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj12_dPhi"); } );
    hists_allHad.addHistogram("FatJet12_dPhi_zoom"   ,  60,   2.5,    3.2, [&]() { return      ana.tx.getBranch<float>("allHad_fj12_dPhi"); } );
    hists_allHad.addHistogram("FatJet12_dEta"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj12_dEta"); } );
    hists_allHad.addHistogram("FatJet12_dR"     ,  60,   0,    5, [&]() { return      ana.tx.getBranch<float>("allHad_fj12_dR"); } );
    hists_allHad.addHistogram("FatJet23_dPhi"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj23_dPhi"); } );
    hists_allHad.addHistogram("FatJet23_dPhi_zoom"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj23_dPhi"); } );
    hists_allHad.addHistogram("FatJet23_dEta"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj23_dEta"); } );
    hists_allHad.addHistogram("FatJet23_dR"     ,  60,   0,    5, [&]() { return      ana.tx.getBranch<float>("allHad_fj23_dR"); } );
    hists_allHad.addHistogram("FatJet31_dPhi"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj31_dPhi"); } );
    hists_allHad.addHistogram("FatJet31_dPhi_zoom"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj31_dPhi"); } );
    hists_allHad.addHistogram("FatJet31_dEta"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj31_dEta"); } );
    hists_allHad.addHistogram("FatJet31_dR"     ,  60,   0,    5, [&]() { return      ana.tx.getBranch<float>("allHad_fj31_dR"); } );


    
    hists_allHad.addHistogram("jet12_mass"          ,  60,   0,    500, [&]() { return  ana.tx.getBranch<float>("allHad_j12_mass") ; } );
    hists_allHad.addHistogram("jet23_mass"          ,  60,   0,    500, [&]() { return  ana.tx.getBranch<float>("allHad_j23_mass") ; } );
    hists_allHad.addHistogram("jet31_mass"          ,  60,   0,    500, [&]() { return  ana.tx.getBranch<float>("allHad_j31_mass") ; } );
    
    hists_allHad.addHistogram("FatJet_pt_0"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_pt")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_pt_1"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_pt")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_pt_2"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_pt")[2] : -999 ; } );
    
    
    hists_allHad.addHistogram("FatJet_eta_0"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_eta").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_eta")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_eta_1"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_eta").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_eta")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_eta_2"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_eta").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_eta")[2] : -999 ; } );
    
    // hists_allHad.addHistogram("FatJet_M_0"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_M").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_M")[0] : -999 ; } );
    // hists_allHad.addHistogram("FatJet_M_1"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_M").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_M")[1] : -999 ; } );
    // hists_allHad.addHistogram("FatJet_M_2"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_M").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_M")[2] : -999 ; } );

    
    // hists_allHad.addHistogram("FatJet_tau1_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau1").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau1")[0] : -999 ; } );
    // hists_allHad.addHistogram("FatJet_tau1_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau1").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau1")[1] : -999 ; } );
    // hists_allHad.addHistogram("FatJet_tau1_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau1").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau1")[2] : -999 ; } );
    
    // hists_allHad.addHistogram("FatJet_tau2_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau2").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau2")[0] : -999 ; } );
    // hists_allHad.addHistogram("FatJet_tau2_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau2").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau2")[1] : -999 ; } );
    // hists_allHad.addHistogram("FatJet_tau2_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau2").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau2")[2] : -999 ; } );
    
    // hists_allHad.addHistogram("FatJet_tau3_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau3").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau3")[0] : -999 ; } );
    // hists_allHad.addHistogram("FatJet_tau3_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau3").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau3")[1] : -999 ; } );
    // hists_allHad.addHistogram("FatJet_tau3_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau3").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau3")[2] : -999 ; } );
    
    
    hists_allHad.addHistogram("FatJet_tau21_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau21").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau21_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau21_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21")[2] : -999 ; } );

    
    hists_allHad.addHistogram("FatJet_tau32_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau32_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau32_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_Wtag_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_W").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Wtag_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_W").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Wtag_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_W").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_Ztag_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_Z").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Ztag_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_Z").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Ztag_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_Z").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_Ttag_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Ttag_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Ttag_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_msoftdrop_0"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_msoftdrop_1"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_msoftdrop_2"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop")[2] : -999 ; } );
    
    hists_allHad.addHistogram("Jet_pt_0"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[0] : -999 ; } );
    hists_allHad.addHistogram("Jet_pt_1"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[1] : -999 ; } );
    hists_allHad.addHistogram("Jet_pt_2"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[2] : -999 ; } );
    hists_allHad.addHistogram("Jet_pt_3"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 3) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[3] : -999; } );
    
    hists_allHad.addHistogram("Jet_eta_0"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_eta").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_Jet_eta")[0] : -999 ; } );
    hists_allHad.addHistogram("Jet_eta_1"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_eta").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_Jet_eta")[1] : -999 ; } );
    hists_allHad.addHistogram("Jet_eta_2"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_eta").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_Jet_eta")[2] : -999 ; } );
    hists_allHad.addHistogram("Jet_eta_3"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_eta").size() > 3) ? ana.tx.getBranch<vector<float>>("allHad_Jet_eta")[3] : -999; } );
    
    //ABCD Method?
    hists_allHad.add2DHistogram("mSD_0",  10,   40,     150,  "mSD_1",  10,   40,     150,   [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[0];}, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[1]; } );
    //hists_allHad.add2DHistogram("mSD_0_high", 10,   105,    150, "mSD_1_high", 10,   105,    150, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[0];}, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[1]; } );
    //hists_allHad.add2DHistogram("mSD_0_SR",   10,   65,     105, "mSD_1_SR",   10,   65,     105, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[0];}, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[1]; } );

    hists_allHad.add2DHistogram("WTag_0",     10,   0.5,     1, "WTag_1",      10,  0.5,     1, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_Wtag")[0];}, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_Wtag")[1]; } );
    hists_allHad.add2DHistogram("WTag_0",     10,   0.5,     1, "mSD_0",       20,  40,     150, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_Wtag")[0];}, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[0]; } );
    hists_allHad.add2DHistogram("WTag_1",     10,   0.5,     1, "mSD_1",       20,  40,     150, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_Wtag")[1];}, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[1]; } );
    hists_allHad.add2DHistogram("WTag_0",     10,   0.5,     1, "mSD_1",       20,  40,     150, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_Wtag")[0];}, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[1]; } );
    hists_allHad.add2DHistogram("WTag_1",     10,   0.5,     1, "mSD_0",       20,  40,     150, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_Wtag")[1];}, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[0]; } );


    /* GEN STUFF
    hists_allHad.addHistogram("genV_status_0"          ,  10,   0,    10, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_genV_status").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_genV_status")[0] : -999 ; } );
    hists_allHad.addHistogram("genV_status_1"          ,  10,   0,    10, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_genV_status").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_genV_status")[1] : -999 ; } );
    hists_allHad.addHistogram("genV_status_2"          ,  10,   0,    10, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_genV_status").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_genV_status")[2] : -999 ; } );
    
    
    hists_allHad.addHistogram("NGenLeptons"       ,  10,   0,   10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_nGenLeps")   ; } );
    hists_allHad.addHistogram("NGenQuarks"       ,  10,   0,   10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_nGenQuarks")   ; } );
    hists_allHad.addHistogram("NGenV"       ,  10,   0,   10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_nGenV")   ; } );
    hists_allHad.addHistogram("FatJet_0_NMatchedQuarks"       ,  10,   0,   10, [&]() { return  (ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_nMatchedQuarks").size() > 0 ) ?    ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_nMatchedQuarks")[0] : -999  ; } );
    hists_allHad.addHistogram("FatJet_1_NMatchedQuarks"       ,  10,   0,   10, [&]() { return  (ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_nMatchedQuarks").size() > 1 ) ?    ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_nMatchedQuarks")[1] : -999  ; } );
    hists_allHad.addHistogram("FatJet_2_NMatchedQuarks"       ,  10,   0,   10, [&]() { return  (ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_nMatchedQuarks").size() > 2 ) ?    ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_nMatchedQuarks")[2] : -999  ; } );
    //hists_allHad.addHistogram("NGenJets"       ,  10,   0,   10, [&]() { return      ana.tx.getBranchLazy<vector<LorentzVector>>("Common_genJet_p4").size()   ; } );
    
    hists_allHad.addVecHistogram("gen_vvvdecay_pdgid"       ,  20,   0,    20,  [&]() { return      ana.tx.getBranch<vector<float>>  ("allHad_gen_vvvdecay_pdgid"); } );
    
    hists_allHad.add2DHistogram("genV12_dPhi", 60,   0,    4, "genV12_dEta", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_v12_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_v12_dEta"); } );
    hists_allHad.add2DHistogram("genV23_dPhi", 60,   0,    4, "genV23_dEta", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_v23_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_v23_dEta"); } );
    hists_allHad.add2DHistogram("genV31_dPhi", 60,   0,    4, "genV31_dEta", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_v31_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_v31_dEta"); } );
    hists_allHad.add2DHistogram("genV12_dR", 60,   0,    5, "genV23_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_v12_dR");}, [&]() { return ana.tx.getBranch<float>  ("allHad_v23_dR"); } );
    hists_allHad.add2DHistogram("genV12_dR", 60,   0,    5, "genV31_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_v12_dR");}, [&]() { return ana.tx.getBranch<float>  ("allHad_v31_dR"); } );
    hists_allHad.add2DHistogram("genV31_dR", 60,   0,    5, "genV23_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_v31_dR");}, [&]() { return ana.tx.getBranch<float>  ("allHad_v23_dR"); } );  
    hists_allHad.add2DHistogram("genV12_dPhi", 60,   0,    4, "genV23_dPhi", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_v12_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_v23_dPhi"); } );
    hists_allHad.add2DHistogram("genV12_dPhi", 60,   0,    4, "genV31_dPhi", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_v12_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_v31_dPhi"); } );
    hists_allHad.add2DHistogram("genV31_dPhi", 60,   0,    4, "genV23_dPhi", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_v31_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_v23_dPhi"); } );  
    
    hists_allHad.add2DHistogram("genV12_dR", 60,   0,    5, "FatJet12_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_v12_dR");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dR"); } );
    hists_allHad.add2DHistogram("genV12_dPhi", 60,   0,  4, "FatJet12_dPhi", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_v12_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dPhi"); } );
    hists_allHad.add2DHistogram("genV12_dEta", 60,   0,  4, "FatJet12_dEta", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_v12_dEta");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj12_dEta"); } );
    
    hists_allHad.add2DHistogram("genV23_dR", 60,   0,    5, "FatJet23_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_v23_dR");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj23_dR"); } );
    hists_allHad.add2DHistogram("genV23_dPhi", 60,   0,  4, "FatJet23_dPhi", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_v23_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj23_dPhi"); } );
    hists_allHad.add2DHistogram("genV23_dEta", 60,   0,  4, "FatJet23_dEta", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_v23_dEta");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj23_dEta"); } );
    
    hists_allHad.add2DHistogram("genV31_dR", 60,   0,    5, "FatJet31_dR", 60,   0,    5, [&]() { return ana.tx.getBranch<float>  ("allHad_v31_dR");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj31_dR"); } );
    hists_allHad.add2DHistogram("genV31_dPhi", 60,   0,  4, "FatJet31_dPhi", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_v31_dPhi");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj31_dPhi"); } );
    hists_allHad.add2DHistogram("genV31_dEta", 60,   0,  4, "FatJet31_dEta", 60,   0,    4, [&]() { return ana.tx.getBranch<float>  ("allHad_v31_dEta");}, [&]() { return ana.tx.getBranch<float>  ("allHad_fj31_dEta"); } );
    
    hists_allHad.addHistogram("genV12_dPhi"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_v12_dPhi"); } );
    hists_allHad.addHistogram("genV12_dPhi_zoom"   ,  60,   2,    4, [&]() { return      ana.tx.getBranch<float>("allHad_v12_dPhi"); } );
    hists_allHad.addHistogram("genV12_dEta"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_v12_dEta"); } );
    hists_allHad.addHistogram("genV12_dR"     ,  60,   0,    5, [&]() { return      ana.tx.getBranch<float>("allHad_v12_dR"); } );
    hists_allHad.addHistogram("genV23_dPhi"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_v23_dPhi"); } );
    hists_allHad.addHistogram("genV23_dPhi_zoom"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_v23_dPhi"); } );
    hists_allHad.addHistogram("genV23_dEta"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_v23_dEta"); } );
    hists_allHad.addHistogram("genV23_dR"     ,  60,   0,    5, [&]() { return      ana.tx.getBranch<float>("allHad_v23_dR"); } );
    hists_allHad.addHistogram("genV31_dPhi"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_v31_dPhi"); } );
    hists_allHad.addHistogram("genV31_dPhi_zoom"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_v31_dPhi"); } );
    hists_allHad.addHistogram("genV31_dEta"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_v31_dEta"); } );
    hists_allHad.addHistogram("genV31_dR"     ,  60,   0,    5, [&]() { return      ana.tx.getBranch<float>("allHad_v31_dR"); } );
  */
  
  
   
    ana.cutflow.bookCutflows(); 
    
    ana.cutflow.bookHistogramsForCut(hists_allHad, "allHad_fixedHT");
    ana.cutflow.bookHistogramsForCutAndBelow(hists_allHad, "allHad_2fj_mSD_sideband");
    ana.cutflow.bookHistogramsForCutAndBelow(hists_allHad, "allHad_2fj_1med1tight");
    ana.cutflow.bookHistogramsForCutAndBelow(hists_allHad, "allHad_2fj_tight");
    ana.cutflow.bookHistogramsForCutAndBelow(hists_allHad, "allHad_2fj_ABCD");
    ana.cutflow.bookHistogramsForCutAndBelow(hists_allHad, "allHad_3fj_tight");
    

}

void Begin_1L_VVVTree()
{
    //vector branches
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau1");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau2");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau3");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau21");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_tau32");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_msoftdrop");
    ana.tx.createBranch<vector<int>>    ("allHad_FatJet_WP");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_pt");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_M");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_eta");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_phi");
    ana.tx.createBranch<vector<LorentzVector>>  ("allHad_FatJet_p4");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_ID");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Zbbtag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Ztag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Ttag");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Wtag");
    ana.tx.createBranch<float>  ("allHad_FatJet_SF");
    
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_pt");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_eta");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_phi");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_M");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_ID");
    ana.tx.createBranch<vector<float>>  ("allHad_Jet_puid");
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvvdecay_pdgid"); // for now these need to be floats bc addVecHistogram doesn't take ints
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvvdecay_pt"); 
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvv_pt"); 
    ana.tx.createBranch<vector<float>>  ("allHad_gen_vvv_eta"); 
    ana.tx.createBranch<vector<float>>  ("allHad_gen_pdgId");
    
    
    // Single var branches
    ana.tx.createBranch<float>  ("allHad_mindPhi_MetFJ");
    ana.tx.createBranch<float>  ("allHad_genHT");
    ana.tx.createBranch<float>  ("allHad_mVVV");
    ana.tx.createBranch<float>  ("allHad_HT");
    ana.tx.createBranch<float>  ("allHad_ST");
    ana.tx.createBranch<float>  ("allHad_mVVV_reco");
    ana.tx.createBranch<float>  ("allHad_ptVVV_reco");
    ana.tx.createBranch<float>  ("allHad_mVVV_reco_nomet");
    ana.tx.createBranch<float>  ("allHad_ptVVV_reco_nomet");
    
    ana.tx.createBranch<float>  ("allHad_fj_mVVV");
    ana.tx.createBranch<float>  ("allHad_fj_HT");
    ana.tx.createBranch<float>  ("allHad_fj_ST");
    ana.tx.createBranch<float>  ("allHad_fj_mVVV_reco");
    ana.tx.createBranch<float>  ("allHad_fj_ptVVV_reco");
    ana.tx.createBranch<float>  ("allHad_fj_mVVV_reco_nomet");
    ana.tx.createBranch<float>  ("allHad_fj_ptVVV_reco_nomet");
    ana.tx.createBranch<float>  ("allHad_fj_mVVV_reco_nomet_SD");
    ana.tx.createBranch<float>  ("allHad_fj_ptVVV_reco_nomet_SD");
    
    ana.tx.createBranch<float>  ("allHad_fj12_dPhi");
    ana.tx.createBranch<float>  ("allHad_fj12_dEta");
    ana.tx.createBranch<float>  ("allHad_fj12_dR");
    ana.tx.createBranch<float>  ("allHad_fj23_dPhi");
    ana.tx.createBranch<float>  ("allHad_fj23_dEta");
    ana.tx.createBranch<float>  ("allHad_fj23_dR");
    ana.tx.createBranch<float>  ("allHad_fj31_dPhi");
    ana.tx.createBranch<float>  ("allHad_fj31_dEta");
    ana.tx.createBranch<float>  ("allHad_fj31_dR");
    
    ana.tx.createBranch<float>  ("allHad_v12_dPhi");
    ana.tx.createBranch<float>  ("allHad_v12_dEta");
    ana.tx.createBranch<float>  ("allHad_v12_dR");
    ana.tx.createBranch<float>  ("allHad_v23_dPhi");
    ana.tx.createBranch<float>  ("allHad_v23_dEta");
    ana.tx.createBranch<float>  ("allHad_v23_dR");
    ana.tx.createBranch<float>  ("allHad_v31_dPhi");
    ana.tx.createBranch<float>  ("allHad_v31_dEta");
    ana.tx.createBranch<float>  ("allHad_v31_dR");
    
    ana.tx.createBranch<float>  ("allHad_j12_mass");
    ana.tx.createBranch<float>  ("allHad_j12_dPhi");
    ana.tx.createBranch<float>  ("allHad_j12_dEta");
    ana.tx.createBranch<float>  ("allHad_j12_dR");
    ana.tx.createBranch<float>  ("allHad_j23_mass");
    ana.tx.createBranch<float>  ("allHad_j23_dPhi");
    ana.tx.createBranch<float>  ("allHad_j23_dEta");
    ana.tx.createBranch<float>  ("allHad_j23_dR");
    ana.tx.createBranch<float>  ("allHad_j31_mass");
    ana.tx.createBranch<float>  ("allHad_j31_dPhi");
    ana.tx.createBranch<float>  ("allHad_j31_dEta");
    ana.tx.createBranch<float>  ("allHad_j31_dR");
    
    
    ana.tx.createBranch<vector<float>>  ("allHad_genV_status");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_nMatchedQuarks");
    
    
    
    ana.tx.createBranch<int>  ("allHad_nGenLeps");
    ana.tx.createBranch<int>  ("allHad_nGenQuarks");
    ana.tx.createBranch<int>  ("allHad_nGenV");
    ana.tx.createBranch<int>  ("allHad_nb_loose");
    ana.tx.createBranch<int>  ("allHad_nb_medium");
    ana.tx.createBranch<int>  ("allHad_nb_tight");
    ana.tx.createBranch<int>  ("allHad_NFatJet_loose");
    ana.tx.createBranch<int>  ("allHad_NFatJet_medium");
    ana.tx.createBranch<int>  ("allHad_NFatJet_tight");
    

    //at this point we've already skimmed
    ana.cutflow.getCut("CommonCut");

    const int eft_reweighting_idx = ana.eft_reweighting_idx;
    std::cout << "eft index " << eft_reweighting_idx;
    ana.cutflow.addCutToLastActiveCut("oneL_EFT", [&]() {
        return true;
        }, [&, eft_reweighting_idx]() { return  eft_reweighting_idx < 0 ? 1.0 : ana.tx.getBranchLazy<float>("Common_genWeight") * ana.tx.getBranchLazy<vector<float>>("Common_LHEReweightingWeight")[eft_reweighting_idx]; } );
    

    //1 lep, orthogonal to qilong's SR
    ana.cutflow.addCutToLastActiveCut("oneL_ptLep_l70", [&]() {
        if (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4").size() == 0) return false;
        if (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt() < 70) return true;
        return false;
        }, [&]() { return 1.0; } );

    //building qilong's SR
    ana.cutflow.addCutToLastActiveCut("oneL_QL_SR", [&]() {
        if (ana.tx.getBranchLazy<int>("allHad_nb_medium") != 0 ) return false;
        if (ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt() < 60) return false;
        if ( getMT() < 150) return false;

        return true;
        }, [&]() { return 1.0; } );
    
    ana.cutflow.addCutToLastActiveCut("oneL_1fj", [&]() {
        if (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size() == 1) return true;
        return false;
        }, [&]() { return 1.0; } );
    
    ana.cutflow.addCutToLastActiveCut("oneL_1fj_tight", [&]() {
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[0] == 3 ) return true;
        return false;
        }, [&]() { return 1.0; } );

    ana.cutflow.addCutToLastActiveCut("oneL_2fj_tight", [&]() {
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[1] == 3 ) return true;
        return false;
        }, [&]() { return 1.0; } );

   
    


    RooUtil::Histograms hists_allHad;

    //single value histograms
    hists_allHad.addHistogram("NJets"            ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt").size()    ; } );
    hists_allHad.addHistogram("NLeps"            ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size()   ; } );
    hists_allHad.addHistogram("NGenFatJets"       ,  10,   0,   10, [&]() { return      ana.tx.getBranchLazy<vector<LorentzVector>>("Common_genFatJet_p4").size()   ; } );
    hists_allHad.addHistogram("NFatJets"         ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_pt").size() ; } );
    hists_allHad.addHistogram("NW"               ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_n_W") ; } );

    hists_allHad.addHistogram("n_b_loose"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_nb_loose") ; } );
    hists_allHad.addHistogram("n_b_medium"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_nb_medium") ; } );
    hists_allHad.addHistogram("n_b_tight"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_nb_tight") ; } );

    hists_allHad.addHistogram("nFatJet_loose"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_NFatJet_loose") ; } );
    hists_allHad.addHistogram("nFatJet_medium"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_NFatJet_medium") ; } );
    hists_allHad.addHistogram("nFatJet_tight"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_NFatJet_tight") ; } );  

    hists_allHad.addHistogram("MET"              ,  40,   0,    800, [&]() { return    ana.tx.getBranch<LorentzVector>  ("Common_met_p4").Pt(); } );

    hists_allHad.addHistogram("MET_phi"              ,  40,   -4,    4, [&]() { return    ana.tx.getBranch<LorentzVector>  ("Common_met_p4").Phi(); } );
    hists_allHad.addHistogram("METFJ_dPhi_min"       ,  40,   0,    4, [&]() { return    ana.tx.getBranch<float>  ("allHad_mindPhi_MetFJ"); } );
    hists_allHad.addHistogram("genHT"            ,  40,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_genHT"); } );
    hists_allHad.addHistogram("HT"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.addHistogram("ST"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_ST"); } );
    hists_allHad.addHistogram("mVVV_reco"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_mVVV_reco"); } );
    hists_allHad.addHistogram("ptVVV_reco"               ,  60,   0,    800, [&]() { return    ana.tx.getBranch<float>  ("allHad_ptVVV_reco"); } );
    hists_allHad.addHistogram("mVVV_reco_nomet"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_mVVV_reco_nomet"); } );
    hists_allHad.addHistogram("ptVVV_reco_nomet"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_ptVVV_reco_nomet"); } );
    
    hists_allHad.addHistogram("HT_fj"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_HT"); } );
    hists_allHad.addHistogram("ST_fj"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ST"); } );
    hists_allHad.addHistogram("mVVV_reco_fj"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco"); } );
    hists_allHad.addHistogram("ptVVV_reco_fj"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco"); } );
    hists_allHad.addHistogram("mVVV_reco_nomet_fj"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco_nomet"); } );
    hists_allHad.addHistogram("ptVVV_reco_nomet_fj"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco_nomet"); } );
    hists_allHad.addHistogram("mVVV_reco_nomet_fj_SD"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco_nomet_SD"); } );
    hists_allHad.addHistogram("ptVVV_reco_nomet_fj_SD"               ,  60,   0,    800, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco_nomet_SD"); } );
 

    hists_allHad.addHistogram("FatJet12_dPhi"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj12_dPhi"); } );
    hists_allHad.addHistogram("FatJet12_dPhi_zoom"   ,  60,   2.5,    3.2, [&]() { return      ana.tx.getBranch<float>("allHad_fj12_dPhi"); } );
    hists_allHad.addHistogram("FatJet12_dEta"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj12_dEta"); } );
    hists_allHad.addHistogram("FatJet12_dR"     ,  60,   0,    5, [&]() { return      ana.tx.getBranch<float>("allHad_fj12_dR"); } );
    hists_allHad.addHistogram("FatJet23_dPhi"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj23_dPhi"); } );
    hists_allHad.addHistogram("FatJet23_dPhi_zoom"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj23_dPhi"); } );
    hists_allHad.addHistogram("FatJet23_dEta"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj23_dEta"); } );
    hists_allHad.addHistogram("FatJet23_dR"     ,  60,   0,    5, [&]() { return      ana.tx.getBranch<float>("allHad_fj23_dR"); } );
    hists_allHad.addHistogram("FatJet31_dPhi"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj31_dPhi"); } );
    hists_allHad.addHistogram("FatJet31_dPhi_zoom"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj31_dPhi"); } );
    hists_allHad.addHistogram("FatJet31_dEta"   ,  60,   0,    4, [&]() { return      ana.tx.getBranch<float>("allHad_fj31_dEta"); } );
    hists_allHad.addHistogram("FatJet31_dR"     ,  60,   0,    5, [&]() { return      ana.tx.getBranch<float>("allHad_fj31_dR"); } );


    
    hists_allHad.addHistogram("jet12_mass"          ,  60,   0,    500, [&]() { return  ana.tx.getBranch<float>("allHad_j12_mass") ; } );
    hists_allHad.addHistogram("jet23_mass"          ,  60,   0,    500, [&]() { return  ana.tx.getBranch<float>("allHad_j23_mass") ; } );
    hists_allHad.addHistogram("jet31_mass"          ,  60,   0,    500, [&]() { return  ana.tx.getBranch<float>("allHad_j31_mass") ; } );
    
    hists_allHad.addHistogram("FatJet_pt_0"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_pt")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_pt_1"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_pt")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_pt_2"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_pt")[2] : -999 ; } );
    
    
    hists_allHad.addHistogram("FatJet_eta_0"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_eta").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_eta")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_eta_1"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_eta").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_eta")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_eta_2"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_eta").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_eta")[2] : -999 ; } );

    
    hists_allHad.addHistogram("FatJet_tau21_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau21_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau21_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau21")[2] : -999 ; } );

    
    hists_allHad.addHistogram("FatJet_tau32_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau32_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau32_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_tau32")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_Wtag_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Wtag_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Wtag_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Wtag")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_Ztag_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Ztag_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Ztag_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ztag")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_Ttag_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Ttag_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_Ttag_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_Ttag")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_msoftdrop_0"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_msoftdrop_1"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_msoftdrop_2"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_FatJet_msoftdrop")[2] : -999 ; } );
    
    hists_allHad.addHistogram("Jet_pt_0"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[0] : -999 ; } );
    hists_allHad.addHistogram("Jet_pt_1"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[1] : -999 ; } );
    hists_allHad.addHistogram("Jet_pt_2"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[2] : -999 ; } );
    hists_allHad.addHistogram("Jet_pt_3"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_pt").size() > 3) ? ana.tx.getBranch<vector<float>>("allHad_Jet_pt")[3] : -999; } );
    
    hists_allHad.addHistogram("Jet_eta_0"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_eta").size() > 0) ? ana.tx.getBranch<vector<float>>("allHad_Jet_eta")[0] : -999 ; } );
    hists_allHad.addHistogram("Jet_eta_1"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_eta").size() > 1) ? ana.tx.getBranch<vector<float>>("allHad_Jet_eta")[1] : -999 ; } );
    hists_allHad.addHistogram("Jet_eta_2"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_eta").size() > 2) ? ana.tx.getBranch<vector<float>>("allHad_Jet_eta")[2] : -999 ; } );
    hists_allHad.addHistogram("Jet_eta_3"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<float>>("allHad_Jet_eta").size() > 3) ? ana.tx.getBranch<vector<float>>("allHad_Jet_eta")[3] : -999; } );
    
    
  
   
    ana.cutflow.bookCutflows(); 
    
    ana.cutflow.bookHistogramsForCutAndBelow(hists_allHad, "oneL_ptLep_l70");
}






bool is_baseline_jet(unsigned int i){
    if( ana.tx.getBranchLazy<vector<int>>("Common_jet_id")[i] != 6 ) return false;
    
    if ( ana.tx.getBranchLazy<vector<int>>("Common_jet_overlapfatjet")[i]) return false;

    return true;
}

bool is_baseline_fatjet(unsigned int i, bool firstPTcut, bool SDcut){
    if( ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i].Pt() < 200 ) return false;
    if( abs(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i].Eta()) > 2.4 ) return false;

    if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_id")[i] != 6) return false;
    
    //if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[i] < 1) return false;

    //first jet pT > 500 GeV
    if(firstPTcut){
        if( i == 0 && ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i].Pt() < 500 ) return false;
    }

    if(SDcut){
        if( !(ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i] <= 105. ) ) return false;
    }
    else{
        if( ! (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i] >= 40. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i] <= 150. ) ) return false;

    }

    return true;
}


float getMT(){
    LorentzVector MET = ana.tx.getBranchLazy<LorentzVector>("Common_met_p4");
    LorentzVector lep = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0];

    float MT = TMath::Sqrt(2*lep.Pt()*MET.Pt()*(1.0-TMath::Cos(lep.Phi() - MET.Phi())));

    //std::cout <<" MT "  << MT << std::endl;;
    return MT;
}

float get_weight(){
    //deal with this later
    if( ana.is_EFT_sample) return 1.0;

    TFile* inputfile = TFile::Open(ana.input_file_list_tstring);
    TH1F* h_nevents = (TH1F*) inputfile->Get("Wgt__h_nevents"); // Should be "Wgt" to be accurate but the tree does not save event weight (i.e. the sign)
    float n_total_events = h_nevents->GetBinContent(1);
    
    //fix this later
    float lumi = 59.74;

    float xsecbr = -999;
    if (ana.input_file_list_tstring.Contains("/QCD_HT700to1000.root"         )) xsecbr = 6831.;
    if (ana.input_file_list_tstring.Contains("/QCD_HT1000to1500.root"         )) xsecbr = 1207.;
    if (ana.input_file_list_tstring.Contains("/QCD_HT1500to2000.root"         )) xsecbr = 119.9;
    if (ana.input_file_list_tstring.Contains("/QCD_HT2000toInf.root"          )) xsecbr = 119.9;

    std::cout << " GOT " << ana.input_file_list_tstring << " with " << xsecbr << std::endl;
    if( xsecbr > 0 ){
        return xsecbr*lumi/n_total_events*1000;
    }
    //for samples i am not dealing with yet
    else return 1.0;


}
