#!/bin/env python

# option parser
import argparse
import sys
import plottery_wrapper as p
import os
import glob
import style
import fnmatch

looper_base_dir_path = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.append("{}/condor/".format(looper_base_dir_path))
import samples

def main(args):

    print ("")
    print ("     -----------")
    print ("       Plotter  ")
    print ("     -----------")
    print ("")

    yearstring = ""
    if args.year == 0:
        yearstring = "combined"
    elif args.year >= 2016 and args.year <= 2018:
        yearstring = str(args.year)
    elif args.year == 2006:
        yearstring = str(args.year)
    elif args.year == -1:
        yearstring = "" #for backwards compatibility
    else:
        print("The year you selected ("+str(args.year)+") does not exist.")
        return
   
    #years = ["2006","2016","2017","2018"]
    # Constructing input directory name
    username = os.environ['USER']
    #input_dir = "/nfs-7/userdata/{}/tupler_babies/merged/VVV/{}/output/".format(username, args.tag)
    #input_dir = "/nfs-7/userdata/{}/tupler_babies/merged/VVV/{}/output/{}/".format(username, args.tag,yearstring)
    input_dir = "/nfs-7/userdata/lhoryn/tupler_babies/merged/VVV/040821_HT/output/2018/"
    input_dir = args.inputDir

    # Printing input directory name
    print(">>>  Input directory: {}".format(input_dir))

    # Get list of files
    list_of_root_files = glob.glob("{}/*.root".format(input_dir))
    list_of_root_files.sort() # Sort the files

    # Printing list of input histogram files
    print(">>>")
    print(">>>  List of files in the input directory")
    print(">>>    {}".format(input_dir))
    for root_file in list_of_root_files:
        print(">>>      {}".format(os.path.basename(root_file)))

    # Histogram grouping
    # Default grouping setting is shown below and each different grouping option will group them differently
    # The grouping will be defined in python/grouping.py
    grouping_setting = {
            "DY_high.root"           : "DY",
            "DY_low.root"            : "DY",
            "DYzpt150.root"          : "NOTUSED",
            "GGHtoZZto4L.root"       : "HZZ",
            "HHAT_0p0.root"          : "NOTUSED",
            "HHAT_0p08.root"         : "NOTUSED",
            "HHAT_0p12.root"         : "NOTUSED",
            "HHAT_0p16.root"         : "NOTUSED",
            "QQWW.root"              : "WW",
            "STantitop.root"         : "ST",
            "STtop.root"             : "ST",
            "TGext.root"             : "NOTUSED",
            "TTBAR_PH.root"          : "TT",
            "TTDL.root"              : "TT",
            "TTGdilep.root"          : "NOTUSED",
            "TTGsinglelep.root"      : "NOTUSED",
            "TTGsinglelepbar.root"   : "NOTUSED",
            "TTHH.root"              : "TTHH",
            "TTSL.root"              : "TT",
            "TTSLtop.root"           : "NOTUSED",
            "TTSLtopbar.root"        : "NOTUSED",
            "TTTJ.root"              : "RareTop",
            "TTTTnew.root"           : "TTTT",
            "TTTW.root"              : "RareTop",
            "TTWH.root"              : "RareTop",
            "TTWW.root"              : "RareTop",
            "TTWZ.root"              : "RareTop",
            "TTWnlo.root"            : "TTW",
            "TTZH.root"              : "RareTop",
            "TTZLOW.root"            : "TTZ",
            "TTZZ.root"              : "RareTop",
            "TTZnlo.root"            : "TTZ",
            "TTdilep0jet.root"       : "NOTUSED",
            "TTdilep1jet.root"       : "NOTUSED",
            "TZQ.root"               : "RareTop",
            "VHtoNonBB.root"         : "VH",
            "W2Jets.root"            : "NOTUSED",
            "W4Jets.root"            : "NOTUSED",
            "WGToLNuGext.root"       : "NOTUSED",
            "WJets.root"             : "W",
            "WJets_HT100To200.root"  : "NOTUSED",
            "WJets_HT200To400.root"  : "NOTUSED", # HT gen level variable not implemented
            "WJets_HT400To600.root"  : "NOTUSED", # HT gen level variable not implemented
            "WJets_HT600To800.root"  : "NOTUSED", # HT gen level variable not implemented
            "WJets_HT800To1200.root" : "NOTUSED", # HT gen level variable not implemented
            "WW.root"                : "WW",
            "WWDPS.root"             : "WW",
            "WWG.root"               : "NOTUSED",
            "WWW.root"               : "WWW",
            "WWZ.root"               : "WWZ",
            "WZ.root"                : "WZ",
            "WZG.root"               : "NOTUSED",
            "WZZ.root"               : "WZZ",
            "ZG.root"                : "NOTUSED",
            "ZZ.root"                : "ZZ",
            "ZZZ.root"               : "ZZZ",
            "ZZcontTo2e2mu.root"     : "ZZ",
            "ZZcontTo2e2tau.root"    : "ZZ",
            "ZZcontTo2mu2tau.root"   : "ZZ",
            "ZZcontTo4mu.root"       : "ZZ",
            "ZZcontTo4tau.root"      : "ZZ",
            }

    # If user wants to use different grouping use the following hooks
    if args.style == 0: grouping_setting = style.grouping_4LepMET
    if args.style == 1: grouping_setting = style.grouping_3LepMET
    if args.style == 5: grouping_setting = style.grouping_OS2jet
    if args.style == 7: grouping_setting = style.grouping_1Lep4jet
    if args.style == 8: grouping_setting = style.grouping_allHad

    # Now loop over files to check the grouping and print a warning that it is skipping some stuff
    root_file_groups = {}

    # Looping over the files found in the input_dir
    for f in list_of_root_files:

        f_basename = os.path.basename(f)
        #add here check for data
        if f_basename not in grouping_setting.keys():
            print("")
            print(">>>  Warning::  {} was not defined in the group setting!! {} is pushed to NOTUSED category.".format(f, f))
            group_name = "NOTUSED"
        else:
            # Get the group name
            group_name = grouping_setting[f_basename]

        # if the group name list is not created yet create one
        if group_name not in root_file_groups:
            root_file_groups[group_name] = []

        # Now push the
        root_file_groups[group_name].append(f)

    # Print warning on skipped files
    print("")
    print(">>>  Warning:: following histogram files are skipped. Make sure this is OK.")
    if "NOTUSED" in root_file_groups:
        for f in root_file_groups["NOTUSED"]:
            print(">>>      {}".format(os.path.basename(f)))

    # Print grouping information
    print("")
    print(">>>  Following is how the histograms are grouped.")
    print(">>>")
    print(">>>      Group : Sample1, Sample2, Sample3, ...")
    print(">>>      --------------------------------------")
    for group in sorted(root_file_groups.keys()):
        if "NOTUSED" in group:
            continue
        print(">>>      {} : {}".format(group, ", ".join([ os.path.basename(f).replace(".root", "") for f in root_file_groups[group]])))

    # Setting plotting styles

    # Plotting order
    bkg_plot_order = [ "DY", "HZZ", "RareTop", "ST", "TT", "TTHH", "TTTT", "TTW", "TTZ", "W", "WW", "WZ", "ZZ", ]
    sig_plot_order = [ "WWW", "WWZ", "WZZ", "ZZZ", "VH", ]
    legend_labels = [] # Default option don't care
    sig_labels = [] # Default option don't care
    colors = [] # Default option don't care

    # over write styles
    if args.style == 0: # 4LepMET style
        bkg_plot_order = style.bkg_plot_order_4LepMET
        sig_plot_order = style.sig_plot_order_4LepMET
        legend_labels = style.legend_labels_4LepMET
        sig_labels = style.sig_labels_4LepMET
        colors = style.colors_4LepMET
    if args.style == 1: # 3LepMET style
        bkg_plot_order = style.bkg_plot_order_3LepMET
        sig_plot_order = style.sig_plot_order_3LepMET
        legend_labels = style.legend_labels_3LepMET
        sig_labels = style.sig_labels_3LepMET
        colors = style.colors_3LepMET
    if args.style == 5: # OS+jets style
        bkg_plot_order = style.bkg_plot_order_OS2jet
        sig_plot_order = style.sig_plot_order_OS2jet
        legend_labels = style.legend_labels_OS2jet
        sig_labels = style.sig_labels_OS2jet
        colors = style.colors_OS2jet
    if args.style == 7: # 1Lep4jet style
        bkg_plot_order = style.bkg_plot_order_1Lep4jet
        sig_plot_order = style.sig_plot_order_1Lep4jet
        legend_labels = style.legend_labels_1Lep4jet
        sig_labels = style.sig_labels_1Lep4jet
        colors = style.colors_1Lep4jet
    if args.style == 8: # allHad style
        bkg_plot_order = style.bkg_plot_order_allHad
        sig_plot_order = style.sig_plot_order_allHad
        legend_labels = style.legend_labels_allHad
        sig_labels = style.sig_labels_allHad
        colors = style.colors_allHad

    # Print the options set
    print("")
    print(">>>  ===== Summary of plotting options =====")
    print(">>>  Bkg plot order : {} ".format(", ".join(bkg_plot_order)))
    print(">>>  Bkg legend     : {} ".format(", ".join(legend_labels)))
    print(">>>  Bkg colors     : {} ".format(", ".join([str(c) for c in colors])))
    print(">>>  Sig plot order : {} ".format(", ".join(sig_plot_order)))
    print(">>>  Sig legend     : {} ".format(", ".join(sig_labels)))
    print("")

    #-------------------------------------------------------
    #
    # Now accessing TFiles and THists and plotting...
    #
    #-------------------------------------------------------

    import ROOT as r

    # Open all TFiles
    tfiles_by_group = {}
    
    for group in sorted(root_file_groups.keys()):

        # If NOTUSED skip the group
        if "NOTUSED" in group:
            continue

        # Create a list that holds tfiles for the group
        tfiles_by_group[group] = []

        # Now open and push it to tfiles_by_group
        for f in root_file_groups[group]:
            tfiles_by_group[group].append(r.TFile(f))
    
    print tfiles_by_group
    # Open last group's first TFile (assuming same histograms exist on every file) and obtain list of histogram names
    hist_names = []
    for key in tfiles_by_group[group][0].GetListOfKeys():
        if "TH" in tfiles_by_group[group][0].Get(key.GetName()).ClassName(): # this is a histogram file
            hist_names.append(key.GetName())
    
    hist_names_to_plot = []
    for hist_name in hist_names:
        if (args.histname == "all") or args.histname in hist_name :
            if "_v_" not in hist_name:
                hist_names_to_plot.append(hist_name)
        
    # Loop over the histograms to plot
    for hist_name in hist_names_to_plot:

        # Open all hists
        thists_by_group = {}
        for group in sorted(tfiles_by_group.keys()):

            # If NOTUSED skip the group
            if "NOTUSED" in group:
                continue

            # Create a list that holds histograms for the group
            thists_by_group[group] = []

            # Loop over the tfiles
            for f in tfiles_by_group[group]:
                print f.GetName(), group

                # Retrieve the histogram after scaling it appropriately according to its cross section and lumi of the year
                if "Data" in group:
                     thists_by_group[group].append(get_raw_histogram(f, hist_name))
                else:
                    isEFT = False
                    if group in sig_plot_order: isEFT = True
                    thists_by_group[group].append(get_xsec_lumi_scaled_histogram(f, hist_name, isEFT))
                    #thists_by_group[group].append(get_raw_histogram(f, hist_name))

        # Now create a list of histogram one per each grouping
        hists = {}
        for group in sorted(thists_by_group.keys()):

            # If NOTUSED skip the group
            if "NOTUSED" in group:
                continue

            # Loop over the thists
            for h in thists_by_group[group]:

                # If the group key does not exist in the mapping, it means a histogram for it hasn't be created yet
                if group not in hists:
                    print "ADDING FIRST", h.GetName(), group, h.Integral()
                    hists[group] = h.Clone(group)
                # If it exists, then there is a base histogram, we add to it
                else:
                    print "ADDING", h.GetName(), group, h.Integral()
                    hists[group].Add(h)

                #if "Data" in group:
                    #if args.year==2016 and group != "Data_2016": continue
                    #if args.year==2017 and group != "Data_2017": continue
                    #if args.year==2018 and group != "Data_2018": continue
                    #if "Data" not in hists:
                    #    hists["Data"] = h.Clone("Data")
                    #else: hists["Data"].Add(h)

        for group in sorted(hists.keys()):
            print group, hists[group].Integral()


        # # Printing histograms we have
        # for group in hists:
        #     hists[group].Print("all")

        #--------------------------
        #
        # Now actual plotting
        #
        #-------------get_xsec-------------
        xminimum = args.xMin if args.xMin!=-999 else hists[bkg_plot_order[0] ].GetXaxis().GetBinLowEdge(1)
        xmaximum = args.xMax if args.xMax!=-999 else hists[bkg_plot_order[0] ].GetXaxis().GetBinLowEdge(hists[bkg_plot_order[0] ].GetNbinsX()+1)
        x_range = [] if (args.xMin==-999 and args.xMax==-999) else [xminimum,xmaximum]
        p.plot_hist(
                bgs = [ hists[group].Clone() for group in bkg_plot_order ],
                sigs = [ hists[group].Clone() for group in sig_plot_order ],
                #data  = [ hists[group].Clone() for group in sig_plot_order ][0],
                data = hists["Data"] if args.data else None,
                colors = colors,
                legend_labels = legend_labels,
                sig_labels = sig_labels,
                options={
                    "yaxis_log":args.yaxis_log,
                    "nbins":args.nbins,
                    "output_name": "plots/{}/{}/{}.pdf".format(args.tag,yearstring,hist_name),#"output_name": "plots/{}/{}.pdf".format(args.tag,hist_name),
                    "lumi_value": "{:.1f}".format(get_lumi(args)),
                    "print_yield": True,
                    "legend_ncolumns": 3,
                    "legend_scalex": 2,
                    "xaxis_range" : x_range,
                    "remove_underflow":True,
                    "yield_prec": 10,
                    "bkg_sort_method":"unsorted",
                    #"ratio_signal":  False if args.data else True,
                    "xaxis_label" : args.label if args.label else hist_name,
                    "signal_scale": 1.0,
                    #"variable_rebin": [0, 1.5, 1.6, 1.7, 1.8, 1.9, 2.0, 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 3.1, 3.2]
                    #"variable_rebin": [0,1100, 2000, 3500, 4000]
                     #"variable_rebin": [0,1500, 2000, 3000, 5000, 14000]
                    #"variable_rebin": [0, 100,200,300, 400,500, 600,700, 800, 900, 1000, ]
                    #"variable_rebin": [0, 40,65,105, 150,200 ]
                    #"variable_rebin": [0, 1,10 ]
                    },
                )
        '''
        p.plot_cut_scan(
                bgs = [ hists[group].Clone() for group in bkg_plot_order ],
                sigs = [ hists[group].Clone() for group in sig_plot_order ],
                options={
                    "yaxis_log":args.yaxis_log,
                    "nbins":args.nbins,
                    "output_name": "plots/{}/{}/{}.pdf".format(args.tag,yearstring,hist_name),#"output_name": "plots/{}/{}.pdf".format(args.tag,hist_name),
                    "lumi_value": "{:.1f}".format(get_lumi(args)),
                    "print_yield": True,
                    "legend_ncolumns": 3,
                    "legend_scalex": 2,
                    "xaxis_range" : x_range,
                    "remove_underflow":False,
                    "bkg_sort_method":"unsorted",
                    "xaxis_label" : hist_name,
                    #"yaxis_range" : [10**-1, 10],
                    "remove_underflow" : True,
                    "signal_scale": 1.0,
                    },
                )
        '''

