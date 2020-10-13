#!/bin/bash
red='\033[0;31m'
green='\033[0;32m'
yellow='033[0;33m'
blue='\033[0;34m'
purple='33[0;35m'
default='33[0m'
read -p "Enter a color please: " color
echo "${color} entered"
color=${color^^}

if [ ${color} = "YELLOW" ]; then
  echo "$color is a color"

if [ ${color} = "GREEN" ]; then
echo "$color is a color"
 
 if [ ${color} = "BLUE" ]; then
echo "$color is a color"

 if [ ${color} = "PURPLE" ]; then
 echo "$color is a color"
 
 if [ ${color} = "RED" ]; then
echo "$color is a color"


fi

fi

fi
fi
else 
  echo "$color is not a valid color"
exit 1

fi
echo -e "${color} Your selected color is ${color}${defaul}"
 

