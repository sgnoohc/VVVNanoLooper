#!/bin/env python

import os

#skimversion = "v9"
#skimdir = "/home/users/phchang/work/vvv/WWZRun3NanoLooper/vvvtree/{skimversion}".format(skimversion=skimversion)

skimversion = "WWZ_4L"
skimdir = "/home/users/kdownham/Triboson/VVVNanoLooper/vvvtree/110422" 

#____________________________________________________________________________________________
def main():

    # Create mappign between "process group" -> "list of ROOT files"
    files = get_groupping()

    # Configuration of how to split the jobs for ZZ and WWZ
    ZZ_njobs = 9

    # Clear the text file that holds the command lines
    jobs_command_file = open(".jobs.txt", "w")

    # Print the command line jobs for entire Run 2
    for proc in proc_groups:
        inputs_allyear = []
        for year in years:
            inputs = ",".join(files[year][proc])
            inputs_allyear += files[year][proc]
            #------------------------------------------
            if proc == "ZZ":
                for i in xrange(ZZ_njobs):
                    jobs_command_file.write(get_command(proc, inputs, year, ZZ_njobs, i) + "\n")
            else:
                jobs_command_file.write(get_command(proc, inputs, year) + "\n")
        #------------------------------------------
        inputs_allyear = ",".join(inputs_allyear)
        if proc == "ZZ":
            for i in xrange(ZZ_njobs):
                jobs_command_file.write(get_command(proc, inputs_allyear, "Run2", ZZ_njobs, i) + "\n")
        else:
            jobs_command_file.write(get_command(proc, inputs_allyear, "Run2") + "\n")

    # Do for the data
    jobs_command_file.write(get_command("data", "\\\"{skimdir}/*Run2016*HIPM*.root\\\"".format(skimdir=skimdir), "2016APV") + "\n")
    jobs_command_file.write(get_command("data", "\\\"{skimdir}/*Run2016*-UL2016*.root\\\"".format(skimdir=skimdir), "2016") + "\n")
    jobs_command_file.write(get_command("data", "\\\"{skimdir}/*Run2017*.root\\\"".format(skimdir=skimdir), "2017") + "\n")
    jobs_command_file.write(get_command("data", "\\\"{skimdir}/*Run2018*.root\\\"".format(skimdir=skimdir), "2018") + "\n")
    jobs_command_file.write(get_command("data", "\\\"{skimdir}/*Run201*.root\\\"".format(skimdir=skimdir), "Run2") + "\n")

    jobs_command_file.close()

    # Run the jobs!
    os.system("xargs.sh .jobs.txt")

    # Hadd ZZ and WWZ's output histograms that were ran in chunks
    print("")
    print("Hadding ZZ and WWZ output rootfiles ......")
    for year in years + ["Run2"]:
        os.system("hadd -f outputs/{0}/ZZ.root outputs/{0}/ZZ_*.root > outputs/{0}/ZZ.log 2>&1".format(year))
        os.system("hadd -f outputs/{0}/WWZ.root outputs/{0}/ZHWWZ.root outputs/{0}/NonResWWZ.root > outputs/{0}/WWZ.log 2>&1".format(year))
        os.system("hadd -f outputs/{0}/NonWWZ.root outputs/{0}/WWW.root outputs/{0}/WZZ.root outputs/{0}/ZZZ.root > outputs/{0}/NonWWZ.log 2>&1".format(year))

    print("Done!")


#____________________________________________________________________________________________
# Get Command
def get_command(proc, inputs, year, njobs=0, idx=0):
    if njobs > 0:
        rtn_str = "rm -f outputs/{}/{}_{}.root;".format(year, proc, idx)
    else:
        rtn_str = "rm -f outputs/{}/{}.root;".format(year, proc)
    rtn_str += "mkdir -p outputs/{};".format(year)
    rtn_str += "./doAnalysis -i {} ".format(inputs)
    if njobs > 0:
        rtn_str += "-j {} -I {} ".format(njobs, idx)
        rtn_str += "-t t -o outputs/{}/{}_{}.root > outputs/{}/{}_{}.log 2>&1".format(year, proc, idx, year, proc, idx)
    else:
        rtn_str += "-t t -o outputs/{}/{}.root > outputs/{}/{}.log 2>&1".format(year, proc, year, proc)
    return rtn_str

