#include "vvvtree.h"
#include "rooutil.h"
#include "cxxopts.h"
#include "ttreex.h"
#include "process.h"

float BLIND() { return vvv.Common_isData() ? 1.: 1.; }

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

    // Lepton ID boolean
    //bool new_lepton_ID = true;

    // TChain that holds the input TTree's
    TChain* events_tchain;

    // Custom Looper object to facilitate looping over many files
    RooUtil::Looper<vvvtree> looper;

    // Custom Cutflow framework
    RooUtil::Cutflow cutflow;

    // Custom Histograms object compatible with RooUtil::Cutflow framework
    RooUtil::Histograms histograms;

    RooUtil::Histograms histograms_3LepTau;

    // Custom TTree object for writing out BDT variables
    //TTree* tree_BDT;
    RooUtil::TTreeX* tx;
    RooUtil::TTreeX* tx2;
    
    // Create output ttree to write to the output root files
    //TTree* output_tree;
    //RooUtil::TTreeX output_tx;

};

AnalysisConfig ana;

// ./process INPUTFILEPATH OUTPUTFILE [NEVENTS]
int main(int argc, char** argv)
{
    bool writeTree = false;
    bool write_counts = true;
    bool new_lepton_ID = true;
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

    // Create ttree for TTreeX to hold the variables
    //ana.tree_BDT = new TTree("t_BDT","t_BDT");
    //ana.tx.setTree(ana.tree_BDT);
    ana.tx = new RooUtil::TTreeX("t_BDT_OF","t_BDT_OF");
    ana.tx2 = new RooUtil::TTreeX("t_BDT_SF","t_BDT_SF");

    // Create output ttree to write to the output root files
    //ana.output_tree = new TTree("t_BDT","t_BDT");
    //ana.output_tx.setTree(ana.output_tree);

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

    ana.cutflow.addCut("CutTrigger",
		       [&]()
		       {

			   bool passTrig = false;
			  
			   passTrig |= vvv.Common_HLT_DoubleEl();
		           passTrig |= vvv.Common_HLT_DoubleMu();
			   passTrig |= vvv.Common_HLT_MuEG(); 

			   return passTrig;
		       }, UNITY);

    ana.cutflow.addCutToLastActiveCut("CutWeight", UNITY, [&]()
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

                           if (ana.looper.getCurrentFileName().Contains("WWZJets"))
                           {
                               weight = 0.002067 / 0.0005972;
                           }
	
			   //float weight_0 = 0.000000;
			
			   //if (vvv.Var_4LepMET_scaleLumi() < 0.) return weight_0;

                           return vvv.Var_4LepMET_scaleLumi() * vvv.Common_genWeight() * weight;
                       } );
    ana.cutflow.addCutToLastActiveCut("CutAdditionalLeptonID", 
                                      [&]()
                                      {

				          
                                          // Z candidate leptons
                                          std::vector<int> Zcand_lep_idxs = {vvv.Var_4LepMET_Zcand_lep_idx_0(), vvv.Var_4LepMET_Zcand_lep_idx_1()};

                                          for (auto& idx : Zcand_lep_idxs)
                                          {

					      //Electron
                                              if (abs(vvv.Common_lep_pdgid()[idx]) == 11)
                                              {

                                                  if (not (vvv.Common_lep_sip3d()[idx] < 4)) return false;

                                                  if (not (vvv.Common_lep_relIso03_all()[idx] < 0.2)) return false;
                                              }
                                              // Muon
                                              else if (abs(vvv.Common_lep_pdgid()[idx]) == 13)
                                              {
                                                  if (not (vvv.Common_lep_sip3d()[idx] < 4)) return false;
						  
						  if (not (new_lepton_ID)){
                                                  	if (not ((vvv.Common_lep_ID()[idx] >> 2) >= 2)) return false;
						  }
                                              }
                                          }
                                          if (vvv.Common_evt()==1800329) std::cout << "1HERE" << std::endl;
                                          // W candidate leptons
                                          std::vector<int> other_lep_idxs = {vvv.Var_4LepMET_other_lep_idx_0(), vvv.Var_4LepMET_other_lep_idx_1()};
                                          //std::vector<int> other_lep_idxs = {Wcand_idx_0, Wcand_idx_1};

					
                                          for (auto& idx : other_lep_idxs)
                                          {
                                              
                                              // Electron
                                              if (abs(vvv.Common_lep_pdgid()[idx]) == 11)
                                              {
                                                  //if (vvv.Common_evt()==1800329)
                                                  //{
                                                  //    std::cout << "3ERE" << std::endl;
                                                  //}
                                                  if (not (vvv.Common_lep_sip3d()[idx] < 4)) return false;


                                                  if (not (vvv.Common_lep_relIso03_all()[idx] < 0.2)) return false;
						  
						  if (not (new_lepton_ID)){
                                                  	if (not (vvv.Common_lep_ID()[idx] & (1 << 4) /* IsoWP90 */)) return false;
						  }
                                              }
                                              // Muon
                                              else if (abs(vvv.Common_lep_pdgid()[idx]) == 13)
                                              {
						      

                                                  if (not (vvv.Common_lep_sip3d()[idx] < 4)) return false;
						
					          if (not (new_lepton_ID)){
                                                  	if (not ((vvv.Common_lep_ID()[idx] >> 2) >= 3)) return false;
						  }
                                              }
                                          }
                                          //if (not (vvv.Var_4LepMET_other_lep_p4_1().pt() > 15)) return false;         // Nominal value is 15
                                          //if (not (vvv.Var_4LepMET_Zcand_lep_p4_1().pt() > 15)) return false;         // Nominal value is 15
					  //if (not (vvv.Var_4LepMET_other_lep_p4_0().pt() > 25)) return false;
					  //if (not (vvv.Var_4LepMET_Zcand_lep_p4_0().pt() > 25)) return false;
					  double max_pt = std::max({vvv.Var_4LepMET_other_lep_p4_1().pt(),vvv.Var_4LepMET_Zcand_lep_p4_1().pt(),vvv.Var_4LepMET_other_lep_p4_0().pt(),vvv.Var_4LepMET_Zcand_lep_p4_0().pt()});
				          if (not ( max_pt > 25. )) return false;

					  double lepton_pts[] = {vvv.Var_4LepMET_Zcand_lep_p4_0().pt(),vvv.Var_4LepMET_Zcand_lep_p4_1().pt(),vvv.Var_4LepMET_other_lep_p4_0().pt(),vvv.Var_4LepMET_other_lep_p4_1().pt()};
					  int n = sizeof(lepton_pts) / sizeof(lepton_pts[0]) ; 
					  std::sort(lepton_pts,lepton_pts+n,greater<double>());
					  

					  if (not ( lepton_pts[1] > 15. )) return false;

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
			// Consider only opposite-charge pairs of leptons
			if ( not ( vvv.Common_lep_pdgid()[ilep]*vvv.Common_lep_pdgid()[jlep] < 0) ) continue;
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
    ana.cutflow.addCutToLastActiveCut("CutBVeto", [&]() { return vvv.Common_nb_loose_CSV() == 0; }, BLIND);
    ana.cutflow.getCut("CutPresel");
    ana.cutflow.addCutToLastActiveCut("CutBTag", [&]() { return vvv.Common_nb_loose_CSV() > 0; }, UNITY);

    ana.cutflow.getCut("CutBVeto");
    ana.cutflow.addCutToLastActiveCut("CutEMu", [&]() { return vvv.Cut_4LepMET_emuChannel(); }, BLIND);
    ana.cutflow.addCutToLastActiveCut("CutEMuMT2", [&]() { return (vvv.Var_4LepMET_other_mll() < 100. and vvv.Var_4LepMET_mt2_PuppiMET() > 25.) or (vvv.Var_4LepMET_other_mll() > 100.); }, UNITY);
    ana.cutflow.getCut("CutBVeto");
    ana.cutflow.addCutToLastActiveCut("CutOffZ", [&]() { return vvv.Cut_4LepMET_offzChannel(); }, UNITY);
    ana.cutflow.getCut("CutPresel");
    ana.cutflow.addCutToLastActiveCut("CutOnZ", [&]() { return vvv.Cut_4LepMET_onzChannel() and vvv.Common_nb_loose_CSV() == 0; }, UNITY);

    // How do ttZ events enter the signal region?

    ana.cutflow.getCut("CutEMuMT2");
    ana.cutflow.addCutToLastActiveCut("CutZeroJetsAll", [&]()
				      {
					 int nj_in = 0;
					 for (long unsigned int i = 0; i < vvv.Common_jet_idxs().size(); i++){
					      if ( std::abs(vvv.Common_jet_p4()[i].eta()) < 4.7  ) nj_in++;
					 }

					 return (nj_in == 0);
				      }, UNITY);

    ana.cutflow.getCut("CutEMuMT2");
    ana.cutflow.addCutToLastActiveCut("CutZeroJetsIn", [&]()
                                      {
                                         int nj_in = 0;
                                         for (long unsigned int i = 0; i < vvv.Common_jet_idxs().size(); i++){
                                              if ( std::abs(vvv.Common_jet_p4()[i].eta()) < 2.4  ) nj_in++;
                                         }

                                         return (nj_in == 0);
                                      }, UNITY);

    ana.cutflow.getCut("CutEMuMT2");
    ana.cutflow.addCutToLastActiveCut("CutZeroJetsOut", [&]()
                                      {
                                         int nj_in = 0;
                                         for (long unsigned int i = 0; i < vvv.Common_jet_idxs().size(); i++){
                                              if ( std::abs(vvv.Common_jet_p4()[i].eta()) > 2.4 && std::abs(vvv.Common_jet_p4()[i].eta()) < 4.7  ) nj_in++;
                                         }

                                         return (nj_in == 0);
                                      }, UNITY);

    ana.cutflow.getCut("CutEMuMT2");
    ana.cutflow.addCutToLastActiveCut("Cut1pJetsAll", [&]()
                                      {
                                         int nj_in = 0;
                                         for (long unsigned int i = 0; i < vvv.Common_jet_idxs().size(); i++){
                                              if ( std::abs(vvv.Common_jet_p4()[i].eta()) < 4.7  ) nj_in++;
                                         }

                                         return (nj_in > 0);
                                      }, UNITY);

    ana.cutflow.getCut("CutEMuMT2");
    ana.cutflow.addCutToLastActiveCut("Cut1pJetsIn", [&]()
                                      {
                                         int nj_in = 0;
                                         for (long unsigned int i = 0; i < vvv.Common_jet_idxs().size(); i++){
                                              if ( std::abs(vvv.Common_jet_p4()[i].eta()) < 2.4  ) nj_in++;
                                         }

                                         return (nj_in > 0);
                                      }, UNITY);

    ana.cutflow.getCut("CutEMuMT2");
    ana.cutflow.addCutToLastActiveCut("Cut1pJetsOut", [&]()
                                      {
                                         int nj_in = 0;
                                         for (long unsigned int i = 0; i < vvv.Common_jet_idxs().size(); i++){
                                              if ( std::abs(vvv.Common_jet_p4()[i].eta()) > 2.4 && std::abs(vvv.Common_jet_p4()[i].eta()) < 4.7  ) nj_in++;
                                         }

                                         return (nj_in > 0);
                                      }, UNITY);
 


    // ZZ CR: 4e final state
    ana.cutflow.getCut("CutOnZ");
    ana.cutflow.addCutToLastActiveCut("CutZZCR_4el", [&]() 
				      { 
					int nel = 0;
					int nmu = 0;
					if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 11 ) nel++;
					if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 13 ) nmu++;
					if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 13 ) nmu++;
					if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 13 ) nmu++;
					if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 13 ) nmu++;
					
					return ( nel == 4 and nmu == 0 );
				      }, UNITY);
    // ZZ CR: 4mu final state
    ana.cutflow.getCut("CutOnZ");
    ana.cutflow.addCutToLastActiveCut("CutZZCR_4mu", [&]()
				      { 
					int nel = 0;
                                        int nmu = 0;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 13 ) nmu++;

                                        return ( nel == 0 and nmu == 4 );
				      }, UNITY);
    // ZZ CR: 2e2mu final state
    ana.cutflow.getCut("CutOnZ");
    ana.cutflow.addCutToLastActiveCut("CutZZCR_2e2mu", [&]() 
				      { 
					int nel = 0;
                                        int nmu = 0;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 13 ) nmu++;

                                        return ( nel == 2 and nmu == 2 ); 
				      }, UNITY);
    // SF SR: 4e final state
    ana.cutflow.getCut("CutOffZ");
    ana.cutflow.addCutToLastActiveCut("CutSFSR_4el", [&]() 
				      { 
					int nel = 0;
                                        int nmu = 0;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 13 ) nmu++;

                                        return ( nel == 4 and nmu == 0 );
				      }, UNITY); 
    // SF SR: 4mu final state
    ana.cutflow.getCut("CutOffZ");
    ana.cutflow.addCutToLastActiveCut("CutSFSR_4mu", [&]() 
				      { 
					int nel = 0;
                                        int nmu = 0;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 13 ) nmu++;

                                        return ( nel == 0 and nmu == 4 );
				      }, UNITY);
    // SF SR: 2e2mu final state
    ana.cutflow.getCut("CutOffZ");
    ana.cutflow.addCutToLastActiveCut("CutSFSR_2e2mu", [&]() 
				      { 
					int nel = 0;
                                        int nmu = 0;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 13 ) nmu++;

                                        return ( nel == 2 and nmu == 2 );
				      }, UNITY);
    // OF SR: 3e1mu final state
    ana.cutflow.getCut("CutEMuMT2");
    ana.cutflow.addCutToLastActiveCut("CutOFSR_3e1mu", [&]() 
				      {
					int nel = 0;
                                        int nmu = 0;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 13 ) nmu++;

                                        return ( nel == 3 and nmu == 1 ); 
				      }, UNITY);
    // OF SR: 1e3mu final state
    ana.cutflow.getCut("CutEMuMT2");
    ana.cutflow.addCutToLastActiveCut("CutOFSR_1e3mu", [&]() 
				      { 
					int nel = 0;
                                        int nmu = 0;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_Zcand_lep_idx_1()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_0()]) == 13 ) nmu++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 11 ) nel++;
                                        if ( std::abs(vvv.Common_lep_pdgid()[vvv.Var_4LepMET_other_lep_idx_1()]) == 13 ) nmu++;

                                        return ( nel == 1 and nmu == 3 ); 
				      }, UNITY);

    ana.cutflow.getCut("CutOffZ");
    ana.cutflow.addCutToLastActiveCut("CutOffZ_trgMatch", [&]()
				      {
					 bool passTrigger = false;
					 std::vector<int> lep_idxs = {vvv.Var_4LepMET_Zcand_lep_idx_0(),vvv.Var_4LepMET_Zcand_lep_idx_1(),vvv.Var_4LepMET_other_lep_idx_0(),vvv.Var_4LepMET_other_lep_idx_1()};					            
					 for (auto& i : lep_idxs){
					     for (auto& j : lep_idxs){
						 if ( i == j ) continue;
						 if ( std::abs(vvv.Common_lep_pdgid()[i]) == 11 and std::abs(vvv.Common_lep_pdgid()[j]) == 11 ) 
						      passTrigger |= (vvv.Common_HLT_DoubleEl() and vvv.Common_lep_p4()[i].pt() > 25. and vvv.Common_lep_p4()[j].pt() > 15.);
						 else if ( std::abs(vvv.Common_lep_pdgid()[i]) == 13 and std::abs(vvv.Common_lep_pdgid()[j]) == 11 )
						      passTrigger |= (vvv.Common_HLT_MuEG() and vvv.Common_lep_p4()[i].pt() > 25. and vvv.Common_lep_p4()[j].pt() > 15.);
						 else if ( std::abs(vvv.Common_lep_pdgid()[i]) == 11 and std::abs(vvv.Common_lep_pdgid()[j]) == 13 )
                                                      passTrigger |= (vvv.Common_HLT_MuEG() and vvv.Common_lep_p4()[i].pt() > 25. and vvv.Common_lep_p4()[j].pt() > 10.);
						 else if ( std::abs(vvv.Common_lep_pdgid()[i]) == 13 and std::abs(vvv.Common_lep_pdgid()[j]) == 13 )
                                                      passTrigger |= (vvv.Common_HLT_DoubleMu() and vvv.Common_lep_p4()[i].pt() > 20. and vvv.Common_lep_p4()[j].pt() > 10.);
					     }
					 }
					 
					 return passTrigger;

				      }, UNITY);

    ana.cutflow.getCut("CutEMuMT2");
    ana.cutflow.addCutToLastActiveCut("CutEMuMT2_trgMatch", [&]()
                                      {
                                         bool passTrigger = false; 
                                         std::vector<int> lep_idxs = {vvv.Var_4LepMET_Zcand_lep_idx_0(),vvv.Var_4LepMET_Zcand_lep_idx_1(),vvv.Var_4LepMET_other_lep_idx_0(),vvv.Var_4LepMET_other_lep_idx_1()};     
                                         for (auto& i : lep_idxs){
                                             for (auto& j : lep_idxs){
                                                 if ( i == j ) continue;
                                                 if ( std::abs(vvv.Common_lep_pdgid()[i]) == 11 and std::abs(vvv.Common_lep_pdgid()[j]) == 11 ) 
                                                      passTrigger |= (vvv.Common_HLT_DoubleEl() and vvv.Common_lep_p4()[i].pt() > 25. and vvv.Common_lep_p4()[j].pt() > 15.);
                                                 else if ( std::abs(vvv.Common_lep_pdgid()[i]) == 13 and std::abs(vvv.Common_lep_pdgid()[j]) == 11 )
                                                      passTrigger |= (vvv.Common_HLT_MuEG() and vvv.Common_lep_p4()[i].pt() > 25. and vvv.Common_lep_p4()[j].pt() > 15.);
                                                 else if ( std::abs(vvv.Common_lep_pdgid()[i]) == 11 and std::abs(vvv.Common_lep_pdgid()[j]) == 13 )
                                                      passTrigger |= (vvv.Common_HLT_MuEG() and vvv.Common_lep_p4()[i].pt() > 25. and vvv.Common_lep_p4()[j].pt() > 10.);
                                                 else if ( std::abs(vvv.Common_lep_pdgid()[i]) == 13 and std::abs(vvv.Common_lep_pdgid()[j]) == 13 )
                                                      passTrigger |= (vvv.Common_HLT_DoubleMu() and vvv.Common_lep_p4()[i].pt() > 20. and vvv.Common_lep_p4()[j].pt() > 10.);
                                             }
                                         }

                                         return passTrigger;

                                      }, UNITY);

    // This is for the ttZ CR
    ana.cutflow.getCut("CutPresel");
    ana.cutflow.addCutToLastActiveCut("CutOppFlav", [&]() { return vvv.Cut_4LepMET_emuChannel(); }, BLIND);
    ana.cutflow.addCutToLastActiveCut("CutEMuBT", [&]() { return vvv.Common_nb_loose_CSV() > 1; }, UNITY);


    //ana.cutflow.addCut("CutWeight_3LepTau", UNITY, [&]()
    //                   {
    //                       bool isWWZEFT = ana.looper.getCurrentFileName().Contains("WWZ_RunIISummer20UL18NanoAODv9_FourleptonFilter_FilterFix_merged");
    //                       bool isWZZEFT = ana.looper.getCurrentFileName().Contains("WZZ_RunIISummer20UL18NanoAODv9_FourleptonFilter_FilterFix_merged");
    //                       bool isZZZEFT = ana.looper.getCurrentFileName().Contains("ZZZ_RunIISummer20UL18NanoAODv9_FourleptonFilter_FilterFix_merged");

    //                       float sm_weight = 1;
    //                       sm_weight = (isWWZEFT ? vvv.Common_LHEWeight_mg_reweighting()[0] * 0.1651 * 0.3272 * 0.3272 * 0.1009 /0.0005972 : 1.)
    //                                 * (isWZZEFT ? vvv.Common_LHEWeight_mg_reweighting()[0] : 1.)
    //                                 * (isZZZEFT ? vvv.Common_LHEWeight_mg_reweighting()[0] : 1.)
    //                                 ;
    //                                 float eftweight = 1;
    //                                 eftweight = (isWWZEFT ? vvv.Common_LHEWeight_mg_reweighting()[ana.eft_reweighting_idx] * 0.1651 * 0.3272 * 0.3272 * 0.1009 /0.0005972 : 1.)
    //                                 * (isWZZEFT ? vvv.Common_LHEWeight_mg_reweighting()[ana.eft_reweighting_idx] : 1.)
    //                                 * (isZZZEFT ? vvv.Common_LHEWeight_mg_reweighting()[ana.eft_reweighting_idx] : 1.)                                                                                                                                 ; 
  
    //                                 float weight = ana.eft_reweighting_idx != 0 ? (eftweight - sm_weight) : sm_weight;

    //    			     if (ana.looper.getCurrentFileName().Contains("WWZJets"))
    //                                 {
    //                                     weight = 0.002067 / 0.0005972;
    //                                 }
    //                                
    //    			     //float weight_0 = 0.;
 
    //    			     //if ( vvv.Var_3LepTauMET_scaleLumi() < -100. ) return weight_0;
    //                                 return vvv.Var_3LepTauMET_scaleLumi() * vvv.Common_genWeight() * weight;
    //                                                                                                                                                                                                                                                                                                                                                                                                                                                          } );
    //ana.cutflow.addCutToLastActiveCut("CutAdditionalLeptonID_3LepTau",
    //    			      [&]()
    //    			      {
    //    				  // Z candidate leptons
    //    				  std::vector<int> Zcand_lep_idxs = {vvv.Var_3LepTauMET_Zcand_lep_idx_0(), vvv.Var_3LepTauMET_Zcand_lep_idx_1()};

    //    				  for (auto& idx : Zcand_lep_idxs){
    //    				      // Electron
    //    				      if (abs(vvv.Common_lep_pdgid()[idx]) == 11){
    //    					  if (not (vvv.Common_lep_sip3d()[idx] < 4)) return false;
    //    					  if (not (vvv.Common_lep_relIso03_all()[idx] < 0.2)) return false;
    //    				      }
    //    				      // Muon
    //    				      if (abs(vvv.Common_lep_pdgid()[idx]) == 13){
    //    					  if (not (vvv.Common_lep_sip3d()[idx] < 4)) return false;
    //    					  if (not (new_lepton_ID)){
    //    					      if (not ((vvv.Common_lep_ID()[idx] >> 2) >= 2)) return false;
    //    					  }
    //    				      }
    //    				  }

    //    				  // W candidate lepton
    //    				  int W_idx = vvv.Var_3LepTauMET_other_lep_idx_0();
    //    				  // W candidate is electron
    //    				  if (abs(vvv.Common_lep_pdgid()[W_idx]) == 11){
    //    				      if (not (vvv.Common_lep_sip3d()[W_idx] < 4)) return false;
    //    				      if (not (vvv.Common_lep_relIso03_all()[W_idx] < 0.2)) return false;
    //    				      if (not (new_lepton_ID)){
    //    					  if (not (vvv.Common_lep_ID()[W_idx] & (1 << 4))) return false; 
    //    				      }
    //    				  }
    //    				  // W candidate is muon
    //    				  if (abs(vvv.Common_lep_pdgid()[W_idx]) == 13){
    //    				      if (not (vvv.Common_lep_sip3d()[W_idx] < 4)) return false;
    //    				      if (not (new_lepton_ID)){
    //    					  if (not ((vvv.Common_lep_ID()[W_idx] >> 2) >= 3)) return false;
    //    				      }
    //    				  }

    //    			          double max_pt = std::max({vvv.Var_3LepTauMET_Zcand_lep_p4_0().pt(),vvv.Var_3LepTauMET_Zcand_lep_p4_1().pt(),vvv.Var_3LepTauMET_other_lep_p4_0().pt()});
    //    				  if (not ( max_pt > 25. )) return false;

    //    				  double lepton_pts[] = {vvv.Var_3LepTauMET_Zcand_lep_p4_0().pt(),vvv.Var_3LepTauMET_Zcand_lep_p4_1().pt(),vvv.Var_3LepTauMET_other_lep_p4_0().pt()};
    //    				  int n = sizeof(lepton_pts) / sizeof(lepton_pts[0]);
    //    				  std::sort(lepton_pts, lepton_pts+n,greater<double>());

    //    				  if (not ( lepton_pts[1] > 15. )) return false;

    //    				  return true;
    //    		
    //    			      },
    //    			      [&]()
    //    			      {
    //    				  return 1.;
    //    			      });

    //ana.cutflow.addCutToLastActiveCut("CutDuplicate_3LepTau", UNITY,
    //    			      [&]()
    //    			      {
    //    				  if (vvv.Common_isData())
    //    				  {
    //    				      duplicate_removal::DorkyEventIdentifier id(vvv.Common_run(), vvv.Common_evt(), vvv.Common_lumi());
    //    				      if (is_duplicate(id))
    //    					  return false;
    //    				      else
    //    					  return true;
    //    				  }
    //    				  else
    //    				  {
    //    				      return true;
    //    				  }
    //    			      
    //    			       } );

    //// Apply min Mll > 12 GeV selection on any pair of opposite-sign charged leptons
    //ana.cutflow.addCutToLastActiveCut("CutVetoLowMassResonance_3LepTau",
    //        [&]()
    //        {

    //    	// Loop over light charged leptons
    //    	for (unsigned int ilep = 0; ilep < vvv.Common_lep_pdgid().size(); ++ilep){
    //    	     const LorentzVector& ip4 = vvv.Common_lep_p4()[ilep];
    //    	     // Loop over other light leptons
    //    	     for (unsigned int jlep = ilep + 1; jlep < vvv.Common_lep_pdgid().size(); ++jlep){
    //    		  const LorentzVector& jp4 = vvv.Common_lep_p4()[jlep];
    //    		  if ( not ( vvv.Common_lep_pdgid()[ilep]*vvv.Common_lep_pdgid()[jlep] < 0 ) ) continue;
    //    		  if ( not ( (ip4+jp4).mass() > 12.) ) return false;
    //    	     }
    //    	     // Do the same with the tau candidate
    //    	     const LorentzVector& tau_p4 = vvv.Var_3LepTauMET_tau_p4_0();
    //    	     if ( not ( vvv.Common_lep_pdgid()[ilep]*vvv.Var_3LepTauMET_tau_pdgid_0() < 0 ) ) continue;
    //    	     if ( not ( (ip4+tau_p4).mass() > 12.) ) return false;
    //    	}

    //    	return true;

    //        }, UNITY);

    //ana.cutflow.addCutToLastActiveCut("CutVetoZHZWW_3LepTau", [&]()
    //    			      {
    //    				  if (ana.looper.getCurrentFileName().Contains("VHToNonbb"))
    //    				  {
    //    				      if (vvv.Common_gen_VH_channel() == 1){
    //    					  return false;
    //    				      }
    //    				  }
    //    				  return true;
    //    			      }, UNITY);

    //ana.cutflow.addCutToLastActiveCut("CutPresel_3LepTau", UNITY, UNITY);

    //ana.cutflow.getCut("CutPresel_3LepTau");
    //ana.cutflow.addCutToLastActiveCut("CutBVeto_3LepTau", [&]() { return vvv.Common_nb_loose_CSV() == 0; }, UNITY);

    //ana.cutflow.getCut("CutBVeto_3LepTau");
    //ana.cutflow.addCutToLastActiveCut("CutETau", [&]() { return vvv.Cut_3LepTauMET_etauChannel(); }, UNITY);

    //ana.cutflow.getCut("CutBVeto_3LepTau");
    //ana.cutflow.addCutToLastActiveCut("CutMuTau", [&]() { return vvv.Cut_3LepTauMET_mutauChannel(); }, UNITY);


    //LorentzVector leading_tau_p4;
    //int ntaus;
    //// TODO: Need to do this by accessing the Common_tau_ branch and selecting the highest pt one that passes the ID requirements
    //ana.cutflow.getCut("CutETau");
    //ana.cutflow.addCutToLastActiveCut("CutETau_idVS", [&]() {
    //    			
    //    			     std::vector<float> tau_pts;	
    //    			     for (unsigned int itau = 0; itau < vvv.Common_tau_p4().size(); itau++){
    //    				  int idVSe = vvv.Common_tau_idVSe()[itau];
    //    				  int idVSmu = vvv.Common_tau_idVSmu()[itau];
    //    				  int idVSjet = vvv.Common_tau_idVSjet()[itau];
    //    				 
    //    				  if (not ((idVSe >= 1)&&(idVSmu >= 0)&&(idVSjet >= 7)) ) continue;
    //    				  tau_pts.push_back(vvv.Common_tau_p4()[itau].pt());
    //    			     }

    //    		             if ( tau_pts.size() < 1 ) return false;

    //    			     return true;
    //    
    //                                 }, UNITY);

    ////ana.cutflow.addCutToLastActiveCut("CutETau_1Tau", [&]() {

    ////                                 std::vector<float> tau_pts;        
    ////                                 for (unsigned int itau = 0; itau < vvv.Common_tau_p4().size(); itau++){
    ////                                      int idVSe = vvv.Common_tau_idVSe()[itau];
    ////                                      int idVSmu = vvv.Common_tau_idVSmu()[itau];
    ////                                      int idVSjet = vvv.Common_tau_idVSjet()[itau];

    ////                                      if (not ((idVSe >= 1)&&(idVSmu >= 0)&&(idVSjet >= 7)) ) continue;
    ////                                      tau_pts.push_back(vvv.Common_tau_p4()[itau].pt());
    ////                                 }

    ////                                 if ( tau_pts.size() != 1 ) return false;

    ////                                 return true;

    ////                                 }, UNITY);

    ////ana.cutflow.getCut("CutETau_idVS");
    ////ana.cutflow.addCutToLastActiveCut("CutETau_2pTaus", [&]() {

    ////                                 std::vector<float> tau_pts;        
    ////                                 for (unsigned int itau = 0; itau < vvv.Common_tau_p4().size(); itau++){
    ////                                      int idVSe = vvv.Common_tau_idVSe()[itau];
    ////                                      int idVSmu = vvv.Common_tau_idVSmu()[itau];
    ////                                      int idVSjet = vvv.Common_tau_idVSjet()[itau];

    ////                                      if (not ((idVSe >= 1)&&(idVSmu >= 0)&&(idVSjet >= 7)) ) continue;
    ////                                      tau_pts.push_back(vvv.Common_tau_p4()[itau].pt());
    ////                                 }

    ////                                 if ( tau_pts.size() < 2 ) return false;

    ////                                 return true;

    ////                                 }, UNITY);

    //ana.cutflow.getCut("CutMuTau");
    //ana.cutflow.addCutToLastActiveCut("CutMuTau_idVS", [&]() {

    //    			     std::vector<float> tau_pts;
    //                                 for (unsigned int itau = 0; itau < vvv.Common_tau_p4().size(); itau++){
    //                                      int idVSe = vvv.Common_tau_idVSe()[itau];
    //                                      int idVSmu = vvv.Common_tau_idVSmu()[itau];
    //                                      int idVSjet = vvv.Common_tau_idVSjet()[itau];

    //                                      if (not ((idVSe >= 1)&&(idVSmu >= 0)&&(idVSjet >= 7)) ) continue;
    //                                      tau_pts.push_back(vvv.Common_tau_p4()[itau].pt());
    //                                 }

    //                                 if ( tau_pts.size() < 1 ) return false;

    //                                 return true;
    //                          

    //                                 }, UNITY);

    ////ana.cutflow.addCutToLastActiveCut("CutMuTau_1Tau", [&]() {

    ////                                 std::vector<float> tau_pts;
    ////                                 for (unsigned int itau = 0; itau < vvv.Common_tau_p4().size(); itau++){
    ////                                      int idVSe = vvv.Common_tau_idVSe()[itau];
    ////                                      int idVSmu = vvv.Common_tau_idVSmu()[itau];
    ////                                      int idVSjet = vvv.Common_tau_idVSjet()[itau];

    ////                                      if (not ((idVSe >= 1)&&(idVSmu >= 0)&&(idVSjet >= 7)) ) continue;
    ////                                      tau_pts.push_back(vvv.Common_tau_p4()[itau].pt());
    ////                                 }

    ////                                 if ( tau_pts.size() != 1 ) return false;

    ////                                 return true;


    ////                                 }, UNITY);

    ////ana.cutflow.getCut("CutMuTau_idVS");
    ////ana.cutflow.addCutToLastActiveCut("CutMuTau_2pTaus", [&]() {

    ////                                 std::vector<float> tau_pts;
    ////                                 for (unsigned int itau = 0; itau < vvv.Common_tau_p4().size(); itau++){
    ////                                      int idVSe = vvv.Common_tau_idVSe()[itau];
    ////                                      int idVSmu = vvv.Common_tau_idVSmu()[itau];
    ////                                      int idVSjet = vvv.Common_tau_idVSjet()[itau];

    ////                                      if (not ((idVSe >= 1)&&(idVSmu >= 0)&&(idVSjet >= 7)) ) continue;
    ////                                      tau_pts.push_back(vvv.Common_tau_p4()[itau].pt());
    ////                                 }

    ////                                 if ( tau_pts.size() < 2 ) return false;

    ////                                 return true;


    ////                                 }, UNITY);
    


    // Print cut structure
    ana.cutflow.printCuts();

    // Histogram utility object that is used to define the histograms
    ana.histograms.addHistogram("Zcand_mll", 180, 60, 120, [&]() { return vvv.Var_4LepMET_Zcand_mll(); } );
    ana.histograms.addHistogram("Zcand_mll_full", 180, 0, 120, [&]() { return vvv.Var_4LepMET_Zcand_mll(); } );
    ana.histograms.addHistogram("Zcand_lep0_pt", 180, 0, 150, [&]() { return vvv.Var_4LepMET_Zcand_lep_p4_0().pt(); } );
    ana.histograms.addHistogram("Zcand_lep1_pt", 180, 0, 150, [&]() { return vvv.Var_4LepMET_Zcand_lep_p4_1().pt(); } );
    ana.histograms.addHistogram("other_mll", 180, 60, 120, [&]() { return vvv.Var_4LepMET_other_mll(); } );
    ana.histograms.addHistogram("other_mll_full", 180, 0, 200, [&]() { return vvv.Var_4LepMET_other_mll(); } );
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
    ana.histograms.addHistogram("MET", 180, 0, 300., [&]() { return vvv.Common_met_p4().pt(); } );
    ana.histograms.addHistogram("pfMET", 180, 0, 300., [&]() { return vvv.Common_met_p4_MET().pt(); } );
    ana.histograms.addHistogram("PuppiMET", 180, 0, 300., [&]() { return vvv.Common_met_p4_PuppiMET().pt(); } );
    ana.histograms.addHistogram("DRll", 180, 0, 5, [&]() { return DRll; } );
    ana.histograms.addHistogram("DR_Wcands", 180, 0, 5, [&]() { return RooUtil::Calc::DeltaR(vvv.Var_4LepMET_other_lep_p4_0(),vvv.Var_4LepMET_other_lep_p4_1()); } );
    ana.histograms.addHistogram("STLepFit", {0.0, 500.0, 1000.0, 1500.0, 2000.0, 2500.0}, [&]() { return STLep; } );
    ana.histograms.addHistogram("STLepHadFit", {0.0, 500.0, 1000.0, 1500.0, 2000.0, 2500.0}, [&]() { return STLepHad; } );
    ana.histograms.addHistogram("STLep", 180, 0., 3000., [&]() { return STLep; } );
    ana.histograms.addHistogram("STLepHad", 180, 0., 3000., [&]() { return STLepHad; } );
    ana.histograms.addHistogram("MT2", 180, 0., 180., [&]() { return vvv.Var_4LepMET_mt2(); } );
    ana.histograms.addHistogram("MT2_PuppiMET", 180, 0., 180., [&]() { return vvv.Var_4LepMET_mt2_PuppiMET(); } );
    ana.histograms.addHistogram("Pt4l", 180, 0., 300., [&]() { return (vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1()+vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1()).pt(); } );
    ana.histograms.addHistogram("nb", 5, 0, 5, [&]() { return vvv.Common_nb_loose_CSV(); } );
    ana.histograms.addHistogram("Yield", 1, 0, 1, [&]() { return 0; } );
    ana.histograms.addHistogram("DR_WW_Z", 180, 0, 5, [&]() { return RooUtil::Calc::DeltaR((vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1()),(vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1())); } );
    ana.histograms.addHistogram("DPhi_WW_MET", 180, -3.14, 3.14, [&]() { return RooUtil::Calc::DeltaPhi((vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1()),vvv.Common_met_p4_MET()); } );
    ana.histograms.addHistogram("DPhi_Z_MET", 180, -3.14, 3.14, [&]() { return RooUtil::Calc::DeltaPhi((vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1()),vvv.Common_met_p4_MET()); } );
    ana.histograms.addHistogram("DPhi_WW_PuppiMET", 180, -3.14, 3.14, [&]() { return RooUtil::Calc::DeltaPhi((vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1()),vvv.Common_met_p4_PuppiMET()); } );
    ana.histograms.addHistogram("DPhi_Z_PuppiMET", 180, -3.14, 3.14, [&]() { return RooUtil::Calc::DeltaPhi((vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1()),vvv.Common_met_p4_PuppiMET()); } );
    ana.histograms.addHistogram("DPhi_WWZ_MET", 180, -3.14, 3.14, [&]() { return RooUtil::Calc::DeltaPhi((vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1()+vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1()),vvv.Common_met_p4_MET()); } );
    ana.histograms.addHistogram("DPhi_WWZ_PuppiMET", 180, -3.14, 3.14, [&]() { return RooUtil::Calc::DeltaPhi((vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1()+vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1()),vvv.Common_met_p4_PuppiMET()); } );

    ana.histograms.addVecHistogram("SRBin", 7, 0, 7,
                                [&]()
                                {
                                    std::vector<float> rtn;
                                    if (vvv.Cut_4LepMET_emuChannel())
                                    {
                                        if (vvv.Var_4LepMET_other_mll() >   0. and vvv.Var_4LepMET_other_mll() <  40. and vvv.Var_4LepMET_mt2_PuppiMET() > 25.)
                                            rtn.push_back(0.);
                                        if (vvv.Var_4LepMET_other_mll() >  40. and vvv.Var_4LepMET_other_mll() <  60. and vvv.Var_4LepMET_mt2_PuppiMET() > 25.)
                                            rtn.push_back(1.);
                                        if (vvv.Var_4LepMET_other_mll() >  60. and vvv.Var_4LepMET_other_mll() < 100. and vvv.Var_4LepMET_mt2_PuppiMET() > 25.)
                                            rtn.push_back(2.);
                                        if (vvv.Var_4LepMET_other_mll() > 100.)
                                            rtn.push_back(3.);
                                    }
                                    else if (vvv.Cut_4LepMET_offzChannel())
                                    {
                                        if (vvv.Common_met_p4_PuppiMET().pt() > 120.)
                                        {
                                            rtn.push_back(4.);
                                        }
                                        if (vvv.Common_met_p4_PuppiMET().pt() > 65. and vvv.Common_met_p4_PuppiMET().pt() < 120.)
                                        {
                                            if (Pt4l > 40. and Pt4l < 70.)
                                                rtn.push_back(6.);
                                            if (Pt4l > 70.)
                                                rtn.push_back(5.);
                                        }
                                    }
                                    return rtn;
                                } );

    /*ana.histograms_bj_in.addHistogram("Min_mlj_in", 180, 0., 300.,
			     [&]()
			     {  
                                 std::vector<float> mlj_in;
				 int nj_in = 0;
                                 for (long unsigned int i = 0; i < vvv.Common_jet_p4().size(); i++ ){
                                      if ( std::abs(vvv.Common_jet_p4()[i].eta()) < 2.4 ){

					   nj_in++;
                                           float mlj_Wl1 = ( vvv.Common_jet_p4()[i] + vvv.Var_4LepMET_other_lep_p4_0() ).M();
                                           float mlj_Wl2 = ( vvv.Common_jet_p4()[i] + vvv.Var_4LepMET_other_lep_p4_1() ).M();

                                           std::vector<float> v = {mlj_Wl1,mlj_Wl2};
                                           float v_min = *min_element(v.begin(),v.end());
                                           mlj_in.push_back(v_min);

                                      }
                                 }

                                 float min_mlj_in; 
				 if (nj_in > 0) min_mlj_in = *min_element(mlj_in.begin(),mlj_in.end());	
				 if (nj_in == 0) min_mlj_in = -1.0;

				 //std::cout << "Event = " << vvv.Common_evt() << ", min_mlj_in =  " << min_mlj_in << std::endl;

				 return min_mlj_in; 
			     } );

    ana.histograms_bj_out.addHistogram("Min_mlj_out", 180, 0., 300.,
                             [&]()
                             {
                                 std::vector<float> mlj_out;
				 int nj_out = 0;
                                 for (long unsigned int i = 0; i < vvv.Common_jet_p4().size(); i++ ){
                                      if ( std::abs(vvv.Common_jet_p4()[i].eta()) > 2.4 && std::abs(vvv.Common_jet_p4()[i].eta()) < 4.7 ){
					   nj_out++;
                                           float mlj_Wl1 = ( vvv.Common_jet_p4()[i] + vvv.Var_4LepMET_other_lep_p4_0() ).M();
                                           float mlj_Wl2 = ( vvv.Common_jet_p4()[i] + vvv.Var_4LepMET_other_lep_p4_1() ).M();

                                           std::vector<float> v = {mlj_Wl1,mlj_Wl2};
                                           float v_min = *min_element(v.begin(),v.end());
                                           mlj_out.push_back(v_min);

                                      }
                                 }

                                 float min_mlj_out; 
				 if ( nj_out > 0 ) min_mlj_out = *min_element(mlj_out.begin(),mlj_out.end());
				 if ( nj_out == 0 ) min_mlj_out = -1.0;

				 //std::cout << "Event = " << vvv.Common_evt() << ", min_mlj_out =  " << min_mlj_out << std::endl;

                                 return min_mlj_out;
                             } );

    ana.histograms_bj_all.addHistogram("Min_mlj_all", 180, 0., 300.,
                             [&]()
                             {
                                 std::vector<float> mlj_all;
				 int nj_all = 0;
                                 for (long unsigned int i = 0; i < vvv.Common_jet_p4().size(); i++ ){
    
                                      nj_all++;
                                      float mlj_Wl1 = ( vvv.Common_jet_p4()[i] + vvv.Var_4LepMET_other_lep_p4_0() ).M();
                                      float mlj_Wl2 = ( vvv.Common_jet_p4()[i] + vvv.Var_4LepMET_other_lep_p4_1() ).M();
    
                                      std::vector<float> v = {mlj_Wl1,mlj_Wl2};
                                      float v_min = *min_element(v.begin(),v.end());
                                      mlj_all.push_back(v_min);

                                 }

                                 float min_mlj_all;
				 if (nj_all > 0) min_mlj_all = *min_element(mlj_all.begin(),mlj_all.end());
				 if (nj_all == 0) min_mlj_all = -1.0;

				 //std::cout << "Event = " << vvv.Common_evt() << ", min_mlj_all =  " << min_mlj_all << std::endl;
			
                                 return min_mlj_all;
                             } );
    */    


    // Book cutflows
    ana.cutflow.bookCutflows();

    // Book Histograms
    ana.cutflow.bookHistogramsForCutAndBelow(ana.histograms, "CutDuplicate"); // if just want to book everywhere
    //ana.cutflow.bookHistogramsForCutAndBelow(ana.histograms_3LepTau, "CutDuplicate_3LepTau");


    // Book Event list
    ana.cutflow.bookEventLists();

    // Load event list
    RooUtil::EventList eventlist_to_check("eventlist_to_check.txt");

    // Setup the BDT branches
    setupBDTBranches();
    setupBDTBranches_SF();

    int eventID = 0;

    int nevts_OF_1 = 0;
    int nevts_OF_2 = 0;
    int nevts_OF_3 = 0;
    int nevts_OF_4 = 0;
    int nevts_SF_5 = 0;
    int nevts_SF_6 = 0;
    int nevts_SF_7 = 0;

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
        STLep = vvv.Var_4LepMET_Zcand_lep_p4_0().pt() + vvv.Var_4LepMET_Zcand_lep_p4_1().pt() + vvv.Var_4LepMET_other_lep_p4_0().pt() + vvv.Var_4LepMET_other_lep_p4_1().pt() + vvv.Common_met_p4_PuppiMET().pt();
        STLepHad = vvv.Var_4LepMET_Zcand_lep_p4_0().pt() + vvv.Var_4LepMET_Zcand_lep_p4_1().pt() + vvv.Var_4LepMET_other_lep_p4_0().pt() + vvv.Var_4LepMET_other_lep_p4_1().pt() + vvv.Common_met_p4_PuppiMET().pt() + (vvv.Common_fatjet_p4().size() > 0 ? vvv.Common_fatjet_p4()[0].pt() : 0.);
        Pt4l = (vvv.Var_4LepMET_Zcand_lep_p4_0() + vvv.Var_4LepMET_Zcand_lep_p4_1() + vvv.Var_4LepMET_other_lep_p4_0() + vvv.Var_4LepMET_other_lep_p4_1()).pt();

        //ana.tx->clear();

        //fillBDTBranches();
        //ana.tx->setBranch<float>("CutBVeto", ana.cutflow.getCut("CutBVeto").pass);

        ana.cutflow.setEventID(vvv.Common_run(), vvv.Common_lumi(), vvv.Common_evt());

        //Do what you need to do in for each event here
        //To save use the following function
        ana.cutflow.fill();

        bool isWWZEFT = ana.looper.getCurrentFileName().Contains("WWZ_RunIISummer20UL18NanoAODv9_FourleptonFilter_FilterFix_merged");
        bool isWZZEFT = ana.looper.getCurrentFileName().Contains("WZZ_RunIISummer20UL18NanoAODv9_FourleptonFilter_FilterFix_merged");
        bool isZZZEFT = ana.looper.getCurrentFileName().Contains("ZZZ_RunIISummer20UL18NanoAODv9_FourleptonFilter_FilterFix_merged");

        float sm_weight = 1;
        sm_weight = (isWWZEFT ? vvv.Common_LHEWeight_mg_reweighting()[0] * 0.1651 * 0.3272 * 0.3272 * 0.1009 /0.0005972 : 1.)
                  * (isWZZEFT ? vvv.Common_LHEWeight_mg_reweighting()[0] : 1.)
                  * (isZZZEFT ? vvv.Common_LHEWeight_mg_reweighting()[0] : 1.)
                  ;
        float eftweight = 1;
        eftweight = (isWWZEFT ? vvv.Common_LHEWeight_mg_reweighting()[ana.eft_reweighting_idx] * 0.1651 * 0.3272 * 0.3272 * 0.1009 /0.0005972 : 1.)                                                                          * (isWZZEFT ? vvv.Common_LHEWeight_mg_reweighting()[ana.eft_reweighting_idx] : 1.)                                                                                                                         * (isZZZEFT ? vvv.Common_LHEWeight_mg_reweighting()[ana.eft_reweighting_idx] : 1.)
                  ;
        
        float weight = ana.eft_reweighting_idx != 0 ? (eftweight - sm_weight) : sm_weight;
        
        
        if (ana.looper.getCurrentFileName().Contains("WWZJets"))
        {                                                                                                                                                                                                              weight = 0.002067 / 0.0005972;
        
        }                                                                 
        
	float evt_weight = vvv.Var_4LepMET_scaleLumi() * vvv.Common_genWeight() * weight;


        if (ana.cutflow.getCut("CutEMu").pass && writeTree){
	    ana.tx->clear();
            fillBDTBranches();
	    ana.tx->setBranch<float>("weight", evt_weight);
            ana.tx->setBranch<int>("eventID", eventID);
            eventID++;     
	    ana.tx->fill();

        }

        if (ana.cutflow.getCut("CutOffZ").pass && writeTree){
	    ana.tx2->clear();
	    fillBDTBranches_SF();
	    ana.tx2->setBranch<float>("weight", evt_weight);
	    ana.tx2->fill();
	}

        if (ana.cutflow.getCut("CutEMuMT2").pass && write_counts){
            if (vvv.Var_4LepMET_other_mll() >   0. and vvv.Var_4LepMET_other_mll() <  40. and vvv.Var_4LepMET_mt2_PuppiMET() > 25.) nevts_OF_1++;
	    if (vvv.Var_4LepMET_other_mll() >  40. and vvv.Var_4LepMET_other_mll() <  60. and vvv.Var_4LepMET_mt2_PuppiMET() > 25.) nevts_OF_2++;
	    if (vvv.Var_4LepMET_other_mll() >  60. and vvv.Var_4LepMET_other_mll() < 100. and vvv.Var_4LepMET_mt2_PuppiMET() > 25.) nevts_OF_3++;
            if (vvv.Var_4LepMET_other_mll() > 100.) nevts_OF_4++;	    
        }

        float pt4l = (vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1()+vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1()).pt();

        if (ana.cutflow.getCut("CutOffZ").pass && write_counts){
	    if (vvv.Common_met_p4_PuppiMET().pt() > 120.) nevts_SF_5++;
	    if (vvv.Common_met_p4_PuppiMET().pt() > 65. and vvv.Common_met_p4_PuppiMET().pt() < 120. and pt4l > 40. and pt4l < 70.) nevts_SF_7++;
	    if (vvv.Common_met_p4_PuppiMET().pt() > 65. and vvv.Common_met_p4_PuppiMET().pt() < 120. and pt4l > 70.) nevts_SF_6++;
        }
        
        //if (ana.cutflow.getCut("CutBVeto").pass){
	//ana.tx->fill();
        //}

        //if (eventlist_to_check.has(vvv.Common_run(), vvv.Common_lumi(), vvv.Common_evt())){

	//	ana.cutflow.printCuts();
       
	//}
	
	
	if (ana.cutflow.getCut("CutEMuMT2").pass){
	      // TODO
	      // Loop over jets and count the number of jets in each event
	      double lead_jet_pt = 0.;
	      double lead_jet_eta = 0.;
	      std::vector<double> mlj;
	      int nj_in = 0;
	      int nj_out = 0;
	      for (unsigned int j = 0; j < vvv.Common_jet_idxs().size(); j++){
		   if ( not (std::abs(vvv.Common_jet_p4()[j].eta()) < 2.4) ) continue;
		   //if ( std::abs(vvv.Common_jet_p4()[j].eta()) > 2.4 && std::abs(vvv.Common_jet_p4()[j].eta()) < 4.7 ) nj_out++;
		   nj_in++;
		   if ( vvv.Common_jet_p4()[j].pt() > lead_jet_pt ){
			// Find the leading jet pt
			lead_jet_pt = vvv.Common_jet_p4()[j].pt();
			// Find the leading jet eta
			lead_jet_eta = vvv.Common_jet_p4()[j].eta();
		   }
		
		   float mlj_Wl1 = ( vvv.Common_jet_p4()[j] + vvv.Var_4LepMET_other_lep_p4_0() ).M();
                   float mlj_Wl2 = ( vvv.Common_jet_p4()[j] + vvv.Var_4LepMET_other_lep_p4_1() ).M();

                   std::vector<float> v = {mlj_Wl1,mlj_Wl2};
                   float v_min = *min_element(v.begin(),v.end());
                   mlj.push_back(v_min);
                   
	      }
	      // Find minimum mlj
	      //float min_mlj;
              //if (nj_in+nj_out > 0) min_mlj = *min_element(mlj.begin(),mlj.end());
	      //if (nj_in+nj_out == 0) min_mlj = -1.0;
	      //// Find SR bin corresponding to the event
	      //int SRBin;
	      //if (vvv.Var_4LepMET_other_mll() >   0. and vvv.Var_4LepMET_other_mll() <  40. and vvv.Var_4LepMET_mt2() > 25.)
              //    SRBin = 0;
              //if (vvv.Var_4LepMET_other_mll() >  40. and vvv.Var_4LepMET_other_mll() <  60. and vvv.Var_4LepMET_mt2() > 25.)
              //    SRBin = 1;
              //if (vvv.Var_4LepMET_other_mll() >  60. and vvv.Var_4LepMET_other_mll() < 100. and vvv.Var_4LepMET_mt2() > 25.)
              //    SRBin = 2;
              //if (vvv.Var_4LepMET_other_mll() > 100.)
              //    SRBin = 3;

	}

        if ( write_counts ){
	     std::cout << "==============================================================" << std::endl;
	     std::cout << "Number of entries in OF bin 1: " << nevts_OF_1 << std::endl;
	     std::cout << "Number of entries in OF bin 2: " << nevts_OF_2 << std::endl;
	     std::cout << "Number of entries in OF bin 3: " << nevts_OF_3 << std::endl;
	     std::cout << "Number of entries in OF bin 4: " << nevts_OF_4 << std::endl;
	     std::cout << "Number of entries in SF bin 5: " << nevts_SF_5 << std::endl;
             std::cout << "Number of entries in SF bin 6: " << nevts_SF_6 << std::endl;
             std::cout << "Number of entries in SF bin 7: " << nevts_SF_7 << std::endl;
        }

        //if (eventlist_to_check.has(vvv.Common_run(), vvv.Common_lumi(), vvv.Common_evt()))
        //{
        //    std::cout <<  " vvv.Common_run(): " << vvv.Common_run() <<  " vvv.Common_lumi(): " << vvv.Common_lumi() <<  " vvv.Common_evt(): " << vvv.Common_evt() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_Zcand_lep_p4_0().pt(): " << vvv.Var_4LepMET_Zcand_lep_p4_0().pt() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_Zcand_lep_p4_0().eta(): " << vvv.Var_4LepMET_Zcand_lep_p4_0().eta() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_Zcand_lep_p4_0().phi(): " << vvv.Var_4LepMET_Zcand_lep_p4_0().phi() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_Zcand_lep_pdgid_0(): " << vvv.Var_4LepMET_Zcand_lep_pdgid_0() <<  std::endl;
        //    std::cout <<  " vvv.Common_lep_ID()[vvv.Var_4LepMET_Zcand_lep_idx_0()]: " << vvv.Common_lep_ID()[vvv.Var_4LepMET_Zcand_lep_idx_0()] <<  std::endl;
	//    std::cout <<  " vvv.Common_lep_relIso03_all()[vvv.Var_4LepMET_Zcand_lep_idx_0()]: " << vvv.Common_lep_relIso03_all()[vvv.Var_4LepMET_Zcand_lep_idx_0()] << std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_Zcand_lep_p4_1().pt(): " << vvv.Var_4LepMET_Zcand_lep_p4_1().pt() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_Zcand_lep_p4_1().eta(): " << vvv.Var_4LepMET_Zcand_lep_p4_1().eta() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_Zcand_lep_p4_1().phi(): " << vvv.Var_4LepMET_Zcand_lep_p4_1().phi() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_Zcand_lep_pdgid_1(): " << vvv.Var_4LepMET_Zcand_lep_pdgid_1() <<  std::endl;
        //    std::cout <<  " vvv.Common_lep_ID()[vvv.Var_4LepMET_Zcand_lep_idx_1()]: " << vvv.Common_lep_ID()[vvv.Var_4LepMET_Zcand_lep_idx_1()] <<  std::endl;
	//    std::cout <<  " vvv.Common_lep_relIso03_all()[vvv.Var_4LepMET_Zcand_lep_idx_1()]: " << vvv.Common_lep_relIso03_all()[vvv.Var_4LepMET_Zcand_lep_idx_1()] << std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_other_lep_p4_0().pt(): " << vvv.Var_4LepMET_other_lep_p4_0().pt() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_other_lep_p4_0().eta(): " << vvv.Var_4LepMET_other_lep_p4_0().eta() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_other_lep_p4_0().phi(): " << vvv.Var_4LepMET_other_lep_p4_0().phi() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_other_lep_pdgid_0(): " << vvv.Var_4LepMET_other_lep_pdgid_0() <<  std::endl;
        //    std::cout <<  " vvv.Common_lep_ID()[vvv.Var_4LepMET_other_lep_idx_0()]: " << vvv.Common_lep_ID()[vvv.Var_4LepMET_other_lep_idx_0()] <<  std::endl;
	//    std::cout <<  " vvv.Common_lep_relIso03_all()[vvv.Var_4LepMET_other_lep_idx_0()]: " << vvv.Common_lep_relIso03_all()[vvv.Var_4LepMET_other_lep_idx_0()] << std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_other_lep_p4_1().pt(): " << vvv.Var_4LepMET_other_lep_p4_1().pt() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_other_lep_p4_1().eta(): " << vvv.Var_4LepMET_other_lep_p4_1().eta() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_other_lep_p4_1().phi(): " << vvv.Var_4LepMET_other_lep_p4_1().phi() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_other_lep_pdgid_1(): " << vvv.Var_4LepMET_other_lep_pdgid_1() <<  std::endl;
        //    std::cout <<  " vvv.Common_lep_ID()[vvv.Var_4LepMET_other_lep_idx_1()]: " << vvv.Common_lep_ID()[vvv.Var_4LepMET_other_lep_idx_1()] <<  std::endl;
	//    std::cout <<  " vvv.Common_lep_relIso03_all()[vvv.Var_4LepMET_other_lep_idx_1()]: " << vvv.Common_lep_relIso03_all()[vvv.Var_4LepMET_other_lep_idx_1()] << std::endl;
        //    std::cout <<  " (vvv.Common_lep_ID()[vvv.Var_4LepMET_other_lep_idx_1()]&(1<<4)): " << (vvv.Common_lep_ID()[vvv.Var_4LepMET_other_lep_idx_1()]&(1<<4)) <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_Zcand_mll(): " << vvv.Var_4LepMET_Zcand_mll() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_other_mll(): " << vvv.Var_4LepMET_other_mll() <<  std::endl;
        //    std::cout <<  " vvv.Var_4LepMET_mt2(): " << vvv.Var_4LepMET_mt2() <<  std::endl;
        //    std::cout <<  " vvv.Common_nb_loose_CSV(): " << vvv.Common_nb_loose_CSV() <<  std::endl;
        //    for (unsigned ijet = 0; ijet < vvv.Common_jet_p4().size(); ++ijet)
        //    {
        //        std::cout <<  " vvv.Common_jet_p4()[ijet].pt(): " << vvv.Common_jet_p4()[ijet].pt() <<  std::endl;
        //        std::cout <<  " vvv.Common_jet_p4()[ijet].eta(): " << vvv.Common_jet_p4()[ijet].eta() <<  std::endl;
        //        std::cout <<  " vvv.Common_jet_p4()[ijet].phi(): " << vvv.Common_jet_p4()[ijet].phi() <<  std::endl;
        //        std::cout <<  " vvv.Common_jet_passBloose_CSV()[ijet]: " << vvv.Common_jet_passBloose_CSV()[ijet] <<  std::endl;
        //    }
        //    ana.cutflow.printCuts();
        //}
    }

    ana.cutflow.getCut("CutEMuMT2").writeEventList("eventlist.txt");

    // Writing output file
    ana.cutflow.saveOutput();

    //if (ana.cutflow.getCut("CutBVeto").pass){
    //	ana.tx->write();
    //}
    ana.tx->write();
    ana.tx2->write();

    delete ana.tx;
    delete ana.tx2;

    // The below can be sometimes crucial
    delete ana.output_tfile;
}

