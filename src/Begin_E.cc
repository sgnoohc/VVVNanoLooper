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
    ana.txskim.createBranch<LorentzVector>("Nu");
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

    ana.txskim.createBranch<int>("NQGen0"); // Number of gen quarks matched to the fat-jet
    ana.txskim.createBranch<int>("NQGen1");
    ana.txskim.createBranch<int>("NQGen2");
    ana.txskim.createBranch<int>("NQGen3");
    ana.txskim.createBranch<int>("NQGen4");
    ana.txskim.createBranch<int>("NBGen0"); // Number of gen b quarks matched to the fat-jet
    ana.txskim.createBranch<int>("NBGen1");
    ana.txskim.createBranch<int>("NBGen2");
    ana.txskim.createBranch<int>("NBGen3");
    ana.txskim.createBranch<int>("NBGen4");
    ana.txskim.createBranch<int>("NLGen0"); // Number of gen light quarks matched to the fat-jet
    ana.txskim.createBranch<int>("NLGen1");
    ana.txskim.createBranch<int>("NLGen2");
    ana.txskim.createBranch<int>("NLGen3");
    ana.txskim.createBranch<int>("NLGen4");

    ana.txskim.createBranch<LorentzVector>("GenV0"); // leading true V 4-vector
    ana.txskim.createBranch<LorentzVector>("GenV1"); // subleading true V 4-vector
    ana.txskim.createBranch<LorentzVector>("GenV2"); // trailing true V 4-vector
    ana.txskim.createBranch<int>("isHad0"); // is leading true V hadronically decaying?
    ana.txskim.createBranch<int>("isHad1"); // is subleading true V hadronically decaying?
    ana.txskim.createBranch<int>("isHad2"); // is trailing true V hadronically decaying?
    ana.txskim.createBranch<LorentzVector>("GenF00"); // leading fermion from the leading true V
    ana.txskim.createBranch<LorentzVector>("GenF01"); // subleading fermion from the leading true V
    ana.txskim.createBranch<LorentzVector>("GenF10"); // leading fermion from the subleading true V
    ana.txskim.createBranch<LorentzVector>("GenF11"); // subleading fermion from the subleading true V
    ana.txskim.createBranch<LorentzVector>("GenF20"); // leading fermion from the trailing true V
    ana.txskim.createBranch<LorentzVector>("GenF21"); // subleading fermion from the trailing true V

    ana.txskim.createBranch<int>("LepFlav");
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

    ana.txskim.createBranch<int>("trigger");


    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("Cut_E_SkimSelection",
        [&]()
        {
            if (not (ana.txskim.getBranch<int>("trigger")))
                return false;

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
