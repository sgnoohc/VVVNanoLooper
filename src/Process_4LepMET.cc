#include "Process_4LepMET.h"

void Process_4LepMET()
{
    // The framework may run over NanoAOD directly or, it may run over VVVTree.
    // ana.run_VVVTree boolean determines this.
    if (ana.run_VVVTree)
    {
        Process_4LepMET_VVVTree();
    }
    else
    {
        Process_4LepMET_NanoAOD();
    }
}

void Process_4LepMET_NanoAOD()
{
    //==============================================
    // Process_4LepMET:
    // This function gets called during the event looping.
    // This is where one sets the variables used for the category 4LepMET.
    //==============================================

    // Set variables used in this category.
    // If histograms are booked with these variables the histograms will be filled automatically.
    // Please follow the convention of <category>_<varname> structure.

    // Example of reading from Nano
    // std::vector<LorentzVector> electron_p4s = nt.Electron_p4(); // nt is a global variable that accesses NanoAOD
    // std::vector<float> electron_mvaTTH = nt.Electron_mvaTTH(); // electron ttH MVA scores from NanoAOD
    // Semi-complete list of NanoAOD for 102X can be found here: https://cms-nanoaod-integration.web.cern.ch/integration/master-102X/mc102X_doc.html
    // Also consult here: https://github.com/cmstas/NanoTools/blob/d641a6d6c1aa9ecc8094a1af73d5e1bd7d6502ab/NanoCORE/Nano.h#L4875 (if new variables are added they may show up in master)
}

void Process_4LepMET_VVVTree()
{
    //==============================================
    // Process_4LepMET:
    // This function gets called during the event looping.
    // This is where one sets the variables used for the category 4LepMET.
    //==============================================

    // Set variables used in this category.
    // If histograms are booked with these variables the histograms will be filled automatically.
    // Please follow the convention of <category>_<varname> structure.

    ana.tx.setBranch<bool>         ("Cut_4LepMET_Preselection"       , vvv.Cut_4LepMET_Preselection());
    ana.tx.setBranch<bool>         ("Cut_4LepMET_emuChannel"         , vvv.Cut_4LepMET_emuChannel());
    ana.tx.setBranch<bool>         ("Cut_4LepMET_offzChannel"        , vvv.Cut_4LepMET_offzChannel());
    ana.tx.setBranch<bool>         ("Cut_4LepMET_onzChannel"         , vvv.Cut_4LepMET_onzChannel());
    ana.tx.setBranch<bool>         ("Cut_4LepMET_onzChannel_HighMET" , vvv.Cut_4LepMET_onzChannel_HighMET());

    // Z candidate idxs, pdgid, and 4 vectors
    // The Z candidate is the SFOS pair that is closest to the Z mass
    ana.tx.setBranch<int>          ("Var_4LepMET_Zcand_lep_idx_0"   , vvv.Var_4LepMET_Zcand_lep_idx_0());    // idxs to the NanoAOD
    ana.tx.setBranch<int>          ("Var_4LepMET_Zcand_lep_pdgid_0" , vvv.Var_4LepMET_Zcand_lep_pdgid_0());  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.setBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_0"    , vvv.Var_4LepMET_Zcand_lep_p4_0());     // p4 of the lepton
    ana.tx.setBranch<int>          ("Var_4LepMET_Zcand_lep_idx_1"   , vvv.Var_4LepMET_Zcand_lep_idx_1());    // idxs to the NanoAOD
    ana.tx.setBranch<int>          ("Var_4LepMET_Zcand_lep_pdgid_1" , vvv.Var_4LepMET_Zcand_lep_pdgid_1());  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.setBranch<LorentzVector>("Var_4LepMET_Zcand_lep_p4_1"    , vvv.Var_4LepMET_Zcand_lep_p4_1());     // p4 of the lepton
    ana.tx.setBranch<float>        ("Var_4LepMET_Zcand_mll"         , vvv.Var_4LepMET_Zcand_mll());          // Invariant mass of the Z candidate

    // The other two leptons from the 4 lepton event (they must be oppositely charged)
    ana.tx.setBranch<int>          ("Var_4LepMET_other_lep_idx_0"   , vvv.Var_4LepMET_other_lep_idx_0());    // idxs to the NanoAOD
    ana.tx.setBranch<int>          ("Var_4LepMET_other_lep_pdgid_0" , vvv.Var_4LepMET_other_lep_pdgid_0());  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.setBranch<LorentzVector>("Var_4LepMET_other_lep_p4_0"    , vvv.Var_4LepMET_other_lep_p4_0());     // p4 of the lepton
    ana.tx.setBranch<int>          ("Var_4LepMET_other_lep_idx_1"   , vvv.Var_4LepMET_other_lep_idx_1());    // idxs to the NanoAOD
    ana.tx.setBranch<int>          ("Var_4LepMET_other_lep_pdgid_1" , vvv.Var_4LepMET_other_lep_pdgid_1());  // pdgid of lepton (so that when accessing NanoAOD we know which containers to look at)
    ana.tx.setBranch<LorentzVector>("Var_4LepMET_other_lep_p4_1"    , vvv.Var_4LepMET_other_lep_p4_1());     // p4 of the lepton
    ana.tx.setBranch<float>        ("Var_4LepMET_other_mll"         , vvv.Var_4LepMET_other_mll());          // Invariant mass of the Z candidate

    // Additional variables
    ana.tx.setBranch<float>        ("Var_4LepMET_mt2"               , vvv.Var_4LepMET_mt2());                // Invariant mass of the Z candidate
}

void PostProcess_4LepMET()
{
    //==============================================
    // Process_4LepMET:
    // This function gets called during the event looping after the event processing has been carried out
    // This is where one may decide to write out TTree
    //==============================================

    // If it passes the preselection than decide to write the TTree
    if (ana.cutflow.getCut("Cut_4LepMET_Preselection").pass)
    {
        ana.tx.fill();
    }

}
