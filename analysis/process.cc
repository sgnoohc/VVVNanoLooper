#include "vvvtree.h"
#include "rooutil.h"
#include "cxxopts.h"

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

    // EFT reweighting index
    int eft_reweighting_idx;

    // Debug boolean
    bool debug;

    // TChain that holds the input TTree's
    TChain* events_tchain;

    // Custom Looper object to facilitate looping over many files
    RooUtil::Looper<vvvtree> looper;

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
        ("e,eftidx"      , "EFT reweighting index"                                                                               , cxxopts::value<int>())
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

    //_______________________________________________________________________________
    // --eftidx
    if (result.count("eftidx"))
    {
        ana.eft_reweighting_idx = result["eftidx"].as<int>();
    }
    else
    {
        ana.eft_reweighting_idx = 0;
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

    // Set the cutflow object output file
    ana.cutflow.setTFile(ana.output_tfile);

    float STLep = 0;
    float STLepHad = 0;
    float DRll = 0;
    float Pt4l = 0;

    ana.cutflow.addCut("CutWeight", UNITY, [&]()
                       {
                           bool isWWZEFT = ana.looper.getCurrentFileName().Contains("WWZ_RunIISummer20UL18NanoAODv9_FourleptonFilter_FilterFix_merged");
                           bool isWZZEFT = ana.looper.getCurrentFileName().Contains("WZZ_RunIISummer20UL18NanoAODv9_FourleptonFilter_FilterFix_merged");
                           bool isZZZEFT = ana.looper.getCurrentFileName().Contains("ZZZ_RunIISummer20UL18NanoAODv9_FourleptonFilter_FilterFix_merged");

                           float sm_weight = 1;
                           sm_weight = (isWWZEFT ? vvv.Common_LHEWeight_mg_reweighting()[0] * 0.1651 * 0.3272 * 0.3272 * 0.1009 /0.0005972 : 1.)
                                     * (isWZZEFT ? vvv.Common_LHEWeight_mg_reweighting()[0] : 1.)
                                     * (isZZZEFT ? vvv.Common_LHEWeight_mg_reweighting()[0] : 1.)
                                     ;
                           float eftweight = 1;
                           eftweight = (isWWZEFT ? vvv.Common_LHEWeight_mg_reweighting()[ana.eft_reweighting_idx] * 0.1651 * 0.3272 * 0.3272 * 0.1009 /0.0005972 : 1.)
                                     * (isWZZEFT ? vvv.Common_LHEWeight_mg_reweighting()[ana.eft_reweighting_idx] : 1.)
                                     * (isZZZEFT ? vvv.Common_LHEWeight_mg_reweighting()[ana.eft_reweighting_idx] : 1.)
                                     ;

                           float weight = ana.eft_reweighting_idx != 0 ? (eftweight - sm_weight) : sm_weight;

                           return vvv.Var_4LepMET_scaleLumi() * vvv.Common_genWeight() * weight;
                       } );
    ana.cutflow.addCutToLastActiveCut("CutAdditionalLeptonID", 
                                      [&]()
                                      {
                                          std::vector<int> Zcand_lep_idxs = {vvv.Var_4LepMET_Zcand_lep_idx_0(), vvv.Var_4LepMET_Zcand_lep_idx_1()};
                                          for (auto& idx : Zcand_lep_idxs)
                                          {
                                              if (abs(vvv.Common_lep_pdgid()[idx]) == 11)
                                              {
                                                  // if (not (vvv.Common_lep_sip3d()[idx] < 4)) return false;
                                                  if (not (vvv.Common_lep_relIso03_all()[idx] < 0.2)) return false;
                                              }
                                              else if (abs(vvv.Common_lep_pdgid()[idx]) == 13)
                                              {
                                                  // if (not (vvv.Common_lep_sip3d()[idx] < 4)) return false;
                                                  if (not ((vvv.Common_lep_ID()[idx] >> 2) >= 2)) return false;
                                              }
                                          }
                                          std::vector<int> other_lep_idxs = {vvv.Var_4LepMET_other_lep_idx_0(), vvv.Var_4LepMET_other_lep_idx_1()};
                                          for (auto& idx : other_lep_idxs)
                                          {
                                              if (abs(vvv.Common_lep_pdgid()[idx]) == 11)
                                              {
                                                  // if (not (vvv.Common_lep_sip3d()[idx] < 4)) return false;
                                                  if (not (vvv.Common_lep_relIso03_all()[idx] < 0.2)) return false;
                                                  if (not (vvv.Common_lep_ID()[idx] & (1 << 4) /* IsoWP90 */)) return false;
                                              }
                                              else if (abs(vvv.Common_lep_pdgid()[idx]) == 13)
                                              {
                                                  // if (not (vvv.Common_lep_sip3d()[idx] < 4)) return false;
                                                  if (not ((vvv.Common_lep_ID()[idx] >> 2) >= 3)) return false;
                                              }
                                          }
                                          if (not (vvv.Var_4LepMET_other_lep_p4_1().pt() > 15)) return false;
                                          if (not (vvv.Var_4LepMET_Zcand_lep_p4_1().pt() > 15)) return false;
                                          return true;
                                      },
                                      [&]()
                                      {
                                          // return vvv.Common_isData() ? 1. : vvv.Common_event_lepSF();
                                          return 1.;
                                      });
    ana.cutflow.addCutToLastActiveCut("CutDuplicate", UNITY,
                                      [&]()
                                      {
                                          if (vvv.Common_isData())
                                          {
                                              duplicate_removal::DorkyEventIdentifier id(vvv.Common_run(), vvv.Common_evt(), vvv.Common_lumi());
                                              if (is_duplicate(id))
                                                  return false;
                                              else
                                                  return true;
                                          }
                                          else
                                          {
                                              return true;
                                          }
                                      } );
    // Apply min Mll > 12 GeV selection on any pair of charged leptons
    ana.cutflow.addCutToLastActiveCut("CutVetoLowMassResonance",
            [&]()
            {

                // Loop over every pair charged lepton pairs and require that they have > 12 GeV mass
                for (unsigned int ilep = 0; ilep < vvv.Common_lep_pdgid().size(); ++ilep)
                {
                    const LorentzVector& ip4 = vvv.Common_lep_p4()[ilep];
                    for (unsigned int jlep = ilep + 1; jlep < vvv.Common_lep_pdgid().size(); ++jlep)
                    {
                        const LorentzVector& jp4 = vvv.Common_lep_p4()[jlep];
                        if (not ((ip4 + jp4).mass() > 12))
                            return false;
                    }
                }

                // If made to this point than it passed
                return true;

            }, UNITY);
    ana.cutflow.addCutToLastActiveCut("CutVetoZHZWW", [&]()
                                      {
                                          if (ana.looper.getCurrentFileName().Contains("VHToNonbb"))
                                          {
                                              if (vvv.Common_gen_VH_channel() == 1)
                                              {
                                                  return false;
                                              }
                                          }
                                          return true;
                                      }, UNITY);
    ana.cutflow.addCutToLastActiveCut("CutPresel", UNITY, UNITY);

    ana.cutflow.getCut("CutPresel");
    ana.cutflow.addCutToLastActiveCut("CutBVeto", [&]() { return vvv.Common_nb_loose() == 0; }, [&]() { return vvv.Common_isData() ? 1. : vvv.Common_event_looseBtagSF(); } );
    ana.cutflow.getCut("CutPresel");
    ana.cutflow.addCutToLastActiveCut("CutBTag", [&]() { return vvv.Common_nb_loose() > 0; }, [&]() { return vvv.Common_isData() ? 1. : vvv.Common_event_looseBtagSF(); } );

    ana.cutflow.getCut("CutBVeto");
    ana.cutflow.addCutToLastActiveCut("CutEMu", [&]() { return vvv.Cut_4LepMET_emuChannel(); }, UNITY);
    ana.cutflow.addCutToLastActiveCut("CutEMuMT2", [&]() { return (vvv.Var_4LepMET_other_mll() < 100. and vvv.Var_4LepMET_mt2() > 25.) or (vvv.Var_4LepMET_other_mll() > 100.); }, UNITY);
    ana.cutflow.getCut("CutBVeto");
    ana.cutflow.addCutToLastActiveCut("CutOffZ", [&]() { return vvv.Cut_4LepMET_offzChannel(); }, UNITY);
    ana.cutflow.getCut("CutBVeto");
    ana.cutflow.addCutToLastActiveCut("CutOnZ", [&]() { return vvv.Cut_4LepMET_onzChannel(); }, UNITY);

    // ana.cutflow.getCut("CutPresel");
    // ana.cutflow.addCutToLastActiveCut("CutNotOnZ", [&]() { return vvv.Cut_4LepMET_offzChannel() or vvv.Cut_4LepMET_emuChannel(); }, UNITY);

    // ana.cutflow.getCut("CutOffZ");
    // ana.cutflow.addCutToLastActiveCut("CutOffZBV", [&]() { return vvv.Common_nb_loose() == 0; }, UNITY);

    // ana.cutflow.getCut("CutOnZ");

    // ana.cutflow.getCut("CutEMu");
    // ana.cutflow.addCutToLastActiveCut("CutEMuBV", [&]() { return vvv.Common_nb_loose() == 0; }, UNITY);

    // ana.cutflow.getCut("CutEMu");
    // ana.cutflow.addCutToLastActiveCut("CutEMuBT", [&]() { return vvv.Common_nb_loose() > 0; }, UNITY);

    // Print cut structure
    ana.cutflow.printCuts();

    // Histogram utility object that is used to define the histograms
    ana.histograms.addHistogram("Zcand_mll", 180, 60, 120, [&]() { return vvv.Var_4LepMET_Zcand_mll(); } );
    ana.histograms.addHistogram("Zcand_mll_full", 180, 0, 120, [&]() { return vvv.Var_4LepMET_Zcand_mll(); } );
    ana.histograms.addHistogram("Zcand_lep0_pt", 180, 0, 150, [&]() { return vvv.Var_4LepMET_Zcand_lep_p4_0().pt(); } );
    ana.histograms.addHistogram("Zcand_lep1_pt", 180, 0, 150, [&]() { return vvv.Var_4LepMET_Zcand_lep_p4_1().pt(); } );
    ana.histograms.addHistogram("other_mll", 180, 60, 120, [&]() { return vvv.Var_4LepMET_other_mll(); } );
    ana.histograms.addHistogram("other_mll_full", 180, 0, 120, [&]() { return vvv.Var_4LepMET_other_mll(); } );
    ana.histograms.addHistogram("other_mll_varbin", {0., 40., 60., 100., 200.}, [&]() { return vvv.Var_4LepMET_other_mll(); } );
    ana.histograms.addHistogram("other_lep0_pt", 180, 0, 150, [&]() { return vvv.Var_4LepMET_other_lep_p4_0().pt(); } );
    ana.histograms.addHistogram("other_lep1_pt", 180, 0, 150, [&]() { return vvv.Var_4LepMET_other_lep_p4_1().pt(); } );
    ana.histograms.addHistogram("other_lep0_sip3d", 180, 0, 10, [&]() { return abs(vvv.Common_lep_sip3d()[vvv.Var_4LepMET_other_lep_idx_0()]); } );
    ana.histograms.addHistogram("other_lep1_sip3d", 180, 0, 10, [&]() { return abs(vvv.Common_lep_sip3d()[vvv.Var_4LepMET_other_lep_idx_1()]); } );
    ana.histograms.addHistogram("other_lep0_dxy", 180, 0, 0.01, [&]() { return abs(vvv.Common_lep_dxy()[vvv.Var_4LepMET_other_lep_idx_0()]); } );
    ana.histograms.addHistogram("other_lep1_dxy", 180, 0, 0.01, [&]() { return abs(vvv.Common_lep_dxy()[vvv.Var_4LepMET_other_lep_idx_1()]); } );
    ana.histograms.addHistogram("other_lep0_dz", 180, 0, 0.1, [&]() { return abs(vvv.Common_lep_dz()[vvv.Var_4LepMET_other_lep_idx_0()]); } );
    ana.histograms.addHistogram("other_lep1_dz", 180, 0, 0.1, [&]() { return abs(vvv.Common_lep_dz()[vvv.Var_4LepMET_other_lep_idx_1()]); } );
    ana.histograms.addHistogram("other_lep_diffdz", 180, -0.5, 0.5, [&]() { return abs(vvv.Common_lep_dz()[vvv.Var_4LepMET_other_lep_idx_0()]-vvv.Common_lep_dz()[vvv.Var_4LepMET_other_lep_idx_1()]); } );
    ana.histograms.addHistogram("MET", 180, 0, 150, [&]() { return vvv.Common_met_p4().pt(); } );
    ana.histograms.addHistogram("DRll", 180, 0, 5, [&]() { return DRll; } );
    ana.histograms.addHistogram("STLepFit", {0.0, 500.0, 1000.0, 1500.0, 2000.0, 2500.0}, [&]() { return STLep; } );
    ana.histograms.addHistogram("STLepHadFit", {0.0, 500.0, 1000.0, 1500.0, 2000.0, 2500.0}, [&]() { return STLepHad; } );
    ana.histograms.addHistogram("STLep", 180, 0., 3000., [&]() { return STLep; } );
    ana.histograms.addHistogram("STLepHad", 180, 0., 3000., [&]() { return STLepHad; } );
    ana.histograms.addHistogram("MT2", 180, 0., 150., [&]() { return vvv.Var_4LepMET_mt2(); } );
    ana.histograms.addHistogram("nb", 5, 0, 5, [&]() { return vvv.Common_nb_loose(); } );
    ana.histograms.addHistogram("Yield", 1, 0, 1, [&]() { return 0; } );

    ana.histograms.addVecHistogram("SRBin", 7, 0, 7,
                                [&]()
                                {
                                    std::vector<float> rtn;
                                    if (vvv.Cut_4LepMET_emuChannel())
                                    {
                                        if (vvv.Var_4LepMET_other_mll() >   0. and vvv.Var_4LepMET_other_mll() <  40. and vvv.Var_4LepMET_mt2() > 25.)
                                            rtn.push_back(0.);
                                        if (vvv.Var_4LepMET_other_mll() >  40. and vvv.Var_4LepMET_other_mll() <  60. and vvv.Var_4LepMET_mt2() > 25.)
                                            rtn.push_back(1.);
                                        if (vvv.Var_4LepMET_other_mll() >  60. and vvv.Var_4LepMET_other_mll() < 100. and vvv.Var_4LepMET_mt2() > 25.)
                                            rtn.push_back(2.);
                                        if (vvv.Var_4LepMET_other_mll() > 100.)
                                            rtn.push_back(3.);
                                    }
                                    else if (vvv.Cut_4LepMET_offzChannel())
                                    {
                                        if (vvv.Common_met_p4().pt() > 120.)
                                        {
                                            rtn.push_back(4.);
                                        }
                                        if (vvv.Common_met_p4().pt() > 70. and vvv.Common_met_p4().pt() < 120.)
                                        {
                                            if (Pt4l > 40. and Pt4l < 70.)
                                                rtn.push_back(5.);
                                            if (Pt4l > 70.)
                                                rtn.push_back(6.);
                                        }
                                    }
                                    return rtn;
                                } );

    // // Book cutflows
    // ana.cutflow.bookCutflows();

    // Book Histograms
    ana.cutflow.bookHistogramsForCutAndBelow(ana.histograms, "CutDuplicate"); // if just want to book everywhere

    // Looping input file
    while (ana.looper.nextEvent())
    {

        // If splitting jobs are requested then determine whether to process the event or not based on remainder
        if (result.count("job_index") and result.count("nsplit_jobs"))
        {
            if (ana.looper.getNEventsProcessed() % ana.nsplit_jobs != (unsigned int) ana.job_index)
                continue;
        }

        DRll = RooUtil::Calc::DeltaR(vvv.Var_4LepMET_Zcand_lep_p4_0(), vvv.Var_4LepMET_Zcand_lep_p4_1());
        STLep = vvv.Var_4LepMET_Zcand_lep_p4_0().pt() + vvv.Var_4LepMET_Zcand_lep_p4_1().pt() + vvv.Var_4LepMET_other_lep_p4_0().pt() + vvv.Var_4LepMET_other_lep_p4_1().pt() + vvv.Common_met_p4().pt();
        STLepHad = vvv.Var_4LepMET_Zcand_lep_p4_0().pt() + vvv.Var_4LepMET_Zcand_lep_p4_1().pt() + vvv.Var_4LepMET_other_lep_p4_0().pt() + vvv.Var_4LepMET_other_lep_p4_1().pt() + vvv.Common_met_p4().pt() + (vvv.Common_fatjet_p4().size() > 0 ? vvv.Common_fatjet_p4()[0].pt() : 0.);
        Pt4l = (vvv.Var_4LepMET_Zcand_lep_p4_0() + vvv.Var_4LepMET_Zcand_lep_p4_1() + vvv.Var_4LepMET_other_lep_p4_0() + vvv.Var_4LepMET_other_lep_p4_1()).pt();

        //Do what you need to do in for each event here
        //To save use the following function
        ana.cutflow.fill();
    }

    // Writing output file
    ana.cutflow.saveOutput();

    // The below can be sometimes crucial
    delete ana.output_tfile;
}

