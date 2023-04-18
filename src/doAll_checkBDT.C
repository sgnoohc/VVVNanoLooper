#include "ScanChain_checkBDT.C+"
#include "Riostream.h"


double getSumOfGenEventSumw(TChain *chaux);

void doAll_checkBDT(TString year){

    TChain *ch = new TChain("Events");
    TChain *ch_aux = new TChain("Runs");
    TChain *ch2 = new TChain("Events");
    TChain *ch2_aux = new TChain("Runs");
    TChain *ch3 = new TChain("Events");
    TChain *ch3_aux = new TChain("Runs");
    TChain *ch4 = new TChain("Events");
    TChain *ch4_aux = new TChain("Runs");
    TChain *ch5 = new TChain("Events");
    TChain *ch5_aux = new TChain("Runs");
    TChain *ch6 = new TChain("Events");
    TChain *ch6_aux = new TChain("Runs");
    TString baseDir = "/ceph/cms/store/user/kdownham/WWZ_samples/"+year+"/";

    TString WWZ_dir;
    TString GGZH_dir;
    TString HZJ_dir;
    TString ZZ2L2Nu_dir;
    TString ZZ2Q2L_dir;
    TString ZZ4L_dir;
    

    if ( year == "2018" ){
	baseDir += "mc/RunIISummer20UL18NanoAODv9/";
    	WWZ_dir = "WWZJetsTo4L2Nu_4F_TuneCP5_13TeV-amcatnlo-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v2/40000";
    	GGZH_dir = "GluGluZH_HToWWTo2L2Nu_M125_13TeV_powheg_pythia8_TuneCP5_PSweights/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v2/270000";
    	HZJ_dir = "HZJ_HToWWTo2L2Nu_ZTo2L_M-125_TuneCP5_13TeV-powheg-jhugen727-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v2/40000";
    	ZZ2L2Nu_dir = "ZZTo2L2Nu_TuneCP5_13TeV_powheg_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/280000";
    	ZZ2Q2L_dir = "ZZTo2Q2L_mllmin4p0_TuneCP5_13TeV-amcatnloFXFX-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v1/2540000";
    	ZZ4L_dir = "ZZTo4L_TuneCP5_13TeV_powheg_pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v2/70000";
    }

    if ( year == "2017" ){
	baseDir += "mc/RunIISummer20UL17NanoAODv9/";
	WWZ_dir = "WWZJetsTo4L2Nu_4F_TuneCP5_13TeV-amcatnlo-pythia8/NANOAODSIM/106X_mc2017_realistic_v9-v2/30000";
	GGZH_dir = "GluGluZH_HToWWTo2L2Nu_M125_13TeV_powheg_pythia8_TuneCP5_PSweights/NANOAODSIM/106X_mc2017_realistic_v9-v2/100000";
	HZJ_dir = "HZJ_HToWWTo2L2Nu_ZTo2L_M-125_TuneCP5_13TeV-powheg-jhugen727-pythia8/NANOAODSIM/106X_mc2017_realistic_v9-v2/50000";
	ZZ2L2Nu_dir = "ZZTo2L2Nu_TuneCP5_13TeV_powheg_pythia8/NANOAODSIM/106X_mc2017_realistic_v9-v1/70000";
	ZZ2Q2L_dir = "ZZTo2Q2L_mllmin4p0_TuneCP5_13TeV-amcatnloFXFX-pythia8/NANOAODSIM/106X_mc2017_realistic_v9-v1/2550000";
	ZZ4L_dir = "ZZTo4L_TuneCP5_13TeV_powheg_pythia8/NANOAODSIM/106X_mc2017_realistic_v9-v2/110000";
    }

    if ( year == "2016" ){
	baseDir += "mc/RunIISummer20UL16NanoAODv9/";
	WWZ_dir = "WWZJetsTo4L2Nu_4F_TuneCP5_13TeV-amcatnlo-pythia8/NANOAODSIM/106X_mcRun2_asymptotic_v17-v2/50000";
	GGZH_dir = "GluGluZH_HToWWTo2L2Nu_M-125_TuneCP5_13TeV-powheg-pythia8/NANOAODSIM/106X_mcRun2_asymptotic_v17-v2/270000";
	HZJ_dir = "HZJ_HToWWTo2L2Nu_ZTo2L_M-125_TuneCP5_13TeV-powheg-jhugen727-pythia8/NANOAODSIM/106X_mcRun2_asymptotic_v17-v2/40000";
	ZZ2L2Nu_dir = "ZZTo2L2Nu_TuneCP5_13TeV_powheg_pythia8/NANOAODSIM/106X_mcRun2_asymptotic_v17-v1/270000";
	ZZ2Q2L_dir = "ZZTo2Q2L_mllmin4p0_TuneCP5_13TeV-amcatnloFXFX-pythia8/NANOAODSIM/106X_mcRun2_asymptotic_v17-v1/2540000";
	ZZ4L_dir = "ZZTo4L_TuneCP5_13TeV_powheg_pythia8/NANOAODSIM/106X_mcRun2_asymptotic_v17-v1/40000";
    }

    if ( year == "2016APV" ){
	baseDir += "mc/RunIISummer20UL16NanoAODAPVv9/";
	WWZ_dir = "WWZJetsTo4L2Nu_4F_TuneCP5_13TeV-amcatnlo-pythia8/NANOAODSIM/106X_mcRun2_asymptotic_preVFP_v11-v2/2820000";
	GGZH_dir = "GluGluZH_HToWWTo2L2Nu_M125_13TeV_powheg_pythia8_TuneCP5_PSweights/NANOAODSIM/106X_mcRun2_asymptotic_preVFP_v11-v2/2500000";
	HZJ_dir = "HZJ_HToWWTo2L2Nu_ZTo2L_M-125_TuneCP5_13TeV-powheg-jhugen727-pythia8/NANOAODSIM/106X_mcRun2_asymptotic_preVFP_v11-v2/50000";
	ZZ2L2Nu_dir = "ZZTo2L2Nu_TuneCP5_13TeV_powheg_pythia8/NANOAODSIM/106X_mcRun2_asymptotic_preVFP_v11-v1/270000";
	ZZ2Q2L_dir = "ZZTo2Q2L_mllmin4p0_TuneCP5_13TeV-amcatnloFXFX-pythia8/NANOAODSIM/106X_mcRun2_asymptotic_preVFP_v11-v1/80000";
	ZZ4L_dir = "ZZTo4L_TuneCP5_13TeV_powheg_pythia8/NANOAODSIM/106X_mcRun2_asymptotic_preVFP_v11-v1/2430000";
    }


    //float WWZ_xsec = 5.972e-04 * 1000.;
    float WWZ_xsec = 2.067e-3 * 1000.;
    float GGZH_xsec = 0.00029975 * 1000.;
    float HZJ_xsec = 0.0018639 * 1000.;
    float ZZ2L2Nu_xsec = 0.5644 * 1000.;
    float ZZ2Q2L_xsec = 3.221 * 1000.;
    float ZZ4L_xsec = 1.3816 * 1000.;

    ch->Add(baseDir+WWZ_dir+"/*");
    ch_aux->Add(baseDir+WWZ_dir+"/*");
    ScanChain(ch,"WWZ",year,getSumOfGenEventSumw(ch_aux),WWZ_xsec);
    
    ch2->Add(baseDir+GGZH_dir+"/*");
    ch2_aux->Add(baseDir+GGZH_dir+"/*");
    ScanChain(ch2,"ggZH",year,getSumOfGenEventSumw(ch2_aux),GGZH_xsec);

    ch3->Add(baseDir+HZJ_dir+"/*");
    ch3_aux->Add(baseDir+HZJ_dir+"/*");
    ScanChain(ch3,"HZJ",year,getSumOfGenEventSumw(ch3_aux),HZJ_xsec);

    ch4->Add(baseDir+ZZ2L2Nu_dir+"/*");
    ch4_aux->Add(baseDir+ZZ2L2Nu_dir+"/*");
    ScanChain(ch4,"ZZTo2L2Nu",year,getSumOfGenEventSumw(ch4_aux),ZZ2L2Nu_xsec);

    ch5->Add(baseDir+ZZ2Q2L_dir+"/*");
    ch5_aux->Add(baseDir+ZZ2Q2L_dir+"/*");
    ScanChain(ch5,"ZZTo2Q2L",year,getSumOfGenEventSumw(ch5_aux),ZZ2Q2L_xsec);
 
    ch6->Add(baseDir+ZZ4L_dir+"/*");
    ch6_aux->Add(baseDir+ZZ4L_dir+"/*");
    ScanChain(ch6,"ZZTo4L",year,getSumOfGenEventSumw(ch6_aux),ZZ4L_xsec);   
    
}
// Called in ScanChain function ----- See how Z prime does this
double getSumOfGenEventSumw(TChain *chaux){
  double genEventSumw, sumOfGenEventSumw=0.0;
  chaux->SetBranchAddress("genEventSumw",&genEventSumw);
  for (unsigned int run = 0; run < chaux->GetEntriesFast(); run++){
      chaux->GetEntry(run);
      sumOfGenEventSumw += genEventSumw;
  }

  return sumOfGenEventSumw;
}

