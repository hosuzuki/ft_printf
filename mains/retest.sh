#!/bin/bash

rm diff.txt pf.txt ft.txt pf.out ft.out
make -C ../ re
gcc -Wall -Werror -Wextra -D PRINT="ft_printf" ../libftprintf.a main_42tester.c -o ft.out -g
gcc -Wall -Werror -Wextra -D PRINT="printf" ../libftprintf.a main_42tester.c -o pf.out
./pf.out >> pf.txt
./ft.out >> ft.txt
diff pf.txt ft.txt >> diff.txt
