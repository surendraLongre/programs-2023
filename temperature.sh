#!/bin/bash
#

while getopts "f:c:" option;
do
	case $option in 
		c) 
			temperature=$OPTARG
			temperature=$(((temperature-32)*5/9))
			echo $temperature
			;;
		f) 	
			temperature=$OPTARG
			temperature=$((temperature*9))
			temperature=$((temperature/5))
			temperature=$((temperature+32))
			echo $temperature;
			;;
		\?) echo "pleae write the command in the following format:- $0 < -f/-c> <temperature>" ;;
	esac
done
