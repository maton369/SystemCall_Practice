#!/bin/bash

# gcc -o open open.c
# ./open | tee output.log
# rm -f open

# gcc -o openat openat.c
# ./openat | tee output.log
# rm -f openat

# gcc -o read read.c
# ./read | tee output.log
# rm -f read

gcc -o write write.c
./write | tee output.log
rm -f write