#!/bin/env python


#~~~~~~~~~~~~~~~~
# allHad styles
#~~~~~~~~~~~~~~~~

grouping_allHad = {
    #"QCD_HT200to300.root"            : "QCD",
    "QCD_HT300to500.root"            : "QCD",
    "QCD_HT500to700.root"            : "QCD",
    "QCD_HT700to1000.root"            : "QCD",
    "QCD_HT1000to1500.root"           : "QCD",
    "QCD_HT1500to2000.root"           : "QCD",
    "QCD_HT2000toInf.root"            : "QCD",
    "WJetsToQQ_HT800toInf.root"       : "W+jets",
    "WJetstoLNu_HT100to200.root"       : "W+jets",
    "WJetstoLNu_HT200to400.root"       : "W+jets",
    "WJetstoLNu_HT400to600.root"       : "W+jets",
    "WJetstoLNu_HT600to800.root"       : "W+jets",
    "WJetstoLNu_HT800to1200.root"       : "W+jets",
    "WJetstoLNu_HT1200to2500.root"       : "W+jets",
    "WJetstoLNu_HT2500toInf.root"       : "W+jets",
    "ZJetsToQQ_HT800toInf.root"       : "Z+jets",
    
    "TTSL.root"                       : "ttbar",
    "TTHad.root"                      : "ttbar",
    "TTWToQQ.root"                    : "ttbar",
    "TTZToQQ.root"                    : "ttbar",
    "TTWJetsToLNu.root"                    : "ttbar",
    #"TTTo2L2Nu.root"                    : "ttbar",
    #"TTZToLLNuNu.root"                    : "ttbar",
    
    "STantitop_inclusive.root"        : "single top",
    "ST_antitop_inclusive.root"        : "single top",
    "STtop_inclusive.root"            : "single top",
    "ST_top_inclusive.root"            : "single top",
    "ST_tchannel_top.root"            : "single top",
    "ST_tchannel_antitop.root"        : "single top",
    "ST_schannel.root"                : "single top",
    "ST_schannel_antitop.root"                : "single top",
    "ST_tW_top.root"                : "single top",
    "ST_tW_antitop.root"                : "single top",
#    "WW.root"                         : "diboson",
 #   "ZZ.root"                         : "diboson",
    "WWTo4Q.root"                         : "diboson",
    "ZZTo4Q.root"                         : "diboson",
    "WZ.root"                         : "diboson",
#    "WplusH_HtoBB_WtoQQ.root"         : "diboson",
#    "WminusH_HtoBB_WtoQQ.root"        : "diboson",
#    "ZH_HtoBB_ZtoQQ.root"             : "diboson",
    


    "WWW_EFT__FT0_p2.root"           : "VVV FT0_p2",
    "WWZ_EFT__FT0_p2.root"           : "VVV FT0_p2",
    "WZZ_EFT__FT0_p2.root"           : "VVV FT0_p2",
    "ZZZ_EFT__FT0_p2.root"           : "VVV FT0_p2",
    
    
    "WWW_EFT__FM0_p2.root"           : "VVV FM0_p2",
    "WWZ_EFT__FM0_p2.root"           : "VVV FM0_p2",
    "WZZ_EFT__FM0_p2.root"           : "VVV FM0_p2",
    "ZZZ_EFT__FM0_p2.root"           : "VVV FM0_p2",
    
    "WWW_EFT__FS0_p2.root"           : "VVV FS0_p2",
    "WWZ_EFT__FS0_p2.root"           : "VVV FS0_p2",
    "WZZ_EFT__FS0_p2.root"           : "VVV FS0_p2",
    "ZZZ_EFT__FS0_p2.root"           : "VVV FS0_p2",
    
    "WWW_EFT__FT0_p15.root"           : "VVV FT0_p15",
    "WWZ_EFT__FT0_p15.root"           : "VVV FT0_p15",
    "WZZ_EFT__FT0_p15.root"           : "VVV FT0_p15",
    "ZZZ_EFT__FT0_p15.root"           : "VVV FT0_p15",
    
    "WWW_EFT__FM0_p2.root"           : "WWW FM0_p2",
    "WWW_EFT__FT0_p2.root"           : "WWW FT0_p2",
    "WWW_EFT__FT0_p15.root"           : "WWW FT0_p15",
    "WWW_EFT__FS0_p2.root"           : "WWW FS0_p2",
    "WWZ_EFT__FM0_p2.root"           : "WWZ FM0_p2",
    "WWZ_EFT__FT0_p2.root"           : "WWZ FT0_p2",
    "WWZ_EFT__FS0_p2.root"           : "WWZ FS0_p2",
    "WWZ_EFT__FT0_p15.root"           : "WWZ FT0_p15",
    "WZZ_EFT__FM0_p2.root"           : "WZZ FM0_p2",
    "WZZ_EFT__FT0_p2.root"           : "WZZ FT0_p2",
    "WZZ_EFT__FT0_p15.root"           : "WZZ FT0_p15",
    "WZZ_EFT__FS0_p2.root"           : "WZZ FS0_p2",
    "ZZZ_EFT__FM0_p2.root"           : "ZZZ FM0_p2",
    "ZZZ_EFT__FT0_p2.root"           : "ZZZ FT0_p2",
    "ZZZ_EFT__FT0_p15.root"           : "ZZZ FT0_p15",
    "ZZZ_EFT__FS0_p2.root"           : "ZZZ FS0_p2",
    
    "JetHT_2018A.root"               : "Data",
    "JetHT_2018B.root"               : "Data",
    "JetHT_2018C.root"               : "Data",
    "JetHT_2018D.root"               : "Data",
    
    "JetHT_2016F.root"               : "Data",
    "JetHT_2016G.root"               : "Data",
    "JetHT_2016H.root"               : "Data",
    
    "JetHT_2016B_ver1.root"               : "Data",
    "JetHT_2016B_ver2.root"               : "Data",
    "JetHT_2016C.root"               : "Data",
    "JetHT_2016D.root"               : "Data",
    "JetHT_2016E.root"               : "Data",
    "JetHT_2016F_HIPM.root"               : "Data",
    
    "JetHT_2017B.root"               : "Data",
    "JetHT_2017C.root"               : "Data",
    "JetHT_2017D.root"               : "Data",
    "JetHT_2017E.root"               : "Data",
    "JetHT_2017F.root"               : "Data",
    
}

