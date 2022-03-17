#include "Process_1Lep2fatjet.h"
#include "TMath.h"

TLorentzVector getNeutrinoP4(double MetPt, double MetPhi, TLorentzVector lep, int lepType){
        float MW_=80.385;

        double leppt = lep.Pt();
        double lepphi = lep.Phi();
        double lepeta = lep.Eta();
        double lepenergy = lep.Energy();

        double metpt = MetPt;
        double metphi = MetPhi;

        double  px = metpt*cos(metphi);
        double  py = metpt*sin(metphi);
        double  pz = 0;
        double  pxl= leppt*cos(lepphi);
        double  pyl= leppt*sin(lepphi);
        double  pzl= leppt*sinh(lepeta);
        double  El = lepenergy;
        double  a = pow(MW_,2) + pow(px+pxl,2) + pow(py+pyl,2) - px*px - py*py - El*El + pzl*pzl;
        double  b = 2.*pzl;
        double  A = b*b -4.*El*El;
        double  B = 2.*a*b;
        double  C = a*a-4.*(px*px+py*py)*El*El;

        ///////////////////////////pz for fnal
        double M_mu =  0;

        //if(lepType==1)M_mu=0.105658367;//mu
        //if(lepType==0)M_mu=0.00051099891;//electron

        int type=2; // use the small abs real root

        a = MW_*MW_ - M_mu*M_mu + 2.0*pxl*px + 2.0*pyl*py;
        A = 4.0*(El*El - pzl*pzl);
        B = -4.0*a*pzl;
        C = 4.0*El*El*(px*px + py*py) - a*a;

        double tmproot = B*B - 4.0*A*C;

        if (tmproot<0) {
            //std::cout << "Complex root detected, taking real part..." << std::endl;
            pz = - B/(2*A); // take real part of complex roots
        }
        else {
            double tmpsol1 = (-B + sqrt(tmproot))/(2.0*A);
            double tmpsol2 = (-B - sqrt(tmproot))/(2.0*A);
            //std::cout << " Neutrino Solutions: " << tmpsol1 << ", " << tmpsol2 << std::endl;

            if (type == 0 ) {
                // two real roots, pick the one closest to pz of muon
                if (TMath::Abs(tmpsol2-pzl) < TMath::Abs(tmpsol1-pzl)) { pz = tmpsol2; }
                else { pz = tmpsol1; }
                // if pz is > 300 pick the most central root
                if ( abs(pz) > 300. ) {
                    if (TMath::Abs(tmpsol1)<TMath::Abs(tmpsol2) ) { pz = tmpsol1; }
                    else { pz = tmpsol2; }
                }
            }
            if (type == 1 ) {
                // two real roots, pick the one closest to pz of muon
                if (TMath::Abs(tmpsol2-pzl) < TMath::Abs(tmpsol1-pzl)) { pz = tmpsol2; }
                else {pz = tmpsol1; }
            }
            if (type == 2 ) {
                // pick the most central root.
                if (TMath::Abs(tmpsol1)<TMath::Abs(tmpsol2) ) { pz = tmpsol1; }
                else { pz = tmpsol2; }
            }
            /*if (type == 3 ) {
             // pick the largest value of the cosine
             TVector3 p3w, p3mu;
             p3w.SetXYZ(pxl+px, pyl+py, pzl+ tmpsol1);
             p3mu.SetXYZ(pxl, pyl, pzl );

             double sinthcm1 = 2.*(p3mu.Perp(p3w))/MW_;
             p3w.SetXYZ(pxl+px, pyl+py, pzl+ tmpsol2);
             double sinthcm2 = 2.*(p3mu.Perp(p3w))/MW_;

             double costhcm1 = sqrt(1. - sinthcm1*sinthcm1);
             double costhcm2 = sqrt(1. - sinthcm2*sinthcm2);

             if ( costhcm1 > costhcm2 ) { pz = tmpsol1; otherSol_ = tmpsol2; }
             else { pz = tmpsol2;otherSol_ = tmpsol1; }

             }*///end of type3

        }//endl of if real root

        //dont correct pt neutrino
        TLorentzVector outP4;
        outP4.SetPxPyPzE(px,py,pz,sqrt(px*px+py*py+pz*pz));
        return outP4;

}

