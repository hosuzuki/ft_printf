#include "ft_printf.h"
#include "libft.h"

void ft_print_decimal(t_stock *lst, size_t decimal)
{
	int len;
	float tmp;
	char	*res;

	tmp = (float)decimal;
	len = 1;
	while (10 < tmp)
	{
		tmp = tmp / 10;
		len++;
	}
	res = ft_itoa(decimal);
	write(1, res, len);
	lst->left_align = lst->left_align - len;
	while (lst->left_align > 0)
	{
		write(1, " ", 1);
		lst->left_align--;
	}
}
