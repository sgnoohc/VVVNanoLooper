#!/bin/env python
#
#  .
# ..: Philip Chang, University of Florida
#

# Takes existing scale1fbs.txt and list of samples cross match to produce a new xsec table

import sys

from difflib import SequenceMatcher

def similar(a, b):
    return SequenceMatcher(None, a, b).ratio()

scale1fb_file_paths = ["MCXsec.txt", "../NanoTools/NanoCORE/datasetinfo/scale1fbs_nanoaod.txt", "../NanoTools/NanoCORE/datasetinfo/scale1fbs.txt"]
sample_list_file_path = "samples.txt"

xsec = {}
for scale1fb_file_path in scale1fb_file_paths:
    scale1fb_file = open(scale1fb_file_path)
    scale1fb_lines = scale1fb_file.readlines()
    if "MINIAODSIM" in "".join(scale1fb_lines):
        thisxsec = dict([ [x.split()[0], x.split()[4]] for x in scale1fb_lines if x[0] != "#" and "MINIAOD" in x ])
    else:
        thisxsec = dict([ x.split() for x in scale1fb_lines if x[0] != "#" ])
    xsec.update(thisxsec)
# for key in xsec.keys():
#     print(key, xsec[key])
# sys.exit()

sample_list_file = open(sample_list_file_path)
sample_list = [ x.strip() for x in sample_list_file.readlines() ]
# print(sample_list)

def strip_common_words(a):
    a = a.replace("13TeV","")
    a = a.replace("TuneCP5","")
    a = a.replace("TuneCUETP8M1","")
    a = a.replace("pythia8","")
    a = a.replace("madspin","")
    a = a.replace("ckm","")
    a = a.replace("NLO","")
    a = a.replace("4f","")
    a = a.replace("4F","")
    a = a.replace("PSWeights","")
    a = a.replace("madgraphMLM","madgraph")
    a = a.replace("amcatnloFXFX","amcatnlo")
    a = a.replace("jhugen727","")
    a = a.replace("jhugen714","")
    a = a.replace("M-125","M125")
    a = a.replace("-","")
    a = a.replace("_","")
    a = a.lower()
    return a

for sample in sample_list:
    maxsim = -999;
    maxsample = ""
    verbose = False
    # if sample == "/ZZTo4L_TuneCP5_13TeV_powheg_pythia8/RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v2/NANOAODSIM":
    #     verbose = True
    # if not verbose:
    #     continue
    for s in xsec.keys():
        # Compare the sample process name only
        aa = strip_common_words(s.split('/')[1])
        bb = strip_common_words(sample.split('/')[1])
        thissim = similar(aa, bb)
        # if "ZZTo4L" in s:
        #     print(aa, bb, thissim)
        if thissim > maxsim:
            maxsim = thissim
            maxsample = s
    # if the first 10 letters are not same, flag it
    issame = False
    aa = strip_common_words(maxsample.split('/')[1])
    bb = strip_common_words(sample.split('/')[1])
    if aa == bb or maxsim == 1:
        issame = True

    print("{:200s} {:30s} {:10s} {:200s}".format(sample, xsec[maxsample], str(issame), maxsample))

    # if not issame:
    #     break


#     sample
#     print(issame, sample[:40], maxsample[:40], maxsim)
