#! /bin/bash

# Put whatever tests you want here, e.g., 
printf "words, words, words" | ./wordcount
printf "one, two, three\nfour, five, six " | ./wordcount -l
printf "one, two, three\nfour, five, six " | ./wordcount -w
printf "one, two, three\nfour, five, six " | ./wordcount -c
./wordcount ../README.md
./wordcount ../README.md -l
./wordcount ../README.md -w
./wordcount ../README.md -c 
