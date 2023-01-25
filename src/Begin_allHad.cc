#include "Begin_allHad.h"

void Begin_allHad()
{
    std::cout << "running VV tree? " << ana.run_VVVTree << " and region " << ana.region << std::endl;
    //region 1 for 1Lep CR
    if(ana.region == 1){
        if(ana.run_VVVTree){
            std::cout << "running!!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
            Begin_1L_VVVTree();
        }
        else   
            Begin_1L_NanoAOD();
    }
    //signal selections
    else{
        if (ana.run_VVVTree)
        {
            if (ana.write_tree)
            {
                Begin_allHad_VVVTree_writeTree();
            }
            else
            {
                Begin_allHad_VVVTree();
            }
        }
        else
        {
            Begin_allHad_NanoAOD();
        }
    }
}

void Begin_allHad_NanoAOD()
{ 

    //define skimming selections -- require 0 leptons and trigger and HT pass
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("allHad", [&]() {

        if( ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size() > 0) return false; 
        if( ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size() < 2) return false;
        //if( ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size() < 1) return false;
        int nfj = 0;
        for(unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size(); i++){
            if( is_baseline_fatjet(i, false, false )) nfj++;
        }
        if(nfj < 1) return false;

        return true;
        }, [&]() { return  1;} );

    ana.cutflow.addCutToLastActiveCut("allHad_trigger", [&]() {
        //std::cout << "year is " << ana.tx.getBranchLazy<int>("Common_year");

        if(  (ana.tx.getBranchLazy<int>("Common_year") == 2018 || ana.tx.getBranchLazy<int>("Common_year") == 2017 )
          &&  (ana.tx.getBranchLazy<bool>("Common_HLT_PFHT1050") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet500") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet360_TrimMass30") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet380_TrimMass30") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet400_TrimMass30") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet420_TrimMass30") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT750_TrimMass50") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT800_TrimMass50") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT850_TrimMass50") || 
               ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT900_TrimMass50")  
        )) 
        {

            return true;
        }

        if(  (ana.tx.getBranchLazy<int>("Common_year") == 2016 )
          &&  (  ana.tx.getBranchLazy<bool>("Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5") || 
                ana.tx.getBranchLazy<bool>("Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5") || 
                ana.tx.getBranchLazy<bool>("Common_HLT_PFHT800") || 
                ana.tx.getBranchLazy<bool>("Common_HLT_PFHT900") || 
                ana.tx.getBranchLazy<bool>("Common_HLT_PFJet450") || 
                ana.tx.getBranchLazy<bool>("Common_HLT_PFJet500" ) || 
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet450" ) || 
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet500") ||
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet360_TrimMass30") ||
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50" ) 
        ) ) return true;

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


        //want first two fatjets to be good, agnostic to others, make 1st pt cut but not msd cut
        if( ! (is_baseline_fatjet(0, true, false) && is_baseline_fatjet(1, true, false)) ) return false;
        
        //HT from all jets/fatjets
        for( unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size(); i++){
            //if( is_baseline_fatjet(i, false, false) ){
            HT+= ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i].Pt();
               // nselect ++;
           // }
        }

        //if( nselect != ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() ) return false;
        if(HT > 1100) return true;
        else return false;

    }, [&]() { return 1; } );

    
    ana.cutflow.bookCutflows(); 
    
}

void Begin_1L_NanoAOD()
{
    //1L skimming -- 1 lepton and 1 fatjet
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("oneLep", [&]() {

        if( ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size() != 1) return false; 
        if( ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size() < 1) return false;
        int nfj = 0;
        for(unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size(); i++){
            //dont cut on SD mass or pt of 1st jet
            if( is_baseline_fatjet(i, false, false )) nfj++;
        }
        //at least 1 good fatjet
        if(nfj < 1) return false;
        if(nfj ==  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size()) return true;

        return false;
        }, [&]() { return  1;} );

    ana.cutflow.addCutToLastActiveCut("oneLep_trigger", [&]() {
        
        if(ana.tx.getBranchLazy<int>("Common_isData"))
        {
            bool passEle = ana.input_file_list_tstring.Contains("EGamma")      &&  abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 11 && ana.tx.getBranchLazy<bool>("Common_HLT_Ele32_WPTight");
            bool passMu  = ana.input_file_list_tstring.Contains("SingleMuon")  &&  abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 13 && ana.tx.getBranchLazy<bool>("Common_HLT_IsoMu24");
            if( passEle || passMu)
            {
                return true;
            }

        }
        else
        {
            if( abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 11 &&  ana.tx.getBranchLazy<bool>("Common_HLT_Ele32_WPTight") ) return true;
            if( abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 13 &&  ana.tx.getBranchLazy<bool>("Common_HLT_IsoMu24") ) return true;
        }
                 
        return false;
        
    }, [&]() { return 1; } );
    
    //Remove HT cut for now, not sure if that will do weird stuff because the lepton will be lower pt
    ana.cutflow.addCutToLastActiveCut("oneLep_HT", [&]() {

        return true;

        // float HT = 0;
        // unsigned int nselect = 0;
        // for( unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4").size(); i++){
        //     if ( is_baseline_jet(i) ){
        //         HT+= ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[i].Pt();
        //     }
        // }
        
        // for( unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size(); i++){
        //     if( is_baseline_fatjet(i, true, true) ){
        //         HT+= ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i].Pt();
        //         nselect ++;
        //     }
        // }

        // if( nselect == ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() ) return true;
        
        // //if(HT > 1100) return true;
        // return false;

    }, [&]() { return 1; } );

    
    ana.cutflow.bookCutflows(); 
}


