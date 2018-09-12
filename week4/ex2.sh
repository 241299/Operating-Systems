#!/usr/bin/env bash
gcc ex2.c -o ex2

./ex2 && ps xu &&

for i in 1 2 3 4 5
do
  sleep 5
  ps xu
done