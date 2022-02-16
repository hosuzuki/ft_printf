#!/bin/bash

rm diff.txt pf.txt ft.txt pf.out ft.out
make -C ../ re
#gcc -Wall -Werror -Wextra -D PRINT="printf" ../libftprintf.a main_printTester.c -o pf.out
#gcc -Wall -Werror -Wextra -D PRINT="ft_printf" ../libftprintf.a main_printTester.c -o ft.out -g
gcc -Wall -Werror -Wextra -D PRINT="printf" ../libftprintf.a main_ft_printf_tester.c -o pf.out
gcc -Wall -Werror -Wextra -D PRINT="ft_printf" ../libftprintf.a main_ft_printf_tester.c -o ft.out -g
./pf.out >> pf.txt
./ft.out >> ft.txt
diff ft.txt pf.txt >> diff.txt
