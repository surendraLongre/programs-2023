#!/bin/bash

line_num=1
file='/home/kgpk/my_scripts/routine/data.txt'
file_length=$(wc -l $file | awk '{print $1}')
file_length=$((file_length))

blue=$(tput bold)$(tput setaf 4)
green=$(tput bold)$(tput setaf 2)
red=$(tput bold)$(tput setaf 1)
reset=$(tput sgr0)

function updateTask(){
	if grep -qi "$1" "$file"; then
		line_num=$(sed -n "/$1/ I =" $file)
		data="$(sed -n "$line_num"p $file)"
		task="$(echo $data | awk '{print $1}')"
		progress="$(echo $data | awk '{print $2}')"


		if [ "$progress" = 'no' ] || [ "$progress" = 'running' ]; then
			echo "${red}$data${reset}"
			echo -n "${blue}(y/n/r):${reset} "
			read -p "" user_response
			#read -p "(y/n/r): " user_response
			echo
		else
			echo "${green}FINISHED${reset}"
			echo
			return
		fi
		case "$user_response" in
			'y')   data=$(awk '{$2="\t\tfinished"; print}' <<< "$data")
				sed -i "${line_num}s/.*/$data/" $file
				;;

			'n')   ;;

			'r')   data=$(awk '{$2="\t\trunning"; print}' <<< "$data")
				sed -i "${line_num}s/.*/$data/" $file
				;;
			*) echo "invalid";;
		esac

	else
		echo 'invalid'
	fi
}

if [ $# -ne 0 ] ;  then
	for task in "$@";
	do
		updateTask $task
	done
else
	while true; do
		data="$(sed -n "$line_num"p $file)"
		task="$(echo $data | awk '{print $1}')"
		progress="$(echo $data | awk '{print $2}')"

		if [ "$progress" = 'no' ] || [ "$progress" = 'running' ]; then
			echo "${green}$data${reset}"
			echo -n "${blue}(y/n/r):${reset} "
			read -p "" user_response
			#read -p "(y/n/r): " user_response
			echo
		elif [ $line_num -lt $file_length ]; then
			line_num=$((line_num+1))
			continue
		fi
		case "$user_response" in
			'y')   data=$(awk '{$2="\t\tfinished"; print}' <<< "$data")
				sed -i "${line_num}s/.*/$data/" $file
				;;

			'n')   if [ $line_num -lt $file_length ]; then
				line_num=$((line_num+1))
				continue
				fi ;;

			'r')   data=$(awk '{$2="\t\trunning"; print}' <<< "$data")
				sed -i "${line_num}s/.*/$data/" $file
				;;
			*) echo "invalid";;
		esac

		break
	done

fi