'''

"EGamma_2018A.root"               : "Data",
"EGamma_2018B.root"               : "Data",
"EGamma_2018C.root"               : "Data",
"EGamma_2018D.root"               : "Data",

"SingleMuon_2018A.root"               : "Data",
"SingleMuon_2018B.root"               : "Data",
"SingleMuon_2018C.root"               : "Data",
"SingleMuon_2018D.root"               : "Data",
'''
bkg_plot_order_allHad = ["diboson", "single top", "ttbar", "Z+jets", "W+jets", "QCD"]
colors_allHad =         [2008,      2002,         2001,   2010,      2011,     2005,]


legend_labels_allHad = bkg_plot_order_allHad
##all separate
#sig_plot_order_allHad = ["WWW FT0_p2", "WWW FS0_p2", "WWW FM0_p2", "WWZ FT0_p2", "WWZ FS0_p2", "WWZ FM0_p2", "WZZ FT0_p2", "WZZ FS0_p2", "WZZ FM0_p2", "ZZZ FT0_p2", "ZZZ FS0_p2", "ZZZ FM0_p2" ]

##all combined
#sig_plot_order_allHad = ["VVV FT0_p2", "VVV FM0_p2", "VVV FS0_p2"]
#sig_plot_order_allHad = ["VVV FT0_p2", "VVV FM0_p2"]
#sig_plot_order_allHad = ["VVV FT0_p15"]
#sig_plot_order_allHad = ["VVV FT0_p2"]

## all FT
#sig_plot_order_allHad = ["WWW FT0_p2", "WWZ FT0_p2", "WZZ FT0_p2", "ZZZ FT0_p2"]
#sig_plot_order_allHad = ["WWW FT0_p15", "WWZ FT0_p15", "WZZ FT0_p15", "ZZZ FT0_p15"]
## all FS
#sig_plot_order_allHad = ["WWW FS0_p2", "WWZ FS0_p2", "WZZ FS0_p2", "ZZZ FS0_p2"]
## all FM
#sig_plot_order_allHad = ["WWW FM0_p2", "WWZ FM0_p2", "WZZ FM0_p2", "ZZZ FM0_p2"]

