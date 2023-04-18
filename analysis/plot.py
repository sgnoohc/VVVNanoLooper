#!/bin/env python

import plottery_wrapper as p
import os

histxaxislabeloptions = {
"DRll"             : {"xaxis_label" : "#DeltaR_{ll}"                           , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"MET"              : {"xaxis_label" : "MET [GeV]"                              , "xaxis_ndivisions" : 505 , "nbins" : 30} ,
"PFMET"            : {"xaxis_label" : "pf MET [GeV]"                           , "xaxis_ndivisions" : 505 , "nbins" : 20} ,
"PuppiMET"         : {"xaxis_label" : "Puppi MET [GeV]"                        , "xaxis_ndivisions" : 505 , "nbins" : 45} , 
"MT2"              : {"xaxis_label" : "MT2 [GeV]"                              , "xaxis_ndivisions" : 505 , "nbins" : 30} ,
"Pt4l"		   : {"xaxis_label" : "p_{T,4l}"			       , "xaxis_ndivisions" : 505 , "nbins" : 48} , 
"SRBin"            : {"xaxis_label" : "SR bins"                                , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"STLep"            : {"xaxis_label" : "#Sigmap_{T,lep,MET} [GeV]"              , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"STLepFit"         : {"xaxis_label" : "#Sigmap_{T,lep,MET} [GeV]"              , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"STLepHad"         : {"xaxis_label" : "#Sigmap_{T,lep,MET,jet} [GeV]"          , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"STLepHadFit"      : {"xaxis_label" : "#Sigmap_{T,lep,MET,jet} [GeV]"          , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"Yield"            : {"xaxis_label" : "Yield"                                  , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"Zcand_lep0_pt"    : {"xaxis_label" : "Z-candidate lead lepton p_{T} [GeV]"    , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"Zcand_lep1_pt"    : {"xaxis_label" : "Z-candidate sublead lepton p_{T} [GeV]" , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"Zcand_mll"        : {"xaxis_label" : "Z-candidate m_{ll} [GeV]"               , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"Zcand_mll_full"   : {"xaxis_label" : "Z-candidate m_{ll} [GeV]"               , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"nb"               : {"xaxis_label" : "# of b-tagged jets"                     , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_lep0_dxy"   : {"xaxis_label" : "W-candidate lead lepton d_{xy}"         , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_lep0_dz"    : {"xaxis_label" : "W-candidate lead lepton d_{z}"          , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_lep0_pt"    : {"xaxis_label" : "W-candidate lead lepton p_{T} [GeV]"    , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_lep0_sip3d" : {"xaxis_label" : "W-candidate lead lepton sip3d"          , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_lep1_dxy"   : {"xaxis_label" : "W-candidate sublead lepton d_{xy}"      , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_lep1_dz"    : {"xaxis_label" : "W-candidate sublead lepton d_{z}"       , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_lep1_pt"    : {"xaxis_label" : "W-candidate sublead lepton p_{T} [GeV]" , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_lep1_sip3d" : {"xaxis_label" : "W-candidate sublead lepton sip3d"       , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_lep_diffdz" : {"xaxis_label" : "W-candidate #Delta d_{z,ll}"            , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_mll"        : {"xaxis_label" : "W-candidate m_{ll} [GeV]"               , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_mll_full"   : {"xaxis_label" : "W-candidate m_{ll} [GeV]"               , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_mll_varbin" : {"xaxis_label" : "W-candidate m_{ll} [GeV]"               , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
}

def plot(year, filterpattern):

    if year == "Run2": lumi = 137
    if year == "2018": lumi = 59.8
    if year == "2017": lumi = 41.5
    if year == "2016": lumi = 16.8
    if year == "2016APV": lumi = 19.5
    
    p.dump_plot(
            fnames=[
                "output_newID_jetCounting/{0}/ZZ.root".format(year),
                "output_newID_jetCounting/{0}/TTZ.root".format(year),
                "output_newID_jetCounting/{0}/Higgs.root".format(year),
                "output_newID_jetCounting/{0}/WZ.root".format(year),
                "output_newID_jetCounting/{0}/Other.root".format(year),
                #"output_newID_W_25_15_Z_10/{0}/NonWWZ.root".format(year),
                #"outputs/{0}/WWZ.root".format(year),
                ],
            sig_fnames=[
                "output_newID_jetCounting/{0}/WWZ.root".format(year),
                #"outputs/{0}/NonResWWZ.root".format(year),
                #"outputs/{0}/ZHWWZ.root".format(year),
                ],
            #data_fname="outputs/{0}/data.root".format(year),
            dirname="../../../public_html/WWZ/jet_Counting_v2/{0}".format(year),
            legend_labels=[
                "ZZ",
                "t#bar{t}Z",
                "Higgs",
                "WZ",
                "Other",
                #"NonWWZ",
                #"WWZ",
                ],
            signal_labels=[
                "WWZ",
                #"NonResWWZ",
                #"ZHWWZ",
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
            filter_pattern=filterpattern,
            dogrep=True,
            extraoptions={
                "print_yield": True,
                "lumi_value": lumi,
                #"nbins": 30,
		"nbins": 45,
                #"yaxis_log": True,
		"yaxis_log": False,
                "ratio_range": [0., 2.],
		#"xaxis_range": [0., 300.],
                # "signal_scale":"auto",
                "legend_scalex": 2.0,
                "legend_ncolumns": 3,
                "yield_prec": 4,
                },
            histxaxislabeloptions=histxaxislabeloptions,
            # _plotter=p.plot_cut_scan,
            )

if __name__ == "__main__":

    filterpatterns = [
        #"Yield",
	#"CutOnZ__PuppiMET",
	#"CutOnZ__Pt4l",
	#"CutOnZ__MT2",
	#"CutOnZ__other_mll",
	#"CutOnZ__MT2",
	#"CutEMuMT2__MET",
	#"CutEMuMT2__PuppiMET",
	#"CutOffZ__MET",
	#"CutOffZ__PuppiMET",
	#"CutOffZ__Yield", # this is the SF signal region
	"CutEMuMT2__Yield", # this is the OF signal region
	"CutZeroJetsAll__Yield",
	"Cut1pJetsAll__Yield",
	"CutZeroJetsIn__Yield",
	"Cut1pJetsIn__Yield",
	"CutZeroJetsOut__Yield",
	"Cut1pJetsOut__Yield",
	#"CutOffZ__SRBin",
	#"CutEMuMT2__SRBin",
	#"CutEMuMT2__Min_mlj",
	#"CutOffZ_trgMatch__Yield",
	#"CutEMuMT2_trgMatch__Yield",
	#"CutOffZ_trgMatch__SRBin",
	#"CutEMuMT2_trgMatch__SRBin",
        #"CutZZCR",
        #"CutSFSR",
	#"CutOFSR",
	#"cutflow",
        ]

    years = [
        "2016",
        "2016APV",
        "2017",
        "2018",
        "Run2",
        ]

    for year in years:
        for filterpattern in filterpatterns:
            plot(year, filterpattern)