void Process_1Lep2fatjet_Geninfo(){
    // Gen level info
    if ( not nt.isData()){
        ana.tx.setBranch<vector<float>>("Lep1fatJet2_GenPart_eta", nt.GenPart_eta());
        ana.tx.setBranch<vector<int>>("Lep1fatJet2_GenPart_genPartIdxMother", nt.GenPart_genPartIdxMother());
        ana.tx.setBranch<vector<float>>("Lep1fatJet2_GenPart_mass", nt.GenPart_mass());
        ana.tx.setBranch<vector<int>>("Lep1fatJet2_GenPart_pdgId", nt.GenPart_pdgId());
        ana.tx.setBranch<vector<float>>("Lep1fatJet2_GenPart_phi", nt.GenPart_phi());
        ana.tx.setBranch<vector<float>>("Lep1fatJet2_GenPart_pt", nt.GenPart_pt());
        ana.tx.setBranch<vector<int>>("Lep1fatJet2_GenPart_status", nt.GenPart_status());
        ana.tx.setBranch<vector<int>>("Lep1fatJet2_GenPart_statusFlags", nt.GenPart_statusFlags());
        ana.tx.setBranch<int>("Lep1fatJet2_nGenPart", nt.nGenPart());
    }
}

void Process_1Lep2fatjet_Weight_HLT(){
    
    // pile-up reweight
    if ( not nt.isData()){
        ana.tx.setBranch<float>("Lep1fatJet2_Pileup_nTrueInt",  nt.Pileup_nTrueInt() );
        ana.tx.setBranch<float>("Lep1fatJet2_Pileup_nPU"     ,  nt.Pileup_nPU()      );
    }

    // 1Lepton HLT
    try { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_Mu50"                        , nt.HLT_Mu50())                        ; }  catch (std::runtime_error) { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_Mu50"                        , -99); }
    try { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_IsoMu24"                     , nt.HLT_IsoMu24())                     ; }  catch (std::runtime_error) { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_IsoMu24"                     , -99);}
    try { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_OldMu100"                    , nt.HLT_OldMu100())                    ; }  catch (std::runtime_error) { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_OldMu100"                    , -99);}
    try { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_TkMu100"                     , nt.HLT_TkMu100())                     ; }  catch (std::runtime_error) { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_TkMu100"                     , -99);}
    try { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_IsoMu27"                     , nt.HLT_IsoMu27())                     ; }  catch (std::runtime_error) { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_IsoMu27"                     , -99);}
    
    try { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_Ele27_WPTight_Gsf"           , nt.HLT_Ele27_WPTight_Gsf())           ; }  catch (std::runtime_error) { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_Ele27_WPTight_Gsf"           , -99);}
    try { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_Ele35_WPTight_Gsf"           , nt.HLT_Ele35_WPTight_Gsf())           ; }  catch (std::runtime_error) { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_Ele35_WPTight_Gsf"           , -99);}
    
    try { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_Ele32_WPTight_Gsf_L1DoubleEG", nt.HLT_Ele32_WPTight_Gsf_L1DoubleEG()); }  catch (std::runtime_error) { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_Ele32_WPTight_Gsf_L1DoubleEG", -99);}
    try { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_Ele32_WPTight_Gsf"           , nt.HLT_Ele32_WPTight_Gsf())           ; }  catch (std::runtime_error) { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_Ele32_WPTight_Gsf"           , -99);}

    try { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_Photon200"                   , nt.HLT_Photon200())                   ; }  catch (std::runtime_error) { ana.tx.setBranch<int> ("Lep1fatJet2_HLT_Photon200"                   , -99);}

}