## all range
#sig_plot_order_allHad = ["VVV FT0_p30", "VVV FT0_m30", "VVV FT0_p15", "VVV FT0_m15", "VVV FT0_p15", "VVV FT0_p10", "VVV FT0_m10", "VVV FT0_p8", "VVV FT0_m8", "VVV FT0_p4", "VVV FT0_m4", "VVV FT0_p2","VVV FT0_m2" ]
sig_plot_order_allHad = [ ]
sig_labels_allHad = sig_plot_order_allHad
#sig_plot_order_allHad = [ "WWW FT0_1" ]
#colors_allHad = [8007, 8006, 8005, 8004, 8003, 8001, ]



grouping_allHad_SRCR = {
    "WJetsToQQ_HT800toInf.root"       : "W+jets SR",
    "WJetstoLNu_HT100to200.root"       : "W+jets CR",
    "WJetstoLNu_HT200to400.root"       : "W+jets CR",
    "WJetstoLNu_HT400to600.root"       : "W+jets CR",
    "WJetstoLNu_HT600to800.root"       : "W+jets CR",
    "WJetstoLNu_HT800to1200.root"       : "W+jets CR",
    "WJetstoLNu_HT1200to2500.root"       : "W+jets CR",
    "WJetstoLNu_HT2500toInf.root"       : "W+jets CR",
    "WJetstoLNu_HT100to200_2.root"       : "W+jets VR",
    "WJetstoLNu_HT200to400_2.root"       : "W+jets VR",
    "WJetstoLNu_HT400to600_2.root"       : "W+jets VR",
    "WJetstoLNu_HT600to800_2.root"       : "W+jets VR",
    "WJetstoLNu_HT800to1200_2.root"       : "W+jets VR",
    "WJetstoLNu_HT1200to2500_2.root"       : "W+jets VR",
    "WJetstoLNu_HT2500toInf_2.root"       : "W+jets VR",

}
colors_allHad_SRCR =         [ 2011    ]
bkg_plot_order_allHad_SRCR = ["W+jets SR"   ]
sig_plot_order_allHad_SRCR = ["W+jets CR", "W+jets VR"]
sig_labels_allHad_SRCR = sig_plot_order_allHad_SRCR
legend_labels_allHad_SRCR = bkg_plot_order_allHad_SRCR





#~~~~~~~~~~~~~~~~
# 4Lep MET styles
#~~~~~~~~~~~~~~~~
grouping_4LepMET = {
        "DY_high.root"           : "Other",
        "DY_low.root"            : "Other",
        "DYzpt150.root"          : "NOTUSED",
        "GGHtoZZto4L.root"       : "Other",
        "HHAT_0p0.root"          : "NOTUSED",
        "HHAT_0p08.root"         : "NOTUSED",
        "HHAT_0p12.root"         : "NOTUSED",
        "HHAT_0p16.root"         : "NOTUSED",
        "QQWW.root"              : "Other",
        "STantitop.root"         : "Other",
        "STtop.root"             : "Other",
        "TGext.root"             : "NOTUSED",
        "TTBAR_PH.root"          : "NOTUSED",
        "TTDL.root"              : "Other",
        "TTGdilep.root"          : "NOTUSED",
        "TTGsinglelep.root"      : "NOTUSED",
        "TTGsinglelepbar.root"   : "NOTUSED",
        "TTHH.root"              : "Other",
        "TTSL.root"              : "Other",
        "TTSLtop.root"           : "NOTUSED",
        "TTSLtopbar.root"        : "NOTUSED",
        "TTTJ.root"              : "Other",
        "TTTTnew.root"           : "Other",
        "TTTW.root"              : "Other",
        "TTWH.root"              : "Other",
        "TTWW.root"              : "Other",
        "TTWZ.root"              : "Other",
        "TTWnlo.root"            : "Other",
        "TTZH.root"              : "Other",
        "TTZLOW.root"            : "TTZ",
        "TTZZ.root"              : "Other",
        "TTZnlo.root"            : "TTZ",
        "TTdilep0jet.root"       : "NOTUSED",
        "TTdilep1jet.root"       : "NOTUSED",
        "TZQ.root"               : "Other",
        "VHtoNonBB.root"         : "VH",
        "W2Jets.root"            : "NOTUSED",
        "W4Jets.root"            : "NOTUSED",
        "WGToLNuGext.root"       : "NOTUSED",
        "WJets.root"             : "Other",
        "WJets_HT100To200.root"  : "NOTUSED",
        "WJets_HT200To400.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT400To600.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT600To800.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT800To1200.root" : "NOTUSED", # HT gen level variable not implemented
        "WW.root"                : "Other",
        "WWDPS.root"             : "Other",
        "WWG.root"               : "NOTUSED",
        "WWW.root"               : "NOTUSED",
        "WWZ.root"               : "NOTUSED",
        "WZ.root"                : "WZ",
        "WZG.root"               : "NOTUSED",
        "WZZ.root"               : "NOTUSED",
        "ZG.root"                : "NOTUSED",
        "ZZ.root"                : "ZZ",
        "ZZZ.root"               : "VVV",
        "ZZcontTo2e2mu.root"     : "ZZ",
        "ZZcontTo2e2tau.root"    : "ZZ",
        "ZZcontTo2mu2tau.root"   : "ZZ",
        "ZZcontTo4mu.root"       : "ZZ",
        "ZZcontTo4tau.root"      : "ZZ",
        }
