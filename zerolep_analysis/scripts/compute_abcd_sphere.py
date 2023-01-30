#!/bin/env python

import ROOT as r
import math
import sys

year = sys.argv[1] if len(sys.argv) > 1 else "all"

#______________________________________________________________________________________________________________________
def move_overflow(hists):
    def func(hist):
        of_bc = hist.GetBinContent(hist.GetNbinsX()+1)
        of_be = hist.GetBinError(hist.GetNbinsX()+1)
        lb_bc = hist.GetBinContent(hist.GetNbinsX())
        lb_be = hist.GetBinError(hist.GetNbinsX())
        lb_bc_new = lb_bc + of_bc
        lb_be_new = math.sqrt(lb_be**2 + of_be**2)
        hist.SetBinContent(hist.GetNbinsX(), lb_bc_new)
        hist.SetBinError(hist.GetNbinsX(), lb_be_new)
        hist.SetBinContent(hist.GetNbinsX()+1, 0)
        hist.SetBinError(hist.GetNbinsX()+1, 0)
    if isinstance(hists, list):
        for hist in hists:
            func(hist)
    else:
        func(hists)
    return hists

def doABCD(bins, fopt="recreate", target="Close"):
    f_NonQCD = r.TFile("hadds/{}/NonQCD.root".format(year))
    f_QCD = r.TFile("hadds/{}/QCD.root".format(year))
    f_JetHT = r.TFile("hadds/{}/JetHT.root".format(year))

    # bins = "SR3"
    anti = "Fail"
    # anti = "NotPass"

    h_A_NonQCD = f_NonQCD.Get("NFJGeq3{}PassWP__HT_FJ{}".format(target, bins))
    h_B_NonQCD = f_NonQCD.Get("NFJGeq3OpenPassWP__HT_FJ{}".format(bins))
    h_C_NonQCD = f_NonQCD.Get("NFJGeq3{}{}WP__HT_FJ{}".format(target, anti, bins))
    h_D_NonQCD = f_NonQCD.Get("NFJGeq3Open{}WP__HT_FJ{}".format(anti, bins))

    h_A_QCD = f_QCD.Get("NFJGeq3{}PassWP__HT_FJ{}".format(target, bins))
    h_B_QCD = f_QCD.Get("NFJGeq3OpenPassWP__HT_FJ{}".format(bins))
    h_C_QCD = f_QCD.Get("NFJGeq3{}{}WP__HT_FJ{}".format(target, anti, bins))
    h_D_QCD = f_QCD.Get("NFJGeq3Open{}WP__HT_FJ{}".format(anti, bins))

    h_A_JetHT = f_JetHT.Get("NFJGeq3{}PassWP__HT_FJ{}".format(target, bins))
    h_B_JetHT = f_JetHT.Get("NFJGeq3OpenPassWP__HT_FJ{}".format(bins))
    h_C_JetHT = f_JetHT.Get("NFJGeq3{}{}WP__HT_FJ{}".format(target, anti, bins))
    h_D_JetHT = f_JetHT.Get("NFJGeq3Open{}WP__HT_FJ{}".format(anti, bins))

    # move_overflow(h_A_NonQCD)
    # move_overflow(h_B_NonQCD)
    # move_overflow(h_C_NonQCD)
    # move_overflow(h_D_NonQCD)

    # move_overflow(h_A_QCD)
    # move_overflow(h_B_QCD)
    # move_overflow(h_C_QCD)
    # move_overflow(h_D_QCD)

    # move_overflow(h_A_JetHT)
    # move_overflow(h_B_JetHT)
    # move_overflow(h_C_JetHT)
    # move_overflow(h_D_JetHT)

    # h_A_JetHT.Print("all")
    # h_B_JetHT.Print("all")
    # h_C_JetHT.Print("all")
    # h_D_JetHT.Print("all")

    # h_A_NonQCD.Print("all")
    # h_B_NonQCD.Print("all")
    # h_C_NonQCD.Print("all")
    # h_D_NonQCD.Print("all")

    h_A_JetHT.Add(h_A_NonQCD, -1);
    h_B_JetHT.Add(h_B_NonQCD, -1);
    h_C_JetHT.Add(h_C_NonQCD, -1);
    h_D_JetHT.Add(h_D_NonQCD, -1);

    # h_A_JetHT.Print("all")
    # h_B_JetHT.Print("all")
    # h_C_JetHT.Print("all")
    # h_D_JetHT.Print("all")

    h_estA_JetHT = h_C_JetHT.Clone()
    h_estA_JetHT.Divide(h_D_JetHT)
    h_estA_JetHT.Multiply(h_B_JetHT)
    h_estA_JetHT.Print("all")

    h_estA_QCD = h_C_QCD.Clone()
    h_estA_QCD.Divide(h_D_QCD)
    h_estA_QCD.Multiply(h_B_QCD)

    # h_A_QCD.Print("all")
    # h_estA_QCD.Print("all")

    # h_closure_QCD = h_estA_QCD.Clone()
    # h_closure_QCD.Divide(h_A_QCD)
    # h_closure_QCD.Print("all")

    f_QCDDD = r.TFile("hadds/{}/QCDDD.root".format(year), fopt)
    h_estA_JetHT.SetDirectory(f_QCDDD)
    h_estA_JetHT.SetName("NFJGeq3{}PassWP__HT_FJ{}".format(target, bins))
    h_estA_JetHT.Write()

    f_QCDClosure = r.TFile("hadds/{}/QCDClosure.root".format(year), fopt)
    h_estA_QCD.SetDirectory(f_QCDClosure)
    h_estA_QCD.SetName("NFJGeq3{}PassWP__HT_FJ{}".format(target, bins))
    h_estA_QCD.Write()
    h_estA_QCD.Print("all")

    f_QCDDD.Close()
    f_QCDClosure.Close()

