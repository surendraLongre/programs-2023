#!/bin/bash

bold=$(tput bold)
red='\033[0;31m'
blue=$(tput setaf 4)
magenta=$(tput setaf 13)
nc_red=$(tput sgr0)
nc='\033[0m' # reset color
PS3="${nc_red}choose an option: "
files=""
cmd=""
read -p "${nc_red}Enter the main command: " cmd_initial 
cmd_base="nice -15 nohup $cmd_initial"
select options in "add a file" "get added files" "start" "status"; 
do
	case "$options" in
#adding a file
		"add a file")
			read -p "${blue}Enter file name: ${bold}${magenta}" -e file
#			echo $file
#loop through all of the files in the variable

			for file_name in $file;
			do
				cmd+="$cmd_base $file_name & "
				files+="$file_name "$'\n'
			done

#			if [ -e $file ]; then
#			echo
#			cmd+="$cmd_base $file & "
#			files+="$file "
#			echo "cmd: $cmd, files: $files"
#			else 
#				echo -e "${red}file does not exist${nc}"
#				echo
#			fi
			;;
		"get added files")
#getting files
			echo "$files"
			echo
			;;
		"start")
#start the process
		if [ -z $files ]; then
			echo "no files chosen"
		else
			echo "file execution has started"
			eval "$cmd"
			echo "running jobs: $(jobs)"
#			break
		fi
			;;
		"status")
			echo "running jobs: $(jobs)"
			;;
		*) 
			echo "you chose wrong option"
			echo
			;;
	esac

done
