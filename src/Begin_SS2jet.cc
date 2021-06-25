#include "Begin_SS2jet.h"

bool SS2jet_SS_filter(){
    cout<<"same sign filtered"<<endl;
    ana.cutflow.getCut("CommonCut");
    ana.cutflow.addCutToLastActiveCut("SS2jet_TriggerCut",
                                        [&](){
                                        bool trig_ee=   ana.tx.getBranch<bool>("Common_HLT_DoubleEl");
                                        bool trig_emu=  ana.tx.getBranch<bool>("Common_HLT_MuEG");
                                        bool trig_mumu= ana.tx.getBranch<bool>("Common_HLT_DoubleMu");
                                        return(trig_ee || trig_emu || trig_mumu);
                                        },UNITY);
    ana.cutflow.addCutToLastActiveCut("SS2jet_LeptonCut",
                                        [&](){
                                        int lep_tight=0;
                                        int lep_SS=1;

                                        vector<int>     pdgid=  ana.tx.getBranchLazy<vector<int>        >("Common_lep_pdgid");
                                        vector<int>     tight=  ana.tx.getBranchLazy<vector<int>        >("Common_lep_tight");
                                        for(unsigned int ilep=0;ilep<tight.size();ilep++){
                                                lep_SS*=pdgid.at(ilep);
                                                if(tight.at(ilep)) lep_tight++;
                                        }
                                        if(pdgid.size()==2 && lep_SS>0) return true;
                                        return false;
                                        },UNITY);

    ana.cutflow.addCutToLastActiveCut("SS2jet_FatJetCut",
                                        [&](){
                                        int fatjet_tight=0;
                                        vector<LorentzVector>     p4=  ana.tx.getBranchLazy<vector<LorentzVector>        >("Common_fatjet_p4");
                                        for(unsigned int ifatjet=0;ifatjet<p4.size();ifatjet++){
                                                if(p4.at(ifatjet).pt()>200.) fatjet_tight++;
                                        }
                                        if(fatjet_tight>=1) return true;
                                        return false;
                                        },UNITY);

    return true; 
}
bool SS2jet_SR(){
    cout<<"The signal region for SS2jet channel"<<endl;
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");
    //ana.cutflow.addCutToLastActiveCut("Cut_SS2jet_Preselection", [&]() { return ana.tx.getBranch<LorentzVector>("SS2jet_LVVar1").pt() > 25.;}, [&]() { return ana.tx.getBranch<float>("SS2jet_floatVar1"); } );
    //This cut is to get the events with exact two same sign leptons with no additional loose lepton
    ana.cutflow.addCutToLastActiveCut("SS2jet_TriggerCut",
					[&](){
					bool trig_ee=	ana.tx.getBranch<bool>("Common_HLT_DoubleEl");
					bool trig_emu=  ana.tx.getBranch<bool>("Common_HLT_MuEG");
					bool trig_mumu=	ana.tx.getBranch<bool>("Common_HLT_DoubleMu");
					return(trig_ee || trig_emu || trig_mumu);
					},UNITY);
    ana.cutflow.addCutToLastActiveCut("SS2jet_LeptonCut",
					[&](){
					int lep_tight=0;
					int lep_SS=1;

					vector<int>	pdgid=	ana.tx.getBranchLazy<vector<int>	>("Common_lep_pdgid");
					vector<int>	tight=	ana.tx.getBranchLazy<vector<int>	>("Common_lep_tight");
					for(unsigned int ilep=0;ilep<tight.size();ilep++){
						lep_SS*=pdgid.at(ilep);
						if(tight.at(ilep)) lep_tight++;
					}
					if(lep_tight==2 && pdgid.size()==2 && lep_SS>0) return true;
					return false;
					},UNITY);
    //This cut is to get the events with no b-tagged jet
    ana.cutflow.addCutToLastActiveCut("SS2jet_bCut",
					[&](){
					int		nb=	ana.tx.getBranch<int	>("Common_nb_medium");
					if(nb==0) return true;
					return false;
					},UNITY);
    //This cut is to get the events with 1 fat jet
    ana.cutflow.addCutToLastActiveCut("SS2jet_FatJetCut",
					[&](){
					int fatjet_tight=0;
					vector<LorentzVector>     p4=  ana.tx.getBranchLazy<vector<LorentzVector>        >("Common_fatjet_p4");	
					for(unsigned int ifatjet=0;ifatjet<p4.size();ifatjet++){
						if(p4.at(ifatjet).pt()>200.) fatjet_tight++;
					}
					if(fatjet_tight>=1) return true;
					return false;
					},UNITY);
    return true;
}

bool SS2jet_CR_WZ(){
    cout<<"The WZ control region for SS2jet channel"<<endl;

    return false;
}

