#include "Process_Common.h"

void Process_Common()
{
    if (ana.run_VVVTree)
    {
        Process_Common_VVVTree();
    }
    else
    {
        Process_Common_NanoAOD();
    }
}

void Process_Common_NanoAOD()
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
    ana.tx.setBranch<int>                  ("Common_isData", nt.isData());
    ana.tx.setBranch<int>                  ("Common_run", nt.run());
    ana.tx.setBranch<int>                  ("Common_lumi", nt.luminosityBlock());
    ana.tx.setBranch<unsigned long long>   ("Common_evt", nt.event());

    try { ana.tx.setBranch<vector<float>>("Common_event_PDF"                                    , nt.LHEPdfWeight());                                     } catch (std::runtime_error) { }
    try { ana.tx.setBranch<vector<float>>("Common_event_QCDScale"                               , nt.LHEScaleWeight());                                   } catch (std::runtime_error) { }

    try { ana.tx.setBranch<float>("Common_event_puWeight"                                       , nt.puWeight());                                         } catch (std::runtime_error) { ana.tx.setBranch<float>("Common_event_puWeight"                                     , 1.); }
    try { ana.tx.setBranch<float>("Common_event_puWeightup"                                     , nt.puWeightUp());                                       } catch (std::runtime_error) { ana.tx.setBranch<float>("Common_event_puWeightup"                                   , 1.); }
    try { ana.tx.setBranch<float>("Common_event_puWeightdn"                                     , nt.puWeightDown());                                     } catch (std::runtime_error) { ana.tx.setBranch<float>("Common_event_puWeightdn"                                   , 1.); }

    try { ana.tx.setBranch<float>("Common_event_prefireWeight"                                  , nt.PrefireWeight());                                    } catch (std::runtime_error) { ana.tx.setBranch<float>("Common_event_prefireWeight"                                , 1.); }
    try { ana.tx.setBranch<float>("Common_event_prefireWeightup"                                , nt.PrefireWeight_Up());                                 } catch (std::runtime_error) { ana.tx.setBranch<float>("Common_event_prefireWeightup"                              , 1.); }
    try { ana.tx.setBranch<float>("Common_event_prefireWeightdn"                                , nt.PrefireWeight_Down());                               } catch (std::runtime_error) { ana.tx.setBranch<float>("Common_event_prefireWeightdn"                         , 1.); }
    if (not nt.isData())
    {
        ana.tx.setBranch<float>            ("Common_genWeight", nt.genWeight());
        if (nt.year() == 2016)
            ana.tx.setBranch<float>        ("Common_btagWeight_DeepCSVB", 1); // TODO
        else
            ana.tx.setBranch<float>        ("Common_btagWeight_DeepCSVB", nt.btagWeight_DeepCSVB());
        if (ana.is_EFT_sample)
            ana.tx.setBranch<vector<float>>("Common_LHEWeight_mg_reweighting", nt.LHEReweightingWeight());
        ana.tx.setBranch<float>            ("Common_wgt", ana.wgt * ((nt.genWeight() > 0) - (nt.genWeight() < 0)));
    }
    else
    {
        ana.tx.setBranch<float>            ("Common_genWeight", 1);
        ana.tx.setBranch<float>            ("Common_btagWeight_DeepCSVB", 1);
        ana.tx.setBranch<float>            ("Common_wgt", 1);
    }

    //---------------------------------------------------------------------------------------------
    // Trigger information
    //---------------------------------------------------------------------------------------------

    try { ana.tx.setBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ"                , nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ());                } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ"                , 0); } // Lowest unprescaled
    try { ana.tx.setBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL"                   , nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL());                   } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL"                   , 0); } // Lowest unprescaled
    try { ana.tx.setBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8"        , nt.HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8());        } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8"        , 0); } // Lowest unprescaled for >= 2017C
    try { ana.tx.setBranch<bool>("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ"          , nt.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ());          } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ"          , 0); } 
    try { ana.tx.setBranch<bool>("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL"             , nt.HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL());             } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL"             , 0); } // Lowest unprescaled
    try { ana.tx.setBranch<bool>("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ" , nt.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ()); } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ" , 0); } // Lowest unprescaled
    try { ana.tx.setBranch<bool>("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL"    , nt.HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL());    } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL"    , 0); } 
    try { ana.tx.setBranch<bool>("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ"  , nt.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ());  } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ"  , 0); } // Lowest unprescaled
    try { ana.tx.setBranch<bool>("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL"     , nt.HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL());     } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL"     , 0); } 
    try { ana.tx.setBranch<bool>("Common_HLT_PFHT1050"                                       , nt.HLT_PFHT1050());                                       } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_PFHT1050"     , 0); } 
    try { ana.tx.setBranch<bool>("Common_HLT_AK8PFJet500"                                     , nt.HLT_AK8PFJet500());                                   } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_AK8PFJet500"     , 0); } 
    try { ana.tx.setBranch<bool>("Common_HLT_AK8PFJet380_TrimMass30"     , nt.HLT_AK8PFJet380_TrimMass30());     } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_AK8PFJet380_TrimMass30"     , 0); } 
    try { ana.tx.setBranch<bool>("Common_HLT_AK8PFJet360_TrimMass30"     , nt.HLT_AK8PFJet360_TrimMass30());     } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_AK8PFJet360_TrimMass30"     , 0); } 
    try { ana.tx.setBranch<bool>("Common_HLT_AK8PFJet400_TrimMass30"     , nt.HLT_AK8PFJet400_TrimMass30());     } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_AK8PFJet400_TrimMass30"     , 0); } 
    try { ana.tx.setBranch<bool>("Common_HLT_AK8PFJet420_TrimMass30"     , nt.HLT_AK8PFJet420_TrimMass30());     } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_AK8PFJet420_TrimMass30"     , 0); } 
    try { ana.tx.setBranch<bool>("Common_HLT_AK8PFHT750_TrimMass50"     , nt.HLT_AK8PFHT750_TrimMass50());     } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_AK8PFHT750_TrimMass50"     , 0); } 
    try { ana.tx.setBranch<bool>("Common_HLT_AK8PFHT800_TrimMass50"     , nt.HLT_AK8PFHT800_TrimMass50());     } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_AK8PFHT800_TrimMass50"     , 0); } 
    try { ana.tx.setBranch<bool>("Common_HLT_AK8PFHT850_TrimMass50"     , nt.HLT_AK8PFHT850_TrimMass50());     } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_AK8PFHT850_TrimMass50"     , 0); } 
    try { ana.tx.setBranch<bool>("Common_HLT_AK8PFHT900_TrimMass50"     , nt.HLT_AK8PFHT900_TrimMass50());     } catch (std::runtime_error) { ana.tx.setBranch<bool>("Common_HLT_AK8PFHT900_TrimMass50"     , 0); } 


    bool is_pd_ee = ana.looper.getCurrentFileName().Contains("DoubleEG") or ana.looper.getCurrentFileName().Contains("EGamma");
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
        if (not trig_mm and not trig_em and trig_ee)
            pass_duplicate_mm_em_ee = true;
    }
    else if (is_pd_em)
    {
        if (not trig_ee and trig_em)
            pass_duplicate_ee_em_mm = true;
        if (not trig_mm and trig_em)
            pass_duplicate_mm_em_ee = true;
    }
    else if (is_pd_mm)
    {
        if (not trig_ee and not trig_em and trig_mm)
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
            filterflag   = nt.Flag_goodVertices() and nt.Flag_globalSuperTightHalo2016Filter() and nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter();
            filterflagMC = nt.Flag_goodVertices() and                                              nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter();
            break;
        case 2017:
            filterflag   = nt.Flag_goodVertices() and nt.Flag_globalSuperTightHalo2016Filter() and nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter() and nt.Flag_ecalBadCalibFilter();
            filterflagMC = nt.Flag_goodVertices() and                                              nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter() and nt.Flag_ecalBadCalibFilter();
            break;
        case 2018:
            filterflag   = nt.Flag_goodVertices() and nt.Flag_globalSuperTightHalo2016Filter() and nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter() and nt.Flag_ecalBadCalibFilter();
            filterflagMC = nt.Flag_goodVertices() and                                              nt.Flag_HBHENoiseFilter() and nt.Flag_HBHENoiseIsoFilter() and nt.Flag_EcalDeadCellTriggerPrimitiveFilter() and nt.Flag_BadPFMuonFilter() and nt.Flag_ecalBadCalibFilter();
            break;
    }
    ana.tx.setBranch<bool>("Common_noiseFlag"  , filterflag  ); // Flag to identify whether the event passes noise filter
    ana.tx.setBranch<bool>("Common_noiseFlagMC", filterflagMC); // Flag to identify whether the event passes noise filter

    //check good runs list
    bool goodRun = true; //set true for MC
    if(nt.isData()) goodRun = goodrun(nt.run(), nt.luminosityBlock());

    ana.tx.setBranch<bool>("Common_passGoodRun", goodRun);
    
    // Example of reading from Nano
    // std::vector<LorentzVector> electron_p4s = nt.Electron_p4(); // nt is a global variable that accesses NanoAOD
    // std::vector<float> electron_mvaTTH = nt.Electron_mvaTTH(); // electron ttH MVA scores from NanoAOD
    // Semi-complete list of NanoAOD for 102X can be found here: https://cms-nanoaod-integration.web.cern.ch/integration/master-102X/mc102X_doc.html
    // Also consult here: https://github.com/cmstas/NanoTools/blob/d641a6d6c1aa9ecc8094a1af73d5e1bd7d6502ab/NanoCORE/Nano.h#L4875 (if new variables are added they may show up in master)
    float lepSFc(1.), lepSFue(1.), lepSFde(1.), lepSFum(1.), lepSFdm(1.);
    float lepSFcTight(1.),lepSFueTight(1.),lepSFdeTight(1.),lepSFumTight(1.),lepSFdmTight(1.);
    //---------------------------------------------------------------------------------------------
    // Electron selection
    //---------------------------------------------------------------------------------------------
    // Loop over electrons and select Fall17V2Iso_WP90 electrons
    for (unsigned int iel = 0; iel < nt.Electron_p4().size(); ++iel)
    {
        // Selections
        if (not (nt.Electron_mvaFall17V2Iso_WP90()[iel])) continue;
        if (not (nt.Electron_p4()[iel].pt()       > 10.)) continue;
        if (not (abs(nt.Electron_p4()[iel].eta()) < 2.5)) continue;
        if (abs(nt.Electron_p4()[iel].eta()) < 1.566 && abs(nt.Electron_p4()[iel].eta()) > 1.444) continue; 

        // If passed up to here add it to the index list
        ana.tx.pushbackToBranch<int>("Common_lep_idxs", iel);
        ana.tx.pushbackToBranch<int>("Common_lep_pdgid", nt.Electron_pdgId()[iel]);
        ana.tx.pushbackToBranch<LorentzVector>("Common_lep_p4", nt.Electron_p4()[iel]);
        ana.tx.pushbackToBranch<int>("Common_lep_tight", nt.Electron_mvaFall17V2Iso_WP80()[iel]);
        ana.tx.pushbackToBranch<float>("Common_lep_dxy", nt.Electron_dxy()[iel]);
        ana.tx.pushbackToBranch<float>("Common_lep_dz", nt.Electron_dz()[iel]);
        ana.tx.pushbackToBranch<float>("Common_lep_ip3d", nt.Electron_ip3d()[iel]);
        ana.tx.pushbackToBranch<float>("Common_lep_sip3d", nt.Electron_sip3d()[iel]);
        //---------
        // bool istight = nt.Electron_mvaFall17V2Iso_WP80()[iel];
        float pt = std::min(std::max(nt.Electron_p4()[iel].pt(), 10.01f), 499.9f);
        float eta = std::min(std::max(nt.Electron_p4()[iel].eta(), -2.499f), 2.499f);
        float sf = (pt > 20 ? ana.electronRECOSFgt20->eval(eta, pt) : ana.electronRECOSFlt20->eval(eta, pt)) * ana.electronMVAID90SF->eval(eta, pt);
        lepSFc  *= sf;
        lepSFum *= sf;
        lepSFdm *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SF",        sf);
        sf       = (pt > 20 ? ana.electronRECOSFgt20->eval_up(eta, pt) : ana.electronRECOSFlt20->eval_up(eta, pt)) * ana.electronMVAID90SF->eval_up(eta, pt);
        lepSFue *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFup",      sf);
        sf       = (pt > 20 ? ana.electronRECOSFgt20->eval_down(eta, pt) : ana.electronRECOSFlt20->eval_down(eta, pt)) * ana.electronMVAID90SF->eval_down(eta, pt);
        lepSFde *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFdn",      sf);
        sf       = (pt > 20 ? ana.electronRECOSFgt20->eval(eta, pt) : ana.electronRECOSFlt20->eval(eta, pt)) * ana.electronMVAID80SF->eval(eta, pt);
        lepSFcTight  *= sf;
        lepSFumTight *= sf;
        lepSFdmTight *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFTight",   sf);
        sf       = (pt > 20 ? ana.electronRECOSFgt20->eval_up(eta, pt) : ana.electronRECOSFlt20->eval_up(eta, pt)) * ana.electronMVAID80SF->eval_up(eta, pt);
        lepSFueTight *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFupTight", sf);
        sf       = (pt > 20 ? ana.electronRECOSFgt20->eval_down(eta, pt) : ana.electronRECOSFlt20->eval_down(eta, pt)) * ana.electronMVAID80SF->eval_down(eta, pt);
        lepSFdeTight *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFdnTight", sf);

        //---------
        // float sf = ana.leptonscalefactors.leptonSF(nt.isData(),nt.year(),11,nt.Electron_p4()[iel].eta(),nt.Electron_p4()[iel].pt(),nt.event(), 0);
        // lepSFc  *= sf;
        // lepSFum *= sf;
        // lepSFdm *= sf;
        // ana.tx.pushbackToBranch<float>("Common_lep_SF",        sf);
        // ana.tx.pushbackToBranch<float>("Common_lep_SFTight",   sf);
        // sf       = ana.leptonscalefactors.leptonSF(nt.isData(),nt.year(),11,nt.Electron_p4()[iel].eta(),nt.Electron_p4()[iel].pt(),nt.event(),+1);
        // lepSFue *= sf;
        // ana.tx.pushbackToBranch<float>("Common_lep_SFup",      sf);
        // ana.tx.pushbackToBranch<float>("Common_lep_SFupTight", sf);
        // sf       = ana.leptonscalefactors.leptonSF(nt.isData(),nt.year(),11,nt.Electron_p4()[iel].eta(),nt.Electron_p4()[iel].pt(),nt.event(),-1);
        // lepSFde *= sf;
        // ana.tx.pushbackToBranch<float>("Common_lep_SFdn",      sf);
        // ana.tx.pushbackToBranch<float>("Common_lep_SFdnTight", sf);
    }

    //---------------------------------------------------------------------------------------------
    // Muon selection
    //---------------------------------------------------------------------------------------------
    // Loop over muons and select POG medium muons
    for (unsigned int imu = 0; imu < nt.Muon_p4().size(); ++imu)
    {
        // Selections
        if (not (nt.Muon_mediumId()[imu]             )) continue; // TODO: What is Muon_mediumPromptId in NanoAOD?
        if (not (nt.Muon_p4()[imu].pt()        > 10. )) continue;
        if (not (nt.Muon_pfRelIso04_all()[imu] < 0.25)) continue; // i.e. Loose from https://twiki.cern.ch/twiki/bin/view/CMS/SWGuideMuonSelection#Particle_Flow_isolation
        if (not (abs(nt.Muon_p4()[imu].eta())  < 2.4 )) continue;

        // If passed up to here add it to the index list
        ana.tx.pushbackToBranch<int>("Common_lep_idxs", imu);
        ana.tx.pushbackToBranch<int>("Common_lep_pdgid", nt.Muon_pdgId()[imu]);
        ana.tx.pushbackToBranch<LorentzVector>("Common_lep_p4", nt.Muon_p4()[imu]);
        ana.tx.pushbackToBranch<int>("Common_lep_tight", nt.Muon_pfRelIso04_all()[imu] < 0.15); // i.e. Tight from https://twiki.cern.ch/twiki/bin/view/CMS/SWGuideMuonSelection#Particle_Flow_isolation
        ana.tx.pushbackToBranch<float>("Common_lep_dxy", nt.Muon_dxy()[imu]);
        ana.tx.pushbackToBranch<float>("Common_lep_dz", nt.Muon_dz()[imu]);
        ana.tx.pushbackToBranch<float>("Common_lep_ip3d", nt.Muon_ip3d()[imu]);
        ana.tx.pushbackToBranch<float>("Common_lep_sip3d", nt.Muon_sip3d()[imu]);
        //---------
        // bool istight = nt.Muon_pfRelIso04_all()[imu] < 0.15;
        // float ptreco = std::min(std::max(nt.Muon_p4()[imu].pt(), 2.01f), 39.9f);	//scale factor for reco pt of muon ranged in [2,40]
        // scale factor for muon reco is measured in 40 to 60GeV, but availabe for 10 to 200GeV,
        // see https://twiki.cern.ch/twiki/bin/viewauth/CMS/MuonUL2018#RECO_efficiency
        float pt = std::min(std::max(nt.Muon_p4()[imu].pt(), 15.01f), 119.9f);
        float abseta = std::min(std::max(fabs(nt.Muon_p4()[imu].eta()), 0.01f), 2.399f);
        float sf = ana.muonRECOSF->eval(abseta, 50.0f) * ana.muonIDSFMedium->eval(abseta, pt) * ana.muonISOSFLoose->eval(abseta, pt);
        lepSFc  *= sf;
        lepSFue *= sf;
        lepSFde *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SF",        sf);
        sf       = ana.muonRECOSF->eval_up(abseta, 50.0f) * ana.muonIDSFMedium->eval_up(abseta, pt) * ana.muonISOSFLoose->eval_up(abseta, pt);
        lepSFum *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFup",      sf);
        sf       = ana.muonRECOSF->eval_down(abseta, 50.0f) * ana.muonIDSFMedium->eval_down(abseta, pt) * ana.muonISOSFLoose->eval_down(abseta, pt);
        lepSFdm *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFdn",      sf);
        sf = ana.muonRECOSF->eval(abseta, 50.0f) * ana.muonIDSFMedium->eval(abseta, pt) * ana.muonISOSFTight->eval(abseta, pt);
        lepSFcTight  *= sf;
        lepSFueTight *= sf;
        lepSFdeTight *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFTight",   sf);
        sf       = ana.muonRECOSF->eval_up(abseta, 50.0f) * ana.muonIDSFMedium->eval_up(abseta, pt) * ana.muonISOSFTight->eval_up(abseta, pt);
        lepSFumTight *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFupTight", sf);
        sf       = ana.muonRECOSF->eval_down(abseta, 50.0f) * ana.muonIDSFMedium->eval_down(abseta, pt) * ana.muonISOSFTight->eval_down(abseta, pt);
        lepSFdmTight *= sf;
        ana.tx.pushbackToBranch<float>("Common_lep_SFdnTight", sf);
        //---------
        // string period = "X";
        // if (nt.year() == 2016 and nt.run() <= 278808) period = "BCDEF";
        // else if (nt.year() == 2016) period = "GH";
        // float sf = ana.leptonscalefactors.leptonSF(nt.isData(),nt.year(),13,nt.Muon_p4()[imu].eta(),nt.Muon_p4()[imu].pt(),nt.event(), 0);
        // lepSFc  *= sf;
        // lepSFue *= sf;
        // lepSFde *= sf;
        // ana.tx.pushbackToBranch<float>("Common_lep_SF",        sf);
        // ana.tx.pushbackToBranch<float>("Common_lep_SFTight",   sf);
        // sf       = ana.leptonscalefactors.leptonSF(nt.isData(),nt.year(),13,nt.Muon_p4()[imu].eta(),nt.Muon_p4()[imu].pt(),nt.event(),+1);
        // lepSFum *= sf;
        // ana.tx.pushbackToBranch<float>("Common_lep_SFup",      sf);
        // ana.tx.pushbackToBranch<float>("Common_lep_SFupTight", sf);
        // sf       = ana.leptonscalefactors.leptonSF(nt.isData(),nt.year(),13,nt.Muon_p4()[imu].eta(),nt.Muon_p4()[imu].pt(),nt.event(),-1);
        // lepSFdm *= sf;
        // ana.tx.pushbackToBranch<float>("Common_lep_SFdn",      sf);
        // ana.tx.pushbackToBranch<float>("Common_lep_SFdnTight", sf);
    }

    ana.tx.setBranch<float>("Common_event_lepSF"      , lepSFc );
    ana.tx.setBranch<float>("Common_event_lepSFelup"  , lepSFue);
    ana.tx.setBranch<float>("Common_event_lepSFeldn"  , lepSFde);
    ana.tx.setBranch<float>("Common_event_lepSFmuup"  , lepSFum);
    ana.tx.setBranch<float>("Common_event_lepSFmudn"  , lepSFdm);

    ana.tx.setBranch<float>("Common_event_lepSFTight"      , lepSFcTight );
    ana.tx.setBranch<float>("Common_event_lepSFelupTight"  , lepSFueTight);
    ana.tx.setBranch<float>("Common_event_lepSFeldnTight"  , lepSFdeTight);
    ana.tx.setBranch<float>("Common_event_lepSFmuupTight"  , lepSFumTight);
    ana.tx.setBranch<float>("Common_event_lepSFmudnTight"  , lepSFdmTight);

    //---------------------------------------------------------------------------------------------

    // b-tagging counter (DeepFlavB)
    float bWPloose  = gconf.WP_DeepFlav_loose;
    float bWPmedium = gconf.WP_DeepFlav_medium;
    float bWPtight  = gconf.WP_DeepFlav_tight;
    int nb_loose = 0;
    int nb_medium = 0;
    int nb_tight = 0;
    int nb_loose_jesAbsoluteStatup = 0;
    int nb_loose_jesAbsoluteStatdn = 0;
    int nb_loose_jesAbsoluteScaleup = 0;            
    int nb_loose_jesAbsoluteScaledn = 0;
    int nb_loose_jesAbsoluteMPFBiasup = 0;
    int nb_loose_jesAbsoluteMPFBiasdn = 0;
    int nb_loose_jesFragmentationup = 0;
    int nb_loose_jesFragmentationdn = 0;
    int nb_loose_jesSinglePionECALup = 0;
    int nb_loose_jesSinglePionECALdn = 0;
    int nb_loose_jesSinglePionHCALup = 0;
    int nb_loose_jesSinglePionHCALdn = 0;
    int nb_loose_jesFlavorQCDup = 0;
    int nb_loose_jesFlavorQCDdn = 0;
    int nb_loose_jesTimePtEtaup = 0;
    int nb_loose_jesTimePtEtadn = 0;
    int nb_loose_jesRelativeJEREC1up = 0;
    int nb_loose_jesRelativeJEREC1dn = 0;
    int nb_loose_jesRelativeJEREC2up = 0;
    int nb_loose_jesRelativeJEREC2dn = 0;
    int nb_loose_jesRelativeJERHFup = 0;
    int nb_loose_jesRelativeJERHFdn = 0;
    int nb_loose_jesRelativePtBBup = 0;
    int nb_loose_jesRelativePtBBdn = 0;
    int nb_loose_jesRelativePtEC1up = 0;
    int nb_loose_jesRelativePtEC1dn = 0;
    int nb_loose_jesRelativePtEC2up = 0;
    int nb_loose_jesRelativePtEC2dn = 0;
    int nb_loose_jesRelativePtHFup = 0;
    int nb_loose_jesRelativePtHFdn = 0;
    int nb_loose_jesRelativeBalup = 0;
    int nb_loose_jesRelativeBaldn = 0;
    int nb_loose_jesRelativeSampleup = 0;
    int nb_loose_jesRelativeSampledn = 0;
    int nb_loose_jesRelativeFSRup = 0;
    int nb_loose_jesRelativeFSRdn = 0;
    int nb_loose_jesRelativeStatFSRup = 0;
    int nb_loose_jesRelativeStatFSRdn = 0;
    int nb_loose_jesRelativeStatECup = 0;
    int nb_loose_jesRelativeStatECdn = 0;
    int nb_loose_jesRelativeStatHFup = 0;
    int nb_loose_jesRelativeStatHFdn = 0;
    int nb_loose_jesPileUpDataMCup = 0;
    int nb_loose_jesPileUpDataMCdn = 0;
    int nb_loose_jesPileUpPtRefup = 0;
    int nb_loose_jesPileUpPtRefdn = 0;
    int nb_loose_jesPileUpPtBBup = 0;
    int nb_loose_jesPileUpPtBBdn = 0;
    int nb_loose_jesPileUpPtEC1up = 0;
    int nb_loose_jesPileUpPtEC1dn = 0;
    int nb_loose_jesPileUpPtEC2up = 0;
    int nb_loose_jesPileUpPtEC2dn = 0;
    int nb_loose_jesPileUpPtHFup = 0;
    int nb_loose_jesPileUpPtHFdn = 0;
    int nb_loose_jesup = 0;
    int nb_loose_jesdn = 0;
    int nb_loose_jerup = 0;
    int nb_loose_jerdn = 0;
    int nb_medium_jesAbsoluteStatup = 0;
    int nb_medium_jesAbsoluteStatdn = 0;
    int nb_medium_jesAbsoluteScaleup = 0;            
    int nb_medium_jesAbsoluteScaledn = 0;
    int nb_medium_jesAbsoluteMPFBiasup = 0;
    int nb_medium_jesAbsoluteMPFBiasdn = 0;
    int nb_medium_jesFragmentationup = 0;
    int nb_medium_jesFragmentationdn = 0;
    int nb_medium_jesSinglePionECALup = 0;
    int nb_medium_jesSinglePionECALdn = 0;
    int nb_medium_jesSinglePionHCALup = 0;
    int nb_medium_jesSinglePionHCALdn = 0;
    int nb_medium_jesFlavorQCDup = 0;
    int nb_medium_jesFlavorQCDdn = 0;
    int nb_medium_jesTimePtEtaup = 0;
    int nb_medium_jesTimePtEtadn = 0;
    int nb_medium_jesRelativeJEREC1up = 0;
    int nb_medium_jesRelativeJEREC1dn = 0;
    int nb_medium_jesRelativeJEREC2up = 0;
    int nb_medium_jesRelativeJEREC2dn = 0;
    int nb_medium_jesRelativeJERHFup = 0;
    int nb_medium_jesRelativeJERHFdn = 0;
    int nb_medium_jesRelativePtBBup = 0;
    int nb_medium_jesRelativePtBBdn = 0;
    int nb_medium_jesRelativePtEC1up = 0;
    int nb_medium_jesRelativePtEC1dn = 0;
    int nb_medium_jesRelativePtEC2up = 0;
    int nb_medium_jesRelativePtEC2dn = 0;
    int nb_medium_jesRelativePtHFup = 0;
    int nb_medium_jesRelativePtHFdn = 0;
    int nb_medium_jesRelativeBalup = 0;
    int nb_medium_jesRelativeBaldn = 0;
    int nb_medium_jesRelativeSampleup = 0;
    int nb_medium_jesRelativeSampledn = 0;
    int nb_medium_jesRelativeFSRup = 0;
    int nb_medium_jesRelativeFSRdn = 0;
    int nb_medium_jesRelativeStatFSRup = 0;
    int nb_medium_jesRelativeStatFSRdn = 0;
    int nb_medium_jesRelativeStatECup = 0;
    int nb_medium_jesRelativeStatECdn = 0;
    int nb_medium_jesRelativeStatHFup = 0;
    int nb_medium_jesRelativeStatHFdn = 0;
    int nb_medium_jesPileUpDataMCup = 0;
    int nb_medium_jesPileUpDataMCdn = 0;
    int nb_medium_jesPileUpPtRefup = 0;
    int nb_medium_jesPileUpPtRefdn = 0;
    int nb_medium_jesPileUpPtBBup = 0;
    int nb_medium_jesPileUpPtBBdn = 0;
    int nb_medium_jesPileUpPtEC1up = 0;
    int nb_medium_jesPileUpPtEC1dn = 0;
    int nb_medium_jesPileUpPtEC2up = 0;
    int nb_medium_jesPileUpPtEC2dn = 0;
    int nb_medium_jesPileUpPtHFup = 0;
    int nb_medium_jesPileUpPtHFdn = 0;
    int nb_medium_jesup = 0;
    int nb_medium_jesdn = 0;    
    int nb_medium_jerup = 0;
    int nb_medium_jerdn = 0;
    int nb_tight_jesAbsoluteStatup = 0;
    int nb_tight_jesAbsoluteStatdn = 0;
    int nb_tight_jesAbsoluteScaleup = 0;            
    int nb_tight_jesAbsoluteScaledn = 0;
    int nb_tight_jesAbsoluteMPFBiasup = 0;
    int nb_tight_jesAbsoluteMPFBiasdn = 0;
    int nb_tight_jesFragmentationup = 0;
    int nb_tight_jesFragmentationdn = 0;
    int nb_tight_jesSinglePionECALup = 0;
    int nb_tight_jesSinglePionECALdn = 0;
    int nb_tight_jesSinglePionHCALup = 0;
    int nb_tight_jesSinglePionHCALdn = 0;
    int nb_tight_jesFlavorQCDup = 0;
    int nb_tight_jesFlavorQCDdn = 0;
    int nb_tight_jesTimePtEtaup = 0;
    int nb_tight_jesTimePtEtadn = 0;
    int nb_tight_jesRelativeJEREC1up = 0;
    int nb_tight_jesRelativeJEREC1dn = 0;
    int nb_tight_jesRelativeJEREC2up = 0;
    int nb_tight_jesRelativeJEREC2dn = 0;
    int nb_tight_jesRelativeJERHFup = 0;
    int nb_tight_jesRelativeJERHFdn = 0;
    int nb_tight_jesRelativePtBBup = 0;
    int nb_tight_jesRelativePtBBdn = 0;
    int nb_tight_jesRelativePtEC1up = 0;
    int nb_tight_jesRelativePtEC1dn = 0;
    int nb_tight_jesRelativePtEC2up = 0;
    int nb_tight_jesRelativePtEC2dn = 0;
    int nb_tight_jesRelativePtHFup = 0;
    int nb_tight_jesRelativePtHFdn = 0;
    int nb_tight_jesRelativeBalup = 0;
    int nb_tight_jesRelativeBaldn = 0;
    int nb_tight_jesRelativeSampleup = 0;
    int nb_tight_jesRelativeSampledn = 0;
    int nb_tight_jesRelativeFSRup = 0;
    int nb_tight_jesRelativeFSRdn = 0;
    int nb_tight_jesRelativeStatFSRup = 0;
    int nb_tight_jesRelativeStatFSRdn = 0;
    int nb_tight_jesRelativeStatECup = 0;
    int nb_tight_jesRelativeStatECdn = 0;
    int nb_tight_jesRelativeStatHFup = 0;
    int nb_tight_jesRelativeStatHFdn = 0;
    int nb_tight_jesPileUpDataMCup = 0;
    int nb_tight_jesPileUpDataMCdn = 0;
    int nb_tight_jesPileUpPtRefup = 0;
    int nb_tight_jesPileUpPtRefdn = 0;
    int nb_tight_jesPileUpPtBBup = 0;
    int nb_tight_jesPileUpPtBBdn = 0;
    int nb_tight_jesPileUpPtEC1up = 0;
    int nb_tight_jesPileUpPtEC1dn = 0;
    int nb_tight_jesPileUpPtEC2up = 0;
    int nb_tight_jesPileUpPtEC2dn = 0;
    int nb_tight_jesPileUpPtHFup = 0;
    int nb_tight_jesPileUpPtHFdn = 0;
    int nb_tight_jesup = 0;
    int nb_tight_jesdn = 0;
    int nb_tight_jerup = 0;
    int nb_tight_jerdn = 0;
    float btagTight_prob_MC = 1;
    float btagTight_prob_DATA = 1;
    float btagTight_up_prob_DATA = 1;
    float btagTight_dn_prob_DATA = 1;
    float btagTight_HFup_prob_DATA = 1;
    float btagTight_HFdn_prob_DATA = 1;
    float btagTight_LFup_prob_DATA = 1;
    float btagTight_LFdn_prob_DATA = 1;
    float btagMedium_prob_MC = 1;
    float btagMedium_prob_DATA = 1;
    float btagMedium_up_prob_DATA = 1;
    float btagMedium_dn_prob_DATA = 1;
    float btagMedium_HFup_prob_DATA = 1;
    float btagMedium_HFdn_prob_DATA = 1;
    float btagMedium_LFup_prob_DATA = 1;
    float btagMedium_LFdn_prob_DATA = 1;
    float btagLoose_prob_MC = 1;
    float btagLoose_prob_DATA = 1;
    float btagLoose_up_prob_DATA = 1;
    float btagLoose_dn_prob_DATA = 1;
    float btagLoose_HFup_prob_DATA = 1;
    float btagLoose_HFdn_prob_DATA = 1;
    float btagLoose_LFup_prob_DATA = 1;
    float btagLoose_LFdn_prob_DATA = 1;

    // Loop over jets and do a simple overlap removal against leptons
    for (unsigned int ijet = 0; ijet < nt.Jet_p4().size(); ++ijet)
    {
	    LorentzVector jet_p4;
        if (ana.is_postprocessed)
        {
            jet_p4=LorentzVector(nt.Jet_pt_nom()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_nom()[ijet]);
        }
	    else 
        {
            jet_p4=nt.Jet_p4()[ijet];
        }
        // TODO: What is POG recommendation? do we use nt.Jet_jetId()? nt.Jet_puId()??
        // Figure this out
        // For now if less than 20 GeV, don't ever consider, unless studying jes and jer with postprocessed samples
        if (not (jet_p4.pt() > 20. or (ana.systematicVariation and ana.is_postprocessed and !nt.isData())))
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
                if (RooUtil::Calc::DeltaR(jet_p4, nt.Electron_p4()[ilep_idx]) < 0.4)
                {
                    is_overlapping_with_a_lepton = true;
                    break;
                }
            }
            // else muon
            else
            {
                if (RooUtil::Calc::DeltaR(jet_p4, nt.Muon_p4()[ilep_idx]) < 0.4)
                {
                    is_overlapping_with_a_lepton = true;
                    break;
                }
            }
        }

        if (is_overlapping_with_a_lepton)
            continue;

        // For the analysis level jets, consider jets only 30 and above
        if ((jet_p4.pt() > 30. or (ana.systematicVariation and ana.is_postprocessed and !nt.isData())) and abs(jet_p4.eta()) < 3.0)//don't trust jets in HF
        {
            // For now, accept anything that reaches this point
            ana.tx.pushbackToBranch<int>("Common_jet_idxs", ijet);
            ana.tx.pushbackToBranch<int>("Common_jet_id", nt.Jet_jetId()[ijet]);
            ana.tx.pushbackToBranch<int>("Common_jet_puid", nt.Jet_puId()[ijet]);
            ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4", jet_p4);
            ana.tx.pushbackToBranch<bool>("Common_jet_passBloose" , nt.Jet_btagDeepFlavB()[ijet] > bWPloose );
            ana.tx.pushbackToBranch<bool>("Common_jet_passBmedium", nt.Jet_btagDeepFlavB()[ijet] > bWPmedium);
            ana.tx.pushbackToBranch<bool>("Common_jet_passBtight" , nt.Jet_btagDeepFlavB()[ijet] > bWPtight );
            if (ana.systematicVariation and ana.is_postprocessed and !nt.isData())
            {                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesAbsoluteStatup", LorentzVector(nt.Jet_pt_jesAbsoluteStatUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesAbsoluteStatUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesAbsoluteStatdn", LorentzVector(nt.Jet_pt_jesAbsoluteStatDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesAbsoluteStatDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesAbsoluteScaleup", LorentzVector(nt.Jet_pt_jesAbsoluteScaleUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesAbsoluteScaleUp()[ijet]));            
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesAbsoluteScaledn", LorentzVector(nt.Jet_pt_jesAbsoluteScaleDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesAbsoluteScaleDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesAbsoluteMPFBiasup", LorentzVector(nt.Jet_pt_jesAbsoluteMPFBiasUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesAbsoluteMPFBiasUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesAbsoluteMPFBiasdn", LorentzVector(nt.Jet_pt_jesAbsoluteMPFBiasDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesAbsoluteMPFBiasDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesFragmentationup", LorentzVector(nt.Jet_pt_jesFragmentationUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesFragmentationUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesFragmentationdn", LorentzVector(nt.Jet_pt_jesFragmentationDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesFragmentationDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesSinglePionECALup", LorentzVector(nt.Jet_pt_jesSinglePionECALUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesSinglePionECALUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesSinglePionECALdn", LorentzVector(nt.Jet_pt_jesSinglePionECALDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesSinglePionECALDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesSinglePionHCALup", LorentzVector(nt.Jet_pt_jesSinglePionHCALUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesSinglePionHCALUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesSinglePionHCALdn", LorentzVector(nt.Jet_pt_jesSinglePionHCALDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesSinglePionHCALDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesFlavorQCDup", LorentzVector(nt.Jet_pt_jesFlavorQCDUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesFlavorQCDUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesFlavorQCDdn", LorentzVector(nt.Jet_pt_jesFlavorQCDDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesFlavorQCDDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesTimePtEtaup", LorentzVector(nt.Jet_pt_jesTimePtEtaUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesTimePtEtaUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesTimePtEtadn", LorentzVector(nt.Jet_pt_jesTimePtEtaDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesTimePtEtaDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeJEREC1up", LorentzVector(nt.Jet_pt_jesRelativeJEREC1Up()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeJEREC1Up()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeJEREC1dn", LorentzVector(nt.Jet_pt_jesRelativeJEREC1Down()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeJEREC1Down()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeJEREC2up", LorentzVector(nt.Jet_pt_jesRelativeJEREC2Up()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeJEREC2Up()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeJEREC2dn", LorentzVector(nt.Jet_pt_jesRelativeJEREC2Down()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeJEREC2Down()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeJERHFup", LorentzVector(nt.Jet_pt_jesRelativeJERHFUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeJERHFUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeJERHFdn", LorentzVector(nt.Jet_pt_jesRelativeJERHFDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeJERHFDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativePtBBup", LorentzVector(nt.Jet_pt_jesRelativePtBBUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativePtBBUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativePtBBdn", LorentzVector(nt.Jet_pt_jesRelativePtBBDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativePtBBDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativePtEC1up", LorentzVector(nt.Jet_pt_jesRelativePtEC1Up()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativePtEC1Up()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativePtEC1dn", LorentzVector(nt.Jet_pt_jesRelativePtEC1Down()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativePtEC1Down()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativePtEC2up", LorentzVector(nt.Jet_pt_jesRelativePtEC2Up()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativePtEC2Up()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativePtEC2dn", LorentzVector(nt.Jet_pt_jesRelativePtEC2Down()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativePtEC2Down()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativePtHFup", LorentzVector(nt.Jet_pt_jesRelativePtHFUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativePtHFUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativePtHFdn", LorentzVector(nt.Jet_pt_jesRelativePtHFDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativePtHFDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeBalup", LorentzVector(nt.Jet_pt_jesRelativeBalUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeBalUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeBaldn", LorentzVector(nt.Jet_pt_jesRelativeBalDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeBalDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeSampleup", LorentzVector(nt.Jet_pt_jesRelativeSampleUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeSampleUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeSampledn", LorentzVector(nt.Jet_pt_jesRelativeSampleDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeSampleDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeFSRup", LorentzVector(nt.Jet_pt_jesRelativeFSRUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeFSRUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeFSRdn", LorentzVector(nt.Jet_pt_jesRelativeFSRDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeFSRDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeStatFSRup", LorentzVector(nt.Jet_pt_jesRelativeStatFSRUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeStatFSRUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeStatFSRdn", LorentzVector(nt.Jet_pt_jesRelativeStatFSRDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeStatFSRDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeStatECup", LorentzVector(nt.Jet_pt_jesRelativeStatECUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeStatECUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeStatECdn", LorentzVector(nt.Jet_pt_jesRelativeStatECDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeStatECDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeStatHFup", LorentzVector(nt.Jet_pt_jesRelativeStatHFUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeStatHFUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesRelativeStatHFdn", LorentzVector(nt.Jet_pt_jesRelativeStatHFDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesRelativeStatHFDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesPileUpDataMCup", LorentzVector(nt.Jet_pt_jesPileUpDataMCUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesPileUpDataMCUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesPileUpDataMCdn", LorentzVector(nt.Jet_pt_jesPileUpDataMCDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesPileUpDataMCDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesPileUpPtRefup", LorentzVector(nt.Jet_pt_jesPileUpPtRefUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesPileUpPtRefUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesPileUpPtRefdn", LorentzVector(nt.Jet_pt_jesPileUpPtRefDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesPileUpPtRefDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesPileUpPtBBup", LorentzVector(nt.Jet_pt_jesPileUpPtBBUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesPileUpPtBBUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesPileUpPtBBdn", LorentzVector(nt.Jet_pt_jesPileUpPtBBDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesPileUpPtBBDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesPileUpPtEC1up", LorentzVector(nt.Jet_pt_jesPileUpPtEC1Up()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesPileUpPtEC1Up()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesPileUpPtEC1dn", LorentzVector(nt.Jet_pt_jesPileUpPtEC1Down()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesPileUpPtEC1Down()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesPileUpPtEC2up", LorentzVector(nt.Jet_pt_jesPileUpPtEC2Up()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesPileUpPtEC2Up()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesPileUpPtEC2dn", LorentzVector(nt.Jet_pt_jesPileUpPtEC2Down()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesPileUpPtEC2Down()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesPileUpPtHFup", LorentzVector(nt.Jet_pt_jesPileUpPtHFUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesPileUpPtHFUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesPileUpPtHFdn", LorentzVector(nt.Jet_pt_jesPileUpPtHFDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesPileUpPtHFDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesup", LorentzVector(nt.Jet_pt_jesTotalUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesTotalUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jesdn", LorentzVector(nt.Jet_pt_jesTotalDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jesTotalDown()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jerup", LorentzVector(nt.Jet_pt_jerUp()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jerUp()[ijet]));
                ana.tx.pushbackToBranch<LorentzVector>("Common_jet_p4_jerdn", LorentzVector(nt.Jet_pt_jerDown()[ijet],nt.Jet_eta()[ijet],nt.Jet_phi()[ijet],nt.Jet_mass_jerDown()[ijet]));
            }
        }

        // b-tagged jet counter
        // For b-tagged jets, consider jets only 20 and above and is central within tracker acceptance

        if (jet_p4.pt() > 20. and abs(jet_p4.eta()) < 2.4)
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

            if (not nt.isData())
            {
                float pt = min(jet_p4.pt(), 599.99f);
                float eta = min(abs(jet_p4.eta()), 2.399f);
                float score = nt.Jet_btagDeepFlavB()[ijet];
                int flavor = nt.Jet_hadronFlavour()[ijet];
                bool is_loose_btagged = score > gconf.WP_DeepFlav_loose;
                bool is_medium_btagged = score > gconf.WP_DeepFlav_medium;
                bool is_tight_btagged = score > gconf.WP_DeepFlav_tight;

                float eff_tight = 1;
                float eff_medium = 1;
                float eff_loose = 1;

                eff_tight = flavor == 5 ? ana.btagEffTight_b->eval(pt, eta) : (flavor == 0 ? ana.btagEffTight_l->eval(pt, eta) : ana.btagEffTight_c->eval(pt, eta));
                eff_medium = flavor == 5 ? ana.btagEffMedium_b->eval(pt, eta) : (flavor == 0 ? ana.btagEffMedium_l->eval(pt, eta) : ana.btagEffMedium_c->eval(pt, eta));
                eff_loose = flavor == 5 ? ana.btagEffLoose_b->eval(pt, eta) : (flavor == 0 ? ana.btagEffLoose_l->eval(pt, eta) : ana.btagEffLoose_c->eval(pt, eta));

                float sf_tight;
                float sf_medium;
                float sf_loose;
                float sf_up_tight;
                float sf_up_medium;
                float sf_up_loose;
                float sf_dn_tight;
                float sf_dn_medium;
                float sf_dn_loose;
                float sf_HFup_tight;
                float sf_HFup_medium;
                float sf_HFup_loose;
                float sf_HFdn_tight;
                float sf_HFdn_medium;
                float sf_HFdn_loose;
                float sf_LFup_tight;
                float sf_LFup_medium;
                float sf_LFup_loose;
                float sf_LFdn_tight;
                float sf_LFdn_medium;
                float sf_LFdn_loose;

                if (nt.year() == 2016)
                {
                    sf_tight =
                        flavor == 5 ? ana.btagReaderTight_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_medium =
                        flavor == 5 ? ana.btagReaderMedium_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_loose =
                        flavor == 5 ? ana.btagReaderLoose_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_up_tight =
                        flavor == 5 ? ana.btagReaderTight_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_up_medium =
                        flavor == 5 ? ana.btagReaderMedium_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_up_loose =
                        flavor == 5 ? ana.btagReaderLoose_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_HFup_tight =
                        flavor == 5 ? ana.btagReaderTight_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_HFup_medium =
                        flavor == 5 ? ana.btagReaderMedium_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_HFup_loose =
                        flavor == 5 ? ana.btagReaderLoose_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_LFup_tight =
                        flavor == 5 ? ana.btagReaderTight_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_LFup_medium =
                        flavor == 5 ? ana.btagReaderMedium_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_LFup_loose =
                        flavor == 5 ? ana.btagReaderLoose_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose_v2->eval_auto_bounds("up", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_dn_tight =
                        flavor == 5 ? ana.btagReaderTight_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_dn_medium =
                        flavor == 5 ? ana.btagReaderMedium_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_dn_loose =
                        flavor == 5 ? ana.btagReaderLoose_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_HFdn_tight =
                        flavor == 5 ? ana.btagReaderTight_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_HFdn_medium =
                        flavor == 5 ? ana.btagReaderMedium_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_HFdn_loose =
                        flavor == 5 ? ana.btagReaderLoose_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_LFdn_tight =
                        flavor == 5 ? ana.btagReaderTight_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_LFdn_medium =
                        flavor == 5 ? ana.btagReaderMedium_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_C, eta, pt));
                    sf_LFdn_loose =
                        flavor == 5 ? ana.btagReaderLoose_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose_v2->eval_auto_bounds("down", BTagEntry_v2::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose_v2->eval_auto_bounds("central", BTagEntry_v2::FLAV_C, eta, pt));
                }
                else
                {
                    sf_tight =
                        flavor == 5 ? ana.btagReaderTight->eval_auto_bounds("central", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight->eval_auto_bounds("central", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight->eval_auto_bounds("central", BTagEntry::FLAV_C, eta, pt));
                    sf_medium =
                        flavor == 5 ? ana.btagReaderMedium->eval_auto_bounds("central", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium->eval_auto_bounds("central", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium->eval_auto_bounds("central", BTagEntry::FLAV_C, eta, pt));
                    sf_loose =
                        flavor == 5 ? ana.btagReaderLoose->eval_auto_bounds("central", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose->eval_auto_bounds("central", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose->eval_auto_bounds("central", BTagEntry::FLAV_C, eta, pt));
                    sf_up_tight =
                        flavor == 5 ? ana.btagReaderTight->eval_auto_bounds("up", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight->eval_auto_bounds("up", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight->eval_auto_bounds("up", BTagEntry::FLAV_C, eta, pt));
                    sf_up_medium =
                        flavor == 5 ? ana.btagReaderMedium->eval_auto_bounds("up", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium->eval_auto_bounds("up", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium->eval_auto_bounds("up", BTagEntry::FLAV_C, eta, pt));
                    sf_up_loose =
                        flavor == 5 ? ana.btagReaderLoose->eval_auto_bounds("up", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose->eval_auto_bounds("up", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose->eval_auto_bounds("up", BTagEntry::FLAV_C, eta, pt));
                    sf_HFup_tight =
                        flavor == 5 ? ana.btagReaderTight->eval_auto_bounds("up", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight->eval_auto_bounds("central", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight->eval_auto_bounds("up", BTagEntry::FLAV_C, eta, pt));
                    sf_HFup_medium =
                        flavor == 5 ? ana.btagReaderMedium->eval_auto_bounds("up", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium->eval_auto_bounds("central", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium->eval_auto_bounds("up", BTagEntry::FLAV_C, eta, pt));
                    sf_HFup_loose =
                        flavor == 5 ? ana.btagReaderLoose->eval_auto_bounds("up", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose->eval_auto_bounds("central", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose->eval_auto_bounds("up", BTagEntry::FLAV_C, eta, pt));
                    sf_LFup_tight =
                        flavor == 5 ? ana.btagReaderTight->eval_auto_bounds("central", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight->eval_auto_bounds("up", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight->eval_auto_bounds("central", BTagEntry::FLAV_C, eta, pt));
                    sf_LFup_medium =
                        flavor == 5 ? ana.btagReaderMedium->eval_auto_bounds("central", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium->eval_auto_bounds("up", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium->eval_auto_bounds("central", BTagEntry::FLAV_C, eta, pt));
                    sf_LFup_loose =
                        flavor == 5 ? ana.btagReaderLoose->eval_auto_bounds("central", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose->eval_auto_bounds("up", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose->eval_auto_bounds("central", BTagEntry::FLAV_C, eta, pt));
                    sf_dn_tight =
                        flavor == 5 ? ana.btagReaderTight->eval_auto_bounds("down", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight->eval_auto_bounds("down", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight->eval_auto_bounds("down", BTagEntry::FLAV_C, eta, pt));
                    sf_dn_medium =
                        flavor == 5 ? ana.btagReaderMedium->eval_auto_bounds("down", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium->eval_auto_bounds("down", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium->eval_auto_bounds("down", BTagEntry::FLAV_C, eta, pt));
                    sf_dn_loose =
                        flavor == 5 ? ana.btagReaderLoose->eval_auto_bounds("down", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose->eval_auto_bounds("down", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose->eval_auto_bounds("down", BTagEntry::FLAV_C, eta, pt));
                    sf_HFdn_tight =
                        flavor == 5 ? ana.btagReaderTight->eval_auto_bounds("down", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight->eval_auto_bounds("central", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight->eval_auto_bounds("down", BTagEntry::FLAV_C, eta, pt));
                    sf_HFdn_medium =
                        flavor == 5 ? ana.btagReaderMedium->eval_auto_bounds("down", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium->eval_auto_bounds("central", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium->eval_auto_bounds("down", BTagEntry::FLAV_C, eta, pt));
                    sf_HFdn_loose =
                        flavor == 5 ? ana.btagReaderLoose->eval_auto_bounds("down", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose->eval_auto_bounds("central", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose->eval_auto_bounds("down", BTagEntry::FLAV_C, eta, pt));
                    sf_LFdn_tight =
                        flavor == 5 ? ana.btagReaderTight->eval_auto_bounds("central", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderTight->eval_auto_bounds("down", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderTight->eval_auto_bounds("central", BTagEntry::FLAV_C, eta, pt));
                    sf_LFdn_medium =
                        flavor == 5 ? ana.btagReaderMedium->eval_auto_bounds("central", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderMedium->eval_auto_bounds("down", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderMedium->eval_auto_bounds("central", BTagEntry::FLAV_C, eta, pt));
                    sf_LFdn_loose =
                        flavor == 5 ? ana.btagReaderLoose->eval_auto_bounds("central", BTagEntry::FLAV_B, eta, pt) : (
                            flavor == 0 ? ana.btagReaderLoose->eval_auto_bounds("down", BTagEntry::FLAV_UDSG, eta, pt) :
                            ana.btagReaderLoose->eval_auto_bounds("central", BTagEntry::FLAV_C, eta, pt));
                }

                if (is_tight_btagged)
                {
                    btagTight_prob_MC *= eff_tight;
                    btagTight_prob_DATA *= sf_tight * eff_tight;
                    btagTight_up_prob_DATA *= sf_up_tight * eff_tight;
                    btagTight_dn_prob_DATA *= sf_dn_tight * eff_tight;
                    btagTight_HFup_prob_DATA *= sf_HFup_tight * eff_tight;
                    btagTight_HFdn_prob_DATA *= sf_HFdn_tight * eff_tight;
                    btagTight_LFup_prob_DATA *= sf_LFup_tight * eff_tight;
                    btagTight_LFdn_prob_DATA *= sf_LFdn_tight * eff_tight;
                }
                else
                {
                    btagTight_prob_MC *= (1 - eff_tight);
                    btagTight_prob_DATA *= (1 - sf_tight * eff_tight);
                    btagTight_up_prob_DATA *= (1 - sf_up_tight * eff_tight);
                    btagTight_dn_prob_DATA *= (1 - sf_dn_tight * eff_tight);
                    btagTight_HFup_prob_DATA *= (1 - sf_HFup_tight * eff_tight);
                    btagTight_HFdn_prob_DATA *= (1 - sf_HFdn_tight * eff_tight);
                    btagTight_LFup_prob_DATA *= (1 - sf_LFup_tight * eff_tight);
                    btagTight_LFdn_prob_DATA *= (1 - sf_LFdn_tight * eff_tight);
                }

                if (is_medium_btagged)
                {
                    btagMedium_prob_MC *= eff_medium;
                    btagMedium_prob_DATA *= sf_medium * eff_medium;
                    btagMedium_up_prob_DATA *= sf_up_medium * eff_medium;
                    btagMedium_dn_prob_DATA *= sf_dn_medium * eff_medium;
                    btagMedium_HFup_prob_DATA *= sf_HFup_medium * eff_medium;
                    btagMedium_HFdn_prob_DATA *= sf_HFdn_medium * eff_medium;
                    btagMedium_LFup_prob_DATA *= sf_LFup_medium * eff_medium;
                    btagMedium_LFdn_prob_DATA *= sf_LFdn_medium * eff_medium;
                }
                else
                {
                    btagMedium_prob_MC *= (1 - eff_medium);
                    btagMedium_prob_DATA *= (1 - sf_medium * eff_medium);
                    btagMedium_up_prob_DATA *= (1 - sf_up_medium * eff_medium);
                    btagMedium_dn_prob_DATA *= (1 - sf_dn_medium * eff_medium);
                    btagMedium_HFup_prob_DATA *= (1 - sf_HFup_medium * eff_medium);
                    btagMedium_HFdn_prob_DATA *= (1 - sf_HFdn_medium * eff_medium);
                    btagMedium_LFup_prob_DATA *= (1 - sf_LFup_medium * eff_medium);
                    btagMedium_LFdn_prob_DATA *= (1 - sf_LFdn_medium * eff_medium);
                }

                if (is_loose_btagged)
                {
                    btagLoose_prob_MC *= eff_loose;
                    btagLoose_prob_DATA *= sf_loose * eff_loose;
                    btagLoose_up_prob_DATA *= sf_up_loose * eff_loose;
                    btagLoose_dn_prob_DATA *= sf_dn_loose * eff_loose;
                    btagLoose_HFup_prob_DATA *= sf_HFup_loose * eff_loose;
                    btagLoose_HFdn_prob_DATA *= sf_HFdn_loose * eff_loose;
                    btagLoose_LFup_prob_DATA *= sf_LFup_loose * eff_loose;
                    btagLoose_LFdn_prob_DATA *= sf_LFdn_loose * eff_loose;
                }
                else
                {
                    btagLoose_prob_MC *= (1 - eff_loose);
                    btagLoose_prob_DATA *= (1 - sf_loose * eff_loose);
                    btagLoose_up_prob_DATA *= (1 - sf_up_loose * eff_loose);
                    btagLoose_dn_prob_DATA *= (1 - sf_dn_loose * eff_loose);
                    btagLoose_HFup_prob_DATA *= (1 - sf_HFup_loose * eff_loose);
                    btagLoose_HFdn_prob_DATA *= (1 - sf_HFdn_loose * eff_loose);
                    btagLoose_LFup_prob_DATA *= (1 - sf_LFup_loose * eff_loose);
                    btagLoose_LFdn_prob_DATA *= (1 - sf_LFdn_loose * eff_loose);
                }
            }
        }
        if(ana.systematicVariation and ana.is_postprocessed and !nt.isData()){
            if (nt.Jet_pt_jesAbsoluteStatUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesAbsoluteStatup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesAbsoluteStatup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesAbsoluteStatup++;
                }
            }
            if (nt.Jet_pt_jesAbsoluteStatDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesAbsoluteStatdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesAbsoluteStatdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesAbsoluteStatdn++;
                }
            }
            if (nt.Jet_pt_jesAbsoluteScaleUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesAbsoluteScaleup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesAbsoluteScaleup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesAbsoluteScaleup++;
                }
            }
            if (nt.Jet_pt_jesAbsoluteScaleDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesAbsoluteScaledn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesAbsoluteScaledn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesAbsoluteScaledn++;
                }
            }
            if (nt.Jet_pt_jesAbsoluteMPFBiasUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesAbsoluteMPFBiasup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesAbsoluteMPFBiasup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesAbsoluteMPFBiasup++;
                }
            }
            if (nt.Jet_pt_jesAbsoluteMPFBiasDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesAbsoluteMPFBiasdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesAbsoluteMPFBiasdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesAbsoluteMPFBiasdn++;
                }
            }
            if (nt.Jet_pt_jesFragmentationUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesFragmentationup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesFragmentationup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesFragmentationup++;
                }
            }
            if (nt.Jet_pt_jesFragmentationDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesFragmentationdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesFragmentationdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesFragmentationdn++;
                }
            }
            if (nt.Jet_pt_jesSinglePionECALUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesSinglePionECALup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesSinglePionECALup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesSinglePionECALup++;
                }
            }
            if (nt.Jet_pt_jesSinglePionECALDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesSinglePionECALdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesSinglePionECALdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesSinglePionECALdn++;
                }
            }
            if (nt.Jet_pt_jesSinglePionHCALUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesSinglePionHCALup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesSinglePionHCALup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesSinglePionHCALup++;
                }
            }
            if (nt.Jet_pt_jesSinglePionHCALDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesSinglePionHCALdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesSinglePionHCALdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesSinglePionHCALdn++;
                }
            }
            if (nt.Jet_pt_jesFlavorQCDUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesFlavorQCDup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesFlavorQCDup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesFlavorQCDup++;
                }
            }
            if (nt.Jet_pt_jesFlavorQCDDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesFlavorQCDdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesFlavorQCDdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesFlavorQCDdn++;
                }
            }
            if (nt.Jet_pt_jesTimePtEtaUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesTimePtEtaup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesTimePtEtaup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesTimePtEtaup++;
                }
            }
            if (nt.Jet_pt_jesTimePtEtaDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesTimePtEtadn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesTimePtEtadn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesTimePtEtadn++;
                }
            }
            if (nt.Jet_pt_jesRelativeJEREC1Up()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeJEREC1up++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeJEREC1up++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeJEREC1up++;
                }
            }
            if (nt.Jet_pt_jesRelativeJEREC1Down()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeJEREC1dn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeJEREC1dn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeJEREC1dn++;
                }
            }
            if (nt.Jet_pt_jesRelativeJEREC2Up()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeJEREC2up++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeJEREC2up++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeJEREC2up++;
                }
            }
            if (nt.Jet_pt_jesRelativeJEREC2Down()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeJEREC2dn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeJEREC2dn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeJEREC2dn++;
                }
            }
            if (nt.Jet_pt_jesRelativeJERHFUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeJERHFup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeJERHFup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeJERHFup++;
                }
            }
            if (nt.Jet_pt_jesRelativeJERHFDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeJERHFdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeJERHFdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeJERHFdn++;
                }
            }
            if (nt.Jet_pt_jesRelativePtBBUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativePtBBup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativePtBBup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativePtBBup++;
                }
            }
            if (nt.Jet_pt_jesRelativePtBBDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativePtBBdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativePtBBdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativePtBBdn++;
                }
            }
            if (nt.Jet_pt_jesRelativePtEC1Up()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativePtEC1up++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativePtEC1up++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativePtEC1up++;
                }
            }
            if (nt.Jet_pt_jesRelativePtEC1Down()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativePtEC1dn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativePtEC1dn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativePtEC1dn++;
                }
            }
            if (nt.Jet_pt_jesRelativePtEC2Up()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativePtEC2up++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativePtEC2up++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativePtEC2up++;
                }
            }
            if (nt.Jet_pt_jesRelativePtEC2Down()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativePtEC2dn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativePtEC2dn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativePtEC2dn++;
                }
            }
            if (nt.Jet_pt_jesRelativePtHFUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativePtHFup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativePtHFup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativePtHFup++;
                }
            }
            if (nt.Jet_pt_jesRelativePtHFDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativePtHFdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativePtHFdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativePtHFdn++;
                }
            }
            if (nt.Jet_pt_jesRelativeBalUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeBalup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeBalup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeBalup++;
                }
            }
            if (nt.Jet_pt_jesRelativeBalDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeBaldn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeBaldn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeBaldn++;
                }
            }
            if (nt.Jet_pt_jesRelativeSampleUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeSampleup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeSampleup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeSampleup++;
                }
            }
            if (nt.Jet_pt_jesRelativeSampleDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeSampledn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeSampledn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeSampledn++;
                }
            }
            if (nt.Jet_pt_jesRelativeFSRUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeFSRup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeFSRup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeFSRup++;
                }
            }
            if (nt.Jet_pt_jesRelativeFSRDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeFSRdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeFSRdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeFSRdn++;
                }
            }
            if (nt.Jet_pt_jesRelativeStatFSRUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeStatFSRup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeStatFSRup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeStatFSRup++;
                }
            }
            if (nt.Jet_pt_jesRelativeStatFSRDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeStatFSRdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeStatFSRdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeStatFSRdn++;
                }
            }
            if (nt.Jet_pt_jesRelativeStatECUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeStatECup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeStatECup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeStatECup++;
                }
            }
            if (nt.Jet_pt_jesRelativeStatECDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeStatECdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeStatECdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeStatECdn++;
                }
            }
            if (nt.Jet_pt_jesRelativeStatHFUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeStatHFup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeStatHFup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeStatHFup++;
                }
            }
            if (nt.Jet_pt_jesRelativeStatHFDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesRelativeStatHFdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesRelativeStatHFdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesRelativeStatHFdn++;
                }
            }
            if (nt.Jet_pt_jesPileUpDataMCUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesPileUpDataMCup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesPileUpDataMCup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesPileUpDataMCup++;
                }
            }
            if (nt.Jet_pt_jesPileUpDataMCDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesPileUpDataMCdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesPileUpDataMCdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesPileUpDataMCdn++;
                }
            }
            if (nt.Jet_pt_jesPileUpPtRefUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesPileUpPtRefup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesPileUpPtRefup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesPileUpPtRefup++;
                }
            }
            if (nt.Jet_pt_jesPileUpPtRefDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesPileUpPtRefdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesPileUpPtRefdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesPileUpPtRefdn++;
                }
            }
            if (nt.Jet_pt_jesPileUpPtBBUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesPileUpPtBBup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesPileUpPtBBup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesPileUpPtBBup++;
                }
            }
            if (nt.Jet_pt_jesPileUpPtBBDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesPileUpPtBBdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesPileUpPtBBdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesPileUpPtBBdn++;
                }
            }
            if (nt.Jet_pt_jesPileUpPtEC1Up()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesPileUpPtEC1up++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesPileUpPtEC1up++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesPileUpPtEC1up++;
                }
            }
            if (nt.Jet_pt_jesPileUpPtEC1Down()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesPileUpPtEC1dn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesPileUpPtEC1dn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesPileUpPtEC1dn++;
                }
            }
            if (nt.Jet_pt_jesPileUpPtEC2Up()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesPileUpPtEC2up++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesPileUpPtEC2up++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesPileUpPtEC2up++;
                }
            }
            if (nt.Jet_pt_jesPileUpPtEC2Down()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesPileUpPtEC2dn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesPileUpPtEC2dn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesPileUpPtEC2dn++;
                }
            }
            if (nt.Jet_pt_jesPileUpPtHFUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesPileUpPtHFup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesPileUpPtHFup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesPileUpPtHFup++;
                }
            }
            if (nt.Jet_pt_jesPileUpPtHFDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesPileUpPtHFdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesPileUpPtHFdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesPileUpPtHFdn++;
                }
            }
            if (nt.Jet_pt_jesTotalUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesup++;
                }
            }
            if (nt.Jet_pt_jesTotalDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jesdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jesdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jesdn++;
                }
            }
            if (nt.Jet_pt_jerUp()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jerup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jerup++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jerup++;
                }
            }
            if (nt.Jet_pt_jerDown()[ijet] > 20. and abs(nt.Jet_eta()[ijet]) < 2.4)
            {

                if (nt.Jet_btagDeepFlavB()[ijet] > bWPloose)
                {
                    nb_loose_jerdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPmedium)
                {
                    nb_medium_jerdn++;
                }
                if (nt.Jet_btagDeepFlavB()[ijet] > bWPtight)
                {
                    nb_tight_jerdn++;
                }
            }
        }
    }


    ana.tx.setBranch<float>("Common_event_tightBtagSF"      , btagTight_prob_DATA       / btagTight_prob_MC);
    ana.tx.setBranch<float>("Common_event_tightBtagSFup"    , btagTight_up_prob_DATA    / btagTight_prob_MC);
    ana.tx.setBranch<float>("Common_event_tightBtagSFdn"    , btagTight_dn_prob_DATA    / btagTight_prob_MC);
    ana.tx.setBranch<float>("Common_event_tightBtagSFHFup"  , btagTight_HFup_prob_DATA  / btagTight_prob_MC);
    ana.tx.setBranch<float>("Common_event_tightBtagSFHFdn"  , btagTight_HFdn_prob_DATA  / btagTight_prob_MC);
    ana.tx.setBranch<float>("Common_event_tightBtagSFLFup"  , btagTight_LFup_prob_DATA  / btagTight_prob_MC);
    ana.tx.setBranch<float>("Common_event_tightBtagSFLFdn"  , btagTight_LFdn_prob_DATA  / btagTight_prob_MC);
    ana.tx.setBranch<float>("Common_event_mediumBtagSF"     , btagMedium_prob_DATA      / btagMedium_prob_MC);
    ana.tx.setBranch<float>("Common_event_mediumBtagSFup"   , btagMedium_up_prob_DATA   / btagMedium_prob_MC);
    ana.tx.setBranch<float>("Common_event_mediumBtagSFdn"   , btagMedium_dn_prob_DATA   / btagMedium_prob_MC);
    ana.tx.setBranch<float>("Common_event_mediumBtagSFHFup" , btagMedium_HFup_prob_DATA / btagMedium_prob_MC);
    ana.tx.setBranch<float>("Common_event_mediumBtagSFHFdn" , btagMedium_HFdn_prob_DATA / btagMedium_prob_MC);
    ana.tx.setBranch<float>("Common_event_mediumBtagSFLFup" , btagMedium_LFup_prob_DATA / btagMedium_prob_MC);
    ana.tx.setBranch<float>("Common_event_mediumBtagSFLFdn" , btagMedium_LFdn_prob_DATA / btagMedium_prob_MC);
    ana.tx.setBranch<float>("Common_event_looseBtagSF"      , btagLoose_prob_DATA       / btagLoose_prob_MC);
    ana.tx.setBranch<float>("Common_event_looseBtagSFup"    , btagLoose_up_prob_DATA    / btagLoose_prob_MC);
    ana.tx.setBranch<float>("Common_event_looseBtagSFdn"    , btagLoose_dn_prob_DATA    / btagLoose_prob_MC);
    ana.tx.setBranch<float>("Common_event_looseBtagSFHFup"  , btagLoose_HFup_prob_DATA  / btagLoose_prob_MC);
    ana.tx.setBranch<float>("Common_event_looseBtagSFHFdn"  , btagLoose_HFdn_prob_DATA  / btagLoose_prob_MC);
    ana.tx.setBranch<float>("Common_event_looseBtagSFLFup"  , btagLoose_LFup_prob_DATA  / btagLoose_prob_MC);
    ana.tx.setBranch<float>("Common_event_looseBtagSFLFdn"  , btagLoose_LFdn_prob_DATA  / btagLoose_prob_MC);

    ana.tx.setBranch<int>("Common_nb_loose", nb_loose);
    ana.tx.setBranch<int>("Common_nb_medium", nb_medium);
    ana.tx.setBranch<int>("Common_nb_tight", nb_tight);
    if(ana.systematicVariation and ana.is_postprocessed and !nt.isData()){
        ana.tx.setBranch<int>("Common_nb_loose_jesAbsoluteStatup", nb_loose_jesAbsoluteStatup);
        ana.tx.setBranch<int>("Common_nb_loose_jesAbsoluteStatdn", nb_loose_jesAbsoluteStatdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesAbsoluteScaleup", nb_loose_jesAbsoluteScaleup);            
        ana.tx.setBranch<int>("Common_nb_loose_jesAbsoluteScaledn", nb_loose_jesAbsoluteScaledn);
        ana.tx.setBranch<int>("Common_nb_loose_jesAbsoluteMPFBiasup", nb_loose_jesAbsoluteMPFBiasup);
        ana.tx.setBranch<int>("Common_nb_loose_jesAbsoluteMPFBiasdn", nb_loose_jesAbsoluteMPFBiasdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesFragmentationup", nb_loose_jesFragmentationup);
        ana.tx.setBranch<int>("Common_nb_loose_jesFragmentationdn", nb_loose_jesFragmentationdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesSinglePionECALup", nb_loose_jesSinglePionECALup);
        ana.tx.setBranch<int>("Common_nb_loose_jesSinglePionECALdn", nb_loose_jesSinglePionECALdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesSinglePionHCALup", nb_loose_jesSinglePionHCALup);
        ana.tx.setBranch<int>("Common_nb_loose_jesSinglePionHCALdn", nb_loose_jesSinglePionHCALdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesFlavorQCDup", nb_loose_jesFlavorQCDup);
        ana.tx.setBranch<int>("Common_nb_loose_jesFlavorQCDdn", nb_loose_jesFlavorQCDdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesTimePtEtaup", nb_loose_jesTimePtEtaup);
        ana.tx.setBranch<int>("Common_nb_loose_jesTimePtEtadn", nb_loose_jesTimePtEtadn);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeJEREC1up", nb_loose_jesRelativeJEREC1up);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeJEREC1dn", nb_loose_jesRelativeJEREC1dn);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeJEREC2up", nb_loose_jesRelativeJEREC2up);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeJEREC2dn", nb_loose_jesRelativeJEREC2dn);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeJERHFup", nb_loose_jesRelativeJERHFup);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeJERHFdn", nb_loose_jesRelativeJERHFdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtBBup", nb_loose_jesRelativePtBBup);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtBBdn", nb_loose_jesRelativePtBBdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtEC1up", nb_loose_jesRelativePtEC1up);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtEC1dn", nb_loose_jesRelativePtEC1dn);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtEC2up", nb_loose_jesRelativePtEC2up);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtEC2dn", nb_loose_jesRelativePtEC2dn);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtHFup", nb_loose_jesRelativePtHFup);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtHFdn", nb_loose_jesRelativePtHFdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeBalup", nb_loose_jesRelativeBalup);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeBaldn", nb_loose_jesRelativeBaldn);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeSampleup", nb_loose_jesRelativeSampleup);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeSampledn", nb_loose_jesRelativeSampledn);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeFSRup", nb_loose_jesRelativeFSRup);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeFSRdn", nb_loose_jesRelativeFSRdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeStatFSRup", nb_loose_jesRelativeStatFSRup);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeStatFSRdn", nb_loose_jesRelativeStatFSRdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeStatECup", nb_loose_jesRelativeStatECup);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeStatECdn", nb_loose_jesRelativeStatECdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeStatHFup", nb_loose_jesRelativeStatHFup);
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeStatHFdn", nb_loose_jesRelativeStatHFdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpDataMCup", nb_loose_jesPileUpDataMCup);
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpDataMCdn", nb_loose_jesPileUpDataMCdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtRefup", nb_loose_jesPileUpPtRefup);
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtRefdn", nb_loose_jesPileUpPtRefdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtBBup", nb_loose_jesPileUpPtBBup);
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtBBdn", nb_loose_jesPileUpPtBBdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtEC1up", nb_loose_jesPileUpPtEC1up);
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtEC1dn", nb_loose_jesPileUpPtEC1dn);
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtEC2up", nb_loose_jesPileUpPtEC2up);
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtEC2dn", nb_loose_jesPileUpPtEC2dn);
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtHFup", nb_loose_jesPileUpPtHFup);
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtHFdn", nb_loose_jesPileUpPtHFdn);
        ana.tx.setBranch<int>("Common_nb_loose_jesup", nb_loose_jesup);
        ana.tx.setBranch<int>("Common_nb_loose_jesdn", nb_loose_jesdn);
        ana.tx.setBranch<int>("Common_nb_loose_jerup", nb_loose_jerup);
        ana.tx.setBranch<int>("Common_nb_loose_jerdn", nb_loose_jerdn);

        ana.tx.setBranch<int>("Common_nb_medium_jesAbsoluteStatup", nb_medium_jesAbsoluteStatup);
        ana.tx.setBranch<int>("Common_nb_medium_jesAbsoluteStatdn", nb_medium_jesAbsoluteStatdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesAbsoluteScaleup", nb_medium_jesAbsoluteScaleup);            
        ana.tx.setBranch<int>("Common_nb_medium_jesAbsoluteScaledn", nb_medium_jesAbsoluteScaledn);
        ana.tx.setBranch<int>("Common_nb_medium_jesAbsoluteMPFBiasup", nb_medium_jesAbsoluteMPFBiasup);
        ana.tx.setBranch<int>("Common_nb_medium_jesAbsoluteMPFBiasdn", nb_medium_jesAbsoluteMPFBiasdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesFragmentationup", nb_medium_jesFragmentationup);
        ana.tx.setBranch<int>("Common_nb_medium_jesFragmentationdn", nb_medium_jesFragmentationdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesSinglePionECALup", nb_medium_jesSinglePionECALup);
        ana.tx.setBranch<int>("Common_nb_medium_jesSinglePionECALdn", nb_medium_jesSinglePionECALdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesSinglePionHCALup", nb_medium_jesSinglePionHCALup);
        ana.tx.setBranch<int>("Common_nb_medium_jesSinglePionHCALdn", nb_medium_jesSinglePionHCALdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesFlavorQCDup", nb_medium_jesFlavorQCDup);
        ana.tx.setBranch<int>("Common_nb_medium_jesFlavorQCDdn", nb_medium_jesFlavorQCDdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesTimePtEtaup", nb_medium_jesTimePtEtaup);
        ana.tx.setBranch<int>("Common_nb_medium_jesTimePtEtadn", nb_medium_jesTimePtEtadn);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeJEREC1up", nb_medium_jesRelativeJEREC1up);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeJEREC1dn", nb_medium_jesRelativeJEREC1dn);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeJEREC2up", nb_medium_jesRelativeJEREC2up);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeJEREC2dn", nb_medium_jesRelativeJEREC2dn);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeJERHFup", nb_medium_jesRelativeJERHFup);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeJERHFdn", nb_medium_jesRelativeJERHFdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtBBup", nb_medium_jesRelativePtBBup);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtBBdn", nb_medium_jesRelativePtBBdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtEC1up", nb_medium_jesRelativePtEC1up);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtEC1dn", nb_medium_jesRelativePtEC1dn);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtEC2up", nb_medium_jesRelativePtEC2up);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtEC2dn", nb_medium_jesRelativePtEC2dn);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtHFup", nb_medium_jesRelativePtHFup);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtHFdn", nb_medium_jesRelativePtHFdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeBalup", nb_medium_jesRelativeBalup);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeBaldn", nb_medium_jesRelativeBaldn);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeSampleup", nb_medium_jesRelativeSampleup);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeSampledn", nb_medium_jesRelativeSampledn);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeFSRup", nb_medium_jesRelativeFSRup);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeFSRdn", nb_medium_jesRelativeFSRdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeStatFSRup", nb_medium_jesRelativeStatFSRup);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeStatFSRdn", nb_medium_jesRelativeStatFSRdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeStatECup", nb_medium_jesRelativeStatECup);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeStatECdn", nb_medium_jesRelativeStatECdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeStatHFup", nb_medium_jesRelativeStatHFup);
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeStatHFdn", nb_medium_jesRelativeStatHFdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpDataMCup", nb_medium_jesPileUpDataMCup);
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpDataMCdn", nb_medium_jesPileUpDataMCdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtRefup", nb_medium_jesPileUpPtRefup);
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtRefdn", nb_medium_jesPileUpPtRefdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtBBup", nb_medium_jesPileUpPtBBup);
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtBBdn", nb_medium_jesPileUpPtBBdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtEC1up", nb_medium_jesPileUpPtEC1up);
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtEC1dn", nb_medium_jesPileUpPtEC1dn);
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtEC2up", nb_medium_jesPileUpPtEC2up);
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtEC2dn", nb_medium_jesPileUpPtEC2dn);
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtHFup", nb_medium_jesPileUpPtHFup);
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtHFdn", nb_medium_jesPileUpPtHFdn);
        ana.tx.setBranch<int>("Common_nb_medium_jesup", nb_medium_jesup);
        ana.tx.setBranch<int>("Common_nb_medium_jesdn", nb_medium_jesdn);        
        ana.tx.setBranch<int>("Common_nb_medium_jerup", nb_medium_jerup);
        ana.tx.setBranch<int>("Common_nb_medium_jerdn", nb_medium_jerdn);

        ana.tx.setBranch<int>("Common_nb_tight_jesAbsoluteStatup", nb_tight_jesAbsoluteStatup);
        ana.tx.setBranch<int>("Common_nb_tight_jesAbsoluteStatdn", nb_tight_jesAbsoluteStatdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesAbsoluteScaleup", nb_tight_jesAbsoluteScaleup);            
        ana.tx.setBranch<int>("Common_nb_tight_jesAbsoluteScaledn", nb_tight_jesAbsoluteScaledn);
        ana.tx.setBranch<int>("Common_nb_tight_jesAbsoluteMPFBiasup", nb_tight_jesAbsoluteMPFBiasup);
        ana.tx.setBranch<int>("Common_nb_tight_jesAbsoluteMPFBiasdn", nb_tight_jesAbsoluteMPFBiasdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesFragmentationup", nb_tight_jesFragmentationup);
        ana.tx.setBranch<int>("Common_nb_tight_jesFragmentationdn", nb_tight_jesFragmentationdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesSinglePionECALup", nb_tight_jesSinglePionECALup);
        ana.tx.setBranch<int>("Common_nb_tight_jesSinglePionECALdn", nb_tight_jesSinglePionECALdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesSinglePionHCALup", nb_tight_jesSinglePionHCALup);
        ana.tx.setBranch<int>("Common_nb_tight_jesSinglePionHCALdn", nb_tight_jesSinglePionHCALdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesFlavorQCDup", nb_tight_jesFlavorQCDup);
        ana.tx.setBranch<int>("Common_nb_tight_jesFlavorQCDdn", nb_tight_jesFlavorQCDdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesTimePtEtaup", nb_tight_jesTimePtEtaup);
        ana.tx.setBranch<int>("Common_nb_tight_jesTimePtEtadn", nb_tight_jesTimePtEtadn);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeJEREC1up", nb_tight_jesRelativeJEREC1up);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeJEREC1dn", nb_tight_jesRelativeJEREC1dn);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeJEREC2up", nb_tight_jesRelativeJEREC2up);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeJEREC2dn", nb_tight_jesRelativeJEREC2dn);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeJERHFup", nb_tight_jesRelativeJERHFup);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeJERHFdn", nb_tight_jesRelativeJERHFdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtBBup", nb_tight_jesRelativePtBBup);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtBBdn", nb_tight_jesRelativePtBBdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtEC1up", nb_tight_jesRelativePtEC1up);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtEC1dn", nb_tight_jesRelativePtEC1dn);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtEC2up", nb_tight_jesRelativePtEC2up);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtEC2dn", nb_tight_jesRelativePtEC2dn);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtHFup", nb_tight_jesRelativePtHFup);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtHFdn", nb_tight_jesRelativePtHFdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeBalup", nb_tight_jesRelativeBalup);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeBaldn", nb_tight_jesRelativeBaldn);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeSampleup", nb_tight_jesRelativeSampleup);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeSampledn", nb_tight_jesRelativeSampledn);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeFSRup", nb_tight_jesRelativeFSRup);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeFSRdn", nb_tight_jesRelativeFSRdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeStatFSRup", nb_tight_jesRelativeStatFSRup);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeStatFSRdn", nb_tight_jesRelativeStatFSRdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeStatECup", nb_tight_jesRelativeStatECup);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeStatECdn", nb_tight_jesRelativeStatECdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeStatHFup", nb_tight_jesRelativeStatHFup);
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeStatHFdn", nb_tight_jesRelativeStatHFdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpDataMCup", nb_tight_jesPileUpDataMCup);
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpDataMCdn", nb_tight_jesPileUpDataMCdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtRefup", nb_tight_jesPileUpPtRefup);
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtRefdn", nb_tight_jesPileUpPtRefdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtBBup", nb_tight_jesPileUpPtBBup);
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtBBdn", nb_tight_jesPileUpPtBBdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtEC1up", nb_tight_jesPileUpPtEC1up);
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtEC1dn", nb_tight_jesPileUpPtEC1dn);
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtEC2up", nb_tight_jesPileUpPtEC2up);
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtEC2dn", nb_tight_jesPileUpPtEC2dn);
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtHFup", nb_tight_jesPileUpPtHFup);
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtHFdn", nb_tight_jesPileUpPtHFdn);
        ana.tx.setBranch<int>("Common_nb_tight_jesup", nb_tight_jesup);
        ana.tx.setBranch<int>("Common_nb_tight_jesdn", nb_tight_jesdn);
        ana.tx.setBranch<int>("Common_nb_tight_jerup", nb_tight_jerup);
        ana.tx.setBranch<int>("Common_nb_tight_jerdn", nb_tight_jerdn);
    }

    //---------------------------------------------------------------------------------------------
    // Fat Jet selection
    //---------------------------------------------------------------------------------------------
    // Loop over jets and do a simple overlap removal against leptons
    float fjSFvlc(1.), fjSFvlu(1.), fjSFvld(1.), fjSFmc(1.), fjSFmu(1.), fjSFmd(1.), fjSFtc(1.), fjSFtu(1.), fjSFtd(1.);
    float fjMDSFlc(1.), fjMDSFlu(1.), fjMDSFld(1.), fjMDSFmc(1.), fjMDSFmu(1.), fjMDSFmd(1.), fjMDSFtc(1.), fjMDSFtu(1.), fjMDSFtd(1.);
    //update with final WPs and for other years
    //currently from https://indico.cern.ch/event/1103765/contributions/4647556/attachments/2364610/4037250/ParticleNet_2018_ULNanoV9_JMAR_14Dec2021_PK.pdf
    //Lesya updated March 22 2022
    //From https://indico.cern.ch/event/1152827/contributions/4840404/attachments/2428856/4162159/ParticleNet_SFs_ULNanoV9_JMAR_25April2022_PK.pdf
    //Yulun updated August 5 2022
    float fjWPVloose  = 0.68;
    float fjWPmedium = 0.94;
    float fjWPtight  = 0.97;        
    float fjWPloose_MD  = 0.64;
    float fjWPmedium_MD = 0.85;
    float fjWPtight_MD  = 0.91;
    if (nt.year() == 2016 && !gconf.isAPV)
    {
        fjWPVloose  = 0.67;
        fjWPmedium = 0.93;
        fjWPtight  = 0.97;
        fjWPloose_MD  = 0.64;
        fjWPmedium_MD = 0.84;
        fjWPtight_MD  = 0.91;
    }
    if (nt.year() == 2017)
    {
        fjWPVloose  = 0.71;
        fjWPmedium = 0.94;
        fjWPtight  = 0.98;
        fjWPloose_MD  = 0.58;
        fjWPmedium_MD = 0.81;
        fjWPtight_MD  = 0.89;
    }
    if (nt.year() == 2018)
    {
        fjWPVloose  = 0.70;
        fjWPmedium = 0.94;
        fjWPtight  = 0.98;
        fjWPloose_MD  = 0.59;
        fjWPmedium_MD = 0.82;
        fjWPtight_MD  = 0.90;
    }
    for (unsigned int ifatjet = 0; ifatjet < nt.FatJet_p4().size(); ++ifatjet)
    {
        LorentzVector fatjet_p4;
        float fatjet_msoftdrop;
        if (ana.is_postprocessed)
        {
            fatjet_p4=LorentzVector(nt.FatJet_pt_nom()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_nom()[ifatjet]);
            fatjet_msoftdrop = nt.FatJet_msoftdrop_nom()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]; //undo the W-JMS correction                  
        }
        else
        {
            fatjet_p4 = nt.FatJet_p4()[ifatjet];
            fatjet_msoftdrop = nt.FatJet_msoftdrop()[ifatjet];

        }

        // TODO: What is POG recommendation? do we use nt.FatJet_jetId()?
        // Figure this out
        if (not (fatjet_p4.pt() > 180. or (ana.systematicVariation and ana.is_postprocessed and !nt.isData())))
            continue;
        if (not (abs(fatjet_p4.eta()) < 2.4))
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
                if (RooUtil::Calc::DeltaR(fatjet_p4, nt.Electron_p4()[ilep_idx]) < 0.8)
                {
                    is_overlapping_with_a_lepton = true;
                    break;
                }
            }
            // else muon
            else
            {
                if (RooUtil::Calc::DeltaR(fatjet_p4, nt.Muon_p4()[ilep_idx]) < 0.8)
                {
                    is_overlapping_with_a_lepton = true;
                    break;
                }
            }
        }

        if (is_overlapping_with_a_lepton)
            continue;
        
        //computed with instructions from NanoAOD reference "For W vs QCD tagging, use (Xcc+Xqq)/(Xcc+Xqq+QCD)"
        float W_MD = ( nt.FatJet_particleNetMD_Xcc()[ifatjet] + nt.FatJet_particleNetMD_Xqq()[ifatjet]) / (nt.FatJet_particleNetMD_Xcc()[ifatjet] + nt.FatJet_particleNetMD_Xqq()[ifatjet] + nt.FatJet_particleNetMD_QCD()[ifatjet]);

        // For now, accept anything that reaches this point
        ana.tx.pushbackToBranch<int>("Common_fatjet_idxs", ifatjet);
        ana.tx.pushbackToBranch<int>("Common_fatjet_id", nt.FatJet_jetId()[ifatjet]);
        ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4", fatjet_p4);
        ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop", fatjet_msoftdrop);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deepMD_W", nt.FatJet_deepTagMD_WvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deep_W", nt.FatJet_deepTag_WvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deepMD_Z", nt.FatJet_deepTagMD_ZvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deep_Z", nt.FatJet_deepTag_ZvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deepMD_T", nt.FatJet_deepTagMD_TvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deep_T", nt.FatJet_deepTag_TvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_deepMD_bb", nt.FatJet_deepTagMD_bbvsLight()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_particleNet_W", nt.FatJet_particleNet_WvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_particleNet_Z", nt.FatJet_particleNet_ZvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_particleNet_T", nt.FatJet_particleNet_TvsQCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_particleNet_QCD", nt.FatJet_particleNet_QCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_particleNetMD_QCD", nt.FatJet_particleNetMD_QCD()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_particleNetMD_Xqq", nt.FatJet_particleNetMD_Xqq()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_particleNetMD_Xbb", nt.FatJet_particleNetMD_Xbb()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_particleNetMD_Xcc", nt.FatJet_particleNetMD_Xcc()[ifatjet]);
        ana.tx.pushbackToBranch<float>("Common_fatjet_particleNetMD_W", W_MD);
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
        if (ana.systematicVariation and ana.is_postprocessed and !nt.isData())
        {
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesAbsoluteStatup", LorentzVector(nt.FatJet_pt_jesAbsoluteStatUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesAbsoluteStatUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesAbsoluteStatdn", LorentzVector(nt.FatJet_pt_jesAbsoluteStatDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesAbsoluteStatDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesAbsoluteScaleup", LorentzVector(nt.FatJet_pt_jesAbsoluteScaleUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesAbsoluteScaleUp()[ifatjet]));            
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesAbsoluteScaledn", LorentzVector(nt.FatJet_pt_jesAbsoluteScaleDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesAbsoluteScaleDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesAbsoluteMPFBiasup", LorentzVector(nt.FatJet_pt_jesAbsoluteMPFBiasUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesAbsoluteMPFBiasUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesAbsoluteMPFBiasdn", LorentzVector(nt.FatJet_pt_jesAbsoluteMPFBiasDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesAbsoluteMPFBiasDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesFragmentationup", LorentzVector(nt.FatJet_pt_jesFragmentationUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesFragmentationUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesFragmentationdn", LorentzVector(nt.FatJet_pt_jesFragmentationDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesFragmentationDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesSinglePionECALup", LorentzVector(nt.FatJet_pt_jesSinglePionECALUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesSinglePionECALUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesSinglePionECALdn", LorentzVector(nt.FatJet_pt_jesSinglePionECALDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesSinglePionECALDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesSinglePionHCALup", LorentzVector(nt.FatJet_pt_jesSinglePionHCALUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesSinglePionHCALUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesSinglePionHCALdn", LorentzVector(nt.FatJet_pt_jesSinglePionHCALDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesSinglePionHCALDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesFlavorQCDup", LorentzVector(nt.FatJet_pt_jesFlavorQCDUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesFlavorQCDUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesFlavorQCDdn", LorentzVector(nt.FatJet_pt_jesFlavorQCDDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesFlavorQCDDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesTimePtEtaup", LorentzVector(nt.FatJet_pt_jesTimePtEtaUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesTimePtEtaUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesTimePtEtadn", LorentzVector(nt.FatJet_pt_jesTimePtEtaDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesTimePtEtaDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeJEREC1up", LorentzVector(nt.FatJet_pt_jesRelativeJEREC1Up()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeJEREC1Up()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeJEREC1dn", LorentzVector(nt.FatJet_pt_jesRelativeJEREC1Down()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeJEREC1Down()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeJEREC2up", LorentzVector(nt.FatJet_pt_jesRelativeJEREC2Up()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeJEREC2Up()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeJEREC2dn", LorentzVector(nt.FatJet_pt_jesRelativeJEREC2Down()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeJEREC2Down()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeJERHFup", LorentzVector(nt.FatJet_pt_jesRelativeJERHFUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeJERHFUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeJERHFdn", LorentzVector(nt.FatJet_pt_jesRelativeJERHFDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeJERHFDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativePtBBup", LorentzVector(nt.FatJet_pt_jesRelativePtBBUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativePtBBUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativePtBBdn", LorentzVector(nt.FatJet_pt_jesRelativePtBBDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativePtBBDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativePtEC1up", LorentzVector(nt.FatJet_pt_jesRelativePtEC1Up()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativePtEC1Up()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativePtEC1dn", LorentzVector(nt.FatJet_pt_jesRelativePtEC1Down()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativePtEC1Down()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativePtEC2up", LorentzVector(nt.FatJet_pt_jesRelativePtEC2Up()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativePtEC2Up()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativePtEC2dn", LorentzVector(nt.FatJet_pt_jesRelativePtEC2Down()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativePtEC2Down()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativePtHFup", LorentzVector(nt.FatJet_pt_jesRelativePtHFUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativePtHFUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativePtHFdn", LorentzVector(nt.FatJet_pt_jesRelativePtHFDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativePtHFDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeBalup", LorentzVector(nt.FatJet_pt_jesRelativeBalUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeBalUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeBaldn", LorentzVector(nt.FatJet_pt_jesRelativeBalDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeBalDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeSampleup", LorentzVector(nt.FatJet_pt_jesRelativeSampleUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeSampleUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeSampledn", LorentzVector(nt.FatJet_pt_jesRelativeSampleDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeSampleDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeFSRup", LorentzVector(nt.FatJet_pt_jesRelativeFSRUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeFSRUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeFSRdn", LorentzVector(nt.FatJet_pt_jesRelativeFSRDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeFSRDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeStatFSRup", LorentzVector(nt.FatJet_pt_jesRelativeStatFSRUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeStatFSRUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeStatFSRdn", LorentzVector(nt.FatJet_pt_jesRelativeStatFSRDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeStatFSRDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeStatECup", LorentzVector(nt.FatJet_pt_jesRelativeStatECUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeStatECUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeStatECdn", LorentzVector(nt.FatJet_pt_jesRelativeStatECDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeStatECDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeStatHFup", LorentzVector(nt.FatJet_pt_jesRelativeStatHFUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeStatHFUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesRelativeStatHFdn", LorentzVector(nt.FatJet_pt_jesRelativeStatHFDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesRelativeStatHFDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesPileUpDataMCup", LorentzVector(nt.FatJet_pt_jesPileUpDataMCUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesPileUpDataMCUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesPileUpDataMCdn", LorentzVector(nt.FatJet_pt_jesPileUpDataMCDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesPileUpDataMCDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesPileUpPtRefup", LorentzVector(nt.FatJet_pt_jesPileUpPtRefUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesPileUpPtRefUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesPileUpPtRefdn", LorentzVector(nt.FatJet_pt_jesPileUpPtRefDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesPileUpPtRefDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesPileUpPtBBup", LorentzVector(nt.FatJet_pt_jesPileUpPtBBUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesPileUpPtBBUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesPileUpPtBBdn", LorentzVector(nt.FatJet_pt_jesPileUpPtBBDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesPileUpPtBBDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesPileUpPtEC1up", LorentzVector(nt.FatJet_pt_jesPileUpPtEC1Up()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesPileUpPtEC1Up()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesPileUpPtEC1dn", LorentzVector(nt.FatJet_pt_jesPileUpPtEC1Down()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesPileUpPtEC1Down()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesPileUpPtEC2up", LorentzVector(nt.FatJet_pt_jesPileUpPtEC2Up()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesPileUpPtEC2Up()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesPileUpPtEC2dn", LorentzVector(nt.FatJet_pt_jesPileUpPtEC2Down()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesPileUpPtEC2Down()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesPileUpPtHFup", LorentzVector(nt.FatJet_pt_jesPileUpPtHFUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesPileUpPtHFUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesPileUpPtHFdn", LorentzVector(nt.FatJet_pt_jesPileUpPtHFDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesPileUpPtHFDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesup", LorentzVector(nt.FatJet_pt_jesTotalUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesTotalUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jesdn", LorentzVector(nt.FatJet_pt_jesTotalDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jesTotalDown()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jerup", LorentzVector(nt.FatJet_pt_jerUp()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jerUp()[ifatjet]));
            ana.tx.pushbackToBranch<LorentzVector>("Common_fatjet_p4_jerdn", LorentzVector(nt.FatJet_pt_jerDown()[ifatjet],nt.FatJet_eta()[ifatjet],nt.FatJet_phi()[ifatjet],nt.FatJet_mass_jerDown()[ifatjet]));
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesAbsoluteStatup", nt.FatJet_msoftdrop_jesAbsoluteStatUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesAbsoluteStatdn", nt.FatJet_msoftdrop_jesAbsoluteStatDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesAbsoluteScaleup", nt.FatJet_msoftdrop_jesAbsoluteScaleUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);            
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesAbsoluteScaledn", nt.FatJet_msoftdrop_jesAbsoluteScaleDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesAbsoluteMPFBiasup", nt.FatJet_msoftdrop_jesAbsoluteMPFBiasUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesAbsoluteMPFBiasdn", nt.FatJet_msoftdrop_jesAbsoluteMPFBiasDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesFragmentationup", nt.FatJet_msoftdrop_jesFragmentationUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesFragmentationdn", nt.FatJet_msoftdrop_jesFragmentationDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesSinglePionECALup", nt.FatJet_msoftdrop_jesSinglePionECALUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesSinglePionECALdn", nt.FatJet_msoftdrop_jesSinglePionECALDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesSinglePionHCALup", nt.FatJet_msoftdrop_jesSinglePionHCALUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesSinglePionHCALdn", nt.FatJet_msoftdrop_jesSinglePionHCALDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesFlavorQCDup", nt.FatJet_msoftdrop_jesFlavorQCDUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesFlavorQCDdn", nt.FatJet_msoftdrop_jesFlavorQCDDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesTimePtEtaup", nt.FatJet_msoftdrop_jesTimePtEtaUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesTimePtEtadn", nt.FatJet_msoftdrop_jesTimePtEtaDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeJEREC1up", nt.FatJet_msoftdrop_jesRelativeJEREC1Up()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeJEREC1dn", nt.FatJet_msoftdrop_jesRelativeJEREC1Down()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeJEREC2up", nt.FatJet_msoftdrop_jesRelativeJEREC2Up()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeJEREC2dn", nt.FatJet_msoftdrop_jesRelativeJEREC2Down()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeJERHFup", nt.FatJet_msoftdrop_jesRelativeJERHFUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeJERHFdn", nt.FatJet_msoftdrop_jesRelativeJERHFDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativePtBBup", nt.FatJet_msoftdrop_jesRelativePtBBUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativePtBBdn", nt.FatJet_msoftdrop_jesRelativePtBBDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativePtEC1up", nt.FatJet_msoftdrop_jesRelativePtEC1Up()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativePtEC1dn", nt.FatJet_msoftdrop_jesRelativePtEC1Down()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativePtEC2up", nt.FatJet_msoftdrop_jesRelativePtEC2Up()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativePtEC2dn", nt.FatJet_msoftdrop_jesRelativePtEC2Down()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativePtHFup", nt.FatJet_msoftdrop_jesRelativePtHFUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativePtHFdn", nt.FatJet_msoftdrop_jesRelativePtHFDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeBalup", nt.FatJet_msoftdrop_jesRelativeBalUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeBaldn", nt.FatJet_msoftdrop_jesRelativeBalDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeSampleup", nt.FatJet_msoftdrop_jesRelativeSampleUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeSampledn", nt.FatJet_msoftdrop_jesRelativeSampleDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeFSRup", nt.FatJet_msoftdrop_jesRelativeFSRUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeFSRdn", nt.FatJet_msoftdrop_jesRelativeFSRDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeStatFSRup", nt.FatJet_msoftdrop_jesRelativeStatFSRUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeStatFSRdn", nt.FatJet_msoftdrop_jesRelativeStatFSRDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeStatECup", nt.FatJet_msoftdrop_jesRelativeStatECUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeStatECdn", nt.FatJet_msoftdrop_jesRelativeStatECDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeStatHFup", nt.FatJet_msoftdrop_jesRelativeStatHFUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesRelativeStatHFdn", nt.FatJet_msoftdrop_jesRelativeStatHFDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesPileUpDataMCup", nt.FatJet_msoftdrop_jesPileUpDataMCUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesPileUpDataMCdn", nt.FatJet_msoftdrop_jesPileUpDataMCDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesPileUpPtRefup", nt.FatJet_msoftdrop_jesPileUpPtRefUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesPileUpPtRefdn", nt.FatJet_msoftdrop_jesPileUpPtRefDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesPileUpPtBBup", nt.FatJet_msoftdrop_jesPileUpPtBBUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesPileUpPtBBdn", nt.FatJet_msoftdrop_jesPileUpPtBBDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesPileUpPtEC1up", nt.FatJet_msoftdrop_jesPileUpPtEC1Up()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesPileUpPtEC1dn", nt.FatJet_msoftdrop_jesPileUpPtEC1Down()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesPileUpPtEC2up", nt.FatJet_msoftdrop_jesPileUpPtEC2Up()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesPileUpPtEC2dn", nt.FatJet_msoftdrop_jesPileUpPtEC2Down()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesPileUpPtHFup", nt.FatJet_msoftdrop_jesPileUpPtHFUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesPileUpPtHFdn", nt.FatJet_msoftdrop_jesPileUpPtHFDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesup", nt.FatJet_msoftdrop_jesTotalUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jesdn", nt.FatJet_msoftdrop_jesTotalDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jerup", nt.FatJet_msoftdrop_jerUp()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
            ana.tx.pushbackToBranch<float>("Common_fatjet_msoftdrop_jerdn", nt.FatJet_msoftdrop_jerDown()[ifatjet] / nt.FatJet_msoftdrop_corr_PUPPI()[ifatjet]);
        }

        float WPtemp = 0;
        int WPid = -999;
        int WPid_MD = -999;


        if (nt.FatJet_particleNet_WvsQCD()[ifatjet] > fjWPVloose) WPid = 0;
        if (nt.FatJet_particleNet_WvsQCD()[ifatjet] > fjWPmedium) WPid = 2;
        if (nt.FatJet_particleNet_WvsQCD()[ifatjet] > fjWPtight) WPid = 3;
        if (W_MD > fjWPloose_MD) WPid_MD = 1; 
        if (W_MD > fjWPmedium_MD) WPid_MD = 2; 
        if (W_MD > fjWPtight_MD) WPid_MD = 3; 
        ana.tx.pushbackToBranch<int>("Common_fatjet_WP", WPid);
        ana.tx.pushbackToBranch<int>("Common_fatjet_WP_MD", WPid_MD);
        ana.tx.pushbackToBranch<int>("Common_fatjet_WP_antimasscut", -999);
        ana.tx.pushbackToBranch<int>("Common_fatjet_WP_MD_antimasscut", -999);
        int year=(gconf.isAPV && nt.year()==2016)?10:nt.year();//use 0 for APV samples
        if (WPid >= 0)
        {
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, false, 0, fatjet_p4.eta(), fatjet_p4.pt(), 0);
            fjSFvlc *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFVLoose", WPtemp);
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, false, 0, fatjet_p4.eta(), fatjet_p4.pt(), -1);
            fjSFvld *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnVLoose", WPtemp);
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, false, 0, fatjet_p4.eta(), fatjet_p4.pt(), +1);
            fjSFvlu *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFupVLoose", WPtemp);
        }
        else
        {
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFVLoose", 0);
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnVLoose", 0);
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFupVLoose", 0);
        }
        if (WPid >= 2)
        {
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, false, 2, fatjet_p4.eta(), fatjet_p4.pt(), 0);
            fjSFmc *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFMedium", WPtemp);
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, false, 2, fatjet_p4.eta(), fatjet_p4.pt(), -1);
            fjSFmd *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnMedium", WPtemp);
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, false, 2, fatjet_p4.eta(), fatjet_p4.pt(), +1);
            fjSFmu *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFupMedium", WPtemp);
        }
        else
        {
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFMedium", 0);
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnMedium", 0);
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFupMedium", 0);
        }
        if (WPid >= 3)
        {
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, false, 3, fatjet_p4.eta(), fatjet_p4.pt(), 0);
            fjSFtc *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFTight", WPtemp);
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, false, 3, fatjet_p4.eta(), fatjet_p4.pt(), -1);
            fjSFtd *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnTight", WPtemp);
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, false, 3, fatjet_p4.eta(), fatjet_p4.pt(), +1);
            fjSFtu *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFupTight", WPtemp);
        }
        else
        {
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFTight", 0);
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFdnTight", 0);
            ana.tx.pushbackToBranch<float>("Common_fatjet_SFupTight", 0);
        }
        if (WPid_MD >= 0)
        {
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, true, 1, fatjet_p4.eta(), fatjet_p4.pt(), 0);
            fjMDSFlc *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFLoose", WPtemp);
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, true, 1, fatjet_p4.eta(), fatjet_p4.pt(), -1);
            fjMDSFld *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFdnLoose", WPtemp);
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, true, 1, fatjet_p4.eta(), fatjet_p4.pt(), +1);
            fjMDSFlu *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFupLoose", WPtemp);
        }
        else
        {
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFLoose", 0);
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFdnLoose", 0);
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFupLoose", 0);
        }
        if (WPid_MD >= 2)
        {
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, true, 2, fatjet_p4.eta(), fatjet_p4.pt(), 0);
            fjMDSFmc *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFMedium", WPtemp);
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, true, 2, fatjet_p4.eta(), fatjet_p4.pt(), -1);
            fjMDSFmd *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFdnMedium", WPtemp);
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, true, 2, fatjet_p4.eta(), fatjet_p4.pt(), +1);
            fjMDSFmu *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFupMedium", WPtemp);
        }
        else
        {
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFMedium", 0);
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFdnMedium", 0);
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFupMedium", 0);
        }
        if (WPid_MD >= 3)
        {
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, true, 3, fatjet_p4.eta(), fatjet_p4.pt(), 0);
            fjMDSFtc *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFTight", WPtemp);
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, true, 3, fatjet_p4.eta(), fatjet_p4.pt(), -1);
            fjMDSFtd *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFdnTight", WPtemp);
            WPtemp = ana.fatjetscalefactors.ak8SF(nt.isData(), year, 24, true, 3, fatjet_p4.eta(), fatjet_p4.pt(), +1);
            fjMDSFtu *= WPtemp;
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFupTight", WPtemp);
        }
        else
        {
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFTight", 0);
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFdnTight", 0);
            ana.tx.pushbackToBranch<float>("Common_fatjet_MD_SFupTight", 0);
        }
    }

    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFVLoose",   fjSFvlc);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFMedium",    fjSFmc);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFTight",     fjSFtc);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFupVLoose", fjSFvlu);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFupMedium",  fjSFmu);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFupTight",   fjSFtu);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFdnVLoose", fjSFvld);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFdnMedium",  fjSFmd);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_SFdnTight",   fjSFtd);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_MD_SFLoose",     fjMDSFlc);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_MD_SFMedium",    fjMDSFmc);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_MD_SFTight",     fjMDSFtc);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_MD_SFupLoose",   fjMDSFlu);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_MD_SFupMedium",  fjMDSFmu);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_MD_SFupTight",   fjMDSFtu);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_MD_SFdnLoose",   fjMDSFld);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_MD_SFdnMedium",  fjMDSFmd);
    ana.tx.setBranch<float>("Common_eventweight_fatjet_MD_SFdnTight",   fjMDSFtd);


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
        ana.tx.pushbackToBranch<int>("Common_jet_overlapfatjet", overlap_with_fatjet);
    }


    //---------------------------------------------------------------------------------------------
    // MET selection
    //---------------------------------------------------------------------------------------------
    if (ana.is_postprocessed && !nt.isData())
    {
        ana.tx.setBranch<LorentzVector>("Common_met_p4", LorentzVector(nt.MET_T1Smear_pt(), 0., nt.MET_T1Smear_phi(), 0)); 
        if(ana.systematicVariation){
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesAbsoluteStatup", LorentzVector(nt.MET_T1Smear_pt_jesAbsoluteStatUp(),0.,nt.MET_T1Smear_phi_jesAbsoluteStatUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesAbsoluteStatdn", LorentzVector(nt.MET_T1Smear_pt_jesAbsoluteStatDown(),0.,nt.MET_T1Smear_phi_jesAbsoluteStatDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesAbsoluteScaleup", LorentzVector(nt.MET_T1Smear_pt_jesAbsoluteScaleUp(),0.,nt.MET_T1Smear_phi_jesAbsoluteScaleUp(),0.));            
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesAbsoluteScaledn", LorentzVector(nt.MET_T1Smear_pt_jesAbsoluteScaleDown(),0.,nt.MET_T1Smear_phi_jesAbsoluteScaleDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesAbsoluteMPFBiasup", LorentzVector(nt.MET_T1Smear_pt_jesAbsoluteMPFBiasUp(),0.,nt.MET_T1Smear_phi_jesAbsoluteMPFBiasUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesAbsoluteMPFBiasdn", LorentzVector(nt.MET_T1Smear_pt_jesAbsoluteMPFBiasDown(),0.,nt.MET_T1Smear_phi_jesAbsoluteMPFBiasDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesFragmentationup", LorentzVector(nt.MET_T1Smear_pt_jesFragmentationUp(),0.,nt.MET_T1Smear_phi_jesFragmentationUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesFragmentationdn", LorentzVector(nt.MET_T1Smear_pt_jesFragmentationDown(),0.,nt.MET_T1Smear_phi_jesFragmentationDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesSinglePionECALup", LorentzVector(nt.MET_T1Smear_pt_jesSinglePionECALUp(),0.,nt.MET_T1Smear_phi_jesSinglePionECALUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesSinglePionECALdn", LorentzVector(nt.MET_T1Smear_pt_jesSinglePionECALDown(),0.,nt.MET_T1Smear_phi_jesSinglePionECALDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesSinglePionHCALup", LorentzVector(nt.MET_T1Smear_pt_jesSinglePionHCALUp(),0.,nt.MET_T1Smear_phi_jesSinglePionHCALUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesSinglePionHCALdn", LorentzVector(nt.MET_T1Smear_pt_jesSinglePionHCALDown(),0.,nt.MET_T1Smear_phi_jesSinglePionHCALDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesFlavorQCDup", LorentzVector(nt.MET_T1Smear_pt_jesFlavorQCDUp(),0.,nt.MET_T1Smear_phi_jesFlavorQCDUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesFlavorQCDdn", LorentzVector(nt.MET_T1Smear_pt_jesFlavorQCDDown(),0.,nt.MET_T1Smear_phi_jesFlavorQCDDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesTimePtEtaup", LorentzVector(nt.MET_T1Smear_pt_jesTimePtEtaUp(),0.,nt.MET_T1Smear_phi_jesTimePtEtaUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesTimePtEtadn", LorentzVector(nt.MET_T1Smear_pt_jesTimePtEtaDown(),0.,nt.MET_T1Smear_phi_jesTimePtEtaDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeJEREC1up", LorentzVector(nt.MET_T1Smear_pt_jesRelativeJEREC1Up(),0.,nt.MET_T1Smear_phi_jesRelativeJEREC1Up(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeJEREC1dn", LorentzVector(nt.MET_T1Smear_pt_jesRelativeJEREC1Down(),0.,nt.MET_T1Smear_phi_jesRelativeJEREC1Down(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeJEREC2up", LorentzVector(nt.MET_T1Smear_pt_jesRelativeJEREC2Up(),0.,nt.MET_T1Smear_phi_jesRelativeJEREC2Up(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeJEREC2dn", LorentzVector(nt.MET_T1Smear_pt_jesRelativeJEREC2Down(),0.,nt.MET_T1Smear_phi_jesRelativeJEREC2Down(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeJERHFup", LorentzVector(nt.MET_T1Smear_pt_jesRelativeJERHFUp(),0.,nt.MET_T1Smear_phi_jesRelativeJERHFUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeJERHFdn", LorentzVector(nt.MET_T1Smear_pt_jesRelativeJERHFDown(),0.,nt.MET_T1Smear_phi_jesRelativeJERHFDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtBBup", LorentzVector(nt.MET_T1Smear_pt_jesRelativePtBBUp(),0.,nt.MET_T1Smear_phi_jesRelativePtBBUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtBBdn", LorentzVector(nt.MET_T1Smear_pt_jesRelativePtBBDown(),0.,nt.MET_T1Smear_phi_jesRelativePtBBDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtEC1up", LorentzVector(nt.MET_T1Smear_pt_jesRelativePtEC1Up(),0.,nt.MET_T1Smear_phi_jesRelativePtEC1Up(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtEC1dn", LorentzVector(nt.MET_T1Smear_pt_jesRelativePtEC1Down(),0.,nt.MET_T1Smear_phi_jesRelativePtEC1Down(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtEC2up", LorentzVector(nt.MET_T1Smear_pt_jesRelativePtEC2Up(),0.,nt.MET_T1Smear_phi_jesRelativePtEC2Up(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtEC2dn", LorentzVector(nt.MET_T1Smear_pt_jesRelativePtEC2Down(),0.,nt.MET_T1Smear_phi_jesRelativePtEC2Down(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtHFup", LorentzVector(nt.MET_T1Smear_pt_jesRelativePtHFUp(),0.,nt.MET_T1Smear_phi_jesRelativePtHFUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtHFdn", LorentzVector(nt.MET_T1Smear_pt_jesRelativePtHFDown(),0.,nt.MET_T1Smear_phi_jesRelativePtHFDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeBalup", LorentzVector(nt.MET_T1Smear_pt_jesRelativeBalUp(),0.,nt.MET_T1Smear_phi_jesRelativeBalUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeBaldn", LorentzVector(nt.MET_T1Smear_pt_jesRelativeBalDown(),0.,nt.MET_T1Smear_phi_jesRelativeBalDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeSampleup", LorentzVector(nt.MET_T1Smear_pt_jesRelativeSampleUp(),0.,nt.MET_T1Smear_phi_jesRelativeSampleUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeSampledn", LorentzVector(nt.MET_T1Smear_pt_jesRelativeSampleDown(),0.,nt.MET_T1Smear_phi_jesRelativeSampleDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeFSRup", LorentzVector(nt.MET_T1Smear_pt_jesRelativeFSRUp(),0.,nt.MET_T1Smear_phi_jesRelativeFSRUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeFSRdn", LorentzVector(nt.MET_T1Smear_pt_jesRelativeFSRDown(),0.,nt.MET_T1Smear_phi_jesRelativeFSRDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeStatFSRup", LorentzVector(nt.MET_T1Smear_pt_jesRelativeStatFSRUp(),0.,nt.MET_T1Smear_phi_jesRelativeStatFSRUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeStatFSRdn", LorentzVector(nt.MET_T1Smear_pt_jesRelativeStatFSRDown(),0.,nt.MET_T1Smear_phi_jesRelativeStatFSRDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeStatECup", LorentzVector(nt.MET_T1Smear_pt_jesRelativeStatECUp(),0.,nt.MET_T1Smear_phi_jesRelativeStatECUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeStatECdn", LorentzVector(nt.MET_T1Smear_pt_jesRelativeStatECDown(),0.,nt.MET_T1Smear_phi_jesRelativeStatECDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeStatHFup", LorentzVector(nt.MET_T1Smear_pt_jesRelativeStatHFUp(),0.,nt.MET_T1Smear_phi_jesRelativeStatHFUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeStatHFdn", LorentzVector(nt.MET_T1Smear_pt_jesRelativeStatHFDown(),0.,nt.MET_T1Smear_phi_jesRelativeStatHFDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpDataMCup", LorentzVector(nt.MET_T1Smear_pt_jesPileUpDataMCUp(),0.,nt.MET_T1Smear_phi_jesPileUpDataMCUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpDataMCdn", LorentzVector(nt.MET_T1Smear_pt_jesPileUpDataMCDown(),0.,nt.MET_T1Smear_phi_jesPileUpDataMCDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtRefup", LorentzVector(nt.MET_T1Smear_pt_jesPileUpPtRefUp(),0.,nt.MET_T1Smear_phi_jesPileUpPtRefUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtRefdn", LorentzVector(nt.MET_T1Smear_pt_jesPileUpPtRefDown(),0.,nt.MET_T1Smear_phi_jesPileUpPtRefDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtBBup", LorentzVector(nt.MET_T1Smear_pt_jesPileUpPtBBUp(),0.,nt.MET_T1Smear_phi_jesPileUpPtBBUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtBBdn", LorentzVector(nt.MET_T1Smear_pt_jesPileUpPtBBDown(),0.,nt.MET_T1Smear_phi_jesPileUpPtBBDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtEC1up", LorentzVector(nt.MET_T1Smear_pt_jesPileUpPtEC1Up(),0.,nt.MET_T1Smear_phi_jesPileUpPtEC1Up(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtEC1dn", LorentzVector(nt.MET_T1Smear_pt_jesPileUpPtEC1Down(),0.,nt.MET_T1Smear_phi_jesPileUpPtEC1Down(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtEC2up", LorentzVector(nt.MET_T1Smear_pt_jesPileUpPtEC2Up(),0.,nt.MET_T1Smear_phi_jesPileUpPtEC2Up(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtEC2dn", LorentzVector(nt.MET_T1Smear_pt_jesPileUpPtEC2Down(),0.,nt.MET_T1Smear_phi_jesPileUpPtEC2Down(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtHFup", LorentzVector(nt.MET_T1Smear_pt_jesPileUpPtHFUp(),0.,nt.MET_T1Smear_phi_jesPileUpPtHFUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtHFdn", LorentzVector(nt.MET_T1Smear_pt_jesPileUpPtHFDown(),0.,nt.MET_T1Smear_phi_jesPileUpPtHFDown(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesup", LorentzVector(nt.MET_T1Smear_pt_jesTotalUp(),0.,nt.MET_T1Smear_phi_jesTotalUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesdn", LorentzVector(nt.MET_T1Smear_pt_jesTotalDown(),0.,nt.MET_T1Smear_phi_jesTotalDown(),0.));            
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jerup", LorentzVector(nt.MET_T1Smear_pt_jerUp(),0.,nt.MET_T1Smear_phi_jerUp(),0.));
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jerdn", LorentzVector(nt.MET_T1Smear_pt_jerDown(),0.,nt.MET_T1Smear_phi_jerDown(),0.));
        }
    }
    else
    {
        ana.tx.setBranch<LorentzVector>("Common_met_p4", RooUtil::Calc::getLV(nt.MET_pt(), 0., nt.MET_phi(), 0));
    }

    //---------------------------------------------------------------------------------------------
    // Gen-level particle selection
    //---------------------------------------------------------------------------------------------
    // This is only possible when it is MC and has GenPart Branches
    if (not nt.isData())
    {
        bool isSignal = false;

        float genHT = 0; // variable to be used to stitch HT-sliced samples

        // Loop over generator particles and do stuff
        for (unsigned int igen = 0; igen < nt.GenPart_pdgId().size(); ++igen)
        {

            // Following particles are used to compute genHT
            if ((abs(nt.GenPart_pdgId()[igen]) <  6 or // quarks
                 abs(nt.GenPart_pdgId()[igen]) == 21)  // gluons
                    and (nt.GenPart_status()[igen] == 22 or // something to do with "status 3"
                         nt.GenPart_status()[igen] == 23))
            {
                genHT += nt.GenPart_pt()[igen];
            }

            // Preliminary filter on the gen particles
            if (not (nt.GenPart_statusFlags()[igen] & (1 << 8))) continue; // fromHardProcess
            if (not (abs(nt.GenPart_pdgId()[igen]) <= 25)) continue;
            if (not (abs(nt.GenPart_pdgId()[igen]) != 21)) continue;

            // If vector boson do a last copy
            if (abs(nt.GenPart_pdgId()[igen]) == 23 or abs(nt.GenPart_pdgId()[igen]) == 24)
            {
                if (not (nt.GenPart_statusFlags()[igen] & (1 << 13))) continue; // isLastCopy
            }
            else if (abs(nt.GenPart_pdgId()[igen]) >= 11 and abs(nt.GenPart_pdgId()[igen]) <= 16)
            {
                if (not (nt.GenPart_statusFlags()[igen] & (1 << 12))) continue; // isFirstCopy
            }
            else if (abs(nt.GenPart_pdgId()[igen]) >= 1 and abs(nt.GenPart_pdgId()[igen]) <= 5)
            {
                if (not (nt.GenPart_statusFlags()[igen] & (1 << 12))) continue; // isFirstCopy
            }
            else // If not defined in previous line we don't consider the object
            {
                continue;
            }

            isSignal = true;
            
            ana.tx.pushbackToBranch<int>          ("Common_gen_idx", igen);                                                            // Selected gen-particle idx in NanoAOD
            ana.tx.pushbackToBranch<int>          ("Common_gen_mother_idx", nt.GenPart_genPartIdxMother()[igen]);                      // Selected gen-particle mother idx in NanoAOD
            ana.tx.pushbackToBranch<int>          ("Common_gen_mother_id",  nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[igen] ]); // Selected gen-particle mother idx in NanoAOD
            ana.tx.pushbackToBranch<int>          ("Common_gen_pdgid", nt.GenPart_pdgId()[igen]);                                      // Selected gen-particle pdgids
            ana.tx.pushbackToBranch<LorentzVector>("Common_gen_p4s", nt.GenPart_p4()[igen]);                                           // Selected gen-particle p4s

        }

        ana.tx.setBranch<float>("Common_genHT", genHT);
        ana.tx.setBranch<bool>("Common_isSignal", isSignal);

        // Selecting 6 fermions from VVV decays
        // int ngen = 0;
        if(isSignal){
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
                if (abs(ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[igen]) != 15)
                {
                    ana.tx.pushbackToBranch<int>("Common_gen_vvvdecay_taudecayid", 0); // no tau
                }
                else
                {

                    bool filled = false;

                    for (unsigned int jgen = 0; jgen < ana.tx.getBranch<vector<int>>("Common_gen_pdgid").size(); ++jgen)
                    {

                        if (ana.tx.getBranch<vector<int>>("Common_gen_idx")[igen] != ana.tx.getBranch<vector<int>>("Common_gen_mother_idx")[jgen])
                            continue;

                        //jgen has as mother the tau
                        if (abs(ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[jgen]) == 11 or abs(ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[jgen]) == 13) 
                        {
                            filled = true;
                            ana.tx.pushbackToBranch<int>("Common_gen_vvvdecay_taudecayid"  ,ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[jgen]);
                            break;
                        }
                    }
                    if (not filled)
                    {
                        if(ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[igen] == 15)
                        {
                            ana.tx.pushbackToBranch<int>("Common_gen_vvvdecay_taudecayid", -211);
                        }
                        else
                        {
                            ana.tx.pushbackToBranch<int>("Common_gen_vvvdecay_taudecayid",  211);
                        }
                    }
                }

                if (abs(ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[igen]) == 11 or abs(ana.tx.getBranch<vector<int>>("Common_gen_pdgid")[igen]) == 13)
                {
                    n_light_lepton++;
                }
            }

            ana.tx.setBranch<int>("Common_gen_n_light_lep", n_light_lepton);

            int nW = 0;
            int nZ = 0;
            int nlepW = 0;
            int ntaulepW = 0;
            int ntauhadW = 0;
            int nlepZ = 0;
            int ntaulepZ = 0;
            int ntauhadZ = 0;
            int nnuZ = 0;
            int nbZ = 0;
            int W1 = -1;
            int W2 = -1;
            bool isSS = false;

            for (unsigned int igen = 0; igen < ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_idx").size(); ++igen)
            {

                int decay = ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_pdgid")[igen];
                int mother = ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_mother_id")[igen];
                int leptau = ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_taudecayid")[igen];

                if (abs(mother) == 24)
                {

                    ++nW;

                    if (abs(decay) == 11 or abs(decay) == 13)
                    {
                        ++nlepW;
                    }
                    else if (abs(decay) == 15 and (abs(leptau) == 11 or abs(leptau) == 13))
                    {
                        ++ntaulepW;
                    }
                    else if (abs(decay) == 15 and abs(leptau) == 211)
                    {
                        ++ntauhadW;
                    }
                    if (abs(decay) == 11 or abs(decay) == 13 or (abs(decay) == 15 and (abs(leptau) == 11 or abs(leptau) == 13)))
                    {
                        if (W1 < 0)
                        {
                            W1 = igen; // first W
                        }
                        else
                        {
                            if (mother == ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_mother_id")[W1])
                            {
                                isSS = true; // first and this W are SS
                            }
                            else if (W2 < 0)
                            {
                                W2 = igen; // second W
                            }
                            else if (mother == ana.tx.getBranchLazy<vector<int>>("Common_gen_vvvdecay_mother_id")[W2])
                            {
                                isSS = true; // second and this W are SS
                            }
                        }
                    }
                }

                if (abs(mother) == 23)
                {
                    ++nZ;
                    if (abs(decay) == 11 or abs(decay) == 13)
                    {
                        ++nlepZ;
                    }
                    else if (abs(decay) == 15 and (abs(leptau) == 11 or abs(leptau) == 13))
                    {
                        ++ntaulepZ;
                    }
                    else if (abs(decay) == 15 and abs(leptau) == 211)
                    {
                        ++ntauhadZ;
                    }
                    else if (abs(decay) == 12 or abs(decay) == 14 or abs(decay) == 16)
                    {
                        ++nnuZ;
                    }
                    else if (abs(decay) == 5)
                    {
                        ++nbZ;
                    }
                }
            }

            ana.tx.setBranch<int> ("Common_n_W",        nW      );
            ana.tx.setBranch<int> ("Common_n_lep_W",    nlepW   );
            ana.tx.setBranch<int> ("Common_n_leptau_W", ntaulepW);
            ana.tx.setBranch<int> ("Common_n_hadtau_W", ntauhadW);
            ana.tx.setBranch<int> ("Common_n_Z",        nZ      );
            ana.tx.setBranch<int> ("Common_n_lep_Z",    nlepZ   );
            ana.tx.setBranch<int> ("Common_n_leptau_Z", ntaulepZ);
            ana.tx.setBranch<int> ("Common_n_hadtau_Z", ntauhadZ);
            ana.tx.setBranch<int> ("Common_n_nu_Z",     nnuZ    );
            ana.tx.setBranch<int> ("Common_n_b_Z",      nbZ     );
            ana.tx.setBranch<bool>("Common_haslepWSS",  isSS    );
        }
        // If VH ntuple than process Common_gen_VH_channel
        if (ana.input_file_list_tstring.Contains("VHToNonbb_M125"))
        {

            // The VHToNonbb_M125 sample's 3rd gen particle is always "V" of the VH
            // HOWEVER IN THE FUTURE MAKE SURE THIS IS TRUE ALWAYS IF ONE CHANGES SAMPLES!!
            int V_abspdgid = abs(nt.GenPart_pdgId()[2]);
            int HXX_abspdgid = 0;

            // Loop over generator particles and do stuff
            for (unsigned int igen = 0; igen < nt.GenPart_pdgId().size(); ++igen)
            {

                // Get the particles with higgs as mother that is not higgs
                if (
                        /* I am not Higgs      */ abs(nt.GenPart_pdgId()[igen]) != 25 and
                        /* But my mom is Higgs */ abs(nt.GenPart_pdgId()[nt.GenPart_genPartIdxMother()[igen]] == 25)
                   )
                {
                    HXX_abspdgid = abs(nt.GenPart_pdgId()[igen]);
                    break;
                }
            }

            if (HXX_abspdgid == 0)
            {
                std::cout << "WARNING: Did not find a particle that seems to match H->XX topology!";
                std::cout  << "event # = " << ana.looper.getCurrentEventIndex() << std::endl;
            }

            if      (V_abspdgid == 24 and HXX_abspdgid == 24) ana.tx.setBranch<int>("Common_gen_VH_channel", 0);
            else if (V_abspdgid == 23 and HXX_abspdgid == 24) ana.tx.setBranch<int>("Common_gen_VH_channel", 1);
            else if (V_abspdgid == 24 and HXX_abspdgid == 23) ana.tx.setBranch<int>("Common_gen_VH_channel", 2);
            else if (V_abspdgid == 23 and HXX_abspdgid == 23) ana.tx.setBranch<int>("Common_gen_VH_channel", 3);
            else                                              ana.tx.setBranch<int>("Common_gen_VH_channel", -HXX_abspdgid);
        }
    }
    else{
        ana.tx.setBranch<bool>("Common_isSignal", false);
    }

    //---------------------------------------------------------------------------------------------
    // Organizing object indices and sorting by Pt
    //---------------------------------------------------------------------------------------------

    // Sorting lepton branches
    ana.tx.sortVecBranchesByPt(
            /* name of the 4vector branch to use to pt sort by*/               "Common_lep_p4",
            /* names of any associated vector<float> branches to sort along */ {"Common_lep_dxy", "Common_lep_dz", "Common_lep_ip3d", "Common_lep_sip3d", "Common_lep_SF", "Common_lep_SFTight", "Common_lep_SFdn", "Common_lep_SFdnTight", "Common_lep_SFup", "Common_lep_SFupTight"},
            /* names of any associated vector<int>   branches to sort along */ {"Common_lep_idxs", "Common_lep_pdgid", "Common_lep_tight"},
            /* names of any associated vector<bool>  branches to sort along */ {}
            );

    // Sorting jet branches
    ana.tx.sortVecBranchesByPt(
            /* name of the 4vector branch to use to pt sort by*/               "Common_jet_p4",
            /* names of any associated vector<float> branches to sort along */ {},
            /* names of any associated vector<int>   branches to sort along */ {"Common_jet_idxs", "Common_jet_overlapfatjet", "Common_jet_id",},
            /* names of any associated vector<bool>  branches to sort along */ {"Common_jet_passBloose", "Common_jet_passBmedium", "Common_jet_passBtight"}
            );

    // Sorting fatjet branches
    ana.tx.sortVecBranchesByPt(
            /* name of the 4vector branch to use to pt sort by*/               "Common_fatjet_p4",
            /* names of any associated vector<float> branches to sort along */ {"Common_fatjet_msoftdrop", "Common_fatjet_deepMD_W", "Common_fatjet_deep_W", "Common_fatjet_deepMD_Z", "Common_fatjet_deep_Z", "Common_fatjet_deepMD_T", "Common_fatjet_deep_T", "Common_fatjet_deepMD_bb", "Common_fatjet_tau3", "Common_fatjet_tau2", "Common_fatjet_tau1", "Common_fatjet_tau32", "Common_fatjet_tau21", "Common_fatjet_subjet0_pt", "Common_fatjet_subjet0_eta", "Common_fatjet_subjet0_phi", "Common_fatjet_subjet0_mass", "Common_fatjet_subjet1_pt", "Common_fatjet_subjet1_eta", "Common_fatjet_subjet1_phi", "Common_fatjet_subjet1_mass", "Common_fatjet_SFVLoose", "Common_fatjet_SFLoose", "Common_fatjet_SFMedium", "Common_fatjet_SFTight", "Common_fatjet_SFdnVLoose", "Common_fatjet_SFdnLoose", "Common_fatjet_SFdnMedium", "Common_fatjet_SFdnTight", "Common_fatjet_SFupVLoose", "Common_fatjet_SFupLoose", "Common_fatjet_SFupMedium", "Common_fatjet_SFupTight" /*, "Common_fatjet_subjet0_p4", "Common_fatjet_subjet1_p4",*/, 
                                                                               },
            /* names of any associated vector<int>   branches to sort along */ {"Common_fatjet_idxs", "Common_fatjet_id", "Common_fatjet_WP", "Common_fatjet_WP_antimasscut"},
            /* names of any associated vector<bool>  branches to sort along */ {}
            );
     //-------------------------------------------------------------------------------------------
     // Setting Trigger weights
     //-------------------------------------------------------------------------------------------
     if(ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid").size() >= 2)
     {
         int lep1pdgid = ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[0];
         int lep2pdgid = ana.tx.getBranchLazy<vector<int>>("Common_lep_pdgid")[1];
         if(abs(lep1pdgid) == 11 && abs(lep2pdgid) == 11)
         {
             float lep1pt = std::min(std::max(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].pt(),20.01f),499.9f);
             float lep2pt = std::min(std::max(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].pt(),15.01f),499.9f);
             ana.tx.setBranch<float>("Common_event_triggerWeight",   ana.triggereeSF->eval(lep1pt, lep2pt));
             ana.tx.setBranch<float>("Common_event_triggerWeightup", ana.triggereeSF->eval_up(lep1pt, lep2pt));
             ana.tx.setBranch<float>("Common_event_triggerWeightdn", ana.triggereeSF->eval_down(lep1pt, lep2pt));
         }
         else if(abs(lep1pdgid) == 11 && abs(lep2pdgid) == 13)
         {
             float lepept = std::min(std::max(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].pt(),15.01f),499.9f);
             float lepmupt = std::min(std::max(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].pt(),15.01f),499.9f);
             ana.tx.setBranch<float>("Common_event_triggerWeight",   ana.triggeremuSF->eval(lepept, lepmupt));
             ana.tx.setBranch<float>("Common_event_triggerWeightup", ana.triggeremuSF->eval_up(lepept, lepmupt));
             ana.tx.setBranch<float>("Common_event_triggerWeightdn", ana.triggeremuSF->eval_down(lepept, lepmupt));
         }
         else if(abs(lep1pdgid) == 13 && abs(lep2pdgid) == 11)
         {
             float lepept = std::min(std::max(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].pt(),15.01f),499.9f);
             float lepmupt = std::min(std::max(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].pt(),15.01f),499.9f);
             ana.tx.setBranch<float>("Common_event_triggerWeight",   ana.triggeremuSF->eval(lepept, lepmupt));
             ana.tx.setBranch<float>("Common_event_triggerWeightup", ana.triggeremuSF->eval_up(lepept, lepmupt));
             ana.tx.setBranch<float>("Common_event_triggerWeightdn", ana.triggeremuSF->eval_down(lepept, lepmupt));
         }
         else if(abs(lep1pdgid) == 13 && abs(lep2pdgid) == 13)
         {
             float lep1pt = std::min(std::max(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[0].pt(),20.01f),499.9f);
             float lep2pt = std::min(std::max(ana.tx.getBranchLazy<vector<LorentzVector>>("Common_lep_p4")[1].pt(),15.01f),499.9f);
             ana.tx.setBranch<float>("Common_event_triggerWeight",   ana.triggermumuSF->eval(lep1pt, lep2pt));
             ana.tx.setBranch<float>("Common_event_triggerWeightup", ana.triggermumuSF->eval_up(lep1pt, lep2pt));
             ana.tx.setBranch<float>("Common_event_triggerWeightdn", ana.triggermumuSF->eval_down(lep1pt, lep2pt));
         }
  
         else
         {
             ana.tx.setBranch<float>("Common_event_triggerWeight",   1.);
             ana.tx.setBranch<float>("Common_event_triggerWeightup", 1.);
             ana.tx.setBranch<float>("Common_event_triggerWeightdn", 1.);
         }
     }
     else
     {
         ana.tx.setBranch<float>("Common_event_triggerWeight",   1.);
         ana.tx.setBranch<float>("Common_event_triggerWeightup", 1.);
         ana.tx.setBranch<float>("Common_event_triggerWeightdn", 1.);
     }  

}

void Process_Common_VVVTree()
{
    // Event level information
    ana.tx.setBranch<int>                  ("Common_isData", vvv.Common_isData());
    ana.tx.setBranch<int>                  ("Common_run", vvv.Common_run());
    ana.tx.setBranch<int>                  ("Common_lumi", vvv.Common_lumi());
    ana.tx.setBranch<unsigned long long>   ("Common_evt", vvv.Common_evt());
    ana.tx.setBranch<float>                ("Common_genWeight", vvv.Common_genWeight());
    ana.tx.setBranch<float>                ("Common_btagWeight_DeepCSVB", vvv.Common_btagWeight_DeepCSVB());

    ana.tx.setBranch<vector<float>>("Common_event_PDF"                                    , vvv.Common_event_PDF());                                     
    ana.tx.setBranch<vector<float>>("Common_event_QCDScale"                               , vvv.Common_event_QCDScale());

    ana.tx.setBranch<float>("Common_event_puWeight"                                       , vvv.Common_event_puWeight());
    ana.tx.setBranch<float>("Common_event_puWeightup"                                     , vvv.Common_event_puWeightup());
    ana.tx.setBranch<float>("Common_event_puWeightdn"                                     , vvv.Common_event_puWeightdn());

    ana.tx.setBranch<float>("Common_event_prefireWeight"                                  , vvv.Common_event_prefireWeight());
    ana.tx.setBranch<float>("Common_event_prefireWeightup"                                , vvv.Common_event_prefireWeightup());
    ana.tx.setBranch<float>("Common_event_prefireWeightdn"                                , vvv.Common_event_prefireWeightdn());
    // EFT weightings
    ana.tx.setBranch<vector<float>>        ("Common_LHEWeight_mg_reweighting", vvv.Common_LHEWeight_mg_reweighting());

    // 2016 only triggers
    ana.tx.setBranch<bool>                 ("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ", vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ()); // Lowest unprescaled
    ana.tx.setBranch<bool>                 ("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL", vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL()); // Lowest unprescaled
    // The rest of the triggers
    ana.tx.setBranch<bool>                 ("Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8", vvv.Common_HLT_Mu17_TrkIsoVVL_Mu8_TrkIsoVVL_DZ_Mass3p8()); // Lowest unprescaled for >= 2017C
    ana.tx.setBranch<bool>                 ("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", vvv.Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL_DZ());
    ana.tx.setBranch<bool>                 ("Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL", vvv.Common_HLT_Ele23_Ele12_CaloIdL_TrackIdL_IsoVL()); // Lowest unprescaled
    ana.tx.setBranch<bool>                 ("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ", vvv.Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL_DZ()); // Lowest unprescaled
    ana.tx.setBranch<bool>                 ("Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL", vvv.Common_HLT_Mu23_TrkIsoVVL_Ele12_CaloIdL_TrackIdL_IsoVL());
    ana.tx.setBranch<bool>                 ("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ", vvv.Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL_DZ()); // Lowest unprescaled
    ana.tx.setBranch<bool>                 ("Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL", vvv.Common_HLT_Mu8_TrkIsoVVL_Ele23_CaloIdL_TrackIdL_IsoVL());
    ana.tx.setBranch<bool>                 ("Common_HLT_PFHT1050"                                  , vvv.Common_HLT_PFHT1050());                                      
    ana.tx.setBranch<bool>                 ("Common_HLT_AK8PFJet500"                               , vvv.Common_HLT_AK8PFJet500());                                   
    ana.tx.setBranch<bool>                 ("Common_HLT_AK8PFJet380_TrimMass30"                    , vvv.Common_HLT_AK8PFJet380_TrimMass30());     
    ana.tx.setBranch<bool>                 ("Common_HLT_AK8PFJet360_TrimMass30"                    , vvv.Common_HLT_AK8PFJet360_TrimMass30());    
    ana.tx.setBranch<bool>                 ("Common_HLT_AK8PFJet400_TrimMass30"                    , vvv.Common_HLT_AK8PFJet400_TrimMass30());     
    ana.tx.setBranch<bool>                 ("Common_HLT_AK8PFJet420_TrimMass30"                    , vvv.Common_HLT_AK8PFJet420_TrimMass30());     
    ana.tx.setBranch<bool>                 ("Common_HLT_AK8PFHT750_TrimMass50"                     , vvv.Common_HLT_AK8PFHT750_TrimMass50());      
    ana.tx.setBranch<bool>                 ("Common_HLT_AK8PFHT800_TrimMass50"                     , vvv.Common_HLT_AK8PFHT800_TrimMass50());     
    ana.tx.setBranch<bool>                 ("Common_HLT_AK8PFHT850_TrimMass50"                     , vvv.Common_HLT_AK8PFHT850_TrimMass50());     
    ana.tx.setBranch<bool>                 ("Common_HLT_AK8PFHT900_TrimMass50"                    , vvv.Common_HLT_AK8PFHT900_TrimMass50()); 
    // Summary triggers
    ana.tx.setBranch<bool>                 ("Common_HLT_DoubleEl", vvv.Common_HLT_DoubleEl());
    ana.tx.setBranch<bool>                 ("Common_HLT_MuEG", vvv.Common_HLT_MuEG());
    ana.tx.setBranch<bool>                 ("Common_HLT_DoubleMu", vvv.Common_HLT_DoubleMu());

    ana.tx.setBranch<bool>                 ("Common_pass_duplicate_removal_ee_em_mm", vvv.Common_pass_duplicate_removal_ee_em_mm()); // Flag to identify whether the event passes duplicate removal
    ana.tx.setBranch<bool>                 ("Common_pass_duplicate_removal_mm_em_ee", vvv.Common_pass_duplicate_removal_mm_em_ee()); // Flag to identify whether the event passes duplicate removal
    ana.tx.setBranch<bool>                 ("Common_noiseFlag", vvv.Common_noiseFlag());                       // Flag to identify noise
    ana.tx.setBranch<bool>                 ("Common_noiseFlagMC", vvv.Common_noiseFlagMC());                     // Flag to identify noise
    ana.tx.setBranch<bool>                 ("Common_passGoodRun", vvv.Common_passGoodRun());                     // golden json

    // Summary 4 vectors of the objects selected
    ana.tx.setBranch<LorentzVector>        ("Common_met_p4", vvv.Common_met_p4());
    if(ana.systematicVariation){
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesAbsoluteStatup", vvv.Common_met_p4_jesAbsoluteStatup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesAbsoluteStatdn", vvv.Common_met_p4_jesAbsoluteStatdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesAbsoluteScaleup", vvv.Common_met_p4_jesAbsoluteScaleup());            
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesAbsoluteScaledn", vvv.Common_met_p4_jesAbsoluteScaledn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesAbsoluteMPFBiasup", vvv.Common_met_p4_jesAbsoluteMPFBiasup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesAbsoluteMPFBiasdn", vvv.Common_met_p4_jesAbsoluteMPFBiasdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesFragmentationup", vvv.Common_met_p4_jesFragmentationup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesFragmentationdn", vvv.Common_met_p4_jesFragmentationdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesSinglePionECALup", vvv.Common_met_p4_jesSinglePionECALup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesSinglePionECALdn", vvv.Common_met_p4_jesSinglePionECALdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesSinglePionHCALup", vvv.Common_met_p4_jesSinglePionHCALup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesSinglePionHCALdn", vvv.Common_met_p4_jesSinglePionHCALdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesFlavorQCDup", vvv.Common_met_p4_jesFlavorQCDup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesFlavorQCDdn", vvv.Common_met_p4_jesFlavorQCDdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesTimePtEtaup", vvv.Common_met_p4_jesTimePtEtaup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesTimePtEtadn", vvv.Common_met_p4_jesTimePtEtadn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeJEREC1up", vvv.Common_met_p4_jesRelativeJEREC1up());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeJEREC1dn", vvv.Common_met_p4_jesRelativeJEREC1dn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeJEREC2up", vvv.Common_met_p4_jesRelativeJEREC2up());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeJEREC2dn", vvv.Common_met_p4_jesRelativeJEREC2dn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeJERHFup", vvv.Common_met_p4_jesRelativeJERHFup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeJERHFdn", vvv.Common_met_p4_jesRelativeJERHFdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtBBup", vvv.Common_met_p4_jesRelativePtBBup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtBBdn", vvv.Common_met_p4_jesRelativePtBBdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtEC1up", vvv.Common_met_p4_jesRelativePtEC1up());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtEC1dn", vvv.Common_met_p4_jesRelativePtEC1dn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtEC2up", vvv.Common_met_p4_jesRelativePtEC2up());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtEC2dn", vvv.Common_met_p4_jesRelativePtEC2dn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtHFup", vvv.Common_met_p4_jesRelativePtHFup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativePtHFdn", vvv.Common_met_p4_jesRelativePtHFdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeBalup", vvv.Common_met_p4_jesRelativeBalup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeBaldn", vvv.Common_met_p4_jesRelativeBaldn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeSampleup", vvv.Common_met_p4_jesRelativeSampleup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeSampledn", vvv.Common_met_p4_jesRelativeSampledn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeFSRup", vvv.Common_met_p4_jesRelativeFSRup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeFSRdn", vvv.Common_met_p4_jesRelativeFSRdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeStatFSRup", vvv.Common_met_p4_jesRelativeStatFSRup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeStatFSRdn", vvv.Common_met_p4_jesRelativeStatFSRdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeStatECup", vvv.Common_met_p4_jesRelativeStatECup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeStatECdn", vvv.Common_met_p4_jesRelativeStatECdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeStatHFup", vvv.Common_met_p4_jesRelativeStatHFup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesRelativeStatHFdn", vvv.Common_met_p4_jesRelativeStatHFdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpDataMCup", vvv.Common_met_p4_jesPileUpDataMCup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpDataMCdn", vvv.Common_met_p4_jesPileUpDataMCdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtRefup", vvv.Common_met_p4_jesPileUpPtRefup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtRefdn", vvv.Common_met_p4_jesPileUpPtRefdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtBBup", vvv.Common_met_p4_jesPileUpPtBBup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtBBdn", vvv.Common_met_p4_jesPileUpPtBBdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtEC1up", vvv.Common_met_p4_jesPileUpPtEC1up());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtEC1dn", vvv.Common_met_p4_jesPileUpPtEC1dn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtEC2up", vvv.Common_met_p4_jesPileUpPtEC2up());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtEC2dn", vvv.Common_met_p4_jesPileUpPtEC2dn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtHFup", vvv.Common_met_p4_jesPileUpPtHFup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesPileUpPtHFdn", vvv.Common_met_p4_jesPileUpPtHFdn());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesup", vvv.Common_met_p4_jesup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jesdn", vvv.Common_met_p4_jesdn());            
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jerup", vvv.Common_met_p4_jerup());
            ana.tx.setBranch<LorentzVector>("Common_met_p4_jerdn", vvv.Common_met_p4_jerdn());
    }


    ana.tx.setBranch<float>                ("Common_event_lepSF", vvv.Common_event_lepSF());      // lepSF
    ana.tx.setBranch<float>                ("Common_event_lepSFelup", vvv.Common_event_lepSFelup());  // lepSF
    ana.tx.setBranch<float>                ("Common_event_lepSFeldn", vvv.Common_event_lepSFeldn());  // lepSF
    ana.tx.setBranch<float>                ("Common_event_lepSFmuup", vvv.Common_event_lepSFmuup());  // lepSF
    ana.tx.setBranch<float>                ("Common_event_lepSFmudn", vvv.Common_event_lepSFmudn());  // lepSF

    ana.tx.setBranch<vector<LorentzVector>>("Common_lep_p4", vvv.Common_lep_p4());        // Pt sorted selected lepton p4s (electrons and muons together)
    ana.tx.setBranch<vector<int>>          ("Common_lep_idxs", vvv.Common_lep_idxs());      // Pt sorted selected lepton idxs (electrons and muons together)
    ana.tx.setBranch<vector<int>>          ("Common_lep_pdgid", vvv.Common_lep_pdgid());     // Pt sorted selected lepton pdgids (so that Common_lep_idxs can be used to access NanoAOD)
    ana.tx.setBranch<vector<int>>          ("Common_lep_tight", vvv.Common_lep_tight());     // Pt sorted selected lepton tight (Where a tight version of the lepton isolation is used to reduce bkg a bit further if necessary)
    ana.tx.setBranch<vector<float>>        ("Common_lep_dxy", vvv.Common_lep_dxy());       // Pt sorted selected lepton dxy (electrons and muons together)
    ana.tx.setBranch<vector<float>>        ("Common_lep_dz", vvv.Common_lep_dz());        // Pt sorted selected lepton dz (electrons and muons together)
    ana.tx.setBranch<vector<float>>        ("Common_lep_ip3d", vvv.Common_lep_ip3d());        // Pt sorted selected lepton ip3d (electrons and muons together)
    ana.tx.setBranch<vector<float>>        ("Common_lep_sip3d", vvv.Common_lep_sip3d());        // Pt sorted selected lepton sip3d (electrons and muons together)
    ana.tx.setBranch<vector<float>>        ("Common_lep_SF", vvv.Common_lep_SF());        // SF
    ana.tx.setBranch<vector<float>>        ("Common_lep_SFTight", vvv.Common_lep_SFTight());   // SF tight iso
    ana.tx.setBranch<vector<float>>        ("Common_lep_SFdn", vvv.Common_lep_SFdn());      // SF
    ana.tx.setBranch<vector<float>>        ("Common_lep_SFdnTight", vvv.Common_lep_SFdnTight()); // SF tight iso
    ana.tx.setBranch<vector<float>>        ("Common_lep_SFup", vvv.Common_lep_SFup());      // SF
    ana.tx.setBranch<vector<float>>        ("Common_lep_SFupTight", vvv.Common_lep_SFupTight()); // SF tight iso

    // Jet variables
    ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4", vvv.Common_jet_p4());            // Pt sorted selected jet p4s
    if (ana.systematicVariation)
    {
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesAbsoluteStatup", vvv.Common_jet_p4_jesAbsoluteStatup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesAbsoluteStatdn", vvv.Common_jet_p4_jesAbsoluteStatdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesAbsoluteScaleup", vvv.Common_jet_p4_jesAbsoluteScaleup());            
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesAbsoluteScaledn", vvv.Common_jet_p4_jesAbsoluteScaledn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesAbsoluteMPFBiasup", vvv.Common_jet_p4_jesAbsoluteMPFBiasup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesAbsoluteMPFBiasdn", vvv.Common_jet_p4_jesAbsoluteMPFBiasdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesFragmentationup", vvv.Common_jet_p4_jesFragmentationup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesFragmentationdn", vvv.Common_jet_p4_jesFragmentationdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesSinglePionECALup", vvv.Common_jet_p4_jesSinglePionECALup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesSinglePionECALdn", vvv.Common_jet_p4_jesSinglePionECALdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesSinglePionHCALup", vvv.Common_jet_p4_jesSinglePionHCALup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesSinglePionHCALdn", vvv.Common_jet_p4_jesSinglePionHCALdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesFlavorQCDup", vvv.Common_jet_p4_jesFlavorQCDup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesFlavorQCDdn", vvv.Common_jet_p4_jesFlavorQCDdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesTimePtEtaup", vvv.Common_jet_p4_jesTimePtEtaup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesTimePtEtadn", vvv.Common_jet_p4_jesTimePtEtadn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeJEREC1up", vvv.Common_jet_p4_jesRelativeJEREC1up());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeJEREC1dn", vvv.Common_jet_p4_jesRelativeJEREC1dn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeJEREC2up", vvv.Common_jet_p4_jesRelativeJEREC2up());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeJEREC2dn", vvv.Common_jet_p4_jesRelativeJEREC2dn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeJERHFup", vvv.Common_jet_p4_jesRelativeJERHFup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeJERHFdn", vvv.Common_jet_p4_jesRelativeJERHFdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativePtBBup", vvv.Common_jet_p4_jesRelativePtBBup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativePtBBdn", vvv.Common_jet_p4_jesRelativePtBBdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativePtEC1up", vvv.Common_jet_p4_jesRelativePtEC1up());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativePtEC1dn", vvv.Common_jet_p4_jesRelativePtEC1dn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativePtEC2up", vvv.Common_jet_p4_jesRelativePtEC2up());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativePtEC2dn", vvv.Common_jet_p4_jesRelativePtEC2dn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativePtHFup", vvv.Common_jet_p4_jesRelativePtHFup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativePtHFdn", vvv.Common_jet_p4_jesRelativePtHFdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeBalup", vvv.Common_jet_p4_jesRelativeBalup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeBaldn", vvv.Common_jet_p4_jesRelativeBaldn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeSampleup", vvv.Common_jet_p4_jesRelativeSampleup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeSampledn", vvv.Common_jet_p4_jesRelativeSampledn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeFSRup", vvv.Common_jet_p4_jesRelativeFSRup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeFSRdn", vvv.Common_jet_p4_jesRelativeFSRdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeStatFSRup", vvv.Common_jet_p4_jesRelativeStatFSRup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeStatFSRdn", vvv.Common_jet_p4_jesRelativeStatFSRdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeStatECup", vvv.Common_jet_p4_jesRelativeStatECup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeStatECdn", vvv.Common_jet_p4_jesRelativeStatECdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeStatHFup", vvv.Common_jet_p4_jesRelativeStatHFup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesRelativeStatHFdn", vvv.Common_jet_p4_jesRelativeStatHFdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesPileUpDataMCup", vvv.Common_jet_p4_jesPileUpDataMCup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesPileUpDataMCdn", vvv.Common_jet_p4_jesPileUpDataMCdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesPileUpPtRefup", vvv.Common_jet_p4_jesPileUpPtRefup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesPileUpPtRefdn", vvv.Common_jet_p4_jesPileUpPtRefdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesPileUpPtBBup", vvv.Common_jet_p4_jesPileUpPtBBup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesPileUpPtBBdn", vvv.Common_jet_p4_jesPileUpPtBBdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesPileUpPtEC1up", vvv.Common_jet_p4_jesPileUpPtEC1up());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesPileUpPtEC1dn", vvv.Common_jet_p4_jesPileUpPtEC1dn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesPileUpPtEC2up", vvv.Common_jet_p4_jesPileUpPtEC2up());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesPileUpPtEC2dn", vvv.Common_jet_p4_jesPileUpPtEC2dn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesPileUpPtHFup", vvv.Common_jet_p4_jesPileUpPtHFup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesPileUpPtHFdn", vvv.Common_jet_p4_jesPileUpPtHFdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesup", vvv.Common_jet_p4_jesup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jesdn", vvv.Common_jet_p4_jesdn());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jerup", vvv.Common_jet_p4_jerup());
	ana.tx.setBranch<vector<LorentzVector>>("Common_jet_p4_jerdn", vvv.Common_jet_p4_jerdn());
    }
    ana.tx.setBranch<vector<int>>          ("Common_jet_idxs", vvv.Common_jet_idxs());          // Pt sorted selected jet idxs (To access rest of the jet variables in NanoAOD)
    ana.tx.setBranch<vector<int>>          ("Common_jet_id", vvv.Common_jet_id());          // Pt sorted selected jet idxs (To access rest of the jet variables in NanoAOD)
    ana.tx.setBranch<vector<bool>>         ("Common_jet_passBloose", vvv.Common_jet_passBloose());    // Pt sorted selected jet idxs (To access rest of the jet variables in NanoAOD)
    ana.tx.setBranch<vector<bool>>         ("Common_jet_passBmedium", vvv.Common_jet_passBmedium());   // Pt sorted selected jet idxs (To access rest of the jet variables in NanoAOD)
    ana.tx.setBranch<vector<bool>>         ("Common_jet_passBtight", vvv.Common_jet_passBtight());    // Pt sorted selected jet idxs (To access rest of the jet variables in NanoAOD)
    //ana.tx.setBranch<vector<float>>        ("Common_jet_bSFLoose", vvv.Common_jet_bSFLoose());      // single jet bSF
    //ana.tx.setBranch<vector<float>>        ("Common_jet_bSFMedium", vvv.Common_jet_bSFMedium());     // single jet bSF
    //ana.tx.setBranch<vector<float>>        ("Common_jet_bSFTight", vvv.Common_jet_bSFTight());      // single jet bSF
    //ana.tx.setBranch<vector<float>>        ("Common_jet_bSFdnLoose", vvv.Common_jet_bSFdnLoose());    // single jet bSF
    //ana.tx.setBranch<vector<float>>        ("Common_jet_bSFdnMedium", vvv.Common_jet_bSFdnMedium());   // single jet bSF
    //ana.tx.setBranch<vector<float>>        ("Common_jet_bSFdnTight", vvv.Common_jet_bSFdnTight());    // single jet bSF
    //ana.tx.setBranch<vector<float>>        ("Common_jet_bSFupLoose", vvv.Common_jet_bSFupLoose());    // single jet bSF
    //ana.tx.setBranch<vector<float>>        ("Common_jet_bSFupMedium", vvv.Common_jet_bSFupMedium());   // single jet bSF
    //ana.tx.setBranch<vector<float>>        ("Common_jet_bSFupTight", vvv.Common_jet_bSFupTight());    // single jet bSF
    ana.tx.setBranch<vector<int>>          ("Common_jet_overlapfatjet", vvv.Common_jet_overlapfatjet()); // Pt sorted selected jet idxs (To access rest of the jet variables in NanoAOD)

    // Fat jet variables
    ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4", vvv.Common_fatjet_p4());            // Pt sorted selected fatjet p4s
    if (ana.systematicVariation)
    {
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesAbsoluteStatup", vvv.Common_fatjet_p4_jesAbsoluteStatup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesAbsoluteStatdn", vvv.Common_fatjet_p4_jesAbsoluteStatdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesAbsoluteScaleup", vvv.Common_fatjet_p4_jesAbsoluteScaleup());            
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesAbsoluteScaledn", vvv.Common_fatjet_p4_jesAbsoluteScaledn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesAbsoluteMPFBiasup", vvv.Common_fatjet_p4_jesAbsoluteMPFBiasup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesAbsoluteMPFBiasdn", vvv.Common_fatjet_p4_jesAbsoluteMPFBiasdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesFragmentationup", vvv.Common_fatjet_p4_jesFragmentationup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesFragmentationdn", vvv.Common_fatjet_p4_jesFragmentationdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesSinglePionECALup", vvv.Common_fatjet_p4_jesSinglePionECALup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesSinglePionECALdn", vvv.Common_fatjet_p4_jesSinglePionECALdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesSinglePionHCALup", vvv.Common_fatjet_p4_jesSinglePionHCALup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesSinglePionHCALdn", vvv.Common_fatjet_p4_jesSinglePionHCALdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesFlavorQCDup", vvv.Common_fatjet_p4_jesFlavorQCDup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesFlavorQCDdn", vvv.Common_fatjet_p4_jesFlavorQCDdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesTimePtEtaup", vvv.Common_fatjet_p4_jesTimePtEtaup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesTimePtEtadn", vvv.Common_fatjet_p4_jesTimePtEtadn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeJEREC1up", vvv.Common_fatjet_p4_jesRelativeJEREC1up());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeJEREC1dn", vvv.Common_fatjet_p4_jesRelativeJEREC1dn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeJEREC2up", vvv.Common_fatjet_p4_jesRelativeJEREC2up());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeJEREC2dn", vvv.Common_fatjet_p4_jesRelativeJEREC2dn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeJERHFup", vvv.Common_fatjet_p4_jesRelativeJERHFup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeJERHFdn", vvv.Common_fatjet_p4_jesRelativeJERHFdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativePtBBup", vvv.Common_fatjet_p4_jesRelativePtBBup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativePtBBdn", vvv.Common_fatjet_p4_jesRelativePtBBdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativePtEC1up", vvv.Common_fatjet_p4_jesRelativePtEC1up());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativePtEC1dn", vvv.Common_fatjet_p4_jesRelativePtEC1dn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativePtEC2up", vvv.Common_fatjet_p4_jesRelativePtEC2up());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativePtEC2dn", vvv.Common_fatjet_p4_jesRelativePtEC2dn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativePtHFup", vvv.Common_fatjet_p4_jesRelativePtHFup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativePtHFdn", vvv.Common_fatjet_p4_jesRelativePtHFdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeBalup", vvv.Common_fatjet_p4_jesRelativeBalup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeBaldn", vvv.Common_fatjet_p4_jesRelativeBaldn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeSampleup", vvv.Common_fatjet_p4_jesRelativeSampleup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeSampledn", vvv.Common_fatjet_p4_jesRelativeSampledn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeFSRup", vvv.Common_fatjet_p4_jesRelativeFSRup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeFSRdn", vvv.Common_fatjet_p4_jesRelativeFSRdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeStatFSRup", vvv.Common_fatjet_p4_jesRelativeStatFSRup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeStatFSRdn", vvv.Common_fatjet_p4_jesRelativeStatFSRdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeStatECup", vvv.Common_fatjet_p4_jesRelativeStatECup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeStatECdn", vvv.Common_fatjet_p4_jesRelativeStatECdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeStatHFup", vvv.Common_fatjet_p4_jesRelativeStatHFup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesRelativeStatHFdn", vvv.Common_fatjet_p4_jesRelativeStatHFdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesPileUpDataMCup", vvv.Common_fatjet_p4_jesPileUpDataMCup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesPileUpDataMCdn", vvv.Common_fatjet_p4_jesPileUpDataMCdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesPileUpPtRefup", vvv.Common_fatjet_p4_jesPileUpPtRefup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesPileUpPtRefdn", vvv.Common_fatjet_p4_jesPileUpPtRefdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesPileUpPtBBup", vvv.Common_fatjet_p4_jesPileUpPtBBup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesPileUpPtBBdn", vvv.Common_fatjet_p4_jesPileUpPtBBdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesPileUpPtEC1up", vvv.Common_fatjet_p4_jesPileUpPtEC1up());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesPileUpPtEC1dn", vvv.Common_fatjet_p4_jesPileUpPtEC1dn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesPileUpPtEC2up", vvv.Common_fatjet_p4_jesPileUpPtEC2up());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesPileUpPtEC2dn", vvv.Common_fatjet_p4_jesPileUpPtEC2dn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesPileUpPtHFup", vvv.Common_fatjet_p4_jesPileUpPtHFup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesPileUpPtHFdn", vvv.Common_fatjet_p4_jesPileUpPtHFdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesup", vvv.Common_fatjet_p4_jesup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jesdn", vvv.Common_fatjet_p4_jesdn());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jerup", vvv.Common_fatjet_p4_jerup());
            ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_p4_jerdn", vvv.Common_fatjet_p4_jerdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesAbsoluteStatup", vvv.Common_fatjet_msoftdrop_jesAbsoluteStatup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesAbsoluteStatdn", vvv.Common_fatjet_msoftdrop_jesAbsoluteStatdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesAbsoluteScaleup", vvv.Common_fatjet_msoftdrop_jesAbsoluteScaleup());            
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesAbsoluteScaledn", vvv.Common_fatjet_msoftdrop_jesAbsoluteScaledn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesAbsoluteMPFBiasup", vvv.Common_fatjet_msoftdrop_jesAbsoluteMPFBiasup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesAbsoluteMPFBiasdn", vvv.Common_fatjet_msoftdrop_jesAbsoluteMPFBiasdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesFragmentationup", vvv.Common_fatjet_msoftdrop_jesFragmentationup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesFragmentationdn", vvv.Common_fatjet_msoftdrop_jesFragmentationdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesSinglePionECALup", vvv.Common_fatjet_msoftdrop_jesSinglePionECALup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesSinglePionECALdn", vvv.Common_fatjet_msoftdrop_jesSinglePionECALdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesSinglePionHCALup", vvv.Common_fatjet_msoftdrop_jesSinglePionHCALup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesSinglePionHCALdn", vvv.Common_fatjet_msoftdrop_jesSinglePionHCALdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesFlavorQCDup", vvv.Common_fatjet_msoftdrop_jesFlavorQCDup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesFlavorQCDdn", vvv.Common_fatjet_msoftdrop_jesFlavorQCDdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesTimePtEtaup", vvv.Common_fatjet_msoftdrop_jesTimePtEtaup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesTimePtEtadn", vvv.Common_fatjet_msoftdrop_jesTimePtEtadn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeJEREC1up", vvv.Common_fatjet_msoftdrop_jesRelativeJEREC1up());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeJEREC1dn", vvv.Common_fatjet_msoftdrop_jesRelativeJEREC1dn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeJEREC2up", vvv.Common_fatjet_msoftdrop_jesRelativeJEREC2up());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeJEREC2dn", vvv.Common_fatjet_msoftdrop_jesRelativeJEREC2dn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeJERHFup", vvv.Common_fatjet_msoftdrop_jesRelativeJERHFup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeJERHFdn", vvv.Common_fatjet_msoftdrop_jesRelativeJERHFdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativePtBBup", vvv.Common_fatjet_msoftdrop_jesRelativePtBBup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativePtBBdn", vvv.Common_fatjet_msoftdrop_jesRelativePtBBdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativePtEC1up", vvv.Common_fatjet_msoftdrop_jesRelativePtEC1up());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativePtEC1dn", vvv.Common_fatjet_msoftdrop_jesRelativePtEC1dn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativePtEC2up", vvv.Common_fatjet_msoftdrop_jesRelativePtEC2up());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativePtEC2dn", vvv.Common_fatjet_msoftdrop_jesRelativePtEC2dn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativePtHFup", vvv.Common_fatjet_msoftdrop_jesRelativePtHFup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativePtHFdn", vvv.Common_fatjet_msoftdrop_jesRelativePtHFdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeBalup", vvv.Common_fatjet_msoftdrop_jesRelativeBalup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeBaldn", vvv.Common_fatjet_msoftdrop_jesRelativeBaldn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeSampleup", vvv.Common_fatjet_msoftdrop_jesRelativeSampleup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeSampledn", vvv.Common_fatjet_msoftdrop_jesRelativeSampledn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeFSRup", vvv.Common_fatjet_msoftdrop_jesRelativeFSRup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeFSRdn", vvv.Common_fatjet_msoftdrop_jesRelativeFSRdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeStatFSRup", vvv.Common_fatjet_msoftdrop_jesRelativeStatFSRup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeStatFSRdn", vvv.Common_fatjet_msoftdrop_jesRelativeStatFSRdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeStatECup", vvv.Common_fatjet_msoftdrop_jesRelativeStatECup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeStatECdn", vvv.Common_fatjet_msoftdrop_jesRelativeStatECdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeStatHFup", vvv.Common_fatjet_msoftdrop_jesRelativeStatHFup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesRelativeStatHFdn", vvv.Common_fatjet_msoftdrop_jesRelativeStatHFdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesPileUpDataMCup", vvv.Common_fatjet_msoftdrop_jesPileUpDataMCup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesPileUpDataMCdn", vvv.Common_fatjet_msoftdrop_jesPileUpDataMCdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesPileUpPtRefup", vvv.Common_fatjet_msoftdrop_jesPileUpPtRefup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesPileUpPtRefdn", vvv.Common_fatjet_msoftdrop_jesPileUpPtRefdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesPileUpPtBBup", vvv.Common_fatjet_msoftdrop_jesPileUpPtBBup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesPileUpPtBBdn", vvv.Common_fatjet_msoftdrop_jesPileUpPtBBdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesPileUpPtEC1up", vvv.Common_fatjet_msoftdrop_jesPileUpPtEC1up());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesPileUpPtEC1dn", vvv.Common_fatjet_msoftdrop_jesPileUpPtEC1dn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesPileUpPtEC2up", vvv.Common_fatjet_msoftdrop_jesPileUpPtEC2up());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesPileUpPtEC2dn", vvv.Common_fatjet_msoftdrop_jesPileUpPtEC2dn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesPileUpPtHFup", vvv.Common_fatjet_msoftdrop_jesPileUpPtHFup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesPileUpPtHFdn", vvv.Common_fatjet_msoftdrop_jesPileUpPtHFdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesup", vvv.Common_fatjet_msoftdrop_jesup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jesdn", vvv.Common_fatjet_msoftdrop_jesdn());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jerup", vvv.Common_fatjet_msoftdrop_jerup());
            ana.tx.setBranch<vector<float>>("Common_fatjet_msoftdrop_jerdn", vvv.Common_fatjet_msoftdrop_jerdn());
    }

    ana.tx.setBranch<vector<int>>          ("Common_fatjet_idxs", vvv.Common_fatjet_idxs());          // Pt sorted selected fatjet idxs (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<int>>          ("Common_fatjet_id", vvv.Common_fatjet_id());          // Pt sorted selected fatjet idxs (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_msoftdrop", vvv.Common_fatjet_msoftdrop());     // Pt sorted selected fatjet msoftdrop (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_deepMD_W", vvv.Common_fatjet_deepMD_W());      // Pt sorted selected fatjet FatJet_deepTagMD_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_deep_W", vvv.Common_fatjet_deep_W());        // Pt sorted selected fatjet FatJet_deepTag_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_deepMD_Z", vvv.Common_fatjet_deepMD_Z());      // Pt sorted selected fatjet FatJet_deepTagMD_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_deep_Z", vvv.Common_fatjet_deep_Z());        // Pt sorted selected fatjet FatJet_deepTag_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_deepMD_T", vvv.Common_fatjet_deepMD_T());      // Pt sorted selected fatjet FatJet_deepTagMD_TvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_deep_T", vvv.Common_fatjet_deep_T());        // Pt sorted selected fatjet FatJet_deepTag_TvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_deepMD_bb", vvv.Common_fatjet_deepMD_bb());     // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_particleNet_W", vvv.Common_fatjet_particleNet_W());        // Pt sorted selected fatjet FatJet_particleNetTag_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_particleNet_Z", vvv.Common_fatjet_particleNet_Z());        // Pt sorted selected fatjet FatJet_particleNetTag_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_particleNet_T", vvv.Common_fatjet_particleNet_T());        // Pt sorted selected fatjet FatJet_particleNetTag_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_particleNet_QCD", vvv.Common_fatjet_particleNet_QCD());        // Pt sorted selected fatjet FatJet_particleNetTag_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_particleNetMD_QCD", vvv.Common_fatjet_particleNetMD_QCD());        // Pt sorted selected fatjet FatJet_particleNetTag_WvsQCD (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_particleNetMD_W", vvv.Common_fatjet_particleNetMD_W());        // Pt sorted selected fatjet FatJet_particleNetTag_WvsW (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_particleNetMD_Xqq", vvv.Common_fatjet_particleNetMD_Xqq());        // Pt sorted selected fatjet FatJet_particleNetTag_WvsXqq (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_particleNetMD_Xcc", vvv.Common_fatjet_particleNetMD_Xcc());        // Pt sorted selected fatjet FatJet_particleNetTag_WvsXcc (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_particleNetMD_Xbb", vvv.Common_fatjet_particleNetMD_Xbb());        // Pt sorted selected fatjet FatJet_particleNetTag_WvsXbb (To abbess rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_tau3", vvv.Common_fatjet_tau3());          // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_tau2", vvv.Common_fatjet_tau2());          // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_tau1", vvv.Common_fatjet_tau1());          // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_tau32", vvv.Common_fatjet_tau32());         // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_tau21", vvv.Common_fatjet_tau21());         // Pt sorted selected fatjet FatJet_deepTagMD_bbvsLight (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_subjet0_pt", vvv.Common_fatjet_subjet0_pt());    // Pt sorted selected fatjet subjet p4 0 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_subjet0_eta", vvv.Common_fatjet_subjet0_eta());   // Pt sorted selected fatjet subjet p4 0 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_subjet0_phi", vvv.Common_fatjet_subjet0_phi());   // Pt sorted selected fatjet subjet p4 0 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_subjet0_mass", vvv.Common_fatjet_subjet0_mass());  // Pt sorted selected fatjet subjet p4 0 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_subjet1_pt", vvv.Common_fatjet_subjet1_pt());    // Pt sorted selected fatjet subjet p4 1 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_subjet1_eta", vvv.Common_fatjet_subjet1_eta());   // Pt sorted selected fatjet subjet p4 2 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_subjet1_phi", vvv.Common_fatjet_subjet1_phi());   // Pt sorted selected fatjet subjet p4 3 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_subjet1_mass", vvv.Common_fatjet_subjet1_mass());  // Pt sorted selected fatjet subjet p4 4 (To access rest of the fatjet variables in NanoAOD)
    ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_subjet0_p4", vvv.Common_fatjet_subjet0_p4());    // Pt sorted selected fatjet p4s
    ana.tx.setBranch<vector<LorentzVector>>("Common_fatjet_subjet1_p4", vvv.Common_fatjet_subjet1_p4());    // Pt sorted selected fatjet p4s
    ana.tx.setBranch<vector<int>>          ("Common_fatjet_WP", vvv.Common_fatjet_WP());            // WP: 0: VLoose (5%), 1: Loose (2.5%), 2: Medium (1%), 3: Tight (0.5%)
    ana.tx.setBranch<vector<int>>          ("Common_fatjet_WP_MD", vvv.Common_fatjet_WP_MD());            // WP: 0: VLoose (5%), 1: Loose (2.5%), 2: Medium (1%), 3: Tight (0.5%)
    ana.tx.setBranch<vector<int>>          ("Common_fatjet_WP_antimasscut", vvv.Common_fatjet_WP_antimasscut());// WP: 0: VLoose (5%), 1: Loose (2.5%), 2: Medium (1%), 3: Tight (0.5%)
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_SFVLoose", vvv.Common_fatjet_SFVLoose());      // single fatjet SF
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_SFLoose", vvv.Common_fatjet_SFLoose());       // single fatjet SF
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_SFMedium", vvv.Common_fatjet_SFMedium());      // single fatjet SF
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_SFTight", vvv.Common_fatjet_SFTight());       // single fatjet SF
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_SFdnVLoose", vvv.Common_fatjet_SFdnVLoose());    // single fatjet SF
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_SFdnLoose", vvv.Common_fatjet_SFdnLoose());     // single fatjet SF
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_SFdnMedium", vvv.Common_fatjet_SFdnMedium());    // single fatjet SF
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_SFdnTight", vvv.Common_fatjet_SFdnTight());     // single fatjet SF
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_SFupVLoose", vvv.Common_fatjet_SFupVLoose());    // single fatjet SF
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_SFupLoose", vvv.Common_fatjet_SFupLoose());     // single fatjet SF
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_SFupMedium", vvv.Common_fatjet_SFupMedium());    // single fatjet SF
    ana.tx.setBranch<vector<float>>        ("Common_fatjet_SFupTight", vvv.Common_fatjet_SFupTight());     // single fatjet SF
    ana.tx.setBranch<float>        ("Common_eventweight_fatjet_SFVLoose", vvv.Common_eventweight_fatjet_SFVLoose());      // event fatjet SF
    ana.tx.setBranch<float>        ("Common_eventweight_fatjet_SFLoose", vvv.Common_eventweight_fatjet_SFLoose());       // event fatjet SF
    ana.tx.setBranch<float>        ("Common_eventweight_fatjet_SFMedium", vvv.Common_eventweight_fatjet_SFMedium());      // event fatjet SF
    ana.tx.setBranch<float>        ("Common_eventweight_fatjet_SFTight", vvv.Common_eventweight_fatjet_SFTight());       // event fatjet SF
    ana.tx.setBranch<float>        ("Common_eventweight_fatjet_SFdnVLoose", vvv.Common_eventweight_fatjet_SFdnVLoose());    // event fatjet SF
    ana.tx.setBranch<float>        ("Common_eventweight_fatjet_SFdnLoose", vvv.Common_eventweight_fatjet_SFdnLoose());     // event fatjet SF
    ana.tx.setBranch<float>        ("Common_eventweight_fatjet_SFdnMedium", vvv.Common_eventweight_fatjet_SFdnMedium());    // event fatjet SF
    ana.tx.setBranch<float>        ("Common_eventweight_fatjet_SFdnTight", vvv.Common_eventweight_fatjet_SFdnTight());     // event fatjet SF
    ana.tx.setBranch<float>        ("Common_eventweight_fatjet_SFupVLoose", vvv.Common_eventweight_fatjet_SFupVLoose());    // event fatjet SF
    ana.tx.setBranch<float>        ("Common_eventweight_fatjet_SFupLoose", vvv.Common_eventweight_fatjet_SFupLoose());     // event fatjet SF
    ana.tx.setBranch<float>        ("Common_eventweight_fatjet_SFupMedium", vvv.Common_eventweight_fatjet_SFupMedium());    // event fatjet SF
    ana.tx.setBranch<float>        ("Common_eventweight_fatjet_SFupTight", vvv.Common_eventweight_fatjet_SFupTight());     // event fatjet SF

    // The n-loose b-tagged jets
    ana.tx.setBranch<int>                  ("Common_nb_loose", vvv.Common_nb_loose());    // DeepFlav-B loose nb
    ana.tx.setBranch<int>                  ("Common_nb_medium", vvv.Common_nb_medium());   // DeepFlav-B medium nb
    ana.tx.setBranch<int>                  ("Common_nb_tight", vvv.Common_nb_tight());    // DeepFlav-B tight nb
    if(ana.systematicVariation){
        ana.tx.setBranch<int>("Common_nb_loose_jesAbsoluteStatup", vvv.Common_nb_loose_jesAbsoluteStatup());
        ana.tx.setBranch<int>("Common_nb_loose_jesAbsoluteStatdn", vvv.Common_nb_loose_jesAbsoluteStatdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesAbsoluteScaleup", vvv.Common_nb_loose_jesAbsoluteScaleup());            
        ana.tx.setBranch<int>("Common_nb_loose_jesAbsoluteScaledn", vvv.Common_nb_loose_jesAbsoluteScaledn());
        ana.tx.setBranch<int>("Common_nb_loose_jesAbsoluteMPFBiasup", vvv.Common_nb_loose_jesAbsoluteMPFBiasup());
        ana.tx.setBranch<int>("Common_nb_loose_jesAbsoluteMPFBiasdn", vvv.Common_nb_loose_jesAbsoluteMPFBiasdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesFragmentationup", vvv.Common_nb_loose_jesFragmentationup());
        ana.tx.setBranch<int>("Common_nb_loose_jesFragmentationdn", vvv.Common_nb_loose_jesFragmentationdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesSinglePionECALup", vvv.Common_nb_loose_jesSinglePionECALup());
        ana.tx.setBranch<int>("Common_nb_loose_jesSinglePionECALdn", vvv.Common_nb_loose_jesSinglePionECALdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesSinglePionHCALup", vvv.Common_nb_loose_jesSinglePionHCALup());
        ana.tx.setBranch<int>("Common_nb_loose_jesSinglePionHCALdn", vvv.Common_nb_loose_jesSinglePionHCALdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesFlavorQCDup", vvv.Common_nb_loose_jesFlavorQCDup());
        ana.tx.setBranch<int>("Common_nb_loose_jesFlavorQCDdn", vvv.Common_nb_loose_jesFlavorQCDdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesTimePtEtaup", vvv.Common_nb_loose_jesTimePtEtaup());
        ana.tx.setBranch<int>("Common_nb_loose_jesTimePtEtadn", vvv.Common_nb_loose_jesTimePtEtadn());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeJEREC1up", vvv.Common_nb_loose_jesRelativeJEREC1up());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeJEREC1dn", vvv.Common_nb_loose_jesRelativeJEREC1dn());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeJEREC2up", vvv.Common_nb_loose_jesRelativeJEREC2up());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeJEREC2dn", vvv.Common_nb_loose_jesRelativeJEREC2dn());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeJERHFup", vvv.Common_nb_loose_jesRelativeJERHFup());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeJERHFdn", vvv.Common_nb_loose_jesRelativeJERHFdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtBBup", vvv.Common_nb_loose_jesRelativePtBBup());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtBBdn", vvv.Common_nb_loose_jesRelativePtBBdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtEC1up", vvv.Common_nb_loose_jesRelativePtEC1up());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtEC1dn", vvv.Common_nb_loose_jesRelativePtEC1dn());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtEC2up", vvv.Common_nb_loose_jesRelativePtEC2up());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtEC2dn", vvv.Common_nb_loose_jesRelativePtEC2dn());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtHFup", vvv.Common_nb_loose_jesRelativePtHFup());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativePtHFdn", vvv.Common_nb_loose_jesRelativePtHFdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeBalup", vvv.Common_nb_loose_jesRelativeBalup());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeBaldn", vvv.Common_nb_loose_jesRelativeBaldn());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeSampleup", vvv.Common_nb_loose_jesRelativeSampleup());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeSampledn", vvv.Common_nb_loose_jesRelativeSampledn());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeFSRup", vvv.Common_nb_loose_jesRelativeFSRup());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeFSRdn", vvv.Common_nb_loose_jesRelativeFSRdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeStatFSRup", vvv.Common_nb_loose_jesRelativeStatFSRup());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeStatFSRdn", vvv.Common_nb_loose_jesRelativeStatFSRdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeStatECup", vvv.Common_nb_loose_jesRelativeStatECup());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeStatECdn", vvv.Common_nb_loose_jesRelativeStatECdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeStatHFup", vvv.Common_nb_loose_jesRelativeStatHFup());
        ana.tx.setBranch<int>("Common_nb_loose_jesRelativeStatHFdn", vvv.Common_nb_loose_jesRelativeStatHFdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpDataMCup", vvv.Common_nb_loose_jesPileUpDataMCup());
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpDataMCdn", vvv.Common_nb_loose_jesPileUpDataMCdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtRefup", vvv.Common_nb_loose_jesPileUpPtRefup());
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtRefdn", vvv.Common_nb_loose_jesPileUpPtRefdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtBBup", vvv.Common_nb_loose_jesPileUpPtBBup());
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtBBdn", vvv.Common_nb_loose_jesPileUpPtBBdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtEC1up", vvv.Common_nb_loose_jesPileUpPtEC1up());
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtEC1dn", vvv.Common_nb_loose_jesPileUpPtEC1dn());
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtEC2up", vvv.Common_nb_loose_jesPileUpPtEC2up());
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtEC2dn", vvv.Common_nb_loose_jesPileUpPtEC2dn());
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtHFup", vvv.Common_nb_loose_jesPileUpPtHFup());
        ana.tx.setBranch<int>("Common_nb_loose_jesPileUpPtHFdn", vvv.Common_nb_loose_jesPileUpPtHFdn());
        ana.tx.setBranch<int>("Common_nb_loose_jesup", vvv.Common_nb_loose_jesup());
        ana.tx.setBranch<int>("Common_nb_loose_jesdn", vvv.Common_nb_loose_jesdn());
        ana.tx.setBranch<int>("Common_nb_loose_jerup", vvv.Common_nb_loose_jerup());
        ana.tx.setBranch<int>("Common_nb_loose_jerdn", vvv.Common_nb_loose_jerdn());

        ana.tx.setBranch<int>("Common_nb_medium_jesAbsoluteStatup", vvv.Common_nb_medium_jesAbsoluteStatup());
        ana.tx.setBranch<int>("Common_nb_medium_jesAbsoluteStatdn", vvv.Common_nb_medium_jesAbsoluteStatdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesAbsoluteScaleup", vvv.Common_nb_medium_jesAbsoluteScaleup());            
        ana.tx.setBranch<int>("Common_nb_medium_jesAbsoluteScaledn", vvv.Common_nb_medium_jesAbsoluteScaledn());
        ana.tx.setBranch<int>("Common_nb_medium_jesAbsoluteMPFBiasup", vvv.Common_nb_medium_jesAbsoluteMPFBiasup());
        ana.tx.setBranch<int>("Common_nb_medium_jesAbsoluteMPFBiasdn", vvv.Common_nb_medium_jesAbsoluteMPFBiasdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesFragmentationup", vvv.Common_nb_medium_jesFragmentationup());
        ana.tx.setBranch<int>("Common_nb_medium_jesFragmentationdn", vvv.Common_nb_medium_jesFragmentationdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesSinglePionECALup", vvv.Common_nb_medium_jesSinglePionECALup());
        ana.tx.setBranch<int>("Common_nb_medium_jesSinglePionECALdn", vvv.Common_nb_medium_jesSinglePionECALdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesSinglePionHCALup", vvv.Common_nb_medium_jesSinglePionHCALup());
        ana.tx.setBranch<int>("Common_nb_medium_jesSinglePionHCALdn", vvv.Common_nb_medium_jesSinglePionHCALdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesFlavorQCDup", vvv.Common_nb_medium_jesFlavorQCDup());
        ana.tx.setBranch<int>("Common_nb_medium_jesFlavorQCDdn", vvv.Common_nb_medium_jesFlavorQCDdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesTimePtEtaup", vvv.Common_nb_medium_jesTimePtEtaup());
        ana.tx.setBranch<int>("Common_nb_medium_jesTimePtEtadn", vvv.Common_nb_medium_jesTimePtEtadn());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeJEREC1up", vvv.Common_nb_medium_jesRelativeJEREC1up());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeJEREC1dn", vvv.Common_nb_medium_jesRelativeJEREC1dn());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeJEREC2up", vvv.Common_nb_medium_jesRelativeJEREC2up());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeJEREC2dn", vvv.Common_nb_medium_jesRelativeJEREC2dn());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeJERHFup", vvv.Common_nb_medium_jesRelativeJERHFup());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeJERHFdn", vvv.Common_nb_medium_jesRelativeJERHFdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtBBup", vvv.Common_nb_medium_jesRelativePtBBup());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtBBdn", vvv.Common_nb_medium_jesRelativePtBBdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtEC1up", vvv.Common_nb_medium_jesRelativePtEC1up());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtEC1dn", vvv.Common_nb_medium_jesRelativePtEC1dn());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtEC2up", vvv.Common_nb_medium_jesRelativePtEC2up());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtEC2dn", vvv.Common_nb_medium_jesRelativePtEC2dn());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtHFup", vvv.Common_nb_medium_jesRelativePtHFup());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativePtHFdn", vvv.Common_nb_medium_jesRelativePtHFdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeBalup", vvv.Common_nb_medium_jesRelativeBalup());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeBaldn", vvv.Common_nb_medium_jesRelativeBaldn());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeSampleup", vvv.Common_nb_medium_jesRelativeSampleup());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeSampledn", vvv.Common_nb_medium_jesRelativeSampledn());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeFSRup", vvv.Common_nb_medium_jesRelativeFSRup());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeFSRdn", vvv.Common_nb_medium_jesRelativeFSRdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeStatFSRup", vvv.Common_nb_medium_jesRelativeStatFSRup());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeStatFSRdn", vvv.Common_nb_medium_jesRelativeStatFSRdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeStatECup", vvv.Common_nb_medium_jesRelativeStatECup());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeStatECdn", vvv.Common_nb_medium_jesRelativeStatECdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeStatHFup", vvv.Common_nb_medium_jesRelativeStatHFup());
        ana.tx.setBranch<int>("Common_nb_medium_jesRelativeStatHFdn", vvv.Common_nb_medium_jesRelativeStatHFdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpDataMCup", vvv.Common_nb_medium_jesPileUpDataMCup());
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpDataMCdn", vvv.Common_nb_medium_jesPileUpDataMCdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtRefup", vvv.Common_nb_medium_jesPileUpPtRefup());
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtRefdn", vvv.Common_nb_medium_jesPileUpPtRefdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtBBup", vvv.Common_nb_medium_jesPileUpPtBBup());
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtBBdn", vvv.Common_nb_medium_jesPileUpPtBBdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtEC1up", vvv.Common_nb_medium_jesPileUpPtEC1up());
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtEC1dn", vvv.Common_nb_medium_jesPileUpPtEC1dn());
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtEC2up", vvv.Common_nb_medium_jesPileUpPtEC2up());
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtEC2dn", vvv.Common_nb_medium_jesPileUpPtEC2dn());
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtHFup", vvv.Common_nb_medium_jesPileUpPtHFup());
        ana.tx.setBranch<int>("Common_nb_medium_jesPileUpPtHFdn", vvv.Common_nb_medium_jesPileUpPtHFdn());
        ana.tx.setBranch<int>("Common_nb_medium_jesup", vvv.Common_nb_medium_jesup());
        ana.tx.setBranch<int>("Common_nb_medium_jesdn", vvv.Common_nb_medium_jesdn());        
        ana.tx.setBranch<int>("Common_nb_medium_jerup", vvv.Common_nb_medium_jerup());
        ana.tx.setBranch<int>("Common_nb_medium_jerdn", vvv.Common_nb_medium_jerdn());

        ana.tx.setBranch<int>("Common_nb_tight_jesAbsoluteStatup", vvv.Common_nb_tight_jesAbsoluteStatup());
        ana.tx.setBranch<int>("Common_nb_tight_jesAbsoluteStatdn", vvv.Common_nb_tight_jesAbsoluteStatdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesAbsoluteScaleup", vvv.Common_nb_tight_jesAbsoluteScaleup());            
        ana.tx.setBranch<int>("Common_nb_tight_jesAbsoluteScaledn", vvv.Common_nb_tight_jesAbsoluteScaledn());
        ana.tx.setBranch<int>("Common_nb_tight_jesAbsoluteMPFBiasup", vvv.Common_nb_tight_jesAbsoluteMPFBiasup());
        ana.tx.setBranch<int>("Common_nb_tight_jesAbsoluteMPFBiasdn", vvv.Common_nb_tight_jesAbsoluteMPFBiasdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesFragmentationup", vvv.Common_nb_tight_jesFragmentationup());
        ana.tx.setBranch<int>("Common_nb_tight_jesFragmentationdn", vvv.Common_nb_tight_jesFragmentationdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesSinglePionECALup", vvv.Common_nb_tight_jesSinglePionECALup());
        ana.tx.setBranch<int>("Common_nb_tight_jesSinglePionECALdn", vvv.Common_nb_tight_jesSinglePionECALdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesSinglePionHCALup", vvv.Common_nb_tight_jesSinglePionHCALup());
        ana.tx.setBranch<int>("Common_nb_tight_jesSinglePionHCALdn", vvv.Common_nb_tight_jesSinglePionHCALdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesFlavorQCDup", vvv.Common_nb_tight_jesFlavorQCDup());
        ana.tx.setBranch<int>("Common_nb_tight_jesFlavorQCDdn", vvv.Common_nb_tight_jesFlavorQCDdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesTimePtEtaup", vvv.Common_nb_tight_jesTimePtEtaup());
        ana.tx.setBranch<int>("Common_nb_tight_jesTimePtEtadn", vvv.Common_nb_tight_jesTimePtEtadn());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeJEREC1up", vvv.Common_nb_tight_jesRelativeJEREC1up());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeJEREC1dn", vvv.Common_nb_tight_jesRelativeJEREC1dn());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeJEREC2up", vvv.Common_nb_tight_jesRelativeJEREC2up());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeJEREC2dn", vvv.Common_nb_tight_jesRelativeJEREC2dn());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeJERHFup", vvv.Common_nb_tight_jesRelativeJERHFup());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeJERHFdn", vvv.Common_nb_tight_jesRelativeJERHFdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtBBup", vvv.Common_nb_tight_jesRelativePtBBup());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtBBdn", vvv.Common_nb_tight_jesRelativePtBBdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtEC1up", vvv.Common_nb_tight_jesRelativePtEC1up());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtEC1dn", vvv.Common_nb_tight_jesRelativePtEC1dn());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtEC2up", vvv.Common_nb_tight_jesRelativePtEC2up());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtEC2dn", vvv.Common_nb_tight_jesRelativePtEC2dn());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtHFup", vvv.Common_nb_tight_jesRelativePtHFup());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativePtHFdn", vvv.Common_nb_tight_jesRelativePtHFdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeBalup", vvv.Common_nb_tight_jesRelativeBalup());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeBaldn", vvv.Common_nb_tight_jesRelativeBaldn());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeSampleup", vvv.Common_nb_tight_jesRelativeSampleup());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeSampledn", vvv.Common_nb_tight_jesRelativeSampledn());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeFSRup", vvv.Common_nb_tight_jesRelativeFSRup());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeFSRdn", vvv.Common_nb_tight_jesRelativeFSRdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeStatFSRup", vvv.Common_nb_tight_jesRelativeStatFSRup());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeStatFSRdn", vvv.Common_nb_tight_jesRelativeStatFSRdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeStatECup", vvv.Common_nb_tight_jesRelativeStatECup());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeStatECdn", vvv.Common_nb_tight_jesRelativeStatECdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeStatHFup", vvv.Common_nb_tight_jesRelativeStatHFup());
        ana.tx.setBranch<int>("Common_nb_tight_jesRelativeStatHFdn", vvv.Common_nb_tight_jesRelativeStatHFdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpDataMCup", vvv.Common_nb_tight_jesPileUpDataMCup());
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpDataMCdn", vvv.Common_nb_tight_jesPileUpDataMCdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtRefup", vvv.Common_nb_tight_jesPileUpPtRefup());
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtRefdn", vvv.Common_nb_tight_jesPileUpPtRefdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtBBup", vvv.Common_nb_tight_jesPileUpPtBBup());
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtBBdn", vvv.Common_nb_tight_jesPileUpPtBBdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtEC1up", vvv.Common_nb_tight_jesPileUpPtEC1up());
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtEC1dn", vvv.Common_nb_tight_jesPileUpPtEC1dn());
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtEC2up", vvv.Common_nb_tight_jesPileUpPtEC2up());
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtEC2dn", vvv.Common_nb_tight_jesPileUpPtEC2dn());
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtHFup", vvv.Common_nb_tight_jesPileUpPtHFup());
        ana.tx.setBranch<int>("Common_nb_tight_jesPileUpPtHFdn", vvv.Common_nb_tight_jesPileUpPtHFdn());
        ana.tx.setBranch<int>("Common_nb_tight_jesup", vvv.Common_nb_tight_jesup());
        ana.tx.setBranch<int>("Common_nb_tight_jesdn", vvv.Common_nb_tight_jesdn());
        ana.tx.setBranch<int>("Common_nb_tight_jerup", vvv.Common_nb_tight_jerup());
        ana.tx.setBranch<int>("Common_nb_tight_jerdn", vvv.Common_nb_tight_jerdn());
    }


    // The gen level information
    ana.tx.setBranch<vector<int>>          ("Common_gen_idx", vvv.Common_gen_idx());        // Selected gen-particle idx in NanoAOD
    ana.tx.setBranch<vector<int>>          ("Common_gen_mother_idx", vvv.Common_gen_mother_idx()); // Selected gen-particle mother idx in NanoAOD
    ana.tx.setBranch<vector<int>>          ("Common_gen_mother_id", vvv.Common_gen_mother_id());  // Selected gen-particle mother id in NanoAOD
    ana.tx.setBranch<vector<int>>          ("Common_gen_pdgid", vvv.Common_gen_pdgid());      // Selected gen-particle pdgids
    ana.tx.setBranch<vector<LorentzVector>>("Common_gen_p4s", vvv.Common_gen_p4s());        // Selected gen-particle p4s

    ana.tx.setBranch<vector<int>>          ("Common_gen_vvvdecay_idx", vvv.Common_gen_vvvdecay_idx());          // Selected gen-particle of vvv decays idx in NanoAOD
    ana.tx.setBranch<vector<int>>          ("Common_gen_vvvdecay_mother_idx", vvv.Common_gen_vvvdecay_mother_idx());   // Selected gen-particle of vvv decays mother idx in NanoAOD
    ana.tx.setBranch<vector<int>>          ("Common_gen_vvvdecay_mother_id", vvv.Common_gen_vvvdecay_mother_id());    // Selected gen-particle of vvv decays mother id in NanoAOD
    ana.tx.setBranch<vector<int>>          ("Common_gen_vvvdecay_pdgid", vvv.Common_gen_vvvdecay_pdgid());        // Selected gen-particle of vvv decays pdgids
    ana.tx.setBranch<vector<LorentzVector>>("Common_gen_vvvdecay_p4s", vvv.Common_gen_vvvdecay_p4s());          // Selected gen-particle of vvv decays p4s
    ana.tx.setBranch<vector<int>>          ("Common_gen_vvvdecay_taudecayid", vvv.Common_gen_vvvdecay_taudecayid());   // If gentau - flag the decay of the gentau

    ana.tx.setBranch<int>                  ("Common_n_W", vvv.Common_n_W());
    ana.tx.setBranch<int>                  ("Common_n_Z", vvv.Common_n_Z());
    ana.tx.setBranch<int>                  ("Common_n_lep_Z", vvv.Common_n_lep_Z());
    ana.tx.setBranch<int>                  ("Common_n_leptau_Z", vvv.Common_n_leptau_Z());
    ana.tx.setBranch<int>                  ("Common_n_hadtau_Z", vvv.Common_n_hadtau_Z());
    ana.tx.setBranch<int>                  ("Common_n_nu_Z", vvv.Common_n_nu_Z());
    ana.tx.setBranch<int>                  ("Common_n_b_Z", vvv.Common_n_b_Z());
    ana.tx.setBranch<int>                  ("Common_n_lep_W", vvv.Common_n_lep_W());
    ana.tx.setBranch<int>                  ("Common_n_leptau_W", vvv.Common_n_leptau_W());
    ana.tx.setBranch<int>                  ("Common_n_hadtau_W", vvv.Common_n_hadtau_W());
    ana.tx.setBranch<bool>                 ("Common_haslepWSS", vvv.Common_haslepWSS());  // includes leptonic tau decays

    ana.tx.setBranch<float>                ("Common_genHT", vvv.Common_genHT());       // Gen HT value for stitching HT-sliced samples
    ana.tx.setBranch<int>                  ("Common_gen_n_light_lep", vvv.Common_gen_n_light_lep()); // Gen value of how many light lepton exists

}
