#!/bin/bash
#script to play the music

#writing music directory

music_path="/home/kgpk/Documents/my_songs.txt"
#echo $music_path

# Get the song name
if [ -z "$1" ];
then
	echo "usage: playmusic <song_name>	//to play the song, or"
	echo "usage: playmusic stop-music 	//to stop the music"
	exit 
elif [ "$1" = "--all" ];
then
	while read -r line; do
		link_addr="$(echo $line | awk '{print $NF}')"
		song_name="$(echo $line | cut -d'-' -f1)"
		if [[ -z $link_addr ]];
		then
			echo "song not found"
			exit
		else
			mpv $link_addr --no-video &>/dev/null &
			echo "playing $song_name"
			wait
		fi
	done < "$music_path"
	exit
elif [ "$1" = "--shuffle" ];
then
	song_index=1
	shuffled_music=$(shuf "$music_path")
	while read -r line; do
		link_addr="$(echo $line | awk '{print $NF}')"
		song_name="$(echo $line | cut -d'-' -f1)"
		if [[ -z $link_addr ]];
		then
			echo "song not found"
			exit
		else
			mpv $link_addr --no-video &>/dev/null &
			echo "playing $song_index $song_name"
			wait
			song_index=$((song_index+1))
		fi
	done <<< "$shuffled_music"
	exit

elif [ "$1" = "stop-music" ];
then
	music_pid="$(ps -ef | grep mpv | grep 'no-video' | awk '{print $2}')"
	kill $music_pid
	exit 
fi

song_name=$1

link_addr="$(grep -i "$song_name" "$music_path" | awk '{print $NF}')"

#echo $link_addr

if [[ -z $link_addr ]];
then
	echo "song not found"
else
	if [ -z "$2" ]; then
		mpv $link_addr --loop --no-video &>/dev/null &
		echo "playing '$1'"
	else
		index=0
		while read -r line; do
			link_addr="$(echo $line | awk '{print $NF}')"
			song_name="$(echo $line | cut -d'-' -f1)"
			if [ $index = 0 ]; then
				shopt -s nocasematch
				if [[ $song_name =~ "$1" ]]; then
					index=1
				else
		#			echo $song_name
					continue
				fi

			fi

			if [[ -z $link_addr ]];
			then
				echo "song not found"
				exit
			else
				mpv $link_addr --no-video &>/dev/null &
				echo "playing $song_name"
				wait
			fi
		done < "$music_path"
		exit
	fi

fi
