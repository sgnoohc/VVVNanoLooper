#include "VVV0LepTree.h"
#include "rooutil.h"
#include "cxxopts.h"

using json = nlohmann::json;

class AnalysisConfig {

public:

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
    RooUtil::Looper<VVV0LepTree> looper;

    // Custom Cutflow framework
    RooUtil::Cutflow cutflow;

    // Custom Histograms object compatible with RooUtil::Cutflow framework
    RooUtil::Histograms histograms;

};

AnalysisConfig ana;

// ./process INPUTFILEPATH OUTPUTFILE [NEVENTS]
int main(int argc, char** argv)
{

//********************************************************************************
//
// 1. Parsing options
//
//********************************************************************************

    // cxxopts is just a tool to parse argc, and argv easily

    // Grand option setting
    cxxopts::Options options("\n  $ doAnalysis",  "\n         **********************\n         *                    *\n         *       Looper       *\n         *                    *\n         **********************\n");

    // Read the options
    options.add_options()
        ("i,input"       , "Comma separated input file list OR if just a directory is provided it will glob all in the directory BUT must end with '/' for the path", cxxopts::value<std::string>())
        ("t,tree"        , "Name of the tree in the root file to open and loop over"                                             , cxxopts::value<std::string>())
        ("o,output"      , "Output file name"                                                                                    , cxxopts::value<std::string>())
        ("n,nevents"     , "N events to loop over"                                                                               , cxxopts::value<int>()->default_value("-1"))
        ("j,nsplit_jobs" , "Enable splitting jobs by N blocks (--job_index must be set)"                                         , cxxopts::value<int>())
        ("I,job_index"   , "job_index of split jobs (--nsplit_jobs must be set. index starts from 0. i.e. 0, 1, 2, 3, etc...)"   , cxxopts::value<int>())
        ("d,debug"       , "Run debug job. i.e. overrides output option to 'debug.root' and 'recreate's the file.")
        ("h,help"        , "Print help")
        ;

    auto result = options.parse(argc, argv);

    // NOTE: When an option was provided (e.g. -i or --input), then the result.count("<option name>") is more than 0
    // Therefore, the option can be parsed easily by asking the condition if (result.count("<option name>");
    // That's how the several options are parsed below

    //_______________________________________________________________________________
    // --help
    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --input
    if (result.count("input"))
    {
        ana.input_file_list_tstring = result["input"].as<std::string>();
    }
    else
    {
        std::cout << options.help() << std::endl;
        std::cout << "ERROR: Input list is not provided! Check your arguments" << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --tree
    if (result.count("tree"))
    {
        ana.input_tree_name = result["tree"].as<std::string>();
    }
    else
    {
        std::cout << options.help() << std::endl;
        std::cout << "ERROR: Input tree name is not provided! Check your arguments" << std::endl;
        exit(1);
    }

    //_______________________________________________________________________________
    // --debug
    if (result.count("debug"))
    {
        ana.output_tfile = new TFile("debug.root", "recreate");
    }
    else
    {
        //_______________________________________________________________________________
        // --output
        if (result.count("output"))
        {
            ana.output_tfile = new TFile(result["output"].as<std::string>().c_str(), "create");
            if (not ana.output_tfile->IsOpen())
            {
                std::cout << options.help() << std::endl;
                std::cout << "ERROR: output already exists! provide new output name or delete old file. OUTPUTFILE=" << result["output"].as<std::string>() << std::endl;
                exit(1);
            }
        }
        else
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: Output file name is not provided! Check your arguments" << std::endl;
            exit(1);
        }
    }

    //_______________________________________________________________________________
    // --nevents
    ana.n_events = result["nevents"].as<int>();

    //_______________________________________________________________________________
    // --nsplit_jobs
    if (result.count("nsplit_jobs"))
    {
        ana.nsplit_jobs = result["nsplit_jobs"].as<int>();
        if (ana.nsplit_jobs <= 0)
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --nsplit_jobs" << ana.nsplit_jobs << " has zero or negative value!" << std::endl;
            std::cout << "I am not sure what this means..." << std::endl;
            exit(1);
        }
    }
    else
    {
        ana.nsplit_jobs = -1;
    }

    //_______________________________________________________________________________
    // --nsplit_jobs
    if (result.count("job_index"))
    {
        ana.job_index = result["job_index"].as<int>();
        if (ana.job_index < 0)
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --job_index" << ana.job_index << " has negative value!" << std::endl;
            std::cout << "I am not sure what this means..." << std::endl;
            exit(1);
        }
    }
    else
    {
        ana.job_index = -1;
    }


    // Sanity check for split jobs (if one is set the other must be set too)
    if (result.count("job_index") or result.count("nsplit_jobs"))
    {
        // If one is not provided then throw error
        if ( not (result.count("job_index") and result.count("nsplit_jobs")))
        {
            std::cout << options.help() << std::endl;
            std::cout << "ERROR: option string --job_index and --nsplit_jobs must be set at the same time!" << std::endl;
            exit(1);
        }
        // If it is set then check for sanity
        else
        {
            if (ana.job_index >= ana.nsplit_jobs)
            {
                std::cout << options.help() << std::endl;
                std::cout << "ERROR: --job_index >= --nsplit_jobs ! This does not make sense..." << std::endl;
                exit(1);
            }
        }
    }

    //
    // Printing out the option settings overview
    //
    std::cout <<  "=========================================================" << std::endl;
    std::cout <<  " Setting of the analysis job based on provided arguments " << std::endl;
    std::cout <<  "---------------------------------------------------------" << std::endl;
    std::cout <<  " ana.input_file_list_tstring: " << ana.input_file_list_tstring <<  std::endl;
    std::cout <<  " ana.output_tfile: " << ana.output_tfile->GetName() <<  std::endl;
    std::cout <<  " ana.n_events: " << ana.n_events <<  std::endl;
    std::cout <<  " ana.nsplit_jobs: " << ana.nsplit_jobs <<  std::endl;
    std::cout <<  " ana.job_index: " << ana.job_index <<  std::endl;
    std::cout <<  "=========================================================" << std::endl;

