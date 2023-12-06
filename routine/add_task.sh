#!/bin/bash
#
#write script for adding tasks

file='/home/kgpk/my_scripts/routine/data.txt'

blue=$(tput bold)$(tput setaf 4)
green=$(tput bold)$(tput setaf 2)
red=$(tput bold)$(tput setaf 1)
reset=$(tput sgr0)

if [ $# -eq 2 ]; then
	task=${1}
	progress=$2
	echo -n "${blue}(top/botttom/line_num): ${reset} "
	read -p "" position
	if [[ $position = 'top' ]]; then
		sed -i "1i${task^^}\t\t$progress" $file
	elif [[ $position = 'bottom' ]]; then
		sed -i "\$a${task^^}\t\t$progress" $file
	else
		sed -i "$position i\\${task^^}\t\t$progress" $file
	fi
else
	echo "usage: $0 {task} {progress}"
fi
