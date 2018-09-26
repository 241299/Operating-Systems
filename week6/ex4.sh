#!/usr/bin/env bash

gcc ex4.c
./a.exe &
kill -SIGUSR1 $(ps | grep week6/a | awk '{print $1}')