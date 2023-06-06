#ifndef AnalysisConfig_h
#define AnalysisConfig_h

#include "rooutil.h"
#include "Nano.h"
#include "Config.h"
#include "VVVTree.h"
#include "math.h"
#include "ScaleFactors.h"
#include <algorithm>
#include "Tools/btagsf/BTagCalibrationStandalone.h"
#include "Tools/btagsf/BTagCalibrationStandalone_v2.h"

class AnalysisConfig {

public:

    enum LooperMode {
        k4LepMET = 0,
        k4Lep2jet,
        k3LepMET,
        k3Lep2jet,
        kOS4jet,
        kOS2jet,
        kSS2jet,
        k1Lep4jet,
        kallHad,
        k1Lep2fatJets,
    };

    LooperMode looperMode;

    // Integer for users to use to define regions (if needed)
    int region;

    enum SystematicVariation {
        kcenter=0,
        kjesup,
        kjesdn,
        kjerup,
        kjerdn,
        kjmsup,
        kjmsdn,
        kjmrup,
        kjmrdn,
    };

    SystematicVariation systematicVariation=kcenter;

    // VH->VVV channel to be selected (if running on VHToNonBB samples)
    int vhvvv_channel;

    // EFT reweighting index
    int eft_reweighting_idx;

    // TString that holds the input file list (comma separated)
    TString input_file_list_tstring;

    // TString that holds the name of the TTree to open for each input files
    TString input_tree_name;

    // Output TFile
    TFile* output_tfile;

    // Number of events to loop over
    int n_events;

    // Jobs to split (if this number is positive, then we will skip certain number of events)
    // If there are N events, and was asked to split 2 ways, then depending on job_index, it will run over first half or latter half
    int nsplit_jobs;

    // Job index (assuming nsplit_jobs is set, the job_index determine where to loop over)
    int job_index;

    // Debug boolean
    bool debug;

    // TChain that holds the input TTree's
    TChain* events_tchain;

    // Custom Looper object to facilitate looping over many files
    RooUtil::Looper<Nano> looper;

    // Custom Looper object to facilitate looping over many files
    RooUtil::Looper<VVVTree> looper_vvvtree;

    // Custom Cutflow framework
    RooUtil::Cutflow cutflow;

    // Custom Histograms object compatible with RooUtil::Cutflow framework
    RooUtil::Histograms histograms;

    // Intermediate TTree that holds variables
    TTree* tree_intermediate_variable;

    // Custom TTreeX object to hold various intermediate variables people want
    RooUtil::TTreeX tx;

    // Boolean to trigger output tree writing
    bool write_tree;

    // Boolean to trigger output tree writing
    bool run_VVVTree;

    // If LHEWeight_mg_reweighting branch exists, it is the EFT sample
    bool is_EFT_sample;

    // if branches added in by NanoAODTools exists, it is the postprocessed NanoAOD sample

    bool is_postprocessed;

    // event weight
    float wgt;

    // Output TTree
    TTree* output_tree;

    // Custom TTree object to use to facilitate TTree output writing
    RooUtil::TTreeX output_tx;

    LeptonScaleFactor leptonscalefactors = LeptonScaleFactor();
    FatJetScaleFactor fatjetscalefactors = FatJetScaleFactor();

    BTagCalibration* btagCalib;
    BTagCalibration* btagCalib_inlieu;
    BTagCalibrationReader* btagReaderTight;
    BTagCalibrationReader* btagReaderMedium;
    BTagCalibrationReader* btagReaderLoose;
    BTagCalibration_v2* btagCalib_v2;
    BTagCalibration_v2* btagCalib_v2_inlieu;
    BTagCalibrationReader_v2* btagReaderTight_v2;
    BTagCalibrationReader_v2* btagReaderMedium_v2;
    BTagCalibrationReader_v2* btagReaderLoose_v2;
    RooUtil::HistMap* btagEffTight_b;
    RooUtil::HistMap* btagEffTight_c;
    RooUtil::HistMap* btagEffTight_l;
    RooUtil::HistMap* btagEffMedium_b;
    RooUtil::HistMap* btagEffMedium_c;
    RooUtil::HistMap* btagEffMedium_l;
    RooUtil::HistMap* btagEffLoose_b;
    RooUtil::HistMap* btagEffLoose_c;
    RooUtil::HistMap* btagEffLoose_l;

    RooUtil::HistMap* muonRECOSF;
    RooUtil::HistMap* muonIDSFMedium;
    RooUtil::HistMap* muonISOSFLoose;
    RooUtil::HistMap* muonISOSFTight;

    RooUtil::HistMap* electronRECOSFlt20;
    RooUtil::HistMap* electronRECOSFgt20;
    RooUtil::HistMap* electronMVAID90SF;
    RooUtil::HistMap* electronMVAID80SF;

    RooUtil::HistMap* triggereeSF;
    RooUtil::HistMap* triggeremuSF;
    RooUtil::HistMap* triggermumuSF;
};

extern AnalysisConfig ana;

#endif
