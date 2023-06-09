#include "Process_E.h"

//_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
void Process_E_Event()
{
    //~~~~~~~
    // Event
    //~~~~~~~
    const int& isData = ana.tx.getBranch<int>("Common_isData");
    const int& run = ana.tx.getBranch<int>("Common_run");
    const int& lumi = ana.tx.getBranch<int>("Common_lumi");
    const unsigned long long& evt = ana.tx.getBranch<int>("Common_evt");
    const int& year = ana.tx.getBranch<int>("Common_year");
    const float& genWeight = ana.tx.getBranch<float>("Common_genWeight");
    const float& wgt = ana.tx.getBranch<float>("Common_wgt");
    const vector<float>& LHEReweightingWeight = ana.tx.getBranchLazy<vector<float>>("Common_LHEReweightingWeight");
    const vector<float>& PDF = ana.tx.getBranchLazy<vector<float>>("Common_event_PDF");
    const vector<float>& QCDScale = ana.tx.getBranchLazy<vector<float>>("Common_event_QCDScale");

    //-----------------
    // Set the branches
    //-----------------
    ana.txskim.setBranch<int>("isData", isData);
    ana.txskim.setBranch<int>("run", run);
    ana.txskim.setBranch<int>("lumi", lumi);
    ana.txskim.setBranch<unsigned long long>("evt", evt);
    ana.txskim.setBranch<int>("year", year);
    ana.txskim.setBranch<float>("genWeight", genWeight);
    ana.txskim.setBranch<float>("wgt", wgt);
    ana.txskim.setBranch<vector<float>>("LHEReweightingWeight", LHEReweightingWeight);
    ana.txskim.setBranch<vector<float>>("PDF", PDF);
    ana.txskim.setBranch<vector<float>>("QCDScale", QCDScale);

}

// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

//_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
void Process_E_Leptons()
{
    //~~~~~~~~
    // Leptons
    //~~~~~~~~

    // VetoID lepton counter
    int nVetoLep = ana.tx.getBranchLazy<vector<LV>>("Common_lep_p4").size();

    // TightID lepton counter
    int nTightLep = 0;
    for (auto& istight : ana.tx.getBranchLazy<vector<int>>("Common_lep_tight"))
    {
        if (istight)
            nTightLep++;
    }

    // Lepton event categorization
    int is0Lep = (nVetoLep == 0);
    int is1Lep = (nVetoLep == 1) and (nTightLep == 1);

    int LepFlav = -999;
    if (is1Lep)
        LepFlav = ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0];

    LV Lep = nVetoLep > 0 ? ana.tx.getBranchLazy<vector<LV>>("Common_lep_p4")[0] : LV();

    //-----------------
    // Set the branches
    //-----------------
    ana.txskim.setBranch<int>("is0Lep", is0Lep);
    ana.txskim.setBranch<int>("is1Lep", is1Lep);
    ana.txskim.setBranch<int>("LepFlav", LepFlav);
    ana.txskim.setBranch<LV>("Lep", Lep);
}

// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

//_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
void Process_E_Trigger()
{

    const int& is0Lep = ana.txskim.getBranch<int>("is0Lep");
    const int& is1Lep = ana.txskim.getBranch<int>("is1Lep");
    const int& year = ana.txskim.getBranch<int>("year");
    const int& isData = ana.txskim.getBranch<int>("isData");
    const int& LepFlav = ana.txskim.getBranch<int>("LepFlav");

    //~~~~~~~~
    // Trigger
    //~~~~~~~~

    int trigger = 0;
    if (is0Lep)
    {
        if (year == 2018 or year == 2017)
        {
            trigger = ana.tx.getBranchLazy<bool>("Common_HLT_PFHT1050") or
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet500") or
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet360_TrimMass30") or
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet380_TrimMass30") or
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet400_TrimMass30") or
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet420_TrimMass30") or
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT750_TrimMass50") or
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT800_TrimMass50") or
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT850_TrimMass50") or
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT900_TrimMass50");
        }
        else if (year == 2016)
        {
            trigger = ana.tx.getBranchLazy<bool>("Common_HLT_PFHT650_WideJetMJJ900DEtaJJ1p5") or
                ana.tx.getBranchLazy<bool>("Common_HLT_PFHT650_WideJetMJJ950DEtaJJ1p5") or
                ana.tx.getBranchLazy<bool>("Common_HLT_PFHT800") or
                ana.tx.getBranchLazy<bool>("Common_HLT_PFHT900") or
                ana.tx.getBranchLazy<bool>("Common_HLT_PFJet450") or
                ana.tx.getBranchLazy<bool>("Common_HLT_PFJet500") or
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet450") or
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet500") or
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFJet360_TrimMass30") or
                ana.tx.getBranchLazy<bool>("Common_HLT_AK8PFHT700_TrimR0p1PT0p03Mass50");
        }
        else
        {
            RooUtil::error(TString::Format("year = %d is not recognized!", year), "Process_E.cc");
        }
    }
    else if (is1Lep)
    {
        if (isData)
        {
            bool passEle = ana.input_file_list_tstring.Contains("EGamma") and abs(LepFlav) == 11 and ana.tx.getBranchLazy<bool>("Common_HLT_Ele32_WPTight");
            bool passMu = ana.input_file_list_tstring.Contains("SingleMuon") and abs(LepFlav) == 13 and ana.tx.getBranchLazy<bool>("Common_HLT_IsoMu24");
            if (passEle || passMu)
                trigger = true;
        }
        else
        {
            if (abs(LepFlav) == 11 and ana.tx.getBranchLazy<bool>("Common_HLT_Ele32_WPTight"))
                trigger = true;
            if (abs(LepFlav) == 13 and ana.tx.getBranchLazy<bool>("Common_HLT_IsoMu24"))
                trigger = true;
        }
    }
    else
    {
        // if it is not either 0 or 1 lep we don't have a trigger we use (for now)
        trigger = 0;
    }

    //-----------------
    // Set the branches
    //-----------------
    ana.txskim.setBranch<int>("trigger", trigger);

}

// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

