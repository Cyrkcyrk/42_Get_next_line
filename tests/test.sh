#!/bin/bash

folderPATH="../"

fileGNL="get_next_line.c"
fileGNLUtils="get_next_line_utils.c"
filesPATH="$folderPATH$fileGNL $folderPATH$fileGNLUtils main.c"

echo "Testing"

rm -f output
testFunction()
{
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$1 $filesPATH -I $folderPATH -o gnl 
	echo "" >> output
	echo "----------------------------------" >> output
	echo "      BUFFER SIZE : $1" >> output
	echo "----------------------------------" >> output
	echo "" >> output
	echo "___normal__________________________________" >> output
	./gnl files/normal >> output
	echo "" >> output
	echo "___No new line at end______________________" >> output
	./gnl files/noNewLine >> output
	echo "" >> output
	echo "___Only 1 new line_________________________" >> output
	./gnl files/newLineAlone >> output
	echo "" >> output
	echo "___Only multiple new line__________________" >> output
	./gnl files/newLineMultiple >> output
	echo "" >> output
	echo "___Empty file______________________________" >> output
	./gnl files/empty >> output
	echo "" >> output
	echo "___Bad FD (-1)_____________________________" >> output
	./gnl fd -1 >> output
	echo "" >> output
	echo "___Bad FD (10000)__________________________" >> output
	./gnl fd 10000 >> output

	rm -f gnl
}

testFunction 1
testFunction 10
testFunction 10000
testFunction 10000000

cat output
rm -f output