bkg_plot_order_4LepMET = [ "WZ", "Other", "VH", "TTZ", "ZZ" ]
legend_labels_4LepMET = [ "WZ", "Other", "VH", "TTZ", "ZZ" ]
sig_plot_order_4LepMET = [ "VVV" ]
sig_labels_4LepMET = [ "VVV" ]
colors_4LepMET = [7013, 920, 4024, 4305, 4020]


#~~~~~~~~~~~~~~~~
# 3Lep MET styles
#~~~~~~~~~~~~~~~~
grouping_3LepMET = {
        "DY_high.root"           : "Z",
        "DY_low.root"            : "Z",
        "DYzpt150.root"          : "NOTUSED",
        "GGHtoZZto4L.root"       : "Other",
        "HHAT_0p0.root"          : "NOTUSED",
        "HHAT_0p08.root"         : "NOTUSED",
        "HHAT_0p12.root"         : "NOTUSED",
        "HHAT_0p16.root"         : "NOTUSED",
        "QQWW.root"              : "WW",
        "STantitop.root"         : "Top",
        "STtop.root"             : "Top",
        "TGext.root"             : "NOTUSED",
        "TTBAR_PH.root"          : "NOTUSED",
        "TTDL.root"              : "Top",
        "TTGdilep.root"          : "NOTUSED",
        "TTGsinglelep.root"      : "NOTUSED",
        "TTGsinglelepbar.root"   : "NOTUSED",
        "TTHH.root"              : "Top",
        "TTSL.root"              : "Top",
        "TTSLtop.root"           : "NOTUSED",
        "TTSLtopbar.root"        : "NOTUSED",
        "TTTJ.root"              : "Top",
        "TTTTnew.root"           : "Top",
        "TTTW.root"              : "Top",
        "TTWH.root"              : "Top",
        "TTWW.root"              : "Top",
        "TTWZ.root"              : "Top",
        "TTWnlo.root"            : "ttW",
        "TTZH.root"              : "Top",
        "TTZLOW.root"            : "TTZ",
        "TTZZ.root"              : "Top",
        "TTZnlo.root"            : "TTZ",
        "TTdilep0jet.root"       : "NOTUSED",
        "TTdilep1jet.root"       : "NOTUSED",
        "TZQ.root"               : "Top",
        "VHtoNonBB.root"         : "VH",
        "W2Jets.root"            : "NOTUSED",
        "W4Jets.root"            : "NOTUSED",
        "WGToLNuGext.root"       : "NOTUSED",
        "WJets.root"             : "Other",
        "WJets_HT100To200.root"  : "NOTUSED",
        "WJets_HT200To400.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT400To600.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT600To800.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT800To1200.root" : "NOTUSED", # HT gen level variable not implemented
        "WW.root"                : "WW",
        "WWDPS.root"             : "WW",
        "WWG.root"               : "NOTUSED",
        "WWW.root"               : "VVV",
        "WWZ.root"               : "VVV",
        "WZ.root"                : "WZ",
        "WZG.root"               : "NOTUSED",
        "WZZ.root"               : "VVV",
        "ZG.root"                : "NOTUSED",
        "ZZ.root"                : "ZZ",
        "ZZZ.root"               : "VVV",
        "ZZcontTo2e2mu.root"     : "ZZ",
        "ZZcontTo2e2tau.root"    : "ZZ",
        "ZZcontTo2mu2tau.root"   : "ZZ",
        "ZZcontTo4mu.root"       : "ZZ",
        "ZZcontTo4tau.root"      : "ZZ",
    }
