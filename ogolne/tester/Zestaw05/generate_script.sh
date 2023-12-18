#!/bin/bash


MAX_NUM=1000000

for ((i = 10000; i <= 150000; i += 10000)); do
    echo "Running Sortings with input size: $i"
    
    ./Generator.x $i $MAX_NUM > input.txt
    
    ./BubbleSort.x measure_mode < input.txt 2>&1
    ./SelectionSort.x measure_mode < input.txt 2>&1
    ./InsertionSort.x measure_mode < input.txt 2>&1
    ./CountingSort.x measure_mode < input.txt 2>&1

    
done

rm -f input.txt