#!/bin/bash

file='data.txt'
file_length=$(wc -l $file | awk '{print $1}')
file_length=$((file_length))

#get the position(top/bottom) to add the text
read -p "Enter the task: " task
read -p "Enter the progress: " progress
read -p "Enter position(top/bottom): " position

data=$(echo "${task}\t\t${progress}")

if [ "$position" = "top" ]; then
	sed -i "1i\\${data}" $file
else
	sed -i "\$a\\${data}" $file
fi
