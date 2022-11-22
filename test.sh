#!/bin/bash

eq="5 * X^0 + 4 * X^1 - 9.3 * X^2 = 1 * X^0"
echo "$eq"
./computorv1 "$eq"
echo

eq="2 * X^2 + 1 * X^1 - 3 * X^0 = 0 * X^1"
echo "$eq"
./computorv1 "$eq"
echo

eq="1 * X^2 + 1 * X^1 + 1 * X^0 = 0 * X^0"
echo "$eq"
./computorv1 "$eq"
echo

eq="9 * X^2 - 30 * X^1 + 25 * X^0 = 0 * X^0"
echo "$eq"
./computorv1 "$eq"
echo

eq="3 * X^2 - 4 * X^1 - 2 * X^0 = 0 * X^0"
echo "$eq"
./computorv1 "$eq"
echo

eq="-3 * X^2 + 1 * X^1 - 2 * X^0 = 0 * X^0"
echo "$eq"
./computorv1 "$eq"
echo

eq="25 * X^2 + 70 * X^1 + 49 * X^0 = 0 * X^0"
echo "$eq"
./computorv1 "$eq"
echo

eq="5 * X^0 + 4 * X^1 = 4 * X^0"
echo "$eq"
./computorv1 "$eq"
echo

eq="5 * X^0 = 4* X^0"
echo "$eq"
./computorv1 "$eq"
echo

eq="42 * X^0 = 42 * X^0"
echo "$eq"
./computorv1 "$eq"
echo

eq="-3 * X^2 + 1 * X^1 - 2 * X^0 = -2 * X^0 + 1 * X^1 - 3 * X^2"
echo "$eq"
./computorv1 "$eq"
