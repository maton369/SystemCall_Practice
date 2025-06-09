#!/bin/bash

# gcc -o open open.c
# ./open | tee output.log
# rm -f open

gcc -o openat openat.c
./openat | tee output.log
rm -f openat