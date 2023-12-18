#!/bin/sh

echo ----- Start  $(date) > test-all.txt
for i in R0 R1 R2 T0 T1 T2 M0 M1 M2
do 
    echo ----- $i ----- >> test-all.txt
    ./bin/vector_sum_$i $1 >> test-all.txt
done
echo ----- Finish  $(date) >> test-all.txt