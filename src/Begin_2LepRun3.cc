#include "Begin_2LepRun3.h"
//#include "lester_mt2_bisect.h"
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <iostream>

namespace twolep{
    std::map<TString, float> scaleLumis;
    std::map<TString, float> intLumis;
}

void Begin_2LepRun3()
{
    // Category flag
    Begin_2LepRun3_Create_Branches();

//    // Parse cross section
//    Begin_2LepRun3_Parse_Scale1fbs();

    Begin_2LepRun3_NanoAOD();

//    // Add different channels

    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
//    ana.histograms.addHistogram("h_2LepRun3_met", 180, 0, 450, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4").pt(); } );
//    ana.histograms.addHistogram("h_2LepRun3_met_phi", 180, -3.1416, 3.1416, [&]() { return ana.tx.getBranch<LorentzVector>("Common_met_p4").phi(); } );
//    ana.histograms.addHistogram("h_2LepRun3_njet", 8, 0, 8, [&]() { return ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4").size(); } );
//    ana.histograms.addHistogram("h_2LepRun3_mt2", 180, 0, 100, [&]() { return ana.tx.getBranch<float>("Var_2LepRun3_mt2"); } );

    // Now book cutflow histogram (could be commented out if user does not want.)
    // N.B. Cutflow histogramming can be CPU consuming.
    // ana.cutflow.bookCutflows();

    // Book histograms to cuts that user wants for this category.
    // ana.cutflow.bookHistogramsForCutAndBelow(ana.histograms, "Cut_2LepRun3_Preselection");

}

