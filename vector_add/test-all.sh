#!/bin/sh

echo ----- Start  $(date) > test-all.txt
for i in 0S 1S 2S 3S 4S 0D 1D 2D 3D 4D
do 
    echo ----- $i ----- >> test-all.txt
    ./bin/vector_add_$i $1 $2 >> test-all.txt
done
echo ----- Finish  $(date) >> test-all.txt
