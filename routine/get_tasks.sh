#!/bin/bash
#
#get the tasks
file='/home/kgpk/my_scripts/routine/data.txt'

blue=$(tput bold)$(tput setaf 4)
green=$(tput bold)$(tput setaf 2)
red=$(tput bold)$(tput setaf 1)
reset=$(tput sgr0)

function printTask(){
	while read data; do
		task="$(echo $data | awk '{print $1}')"
		progress="$(echo $data | awk '{print $2}')"

		if [[ $progress = "$1" ]]; then
			echo "${2}$data${reset}"
		fi
	done < "$file"
}

while getopts "frn" opt; do
	case $opt in
		f)
			printTask finished $green
			;;
		r)
			printTask running $blue
			;;
		n)
			printTask no $red
			;;
	esac
done


if [ $# -eq 0 ]; then
	while read data; do
		task="$(echo $data | awk '{print $1}')"
		progress="$(echo $data | awk '{print $2}')"

		if [[ $progress = 'no' ]]; then
			echo "${red}$data${reset}"
		elif [[ $progress = 'running' ]]; then
			echo "${blue}$data${reset}"
		else
			echo "${green}$data${reset}"
		fi
	done < "$file"
fi
