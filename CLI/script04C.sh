#!/bin/bash
echo "Please input two numbers:"
read num1 num2
echo "Enter the operation to be performed (1:+ 2:- 3:* 4:/):"
read op

if [ $op -eq 1 ]; then
    echo "$num1 + $num2 = `expr $num1 + $num2`"
elif [ $op -eq 2 ]; then
    echo "$num1 - $num2 = `expr $num1 - $num2`"
elif [ $op -eq 3 ]; then
    echo "$num1 * $num2 = `expr $num1 \* $num2`"
elif [ $op -eq 4 ]; then
    echo "$num1 / $num2 = `expr $num1 / $num2`"
else
    echo "INVALID INPUT!"
fi