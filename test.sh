#!/bin/bash

rm -f output
testFunction()
{
	gcc -Wall -Werror -Wextra -D BUFFER_SIZE=$1 get_next_line.c get_next_line_utils.c main.c -o gnl
	echo "      BUFFER SIZE : $1"
	echo "----------------------------------" >> output
	echo "      BUFFER SIZE : $1" >> output
	echo "----------------------------------" >> output
	echo "___normal__________________________________" >> output
	./gnl tests/normal >> output
	echo "___No new line at end______________________" >> output
	./gnl tests/noNewLine >> output
	echo "___Only 1 new line_________________________" >> output
	./gnl tests/newLineAlone >> output
	echo "___Only multiple new line__________________" >> output
	./gnl tests/newLineMultiple >> output
	echo "___Empty file______________________________" >> output
	./gnl tests/empty >> output
	echo "___Bad FD (-1)_____________________________" >> output
	./gnl fd -1 >> output
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
