#!/bin/bash
#

while getopts "m:s:" option;
do
	case $option in 
		m) 
			minute=$OPTARG
			;;
		s)
			second=$OPTARG
			;;
	esac
done

while [ $minute -ne 0 ] || [ $second -ne 0 ];
do
	echo "$minute:$second"
	sleep 1
	if [ $((second-1)) -ge 0 ]; then
	       	second=$((second-1))
	else
		if [ $((minute)) != 0 ]; then 
			minute=$((minute-1))
		fi
		second=$((59))
	fi
done


