#!/bin/bash

rm diff.txt pf.txt ft.txt pf.out ft.out
gcc -Wall -Werror -Wextra -D PRINT="printf" ../libftprintf.a main_42tester.c -o pf.out
gcc -Wall -Werror -Wextra -D PRINT="ft_printf" ../libftprintf.a main_42tester.c -o ft.out -g
./pf.out >> pf.txt
./ft.out >> ft.txt
diff ft.txt pf.txt >> diff.txt
