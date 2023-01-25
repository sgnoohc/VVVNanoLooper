#!/bin/env python

import plottery_wrapper as p
import sys

# Plotting options___________________________________________
filter_pattern = sys.argv[1] if len(sys.argv) > 1 else ""
blind = bool(int(sys.argv[2])) if len(sys.argv) > 2 else False
dogrep = bool(int(sys.argv[3])) if len(sys.argv) > 3 else False
doylog = bool(int(sys.argv[4])) if len(sys.argv) > 4 else True
doQCD_dd = bool(int(sys.argv[5])) if len(sys.argv) > 5 else True

# Background samples_________________________________________
fnames = [
    "hadds/QCD.root",
    "hadds/ST.root",
    "hadds/TT.root",
    "hadds/TTV.root",
    "hadds/VV.root",
    "hadds/W.root",
    "hadds/Z.root",
    ]
legend_labels = [
    "QCD",
    "ST",
    "TT",
    "TTV",
    "VV",
    "W",
    "Z",
    ]

# Background samples_________________________________________
fnames_dd = [
    "hadds/QCDDD.root",
    "hadds/ST.root",
    "hadds/TT.root",
    "hadds/TTV.root",
    "hadds/VV.root",
    "hadds/W.root",
    "hadds/Z.root",
    ]
legend_labels_dd = [
    "QCD-DD",
    "ST",
    "TT",
    "TTV",
    "VV",
    "W",
    "Z",
    ]

# Signal samples_____________________________________________
sig_fnames_d6 = [
    "hadds/Dim6_WWW.root",
    "hadds/Dim6_WWZ.root",
    "hadds/Dim6_WZZ.root",
    "hadds/Dim6_ZZZ.root",
    ]
signal_labels_d6 = [
    "WWW_D6",
    "WWZ_D6",
    "WZZ_D6",
    "ZZZ_D6",
    ]

# Signal samples_____________________________________________
sig_fnames_d8 = [
    "hadds/WWW.root",
    "hadds/WWZ.root",
    "hadds/WZZ.root",
    "hadds/ZZZ.root",
    "hadds/VVV.root",
    ]
signal_labels_d8 = [
    "WWW_D8",
    "WWZ_D8",
    "WZZ_D8",
    "ZZZ_D8",
    "VVV_D8",
    ]

# Data samples_______________________________________________
data_fname = "hadds/JetHT_2018.root"

# Color settings_____________________________________________
usercolors = [
    7001,
    7002,
    7003,
    7004,
    7005,
    7006,
    7007,
    ]

# Color settings_____________________________________________
usercolors_dd = [
    4003,
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
    # "autobin"          : True,
    "print_yield"      : True,
    "yield_prec"       : 6,
    "yaxis_log"        : doylog,
    "legend_scalex"    : 2,
    "legend_ncolumns"  : 3,
    "ratio_range"      : [0., 2.1],
    "xaxis_ndivisions" : 505,
    "blind"            : blind,
    "lumi_value"       : "59.8",
    # "divide_by_bin_width": True,
    # "fit_bkg"          : True,
    # "signal_scale"     : "auto",
    # "signal_scale"     : 100,
    }

p.dump_plot(
        filter_pattern = filter_pattern,
        dogrep = dogrep,
        fnames = fnames,
        legend_labels = legend_labels,
        sig_fnames = sig_fnames_d8,
        signal_labels = signal_labels_d8,
        data_fname = data_fname,
        usercolors = usercolors,
        extraoptions = extraoptions,
        skip2d=True,
        dirname = "plots/plots_d8_SF" if "NFJEq2Pt1" in filter_pattern else "plots/plots_d8",
        # _plotter = p.plot_cut_scan
        )

extraoptions["yaxis_log"] = False
p.dump_plot(
        filter_pattern = filter_pattern,
        dogrep = dogrep,
        fnames = fnames,
        legend_labels = legend_labels,
        sig_fnames = sig_fnames_d8,
        signal_labels = signal_labels_d8,
        # data_fname = data_fname,
        usercolors = usercolors,
        extraoptions = extraoptions,
        skip2d=True,
        dirname = "plots/plots_d8_cutscan",
        _plotter = p.plot_cut_scan
        )

extraoptions["yaxis_log"] = doylog
p.dump_plot(
        filter_pattern = filter_pattern,
        dogrep = dogrep,
        fnames = fnames_dd,
        legend_labels = legend_labels_dd,
        sig_fnames = sig_fnames_d8,
        signal_labels = signal_labels_d8,
        data_fname = data_fname,
        usercolors = usercolors_dd,
        extraoptions = extraoptions,
        skip2d=True,
        dirname = "plots/plots_d8_datadriven",
        # _plotter = p.plot_cut_scan
        )

# p.dump_plot(
#         filter_pattern = filter_pattern,
#         dogrep = dogrep,
#         fnames = fnames,
#         legend_labels = legend_labels,
#         sig_fnames = sig_fnames_d6,
#         signal_labels = signal_labels_d6,
#         # data_fname = data_fname,
#         usercolors = usercolors,
#         extraoptions = extraoptions,
#         skip2d=True,
#         dirname = "plots_d6",
#         # _plotter = p.plot_cut_scan
#         )

# p.dump_plot(
#         filter_pattern = filter_pattern,
#         dogrep = dogrep,
#         fnames = fnames,
#         legend_labels = legend_labels,
#         sig_fnames = sig_fnames_d6,
#         signal_labels = signal_labels_d6,
#         # data_fname = data_fname,
#         usercolors = usercolors,
#         extraoptions = extraoptions,
#         skip2d=True,
#         dirname = "plots_d6_cutscan",
#         _plotter = p.plot_cut_scan
#         )

# Background samples_________________________________________
fnames = [
    "hadds/Bkg.root",
    "hadds/QCD.root",
    "hadds/NonQCD.root"
    ]
legend_labels = [
    "BKG",
    "QCD",
    "NonQCD",
    ]

# Signal samples_____________________________________________
sig_fnames_d6 = [
    "hadds/Dim6.root",
    ]
signal_labels_d6 = [
    "D6",
    ]

# Signal samples_____________________________________________
sig_fnames_d8 = [
    "hadds/VVV.root",
    ]
signal_labels_d8 = [
    "VVV",
    ]

if "_v_" in filter_pattern:
    if "__" in filter_pattern:
        filter_pattern_2d = filter_pattern.split("__")[0] + "__*_v_*"

    p.dump_plot(
            filter_pattern = filter_pattern_2d,
            dogrep = dogrep,
            fnames = fnames,
            legend_labels = legend_labels,
            sig_fnames = sig_fnames_d6,
            signal_labels = signal_labels_d6,
            # data_fname = data_fname,
            usercolors = usercolors,
            extraoptions = extraoptions,
            dirname = "plots/plots_d6",
            # _plotter = p.plot_cut_scan
            )

    p.dump_plot(
            filter_pattern = filter_pattern_2d,
            dogrep = dogrep,
            fnames = fnames,
            legend_labels = legend_labels,
            sig_fnames = sig_fnames_d8,
            signal_labels = signal_labels_d8,
            data_fname = data_fname,
            usercolors = usercolors,
            extraoptions = extraoptions,
            dirname = "plots/plots_d8",
            # _plotter = p.plot_cut_scan
            )

