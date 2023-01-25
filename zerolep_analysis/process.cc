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
// 2. Setting up IO
//
//********************************************************************************

    // Create the TChain that holds the TTree's of the baby ntuples
    ana.events_tchain = RooUtil::FileUtil::createTChain(ana.input_tree_name, ana.input_file_list_tstring);

    // Create a Looper object to loop over input files
    ana.looper.init(ana.events_tchain, &vvv, ana.n_events);

    // Set the cutflow object output file
    ana.cutflow.setTFile(ana.output_tfile);








//********************************************************************************
//
// 3. Some meta data handling for weighting of the events
//
//********************************************************************************

    // cross section information is saved in a json format
    std::ifstream xsec("data/xsec_VVV0Lep.json"); //
    json j;
    xsec >> j;

    // When the VVVNanoLooper was run with some job splitting, the "njobs" information is needed to properly weight them up.
    // e.g. if for a QCD HT1500 slice sample, the jobs ran with njobs=5 the Root__h_Common_LHEWeight_mg_reweighting_times_genWeight histogram after hadding gets 5x'ed.
    // (because each job will produce a proper total nevents, and then there are 5 rootfiles that contain same information.)
    // (so after hadding, the histogram contains 5x the correct value)
    // I know it's a bit stupid and confusing... and hacky... but it works.
    std::ifstream njobs("data/njobs.json");
    json n;
    njobs >> n;