bkg_plot_order_3LepMET = [ "ZZ", "TTZ", "VH", "Other", "WZ", "WW","Top","Z","ttW" ]
legend_labels_3LepMET = [ "ZZ", "TTZ", "VH", "Other", "WZ", "WW","Top","Z","ttW" ]
sig_plot_order_3LepMET = [ "VVV" ]
sig_labels_3LepMET = [ "VVV" ]
colors_3LepMET = [2001, 2002, 2003, 2005, 2006, 2011, 2007, 920]
"""
legend_labels_1Lep4jet = [ "W", "Z", "Top", "Other" ]
sig_plot_order_1Lep4jet = [ "VVV", "VH" ]
sig_labels_1Lep4jet = [ "VVV", "VH" ]
colors_1Lep4jet = [2001, 7004, 7003, 7001]
"""

#~~~~~~~~~~~~~~~~
# 1Lep 4jet styles
#~~~~~~~~~~~~~~~~
grouping_1Lep4jet = {
        "DY_high.root"           : "Z",
        "DY_low.root"            : "NOTUSED",
        "DYzpt150.root"          : "NOTUSED",
        "GGHtoZZto4L.root"       : "NOTUSED",
        "HHAT_0p0.root"          : "NOTUSED",
        "HHAT_0p08.root"         : "NOTUSED",
        "HHAT_0p12.root"         : "NOTUSED",
        "HHAT_0p16.root"         : "NOTUSED",
        "QQWW.root"              : "VV",
        "STantitop.root"         : "Top",
        "STtop.root"             : "Top",
        "TGext.root"             : "NOTUSED",
        "TTBAR_PH.root"          : "NOTUSED",
        "TTDL.root"              : "Top",
        "TTGdilep.root"          : "NOTUSED",
        "TTGsinglelep.root"      : "NOTUSED",
        "TTGsinglelepbar.root"   : "NOTUSED",
        "TTHH.root"              : "NOTUSED",
        "TTSL.root"              : "Top",
        "TTSLtop.root"           : "NOTUSED",
        "TTSLtopbar.root"        : "NOTUSED",
        "TTTJ.root"              : "NOTUSED",
        "TTTTnew.root"           : "NOTUSED",
        "TTTW.root"              : "NOTUSED",
        "TTWH.root"              : "NOTUSED",
        "TTWW.root"              : "NOTUSED",
        "TTWZ.root"              : "NOTUSED",
        "TTWnlo.root"            : "NOTUSED",
        "TTZH.root"              : "NOTUSED",
        "TTZLOW.root"            : "NOTUSED",
        "TTZZ.root"              : "NOTUSED",
        "TTZnlo.root"            : "NOTUSED",
        "TTdilep0jet.root"       : "NOTUSED",
        "TTdilep1jet.root"       : "NOTUSED",
        "TZQ.root"               : "NOTUSED",
        "VHtoNonBB.root"         : "NOTUSED",
        "W2Jets.root"            : "NOTUSED",
        "W4Jets.root"            : "W",
        "WGToLNuGext.root"       : "NOTUSED",
        "WJets.root"             : "NOTUSED",
        "WJets_HT100To200.root"  : "NOTUSED",
        "WJets_HT200To400.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT400To600.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT600To800.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT800To1200.root" : "NOTUSED", # HT gen level variable not implemented
        "WW.root"                : "VV",
        "WWDPS.root"             : "NOTUSED",
        "WWG.root"               : "NOTUSED",
        "WWW.root"               : "VVV",
        "WWZ.root"               : "VVV",
        "WZ.root"                : "VV",
        "WZG.root"               : "NOTUSED",
        "WZZ.root"               : "VVV",
        "ZG.root"                : "NOTUSED",
        "ZZ.root"                : "VV",
        "ZZZ.root"               : "VVV",
        "ZZcontTo2e2mu.root"     : "NOTUSED",
        "ZZcontTo2e2tau.root"    : "NOTUSED",
        "ZZcontTo2mu2tau.root"   : "NOTUSED",
        "ZZcontTo4mu.root"       : "NOTUSED",
        "ZZcontTo4tau.root"      : "NOTUSED",
        }
