#include "Begin.h"

void Begin()
{
    //==============================================
    // Begin:
    // This function gets called prior to the event looping.
    // This function gets called regardless of the looper mode
    //==============================================

    // Begin_Common is always called regardless of the category
    Begin_Common();

    // Then depending on the analysis mode, different "Begin" runs
    switch (ana.looperMode)
    {
        case AnalysisConfig::k4LepMET: Begin_4LepMET(); break;
        case AnalysisConfig::k4Lep2jet: Begin_4Lep2jet(); break;
        case AnalysisConfig::k3LepMET: Begin_3LepMET(); break;
        case AnalysisConfig::k3Lep2jet: Begin_3Lep2jet(); break;
        case AnalysisConfig::kOS4jet: Begin_OS4jet(); break;
        case AnalysisConfig::kOS2jet: Begin_OS2jet(); break;
        case AnalysisConfig::kSS2jet: Begin_SS2jet(); break;
        case AnalysisConfig::k1Lep4jet: Begin_1Lep4jet(); break;
        case AnalysisConfig::kallHad: Begin_allHad(); break;
        case AnalysisConfig::k1Lep2fatJets: Begin_1Lep2fatjet(); break;
    }
    RooUtil::Histograms h_systematic_uncertainties_type1;
    h_systematic_uncertainties_type1.addVecHistogram("systematic_variation",200, 0, 200, [&]() { 
        std::vector<float> rtn; 
        unsigned int i=0;
        for (i = 0; i < 33; ++i) rtn.push_back(i); 
        vector<float> pdf=ana.tx.getBranchLazy<vector<float>>("Common_event_PDF");
        for (unsigned int j = 0; j < pdf.size(); ++j){
            rtn.push_back(i);
            i++;
        }         
        return rtn;
    }, [&]() { 
        std::vector<float> rtn;
        //bin 1 for center value
        rtn.push_back(1);
        float c,up,dn;    
        //bin 2,3 for pileup weights                         
        c=ana.tx.getBranch<float>("Common_event_puWeight");
        up=ana.tx.getBranch<float>("Common_event_puWeightup");
        dn=ana.tx.getBranch<float>("Common_event_puWeightdn");
        rtn.push_back(up/c);
        rtn.push_back(dn/c);
        //bin 4,5 for prefire weights
        c=ana.tx.getBranch<float>("Common_event_prefireWeight");
        up=ana.tx.getBranch<float>("Common_event_prefireWeightup");
        dn=ana.tx.getBranch<float>("Common_event_prefireWeightdn");
        rtn.push_back(up/c);
        rtn.push_back(dn/c);
        //bin 6,7 for trigger weights
        c=ana.tx.getBranch<float>("Common_event_triggerWeight");
        up=ana.tx.getBranch<float>("Common_event_triggerWeightup");
        dn=ana.tx.getBranch<float>("Common_event_triggerWeightdn");
        rtn.push_back(up/c);
        rtn.push_back(dn/c);
        //bin 8-11 for tight lepton weights
        c=ana.tx.getBranch<float>("Common_event_lepSFTight");
        up=ana.tx.getBranch<float>("Common_event_lepSFelupTight");
        dn=ana.tx.getBranch<float>("Common_event_lepSFeldnTight");
        rtn.push_back(up/c);
        rtn.push_back(dn/c);        
        up=ana.tx.getBranch<float>("Common_event_lepSFmuupTight");
        dn=ana.tx.getBranch<float>("Common_event_lepSFmudnTight");
        rtn.push_back(up/c);
        rtn.push_back(dn/c);
        //bin 12-15 for veto lepton weights
        c=ana.tx.getBranch<float>("Common_event_lepSF");
        up=ana.tx.getBranch<float>("Common_event_lepSFelup");
        dn=ana.tx.getBranch<float>("Common_event_lepSFeldn");
        rtn.push_back(up/c);
        rtn.push_back(dn/c);
        up=ana.tx.getBranch<float>("Common_event_lepSFmuup");
        dn=ana.tx.getBranch<float>("Common_event_lepSFmudn");
        rtn.push_back(up/c);
        rtn.push_back(dn/c);
        //bin 16-21 for jet b-tagging weights        
        c=ana.tx.getBranch<float>("Common_event_tightBtagSF");
        up=ana.tx.getBranch<float>("Common_event_tightBtagSFup");
        dn=ana.tx.getBranch<float>("Common_event_tightBtagSFdn");
        rtn.push_back(up/c);
        rtn.push_back(dn/c);
        c=ana.tx.getBranch<float>("Common_event_mediumBtagSF");
        up=ana.tx.getBranch<float>("Common_event_mediumBtagSFup");
        dn=ana.tx.getBranch<float>("Common_event_mediumBtagSFdn");
        rtn.push_back(up/c);
        rtn.push_back(dn/c);
        c=ana.tx.getBranch<float>("Common_event_looseBtagSF");
        up=ana.tx.getBranch<float>("Common_event_looseBtagSFup");
        dn=ana.tx.getBranch<float>("Common_event_looseBtagSFdn");
        rtn.push_back(up/c);
        rtn.push_back(dn/c);
        //bin 22-27 for fatjet W-tagging weights        
        c=ana.tx.getBranch<float>("Common_eventweight_fatjet_MD_SFTight");
        up=ana.tx.getBranch<float>("Common_eventweight_fatjet_MD_SFupTight");
        dn=ana.tx.getBranch<float>("Common_eventweight_fatjet_MD_SFdnTight");
        rtn.push_back(up/c);
        rtn.push_back(dn/c);
        c=ana.tx.getBranch<float>("Common_eventweight_fatjet_MD_SFMedium");
        up=ana.tx.getBranch<float>("Common_eventweight_fatjet_MD_SFupMedium");
        dn=ana.tx.getBranch<float>("Common_eventweight_fatjet_MD_SFdnMedium");
        rtn.push_back(up/c);
        rtn.push_back(dn/c);
        c=ana.tx.getBranch<float>("Common_eventweight_fatjet_MD_SFLoose");
        up=ana.tx.getBranch<float>("Common_eventweight_fatjet_MD_SFupLoose");
        dn=ana.tx.getBranch<float>("Common_eventweight_fatjet_MD_SFdnLoose");
        rtn.push_back(up/c);
        rtn.push_back(dn/c);
        //bin 28-33 for QCD scale weights
        vector<float> qcd=ana.tx.getBranchLazy<vector<float>>("Common_event_QCDScale");
	if(qcd.size()==9){
		rtn.push_back(qcd.at(0));
		rtn.push_back(qcd.at(1));
		rtn.push_back(qcd.at(3));
		rtn.push_back(qcd.at(5));	
		rtn.push_back(qcd.at(7));
		rtn.push_back(qcd.at(8));
	}
	else if(qcd.size()==8){
		rtn.push_back(qcd.at(0));
		rtn.push_back(qcd.at(1));
		rtn.push_back(qcd.at(3));
		rtn.push_back(qcd.at(4));	
		rtn.push_back(qcd.at(6));
		rtn.push_back(qcd.at(7));
	}

	else{
		for(unsigned int i = 0; i < 6; ++i) rtn.push_back(1);
	}
        //bin 34-134 for pdf weights, 135,136 for alpha_s weights
        vector<float> pdf=ana.tx.getBranchLazy<vector<float>>("Common_event_PDF");
        for (unsigned int i = 0; i < pdf.size(); ++i){
            rtn.push_back(pdf.at(i));
        }         
        return rtn;
    });
    ana.cutflow.bookHistogramsForEndCuts(h_systematic_uncertainties_type1);

    // At this point, the variables, histograms, selections are all defined and booked.

    // Print cut structure
    ana.cutflow.printCuts();

}
