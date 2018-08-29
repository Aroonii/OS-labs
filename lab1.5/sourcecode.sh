#!/bin/bash

directory=$1
echo $directory

for dir in $(find $directory -type d ); do echo ".h files"; ls $dir/*.h; done
for dir in $(find $directory -type d ); do echo ".c files"; ls $dir/*.c; done