//_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
void Process_E_Gen()
{
    //~~~~~~~~~~~~~~~~~~~
    // 3V->6F gen vectors
    //~~~~~~~~~~~~~~~~~~~

    LV GenV0;
    LV GenV1;
    LV GenV2;
    int isHad0 = -999;
    int isHad1 = -999;
    int isHad2 = -999;
    LV GenF00;
    LV GenF01;
    LV GenF10;
    LV GenF11;
    LV GenF20;
    LV GenF21;

    vector<LV> fermions;
    vector<int> ishadrons;
    for (auto &idx : ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_idx"))
    {
        const LV &gen_p4 = nt.GenPart_p4()[idx];
        const int &gen_pdgid = nt.GenPart_pdgId()[idx];
        fermions.push_back(gen_p4);
        ishadrons.push_back(abs(gen_pdgid) <= 5);
    }

    // following is also always 6 entries
    // For signal, the first two entry in the "bosons" are the same boson (3, 4th is the same, and 5, 6th is the same)
    vector<LV> bosons;
    vector<int> pdgids;
    for (auto &idx : ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_mother_idx"))
    {
        const LV &gen_p4 = nt.GenPart_p4()[idx];
        const int &gen_pdgid = nt.GenPart_pdgId()[idx];
        bosons.push_back(gen_p4);
        pdgids.push_back(gen_pdgid);
    }

    // When the size is 6 we have something to do (either signal or some background samples)
    if (bosons.size() == 6)
    {
        // obtain the ordering based on the boson pts
        float pt0 = bosons[0].pt(); // first boson
        float pt1 = bosons[2].pt(); // second boson
        float pt2 = bosons[4].pt(); // third boson
        std::vector<float> input = {pt0, pt1, pt2};
        std::vector<int> order(3);
        std::iota(order.begin(), order.end(), 0); // initialize order to 0, 1, 2, ..., n-1
        std::sort(order.begin(), order.end(), [&](int i, int j) { return input[i] > input[j]; });
        int V0idx = 2 * order[0];
        int V1idx = 2 * order[1];
        int V2idx = 2 * order[2];
        GenV0 = bosons[V0idx];
        GenV1 = bosons[V1idx];
        GenV2 = bosons[V2idx];
        isHad0 = ishadrons[V0idx];
        isHad1 = ishadrons[V1idx];
        isHad2 = ishadrons[V2idx];
        const LV &f0a = fermions[2 * order[0]];
        const LV &f0b = fermions[2 * order[0] + 1];
        const LV &f1a = fermions[2 * order[1]];
        const LV &f1b = fermions[2 * order[1] + 1];
        const LV &f2a = fermions[2 * order[2]];
        const LV &f2b = fermions[2 * order[2] + 1];
        GenF00 = f0a.pt() > f0b.pt() ? f0a : f0b;
        GenF01 = f0a.pt() <= f0b.pt() ? f0a : f0b;
        GenF10 = f1a.pt() > f1b.pt() ? f1a : f1b;
        GenF11 = f1a.pt() <= f1b.pt() ? f1a : f1b;
        GenF20 = f2a.pt() > f2b.pt() ? f2a : f2b;
        GenF21 = f2a.pt() <= f2b.pt() ? f2a : f2b;
    }

    ana.txskim.setBranch<LV>("GenV0", GenV0);
    ana.txskim.setBranch<LV>("GenV1", GenV1);
    ana.txskim.setBranch<LV>("GenV2", GenV2);
    ana.txskim.setBranch<int>("isHad0", isHad0);
    ana.txskim.setBranch<int>("isHad1", isHad1);
    ana.txskim.setBranch<int>("isHad2", isHad2);
    ana.txskim.setBranch<LV>("GenF00", GenF00);
    ana.txskim.setBranch<LV>("GenF01", GenF01);
    ana.txskim.setBranch<LV>("GenF10", GenF10);
    ana.txskim.setBranch<LV>("GenF11", GenF11);
    ana.txskim.setBranch<LV>("GenF20", GenF20);
    ana.txskim.setBranch<LV>("GenF21", GenF21);
}


// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

//_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
void Process_E_FatJets()
{
    //~~~~~~~~~
    // Fat-jets
    //~~~~~~~~~

    // vector<TString> variations = {"", "JESUp", "JESDn", "JERUp", "JERDn", "JMSUp", "JMSDn", "JMRUp", "JMRDn"};

    // VetoID FatJets 4-vector with MSD as mass, and scores
    map<TString, vector<LV>> fatjet_p4s;
    map<TString, vector<float>> fatjet_VMDs;
    map<TString, vector<float>> fatjet_WMDs;
    map<TString, vector<LV>> noVMD_fatjet_p4s;
    map<TString, vector<float>> noVMD_fatjet_VMDs;
    map<TString, vector<float>> noVMD_fatjet_WMDs;

    for (unsigned int ifatjet = 0; ifatjet < nt.FatJet_p4().size(); ++ifatjet)
    {

        if (not nt.FatJet_jetId()[ifatjet] >= 6)
            continue;

        // Because every muon and electron shows up in PF FatJet collections
        // Need to check against leptons
        bool is_overlapping_with_a_lepton = false;

        // Overlap check against leptons (electrons)
        for (unsigned int ilep = 0; ilep < ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size(); ++ilep)
        {
            int ilep_idx = ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[ilep];
            // If electron
            if (abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[ilep]) == 11)
            {
                if (RooUtil::Calc::DeltaR(nt.FatJet_p4()[ifatjet], nt.Electron_p4()[ilep_idx]) < 0.8)
                {
                    is_overlapping_with_a_lepton = true;
                    break;
                }
            }
            // else muon
            else
            {
                if (RooUtil::Calc::DeltaR(nt.FatJet_p4()[ifatjet], nt.Muon_p4()[ilep_idx]) < 0.8)
                {
                    is_overlapping_with_a_lepton = true;
                    break;
                }
            }
        }

        if (is_overlapping_with_a_lepton) continue;

        map<TString, LorentzVector> fatjet_p4;
        map<TString, float> fatjet_msoftdrop;
        if (ana.is_postprocessed)
        {
            fatjet_msoftdrop[""]      = nt.FatJet_msoftdrop_nom()[ifatjet]          / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]; // undo the W-JMS correction
            fatjet_msoftdrop["JESUp"] = nt.FatJet_msoftdrop_jesTotalUp()[ifatjet]   / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet];
            fatjet_msoftdrop["JESDn"] = nt.FatJet_msoftdrop_jesTotalDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet];
            fatjet_msoftdrop["JERUp"] = nt.FatJet_msoftdrop_jerUp()[ifatjet]        / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet];
            fatjet_msoftdrop["JERDn"] = nt.FatJet_msoftdrop_jerDown()[ifatjet]      / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet];
            fatjet_msoftdrop["JMSUp"] = nt.FatJet_msoftdrop_jmsUp()[ifatjet]        / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet];
            fatjet_msoftdrop["JMSDn"] = nt.FatJet_msoftdrop_jmsDown()[ifatjet]      / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet];
            fatjet_msoftdrop["JMRUp"] = nt.FatJet_msoftdrop_jmrUp()[ifatjet]        / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet];
            fatjet_msoftdrop["JMRDn"] = nt.FatJet_msoftdrop_jmrDown()[ifatjet]      / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet];

            fatjet_p4[""]      = LorentzVector(nt.FatJet_pt_nom()[ifatjet]          , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop[""]     );
            fatjet_p4["JESUp"] = LorentzVector(nt.FatJet_pt_jesTotalUp()[ifatjet]   , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JESUp"]);
            fatjet_p4["JESDn"] = LorentzVector(nt.FatJet_pt_jesTotalDown()[ifatjet] , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JESDn"]);
            fatjet_p4["JERUp"] = LorentzVector(nt.FatJet_pt_jerUp()[ifatjet]        , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JERUp"]);
            fatjet_p4["JERDn"] = LorentzVector(nt.FatJet_pt_jerDown()[ifatjet]      , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JERDn"]);
            fatjet_p4["JMSUp"] = LorentzVector(nt.FatJet_pt_nom()[ifatjet]          , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JMSUp"]);
            fatjet_p4["JMSDn"] = LorentzVector(nt.FatJet_pt_nom()[ifatjet]          , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JMSDn"]);
            fatjet_p4["JMRUp"] = LorentzVector(nt.FatJet_pt_nom()[ifatjet]          , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JMRUp"]);
            fatjet_p4["JMRDn"] = LorentzVector(nt.FatJet_pt_nom()[ifatjet]          , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JMRDn"]);
        }
        else
        {
            fatjet_msoftdrop[""]      = nt.FatJet_msoftdrop()[ifatjet];
            fatjet_msoftdrop["JESUp"] = nt.FatJet_msoftdrop()[ifatjet];
            fatjet_msoftdrop["JESDn"] = nt.FatJet_msoftdrop()[ifatjet];
            fatjet_msoftdrop["JERUp"] = nt.FatJet_msoftdrop()[ifatjet];
            fatjet_msoftdrop["JERDn"] = nt.FatJet_msoftdrop()[ifatjet];
            fatjet_msoftdrop["JMSUp"] = nt.FatJet_msoftdrop()[ifatjet];
            fatjet_msoftdrop["JMSDn"] = nt.FatJet_msoftdrop()[ifatjet];
            fatjet_msoftdrop["JMRUp"] = nt.FatJet_msoftdrop()[ifatjet];
            fatjet_msoftdrop["JMRDn"] = nt.FatJet_msoftdrop()[ifatjet];

            fatjet_p4[""]      = LorentzVector(nt.FatJet_pt()[ifatjet] , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop[""]     );
            fatjet_p4["JESUp"] = LorentzVector(nt.FatJet_pt()[ifatjet] , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JESUp"]);
            fatjet_p4["JESDn"] = LorentzVector(nt.FatJet_pt()[ifatjet] , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JESDn"]);
            fatjet_p4["JERUp"] = LorentzVector(nt.FatJet_pt()[ifatjet] , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JERUp"]);
            fatjet_p4["JERDn"] = LorentzVector(nt.FatJet_pt()[ifatjet] , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JERDn"]);
            fatjet_p4["JMSUp"] = LorentzVector(nt.FatJet_pt()[ifatjet] , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JMSUp"]);
            fatjet_p4["JMSDn"] = LorentzVector(nt.FatJet_pt()[ifatjet] , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JMSDn"]);
            fatjet_p4["JMRUp"] = LorentzVector(nt.FatJet_pt()[ifatjet] , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JMRUp"]);
            fatjet_p4["JMRDn"] = LorentzVector(nt.FatJet_pt()[ifatjet] , nt.FatJet_eta()[ifatjet] , nt.FatJet_phi()[ifatjet] , fatjet_msoftdrop["JMRDn"]);
        }

        // computed with instructions from NanoAOD reference "For W vs QCD tagging, use (Xcc+Xqq)/(Xcc+Xqq+QCD)"
        float VMD = (nt.FatJet_particleNetMD_Xbb()[ifatjet] + nt.FatJet_particleNetMD_Xcc()[ifatjet] + nt.FatJet_particleNetMD_Xqq()[ifatjet]) / (nt.FatJet_particleNetMD_Xbb()[ifatjet] + nt.FatJet_particleNetMD_Xcc()[ifatjet] + nt.FatJet_particleNetMD_Xqq()[ifatjet] + nt.FatJet_particleNetMD_QCD()[ifatjet]);
        float WMD = (nt.FatJet_particleNetMD_Xcc()[ifatjet] + nt.FatJet_particleNetMD_Xqq()[ifatjet]) / (nt.FatJet_particleNetMD_Xcc()[ifatjet] + nt.FatJet_particleNetMD_Xqq()[ifatjet] + nt.FatJet_particleNetMD_QCD()[ifatjet]);

        for (auto& var : ana.variations)
        {
            // Figure this out
            if (not (fatjet_p4[var].pt() > 200.)) continue;
            if (not (abs(fatjet_p4[var].eta()) < 2.4)) continue;
            if (not (fatjet_msoftdrop[var] > 40.)) continue;

            // if (VMD > 0.2)
            if (true)
            {
                fatjet_p4s[var].push_back(fatjet_p4[var]);
                fatjet_VMDs[var].push_back(VMD);
                fatjet_WMDs[var].push_back(WMD);
            }
            else
            {
                noVMD_fatjet_p4s[var].push_back(fatjet_p4[var]);
                noVMD_fatjet_VMDs[var].push_back(VMD);
                noVMD_fatjet_WMDs[var].push_back(WMD);
            }
        }

    }

    for (auto& var : ana.variations)
    {
        ana.tx.setBranch<vector<LV>>(TString::Format("FJs%s", var.Data()), fatjet_p4s[var]);
        ana.txskim.setBranch<int>(TString::Format("NFJ%s", var.Data()), fatjet_p4s[var].size());
        ana.txskim.setBranch<LV>(TString::Format("FJ0%s", var.Data()), fatjet_p4s[var].size() > 0 ? fatjet_p4s[var][0] : LV());
        ana.txskim.setBranch<LV>(TString::Format("FJ1%s", var.Data()), fatjet_p4s[var].size() > 1 ? fatjet_p4s[var][1] : LV());
        ana.txskim.setBranch<LV>(TString::Format("FJ2%s", var.Data()), fatjet_p4s[var].size() > 2 ? fatjet_p4s[var][2] : LV());
        ana.txskim.setBranch<LV>(TString::Format("FJ3%s", var.Data()), fatjet_p4s[var].size() > 3 ? fatjet_p4s[var][3] : LV());
        ana.txskim.setBranch<LV>(TString::Format("FJ4%s", var.Data()), fatjet_p4s[var].size() > 4 ? fatjet_p4s[var][4] : LV());
        ana.txskim.setBranch<float>(TString::Format("VMD0%s", var.Data()), fatjet_VMDs[var].size() > 0 ? fatjet_VMDs[var][0] : -999);
        ana.txskim.setBranch<float>(TString::Format("VMD1%s", var.Data()), fatjet_VMDs[var].size() > 1 ? fatjet_VMDs[var][1] : -999);
        ana.txskim.setBranch<float>(TString::Format("VMD2%s", var.Data()), fatjet_VMDs[var].size() > 2 ? fatjet_VMDs[var][2] : -999);
        ana.txskim.setBranch<float>(TString::Format("VMD3%s", var.Data()), fatjet_VMDs[var].size() > 3 ? fatjet_VMDs[var][3] : -999);
        ana.txskim.setBranch<float>(TString::Format("VMD4%s", var.Data()), fatjet_VMDs[var].size() > 4 ? fatjet_VMDs[var][4] : -999);
        ana.txskim.setBranch<float>(TString::Format("WMD0%s", var.Data()), fatjet_WMDs[var].size() > 0 ? fatjet_WMDs[var][0] : -999);
        ana.txskim.setBranch<float>(TString::Format("WMD1%s", var.Data()), fatjet_WMDs[var].size() > 1 ? fatjet_WMDs[var][1] : -999);
        ana.txskim.setBranch<float>(TString::Format("WMD2%s", var.Data()), fatjet_WMDs[var].size() > 2 ? fatjet_WMDs[var][2] : -999);
        ana.txskim.setBranch<float>(TString::Format("WMD3%s", var.Data()), fatjet_WMDs[var].size() > 3 ? fatjet_WMDs[var][3] : -999);
        ana.txskim.setBranch<float>(TString::Format("WMD4%s", var.Data()), fatjet_WMDs[var].size() > 4 ? fatjet_WMDs[var][4] : -999);
        ana.tx.setBranch<vector<LV>>(TString::Format("iFJs%s", var.Data()), fatjet_p4s[var]);
        ana.txskim.setBranch<int>(TString::Format("NiFJ%s", var.Data()), noVMD_fatjet_p4s[var].size());
        ana.txskim.setBranch<LV>(TString::Format("iFJ0%s", var.Data()), noVMD_fatjet_p4s[var].size() > 0 ? noVMD_fatjet_p4s[var][0] : LV());
        ana.txskim.setBranch<LV>(TString::Format("iFJ1%s", var.Data()), noVMD_fatjet_p4s[var].size() > 1 ? noVMD_fatjet_p4s[var][1] : LV());
        ana.txskim.setBranch<LV>(TString::Format("iFJ2%s", var.Data()), noVMD_fatjet_p4s[var].size() > 2 ? noVMD_fatjet_p4s[var][2] : LV());
        ana.txskim.setBranch<LV>(TString::Format("iFJ3%s", var.Data()), noVMD_fatjet_p4s[var].size() > 3 ? noVMD_fatjet_p4s[var][3] : LV());
        ana.txskim.setBranch<LV>(TString::Format("iFJ4%s", var.Data()), noVMD_fatjet_p4s[var].size() > 4 ? noVMD_fatjet_p4s[var][4] : LV());
        ana.txskim.setBranch<float>(TString::Format("iVMD0%s", var.Data()), noVMD_fatjet_VMDs[var].size() > 0 ? noVMD_fatjet_VMDs[var][0] : -999);
        ana.txskim.setBranch<float>(TString::Format("iVMD1%s", var.Data()), noVMD_fatjet_VMDs[var].size() > 1 ? noVMD_fatjet_VMDs[var][1] : -999);
        ana.txskim.setBranch<float>(TString::Format("iVMD2%s", var.Data()), noVMD_fatjet_VMDs[var].size() > 2 ? noVMD_fatjet_VMDs[var][2] : -999);
        ana.txskim.setBranch<float>(TString::Format("iVMD3%s", var.Data()), noVMD_fatjet_VMDs[var].size() > 3 ? noVMD_fatjet_VMDs[var][3] : -999);
        ana.txskim.setBranch<float>(TString::Format("iVMD4%s", var.Data()), noVMD_fatjet_VMDs[var].size() > 4 ? noVMD_fatjet_VMDs[var][4] : -999);
        ana.txskim.setBranch<float>(TString::Format("iWMD0%s", var.Data()), noVMD_fatjet_WMDs[var].size() > 0 ? noVMD_fatjet_WMDs[var][0] : -999);
        ana.txskim.setBranch<float>(TString::Format("iWMD1%s", var.Data()), noVMD_fatjet_WMDs[var].size() > 1 ? noVMD_fatjet_WMDs[var][1] : -999);
        ana.txskim.setBranch<float>(TString::Format("iWMD2%s", var.Data()), noVMD_fatjet_WMDs[var].size() > 2 ? noVMD_fatjet_WMDs[var][2] : -999);
        ana.txskim.setBranch<float>(TString::Format("iWMD3%s", var.Data()), noVMD_fatjet_WMDs[var].size() > 3 ? noVMD_fatjet_WMDs[var][3] : -999);
        ana.txskim.setBranch<float>(TString::Format("iWMD4%s", var.Data()), noVMD_fatjet_WMDs[var].size() > 4 ? noVMD_fatjet_WMDs[var][4] : -999);
    }

    vector<int> NQGen = {0, 0, 0, 0, 0};
    vector<int> NBGen = {0, 0, 0, 0, 0};
    vector<int> NLGen = {0, 0, 0, 0, 0};

    map<TString, vector<int>> NQGens;
    map<TString, vector<int>> NBGens;
    map<TString, vector<int>> NLGens;

    for (auto& var : ana.variations)
    {
        NQGens[var] = NQGen;
        NBGens[var] = NBGen;
        NLGens[var] = NLGen;
    }

    // =========================================================
    // TTToSemiLeptonic sample categorization of leading fat-jet
    // =========================================================
    // - Categorize the fat-jet's gen-level information for TTToSemileptonic samples
    // - The matching for this is done on the leading fat-jet only (where we perform the scale factor calculations)
    if (ana.looper.getCurrentFileName().Contains("TTToSemi"))
    {

        // The parsing is done only on the TTToSemileptonic sample. (i.e. tt->WbWb->lvbjjb)

        // Get some gen level vectors
        const vector<int>& gen_pdgid = ana.tx.getBranchLazy<vector<int>>("Common_gen_pdgid");
        const vector<int>& gen_mother_id = ana.tx.getBranchLazy<vector<int>>("Common_gen_mother_id");
        const vector<LV>& gen_p4s = ana.tx.getBranchLazy<vector<LV>>("Common_gen_p4s");

        // Parse the Wlep b Whad b from the ttbar decay looping over the gen particles
        int hadwid = -1; // the pdgid of the hadronic W (to keep track of sign)
        // int lepwid = -1; // the pdgid of the leptonic W (to keep track of sign)
        LV b; // the b-quark
        LV antib; // the anti-b-quark
        LV hadb; // the b-quark from the top-quark where the top-quarks daughter  W's decaying hadronically
        LV q; // the quark from the hadronically decaying W
        LV antiq; // the quark from the hadronically decaying W

        for (unsigned int igen = 0; igen < gen_pdgid.size(); ++igen)
        {
            int id = gen_pdgid[igen];
            int mid = gen_mother_id[igen];
            LV p = gen_p4s[igen];

            // if (abs(id) >= 11 and abs(id) <= 16 and abs(mid) == 24)
            //     lepwid = mid;

            if (abs(id) >= 1 and abs(id) <= 6 and abs(mid) == 24)
            {
                if (id > 0)
                    q = p;
                if (id < 0)
                    antiq = p;
                hadwid = mid;
            }

            if (id == 5)
                b = p;

            if (id == -5)
                antib = p;
        }

        hadb = hadwid == 24 ? b : antib;
        // LV W = q + antiq;
        // LV t = W + hadb;

        for (auto& var : ana.variations)
        {
            if (fatjet_p4s[var].size() == 0)
                continue;

            // perform matching
            if (RooUtil::Calc::DeltaR(fatjet_p4s[var][0], q) < 0.8)
            {
                NQGens[var][0]++;
                NLGens[var][0]++;
            }
            if (RooUtil::Calc::DeltaR(fatjet_p4s[var][0], antiq) < 0.8)
            {
                NQGens[var][0]++;
                NLGens[var][0]++;
            }
            if (RooUtil::Calc::DeltaR(fatjet_p4s[var][0], hadb) < 0.8)
            {
                NQGens[var][0]++;
                NBGens[var][0]++;
            }
        }
    }
    // ==================================================================================
    // WWW/WWZ/WZZ/ZZZ sample categorization of fat-jets (up to 5 leading VetoID Fat Jet)
    // ==================================================================================
    // - Uses Common_gen_vvvdecay_idx to find the 6 decay fermions from tri-boson and match
    // - For each fat-jet, we count how many of the vvv's 6 decay fermions are included
    // - same categorization of number of quarks, b quarks, and light quarks are done.
    // - no check for whether two quarks from different mother is matched. (probably unlikely)
    // NOTE: Background samples are also falling here!
    // I do not know what happens for bkg samples, but for TTToHad for example it kind of interestingly is doing something!!!
    else
    {
        for (auto& idx : ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_idx"))
        {
            const LV& gen_p4 = nt.GenPart_p4()[idx];
            const int& gen_pdgid = nt.GenPart_pdgId()[idx];

            for (auto& var : ana.variations)
            {
                for (unsigned int fatjet_i = 0; fatjet_i < fatjet_p4s[var].size() and fatjet_i < 5; ++fatjet_i)
                {
                    const LV& fatjet_p4 = fatjet_p4s[var][fatjet_i];
                    float dr = RooUtil::Calc::DeltaR(fatjet_p4, gen_p4);
                    if (dr < 0.8)
                    {
                        if (abs(gen_pdgid) == 5)
                        {
                            NBGens[var][fatjet_i]++;
                            NQGens[var][fatjet_i]++;
                        }
                        else if (abs(gen_pdgid) < 5)
                        {
                            NLGens[var][fatjet_i]++;
                            NQGens[var][fatjet_i]++;
                        }
                    }
                }
            }
        }
    }

    for (auto& var : ana.variations)
    {
        ana.txskim.setBranch<int>(TString::Format("NQGen0%s", var.Data()), NQGens[var][0]);
        ana.txskim.setBranch<int>(TString::Format("NQGen1%s", var.Data()), NQGens[var][1]);
        ana.txskim.setBranch<int>(TString::Format("NQGen2%s", var.Data()), NQGens[var][2]);
        ana.txskim.setBranch<int>(TString::Format("NQGen3%s", var.Data()), NQGens[var][3]);
        ana.txskim.setBranch<int>(TString::Format("NQGen4%s", var.Data()), NQGens[var][4]);
        ana.txskim.setBranch<int>(TString::Format("NBGen0%s", var.Data()), NBGens[var][0]);
        ana.txskim.setBranch<int>(TString::Format("NBGen1%s", var.Data()), NBGens[var][1]);
        ana.txskim.setBranch<int>(TString::Format("NBGen2%s", var.Data()), NBGens[var][2]);
        ana.txskim.setBranch<int>(TString::Format("NBGen3%s", var.Data()), NBGens[var][3]);
        ana.txskim.setBranch<int>(TString::Format("NBGen4%s", var.Data()), NBGens[var][4]);
        ana.txskim.setBranch<int>(TString::Format("NLGen0%s", var.Data()), NLGens[var][0]);
        ana.txskim.setBranch<int>(TString::Format("NLGen1%s", var.Data()), NLGens[var][1]);
        ana.txskim.setBranch<int>(TString::Format("NLGen2%s", var.Data()), NLGens[var][2]);
        ana.txskim.setBranch<int>(TString::Format("NLGen3%s", var.Data()), NLGens[var][3]);
        ana.txskim.setBranch<int>(TString::Format("NLGen4%s", var.Data()), NLGens[var][4]);
    }
}

// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

//_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
void Process_E_MET()
{

    //~~~~~~
    // MET
    //~~~~~~
    map<TString, LV> MET;
    MET[""]      = ana.tx.getBranch<LV>("Common_met_p4");
    MET["JESUp"] = ana.tx.getBranch<LV>("Common_met_p4");
    MET["JESDn"] = ana.tx.getBranch<LV>("Common_met_p4");
    MET["JERUp"] = ana.tx.getBranch<LV>("Common_met_p4");
    MET["JERDn"] = ana.tx.getBranch<LV>("Common_met_p4");
    MET["JMSUp"] = ana.tx.getBranch<LV>("Common_met_p4");
    MET["JMSDn"] = ana.tx.getBranch<LV>("Common_met_p4");
    MET["JMRUp"] = ana.tx.getBranch<LV>("Common_met_p4");
    MET["JMRDn"] = ana.tx.getBranch<LV>("Common_met_p4");

    //---------------------------------------------------------------------------------------------
    // MET selection
    //---------------------------------------------------------------------------------------------
    if (ana.is_postprocessed and not nt.isData())
    {
        MET[""]      = ana.tx.getBranch<LorentzVector>("Common_met_p4");
        MET["JESUp"] = ana.tx.getBranch<LorentzVector>("Common_met_p4_jesup");
        MET["JESDn"] = ana.tx.getBranch<LorentzVector>("Common_met_p4_jesdn");
        MET["JERUp"] = ana.tx.getBranch<LorentzVector>("Common_met_p4_jerup");
        MET["JERUp"] = ana.tx.getBranch<LorentzVector>("Common_met_p4_jerdn");
        MET["JMSUp"] = ana.tx.getBranch<LorentzVector>("Common_met_p4");
        MET["JMSDn"] = ana.tx.getBranch<LorentzVector>("Common_met_p4");
        MET["JMRUp"] = ana.tx.getBranch<LorentzVector>("Common_met_p4");
        MET["JMRUp"] = ana.tx.getBranch<LorentzVector>("Common_met_p4");
    }

    for (auto& var : ana.variations)
    {
        ana.txskim.setBranch<LV>(TString::Format("MET%s", var.Data()), MET[var]);
    }

    map<TString, LV> Nu;
    if (ana.txskim.getBranchLazy<int>("is1Lep"))
    {
        for (auto& var : ana.variations)
        {
            Nu[var] = getNeutrinoP4(MET[var], ana.txskim.getBranch<LV>("Lep"));
        }
    }

    for (auto& var : ana.variations)
    {
        ana.txskim.setBranch<LV>(TString::Format("MET%s", var.Data()), MET[var]);
        ana.txskim.setBranch<LV>(TString::Format("Nu%s", var.Data()), Nu[var]);
    }
}

// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

//_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
void Process_E_Jets()
{
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // AK4-jets (OR against leptons in Common and OR against Fat-Jets here)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // AK4 jets overlap removed against the fat-jet (in the following loop) and leptons (in Common)
    map<TString, vector<LV>> jet_p4s;

    // B-tagging counters with AK4 jets overlap removed against fat-jet
    map<TString, int> NbLoose;
    map<TString, int> NbMedium;
    map<TString, int> NbTight;
    map<TString, int> NoORNbLoose;
    map<TString, int> NoORNbMedium;
    map<TString, int> NoORNbTight;

    map<TString, int> NJ;

    for (auto& var : ana.variations)
    {

        // Loop over the AK4 jets and compute relevant variables
        // (In common, the Common_jet_p4 are saved if the jet is pT > 20 and eta < 3)
        for (unsigned jet_i = 0; jet_i < ana.tx.getBranchLazy<vector<LV>>("Common_jet_p4").size(); ++jet_i)
        {

            if (not ana.tx.getBranchLazy<vector<int>>("Common_jet_id")[jet_i] >= 6)
                continue;

            // AK4 4-vector
            const LV& jet_p4 = ana.tx.getBranchLazy<vector<LV>>("Common_jet_p4")[jet_i];

            const vector<LV>& FJs = ana.tx.getBranch<vector<LV>>(TString::Format("FJs%s", var.Data()));

            // No OR b-tagging
            // b-tag counting
            if (abs(jet_p4.eta()) < 2.4)
            {
                bool pass_loose = ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBloose")[jet_i];
                bool pass_medium = ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBmedium")[jet_i];
                bool pass_tight = ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBtight")[jet_i];
                if (pass_loose) NoORNbLoose[var]++;
                if (pass_medium) NoORNbMedium[var]++;
                if (pass_tight) NoORNbTight[var]++;
            }

            // Checking against FatJets
            bool is_overlapping_with_fatjet = false; // OR against lepton already checked in Process_Common
            for (unsigned fatjet_i = 0; fatjet_i < FJs.size(); ++fatjet_i)
            {
                const LV& fatjet_p4 = FJs[fatjet_i];
                float dR = RooUtil::Calc::DeltaR(jet_p4, fatjet_p4);

                // OR condition
                if (dR < 0.8)
                {
                    is_overlapping_with_fatjet = true;
                    break;
                }
            }

            // if overlapping skip the AK4-jet
            if (is_overlapping_with_fatjet)
                continue;

            // With OR b-tagging
            // b-tag counting
            if (abs(jet_p4.eta()) < 2.4)
            {
                bool pass_loose = ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBloose")[jet_i];
                bool pass_medium = ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBmedium")[jet_i];
                bool pass_tight = ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBtight")[jet_i];
                if (pass_loose) NbLoose[var]++;
                if (pass_medium) NbMedium[var]++;
                if (pass_tight) NbTight[var]++;
            }

            // After b-tagging counting now we focus only on jets with pT > 30
            if (not (jet_p4.pt() > 30))
                continue;

            // Save the AK4 jets
            jet_p4s[var].push_back(jet_p4);
        }

        NJ[var] = jet_p4s[var].size();

        ana.txskim.setBranch<vector<LV>>(TString::Format("Js%s", var.Data()), jet_p4s[var]);
        ana.txskim.setBranch<int>(TString::Format("NJ%s", var.Data()), NJ[var]);
        ana.txskim.setBranch<int>(TString::Format("NbLoose%s", var.Data()), NbLoose[var]);
        ana.txskim.setBranch<int>(TString::Format("NbMedium%s", var.Data()), NbMedium[var]);
        ana.txskim.setBranch<int>(TString::Format("NbTight%s", var.Data()), NbTight[var]);
        ana.txskim.setBranch<int>(TString::Format("NoORNbLoose%s", var.Data()), NoORNbLoose[var]);
        ana.txskim.setBranch<int>(TString::Format("NoORNbMedium%s", var.Data()), NoORNbMedium[var]);
        ana.txskim.setBranch<int>(TString::Format("NoORNbTight%s", var.Data()), NoORNbTight[var]);
        ana.txskim.setBranch<LorentzVector>(TString::Format("J0%s", var.Data()), jet_p4s[var].size() > 0 ? jet_p4s[var][0] : LV());
        ana.txskim.setBranch<LorentzVector>(TString::Format("J1%s", var.Data()), jet_p4s[var].size() > 1 ? jet_p4s[var][1] : LV());
        ana.txskim.setBranch<LorentzVector>(TString::Format("J2%s", var.Data()), jet_p4s[var].size() > 2 ? jet_p4s[var][2] : LV());
        ana.txskim.setBranch<LorentzVector>(TString::Format("J3%s", var.Data()), jet_p4s[var].size() > 3 ? jet_p4s[var][3] : LV());
        ana.txskim.setBranch<LorentzVector>(TString::Format("J4%s", var.Data()), jet_p4s[var].size() > 4 ? jet_p4s[var][4] : LV());
        ana.txskim.setBranch<LorentzVector>(TString::Format("J5%s", var.Data()), jet_p4s[var].size() > 5 ? jet_p4s[var][5] : LV());
        ana.txskim.setBranch<LorentzVector>(TString::Format("J6%s", var.Data()), jet_p4s[var].size() > 6 ? jet_p4s[var][6] : LV());
        ana.txskim.setBranch<LorentzVector>(TString::Format("J7%s", var.Data()), jet_p4s[var].size() > 7 ? jet_p4s[var][7] : LV());
    }

    map<TString, vector<int>> NQGens;
    map<TString, vector<int>> NBGens;
    map<TString, vector<int>> NLGens;

    for (auto& var : ana.variations)
    {
        vector<int> zeros(NJ[var]);
        NQGens[var] = zeros;
        NBGens[var] = zeros;
        NLGens[var] = zeros;
    }

    // ==================================================================================
    // WWW/WWZ/WZZ/ZZZ sample categorization of jets (up to 8 leading VetoID Jet)
    // ==================================================================================
    // - Uses Common_gen_vvvdecay_idx to find the 6 decay fermions from tri-boson and match
    // - For each fat-jet, we count how many of the vvv's 6 decay fermions are included
    // - same categorization of number of quarks, b quarks, and light quarks are done.
    // - no check for whether two quarks from different mother is matched. (probably unlikely)
    // NOTE: Background samples are also falling here!
    // I do not know what happens for bkg samples, but for TTToHad for example it kind of interestingly is doing something!!!
    for (auto& idx : ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_idx"))
    {
        const LV& gen_p4 = nt.GenPart_p4()[idx];
        const int& gen_pdgid = nt.GenPart_pdgId()[idx];

        for (auto& var : ana.variations)
        {
            for (unsigned int jet_i = 0; jet_i < jet_p4s[var].size() and jet_i < 5; ++jet_i)
            {
                const LV& jet_p4 = jet_p4s[var][jet_i];
                float dr = RooUtil::Calc::DeltaR(jet_p4, gen_p4);
                if (dr < 0.4)
                {
                    if (abs(gen_pdgid) == 5)
                    {
                        NBGens[var][jet_i]++;
                        NQGens[var][jet_i]++;
                    }
                    else if (abs(gen_pdgid) < 5)
                    {
                        NLGens[var][jet_i]++;
                        NQGens[var][jet_i]++;
                    }
                }
            }
        }
    }

    for (auto& var : ana.variations)
    {
        ana.txskim.setBranch<vector<int>>(TString::Format("NQJGen%s", var.Data()), NQGens[var]);
        ana.txskim.setBranch<vector<int>>(TString::Format("NBJGen%s", var.Data()), NQGens[var]);
        ana.txskim.setBranch<vector<int>>(TString::Format("NLJGen%s", var.Data()), NQGens[var]);
    }
}

// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

//_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
void Process_E_Kinematics()
{
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

    //~~~~~~~~~~~~~~~
    // HT Computation
    //~~~~~~~~~~~~~~~
    // Adding the remaining MET portion to the HT and HTFJ

    // HT with AK8 + AK4 + MET
    map<TString, float> HT;

    // HTJ with AK8 + AK4 (no MET)
    map<TString, float> HTJ;

    // HT with AK8 + MET
    map<TString, float> HTFJ;

    // Scalar Sum of AK8 PT
    map<TString, float> SumPtFJ;

    // Scalar Sum of AK4 PT
    map<TString, float> SumPtJ;

    // Two or three fatjet representing VV or VVV system 
    map<TString, LV> VVX;

    // Lep
    const int& is1Lep = ana.txskim.getBranch<int>("is1Lep");
    const LV& Lep = ana.txskim.getBranch<LV>("Lep");

    // If 0 lep add it up to 3 FJ, if 1 lep add it up to 2 FJ
    unsigned int max_NFJ_to_consider = is1Lep ? 2 : 3;

    for (auto& var : ana.variations)
    {

        const vector<LV>& fatjet_p4s = ana.tx.getBranchLazy<vector<LV>>(TString::Format("FJs%s", var.Data()));
        const vector<LV>& jet_p4s = ana.tx.getBranchLazy<vector<LV>>(TString::Format("Js%s", var.Data()));
        unsigned int NFJ = ana.txskim.getBranch<int>(TString::Format("NFJ%s", var.Data()));
        const LV& MET = ana.txskim.getBranch<LV>(TString::Format("MET%s", var.Data()));
        const LV& Nu = ana.txskim.getBranch<LV>(TString::Format("Nu%s", var.Data()));

        // Sum the AK8
        for (unsigned int fatjet_i = 0; fatjet_i < 3 and fatjet_i < NFJ; ++fatjet_i)
        {
            const LV& AK8 = fatjet_p4s[fatjet_i];
            HT[var] += AK8.pt();
            HTJ[var] += AK8.pt();
            HTFJ[var] += AK8.pt();
            SumPtFJ[var] += AK8.pt();
        }

        // Sum the AK4
        for (auto& AK4 : jet_p4s)
        {
            HT[var] += AK4.pt();
            HTJ[var] += AK4.pt();
            SumPtJ[var] += AK4.pt();
        }

        // Sum the MET
        HT[var] += MET.pt();
        HTFJ[var] += MET.pt();

        // if 1 lep add the lep + Nu
        if (is1Lep)
        {
            VVX[var] += Lep;
            VVX[var] += Nu;
        }

        // Add the FJ's
        for (unsigned int fatjet_i = 0; fatjet_i < NFJ and fatjet_i < max_NFJ_to_consider; fatjet_i++)
        {
            // Up to 3 fat-jets we add to the VV/VVV system 4-vector
            VVX[var] += fatjet_p4s[fatjet_i];
        }

        ana.txskim.setBranch<float>(TString::Format("MVVX%s", var.Data()), VVX[var].mass());
        ana.txskim.setBranch<float>(TString::Format("PtVVX%s", var.Data()), VVX[var].pt());
        ana.txskim.setBranch<float>(TString::Format("HT%s", var.Data()), HT[var]);
        ana.txskim.setBranch<float>(TString::Format("HTJ%s", var.Data()), HTJ[var]);
        ana.txskim.setBranch<float>(TString::Format("HTFJ%s", var.Data()), HTFJ[var]);
        ana.txskim.setBranch<float>(TString::Format("SumPtFJ%s", var.Data()), SumPtFJ[var]);
        ana.txskim.setBranch<float>(TString::Format("SumPtJ%s", var.Data()), SumPtJ[var]);

    }

}

// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
// --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

//_________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________
void Process_E()
{
    if (ana.region == 3)
    {
        if (nt.nFatJet() < 3) return;
    }
    else
    {
        if (nt.nFatJet() < 1) return;
    }
    Process_E_Event();
    Process_E_Leptons();
    Process_E_Trigger();
    Process_E_Gen();
    Process_E_FatJets();
    Process_E_MET();
    Process_E_Jets();
    Process_E_Kinematics();

}

void PostProcess_E()
{
    if (ana.cutflow.getCut("Cut_E_SkimSelection").pass)
        ana.txskim.fill();
}

LV getNeutrinoP4(LV MET, LV lep)
{
    const float MW_ = 80.385;

    double leppt = lep.pt();
    double lepphi = lep.phi();
    double lepeta = lep.eta();
    double lepenergy = lep.energy();

    double metpt = MET.pt();
    double metphi = MET.phi();

    double px = metpt * cos(metphi);
    double py = metpt * sin(metphi);
    double pz = 0;
    double pxl = leppt * cos(lepphi);
    double pyl = leppt * sin(lepphi);
    double pzl = leppt * sinh(lepeta);
    double El = lepenergy;
    double a = pow(MW_, 2) + pow(px + pxl, 2) + pow(py + pyl, 2) - px * px - py * py - El * El + pzl * pzl;
    double b = 2. * pzl;
    double A = b * b - 4. * El * El;
    double B = 2. * a * b;
    double C = a * a - 4. * (px * px + py * py) * El * El;

    ///////////////////////////pz for fnal
    double M_mu = 0;
    // if(lepType==1) M_mu=0.105658367;//mu
    // if(lepType==0) M_mu=0.00051099891;//electron

    int type = 2; // use the small abs real root

    a = MW_ * MW_ - M_mu * M_mu + 2.0 * pxl * px + 2.0 * pyl * py;
    A = 4.0 * (El * El - pzl * pzl);
    B = -4.0 * a * pzl;
    C = 4.0 * El * El * (px * px + py * py) - a * a;

    double tmproot = B * B - 4.0 * A * C;

    if (tmproot < 0)
    {
        // std::cout << "Complex root detected, taking real part..." << std::endl;
        pz = -B / (2 * A); // take real part of complex roots
    }
    else
    {
        double tmpsol1 = (-B + sqrt(tmproot)) / (2.0 * A);
        double tmpsol2 = (-B - sqrt(tmproot)) / (2.0 * A);
        // std::cout << " Neutrino Solutions: " << tmpsol1 << ", " << tmpsol2 << std::endl;

        if (type == 0)
        {
            // two real roots, pick the one closest to pz of muon
            if (TMath::Abs(tmpsol2 - pzl) < TMath::Abs(tmpsol1 - pzl))
            {
                pz = tmpsol2;
            }
            else
            {
                pz = tmpsol1;
            }
            // if pz is > 300 pick the most central root
            if (abs(pz) > 300.)
            {
                if (TMath::Abs(tmpsol1) < TMath::Abs(tmpsol2))
                {
                    pz = tmpsol1;
                }
                else
                {
                    pz = tmpsol2;
                }
            }
        }
        if (type == 1)
        {
            // two real roots, pick the one closest to pz of muon
            if (TMath::Abs(tmpsol2 - pzl) < TMath::Abs(tmpsol1 - pzl))
            {
                pz = tmpsol2;
            }
            else
            {
                pz = tmpsol1;
            }
        }
        if (type == 2)
        {
            // pick the most central root.
            if (TMath::Abs(tmpsol1) < TMath::Abs(tmpsol2))
            {
                pz = tmpsol1;
            }
            else
            {
                pz = tmpsol2;
            }
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

    } // endl of if real root

    // dont correct pt neutrino
    LV outP4;
    outP4.SetPxPyPzE(px, py, pz, sqrt(px * px + py * py + pz * pz));
    return outP4;
}
