#!/bin/env python

import plottery_wrapper as p
import os

histxaxislabeloptions = {
"DRll"             : {"xaxis_label" : "#DeltaR_{ll}"                           , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"MET"              : {"xaxis_label" : "MET [GeV]"                              , "xaxis_ndivisions" : 505 , "nbins" : 30} ,
"PFMET"            : {"xaxis_label" : "pf MET [GeV]"                           , "xaxis_ndivisions" : 505 , "nbins" : 20} ,
"PuppiMET"         : {"xaxis_label" : "Puppi MET [GeV]"                        , "xaxis_ndivisions" : 505 , "nbins" : 45} , 
"Yield"            : {"xaxis_label" : "Yield"                                  , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"Zcand_lep0_pt"    : {"xaxis_label" : "Z-candidate lead lepton p_{T} [GeV]"    , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"Zcand_lep1_pt"    : {"xaxis_label" : "Z-candidate sublead lepton p_{T} [GeV]" , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"Zcand_mll"        : {"xaxis_label" : "Z-candidate m_{ll} [GeV]"               , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"Zcand_mll_full"   : {"xaxis_label" : "Z-candidate m_{ll} [GeV]"               , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"nb"               : {"xaxis_label" : "# of b-tagged jets"                     , "xaxis_ndivisions" : 505 , "nbins" : 20} ,
"ntau"		   : {"xaxis_label" : "# of hadronic taus"                     , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_lep0_dxy"   : {"xaxis_label" : "W-candidate lead lepton d_{xy}"         , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_lep0_dz"    : {"xaxis_label" : "W-candidate lead lepton d_{z}"          , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_lep0_pt"    : {"xaxis_label" : "W-candidate lead lepton p_{T} [GeV]"    , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_lep0_sip3d" : {"xaxis_label" : "W-candidate lead lepton sip3d"          , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"tau0_pt"          : {"xaxis_label" : "#tau_{h} p_{T} [GeV]"                   , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"other_mll"        : {"xaxis_label" : "W-candidate m_{ll} [GeV]"               , "xaxis_ndivisions" : 505 , "nbins" : 40} , 
"other_mll_full"   : {"xaxis_label" : "W-candidate m_{ll} [GeV]"               , "xaxis_ndivisions" : 505 , "nbins" : 40} , 
"other_mll_varbin" : {"xaxis_label" : "W-candidate m_{ll} [GeV]"               , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"MT2"              : {"xaxis_label" : "M_{T2} [GeV]"                           , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"Pt4l"             : {"xaxis_label" : "p_{T}^{4l} [GeV]"                       , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"SRBin_MET"        : {"xaxis_label" : "SRBins (binned in MET)"                 , "xaxis_ndivisions" : 505 , "nbins" : 3}  ,
"SRBin_METandMT2"  : {"xaxis_label" : "SRBins (binned in MET with M_{T2} cut)" , "xaxis_ndivisions" : 505 , "nbins" : 3}  ,
"DR_WW_Z"	   : {"xaxis_label" : "#Delta R(Wcand system, Zcand system)"   , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"DR_ltau"          : {"xaxis_label" : "#Delta R(l,#tau_{h})"                   , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"MT2_PuppiMET"     : {"xaxis_label" : "M_{T2} (w/ PuppiMET) [GeV]"             , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"other_lep0_eta"   : {"xaxis_label" : "W-candidate lead lepton #eta"           , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"other_lep0_phi"   : {"xaxis_label" : "W-candidate lead lepton #phi"           , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"tau0_eta"         : {"xaxis_label" : "#tau_{h} #eta"                          , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"tau0_phi"         : {"xaxis_label" : "#tau_{h} #phi"                          , "xaxis_ndivisions" : 505 , "nbins" : 40} ,  
"DR_WWMET_Z"       : {"xaxis_label" : "#Delta R(Wcand leps + p_{T}^{miss},Z)"  , "xaxis_ndivisions" : 505 , "nbins" : 40} , 
"DR_WWPuppiMET_Z"  : {"xaxis_label" : "#Delta R(Wcand leps + p_{T}^{miss},Z)"  , "xaxis_ndivisions" : 505 , "nbins" : 40} , 
"DR_WW_MET"        : {"xaxis_label" : "#Delta R(Wcand leps, p_{T}^{miss}"      , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"DR_WW_PuppiMET"   : {"xaxis_label" : "#Delta R(Wcand leps, p_{T}^{miss}"      , "xaxis_ndivisions" : 505 , "nbins" : 40} , 
"DR_Z_MET"         : {"xaxis_label" : "#Delta R(Zcand leps, p_{T}^{miss}"      , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"DR_Z_PuppiMET"    : {"xaxis_label" : "#Delta R(Zcand leps, p_{T}^{miss}"      , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
}

def plot(year, filterpattern):

    if year == "Run2": lumi = 137
    if year == "2018": lumi = 59.8
    if year == "2017": lumi = 41.5
    if year == "2016": lumi = 16.8
    if year == "2016APV": lumi = 19.5
    
    p.dump_plot(
            fnames=[
                "output_mVSj_mVSl_highMET/{0}/ZZ.root".format(year),
                "output_mVSj_mVSl_highMET/{0}/TTZ.root".format(year),
                "output_mVSj_mVSl_highMET/{0}/Higgs.root".format(year),
                "output_mVSj_mVSl_highMET/{0}/WZ.root".format(year),
                "output_mVSj_mVSl_highMET/{0}/Other.root".format(year),
		"output_mVSj_mVSl_highMET/{0}/DY.root".format(year),
		#"output_mediumVSemu/{0}/SSWW.root".format(year),
		#"output_mediumVSemu/{0}/SingleTop.root".format(year),			
		#"output_mediumVSemu/{0}/TTBar.root".format(year),
		#"output_mediumVSemu/{0}/TTW.root".format(year),
		#"output_mediumVSemu/{0}/WLNu.root".format(year),
		#"output_mediumVSemu/{0}/WWLNu.root".format(year),
                ],
            sig_fnames=[
                "output_mVSj_mVSl_highMET/{0}/WWZ.root".format(year),
                #"outputs/{0}/NonResWWZ.root".format(year),
                #"outputs/{0}/ZHWWZ.root".format(year),
                ],
            #data_fname="outputs/{0}/data.root".format(year),
            dirname="../../../public_html/WWZ/tau_mVSj_mVSl_highMET/{0}".format(year),
            legend_labels=[
                "ZZ",
                "t#bar{t}Z",
                "Higgs",
                "WZ",
                "Other",
		"Drell-Yan",
		#"Same-sign WW",
		#"Single Top",
		#"t#bar{t}",
		#"t#bar{t}W",
		#"W#rightarrow l#nu",
		#"WW#rightarrow l#nu l#nu",
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
		#880,
		#860,
		#820,
		#800,
		#1,
		#632,
                ],
            filter_pattern=filterpattern,
            dogrep=True,
            extraoptions={
                "print_yield": True,
                "lumi_value": lumi,
                #"nbins": 30,
		"nbins": 90,
                #"yaxis_log": True,
		"yaxis_log": False,
                "ratio_range": [0., 2.],
		#"xaxis_range": [0., 300.],
                #"signal_scale":"auto",
		"signal_scale": 50.,
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
	#"CutETau_idVS__Yield",
	#"CutMuTau_idVS__Yield",
	#"CutBVeto_3LepTau__other_mll",
	#"CutBVeto_3LepTau__Yield",
	#"cutflow",
	#"CutBVeto_3LepTau__",
	#"CutHigh",
	#"CutMed",
	#"CutLow",
	#"CutBVeto_3LepTau__Yield",
	#"CutBVeto_3LepTau__SRBin",
	#"CutHighMETandMT2",
	"CutBVeto_3LepTau",
        ]

    years = [
        #"2016",
        #"2016APV",
        #"2017",
        #"2018",
        "Run2",
        ]

    for year in years:
        for filterpattern in filterpatterns:
            plot(year, filterpattern)

