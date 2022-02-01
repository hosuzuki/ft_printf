/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/01 18:55:23 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void ft_print_space(t_stock *lst, int len)
{
	if (lst->space == OFF)
		return;
	if (lst->width > len)
	{
		while (lst->width - len > 0)
		{
			lst->total_len += write(1, " ", 1);
			lst->width--;
		}
	}
	else if (lst->precision != OFF && lst->width > lst->precision)
	{
		while (lst->width - lst->precision > 0)
		{
			lst->total_len += write(1, " ", 1);
			lst->width--;
		}
	}
}
/*
void ft_print_space(t_stock *lst, int len)
{
//	if (lst->sign != OFF)
//		lst->width--;
	if (lst->space == ON && len != 0)
	{
		lst->total_len += write(1, " ", 1);
		lst->width--;
	}
	else if (lst->width > 0 && lst->zero_pad == OFF)
	{
		while (lst->width - len > 0)
		{
			lst->total_len += write(1, " ", 1);
			lst->width--;
		}
	}
}
*/
void ft_print_sign(t_stock *lst)
{
	if (lst->sign == PLUS)
	{
		lst->width--;
		lst->total_len += write(1, "+", 1);
	}
	else if (lst->sign == MINUS)
	{
		lst->width--;
		lst->total_len += write(1, "-", 1);
	}
}

void ft_print_left_align(t_stock *lst, int len)
{
	if (lst->left_align == OFF)
		return ;
//	lst->width -= len;
	while (lst->width - len > 0)
	{
		lst->total_len += write(1, " ", 1);
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
			lst->total_len +=	write(1, "0", 1);
			lst->precision--;
		}
	}
	if (lst->zero_pad == OFF)
		return ;
	while (lst->width - len > 0)
	{
		lst->total_len += write(1, "0", 1);
		lst->width--;
	}
}

void ft_print_decimal(t_stock *lst, int decimal)
{
	int len;
	long long  tmp;
	char	*res;

	tmp = (long long)decimal;
	len = 1;
	if (decimal < 0)
	{
		lst->sign = MINUS;
		tmp *= -1;
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
	if (res[0] == '-')
		lst->total_len += write(1, res + 1, len);
	else
		lst->total_len += write(1, res, len);
	ft_print_left_align(lst, len);
	free (res);
}