//==========================================================================================
// Setup BDT branches (prior to event looping)
//==========================================================================================
void setupBDTBranches()
{
     ana.tx->createBranch<float>("m_ll");
     ana.tx->createBranch<float>("dPhi_4Lep_MET");
     ana.tx->createBranch<float>("dPhi_Zcand_MET");
     ana.tx->createBranch<float>("dPhi_WW_MET");
     ana.tx->createBranch<float>("dR_Wcands");
     ana.tx->createBranch<float>("dR_Zcands");
     ana.tx->createBranch<float>("MET");
     ana.tx->createBranch<float>("MT2");
     ana.tx->createBranch<float>("Pt4l");
     ana.tx->createBranch<float>("STLepHad");
     ana.tx->createBranch<float>("leading_Zcand_pt");
     ana.tx->createBranch<float>("subleading_Zcand_pt");
     ana.tx->createBranch<float>("leading_Wcand_pt");
     ana.tx->createBranch<float>("subleading_Wcand_pt");
     ana.tx->createBranch<float>("weight");
     ana.tx->createBranch<int>("eventID");
}

//==========================================================================================
// Write values to BDT branches (during event looping)
//==========================================================================================
void fillBDTBranches()
{
     ana.tx->setBranch<float>("m_ll", vvv.Var_4LepMET_other_mll());
     ana.tx->setBranch<float>("dPhi_4Lep_MET", RooUtil::Calc::DeltaPhi(vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1()+vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1(), vvv.Common_met_p4_PuppiMET()));
     ana.tx->setBranch<float>("dPhi_Zcand_MET", RooUtil::Calc::DeltaPhi(vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1(),vvv.Common_met_p4_PuppiMET()));
     ana.tx->setBranch<float>("dPhi_WW_MET", RooUtil::Calc::DeltaPhi(vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1(),vvv.Common_met_p4_PuppiMET()));
     ana.tx->setBranch<float>("dR_Wcands", RooUtil::Calc::DeltaR(vvv.Var_4LepMET_other_lep_p4_0(),vvv.Var_4LepMET_other_lep_p4_1()));
     ana.tx->setBranch<float>("dR_Zcands", RooUtil::Calc::DeltaR(vvv.Var_4LepMET_Zcand_lep_p4_0(),vvv.Var_4LepMET_Zcand_lep_p4_1()));
     ana.tx->setBranch<float>("MET", vvv.Common_met_p4_PuppiMET().pt());
     ana.tx->setBranch<float>("MT2", vvv.Var_4LepMET_mt2_PuppiMET());
     ana.tx->setBranch<float>("Pt4l", (vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1()+vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1()).pt());
     ana.tx->setBranch<float>("STLepHad", vvv.Var_4LepMET_Zcand_lep_p4_0().pt() + vvv.Var_4LepMET_Zcand_lep_p4_1().pt() + vvv.Var_4LepMET_other_lep_p4_0().pt() + vvv.Var_4LepMET_other_lep_p4_1().pt() + vvv.Common_met_p4_PuppiMET().pt() + (vvv.Common_fatjet_p4().size() > 0 ? vvv.Common_fatjet_p4()[0].pt() : 0.));
     ana.tx->setBranch<float>("leading_Zcand_pt", vvv.Var_4LepMET_Zcand_lep_p4_0().pt());
     ana.tx->setBranch<float>("subleading_Zcand_pt", vvv.Var_4LepMET_Zcand_lep_p4_1().pt());
     ana.tx->setBranch<float>("leading_Wcand_pt", vvv.Var_4LepMET_other_lep_p4_0().pt());
     ana.tx->setBranch<float>("subleading_Wcand_pt", vvv.Var_4LepMET_other_lep_p4_1().pt());        
}