#____________________________________________________________________________________________
# Create mappign between "process group" -> "list of ROOT files"
def get_groupping():
    files = {}
    for year in years:
        files[year] = {}
        for proc_group in proc_groups:
            files[year][proc_group] = []

    # Loop over processes and put the corresponding root files in to proc_group lists
    for proc in process.keys():
        for year in years:
            key = proc+"_"+year
            #print(key)
            if "WWZ_4l_2016APV" == key: continue
            if "WWZ_4l_2016" == key: continue
            if "WWZ_4l_2017" == key: continue
            if "WWZ_4l_2018" == key: continue
	    print(key)
            # add to the list in the grouping
            files[year][process[proc]].append(mc[key].format(skimdir=skimdir, skimversion=skimversion))

    return files

#____________________________________________________________________________________________
# Different eras defined
years=["2016APV", "2016", "2017", "2018"]

#____________________________________________________________________________________________
# List of different process groups
#proc_groups = [ "WWW", "NonResWWZ", "ZHWWZ", "WZZ", "ZZZ", "Higgs", "ZZ", "TTZ", "WZ", "Other", ]
proc_groups = [ "NonResWWZ", "ZHWWZ", "ZZ", ]

#____________________________________________________________________________________________
# Process grouping definition
process={
"GGZHWW_WW2l"         : "ZHWWZ",
"ZHWW_4l"             : "ZHWWZ",
"WWZ_4l"              : "NonResWWZ",
"WWZ"                 : "NonResWWZ",
"ZZ4l"		      : "ZZ",
"ZZ2l2q"	      : "ZZ",
"ZZ2l2v"	      : "ZZ",
"GGZZ2e2m"	      : "ZZ",
"GGZZ2e2t"	      : "ZZ",
"GGZZ2m2t"	      : "ZZ",
"GGZZ4e"	      : "ZZ",
"GGZZ4m"	      : "ZZ",
"GGZZ4t"	      : "ZZ",
}

#____________________________________________________________________________________________
# Data root files and their short names
data={
# intentionally left empty for simplification
}