void Begin_2LepRun3_NanoAOD()
{
    //==============================================
    // Begin_2LepRun3:
    // This function gets called prior to the event looping.
    // This is where one declares variables, histograms, event selections for the category 2LepRun3.
    //==============================================

    // Create variables used in this category.
    // Please follow the convention of <category>_<varname> structure.

    // Define selections
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.

    ana.cutflow.getCut("CommonCut");

//--------------------------------------------------------------------------------------------
//    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_Trigger",
//            [&]()
//            {
//                if (not (nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8() == 1))
//                    return false;
//                return true;
//            }, UNITY);
//  
//    // Select 2 leptons
//    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_Has2Lepton",
//            [&]()
//            {
//                // Needs to be 2 leptons
//                if (not (ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size() == 2))
//                    return false;
//                return true;
//            }, UNITY);
//
//
//    // Muon and Electron Check
//    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_Mus_Elecs",
//            [&]()
//            {
//                // Needs to be only Muons or Electrons
//                if (not (abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 13))
//                    if (not (abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 11))
//                        return false;
//                if (not (abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1]) == 13))
//                    if (not (abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1]) == 11))
//                        return false;
//
//                return true;
//            }, UNITY);
//
//
//    //Select events with opposite sign leptons
//    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_HasOppositeLeps",
//            [&]()
//            {
//                if (not (ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0] + ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1] == 0))
//                    return false;
//                return true;
//            }, UNITY);
//
//    //Leading Lepton must have 25 Gev
//    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_lep0_25Gev",
//            [&]()
//            {
//            if (not (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].pt() > 25.))
//                return false;
//            return true;
//            }, UNITY);
//
//    //SubLeading Lepton must have 15 Gev
//    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_lep1_15Gev",
//            [&]()
//            {
//            if (not (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].pt() > 15.))
//                return false;
//            return true;
//            }, UNITY);
//
//    //MET must be Greater than 30
//    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_MET",
//            [&]()
//            {
//            if (not (nt.PuppiMET_pt() <= 30.))
//                return false;
//            return true;
//            }, UNITY);
//
//    // Select Z candidate
//    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_HasZCandidate",
//            [&]()
//            {
//                float mll = (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1] + ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]).mass();
//                if (not (abs(mll - 91.1876) < 10.)) return false;
//
//                // If found a Z then set the variables
//
//                if ((abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 13))
//                    {
//                    ana.tx.setBranch<int>          ("Var_2LepRun3_Zcand_muon_pdgid_0" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]);
//                    ana.tx.setBranch<LorentzVector>("Var_2LepRun3_Zcand_muon_p4_0"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]);
//                    ana.tx.setBranch<int>          ("Var_2LepRun3_Zcand_muon_pdgid_1" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1]);
//                    ana.tx.setBranch<LorentzVector>("Var_2LepRun3_Zcand_muon_p4_1"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]);
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_mll", mll);
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_eta_0", ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].eta());
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_eta_1", ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].eta());
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_reliso_0", nt.Muon_pfRelIso03_all()[0]);
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_reliso_1", nt.Muon_pfRelIso03_all()[1]);
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_met", nt.PuppiMET_pt());
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_met_phi", nt.PuppiMET_phi());
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_mt_0", (sqrt(2 * nt.PuppiMET_pt() *  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Et() * (1.0 - cos(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].phi() - nt.PuppiMET_phi())))));
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_mt_1", (sqrt(2 * nt.PuppiMET_pt() *  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].Et() * (1.0 - cos(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].phi() - nt.PuppiMET_phi())))));
//                    }
//
//                if ((abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 11))
//                    {
//                    ana.tx.setBranch<int>          ("Var_2LepRun3_Zcand_electron_pdgid_0" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]);
//                    ana.tx.setBranch<LorentzVector>("Var_2LepRun3_Zcand_electron_p4_0"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]);
//                    ana.tx.setBranch<int>          ("Var_2LepRun3_Zcand_electron_pdgid_1" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1]);
//                    ana.tx.setBranch<LorentzVector>("Var_2LepRun3_Zcand_electron_p4_1"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]);
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_mll", mll);
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_eta_0", ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].eta());
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_eta_1", ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].eta());
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_reliso_0", nt.Electron_pfRelIso03_all()[0]);
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_reliso_1", nt.Electron_pfRelIso03_all()[1]);
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_met", nt.PuppiMET_pt());
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_met_phi", nt.PuppiMET_phi());
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_mt_0", (sqrt(2 * nt.PuppiMET_pt() *  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Et() * (1.0 - cos(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].phi() - nt.PuppiMET_phi())))));
//                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_mt_1", (sqrt(2 * nt.PuppiMET_pt() *  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].Et() * (1.0 - cos(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].phi() - nt.PuppiMET_phi())))));
//                    }
//
//                return true;
//            }, UNITY);
//--------------------------------------------------------------------------------------------

    // Select 2 leptons
    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_Has2Lepton",
            [&]()
            {
                // Needs to be 2 leptons
                if (not (ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size() == 2))
                    return false;
                return true;
            }, UNITY);

    // Must have 2 jets 
    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_Has2Jets",
            [&]()
            {
                // Needs to be 2 leptons
                if (not (ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size() >= 2))
                    return false;
                return true;
            }, UNITY);

    //Select events with opposite sign and opposite flavor leps
    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_HasOppositeLeps",
            [&]()
            {
                if (not ((abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0])) !=  (abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1]))))
                    return false;
                if ((ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0] > 0 ) and (ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1] > 0 ))
                    return false;
                if ((ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0] < 0 ) and (ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1] < 0 ))
                    return false;
                return true;
            }, UNITY);

    //Trigger Selections
    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_Trigger",
            [&]()
            {
                if (abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0] == 11 ))
                    if (not (nt.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ() == 1))
                        return false;
                if (abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0] == 13 ))
                    if (not (nt.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ() == 1))
                        return false;
                return true;
            }, UNITY);

    //Leading Lepton must have 25 Gev
    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_lep0_25Gev",
            [&]()
            {
            if (not (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].pt() > 25.))
                return false;
            return true;
            }, UNITY);

    //SubLeading Lepton must have 15 Gev
    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_lep1_15Gev",
            [&]()
            {
            if (not (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].pt() > 15.))
                return false;
            return true;
            }, UNITY);

    // Binning
    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_mllCut",
            [&]()
            {
                float mll = (ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1] + ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]).mass();
                if (not (mll > 20.)) return false;

                if ((abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 13))
                    {
                    ana.tx.setBranch<int>          ("Var_2LepRun3_Zcand_muon_pdgid" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]);
                    ana.tx.setBranch<LorentzVector>("Var_2LepRun3_Zcand_muon_p4"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]);
                    ana.tx.setBranch<int>          ("Var_2LepRun3_Zcand_electron_pdgid" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1]);
                    ana.tx.setBranch<LorentzVector>("Var_2LepRun3_Zcand_electron_p4"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]);
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_mll", mll);
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_eta", ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].eta());
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_eta", ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].eta());
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_reliso", nt.Muon_pfIsoId()[ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[0]]);
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_reliso", nt.Electron_pfRelIso03_all()[ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1]]);
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_met", nt.PuppiMET_pt());
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_met_phi", nt.PuppiMET_phi());
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_mt", (sqrt(2 * nt.PuppiMET_pt() *  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Et() * (1.0 - cos(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].phi() - nt.PuppiMET_phi())))));
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_mt", (sqrt(2 * nt.PuppiMET_pt() *  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].Et() * (1.0 - cos(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].phi() - nt.PuppiMET_phi())))));
                    }

                if ((abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]) == 11))
                    {
                    ana.tx.setBranch<int>          ("Var_2LepRun3_Zcand_muon_pdgid" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1]);
                    ana.tx.setBranch<LorentzVector>("Var_2LepRun3_Zcand_muon_p4"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1]);
                    ana.tx.setBranch<int>          ("Var_2LepRun3_Zcand_electron_pdgid" , ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]);
                    ana.tx.setBranch<LorentzVector>("Var_2LepRun3_Zcand_electron_p4"    , ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0]);
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_mll", mll);
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_eta", ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].eta());
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_eta", ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].eta());
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_reliso", nt.Muon_pfIsoId()[ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[1]]);
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_reliso", nt.Electron_pfRelIso03_all()[ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0]]);
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_met", nt.PuppiMET_pt());
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_met_phi", nt.PuppiMET_phi());
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_muon_mt", (sqrt(2 * nt.PuppiMET_pt() *  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].Et() * (1.0 - cos(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].phi() - nt.PuppiMET_phi())))));
                    ana.tx.setBranch<float>("Var_2LepRun3_Zcand_electron_mt", (sqrt(2 * nt.PuppiMET_pt() *  ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].Et() * (1.0 - cos(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].phi() - nt.PuppiMET_phi())))));
                    }

                return true;
            }, UNITY);






    // Create a middle point of preselection
    ana.cutflow.addCutToLastActiveCut("Cut_2LepRun3_Preselection", [&]() { ana.tx.setBranch<bool>("Cut_2LepRun3_Preselection", true); return true; }, UNITY); // This "cut" does not do anything. It works as a middle point

}

