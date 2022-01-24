#include "ft_printf.h"

void ft_print_decimal(t_stock lst, size_t decimal)
{
	int res;
	int len;
	float tmp;

	res = va_arg(lst.args, int)
	tmp = (float)res;
	len = 1;
	while (10 < tmp)
	{
		tmp = tmp / 10;
		len++;
	}
	write(1, &res, len)
	lst.left_align = lst.left_align - len;
	if (lst.left_align > 0)
	{
		write(1, ' ', 1);
		lst.left_align--;
	}
}