// #[1/252] FS0:-3e-08
// #[2/252] FS0:-1.5e-08
// #[3/252] FS0:-1e-08
// #[4/252] FS0:-8e-09
// #[5/252] FS0:-4e-09
// #[6/252] FS0:-2e-09
// #[7/252] FS0:2e-09
// #[8/252] FS0:4e-09
// #[9/252] FS0:8e-09
// #[10/252] FS0:1e-08
// #[11/252] FS0:1.5e-08
// #[12/252] FS0:3e-08
// #[13/252] FS1:-3e-08
// #[14/252] FS1:-1.5e-08
// #[15/252] FS1:-1e-08
// #[16/252] FS1:-8e-09
// #[17/252] FS1:-4e-09
// #[18/252] FS1:-2e-09
// #[19/252] FS1:2e-09
// #[20/252] FS1:4e-09
// #[21/252] FS1:8e-09
// #[22/252] FS1:1e-08
// #[23/252] FS1:1.5e-08
// #[24/252] FS1:3e-08
// #[25/252] FS2:-3e-08
// #[26/252] FS2:-1.5e-08
// #[27/252] FS2:-1e-08
// #[28/252] FS2:-8e-09
// #[29/252] FS2:-4e-09
// #[30/252] FS2:-2e-09
// #[31/252] FS2:2e-09
// #[32/252] FS2:4e-09
// #[33/252] FS2:8e-09
// #[34/252] FS2:1e-08
// #[35/252] FS2:1.5e-08
// #[36/252] FS2:3e-08
// #[37/252] FM0:-3e-11
// #[38/252] FM0:-1.5e-11
// #[39/252] FM0:-1e-11
// #[40/252] FM0:-8e-12
// #[41/252] FM0:-4e-12
// #[42/252] FM0:-2e-12
// #[43/252] FM0:2e-12
// #[44/252] FM0:4e-12
// #[45/252] FM0:8e-12
// #[46/252] FM0:1e-11
// #[47/252] FM0:1.5e-11
// #[48/252] FM0:3e-11
// #[49/252] FM1:-3e-11
// #[50/252] FM1:-1.5e-11
// #[51/252] FM1:-1e-11
// #[52/252] FM1:-8e-12
// #[53/252] FM1:-4e-12
// #[54/252] FM1:-2e-12
// #[55/252] FM1:2e-12
// #[56/252] FM1:4e-12
// #[57/252] FM1:8e-12
// #[58/252] FM1:1e-11
// #[59/252] FM1:1.5e-11
// #[60/252] FM1:3e-11
// #[61/252] FM2:-3e-11
// #[62/252] FM2:-1.5e-11
// #[63/252] FM2:-1e-11
// #[64/252] FM2:-8e-12
// #[65/252] FM2:-4e-12
// #[66/252] FM2:-2e-12
// #[67/252] FM2:2e-12
// #[68/252] FM2:4e-12
// #[69/252] FM2:8e-12
// #[70/252] FM2:1e-11
// #[71/252] FM2:1.5e-11
// #[72/252] FM2:3e-11
// #[73/252] FM3:-3e-11
// #[74/252] FM3:-1.5e-11
// #[75/252] FM3:-1e-11
// #[76/252] FM3:-8e-12
// #[77/252] FM3:-4e-12
// #[78/252] FM3:-2e-12
// #[79/252] FM3:2e-12
// #[80/252] FM3:4e-12
// #[81/252] FM3:8e-12
// #[82/252] FM3:1e-11
// #[83/252] FM3:1.5e-11
// #[84/252] FM3:3e-11
// #[85/252] FM4:-3e-11
// #[86/252] FM4:-1.5e-11
// #[87/252] FM4:-1e-11
// #[88/252] FM4:-8e-12
// #[89/252] FM4:-4e-12
// #[90/252] FM4:-2e-12
// #[91/252] FM4:2e-12
// #[92/252] FM4:4e-12
// #[93/252] FM4:8e-12
// #[94/252] FM4:1e-11
// #[95/252] FM4:1.5e-11
// #[96/252] FM4:3e-11
// #[97/252] FM5:-3e-11
// #[98/252] FM5:-1.5e-11
// #[99/252] FM5:-1e-11
// #[100/252] FM5:-8e-12
// #[101/252] FM5:-4e-12
// #[102/252] FM5:-2e-12
// #[103/252] FM5:2e-12
// #[104/252] FM5:4e-12
// #[105/252] FM5:8e-12
// #[106/252] FM5:1e-11
// #[107/252] FM5:1.5e-11
// #[108/252] FM5:3e-11
// #[109/252] FM6:-3e-11
// #[110/252] FM6:-1.5e-11
// #[111/252] FM6:-1e-11
// #[112/252] FM6:-8e-12
// #[113/252] FM6:-4e-12
// #[114/252] FM6:-2e-12
// #[115/252] FM6:2e-12
// #[116/252] FM6:4e-12
// #[117/252] FM6:8e-12
// #[118/252] FM6:1e-11
// #[119/252] FM6:1.5e-11
// #[120/252] FM6:3e-11
// #[121/252] FM7:-3e-11
// #[122/252] FM7:-1.5e-11
// #[123/252] FM7:-1e-11
// #[124/252] FM7:-8e-12
// #[125/252] FM7:-4e-12
// #[126/252] FM7:-2e-12
// #[127/252] FM7:2e-12
// #[128/252] FM7:4e-12
// #[129/252] FM7:8e-12
// #[130/252] FM7:1e-11
// #[131/252] FM7:1.5e-11
// #[132/252] FM7:3e-11
// #[133/252] FT0:-3e-12
// #[134/252] FT0:-1.5e-12
// #[135/252] FT0:-1e-12
// #[136/252] FT0:-8e-13
// #[137/252] FT0:-4e-13
// #[138/252] FT0:-2e-13
// #[139/252] FT0:2e-13
// #[140/252] FT0:4e-13
// #[141/252] FT0:8e-13
// #[142/252] FT0:1e-12
// #[143/252] FT0:1.5e-12
// #[144/252] FT0:3e-12
// #[145/252] FT1:-3e-12
// #[146/252] FT1:-1.5e-12
// #[147/252] FT1:-1e-12
// #[148/252] FT1:-8e-13
// #[149/252] FT1:-4e-13
// #[150/252] FT1:-2e-13
// #[151/252] FT1:2e-13
// #[152/252] FT1:4e-13
// #[153/252] FT1:8e-13
// #[154/252] FT1:1e-12
// #[155/252] FT1:1.5e-12
// #[156/252] FT1:3e-12
// #[157/252] FT2:-3e-12
// #[158/252] FT2:-1.5e-12
// #[159/252] FT2:-1e-12
// #[160/252] FT2:-8e-13
// #[161/252] FT2:-4e-13
// #[162/252] FT2:-2e-13
// #[163/252] FT2:2e-13
// #[164/252] FT2:4e-13
// #[165/252] FT2:8e-13
// #[166/252] FT2:1e-12
// #[167/252] FT2:1.5e-12
// #[168/252] FT2:3e-12
// #[121/252] FT3:-3e-11
// #[122/252] FT3:-1.5e-11
// #[123/252] FT3:-1e-11
// #[124/252] FT3:-8e-12
// #[125/252] FT3:-4e-12
// #[126/252] FT3:-2e-12
// #[127/252] FT3:2e-12
// #[128/252] FT3:4e-12
// #[129/252] FT3:8e-12
// #[130/252] FT3:1e-11
// #[131/252] FT3:1.5e-11
// #[132/252] FT3:3e-11
// #[133/252] FT4:-3e-11
// #[134/252] FT4:-1.5e-11
// #[135/252] FT4:-1e-11
// #[136/252] FT4:-8e-12
// #[137/252] FT4:-4e-12
// #[138/252] FT4:-2e-12
// #[139/252] FT4:2e-12
// #[140/252] FT4:4e-12
// #[141/252] FT4:8e-12
// #[142/252] FT4:1e-11
// #[143/252] FT4:1.5e-11
// #[144/252] FT4:3e-11
// #[193/252] FT5:-3e-11
// #[194/252] FT5:-1.5e-11
// #[195/252] FT5:-1e-11
// #[196/252] FT5:-8e-12
// #[197/252] FT5:-4e-12
// #[198/252] FT5:-2e-12
// #[199/252] FT5:2e-12
// #[200/252] FT5:4e-12
// #[201/252] FT5:8e-12
// #[202/252] FT5:1e-11
// #[203/252] FT5:1.5e-11
// #[204/252] FT5:3e-11
// #[205/252] FT6:-3e-11
// #[206/252] FT6:-1.5e-11
// #[207/252] FT6:-1e-11
// #[208/252] FT6:-8e-12
// #[209/252] FT6:-4e-12
// #[210/252] FT6:-2e-12
// #[211/252] FT6:2e-12
// #[212/252] FT6:4e-12
// #[213/252] FT6:8e-12
// #[214/252] FT6:1e-11
// #[215/252] FT6:1.5e-11
// #[216/252] FT6:3e-11
// #[217/252] FT7:-3e-11
// #[218/252] FT7:-1.5e-11
// #[219/252] FT7:-1e-11
// #[220/252] FT7:-8e-12
// #[221/252] FT7:-4e-12
// #[222/252] FT7:-2e-12
// #[223/252] FT7:2e-12
// #[224/252] FT7:4e-12
// #[225/252] FT7:8e-12
// #[226/252] FT7:1e-11
// #[227/252] FT7:1.5e-11
// #[228/252] FT7:3e-11
// #[229/252] FT8:-3e-11
// #[230/252] FT8:-1.5e-11
// #[231/252] FT8:-1e-11
// #[232/252] FT8:-8e-12
// #[233/252] FT8:-4e-12
// #[234/252] FT8:-2e-12
// #[235/252] FT8:2e-12
// #[236/252] FT8:4e-12
// #[237/252] FT8:8e-12
// #[238/252] FT8:1e-11
// #[239/252] FT8:1.5e-11
// #[240/252] FT8:3e-11
// #[241/252] FT9:-3e-11
// #[242/252] FT9:-1.5e-11
// #[243/252] FT9:-1e-11
// #[244/252] FT9:-8e-12
// #[245/252] FT9:-4e-12
// #[246/252] FT9:-2e-12
// #[247/252] FT9:2e-12
// #[248/252] FT9:4e-12
// #[249/252] FT9:8e-12
// #[250/252] FT9:1e-11
// #[251/252] FT9:1.5e-11
// #[252/252] FT9:3e-11
// #[1/228] FS0:-3e-08              #[1/228] FS0:-3e-08
// #[2/228] FS0:-1.5e-08            #[2/228] FS0:-1.5e-08
// #[3/228] FS0:-1e-08              #[3/228] FS0:-1e-08
// #[4/228] FS0:-8e-09              #[4/228] FS0:-8e-09
// #[5/228] FS0:-4e-09              #[5/228] FS0:-4e-09
// #[6/228] FS0:-2e-09              #[6/228] FS0:-2e-09
// #[7/228] FS0:2e-09               #[7/228] FS0:2e-09
// #[8/228] FS0:4e-09               #[8/228] FS0:4e-09
// #[9/228] FS0:8e-09               #[9/228] FS0:8e-09
// #[10/228] FS0:1e-08              #[10/228] FS0:1e-08
// #[11/228] FS0:1.5e-08            #[11/228] FS0:1.5e-08
// #[12/228] FS0:3e-08              #[12/228] FS0:3e-08
// #[13/228] FS1:-3e-08             #[13/228] FS1:-3e-08
// #[14/228] FS1:-1.5e-08           #[14/228] FS1:-1.5e-08
// #[15/228] FS1:-1e-08             #[15/228] FS1:-1e-08
// #[16/228] FS1:-8e-09             #[16/228] FS1:-8e-09
// #[17/228] FS1:-4e-09             #[17/228] FS1:-4e-09
// #[18/228] FS1:-2e-09             #[18/228] FS1:-2e-09
// #[19/228] FS1:2e-09              #[19/228] FS1:2e-09
// #[20/228] FS1:4e-09              #[20/228] FS1:4e-09
// #[21/228] FS1:8e-09              #[21/228] FS1:8e-09
// #[22/228] FS1:1e-08              #[22/228] FS1:1e-08
// #[23/228] FS1:1.5e-08            #[23/228] FS1:1.5e-08
// #[24/228] FS1:3e-08              #[24/228] FS1:3e-08
// #[25/228] FS2:-3e-08             #[25/228] FS2:-3e-08
// #[26/228] FS2:-1.5e-08           #[26/228] FS2:-1.5e-08
// #[27/228] FS2:-1e-08             #[27/228] FS2:-1e-08
// #[28/228] FS2:-8e-09             #[28/228] FS2:-8e-09
// #[29/228] FS2:-4e-09             #[29/228] FS2:-4e-09
// #[30/228] FS2:-2e-09             #[30/228] FS2:-2e-09
// #[31/228] FS2:2e-09              #[31/228] FS2:2e-09
// #[32/228] FS2:4e-09              #[32/228] FS2:4e-09
// #[33/228] FS2:8e-09              #[33/228] FS2:8e-09
// #[34/228] FS2:1e-08              #[34/228] FS2:1e-08
// #[35/228] FS2:1.5e-08            #[35/228] FS2:1.5e-08
// #[36/228] FS2:3e-08              #[36/228] FS2:3e-08
// #[37/228] FM0:-3e-11             #[37/228] FM0:-3e-11
// #[38/228] FM0:-1.5e-11           #[38/228] FM0:-1.5e-11
// #[39/228] FM0:-1e-11             #[39/228] FM0:-1e-11
// #[40/228] FM0:-8e-12             #[40/228] FM0:-8e-12
// #[41/228] FM0:-4e-12             #[41/228] FM0:-4e-12
// #[42/228] FM0:-2e-12             #[42/228] FM0:-2e-12
// #[43/228] FM0:2e-12              #[43/228] FM0:2e-12
// #[44/228] FM0:4e-12              #[44/228] FM0:4e-12
// #[45/228] FM0:8e-12              #[45/228] FM0:8e-12
// #[46/228] FM0:1e-11              #[46/228] FM0:1e-11
// #[47/228] FM0:1.5e-11            #[47/228] FM0:1.5e-11
// #[48/228] FM0:3e-11              #[48/228] FM0:3e-11
// #[49/228] FM1:-3e-11             #[49/228] FM1:-3e-11
// #[50/228] FM1:-1.5e-11           #[50/228] FM1:-1.5e-11
// #[51/228] FM1:-1e-11             #[51/228] FM1:-1e-11
// #[52/228] FM1:-8e-12             #[52/228] FM1:-8e-12
// #[53/228] FM1:-4e-12             #[53/228] FM1:-4e-12
// #[54/228] FM1:-2e-12             #[54/228] FM1:-2e-12
// #[55/228] FM1:2e-12              #[55/228] FM1:2e-12
// #[56/228] FM1:4e-12              #[56/228] FM1:4e-12
// #[57/228] FM1:8e-12              #[57/228] FM1:8e-12
// #[58/228] FM1:1e-11              #[58/228] FM1:1e-11
// #[59/228] FM1:1.5e-11            #[59/228] FM1:1.5e-11
// #[60/228] FM1:3e-11              #[60/228] FM1:3e-11
// #[61/228] FM2:-3e-11             #[61/228] FM2:-3e-11
// #[62/228] FM2:-1.5e-11           #[62/228] FM2:-1.5e-11
// #[63/228] FM2:-1e-11             #[63/228] FM2:-1e-11
// #[64/228] FM2:-8e-12             #[64/228] FM2:-8e-12
// #[65/228] FM2:-4e-12             #[65/228] FM2:-4e-12
// #[66/228] FM2:-2e-12             #[66/228] FM2:-2e-12
// #[67/228] FM2:2e-12              #[67/228] FM2:2e-12
// #[68/228] FM2:4e-12              #[68/228] FM2:4e-12
// #[69/228] FM2:8e-12              #[69/228] FM2:8e-12
// #[70/228] FM2:1e-11              #[70/228] FM2:1e-11
// #[71/228] FM2:1.5e-11            #[71/228] FM2:1.5e-11
// #[72/228] FM2:3e-11              #[72/228] FM2:3e-11
// #[73/228] FM3:-3e-11             #[73/228] FM3:-3e-11
// #[74/228] FM3:-1.5e-11           #[74/228] FM3:-1.5e-11
// #[75/228] FM3:-1e-11             #[75/228] FM3:-1e-11
// #[76/228] FM3:-8e-12             #[76/228] FM3:-8e-12
// #[77/228] FM3:-4e-12             #[77/228] FM3:-4e-12
// #[78/228] FM3:-2e-12             #[78/228] FM3:-2e-12
// #[79/228] FM3:2e-12              #[79/228] FM3:2e-12
// #[80/228] FM3:4e-12              #[80/228] FM3:4e-12
// #[81/228] FM3:8e-12              #[81/228] FM3:8e-12
// #[82/228] FM3:1e-11              #[82/228] FM3:1e-11
// #[83/228] FM3:1.5e-11            #[83/228] FM3:1.5e-11
// #[84/228] FM3:3e-11              #[84/228] FM3:3e-11
// #[85/228] FM4:-3e-11             #[85/228] FM4:-3e-11
// #[86/228] FM4:-1.5e-11           #[86/228] FM4:-1.5e-11
// #[87/228] FM4:-1e-11             #[87/228] FM4:-1e-11
// #[88/228] FM4:-8e-12             #[88/228] FM4:-8e-12
// #[89/228] FM4:-4e-12             #[89/228] FM4:-4e-12
// #[90/228] FM4:-2e-12             #[90/228] FM4:-2e-12
// #[91/228] FM4:2e-12              #[91/228] FM4:2e-12
// #[92/228] FM4:4e-12              #[92/228] FM4:4e-12
// #[93/228] FM4:8e-12              #[93/228] FM4:8e-12
// #[94/228] FM4:1e-11              #[94/228] FM4:1e-11
// #[95/228] FM4:1.5e-11            #[95/228] FM4:1.5e-11
// #[96/228] FM4:3e-11              #[96/228] FM4:3e-11
// #[97/228] FM5:-3e-11             #[97/228] FM5:-3e-11
// #[98/228] FM5:-1.5e-11           #[98/228] FM5:-1.5e-11
// #[99/228] FM5:-1e-11             #[99/228] FM5:-1e-11
// #[100/228] FM5:-8e-12            #[100/228] FM5:-8e-12
// #[101/228] FM5:-4e-12            #[101/228] FM5:-4e-12
// #[102/228] FM5:-2e-12            #[102/228] FM5:-2e-12
// #[103/228] FM5:2e-12             #[103/228] FM5:2e-12
// #[104/228] FM5:4e-12             #[104/228] FM5:4e-12
// #[105/228] FM5:8e-12             #[105/228] FM5:8e-12
// #[106/228] FM5:1e-11             #[106/228] FM5:1e-11
// #[107/228] FM5:1.5e-11           #[107/228] FM5:1.5e-11
// #[108/228] FM5:3e-11             #[108/228] FM5:3e-11
// #[109/228] FM6:-3e-11            #[109/228] FM6:-3e-11
// #[110/228] FM6:-1.5e-11          #[110/228] FM6:-1.5e-11
// #[111/228] FM6:-1e-11            #[111/228] FM6:-1e-11
// #[112/228] FM6:-8e-12            #[112/228] FM6:-8e-12
// #[113/228] FM6:-4e-12            #[113/228] FM6:-4e-12
// #[114/228] FM6:-2e-12            #[114/228] FM6:-2e-12
// #[115/228] FM6:2e-12             #[115/228] FM6:2e-12
// #[116/228] FM6:4e-12             #[116/228] FM6:4e-12
// #[117/228] FM6:8e-12             #[117/228] FM6:8e-12
// #[118/228] FM6:1e-11             #[118/228] FM6:1e-11
// #[119/228] FM6:1.5e-11           #[119/228] FM6:1.5e-11
// #[120/228] FM6:3e-11             #[120/228] FM6:3e-11
// #[121/228] FM7:-3e-11            #[121/228] FM7:-3e-11
// #[122/228] FM7:-1.5e-11          #[122/228] FM7:-1.5e-11
// #[123/228] FM7:-1e-11            #[123/228] FM7:-1e-11
// #[124/228] FM7:-8e-12            #[124/228] FM7:-8e-12
// #[125/228] FM7:-4e-12            #[125/228] FM7:-4e-12
// #[126/228] FM7:-2e-12            #[126/228] FM7:-2e-12
// #[127/228] FM7:2e-12             #[127/228] FM7:2e-12
// #[128/228] FM7:4e-12             #[128/228] FM7:4e-12
// #[129/228] FM7:8e-12             #[129/228] FM7:8e-12
// #[130/228] FM7:1e-11             #[130/228] FM7:1e-11
// #[131/228] FM7:1.5e-11           #[131/228] FM7:1.5e-11
// #[132/228] FM7:3e-11             #[132/228] FM7:3e-11
// #[133/228] FT0:-3e-12            #[133/228] FT0:-3e-12
// #[134/228] FT0:-1.5e-12          #[134/228] FT0:-1.5e-12
// #[135/228] FT0:-1e-12            #[135/228] FT0:-1e-12
// #[136/228] FT0:-8e-13            #[136/228] FT0:-8e-13
// #[137/228] FT0:-4e-13            #[137/228] FT0:-4e-13
// #[138/228] FT0:-2e-13            #[138/228] FT0:-2e-13
// #[139/228] FT0:2e-13             #[139/228] FT0:2e-13
// #[140/228] FT0:4e-13             #[140/228] FT0:4e-13
// #[141/228] FT0:8e-13             #[141/228] FT0:8e-13
// #[142/228] FT0:1e-12             #[142/228] FT0:1e-12
// #[143/228] FT0:1.5e-12           #[143/228] FT0:1.5e-12
// #[144/228] FT0:3e-12             #[144/228] FT0:3e-12
// #[145/228] FT1:-3e-12            #[145/228] FT1:-3e-12
// #[146/228] FT1:-1.5e-12          #[146/228] FT1:-1.5e-12
// #[147/228] FT1:-1e-12            #[147/228] FT1:-1e-12
// #[148/228] FT1:-8e-13            #[148/228] FT1:-8e-13
// #[149/228] FT1:-4e-13            #[149/228] FT1:-4e-13
// #[150/228] FT1:-2e-13            #[150/228] FT1:-2e-13
// #[151/228] FT1:2e-13             #[151/228] FT1:2e-13
// #[152/228] FT1:4e-13             #[152/228] FT1:4e-13
// #[153/228] FT1:8e-13             #[153/228] FT1:8e-13
// #[154/228] FT1:1e-12             #[154/228] FT1:1e-12
// #[155/228] FT1:1.5e-12           #[155/228] FT1:1.5e-12
// #[156/228] FT1:3e-12             #[156/228] FT1:3e-12
// #[157/228] FT2:-3e-12            #[157/228] FT2:-3e-12
// #[158/228] FT2:-1.5e-12          #[158/228] FT2:-1.5e-12
// #[159/228] FT2:-1e-12            #[159/228] FT2:-1e-12
// #[160/228] FT2:-8e-13            #[160/228] FT2:-8e-13
// #[161/228] FT2:-4e-13            #[161/228] FT2:-4e-13
// #[162/228] FT2:-2e-13            #[162/228] FT2:-2e-13
// #[163/228] FT2:2e-13             #[163/228] FT2:2e-13
// #[164/228] FT2:4e-13             #[164/228] FT2:4e-13
// #[165/228] FT2:8e-13             #[165/228] FT2:8e-13
// #[166/228] FT2:1e-12             #[166/228] FT2:1e-12
// #[167/228] FT2:1.5e-12           #[167/228] FT2:1.5e-12
// #[168/228] FT2:3e-12             #[168/228] FT2:3e-12
// #[121/228] FT3:-3e-11            #[121/228] FT3:-3e-11
// #[122/228] FT3:-1.5e-11          #[122/228] FT3:-1.5e-11
// #[123/228] FT3:-1e-11            #[123/228] FT3:-1e-11
// #[124/228] FT3:-8e-12            #[124/228] FT3:-8e-12
// #[125/228] FT3:-4e-12            #[125/228] FT3:-4e-12
// #[126/228] FT3:-2e-12            #[126/228] FT3:-2e-12
// #[127/228] FT3:2e-12             #[127/228] FT3:2e-12
// #[128/228] FT3:4e-12             #[128/228] FT3:4e-12
// #[129/228] FT3:8e-12             #[129/228] FT3:8e-12
// #[130/228] FT3:1e-11             #[130/228] FT3:1e-11
// #[131/228] FT3:1.5e-11           #[131/228] FT3:1.5e-11
// #[132/228] FT3:3e-11             #[132/228] FT3:3e-11
// #[133/228] FT4:-3e-11            #[133/228] FT4:-3e-11
// #[134/228] FT4:-1.5e-11          #[134/228] FT4:-1.5e-11
// #[135/228] FT4:-1e-11            #[135/228] FT4:-1e-11
// #[136/228] FT4:-8e-12            #[136/228] FT4:-8e-12
// #[137/228] FT4:-4e-12            #[137/228] FT4:-4e-12
// #[138/228] FT4:-2e-12            #[138/228] FT4:-2e-12
// #[139/228] FT4:2e-12             #[139/228] FT4:2e-12
// #[140/228] FT4:4e-12             #[140/228] FT4:4e-12
// #[141/228] FT4:8e-12             #[141/228] FT4:8e-12
// #[142/228] FT4:1e-11             #[142/228] FT4:1e-11
// #[143/228] FT4:1.5e-11           #[143/228] FT4:1.5e-11
// #[144/228] FT4:3e-11             #[144/228] FT4:3e-11
// #[193/228] FT5:-3e-11            #[193/228] FT5:-3e-11
// #[194/228] FT5:-1.5e-11          #[194/228] FT5:-1.5e-11
// #[195/228] FT5:-1e-11            #[195/228] FT5:-1e-11
// #[196/228] FT5:-8e-12            #[196/228] FT5:-8e-12
// #[197/228] FT5:-4e-12            #[197/228] FT5:-4e-12
// #[198/228] FT5:-2e-12            #[198/228] FT5:-2e-12
// #[199/228] FT5:2e-12             #[199/228] FT5:2e-12
// #[200/228] FT5:4e-12             #[200/228] FT5:4e-12
// #[201/228] FT5:8e-12             #[201/228] FT5:8e-12
// #[202/228] FT5:1e-11             #[202/228] FT5:1e-11
// #[203/228] FT5:1.5e-11           #[203/228] FT5:1.5e-11
// #[204/228] FT5:3e-11             #[204/228] FT5:3e-11
// #[205/228] FT6:-3e-11            #[205/228] FT6:-3e-11
// #[206/228] FT6:-1.5e-11          #[206/228] FT6:-1.5e-11
// #[207/228] FT6:-1e-11            #[207/228] FT6:-1e-11
// #[208/228] FT6:-8e-12            #[208/228] FT6:-8e-12
// #[209/228] FT6:-4e-12            #[209/228] FT6:-4e-12
// #[210/228] FT6:-2e-12            #[210/228] FT6:-2e-12
// #[211/228] FT6:2e-12             #[211/228] FT6:2e-12
// #[212/228] FT6:4e-12             #[212/228] FT6:4e-12
// #[213/228] FT6:8e-12             #[213/228] FT6:8e-12
// #[214/228] FT6:1e-11             #[214/228] FT6:1e-11
// #[215/228] FT6:1.5e-11           #[215/228] FT6:1.5e-11
// #[216/228] FT6:3e-11             #[216/228] FT6:3e-11
// #[217/228] FT7:-3e-11            #[217/228] FT7:-3e-11
// #[218/228] FT7:-1.5e-11          #[218/228] FT7:-1.5e-11
// #[219/228] FT7:-1e-11            #[219/228] FT7:-1e-11
// #[220/228] FT7:-8e-12            #[220/228] FT7:-8e-12
// #[221/228] FT7:-4e-12            #[221/228] FT7:-4e-12
// #[222/228] FT7:-2e-12            #[222/228] FT7:-2e-12
// #[223/228] FT7:2e-12             #[223/228] FT7:2e-12
// #[224/228] FT7:4e-12             #[224/228] FT7:4e-12
// #[225/228] FT7:8e-12             #[225/228] FT7:8e-12
// #[226/228] FT7:1e-11             #[226/228] FT7:1e-11
// #[227/228] FT7:1.5e-11           #[227/228] FT7:1.5e-11
// #[228/228] FT7:3e-11             #[228/228] FT7:3e-11
