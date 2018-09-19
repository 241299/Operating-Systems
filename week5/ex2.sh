#!/usr/bin/env bash

echo 0 >ex2

if ln ex2 ex2.lock
then
for i in {1..10}
    do
        a=$(($(tail -n 1 ex2)+1))

        echo ${a} >> ex2
    done
rm ex2.lock
fi