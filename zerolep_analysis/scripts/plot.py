#!/bin/env python

import plottery_wrapper as p
import sys

# Plotting options___________________________________________
filter_pattern = sys.argv[1] if len(sys.argv) > 1 else ""
blind = bool(int(sys.argv[2])) if len(sys.argv) > 2 else False
dogrep = bool(int(sys.argv[3])) if len(sys.argv) > 3 else False
doylog = bool(int(sys.argv[4])) if len(sys.argv) > 4 else True
year = sys.argv[5] if len(sys.argv) > 5 else "all"
realyear = "2016" if year == "2006" else year 

# Process Luminosity_________________________________________
if year == "2006": lumi_value = "19.5";
if year == "2016": lumi_value = "16.8";
if year == "2017": lumi_value = "41.4";
if year == "2018": lumi_value = "59.8";
if year == "all" : lumi_value = "138";

# Background samples_________________________________________
fnames = [
    "hadds/{}/QCD.root".format(year),
    "hadds/{}/ST.root".format(year),
    "hadds/{}/TT.root".format(year),
    "hadds/{}/TTV.root".format(year),
    "hadds/{}/VV.root".format(year),
    "hadds/{}/W.root".format(year),
    "hadds/{}/Z.root".format(year),
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
    "hadds/{}/QCDDD.root".format(year),
    "hadds/{}/ST.root".format(year),
    "hadds/{}/TT.root".format(year),
    "hadds/{}/TTV.root".format(year),
    "hadds/{}/VV.root".format(year),
    "hadds/{}/W.root".format(year),
    "hadds/{}/Z.root".format(year),
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

# # Signal samples_____________________________________________
# sig_fnames_d6 = [
#     "hadds/Dim6_WWW.root",
#     "hadds/Dim6_WWZ.root",
#     "hadds/Dim6_WZZ.root",
#     "hadds/Dim6_ZZZ.root",
#     ]
# signal_labels_d6 = [
#     "WWW_D6",
#     "WWZ_D6",
#     "WZZ_D6",
#     "ZZZ_D6",
#     ]

# Signal samples_____________________________________________
sig_fnames_d8 = [
    "hadds/{}/WWW_p0p2.root".format(year),
    "hadds/{}/WWZ_p0p2.root".format(year),
    "hadds/{}/WZZ_p0p2.root".format(year),
    "hadds/{}/ZZZ_p0p2.root".format(year),
    "hadds/{}/VVV_p0p2.root".format(year),
    ]
signal_labels_d8 = [
    "WWW_D8",
    "WWZ_D8",
    "WZZ_D8",
    "ZZZ_D8",
    "VVV_D8",
    ]

# Data samples_______________________________________________
data_fname = "hadds/{}/JetHT.root".format(year)

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
    "ratio_range"      : [0., 2.5],
    "xaxis_ndivisions" : 505,
    "blind"            : blind,
    "lumi_value"       : lumi_value,
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
        dirname = "plots/{}/plots_d8_SF".format(year) if "V1SF" in filter_pattern else "plots/{}/plots_d8".format(year),
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
        dirname = "plots/{}/plots_d8_cutscan".format(year),
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
        dirname = "plots/{}/plots_d8_datadriven".format(year),
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
    "hadds/{}/Bkg.root".format(year),
    "hadds/{}/QCD.root".format(year),
    "hadds/{}/NonQCD.root".format(year)
    ]
legend_labels = [
    "BKG",
    "QCD",
    "NonQCD",
    ]

# # Signal samples_____________________________________________
# sig_fnames_d6 = [
#     "hadds/Dim6.root",
#     ]
# signal_labels_d6 = [
#     "D6",
#     ]

# Signal samples_____________________________________________
sig_fnames_d8 = [
    "hadds/{}/VVV_p0p4.root".format(year),
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
            dirname = "plots/{}/plots_d6".format(year),
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
            dirname = "plots/{}/plots_d8".format(year),
            # _plotter = p.plot_cut_scan
            )