//********************************************************************************
//
// 4. Some on the fly variable calculating lambda's
//
//********************************************************************************

    //_______________________________________________________________________________
    // Returns number of hadronically decaying V bosons (gen-level)
    auto nGenHadV = [&]()
    {
        TString filename = ana.looper.getCurrentFileBaseName();
        TString samplename = filename.ReplaceAll(".root", "");
        bool is_signal = false;
        if (samplename.EqualTo("WWW") or samplename.EqualTo("WWZ") or samplename.EqualTo("WZZ") or samplename.EqualTo("ZZZ") or
            samplename.EqualTo("Dim6_WWW") or samplename.EqualTo("Dim6_WWZ") or samplename.EqualTo("Dim6_WZZ") or samplename.EqualTo("Dim6_ZZZ"))
        {
            is_signal = true;
        }
        if (is_signal) // if signal
        {
            int nhadv = 0;
            if (abs(vvv.Common_gen_vvvdecay_pdgid()[0]) < 10) nhadv++;
            if (abs(vvv.Common_gen_vvvdecay_pdgid()[2]) < 10) nhadv++;
            if (abs(vvv.Common_gen_vvvdecay_pdgid()[4]) < 10) nhadv++;
            return nhadv;
        }
        else
        {
            return -1;
        }
    };

    //_______________________________________________________________________________
    // Returns number of reconstructed fat-jets p4 matched to the gen-level bosons p4
    // Matching is done via delta R with minimizing dR distances between three objects. (i.e. hungarian methods)
    auto nFJGenMatched = [&]()
    {
        TString filename = ana.looper.getCurrentFileBaseName();
        TString samplename = filename.ReplaceAll(".root", "");
        bool is_signal = false;
        if (samplename.EqualTo("WWW") or samplename.EqualTo("WWZ") or samplename.EqualTo("WZZ") or samplename.EqualTo("ZZZ") or
            samplename.EqualTo("Dim6_WWW") or samplename.EqualTo("Dim6_WWZ") or samplename.EqualTo("Dim6_WZZ") or samplename.EqualTo("Dim6_ZZZ"))
        {
            is_signal = true;
        }
        if (is_signal) // if signal
        {
            int ngenmatched = 0;
            std::vector<LV> bosons = {
                vvv.Common_gen_vvvdecay_p4s()[0] + vvv.Common_gen_vvvdecay_p4s()[1],
                vvv.Common_gen_vvvdecay_p4s()[2] + vvv.Common_gen_vvvdecay_p4s()[3],
                vvv.Common_gen_vvvdecay_p4s()[4] + vvv.Common_gen_vvvdecay_p4s()[5]
            };
            std::vector<int> matches = RooUtil::Calc::hungarianDeltaRMatching(vvv.allHad_fatjets_mSD_p4(), bosons);
            if (RooUtil::Calc::DeltaR(bosons[matches[0]], vvv.allHad_fatjets_mSD_p4()[0]) < 0.8) ngenmatched++;
            if (RooUtil::Calc::DeltaR(bosons[matches[1]], vvv.allHad_fatjets_mSD_p4()[1]) < 0.8) ngenmatched++;
            if (RooUtil::Calc::DeltaR(bosons[matches[2]], vvv.allHad_fatjets_mSD_p4()[2]) < 0.8) ngenmatched++;
            return ngenmatched;
        }
        else
        {
            return -1;
        }
    };

    //_______________________________________________________________________________
    // Returns fat-jet 4 vectors ordered by Xqq+Xbb+Xcc/Xqq+Xbb+Xcc+QCD scores
    auto VMDsorted = [&]()
    {
        float VMD0 = vvv.allHad_FJ0_VMD();
        float VMD1 = vvv.allHad_FJ1_VMD();
        float VMD2 = vvv.allHad_FJ2_VMD();
        std::vector<LV> p4s;
        if (VMD0 >= VMD1 and VMD0 >= VMD2 and VMD1 >= VMD2) p4s = {vvv.allHad_fatjets_mSD_p4()[0], vvv.allHad_fatjets_mSD_p4()[1], vvv.allHad_fatjets_mSD_p4()[2]};
        if (VMD0 >= VMD1 and VMD0 >= VMD2 and VMD2 >= VMD1) p4s = {vvv.allHad_fatjets_mSD_p4()[0], vvv.allHad_fatjets_mSD_p4()[2], vvv.allHad_fatjets_mSD_p4()[1]};
        if (VMD1 >= VMD0 and VMD1 >= VMD2 and VMD0 >= VMD2) p4s = {vvv.allHad_fatjets_mSD_p4()[1], vvv.allHad_fatjets_mSD_p4()[0], vvv.allHad_fatjets_mSD_p4()[2]};
        if (VMD1 >= VMD0 and VMD1 >= VMD2 and VMD2 >= VMD0) p4s = {vvv.allHad_fatjets_mSD_p4()[1], vvv.allHad_fatjets_mSD_p4()[2], vvv.allHad_fatjets_mSD_p4()[0]};
        if (VMD2 >= VMD0 and VMD2 >= VMD1 and VMD0 >= VMD1) p4s = {vvv.allHad_fatjets_mSD_p4()[2], vvv.allHad_fatjets_mSD_p4()[0], vvv.allHad_fatjets_mSD_p4()[1]};
        if (VMD2 >= VMD0 and VMD2 >= VMD1 and VMD1 >= VMD0) p4s = {vvv.allHad_fatjets_mSD_p4()[2], vvv.allHad_fatjets_mSD_p4()[1], vvv.allHad_fatjets_mSD_p4()[0]};
        return p4s;
    };

    //_______________________________________________________________________________
    // Returns fat-jet 4 vectors ordered by Xqq+Xbb+Xcc/Xqq+Xbb+Xcc+QCD scores
    auto VMDsDescending = [&]()
    {
        float VMD0 = vvv.allHad_FJ0_VMD();
        float VMD1 = vvv.allHad_FJ1_VMD();
        float VMD2 = vvv.allHad_FJ2_VMD();
        std::vector<float> Vs;
        if (VMD0 >= VMD1 and VMD0 >= VMD2 and VMD1 >= VMD2) Vs = {VMD0, VMD1, VMD2};
        if (VMD0 >= VMD1 and VMD0 >= VMD2 and VMD2 >= VMD1) Vs = {VMD0, VMD2, VMD1};
        if (VMD1 >= VMD0 and VMD1 >= VMD2 and VMD0 >= VMD2) Vs = {VMD1, VMD0, VMD2};
        if (VMD1 >= VMD0 and VMD1 >= VMD2 and VMD2 >= VMD0) Vs = {VMD1, VMD2, VMD0};
        if (VMD2 >= VMD0 and VMD2 >= VMD1 and VMD0 >= VMD1) Vs = {VMD2, VMD0, VMD1};
        if (VMD2 >= VMD0 and VMD2 >= VMD1 and VMD1 >= VMD0) Vs = {VMD2, VMD1, VMD0};
        return Vs;
    };

    //_______________________________________________________________________________
    // Returns the HT computed using AK4 jets only
    auto HT_ak4 = [&]()
        {
            float HT = 0;
            for (unsigned int i = 0; i < vvv.allHad_jets_p4().size(); ++i)
            {
                HT += vvv.allHad_jets_p4()[i].pt();
            }
            return HT;
        };

    //_______________________________________________________________________________
    // Returns radius of the MSDa/b values away from center of (85, 85)
    auto radius_ab = [&]()
        {
            float VMD1 = VMDsorted()[1].mass();
            float VMD2 = VMDsorted()[2].mass();
            return sqrt(pow(VMD1 - 85, 2) + pow(VMD2 - 85, 2));
        };

    //_______________________________________________________________________________
    // Returns radius away from center of (85, 85)
    auto radius_01 = [&]()
        {
            float VMD0 = vvv.allHad_FJ0_mSD_p4().mass();
            float VMD1 = vvv.allHad_FJ1_mSD_p4().mass();
            return sqrt(pow(VMD0 - 85, 2) + pow(VMD1 - 85, 2));
        };

    //_______________________________________________________________________________
    // Returns radius away from center of (85, 85)
    auto radius_02 = [&]()
        {
            float VMD0 = vvv.allHad_FJ0_mSD_p4().mass();
            float VMD2 = vvv.allHad_FJ2_mSD_p4().mass();
            return sqrt(pow(VMD0 - 85, 2) + pow(VMD2 - 85, 2));
        };

    //_______________________________________________________________________________
    // Returns radius away from center of (85, 85)
    auto radius_12 = [&]()
        {
            float VMD1 = vvv.allHad_FJ1_mSD_p4().mass();
            float VMD2 = vvv.allHad_FJ2_mSD_p4().mass();
            return sqrt(pow(VMD1 - 85, 2) + pow(VMD2 - 85, 2));
        };

    //_______________________________________________________________________________
    // Returns radius away from center of (85, 85)
    auto radius_012 = [&]()
        {
            float VMD0 = vvv.allHad_FJ0_mSD_p4().mass();
            float VMD1 = vvv.allHad_FJ1_mSD_p4().mass();
            float VMD2 = vvv.allHad_FJ2_mSD_p4().mass();
            return sqrt(pow(VMD0 - 85, 2) + pow(VMD1 - 85, 2) + pow(VMD2 - 85, 2));
        };

    //_______________________________________________________________________________
    auto VMD0p4_SF = [&](float pt)
        {
            if (pt >= 200 and pt < 250) return 1.29440907471;
            if (pt >= 250 and pt < 300) return 1.28090117769;
            if (pt >= 300 and pt < 350) return 1.27446411485;
            if (pt >= 350 and pt < 400) return 1.26306236664;
            if (pt >= 400 and pt < 450) return 1.27071708912;
            if (pt >= 450 and pt < 500) return 1.27804980241;
            if (pt >= 500 and pt < 550) return 1.27762531922;
            if (pt >= 550 and pt < 600) return 1.30006570695;
            if (pt >= 600             ) return 1.33278758211;
            else                        return 1.00000000000;
        };

    //_______________________________________________________________________________
    auto VMD0p4_ineffSF = [&](float pt)
        {
            if (pt >= 200 and pt < 250) return 0.829922666647;
            if (pt >= 250 and pt < 300) return 0.813447622921;
            if (pt >= 300 and pt < 350) return 0.816607145368;
            if (pt >= 350 and pt < 400) return 0.829859429613;
            if (pt >= 400 and pt < 450) return 0.834301979291;
            if (pt >= 450 and pt < 500) return 0.832412094501;
            if (pt >= 500 and pt < 550) return 0.833088639958;
            if (pt >= 550 and pt < 600) return 0.827573867412;
            if (pt >= 600             ) return 0.822212583505;
            else                        return 1.00000000000;
        };

    //_______________________________________________________________________________
    auto VMD0p6_SF = [&](float pt)
        {
            if (pt >= 200 and pt < 250) return 1.3147757453 ;
            if (pt >= 250 and pt < 300) return 1.27669956731;
            if (pt >= 300 and pt < 350) return 1.28397877821;
            if (pt >= 350 and pt < 400) return 1.26613857403;
            if (pt >= 400 and pt < 450) return 1.27522074525;
            if (pt >= 450 and pt < 500) return 1.30206287535;
            if (pt >= 500 and pt < 550) return 1.30323904979;
            if (pt >= 550 and pt < 600) return 1.32972185118;
            if (pt >= 600             ) return 1.35072225183;
            else                        return 1.00000000000;
        };

    //_______________________________________________________________________________
    auto VMD0p6_ineffSF = [&](float pt)
        {
            if (pt >= 200 and pt < 250) return 0.90641678061;
            if (pt >= 250 and pt < 300) return 0.90183402933;
            if (pt >= 300 and pt < 350) return 0.89967876043;
            if (pt >= 350 and pt < 400) return 0.90895086656;
            if (pt >= 400 and pt < 450) return 0.91056483827;
            if (pt >= 450 and pt < 500) return 0.90493233241;
            if (pt >= 500 and pt < 550) return 0.90528953116;
            if (pt >= 550 and pt < 600) return 0.90276189051;
            if (pt >= 600             ) return 0.90315561665;
            else                        return 1.00000000000;
        };

    //_______________________________________________________________________________
    auto VMD0p8_SF = [&](float pt)
        {
            if (pt >= 200 and pt < 250) return 1.32893107015;
            if (pt >= 250 and pt < 300) return 1.25901767329;
            if (pt >= 300 and pt < 350) return 1.25500490767;
            if (pt >= 350 and pt < 400) return 1.25073549711;
            if (pt >= 400 and pt < 450) return 1.22783508114;
            if (pt >= 450 and pt < 500) return 1.27004526173;
            if (pt >= 500 and pt < 550) return 1.30545185756;
            if (pt >= 550 and pt < 600) return 1.28263025928;
            if (pt >= 600             ) return 1.32223397985;
            else                        return 1.00000000000;
        };

    //_______________________________________________________________________________
    auto VMD0p8_ineffSF = [&](float pt)
        {
            if (pt >= 200 and pt < 250) return 0.96069773538;
            if (pt >= 250 and pt < 300) return 0.96270916190;
            if (pt >= 300 and pt < 350) return 0.96258385092;
            if (pt >= 350 and pt < 400) return 0.96409010593;
            if (pt >= 400 and pt < 450) return 0.96833122554;
            if (pt >= 450 and pt < 500) return 0.96424362855;
            if (pt >= 500 and pt < 550) return 0.96085705434;
            if (pt >= 550 and pt < 600) return 0.96453807666;
            if (pt >= 600             ) return 0.96258145395;
            else                        return 1.00000000000;
        };

    //_______________________________________________________________________________
    auto Pass80 = [&]() { return vvv.allHad_FJ0_VMD() >= 0.8; };
    auto Pass81 = [&]() { return vvv.allHad_FJ1_VMD() >= 0.8; };
    auto Pass82 = [&]() { return vvv.allHad_FJ2_VMD() >= 0.8; };
    auto Fail80 = [&]() { return vvv.allHad_FJ0_VMD() <  0.8; };
    auto Fail81 = [&]() { return vvv.allHad_FJ1_VMD() <  0.8; };
    auto Fail82 = [&]() { return vvv.allHad_FJ2_VMD() <  0.8; };
    auto Pass40 = [&]() { return vvv.allHad_FJ0_VMD() >= 0.4; };
    auto Pass41 = [&]() { return vvv.allHad_FJ1_VMD() >= 0.4; };
    auto Pass42 = [&]() { return vvv.allHad_FJ2_VMD() >= 0.4; };
    auto Fail40 = [&]() { return vvv.allHad_FJ0_VMD() <  0.4; };
    auto Fail41 = [&]() { return vvv.allHad_FJ1_VMD() <  0.4; };
    auto Fail42 = [&]() { return vvv.allHad_FJ2_VMD() <  0.4; };
    auto On0 = [&]() { return vvv.allHad_FJ0_mSD_p4().mass() >= 60 and vvv.allHad_FJ0_mSD_p4().mass() >= 110; };
    auto On1 = [&]() { return vvv.allHad_FJ1_mSD_p4().mass() >= 60 and vvv.allHad_FJ1_mSD_p4().mass() >= 110; };
    auto On2 = [&]() { return vvv.allHad_FJ2_mSD_p4().mass() >= 60 and vvv.allHad_FJ2_mSD_p4().mass() >= 110; };
    auto Off0 = [&]() { return not (vvv.allHad_FJ0_mSD_p4().mass() >= 60 and vvv.allHad_FJ0_mSD_p4().mass() >= 110); };
    auto Off1 = [&]() { return not (vvv.allHad_FJ1_mSD_p4().mass() >= 60 and vvv.allHad_FJ1_mSD_p4().mass() >= 110); };
    auto Off2 = [&]() { return not (vvv.allHad_FJ2_mSD_p4().mass() >= 60 and vvv.allHad_FJ2_mSD_p4().mass() >= 110); };
    auto In01 = [&]() { return radius_01() <= 30.; };
    auto In02 = [&]() { return radius_02() <= 30.; };
    auto In12 = [&]() { return radius_12() <= 30.; };
    auto Out01 = [&]() { return radius_01() > 30; };
    auto Out02 = [&]() { return radius_02() > 30; };
    auto Out12 = [&]() { return radius_12() > 30; };
    auto Close = [&]() { return radius_012() <= 35.; };
    auto Shell = [&]() { return radius_012() <= 50. and radius_012() > 35.; };
    auto Open = [&]() { return radius_012() > 50.; };

    auto Pass80SF = [&]() { return ana.looper.getCurrentFileName().Contains("QCD") ? VMD0p8_SF(vvv.allHad_FJ0_mSD_p4().pt()) : 1.; };
    auto Pass81SF = [&]() { return ana.looper.getCurrentFileName().Contains("QCD") ? VMD0p8_SF(vvv.allHad_FJ1_mSD_p4().pt()) : 1.; };
    auto Pass82SF = [&]() { return ana.looper.getCurrentFileName().Contains("QCD") ? VMD0p8_SF(vvv.allHad_FJ2_mSD_p4().pt()) : 1.; };
    auto Fail80SF = [&]() { return ana.looper.getCurrentFileName().Contains("QCD") ? VMD0p8_ineffSF(vvv.allHad_FJ0_mSD_p4().pt()) : 1.; };
    auto Fail81SF = [&]() { return ana.looper.getCurrentFileName().Contains("QCD") ? VMD0p8_ineffSF(vvv.allHad_FJ1_mSD_p4().pt()) : 1.; };
    auto Fail82SF = [&]() { return ana.looper.getCurrentFileName().Contains("QCD") ? VMD0p8_ineffSF(vvv.allHad_FJ2_mSD_p4().pt()) : 1.; };
    auto Pass40SF = [&]() { return ana.looper.getCurrentFileName().Contains("QCD") ? VMD0p4_SF(vvv.allHad_FJ0_mSD_p4().pt()) : 1.; };
    auto Pass41SF = [&]() { return ana.looper.getCurrentFileName().Contains("QCD") ? VMD0p4_SF(vvv.allHad_FJ1_mSD_p4().pt()) : 1.; };
    auto Pass42SF = [&]() { return ana.looper.getCurrentFileName().Contains("QCD") ? VMD0p4_SF(vvv.allHad_FJ2_mSD_p4().pt()) : 1.; };
    auto Fail40SF = [&]() { return ana.looper.getCurrentFileName().Contains("QCD") ? VMD0p4_ineffSF(vvv.allHad_FJ0_mSD_p4().pt()) : 1.; };
    auto Fail41SF = [&]() { return ana.looper.getCurrentFileName().Contains("QCD") ? VMD0p4_ineffSF(vvv.allHad_FJ1_mSD_p4().pt()) : 1.; };
    auto Fail42SF = [&]() { return ana.looper.getCurrentFileName().Contains("QCD") ? VMD0p4_ineffSF(vvv.allHad_FJ2_mSD_p4().pt()) : 1.; };

    auto NotPass8 = [&]() { return not (Pass80() and Pass81() and Pass82()); };
    auto NotPass8SF = [&]()
        {
            if (ana.looper.getCurrentFileName().Contains("QCD"))
            {

                float sf = 1.;
                if (    Pass80()) sf *= VMD0p8_SF     (vvv.allHad_FJ0_mSD_p4().pt());
                if (not Pass80()) sf *= VMD0p8_ineffSF(vvv.allHad_FJ0_mSD_p4().pt());
                if (    Pass81()) sf *= VMD0p8_SF     (vvv.allHad_FJ1_mSD_p4().pt());
                if (not Pass81()) sf *= VMD0p8_ineffSF(vvv.allHad_FJ1_mSD_p4().pt());
                if (    Pass82()) sf *= VMD0p8_SF     (vvv.allHad_FJ2_mSD_p4().pt());
                if (not Pass82()) sf *= VMD0p8_ineffSF(vvv.allHad_FJ2_mSD_p4().pt());
                return sf;
            }
            else
            {
                return 1.f;
            }
        };

    //_______________________________________________________________________________
    auto MSDaMassCut = [&]()
        {
            return VMDsorted()[0].mass() >= 60 and VMDsorted()[0].mass() <= 110;
        };

    //_______________________________________________________________________________
    auto AntiV0Cut = [&]()
        {
            return vvv.allHad_FJ0_VMD() < 0.4 and vvv.allHad_FJ1_VMD() >= 0.4 and vvv.allHad_FJ2_VMD() >= 0.4;
        };

    //_______________________________________________________________________________
    auto AntiV0p8Cut = [&]()
        {
            return vvv.allHad_FJ0_VMD() < 0.8 and vvv.allHad_FJ1_VMD() >= 0.8 and vvv.allHad_FJ2_VMD() >= 0.8;
        };

    //_______________________________________________________________________________
    // Cuts
    auto In   = [&]() { return radius_ab() <= 30.; };
    auto Out  = [&]() { return not In(); };
    auto On   = [&]() { return VMDsorted()[0].mass() >= 60 and VMDsorted()[0].mass() <= 110; };
    auto Off  = [&]() { return not On(); };
    auto Pass = [&]() { return vvv.allHad_FJ0_VMD() >= 0.8 and vvv.allHad_FJ1_VMD() >= 0.8 and vvv.allHad_FJ2_VMD() >= 0.8; };
    auto Fail = [&]() { return vvv.allHad_FJ0_VMD() <  0.8 and vvv.allHad_FJ1_VMD() <  0.8 and vvv.allHad_FJ2_VMD() >= 0.8; };

    //_______________________________________________________________________________
    auto Pass0p4SF = [&]()
        {
            if (ana.looper.getCurrentFileName().Contains("QCD"))
                return VMD0p4_SF(vvv.allHad_FJ0_mSD_p4().pt())*VMD0p4_SF(vvv.allHad_FJ1_mSD_p4().pt())*VMD0p4_SF(vvv.allHad_FJ2_mSD_p4().pt());
            else
                return 1.;
        };

    //_______________________________________________________________________________
    auto Fail0p4SF = [&]()
        {
            if (ana.looper.getCurrentFileName().Contains("QCD"))
                return VMD0p4_ineffSF(vvv.allHad_FJ0_mSD_p4().pt())*VMD0p4_SF(vvv.allHad_FJ1_mSD_p4().pt())*VMD0p4_SF(vvv.allHad_FJ2_mSD_p4().pt());
            else
                return 1.;
        };

    //_______________________________________________________________________________
    auto Pass0p8SF = [&]()
        {
            if (ana.looper.getCurrentFileName().Contains("QCD"))
                return VMD0p8_SF(vvv.allHad_FJ0_mSD_p4().pt())*VMD0p8_SF(vvv.allHad_FJ1_mSD_p4().pt())*VMD0p8_SF(vvv.allHad_FJ2_mSD_p4().pt());
            else
                return 1.;
        };

    //_______________________________________________________________________________
    auto Fail0p8SF = [&]()
        {
            if (ana.looper.getCurrentFileName().Contains("QCD"))
                return VMD0p8_ineffSF(vvv.allHad_FJ0_mSD_p4().pt())*VMD0p8_ineffSF(vvv.allHad_FJ1_mSD_p4().pt())*VMD0p8_SF(vvv.allHad_FJ2_mSD_p4().pt());
            else
                return 1.;
        };

    //_______________________________________________________________________________
    auto PassSF = [&]()
        {
            if (ana.looper.getCurrentFileName().Contains("QCD"))
                return Pass0p8SF();
            else
                return 1.;
        };

    //_______________________________________________________________________________
    auto FailSF = [&]()
        {
            if (ana.looper.getCurrentFileName().Contains("QCD"))
                return Fail0p8SF();
            else
                return 1.;
        };

    //_______________________________________________________________________________
    // Various regions
    auto ABCD = [&]()
        {
            if (In () and On ()) { return 0.; }
            if (In () and Off()) { return 1.; }
            if (Out() and On ()) { return 2.; }
            if (Out() and Off()) { return 3.; }
            return -999.;
        };

    //_______________________________________________________________________________
    auto BlindingCut = [&]()
        {
            if (ana.looper.getCurrentFileName().Contains("JetHT"))
            {
                if (MSDaMassCut() and radius_ab() <= 30. and Pass())
                    return false;
                else
                    return true;
            }
            else
            {
                return true;
            }
        };




