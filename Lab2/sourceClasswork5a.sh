#!/bin/bash

correct_name="Nguyen Van Hung"
correct_id="23520569"

read -p "Nhap ten cua ban: " name
read -p "Nhap ma so sinh vien cua ban: " id

while [ "$name" != "$correct_name" ] || [ "$id" != "$correct_id" ]
do
	echo "Access Denied"
	read -p "Nhap lai ten cua ban: " name
	read -p "Nhap lai ma so sinh vien cua ban: " id
done

echo "Xin chao $name, ban da xac thuc thanh cong!"
