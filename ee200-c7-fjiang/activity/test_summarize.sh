#! /bin/bash

# Put whatever tests you want here, e.g., 
./summarize 3d
./log lift 100 "feeling strong"
./log walk 10 "home sweet home"
./summarize 1w
./summarize abc
./summarize 10k
./summarize 
rm -f activity.tsv
./summarize 1d
./log jog 20 "relaxing"

