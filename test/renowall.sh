#!/bin/bash

rm diff.txt pf.txt ft.txt pf.out ft.out
make -C ../ re
#gcc -D PRINT="printf" ../libftprintf.a main_42tester.c -o pf.out
#gcc -D PRINT="ft_printf" ../libftprintf.a main_42tester.c -o ft.out -g
#gcc -D PRINT="printf" ../libftprintf.a main_printTester.c -o pf.out
#gcc -D PRINT="ft_printf" ../libftprintf.a main_printTester.c -o ft.out -g
gcc -D PRINT="printf" ../libftprintf.a main_ft_printf_tester.c -o pf.out
gcc -D PRINT="ft_printf" ../libftprintf.a main_ft_printf_tester.c -o ft.out -g
./pf.out >> pf.txt
./ft.out >> ft.txt
diff ft.txt pf.txt >> diff.txt
