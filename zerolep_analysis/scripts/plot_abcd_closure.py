#!/bin/env python

import plottery_wrapper as p

# Extra options______________________________________________
extraoptions = {
    "nbins"            : 45,
    "autobin"          : False,
    "print_yield"      : True,
    "yield_prec"       : 4,
    "yaxis_log"        : True,
    "legend_scalex"    : 2,
    "legend_ncolumns"  : 1,
    "ratio_range"      : [0., 2.1],
    "xaxis_ndivisions" : 505,
    "legend_datalabel" : "Estimated QCD",
    # "blind"            : True,
    # "divide_by_bin_width": True,
    # "fit_bkg"          : True,
    # "signal_scale"     : "auto",
    # "signal_scale"     : 100,
    }

p.dump_plot(
        filter_pattern = "NFJGeq3ClosePass8__HT_FJSR4,NFJGeq3ClosePass8__HT_FJSR3,NFJGeq3ShellPass8__HT_FJSR3",
        dogrep = False,
        fnames = ["hadds/QCDClosure.root"],
        legend_labels = ["Predicted QCD"],
        data_fname = "hadds/QCD.root",
        usercolors = [7001],
        extraoptions = extraoptions,
        # skip2d=True,
        dirname = "plots/plots_closure",
        # _plotter = p.plot_cut_scan
        )

