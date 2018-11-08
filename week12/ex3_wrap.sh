#!/usr/bin/env bash

cmd="gcc copy.c -o copy "

if [ "$1" = "-SYNC" ] || [ "$3" = "-SYNC" ]
then
	cmd="$cmd -DSYNC"
fi

# Buffer
buf=""

if [ "$2" = "-BUF" ]
then
	buf="-DBUF_SIZE=$3" # for internal use, no injection checking
else
	if [ "$1" = "-BUF" ]
	then
		buf="-DBUF_SIZE=$2" # for internal use, no injection checking
	fi
fi

cmd="$cmd $buf"

echo $cmd
$cmd


(time ./copy copy_in.txt copy_out.txt) 2>&1