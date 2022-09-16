import os
import sys
import ROOT
import glob
import argparse
import math
from array import array

execfile("tdrstyle.py")
execfile("basic_plotting.py")
setTDRStyle()


ROOT.gROOT.SetBatch()

c = ROOT.TCanvas()
ROOT.gPad.SetLogx()
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

0LDir = ("/eos/uscms/store/group/lpcvvv/horyn/VVVAnalysis/Mar23_UL_reProc/atleast_3fj/")

all_files = os.listdir(0LDir)

subtract_other = True
rebin = True
bins = [0,1100,2000,2500,140000]
data_hists = {}
other_hists = {}
final_hists = {}

hist = "HTMET"

## empty histograms to add to
tmp = ROOT.TFile(in_dir + "/" + all_files[0])
empty = tmp.Get("allHad_2fj_ABCD_B__"+hist)
empty.Reset()

for reg in ["B", "C", "D", "E", "F"]:    
    data_hists[reg] = empty.Clone("data_"+reg)
    other_hists[reg] = empty.Clone("other_"+reg)

##combine all data and non-QCD or signal MC
for f in all_files:
    tf = ROOT.TFile(in_dir + "/" + f)
    for reg in ["B", "C", "D", "E", "F"]:    
        if "JetHT" in f:
            data_next = get_raw_histogram(tf, "allHad_2fj_ABCD_"+reg+"__"+hist)
            data_next = addOverflow(data_next)
            data_hists[reg].Add(data_next)

        elif "EFT" not in f and "QCD" not in f:
            other_next = get_xsec_lumi_scaled_histogram(tf, "allHad_2fj_ABCD_"+reg+"__"+hist, 2018, False) 
            other_next = addOverflow(other_next)
            other_hists[reg].Add(other_next * 1.0)

##now subtract other MC from data
for reg in ["B", "C", "D", "E", "F"]:
    final = data_hists[reg].Clone("final_"+reg)
    if subtract_other :
        print "subtracting others"
        final.Add(other_hists[reg], -1)
        data = data_hists[reg]
        other = other_hists[reg]
    if rebin:
        final_rebin = final.Rebin(len(bins)-1, final.GetName() + "new", array('d', bins))
        other_rebin = other.Rebin(len(bins)-1, other.GetName() + "new", array('d', bins))
        data_rebin = data.Rebin(len(bins)-1, data.GetName() + "new", array('d', bins))
    else:
        final_rebin = final
        data_rebin = data
        other_rebin = other
    final_hists[reg] = final_rebin
    data_hists[reg] = data_rebin
    other_hists[reg] = other_rebin
    
    print "n bins", final_rebin.GetNbinsX() 
    for i in xrange(0, final_rebin.GetNbinsX()+2):
        print "bin ", i , final_rebin.GetBinContent(i)
    
    data_hists[reg].SetLineColor(ROOT.kBlue)
    other_hists[reg].SetLineColor(ROOT.kRed)
    final_hists[reg].SetLineColor(ROOT.kBlack)

    c.Clear()
    data_hists[reg].Draw("hist")
    other_hists[reg].Draw("hist same")
    final_hists[reg].Draw("hist same")
    c.Modified()
    c.Update()
    c.SaveAs("plots/abcd/reg_"+reg+".pdf")
    
    print "for region ", reg
    print "   # inital data ", data_hists[reg].GetBinContent(1)
    print "   # inital other ", other_hists[reg].GetBinContent(1)
    print "   # final        ", final_hists[reg].GetBinContent(1)





##  c/d ratio
g_R_est = ROOT.TGraphAsymmErrors()
print "entries c d", final_hists["C"].GetEntries(), final_hists["C"].Integral(), final_hists["D"].GetEntries(), final_hists["D"].Integral()
g_R_est.Divide(final_hists["C"], final_hists["D"], "pois")
c.Clear()
g_R_est.Draw('pela')
c.Modified()
c.Update()
c.SaveAs("plots/abcd/ratio.pdf")

# 3 SR bins, root histograms count from bin 1
for b in xrange(2, 6):
    
    n_b = final_hists["B"].GetBinContent(b)
    n_c = final_hists["C"].GetBinContent(b)
    n_d = final_hists["D"].GetBinContent(b)
    n_e = final_hists["E"].GetBinContent(b)
    n_f = final_hists["F"].GetBinContent(b)
    

    #g_R_est.Divide(final_hists["C"], final_hists["D"], "pois")

    ## graph points count from 0, thanks root, also -1 for empty 1st bin
    gp = b-2 
    r = g_R_est.GetY()[gp]
    r_eup = g_R_est.GetErrorYhigh(gp)
    r_edw = g_R_est.GetErrorYlow(gp)
    print " R ", r, r_eup, r_edw


    est_e = r*n_f
    unc_Eup = est_e*math.sqrt(1./n_f + (r_eup/r)**2)
    unc_Edw = est_e*math.sqrt(1./n_f + (r_edw/r)**2)
    
    n_b = n_b
    est_a = r*n_b
    unc_Aup = est_a*math.sqrt(1./n_b + (r_eup/r)**2)
    unc_Adw = est_a*math.sqrt(1./n_b + (r_edw/r)**2)



    print
    print "\n\nworking with bin ", b, final_hists["B"].GetBinLowEdge(b), final_hists["B"].GetBinLowEdge(b+1)
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
    
    print " SR estimate!!:: "
    print "    n_c = ", round(n_c, 3)
    print "    n_d = ", round(n_d, 3)
    print "    n_b = ", round(n_b, 3)
    print "    up_err = ", round(unc_Aup, 3)
    print "    dn_err = ", round(unc_Adw, 3)
    print "    est_a = ", round(est_a, 3)
    



