#!/bin/bash


# Specify the range of numbers to generate
MAX_NUM=1000000

# Run BubbleSort.cpp 15 times with different input sizes
for ((i = 10000; i <= 150000; i += 10000)); do
    echo "Running Sortings with input size: $i"
    
    # Generate input using Generator.cpp with a fixed maximum number
    ./Generator.x $i $MAX_NUM > input.txt
    
    # Run BubbleSort.cpp in "measure_mode" and measure time
    ./BubbleSort.x measure_mode < input.txt 2>&1
    ./SelectionSort.x measure_mode < input.txt 2>&1
    ./InsertionSort.x measure_mode < input.txt 2>&1
    ./CountingSort.x measure_mode < input.txt 2>&1

    
    echo "Time taken to sort $i numbers: $TIME"
done

# Clean up temporary files
rm -f Generator BubbleSort input.txt