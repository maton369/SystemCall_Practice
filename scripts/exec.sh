#!/bin/bash

# ps aux | tee output.log

# gcc -o fork fork.c
# ./fork | tee output.log

gcc -o execve execve.c
./execve | tee output.log