#!/bin/sh

while (true)
do
./fsanitize test_fillit
sleep 2
valgrind --tool=memcheck --leak-check=full ./fillit test_fillit
sleep 2
done