bool SS2jet_CR_ttbar(){
    cout<<"The ttbar control region for SS2jet channel"<<endl;
    // CommonCut will contain selections that should be common to all categories, starting from this cut, add cuts for this category of the analysis.
    ana.cutflow.getCut("CommonCut");
    //ana.cutflow.addCutToLastActiveCut("Cut_SS2jet_Preselection", [&]() { return ana.tx.getBranch<LorentzVector>("SS2jet_LVVar1").pt() > 25.;}, [&]() { return ana.tx.getBranch<float>("SS2jet_floatVar1"); } );
    //This cut is to get the events with exact two same sign leptons with no additional loose lepton
    ana.cutflow.addCutToLastActiveCut("SS2jet_LeptonCut",
					[&](){
					int lep_tight=0;

					for(unsigned int iel=0;iel<nt.Electron_p4().size();iel++){
        					if(!(nt.Electron_mvaFall17V2Iso_WP80().at(iel))) continue;
        					if(!(nt.Electron_p4().at(iel).pt()>25)) continue;
        					if(!(fabs(nt.Electron_p4().at(iel).eta())<2.5)) continue;
        					if(!(nt.Electron_ip3d().at(iel)<0.01)) continue;
        					if(!(fabs(nt.Electron_dxy().at(iel))<0.05)) continue;
        					if(!(fabs(nt.Electron_dz().at(iel))<0.1)) continue;
        					if(fabs(nt.Electron_p4().at(iel).eta())<1.556 && fabs(nt.Electron_p4().at(iel).eta()>1.442)) continue;
						lep_tight++;
					}

					for(unsigned int imu=0;imu<nt.Muon_p4().size();imu++){
        					if(!(nt.Muon_mediumId().at(imu))) continue;
        					if(!(nt.Muon_p4().at(imu).pt()>25)) continue;
        					if(!(fabs(nt.Muon_p4().at(imu).eta())<2.4)) continue;
        					if(!(nt.Muon_ip3d().at(imu)<0.015)) continue;
        					if(!(nt.Muon_sip3d().at(imu)<4)) continue;
        					if(!(fabs(nt.Muon_dxy().at(imu))<0.05)) continue;
        					if(!(fabs(nt.Muon_dz().at(imu))<0.1)) continue;
						if(!(nt.Muon_pfRelIso04_all().at(imu)<0.04)) continue;
        					//if(!(nt.Muon_pfRelIso03_all().at(imu)<0.04)) continue;
        					lep_tight++;
					}

					vector<int>	pdgid=	ana.tx.getBranchLazy<vector<int>	>("Common_lep_pdgid");

					if(lep_tight==2 && pdgid.size()==2 && pdgid.at(0)*pdgid.at(1)>0) return true;
					return false;
					},UNITY); 
    //This cut is to get the events with at least 1 b-tagged jet
    ana.cutflow.addCutToLastActiveCut("SS2jet_bCut",
					[&](){
					int		nb=	ana.tx.getBranchLazy<int	>("Common_nb_medium");
					if(nb!=0) return true;
					return false;
					},UNITY);
    //This cut is to get the events with excat 1 fat jet
    ana.cutflow.addCutToLastActiveCut("SS2jet_FatJetCut",
					[&](){
					vector<int>     idx=  ana.tx.getBranchLazy<vector<int>        >("Common_fatjet_idxs");	
					if(idx.size()==1) return true;
					return false;
					},UNITY);
    return true;
}
 
void Begin_SS2jet()
{
    //==============================================
    // Begin_SS2jet:
    // This function gets called prior to the event looping.
    // This is where one declares variables, histograms, event selections for the category SS2jet.
    //==============================================

    // Create variables used in this category.
    // Please follow the convention of <category>_<varname> structure.
    //ana.tx.createBranch<int>("SS2jet_intVar1");
    //ana.tx.createBranch<float>("SS2jet_floatVar1");
    //ana.tx.createBranch<LorentzVector>("SS2jet_LVVar1");

    // Define selections

    ana.tx.createBranch<vector<int>>		("SS2jet_raw_gen_idx");        // Selected gen-particle idx in NanoAOD
    ana.tx.createBranch<vector<int>>		("SS2jet_raw_gen_mother_idx"); // Selected gen-particle mother idx in NanoAOD
    ana.tx.createBranch<vector<int>>		("SS2jet_raw_gen_mother_id");  // Selected gen-particle mother id in NanoAOD
    ana.tx.createBranch<vector<int>>		("SS2jet_raw_gen_pdgid");      // Selected gen-particle pdgids
    ana.tx.createBranch<vector<LorentzVector>>	("SS2jet_raw_gen_p4s");        // Selected gen-particle p4s 
    ana.tx.createBranch<vector<int>>            ("SS2jet_raw_gen_status");
    ana.tx.createBranch<vector<int>>            ("SS2jet_raw_gen_statusFlags");
    bool status=false;
    switch(ana.region){
	case 0:status=SS2jet_SS_filter();break;
	case 1:status=SS2jet_CR_WZ();break;
	case 2:status=SS2jet_CR_ttbar();break;
    }
    if(!status){
	std::cout<<"ERROR:This region is not set yet"<<endl;
	exit(1);
    }
    // Create histograms used in this category.
    // Please follow the convention of h_<category>_<varname> structure.
    // N.B. Using nbins of size 180 or 360 can provide flexibility as it can be rebinned easily, as 180, 360 are highly composite numbers.
    RooUtil::Histograms hists_SS2jet;
    //hists_SS2jet.addHistogram("h_SS2jet_intVar1", 10, 0, 10, [&]() { return ana.tx.getBranch<int>("SS2jet_intVar1"); } );
    //hists_SS2jet.addHistogram("h_SS2jet_floatVar1", 180, 0, 500, [&]() { return ana.tx.getBranch<float>("SS2jet_floatVar1"); } );
    //hists_SS2jet.addHistogram("h_SS2jet_LVVar1_Pt", 180, 0, 150, [&]() { return ana.tx.getBranch<LorentzVector>("SS2jet_LVVar1").pt(); } );
    // Now book cutflow histogram (could be commented out if user does not want.)
    // N.B. Cutflow histogramming can be CPU consuming.
    ana.cutflow.bookCutflows();
    //ana.cutflow.bookHistogramsForCutAndBelow(hists_SS2jet, "SS2jet_GenSS1FatJet");

    // Book histograms to cuts that user wants for this category.
    //ana.cutflow.bookHistogramsForCut(hists_SS2jet, "Cut_SS2jet_Preselection");

}
