#!/bin/env python

import sys
import plottery_wrapper as p

year = sys.argv[1] if len(sys.argv) > 1 else "all"
realyear = "2016" if year == "2006" else year 

# Process Luminosity_________________________________________
if year == "2006": lumi_value = "19.5";
if year == "2016": lumi_value = "16.8";
if year == "2017": lumi_value = "41.4";
if year == "2018": lumi_value = "59.8";
if year == "all" : lumi_value = "138";


# Extra options______________________________________________
extraoptions = {
    "nbins"            : 45,
    "autobin"          : False,
    "print_yield"      : True,
    "yield_prec"       : 4,
    "yaxis_log"        : True,
    "legend_scalex"    : 2,
    "legend_ncolumns"  : 1,
    "ratio_range"      : [0., 5.5],
    "xaxis_ndivisions" : 505,
    "legend_datalabel" : "Estimated QCD",
    "lumi_value"       : lumi_value,
    # "blind"            : True,
    # "divide_by_bin_width": True,
    # "fit_bkg"          : True,
    # "signal_scale"     : "auto",
    # "signal_scale"     : 100,
    }

p.dump_plot(
        filter_pattern = "NFJGeq3ClosePassWP__HT_FJSR4,NFJGeq3ClosePassWP__HT_FJSR3,NFJGeq3ShellPassWP__HT_FJSR3",
        dogrep = False,
        fnames = ["hadds/{}/QCDClosure.root".format(year)],
        legend_labels = ["Predicted QCD"],
        data_fname = "hadds/{}/QCD.root".format(year),
        usercolors = [7001],
        extraoptions = extraoptions,
        # skip2d=True,
        dirname = "plots/{}/plots_closure".format(year),
        # _plotter = p.plot_cut_scan
        )

