#!/bin/env python

import plottery_wrapper as p
import os

analysis_output="/home/users/kdownham/Triboson/VVVNanoLooper/analysis/output_070623_masterSync"
plot_output_dir="/WWZ/070623_masterSync"

histxaxislabeloptions = {
"DRll"             : {"xaxis_label" : "#DeltaR_{ll}"                           , "xaxis_ndivisions" : 505 , "nbins" : 20} , 
"MET"              : {"xaxis_label" : "MET [GeV]"                              , "xaxis_ndivisions" : 505 , "nbins" : 30} ,
"PFMET"            : {"xaxis_label" : "pf MET [GeV]"                           , "xaxis_ndivisions" : 505 , "nbins" : 20} ,
"PuppiMET"         : {"xaxis_label" : "Puppi MET [GeV]"                        , "xaxis_ndivisions" : 505 , "nbins" : 45} , 
"MT2"              : {"xaxis_label" : "M_{T2} [GeV]"                           , "xaxis_ndivisions" : 505 , "nbins" : 30} ,
"Pt4l"		   : {"xaxis_label" : "p_{T,4l} [GeV]"			       , "xaxis_ndivisions" : 505 , "nbins" : 48} , 
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
"other_mll_full"   : {"xaxis_label" : "W-candidate m_{ll} [GeV]"               , "xaxis_ndivisions" : 505 , "nbins" : 40} , 
"other_mll_varbin" : {"xaxis_label" : "W-candidate m_{ll} [GeV]"               , "xaxis_ndivisions" : 505 , "nbins" : 20} ,
"MT2_PuppiMET"     : {"xaxis_label" : "M_{T2} [GeV]"                           , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"DR_WW_Z"          : {"xaxis_label" : "#Delta R(Wleps,Zleps)"                  , "xaxis_ndivisions" : 505 , "nbins" : 40} , 
"DPhi_WW_MET"      : {"xaxis_label" : "#Delta#phi(WW,p_{T}^{miss})"            , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"DPhi_Z_MET"       : {"xaxis_label" : "#Delta#phi(Z,p_{T}^{miss})"             , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"DPhi_WW_PuppiMET" : {"xaxis_label" : "#Delta#phi(WW,p_{T}^{miss})"            , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"DPhi_Z_PuppiMET"  : {"xaxis_label" : "#Delta#phi(Z,p_{T}^{miss})"             , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"DPhi_WWZ_MET"     : {"xaxis_label" : "#Delta#phi(WWZ,p_{T}^{miss})"           , "xaxis_ndivisions" : 505 , "nbins" : 40} ,
"DPhi_WWZ_PuppiMET": {"xaxis_label" : "#Delta#phi(WWZ,p_{T}^{miss})"           , "xaxis_ndivisions" : 505 , "nbins" : 40} , 
}

def plot(year, filterpattern):

    if year == "Run2": lumi = 137
    if year == "2018": lumi = 59.8
    if year == "2017": lumi = 41.5
    if year == "2016": lumi = 16.8
    if year == "2016APV": lumi = 19.5
    
    p.dump_plot(
            fnames=[
                "{1}/{0}/ZZ.root".format(year, analysis_output),
                "{1}/{0}/TTZ.root".format(year, analysis_output),
                "{1}/{0}/Higgs.root".format(year, analysis_output),
                "{1}/{0}/WZ.root".format(year, analysis_output),
                "{1}/{0}/Other.root".format(year, analysis_output),
		#"output_BDTVars/{0}/WWZ.root".format(year),
		#"output_BDTVars/{0}/DY.root".format(year),
		#"output_BDTVars/{0}/SSWW.root".format(year),
		#"output_BDTVars/{0}/SingleTop.root".format(year),			
		#"output_BDTVars/{0}/TTBar.root".format(year),
		#"output_BDTVars/{0}/TTW.root".format(year),
		#"output_BDTVars/{0}/WLNu.root".format(year),
		#"output_BDTVars/{0}/WWLNu.root".format(year),
                ],
            sig_fnames=[
                #"{1}/{0}/WWZ.root".format(year, analysis_output),
                "{1}/{0}/NonResWWZ.root".format(year, analysis_output),
                "{1}/{0}/ZHWWZ.root".format(year, analysis_output),
                ],
            #data_fname="outputs/{0}/data.root".format(year),
            dirname="../../../public_html/{1}/{0}".format(year, plot_output_dir),
            legend_labels=[
                "ZZ",
                "tbar{t}Z",
                "Higgs",
                "WZ",
                "Other",
		#"WWZ",
		#"Drell-Yan",
		#"Same-sign WW",
		#"Single Top",
		#"t#bar{t}",
		#"t#bar{t}W",
		#"W#rightarrow l#nu",
		#"WW#rightarrow l#nu l#nu",
                ],
            signal_labels=[
                #"WWZ",
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
		880,
		#860,
		#820,
		#800,
		1,
		#632,
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
		#"signal_scale":"auto",
                #"signal_scale":50.,
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
	#"CutOffZ_trgMatch__SRBin", # this is the SF signal region
	#"CutEMuMT2_trgMatch__SRBin", # this is the OF signal region
	#"CutOffZ",
	"CutEMu",
	#"CutOnZ",
	#"CutEMuBT",
	#"CutPresel",
	#"CutEMu__other_mll_full",
	#"CutOffZ__PuppiMET",
	#"CutOffZ__Pt4l",
	#"CutBVeto",
	#"CutEMu_",
	#"CutPresel",
	#"CutOffZ",
	#"CutOnZ",
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

