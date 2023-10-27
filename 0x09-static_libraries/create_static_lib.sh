#!/bin/bash
gcc -Wall -pedantic -Werror -Wextra -c *.c
ar rcs liball_tmp.a *.o
rm -f liball.a
mv liball_tmp.a liball.a
rm *.o