def get_xsec_lumi_scaled_histogram(tfile, name, isEFT):
    print tfile.GetName(), isEFT
    n_eff_events = get_n_eff_events(tfile)
    print "got events ", n_eff_events
    if isEFT: #divide by number of SM events
        sm_idx = 1
        n_eff_events = tfile.Get("Root__h_Common_LHEWeight_mg_reweighting_times_genWeight").GetBinContent(sm_idx)
    xsec = get_xsec(args, tfile)
    lumi = get_lumi(args)
    
    scale1fb = xsec * 1000. * lumi / n_eff_events

    print " now plotting ", name 
    h = tfile.Get(name).Clone("{}_{}".format(tfile.GetName(), name))
    #h = tfile.Get(name).Clone()
    #h.SetDirectory(0)
    h.Scale(scale1fb)
    return h


def get_raw_histogram(tfile, name):
    # The Wgt__h_nevents holds the information about the total number of events processed for this sample
    # The Wgt__h_nevents will hold (total # of positive weight events) - (total # of neg weight events)
    print "RAW getting ", tfile.GetName()
    h = tfile.Get(name).Clone("{}_{}".format(tfile.GetName(), name))
    print "integral", h.Integral()
    return h

def get_n_eff_events(tfile):
    return tfile.Get("Wgt__h_nevents").GetBinContent(1)

