#!/bin/env python

# Parsing V1SF histogram for computing SF

import sys
from errors import E
import math

def getSF(fname):
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
    return sf, sfineff

print(getSF("plots/plots_d8_SF/NFJEq2Pt1200250__V1SF.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1250300__V1SF.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1300350__V1SF.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1350400__V1SF.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1400450__V1SF.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1450500__V1SF.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1500550__V1SF.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1550600__V1SF.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1600Inf__V1SF.txt"))

print(getSF("plots/plots_d8_SF/NFJEq2Pt1200250__V1SF0p8.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1250300__V1SF0p8.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1300350__V1SF0p8.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1350400__V1SF0p8.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1400450__V1SF0p8.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1450500__V1SF0p8.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1500550__V1SF0p8.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1550600__V1SF0p8.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1600Inf__V1SF0p8.txt"))

print(getSF("plots/plots_d8_SF/NFJEq2Pt1200250__V1SF0p6.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1250300__V1SF0p6.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1300350__V1SF0p6.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1350400__V1SF0p6.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1400450__V1SF0p6.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1450500__V1SF0p6.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1500550__V1SF0p6.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1550600__V1SF0p6.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1600Inf__V1SF0p6.txt"))

print(getSF("plots/plots_d8_SF/NFJEq2Pt1200250__V1SF0p9.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1250300__V1SF0p9.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1300350__V1SF0p9.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1350400__V1SF0p9.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1400450__V1SF0p9.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1450500__V1SF0p9.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1500550__V1SF0p9.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1550600__V1SF0p9.txt"))
print(getSF("plots/plots_d8_SF/NFJEq2Pt1600Inf__V1SF0p9.txt"))

