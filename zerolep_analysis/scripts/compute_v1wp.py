#!/bin/env python

# Parsing V1SF histogram for computing SF

import sys
from errors import E
import math
import ROOT as r

def getROC(year,ptbin):

    f_QCD    = r.TFile("hadds/{}/QCD.root".format(year))
    f_JetHT  = r.TFile("hadds/{}/JetHT.root".format(year))
    f_NonQCD = r.TFile("hadds/{}/NonQCD.root".format(year))

    # h_QCD    = f_QCD.Get("NFJEq2Pt1{}__V1WP".format(ptbin))
    # h_JetHT  = f_JetHT.Get("NFJEq2Pt1{}__V1WP".format(ptbin))
    # h_NonQCD = f_NonQCD.Get("NFJEq2Pt1{}__V1WP".format(ptbin))

    # h_QCD    = f_QCD.Get("NFJGeq3Close{}__VcWP".format(ptbin))
    # h_JetHT  = f_JetHT.Get("NFJGeq3Close{}__VcWP".format(ptbin))
    # h_NonQCD = f_NonQCD.Get("NFJGeq3Close{}__VcWP".format(ptbin))

    h_QCD    = f_QCD.Get("NFJEq2MSD1__V1WP".format(ptbin))
    h_JetHT  = f_JetHT.Get("NFJEq2MSD1__V1WP".format(ptbin))
    h_NonQCD = f_NonQCD.Get("NFJEq2MSD1__V1WP".format(ptbin))

    h_JetHT.Add(h_NonQCD, -1)

    h = h_JetHT.Clone()
    # h = h_QCD.Clone()

    g = r.TGraph(h.GetNbinsX())
    y = r.TGraph(h.GetNbinsX())
    for idx in range(1, h.GetNbinsX()+2):
        eff = h.Integral(idx, h.GetNbinsX()+1) / h.Integral()
        # print(h.GetBinContent(idx))
        cutval = h.GetBinLowEdge(idx)
        g.SetPoint(idx, eff, cutval)
        y.SetPoint(idx, cutval, eff)
        # print("{}: {}".format(cutval, eff))
    print g.Eval(0.14), y.Eval(g.Eval(0.14))
    # print g.Eval(0.003375), y.Eval(g.Eval(0.003375))

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
    VVVidx = -1
    for line in lines:
        if "Bin#" in line:
            for index, ls in enumerate(line.split()):
                if "QCD" in ls:
                    QCDidx = (index - 3) * 2 + 3
                if "VVV" in ls:
                    VVVidx = (index - 3) * 2 + 3
                if "Total" in ls:
                    Totalidx = (index - 3) * 2 + 3
                if "JetHT" in ls:
                    Dataidx = (index - 3) * 2 + 3
        if "Bin1" in line:
            QCD = float(line.split()[QCDidx])
            QCDerr = float(line.split()[QCDidx+2])
            VVV = float(line.split()[VVVidx])
            VVVerr = float(line.split()[VVVidx+2])
            Total = float(line.split()[Totalidx])
            Totalerr = float(line.split()[Totalidx+2])
            Data = float(line.split()[Dataidx])
            Dataerr = float(line.split()[Dataidx+2])
            NonQCD = Total - QCD
            NonQCDerr = math.sqrt(Totalerr**2 - QCDerr**2)
            qcd = E(QCD, QCDerr)
            total = E(Total, Totalerr)
            nonqcd = E(NonQCD, NonQCDerr)
            vvv = E(VVV, VVVerr)
            data = E(Data, Dataerr)
            dataqcd = data - nonqcd
            datafail = dataqcd
            mcfail = qcd
            sigfail = vvv
        if "Bin2" in line:
            QCD = float(line.split()[QCDidx])
            QCDerr = float(line.split()[QCDidx+2])
            VVV = float(line.split()[VVVidx])
            VVVerr = float(line.split()[VVVidx+2])
            Total = float(line.split()[Totalidx])
            Totalerr = float(line.split()[Totalidx+2])
            Data = float(line.split()[Dataidx])
            Dataerr = float(line.split()[Dataidx+2])
            NonQCD = Total - QCD
            NonQCDerr = math.sqrt(Totalerr**2 - QCDerr**2)
            qcd = E(QCD, QCDerr)
            vvv = E(VVV, VVVerr)
            total = E(Total, Totalerr)
            nonqcd = E(NonQCD, NonQCDerr)
            data = E(Data, Dataerr)
            dataqcd = data - nonqcd
            datapass = dataqcd
            mcpass = qcd
            sigpass = vvv
    dataall = datapass + datafail
    mcall = mcpass + mcfail
    dataeff = datapass / dataall
    mceff = mcpass / mcall
    dataineff = datafail / dataall
    mcineff = mcfail / mcall
    sigall = sigpass + sigfail
    sigeff = sigpass / sigall
    sigineff = sigfail / sigall
    # print(dataeff)
    # print(mceff)
    sf = dataeff / mceff
    sfineff = dataineff / mcineff
    if printineff:
        print("            if ({}) return {}; // dataQCD = {}, sig = {}".format(selection, sfineff.val, dataineff, sigineff))
    else:
        print("            if ({}) return {}; // dataQCD = {}, sig = {}".format(selection, sf.val, dataeff, sigeff))
    # return sf, sfineff


