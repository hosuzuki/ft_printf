#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
	t_stock	*lst;
	size_t total_length;

	if(!fmt)
		return (0);
	lst = (t_stock *)malloc(sizeof(t_stock));
	if (!lst)
		return (-1);
	lst->total_len = 0;
	va_start(lst->args, fmt);
	total_length = ft_analyze_fmt(fmt, lst);
	va_end(lst->args);
	free(lst);
	return (total_length);
}
