#!/bin/bash
#
#delete tasks
file='/home/kgpk/my_scripts/routine/data.txt'

if [ $# -ne 0 ]; then
	for task in "$@"; do
		sed -i "/${task^^}/d" $file
	done
else
	echo "usage: $0 {tasks}"
fi
