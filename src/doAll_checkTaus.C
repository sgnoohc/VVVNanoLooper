#include "ScanChain_checkTaus.C+"
#include "Riostream.h"


double getSumOfGenEventSumw(TChain *chaux);

void doAll_checkTaus(){

    TChain *ch = new TChain("Events");
    TChain *ch_aux = new TChain("Runs");
    TChain *ch2 = new TChain("Events");
    TChain *ch2_aux = new TChain("Runs");
    TString baseDirRAW = "/ceph/cms/store/user/kdownham/WWZ_samples/2018/";
    TString baseDirSkim = "/home/users/kdownham/Triboson/NanoSkimmer/WWZJets_Run2018_UL18_Skim.root";
    TString WWZ_dir;

    baseDirRAW += "mc/RunIISummer20UL18NanoAODv9/";
    WWZ_dir = "WWZJetsTo4L2Nu_4F_TuneCP5_13TeV-amcatnlo-pythia8/NANOAODSIM/106X_upgrade2018_realistic_v16_L1v1-v2/40000";

    //baseDirSkim += "WWZJetsTo4L2Nu_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v2_NANOAODSIM_WWZ_3L";

    float WWZ_xsec = 0.02067 * 1000.;

    ch->Add(baseDirRAW+WWZ_dir+"/*");
    ch_aux->Add(baseDirRAW+WWZ_dir+"/*");
    ScanChain(ch,"WWZGen","2018",getSumOfGenEventSumw(ch_aux),WWZ_xsec);

    ch2->Add(baseDirSkim);
    ch2_aux->Add(baseDirSkim);
    ScanChain(ch2,"WWZSkim","2018",getSumOfGenEventSumw(ch2_aux),WWZ_xsec);

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

