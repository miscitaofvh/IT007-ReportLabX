#!/bin/bash

read -p "Nhap tuoi cua ban: " age

if [ $age -lt 1 ] || [ $age -gt 99 ]; then
	echo "Tuoi khong hop le"
elif [ $age -lt 12 ]; then
	echo "Ban la mot dua tre"
elif [ $age -lt 19 ]; then
	echo "Ban la mot thieu nien"
else 
	echo "Ban la nguoi lon"
fi
