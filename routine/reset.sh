#!/bin/bash
#
#reset tasks

line_num=1
file='/home/kgpk/my_scripts/routine/data.txt'
file_length=$(wc -l $file | awk '{print $1}')
file_length=$((file_length+1))

while [[ $line_num -ne $file_length ]]; do
	data="$(sed -n "$line_num"p $file)"
	task="$(echo $data | awk '{print $1}')"
	progress="$(echo $data | awk '{print $2}')"

	data=$(awk '{$2="\t\tno"; print}' <<< "$data")
	sed -i "${line_num}s/.*/$data/" $file
	line_num=$((line_num+1))
done
