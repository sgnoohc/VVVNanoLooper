#!/bin/env python

# Parsing V1SF histogram for computing SF

import sys
from errors import E
import math
import ROOT as r

# Plotting the efficieny graph
c1 = r.TCanvas()
c1.SetLeftMargin(0.15)
c1.SetBottomMargin(0.2)


def getSF(fname, selection, printineff=False):
    f = open(fname)
    lines = f.readlines()
    datafail = 0
    datapass = 0
    mcfail = 0
    mcpass = 0
    QCDidx = -1
    Totalidx = -1
    Dataidx = -1
    for line in lines:
        if "Bin#" in line:
            for index, ls in enumerate(line.split()):
                if "QCD" in ls:
                    QCDidx = (index - 3) * 2 + 3
                if "Total" in ls:
                    Totalidx = (index - 3) * 2 + 3
                if "JetHT" in ls:
                    Dataidx = (index - 3) * 2 + 3
        if "Bin1" in line:
            QCD = float(line.split()[QCDidx])
            QCDerr = float(line.split()[QCDidx+2])
            Total = float(line.split()[Totalidx])
            Totalerr = float(line.split()[Totalidx+2])
            Data = float(line.split()[Dataidx])
            Dataerr = float(line.split()[Dataidx+2])
            NonQCD = Total - QCD
            NonQCDerr = math.sqrt(Totalerr**2 - QCDerr**2)
            qcd = E(QCD, QCDerr)
            total = E(Total, Totalerr)
            nonqcd = E(NonQCD, NonQCDerr)
            data = E(Data, Dataerr)
            dataqcd = data - nonqcd
            datafail = dataqcd
            mcfail = qcd
        if "Bin2" in line:
            QCD = float(line.split()[QCDidx])
            QCDerr = float(line.split()[QCDidx+2])
            Total = float(line.split()[Totalidx])
            Totalerr = float(line.split()[Totalidx+2])
            Data = float(line.split()[Dataidx])
            Dataerr = float(line.split()[Dataidx+2])
            NonQCD = Total - QCD
            NonQCDerr = math.sqrt(Totalerr**2 - QCDerr**2)
            qcd = E(QCD, QCDerr)
            total = E(Total, Totalerr)
            nonqcd = E(NonQCD, NonQCDerr)
            data = E(Data, Dataerr)
            dataqcd = data - nonqcd
            datapass = dataqcd
            mcpass = qcd
    dataall = datapass + datafail
    mcall = mcpass + mcfail
    dataeff = datapass / dataall
    mceff = mcpass / mcall
    dataineff = datafail / dataall
    mcineff = mcfail / mcall
    # print(dataeff)
    # print(mceff)
    sf = dataeff / mceff
    sfineff = dataineff / mcineff
    if printineff:
        print("            if ({}) return {}; // ineff_data={}".format(selection, sfineff.val, dataineff))
    else:
        print("            if ({}) return {}; // eff_data={}".format(selection, sf.val, dataeff))
    return (sf, sfineff, mceff, dataeff)