void setupBDTBranches_SF()
{
     ana.tx2->createBranch<float>("m_ll");
     ana.tx2->createBranch<float>("dPhi_4Lep_MET");
     ana.tx2->createBranch<float>("dPhi_Zcand_MET");
     ana.tx2->createBranch<float>("dPhi_WW_MET");
     ana.tx2->createBranch<float>("dR_Wcands");
     ana.tx2->createBranch<float>("dR_Zcands");
     ana.tx2->createBranch<float>("dR_WW_Z");
     ana.tx2->createBranch<float>("MET");
     ana.tx2->createBranch<float>("MT2");
     ana.tx2->createBranch<float>("Pt4l");
     ana.tx2->createBranch<float>("STLepHad");
     ana.tx2->createBranch<float>("STLep");
     ana.tx2->createBranch<float>("leading_Zcand_pt");
     ana.tx2->createBranch<float>("subleading_Zcand_pt");
     ana.tx2->createBranch<float>("leading_Wcand_pt");
     ana.tx2->createBranch<float>("subleading_Wcand_pt");
     ana.tx2->createBranch<float>("weight");
}

void fillBDTBranches_SF()
{
     ana.tx2->setBranch<float>("m_ll", vvv.Var_4LepMET_other_mll());
     ana.tx2->setBranch<float>("dPhi_4Lep_MET", RooUtil::Calc::DeltaPhi(vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1()+vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1(), vvv.Common_met_p4_PuppiMET()));
     ana.tx2->setBranch<float>("dPhi_Zcand_MET", RooUtil::Calc::DeltaPhi(vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1(),vvv.Common_met_p4_PuppiMET()));
     ana.tx2->setBranch<float>("dPhi_WW_MET", RooUtil::Calc::DeltaPhi(vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1(),vvv.Common_met_p4_PuppiMET()));
     ana.tx2->setBranch<float>("dR_Wcands", RooUtil::Calc::DeltaR(vvv.Var_4LepMET_other_lep_p4_0(),vvv.Var_4LepMET_other_lep_p4_1()));
     ana.tx2->setBranch<float>("dR_Zcands", RooUtil::Calc::DeltaR(vvv.Var_4LepMET_Zcand_lep_p4_0(),vvv.Var_4LepMET_Zcand_lep_p4_1()));
     ana.tx2->setBranch<float>("dR_WW_Z", RooUtil::Calc::DeltaR((vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1()),(vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1())));
     ana.tx2->setBranch<float>("MET", vvv.Common_met_p4_PuppiMET().pt());
     ana.tx2->setBranch<float>("MT2", vvv.Var_4LepMET_mt2_PuppiMET());
     ana.tx2->setBranch<float>("Pt4l", (vvv.Var_4LepMET_Zcand_lep_p4_0()+vvv.Var_4LepMET_Zcand_lep_p4_1()+vvv.Var_4LepMET_other_lep_p4_0()+vvv.Var_4LepMET_other_lep_p4_1()).pt());
     ana.tx2->setBranch<float>("STLepHad", vvv.Var_4LepMET_Zcand_lep_p4_0().pt() + vvv.Var_4LepMET_Zcand_lep_p4_1().pt() + vvv.Var_4LepMET_other_lep_p4_0().pt() + vvv.Var_4LepMET_other_lep_p4_1().pt() + vvv.Common_met_p4_PuppiMET().pt() + (vvv.Common_fatjet_p4().size() > 0 ? vvv.Common_fatjet_p4()[0].pt() : 0.));
     ana.tx2->setBranch<float>("STLep", vvv.Var_4LepMET_Zcand_lep_p4_0().pt() + vvv.Var_4LepMET_Zcand_lep_p4_1().pt() + vvv.Var_4LepMET_other_lep_p4_0().pt() + vvv.Var_4LepMET_other_lep_p4_1().pt() + vvv.Common_met_p4_PuppiMET().pt() );
     ana.tx2->setBranch<float>("leading_Zcand_pt", vvv.Var_4LepMET_Zcand_lep_p4_0().pt());
     ana.tx2->setBranch<float>("subleading_Zcand_pt", vvv.Var_4LepMET_Zcand_lep_p4_1().pt());
     ana.tx2->setBranch<float>("leading_Wcand_pt", vvv.Var_4LepMET_other_lep_p4_0().pt());
     ana.tx2->setBranch<float>("subleading_Wcand_pt", vvv.Var_4LepMET_other_lep_p4_1().pt());
}

