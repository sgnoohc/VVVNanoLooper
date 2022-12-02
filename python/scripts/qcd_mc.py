import ROOT
import os
import glob
import numpy
from array import array

execfile("basic_plotting.py")

ROOT.gROOT.SetBatch(True)
c = ROOT.TCanvas()

to_plot = ["mVVV_reco_nomet_fj_SD", "ptVVV_reco_nomet_fj_SD", "FatJet_pt_0", "MET", "HT", "HT_fj", "ST"]

out_name = "plots/QCD/"

qcd_mc = ROOT.TFile("/eos/uscms/store/group/lpcvvv/horyn/VVVAnalysis/011922_loose_nomSD/hists_v1//QCD_all.root")

for v in to_plot:

    mjj_CR = qcd_mc.Get("allHad_2fj_1med1tight__%s"%v)
    mjj_SD = qcd_mc.Get("allHad_2fj_mSD_sideband__%s"%v)
    mjj_SR = qcd_mc.Get("allHad_ORTrigger_2fj__%s"%v)

    mjj_CR.SetTitle("1 medium 1 tight")
    mjj_SD.SetTitle("mSD sideband")
    mjj_SR.SetTitle("SR")

    mjj_CR = addOverflow(mjj_CR)
    mjj_SD = addOverflow(mjj_SD)
    mjj_SR = addOverflow(mjj_SR)
    
    mjj_CR.Scale(mjj_SR.Integral()/mjj_CR.Integral())
    mjj_SD.Scale(mjj_SR.Integral()/mjj_SD.Integral())

    mjj_CR.SetLineColor(colors[0])
    mjj_CR.SetMarkerColor(colors[0])
    
    mjj_SD.SetLineColor(colors[1])
    mjj_SD.SetMarkerColor(colors[1])
    
    mjj_SR.SetLineColor(ROOT.kBlack)
    mjj_SR.SetMarkerColor(ROOT.kBlack)

    mjj_CR.Rebin(12)
    mjj_SD.Rebin(12)
    mjj_SR.Rebin(12)
#xbins = array('d',[0,500,700,900,1100,1300,1500,1700,2000,2400,2800,4000])
#mjj_CR_r = mjj_CR.Rebin(12, "CR_dup", xbins)
#mjj_SR_r = mjj_SR.Rebin(12, "SR_dup", xbins)

##clone everything to not mess up plotting
    CR_init = mjj_CR.Clone()
    SD_init = mjj_SD.Clone()
    SR_init = mjj_SR.Clone()

    ratio_CR = CR_init.Clone()
    ratio_CR.Divide(SR_init)
    ratio_CR.GetXaxis().SetTitle(v)
    
    ratio_SD = SD_init.Clone()
    ratio_SD.Divide(SR_init)
    ratio_SD.GetXaxis().SetTitle(v)
    
    ratio_SD = SD_init.Clone()
    
    drawTwoPads([CR_init, SD_init, SR_init], [ratio_CR, ratio_SD], out_name+"%s_CRSR_norm.pdf"%v)
    
    drawTwoPads([SD_init, SR_init], [ratio_SD], out_name+"%s_CRSR_onlySD.pdf"%v)
    
    drawTwoPads([CR_init, SR_init], [ratio_CR], out_name+"%s_CRSR_only1med1tight.pdf"%v)