# bkg_plot_order_1Lep4jet = [ "W", "Top", "Z", "VV" ]
# legend_labels_1Lep4jet = [ "W", "Top", "Z", "VV" ]
# sig_plot_order_1Lep4jet = [ "VVV" ]
# sig_labels_1Lep4jet = [ "VVV" ]
# colors_1Lep4jet = [2001, 7003, 7004, 7007 ]
bkg_plot_order_1Lep4jet = [ "VVV", "W", "Top", "Z", "VV" ]
legend_labels_1Lep4jet = [ "VVV", "W", "Top", "Z", "VV" ]
bkg_plot_order_1Lep4jet = [ "VV", "Z", "Top", "W", "VVV" ]
legend_labels_1Lep4jet = [ "VV", "Z", "Top", "W", "VVV" ]
sig_plot_order_1Lep4jet = [ "VVV" ]
sig_labels_1Lep4jet = [ "VVV" ]
colors_1Lep4jet = [7007, 7004, 7003, 2001, 2]
#~~~~~~~~~~~~~~~~
# OS +jets styles
#~~~~~~~~~~~~~~~~
grouping_OS2jet = {
        "DY_high.root"           : "Z",
        "DY_low.root"            : "Z",
        "DYzpt150.root"          : "NOTUSED",
        "GGHtoZZto4L.root"       : "Other",
        "HHAT_0p0.root"          : "NOTUSED",
        "HHAT_0p08.root"         : "NOTUSED",
        "HHAT_0p12.root"         : "NOTUSED",
        "HHAT_0p16.root"         : "NOTUSED",
        "QQWW.root"              : "WW",
        "STantitop.root"         : "Top",
        "STtop.root"             : "Top",
        "TGext.root"             : "NOTUSED",
        "TTBAR_PH.root"          : "NOTUSED",
        "TTDL.root"              : "Top",
        "TTGdilep.root"          : "NOTUSED",
        "TTGsinglelep.root"      : "NOTUSED",
        "TTGsinglelepbar.root"   : "NOTUSED",
        "TTHH.root"              : "TopX",
        "TTSL.root"              : "Top",
        "TTSLtop.root"           : "NOTUSED",
        "TTSLtopbar.root"        : "NOTUSED",
        "TTTJ.root"              : "Top",
        "TTTTnew.root"           : "Top",
        "TTTW.root"              : "TopX",
        "TTWH.root"              : "TopX",
        "TTWW.root"              : "TopX",
        "TTWZ.root"              : "TopX",
        "TTWnlo.root"            : "TopX",
        "TTZH.root"              : "TopX",
        "TTZLOW.root"            : "TopX",
        "TTZZ.root"              : "TopX",
        "TTZnlo.root"            : "TopX",
        "TTdilep0jet.root"       : "NOTUSED",
        "TTdilep1jet.root"       : "NOTUSED",
        "TZQ.root"               : "TopX",
        "TWZ.root"               : "TopX",
        "VHtoNonBB.root"         : "VH",
        "W2Jets.root"            : "NOTUSED",
        "W4Jets.root"            : "NOTUSED",
        "WGToLNuGext.root"       : "NOTUSED",
        "WJets.root"             : "NOTUSED",
        "WJets_HT100To200.root"  : "W",
        "WJets_HT200To400.root"  : "W", # HT gen level variable not implemented
        "WJets_HT400To600.root"  : "W", # HT gen level variable not implemented
        "WJets_HT600To800.root"  : "W", # HT gen level variable not implemented
        "WJets_HT800To1200.root" : "W", # HT gen level variable not implemented
        "WW.root"                : "WW",
        "WWDPS.root"             : "WW",
        "WWG.root"               : "NOTUSED",
        "WWW.root"               : "VVV",
        "WWZ.root"               : "VVV",
        "WZ.root"                : "WZ",
        "WZG.root"               : "NOTUSED",
        "WZZ.root"               : "VVV",
        "WGToLNuGext.root"       : "Other",
        "ZG.root"                : "Other",
        "ZZ.root"                : "ZZ",
        "ZZZ.root"               : "VVV",
        "ZZcontTo2e2mu.root"     : "NOTUSED",
        "ZZcontTo2e2tau.root"    : "NOTUSED",
        "ZZcontTo2mu2tau.root"   : "NOTUSED",
        "ZZcontTo4mu.root"       : "NOTUSED",
        "ZZcontTo4tau.root"      : "NOTUSED",
        "ZZcontTo4e.root"        : "NOTUSED",
        #ADD DATA
        "data_Run2016Bv1_ee.root": "Data_2016",
        "data_Run2016Bv2_ee.root": "Data_2016",
        "data_Run2016C_ee.root"  : "Data_2016",
        "data_Run2016D_ee.root"  : "Data_2016",
        "data_Run2016E_ee.root"  : "Data_2016",
        "data_Run2016F_ee.root"  : "Data_2016",
        "data_Run2016G_ee.root"  : "Data_2016",
        "data_Run2016H_ee.root"  : "Data_2016",
        "data_Run2016Bv1_em.root": "Data_2016",
        "data_Run2016Bv2_em.root": "Data_2016",
        "data_Run2016C_em.root"  : "Data_2016",
        "data_Run2016D_em.root"  : "Data_2016",
        "data_Run2016E_em.root"  : "Data_2016",
        "data_Run2016F_em.root"  : "Data_2016",
        "data_Run2016G_em.root"  : "Data_2016",
        "data_Run2016H_em.root"  : "Data_2016",
        "data_Run2016Bv1_mm.root": "Data_2016",
        "data_Run2016Bv2_mm.root": "Data_2016",
        "data_Run2016C_mm.root"  : "Data_2016",
        "data_Run2016D_mm.root"  : "Data_2016",
        "data_Run2016E_mm.root"  : "Data_2016",
        "data_Run2016F_mm.root"  : "Data_2016",
        "data_Run2016G_mm.root"  : "Data_2016",
        "data_Run2016H_mm.root"  : "Data_2016",
        "data_Run2017B_ee.root"  : "Data_2017",
        "data_Run2017C_ee.root"  : "Data_2017",
        "data_Run2017D_ee.root"  : "Data_2017",
        "data_Run2017E_ee.root"  : "Data_2017",
        "data_Run2017F_ee.root"  : "Data_2017",
        "data_Run2017B_em.root"  : "Data_2017",
        "data_Run2017C_em.root"  : "Data_2017",
        "data_Run2017D_em.root"  : "Data_2017",
        "data_Run2017E_em.root"  : "Data_2017",
        "data_Run2017F_em.root"  : "Data_2017",
        "data_Run2017B_mm.root"  : "Data_2017",
        "data_Run2017C_mm.root"  : "Data_2017",
        "data_Run2017D_mm.root"  : "Data_2017",
        "data_Run2017E_mm.root"  : "Data_2017",
        "data_Run2017F_mm.root"  : "Data_2017",
        "data_Run2018A_ee.root"  : "Data_2018",
        "data_Run2018B_ee.root"  : "Data_2018",
        "data_Run2018C_ee.root"  : "Data_2018",
        "data_Run2018D_ee.root"  : "Data_2018",
        "data_Run2018A_em.root"  : "Data_2018",
        "data_Run2018B_em.root"  : "Data_2018",
        "data_Run2018C_em.root"  : "Data_2018",
        "data_Run2018D_em.root"  : "Data_2018",
        "data_Run2018A_mm.root"  : "Data_2018",
        "data_Run2018B_mm.root"  : "Data_2018",
        "data_Run2018C_mm.root"  : "Data_2018",
        "data_Run2018D_mm.root"  : "Data_2018",
    }
bkg_plot_order_OS2jet = [ "ZZ", "WZ", "WW", "VH", "Z", "W","Top","TopX","Other" ]
legend_labels_OS2jet = [ "ZZ", "WZ", "WW", "VH", "DY", "W","Top","Top+X","Other" ]
colors_OS2jet        = [9001, 2003, 2001, 2006, 7004, 7005, 2012, 4006, 920]
sig_plot_order_OS2jet = [ "VVV" ]
sig_labels_OS2jet = [ "VVV" ]
#colors_OS2jet = [2001, 2002, 2003, 2005, 2006, 2011, 2007, 920]
