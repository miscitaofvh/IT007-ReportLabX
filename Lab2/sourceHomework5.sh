#!/bin/bash

read -p "Nhap ID sinh vien: " studentID

while IFS=';' read -r id name grade; do
	if [ "$id" == "$studentID" ]; then
		echo "Ten hoc sinh la: $name"
		echo "Diem cua hoc sinh la: $grade"
		exit 0
	fi
done < gradebook.csv

echo "Sinh vien co ma ID $studentId khong ton tai"
