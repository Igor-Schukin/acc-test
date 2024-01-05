#!/bin/sh

echo ----- Start  $(date) > test-all.txt
for i in 0 1 2 3 4 0M 1M
do 
    echo ----- $i ----- >> test-all.txt
    ./bin/gauss_$i $1 $2 >> test-all.txt
done
echo ----- Finish  $(date) >> test-all.txt
