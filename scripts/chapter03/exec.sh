#!/bin/bash

gcc -o open open.c
./open | tee output.log
rm -f open