void Begin_2LepRun3_Create_Branches()
{
    ana.tx.createBranch<bool>         ("Cut_2LepRun3_Preselection");

    ana.tx.createBranch<int>          ("Var_2LepRun3_Zcand_muon_idx");    // idxs to the NanoAOD
    ana.tx.createBranch<int>          ("Var_2LepRun3_Zcand_muon_pdgid");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.createBranch<LorentzVector>("Var_2LepRun3_Zcand_muon_p4");     // p4 of the lepton
//    ana.tx.createBranch<int>          ("Var_2LepRun3_Zcand_muon_idx_1");    // idxs to the NanoAOD
//    ana.tx.createBranch<int>          ("Var_2LepRun3_Zcand_muon_pdgid_1");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
//    ana.tx.createBranch<LorentzVector>("Var_2LepRun3_Zcand_muon_p4_1");     // p4 of the lepton
    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_mll");          // Invariant mass of the Z candidate
    ana.tx.createBranch<int>          ("Var_2LepRun3_Zcand_muon_lep_ID");     // ID of leading lepton
//    ana.tx.createBranch<int>	      ("Var_2LepRun3_Zcand_muon_lep_ID_1");     // ID of subleading lepton
    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_muon_eta");          // Invariant mass of the Z candidate
//    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_muon_eta_1");          // Invariant mass of the Z candidate
    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_muon_reliso");
//    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_muon_reliso_1"); 
    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_met");
    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_met_phi");
    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_muon_mt");
//    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_muon_mt_1");

    ana.tx.createBranch<int>          ("Var_2LepRun3_Zcand_electron_idx");    // idxs to the NanoAOD
    ana.tx.createBranch<int>          ("Var_2LepRun3_Zcand_electron_pdgid");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.createBranch<LorentzVector>("Var_2LepRun3_Zcand_electron_p4");     // p4 of the lepton
//    ana.tx.createBranch<int>          ("Var_2LepRun3_Zcand_electron_idx_1");    // idxs to the NanoAOD
//    ana.tx.createBranch<int>          ("Var_2LepRun3_Zcand_electron_pdgid_1");  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
//    ana.tx.createBranch<LorentzVector>("Var_2LepRun3_Zcand_electron_p4_1");     // p4 of the lepton
//    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_electron_mll");          // Invariant mass of the Z candidate
    ana.tx.createBranch<int>          ("Var_2LepRun3_Zcand_electron_lep_ID");     // ID of leading lepton
//    ana.tx.createBranch<int>	      ("Var_2LepRun3_Zcand_electron_lep_ID_1");     // ID of subleading lepton
    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_electron_eta");          // Invariant mass of the Z candidate
//    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_electron_eta_1");          // Invariant mass of the Z candidate
    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_electron_reliso");
//    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_electron_reliso_1"); 
//    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_electron_met");
//    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_electron_met_phi");
    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_electron_mt");
//    ana.tx.createBranch<float>        ("Var_2LepRun3_Zcand_electron_mt_1");

    ana.tx.createBranch<float>        ("Var_2LepRun3_scaleLumi");          // Scale 1fb
    ana.tx.createBranch<float>        ("Var_2LepRun3_intLumi");            // Integrated Luminosity

}

