#!/bin/bash
echo "Please enter the number whose factorial has to be calculated:"
read num
fact=1
for((i=1;i<=$num;i++))
do
    fact=$((fact*i))
done
echo "$num! = $fact"