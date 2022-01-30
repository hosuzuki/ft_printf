/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/01/30 20:06:18 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void ft_print_space(t_stock *lst, int len)
{
	if (lst->sign != OFF)
		lst->width--;
	if (lst->space == ON)
	{
		lst->total_len++;
		lst->width--;
		write(1, " ", 1);
	}
	else if (lst->width > 0 && lst->zero_pad == OFF)
	{
		while (lst->width - len > 0)
		{
			write(1, " ", 1);
			lst->width--;
			lst->total_len++;
		}
	}
}

void ft_print_sign(t_stock *lst)
{
	if (lst->sign == PLUS)
	{
		lst->width--;
		lst->total_len++;
		write(1, "+", 1);
	}
	else if (lst->sign == MINUS)
	{
		lst->width--;
		lst->total_len++;
		write(1, "-", 1);
	}
}

void ft_print_left_align(t_stock *lst, int len)
{
	if (lst->left_align == OFF)
		return ;
	lst->width -= len;
	while (lst->width > 0)
	{
		write(1, " ", 1);
		lst->total_len++;
		lst->width--;
	}
}

void ft_print_zero_pad(t_stock *lst, int len)
{
	if (lst->width < 1)
	{
		lst->precision -= len;
		while (lst->precision > 0)
		{
			write(1, "0", 1);
			lst->precision--;
			lst->total_len++;
		}
	}
	if (lst->zero_pad == OFF)
		return ;
	lst->width -= len;
	while (lst->width > 0)
	{
		write(1, "0", 1);
		lst->total_len++;
		lst->width--;
	}
}

void ft_print_decimal(t_stock *lst, int decimal)
{
	int len;
	long tmp;
	char	*res;

	tmp = (long)decimal;
	len = 1;
	if (decimal < 0)
	{
//		lst->sign = MINUS;
		tmp *= -1;
		len++;
	}
	while (10 <= tmp)
	{
		tmp /= 10;
		len++;
	}
	res = ft_itoa(decimal);
	if (lst->left_align == OFF)
		ft_print_space(lst, len);
	ft_print_sign(lst);
//	if (lst->left_align == OFF)
//		ft_print_space(lst, len);
	ft_print_zero_pad(lst, len);
	write(1, res, len);
	lst->total_len += len;
	ft_print_left_align(lst, len);
	free (res);
}