doABCD("SR3", "recreate")
doABCD("SR3", "update", "Shell")

# def doABCDEF():
#     f_NonQCD = r.TFile("hadds/{}/NonQCD.root".format(year))
#     f_QCD = r.TFile("hadds/{}/QCD.root".format(year))
#     f_JetHT = r.TFile("hadds/{}/JetHT.root".format(year))

#     bins = "SR3"
#     anti = "Fail"
#     # anti = "NotPass"

#     h_A_NonQCD = f_NonQCD.Get("NFJGeq3ClosePass8__HT_FJ{}".format(bins))
#     h_B_NonQCD = f_NonQCD.Get("NFJGeq3OpenPass8__HT_FJ{}".format(bins))
#     h_C_NonQCD = f_NonQCD.Get("NFJGeq3Close{}8Pass4__HT_FJ{}".format(anti, bins))
#     h_D_NonQCD = f_NonQCD.Get("NFJGeq3Open{}8Pass4__HT_FJ{}".format(anti, bins))
#     h_E_NonQCD = f_NonQCD.Get("NFJGeq3Close{}8__HT_FJ{}".format(anti, bins))
#     h_F_NonQCD = f_NonQCD.Get("NFJGeq3Open{}8__HT_FJ{}".format(anti, bins))

#     h_A_QCD = f_QCD.Get("NFJGeq3ClosePass8__HT_FJ{}".format(bins))
#     h_B_QCD = f_QCD.Get("NFJGeq3OpenPass8__HT_FJ{}".format(bins))
#     h_C_QCD = f_QCD.Get("NFJGeq3Close{}8Pass4__HT_FJ{}".format(anti, bins))
#     h_D_QCD = f_QCD.Get("NFJGeq3Open{}8Pass4__HT_FJ{}".format(anti, bins))
#     h_E_QCD = f_QCD.Get("NFJGeq3Close{}8__HT_FJ{}".format(anti, bins))
#     h_F_QCD = f_QCD.Get("NFJGeq3Open{}8__HT_FJ{}".format(anti, bins))

