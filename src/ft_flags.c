#include <ft_printf.h>

void ft_left_align(const char *fmt, t_stock lst, int &i)
{
	size_t len;
	
	while (ft_isdigit(fmt[*i])
	{
		len = len * 10;
		len = len + ft_atoi(fmt[*i]);
		*i++;
	}
	lst.left_align = len;
}

