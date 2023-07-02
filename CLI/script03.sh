#!/bin/bash
echo "This is $0"
echo "The number of arguments is $#"
echo "$1 + $2 = `expr $1 + $2`"
echo "$3 - $4 = `expr $3 - $4`"
echo `ls *`
echo `cal`