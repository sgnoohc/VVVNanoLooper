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


in_dir = "/eos/uscms/store/group/lpcvvv/horyn/VVVAnalysis/EFT_noselection/hists/"

all_files = os.listdir(in_dir)

weighted_hists = {}

efts = {"SM":     {"color": ROOT.kBlack, "index": 0, "label": "SM"},
        "FM0_p30": {"color": ROOT.kBlue, "index": 43, "label": "FM0 = 2 TeV^{-4}"},
        "FT0_p30": {"color": ROOT.kRed, "index": 91,  "label": "FT0 = 30 TeV^{-4}" }, 
        "FS0_p15": {"color": ROOT.kMagenta + 2, "index": 7, "label": "FS0 = 150 TeV^{-4}"}
}

files = {}
for af in all_files:
    eft = af.split("__")[1].strip(".root")
    files[eft] = ROOT.TFile(in_dir + af)
    print eft
    weighted_hists[eft] = files[eft].Get("allHad_EFT__mVVV")
    #weighted_hists[eft].Rebin(3)
    
    n_eff_events = files[eft].Get("Root__h_Common_LHEWeight_mg_reweighting_times_genWeight").GetBinContent(1)
    xsec = 0.2086
    lumi = 137.
    
    scale1fb = xsec * 1000. * lumi / n_eff_events
    #weighted_hists[eft].Scale(1/weighted_hists[eft].Integral())
    #if eft == "FS0_p30": weighted_hists[eft].Scale(scale1fb*0.8)
    #else: weighted_hists[eft].Scale(scale1fb)
    #weighted_hists[eft].Scale(scale1fb)



c = ROOT.TCanvas()
leg = ROOT.TLegend(0.55,0.72,0.85,0.92)
c.Clear()
leg.SetTextSize(0.04)
leg.SetTextFont(42)
leg.SetFillStyle(0)


#ROOT.gPad.SetLogy()
weighted_hists["SM"].SetLineColor(efts["SM"]["color"])
weighted_hists["SM"].SetMarkerColor(efts["SM"]["color"])
weighted_hists["SM"].GetXaxis().SetTitle("m_{VVV} (gen-level) [GeV]")
weighted_hists["SM"].GetYaxis().SetTitle("Entries")
#weighted_hists["SM"].SetMaximum(100000)
weighted_hists["SM"].Draw("hist")
leg.AddEntry(weighted_hists["SM"], efts["SM"]["label"], 'l')

for ef in efts:
    if ef == "SM": continue
    print ef
    print efts[ef]["color"]
    print weighted_hists[ef]
    weighted_hists[ef].SetLineColor(efts[ef]["color"])
    weighted_hists[ef].SetMarkerColor(efts[ef]["color"])
    weighted_hists[ef].Draw("histsame")
    leg.AddEntry(weighted_hists[ef], efts[ef]["label"], 'l')


leg.Draw("same")
ROOT.gPad.Update()
c.Update()
c.SaveAs("eft_comp.pdf")
