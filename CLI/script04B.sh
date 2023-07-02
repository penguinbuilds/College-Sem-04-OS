#!/bin/bash
echo "Enter limit till which the Fibonacci Sequence must be calculated:"
read limit
echo "Following is the Fibonacci Sequence:"
prev=0
curr=1
for((i=0;i<=limit;i++))
do  
    echo "$prev"
    temp=`expr $prev + $curr`
    prev=$curr
    curr=$temp
done