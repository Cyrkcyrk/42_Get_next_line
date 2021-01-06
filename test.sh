rm -f output
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=100000 get_next_line.c get_next_line_utils.c main.c -o gnl

echo "___test1__________________________________" >> output
./gnl tests/test1.txt >> output
echo "___test2__________________________________" >> output
./gnl tests/test2.txt >> output
echo "___test3__________________________________" >> output
./gnl tests/test3.txt >> output

cat output
rm -f output
rm -f gnl
