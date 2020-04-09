#ifndef AnalysisConfig_h
#define AnalysisConfig_h

#include "rooutil.h"
#include "Nano.h"

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
    };

    LooperMode looperMode;

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

    // Custom Cutflow framework
    RooUtil::Cutflow cutflow;

    // Custom Histograms object compatible with RooUtil::Cutflow framework
    RooUtil::Histograms histograms;

    // Intermediate TTree that holds variables
    TTree* tree_intermediate_variable;

    // Custom TTreeX object to hold various intermediate variables people want
    RooUtil::TTreeX tx;

    // Output TTree
    TTree* output_tree;

    // Custom TTree object to use to facilitate TTree output writing
    RooUtil::TTreeX output_tx;

};

extern AnalysisConfig ana;

#endif
