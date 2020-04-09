# VVVNanoLooper

## Installation

    ssh uaf-10.t2.ucsd.edu
    cd your/favoriate/working/directory
    git clone --recursive git@github.com:sgnoohc/VVVNanoLooper.git
    cd VVVNanoLooper/
    source rooutil/thisrooutil.sh
    source rooutil/root.sh
    make clean; // Clean only VVV looper related
    make cleanall; // Full clean include NanoTools/rooutil related objects
    make -j;

## Quick start

Below command will create ```debug.root``` output from the loop

     ./doVVVAnalysis --input /hadoop/cms/store/group/snt/nanoaod/GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8__RunIIAutumn18NanoAODv5-Nano1June2019_102X_upgrade2018_realistic_v19-v1/C91570D8-46E6-6A4F-B722-857B9C5FE1F4.root \
        --tree Events \
        --mode 0 \
        --debug

Alternatively, if you want to write it out to ```my_output.root```,

     ./doVVVAnalysis --input /hadoop/cms/store/group/snt/nanoaod/GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8__RunIIAutumn18NanoAODv5-Nano1June2019_102X_upgrade2018_realistic_v19-v1/C91570D8-46E6-6A4F-B722-857B9C5FE1F4.root \
        --tree Events \
        --mode 0 \
        --output my_output.root

This will create some dummy histograms with dummy variables with dummy selections.  See the actual source code to see what is going on.

## Code organization

The ```doVVVAnalysis``` executable will take in NanoAOD root file and produce histograms (or TTree--but currently not implemented).

The development of different VVV channel will be modular by the option ```--mode```.

Currently the implemented catgories are

      -m, --mode arg         Looper mode (--mode 0=k4LepMET, 1=k4Lep2jet,
                             2=k3LepMET, 3=k3Lep2jet, 4=kOS4jet, 5=kOS2jet, 6=kSS2jet,
                             7=k1Lep4jet)

### Begin, Process, Terminate concept

The looper follows the ROOT's TSelector style framework.

There are separate ```Begin_<cateogry>```, ```Process_<catgory>```, and ```Terminate_<cateogry>``` functions defined in ```src/*_<category>.cc/h```.

The ```--mode``` option will determine which one will be called.

Regardless of which mode it is, the ```Begin_Common```, ```Process_Common```, and ```Terminate_Common``` will always run before each channel's relevant function runs.

So the pseudocode representation of the order of function call look like the following:

    main()
    {
        ...
        ...

        Begin_Common();
        Begin_<category>();

        while (event loop)
        {

            Process_Common();
            Process_<category>();

        }

        Terminate_Common();
        Terminate_<category>();

        ...
        ...
            
    }

#### Begin

This is where variables, histograms, or event selections needed for the category are defined.

##### Adding variables

When adding variables use the following functions and guidelines:

The naming of the variable should be <category>_<name> to minimize any clashes between different channels.

If you want to add float, int, bool, double type variable, use "float" type for simplicity.
    ana.tx.createBranch<float>("<category>_<name>");

If you want to add a LorentzVector type, use the following
    ana.tx.createBranch<LorentzVector>("<category>_<name>");

If you want to have an list of float
    ana.tx.createBranch<vector<float>>("<category>_<name>");

If you want to have an list of ints (e.g. index of lepton / jets or some objects in the NanoAOD)
    ana.tx.createBranch<vector<int>>("<category>_<name>");

If you want to have an list of lorentzVectors (e.g. list of electron p4s)
    ana.tx.createBranch<vector<LorentzVector>>("<category>_<name>");

##### Adding histograms

Histograms are defined in example like the following:

    ana.histograms.addHistogram("h_Common_nLep", 10, 0, 10, [&]() { return ana.tx.getBranchLazy<vector<int>>("Common_electron_idxs").size() + ana.tx.getBranchLazy<vector<int>>("Common_muon_idxs").size(); } );

Note that ```getBranchLazy``` used to access the variables that was defined to determine how the histogram will be filled.

##### Note on common variables that would be shared across different channels

If some variables, histograms, or event selections need to run for all categories, then they should be implemented in ```Common``` equivalent area.

#### Process

This is where the variables are computed and set

If you want to set float, int, bool, double type variable, that are declared as "float" type for simplicity.
    ana.tx.setBranch<float>("<category>_<name>", -999);

If you want to set a LorentzVector type, use the following
    ana.tx.setBranch<LorentzVector>("<category>_<name>", lorentzVector);

If you want to add a float to the list of float
    ana.tx.pushbackToBranch<float>("<category>_<name>", -999);

If you want to add a int to the list of ints (e.g. index of lepton / jets or some objects in the NanoAOD)
    ana.tx.pushbackToBranch<int>("<category>_<name>", -999);

