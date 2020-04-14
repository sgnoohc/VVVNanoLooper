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
bkg_plot_order_4LepMET = [ "ZZ", "TTZ", "VH", "Other", "WZ" ]
legend_labels_4LepMET = [ "ZZ", "TTZ", "VH", "Other", "WZ" ]
sig_plot_order_4LepMET = [ "VVV" ]
sig_labels_4LepMET = [ "VVV" ]
colors_4LepMET = [2001, 2002, 2003, 2005, 2006]

#~~~~~~~~~~~~~~~~
# 1Lep 4jet styles
#~~~~~~~~~~~~~~~~
grouping_1Lep4jet = {
        "DY_high.root"           : "Z",
        "DY_low.root"            : "Z",
        "DYzpt150.root"          : "NOTUSED",
        "GGHtoZZto4L.root"       : "Other",
        "HHAT_0p0.root"          : "NOTUSED",
        "HHAT_0p08.root"         : "NOTUSED",
        "HHAT_0p12.root"         : "NOTUSED",
        "HHAT_0p16.root"         : "NOTUSED",
        "QQWW.root"              : "Other",
        "STantitop.root"         : "Top",
        "STtop.root"             : "Top",
        "TGext.root"             : "NOTUSED",
        "TTBAR_PH.root"          : "Top",
        "TTDL.root"              : "NOTUSED",
        "TTGdilep.root"          : "NOTUSED",
        "TTGsinglelep.root"      : "NOTUSED",
        "TTGsinglelepbar.root"   : "NOTUSED",
        "TTHH.root"              : "Other",
        "TTSL.root"              : "NOTUSED",
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
        "TTZLOW.root"            : "Other",
        "TTZZ.root"              : "Other",
        "TTZnlo.root"            : "Other",
        "TTdilep0jet.root"       : "NOTUSED",
        "TTdilep1jet.root"       : "NOTUSED",
        "TZQ.root"               : "Other",
        "VHtoNonBB.root"         : "VH",
        "W2Jets.root"            : "NOTUSED",
        "W4Jets.root"            : "NOTUSED",
        "WGToLNuGext.root"       : "NOTUSED",
        "WJets.root"             : "W",
        "WJets_HT100To200.root"  : "NOTUSED",
        "WJets_HT200To400.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT400To600.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT600To800.root"  : "NOTUSED", # HT gen level variable not implemented
        "WJets_HT800To1200.root" : "NOTUSED", # HT gen level variable not implemented
        "WW.root"                : "Other",
        "WWDPS.root"             : "Other",
        "WWG.root"               : "NOTUSED",
        "WWW.root"               : "VVV",
        "WWZ.root"               : "VVV",
        "WZ.root"                : "Other",
        "WZG.root"               : "NOTUSED",
        "WZZ.root"               : "VVV",
        "ZG.root"                : "NOTUSED",
        "ZZ.root"                : "Other",
        "ZZZ.root"               : "VVV",
        "ZZcontTo2e2mu.root"     : "Other",
        "ZZcontTo2e2tau.root"    : "Other",
        "ZZcontTo2mu2tau.root"   : "Other",
        "ZZcontTo4mu.root"       : "Other",
        "ZZcontTo4tau.root"      : "Other",
        }
bkg_plot_order_1Lep4jet = [ "W", "Z", "Top", "Other" ]
legend_labels_1Lep4jet = [ "W", "Z", "Top", "Other" ]
sig_plot_order_1Lep4jet = [ "VVV", "VH" ]
sig_labels_1Lep4jet = [ "VVV", "VH" ]
colors_1Lep4jet = [2001, 7004, 7003, 7001]
