import ROOT
import glob

ROOT.gROOT.SetBatch(1)
files = glob.glob("../WZZ/WZZ_EFT*.root")

to_plot = ["allHad_ORTrigger_3fj__HT_fj", "allHad_ORTrigger_2fj__HT_fj", "allHad_ORTrigger_3fj__mVVV_reco_fj", "allHad_ORTrigger_2fj__mVVV_reco_fj", "allHad_ORTrigger_2fj__ptVVV_reco_fj", "allHad_ORTrigger_3fj__ptVVV_reco_fj", "allHad_ORTrigger_2fj__MET", "allHad_ORTrigger_3fj__MET"]

execfile("tdrstyle.py")
setTDRStyle()

c = ROOT.TCanvas()
leg = ROOT.TLegend(0.55,0.62,0.85,0.92)
for var in to_plot:
    c.Clear()
    leg.Clear()
    first = True
    i=0
    for ff in files:
        f = ROOT.TFile(ff)
        print ff
        h = f.Get(var)
        h.SetDirectory(0)
        h.SetLineColor(colors[i])
        h.SetMarkerColor(colors[i])
        h.Scale(1./h.Integral())
        h.Rebin(2)
        
        if "FM" in ff: h.SetMarkerStyle(21)
        if "FS" in ff: h.SetMarkerStyle(22)
        i+=1
         
        leg.AddEntry(h, ff.split("__")[1].strip(".root"), 'lp')

        if first:
            h.Draw("pl hist")
            h.SetMaximum(.6)
            first = False
        else:
            h.Draw("phistl same")

    leg.Draw("same")
    c.Modified()
    #c.Update()
    c.SaveAs("stacks/wzz_eft_%s.pdf"%var)