If you want to add a LorentzVector to the list of LorentzVector
    ana.tx.pushbackToBranch<LorentzVector>("<category>_<name>", lorentzVector);

If some variables need to run for all categories, then they should be implemented in ```Common``` equivalent area.

#### Terminate

This is where the stuff that runs once after the event loop is done.

If some action needs to run for all categories, then they should be implemented in ```Common``` equivalent area.

### Some tips on debugging

If you encounter an error that starts with something like ```RooUtil:: ERROR blah blah blah```, then approach it like the following using ```gdb```

Start ```gdb``` by ```gdb --args <your usual command>```. -> After the prompt opens run the program via "r" and when it dies, type ```backtrace``` or ```bt``` for short.

In the case shown below, the key point is here:

    #4  0x0000000000490fcf in <lambda()>::operator() (__closure=<optimized out>) at src/Begin_Common.cc:25

The following is the full print out

    $ gdb --args ./doVVVAnalysis -i /hadoop/cms/store/group/snt/nanoaod/GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8__RunIIAutumn18NanoAODv5-Nano1June2019_102X_upgrade2018_realistic_v19-v1/C91570D8-46E6-6A4F-B722-857B9C5FE1F4.root -t Events -m 0 -o my_output.root -d
    GNU gdb (GDB) 7.12
    Copyright (C) 2016 Free Software Foundation, Inc.
    License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
    This is free software: you are free to change and redistribute it.
    There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
    and "show warranty" for details.
    This GDB was configured as "x86_64-pc-linux-gnu".
    Type "show configuration" for configuration details.
    For bug reporting instructions, please see:
    <http://www.gnu.org/software/gdb/bugs/>.
    Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.
    For help, type "help".
    Type "apropos word" to search for commands related to "word"...
    Reading symbols from ./doVVVAnalysis...done.
    (gdb) r
    Starting program: /home/users/phchang/public_html/analysis/vvv/VVVNanoLooper/doVVVAnalysis -i /hadoop/cms/store/group/snt/nanoaod/GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8__RunIIAutumn18NanoAODv5-Nano1June2019_102X_upgrade2018_realistic_v19-v1/C91570D8-46E6-6A4F-B722-857B9C5FE1F4.root -t Events -m 0 -o my_output.root -d
    warning: File "/cvmfs/cms.cern.ch/slc6_amd64_gcc700/external/gcc/7.0.0-njopjo/lib64/libstdc++.so.6.0.23-gdb.py" auto-loading has been declined by your `auto-load safe-path' set to "$debugdir:$datadir/auto-load".
    To enable execution of this file add
            add-auto-load-safe-path /cvmfs/cms.cern.ch/slc6_amd64_gcc700/external/gcc/7.0.0-njopjo/lib64/libstdc++.so.6.0.23-gdb.py
    line to your configuration file "/home/users/phchang/.gdbinit".
    To completely disable this security protection add
            set auto-load safe-path /
    line to your configuration file "/home/users/phchang/.gdbinit".
    For more information about this security protection see the
    "Auto-loading safe path" section in the GDB manual.  E.g., run from the shell:
            info "(gdb)Auto-loading safe path"
    [Thread debugging using libthread_db enabled]
    Using host libthread_db library "/lib64/libthread_db.so.1".
    =========================================================
     Setting of the analysis job based on provided arguments
    ---------------------------------------------------------
     ana.input_file_list_tstring: /hadoop/cms/store/group/snt/nanoaod/GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8__RunIIAutumn18NanoAODv5-Nano1June2019_102X_upgrade2018_realistic_v19-v1/C91570D8-46E6-6A4F-B722-857B9C5FE1F4.root
     ana.output_tfile: debug.root
     ana.n_events: -1
     ana.nsplit_jobs: -1
     ana.job_index: -1
    =========================================================
    >>> Hostname is uaf-10.t2.ucsd.edu
    RooUtil:: Adding /hadoop/cms/store/group/snt/nanoaod/GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8__RunIIAutumn18NanoAODv5-Nano1June2019_102X_upgrade2018_realistic_v19-v1/C91570D8-46E6-6A4F-B722-857B9C5FE1F4.root
    RooUtil:: Start EventLooping
    RooUtil:: System info:
    uaf-10.t2.ucsd.edu
    Linux uaf-10.t2.ucsd.edu 2.6.32-754.3.5.el6.x86_64 #1 SMP Tue Aug 14 20:46:41 UTC 2018 x86_64 x86_64 x86_64 GNU/Linux
    Thu Apr  9 00:09:46 PDT 2020
    phchang
    /home/users/phchang/public_html/analysis/vvv/VVVNanoLooper
    RooUtil::  _
    RooUtil:: /\\
    RooUtil:: \ \\  \__/ \__/
    RooUtil::  \ \\ (oo) (oo)  Here we come!
    RooUtil::   \_\\/~~\_/~~\_
    RooUtil::  _.-~===========~-._
    RooUtil:: (___________________)
    RooUtil::       \_______/
    RooUtil::
    RooUtil::  Your friendly aliens
    RooUtil::      Surf & Turf
    RooUtil::
    Warning in <TClass::Init>: no dictionary for class ROOT::TIOFeatures is available
    RooUtil:: Total Events in this Chain to process = 658000
    RooUtil:: Booked cutflow histogram for cut = 4LepMET_Preselection
    RooUtil:: Booked rawcutflow histogram for cut = 4LepMET_Preselection
    RooUtil:: Cut name                                                                                                                                                                                                                |pass|weight|systs
    RooUtil:: ==================================================================================================================================================================================================================================================================================================================
    RooUtil:: Root                                                                                                                                                                                                                    | 0 | 0.000000|
    RooUtil::   Wgt                                                                                                                                                                                                                   | 0 | 0.000000|
    RooUtil::     VVVCommonCut                                                                                                                                                                                                        | 0 | 0.000000|
    RooUtil::       4LepMET_Preselection                                                                                                                                                                                              | 0 | 0.000000|
    RooUtil:: TTreeCache enabled
    RooUtil:: Looping /hadoop/cms/store/group/snt/nanoaod/GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8__RunIIAutumn18NanoAODv5-Nano1June2019_102X_upgrade2018_realistic_v19-v1/C91570D8-46E6-6A4F-B722-857B9C5FE1F4.root/TTree:Events
    RooUtil:: ERROR - branch hasn't been set yet bn = Common_muon_idxs, exiting.


    Program received signal SIGABRT, Aborted.
    0x00000031c76324f5 in raise () from /lib64/libc.so.6
    (gdb) bt
    #0  0x00000031c76324f5 in raise () from /lib64/libc.so.6
    #1  0x00000031c7633cd5 in abort () from /lib64/libc.so.6
    #2  0x0000000000515751 in RooUtil::error (msg=<incomplete type>, fname=0x3f5765 <error: Cannot access memory at address 0x3f5765>, is_error=6) at rooutil/printutil.cc:50
    #3  0x0000000000521297 in RooUtil::TTreeX::getBranch<std::vector<int, std::allocator<int> > > (this=0x5bc440 <ana+1888>, bn=<incomplete type>, check=6) at rooutil/ttreex.cc:189
    #4  0x0000000000490fcf in <lambda()>::operator() (__closure=<optimized out>) at src/Begin_Common.cc:25
    #5  std::_Function_handler<float(), Begin_Common()::<lambda()> >::_M_invoke(const std::_Any_data &) (__functor=...) at /cvmfs/cms.cern.ch/slc6_amd64_gcc700/external/gcc/7.0.0-njopjo/include/c++/7.1.1/bits/std_function.h:301
    #6  0x000000000054f558 in std::function<float ()>::operator()() const (this=<optimized out>) at /cvmfs/cms.cern.ch/slc6_amd64_gcc700/external/gcc/7.0.0-njopjo/include/c++/7.1.1/bits/std_function.h:706
    #7  RooUtil::CutTree::fillHistograms (this=0x3f5765, syst=<incomplete type>, extrawgt=0) at rooutil/cutflowutil.h:589
    #8  0x000000000054fc7c in RooUtil::CutTree::fillHistograms (this=0x3f5765, syst=<incomplete type>, extrawgt=0) at rooutil/cutflowutil.h:642
    #9  0x000000000054fc7c in RooUtil::CutTree::fillHistograms (this=0x3f5765, syst=<incomplete type>, extrawgt=0) at rooutil/cutflowutil.h:642
    #10 0x000000000052a604 in RooUtil::Cutflow::fillHistograms (this=0x5bbe88 <ana+424>, syst=<incomplete type>, iswgtsyst=6) at rooutil/anautil.cc:612
    #11 0x000000000052c9fb in RooUtil::Cutflow::fill (this=0x5bbe88 <ana+424>) at rooutil/anautil.cc:496
    #12 0x0000000000490769 in Process () at src/Process.cc:31
    #13 0x000000000046951d in main (argc=1, argv=0x7fffffff4f48) at src/main.cc:245
    (gdb) q
    A debugging session is active.

            Inferior 1 [process 4151141] will be killed.

    Quit anyway? (y or n) y



## RooUtil Framework Notes

    //********************************************************************************
    //
    // notes on RooUtil framework
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

