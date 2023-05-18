#!/bin/bash
#This script was written by Surendra Longre

ip_table="./ip_table.txt"
for ip in $(cat $ip_table)
do
	ping -c1 $ip > /dev/null

	if [ $? -eq 0 ]
	then
		echo "$ip is up and running"
	else echo "$ip is down"
	fi

done
