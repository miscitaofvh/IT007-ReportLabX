#!/bin/bash
#echo "Implementing: $0"
#echo "PPID of count.sh: "
#ps -ef | grep count.sh
i=1
while [ $i -le $1 ]
do
 echo $i #>> count.txt
 i=$((i + 1))
 sleep 1
done
exit 0