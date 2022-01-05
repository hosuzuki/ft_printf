#include "ft_printf.h"
#include <stdio.h>

void	ft_write_char(char c, t_analyze *analyze)
{
	analyze->buffer[analyze->done % BUFSIZ] = c;
	analyze->done++;
	printf("out is : %lu\n",  analyze->done % BUFSIZ);
	if (analyze->done % BUFSIZ == 0)
		write(1, analyze->buffer, BUFSIZ);
}
