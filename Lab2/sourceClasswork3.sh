#!/bin/sh

correct_name="Nguyen Van Hung"
correct_id="23520569"

read -p "Nhap ten cua ban: " name
read -p "Nhap ma so sinh vien cua ban: " id

if [ "$name" = "$correct_name" ] && [ "$id" = "$correct_id" ]; then
	echo "Xin chao $name, ban da xac thuc thanh cong!"
else
	echo "Access Denied"
fi
