#include "ft_printf.h"
#include "libft.h"

void ft_print_sign(t_stock *lst, size_t decimal)
{
	if (lst->sign == ON)
	{
		if (decimal >= 0)
			write(1, "+", 1);
	}
}

void ft_print_left_align(t_stock *lst, size_t len)
{
	lst->left_align = lst->left_align - len;
	while (lst->left_align > 0)
	{
		write(1, " ", 1);
		lst->left_align--;
	}
}

void ft_print_zero_pad(t_stock *lst, size_t len)
{
	lst->zero_pad -= len;
	while (lst->zero_pad > 0)
	{
		write(1, "0", 1);
		lst->zero_pad--;
	}
}

void ft_print_decimal(t_stock *lst, size_t decimal)
{
	size_t len;
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
	ft_print_sign(lst, decimal);
	ft_print_zero_pad(lst, len);
	write(1, res, len);
	ft_print_left_align(lst, len);
}