void Process_1Lep2fatjet_Jet(){
    for (unsigned int inum = 0; inum < ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size(); ++inum){

        ana.tx.pushbackToBranch<float>("Lep1fatJet2_Jet_pt" , nt.Jet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]].pt()     );
        ana.tx.pushbackToBranch<float>("Lep1fatJet2_Jet_eta", nt.Jet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]].eta()    );
        ana.tx.pushbackToBranch<float>("Lep1fatJet2_Jet_phi", nt.Jet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]].phi()    );
        ana.tx.pushbackToBranch<float>("Lep1fatJet2_Jet_e"  , nt.Jet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]].energy() );

        ana.tx.pushbackToBranch<int>("Lep1fatJet2_Jet_jetId", nt.Jet_jetId()[inum] );

        // int _Jet_jetId = nt.Jet_jetId()[inum]; _Jet_jetId = ((_Jet_jetId &2) == 2); ana.tx.pushbackToBranch<int>("Lep1fatJet2_Jet_jetId", _Jet_jetId);
        if (not nt.isData()){
            ana.tx.pushbackToBranch<int>("Lep1fatJet2_Jet_hadronFlavour", nt.Jet_hadronFlavour()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]]);
            ana.tx.pushbackToBranch<int>("Lep1fatJet2_Jet_partonFlavour", nt.Jet_partonFlavour()[ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]]);
        }

        ana.tx.pushbackToBranch<float>("Lep1fatJet2_Jet_btagDeepB"    , nt.Jet_btagDeepB()     [ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]] );
        // ana.tx.pushbackToBranch<float>("Lep1fatJet2_Jet_btagDeepC"    , nt.Jet_btagDeepC()     [ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]] );
        // ana.tx.pushbackToBranch<float>("Lep1fatJet2_Jet_btagDeepFlavC", nt.Jet_btagDeepFlavC() [ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]] );
        ana.tx.pushbackToBranch<float>("Lep1fatJet2_Jet_btagDeepFlavB", nt.Jet_btagDeepFlavB() [ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]] );
        ana.tx.pushbackToBranch<float>("Lep1fatJet2_Jet_qgl"          , nt.Jet_qgl()           [ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs")[inum]] );
        
    }
}

