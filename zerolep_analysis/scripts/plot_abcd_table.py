#!/bin/env python

import plottery_wrapper as p
import sys

# Plotting options___________________________________________
doQCD_dd = True
doylog = True

# Histogram name filter______________________________________
filter_pattern = sys.argv[1] if len(sys.argv) > 1 else ""
dogrep = True

# Background samples_________________________________________
fnames = [
    "hadds/NonQCD.root",
    "hadds/QCD.root",
    ]
legend_labels = [
    "NonQCD",
    "QCD",
    ]

# Data samples_______________________________________________
data_fname = "hadds/JetHT_2018.root"

# Signal samples_____________________________________________
sig_fnames = ["hadds/VVV.root"]
signal_labels = ["VVV D8"]

# Color settings_____________________________________________
usercolors = [
    4003 if doQCD_dd else 7001,
    7002,
    7003,
    7004,
    7005,
    7006,
    7007,
    ]

# Extra options______________________________________________
extraoptions = {
    "nbins"            : 60,
    "autobin"          : False,
    "print_yield"      : True,
    "yield_prec"       : 6,
    "yaxis_log"        : doylog,
    "legend_scalex"    : 2,
    "legend_ncolumns"  : 3,
    "ratio_range"      : [0., 2.1],
    "xaxis_ndivisions" : 505,
    "blind"            : True,
    # "divide_by_bin_width": True,
    # "fit_bkg"          : True,
    # "signal_scale"     : "auto",
    # "signal_scale"     : 100,
    }

p.dump_plot(
        filter_pattern = "NFJGeq3ClosePass8__HT_FJSR3",
        dogrep = dogrep,
        fnames = fnames,
        legend_labels = legend_labels,
        sig_fnames = sig_fnames,
        signal_labels = signal_labels,
        data_fname = data_fname,
        usercolors = usercolors,
        extraoptions = extraoptions,
        skip2d=True,
        dirname = "plots_closure",
        )

extraoptions["blind"] = False

p.dump_plot(
        filter_pattern = "NFJGeq3ShellPass8__HT_FJSR3,NFJGeq3ShellFail8__HT_FJSR3,NFJGeq3OpenPass8__HT_FJSR3,NFJGeq3CloseFail8__HT_FJSR3,NFJGeq3OpenFail8__HT_FJSR3,NFJGeq3CloseNotPass8__HT_FJSR3,NFJGeq3OpenNotPass8__HT_FJSR3",
        dogrep = dogrep,
        fnames = fnames,
        legend_labels = legend_labels,
        sig_fnames = sig_fnames,
        signal_labels = signal_labels,
        data_fname = data_fname,
        usercolors = usercolors,
        extraoptions = extraoptions,
        skip2d=True,
        dirname = "plots_closure",
        )

