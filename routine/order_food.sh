#!/bin/bash
#I am writing to order food based on the time I"m currently in"

cmd="firefox "
while getopts "l:q:" opt;
do
	location=${OPTARG,,}
	case $opt in
		"l")
			shop_name=${OPTARG,,}
			if [ $shop_name = "h2" ]; then
				shop_name+="canteen"
			elif [ $shop_name = "aroma" ]; then
				shop_name+="dhaba"
			else
				echo "wrong shop_name-$shop_name"
				exit 1
			fi
			;;
		"q")
			query=$OPTARG
			;;
	esac
done

if [ $# -eq 0 ]; then

	if [  "$time"  -lt  "29" ]; then
		firefox "https://aromadhaba.com/search?query=${1:-paneer}"
	else
		firefox "https://h2canteen.com/search?query=${1:-paneer}"
	fi

	exit 0

fi

firefox "https://$shop_name.com/search?query=$query"


