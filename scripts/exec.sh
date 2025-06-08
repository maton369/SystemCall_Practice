#!/bin/bash

# ps aux | tee output.log

# gcc -o fork fork.c
# ./fork | tee output.log

# gcc -o execve execve.c
# ./execve | tee output.log

# gcc -o exit exit.c
# ./exit | tee output.log
# echo $? |tee -a output.log

gcc -o wait wait.c
./wait | tee output.log