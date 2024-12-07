#!/bin/bash

read -p "Nhap ho ten nguoi dung: " name

mkdir "$name"

while IFS= read -r subject_code; do
    mkdir "$name/$subject_code"
done < subject.txt

echo "Đã tạo các thư mục theo thông tin người dùng và mã môn học."