//void Begin_2LepRun3_Parse_Scale1fbs()
//{
//    fourlep::scaleLumis.clear();
//    ifstream ifile;
//    ifile.open("weights/scaleLumis.txt");
//    std::string line;
//    while (std::getline(ifile, line))
//    {
//        TString rawline = line;
//        std::vector<TString> list = RooUtil::StringUtil::split(rawline, ",");
//        fourlep::scaleLumis[list[0].Strip()] = list[1].Atof();
//        fourlep::intLumis[list[0].Strip()] = list[3].Atof();
//    }
//}

//float Begin_2LepRun3_MT2(int var)
//{
//    TLorentzVector lepton1 = RooUtil::Calc::getTLV(ana.tx.getBranch<LorentzVector>("Var_2LepRun3_other_lep_p4_0"));
//    TLorentzVector lepton2 = RooUtil::Calc::getTLV(ana.tx.getBranch<LorentzVector>("Var_2LepRun3_other_lep_p4_1"));
//    TLorentzVector misspart = RooUtil::Calc::getTLV(ana.tx.getBranch<LorentzVector>("Common_met_p4"));
//    TLorentzVector rest_WW;
//    rest_WW = lepton1 + lepton2 + misspart;
//    TVector3 beta_from_miss_reverse(rest_WW.BoostVector());
//    TVector3 beta_from_miss(-beta_from_miss_reverse.X(),-beta_from_miss_reverse.Y(),-beta_from_miss_reverse.Z());
//
//    lepton1.Boost(beta_from_miss);
//    lepton2.Boost(beta_from_miss);
//    misspart.Boost(beta_from_miss);
//    asymm_mt2_lester_bisect::disableCopyrightMessage();
//    double MT2_0mass = asymm_mt2_lester_bisect::get_mT2(0,lepton1.Px(),lepton1.Py(),0,lepton2.Px(),lepton2.Py(),misspart.Px(), misspart.Py(),0,0,0);
//
//    return MT2_0mass;
//}

