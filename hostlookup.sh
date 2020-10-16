#!/bin/bash
#comments go here

usage()
{
  echo "$0 usage: [-f input filed]"
exit 1
}
while getopts ":f:" options;
do
 case "${options}" in
 f)
 f=${OPTARG}
 if [ -f ${f} ]; then
  echo The file: ${f} is present 
 else
 usage
 fi
 ;;
 *)
 usage
 ;;
 esac
done
while read line
do 
out=$(host -W1 -t A $line)
 if [ $? -eq 0 ]; then
  echo $out
 else 
  echo "$line does not have a DNS A record"
 fi


done < ${f}


