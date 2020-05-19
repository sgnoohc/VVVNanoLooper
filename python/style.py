#!/bin/env python

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
