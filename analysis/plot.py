#!/bin/env python

import plottery_wrapper as p

def plot(year):

    if year == "Run2": lumi = 137
    if year == "2018": lumi = 59.8
    if year == "2017": lumi = 41.5
    if year == "2016": lumi = 16.8
    if year == "2016APV": lumi = 19.5
    
    p.dump_plot(
            fnames=[
                "outputs/{0}/ZZ.root".format(year),
                "outputs/{0}/TTZ.root".format(year),
                "outputs/{0}/Higgs.root".format(year),
                "outputs/{0}/WZ.root".format(year),
                "outputs/{0}/Other.root".format(year),
                "outputs/{0}/NonWWZ.root".format(year),
                "outputs/{0}/WWZ.root".format(year),
                ],
            sig_fnames=[
                "outputs/{0}/WWZ.root".format(year),
                "outputs/{0}/NonResWWZ.root".format(year),
                "outputs/{0}/ZHWWZ.root".format(year),
                ],
            data_fname="outputs/{0}/data.root".format(year),
            dirname="plots/{0}".format(year),
            legend_labels=[
                "ZZ",
                "t#bar{t}Z",
                "Higgs",
                "WZ",
                "Other",
                "NonWWZ",
                "WWZ",
                ],
            signal_labels=[
                "WWZ",
                "NonResWWZ",
                "ZHWWZ",
                ],
            usercolors=[
                4020,
                4305,
                4024,
                7013,
                920,
                2005,
                2,
                ],
            filter_pattern="Yield",
            dogrep=True,
            extraoptions={
                "print_yield": True,
                "lumi_value": lumi,
                "nbins": 40,
                # "yaxis_log": True,
                "ratio_range": [0., 2.],
                # "signal_scale":"auto",
                "legend_scalex": 2.0,
                "legend_ncolumns": 3,
                "yield_prec": 4,
                },
            # _plotter=p.plot_cut_scan,
            )
if __name__ == "__main__":
    plot("Run2")
    plot("2016")
    plot("2016APV")
    plot("2017")
    plot("2018")

