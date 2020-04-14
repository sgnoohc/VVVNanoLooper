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
        // Selections
        if (not (nt.Electron_mvaFall17V2Iso_WP90()[iel])) continue;
        if (not (nt.Electron_p4()[iel].pt() > 10.)) continue;
        if (not (abs(nt.Electron_p4()[iel].eta()) < 2.5)) continue;

        // If passed up to here add it to the index list
        ana.tx.pushbackToBranch<int>("Common_lep_idxs", iel);
        ana.tx.pushbackToBranch<int>("Common_lep_pdgid", nt.Electron_pdgId()[iel]);
        ana.tx.pushbackToBranch<LorentzVector>("Common_lep_p4", nt.Electron_p4()[iel]);
    }

    //---------------------------------------------------------------------------------------------
    // Muon selection
    //---------------------------------------------------------------------------------------------
    // Loop over muons and select POG medium muons
    for (unsigned int imu = 0; imu < nt.Muon_p4().size(); ++imu)
    {
        // Selections
        if (not (nt.Muon_mediumId()[imu])) continue; // TODO: What is Muon_mediumPromptId in NanoAOD?
        if (not (nt.Muon_p4()[imu].pt() > 10.)) continue;
        if (not (nt.Muon_pfRelIso04_all()[imu] < 0.25)) continue;
        if (not (abs(nt.Muon_p4()[imu].eta()) < 2.4)) continue;

        // If passed up to here add it to the index list
        ana.tx.pushbackToBranch<int>("Common_lep_idxs", imu);
        ana.tx.pushbackToBranch<int>("Common_lep_pdgid", nt.Muon_pdgId()[imu]);
        ana.tx.pushbackToBranch<LorentzVector>("Common_lep_p4", nt.Muon_p4()[imu]);
    }

    //---------------------------------------------------------------------------------------------
    // Jet selection
    //---------------------------------------------------------------------------------------------

    // b-tagging counter (DeepFlavB)
    int nb_loose = 0;
    int nb_medium = 0;
    int nb_tight = 0;

    // Loop over jets and do a simple overlap removal against leptons
    for (unsigned int ijet = 0; ijet < nt.Jet_p4().size(); ++ijet)
    {

        // TODO: What is POG recommendation? do we use nt.Jet_jetId()? nt.Jet_puId()??
        // Figure this out
        // For now if less than 20 GeV, don't ever consider
        if (not (nt.Jet_p4()[ijet].pt() > 20.))
            continue;

        // Because every muon and electron shows up in PF Jet collections
        // Need to check against leptons
        bool is_overlapping_with_a_lepton = false;

        // Overlap check against leptons (electrons)
        for (unsigned int ilep = 0; ilep < ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs").size(); ++ilep)
        {
            int ilep_idx = ana.tx.getBranchLazy<vector<int>>("Common_lep_idxs")[ilep];
            // If electron
            if (abs(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[ilep]) == 11)
            {
                if (RooUtil::Calc::DeltaR(nt.Jet_p4()[ijet], nt.Electron_p4()[ilep_idx]) < 0.4)
                {
                    is_overlapping_with_a_lepton = true;
                    break;
                }
            }
            // else muon
            else
            {
                if (RooUtil::Calc::DeltaR(nt.Jet_p4()[ijet], nt.Muon_p4()[ilep_idx]) < 0.4)
                {
                    is_overlapping_with_a_lepton = true;
                    break;
                }
            }
        }

        if (is_overlapping_with_a_lepton)
            continue;

        // For the analysis level jets, consider jets only 30 and above
        if (nt.Jet_p4()[ijet].pt() > 30.)
        {
            // For now, accept anything that reaches this point
            ana.tx.pushbackToBranch<int>("Common_jet_idxs", ijet);
            ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4", nt.Jet_p4()[ijet]);
        }

        // b-tagged jet counter
        // For b-tagged jets, consider jets only 20 and above and is central within tracker acceptance
        if (nt.Jet_p4()[ijet].pt() > 20. and abs(nt.Jet_p4()[ijet].eta()) < 2.4)
        {
            if (nt.Jet_btagDeepFlavB()[ijet] > 0.0494) // TODO: Factorize this for each year and etc. https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation102X
                nb_loose++;
            if (nt.Jet_btagDeepFlavB()[ijet] > 0.2770) // TODO: Factorize this for each year and etc. https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation102X
                nb_medium++;
            if (nt.Jet_btagDeepFlavB()[ijet] > 0.7264) // TODO: Factorize this for each year and etc. https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation102X
                nb_tight++;
        }
    }

    ana.tx.setBranch<int>("Common_nb_loose", nb_loose);
    ana.tx.setBranch<int>("Common_nb_medium", nb_medium);
    ana.tx.setBranch<int>("Common_nb_tight", nb_tight);

    //---------------------------------------------------------------------------------------------
    // Fat Jet selection
    //---------------------------------------------------------------------------------------------
    // Loop over jets and do a simple overlap removal against leptons
    for (unsigned int ifatjet = 0; ifatjet < nt.FatJet_p4().size(); ++ifatjet)
    {

        // TODO: What is POG recommendation? do we use nt.FatJet_jetId()?
        // Figure this out
        // For now, accept anything above 250 GeV (TODO: is 250 GeV also ok?)
        if (not (nt.FatJet_p4()[ifatjet].pt() > 250.))
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
                if (RooUtil::Calc::DeltaR(nt.FatJet_p4()[ifatjet], nt.Electron_p4()[ilep_idx]) < 0.4)
                {
                    is_overlapping_with_a_lepton = true;
                    break;
                }
            }
            // else muon
            else
            {
                if (RooUtil::Calc::DeltaR(nt.FatJet_p4()[ifatjet], nt.Muon_p4()[ilep_idx]) < 0.4)
                {
                    is_overlapping_with_a_lepton = true;
                    break;
                }
            }
        }

        if (is_overlapping_with_a_lepton)
            continue;

        // For now, accept anything that reaches this point
        ana.tx.pushbackToBranch<int>("Common_fatjet_idxs", ifatjet);
        ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4", nt.FatJet_p4()[ifatjet]);

    }

    //---------------------------------------------------------------------------------------------
    // MET selection
    //---------------------------------------------------------------------------------------------
    ana.tx.setBranch<LorentzVector>("Common_met_p4", RooUtil::Calc::getLV(nt.MET_pt(), 0., nt.MET_phi(), 0));

    //---------------------------------------------------------------------------------------------
    // Gen-level particle selection
    //---------------------------------------------------------------------------------------------
    // This is only possible when it is MC and has GenPart Branches
    if (nt.hasGenBranches())
    {

        float genHT = 0; // variable to be used to stitch HT-sliced samples

        // Loop over generator particles and do stuff
        for (unsigned int igen = 0; igen < nt.GenPart_pdgId().size(); ++igen)
        {

            // Following particles are used to compute genHT
            if ((abs(nt.GenPart_pdgId()[igen]) <  6 || // quarks
                        abs(nt.GenPart_pdgId()[igen]) == 21)  // gluons
                    && (nt.GenPart_status()[igen] == 22 || // something to do with "status 3"
                        nt.GenPart_status()[igen] == 23))
            {
                genHT += nt.GenPart_pt()[igen];
            }

            // Preliminary filter on the gen particles
            if (not (nt.GenPart_statusFlags()[igen]&(1<<8))) continue; // fromHardProcess
            if (not (abs(nt.GenPart_pdgId()[igen]) <= 25)) continue;
            if (not (abs(nt.GenPart_pdgId()[igen]) != 21)) continue;

            // If vector boson do a last copy
            if (abs(nt.GenPart_pdgId()[igen]) == 23 || abs(nt.GenPart_pdgId()[igen]) == 24)
            {
                if (not (nt.GenPart_statusFlags()[igen]&(1<<13))) continue; // isLastCopy
            }
            else if (abs(nt.GenPart_pdgId()[igen]) >= 11 && abs(nt.GenPart_pdgId()[igen]) <= 16)
            {
                if (not (nt.GenPart_statusFlags()[igen]&(1<<12))) continue; // isFirstCopy
            }
            else if (abs(nt.GenPart_pdgId()[igen]) >= 1 && abs(nt.GenPart_pdgId()[igen]) <= 5)
            {
                if (not (nt.GenPart_statusFlags()[igen]&(1<<12))) continue; // isFirstCopy
            }
            else // If not defined in previous line we don't consider the object
            {
                continue;
            }

            ana.tx.pushbackToBranch<int>          ("Common_gen_idx", igen);                                       // Selected gen-particle idx in NanoAOD
            ana.tx.pushbackToBranch<int>          ("Common_gen_mother_idx", nt.GenPart_genPartIdxMother()[igen]); // Selected gen-particle mother idx in NanoAOD
            ana.tx.pushbackToBranch<int>          ("Common_gen_pdgid", nt.GenPart_pdgId()[igen]);                 // Selected gen-particle pdgids
            ana.tx.pushbackToBranch<LorentzVector>("Common_gen_p4s", nt.GenPart_p4()[igen]);                      // Selected gen-particle p4s

            if (abs(nt.GenPart_pdgId()[igen]) >= 11 and abs(nt.GenPart_pdgId()[igen]) <= 16)
            {

                ana.tx.pushbackToBranch<int>          ("Common_gen_lep_idx", igen);                                       // Selected gen-particle idx in NanoAOD
                ana.tx.pushbackToBranch<int>          ("Common_gen_lep_mother_idx", nt.GenPart_genPartIdxMother()[igen]); // Selected gen-particle mother idx in NanoAOD
                ana.tx.pushbackToBranch<int>          ("Common_gen_lep_pdgid", nt.GenPart_pdgId()[igen]);                 // Selected gen-particle pdgids
                ana.tx.pushbackToBranch<LorentzVector>("Common_gen_lep_p4s", nt.GenPart_p4()[igen]);                      // Selected gen-particle p4s

            }

        }

        ana.tx.setBranch<float>("Common_genHT", genHT);

    }

    //---------------------------------------------------------------------------------------------
    // Organizing object indices and sorting by Pt
    //---------------------------------------------------------------------------------------------

    // Sorting lepton branches
    ana.tx.sortVecBranchesByPt(
            /* name of the 4vector branch to use to pt sort by*/               "Common_lep_p4",
            /* names of any associated vector<float> branches to sort along */ {},
            /* names of any associated vector<int>   branches to sort along */ {"Common_lep_idxs", "Common_lep_pdgid"},
            /* names of any associated vector<bool>  branches to sort along */ {}
            );

    // Sorting jet branches
    ana.tx.sortVecBranchesByPt(
            /* name of the 4vector branch to use to pt sort by*/               "Common_jet_p4",
            /* names of any associated vector<float> branches to sort along */ {},
            /* names of any associated vector<int>   branches to sort along */ {"Common_jet_idxs"},
            /* names of any associated vector<bool>  branches to sort along */ {}
            );

    // Sorting fatjet branches
    ana.tx.sortVecBranchesByPt(
            /* name of the 4vector branch to use to pt sort by*/               "Common_fatjet_p4",
            /* names of any associated vector<float> branches to sort along */ {},
            /* names of any associated vector<int>   branches to sort along */ {"Common_fatjet_idxs"},
            /* names of any associated vector<bool>  branches to sort along */ {}
            );

    // Sorting genlep branches
    ana.tx.sortVecBranchesByPt(
            /* name of the 4vector branch to use to pt sort by*/               "Common_gen_lep_p4s",
            /* names of any associated vector<float> branches to sort along */ {},
            /* names of any associated vector<int>   branches to sort along */ {"Common_gen_lep_idxs", "Common_gen_lep_mother_idx", "Common_gen_lep_pdgid"},
            /* names of any associated vector<bool>  branches to sort along */ {}
            );

}