ptbins = ["200250", "250300", "300350", "350400", "400450", "450500", "500550", "550600", "600650", "650700", "700750", "750800", "800850", "8501000", "1000Inf",]

for year in ["2006", "2016", "2017", "2018"]:
    print year
    for ptbin in ptbins:
        getROC(year, ptbin)




# years = ["2006", "2016", "2017", "2018"]

# for year in years:
#     print("    //_______________________________________________________________________________")
#     print("    auto VMD0p4_SF_{} = [&](float pt)".format(year))
#     print("        {")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1200250__V1SF.txt".format(year), "pt >= 200 and pt < 250")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1250300__V1SF.txt".format(year), "pt >= 250 and pt < 300")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1300350__V1SF.txt".format(year), "pt >= 300 and pt < 350")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1350400__V1SF.txt".format(year), "pt >= 350 and pt < 400")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1400450__V1SF.txt".format(year), "pt >= 400 and pt < 450")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1450500__V1SF.txt".format(year), "pt >= 450 and pt < 500")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1500550__V1SF.txt".format(year), "pt >= 500 and pt < 550")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1550600__V1SF.txt".format(year), "pt >= 550 and pt < 600")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1600Inf__V1SF.txt".format(year), "pt >= 600             ")
#     print("            else                        return 1.00000000000;")
#     print("        };")

#     print("    //_______________________________________________________________________________")
#     print("    auto VMD0p8_SF_{} = [&](float pt)".format(year))
#     print("        {")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1200250__V1SF0p8.txt".format(year), "pt >= 200 and pt < 250")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1250300__V1SF0p8.txt".format(year), "pt >= 250 and pt < 300")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1300350__V1SF0p8.txt".format(year), "pt >= 300 and pt < 350")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1350400__V1SF0p8.txt".format(year), "pt >= 350 and pt < 400")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1400450__V1SF0p8.txt".format(year), "pt >= 400 and pt < 450")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1450500__V1SF0p8.txt".format(year), "pt >= 450 and pt < 500")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1500550__V1SF0p8.txt".format(year), "pt >= 500 and pt < 550")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1550600__V1SF0p8.txt".format(year), "pt >= 550 and pt < 600")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1600Inf__V1SF0p8.txt".format(year), "pt >= 600             ")
#     print("            else                        return 1.00000000000;")
#     print("        };")

#     print("    //_______________________________________________________________________________")
#     print("    auto VMD0p6_SF_{} = [&](float pt)".format(year))
#     print("        {")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1200250__V1SF0p6.txt".format(year), "pt >= 200 and pt < 250")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1250300__V1SF0p6.txt".format(year), "pt >= 250 and pt < 300")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1300350__V1SF0p6.txt".format(year), "pt >= 300 and pt < 350")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1350400__V1SF0p6.txt".format(year), "pt >= 350 and pt < 400")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1400450__V1SF0p6.txt".format(year), "pt >= 400 and pt < 450")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1450500__V1SF0p6.txt".format(year), "pt >= 450 and pt < 500")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1500550__V1SF0p6.txt".format(year), "pt >= 500 and pt < 550")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1550600__V1SF0p6.txt".format(year), "pt >= 550 and pt < 600")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1600Inf__V1SF0p6.txt".format(year), "pt >= 600             ")
#     print("            else                        return 1.00000000000;")
#     print("        };")

#     print("    //_______________________________________________________________________________")
#     print("    auto VMD0p9_SF_{} = [&](float pt)".format(year))
#     print("        {")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1200250__V1SF0p9.txt".format(year), "pt >= 200 and pt < 250")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1250300__V1SF0p9.txt".format(year), "pt >= 250 and pt < 300")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1300350__V1SF0p9.txt".format(year), "pt >= 300 and pt < 350")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1350400__V1SF0p9.txt".format(year), "pt >= 350 and pt < 400")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1400450__V1SF0p9.txt".format(year), "pt >= 400 and pt < 450")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1450500__V1SF0p9.txt".format(year), "pt >= 450 and pt < 500")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1500550__V1SF0p9.txt".format(year), "pt >= 500 and pt < 550")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1550600__V1SF0p9.txt".format(year), "pt >= 550 and pt < 600")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1600Inf__V1SF0p9.txt".format(year), "pt >= 600             ")
#     print("            else                        return 1.00000000000;")
#     print("        };")

