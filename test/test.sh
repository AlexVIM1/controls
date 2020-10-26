#!/bin/bash

# You must be in 'test/' directory
# Controls must be installed

controls > output/blank 2>&1
controls write cat <input/category > output/create_category 2>&1
controls write file <input/file_data > output/write_file 2>&1
controls list cats > output/list_categories
controls list cat <input/category > output/list_files 2>&1
controls list file <input/file > output/list_file 2>&1
controls rm file <input/file > output/remove_file 2>&1
controls rm cat <input/category_name > output/remove_category 2>&1

echo "


--------------------

create_category:

"
cat output/create_category
echo "

write_file:

"
cat output/write_file
echo "

list_categories:

"
cat output/list_categories
echo "

list_files:

"
cat output/list_files
echo "

list_file:

"
cat output/list_file
echo "

remove_file:

"
cat output/remove_file
echo "

remove_category:

"
cat output/remove_category
