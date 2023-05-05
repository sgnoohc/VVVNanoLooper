#include "Begin_E.h"

void Begin_E()
{

    ana.txskim.createBranch<int>("isData");
    ana.txskim.createBranch<int>("run");
    ana.txskim.createBranch<int>("lumi");
    ana.txskim.createBranch<unsigned long long>("evt");
    ana.txskim.createBranch<int>("year");
    ana.txskim.createBranch<float>("genWeight");
    ana.txskim.createBranch<float>("wgt");
    ana.txskim.createBranch<vector<float>>("LHEReweightingWeight");
    ana.txskim.createBranch<float>("prefireWgt");
    ana.txskim.createBranch<float>("prefireWgtUp");
    ana.txskim.createBranch<float>("prefireWgtDn");
    ana.txskim.createBranch<float>("puWgt");
    ana.txskim.createBranch<float>("puWgtUp");
    ana.txskim.createBranch<float>("puWgtDn");
    ana.txskim.createBranch<float>("trigWgt");
    ana.txskim.createBranch<float>("trigWgtUp");
    ana.txskim.createBranch<float>("trigWgtDn");

    ana.txskim.createBranch<int>("trigger");
    ana.txskim.createBranch<int>("is0Lep");
    ana.txskim.createBranch<int>("is1Lep");

    ana.txskim.createBranch<LorentzVector>("Lep");
    ana.txskim.createBranch<int>("LepFlav");

    vector<TString> variations = {"", "JESUp", "JESDn", "JERUp", "JERDn", "JMSUp", "JMSDn", "JMRUp", "JMRDn"};
    ana.variations = variations;

    for (auto& variation : ana.variations)
    {

        // ******
        // Not part of "txskim"
        ana.tx.createBranch<vector<LV>>(TString::Format("FJs%s", variation.Data()));
        ana.tx.createBranch<vector<LV>>(TString::Format("iFJs%s", variation.Data()));
        ana.tx.createBranch<vector<LV>>(TString::Format("Js%s", variation.Data()));
        // ******

        ana.txskim.createBranch<int>(TString::Format("NFJ%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("FJ0%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("FJ1%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("FJ2%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("FJ3%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("FJ4%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("VMD0%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("VMD1%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("VMD2%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("VMD3%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("VMD4%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("WMD0%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("WMD1%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("WMD2%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("WMD3%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("WMD4%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NQGen0%s", variation.Data())); // Number of gen quarks matched to the fat-jet
        ana.txskim.createBranch<int>(TString::Format("NQGen1%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NQGen2%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NQGen3%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NQGen4%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NBGen0%s", variation.Data())); // Number of gen b quarks matched to the fat-jet
        ana.txskim.createBranch<int>(TString::Format("NBGen1%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NBGen2%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NBGen3%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NBGen4%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NLGen0%s", variation.Data())); // Number of gen light quarks matched to the fat-jet
        ana.txskim.createBranch<int>(TString::Format("NLGen1%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NLGen2%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NLGen3%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NLGen4%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NiFJ%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("iFJ0%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("iFJ1%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("iFJ2%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("iFJ3%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("iFJ4%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("iVMD0%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("iVMD1%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("iVMD2%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("iVMD3%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("iVMD4%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("iWMD0%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("iWMD1%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("iWMD2%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("iWMD3%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("iWMD4%s", variation.Data()));

        ana.txskim.createBranch<LorentzVector>(TString::Format("MET%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("Nu%s", variation.Data()));

        ana.txskim.createBranch<int>(TString::Format("NJ%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NbLoose%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NbMedium%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NbTight%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NoORNbLoose%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NoORNbMedium%s", variation.Data()));
        ana.txskim.createBranch<int>(TString::Format("NoORNbTight%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("J0%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("J1%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("J2%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("J3%s", variation.Data()));
        ana.txskim.createBranch<LorentzVector>(TString::Format("J4%s", variation.Data()));

        ana.txskim.createBranch<float>(TString::Format("MVVX%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("PtVVX%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("HT%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("HTJ%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("HTFJ%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("SumPtFJ%s", variation.Data()));
        ana.txskim.createBranch<float>(TString::Format("SumPtJ%s", variation.Data()));
    }

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

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("Cut_E_SkimSelection",
        [&]()
        {
            if (not (ana.txskim.getBranchLazy<int>("trigger")))
                return false;

            if (ana.txskim.getBranchLazy<int>("is0Lep"))
            {
                bool pass = false;
                for (auto& var : ana.variations)
                {
                    const int& NFJ = ana.txskim.getBranchLazy<int>(TString::Format("NFJ%s", var.Data()));
                    const int& NiFJ = ana.txskim.getBranchLazy<int>(TString::Format("NiFJ%s", var.Data()));
                    float FJ0pt = ana.txskim.getBranchLazy<LV>(TString::Format("FJ0%s", var.Data())).pt();
                    float iFJ0pt = ana.txskim.getBranchLazy<LV>(TString::Format("iFJ0%s", var.Data())).pt();
                    if (NFJ >= 2 and FJ0pt >= 400)
                    {
                        pass = true;
                        break;
                    }
                    else if (NFJ == 1 and NiFJ >= 1 and FJ0pt >= 400)
                    {
                        pass = true;
                        break;
                    }
                }
                return pass;
            }
            else if (ana.txskim.getBranchLazy<int>("is1Lep"))
            {
                bool pass = false;
                for (auto& var : ana.variations)
                {
                    const int& NFJ = ana.txskim.getBranchLazy<int>(TString::Format("NFJ%s", var.Data()));
                    const int& NiFJ = ana.txskim.getBranchLazy<int>(TString::Format("NiFJ%s", var.Data()));
                    float FJ0pt = ana.txskim.getBranchLazy<LV>(TString::Format("FJ0%s", var.Data())).pt();
                    float iFJ0pt = ana.txskim.getBranchLazy<LV>(TString::Format("iFJ0%s", var.Data())).pt();
                    if (NFJ >= 1)
                    {
                        pass = true;
                        break;
                    }
                    else if (NFJ == 0 and NiFJ >= 1)
                    {
                        pass = true;
                        break;
                    }
                }
                return pass;
            }
            else
            {
                return false;
            }
        }, UNITY);
}
