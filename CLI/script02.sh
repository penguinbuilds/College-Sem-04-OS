#!/bin/bash
echo "Please input two numbers:"
read num1 num2
echo "The sum of $num1 and $num2 is `expr $num1 + $num2`"

echo "Please enter the radius of the circle:"
read r
echo "The area of circle with radius $r is:"
echo "$r * $r * 3.14" | bc

a=5
b=10

echo "Before Swapping, a = $a and b = $b"

c=$a
a=$b
b=$c

echo "After Swapping, a = $a and b = $b"

a=`expr $a + $b`
b=`expr $a - $b`
a=`expr $a - $b`

echo "Swapping again, a = $a and b = $b"