//___________________________________________________________________________________________________________________
void Begin_allHad_VVVTree_writeTree()
{
   // float wgt = get_weight();
    float wgt = 1.0;

    //===================================================================
    ana.tx.createBranch<vector<LV>>("allHad_jets_p4");
    ana.tx.createBranch<vector<LV>>("allHad_fatjets_mSD_p4");
    ana.tx.createBranch<vector<int>>("allHad_fatjets_WP_MD");
    ana.tx.createBranch<vector<int>>("allHad_fatjets_commonFJIdxs");

    ana.tx.createBranch<int>("allHad_nFJ");
    ana.tx.createBranch<LV>("allHad_FJ0_mSD_p4");
    ana.tx.createBranch<LV>("allHad_FJ1_mSD_p4");
    ana.tx.createBranch<LV>("allHad_FJ2_mSD_p4");
    ana.tx.createBranch<int>("allHad_FJ0_WP_MD");
    ana.tx.createBranch<int>("allHad_FJ1_WP_MD");
    ana.tx.createBranch<int>("allHad_FJ2_WP_MD");
    ana.tx.createBranch<float>("allHad_FJ0_WMD");
    ana.tx.createBranch<float>("allHad_FJ1_WMD");
    ana.tx.createBranch<float>("allHad_FJ2_WMD");
    ana.tx.createBranch<float>("allHad_FJ0_VMD");
    ana.tx.createBranch<float>("allHad_FJ1_VMD");
    ana.tx.createBranch<float>("allHad_FJ2_VMD");
    ana.tx.createBranch<float>("allHad_FJ0_Xqq");
    ana.tx.createBranch<float>("allHad_FJ1_Xqq");
    ana.tx.createBranch<float>("allHad_FJ2_Xqq");
    ana.tx.createBranch<float>("allHad_FJ0_Xcc");
    ana.tx.createBranch<float>("allHad_FJ1_Xcc");
    ana.tx.createBranch<float>("allHad_FJ2_Xcc");
    ana.tx.createBranch<float>("allHad_FJ0_Xbb");
    ana.tx.createBranch<float>("allHad_FJ1_Xbb");
    ana.tx.createBranch<float>("allHad_FJ2_Xbb");
    ana.tx.createBranch<float>("allHad_FJ0_QCD");
    ana.tx.createBranch<float>("allHad_FJ1_QCD");
    ana.tx.createBranch<float>("allHad_FJ2_QCD");
    ana.tx.createBranch<int>("allHad_FJ0_commonFJIdxs");
    ana.tx.createBranch<int>("allHad_FJ1_commonFJIdxs");
    ana.tx.createBranch<int>("allHad_FJ2_commonFJIdxs");

    ana.tx.createBranch<LV>("allHad_VVV_mSD_p4");
    ana.tx.createBranch<float>("allHad_mVVV");
    ana.tx.createBranch<float>("allHad_ptVVV");
    ana.tx.createBranch<float>("allHad_HT");
    ana.tx.createBranch<float>("allHad_HT_FJ");

    ana.tx.createBranch<int>("allHad_nb_loose");
    ana.tx.createBranch<int>("allHad_nb_medium");
    ana.tx.createBranch<int>("allHad_nb_tight");

    ana.tx.createBranch<float>("allHad_FJ01_dPhi");
    ana.tx.createBranch<float>("allHad_FJ01_dEta");
    ana.tx.createBranch<float>("allHad_FJ01_dR");
    ana.tx.createBranch<float>("allHad_FJ01_dPtFrac");
    ana.tx.createBranch<float>("allHad_FJ01_pPRel");
    ana.tx.createBranch<float>("allHad_FJ02_dPhi");
    ana.tx.createBranch<float>("allHad_FJ02_dEta");
    ana.tx.createBranch<float>("allHad_FJ02_dR");
    ana.tx.createBranch<float>("allHad_FJ02_dPtFrac");
    ana.tx.createBranch<float>("allHad_FJ02_pPRel");
    ana.tx.createBranch<float>("allHad_FJ12_dPhi");
    ana.tx.createBranch<float>("allHad_FJ12_dEta");
    ana.tx.createBranch<float>("allHad_FJ12_dR");
    ana.tx.createBranch<float>("allHad_FJ12_dPtFrac");
    ana.tx.createBranch<float>("allHad_FJ12_pPRel");
    //===================================================================

    ana.tx.clear();

    //////////////////////////////////////////
    // PRESELECTION
    //////////////////////////////////////////

    // At this point we've already skimmed
    ana.cutflow.getCut("CommonCut");

    const int eft_reweighting_idx = ana.eft_reweighting_idx;
    std::cout << "eft index " << eft_reweighting_idx;

    //~~~~~~~~~~~~~~~~
    // EFT Reweighting
    //~~~~~~~~~~~~~~~~
    ana.cutflow.addCutToLastActiveCut("allHad_EFT", UNITY /* no cuts */,
        [&, eft_reweighting_idx]()
        {
            // Default is weight = 1
            float wgt = 1.0;

            // if EFT then multiply some factors
            if (eft_reweighting_idx >= 0)
            {
                wgt *= ana.tx.getBranch<float>("Common_genWeight");
                wgt *= ana.tx.getBranch<vector<float>>("Common_LHEReweightingWeight")[eft_reweighting_idx];
            }

            // return the weight
            return wgt;
        });

    //~~~~~~~~~~~~~~~~~
    // Object Selection
    //~~~~~~~~~~~~~~~~~
    ana.cutflow.addCutToLastActiveCut("allHad_objSelection",
        [&]()
        {
            float HT = 0;
            float HT_fj = 0 ;

            int nb_loose = 0;
            int nb_medium = 0;
            int nb_tight = 0;

            // Loop over the common jets from common jet selections in *_Common.cc
            for (unsigned int ijet = 0; ijet < ana.tx.getBranchLazy<vector<LV>>("Common_jet_p4").size(); ijet++)
            {
                if (is_baseline_jet(ijet)) // NOTE The overlap removal against fat-jet is already done in this function
                {
                    // Get the jet
                    LV jet = ana.tx.getBranchLazy<vector<LV>>("Common_jet_p4")[ijet];
                    bool pass_loose  = ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBloose")[ijet];
                    bool pass_medium = ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBmedium")[ijet];
                    bool pass_tight  = ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBtight")[ijet];

                    if (pass_loose) nb_loose++;
                    if (pass_medium) nb_medium++;
                    if (pass_tight) nb_tight++;

                    // Save to list of jets for allHad
                    ana.tx.pushbackToBranch<LV>("allHad_jets_p4", jet);

                    // Compute HT
                    HT += jet.Pt();
                }
            }

            ana.tx.setBranch<int>("allHad_nb_loose", nb_loose);
            ana.tx.setBranch<int>("allHad_nb_medium", nb_medium);
            ana.tx.setBranch<int>("allHad_nb_tight", nb_tight);

            // Looping over the fat-jets
            for (unsigned int ifatjet = 0; ifatjet < ana.tx.getBranchLazy<vector<LV>>("Common_fatjet_p4").size(); ifatjet++)
            {
                if (is_baseline_fatjet(ifatjet, true, false))
                {
                    // Get the fatjet
                    LV fatjet = ana.tx.getBranchLazy<vector<LV>>("Common_fatjet_p4")[ifatjet];

                    // Get the softdrop mass
                    float mSD = ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[ifatjet];

                    // Get the fatjet with softdropmass as mass
                    LV fatjet_mSD = RooUtil::Calc::getLV(fatjet.Pt(), fatjet.Eta(), fatjet.Phi(), mSD);


                    // Get jet tagging working point
                    int fatjet_WP = ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[ifatjet];

                    // Save to list of fatjets for allHad
                    ana.tx.pushbackToBranch<LV>("allHad_fatjets_mSD_p4", fatjet_mSD);
                    ana.tx.pushbackToBranch<int>("allHad_fatjets_WP_MD", fatjet_WP);
                    ana.tx.pushbackToBranch<int>("allHad_fatjets_commonFJIdxs", ifatjet);

                    // Compute HT
                    HT += fatjet_mSD.Pt();

                    // Compute HT with fat-jet only
                    HT_fj += ana.tx.getBranchLazy<vector<LV>>("Common_fatjet_p4")[ifatjet].Pt();
                }
            }

            ana.tx.setBranch<float>("allHad_HT", HT);
            ana.tx.setBranch<float>("allHad_HT_FJ", HT_fj);
            return true;

        }, UNITY);

    //~~~~~~~~~~~~~~~~
    // HT preselection
    //~~~~~~~~~~~~~~~~
    ana.cutflow.addCutToLastActiveCut("allHad_preselection",
        [&]()
        {
            // Require HT cut
            if (not (ana.tx.getBranch<float>("allHad_HT") > 1100))
                return false;
            return true;
        }, UNITY);

    ana.cutflow.addCutToLastActiveCut("allHad_computeVariables",
        [&]()
        {
            // Set the nFJ channel
            int nFJ = ana.tx.getBranchLazy<vector<LV>>("allHad_fatjets_mSD_p4").size();
            ana.tx.setBranch<int>("allHad_nFJ", nFJ);

            // Set the flat FJ branches
            if (nFJ > 0) ana.tx.setBranch<LV>("allHad_FJ0_mSD_p4", ana.tx.getBranchLazy<vector<LV>>("allHad_fatjets_mSD_p4")[0]);
            if (nFJ > 1) ana.tx.setBranch<LV>("allHad_FJ1_mSD_p4", ana.tx.getBranchLazy<vector<LV>>("allHad_fatjets_mSD_p4")[1]);
            if (nFJ > 2) ana.tx.setBranch<LV>("allHad_FJ2_mSD_p4", ana.tx.getBranchLazy<vector<LV>>("allHad_fatjets_mSD_p4")[2]);
            if (nFJ > 0) ana.tx.setBranch<int>("allHad_FJ0_WP_MD", ana.tx.getBranchLazy<vector<int>>("allHad_fatjets_WP_MD")[0]);
            if (nFJ > 1) ana.tx.setBranch<int>("allHad_FJ1_WP_MD", ana.tx.getBranchLazy<vector<int>>("allHad_fatjets_WP_MD")[1]);
            if (nFJ > 2) ana.tx.setBranch<int>("allHad_FJ2_WP_MD", ana.tx.getBranchLazy<vector<int>>("allHad_fatjets_WP_MD")[2]);
            if (nFJ > 0) ana.tx.setBranch<int>("allHad_FJ0_commonFJIdxs", ana.tx.getBranchLazy<vector<int>>("allHad_fatjets_commonFJIdxs")[0]);
            if (nFJ > 1) ana.tx.setBranch<int>("allHad_FJ1_commonFJIdxs", ana.tx.getBranchLazy<vector<int>>("allHad_fatjets_commonFJIdxs")[1]);
            if (nFJ > 2) ana.tx.setBranch<int>("allHad_FJ2_commonFJIdxs", ana.tx.getBranchLazy<vector<int>>("allHad_fatjets_commonFJIdxs")[2]);
            if (nFJ > 0) ana.tx.setBranch<float>("allHad_FJ0_WMD", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_W")[ana.tx.getBranchLazy<int>("allHad_FJ0_commonFJIdxs")]);
            if (nFJ > 1) ana.tx.setBranch<float>("allHad_FJ1_WMD", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_W")[ana.tx.getBranchLazy<int>("allHad_FJ1_commonFJIdxs")]);
            if (nFJ > 2) ana.tx.setBranch<float>("allHad_FJ2_WMD", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_W")[ana.tx.getBranchLazy<int>("allHad_FJ2_commonFJIdxs")]);
            if (nFJ > 0) ana.tx.setBranch<float>("allHad_FJ0_Xqq", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_Xqq")[ana.tx.getBranchLazy<int>("allHad_FJ0_commonFJIdxs")]);
            if (nFJ > 1) ana.tx.setBranch<float>("allHad_FJ1_Xqq", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_Xqq")[ana.tx.getBranchLazy<int>("allHad_FJ1_commonFJIdxs")]);
            if (nFJ > 2) ana.tx.setBranch<float>("allHad_FJ2_Xqq", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_Xqq")[ana.tx.getBranchLazy<int>("allHad_FJ2_commonFJIdxs")]);
            if (nFJ > 0) ana.tx.setBranch<float>("allHad_FJ0_Xbb", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_Xbb")[ana.tx.getBranchLazy<int>("allHad_FJ0_commonFJIdxs")]);
            if (nFJ > 1) ana.tx.setBranch<float>("allHad_FJ1_Xbb", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_Xbb")[ana.tx.getBranchLazy<int>("allHad_FJ1_commonFJIdxs")]);
            if (nFJ > 2) ana.tx.setBranch<float>("allHad_FJ2_Xbb", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_Xbb")[ana.tx.getBranchLazy<int>("allHad_FJ2_commonFJIdxs")]);
            if (nFJ > 0) ana.tx.setBranch<float>("allHad_FJ0_Xcc", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_Xcc")[ana.tx.getBranchLazy<int>("allHad_FJ0_commonFJIdxs")]);
            if (nFJ > 1) ana.tx.setBranch<float>("allHad_FJ1_Xcc", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_Xcc")[ana.tx.getBranchLazy<int>("allHad_FJ1_commonFJIdxs")]);
            if (nFJ > 2) ana.tx.setBranch<float>("allHad_FJ2_Xcc", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_Xcc")[ana.tx.getBranchLazy<int>("allHad_FJ2_commonFJIdxs")]);
            if (nFJ > 0) ana.tx.setBranch<float>("allHad_FJ0_QCD", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_QCD")[ana.tx.getBranchLazy<int>("allHad_FJ0_commonFJIdxs")]);
            if (nFJ > 1) ana.tx.setBranch<float>("allHad_FJ1_QCD", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_QCD")[ana.tx.getBranchLazy<int>("allHad_FJ1_commonFJIdxs")]);
            if (nFJ > 2) ana.tx.setBranch<float>("allHad_FJ2_QCD", ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_QCD")[ana.tx.getBranchLazy<int>("allHad_FJ2_commonFJIdxs")]);
            if (nFJ > 0) ana.tx.setBranch<float>("allHad_FJ0_VMD", (ana.tx.getBranchLazy<float>("allHad_FJ0_Xqq") + ana.tx.getBranchLazy<float>("allHad_FJ0_Xcc") + ana.tx.getBranchLazy<float>("allHad_FJ0_Xbb")) / (ana.tx.getBranchLazy<float>("allHad_FJ0_Xqq") + ana.tx.getBranchLazy<float>("allHad_FJ0_Xcc") + ana.tx.getBranchLazy<float>("allHad_FJ0_Xbb") + ana.tx.getBranchLazy<float>("allHad_FJ0_QCD")));
            if (nFJ > 1) ana.tx.setBranch<float>("allHad_FJ1_VMD", (ana.tx.getBranchLazy<float>("allHad_FJ1_Xqq") + ana.tx.getBranchLazy<float>("allHad_FJ1_Xcc") + ana.tx.getBranchLazy<float>("allHad_FJ1_Xbb")) / (ana.tx.getBranchLazy<float>("allHad_FJ1_Xqq") + ana.tx.getBranchLazy<float>("allHad_FJ1_Xcc") + ana.tx.getBranchLazy<float>("allHad_FJ1_Xbb") + ana.tx.getBranchLazy<float>("allHad_FJ1_QCD")));
            if (nFJ > 2) ana.tx.setBranch<float>("allHad_FJ2_VMD", (ana.tx.getBranchLazy<float>("allHad_FJ2_Xqq") + ana.tx.getBranchLazy<float>("allHad_FJ2_Xcc") + ana.tx.getBranchLazy<float>("allHad_FJ2_Xbb")) / (ana.tx.getBranchLazy<float>("allHad_FJ2_Xqq") + ana.tx.getBranchLazy<float>("allHad_FJ2_Xcc") + ana.tx.getBranchLazy<float>("allHad_FJ2_Xbb") + ana.tx.getBranchLazy<float>("allHad_FJ2_QCD")));

            // Compute the best VVV invariant mass estimator
            LV allHad_VVV_mSD_p4;
            if (nFJ > 0) allHad_VVV_mSD_p4 += ana.tx.getBranchLazy<vector<LV>>("allHad_fatjets_mSD_p4")[0];
            if (nFJ > 1) allHad_VVV_mSD_p4 += ana.tx.getBranchLazy<vector<LV>>("allHad_fatjets_mSD_p4")[1];
            if (nFJ > 2) allHad_VVV_mSD_p4 += ana.tx.getBranchLazy<vector<LV>>("allHad_fatjets_mSD_p4")[2];

            // Fill some event level variables
            ana.tx.setBranch<float>("allHad_mVVV", allHad_VVV_mSD_p4.mass());
            ana.tx.setBranch<float>("allHad_ptVVV", allHad_VVV_mSD_p4.pt());

            if (nFJ > 1)
            {
                ana.tx.setBranch<float>("allHad_FJ01_dPhi"   , RooUtil::Calc::DeltaPhi   (ana.tx.getBranchLazy<LV>("allHad_FJ0_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ1_mSD_p4")));
                ana.tx.setBranch<float>("allHad_FJ01_dEta"   , RooUtil::Calc::DeltaEta   (ana.tx.getBranchLazy<LV>("allHad_FJ0_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ1_mSD_p4")));
                ana.tx.setBranch<float>("allHad_FJ01_dR"     , RooUtil::Calc::DeltaR     (ana.tx.getBranchLazy<LV>("allHad_FJ0_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ1_mSD_p4")));
                ana.tx.setBranch<float>("allHad_FJ01_pPRel"  , RooUtil::Calc::pPRel      (ana.tx.getBranchLazy<LV>("allHad_FJ0_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ1_mSD_p4")));
                ana.tx.setBranch<float>("allHad_FJ01_dPtFrac", RooUtil::Calc::DeltaPtFrac(ana.tx.getBranchLazy<LV>("allHad_FJ0_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ1_mSD_p4")));
            }

            if (nFJ > 2)
            {
                ana.tx.setBranch<float>("allHad_FJ02_dPhi"   , RooUtil::Calc::DeltaPhi   (ana.tx.getBranchLazy<LV>("allHad_FJ0_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ2_mSD_p4")));
                ana.tx.setBranch<float>("allHad_FJ02_dEta"   , RooUtil::Calc::DeltaEta   (ana.tx.getBranchLazy<LV>("allHad_FJ0_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ2_mSD_p4")));
                ana.tx.setBranch<float>("allHad_FJ02_dR"     , RooUtil::Calc::DeltaR     (ana.tx.getBranchLazy<LV>("allHad_FJ0_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ2_mSD_p4")));
                ana.tx.setBranch<float>("allHad_FJ02_pPRel"  , RooUtil::Calc::pPRel      (ana.tx.getBranchLazy<LV>("allHad_FJ0_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ2_mSD_p4")));
                ana.tx.setBranch<float>("allHad_FJ02_dPtFrac", RooUtil::Calc::DeltaPtFrac(ana.tx.getBranchLazy<LV>("allHad_FJ0_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ2_mSD_p4")));

                ana.tx.setBranch<float>("allHad_FJ12_dPhi"   , RooUtil::Calc::DeltaPhi   (ana.tx.getBranchLazy<LV>("allHad_FJ1_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ2_mSD_p4")));
                ana.tx.setBranch<float>("allHad_FJ12_dEta"   , RooUtil::Calc::DeltaEta   (ana.tx.getBranchLazy<LV>("allHad_FJ1_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ2_mSD_p4")));
                ana.tx.setBranch<float>("allHad_FJ12_dR"     , RooUtil::Calc::DeltaR     (ana.tx.getBranchLazy<LV>("allHad_FJ1_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ2_mSD_p4")));
                ana.tx.setBranch<float>("allHad_FJ12_pPRel"  , RooUtil::Calc::pPRel      (ana.tx.getBranchLazy<LV>("allHad_FJ1_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ2_mSD_p4")));
                ana.tx.setBranch<float>("allHad_FJ12_dPtFrac", RooUtil::Calc::DeltaPtFrac(ana.tx.getBranchLazy<LV>("allHad_FJ1_mSD_p4"), ana.tx.getBranchLazy<LV>("allHad_FJ2_mSD_p4")));
            }
            return true;

        }, UNITY);

    ana.cutflow.bookCutflows();

    return;
}

void Begin_allHad_VVVTree()
{
   // float wgt = get_weight();
    float wgt = 1.0;


    //vector branches
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

    ana.tx.createBranch<float>  ("allHad_FatJet_SF");
    
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
    ana.tx.createBranch<int>  ("allHad_NFatJet_loose_MD");
    ana.tx.createBranch<int>  ("allHad_NFatJet_medium_MD");
    ana.tx.createBranch<int>  ("allHad_NFatJet_tight_MD");
    ana.tx.createBranch<int>  ("allHad_FatJet_Class_2fj_MD");
    ana.tx.createBranch<vector<float>>  ("allHad_FatJet_Class_3fj_MD");
    ana.tx.createBranch<int>  ("allHad_FatJet_Class");
        
    ana.tx.createBranch<float>  ("allHad_WMatchedFJ_pt");
    ana.tx.createBranch<float>  ("allHad_WMatchedFJ_eta");
    ana.tx.createBranch<float>  ("allHad_WMatchedFJ_phi");
    ana.tx.createBranch<float>  ("allHad_WMatchedFJ_msoftdrop");
    ana.tx.createBranch<int>    ("allHad_WMatchedFJ_idx");
    ana.tx.createBranch<float>  ("allHad_WMatchedFJ_particleNet_W_MD");
    ana.tx.createBranch<float>  ("allHad_WUnmatchedFJ_pt");
    ana.tx.createBranch<float>  ("allHad_WUnmatchedFJ_eta");
    ana.tx.createBranch<float>  ("allHad_WUnmatchedFJ_phi");
    ana.tx.createBranch<float>  ("allHad_WUnmatchedFJ_msoftdrop");
    ana.tx.createBranch<int>    ("allHad_WUnmatchedFJ_idx");
    ana.tx.createBranch<float>  ("allHad_WUnmatchedFJ_particleNet_W_MD");
    
    //////////////////////////////////////////
    // PRESELECTION
    //////////////////////////////////////////

    //at this point we've already skimmed
    ana.cutflow.getCut("CommonCut");

    const int eft_reweighting_idx = ana.eft_reweighting_idx;
    std::cout << "eft index " << eft_reweighting_idx;
    ana.cutflow.addCutToLastActiveCut("allHad_EFT", [&, eft_reweighting_idx]() {
        ana.tx.setBranch<float>  ("allHad_fj_mVVV_reco_nomet_SD",   -999);
        ana.tx.setBranch<float>  ("allHad_fj_ptVVV_reco_nomet_SD",  -999);
        ana.tx.setBranch<float>  ("allHad_HT",   -999);
        ana.tx.setBranch<float>  ("allHad_WMatchedFJ_pt",   -999);
        ana.tx.setBranch<float>  ("allHad_WMatchedFJ_eta",   -999);
        ana.tx.setBranch<float>  ("allHad_WMatchedFJ_phi",   -999);
        ana.tx.setBranch<float>  ("allHad_WMatchedFJ_msoftdrop",   -999);
        ana.tx.setBranch<int>    ("allHad_WMatchedFJ_idx",   -999);
        ana.tx.setBranch<float>  ("allHad_WMatchedFJ_particleNet_W_MD",   -999);
        ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_pt",   -999);
        ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_eta",   -999);
        ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_phi",   -999);
        ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_msoftdrop",   -999);
        ana.tx.setBranch<int>    ("allHad_WUnmatchedFJ_idx",   -999);
        ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_particleNet_W_MD",   -999);
        return true;
        }, [&, eft_reweighting_idx]() { return  eft_reweighting_idx < 0 ? 1.0 : ana.tx.getBranch<float>("Common_genWeight") * ana.tx.getBranch<vector<float>>("Common_LHEReweightingWeight")[eft_reweighting_idx]; } );
    

    //Basic cut for everything going forward
    ana.cutflow.addCutToLastActiveCut("allHad_fixedHT", [&]() {
        
        
        float HT = 0;
        float HT_fj = 0 ;
        unsigned int nselect = 0;
        LorentzVector vvv_reco_fj_SD; 

        for( unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4").size(); i++){
            if(is_baseline_jet(i)){
                HT+= ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[i].Pt();
            }
        }

        for( unsigned int ij =0; ij < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); ij++  ){
            if(is_baseline_fatjet(ij, true, false)){
                HT += ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[ij].Pt();
                HT_fj += ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[ij].Pt();
                LorentzVector tmp_SD = RooUtil::Calc::getLV(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[ij].Pt(), 
                                                            ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[ij].Eta(), 
                                                            ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[ij].Phi(), 
                                                            ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[ij]);
                
                
                vvv_reco_fj_SD += tmp_SD;
                nselect ++;
            }
        }

        //want only events where the fatjets are all good
        //if( nselect != ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() ) return false;
        if( HT < 1100) return false;


        ana.tx.setBranch<float>  ("allHad_fj_mVVV_reco_nomet_SD",   vvv_reco_fj_SD.M());
        ana.tx.setBranch<float>  ("allHad_fj_ptVVV_reco_nomet_SD",  vvv_reco_fj_SD.Pt());
        ana.tx.setBranch<float>  ("allHad_HT",   HT);
        ana.tx.setBranch<float>  ("allHad_fj_HT",   HT_fj);
        
        if(nselect > 1){
            TLorentzVector fj1 = RooUtil::Calc::getTLV(RooUtil::Calc::getLV(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0].Pt(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0].Eta(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0].Phi(), ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0]));
            TLorentzVector fj2 = RooUtil::Calc::getTLV(RooUtil::Calc::getLV(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1].Pt(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1].Eta(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1].Phi(), ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1]));
            ana.tx.setBranch<float>  ("allHad_fj12_dPhi",  abs(fj1.DeltaPhi(fj2)));
            ana.tx.setBranch<float>  ("allHad_fj12_dEta",  abs( abs(fj1.Eta()) - abs(fj2.Eta()) ) );
            ana.tx.setBranch<float>  ("allHad_fj12_dR",    fj1.DeltaR(fj2));
        }
        else{
            ana.tx.setBranch<float>  ("allHad_fj12_dPhi",  -999);
            ana.tx.setBranch<float>  ("allHad_fj12_dEta",  -999);
            ana.tx.setBranch<float>  ("allHad_fj12_dR",    -999);
        }
        if(nselect > 2){
            TLorentzVector fj1 = RooUtil::Calc::getTLV(RooUtil::Calc::getLV(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0].Pt(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0].Eta(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[0].Phi(), ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0]));
            TLorentzVector fj2 = RooUtil::Calc::getTLV(RooUtil::Calc::getLV(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1].Pt(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1].Eta(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[1].Phi(), ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1]));
            TLorentzVector fj3 = RooUtil::Calc::getTLV(RooUtil::Calc::getLV(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[2].Pt(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[2].Eta(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[2].Phi(), ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[2]));
            ana.tx.setBranch<float>  ("allHad_fj23_dPhi",  abs(fj3.DeltaPhi(fj2)));
            ana.tx.setBranch<float>  ("allHad_fj23_dEta",  abs(abs(fj3.Eta()) - abs(fj2.Eta())));
            ana.tx.setBranch<float>  ("allHad_fj23_dR",    fj3.DeltaR(fj2));
            
            ana.tx.setBranch<float>  ("allHad_fj31_dPhi",  abs(fj3.DeltaPhi(fj1)));
            ana.tx.setBranch<float>  ("allHad_fj31_dEta",  abs(abs(fj3.Eta()) - abs(fj1.Eta())));
            ana.tx.setBranch<float>  ("allHad_fj31_dR",    fj3.DeltaR(fj1));
        }
        else{
            ana.tx.setBranch<float>  ("allHad_fj23_dPhi",  -999);
            ana.tx.setBranch<float>  ("allHad_fj23_dEta",  -999);
            ana.tx.setBranch<float>  ("allHad_fj23_dR",    -999);
            
            ana.tx.setBranch<float>  ("allHad_fj31_dPhi",  -999);
            ana.tx.setBranch<float>  ("allHad_fj31_dEta",  -999);
            ana.tx.setBranch<float>  ("allHad_fj31_dR",    -999);

        }

        return true;
        }, [&]() { return ana.tx.getBranch<float>("Common_event_puWeight")*ana.tx.getBranch<float>("Common_event_prefireWeight"); } );


    

    //////////////////////////////////////////
    // 2/3 tight fatjets
    //////////////////////////////////////////


    ana.cutflow.getCut("allHad_fixedHT");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_nob_medium", [&]() {
        if (ana.tx.getBranchLazy<int>("Common_nb_medium") > 0) return false;
        return true;
    }, [&]() { return 1; } );
            
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_tight_2j", [&]() {
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() !=2 ) return false;
        return true;
    }, [&]() { return 1; } );
    
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_tight_mSD", [&]() {
        if( ! (is_baseline_fatjet(0, true, true) && is_baseline_fatjet(1, true, true)) ) return false;
        return true;
    }, [&]() { return 1; } );
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_tight_1sttight", [&]() {
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[0] == 3 ) return true;
        return false;
    }, [&]() { return 1; } );

    ana.cutflow.addCutToLastActiveCut("allHad_2fj_tight", [&]() {
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[1] == 3 ) return true;
        return false;
    }, [&]() { return 1; } );

    ana.cutflow.addCutToLastActiveCut("allHad_ORTrigger_2fj", [&]() {
        return true;
        }, [&]() { return 1; } );



    ana.cutflow.getCut("allHad_2fj_tight_mSD");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_1med1tight", [&]() {
        if (ana.tx.getBranchLazy<int>("Common_nb_medium") > 0) return false;

        if( (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[0] == 3 && ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[1] == 2) 
         || (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[1] == 3 && ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[0] == 2)) 
            return true; 


        return false;
    }, [&]() { return 1; } );

    
    ana.cutflow.getCut("allHad_fixedHT");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_deepMDSR", [&]() {
        if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() !=2 ) return false;
        if( ! (is_baseline_fatjet(0, true, true) && is_baseline_fatjet(1, true, true)) ) return false;
        if( ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[0] < 0.806) return false;
        if( ana.tx.getBranchLazy<vector<float>>("Common_fatjet_deepMD_W")[1] < 0.806) return false;
        if (ana.tx.getBranchLazy<int>("Common_nb_medium") > 0) return false;
        return true;
    }, [&]() { return 1; } );



    ana.cutflow.getCut("allHad_fixedHT");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_ABCD", [&]() {

        //I want 2 fatjets, where both of them are tight
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() !=2 ) return false;
        
        // no b-jets
        if (ana.tx.getBranchLazy<int>("Common_nb_medium") > 0 ) return false;
        //baseline fatjets passing first pt and mSD cuts
        if( ! (is_baseline_fatjet(0, true, false) && is_baseline_fatjet(1, true, false)) ) return false;
        

        return true;
        }, [&]() { return 1; } );

    //////////////////////////////////////////
    // ABCD regions
    //////////////////////////////////////////
    ana.cutflow.getCut("allHad_2fj_ABCD");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_ABCD_A", [&]() {
        //signal region -- 2 tight, signal mSD
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[0] != 3 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[1] != 3 ) return false;

        if(  (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] <= 105.)
          && (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] <= 105.))
          return true;

        return false;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_2fj_ABCD");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_ABCD_B", [&]() {
        //1st jet medium
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[0] != 2 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[1] != 3 ) return false;

        if(  (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] <= 105.)
          && (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] <= 105.))
          return true;

        return false;
        }, [&]() { return 1; } );
   
    ana.cutflow.getCut("allHad_2fj_ABCD");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_ABCD_C", [&]() {
        //2nd jet low mSD
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[0] != 3 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[1] != 3 ) return false;

        if(  (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] <= 105.)
          && (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] > 40. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] < 65.))
          return true;

        return false;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_2fj_ABCD");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_ABCD_D", [&]() {
        //2nd jet low mSD & 1st jet medium
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[0] != 2 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[1] != 3 ) return false;

        if(  (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] <= 105.)
          && (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] > 40. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] < 65.))
          return true;

        return false;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_2fj_ABCD");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_ABCD_E", [&]() {
        //2nd jet low mSD
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[0] != 3 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[1] != 3 ) return false;

        if(  (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] <= 105.)
          && (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] > 105. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] < 150.))
          return true;

        return false;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_2fj_ABCD");
    ana.cutflow.addCutToLastActiveCut("allHad_2fj_ABCD_F", [&]() {
        //2nd jet low mSD & 1st jet medium
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[0] != 2 ) return false;
        if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[1] != 3 ) return false;

        if(  (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] <= 105.)
          && (ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] > 105. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] < 150.))
          return true;

        return false;
        }, [&]() { return 1; } );
    
    
    
    //this is just for W+jets, there should be one fatjet matched to a W, one not
    ana.cutflow.getCut("allHad_ORTrigger_2fj");
    ana.cutflow.addCutToLastActiveCut("allHad_ORTrigger_matchW", [&]() {
        int nW = 0;
        int iMatch = -999;
        int iUnmatch = -999;
        for(int i=0; i<ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid").size(); i++){
            
            if(abs (ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[i]) == 24){
                for(int j=0; j<ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); j++){
                    //find fatjet within dR < 0.8 from the truth W
                    if( abs(RooUtil::Calc::DeltaR( ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i], ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[j])) < 0.8)
                        iMatch = j;
                    else
                        iUnmatch = j;
                }

            }

        }

        //check that we found both a match and an unmatched
        if( iMatch != -999 && iUnmatch != -999){
            
            ana.tx.setBranch<int>    ("allHad_WMatchedFJ_idx",   iMatch);
            ana.tx.setBranch<float>  ("allHad_WMatchedFJ_pt",    ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[iMatch].Pt());
            ana.tx.setBranch<float>  ("allHad_WMatchedFJ_eta",   ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[iMatch].Eta());
            ana.tx.setBranch<float>  ("allHad_WMatchedFJ_phi",   ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[iMatch].Phi());
            ana.tx.setBranch<float>  ("allHad_WMatchedFJ_msoftdrop",   ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop")[iMatch]);
            ana.tx.setBranch<float>  ("allHad_WMatchedFJ_particleNet_W_MD",   ana.tx.getBranch<vector<float>>("Common_fatjet_particleNetMD_W")[iMatch]);
            
            ana.tx.setBranch<int>    ("allHad_WUnmatchedFJ_idx",   iUnmatch);
            ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_pt",    ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[iUnmatch].Pt());
            ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_eta",   ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[iUnmatch].Eta());
            ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_phi",   ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[iUnmatch].Phi());
            ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_msoftdrop",   ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop")[iUnmatch]);
            ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_particleNet_W_MD",   ana.tx.getBranch<vector<float>>("Common_fatjet_particleNetMD_W")[iUnmatch]);
            return true;
        }
        else{
            //std::cout << "alert!! i didnt find both jets :( I have iMatch " << iMatch << " and iUnmatch " << iUnmatch << std::endl;
            return false;
        }


        }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_2fj_ABCD"); //this cut has 2 good fatjets, 
    ana.cutflow.addCutToLastActiveCut("allHad_ORTrigger_matchW_VR", [&]() {
        
        //jets also pass mSD cut
        if( ! (is_baseline_fatjet(0, true, true) && is_baseline_fatjet(1, true, true)) ) return false;
        int nW = 0;

        int iMatch = -999;
        int iUnmatch = -999;
        for(int i=0; i<ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid").size(); i++){
            
            if(abs (ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[i]) == 24){
                for(int j=0; j<ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); j++){
                    //find fatjet within dR < 0.8 from the truth W
                    if( abs(RooUtil::Calc::DeltaR( ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i], ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[j])) < 0.8)
                        iMatch = j;
                    else
                        iUnmatch = j;
                }

            }

        }

        //check that we found both a match and an unmatched
        if( iMatch != -999 && iUnmatch != -999){

            if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[iMatch] != 3 || ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[iUnmatch] != 2)
            {
                //std::cout << "1st fatjet is not the tight one" << std::endl;
                return false;
            }
            
            ana.tx.setBranch<int>    ("allHad_WMatchedFJ_idx",   iMatch);
            ana.tx.setBranch<float>  ("allHad_WMatchedFJ_pt",    ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[iMatch].Pt());
            ana.tx.setBranch<float>  ("allHad_WMatchedFJ_eta",   ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[iMatch].Eta());
            ana.tx.setBranch<float>  ("allHad_WMatchedFJ_phi",   ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[iMatch].Phi());
            ana.tx.setBranch<float>  ("allHad_WMatchedFJ_msoftdrop",   ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop")[iMatch]);
            ana.tx.setBranch<float>  ("allHad_WMatchedFJ_particleNet_W_MD",   ana.tx.getBranch<vector<float>>("Common_fatjet_particleNetMD_W")[iMatch]);
            
            ana.tx.setBranch<int>    ("allHad_WUnmatchedFJ_idx",   iUnmatch);
            ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_pt",    ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[iUnmatch].Pt());
            ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_eta",   ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[iUnmatch].Eta());
            ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_phi",   ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[iUnmatch].Phi());
            ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_msoftdrop",   ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop")[iUnmatch]);
            ana.tx.setBranch<float>  ("allHad_WUnmatchedFJ_particleNet_W_MD",   ana.tx.getBranch<vector<float>>("Common_fatjet_particleNetMD_W")[iUnmatch]);
            //
            
            //std::cout << "Saving event!" << std::endl;
            return true;
        }
        else{
            //std::cout << "alert!! i didnt find both jets :( I have iMatch " << iMatch << " and iUnmatch " << iUnmatch << std::endl;
            return false;
        }


        }, [&]() { return 1; } );
    
   
    /* 
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
    */
    //////////////////////////////////////////
    // 3 Fatjets
    //////////////////////////////////////////
    ana.cutflow.getCut("allHad_fixedHT");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj", [&]() {
        
        //I want 3 fatjets, where all of them are tight
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() < 3 ) return false;

        //baseline fatjets passing first pt, don't cut on mSD cut yet
        if( ! (is_baseline_fatjet(0, true, false) && is_baseline_fatjet(1, true, false) && is_baseline_fatjet(2, true, false)) ) return false;

        return true;
        }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_3fj");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_withB", [&]() {
        if (ana.tx.getBranchLazy<int>("Common_nb_medium") > 0) return true;
        return false;
        }, [&]() { return 1; } );


    

    //3 tight fatjets
    ana.cutflow.getCut("allHad_3fj_withB");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_3tight", [&]() {
        if ( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[0] != 3) return false;
        if ( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[1] != 3) return false;
        if ( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[2] != 3) return false;
        return true;
    }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_3fj_3tight");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_1outsideMSD", [&]() {
        
        int n_fail = 0;
        int n_pass = 0;

        for(unsigned int i=0; i<3; i++)
        {
            if(is_baseline_fatjet(i, true, true)) n_pass++;
            else n_fail++;
        } 

        if( n_fail == 1 && n_pass == 2) return true;
        else return false;
    }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_3fj_3tight");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_2outsideMSD", [&]() {
        
        int n_fail = 0;
        int n_pass = 0;

        for(unsigned int i=0; i<3; i++)
        {
            if(is_baseline_fatjet(i, true, true)) n_pass++;
            else n_fail++;
        } 

        if( n_fail == 2 && n_pass == 1) return true;
        else return false;
    }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_3fj_3tight");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_signalMSD", [&]() {
        
        int n_fail = 0;
        int n_pass = 0;

        for(unsigned int i=0; i<3; i++)
        {
            if(is_baseline_fatjet(i, true, true)) n_pass++;
            else n_fail++;
        } 

        if(  n_pass == 3) return true;
        else return false;
    }, [&]() { return 1; } );

    //3 tight fatjets
    ana.cutflow.getCut("allHad_3fj_withB");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_3passmSD", [&]() {
        if( (is_baseline_fatjet(0, true, true) && is_baseline_fatjet(1, true, true) && is_baseline_fatjet(2, true, true)) ) return true;
        return false;
    }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_3fj_3passmSD");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_2tight1med", [&]() {
        
        int n_fail = 0;
        int n_pass = 0;

        for(unsigned int i=0; i<3; i++)
        {
            if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] == 3 ) n_pass++;
            else if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] == 2 ) n_fail++;
        } 

        if( n_fail == 1 && n_pass == 2) return true;
        else return false;
    }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_3fj_3passmSD");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_1tight2med", [&]() {
        
        int n_fail = 0;
        int n_pass = 0;

        for(unsigned int i=0; i<3; i++)
        {
            if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] == 3 ) n_pass++;
            else if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] == 2 ) n_fail++;
        } 

        if( n_fail == 2 && n_pass == 1) return true;
        else return false;
    }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_3fj_3passmSD");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_signal3tight", [&]() {
        
        int n_fail = 0;
        int n_pass = 0;

        for(unsigned int i=0; i<3; i++)
        {
            if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] == 3 ) n_pass++;
            else if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] == 2 ) n_fail++;
        } 

        if( n_fail == 0 && n_pass == 3) return true;
        else return false;
    }, [&]() { return 1; } );

    
    
    //ATLEAST    
    //at least 1 fails mSD
    ana.cutflow.getCut("allHad_3fj_3tight");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_atleast1failmSD", [&]() {
        
        int n_fail = 0;
        int n_pass = 0;

        for(unsigned int i=0; i<3; i++)
        {
            if(is_baseline_fatjet(i, true, true)) n_pass++;
            else n_fail++;
        } 

        if( n_fail+n_pass == 3 && n_pass >= 1) return true;
        else return false;
    }, [&]() { return 1; } );

    //at least 1 is med-not-tight
    ana.cutflow.getCut("allHad_3fj_3passmSD");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_atleast1failtight", [&]() {
        
        int n_fail = 0;
        int n_pass = 0;

        for(unsigned int i=0; i<3; i++)
        {
            if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] == 3 ) n_pass++;
            else if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] == 2 ) n_fail++;
        } 

        if( n_fail+n_pass == 3 && n_pass >= 1) return true;
        else return false;
    }, [&]() { return 1; } );

    //at least 1 medium-not-tight, inclusive mSD range
    ana.cutflow.getCut("allHad_3fj_withB");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_atleast1MED_incMSD", [&]() {
        int n_fail = 0;
        int n_pass = 0;

        for(unsigned int i=0; i<3; i++)
        {
            if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] == 3 ) n_pass++;
            else if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] == 2 ) n_fail++;
        } 

        //want 3 at least medium, and at least 1 medium-not-tight
        if( n_pass+n_fail == 3 && n_fail >=1 ) return true;
        else return false;
    }, [&]() { return 1; } );



    //at least 1 fails something
    ana.cutflow.getCut("allHad_3fj_withB");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_atleastfailsomething", [&]() {
        int n_fail = 0;
        int n_pass = 0;

        for(unsigned int i=0; i<3; i++)
        {
            if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] == 3  && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i] < 105.) n_pass++;
            else if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] >= 2 ) n_fail++;
        } 

        //want 3 at least medium, and at least 1 medium-not-tight
        if( n_pass+n_fail == 3 && n_fail >=1 ) return true;
        else return false;
    }, [&]() { return 1; } );

    //at least 1 fails something -- 3rd must be signal
    ana.cutflow.getCut("allHad_3fj_withB");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_atleastfailsomething_3rdsignal", [&]() {
        int n_fail = 0;
        int n_pass = 0;
        bool signal3rd = false;

        for(unsigned int i=0; i<2; i++)
        {
            if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] == 3  && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i] < 105.) n_pass++;
            else if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[i] >= 2 ) n_fail++;
        } 

         if( ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[2] == 3  && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[2] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[2] < 105.) signal3rd = true;



        //want 3 at least medium, and at least 1 medium-not-tight
        if( n_pass+n_fail == 2 && n_fail >=1 && signal3rd) return true;
        else return false;
    }, [&]() { return 1; } );



    /*
    ana.cutflow.getCut("allHad_3fj_withB");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_withB_class2", [&]() {
        if ( std::find(ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").begin(), ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end(), 2) != ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end() ) return true;
        return false;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_3fj_withB");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_withB_class3", [&]() {
        if ( std::find(ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").begin(), ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end(), 3) != ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end() ) return true;
        return false;
        }, [&]() { return 1; } );
            
    ana.cutflow.getCut("allHad_3fj_withB");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_withB_class8", [&]() {
        if ( std::find(ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").begin(), ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end(), 8) != ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end() ) return true;
        return false;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_3fj_withB");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_withB_class9", [&]() {
        if ( std::find(ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").begin(), ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end(), 9) != ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end() ) return true;
        return false;
        }, [&]() { return 1; } );


    ana.cutflow.getCut("allHad_3fj");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_noB", [&]() {
        if (ana.tx.getBranchLazy<int>("Common_nb_medium") > 0) return false;
        return true;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_3fj_noB");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_noB_class2", [&]() {
        if ( std::find(ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").begin(), ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end(), 2) != ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end() ) return true;
        return false;
        }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_3fj_noB");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_noB_class3", [&]() {
        if ( std::find(ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").begin(), ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end(), 3) != ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end() ) return true;
        return false;
        }, [&]() { return 1; } );
    
    ana.cutflow.getCut("allHad_3fj_noB");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_noB_class8", [&]() {
        if ( std::find(ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").begin(), ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end(), 8) != ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end() ) return true;
        return false;
        }, [&]() { return 1; } );

    ana.cutflow.getCut("allHad_3fj_noB");
    ana.cutflow.addCutToLastActiveCut("allHad_3fj_noB_class9", [&]() {
        if ( std::find(ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").begin(), ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end(), 9) != ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_Class_3fj_MD").end() ) return true;
        return false;
        }, [&]() { return 1; } );
        */
        // int nMedium = 0;
        // int nTight = 0;
        // //3 tight fatjets
        // for(unsigned int ij = 0; ij < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); ij++)
        // {
        //     if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[ij] >= 2) nMedium++;
        //     if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[ij] >= 3) nTight++;
        // }
        // //std::cout << " i got nmedium " << nMedium << " and nTight " << nTight << " in jets: " << ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() << std::endl;
        // //want at least 1 tight jet, all 3 pass medium
        // //if(nTight >= 3) return true;
        // if(nTight >= 1 && nMedium >= 3) return true;




    
    // ana.cutflow.getCut("allHad_3fj_tight");
    // ana.cutflow.addCutToLastActiveCut("allHad_ORTrigger_3fj", [&]() {
    //     if (ana.tx.getBranchLazy<int>("Common_nb_medium") > 0) return false;
    //     return true;
    //     }, [&]() { return 1; } );
    
    // ana.cutflow.getCut("allHad_3fj_tight");
    // ana.cutflow.addCutToLastActiveCut("allHad_CRb_3fj", [&]() {
    //     if (ana.tx.getBranchLazy<int>("Common_nb_medium") < 1 ) return false;
    //     return true;
    //     }, [&]() { return 1; } );
   
   
    
    vector<float> SR_bins{0,1000,1500, 3500, 8000};

    RooUtil::Histograms hists_allHad;
    
    
    
    //single value histograms
    hists_allHad.addHistogram("NJets"            ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt").size()    ; } );
    hists_allHad.addHistogram("NLeps"            ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size()   ; } );
    hists_allHad.addHistogram("NGenFatJets"       ,  10,   0,   10, [&]() { return      ana.tx.getBranchLazy<vector<LorentzVector>>("Common_genFatJet_p4").size()   ; } );
    hists_allHad.addHistogram("NFatJets"         ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<float>>("allHad_FatJet_pt").size() ; } );
    hists_allHad.addHistogram("NW"               ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_n_W") ; } );
    //hists_allHad.addHistogram("gen_vvvdecay_n"               ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_idx").size() ; } );
    hists_allHad.addHistogram("n_b_loose"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_nb_loose") ; } );
    hists_allHad.addHistogram("n_b_medium"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_nb_medium") ; } );
    hists_allHad.addHistogram("n_b_tight"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_nb_tight") ; } );

    hists_allHad.addHistogram("nFatJet_loose"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_NFatJet_loose") ; } );
    hists_allHad.addHistogram("nFatJet_medium"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_NFatJet_medium") ; } );
    hists_allHad.addHistogram("nFatJet_tight"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_NFatJet_tight") ; } );  
    
    //hists_allHad.addHistogram("nFatJet_loose_MD"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_NFatJet_loose_MD") ; } );
    //hists_allHad.addHistogram("nFatJet_medium_MD"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_NFatJet_medium_MD") ; } );
   // hists_allHad.addHistogram("nFatJet_tight_MD"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_NFatJet_tight_MD") ; } );  
    
    hists_allHad.addHistogram("FatJet_Class"                 ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_FatJet_Class") ; } );  
    hists_allHad.addHistogram("FatJet_Class_2fj_MD"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("allHad_FatJet_Class_2fj_MD") ; } ); 
    hists_allHad.addVecHistogram("FatJet_Class_3fj_MD"          ,  10,   0,    10, [&]() { return      ana.tx.getBranch<vector<float>>("allHad_FatJet_Class_3fj_MD") ; } ); 


    hists_allHad.addHistogram("MET"              ,  40,   0,    800, [&]() { return    ana.tx.getBranch<LorentzVector>  ("Common_met_p4").Pt(); } );

    hists_allHad.addHistogram("MET_phi"              ,  40,   -4,    4, [&]() { return    ana.tx.getBranch<LorentzVector>  ("Common_met_p4").Phi(); } );
    hists_allHad.addHistogram("HT"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.addHistogram("HT_wide"               ,  140,   0,    14000, [&]() { return    ana.tx.getBranch<float>  ("allHad_HT"); } );
    
    vector<float> HT_bin0{0,1100,2000,2500,14000};
    hists_allHad.addHistogram("HT_bin0"             , HT_bin0, [&]() { return    ana.tx.getBranch<float>  ("allHad_HT"); } );
    
    hists_allHad.addHistogram("HT_fj"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_HT"); } );
    //hists_allHad.addHistogram("ST_fj"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ST"); } );
    hists_allHad.addHistogram("mVVV_reco_nomet_fj_SD"       ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco_nomet_SD"); } );
    hists_allHad.addHistogram("ptVVV_reco_nomet_fj_SD"       ,  8,   0,    800, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco_nomet_SD"); } );
    
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


    
    // hists_allHad.addHistogram("jet12_mass"          ,  60,   0,    500, [&]() { return  ana.tx.getBranch<float>("allHad_j12_mass") ; } );
    // hists_allHad.addHistogram("jet23_mass"          ,  60,   0,    500, [&]() { return  ana.tx.getBranch<float>("allHad_j23_mass") ; } );
    // hists_allHad.addHistogram("jet31_mass"          ,  60,   0,    500, [&]() { return  ana.tx.getBranch<float>("allHad_j31_mass") ; } );
    
    hists_allHad.addHistogram("FatJet_pt_0"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4").size() > 0) ? ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[0].Pt() : -999 ; } );
    hists_allHad.addHistogram("FatJet_pt_1"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4").size() > 1) ? ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[1].Pt() : -999 ; } );
    hists_allHad.addHistogram("FatJet_pt_2"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4").size() > 2) ? ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[2].Pt() : -999 ; } );
    hists_allHad.addHistogram("FatJet_WMatch_pt"          ,  40,   0,    2000, [&]() { return      ana.tx.getBranch<float>("allHad_WMatchedFJ_pt")  ; } );
    hists_allHad.addHistogram("FatJet_WUnmatch_pt"          ,  40,   0,    2000, [&]() { return      ana.tx.getBranch<float>("allHad_WUnmatchedFJ_pt")  ; } );

    
    
    hists_allHad.addHistogram("FatJet_eta_0"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4").size() > 0) ? ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[0].Eta() : -999 ; } );
    hists_allHad.addHistogram("FatJet_eta_1"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4").size() > 1) ? ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[1].Eta() : -999 ; } );
    hists_allHad.addHistogram("FatJet_eta_2"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4").size() > 2) ? ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[2].Eta() : -999 ; } );
    hists_allHad.addHistogram("FatJet_WMatch_eta"          ,  20,   -3,    3, [&]() { return      ana.tx.getBranch<float>("allHad_WMatchedFJ_eta") ; } );
    hists_allHad.addHistogram("FatJet_WUnmatch_eta"          ,  20,   -3,    3, [&]() { return      ana.tx.getBranch<float>("allHad_WUnmatchedFJ_eta") ; } );
    
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
    
    
    hists_allHad.addHistogram("FatJet_tau21_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau21").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_tau21")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau21_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_tau21")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau21_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_tau21")[2] : -999 ; } );

    hists_allHad.addHistogram("FatJet_tau32_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_tau32")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau32_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_tau32")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau32_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_tau32")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_deepMD_W_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_W").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_W")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_deepMD_W_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_W").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_W")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_deepMD_W_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_W").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_W")[2] : -999 ; } );
    
    
    
    hists_allHad.addHistogram("FatJet_deepMD_Z_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_W").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_W")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_deepMD_Z_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_Z").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_W")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_deepMD_Z_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_Z").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_W")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_deepMD_T_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_T").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_T")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_deepMD_T_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_T").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_T")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_deepMD_T_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_T").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_deepMD_T")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_particleNet_W_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNet_W_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNet_W_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_particleNet_Z_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNet_Z_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_Z").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNet_Z_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_Z").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_particleNet_T_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_T").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_T")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNet_T_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_T").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_T")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNet_T_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_T").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_T")[2] : -999 ; } );
            
    
    hists_allHad.addHistogram("FatJet_particleNetMD_W_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNetMD_W")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNetMD_W_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNetMD_W")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNetMD_W_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNetMD_W")[2] : -999 ; } );
    hists_allHad.addHistogram("FatJet_WMatch_particleNetMD_W"          ,  30,   0,    1, [&]() { return   ana.tx.getBranch<float>("allHad_WMatchedFJ_particleNet_W_MD") ; } );
    hists_allHad.addHistogram("FatJet_WUnmatch_particleNetMD_W"          ,  30,   0,    1, [&]() { return   ana.tx.getBranch<float>("allHad_WUnmatchedFJ_particleNet_W_MD") ; } );
    


    hists_allHad.addHistogram("FatJet_msoftdrop_0"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_msoftdrop_1"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_msoftdrop_2"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop")[2] : -999 ; } );
    hists_allHad.addHistogram("FatJet_WMatch_msoftdrop"          ,  40,   0,    200, [&]() { return  ana.tx.getBranch<float>("allHad_WMatchedFJ_msoftdrop"); } );
    hists_allHad.addHistogram("FatJet_WUnmatch_msoftdrop"          ,  40,   0,    200, [&]() { return  ana.tx.getBranch<float>("allHad_WUnmatchedFJ_msoftdrop") ; } );
    
    hists_allHad.addHistogram("FatJet_WMatch_idx"          ,  3,   0,    3, [&]() { return  ana.tx.getBranch<float>("allHad_WMatchedFJ_idx")  ; } );
    hists_allHad.addHistogram("FatJet_WUnmatch_idx"          ,  3,   0,    3, [&]() { return  ana.tx.getBranch<float>("allHad_WUnmatchedFJ_idx")  ; } );
    
    
    //ABCD Method?
    hists_allHad.add2DHistogram("mSD_0",  10,   40,     150,  "mSD_1",  10,   40,     150,   [&]() { return ana.tx.getBranch<vector<float>>  ("Common_fatjet_msoftdrop")[0];}, [&]() { return ana.tx.getBranch<vector<float>>  ("Common_fatjet_msoftdrop")[1]; } );
    //hists_allHad.add2DHistogram("mSD_0_high", 10,   105,    150, "mSD_1_high", 10,   105,    150, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[0];}, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[1]; } );
    //hists_allHad.add2DHistogram("mSD_0_SR",   10,   65,     105, "mSD_1_SR",   10,   65,     105, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[0];}, [&]() { return ana.tx.getBranch<vector<float>>  ("allHad_FatJet_msoftdrop")[1]; } );

    hists_allHad.add2DHistogram("WTag_0",     10,   0.5,     1, "WTag_1",      10,  0.5,     1, [&]() { return ana.tx.getBranch<vector<float>>  ("Common_fatjet_particleNetMD_W")[0];}, [&]() { return ana.tx.getBranch<vector<float>>  ("Common_fatjet_particleNetMD_W")[1]; } );
    hists_allHad.add2DHistogram("WTag_0",     10,   0.5,     1, "mSD_0",       20,  40,     150, [&]() { return ana.tx.getBranch<vector<float>>  ("Common_fatjet_particleNetMD_W")[0];}, [&]() { return ana.tx.getBranch<vector<float>>  ("Common_fatjet_msoftdrop")[0]; } );
    hists_allHad.add2DHistogram("WTag_1",     10,   0.5,     1, "mSD_1",       20,  40,     150, [&]() { return ana.tx.getBranch<vector<float>>  ("Common_fatjet_particleNetMD_W")[1];}, [&]() { return ana.tx.getBranch<vector<float>>  ("Common_fatjet_msoftdrop")[1]; } );
    hists_allHad.add2DHistogram("WTag_0",     10,   0.5,     1, "mSD_1",       20,  40,     150, [&]() { return ana.tx.getBranch<vector<float>>  ("Common_fatjet_particleNetMD_W")[0];}, [&]() { return ana.tx.getBranch<vector<float>>  ("Common_fatjet_msoftdrop")[1]; } );
    hists_allHad.add2DHistogram("WTag_1",     10,   0.5,     1, "mSD_0",       20,  40,     150, [&]() { return ana.tx.getBranch<vector<float>>  ("Common_fatjet_particleNetMD_W")[1];}, [&]() { return ana.tx.getBranch<vector<float>>  ("Common_fatjet_msoftdrop")[0]; } );


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
    
    ana.cutflow.bookHistogramsForCutAndBelow(hists_allHad, "allHad_fixedHT");

    

}

