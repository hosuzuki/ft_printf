#include "ft_printf.h"
#include "libft.h"

void ft_print_space(t_stock *lst)
{
	if (lst->space == ON)
	{
		lst->width--;
		write(1, " ", 1);
	}
}

void ft_print_sign(t_stock *lst)
{
	if (lst->sign == PLUS)
	{
		lst->width--;
		write(1, "+", 1);
	}
	else if (lst->sign == MINUS)
	{
		lst->width--;
		write(1, "-", 1);
	}
}

void ft_print_left_align(t_stock *lst, size_t len)
{
	if (lst->left_align != OFF)
		return ;
	lst->width -= len;
	while (lst->width > 0)
	{
		write(1, " ", 1);
		lst->width--;
	}
}

void ft_print_zero_pad(t_stock *lst, size_t len)
{
	if (lst->zero_pad != OFF)
		return ;
	lst->width -= len;
	while (lst->width > 0)
	{
		write(1, "0", 1);
		lst->width--;
	}
}

void ft_print_decimal(t_stock *lst, int decimal)
{
	size_t len;
	int tmp;
	char	*res;

	tmp = decimal;
	len = 1;
	while (10 < tmp)
	{
		tmp = tmp / 10;
		len++;
	}
	res = ft_itoa(decimal);
	if (res[0] == '-')
		lst->sign = MINUS;
	ft_print_sign(lst);
	ft_print_space(lst);
	ft_print_zero_pad(lst, len);
	write(1, res, len);
	ft_print_left_align(lst, len);
}
