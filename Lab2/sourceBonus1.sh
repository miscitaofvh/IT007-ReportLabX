#!/bin/bash

if [ -d "OS_LAB2_IMG" ]; then
    echo "Repository đã tồn tại. Đang cập nhật..."
    cd OS_LAB2_IMG && git pull
else
    git clone https://github.com/locth/OS_LAB2_IMG
fi

if [ ! -d "png" ]; then
    mkdir png
    echo "Đã tạo thư mục png"
fi

if [ ! -d "jpg" ]; then
    mkdir jpg
    echo "Đã tạo thư mục jpg"
fi

mv OS_LAB2_IMG/*.png png/
mv OS_LAB2_IMG/*.jpg jpg/
