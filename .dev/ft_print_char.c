#include "ft_printf.h"

void	ft_print_char(int c, t_analyze *analyze)
{
	char	output[2];

//	analyze->zero_padding = 0; do i need this even in it is initialized with 0 in ft_init_format?
	analyze->len = 1;
	output[0] = c;
	output[1] = '\0';
	analyze->status = ft_push(analyze, "", output);
}