//********************************************************************************
//
// 5. Setting up cutflow
//
//********************************************************************************

// Weighting and preselections______________________________________________________________________________________________________________________________________
    ana.cutflow.addCut("WeightByXsec", UNITY,
                       [&, j, n]()
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
                               // if (samplename.EqualTo("WWW")) idx = 94;
                               // if (samplename.EqualTo("WWZ")) idx = 142;
                               // if (samplename.EqualTo("WZZ")) idx = 142;
                               // if (samplename.EqualTo("ZZZ")) idx = 142;
                               if (samplename.EqualTo("WWW")) idx = 91; // FT0 0.2
                               if (samplename.EqualTo("WWZ")) idx = 139; // FT0 0.2
                               if (samplename.EqualTo("WZZ")) idx = 139; // FT0 0.2
                               if (samplename.EqualTo("ZZZ")) idx = 139; // FT0 0.2
                               // if (samplename.EqualTo("WWW")) idx = 92;
                               // if (samplename.EqualTo("WWZ")) idx = 140;
                               // if (samplename.EqualTo("WZZ")) idx = 140;
                               // if (samplename.EqualTo("ZZZ")) idx = 140;
                               if (samplename.EqualTo("Dim6_WWW")) idx = 13; // cW 0.3
                               if (samplename.EqualTo("Dim6_WWZ")) idx = 13; // cW 0.3
                               if (samplename.EqualTo("Dim6_WZZ")) idx = 13; // cW 0.3
                               if (samplename.EqualTo("Dim6_ZZZ")) idx = 13; // cW 0.3
                               // if (samplename.EqualTo("Dim6_WWW")) idx = 19;
                               // if (samplename.EqualTo("Dim6_WWZ")) idx = 19;
                               // if (samplename.EqualTo("Dim6_WZZ")) idx = 19;
                               // if (samplename.EqualTo("Dim6_ZZZ")) idx = 19;
                               wgt *= vvv.Common_genWeight() * vvv.Common_LHEReweightingWeight()[idx];
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




    //
    // Two fat-jet channel______________________________________________________________________________________________________________________________________________
    //
    ana.cutflow.getCut("Preselection");
    ana.cutflow.addCutToLastActiveCut("NFJEq2"     , [&]() { return vvv.allHad_nFJ() == 2; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJEq2MSD0" , [&]() { return vvv.allHad_FJ0_mSD_p4().mass() >= 60 and vvv.allHad_FJ0_mSD_p4().mass() <= 110; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJEq2MSD1" , [&]() { return vvv.allHad_FJ1_mSD_p4().mass() >= 60 and vvv.allHad_FJ1_mSD_p4().mass() <= 110; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJEq2V0p4" , [&]() { return vvv.allHad_FJ0_VMD() >= 0.4 and vvv.allHad_FJ1_VMD() >= 0.4; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJEq2MVVV" , [&]() { return vvv.allHad_mVVV() > 1100.; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJEq2PtVVV", [&]() { return vvv.allHad_ptVVV() > 1100.; }, UNITY);
    // ana.cutflow.addCutToLastActiveCut("NFJEq2Loose", [&]() { return vvv.allHad_FJ0_WP_MD() >= 1 and vvv.allHad_FJ1_WP_MD() >= 1; }, UNITY);
    // ana.cutflow.addCutToLastActiveCut("NFJEq2Tight", [&]() { return vvv.allHad_FJ0_WP_MD() == 3 and vvv.allHad_FJ1_WP_MD() == 3; }, UNITY);
    // ana.cutflow.addCutToLastActiveCut("NFJEq2BVeto", [&]() { return vvv.Common_nb_medium() == 0; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJEq2SR"   , UNITY, UNITY); // Dummy for labeling purpose




    //
    // Three fat-jet channel____________________________________________________________________________________________________________________________________________
    //
    ana.cutflow.getCut("Preselection");
    ana.cutflow.addCutToLastActiveCut("NFJGeq3"       , [&]() { return vvv.allHad_nFJ() >= 3; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJGeq3HTFJ"   , [&]() { return vvv.allHad_HT_FJ() > 1250.; }, UNITY);
    ana.cutflow.addCutToLastActiveCut("NFJGeq3SF"     , UNITY, [&]() { if (ana.looper.getCurrentFileName().Contains("QCD")) return 1.1116193638; else return 1.; } );
    // ana.cutflow.addCutToLastActiveCut("NFJGeq3Blind"  , UNITY, BlindingCut );
    ana.cutflow.addCutToLastActiveCut("NFJGeq3All"    , UNITY, UNITY);

    ana.cutflow.getCut("NFJGeq3All"); ana.cutflow.addCutToLastActiveCut("NFJGeq3Close", Close, UNITY);
    ana.cutflow.getCut("NFJGeq3All"); ana.cutflow.addCutToLastActiveCut("NFJGeq3Shell", Shell, UNITY);
    ana.cutflow.getCut("NFJGeq3All"); ana.cutflow.addCutToLastActiveCut("NFJGeq3Open", Open, UNITY);

    ana.cutflow.getCut("NFJGeq3Close"); ana.cutflow.addCutToLastActiveCut("NFJGeq3ClosePass8", [&]() { return Pass80() and Pass81() and Pass82(); }, [&]() { return Pass80SF() * Pass81SF() * Pass82SF(); });
    ana.cutflow.getCut("NFJGeq3Close"); ana.cutflow.addCutToLastActiveCut("NFJGeq3CloseFail8", [&]() { return Fail80() and Fail81() and Fail82(); }, [&]() { return Fail80SF() * Fail81SF() * Fail82SF(); });
    ana.cutflow.getCut("NFJGeq3Shell"); ana.cutflow.addCutToLastActiveCut("NFJGeq3ShellPass8", [&]() { return Pass80() and Pass81() and Pass82(); }, [&]() { return Pass80SF() * Pass81SF() * Pass82SF(); });
    ana.cutflow.getCut("NFJGeq3Shell"); ana.cutflow.addCutToLastActiveCut("NFJGeq3ShellFail8", [&]() { return Fail80() and Fail81() and Fail82(); }, [&]() { return Fail80SF() * Fail81SF() * Fail82SF(); });
    ana.cutflow.getCut("NFJGeq3Open"); ana.cutflow.addCutToLastActiveCut("NFJGeq3OpenPass8", [&]() { return Pass80() and Pass81() and Pass82(); }, [&]() { return Pass80SF() * Pass81SF() * Pass82SF(); });
    ana.cutflow.getCut("NFJGeq3Open"); ana.cutflow.addCutToLastActiveCut("NFJGeq3OpenFail8", [&]() { return Fail80() and Fail81() and Fail82(); }, [&]() { return Fail80SF() * Fail81SF() * Fail82SF(); });
    ana.cutflow.getCut("NFJGeq3CloseFail8"); ana.cutflow.addCutToLastActiveCut("NFJGeq3CloseFail8Pass4", [&]() { return Pass40() and Pass41() and Pass42(); }, [&]() { return Pass40SF() * Pass41SF() * Pass42SF(); });
    ana.cutflow.getCut("NFJGeq3ShellFail8"); ana.cutflow.addCutToLastActiveCut("NFJGeq3ShellFail8Pass4", [&]() { return Pass40() and Pass41() and Pass42(); }, [&]() { return Pass40SF() * Pass41SF() * Pass42SF(); });
    ana.cutflow.getCut("NFJGeq3OpenFail8"); ana.cutflow.addCutToLastActiveCut("NFJGeq3OpenFail8Pass4", [&]() { return Pass40() and Pass41() and Pass42(); }, [&]() { return Pass40SF() * Pass41SF() * Pass42SF(); });

    ana.cutflow.getCut("NFJGeq3ClosePass8"); ana.cutflow.addCutToLastActiveCut("NFJGeq3ClosePass8HT2000", [&]() { return vvv.allHad_HT_FJ() > 2000.; }, UNITY);
    ana.cutflow.getCut("NFJGeq3CloseFail8"); ana.cutflow.addCutToLastActiveCut("NFJGeq3CloseFail8HT2000", [&]() { return vvv.allHad_HT_FJ() > 2000.; }, UNITY);
    ana.cutflow.getCut("NFJGeq3ShellPass8"); ana.cutflow.addCutToLastActiveCut("NFJGeq3ShellPass8HT2000", [&]() { return vvv.allHad_HT_FJ() > 2000.; }, UNITY);
    ana.cutflow.getCut("NFJGeq3ShellFail8"); ana.cutflow.addCutToLastActiveCut("NFJGeq3ShellFail8HT2000", [&]() { return vvv.allHad_HT_FJ() > 2000.; }, UNITY);
    ana.cutflow.getCut("NFJGeq3OpenPass8"); ana.cutflow.addCutToLastActiveCut("NFJGeq3OpenPass8HT2000", [&]() { return vvv.allHad_HT_FJ() > 2000.; }, UNITY);
    ana.cutflow.getCut("NFJGeq3OpenFail8"); ana.cutflow.addCutToLastActiveCut("NFJGeq3OpenFail8HT2000", [&]() { return vvv.allHad_HT_FJ() > 2000.; }, UNITY);

    ana.cutflow.getCut("NFJGeq3Close"); ana.cutflow.addCutToLastActiveCut("NFJGeq3CloseNotPass8", NotPass8, NotPass8SF);
    ana.cutflow.getCut("NFJGeq3Shell"); ana.cutflow.addCutToLastActiveCut("NFJGeq3ShellNotPass8", NotPass8, NotPass8SF);
    ana.cutflow.getCut("NFJGeq3Open"); ana.cutflow.addCutToLastActiveCut("NFJGeq3OpenNotPass8", NotPass8, NotPass8SF);

    ana.cutflow.getCut("NFJGeq3Close"); ana.cutflow.addCutToLastActiveCut("NFJGeq3ClosePass4", [&]() { return Pass40() and Pass41() and Pass42(); }, [&]() { return Pass40SF() * Pass41SF() * Pass42SF(); });
    ana.cutflow.getCut("NFJGeq3Close"); ana.cutflow.addCutToLastActiveCut("NFJGeq3CloseFail4", [&]() { return Fail40() and Fail41() and Fail42(); }, [&]() { return Fail40SF() * Fail41SF() * Fail42SF(); });
    ana.cutflow.getCut("NFJGeq3Shell"); ana.cutflow.addCutToLastActiveCut("NFJGeq3ShellPass4", [&]() { return Pass40() and Pass41() and Pass42(); }, [&]() { return Pass40SF() * Pass41SF() * Pass42SF(); });
    ana.cutflow.getCut("NFJGeq3Shell"); ana.cutflow.addCutToLastActiveCut("NFJGeq3ShellFail4", [&]() { return Fail40() and Fail41() and Fail42(); }, [&]() { return Fail40SF() * Fail41SF() * Fail42SF(); });
    ana.cutflow.getCut("NFJGeq3Open"); ana.cutflow.addCutToLastActiveCut("NFJGeq3OpenPass4", [&]() { return Pass40() and Pass41() and Pass42(); }, [&]() { return Pass40SF() * Pass41SF() * Pass42SF(); });
    ana.cutflow.getCut("NFJGeq3Open"); ana.cutflow.addCutToLastActiveCut("NFJGeq3OpenFail4", [&]() { return Fail40() and Fail41() and Fail42(); }, [&]() { return Fail40SF() * Fail41SF() * Fail42SF(); });



    //
    // Two fat-jet channel SF measurement region________________________________________________________________________________________________________________________
    //
    ana.cutflow.getCut("NFJEq2MSD1"); ana.cutflow.addCutToLastActiveCut("NFJEq2Pt1200250" , [&]() { return vvv.allHad_FJ1_mSD_p4().pt() >= 200. and vvv.allHad_FJ1_mSD_p4().pt() <  250; }, UNITY);
    ana.cutflow.getCut("NFJEq2MSD1"); ana.cutflow.addCutToLastActiveCut("NFJEq2Pt1250300" , [&]() { return vvv.allHad_FJ1_mSD_p4().pt() >= 250. and vvv.allHad_FJ1_mSD_p4().pt() <  300; }, UNITY);
    ana.cutflow.getCut("NFJEq2MSD1"); ana.cutflow.addCutToLastActiveCut("NFJEq2Pt1300350" , [&]() { return vvv.allHad_FJ1_mSD_p4().pt() >= 300. and vvv.allHad_FJ1_mSD_p4().pt() <  350; }, UNITY);
    ana.cutflow.getCut("NFJEq2MSD1"); ana.cutflow.addCutToLastActiveCut("NFJEq2Pt1350400" , [&]() { return vvv.allHad_FJ1_mSD_p4().pt() >= 350. and vvv.allHad_FJ1_mSD_p4().pt() <  400; }, UNITY);
    ana.cutflow.getCut("NFJEq2MSD1"); ana.cutflow.addCutToLastActiveCut("NFJEq2Pt1400450" , [&]() { return vvv.allHad_FJ1_mSD_p4().pt() >= 400. and vvv.allHad_FJ1_mSD_p4().pt() <  450; }, UNITY);
    ana.cutflow.getCut("NFJEq2MSD1"); ana.cutflow.addCutToLastActiveCut("NFJEq2Pt1450500" , [&]() { return vvv.allHad_FJ1_mSD_p4().pt() >= 450. and vvv.allHad_FJ1_mSD_p4().pt() <  500; }, UNITY);
    ana.cutflow.getCut("NFJEq2MSD1"); ana.cutflow.addCutToLastActiveCut("NFJEq2Pt1500550" , [&]() { return vvv.allHad_FJ1_mSD_p4().pt() >= 500. and vvv.allHad_FJ1_mSD_p4().pt() <  550; }, UNITY);
    ana.cutflow.getCut("NFJEq2MSD1"); ana.cutflow.addCutToLastActiveCut("NFJEq2Pt1550600" , [&]() { return vvv.allHad_FJ1_mSD_p4().pt() >= 550. and vvv.allHad_FJ1_mSD_p4().pt() <  600; }, UNITY);
    ana.cutflow.getCut("NFJEq2MSD1"); ana.cutflow.addCutToLastActiveCut("NFJEq2Pt1600Inf" , [&]() { return vvv.allHad_FJ1_mSD_p4().pt() >= 600.                                        ; }, UNITY);





    // Print cut structure
    ana.cutflow.printCuts();







//********************************************************************************
//
// 6. Setting up histograms
//
//********************************************************************************

    // Histogram utility object that is used to define the histograms
    ana.histograms.addHistogram("MSD0"   , 180 , 40 , 150  , [&]() { return vvv.allHad_FJ0_mSD_p4().mass(); } );
    ana.histograms.addHistogram("MSD1"   , 180 , 40 , 150  , [&]() { return vvv.allHad_FJ1_mSD_p4().mass(); } );
    ana.histograms.addHistogram("MSD2"   , 180 , 40 , 150  , [&]() { return vvv.allHad_FJ2_mSD_p4().mass(); } );
    ana.histograms.addHistogram("MSDa"   , 180 , 40 , 150  , [&]() { return VMDsorted()[0].mass(); } );
    ana.histograms.addHistogram("MSDb"   , 180 , 40 , 150  , [&]() { return VMDsorted()[1].mass(); } );
    ana.histograms.addHistogram("MSDc"   , 180 , 40 , 150  , [&]() { return VMDsorted()[2].mass(); } );
    ana.histograms.addHistogram("radius" , 180 , 0  , 65   , [&]() { return radius_ab(); } );
    ana.histograms.addHistogram("radi01" , 180 , 0  , 65   , [&]() { return radius_01(); } );
    ana.histograms.addHistogram("radi02" , 180 , 0  , 65   , [&]() { return radius_02(); } );
    ana.histograms.addHistogram("radi12" , 180 , 0  , 65   , [&]() { return radius_12(); } );
    ana.histograms.addHistogram("sphrad" , 180 , 0  , 65   , [&]() { return radius_012(); } );
    ana.histograms.addHistogram("Pt0"    , 180 , 0  , 5500 , [&]() { return vvv.allHad_FJ0_mSD_p4().pt(); } );
    ana.histograms.addHistogram("Pt1"    , 180 , 0  , 4500 , [&]() { return vvv.allHad_FJ1_mSD_p4().pt(); } );
    ana.histograms.addHistogram("Pt2"    , 180 , 0  , 2500 , [&]() { return vvv.allHad_FJ2_mSD_p4().pt(); } );
    ana.histograms.addHistogram("W0"     , 180 , 0  , 1    , [&]() { return vvv.allHad_FJ0_WMD(); } );
    ana.histograms.addHistogram("W1"     , 180 , 0  , 1    , [&]() { return vvv.allHad_FJ1_WMD(); } );
    ana.histograms.addHistogram("W2"     , 180 , 0  , 1    , [&]() { return vvv.allHad_FJ2_WMD(); } );
    ana.histograms.addHistogram("V0"     , 180 , 0  , 1    , [&]() { return vvv.allHad_FJ0_VMD(); } );
    ana.histograms.addHistogram("V1"     , 180 , 0  , 1    , [&]() { return vvv.allHad_FJ1_VMD(); } );
    ana.histograms.addHistogram("V2"     , 180 , 0  , 1    , [&]() { return vvv.allHad_FJ2_VMD(); } );
    ana.histograms.addHistogram("Va"     , 180 , 0  , 1    , [&]() { return VMDsDescending()[0]; } );
    ana.histograms.addHistogram("Vb"     , 180 , 0  , 1    , [&]() { return VMDsDescending()[1]; } );
    ana.histograms.addHistogram("Vc"     , 180 , 0  , 1    , [&]() { return VMDsDescending()[2]; } );
    ana.histograms.addHistogram("AK0"    , 180 , 0  , 2500 , [&]() { return vvv.allHad_jets_p4().size() > 0 ? vvv.allHad_jets_p4()[0].pt() : -999; } );
    ana.histograms.addHistogram("V1SF"   , {0., 0.4, 1}    , [&]() { return vvv.allHad_FJ1_VMD(); } );
    ana.histograms.addHistogram("V1SF0p6", {0., 0.6, 1}    , [&]() { return vvv.allHad_FJ1_VMD(); } );
    ana.histograms.addHistogram("V1SF0p8", {0., 0.8, 1}    , [&]() { return vvv.allHad_FJ1_VMD(); } );
    ana.histograms.addHistogram("V1SF0p9", {0., 0.9, 1}    , [&]() { return vvv.allHad_FJ1_VMD(); } );

    ana.histograms.addHistogram("OnOff"  , 2   , 0  , 1    , [&]() { return radius_ab() <= 30; } );

    ana.histograms.addHistogram("NbLoose"      , 5  , 0 , 5  , [&]() { return vvv.allHad_nb_loose(); } );
    ana.histograms.addHistogram("NbMedium"     , 5  , 0 , 5  , [&]() { return vvv.allHad_nb_medium(); } );
    ana.histograms.addHistogram("NbTight"      , 5  , 0 , 5  , [&]() { return vvv.allHad_nb_tight(); } );
    ana.histograms.addHistogram("NoORNbLoose"  , 7  , 0 , 7  , [&]() { return vvv.Common_nb_loose(); } );
    ana.histograms.addHistogram("NoORNbMedium" , 7  , 0 , 7  , [&]() { return vvv.Common_nb_medium(); } );
    ana.histograms.addHistogram("NoORNbTight"  , 7  , 0 , 7  , [&]() { return vvv.Common_nb_tight(); } );
    ana.histograms.addHistogram("NL"           , 15 , 0 , 15 , [&]() { return vvv.Common_lep_pdgid().size(); } );
    ana.histograms.addHistogram("NJ"           , 10 , 0 , 10 , [&]() { return vvv.allHad_jets_p4().size(); } );
    ana.histograms.addHistogram("NoORNJ"       , 10 , 0 , 10 , [&]() { return vvv.Common_jet_p4().size(); } );
    ana.histograms.addHistogram("NFJ"          , 10 , 0 , 10 , [&]() { return vvv.allHad_nFJ(); } );

    ana.histograms.addHistogram("HT"     , 180 , 0 , 8500 , [&]() { return vvv.allHad_HT(); } );
    ana.histograms.addHistogram("HT_FJ"  , 180 , 0 , 5500 , [&]() { return vvv.allHad_HT_FJ(); } );
    ana.histograms.addHistogram("HT_AK4" , 180 , 0 , 2500 , HT_ak4 );
    ana.histograms.addHistogram("HT_FJSR", {1250., 1500., 1750., 2000., 2250., 2500., 2750., 3000., 3500., 5000.},[&]() { return vvv.allHad_HT_FJ(); } );
    ana.histograms.addHistogram("HT_FJSR2", {1250., 1500., 1750., 2000., 2500., 3000., 3500., 5000.},[&]() { return vvv.allHad_HT_FJ(); } );
    ana.histograms.addHistogram("HT_FJSR3", {1250., 1500., 1750., 2000., 2500., 3000., 4000.},[&]() { return vvv.allHad_HT_FJ(); } );
    ana.histograms.addHistogram("HT_FJSR4", {1250., 1500., 1750., 2000., 2500., 4000.},[&]() { return vvv.allHad_HT_FJ(); } );

    ana.histograms.addHistogram("MVVV"  , 180 , 0 , 8500 , [&]() { return vvv.allHad_mVVV(); } );
    ana.histograms.addHistogram("PtVVV" , 180 , 0 , 5500 , [&]() { return vvv.allHad_ptVVV(); } );
    ana.histograms.addHistogram("MVVVSR", {1000., 1250., 1500., 1750., 2000., 2250., 2500., 2750., 3000., 3500., 4000., 5000., 8000.}, [&]() { return vvv.allHad_mVVV(); } );

    ana.histograms.addHistogram("nGenHadV", 5, -1, 4, nGenHadV);
    ana.histograms.addHistogram("nFJGenMatched", 5, -1, 4, nFJGenMatched);

    ana.histograms.add2DHistogram("MSDb", 15, 40., 150., "MSDc", 15, 40., 150., [&]() { return VMDsorted()[1].mass(); }, [&]() { return VMDsorted()[2].mass(); });

    ana.histograms.addHistogram("ABCD", 4, 0, 4, ABCD);

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






//********************************************************************************
//
// 7. Run the code!!!!!
//
//********************************************************************************


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





















//  ---------------------==============================-------------------------================================----------------------===========================----------------------==================
//  ---------------------==============================-------------------------================================----------------------===========================----------------------==================
//  ---------------------==============================-------------------------================================----------------------===========================----------------------==================



// Deprecated___________________________________________________________________________________________________________________________________________________________________
    // ana.histograms.addHistogram("FJ01_dPhi", 180, 0, 3.1416, [&]() { return fabs(vvv.allHad_FJ01_dPhi()); } );
    // ana.histograms.addHistogram("FJ01_dEta", 180, 0, 7, [&]() { return fabs(vvv.allHad_FJ01_dEta()); } );
    // ana.histograms.addHistogram("FJ01_dR", 180, 0, 7, [&]() { return fabs(vvv.allHad_FJ01_dR()); } );
    // ana.histograms.addHistogram("FJ01_dPtFrac", 180, -2, 2, [&]() { return vvv.allHad_FJ01_dPtFrac(); } );
    // ana.histograms.addHistogram("FJ01_pPRel", 180, 0, 5500, [&]() { return vvv.allHad_FJ01_pPRel(); } );

    // ana.histograms.addHistogram("FJ02_dPhi", 180, 0, 3.1416, [&]() { return fabs(vvv.allHad_FJ02_dPhi()); } );
    // ana.histograms.addHistogram("FJ02_dEta", 180, 0, 7, [&]() { return fabs(vvv.allHad_FJ02_dEta()); } );
    // ana.histograms.addHistogram("FJ02_dR", 180, 0, 7, [&]() { return fabs(vvv.allHad_FJ02_dR()); } );
    // ana.histograms.addHistogram("FJ02_dPtFrac", 180, -2, 2, [&]() { return vvv.allHad_FJ02_dPtFrac(); } );
    // ana.histograms.addHistogram("FJ02_pPRel", 180, 0, 5500, [&]() { return vvv.allHad_FJ02_pPRel(); } );

    // ana.histograms.addHistogram("FJ12_dPhi", 180, 0, 3.1416, [&]() { return fabs(vvv.allHad_FJ12_dPhi()); } );
    // ana.histograms.addHistogram("FJ12_dEta", 180, 0, 7, [&]() { return fabs(vvv.allHad_FJ12_dEta()); } );
    // ana.histograms.addHistogram("FJ12_dR", 180, 0, 7, [&]() { return fabs(vvv.allHad_FJ12_dR()); } );
    // ana.histograms.addHistogram("FJ12_dPtFrac", 180, -2, 2, [&]() { return vvv.allHad_FJ12_dPtFrac(); } );
    // ana.histograms.addHistogram("FJ12_pPRel", 180, 0, 5500, [&]() { return vvv.allHad_FJ12_pPRel(); } );

    // ana.histograms.addHistogram("Gen01_mass", 180, 60, 120, [&]() { return vvv.Common_gen_vvvdecay_p4s().size() > 0 ? (vvv.Common_gen_vvvdecay_p4s()[0] + vvv.Common_gen_vvvdecay_p4s()[1]).mass() : -999; } );
    // ana.histograms.addHistogram("Gen23_mass", 180, 60, 120, [&]() { return vvv.Common_gen_vvvdecay_p4s().size() > 0 ? (vvv.Common_gen_vvvdecay_p4s()[2] + vvv.Common_gen_vvvdecay_p4s()[3]).mass() : -999; } );
    // ana.histograms.addHistogram("Gen45_mass", 180, 60, 120, [&]() { return vvv.Common_gen_vvvdecay_p4s().size() > 0 ? (vvv.Common_gen_vvvdecay_p4s()[4] + vvv.Common_gen_vvvdecay_p4s()[5]).mass() : -999; } );