def get_xsec(args, tfile):
    sample_short_name = os.path.basename(tfile.GetName()).replace(".root","")
    print
    print sample_short_name
    f = open("scale1fbs_nanoaod.txt")
    for line in f.readlines():
        if line == "": continue
        if "#" in line: continue
        if sample_short_name == line.split()[0]:
        #if sample_short_name in line.split()[0]:
            print line.split()[0], float(line.split()[1])
            if "WJets" in sample_short_name: 
                print "scaling wjets" 
                return float(line.split()[1])*1.0
                #return float(line.split()[1])*1.0
            else: return float(line.split()[1])

    sys.exit("ERROR - The specific sample was not found from NanoTools/NanoCORE/scale1fbs_nanoaod.txt. {} not found.".format(sample_short_name))


def get_lumi(args):
    if args.year == 2006: #2016 APV (comes first)
        print "year is 2006!"
        return 19.52
    elif args.year == 2016: #2016 non-APV
        return 16.81
    elif args.year == 2017:
        #return 41.3
        return 41.48
    elif args.year == 2018:
        #return 59.7
        return 59.83
    elif args.year == 0:
        #return 137.
        return 137.64
    else:
        sys.exit("ERROR - Year is not recognized. You said the year is {}".format(args.year))

if __name__ == "__main__":

    # Define options
    parser = argparse.ArgumentParser(description="Plotter for VVV analysis")
    parser.add_argument('-t' , '--tag'      , dest='tag'      , help='tag of the job submitted to condor'   , required=True)
    parser.add_argument('-s' , '--scale'    , dest='scale'    , help='signal scale'  ,type=float, default=1., required=False)
    parser.add_argument('-b' , '--nbins'    , dest='nbins'    , help='number of bins',type=int,   default=30, required=False)
    parser.add_argument('-g' , '--style'    , dest='style'    , help='Style option to specify MC grouping/color/etc (-1 = default, 0 = 4LepMET grouping, 1 = ... TODO)', type=int, default=-1)
    parser.add_argument('-y' , '--year'     , dest='year'     , help='data year', type=int, required=True)
    parser.add_argument('-d' , '--data'     , dest='data'     , help='plot data',           default=False, action='store_true')
    parser.add_argument('-n' , '--histname' , dest='histname' , help='name of the histogram OR type "all" to plot everything', required=True)
    parser.add_argument('-l' , '--yaxis_log', dest='yaxis_log', help='Y-axis set to log' ,  default=False, action='store_true') 
    parser.add_argument('-xn', '--xMin'     , dest='xMin'     , help='X-axis range setting' , type=float,  default=-999., required=False) 
    parser.add_argument('-xx', '--xMax'     , dest='xMax'     , help='X-axis range setting' , type=float,  default=-999., required=False) 
    parser.add_argument('-i',  '--inDir'     , dest='inputDir'     , help='input director' ,   required=True) 
    parser.add_argument('-la', '--label'     , dest='label'     , help='x axis label' ,   required=False) 
    # Argument parser
    args = parser.parse_args()
    args.tag

    # Main
    main(args)