def printSF(year, WP, printineff=False):
    suffix = WP
    if WP == "0p4": suffix = ""
    if WP == "0p6": suffix = "0p6"
    if WP == "0p8": suffix = "0p8"
    if WP == "0p9": suffix = "0p9"
    print("    //_______________________________________________________________________________")
    if printineff:
        print("    auto VMD{}_ineffSF_{} = [&](float pt)".format(WP, year))
    else:
        print("    auto VMD{}_SF_{} = [&](float pt)".format(WP, year))
    print("        {")
    results = []
    getSF("plots/{}/plots_d8_SF/NFJEq2MSD1__V1SF{}.txt".format(year, suffix)        , "false", printineff=printineff)
    bounds = ["200", "250", "300", "350", "400", "450", "500", "550", "600", "650", "700", "750", "800", "850", "1000"]
    for idx, bound in enumerate(bounds):
        lowbound = bound
        # If last element then special
        if idx == len(bounds) - 1:
            results.append(
                    getSF(
                        "plots/{}/plots_d8_SF/NFJEq2Pt1{}Inf__V1SF{}.txt".format(year, lowbound, suffix),
                        "pt >= {}              ".format(lowbound),
                        printineff=printineff)
                    )
        else:
            highbound = bounds[idx+1]
            results.append(
                    getSF(
                        "plots/{}/plots_d8_SF/NFJEq2Pt1{}{}__V1SF{}.txt".format(year, lowbound, highbound, suffix),
                        "pt >= {}  and pt < {:4s}".format(lowbound, highbound),
                        printineff=printineff)
                    )
    print("            else                        return 1.00000000000;")
    print("        };")

    gSF = r.TGraphErrors(len(results))
    gDE = r.TGraphErrors(len(results))
    gME = r.TGraphErrors(len(results))
    gSF.SetTitle("VMD SF {} {}".format(year, WP))
    gDE.SetTitle("VMD data eff {} {}".format(year, WP))
    gME.SetTitle("VMD MC eff {} {}".format(year, WP))
    for idx, res in enumerate(results):
        if idx == len(results) - 1:
            width =  500
            center = 1250
        else:
            width = float(bounds[idx+1]) - float(bounds[idx])
            center = float(bounds[idx]) + (width / 2)
        gSF.SetPoint(idx, center, results[idx][0].val)
        gSF.SetPointError(idx, width / 2., results[idx][0].err)
        gDE.SetPoint(idx, center, results[idx][2].val)
        gDE.SetPointError(idx, width / 2., results[idx][2].err)
        gME.SetPoint(idx, center, results[idx][3].val)
        gME.SetPointError(idx, width / 2., results[idx][3].err)
    gSF.SetMarkerStyle(19)
    gSF.Draw("ape")
    gSF.GetYaxis().SetTitle("Scale Factor")
    gSF.GetXaxis().SetTitle("p_{T} [GeV]")
    gSF.GetYaxis().SetTitleOffset(1)
    gSF.GetXaxis().SetTitleOffset(1)
    gSF.GetYaxis().SetTitleSize(0.08)
    gSF.GetXaxis().SetTitleSize(0.08)
    gSF.GetYaxis().SetLabelSize(0.06)
    gSF.GetXaxis().SetLabelSize(0.06)
    c1.Print("plots/vmd_tagger_performance/SF.pdf", "pdf")
    gDE.SetMarkerStyle(19)
    gDE.Draw("ape")
    gDE.GetYaxis().SetTitle("VMD Tagger Eff. (QCD Data)")
    gDE.GetXaxis().SetTitle("p_{T} [GeV]")
    c1.Print("plots/vmd_tagger_performance/data_eff.pdf", "pdf")
    gME.SetMarkerStyle(19)
    gME.Draw("ape")
    gME.GetYaxis().SetTitle("VMD Tagger Eff. (QCD MC)")
    gME.GetXaxis().SetTitle("p_{T} [GeV]")
    c1.Print("plots/vmd_tagger_performance/mc_eff.pdf", "pdf")





years = ["2006", "2016", "2017", "2018"]

c1.Print("plots/vmd_tagger_performance/SF.pdf(", "pdf")
c1.Print("plots/vmd_tagger_performance/data_eff.pdf(", "pdf")
c1.Print("plots/vmd_tagger_performance/mc_eff.pdf(", "pdf")
for year in years:
    printSF(year, "0p4", False)
    printSF(year, "0p6", False)
    printSF(year, "0p8", False)
    printSF(year, "0p9", False)
    printSF(year, "0p4", True)
    printSF(year, "0p6", True)
    printSF(year, "0p8", True)
    printSF(year, "0p9", True)
printSF("2006", "WP06", False)
printSF("2006", "WP06", True)
printSF("2016", "WP16", False)
printSF("2016", "WP16", True)
printSF("2017", "WP17", False)
printSF("2017", "WP17", True)
printSF("2018", "WP18", False)
printSF("2018", "WP18", True)
c1.Print("plots/vmd_tagger_performance/SF.pdf)", "pdf")
c1.Print("plots/vmd_tagger_performance/data_eff.pdf)", "pdf")
c1.Print("plots/vmd_tagger_performance/mc_eff.pdf)", "pdf")
