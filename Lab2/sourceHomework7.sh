#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Usage: $0 <string> <directory>"
    exit 1
fi

search_string="$1"
directory="$2"

for file in "$directory"/*; do
    if grep -q "$search_string" "$file"; then
        echo "Tim thay trong file: $file"
        grep "$search_string" "$file"
    fi
done
