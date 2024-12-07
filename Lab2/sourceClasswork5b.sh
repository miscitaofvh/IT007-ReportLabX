#!/bin/bash

correct_name="Nguyen Van Hung"
correct_id="23520569"

read -p "Nhap ten cua ban: " name
read -p "Nhap ma so sinh vien cua ban: " id

for ((i = 1; i <= 5; ++i))
do
	if [ "$name" != "$correct_name" ] || [ "$id" != "$correct_id" ]; then
        	echo "Access Denied"
        	read -p "Nhap lai ten cua ban: " name
        	read -p "Nhap lai ma so sinh vien cua ban: " id
	else
		break
	fi 
	
done

if [ "$name" != "$correct_name" ] || [ "$id" != "$correct_id" ]; then
	echo "Access Denied"
else
	echo "Xin chao $name, ban da xac thuc thanh cong!"
fi
