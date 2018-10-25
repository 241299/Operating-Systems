#!/usr/bin/env bash

f="_ex3.txt"
echo > ${f}

chmod -x ${f} # removing execute permission from everybody
ls -l ${f}

chmod uo+rwx ${f} # granting all permissions to user and others
ls -l ${f}

chmod 660 ${f} # rw- rw- ---
ls -l ${f}

chmod 775 ${f} # rwx rwx r-x
ls -l ${f}

chmod 777 ${f} # everyone can do everything
ls -l ${f}