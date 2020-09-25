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

    //---------------------------------------------------------------------------------------------
    // Event information
    //---------------------------------------------------------------------------------------------
    // Event level information
    ana.tx.setBranch<int>                  ("Common_run", nt.run());
    ana.tx.setBranch<int>                  ("Common_lumi", nt.luminosityBlock());
    ana.tx.setBranch<unsigned long long>   ("Common_evt", nt.event());
    if (not nt.isData())
    {
        ana.tx.setBranch<float>            ("Common_genWeight", nt.genWeight());
        if (nt.year() == 2016)
            ana.tx.setBranch<float>        ("Common_btagWeight_DeepCSVB", 1); // TODO
        else
            ana.tx.setBranch<float>        ("Common_btagWeight_DeepCSVB", nt.btagWeight_DeepCSVB());
        ana.tx.setBranch<vector<float>>    ("Common_LHEWeight_mg_reweighting", nt.LHEWeight_mg_reweighting());
    }
    else
    {
        ana.tx.setBranch<float>            ("Common_genWeight", 1);
        ana.tx.setBranch<float>            ("Common_btagWeight_DeepCSVB", 1);
    }

    //---------------------------------------------------------------------------------------------
    // Trigger information
    //---------------------------------------------------------------------------------------------

    try { ana.tx.setBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ"                , nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ()); }                catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ"                , 0); } // Lowest unprescaled
    try { ana.tx.setBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL"                   , nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL()); }                   catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL"                   , 0); } // Lowest unprescaled
    try { ana.tx.setBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8"        , nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8()); }        catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8"        , 0); } // Lowest unprescaled for >= 2017C
    try { ana.tx.setBranch<bool>("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ"          , nt.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ()); }          catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ"          , 0); }
    try { ana.tx.setBranch<bool>("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL"             , nt.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL()); }             catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL"             , 0); } // Lowest unprescaled
    try { ana.tx.setBranch<bool>("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ" , nt.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ()); } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ" , 0); } // Lowest unprescaled
    try { ana.tx.setBranch<bool>("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL"    , nt.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL()); }    catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL"    , 0); }
    try { ana.tx.setBranch<bool>("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ"  , nt.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ()); }  catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ"  , 0); } // Lowest unprescaled
    try { ana.tx.setBranch<bool>("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL"     , nt.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL()); }     catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL"     , 0); }

    bool is_pd_ee = (ana.looper.getCurrentFileName().Contains("DoubleEG") || ana.looper.getCurrentFileName().Contains("EGamma"));
    bool is_pd_em = ana.looper.getCurrentFileName().Contains("MuonEG");
    bool is_pd_mm = ana.looper.getCurrentFileName().Contains("DoubleMuon");
    bool pass_duplicate_ee_em_mm = false;
    bool pass_duplicate_mm_em_ee = false;

    bool trig_ee = false;
    bool trig_em = false;
    bool trig_mm = false;

    switch (nt.year())
    {
        case 2016:
            trig_ee = ana.tx.getBranch<bool>("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ");
            trig_em = ana.tx.getBranch<bool>("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL") or ana.tx.getBranch<bool>("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL") or
                      ana.tx.getBranch<bool>("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ") or ana.tx.getBranch<bool>("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ");
            trig_mm = ana.tx.getBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ") or
                      ana.tx.getBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL");
            break;
        case 2017:
            trig_ee = ana.tx.getBranch<bool>("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL");
            trig_em = ana.tx.getBranch<bool>("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ") or ana.tx.getBranch<bool>("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ");
            trig_mm = ana.tx.getBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8");
            break;
        case 2018:
            trig_ee = ana.tx.getBranch<bool>("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL");
            trig_em = ana.tx.getBranch<bool>("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ") or ana.tx.getBranch<bool>("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ");
            trig_mm = ana.tx.getBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8");
            break;
    }

    ana.tx.setBranch<bool>("Common_HLT_DoubleEl", trig_ee);
    ana.tx.setBranch<bool>("Common_HLT_MuEG", trig_em);
    ana.tx.setBranch<bool>("Common_HLT_DoubleMu", trig_mm);

    if (is_pd_ee)
    {
        if (trig_ee)
            pass_duplicate_ee_em_mm = true;
        if (!trig_mm && !trig_em && trig_ee)
            pass_duplicate_mm_em_ee = true;
    }
    else if (is_pd_em)
    {
        if (!trig_ee && trig_em)
            pass_duplicate_ee_em_mm = true;
        if (!trig_mm && trig_em)
            pass_duplicate_mm_em_ee = true;
    }
    else if (is_pd_mm)
    {
        if (!trig_ee && !trig_em && trig_mm)
            pass_duplicate_ee_em_mm = true;
        if (trig_mm)
            pass_duplicate_mm_em_ee = true;
    }


    ana.tx.setBranch<bool>("Common_pass_duplicate_removal_ee_em_mm", pass_duplicate_ee_em_mm); // Flag to identify whether the event passes duplicate removal
    ana.tx.setBranch<bool>("Common_pass_duplicate_removal_mm_em_ee", pass_duplicate_mm_em_ee); // Flag to identify whether the event passes duplicate removal
    bool filterflag   = false;
    bool filterflagMC = false;
    switch (nt.year())
    {
        case 2016:
          filterflag   = nt.Flag_goodVertices() && nt.Flag_globalSuperTightHalo2016Filter() && nt.Flag_HBHENoiseFilter() && nt.Flag_HBHENoiseIsoFilter() && nt.Flag_EcalDeadCellTriggerPrimitiveFilter() && nt.Flag_BadPFMuonFilter();
          filterflagMC = nt.Flag_goodVertices() &&                                             nt.Flag_HBHENoiseFilter() && nt.Flag_HBHENoiseIsoFilter() && nt.Flag_EcalDeadCellTriggerPrimitiveFilter() && nt.Flag_BadPFMuonFilter();
            break;
        case 2017:
          filterflag   = nt.Flag_goodVertices() && nt.Flag_globalSuperTightHalo2016Filter() && nt.Flag_HBHENoiseFilter() && nt.Flag_HBHENoiseIsoFilter() && nt.Flag_EcalDeadCellTriggerPrimitiveFilter() && nt.Flag_BadPFMuonFilter() && nt.Flag_ecalBadCalibFilterV2();
          filterflagMC = nt.Flag_goodVertices() &&                                             nt.Flag_HBHENoiseFilter() && nt.Flag_HBHENoiseIsoFilter() && nt.Flag_EcalDeadCellTriggerPrimitiveFilter() && nt.Flag_BadPFMuonFilter() && nt.Flag_ecalBadCalibFilterV2();
          break;
        case 2018:
          filterflag   = nt.Flag_goodVertices() && nt.Flag_globalSuperTightHalo2016Filter() && nt.Flag_HBHENoiseFilter() && nt.Flag_HBHENoiseIsoFilter() && nt.Flag_EcalDeadCellTriggerPrimitiveFilter() && nt.Flag_BadPFMuonFilter() && nt.Flag_ecalBadCalibFilterV2();
          filterflagMC = nt.Flag_goodVertices() &&                                             nt.Flag_HBHENoiseFilter() && nt.Flag_HBHENoiseIsoFilter() && nt.Flag_EcalDeadCellTriggerPrimitiveFilter() && nt.Flag_BadPFMuonFilter() && nt.Flag_ecalBadCalibFilterV2();
          break;
    }
    ana.tx.setBranch<bool>("Common_noiseFlag"  , filterflag  ); // Flag to identify whether the event passes duplicate removal
    ana.tx.setBranch<bool>("Common_noiseFlagMC", filterflagMC); // Flag to identify whether the event passes duplicate removal


    // Example of reading from Nano
    // std::vector<LorentzVector> electron_p4s = nt.Electron_p4(); // nt is a global variable that accesses NanoAOD
    // std::vector<float> electron_mvaTTH = nt.Electron_mvaTTH(); // electron ttH MVA scores from NanoAOD
    // Semi-complete list of NanoAOD for 102X can be found here: https://cms-nanoaod-integration.web.cern.ch/integration/master-102X/mc102X_doc.html
    // Also consult here: https://github.com/cmstas/NanoTools/blob/d641a6d6c1aa9ecc8094a1af73d5e1bd7d6502ab/NanoCORE/Nano.h#L4875 (if new variables are added they may show up in master)
    float lepSFc(1.), lepSFue(1.), lepSFde(1.), lepSFum(1.), lepSFdm(1.);
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
        ana.tx.pushbackToBranch<int>("Common_lep_tight", nt.Electron_mvaFall17V2Iso_WP80()[iel]);
        ana.tx.pushbackToBranch<float>("Common_lep_dxy", nt.Electron_dxy()[iel]);
        ana.tx.pushbackToBranch<float>("Common_lep_dz", nt.Electron_dz()[iel]);
        float sf = sf::LeptonSFtot(11,1,nt.year(),"",nt.isData(), 0,nt.Electron_p4()[iel].pt(),nt.Electron_p4()[iel].eta());//no SC eta exists//WP doesn't mean anything right now
        lepSFc  *= sf;
        lepSFum *= sf;
        lepSFdm *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SF",        sf);
        ana.tx.pushbackToBranch<float>("Common_lep_SFTight",   sf);
        sf       = sf::LeptonSFtot(11,1,nt.year(),"",nt.isData(),+1,nt.Electron_p4()[iel].pt(),nt.Electron_p4()[iel].eta());//no SC eta exists
        lepSFue *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFup",      sf);
        ana.tx.pushbackToBranch<float>("Common_lep_SFupTight", sf);
        sf       = sf::LeptonSFtot(11,1,nt.year(),"",nt.isData(),-1,nt.Electron_p4()[iel].pt(),nt.Electron_p4()[iel].eta());//no SC eta exists
        lepSFde *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFdn",      sf);
        ana.tx.pushbackToBranch<float>("Common_lep_SFdnTight", sf);
        

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
        ana.tx.pushbackToBranch<int>("Common_lep_tight", nt.Muon_pfRelIso04_all()[imu] < 0.15);
        ana.tx.pushbackToBranch<float>("Common_lep_dxy", nt.Muon_dxy()[imu]);
        ana.tx.pushbackToBranch<float>("Common_lep_dz", nt.Muon_dz()[imu]);
        string period = "X";
        if(nt.year()==2016 && nt.run()<=278808) period = "BCDEF";
        else if(nt.year()==2016) period = "GH";
        float sf = sf::LeptonSFtot(13,1,nt.year(),period,nt.isData(), 0,nt.Muon_p4()[imu].pt(),nt.Muon_p4()[imu].eta());//WP doesn't mean anything right now
        lepSFc  *= sf;
        lepSFue *= sf;
        lepSFde *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SF",        sf);
        ana.tx.pushbackToBranch<float>("Common_lep_SFTight",   sf);
        sf       = sf::LeptonSFtot(13,1,nt.year(),period,nt.isData(),+1,nt.Muon_p4()[imu].pt(),nt.Muon_p4()[imu].eta());
        lepSFum *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFup",      sf);
        ana.tx.pushbackToBranch<float>("Common_lep_SFupTight", sf);
        sf       = sf::LeptonSFtot(13,1,nt.year(),period,nt.isData(),-1,nt.Muon_p4()[imu].pt(),nt.Muon_p4()[imu].eta());
        lepSFdm *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFdn",      sf);
        ana.tx.pushbackToBranch<float>("Common_lep_SFdnTight", sf);
    }

    ana.tx.setBranch<float>("Common_event_lepSF"      , lepSFc ); 
    ana.tx.setBranch<float>("Common_event_lepSFelup"  , lepSFue); 
    ana.tx.setBranch<float>("Common_event_lepSFeldn"  , lepSFde); 
    ana.tx.setBranch<float>("Common_event_lepSFmuup"  , lepSFum); 
    ana.tx.setBranch<float>("Common_event_lepSFmudn"  , lepSFdm); 

    //---------------------------------------------------------------------------------------------
    // Jet selection
    //---------------------------------------------------------------------------------------------

    // b-tagging counter (DeepFlavB)
    float bWPloose  = 0.0614;// https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation2016Legacy
    float bWPmedium = 0.3093;// https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation2016Legacy
    float bWPtight  = 0.7221;// https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation2016Legacy
    if(nt.year() == 2017){
      bWPloose  = 0.0521;    // https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation94X
      bWPmedium = 0.3033;    // https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation94X
      bWPtight  = 0.7489;    // https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation94X
    }
    if(nt.year() == 2018){
      bWPloose  = 0.0494;    // https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation102X
      bWPmedium = 0.2770;    // https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation102X
      bWPtight  = 0.7264;    // https://twiki.cern.ch/twiki/bin/viewauth/CMS/BtagRecommendation102X
    }
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
        if (nt.Jet_p4()[ijet].pt() > 30. && abs(nt.Jet_p4()[ijet].eta()) <3.0)//don't trust jets in HF
        {
            // For now, accept anything that reaches this point
            ana.tx.pushbackToBranch<int>("Common_jet_idxs", ijet);
            ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4", nt.Jet_p4()[ijet]);
            ana.tx.pushbackToBranch<bool>("Common_jet_passBloose" , nt.Jet_btagDeepFlavB()[ijet] > bWPloose );
            ana.tx.pushbackToBranch<bool>("Common_jet_passBmedium", nt.Jet_btagDeepFlavB()[ijet] > bWPmedium);
            ana.tx.pushbackToBranch<bool>("Common_jet_passBtight" , nt.Jet_btagDeepFlavB()[ijet] > bWPtight );
        }

        // b-tagged jet counter
        // For b-tagged jets, consider jets only 20 and above and is central within tracker acceptance

        if (nt.Jet_p4()[ijet].pt() > 20. and abs(nt.Jet_p4()[ijet].eta()) < 2.4)
        {
            if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
              {
                    nb_loose++;
              }
            if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
              {
                    nb_medium++;
              }
            if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
              {
                    nb_tight++;
              }
        }
    }

    ana.tx.setBranch<int>("Common_nb_loose", nb_loose);
    ana.tx.setBranch<int>("Common_nb_medium", nb_medium);
    ana.tx.setBranch<int>("Common_nb_tight", nb_tight);

    //---------------------------------------------------------------------------------------------
    // Fat Jet selection
    //---------------------------------------------------------------------------------------------
    // Loop over jets and do a simple overlap removal against leptons
    float fjSFvlc(1.), fjSFvlu(1.), fjSFvld(1.), fjSFlc(1.), fjSFlu(1.), fjSFld(1.), fjSFmc(1.), fjSFmu(1.), fjSFmd(1.), fjSFtc(1.), fjSFtu(1.), fjSFtd(1.);
    for (unsigned int ifatjet = 0; ifatjet < nt.FatJet_p4().size(); ++ifatjet)
    {
      float fjWPvloose = 0.274; //https://twiki.cern.ch/twiki/bin/view/CMS/DeepAK8Tagging2018WPsSFs
      float fjWPloose  = 0.506;
      float fjWPmedium = 0.731;
      float fjWPtight  = 0.828;
      if(nt.year() == 2017){
        fjWPvloose = 0.258;
        fjWPloose  = 0.506;
        fjWPmedium = 0.739;
        fjWPtight  = 0.838;
      }
      if(nt.year() == 2018){
        fjWPvloose = 0.245;
        fjWPloose  = 0.479;
        fjWPmedium = 0.704;
        fjWPtight  = 0.806;
      }

        // TODO: What is POG recommendation? do we use nt.FatJet_jetId()?
        // Figure this out
        // For now, accept anything above 250 GeV (TODO: is 250 GeV also ok?)
        if (not (nt.FatJet_p4()[ifatjet].pt() > 250.))
            continue;
        if (not (abs(nt.FatJet_p4()[ifatjet].eta()) < 2.5))
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
                if (RooUtil::Calc::DeltaR(nt.FatJet_p4()[ifatjet], nt.Electron_p4()[ilep_idx]) < 0.8)//SHOULD THIS BE 0.8? - try it
                {
                    is_overlapping_with_a_lepton = true;
                    break;
                }
            }
            // else muon
            else
            {
                if (RooUtil::Calc::DeltaR(nt.FatJet_p4()[ifatjet], nt.Muon_p4()[ilep_idx]) < 0.8)//SHOULD THIS BE 0.8? - try it
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
        ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop", nt.FatJet_msoftdrop()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deepMD_W", nt.FatJet_deepTagMD_WvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deep_W", nt.FatJet_deepTag_WvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deepMD_Z", nt.FatJet_deepTagMD_ZvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deep_Z", nt.FatJet_deepTag_ZvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deepMD_T", nt.FatJet_deepTagMD_TvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deep_T", nt.FatJet_deepTag_TvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deepMD_bb", nt.FatJet_deepTagMD_bbvsLight()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_tau3",  nt.FatJet_tau3()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_tau2",  nt.FatJet_tau2()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_tau1",  nt.FatJet_tau1()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_tau32", nt.FatJet_tau2()[ifatjet]!=0 ? nt.FatJet_tau3()[ifatjet] / nt.FatJet_tau2()[ifatjet] : -999.f);
        ana.tx.pushbackToBranch<float>("Common_fatjet_tau21", nt.FatJet_tau1()[ifatjet]!=0 ? nt.FatJet_tau2()[ifatjet] / nt.FatJet_tau1()[ifatjet] : -999.f);
        ana.tx.pushbackToBranch<float>("Common_fatjet_subjet0_pt",   nt.FatJet_subJetIdx1()[ifatjet] >= 0 ? nt.SubJet_pt()[  nt.FatJet_subJetIdx1()[ifatjet]] : -999.f);
        ana.tx.pushbackToBranch<float>("Common_fatjet_subjet0_eta",  nt.FatJet_subJetIdx1()[ifatjet] >= 0 ? nt.SubJet_eta()[ nt.FatJet_subJetIdx1()[ifatjet]] : -999.f);
        ana.tx.pushbackToBranch<float>("Common_fatjet_subjet0_phi",  nt.FatJet_subJetIdx1()[ifatjet] >= 0 ? nt.SubJet_phi()[ nt.FatJet_subJetIdx1()[ifatjet]] : -999.f);
        ana.tx.pushbackToBranch<float>("Common_fatjet_subjet0_mass", nt.FatJet_subJetIdx1()[ifatjet] >= 0 ? nt.SubJet_mass()[nt.FatJet_subJetIdx1()[ifatjet]] : -999.f);
        ana.tx.pushbackToBranch<float>("Common_fatjet_subjet1_pt",   nt.FatJet_subJetIdx2()[ifatjet] >= 0 ? nt.SubJet_pt()[  nt.FatJet_subJetIdx2()[ifatjet]] : -999.f);
        ana.tx.pushbackToBranch<float>("Common_fatjet_subjet1_eta",  nt.FatJet_subJetIdx2()[ifatjet] >= 0 ? nt.SubJet_eta()[ nt.FatJet_subJetIdx2()[ifatjet]] : -999.f);
        ana.tx.pushbackToBranch<float>("Common_fatjet_subjet1_phi",  nt.FatJet_subJetIdx2()[ifatjet] >= 0 ? nt.SubJet_phi()[ nt.FatJet_subJetIdx2()[ifatjet]] : -999.f);
        ana.tx.pushbackToBranch<float>("Common_fatjet_subjet1_mass", nt.FatJet_subJetIdx2()[ifatjet] >= 0 ? nt.SubJet_mass()[nt.FatJet_subJetIdx2()[ifatjet]] : -999.f);
        ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_subjet0_p4",  nt.FatJet_subJetIdx1()[ifatjet] >= 0 ? (RooUtil::Calc::getLV(nt.SubJet_pt()[nt.FatJet_subJetIdx1()[ifatjet]], nt.SubJet_eta()[nt.FatJet_subJetIdx1()[ifatjet]], nt.SubJet_phi()[nt.FatJet_subJetIdx1()[ifatjet]], nt.SubJet_mass()[nt.FatJet_subJetIdx1()[ifatjet]])) : (RooUtil::Calc::getLV(0., 0., 0., 0.)));
        ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_subjet1_p4",  nt.FatJet_subJetIdx2()[ifatjet] >= 0 ? (RooUtil::Calc::getLV(nt.SubJet_pt()[nt.FatJet_subJetIdx2()[ifatjet]], nt.SubJet_eta()[nt.FatJet_subJetIdx2()[ifatjet]], nt.SubJet_phi()[nt.FatJet_subJetIdx2()[ifatjet]], nt.SubJet_mass()[nt.FatJet_subJetIdx2()[ifatjet]])) : (RooUtil::Calc::getLV(0., 0., 0., 0.)));
        float WPtemp = 0;
        int WPid = -999;
        if(nt.FatJet_msoftdrop()[ifatjet]>=65. && nt.FatJet_msoftdrop()[ifatjet]<=105.){
          if(nt.FatJet_deepTagMD_WvsQCD()[ifatjet]>fjWPvloose) WPid = 0;
          if(nt.FatJet_deepTagMD_WvsQCD()[ifatjet]>fjWPloose)  WPid = 1;
          if(nt.FatJet_deepTagMD_WvsQCD()[ifatjet]>fjWPmedium) WPid = 2;
          if(nt.FatJet_deepTagMD_WvsQCD()[ifatjet]>fjWPtight)  WPid = 3;
        }
        ana.tx.pushbackToBranch<int>("Common_fatjet_WP", WPid);
        if(WPid>=0){
          WPtemp = sf::FatjetWSF(0,nt.year(),nt.isData(), 0,nt.FatJet_p4()[ifatjet].Pt());
          fjSFvlc *= WPtemp;
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFVLoose"  , WPtemp);
          WPtemp = sf::FatjetWSF(0,nt.year(),nt.isData(),-1,nt.FatJet_p4()[ifatjet].Pt());
          fjSFvld *= WPtemp;
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnVLoose", WPtemp);
          WPtemp = sf::FatjetWSF(0,nt.year(),nt.isData(),+1,nt.FatJet_p4()[ifatjet].Pt());
          fjSFvlu *= WPtemp;
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFupVLoose", WPtemp);
        }
        else {
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFVLoose"  , 0);
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnVLoose", 0);
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFupVLoose", 0);
        }
        if(WPid>=1){
          WPtemp = sf::FatjetWSF(1,nt.year(),nt.isData(), 0,nt.FatJet_p4()[ifatjet].Pt());
          fjSFlc *= WPtemp;
          // cout << "SF fatjet loose " << WPtemp << " eventSF " << fjSFlc << endl;//test debug
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFLoose"  , WPtemp);
          WPtemp = sf::FatjetWSF(1,nt.year(),nt.isData(),-1,nt.FatJet_p4()[ifatjet].Pt());
          fjSFld *= WPtemp;
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnLoose", WPtemp);
          WPtemp = sf::FatjetWSF(1,nt.year(),nt.isData(),+1,nt.FatJet_p4()[ifatjet].Pt());
          fjSFlu *= WPtemp;
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFupLoose", WPtemp);
        }
        else {
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFLoose"  , 0);
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnLoose", 0);
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFupLoose", 0);
        }
        if(WPid>=2){
          WPtemp = sf::FatjetWSF(2,nt.year(),nt.isData(), 0,nt.FatJet_p4()[ifatjet].Pt());
          fjSFmc *= WPtemp;
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFMedium"  , WPtemp);
          WPtemp = sf::FatjetWSF(2,nt.year(),nt.isData(),-1,nt.FatJet_p4()[ifatjet].Pt());
          fjSFmd *= WPtemp;
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnMedium", WPtemp);
          WPtemp = sf::FatjetWSF(2,nt.year(),nt.isData(),+1,nt.FatJet_p4()[ifatjet].Pt());
          fjSFmu *= WPtemp;
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFupMedium", WPtemp);
        }
        else {
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFMedium"  , 0);
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnMedium", 0);
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFupMedium", 0);
        }
        if(WPid>=3){
          WPtemp = sf::FatjetWSF(3,nt.year(),nt.isData(), 0,nt.FatJet_p4()[ifatjet].Pt());
          fjSFtc *= WPtemp;
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFTight"  , WPtemp);
          WPtemp = sf::FatjetWSF(3,nt.year(),nt.isData(),-1,nt.FatJet_p4()[ifatjet].Pt());
          fjSFtd *= WPtemp;
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnTight", WPtemp);
          WPtemp = sf::FatjetWSF(3,nt.year(),nt.isData(),+1,nt.FatJet_p4()[ifatjet].Pt());
          fjSFtu *= WPtemp;
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFupTight", WPtemp);
        }
        else {
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFTight"  , 0);
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnTight", 0);
          ana.tx.pushbackToBranch<float>("Common_fatjet_SFupTight", 0);
        }
    }
    for (unsigned int ijet = 0; ijet < ana.tx.getBranchLazy<vector<int>>("Common_jet_idxs").size(); ++ijet)
    {
        int overlap_with_fatjet = -1;
        for (unsigned int ifat = 0; ifat < ana.tx.getBranchLazy<vector<int>>("Common_fatjet_idxs").size(); ++ifat)
        {
            if (RooUtil::Calc::DeltaR(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_fatjet_p4")[ifat], ana.tx.getBranchLazy<vector<LorentzVector>>("Common_jet_p4")[ijet]) < 0.8)//should this be 0.4
            {
                overlap_with_fatjet = ifat;
                break;
            }
        }
        ana.tx.pushbackToBranch<int>("Common_jet_overlapfatjet", overlap_with_fatjet);//not actually applied - be careful with counters!
    }
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFVLoose",   fjSFvlc);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFLoose",     fjSFlc);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFMedium",    fjSFmc);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFTight",     fjSFtc);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFupVLoose", fjSFvlu);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFupLoose",   fjSFlu);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFupMedium",  fjSFmu);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFupTight",   fjSFtu);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFdnVLoose", fjSFvld);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFdnLoose",   fjSFld);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFdnMedium",  fjSFmd);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFdnTight",   fjSFtd);



    //---------------------------------------------------------------------------------------------
    // MET selection
    //---------------------------------------------------------------------------------------------
    ana.tx.setBranch<LorentzVector>("Common_met_p4", RooUtil::Calc::getLV(nt.MET_pt(), 0., nt.MET_phi(), 0));

    //---------------------------------------------------------------------------------------------
    // Gen-level particle selection
    //---------------------------------------------------------------------------------------------
    // This is only possible when it is MC and has GenPart Branches
    if (not nt.isData())
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

            ana.tx.pushbackToBranch<int>          ("Common_gen_idx", igen);                                                            // Selected gen-particle idx in NanoAOD
            ana.tx.pushbackToBranch<int>          ("Common_gen_mother_idx", nt.GenPart_genPartIdxMother()[igen]);                      // Selected gen-particle mother idx in NanoAOD
            ana.tx.pushbackToBranch<int>          ("Common_gen_mother_id",  nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[igen] ]); // Selected gen-particle mother idx in NanoAOD
            ana.tx.pushbackToBranch<int>          ("Common_gen_pdgid", nt.GenPart_pdgId()[igen]);                                      // Selected gen-particle pdgids
            ana.tx.pushbackToBranch<LorentzVector>("Common_gen_p4s", nt.GenPart_p4()[igen]);                                           // Selected gen-particle p4s

        }

        ana.tx.setBranch<float>("Common_genHT", genHT);

        // Selecting 6 fermions from VVV decays
        // int ngen = 0;
        vector<int> vvvdecay_candidates; // list of idxs that points to the vvv decays
        for (unsigned int igen = 0; igen < ana.tx.getBranch<vector<int>>("Common_gen_pdgid").size(); ++igen)
        {
            const int& pdgid = ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[igen];
            const int& mother_idx = ana.tx.getBranch<vector<int>>("Common_gen_mother_idx")[igen];
            float pt = ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[igen].pt();
            if (abs(pdgid) <= 20 and mother_idx >= 0 and pt >= 1e-8) // pt requirement is added because sometimes the incoming parton gets included ....
            {
                vvvdecay_candidates.push_back(igen);
            }
        }

        // If we find that there are 6 particles only, then we accept it as good and no need to try to salvage
        if (vvvdecay_candidates.size() == 6)
        {
        }
        else if (vvvdecay_candidates.size() == 7) // For WWW this seems to be the common case
        {
            vvvdecay_candidates.erase(vvvdecay_candidates.begin());
        }
        else
        {
            // std::cout << "did not find 6 ngen" << vvvdecay_candidates.size() << " " << ana.looper.getCurrentEventIndex() << std::endl;
            // for (auto& igen : vvvdecay_candidates)
            // {
            //     std::cout <<  " ana.tx.getBranch<vector<int>>('Common_gen_idx')[igen]: " << ana.tx.getBranch<vector<int>>("Common_gen_idx")[igen] <<  std::endl;
            //     std::cout <<  " ana.tx.getBranch<vector<int>>('Common_gen_mother_idx')[igen]: " << ana.tx.getBranch<vector<int>>("Common_gen_mother_idx")[igen] <<  std::endl;
            //     std::cout <<  " ana.tx.getBranch<vector<int>>('Common_gen_pdgid')[igen]: " << ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[igen] <<  std::endl;
            //     std::cout <<  " ana.tx.getBranch<vector<LorentzVector>>('Common_gen_p4s')[igen]: " << ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[igen] <<  std::endl;
            // }
            // std::cout << "=======================" << std::endl;
            // std::cout << "duplicate mother found!" << std::endl;
            // std::cout << "=======================" << std::endl;
            // for (unsigned int igen = 0; igen < nt.GenPart_pdgId().size(); ++igen)
            // {
            //     std::cout <<  " igen: " << igen <<  std::endl;
            //     std::cout <<  " nt.GenPart_pdgId()[igen]: " << nt.GenPart_pdgId()[igen] <<  std::endl;
            //     std::cout <<  " nt.GenPart_status()[igen]: " << nt.GenPart_status()[igen] <<  std::endl;
            //     std::cout <<  " nt.GenPart_statusFlags()[igen]: " << nt.GenPart_statusFlags()[igen] <<  std::endl;
            //     std::cout <<  " nt.GenPart_genPartIdxMother()[igen]: " << nt.GenPart_genPartIdxMother()[igen] <<  std::endl;
            //     std::cout <<  " nt.GenPart_p4()[igen].pt(): " << nt.GenPart_p4()[igen].pt() <<  std::endl;
            //     std::cout <<  " nt.GenPart_p4()[igen].eta(): " << nt.GenPart_p4()[igen].eta() <<  std::endl;
            //     std::cout <<  " nt.GenPart_p4()[igen].phi(): " << nt.GenPart_p4()[igen].phi() <<  std::endl;
            // }
            // std::cout << "=======================" << std::endl;
        }

        int n_light_lepton = 0;
        for (auto& igen : vvvdecay_candidates)
        {
            ana.tx.pushbackToBranch<int>          ("Common_gen_vvvdecay_idx"         , ana.tx.getBranch<vector<int>>          ("Common_gen_idx")[igen]); // Selected gen-particle of vvv decays idx in NanoAOD
            ana.tx.pushbackToBranch<int>          ("Common_gen_vvvdecay_mother_idx"  , ana.tx.getBranch<vector<int>>          ("Common_gen_mother_idx")[igen]); // Selected gen-particle of vvv decays mother idx in NanoAOD
            ana.tx.pushbackToBranch<int>          ("Common_gen_vvvdecay_mother_id"   , ana.tx.getBranch<vector<int>>          ("Common_gen_mother_id")[igen]); // Selected gen-particle of vvv decays mother idx in NanoAOD
            ana.tx.pushbackToBranch<int>          ("Common_gen_vvvdecay_pdgid"       , ana.tx.getBranch<vector<int>>          ("Common_gen_pdgid")[igen]); // Selected gen-particle of vvv decays pdgids
            ana.tx.pushbackToBranch<LorentzVector>("Common_gen_vvvdecay_p4s"         , ana.tx.getBranch<vector<LorentzVector>>("Common_gen_p4s")[igen]); // Selected gen-particle of vvv decays p4s
            if (abs(ana.tx.getBranch<vector<int>>          ("Common_gen_pdgid")[igen]) != 15)
                ana.tx.pushbackToBranch<int>          ("Common_gen_vvvdecay_taudecayid"  , 0); // no tau
            else
            {
                bool filled = false;
                for (unsigned int jgen = 0; jgen < ana.tx.getBranch<vector<int>>("Common_gen_pdgid").size(); ++jgen)
                {
                    if ( ana.tx.getBranch<vector<int>>("Common_gen_idx")[igen] != ana.tx.getBranch<vector<int>>("Common_gen_mother_idx")[jgen]) continue;
                    //jgen has as mother the tau
                    if(abs(ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[jgen])==11 || abs(ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[jgen])==13)
                    {
                        filled = true;
                        ana.tx.pushbackToBranch<int>          ("Common_gen_vvvdecay_taudecayid"  ,ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[jgen]);
                        break;
                    }
                }
                if(!filled)
                {
                    if(ana.tx.getBranch<vector<int>>          ("Common_gen_pdgid")[igen] == 15)
                        ana.tx.pushbackToBranch<int>          ("Common_gen_vvvdecay_taudecayid"  , -211);
                    else
                        ana.tx.pushbackToBranch<int>          ("Common_gen_vvvdecay_taudecayid"  ,  211);
                }
            }

            if (abs(ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[igen]) == 11 or abs(ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[igen]) == 13)
            {
                n_light_lepton++;
            }
        }

        ana.tx.setBranch<int>("Common_gen_n_light_lep", n_light_lepton);

        int nW = 0; int nZ = 0;
        int nlepW = 0; int ntaulepW = 0; int ntauhadW = 0;
        int nlepZ = 0; int ntaulepZ = 0; int ntauhadZ = 0; int nnuZ = 0; int nbZ = 0;
        int W1 = -1; int W2 = -1; bool isSS = false;
        for (unsigned int igen = 0; igen < ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_idx").size(); ++igen)
        {
            int decay  = ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid")[igen];
            int mother = ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_mother_id")[igen];
            int leptau = ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_taudecayid")[igen];
            if(abs(mother)==24)
            {
                ++nW;
                if(abs(decay)==11 || abs(decay)==13) ++nlepW;
                else if(abs(decay)==15 && (abs(leptau)==11 || abs(leptau)==13)) ++ntaulepW;
                else if(abs(decay)==15 && abs(leptau)==211) ++ntauhadW;
                if(abs(decay)==11 || abs(decay)==13 || (abs(decay)==15 && (abs(leptau)==11 || abs(leptau)==13)))
                {
                    if(W1<0) W1 = igen;//first W
                    else
                    {
                        if(mother == ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_mother_id")[W1]) isSS = true;//first and this W are SS
                        else if(W2<0) W2 = igen;//second W
                        else if(mother == ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_mother_id")[W2]) isSS = true;//second and this W are SS
                    }
                }
            }
            if(abs(mother)==23)
            {
                ++nZ;
                if(abs(decay)==11 || abs(decay)==13) ++nlepZ;
                else if(abs(decay)==15 && (abs(leptau)==11 || abs(leptau)==13)) ++ntaulepZ;
                else if(abs(decay)==15 && abs(leptau)==211) ++ntauhadZ;
                else if(abs(decay)==12 || abs(decay)==14 || abs(decay)==16) ++nnuZ;
                else if(abs(decay)==5) ++nbZ;
            }
        }
        ana.tx.setBranch<int> ("n_W",        nW      );
        ana.tx.setBranch<int> ("n_lep_W",    nlepW   );
        ana.tx.setBranch<int> ("n_leptau_W", ntaulepW);
        ana.tx.setBranch<int> ("n_hadtau_W", ntauhadW);
        ana.tx.setBranch<int> ("n_Z",        nZ      );
        ana.tx.setBranch<int> ("n_lep_Z",    nlepZ   );
        ana.tx.setBranch<int> ("n_leptau_Z", ntaulepZ);
        ana.tx.setBranch<int> ("n_hadtau_Z", ntauhadZ);
        ana.tx.setBranch<int> ("n_nu_Z",     nnuZ    );
        ana.tx.setBranch<int> ("n_b_Z",      nbZ     );
        ana.tx.setBranch<bool>("haslepWSS",  isSS    );
    }

    //---------------------------------------------------------------------------------------------
    // Organizing object indices and sorting by Pt
    //---------------------------------------------------------------------------------------------

    // Sorting lepton branches
    ana.tx.sortVecBranchesByPt(
            /* name of the 4vector branch to use to pt sort by*/               "Common_lep_p4",
            /* names of any associated vector<float> branches to sort along */ {"Common_lep_dxy", "Common_lep_dz", "Common_lep_SF", "Common_lep_SFTight","Common_lep_SFdn","Common_lep_SFdnTight","Common_lep_SFup","Common_lep_SFupTight"},
            /* names of any associated vector<int>   branches to sort along */ {"Common_lep_idxs", "Common_lep_pdgid", "Common_lep_tight"},
            /* names of any associated vector<bool>  branches to sort along */ {}
            );

    // Sorting jet branches
    ana.tx.sortVecBranchesByPt(
            /* name of the 4vector branch to use to pt sort by*/               "Common_jet_p4",
            /* names of any associated vector<float> branches to sort along */ {},
            /* names of any associated vector<int>   branches to sort along */ {"Common_jet_idxs","Common_jet_overlapfatjet"},
            /* names of any associated vector<bool>  branches to sort along */ {"Common_jet_passBloose","Common_jet_passBmedium","Common_jet_passBtight"}
            );

    // Sorting fatjet branches
    ana.tx.sortVecBranchesByPt(
            /* name of the 4vector branch to use to pt sort by*/               "Common_fatjet_p4",
            /* names of any associated vector<float> branches to sort along */ {"Common_fatjet_msoftdrop", "Common_fatjet_deepMD_W", "Common_fatjet_deep_W", "Common_fatjet_deepMD_Z", "Common_fatjet_deep_Z", "Common_fatjet_deepMD_T", "Common_fatjet_deep_T", "Common_fatjet_deepMD_bb", "Common_fatjet_tau3", "Common_fatjet_tau2", "Common_fatjet_tau1", "Common_fatjet_tau32", "Common_fatjet_tau21", "Common_fatjet_subjet0_pt", "Common_fatjet_subjet0_eta", "Common_fatjet_subjet0_phi", "Common_fatjet_subjet0_mass", "Common_fatjet_subjet1_pt", "Common_fatjet_subjet1_eta", "Common_fatjet_subjet1_phi", "Common_fatjet_subjet1_mass", "Common_fatjet_SFVLoose", "Common_fatjet_SFLoose", "Common_fatjet_SFMedium", "Common_fatjet_SFTight", "Common_fatjet_SFdnVLoose", "Common_fatjet_SFdnLoose", "Common_fatjet_SFdnMedium", "Common_fatjet_SFdnTight", "Common_fatjet_SFupVLoose", "Common_fatjet_SFupLoose", "Common_fatjet_SFupMedium", "Common_fatjet_SFupTight"/*, "Common_fatjet_subjet0_p4", "Common_fatjet_subjet1_p4",*/
                                                                               },
            /* names of any associated vector<int>   branches to sort along */ {"Common_fatjet_idxs","Common_fatjet_WP"},
            /* names of any associated vector<bool>  branches to sort along */ {}
            );

}
