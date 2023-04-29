#include "Begin_E.h"

void Begin_E()
{

    ana.txskim.createBranch<int>("is0Lep");
    ana.txskim.createBranch<int>("is1Lep");

    ana.txskim.createBranch<LorentzVector>("FJ0");
    ana.txskim.createBranch<LorentzVector>("FJ1");
    ana.txskim.createBranch<LorentzVector>("FJ2");
    ana.txskim.createBranch<LorentzVector>("FJ3");
    ana.txskim.createBranch<LorentzVector>("FJ4");
    ana.txskim.createBranch<LorentzVector>("Lep");
    ana.txskim.createBranch<LorentzVector>("MET");
    ana.txskim.createBranch<LorentzVector>("J0");
    ana.txskim.createBranch<LorentzVector>("J1");
    ana.txskim.createBranch<LorentzVector>("J2");
    ana.txskim.createBranch<LorentzVector>("J3");
    ana.txskim.createBranch<LorentzVector>("J4");

    ana.txskim.createBranch<float>("VMD0");
    ana.txskim.createBranch<float>("VMD1");
    ana.txskim.createBranch<float>("VMD2");
    ana.txskim.createBranch<float>("VMD3");
    ana.txskim.createBranch<float>("VMD4");
    ana.txskim.createBranch<float>("WMD0");
    ana.txskim.createBranch<float>("WMD1");
    ana.txskim.createBranch<float>("WMD2");
    ana.txskim.createBranch<float>("WMD3");
    ana.txskim.createBranch<float>("WMD4");

    ana.txskim.createBranch<int>("NFJ");
    ana.txskim.createBranch<int>("NJ");
    ana.txskim.createBranch<int>("NbLoose");
    ana.txskim.createBranch<int>("NbMedium");
    ana.txskim.createBranch<int>("NbTight");
    ana.txskim.createBranch<float>("MVVX");
    ana.txskim.createBranch<float>("PtVVX");
    ana.txskim.createBranch<float>("HT");
    ana.txskim.createBranch<float>("HTJ");
    ana.txskim.createBranch<float>("HTFJ");
    ana.txskim.createBranch<float>("SumPtFJ");
    ana.txskim.createBranch<float>("SumPtJ");

    ana.txskim.createBranch<int>("isData");
    ana.txskim.createBranch<int>("run");
    ana.txskim.createBranch<int>("lumi");
    ana.txskim.createBranch<unsigned long long>("evt");
    ana.txskim.createBranch<int>("year");
    ana.txskim.createBranch<float>("genWeight");
    ana.txskim.createBranch<float>("wgt");

    ana.txskim.createBranch<vector<float>>("LHEReweightingWeight");

    // ana.txskim.createBranch<vector<int>>("Common_gen_idx");        // Selected gen-particle idx in NanoAOD
    // ana.txskim.createBranch<vector<int>>("Common_gen_mother_idx"); // Selected gen-particle mother idx in NanoAOD
    // ana.txskim.createBranch<vector<int>>("Common_gen_mother_id");  // Selected gen-particle mother id in NanoAOD
    // ana.txskim.createBranch<vector<int>>("Common_gen_pdgid");      // Selected gen-particle pdgids
    // ana.txskim.createBranch<vector<LV>>("Common_gen_p4s");         // Selected gen-particle p4s


    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("Cut_E_SkimSelection",
        [&]()
        {
            if (ana.txskim.getBranch<int>("is0Lep"))
            {
                return ana.txskim.getBranch<int>("NFJ") >= 2;
            }
            else if (ana.txskim.getBranch<int>("is1Lep"))
            {
                return ana.txskim.getBranch<int>("NFJ") >= 1;
            }
            else
            {
                return false;
            }
        }, UNITY);
}
