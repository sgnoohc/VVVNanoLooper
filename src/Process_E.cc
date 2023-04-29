#include "Process_E.h"

void Process_E()
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



    //~~~~~~
    // MET
    //~~~~~~
    LV MET = ana.tx.getBranch<LV>("Common_met_p4");


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

    ana.txskim.setBranch<int>("is0Lep", is0Lep);
    ana.txskim.setBranch<int>("is1Lep", is1Lep);
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

    ana.txskim.setBranch<int>("isData", ana.tx.getBranch<int>("Common_isData"));
    ana.txskim.setBranch<int>("run", ana.tx.getBranch<int>("Common_run"));
    ana.txskim.setBranch<int>("lumi", ana.tx.getBranch<int>("Common_lumi"));
    ana.txskim.setBranch<unsigned long long>("evt", ana.tx.getBranch<unsigned long long>("Common_evt"));
    ana.txskim.setBranch<int>("year", ana.tx.getBranch<int>("Common_year"));
    ana.txskim.setBranch<float>("genWeight", ana.tx.getBranch<float>("Common_genWeight"));
    ana.txskim.setBranch<float>("wgt", ana.tx.getBranch<float>("Common_wgt"));

    ana.txskim.setBranch<vector<float>>("LHEReweightingWeight", ana.tx.getBranch<vector<float>>("Common_LHEReweightingWeight"));


    // FJ category (q, qq, bq, bqq, etc.)
}

void PostProcess_E()
{
    if (ana.cutflow.getCut("Cut_E_SkimSelection").pass)
        ana.txskim.fill();
}
