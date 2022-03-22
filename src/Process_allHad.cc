#include "Process_allHad.h"

void Process_allHad()
{
    if(ana.run_VVVTree)
        Process_allHad_VVVTree();
    else
        Process_allHad_NanoAOD();
}

void Process_allHad_NanoAOD()
{

}

void Process_allHad_VVVTree()
{

    //==============================================
    // Process_allHad:
    // This function gets called during the event looping.
    // This is where one sets the variables used for the category allHad.
    //==============================================

    // Set variables used in this category.
    // If histograms are booked with these variables the histograms will be filled automatically.
    // Please follow the convention of <category>_<varname> structure.
    //ana.tx.setBranch<int>("allHad_intVar1", -999);
    //ana.tx.setBranch<float>("allHad_floatVar1", -999);
    
    //event level vars
    ana.tx.setBranch<float>  ("allHad_genHT",   ana.tx.getBranchLazy<float>("Common_genHT"));
    
    
    //vector vars
    vector<float> empty;
    vector<int> empty_i;
    empty.clear();
    empty_i.clear();
    
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_pt",        empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_eta",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_phi",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_ID",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_Jet_puid",       empty);
    
    ana.tx.setBranch<vector<float>>    ("allHad_FatJet_nMatchedQuarks",     empty);
    
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvvdecay_pdgid",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvvdecay_pt",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvv_pt",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_vvv_eta",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_gen_pdgId",       empty);
    ana.tx.setBranch<vector<float>>  ("allHad_genV_status",       empty);

    
    ana.tx.setBranch<float>  ("allHad_v12_dPhi", -999);
    ana.tx.setBranch<float>  ("allHad_v12_dEta", -999);
    ana.tx.setBranch<float>  ("allHad_v12_dR", -999);
    ana.tx.setBranch<float>  ("allHad_v23_dPhi", -999);
    ana.tx.setBranch<float>  ("allHad_v23_dEta", -999);
    ana.tx.setBranch<float>  ("allHad_v23_dR", -999);
    ana.tx.setBranch<float>  ("allHad_v31_dPhi", -999);
    ana.tx.setBranch<float>  ("allHad_v31_dEta", -999);
    ana.tx.setBranch<float>  ("allHad_v31_dR", -999);

    vector<LorentzVector> selected_p4;

    float HT_fj = 0;
    float ST_fj = 0;
    LorentzVector vvv_reco_fj; 
    LorentzVector vvv_reco_fj_SD;
        
    int nfat = 0;
    float SF = 1.0;
    int nloose = 0;
    int nmed = 0;
    int ntight = 0;
    vector<LorentzVector> savedFj;
    vector<LorentzVector> savedFj_SD;

    float minMetdPhi = 999;
    for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); i++){
        LorentzVector tmp = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i];
        int fjid = ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[i];
        //if (tmp.Pt() < 200 || abs(tmp.Eta()) > 2.4) continue;
        //if (ana.tx.getBranchLazy<vector<int>>("Common_fatjet_id")[i] != 6) continue;

        LorentzVector tmp_SD = RooUtil::Calc::getLV(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i].Pt(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i].Eta(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i].Phi(), ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[i]);

        if( fjid >= 1) nloose += 1;
        if( fjid >= 2) nmed += 1;

        selected_p4.push_back(tmp);
        HT_fj += tmp.Pt();
        vvv_reco_fj += tmp;
        vvv_reco_fj_SD += tmp_SD;
        
        SF *= ana.tx.getBranchLazy<vector<float>>("Common_fatjet_SFTight")[i];

        nfat++;
        savedFj.push_back(tmp);
        savedFj_SD.push_back(tmp_SD);

        
        float dPhiMet = abs(RooUtil::Calc::DeltaPhi( ana.tx.getBranch<LorentzVector>("Common_met_p4"), tmp));
        if( dPhiMet < minMetdPhi) minMetdPhi = dPhiMet;
            
            
       // }
    }

    ana.tx.setBranch<int>  ("allHad_NFatJet_loose", nloose);
    ana.tx.setBranch<int>  ("allHad_NFatJet_medium", nmed);
    ana.tx.setBranch<int>  ("allHad_NFatJet_tight", ntight);

    ST_fj = HT_fj + ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt();

    ana.tx.setBranch<float>  ("allHad_mindPhi_MetFJ",   minMetdPhi);

    ana.tx.setBranch<float>  ("allHad_fj_mVVV_reco_nomet",   vvv_reco_fj.M());
    ana.tx.setBranch<float>  ("allHad_fj_ptVVV_reco_nomet",  vvv_reco_fj.Pt());
    ana.tx.setBranch<float>  ("allHad_fj_mVVV_reco_nomet_SD",   vvv_reco_fj_SD.M());
    ana.tx.setBranch<float>  ("allHad_fj_ptVVV_reco_nomet_SD",  vvv_reco_fj_SD.Pt());
    
    ana.tx.setBranch<float>  ("allHad_FatJet_SF",  SF);
    
    vvv_reco_fj += ana.tx.getBranchLazy<LorentzVector>("Common_met_p4");
    
    ana.tx.setBranch<float>  ("allHad_fj_HT",   HT_fj);
    ana.tx.setBranch<float>  ("allHad_fj_ST",   ST_fj);
    ana.tx.setBranch<float>  ("allHad_fj_mVVV_reco",   vvv_reco_fj.M());
    ana.tx.setBranch<float>  ("allHad_fj_ptVVV_reco",  vvv_reco_fj.Pt());

    //2 fatjets
    if(nfat > 1){
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

    //3 fatjets
    if(nfat > 2){
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

    int nb_loose = 0;
    int nb_tight = 0;
    int nb_medium = 0;
    int njets = 0;

    for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size(); i++){
        
        //if (ana.tx.getBranchLazy<vector<int>>("Common_jet_id")[i] != 6) continue;
        
        LorentzVector tmp = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[i];
        if (abs(tmp.Eta()) > 2.4) continue;
        
        //do jet/fatjet overlap removal after b-veto 
        if( ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBmedium")[i] ) nb_medium++;
        if( ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBtight")[i] ) nb_tight++;
        if( ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBloose")[i] ) nb_loose++;
        
        if(ana.tx.getBranchLazy<vector<int>>("Common_jet_overlapfatjet")[i]) continue;
         
        njets ++;
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_pt",  tmp.Pt());
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_eta", tmp.Eta()); 
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_phi", tmp.Phi());
        ana.tx.pushbackToBranch<float>  ("allHad_Jet_M",   tmp.M());
        
        //ana.tx.pushbackToBranch<float>  ("allHad_Jet_ID", ana.tx.getBranchLazy<vector<int>>("Common_jet_id")[i]);

        selected_p4.push_back(tmp);
    }

    if(njets > 1){
        TLorentzVector j1 = RooUtil::Calc::getTLV(RooUtil::Calc::getLV(ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt")[0], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_eta")[0], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_phi")[0], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_M")[0]));
        TLorentzVector j2 = RooUtil::Calc::getTLV(RooUtil::Calc::getLV(ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt")[1], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_eta")[1], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_phi")[1], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_M")[1]));
        ana.tx.setBranch<float> ("allHad_j12_mass", (j1+j2).M());
        ana.tx.setBranch<float> ("allHad_j12_dPhi", abs(j1.DeltaPhi(j2)));
        ana.tx.setBranch<float> ("allHad_j12_dEta", abs(abs(j1.Eta()) - abs(j2.Eta())));
        ana.tx.setBranch<float> ("allHad_j12_dR",   j1.DeltaR(j2));
    }
    else{
        ana.tx.setBranch<float> ("allHad_j12_mass", -999);
        ana.tx.setBranch<float> ("allHad_j12_dPhi", -999);
        ana.tx.setBranch<float> ("allHad_j12_dEta", -999);
        ana.tx.setBranch<float> ("allHad_j12_dR",   -999);
    }
    
    if(njets > 2){
        TLorentzVector j1 = RooUtil::Calc::getTLV(RooUtil::Calc::getLV(ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt")[0], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_eta")[0], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_phi")[0], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_M")[0]));
        TLorentzVector j2 = RooUtil::Calc::getTLV(RooUtil::Calc::getLV(ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt")[1], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_eta")[1], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_phi")[1], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_M")[1]));
        TLorentzVector j3 = RooUtil::Calc::getTLV(RooUtil::Calc::getLV(ana.tx.getBranchLazy<vector<float>>("allHad_Jet_pt")[2], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_eta")[2], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_phi")[2], ana.tx.getBranchLazy<vector<float>>("allHad_Jet_M")[2]));
        ana.tx.setBranch<float> ("allHad_j23_mass", (j2+j3).M());
        ana.tx.setBranch<float> ("allHad_j23_dPhi", abs(j3.DeltaPhi(j2)));
        ana.tx.setBranch<float> ("allHad_j23_dEta", abs(abs(j3.Eta()) - abs(j2.Eta())));
        ana.tx.setBranch<float> ("allHad_j23_dR",   j3.DeltaR(j2));
        ana.tx.setBranch<float> ("allHad_j31_mass", (j1+j3).M());
        ana.tx.setBranch<float> ("allHad_j31_dPhi", abs(j3.DeltaPhi(j1)));
        ana.tx.setBranch<float> ("allHad_j31_dEta", abs(abs(j3.Eta()) - abs(j1.Eta())));
        ana.tx.setBranch<float> ("allHad_j31_dR",   j3.DeltaR(j1));
    }
    else{
        ana.tx.setBranch<float> ("allHad_j23_mass", -999);
        ana.tx.setBranch<float> ("allHad_j23_dPhi", -999);
        ana.tx.setBranch<float> ("allHad_j23_dEta", -999);
        ana.tx.setBranch<float> ("allHad_j23_dR",   -999);
        ana.tx.setBranch<float> ("allHad_j31_mass", -999);
        ana.tx.setBranch<float> ("allHad_j31_dPhi", -999);
        ana.tx.setBranch<float> ("allHad_j31_dEta", -999);
        ana.tx.setBranch<float> ("allHad_j31_dR",   -999);
    }

        
    ana.tx.setBranch<int>  ("allHad_nb_loose",   nb_loose);
    ana.tx.setBranch<int>  ("allHad_nb_medium",  nb_medium);
    ana.tx.setBranch<int>  ("allHad_nb_tight",   nb_tight);
     
    float HT = 0;
    float ST = 0;
    LorentzVector vvv_reco; 
    for(unsigned int i=0; i<selected_p4.size(); i++){
        HT += selected_p4[i].Pt();
        LorentzVector tmp = RooUtil::Calc::getLV(selected_p4[i].Pt(), selected_p4[i].Eta(), selected_p4[i].Phi(), selected_p4[i].M());
        vvv_reco += tmp;

    }
    ST = HT + ana.tx.getBranchLazy<LorentzVector>("Common_met_p4").Pt();
    
    ana.tx.setBranch<float>  ("allHad_mVVV_reco_nomet",   vvv_reco.M());
    ana.tx.setBranch<float>  ("allHad_ptVVV_reco_nomet",   vvv_reco.Pt());
    vvv_reco += ana.tx.getBranchLazy<LorentzVector>("Common_met_p4");
        
    
    ana.tx.setBranch<float>  ("allHad_HT",   HT);
    ana.tx.setBranch<float>  ("allHad_ST",   ST);
    ana.tx.setBranch<float>  ("allHad_mVVV_reco",   vvv_reco.M());
    ana.tx.setBranch<float>  ("allHad_ptVVV_reco",  vvv_reco.Pt());

        
    
    if(! ana.tx.getBranchLazy<bool>("Common_isData")){

        //truth level stuff
        
        ana.tx.setBranch<float>  ("allHad_mVVV",  -999);
        ana.tx.setBranch<int>  ("allHad_nGenLeps",  -999);
        ana.tx.setBranch<int>  ("allHad_nGenQuarks",  -999);
        ana.tx.setBranch<int>  ("allHad_nGenV",  -999);
        LorentzVector vvv; 
        int nboson = 0;
        vector<int> bosonI;
        for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_gen_idx").size(); i++){
            if (abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[i]) == 24 || abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[i] == 23)){
                LorentzVector tmp = RooUtil::Calc::getLV(ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Pt(), ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Eta(), ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Phi(), ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].M());
                vvv += tmp;
                nboson++;
                bosonI.push_back(i);
                
                ana.tx.pushbackToBranch<float>    ("allHad_gen_vvv_pt", abs(ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Pt()));
                ana.tx.pushbackToBranch<float>    ("allHad_gen_vvv_eta", abs(ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Eta()));
           }   
        }
        
        int nleps = 0;
        int nquarks = 0;
        //ana.tx.setBranch<int>  ("allHad_nGenLeptons",  10);
        for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid").size(); i++){
            //std::cout << (ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid")[i]) << std::endl;
            if( abs(ana.tx.getBranch<vector<int>>("Common_gen_vvvdecay_pdgid")[i]) == 11 ||  
                abs(ana.tx.getBranch<vector<int>>("Common_gen_vvvdecay_pdgid")[i]) == 13 || 
                abs(ana.tx.getBranch<vector<int>>("Common_gen_vvvdecay_pdgid")[i]) == 15   ){ nleps+=1;}
            else if (  abs(ana.tx.getBranch<vector<int>>("Common_gen_vvvdecay_pdgid")[i]) > 0 &&  abs(ana.tx.getBranch<vector<int>>("Common_gen_vvvdecay_pdgid")[i]) < 9) nquarks++;

            ana.tx.pushbackToBranch<float>    ("allHad_gen_vvvdecay_pdgid", abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid")[i]));
            ana.tx.pushbackToBranch<float>    ("allHad_gen_vvvdecay_pt", abs(ana.tx.getBranch<vector<LorentzVector>>("Common_gen_vvvdecay_p4s")[i].Pt()));

                    

        }
        
        for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid").size(); i++){
            ana.tx.pushbackToBranch<float>    ("allHad_gen_pdgId", abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[i]));
        }
        
        ana.tx.setBranch<float>  ("allHad_mVVV",  vvv.M());
        ana.tx.setBranch<int>  ("allHad_nGenLeps", nleps);
        ana.tx.setBranch<int>  ("allHad_nGenQuarks", nquarks);
        
        vector<LorentzVector> vs;
        //loop over fatjets to match with quarks -- each fatjet should match two quarks
        int nmatched = 0;
        vector<int> matchedI;

        for(unsigned int ifj=0; ifj< savedFj.size(); ifj++){
            for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_gen_idx").size(); i++){
                if (abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[i]) == 24 || abs(ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid")[i] == 23)){
                    if( RooUtil::Calc::DeltaR( savedFj[ifj], ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i] ) < 0.4){
                        nmatched++;
                        matchedI.push_back(i);
                        vs.push_back( ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i]);
                    }
                }
            }
        }

        //loop over all the bosons and figure out what happened to them
        //status 0 is not set/other
        //status 1 is matched to a jet
        //status 2 is decayed to leptons
        //status 3 is pT < 200 GeV
        //status 4 is fatjet exists, but doesnt pass pt, eta, ID
        //status 5 is fatjet exists, passed fiducial selections but no deep W 
        //status 6 is fatjet exists, only passes very loose
        //status 7 is fatjet exists, only passes loose
        //status 8 is fatjet exists, only passes medium
        vector<float> boson_status;
        for(unsigned int i=0; i < bosonI.size(); i++){
            //boson has been matched to a fatjet
            int status = 0;
            if( std::find( matchedI.begin(), matchedI.end(), i) != matchedI.end()  ){
                status = 1;
            }
            else if (nquarks < 6){
                status = 2;
            }
            else if ( ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Pt() < 150 || abs(ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i].Eta()) > 2.2) {
                status = 3;
            }
            else{
                for (unsigned int ij=0; ij < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); ij++){
                    if( RooUtil::Calc::DeltaR( ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i], ana.tx.getBranch<vector<LorentzVector>>("Common_fatjet_p4")[ij] ) < 0.4){
                        
                        LorentzVector tmp = ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[i];
                        int fjid = ana.tx.getBranchLazy<vector<int>>("Common_fatjet_WP")[i];
                        
                        if (tmp.Pt() > 200 && abs(tmp.Eta()) < 2.4 && ana.tx.getBranchLazy<vector<int>>("Common_fatjet_id")[i] == 6){
                            status = 5;
                            
                            if( fjid == 0 ){
                                status = 6;
                            }
                            else if ( fjid == 1){
                                status = 7;
                            }
                            else if ( fjid == 2){
                                status = 8;
                            }
                        }
                        else{
                            status = 4;
                        }
                            
                    }    
                }
                
                //see if we can find 2 small R jets if we didn't get a good fatjet, we removed jets that overlap with fatjets
                int nclosebyjets = 0;
                for (unsigned int ij=0; ij < ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size(); ij++){
                    if( RooUtil::Calc::DeltaR( ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[i], ana.tx.getBranch<vector<LorentzVector>>("Common_jet_p4")[ij] ) < 0.8){
                        nclosebyjets ++;
                    }
                }

                if(nclosebyjets == 2){
                    status = 9;
                
                }



            }

            boson_status.push_back(status);
        }

        ana.tx.setBranch<vector<float>>  ("allHad_genV_status",  boson_status);







            
            /*            
            for (unsigned int i=0; i < ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid").size(); i++){
                if (  abs(ana.tx.getBranch<vector<int>>("Common_gen_vvvdecay_pdgid")[i]) > 0 &&  abs(ana.tx.getBranch<vector<int>>("Common_gen_vvvdecay_pdgid")[i]) < 9){
                    if( RooUtil::Calc::DeltaR( savedFj[ifj], ana.tx.getBranch<vector<LorentzVector>>("Common_gen_vvvdecay_p4s")[i] ) < 0.4){
                        nmatched++;
                        imatched.push_back(i);
                    }
                    
                }
            }
            ana.tx.pushbackToBranch<float> ("allHad_FatJet_nMatchedQuarks", nmatched);

            //for now only handle jets with 2 matched quarks
            if(nmatched == 2){
                //sum quarks to make w boson
                LorentzVector v = ana.tx.getBranch<vector<LorentzVector>>("Common_gen_vvvdecay_p4s")[imatched[0]] +  ana.tx.getBranch<vector<LorentzVector>>("Common_gen_vvvdecay_p4s")[imatched[1]];
                vs.push_back(v);
            }*/


        if (nfat > 2){
            //std::cout << std::endl;
            //std::cout << bosonI.size() << " bosons with matched " << matchedI.size() << std::endl;
            //std::cout << nfat << " fatjets matched to " << nmatched << std::endl;
        }
        
        ana.tx.setBranch<int>("allHad_nGenV", vs.size());

        //2 bosons
        if(vs.size() > 1){
            ana.tx.setBranch<float>  ("allHad_v12_dPhi",  RooUtil::Calc::DeltaPhi(vs[0],vs[1]));
            ana.tx.setBranch<float>  ("allHad_v12_dEta",  abs(RooUtil::Calc::DeltaEta(vs[0],vs[1])));
            ana.tx.setBranch<float>  ("allHad_v12_dR",    RooUtil::Calc::DeltaR(vs[0],vs[1]));
            
        }
        else{
            ana.tx.setBranch<float>  ("allHad_v12_dPhi",  -999);
            ana.tx.setBranch<float>  ("allHad_v12_dEta",  -999);
            ana.tx.setBranch<float>  ("allHad_v12_dR",    -999);
        }

        //3 fatjets
        if(vs.size() > 2){
            ana.tx.setBranch<float>  ("allHad_v23_dPhi",  RooUtil::Calc::DeltaPhi(vs[1],vs[2]));
            ana.tx.setBranch<float>  ("allHad_v23_dEta",  abs( RooUtil::Calc::DeltaEta(vs[1],vs[2]) ));
            ana.tx.setBranch<float>  ("allHad_v23_dR",    RooUtil::Calc::DeltaR(vs[1],vs[2]));
            
            ana.tx.setBranch<float>  ("allHad_v31_dPhi",  RooUtil::Calc::DeltaPhi(vs[0],vs[2]));
            ana.tx.setBranch<float>  ("allHad_v31_dEta",  abs( RooUtil::Calc::DeltaEta(vs[0],vs[2]) ));
            ana.tx.setBranch<float>  ("allHad_v31_dR",    RooUtil::Calc::DeltaR(vs[0],vs[2]));
            
            
        }
        else{
            ana.tx.setBranch<float>  ("allHad_v23_dPhi",  -999);
            ana.tx.setBranch<float>  ("allHad_v23_dEta",  -999);
            ana.tx.setBranch<float>  ("allHad_v23_dR",    -999);
            
            ana.tx.setBranch<float>  ("allHad_v31_dPhi",  -999);
            ana.tx.setBranch<float>  ("allHad_v31_dEta",  -999);
            ana.tx.setBranch<float>  ("allHad_v31_dR",    -999);

        }
    
    
        
    }

    // Semi-complete list of NanoAOD for 102X can be found here: https://cms-nanoaod-integration.web.cern.ch/integration/master-102X/mc102X_doc.html
    // Also consult here: https://github.com/cmstas/NanoTools/blob/d641a6d6c1aa9ecc8094a1af73d5e1bd7d6502ab/NanoCORE/Nano.h#L4875 (if new variables are added they may show up in master)

}


void PostProcess_allHad()
{
    if (ana.region == 1){
        if (ana.cutflow.getCut("oneLep_HT").pass)
        {
            ana.tx.fill();
        }
    }
    else{
        if (ana.cutflow.getCut("allHad_HT").pass)
        {
            ana.tx.fill();
        }

    }
}

