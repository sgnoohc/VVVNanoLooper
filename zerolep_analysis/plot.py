#!/bin/env python

import plottery_wrapper as p
import sys

p.dump_plot(
        # Histogram name filter______________________________________
        filter_pattern = sys.argv[1] if len(sys.argv) > 1 else "",
        dogrep = True,

        # Background samples_________________________________________
        fnames = [
            "hadds/QCD.root",
            "hadds/ST.root",
            "hadds/TT.root",
            "hadds/TTV.root",
            "hadds/VV.root",
            "hadds/W.root",
            "hadds/Z.root",
            ],
        legend_labels = [
            "QCD",
            "ST",
            "TT",
            "TTV",
            "VV",
            "W",
            "Z",
            ],

        # Signal samples_____________________________________________
        sig_fnames = [
            # "hadds/WWW_Dim6.root",
            # "hadds/WWZ_Dim6.root",
            # "hadds/WZZ_Dim6.root",
            # "hadds/ZZZ_Dim6.root",
            "hadds/WWW.root",
            "hadds/WWZ.root",
            "hadds/WZZ.root",
            "hadds/ZZZ.root",
            ],
        signal_labels = [
            # "WWW_D6",
            # "WWZ_D6",
            # "WZZ_D6",
            # "ZZZ_D6",
            "WWW_D8",
            "WWZ_D8",
            "WZZ_D8",
            "ZZZ_D8",
            ],

        # Data samples_______________________________________________
        data_fname = "hadds/JetHT_2018.root",

        # Color settings_____________________________________________
        usercolors = [
            7001,
            7002,
            7003,
            7004,
            7005,
            7006,
            7007,
            ],

        # Extra options______________________________________________
        extraoptions = {
            "nbins"            : 45,
            "autobin"          : False,
            "print_yield"      : True,
            "yield_prec"       : 6,
            # "yaxis_log"        : False,
            "yaxis_log"        : True,
            "legend_scalex"    : 2,
            "legend_ncolumns"  : 3,
            "ratio_range"      : [0., 2.1],
            "xaxis_ndivisions" : 505,
            # "signal_scale"     : "auto",
            },
        # _plotter = p.plot_cut_scan
        )