void Process_1Lep2fatjet_MET_Lepton_leptonicW(){

    ana.tx.setBranch<float>("Lep1fatJet2_MET_pt" , nt.MET_pt()  );
    ana.tx.setBranch<float>("Lep1fatJet2_MET_phi", nt.MET_phi() );

    if ( ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size() == 1 ){
        
        ana.tx.setBranch<float>("Lep1fatJet2_LeptonPt"   , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")   [0].pt() );
        ana.tx.setBranch<float>("Lep1fatJet2_LeptonEta"  , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")   [0].eta() );
        ana.tx.setBranch<float>("Lep1fatJet2_LeptonPhi"  , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")   [0].phi() );
        ana.tx.setBranch<float>("Lep1fatJet2_LeptonE"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")   [0].energy() );
        ana.tx.setBranch<int>  ("Lep1fatJet2_LeptonPDGID", ana.tx.getBranchLazy<vector<int>>          ("Common_lep_pdgid")[0] );
        if (abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) ==13){
            ana.tx.setBranch<float>("Lep1fatJet2_Muon_pfRelIso04_all", nt.Muon_pfRelIso04_all()[ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[0]] );
        }

        TLorentzVector  glepton, neutrino, neutrinoP4, WLeptonic;
        glepton.SetPtEtaPhiE( ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].pt(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].eta(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].phi(), ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].energy());
        int leptontype = 1;

        neutrino = getNeutrinoP4(nt.MET_pt() , nt.MET_phi(), glepton, leptontype);
        neutrinoP4.SetPtEtaPhiE(neutrino.Pt(),neutrino.Eta(),neutrino.Phi(),neutrino.Energy());

        ana.tx.setBranch<float>("Lep1fatJet2_NeutrinoPt" , neutrinoP4.Pt()     );
        ana.tx.setBranch<float>("Lep1fatJet2_NeutrinoEta", neutrinoP4.Eta()    );
        ana.tx.setBranch<float>("Lep1fatJet2_Neutrinophi", neutrinoP4.Phi()    );
        ana.tx.setBranch<float>("Lep1fatJet2_NeutrinoE"  , neutrinoP4.Energy() );

        WLeptonic = glepton+neutrinoP4;
        ana.tx.setBranch<float>("Lep1fatJet2_LeptonicWPt"  , WLeptonic.Pt()  );
        ana.tx.setBranch<float>("Lep1fatJet2_LeptonicWEta" , WLeptonic.Eta() );
        ana.tx.setBranch<float>("Lep1fatJet2_LeptonicWPhi" , WLeptonic.Phi() );
        ana.tx.setBranch<float>("Lep1fatJet2_LeptonicWM"   , WLeptonic.M()   );
        ana.tx.setBranch<float>("Lep1fatJet2_LeptonicWMt"  , WLeptonic.Mt()  );
    }
    
}


void Process_1Lep2fatjet_StorefatJet(){

    if(ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() == 2){
        int usenumber3 = -1; double pt_larger=0;
        for (unsigned int inum = 0; inum < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); ++inum){
            if(nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].pt() > pt_larger && fabs(nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].eta())<2.4 && inum<4) {
                pt_larger = nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].pt(); 
                usenumber3 = ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]; 
                continue;
            }
        }

        if (usenumber3>-1) {
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_pt"       , nt.FatJet_p4()        [usenumber3].pt() );
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_eta"       , nt.FatJet_p4()        [usenumber3].eta());
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_phi"       , nt.FatJet_p4()        [usenumber3].phi());
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_msoftdrop" , nt.FatJet_msoftdrop() [usenumber3]      );

            ana.tx.setBranch<int>("Lep1fatJet2_FatJet_jetId", nt.FatJet_jetId()[usenumber3]);

            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_tau1", nt.FatJet_tau1()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_tau2", nt.FatJet_tau2()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_tau3", nt.FatJet_tau3()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_tau4", nt.FatJet_tau4()[usenumber3]);

            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_H4qvsQCD", nt.FatJet_deepTagMD_H4qvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_HbbvsQCD", nt.FatJet_deepTagMD_HbbvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_TvsQCD", nt.FatJet_deepTagMD_TvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_WvsQCD", nt.FatJet_deepTagMD_WvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZHbbvsQCD", nt.FatJet_deepTagMD_ZHbbvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZHccvsQCD", nt.FatJet_deepTagMD_ZHccvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZbbvsQCD", nt.FatJet_deepTagMD_ZbbvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZvsQCD", nt.FatJet_deepTagMD_ZvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_bbvsLight", nt.FatJet_deepTagMD_bbvsLight()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ccvsLight", nt.FatJet_deepTagMD_ccvsLight()[usenumber3]);

            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTag_H", nt.FatJet_deepTag_H()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTag_QCD", nt.FatJet_deepTag_QCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTag_QCDothers", nt.FatJet_deepTag_QCDothers()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTag_TvsQCD", nt.FatJet_deepTag_TvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTag_WvsQCD", nt.FatJet_deepTag_WvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTag_ZvsQCD", nt.FatJet_deepTag_ZvsQCD()[usenumber3]);

            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNetMD_QCD", nt.FatJet_particleNetMD_QCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNetMD_Xbb", nt.FatJet_particleNetMD_Xbb()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNetMD_Xcc", nt.FatJet_particleNetMD_Xcc()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNetMD_Xqq", nt.FatJet_particleNetMD_Xqq()[usenumber3]);

            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_H4qvsQCD", nt.FatJet_particleNet_H4qvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_HbbvsQCD", nt.FatJet_particleNet_HbbvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_HccvsQCD", nt.FatJet_particleNet_HccvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_QCD", nt.FatJet_particleNet_QCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_TvsQCD", nt.FatJet_particleNet_TvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_WvsQCD", nt.FatJet_particleNet_WvsQCD()[usenumber3]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_ZvsQCD", nt.FatJet_particleNet_ZvsQCD()[usenumber3]);

        }


        int usenumber2 = -1; pt_larger=0;
        for (unsigned int inum = 0; inum < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); ++inum){
            if(nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].pt() > pt_larger && fabs(nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].eta())<2.4 && inum<4 && ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum] != usenumber3) {
                pt_larger = nt.FatJet_p4()[ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]].pt(); 
                usenumber2 = ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs")[inum]; 
                continue;
            }
        }

        if (usenumber2>-1) {
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_pt_2"       , nt.FatJet_p4()        [usenumber2].pt() );
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_eta_2"       , nt.FatJet_p4()        [usenumber2].eta());
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_phi_2"       , nt.FatJet_p4()        [usenumber2].phi());
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_msoftdrop_2" , nt.FatJet_msoftdrop() [usenumber2]      );

            ana.tx.setBranch<int>("Lep1fatJet2_FatJet_jetId_2", nt.FatJet_jetId()[usenumber2]);

            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_tau1_2", nt.FatJet_tau1()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_tau2_2", nt.FatJet_tau2()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_tau3_2", nt.FatJet_tau3()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_tau4_2", nt.FatJet_tau4()[usenumber2]);

            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_H4qvsQCD_2", nt.FatJet_deepTagMD_H4qvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_HbbvsQCD_2", nt.FatJet_deepTagMD_HbbvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_TvsQCD_2", nt.FatJet_deepTagMD_TvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_WvsQCD_2", nt.FatJet_deepTagMD_WvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZHbbvsQCD_2", nt.FatJet_deepTagMD_ZHbbvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZHccvsQCD_2", nt.FatJet_deepTagMD_ZHccvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZbbvsQCD_2", nt.FatJet_deepTagMD_ZbbvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ZvsQCD_2", nt.FatJet_deepTagMD_ZvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_bbvsLight_2", nt.FatJet_deepTagMD_bbvsLight()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTagMD_ccvsLight_2", nt.FatJet_deepTagMD_ccvsLight()[usenumber2]);

            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTag_H_2", nt.FatJet_deepTag_H()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTag_QCD_2", nt.FatJet_deepTag_QCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTag_QCDothers_2", nt.FatJet_deepTag_QCDothers()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTag_TvsQCD_2", nt.FatJet_deepTag_TvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTag_WvsQCD_2", nt.FatJet_deepTag_WvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_deepTag_ZvsQCD_2", nt.FatJet_deepTag_ZvsQCD()[usenumber2]);

            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNetMD_QCD_2", nt.FatJet_particleNetMD_QCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNetMD_Xbb_2", nt.FatJet_particleNetMD_Xbb()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNetMD_Xcc_2", nt.FatJet_particleNetMD_Xcc()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNetMD_Xqq_2", nt.FatJet_particleNetMD_Xqq()[usenumber2]);

            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_H4qvsQCD_2", nt.FatJet_particleNet_H4qvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_HbbvsQCD_2", nt.FatJet_particleNet_HbbvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_HccvsQCD_2", nt.FatJet_particleNet_HccvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_QCD_2", nt.FatJet_particleNet_QCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_TvsQCD_2", nt.FatJet_particleNet_TvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_WvsQCD_2", nt.FatJet_particleNet_WvsQCD()[usenumber2]);
            ana.tx.setBranch<float>("Lep1fatJet2_FatJet_particleNet_ZvsQCD_2", nt.FatJet_particleNet_ZvsQCD()[usenumber2]);
            
        }
    }

}

