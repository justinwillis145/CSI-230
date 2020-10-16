#!/bin/bash
 
usage()
{
  echo "$0 usage: [-f input filed] [-c U(upper) or L(lower)]"
exit 1
}
while getopts ":f:c:" options;
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
 c)
 c=${OPTARG}
 if [[ ${c} == "U" || ${c} == "L" ]]; then
 echo "${f} - ${c}"
 else
 usage
 fi
 ;;
 *)
 usage
 ;;
 esac
done
#conversion logic here

 while read line
 do
  if [ ${c} == "U" ]; then
     echo $line | tr [:lower:] [:upper:]
else 
echo $line | tr [:upper:] [:lower:]
 fi
 done < $f

exit 0
