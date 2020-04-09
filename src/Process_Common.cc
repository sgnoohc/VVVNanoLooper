#include "Process_Common.h"

void Process_Common()
{
    //==============================================
    // Process_Common:
    // This function gets called during the event looping.
    // This is where one sets the variables used for the category Common.
    //==============================================

    // Set variables used in this category.
    // If histograms are booked with these variables the histograms will be filled automatically.
    // Please follow the convention of <category>_<varname> structure.
    // N.B. PLEASE USE float TYPE FOR EVERYTHING, UNLESS IT IS LORENTZVECTOR (which is also done in float).

    // Example of reading from Nano
    // std::vector<LorentzVector> electron_p4s = nt.Electron_p4(); // nt is a global variable that accesses NanoAOD
    // std::vector<float> electron_mvaTTH = nt.Electron_mvaTTH(); // electron ttH MVA scores from NanoAOD
    // Semi-complete list of NanoAOD for 102X can be found here: https://cms-nanoaod-integration.web.cern.ch/integration/master-102X/mc102X_doc.html
    // Also consult here: https://github.com/cmstas/NanoTools/blob/d641a6d6c1aa9ecc8094a1af73d5e1bd7d6502ab/NanoCORE/Nano.h#L4875 (if new variables are added they may show up in master)

    //---------------------------------------------------------------------------------------------
    // Electron selection
    //---------------------------------------------------------------------------------------------
    // Loop over electrons and select Fall17V2Iso_WP90 electrons
    for (unsigned int iel = 0; iel < nt.Electron_p4().size(); ++iel)
    {
        if (nt.Electron_mvaFall17V2Iso_WP90()[iel])
            ana.tx.pushbackToBranch<int>("Common_electron_idxs", iel);
    }

    //---------------------------------------------------------------------------------------------
    // Muon selection
    //---------------------------------------------------------------------------------------------
    // Loop over muons and select POG medium muons
    for (unsigned int imu = 0; imu < nt.Muon_p4().size(); ++imu)
    {
        if (nt.Muon_looseId()[imu])
            ana.tx.pushbackToBranch<int>("Common_muon_idxs", imu);
    }

    //---------------------------------------------------------------------------------------------
    // MET selection
    //---------------------------------------------------------------------------------------------
    ana.tx.setBranch<LorentzVector>("Common_met_p4", RooUtil::Calc::getLV(nt.MET_pt(), 0., nt.MET_phi(), 0));

    //---------------------------------------------------------------------------------------------
    // Jet selection
    //---------------------------------------------------------------------------------------------
    // Loop over jets and do a simple overlap removal against leptons
    for (unsigned int ijet = 0; ijet < nt.Jet_p4().size(); ++ijet)
    {

        // Because every muon and electron shows up in PF Jet collections
        // Need to check against leptons
        bool is_overlapping_with_a_lepton = false;

        // Overlap check against leptons (electrons)
        for (auto& iel : ana.tx.getBranchLazy<vector<int>>("Common_electron_idxs"))
        {
            if (RooUtil::Calc::DeltaR(nt.Jet_p4()[ijet], nt.Electron_p4()[iel]) < 0.4)
            {
                is_overlapping_with_a_lepton = true;
                break;
            }
        }

        if (is_overlapping_with_a_lepton)
            continue;

        // Overlap check against leptons (muons)
        for (auto& imu : ana.tx.getBranchLazy<vector<int>>("Common_muon_idxs"))
        {
            if (RooUtil::Calc::DeltaR(nt.Jet_p4()[ijet], nt.Muon_p4()[imu]) < 0.4)
            {
                is_overlapping_with_a_lepton = true;
                break;
            }
        }

        if (is_overlapping_with_a_lepton)
            continue;

        // TODO: What is POG recommendation? do we use nt.Jet_jetId()? nt.Jet_puId()??
        // Figure this out
        // For now, accept anything above 30 GeV

        if (nt.Jet_p4()[ijet].pt() > 30.)
            ana.tx.pushbackToBranch<int>("Common_jet_idxs", ijet);

    }

    //---------------------------------------------------------------------------------------------
    // Fat Jet selection
    //---------------------------------------------------------------------------------------------
    // Loop over jets and do a simple overlap removal against leptons
    for (unsigned int ifatjet = 0; ifatjet < nt.FatJet_p4().size(); ++ifatjet)
    {

        // Because every muon and electron shows up in PF FatJet collections
        // Need to check against leptons
        bool is_overlapping_with_a_lepton = false;

        // Overlap check against leptons (electrons)
        for (auto& iel : ana.tx.getBranchLazy<vector<int>>("Common_electron_idxs"))
        {
            if (RooUtil::Calc::DeltaR(nt.FatJet_p4()[ifatjet], nt.Electron_p4()[iel]) < 0.4)
            {
                is_overlapping_with_a_lepton = true;
                break;
            }
        }

        if (is_overlapping_with_a_lepton)
            continue;

        // Overlap check against leptons (muons)
        for (auto& imu : ana.tx.getBranchLazy<vector<int>>("Common_muon_idxs"))
        {
            if (RooUtil::Calc::DeltaR(nt.FatJet_p4()[ifatjet], nt.Muon_p4()[imu]) < 0.4)
            {
                is_overlapping_with_a_lepton = true;
                break;
            }
        }

        if (is_overlapping_with_a_lepton)
            continue;

        // TODO: What is POG recommendation? do we use nt.FatJet_jetId()?
        // Figure this out
        // For now, accept anything above 250 GeV (TODO: is 250 GeV also ok?)

        if (nt.FatJet_p4()[ifatjet].pt() > 250.)
            ana.tx.pushbackToBranch<int>("Common_fatjet_idxs", ifatjet);

    }


}
