#!/bin/bash

blue=$(tput bold)$(tput setaf 4)
green=$(tput bold)$(tput setaf 2)
red=$(tput bold)$(tput setaf 1)
reset=$(tput sgr0)

file='data.txt'
echo
echo -e "${blue}$(cat $file)${reset}"
