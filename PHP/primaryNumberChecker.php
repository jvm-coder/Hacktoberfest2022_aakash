<?php

$input = readline('Enter a number: ');

function checkNumber($num)
{
    if ($num === 1) {
        return 0;
    }
    for ($i = 2; $i <= $num / 2; $i++) {
        if ($num % $i === 0) {
            return 0;
        }
    }
    return 1;
}

$numbVal = checkNumber($input);
if ($numbVal === 1) {
    echo "It is a prime number";
} else {
    echo "It is a non-prime number";
}
