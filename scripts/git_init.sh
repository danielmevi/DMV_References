#!/bin/bash

if [[ $# -ne 1 ]];
then
    echo "ERROR: git_init takes only one argument."
    echo "INFO: ./git_init.sh <ssh_git_repo_path>"
    exit 1
fi


git init
git remote add origin $1
git config branch.master.remote origin
git config branch.master.merge refs/heads/master
git config --global user.name dmedin2
git config --global user.email daniel.medina.villegas@intel.com
git config --global http.proxy http://proxy-chain.intel.com:911
git pull $1 master

