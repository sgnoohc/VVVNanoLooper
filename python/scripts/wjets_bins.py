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

dir_0l = ("/eos/uscms/store/group/lpcvvv/horyn/VVVAnalysis/Mar23_UL_reProc/atleast_3fj/")
dir_1l = ("/eos/uscms/store/group/lpcvvv/horyn/VVVAnalysis/Jul29_1L_noWMD/looseBVeto/")

files_0l = os.listdir(dir_0l)
files_1l = os.listdir(dir_1l)

subtract_other = True
rebin = True
bins = [0,1100,2000,2500,140000]

## make base HT histogram that we will add everything to
tmp = ROOT.TFile(dir_1l + "/" + files_1l[0])
empty = tmp.Get("oneL_1fj_medium__HTMET")
empty.Reset()

hists = {}

## SR estimate
hists["data"] = empty.Clone("data")
hists["other"] = empty.Clone("other")
hists["SRMC"] = empty.Clone("SRMC")
hists["CRMC"] = empty.Clone("CRMC")

## VR estimate
hists["VRdata"] = empty.Clone("VRdata")
hists["VRother"] = empty.Clone("VRother")
hists["VRSRMC"] = empty.Clone("SRVRMC")
hists["VRMC"] = empty.Clone("VRMC")

for f in files_1l:
    tf = ROOT.TFile(dir_1l + "/" + f)
    if "SingleMuon" in f or "EGamma" in f: 
        ## what we are scaling for VR
        data_next = get_raw_histogram(tf, "oneL_1fj_medium__HTMET")
        data_next = addOverflow(data_next)
        hists["VRdata"].Add(data_next)
        
        ## what we are scaling in SR
        data_next = get_raw_histogram(tf, "oneL_1fj_tight__HTMET")
        data_next = addOverflow(data_next)
        hists["data"].Add(data_next)

    elif "EFT" not in f and "WJetstoLNu" not in f:
        ## other VR
        other_next = get_xsec_lumi_scaled_histogram(tf, "oneL_1fj_medium__HTMET", 2018, False, True) 
        other_next = addOverflow(other_next)
        hists["VRother"].Add(other_next * 1.0)

        ## other SR
        other_next = get_xsec_lumi_scaled_histogram(tf, "oneL_1fj_tight__HTMET", 2018, False, True) 
        other_next = addOverflow(other_next)
        hists["other"].Add(other_next * 1.0)

    elif "WJetstoLNu" in f and "_2" not in f:
        ## VR MC WJets only
        print "working with f", f
        wjets_next = get_xsec_lumi_scaled_histogram(tf, "oneL_1fj_medium__HTMET", 2018, False, True) 
        wjets_next = addOverflow(wjets_next)
        hists["VRMC"].Add(wjets_next)
        
        ## CR MC WJets only
        wjets_next = get_xsec_lumi_scaled_histogram(tf, "oneL_1fj_tight__HTMET", 2018, False, True) 
        wjets_next = addOverflow(wjets_next)
        hists["CRMC"].Add(wjets_next)

for f in files_0l:
     tf = ROOT.TFile(dir_0l + "/" + f)

     if "WJetsToQQ" in f:
        #WJets in SR
        SR_next = get_xsec_lumi_scaled_histogram(tf, "allHad_ORTrigger_2fj__HT", 2018, False, False) 
        SR_next = addOverflow(SR_next)
        hists["SRMC"].Add(SR_next)
        
        #WJets in VR
        SR_next = get_xsec_lumi_scaled_histogram(tf, "allHad_2fj_1med1tight__HT", 2018, False, False)
        SR_next = addOverflow(SR_next)
        hists["VRSRMC"].Add(SR_next)

hists["final"] = hists["data"].Clone("final")
hists["VRfinal"] = hists["VRdata"].Clone("VRfinal")

# subtract other from data 
hists["final"].Add(hists["other"], -1)
hists["VRfinal"].Add(hists["VRother"], -1)

# SR binning
for h in hists:
    hists[h] = hists[h].Rebin(len(bins)-1, hists[h].GetName() + "new", array('d', bins))

# make TEfficiency plots
hists["VRRatio"] = ROOT.TGraphAsymmErrors(hists["VRSRMC"], hists["VRMC"], "pois")
#print "bins VRSRMC, VRMC", hists["VRSRMC"].GetNbinsX(), hists["VRMC"].GetNbinsX()
#hists["VRRatio"].Divide(hists["VRSRMC"], hists["VRMC"], "pois w")

hists["SRRatio"] = ROOT.TGraphAsymmErrors(hists["SRMC"], hists["CRMC"], "pois w")
print "SRRatio points", hists["SRRatio"].GetN(), hists["SRMC"].GetBinContent(2), hists["CRMC"].GetBinContent(2)
#hists["SRRatio"].Divide(hists["SRMC"], hists["CRMC"], "pois w")

# 3 SR bins, root histograms count from bin 1
# first bin is empty (0-1100)
for b in xrange(2, 6):

    ## graph points count from 0, thanks root, also -1 for empty 1st bin
    
    ## SR Estimate
    SR_Wjets = hists["SRMC"].GetBinContent(b)
    CR_Wjets = hists["CRMC"].GetBinContent(b)
    data = hists["final"].GetBinContent(b)

    gp = b-2 
    r_SR = hists["SRRatio"].GetY()[gp]
    r_SRup = hists["SRRatio"].GetErrorYhigh(gp)
    r_SRdw = hists["SRRatio"].GetErrorYlow(gp)
    print " R ", r_SR, r_SRup, r_SRdw

    est_SR = r_SR*data
    unc_SRup = est_SR*math.sqrt(1./data + (r_SRup/r_SR)**2)
    unc_SRdw = est_SR*math.sqrt(1./data + (r_SRdw/r_SR)**2)
    
    ## VR estimate
    SRVR_Wjets = hists["VRSRMC"].GetBinContent(b)
    VR_Wjets = hists["VRMC"].GetBinContent(b)
    VRdata = hists["VRfinal"].GetBinContent(b)

    r_VR = hists["VRRatio"].GetY()[gp]
    r_VRup = hists["VRRatio"].GetErrorYhigh(gp)
    r_VRdw = hists["VRRatio"].GetErrorYlow(gp)
    print " R ", r_VR, r_VRup, r_VRdw
    
    est_VR = r_VR*VRdata
    unc_VRup = est_VR*math.sqrt(1./VRdata + (r_VRup/r_VR)**2)
    unc_VRdw = est_VR*math.sqrt(1./VRdata + (r_VRdw/r_VR)**2)


    print
    print "\n\nworking with bin ", b, hists["SRMC"].GetBinLowEdge(b), hists["SRMC"].GetBinLowEdge(b+1)
    print
    print " VR estimate!!:: "
    print "    SRVR MC = ", round(SRVR_Wjets, 3)
    print "    VR MC   = ", round(VR_Wjets, 3)
    print "    data    = ", round(VRdata, 3)
    print "    up_err = ", round(unc_VRup, 3)
    print "    dn_err = ", round(unc_VRdw, 3)
    print "    est_e = ", round(est_VR, 3)
    
    print " SR estimate!!:: "
    print "    SR MC = ", round(SR_Wjets, 3)
    print "    CR MC   = ", round(CR_Wjets, 3)
    print "    data    = ", round(data, 3)
    print "    up_err = ", round(unc_SRup, 3)
    print "    dn_err = ", round(unc_SRdw, 3)
    print "    est_e = ", round(est_SR, 3)




     


        












