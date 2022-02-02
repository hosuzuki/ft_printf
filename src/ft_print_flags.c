/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:50:02 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/02 21:10:31 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_print_space(t_stock *lst, int len)
{
	if (lst->sign == MINUS)
		return ;
	if (lst->space == ON && len != 0)
	{
		lst->total_len += write(1, " ", 1);
		lst->width--;
	}
	else if (lst->width > len && lst->zero_pad == OFF)
	{
		while (lst->width - len > 0)
		{
			lst->total_len += write(1, " ", 1);
			lst->width--;
		}
	}
	else if (lst->precision > 0 && lst->width > lst->precision)
	{
		while (lst->width - lst->precision > 0)
		{
			lst->total_len += write(1, " ", 1);
			lst->width--;
		}
	}
}

void	ft_print_sign(t_stock *lst)
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

void	ft_print_left_align(t_stock *lst, int len)
{
	if (lst->left_align == OFF)
		return ;
	while (lst->width - len > 0)
	{
		lst->total_len += write(1, " ", 1);
		lst->width--;
	}
}

void	ft_print_zero_pad(t_stock *lst, int len)
{
	if (lst->width < 1)
	{
		lst->precision -= len;
		while (lst->precision > 0)
		{
			lst->total_len += write(1, "0", 1);
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
