#!/bin/sh

mkdir -p day-$1/ex-1 day-$1/ex-2
for i in 1 2; do
    cp template/aoc.cpp day-$1/ex-$i/aoc-$1.cpp
    mkdir day-$1/resources
    touch day-$1/resources/aoc-input.txt
    cp template/Makefile day-$1/Makefile
    sed -i "s/day-n/day-$1/g" day-$1/Makefile
    sed -i "s/aoc-n/aoc-$1/g" day-$1/Makefile
done
