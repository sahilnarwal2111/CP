#!/bin/bash

file1="output.txt"
file2="ref.txt"

line_num=0

while IFS= read -r line1 && IFS= read -r line2 <&3; do
    ((line_num++))
    if [[ "$line1" != "$line2" ]]; then
        echo "Line $line_num differs"
    fi
done <"$file1" 3<"$file2"

# Check if one file has extra lines
file1_lines=$(wc -l < "$file1")
file2_lines=$(wc -l < "$file2")

if [[ $file1_lines -gt $file2_lines ]]; then
    echo "Extra lines in $file1 starting from line $((file2_lines + 1))"
elif [[ $file2_lines -gt $file1_lines ]]; then
    echo "Extra lines in $file2 starting from line $((file1_lines + 1))"
fi