#     print("    //_______________________________________________________________________________")
#     print("    auto VMD0p4_ineffSF_{} = [&](float pt)".format(year))
#     print("        {")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1200250__V1SF.txt".format(year), "pt >= 200 and pt < 250", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1250300__V1SF.txt".format(year), "pt >= 250 and pt < 300", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1300350__V1SF.txt".format(year), "pt >= 300 and pt < 350", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1350400__V1SF.txt".format(year), "pt >= 350 and pt < 400", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1400450__V1SF.txt".format(year), "pt >= 400 and pt < 450", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1450500__V1SF.txt".format(year), "pt >= 450 and pt < 500", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1500550__V1SF.txt".format(year), "pt >= 500 and pt < 550", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1550600__V1SF.txt".format(year), "pt >= 550 and pt < 600", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1600Inf__V1SF.txt".format(year), "pt >= 600             ", printineff=True)
#     print("            else                        return 1.00000000000;")
#     print("        };")

#     print("    //_______________________________________________________________________________")
#     print("    auto VMD0p8_ineffSF_{} = [&](float pt)".format(year))
#     print("        {")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1200250__V1SF0p8.txt".format(year), "pt >= 200 and pt < 250", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1250300__V1SF0p8.txt".format(year), "pt >= 250 and pt < 300", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1300350__V1SF0p8.txt".format(year), "pt >= 300 and pt < 350", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1350400__V1SF0p8.txt".format(year), "pt >= 350 and pt < 400", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1400450__V1SF0p8.txt".format(year), "pt >= 400 and pt < 450", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1450500__V1SF0p8.txt".format(year), "pt >= 450 and pt < 500", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1500550__V1SF0p8.txt".format(year), "pt >= 500 and pt < 550", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1550600__V1SF0p8.txt".format(year), "pt >= 550 and pt < 600", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1600Inf__V1SF0p8.txt".format(year), "pt >= 600             ", printineff=True)
#     print("            else                        return 1.00000000000;")
#     print("        };")

#     print("    //_______________________________________________________________________________")
#     print("    auto VMD0p6_ineffSF_{} = [&](float pt)".format(year))
#     print("        {")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1200250__V1SF0p6.txt".format(year), "pt >= 200 and pt < 250", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1250300__V1SF0p6.txt".format(year), "pt >= 250 and pt < 300", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1300350__V1SF0p6.txt".format(year), "pt >= 300 and pt < 350", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1350400__V1SF0p6.txt".format(year), "pt >= 350 and pt < 400", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1400450__V1SF0p6.txt".format(year), "pt >= 400 and pt < 450", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1450500__V1SF0p6.txt".format(year), "pt >= 450 and pt < 500", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1500550__V1SF0p6.txt".format(year), "pt >= 500 and pt < 550", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1550600__V1SF0p6.txt".format(year), "pt >= 550 and pt < 600", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1600Inf__V1SF0p6.txt".format(year), "pt >= 600             ", printineff=True)
#     print("            else                        return 1.00000000000;")
#     print("        };")

#     print("    //_______________________________________________________________________________")
#     print("    auto VMD0p9_ineffSF_{} = [&](float pt)".format(year))
#     print("        {")
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1200250__V1SF0p9.txt".format(year), "pt >= 200 and pt < 250", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1250300__V1SF0p9.txt".format(year), "pt >= 250 and pt < 300", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1300350__V1SF0p9.txt".format(year), "pt >= 300 and pt < 350", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1350400__V1SF0p9.txt".format(year), "pt >= 350 and pt < 400", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1400450__V1SF0p9.txt".format(year), "pt >= 400 and pt < 450", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1450500__V1SF0p9.txt".format(year), "pt >= 450 and pt < 500", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1500550__V1SF0p9.txt".format(year), "pt >= 500 and pt < 550", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1550600__V1SF0p9.txt".format(year), "pt >= 550 and pt < 600", printineff=True)
#     getSF("plots/{}/plots_d8_SF/NFJEq2Pt1600Inf__V1SF0p9.txt".format(year), "pt >= 600             ", printineff=True)
#     print("            else                        return 1.00000000000;")
#     print("        };")
