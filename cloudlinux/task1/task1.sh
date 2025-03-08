#!/bin/bash

for file in `find ./ -name "*.c"`
do
    if [[ !(-e ${file}.orig) ]]
    then
        cp $file ${file}.orig
    fi
done