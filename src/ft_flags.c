#include "ft_printf.h"
#include "libft.h"

void ft_left_align(const char *fmt, t_stock *lst, size_t *i)
{
	size_t len;
	
	len = 0;
	while (ft_isdigit(fmt[*i]))
	{
		len = len * 10;
		len = len + (fmt[*i] - '0');
		(*i)++;
	}
	lst->left_align = len;
}