#____________________________________________________________________________________________
# MC root files and their short names
mc={
#
# Signal samples
#
"GGZHWW_WW2l_2016APV": "{skimdir}/GluGluZH_HToWWTo2L2Nu_M125_13TeV_powheg_pythia8_TuneCP5_PSweights_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11-v2_NANOAODSIM_{skimversion}.root",
"GGZHWW_WW2l_2016": "{skimdir}/GluGluZH_HToWWTo2L2Nu_M125_13TeV_powheg_pythia8_TuneCP5_PSweights_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17-v2_NANOAODSIM_{skimversion}.root",
"GGZHWW_WW2l_2017" : "{skimdir}/GluGluZH_HToWWTo2L2Nu_M125_13TeV_powheg_pythia8_TuneCP5_PSweights_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v2_NANOAODSIM_{skimversion}.root",
"GGZHWW_WW2l_2018" : "{skimdir}/GluGluZH_HToWWTo2L2Nu_M125_13TeV_powheg_pythia8_TuneCP5_PSweights_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v2_NANOAODSIM_{skimversion}.root",
"ZHWW_4l_2016APV" : "{skimdir}/HZJ_HToWWTo2L2Nu_ZTo2L_M-125_TuneCP5_13TeV-powheg-jhugen727-pythia8_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11-v2_NANOAODSIM_{skimversion}.root",
"ZHWW_4l_2016" : "{skimdir}/HZJ_HToWWTo2L2Nu_ZTo2L_M-125_TuneCP5_13TeV-powheg-jhugen727-pythia8_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17-v2_NANOAODSIM_{skimversion}.root",
"ZHWW_4l_2017" : "{skimdir}/HZJ_HToWWTo2L2Nu_ZTo2L_M-125_TuneCP5_13TeV-powheg-jhugen727-pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v2_NANOAODSIM_{skimversion}.root",
"ZHWW_4l_2018" : "{skimdir}/HZJ_HToWWTo2L2Nu_ZTo2L_M-125_TuneCP5_13TeV-powheg-jhugen727-pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v2_NANOAODSIM_{skimversion}.root",
# Does not seem to have been produced for APV why?
#"WWZ_4l_2016" : "{skimdir}/WWZJetsTo4L2Nu_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17-v2_NANOAODSIM_{skimversion}.root",
#"WWZ_4l_2017" : "{skimdir}/WWZJetsTo4L2Nu_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v2_NANOAODSIM_{skimversion}.root",
#"WWZ_4l_2018" : "{skimdir}/WWZJetsTo4L2Nu_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v2_NANOAODSIM_{skimversion}.root",
"WWZ_2016APV" : "{skimdir}/WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11-v1_NANOAODSIM_{skimversion}.root",
"WWZ_2016" : "{skimdir}/WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17-v1_NANOAODSIM_{skimversion}.root",
"WWZ_2017" : "{skimdir}/WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v1_NANOAODSIM_{skimversion}.root",
"WWZ_2018" : "{skimdir}/WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v1_NANOAODSIM_{skimversion}.root",
# "WWZ_ext_2016APV" : "{skimdir}/WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11_ext1-v1_NANOAODSIM_{skimversion}.root",
# "WWZ_ext_2016" : "{skimdir}/WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17_ext1-v1_NANOAODSIM_{skimversion}.root",
# "WWZ_ext_2017" : "{skimdir}/WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9_ext1-v2_NANOAODSIM_{skimversion}.root",
# "WWZ_ext_2018" : "{skimdir}/WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1_ext1-v2_NANOAODSIM_{skimversion}.root",
#
# ZZ background samples
#
# ZZ to 4L samples
"ZZ4l_2016APV" : "{skimdir}/ZZTo4L_TuneCP5_13TeV_powheg_pythia8_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11-v1_NANOAODSIM_{skimversion}.root",
"ZZ4l_2016" : "{skimdir}/ZZTo4L_TuneCP5_13TeV_powheg_pythia8_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17-v1_NANOAODSIM_{skimversion}.root",
"ZZ4l_2017" : "{skimdir}/ZZTo4L_TuneCP5_13TeV_powheg_pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v2_NANOAODSIM_{skimversion}.root",
"ZZ4l_2018" : "{skimdir}/ZZTo4L_TuneCP5_13TeV_powheg_pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v2_NANOAODSIM_{skimversion}.root",
#
# ZZ to 2L2Q samples
"ZZ2l2q_2016APV" : "{skimdir}/ZZTo2Q2L_mllmin4p0_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11-v1_NANOAODSIM_{skimversion}.root",
"ZZ2l2q_2016" : "{skimdir}/ZZTo2Q2L_mllmin4p0_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17-v1_NANOAODSIM_{skimversion}.root",
"ZZ2l2q_2017" : "{skimdir}/ZZTo2Q2L_mllmin4p0_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v1_NANOAODSIM_{skimversion}.root",
"ZZ2l2q_2018" : "{skimdir}/ZZTo2Q2L_mllmin4p0_TuneCP5_13TeV-amcatnloFXFX-pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v1_NANOAODSIM_{skimversion}.root",
#
# ZZ to 2L2Nu samples
"ZZ2l2v_2016APV" : "{skimdir}/ZZTo2L2Nu_TuneCP5_13TeV_powheg_pythia8_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11-v1_NANOAODSIM_{skimversion}.root",
"ZZ2l2v_2016" : "{skimdir}/ZZTo2L2Nu_TuneCP5_13TeV_powheg_pythia8_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17-v1_NANOAODSIM_{skimversion}.root",
"ZZ2l2v_2017" : "{skimdir}/ZZTo2L2Nu_TuneCP5_13TeV_powheg_pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v1_NANOAODSIM_{skimversion}.root",
"ZZ2l2v_2018" : "{skimdir}/ZZTo2L2Nu_TuneCP5_13TeV_powheg_pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v1_NANOAODSIM_{skimversion}.root",
#
# GluGluZZTo2e2mu
"GGZZ2e2m_2016APV" : "{skimdir}/GluGluToContinToZZTo2e2mu_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11-v2_NANOAODSIM_{skimversion}.root",
"GGZZ2e2m_2016" : "{skimdir}/GluGluToContinToZZTo2e2mu_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17-v1_NANOAODSIM_{skimversion}.root",
"GGZZ2e2m_2017" : "{skimdir}/GluGluToContinToZZTo2e2mu_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v2_NANOAODSIM_{skimversion}.root",
"GGZZ2e2m_2018" : "{skimdir}/GluGluToContinToZZTo2e2mu_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v2_NANOAODSIM_{skimversion}.root",
#
# GluGluZZTo2e2t
"GGZZ2e2t_2016APV" : "{skimdir}/GluGluToContinToZZTo2e2tau_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11-v2_NANOAODSIM_{skimversion}.root",
"GGZZ2e2t_2016" : "{skimdir}/GluGluToContinToZZTo2e2tau_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17-v1_NANOAODSIM_{skimversion}.root",
"GGZZ2e2t_2017" : "{skimdir}/GluGluToContinToZZTo2e2tau_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v2_NANOAODSIM_{skimversion}.root",
"GGZZ2e2t_2018" : "{skimdir}/GluGluToContinToZZTo2e2tau_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v2_NANOAODSIM_{skimversion}.root",
#
# GluGluZZTo2m2t
"GGZZ2m2t_2016APV" : "{skimdir}/GluGluToContinToZZTo2mu2tau_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11-v2_NANOAODSIM_{skimversion}.root",
"GGZZ2m2t_2016" : "{skimdir}/GluGluToContinToZZTo2mu2tau_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17-v1_NANOAODSIM_{skimversion}.root",
"GGZZ2m2t_2017" : "{skimdir}/GluGluToContinToZZTo2mu2tau_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v2_NANOAODSIM_{skimversion}.root",
"GGZZ2m2t_2018" : "{skimdir}/GluGluToContinToZZTo2mu2tau_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v2_NANOAODSIM_{skimversion}.root",
#
# GluGluZZTo4e
"GGZZ4e_2016APV" : "{skimdir}/GluGluToContinToZZTo4e_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11-v2_NANOAODSIM_{skimversion}.root",
"GGZZ4e_2016" : "{skimdir}/GluGluToContinToZZTo4e_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17-v2_NANOAODSIM_{skimversion}.root",
"GGZZ4e_2017" : "{skimdir}/GluGluToContinToZZTo4e_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v2_NANOAODSIM_{skimversion}.root",
"GGZZ4e_2018" : "{skimdir}/GluGluToContinToZZTo4e_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v2_NANOAODSIM_{skimversion}.root",
#
# GluGluZZTo4mu
"GGZZ4m_2016APV" : "{skimdir}/GluGluToContinToZZTo4mu_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11-v2_NANOAODSIM_{skimversion}.root",
"GGZZ4m_2016" : "{skimdir}/GluGluToContinToZZTo4mu_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17-v2_NANOAODSIM_{skimversion}.root",
"GGZZ4m_2017" : "{skimdir}/GluGluToContinToZZTo4mu_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v2_NANOAODSIM_{skimversion}.root",
"GGZZ4m_2018" : "{skimdir}/GluGluToContinToZZTo4mu_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v2_NANOAODSIM_{skimversion}.root",
#
# GluGluZZTo4tau
"GGZZ4t_2016APV" : "{skimdir}/GluGluToContinToZZTo4tau_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL16NanoAODAPVv9-106X_mcRun2_asymptotic_preVFP_v11-v2_NANOAODSIM_{skimversion}.root",
"GGZZ4t_2016" : "{skimdir}/GluGluToContinToZZTo4tau_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL16NanoAODv9-106X_mcRun2_asymptotic_v17-v1_NANOAODSIM_{skimversion}.root",
"GGZZ4t_2017" : "{skimdir}/GluGluToContinToZZTo4tau_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v2_NANOAODSIM_{skimversion}.root",
"GGZZ4t_2018" : "{skimdir}/GluGluToContinToZZTo4tau_TuneCP5_13TeV-mcfm701-pythia8_RunIISummer20UL18NanoAODv9-106X_upgrade2018_realistic_v16_L1v1-v2_NANOAODSIM_{skimversion}.root",
#
}

if __name__ == "__main__":

    main()
