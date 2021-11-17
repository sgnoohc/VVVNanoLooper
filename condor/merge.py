import argparse
import os
import samples

if __name__ == "__main__":

    parser = argparse.ArgumentParser(description="merge jobs for VVV analysis")
    parser.add_argument('-d' , '--datamc'      , dest='datamc'    , help='data or mc'                ,                          default=False , action='store_true')
    parser.add_argument('-y' , '--year'        , dest='year'      , help='data year'                 , type=int, required=True                                     )
    parser.add_argument('-t' , '--tag'      , dest='tag'    , help='tag'                       , type=str,                default="test"                     )
    # Argument parser
    args = parser.parse_args()
    
    # Specify a dataset name and a short name for the output root file on nfs
    sample_map = samples.mc_2018 # See condor/samples.py
    if args.year==2017:
        sample_map = samples.mc_2017 # See condor/samples.py
    elif args.year==2016:
        sample_map = samples.mc_2016 # See condor/samples.py
    if args.datamc:
        sample_map = samples.data_2018 # See condor/samples.py
        if args.year==2017:
            sample_map = samples.data_2017 # See condor/samples.py
        elif args.year==2016:
            sample_map = samples.data_2016 # See condor/samples.py

    merged_dir = "/store/group/lpcvvv/{}/merged/VVV/{}/output/{}".format(os.getenv("USER"),args.tag,args.year)
    for ds,shortname in sample_map.items():
        input_dir = "/store/group/lpcvvv/{}/VVVAnalysis/{}/{}/{}_{}/".format(os.getenv("USER"),args.tag,args.year,ds.get_datasetname().replace("/", "_").lstrip("_"),args.tag)
	print shortname
	print input_dir
