#include "Process_E.h"

void Process_E()
{

    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

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

    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

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

    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

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


    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // Fat-jets (OR against leptons in Common)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // VetoID FatJet counter (see Process_Common.cc for VetoID FatJet: pT > 200, VMD > 0.2, MSD > 40)
    unsigned int NFJ = ana.tx.getBranchLazy<vector<LV>>("Common_fatjet_p4").size();

    // VetoID FatJets 4-vector with MSD as mass, and scores
    vector<LV> fatjet_p4s;
    vector<float> fatjet_VMDs;
    vector<float> fatjet_WMDs;

    // Two or three fatjet representing VV or VVV system 
    LV VVX;

    // Loop over Fat Jets to compute relevant variables
    for (unsigned fatjet_i = 0; fatjet_i < NFJ; ++fatjet_i)
    {
        // Obtaining a 4-vector with MSD as the mass
        const LV& fatjet_p4 = ana.tx.getBranchLazy<vector<LV>>("Common_fatjet_p4")[fatjet_i];
        const float& fatjet_msoftdrop = ana.tx.getBranchLazy<vector<float>>("Common_fatjet_msoftdrop")[fatjet_i];
        LV fatjet_p4_msd = RooUtil::Calc::getLV(fatjet_p4.pt(), fatjet_p4.eta(), fatjet_p4.phi(), fatjet_msoftdrop);

        // Save and keep track of them
        fatjet_p4s.push_back(fatjet_p4_msd);

        // Computing the scores for ParticleNet tagger
        float QCD = ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_QCD")[fatjet_i];
        float Xqq = ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_Xqq")[fatjet_i];
        float Xbb = ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_Xbb")[fatjet_i];
        float Xcc = ana.tx.getBranchLazy<vector<float>>("Common_fatjet_particleNetMD_Xcc")[fatjet_i];
        float VMD = (Xqq + Xcc + Xbb) / (Xqq + Xcc + Xbb + QCD);
        float WMD = (Xqq + Xcc) / (Xqq + Xcc + QCD);
        fatjet_VMDs.push_back(VMD);
        fatjet_WMDs.push_back(WMD);

        // Up to 3 fat-jets we add to the VV/VVV system 4-vector
        if (fatjet_i < 3)
        {
            VVX += fatjet_p4_msd;
        }
    }

    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // AK4-jets (OR against leptons in Common and OR against Fat-Jets here)
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // AK4 jets overlap removed against the fat-jet (in the following loop) and leptons (in Common)
    vector<LV> jet_p4s;

    // B-tagging counters with AK4 jets overlap removed against fat-jet
    int NbLoose = 0;
    int NbMedium = 0;
    int NbTight = 0;

    // Loop over the AK4 jets and compute relevant variables
    // (In common, the Common_jet_p4 are saved if the jet is pT > 20 and eta < 3)
    for (unsigned jet_i = 0; jet_i < ana.tx.getBranchLazy<vector<LV>>("Common_jet_p4").size(); ++jet_i)
    {

        // AK4 4-vector
        const LV& jet_p4 = ana.tx.getBranchLazy<vector<LV>>("Common_jet_p4")[jet_i];

        // Checking against FatJets
        bool is_overlapping_with_fatjet = false; // OR against lepton already checked in Process_Common
        for (unsigned fatjet_i = 0; fatjet_i < NFJ; ++fatjet_i)
        {
            const LV& fatjet_p4 = ana.tx.getBranchLazy<vector<LV>>("Common_fatjet_p4")[fatjet_i];
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

        // b-tag counting
        if (abs(jet_p4.eta()) < 2.4)
        {
            bool pass_loose = ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBloose")[jet_i];
            bool pass_medium = ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBmedium")[jet_i];
            bool pass_tight = ana.tx.getBranchLazy<vector<bool>>("Common_jet_passBtight")[jet_i];
            if (pass_loose) NbLoose++;
            if (pass_medium) NbMedium++;
            if (pass_tight) NbTight++;
        }

        // After b-tagging counting now we focus only on jets with pT > 30
        if (not (jet_p4.pt() > 30))
            continue;

        // Save the AK4 jets
        jet_p4s.push_back(jet_p4);
    }

    // Count the number of AK4 jets
    unsigned int NJ = jet_p4s.size();



    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

    //~~~~~~
    // MET
    //~~~~~~
    LV MET = ana.tx.getBranch<LV>("Common_met_p4");


    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

    //~~~~~~~~~~~~~~~
    // HT Computation
    //~~~~~~~~~~~~~~~
    // Adding the remaining MET portion to the HT and HTFJ

    // HT with AK8 + AK4 + MET
    float HT = 0;

    // HTJ with AK8 + AK4 (no MET)
    float HTJ = 0;

    // HT with AK8 + MET
    float HTFJ = 0;

    // Scalar Sum of AK8 PT
    float SumPtFJ = 0;

    // Scalar Sum of AK4 PT
    float SumPtJ = 0;

    // Sum the AK8
    for (unsigned int fatjet_i = 0; fatjet_i < 3 and fatjet_i < NFJ; ++fatjet_i)
    {
        LV& AK8 = fatjet_p4s[fatjet_i];
        HT += AK8.pt();
        HTJ += AK8.pt();
        HTFJ += AK8.pt();
        SumPtFJ += AK8.pt();
    }

    // Sum the AK4
    for (auto& AK4 : jet_p4s)
    {
        HT += AK4.pt();
        HTJ += AK4.pt();
        SumPtJ += AK4.pt();
    }

    // Sum the MET
    HT += MET.pt();
    HTFJ += MET.pt();

    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

    //~~~~~~~~~~~~~~~~~~~~~~~~~~~
    // FatJet Gen categorizations
    //~~~~~~~~~~~~~~~~~~~~~~~~~~~

    vector<int> NQGen = {0, 0, 0, 0, 0};
    vector<int> NBGen = {0, 0, 0, 0, 0};
    vector<int> NLGen = {0, 0, 0, 0, 0};

    // =========================================================
    // TTToSemiLeptonic sample categorization of leading fat-jet
    // =========================================================
    // - Categorize the fat-jet's gen-level information for TTToSemileptonic samples
    // - The matching for this is done on the leading fat-jet only (where we perform the scale factor calculations)
    if (ana.looper.getCurrentFileName().Contains("TTToSemi") and fatjet_p4s.size() > 0)
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

        // perform matching
        if (RooUtil::Calc::DeltaR(fatjet_p4s[0], q) < 0.8)
        {
            NQGen[0]++;
            NLGen[0]++;
        }
        if (RooUtil::Calc::DeltaR(fatjet_p4s[0], antiq) < 0.8)
        {
            NQGen[0]++;
            NLGen[0]++;
        }
        if (RooUtil::Calc::DeltaR(fatjet_p4s[0], hadb) < 0.8)
        {
            NQGen[0]++;
            NBGen[0]++;
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
        for (auto& idx : ana.tx.getBranch<vector<int>>("Common_gen_vvvdecay_idx"))
        {
            const LV& gen_p4 = nt.GenPart_p4()[idx];
            const int& gen_pdgid = nt.GenPart_pdgId()[idx];
            for (unsigned int fatjet_i = 0; fatjet_i < fatjet_p4s.size() and fatjet_i < 5; ++fatjet_i)
            {
                const LV& fatjet_p4 = fatjet_p4s[fatjet_i];
                float dr = RooUtil::Calc::DeltaR(fatjet_p4, gen_p4);
                if (dr < 0.8)
                {
                    if (abs(gen_pdgid) == 5)
                    {
                        NBGen[fatjet_i]++;
                        NQGen[fatjet_i]++;
                    }
                    else if (abs(gen_pdgid) < 5)
                    {
                        NLGen[fatjet_i]++;
                        NQGen[fatjet_i]++;
                    }
                }
            }
        }
    }

    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

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
    for (auto& idx : ana.tx.getBranch<vector<int>>("Common_gen_vvvdecay_idx"))
    {
        const LV& gen_p4 = nt.GenPart_p4()[idx];
        const int& gen_pdgid = nt.GenPart_pdgId()[idx];
        fermions.push_back(gen_p4);
        ishadrons.push_back(abs(gen_pdgid) <= 5);
    }

    // following is also always 6 entries
    // For signal, the first two entry in the "bosons" are the same boson (3, 4th is the same, and 5, 6th is the same)
    vector<LV> bosons;
    vector<int> pdgids;
    for (auto& idx : ana.tx.getBranch<vector<int>>("Common_gen_vvvdecay_mother_idx"))
    {
        const LV& gen_p4 = nt.GenPart_p4()[idx];
        const int& gen_pdgid = nt.GenPart_pdgId()[idx];
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
        std::iota(order.begin(), order.end(), 0);  // initialize order to 0, 1, 2, ..., n-1
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
        const LV& f0a = fermions[2 * order[0]];
        const LV& f0b = fermions[2 * order[0] + 1];
        const LV& f1a = fermions[2 * order[1]];
        const LV& f1b = fermions[2 * order[1] + 1];
        const LV& f2a = fermions[2 * order[2]];
        const LV& f2b = fermions[2 * order[2] + 1];
        GenF00 = f0a.pt() >  f0b.pt() ? f0a : f0b;
        GenF01 = f0a.pt() <= f0b.pt() ? f0a : f0b;
        GenF10 = f1a.pt() >  f1b.pt() ? f1a : f1b;
        GenF11 = f1a.pt() <= f1b.pt() ? f1a : f1b;
        GenF20 = f2a.pt() >  f2b.pt() ? f2a : f2b;
        GenF21 = f2a.pt() <= f2b.pt() ? f2a : f2b;
    }

    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================
    // --------------------====================--------------------====================--------------------====================--------------------====================--------------------====================--------------------====================

    //~~~~~~~~~~~~~~~~~~~~~
    // Saving the variables
    //~~~~~~~~~~~~~~~~~~~~~
    LV empty;
    ana.txskim.setBranch<LV>("FJ0", fatjet_p4s.size() > 0 ? fatjet_p4s[0] : empty);
    ana.txskim.setBranch<LV>("FJ1", fatjet_p4s.size() > 1 ? fatjet_p4s[1] : empty);
    ana.txskim.setBranch<LV>("FJ2", fatjet_p4s.size() > 2 ? fatjet_p4s[2] : empty);
    ana.txskim.setBranch<LV>("FJ3", fatjet_p4s.size() > 3 ? fatjet_p4s[3] : empty);
    ana.txskim.setBranch<LV>("FJ4", fatjet_p4s.size() > 4 ? fatjet_p4s[4] : empty);
    ana.txskim.setBranch<LV>("Lep", nVetoLep > 0 ? ana.tx.getBranchLazy<vector<LV>>("Common_lep_p4")[0] : empty);
    ana.txskim.setBranch<LV>("MET", MET);
    ana.txskim.setBranch<LV>("J0", jet_p4s.size() > 0 ? jet_p4s[0] : empty);
    ana.txskim.setBranch<LV>("J1", jet_p4s.size() > 1 ? jet_p4s[1] : empty);
    ana.txskim.setBranch<LV>("J2", jet_p4s.size() > 2 ? jet_p4s[2] : empty);
    ana.txskim.setBranch<LV>("J3", jet_p4s.size() > 3 ? jet_p4s[3] : empty);
    ana.txskim.setBranch<LV>("J4", jet_p4s.size() > 4 ? jet_p4s[4] : empty);

    ana.txskim.setBranch<float>("VMD0", fatjet_VMDs.size() > 0 ? fatjet_VMDs[0] : -999);
    ana.txskim.setBranch<float>("VMD1", fatjet_VMDs.size() > 1 ? fatjet_VMDs[1] : -999);
    ana.txskim.setBranch<float>("VMD2", fatjet_VMDs.size() > 2 ? fatjet_VMDs[2] : -999);
    ana.txskim.setBranch<float>("VMD3", fatjet_VMDs.size() > 3 ? fatjet_VMDs[3] : -999);
    ana.txskim.setBranch<float>("VMD4", fatjet_VMDs.size() > 4 ? fatjet_VMDs[4] : -999);
    ana.txskim.setBranch<float>("WMD0", fatjet_WMDs.size() > 0 ? fatjet_WMDs[0] : -999);
    ana.txskim.setBranch<float>("WMD1", fatjet_WMDs.size() > 1 ? fatjet_WMDs[1] : -999);
    ana.txskim.setBranch<float>("WMD2", fatjet_WMDs.size() > 2 ? fatjet_WMDs[2] : -999);
    ana.txskim.setBranch<float>("WMD3", fatjet_WMDs.size() > 3 ? fatjet_WMDs[3] : -999);
    ana.txskim.setBranch<float>("WMD4", fatjet_WMDs.size() > 4 ? fatjet_WMDs[4] : -999);

    ana.txskim.setBranch<int>("NQGen0", NQGen[0]);
    ana.txskim.setBranch<int>("NQGen1", NQGen[1]);
    ana.txskim.setBranch<int>("NQGen2", NQGen[2]);
    ana.txskim.setBranch<int>("NQGen3", NQGen[3]);
    ana.txskim.setBranch<int>("NQGen4", NQGen[4]);
    ana.txskim.setBranch<int>("NBGen0", NBGen[0]);
    ana.txskim.setBranch<int>("NBGen1", NBGen[1]);
    ana.txskim.setBranch<int>("NBGen2", NBGen[2]);
    ana.txskim.setBranch<int>("NBGen3", NBGen[3]);
    ana.txskim.setBranch<int>("NBGen4", NBGen[4]);
    ana.txskim.setBranch<int>("NLGen0", NLGen[0]);
    ana.txskim.setBranch<int>("NLGen1", NLGen[1]);
    ana.txskim.setBranch<int>("NLGen2", NLGen[2]);
    ana.txskim.setBranch<int>("NLGen3", NLGen[3]);
    ana.txskim.setBranch<int>("NLGen4", NLGen[4]);

    ana.txskim.setBranch<int>("is0Lep", is0Lep);
    ana.txskim.setBranch<int>("is1Lep", is1Lep);
    ana.txskim.setBranch<int>("LepFlav", LepFlav);
    ana.txskim.setBranch<int>("NFJ", NFJ);
    ana.txskim.setBranch<int>("NJ", NJ);
    ana.txskim.setBranch<int>("NbLoose", NbLoose);
    ana.txskim.setBranch<int>("NbMedium", NbMedium);
    ana.txskim.setBranch<int>("NbTight", NbTight);
    ana.txskim.setBranch<float>("MVVX", VVX.mass());
    ana.txskim.setBranch<float>("PtVVX", VVX.pt());
    ana.txskim.setBranch<float>("HT", HT);
    ana.txskim.setBranch<float>("HTJ", HTJ);
    ana.txskim.setBranch<float>("HTFJ", HTFJ);
    ana.txskim.setBranch<float>("SumPtFJ", SumPtFJ);
    ana.txskim.setBranch<float>("SumPtJ", SumPtJ);

    ana.txskim.setBranch<int>("isData", isData);
    ana.txskim.setBranch<int>("run", run);
    ana.txskim.setBranch<int>("lumi", lumi);
    ana.txskim.setBranch<unsigned long long>("evt", evt);
    ana.txskim.setBranch<int>("year", year);
    ana.txskim.setBranch<float>("genWeight", genWeight);
    ana.txskim.setBranch<float>("wgt", wgt);

    ana.txskim.setBranch<int>("trigger", trigger);

    ana.txskim.setBranch<vector<float>>("LHEReweightingWeight", ana.tx.getBranch<vector<float>>("Common_LHEReweightingWeight"));

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

void PostProcess_E()
{
    if (ana.cutflow.getCut("Cut_E_SkimSelection").pass)
        ana.txskim.fill();
}
