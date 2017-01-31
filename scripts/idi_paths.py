"""
" Paths.py is a script that parse current IDI PWD path, and return the requested path fromm its repository
"
" CMI:
"    idi_paths.pu <src, simics, core, uncore, testmodel, unittest, targets, regression>
"
" 
" Known Bugs: 
"     cdcore and cduncore sometimes get corrupted with each other
"
"
"""

import argparse
import sys
import os

idi_repo = { "root" : "/..",
             "idi" : "",
             "src" : "/src",
             "include" : "/include",
             "hw" : "/hw",
             "simics" : "/simics",
             "core" : "/simics/IDICoreDevice",
             "uncore" : "/simics/IDIUncoreDevice",
             "base" : "/simics/IDIBaseDevice",
             "regression" : "/regression",
             "testmodel" : "/regression/test_model",
             "tests" : "/regression/test_model/tests",
             "unittests" : "/regression/test_model/unit_tests",
             "cfg" : "/regression/test_model/cfg",
             "targets" : "/regression/test_model/targets"}

def run(req_path):

    # Open output file which will hold the final path for linux usage
    home = os.environ['HOME']
    ofile = home + "/.repo_path"
    f = open(ofile, 'w')
  
    pwd = os.getcwd()

    repo  = pwd.split("/")
    if "idi" in repo:
        idi_version = "idi"
    elif "idi_v1" in repo:
        idi_version = "idi_v1"
    else:
        f.write("")
        print("ERROR: Not under IDI repo directory (idi or idi_v1)...")
        sys.exit(0)

    root = ''
    for idi_folder in repo:
        if idi_folder == idi_version:
            break
        else:  
            root = root +  "/" + idi_folder

    path =  root + '/' + idi_version + idi_repo[req_path]

    f.write(path)
    f.close


def parse(path):

    match = [i for i in idi_repo if path in i]

    if not match:
        print("ERROR: Not a valid idi repo path...")
        sys.exit(0)
    
    return match

    

def main():
    global args
    parser = argparse.ArgumentParser(description='Get requested path fromm IDI repo directory')
    parser.add_argument("--req_path", type=str,
                        help=('Requested path to return from idi repo directory\n'
                            + 'Options: idi, rsc, hw, include, core, uncore, base, regression'
                            + 'testmodel, unittest, test, targets'),
                        default='')
    
    args = parser.parse_args()
    if not args.req_path:
        print("ERROR: Missing --req_path argument...")
        sys.exit(0)

    req_path = parse(args.req_path)

    run(req_path[0])




if __name__=="__main__":
    main()