void Process_1Lep2fatjet_Selection(){

    if (ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size() == 1 && ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size() == 2){
        Process_1Lep2fatjet_Weight_HLT();
        Process_1Lep2fatjet_Jet();
        Process_1Lep2fatjet_MET_Lepton_leptonicW();
        Process_1Lep2fatjet_Geninfo();
        Process_1Lep2fatjet_StorefatJet();
        ana.tx.fill();
    }

}


void Process_1Lep2fatjet()
{
    //==============================================
    // Process_1Lep2fatjet:
    // This function gets called during the event looping.
    // This is where one sets the variables used for the category 1Lep2fatjet.
    //==============================================

    Process_1Lep2fatjet_Selection();


    // Set variables used in this category.
    // If histograms are booked with these variables the histograms will be filled automatically.
    // Please follow the convention of <category>_<varname> structure.

    // Example of reading from Nano
    // std::vector<LorentzVector> electron_p4s = nt.Electron_p4(); // nt is a global variable that accesses NanoAOD
    // std::vector<float> electron_mvaTTH = nt.Electron_mvaTTH(); // electron ttH MVA scores from NanoAOD
    // Semi-complete list of NanoAOD for 102X can be found here: https://cms-nanoaod-integration.web.cern.ch/integration/master-102X/mc102X_doc.html
    // Also consult here: https://github.com/cmstas/NanoTools/blob/d641a6d6c1aa9ecc8094a1af73d5e1bd7d6502ab/NanoCORE/Nano.h#L4875 (if new variables are added they may show up in master)
}