#     h_A_JetHT = f_JetHT.Get("NFJGeq3ClosePass8__HT_FJ{}".format(bins))
#     h_B_JetHT = f_JetHT.Get("NFJGeq3OpenPass8__HT_FJ{}".format(bins))
#     h_C_JetHT = f_JetHT.Get("NFJGeq3Close{}8Pass4__HT_FJ{}".format(anti, bins))
#     h_D_JetHT = f_JetHT.Get("NFJGeq3Open{}8Pass4__HT_FJ{}".format(anti, bins))
#     h_E_JetHT = f_JetHT.Get("NFJGeq3Close{}8__HT_FJ{}".format(anti, bins))
#     h_F_JetHT = f_JetHT.Get("NFJGeq3Open{}8__HT_FJ{}".format(anti, bins))

#     move_overflow(h_A_NonQCD)
#     move_overflow(h_B_NonQCD)
#     move_overflow(h_C_NonQCD)
#     move_overflow(h_D_NonQCD)
#     move_overflow(h_E_NonQCD)
#     move_overflow(h_F_NonQCD)

#     move_overflow(h_A_QCD)
#     move_overflow(h_B_QCD)
#     move_overflow(h_C_QCD)
#     move_overflow(h_D_QCD)
#     move_overflow(h_E_QCD)
#     move_overflow(h_F_QCD)

#     move_overflow(h_A_JetHT)
#     move_overflow(h_B_JetHT)
#     move_overflow(h_C_JetHT)
#     move_overflow(h_D_JetHT)
#     move_overflow(h_E_JetHT)
#     move_overflow(h_F_JetHT)

#     # h_A_JetHT.Print("all")
#     # h_B_JetHT.Print("all")
#     # h_C_JetHT.Print("all")
#     # h_D_JetHT.Print("all")

#     # h_A_NonQCD.Print("all")
#     # h_B_NonQCD.Print("all")
#     # h_C_NonQCD.Print("all")
#     # h_D_NonQCD.Print("all")

#     h_A_JetHT.Add(h_A_NonQCD, -1);
#     h_B_JetHT.Add(h_B_NonQCD, -1);
#     h_C_JetHT.Add(h_C_NonQCD, -1);
#     h_D_JetHT.Add(h_D_NonQCD, -1);
#     h_E_JetHT.Add(h_E_NonQCD, -1);
#     h_F_JetHT.Add(h_F_NonQCD, -1);

#     # h_A_JetHT.Print("all")
#     # h_B_JetHT.Print("all")
#     # h_C_JetHT.Print("all")
#     # h_D_JetHT.Print("all")

#     h_estA_JetHT = h_C_JetHT.Clone()
#     h_estA_JetHT.Divide(h_D_JetHT)
#     h_estA_JetHT.Multiply(h_B_JetHT)

#     h_estC_JetHT = h_E_JetHT.Clone()
#     h_estC_JetHT.Divide(h_F_JetHT)
#     h_estC_JetHT.Multiply(h_D_JetHT)
#     h_estC_JetHT.Print("all")

#     h_estA_QCD = h_C_QCD.Clone()
#     h_estA_QCD.Divide(h_D_QCD)
#     h_estA_QCD.Multiply(h_B_QCD)

#     h_estC_QCD = h_E_QCD.Clone()
#     h_estC_QCD.Divide(h_F_QCD)
#     h_estC_QCD.Multiply(h_D_QCD)

#     # h_A_QCD.Print("all")
#     # h_estA_QCD.Print("all")

#     # h_closure_QCD = h_estA_QCD.Clone()
#     # h_closure_QCD.Divide(h_A_QCD)
#     # h_closure_QCD.Print("all")

#     f_QCDDD = r.TFile("hadds/{}/QCDDD.root".format(year), "update")
#     h_estC_JetHT.SetDirectory(f_QCDDD)
#     h_estC_JetHT.SetName("NFJGeq3CloseFail8Pass4__HT_FJ{}".format(bins))
#     h_estC_JetHT.Write()

#     f_QCDClosure = r.TFile("hadds/{}/QCDClosure.root".format(year), "update")
#     h_estC_QCD.SetDirectory(f_QCDClosure)
#     h_estC_QCD.SetName("NFJGeq3CloseFail8Pass4__HT_FJ{}".format(bins))
#     h_estC_QCD.Write()

# doABCDEF()
