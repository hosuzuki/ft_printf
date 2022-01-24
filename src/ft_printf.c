#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
	t_stock	lst;

	if(!fmt)
		return (0);
	lst = malloc(sizeof(t_stock));
	if (!lst)
		return (-1);
	lst.total_len = 0;
	va_start(lst.args, fmt);
	ft_analyze_fmt(fmt, lst);
	va_end(lst.args);
	return (lst.total_len);
}