//********************************************************************************
//
// 2. Opening input baby files
//
//********************************************************************************

    // Create the TChain that holds the TTree's of the baby ntuples
    ana.events_tchain = RooUtil::FileUtil::createTChain(ana.input_tree_name, ana.input_file_list_tstring);

    // Create a Looper object to loop over input files
    // the "www" object is defined in the wwwtree.h/cc
    // This is an instance which helps read variables in the WWW baby TTree
    // It is a giant wrapper that facilitates reading TBranch values.
    // e.g. if there is a TBranch named "lep_pt" which is a std::vector<float> then, one can access the branch via
    //
    //    std::vector<float> lep_pt = www.lep_pt();
    //
    // and no need for "SetBranchAddress" and declaring variable shenanigans necessary
    // This is a standard thing SNT does pretty much every looper we use
    ana.looper.init(ana.events_tchain, &vvv, ana.n_events);

//********************************************************************************
//
// Interlude... notes on RooUtil framework
//
//********************************************************************************

    // ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    // Quick tutorial on RooUtil::Cutflow object cut tree formation
    // ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    //
    // The RooUtil::Cutflow object facilitates creating a tree structure of cuts
    //
    // To add cuts to each node of the tree with cuts defined, use "addCut" or "addCutToLastActiveCut"
    // The "addCut" or "addCutToLastActiveCut" accepts three argument, <name>, and two lambda's that define the cut selection, and the weight to apply to that cut stage
    //
    // e.g. To create following cut-tree structure one does
    //
    //             (Root) <--- Always exists as soon as RooUtil::Cutflow object is created. But this is basically hidden underneath and users do not have to care
    //                |
    //            CutWeight
    //            |       |
    //     CutPreSel1    CutPreSel2
    //       |                  |
    //     CutSel1           CutSel2
    //
    //
    //   code:
    //
    //      // Create the object (Root node is created as soon as the instance is created)
    //      RooUtil::Cutflow cutflow;
    //
    //      cutflow.addCut("CutWeight"                 , <lambda> , <lambda>); // CutWeight is added below "Root"-node
    //      cutflow.addCutToLastActiveCut("CutPresel1" , <lambda> , <lambda>); // The last "active" cut is "CutWeight" since I just added that. So "CutPresel1" is added below "CutWeight"
    //      cutflow.addCutToLastActiveCut("CutSel1"    , <lambda> , <lambda>); // The last "active" cut is "CutPresel1" since I just added that. So "CutSel1" is added below "CutPresel1"
    //
    //      cutflow.getCut("CutWeight"); // By "getting" the cut object, this makes the "CutWeight" the last "active" cut.
    //      cutflow.addCutToLastActiveCut("CutPresel2" , <lambda> , <lambda>); // The last "active" cut is "CutWeight" since I "getCut" on it. So "CutPresel2" is added below "CutWeight"
    //      cutflow.addCutToLastActiveCut("CutSel2"    , <lambda> , <lambda>); // The last "active" cut is "CutPresel2" since I just added that. So "CutSel2" is added below "CutPresel1"
    //
    // (Side note: "UNITY" lambda is defined in the framework to just return 1. This so that use don't have to type [&]() {return 1;} so many times.)
    //
    // Once the cutflow is formed, create cutflow histograms can be created by calling RooUtil::Cutflow::bookCutflows())
    // This function looks through the terminating nodes of the tree structured cut tree. and creates a histogram that will fill the yields
    // For the example above, there are two terminationg nodes, "CutSel1", and "CutSel2"
    // So in this case Root::Cutflow::bookCutflows() will create two histograms. (Actually four histograms.)
    //
    //  - TH1F* type object :  CutSel1_cutflow (4 bins, with first bin labeled "Root", second bin labeled "CutWeight", third bin labeled "CutPreSel1", fourth bin labeled "CutSel1")
    //  - TH1F* type object :  CutSel2_cutflow (...)
    //  - TH1F* type object :  CutSel1_rawcutflow (...)
    //  - TH1F* type object :  CutSel2_rawcutflow (...)
    //                                ^
    //                                |
    // NOTE: There is only one underscore "_" between <CutName>_cutflow or <CutName>_rawcutflow
    //
    // And later in the loop when RooUtil::Cutflow::fill() function is called, the tree structure will be traversed through and the appropriate yields will be filled into the histograms
    //
    // After running the loop check for the histograms in the output root file

    // ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    // Quick tutorial on RooUtil::Histograms object
    // ~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=~=
    //
    // The RooUtil::Histograms object facilitates book keeping histogram definitions
    // And in conjunction with RooUtil::Cutflow object, one can book same histograms across different cut stages easily without copy pasting codes many times by hand.
    //
    // The histogram addition happens in two steps.
    // 1. Defining histograms
    // 2. Booking histograms to cuts
    //
    // Histograms are defined via following functions
    //
    //      RooUtil::Histograms::addHistogram       : Typical 1D histogram (TH1F*) "Fill()" called once per event
    //      RooUtil::Histograms::addVecHistogram    : Typical 1D histogram (TH1F*) "Fill()" called multiple times per event
    //      RooUtil::Histograms::add2DHistogram     : Typical 2D histogram (TH2F*) "Fill()" called once per event
    //      RooUtil::Histograms::add2DVecHistogram  : Typical 2D histogram (TH2F*) "Fill()" called multiple times per event
    // e.g.
    //
    //    RooUtil::Histograms histograms;
    //    histograms.addHistogram   ("MllSS"    , 180 , 0. , 300. , [&]() { return www.MllSS()  ; }); // The lambda returns float
    //    histograms.addVecHistogram("AllLepPt" , 180 , 0. , 300. , [&]() { return www.lep_pt() ; }); // The lambda returns vector<float>
    //
    // The addVecHistogram will have lambda to return vector<float> and it will loop over the values and call TH1F::Fill() for each item
    //
    // To book histograms to cuts one uses
    //
    //      RooUtil::Cutflow::bookHistogramsForCut()
    //      RooUtil::Cutflow::bookHistogramsForCutAndBelow()
    //      RooUtil::Cutflow::bookHistogramsForCutAndAbove()
    //      RooUtil::Cutflow::bookHistogramsForEndCuts()
    //
    // e.g. Given a tree like the following, we can book histograms to various cuts as we want
    //
    //              Root
    //                |
    //            CutWeight
    //            |       |
    //     CutPreSel1    CutPreSel2
    //       |                  |
    //     CutSel1           CutSel2
    //
    // For example,
    //
    //    1. book a set of histograms to one cut:
    //
    //       cutflow.bookHistogramsForCut(histograms, "CutPreSel2")
    //
    //    2. book a set of histograms to a cut and below
    //
    //       cutflow.bookHistogramsForCutAndBelow(histograms, "CutWeight") // will book a set of histograms to CutWeight, CutPreSel1, CutPreSel2, CutSel1, and CutSel2
    //
    //    3. book a set of histograms to a cut and above (... useless...?)
    //
    //       cutflow.bookHistogramsForCutAndAbove(histograms, "CutPreSel2") // will book a set of histograms to CutPreSel2, CutWeight (nothing happens to Root node)
    //
    //    4. book a set of histograms to a terminating nodes
    //
    //       cutflow.bookHistogramsForEndCuts(histograms) // will book a set of histograms to CutSel1 and CutSel2
    //
    // The naming convention of the booked histograms are as follows
    //
    //   cutflow.bookHistogramsForCut(histograms, "CutSel1");
    //
    //  - TH1F* type object : CutSel1__MllSS;
    //  - TH1F* type object : CutSel1__AllLepPt;
    //                               ^^
    //                               ||
    // NOTE: There are two underscores "__" between <CutName>__<HistogramName>
    //
    // And later in the loop when RooUtil::CutName::fill() function is called, the tree structure will be traversed through and the appropriate histograms will be filled with appropriate variables
    // After running the loop check for the histograms in the output root file

    std::ifstream scale1fb("scale1fbs_VVV0Lep.txt");
    json j;
    scale1fb >> j;

    std::ifstream njobs("njobs.txt");
    json n;
    njobs >> n;
    
    // Set the cutflow object output file
    ana.cutflow.setTFile(ana.output_tfile);

    auto HT_ak4 = [&]()
        {
            float HT = 0;
            for (unsigned int i = 0; i < vvv.allHad_jets_p4().size(); ++i)
            {
                HT += vvv.allHad_jets_p4()[i].pt();
            }
            return HT;
        };

    ana.cutflow.addCut("WeightByXsec", UNITY,
                       [&, j]()
                       {
                           TString filename = ana.looper.getCurrentFileBaseName();
                           TString samplename = filename.ReplaceAll(".root", "");

                           float lumi = -1;
                           if (ana.looper.getCurrentFileName().Contains("2006"))
                               lumi = 19.52;
                           if (ana.looper.getCurrentFileName().Contains("2016"))
                               lumi = 16.81;
                           if (ana.looper.getCurrentFileName().Contains("2017"))
                               lumi = 41.48;
                           if (ana.looper.getCurrentFileName().Contains("2018"))
                               lumi = 59.83;

                           float wgt = 1;
                           if (not vvv.Common_isData())
                           {
                               wgt = (vvv.Common_genWeight() > 0) - (vvv.Common_genWeight() < 0);
                           }

                           int nfact = 0;
                           float xsec = 1;

                           if (j.find(samplename.Data()) != j.end())
                           {
                               xsec = j[samplename.Data()];
                               nfact = n[samplename.Data()];
                           }
                           else
                           {
                               return 1.;
                           }

                           float nevts = 1;
                           if (vvv.Common_LHEReweightingWeight().size() > 0)
                           {
                               nevts = ((TH1F*)ana.looper.getCurrentFile()->Get("Root__h_Common_LHEWeight_mg_reweighting_times_genWeight"))->GetBinContent(1);
                               int idx = 0;
                               if (samplename.EqualTo("WWW")) idx = 94;
                               if (samplename.EqualTo("WWZ")) idx = 142;
                               if (samplename.EqualTo("WZZ")) idx = 142;
                               if (samplename.EqualTo("ZZZ")) idx = 142;
                               if (samplename.EqualTo("WWW_Dim6")) idx = 13;
                               if (samplename.EqualTo("WWZ_Dim6")) idx = 13;
                               if (samplename.EqualTo("WZZ_Dim6")) idx = 13;
                               if (samplename.EqualTo("ZZZ_Dim6")) idx = 13;
                               wgt *= vvv.Common_genWeight() * vvv.Common_LHEReweightingWeight()[idx]; // FT0=1.0 I think? (TODO: Check)
                           }
                           else
                           {
                               nevts = ((TH1F*)ana.looper.getCurrentFile()->Get("Wgt__h_nevents"))->GetBinContent(1);
                           }

                           return wgt * xsec * 1000.0 / nevts * lumi * nfact;
                       });
    ana.cutflow.addCutToLastActiveCut("Preselection",
        [&]()
        {
            if (not (vvv.allHad_nFJ()               >=    2 )) return false;
            if (not (vvv.allHad_FJ0_mSD_p4().pt()   >   500 )) return false;
            if (not (vvv.allHad_FJ1_mSD_p4().pt()   >   200 )) return false;
            return true;
        }, UNITY);

    ana.cutflow.getCut("Preselection");
    ana.cutflow.addCutToLastActiveCut("NFJEq2"     , [&]() { return vvv.allHad_nFJ() == 2; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJEq2V0p4" , [&]() { return vvv.allHad_FJ0_VMD() >= 0.4 and vvv.allHad_FJ1_VMD() >= 0.4; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJEq2MSD0" , [&]() { return vvv.allHad_FJ0_mSD_p4().mass() >= 60 and vvv.allHad_FJ0_mSD_p4().mass() <= 110; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJEq2MSD1" , [&]() { return vvv.allHad_FJ1_mSD_p4().mass() >= 60 and vvv.allHad_FJ1_mSD_p4().mass() <= 110; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJEq2MVVV" , [&]() { return vvv.allHad_mVVV() > 1100.; }, UNITY);

    ana.cutflow.getCut("NFJEq2MVVV");
    ana.cutflow.addCutToLastActiveCut("NFJEq2LoDR", [&]() { return vvv.allHad_FJ01_dR() < 3.1416; }, UNITY);
    ana.cutflow.getCut("NFJEq2MVVV");
    ana.cutflow.addCutToLastActiveCut("NFJEq2HiDR", [&]() { return vvv.allHad_FJ01_dR() >= 3.1416; }, UNITY);

    // ana.cutflow.addCutToLastActiveCut("NFJEq2Loose", [&]() { return vvv.allHad_FJ0_WP_MD() >= 1 and vvv.allHad_FJ1_WP_MD() >= 1; }, UNITY);
    // ana.cutflow.addCutToLastActiveCut("NFJEq2Tight", [&]() { return vvv.allHad_FJ0_WP_MD() == 3 and vvv.allHad_FJ1_WP_MD() == 3; }, UNITY);
    // ana.cutflow.addCutToLastActiveCut("NFJEq2BVeto", [&]() { return vvv.Common_nb_medium() == 0; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJEq2SR"   , UNITY, UNITY);
    ana.cutflow.getCut("Preselection");
    ana.cutflow.addCutToLastActiveCut("NFJGeq3"     , [&]() { return vvv.allHad_nFJ() >= 3; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJGeq3V0p4" , [&]() { return vvv.allHad_FJ0_VMD() >= 0.4 and vvv.allHad_FJ1_VMD() >= 0.4 and vvv.allHad_FJ2_VMD() >= 0.4; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJGeq3MSD0" , [&]() { return vvv.allHad_FJ0_mSD_p4().mass() >= 60 and vvv.allHad_FJ0_mSD_p4().mass() <= 110; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJGeq3MSD1" , [&]() { return vvv.allHad_FJ1_mSD_p4().mass() >= 60 and vvv.allHad_FJ1_mSD_p4().mass() <= 110; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJGeq3MSD2" , [&]() { return vvv.allHad_FJ2_mSD_p4().mass() >= 60 and vvv.allHad_FJ2_mSD_p4().mass() <= 110; }, UNITY);
    // ana.cutflow.addCutToLastActiveCut("NFJGeq3Loose", [&]() { return vvv.allHad_FJ0_WP_MD() >= 1 and vvv.allHad_FJ1_WP_MD() >= 1 and vvv.allHad_FJ2_WP_MD() >= 1; }, UNITY);
    // ana.cutflow.addCutToLastActiveCut("NFJGeq3Tight", [&]() { return vvv.allHad_FJ0_WP_MD() == 3 and vvv.allHad_FJ1_WP_MD() == 3 and vvv.allHad_FJ2_WP_MD() == 3; }, UNITY);
    // ana.cutflow.addCutToLastActiveCut("NFJGeq3BVeto", [&]() { return vvv.Common_nb_medium() == 0; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJGeq3SR"   , UNITY, UNITY);

    // Print cut structure
    ana.cutflow.printCuts();

    // Histogram utility object that is used to define the histograms
    ana.histograms.addHistogram("MSD0", 180, 30, 150, [&]() { return vvv.allHad_FJ0_mSD_p4().mass(); } );
    ana.histograms.addHistogram("MSD1", 180, 30, 150, [&]() { return vvv.allHad_FJ1_mSD_p4().mass(); } );
    ana.histograms.addHistogram("MSD2", 180, 30, 150, [&]() { return vvv.allHad_FJ2_mSD_p4().mass(); } );
    ana.histograms.addHistogram("Pt0", 180, 0, 2500, [&]() { return vvv.allHad_FJ0_mSD_p4().pt(); } );
    ana.histograms.addHistogram("Pt1", 180, 0, 2500, [&]() { return vvv.allHad_FJ1_mSD_p4().pt(); } );
    ana.histograms.addHistogram("Pt2", 180, 0, 2500, [&]() { return vvv.allHad_FJ2_mSD_p4().pt(); } );
    ana.histograms.addHistogram("W0", 180, 0, 1, [&]() { return vvv.allHad_FJ0_WMD(); } );
    ana.histograms.addHistogram("W1", 180, 0, 1, [&]() { return vvv.allHad_FJ1_WMD(); } );
    ana.histograms.addHistogram("W2", 180, 0, 1, [&]() { return vvv.allHad_FJ2_WMD(); } );
    ana.histograms.addHistogram("V0", 180, 0, 1, [&]() { return vvv.allHad_FJ0_VMD(); } );
    ana.histograms.addHistogram("V1", 180, 0, 1, [&]() { return vvv.allHad_FJ1_VMD(); } );
    ana.histograms.addHistogram("V2", 180, 0, 1, [&]() { return vvv.allHad_FJ2_VMD(); } );

    ana.histograms.addHistogram("NbLoose", 10, 0, 15, [&]() { return vvv.Common_nb_loose(); } );
    ana.histograms.addHistogram("NbMedium", 10, 0, 10, [&]() { return vvv.Common_nb_medium(); } );
    ana.histograms.addHistogram("NbTight", 10, 0, 10, [&]() { return vvv.Common_nb_tight(); } );
    ana.histograms.addHistogram("NL", 15, 0, 15, [&]() { return vvv.Common_lep_pdgid().size(); } );
    ana.histograms.addHistogram("NJ", 10, 0, 10, [&]() { return vvv.allHad_jets_p4().size(); } );
    ana.histograms.addHistogram("NFJ", 10, 0, 10, [&]() { return vvv.allHad_nFJ(); } );

    ana.histograms.addHistogram("HT", 180, 0, 8500, [&]() { return vvv.allHad_HT(); } );
    ana.histograms.addHistogram("HT_FJ", 180, 0, 5500, [&]() { return vvv.allHad_HT_FJ(); } );
    ana.histograms.addHistogram("HT_AK4", 180, 0, 2500, HT_ak4 );

    ana.histograms.addHistogram("MVVV", 180, 0, 8500, [&]() { return vvv.allHad_mVVV(); } );
    ana.histograms.addHistogram("PtVVV", 180, 0, 5500, [&]() { return vvv.allHad_ptVVV(); } );
    ana.histograms.addHistogram("MVVVSR", {0., 1000., 1500., 3500., 6000., 8000.}, [&]() { return vvv.allHad_mVVV(); } );

    ana.histograms.addHistogram("FJ01_dPhi", 180, 0, 3.1416, [&]() { return fabs(vvv.allHad_FJ01_dPhi()); } );
    ana.histograms.addHistogram("FJ01_dEta", 180, 0, 7, [&]() { return fabs(vvv.allHad_FJ01_dEta()); } );
    ana.histograms.addHistogram("FJ01_dR", 180, 0, 7, [&]() { return fabs(vvv.allHad_FJ01_dR()); } );
    ana.histograms.addHistogram("FJ01_dPtFrac", 180, -2, 2, [&]() { return vvv.allHad_FJ01_dPtFrac(); } );
    ana.histograms.addHistogram("FJ01_pPRel", 180, 0, 5500, [&]() { return vvv.allHad_FJ01_pPRel(); } );

    ana.histograms.addHistogram("FJ02_dPhi", 180, 0, 3.1416, [&]() { return fabs(vvv.allHad_FJ02_dPhi()); } );
    ana.histograms.addHistogram("FJ02_dEta", 180, 0, 7, [&]() { return fabs(vvv.allHad_FJ02_dEta()); } );
    ana.histograms.addHistogram("FJ02_dR", 180, 0, 7, [&]() { return fabs(vvv.allHad_FJ02_dR()); } );
    ana.histograms.addHistogram("FJ02_dPtFrac", 180, -2, 2, [&]() { return vvv.allHad_FJ02_dPtFrac(); } );
    ana.histograms.addHistogram("FJ02_pPRel", 180, 0, 5500, [&]() { return vvv.allHad_FJ02_pPRel(); } );

    ana.histograms.addHistogram("FJ12_dPhi", 180, 0, 3.1416, [&]() { return fabs(vvv.allHad_FJ12_dPhi()); } );
    ana.histograms.addHistogram("FJ12_dEta", 180, 0, 7, [&]() { return fabs(vvv.allHad_FJ12_dEta()); } );
    ana.histograms.addHistogram("FJ12_dR", 180, 0, 7, [&]() { return fabs(vvv.allHad_FJ12_dR()); } );
    ana.histograms.addHistogram("FJ12_dPtFrac", 180, -2, 2, [&]() { return vvv.allHad_FJ12_dPtFrac(); } );
    ana.histograms.addHistogram("FJ12_pPRel", 180, 0, 5500, [&]() { return vvv.allHad_FJ12_pPRel(); } );

    // Book cutflows
    ana.cutflow.bookCutflows();

    // Book Histograms
    ana.cutflow.bookHistograms(ana.histograms); // if just want to book everywhere

    // Looping input file
    while (ana.looper.nextEvent())
    {

        // If splitting jobs are requested then determine whether to process the event or not based on remainder
        if (result.count("job_index") and result.count("nsplit_jobs"))
        {
            if (ana.looper.getNEventsProcessed() % ana.nsplit_jobs != (unsigned int) ana.job_index)
                continue;
        }

        //Do what you need to do in for each event here
        //To save use the following function
        ana.cutflow.fill();
    }

    // Writing output file
    ana.cutflow.saveOutput();

    // The below can be sometimes crucial
    delete ana.output_tfile;
}
