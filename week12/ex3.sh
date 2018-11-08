#!/usr/bin/env bash

# Preparing input
cat /dev/random | head -c $1 > copy_in.txt
printf "File size: $(stat -c %s copy_in.txt) B\n"


printf "\n[DEFAULT CASE]\n"
sh ex3_wrap.sh

printf "\n[DEFAULT CASE SYNC]\n"
sh ex3_wrap.sh -SYNC


printf "\n[Buffer 256B]\n"
sh ex3_wrap.sh -BUF 256

printf "\n[Buffer 256B SYNC]\n"
sh ex3_wrap.sh -BUF 256 -SYNC


printf "\n[Buffer 512B]\n"
sh ex3_wrap.sh -BUF 512

printf "\n[Buffer 512B SYNC]\n"
sh ex3_wrap.sh -BUF 512 -SYNC


printf "\n[Buffer 1MB]\n"
sh ex3_wrap.sh -BUF $(expr 1024*1024) 

printf "\n[Buffer 1MB SYNC]\n"
sh ex3_wrap.sh -BUF $(expr 1024*1024) -SYNC


# Cleaning up all mess
rm copy_in.txt copy_out.txt