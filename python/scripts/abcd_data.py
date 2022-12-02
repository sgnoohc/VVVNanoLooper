import os
import sys
import ROOT
import glob
import argparse
import math

execfile("tdrstyle.py")
execfile("basic_plotting.py")
setTDRStyle()


ROOT.gROOT.SetBatch()

c = ROOT.TCanvas()
'''
    # Get ratio of C/D with full errors
    g_R_est = ROOT.TGraphAsymmErrors()
    g_R_est.Divide(samples[s]["hists"]["C"], samples[s]["hists"]["D"])
    r = g_R_est.GetPointY(0)
    r_eup = g_R_est.GetErrorYhigh(0)
    r_edw = g_R_est.GetErrorYlow(0)

    # Combine with events in B
    est_A = r*tot_B
    unc_Aup = est_A*math.sqrt(1./tot_B + (r_eup/r)**2)
    unc_Adw = est_A*math.sqrt(1./tot_B + (r_edw/r)**2)
'''

in_dir = ("/eos/uscms/store/group/lpcvvv/horyn/VVVAnalysis/Mar23_UL_reProc/tightWPSR/")

all_files = os.listdir(in_dir)

doQCDOnly = True


data_hists = {}
qcd_hists = {}
other_hists = {}
final_hists = {}

## empty histograms to add to
tmp = ROOT.TFile(in_dir + "/" + all_files[0])
empty = tmp.Get("allHad_2fj_ABCD_A__NLeps")
empty.Reset()

for reg in ["A","B", "C", "D", "E", "F"]:
    data_hists[reg] = empty.Clone("data_"+reg)
    other_hists[reg] = empty.Clone("other_"+reg)
    qcd_hists[reg] = empty.Clone("qcd_"+reg)

##combine all data and non-QCD or signal MC
for f in all_files:
    tf = ROOT.TFile(in_dir + "/" + f)
    for reg in ["A","B", "C", "D", "E", "F"]:    
        if "JetHT" in f:
            data_next = get_raw_histogram(tf, "allHad_2fj_ABCD_"+reg+"__NLeps")
            data_hists[reg].Add(data_next)
        
        elif "QCD" in f:
            qcd_next = get_xsec_lumi_scaled_histogram(tf, "allHad_2fj_ABCD_"+reg+"__NLeps", 2018, False) 
            qcd_hists[reg].Add(qcd_next)

        elif "EFT" not in f and "QCD" not in f:
            other_next = get_xsec_lumi_scaled_histogram(tf, "allHad_2fj_ABCD_"+reg+"__NLeps", 2018, False) 
            other_hists[reg].Add(other_next * 1.0)
            #if "JetsToQQ" not in f and "WZ" not in f and "WW" not in f and "ZZ" not in f:
            #    other_hists[reg].Add(other_next * 0.5)
            #else:
            #    other_hists[reg].Add(other_next * 1.0)

##now subtract other MC from data
for reg in ["A","B", "C", "D", "E", "F"]:
    final = data_hists[reg].Clone("final_"+reg)
    final.Add(other_hists[reg], -1)
    final_hists[reg] = final
    
    data_hists[reg].SetLineColor(ROOT.kBlue)
    other_hists[reg].SetLineColor(ROOT.kRed)
    final_hists[reg].SetLineColor(ROOT.kBlack)
    
    print "for region ", reg
    print "   # inital data ", data_hists[reg].GetBinContent(1)
    print "   # inital other ", other_hists[reg].GetBinContent(1)
    print "   # final        ", final_hists[reg].GetBinContent(1)


if doQCDOnly:
    final_hists = qcd_hists

#n_a = f.Get("allHad_2fj_ABCD_A__NLeps").GetBinContent(1)
n_b = final_hists["B"].GetBinContent(1)
n_c = final_hists["C"].GetBinContent(1)
n_d = final_hists["D"].GetBinContent(1)
n_e = final_hists["E"].GetBinContent(1)
n_f = final_hists["F"].GetBinContent(1)


### VR estimate
g_R_est = ROOT.TGraphAsymmErrors()
g_R_est.Divide(final_hists["C"], final_hists["D"], "pois")
r = g_R_est.GetY()[0]
print " R ", r
r_eup = g_R_est.GetErrorYhigh(0)
r_edw = g_R_est.GetErrorYlow(0)

est_e = r*n_f
unc_Eup = est_e*math.sqrt(1./n_f + (r_eup/r)**2)
unc_Edw = est_e*math.sqrt(1./n_f + (r_edw/r)**2)

est_a = r*n_b
unc_Aup = est_a*math.sqrt(1./n_b + (r_eup/r)**2)
unc_Adw = est_a*math.sqrt(1./n_b + (r_edw/r)**2)


print
print
print " VR estimate!!:: "
print "    n_c = ", round(n_c, 3)
print "    n_d = ", round(n_d, 3)
print "    n_f = ", round(n_f, 3)
print "    n_e = ", round(n_e, 3)
print "    up_err = ", round(unc_Eup, 3)
print "    dn_err = ", round(unc_Edw, 3)
print "    est_e = ", round(est_e, 3)
print "     % err = ", round(abs(est_e - n_e)*100/n_e, 3)
print
print "    up_err = ", round(unc_Aup, 3)
print "    dn_err = ", round(unc_Adw, 3)
print "    est_a = ", round(est_a, 3)



