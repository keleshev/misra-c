#! /usr/bin/env bash

echo "___misra-c________________________________________________________"

# compile and put in /tmp folder 
# (tmp folder is wiped at every reboot)
echo "___gcc-messages______"
#gcc -std=gnu99 main.c -o /tmp/misra-c
gcc -std=c99 -pedantic main.c -o /tmp/misra-c

# run test-case
echo "___test-case_________"
/tmp/misra-c < ./test-case.c

# run self
echo "___stdin_____________"
/tmp/misra-c



echo "___end_______________"


rm /tmp/misra-c
