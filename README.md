# VVVNanoLooper

## Quick start


Below command will create ```debug.root``` output from the loop

     ./doAnalysis --input /hadoop/cms/store/group/snt/nanoaod/GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8__RunIIAutumn18NanoAODv5-Nano1June2019_102X_upgrade2018_realistic_v19-v1/C91570D8-46E6-6A4F-B722-857B9C5FE1F4.root \
        --tree Events \
        --mode 0 \
        --debug


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