void Begin_1L_VVVTree()
{

    std::cout << "running 1 l tree"<< std::endl;
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
    ana.tx.createBranch<int>  ("allHad_NFatJet_loose_MD");
    ana.tx.createBranch<int>  ("allHad_NFatJet_medium_MD");
    ana.tx.createBranch<int>  ("allHad_NFatJet_tight_MD");
    ana.tx.createBranch<int>  ("allHad_FatJet_Class_MD");
    ana.tx.createBranch<int>  ("allHad_FatJet_Class");
    
    
    // Single var branches
    ana.tx.createBranch<float>  ("allHad_mindPhi_MetFJ");
    ana.tx.createBranch<float>  ("allHad_genHT");
    ana.tx.createBranch<float>  ("allHad_mVVV");
    ana.tx.createBranch<float>  ("allHad_HT");
    ana.tx.createBranch<float>  ("allHad_HT_nolep");
    ana.tx.createBranch<float>  ("allHad_HTMET");
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
    ana.tx.createBranch<float>  ("allHad_fj_mVVV_reco_nomet_nolep_SD");
    ana.tx.createBranch<float>  ("allHad_fj_ptVVV_reco_nomet_nolep_SD");
    ana.tx.createBranch<float>  ("allHad_fj_mVVV_reco_SD");
    ana.tx.createBranch<float>  ("allHad_fj_ptVVV_reco_SD");
    
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
    ana.tx.createBranch<float>  ("allHad_dPhi_lep_jet");
    
    
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
    const int eft_reweighting_idx_1l = ana.eft_reweighting_idx;
    
    std::cout << "eft index " << eft_reweighting_idx_1l;
    std::cout << "eft index " << eft_reweighting_idx_1l;
    
    
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("oneLep_EFT", [&, eft_reweighting_idx_1l]() {
        ana.tx.setBranch<float>  ("allHad_fj_mVVV_reco_nomet_SD",   -999);
        ana.tx.setBranch<float>  ("allHad_fj_ptVVV_reco_nomet_SD",  -999);
        ana.tx.setBranch<float>  ("allHad_HT",   -999);
        ana.tx.setBranch<float>  ("allHad_fj_HT",   -999);
        ana.tx.setBranch<float>  ("allHad_fj_mVVV_reco_SD",   -999);
        ana.tx.setBranch<float>  ("allHad_fj_ptVVV_reco_SD",  -999);
        ana.tx.setBranch<float>  ("allHad_HTMET",   -999);
        ana.tx.setBranch<float>  ("allHad_fj_mVVV_reco_nomet_nolep_SD",   -999);
        ana.tx.setBranch<float>  ("allHad_fj_ptVVV_reco_nomet_nolep_SD",  -999);
        ana.tx.setBranch<float>  ("allHad_HT_nolep",   -999);
        ana.tx.setBranch<float>  ("allHad_dPhi_lep_jet",   -999);
        return true;
        //}, [&, eft_reweighting_idx_1l]() { return  eft_reweighting_idx_1l < 0 ? 1.0 : ana.tx.getBranch<float>("Common_genWeight") * ana.tx.getBranch<vector<float>>("Common_LHEReweightingWeight")[eft_reweighting_idx_1l]; } );
        }, [&]() { return 1.0; } ); 
    
    ana.cutflow.addCutToLastActiveCut("oneL_fixedHT", [&]() {
        //std::cout << "PDGID " << abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) << " ele trigger? " <<  ana.tx.getBranchLazy<bool>("Common_HLT_Ele32_WPTight") << " Mu trigger? " << ana.tx.getBranchLazy<bool>("Common_HLT_IsoMu24")  << " overall: " << ( ( abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 11 &&  ana.tx.getBranchLazy<bool>("Common_HLT_Ele32_WPTight") ) || ( abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 13 &&  ana.tx.getBranchLazy<bool>("Common_HLT_IsoMu24") ))<< std::endl;
        
        //if (ana.tx.getBranchLazy<bool>("Common_HLT_Ele32_WPTight") && ana.tx.getBranchLazy<bool>("Common_HLT_IsoMu24") ) std::cout << "SO MANY TRIGGERS" << std::endl;
        //this cut should have already been made but making it again
        if(ana.tx.getBranchLazy<int>("Common_isData"))
        {
            bool passEle = ana.input_file_list_tstring.Contains("EGamma")      &&  abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 11 && ana.tx.getBranchLazy<bool>("Common_HLT_Ele32_WPTight");
            bool passMu  = ana.input_file_list_tstring.Contains("SingleMuon")  &&  abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 13 && ana.tx.getBranchLazy<bool>("Common_HLT_IsoMu24");
            if( !(passEle || passMu))
            {
                std::cout << "vetoing an event" << std::endl;
                return false;
            }

        }

        //
        //std::cout << "Pass ele? " << passEle << " pass Mu? " << passMu << std::endl;
        //if( ! ( ( abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 11 &&  ana.tx.getBranchLazy<bool>("Common_HLT_Ele32_WPTight") ) || ( abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 13 &&  ana.tx.getBranchLazy<bool>("Common_HLT_IsoMu24") )) ) return false;
        
        float HT = 0;
        float HT_fj = 0 ;
        unsigned int nselect = 0;
        LorentzVector vvv_reco_fj_SD; 

        for( unsigned int i=0; i < ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4").size(); i++){
            if(is_baseline_jet(i)){
                HT+= ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[i].Pt();
            }
        }

        for( unsigned int ij =0; ij < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); ij++  ){
            if(is_baseline_fatjet(ij, false, true)){
                HT += ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[ij].Pt();
                HT_fj += ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[ij].Pt();
                LorentzVector tmp_SD = RooUtil::Calc::getLV(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[ij].Pt(), 
                                                            ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[ij].Eta(), 
                                                            ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[ij].Phi(), 
                                                            ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[ij]);
                
                
                vvv_reco_fj_SD += tmp_SD;
                nselect ++;
            }
        }
        
        //want only events where the fatjets are all good
        if( nselect != ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() ) return false;
        //if( HT < 1100) return false;        
        ana.tx.setBranch<float>  ("allHad_fj_mVVV_reco_nomet_nolep_SD",   vvv_reco_fj_SD.M());
        ana.tx.setBranch<float>  ("allHad_fj_ptVVV_reco_nomet_nolep_SD",  vvv_reco_fj_SD.Pt());
        ana.tx.setBranch<float>  ("allHad_HT_nolep",   HT);
        ana.tx.setBranch<float>  ("allHad_fj_HT",   HT_fj);

        vvv_reco_fj_SD +=  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0];
        HT +=  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt();

        ana.tx.setBranch<float>  ("allHad_fj_mVVV_reco_nomet_SD",   vvv_reco_fj_SD.M());
        ana.tx.setBranch<float>  ("allHad_fj_ptVVV_reco_nomet_SD",  vvv_reco_fj_SD.Pt());
        ana.tx.setBranch<float>  ("allHad_HT",   HT);
       
       
        
        vvv_reco_fj_SD +=  ana.tx.getBranchLazy<LorentzVector>("Common_met_p4");
        HT +=  ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt();

        ana.tx.setBranch<float>  ("allHad_fj_mVVV_reco_SD",   vvv_reco_fj_SD.M());
        ana.tx.setBranch<float>  ("allHad_fj_ptVVV_reco_SD",  vvv_reco_fj_SD.Pt());
        ana.tx.setBranch<float>  ("allHad_HTMET",   HT);


        return true;
        }, [&]() { return 1.0; } );
   
   ana.cutflow.addCutToLastActiveCut("oneL_1fj", [&]() {
        ana.tx.setBranch<float>  ("allHad_dPhi_lep_jet",    abs(RooUtil::Calc::DeltaPhi( ana.tx.getBranch<vector<LorentzVector>>("Common_lep_p4")[0], ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[0])) );
       if (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size() != 1) return false;
       return true;
        }, [&]() { return 1.0; } );
    
    // ana.cutflow.addCutToLastActiveCut("oneL_nob_medium", [&]() {
    //     if (ana.tx.getBranchLazy<int>("Common_nb_medium" ) > 0) return false;
    //     return true;
    //     }, [&]() { return 1.0; } );
    ana.cutflow.addCutToLastActiveCut("oneL_nob_loose", [&]() {
        if (ana.tx.getBranchLazy<int>("Common_nb_loose" ) > 0) return false;
        return true;
        }, [&]() { return 1.0; } );


    ana.cutflow.addCutToLastActiveCut("oneL_HT", [&]() {
        if( ana.tx.getBranchLazy<float>("allHad_HTMET") > 1100) return true;
        return false;
        }, [&]() { return 1.0; } );
    
    ana.cutflow.addCutToLastActiveCut("oneL_WPT", [&]() {
        if( ( ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt() + ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt() ) > 500) return true;
        return false;
        }, [&]() { return 1.0; } );
    
    ana.cutflow.addCutToLastActiveCut("oneL_1fj_tight", [&]() {
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[0] == 3 &&  ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] <= 105.) return true;
        return false;
        }, [&]() { return 1.0; } );
   
    ana.cutflow.getCut("oneL_WPT"); 
    ana.cutflow.addCutToLastActiveCut("oneL_1fj_medium", [&]() {
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[0] == 2 &&  ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[0] <= 105.) return true;
        return false;
        }, [&]() { return 1.0; } );
    
    
    ana.cutflow.getCut("oneL_1fj_tight"); 
    ana.cutflow.addCutToLastActiveCut("oneLep_Mu", [&]() {
        if( abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 13 ) return true;
       return false;
        }, [&]() { return 1.0; } );
    
    ana.cutflow.addCutToLastActiveCut("oneLep_Mu_pt", [&]() {
        if( ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt() > 40 ) return true;
       return false;
        }, [&]() { return 1.0; } );
    
    ana.cutflow.addCutToLastActiveCut("oneLep_MuSF", [&]() {
       return true;
        }, [&]() { return ana.tx.getBranchLazy<vector<float>>("Common_lep_SF")[0]; } );
   
    ana.cutflow.getCut("oneL_1fj_tight"); 
    ana.cutflow.addCutToLastActiveCut("oneLep_El", [&]() {
        if( abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 11 ) return true;
       return false;
        }, [&]() { return 1.0; } );
    
    ana.cutflow.addCutToLastActiveCut("oneLep_El_pt", [&]() {
        if( ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Pt() > 40 ) return true;
       return false;
        }, [&]() { return 1.0; } );
    
    ana.cutflow.addCutToLastActiveCut("oneLep_ElSF", [&]() {
       return true;
        }, [&]() { return ana.tx.getBranchLazy<vector<float>>("Common_lep_SF")[0]; } );


    
    /*ana.cutflow.getCut("oneLep_EFT");
    ana.cutflow.addCutToLastActiveCut("oneLep_El", [&]() {
        if( abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 11 ) return true;
       return false;
        }, [&]() { return 1.0; } );*/

    //Basic cut for everything going forward
   


    

    


    
    ana.cutflow.getCut("oneL_fixedHT");
    ana.cutflow.addCutToLastActiveCut("oneL_2fj_tight", [&]() {
        if (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4").size() != 2) return false;
        if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP_MD")[1] == 3 &&  ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[1] <= 105.) return true;
        return false;
        }, [&]() { return 1.0; } );
    


    RooUtil::Histograms hists_allHad;

    //single value histograms
    hists_allHad.addHistogram("NJets"            ,  10,   0,    10, [&]() { return     ana.tx.getBranch<vector<LorentzVector>>("Common_jet_p4").size()   ; } );
    hists_allHad.addHistogram("NLeps"            ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size()   ; } );
    hists_allHad.addHistogram("NGenFatJets"       ,  10,   0,   10, [&]() { return      ana.tx.getBranchLazy<vector<LorentzVector>>("Common_genFatJet_p4").size()   ; } );
    hists_allHad.addHistogram("NFatJets"         ,  10,   0,    10, [&]() { return      ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4").size() ; } );
    hists_allHad.addHistogram("NW"               ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_n_W") ; } );

    hists_allHad.addHistogram("MET"              ,  40,   0,    800, [&]() { return    ana.tx.getBranch<LorentzVector>  ("Common_met_p4").Pt(); } );
    hists_allHad.addHistogram("mT"              ,  40,   0,    800, [&]() { return getMT(); } );

    hists_allHad.addHistogram("n_b_loose"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_nb_loose") ; } );
    hists_allHad.addHistogram("n_b_medium"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_nb_medium") ; } );
    hists_allHad.addHistogram("n_b_tight"          ,  10,   0,    10, [&]() { return      ana.tx.getBranchLazy<int>("Common_nb_tight") ; } );

    hists_allHad.addHistogram("MET_phi"              ,  40,   -4,    4, [&]() { return    ana.tx.getBranch<LorentzVector>  ("Common_met_p4").Phi(); } );
    hists_allHad.addHistogram("METFJ_dPhi_min"       ,  40,   0,    4, [&]() { return    ana.tx.getBranch<float>  ("allHad_mindPhi_MetFJ"); } );
    hists_allHad.addHistogram("dPhi_MET_fjn"       ,  40,   0,    4, [&]() { return    ana.tx.getBranch<float>  ("allHad_dPhi_lep_jet"); } );
    hists_allHad.addHistogram("genHT"            ,  40,   0,    5000, [&]() { return    ana.tx.getBranch<float>  ("allHad_genHT"); } );
    hists_allHad.addHistogram("HT"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_HT"); } );
    hists_allHad.addHistogram("HTMET"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_HTMET"); } );
    hists_allHad.addHistogram("HT_nolep"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_HT_nolep"); } );
    
    hists_allHad.addHistogram("HT_fj"               ,  40,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_HT"); } );
    hists_allHad.addHistogram("mVVV_reco_nomet_fj_SD"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco_nomet_SD"); } );
    hists_allHad.addHistogram("ptVVV_reco_nomet_fj_SD"               ,  60,   0,    800, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco_nomet_SD"); } );
    hists_allHad.addHistogram("mVVV_reco_fj_SD"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco_SD"); } );
    hists_allHad.addHistogram("ptVVV_reco_fj_SD"               ,  60,   0,    800, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco_SD"); } );
    hists_allHad.addHistogram("mVVV_reco_nomet_nolep_fj_SD"               ,  60,   0,    4000, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_mVVV_reco_nomet_nolep_SD"); } );
    hists_allHad.addHistogram("ptVVV_reco_nomet_nolep_fj_SD"               ,  60,   0,    800, [&]() { return    ana.tx.getBranch<float>  ("allHad_fj_ptVVV_reco_nomet_nolep_SD"); } );
    
    hists_allHad.addHistogram("lepton_pt"         ,  40,   0,    1000, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_lep_p4").size() > 0) ? ana.tx.getBranch<vector<LorentzVector>>("Common_lep_p4")[0].Pt() : -999 ; } );
    hists_allHad.addHistogram("lepton_eta"         ,  40,   -4,    4, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_lep_p4").size() > 0) ? ana.tx.getBranch<vector<LorentzVector>>("Common_lep_p4")[0].Eta() : -999 ; } );
    hists_allHad.addHistogram("lepton_phi"         ,  40,   -4,    4, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_lep_p4").size() > 0) ? ana.tx.getBranch<vector<LorentzVector>>("Common_lep_p4")[0].Phi() : -999 ; } );
    hists_allHad.addHistogram("lepton_pdgid"         ,  50,   -25,    25, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_lep_p4").size() > 0) ? ana.tx.getBranch<vector<int>>("Common_lep_pdgid")[0] : -999 ; } );
    
    
    hists_allHad.addHistogram("FatJet_pt_0"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4").size() > 0) ? ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[0].Pt() : -999 ; } );
    hists_allHad.addHistogram("FatJet_pt_1"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4").size() > 1) ? ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[1].Pt() : -999 ; } );
    hists_allHad.addHistogram("FatJet_pt_2"          ,  40,   0,    2000, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4").size() > 2) ? ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[2].Pt() : -999 ; } );
    
    
    hists_allHad.addHistogram("FatJet_eta_0"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4").size() > 0) ? ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[0].Eta() : -999 ; } );
    hists_allHad.addHistogram("FatJet_eta_1"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4").size() > 1) ? ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[1].Eta() : -999 ; } );
    hists_allHad.addHistogram("FatJet_eta_2"          ,  20,   -3,    3, [&]() { return      (ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4").size() > 2) ? ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[2].Eta() : -999 ; } );
 
    hists_allHad.addHistogram("FatJet_tau21_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau21").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_tau21")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau21_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_tau21")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau21_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_tau21")[2] : -999 ; } );

    hists_allHad.addHistogram("FatJet_tau32_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_tau32")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau32_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_tau32")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_tau32_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_tau32").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_tau32")[2] : -999 ; } );
    
    
    hists_allHad.addHistogram("FatJet_particleNet_W_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNet_W_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNet_W_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_particleNet_Z_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNet_Z_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_Z").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNet_Z_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_Z").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_particleNet_T_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_T").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_T")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNet_T_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_T").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_T")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNet_T_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_T").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_T")[2] : -999 ; } );
    
    hists_allHad.addHistogram("FatJet_particleNetMD_W_0"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNetMD_W")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNetMD_W_1"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNetMD_W")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_particleNetMD_W_2"          ,  30,   0,    1, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_particleNet_W").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_particleNetMD_W")[2] : -999 ; } );
    

    hists_allHad.addHistogram("FatJet_msoftdrop_0"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop").size() > 0) ? ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop")[0] : -999 ; } );
    hists_allHad.addHistogram("FatJet_msoftdrop_1"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop").size() > 1) ? ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop")[1] : -999 ; } );
    hists_allHad.addHistogram("FatJet_msoftdrop_2"          ,  40,   0,    200, [&]() { return      (ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop").size() > 2) ? ana.tx.getBranch<vector<float>>("Common_fatjet_msoftdrop")[2] : -999 ; } );
    
    
  
   
    ana.cutflow.bookCutflows(); 
    
    //ana.cutflow.bookHistogramsForCutAndBelow(hists_allHad, "oneL_fixedHT");
    ana.cutflow.bookHistogramsForCutAndBelow(hists_allHad, "CommonCut");
}






bool is_baseline_jet(unsigned int i){
    //always 6 despite twiki...
    if ( ! (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_id")[i] == 6) ) return false;    
   
    if ( ana.tx.getBranchLazy<vector<int>>("Common_jet_overlapfatjet")[i]) return false;

    return true;
}

bool is_baseline_fatjet(unsigned int i, bool firstPTcut, bool SDcut){
    if( ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i].Pt() < 200 ) return false;
    if( abs(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i].Eta()) > 2.4 ) return false;

    //always 6 despite twiki...
    if (! (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_id")[i] == 6) ) return false;

    //first jet pT > 500 GeV
    if(firstPTcut){
        if( i == 0 && ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i].Pt() < 500 ) return false;
    }

    if(SDcut){
        if( !(ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i] <= 105. ) ) return false;
        //if( !(ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i] >= 65. && ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i] <= 110. ) ) return false;
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


