#include "Process_4LepMET.h"

void Process_4LepMET()
{
    Process_4LepMET_NanoAOD();
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

    // 1:1802:1801785
    // 1:2318:2317296
    // 1:2320:2319992
    // 1:2999:2998826

    if (nt.run() == 1 and nt.luminosityBlock() == 1802 and nt.event() == 1801785)
    {

        //for (unsigned int iel = 0; iel < nt.Electron_p4().size(); ++iel)
        //{
        //    if (not (nt.Electron_mvaFall17V2noIso_WPL()[iel])) continue;
        //    if (not (nt.Electron_pfRelIso03_all()[iel] < 0.4)) continue;
        //    if (not (nt.Electron_p4()[iel].pt()       > 10.)) continue;
        //    if (not (abs(nt.Electron_p4()[iel].eta()) < 2.5)) continue;
        //    if (abs(nt.Electron_p4()[iel].eta()) < 1.566 && abs(nt.Electron_p4()[iel].eta()) > 1.444) continue; 
        //}

        //for (unsigned int iel = 0; iel < nt.Electron_p4().size(); ++iel)
        //{
        //    // Selections
        //    if (not (nt.Electron_mvaFall17V2noIso_WPL()[iel])) continue;
        //    if (not (nt.Electron_pfRelIso03_all()[iel] < 0.4)) continue;
        //    if (not (nt.Electron_p4()[iel].pt()       > 10.)) continue;
        //    if (not (abs(nt.Electron_p4()[iel].eta()) < 2.5)) continue;
        //    if (abs(nt.Electron_p4()[iel].eta()) < 1.566 && abs(nt.Electron_p4()[iel].eta()) > 1.444) continue; 

        //    // If passed up to here add it to the index list
        //    ana.tx.pushbackToBranch<int>("Common_lep_idxs", iel);
        //    ana.tx.pushbackToBranch<int>("Common_lep_pdgid", nt.Electron_pdgId()[iel]);
        //    ana.tx.pushbackToBranch<LorentzVector>("Common_lep_p4", nt.Electron_p4()[iel]);
        //    ana.tx.pushbackToBranch<int>("Common_lep_tight", nt.Electron_mvaFall17V2Iso_WP80()[iel]);
        //    ana.tx.pushbackToBranch<float>("Common_lep_dxy", nt.Electron_dxy()[iel]);
        //    ana.tx.pushbackToBranch<float>("Common_lep_dz", nt.Electron_dz()[iel]);
        //    ana.tx.pushbackToBranch<float>("Common_lep_ip3d", nt.Electron_ip3d()[iel]);
        //    ana.tx.pushbackToBranch<float>("Common_lep_sip3d", nt.Electron_sip3d()[iel]);
        //    ana.tx.pushbackToBranch<int>  ("Common_lep_IsoID", -1);
        //    ana.tx.pushbackToBranch<float>("Common_lep_relIso03_all", nt.Electron_pfRelIso03_all()[iel]); // Pt sorted selected lepton isolation reliso03_all (electrons and muons together)
        //    int ID = 0;
        //    ID |= nt.Electron_mvaFall17V2noIso_WPL()[iel] << 0;
        //    ID |= nt.Electron_mvaFall17V2noIso_WP90()[iel] << 1;
        //    ID |= nt.Electron_mvaFall17V2noIso_WP80()[iel] << 2;
        //    ID |= nt.Electron_mvaFall17V2Iso_WPL()[iel] << 3;
        //    ID |= nt.Electron_mvaFall17V2Iso_WP90()[iel] << 4;
        //    ID |= nt.Electron_mvaFall17V2Iso_WP80()[iel] << 5;
        //    ana.tx.pushbackToBranch<int>("Common_lep_ID", ID);
        //    //---------
        //    // bool istight = nt.Electron_mvaFall17V2Iso_WP80()[iel];
        //    float pt = std::min(std::max(nt.Electron_p4()[iel].pt(), 10.01f), 499.9f);
        //    float eta = std::min(std::max(nt.Electron_p4()[iel].eta(), -2.499f), 2.499f);
        //    float sf = (pt > 20 ? ana.electronRECOSFgt20->eval(eta, pt) : ana.electronRECOSFlt20->eval(eta, pt)) * ana.electronMVAID90SF->eval(eta, pt);
        //    lepSFc  *= sf;
        //    lepSFum *= sf;
        //    lepSFdm *= sf;
        //    ana.tx.pushbackToBranch<float>("Common_lep_SF",        sf);
        //    sf       = (pt > 20 ? ana.electronRECOSFgt20->eval_up(eta, pt) : ana.electronRECOSFlt20->eval_up(eta, pt)) * ana.electronMVAID90SF->eval_up(eta, pt);
        //    lepSFue *= sf;
        //    ana.tx.pushbackToBranch<float>("Common_lep_SFup",      sf);
        //    sf       = (pt > 20 ? ana.electronRECOSFgt20->eval_down(eta, pt) : ana.electronRECOSFlt20->eval_down(eta, pt)) * ana.electronMVAID90SF->eval_down(eta, pt);
        //    lepSFde *= sf;
        //    ana.tx.pushbackToBranch<float>("Common_lep_SFdn",      sf);
        //    sf       = (pt > 20 ? ana.electronRECOSFgt20->eval(eta, pt) : ana.electronRECOSFlt20->eval(eta, pt)) * ana.electronMVAID80SF->eval(eta, pt);
        //    lepSFcTight  *= sf;
        //    lepSFumTight *= sf;
        //    lepSFdmTight *= sf;
        //    ana.tx.pushbackToBranch<float>("Common_lep_SFTight",   sf);
        //    sf       = (pt > 20 ? ana.electronRECOSFgt20->eval_up(eta, pt) : ana.electronRECOSFlt20->eval_up(eta, pt)) * ana.electronMVAID80SF->eval_up(eta, pt);
        //    lepSFueTight *= sf;
        //    ana.tx.pushbackToBranch<float>("Common_lep_SFupTight", sf);
        //    sf       = (pt > 20 ? ana.electronRECOSFgt20->eval_down(eta, pt) : ana.electronRECOSFlt20->eval_down(eta, pt)) * ana.electronMVAID80SF->eval_down(eta, pt);
        //    lepSFdeTight *= sf;
        //    ana.tx.pushbackToBranch<float>("Common_lep_SFdnTight", sf);

        //    //---------
        //    // float sf = ana.leptonscalefactors.leptonSF(nt.isData(),nt.year(),11,nt.Electron_p4()[iel].eta(),nt.Electron_p4()[iel].pt(),nt.event(), 0);
        //    // lepSFc  *= sf;
        //    // lepSFum *= sf;
        //    // lepSFdm *= sf;
        //    // ana.tx.pushbackToBranch<float>("Common_lep_SF",        sf);
        //    // ana.tx.pushbackToBranch<float>("Common_lep_SFTight",   sf);
        //    // sf       = ana.leptonscalefactors.leptonSF(nt.isData(),nt.year(),11,nt.Electron_p4()[iel].eta(),nt.Electron_p4()[iel].pt(),nt.event(),+1);
        //    // lepSFue *= sf;
        //    // ana.tx.pushbackToBranch<float>("Common_lep_SFup",      sf);
        //    // ana.tx.pushbackToBranch<float>("Common_lep_SFupTight", sf);
        //    // sf       = ana.leptonscalefactors.leptonSF(nt.isData(),nt.year(),11,nt.Electron_p4()[iel].eta(),nt.Electron_p4()[iel].pt(),nt.event(),-1);
        //    // lepSFde *= sf;
        //    // ana.tx.pushbackToBranch<float>("Common_lep_SFdn",      sf);
        //    // ana.tx.pushbackToBranch<float>("Common_lep_SFdnTight", sf);
        //}
    }
}

void PostProcess_4LepMET()
{
    //==============================================
    // Process_4LepMET:
    // This function gets called during the event looping after the event processing has been carried out
    // This is where one may decide to write out TTree
    //==============================================

    // If it passes the preselection than decide to write the TTree
    //std::cout << "Debug Process_4LepMET 1" << std::endl;    

    if (ana.cutflow.getCut("Cut_4LepMET_Preselection").pass)
    {
        ana.tx.fill();
    }

}
