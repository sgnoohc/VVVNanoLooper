import os
import sys
import ROOT
import glob
import argparse
import math

execfile("tdrstyle.py")
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

in_f = ("/eos/uscms/store/group/lpcvvv/horyn/VVVAnalysis/011922_loose_nomSD/ABCD_SRbins/QCD_all.root")

f = ROOT.TFile(in_f)


n_a = f.Get("allHad_2fj_ABCD_A__NLeps").GetBinContent(1)
n_b = f.Get("allHad_2fj_ABCD_B__NLeps").GetBinContent(1)
n_c = f.Get("allHad_2fj_ABCD_C__NLeps").GetBinContent(1)
n_d = f.Get("allHad_2fj_ABCD_D__NLeps").GetBinContent(1)
n_e = f.Get("allHad_2fj_ABCD_E__NLeps").GetBinContent(1)
n_f = f.Get("allHad_2fj_ABCD_F__NLeps").GetBinContent(1)

g_R_est = ROOT.TGraphAsymmErrors()
g_R_est.Divide(f.Get("allHad_2fj_ABCD_C__NLeps"), f.Get("allHad_2fj_ABCD_D__NLeps"), "pois")
r = g_R_est.GetY()[0]
print " R ", r
r_eup = g_R_est.GetErrorYhigh(0)
r_edw = g_R_est.GetErrorYlow(0)

est_a = r*n_b
unc_Aup = est_a*math.sqrt(1./n_b + (r_eup/r)**2)
unc_Adw = est_a*math.sqrt(1./n_b + (r_edw/r)**2)

est_e = r*n_f
unc_Eup = est_e*math.sqrt(1./n_f + (r_eup/r)**2)
unc_Edw = est_e*math.sqrt(1./n_f + (r_edw/r)**2)



print " estimate!!:: "
print "    n_c = ", round(n_c, 3)
print "    n_d = ", round(n_d, 3)
print "    n_b = ", round(n_b, 3)
print "    n_a = ", round(n_a, 3)
print "    up_err = ", round(unc_Aup, 3)
print "    dn_err = ", round(unc_Adw, 3)
print "    est_a = ", round(est_a, 3)
print "     % err = ", round(abs(est_a - n_a)*100/n_a, 3)

print
print
print " VR estimate!!:: "
print "    n_c = ", round(n_c, 3)
print "    n_d = ", round(n_d, 3)
print "    n_f = ", round(n_f, 3)
print "    n_e = ", round(n_e, 3)
print "    up_err = ", round(unc_Eup, 3)
print "    dn_err = ", round(unc_Edw, 3)
print "    est_a = ", round(est_e, 3)
print "     % err = ", round(abs(est_e - n_e)*100/n_e, 3)




