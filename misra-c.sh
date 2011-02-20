#! /usr/bin/env bash

echo "___misra-c.sh________________________________________________________"

# compile and put in /tmp folder 
# (tmp folder is wiped at every reboot)
echo "___gcc-messages______"
gcc -std=c99 misra-c.c -o /tmp/misra-c

# allow execution
#chmod 755 /tmp/misra-c

# run test-case
echo "___test-case.c_______"
/tmp/misra-c < ./test-case.c

# run self
echo "___stdin_____________"
/tmp/misra-c



echo "___end_______________"


#rm misra-c
