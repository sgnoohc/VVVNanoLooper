import os
import argparse
import subprocess
import sys

eft_to_run = {
    "WWW": { "42": "EFT__FM0_p2", "90":  "EFT__FT0_p2", "6": "EFT__FS0_p2"},
#    "WWZ": { "42": "EFT__FM0_p2", "138": "EFT__FT0_p2", "6": "EFT__FS0_p2"},
#    "WZZ": { "42": "EFT__FM0_p2", "138": "EFT__FT0_p2", "6": "EFT__FS0_p2"},
#    "ZZZ": { "42": "EFT__FM0_p2", "138": "EFT__FT0_p2", "6": "EFT__FS0_p2"},
}

eft_to_run = {}

if __name__ == "__main__":

    parser = argparse.ArgumentParser(description="hadd output files from condor jobs")
    parser.add_argument('-i' , '--inputPath'    , dest='inPath'  , help='top level directory with all samples'   , type=str,  required=True   )
    parser.add_argument('-o' , '--outputPath'   , dest='outPath' , help='output directory'                       , type=str, required=True   )
    # Argument parser
    args = parser.parse_args()

if not os.path.exists(args.outPath):
    os.makedirs(args.outPath)


to_run = os.listdir(args.inPath)

for f in to_run:
    out_name = f.split("/")[-1]
    if ".root" not in out_name: continue
    print "RUNNING ", out_name
    if out_name.strip(".root") not in eft_to_run:
    #    continue
        subprocess.call(["./doVVVAnalysis", "--input", args.inPath+f, "--tree", "t", "--mode", "8", "-V", "--output", out_name] )
        subprocess.call(["mv", out_name, args.outPath])
    else:
        for idx in eft_to_run[out_name.strip(".root")]:
            out_name = f.split("/")[-1]
            out_name = out_name.strip(".root") + "_" + eft_to_run[out_name.strip(".root")][idx] + ".root"
            print out_name
            subprocess.call(["./doVVVAnalysis", "--input", args.inPath+f, "--tree", "t", "--mode", "8", "-V", "--output", out_name, "-e", idx] )
            subprocess.call(["mv", out_name, args.outPath])


