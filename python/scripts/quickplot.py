import os
import sys
import ROOT
import glob
import argparse

execfile("tdrstyle.py")
setTDRStyle()

weighting = {
    "WZZ" : {
       "EFT__FS0_p30" : 11,
       "EFT__FS1_p30" : 23,
       "EFT__FS2_p30" : 35,
       "EFT__FM0_p30" : 47,
       "EFT__FM1_p30" : 59,
       "EFT__FM6_p30" : 71,
       "EFT__FM7_p30" : 83,
       "EFT__FT0_p30" : 95,
       "EFT__FT1_p30" : 107,
       "EFT__FT2_p30" : 119,
       "SM"           : 120,
       "xs"           : 0.05565, 
    }
}

ROOT.gROOT.SetBatch()

c = ROOT.TCanvas()

def get_weight(hname, f):
    lumi = 137. #ifb
    xs = 0.2086 *1000# for WWW, make this smarter in the future
    eftbin = 6 # default, for FT0_5
    if "SM" in hname: eftbin = 0
    if "FT0_m10" in hname: eftbin = 1
    if "FT0_m5" in hname: eftbin = 2
    if "FT0_10" in hname: eftbin = 6
    # bins count from 1
    denom = f.Get("Wgt__h_nevents").GetBinContent(1) 
    if "WWW" in hname: denom = f.Get("Root__h_Common_LHEWeight_mg_reweighting_times_genWeight").GetBinContent(1)
    
    return xs*lumi/denom
    

if __name__ == "__main__":
    
    parser = argparse.ArgumentParser()
    parser.add_argument("--inpFile", help="input filename") 
    parser.add_argument("--inpDir", help="input directory with files") 
    parser.add_argument("--do1D", help="do 1d histograms", action='store_true') 
    parser.add_argument("--log1D", help="log 1D histograms", action='store_true') 
    args = parser.parse_args()
    
    files = []
    if args.inpFile:
        files.append(args.inpFile)
    elif args.inpDir: 
        files = glob.glob(args.inpDir + "/*.root")
    else:
        print "you need to give me something to work with!"
        sys.exit()
     
    for inFile in files:
        f = ROOT.TFile(inFile)
        outputName = inFile.split("/")[-1].strip(".root")
        print outputName 
        if not os.path.exists("plots/"+outputName):
                os.makedirs("plots/"+outputName)
        
                 
        sumw_hist = f.Get("Root__h_Common_LHEWeight_mg_reweighting_times_genWeight")

        for key in f.GetListOfKeys():
            c.Clear()
            if "TH" not in key.GetClassName(): continue 
            
            kname = key.GetName()
            if "SR" in kname: continue
            h = f.Get(kname)
            
             
            ## 2D histogram
            if "_v_" in kname:
                yname = kname.split("_v_")[1]
                xname = kname.split("__")[1].split("_v_")[0]

                h.GetYaxis().SetTitle(yname)
                h.GetXaxis().SetTitle(xname)
                
                #h.Scale(get_weight(kname, f))
                h.Draw("COLZ")
                c.SaveAs("plots/"+ outputName + "/" +kname+".pdf")
            
            ## 1D histogram
            
            elif args.do1D:
                ROOT.gPad.SetLogy(args.log1D)
                xname = kname
                try:
                    xname = kname.split("__")[1]
                except:
                    xname = kname
                    
                h.SetLineColor(ROOT.kMagenta+1)
                h.GetXaxis().SetTitle(xname)
                h.GetYaxis().SetTitle("number of entries")
                h.Scale(get_weight(kname, f))

                h.Draw("hist")
             
                c.SaveAs("plots/"+ outputName + "/" +kname+".pdf")
            
