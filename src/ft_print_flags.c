/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:50:02 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/03 17:43:14 by hokutosuz        ###   ########.fr       */
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
	else if (len < lst->width && lst->zero_pad == OFF)
	{
		while (0 < lst->width - len)
		{
			lst->total_len += write(1, " ", 1);
			lst->width--;
		}
	}
	else if (0 < lst->precision && lst->width > lst->precision)
	{
		while (0 < lst->width - lst->precision)
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
		lst->total_len += write(1, "+", 1);
		lst->width--;
	}
	else if (lst->sign == MINUS)
	{
		lst->total_len += write(1, "-", 1);
		lst->width--;
	}
}

void	ft_print_left_align_space(t_stock *lst, int len)
{
	if (lst->left_align == OFF)
		return ;
	while (0 < lst->width - len)
	{
		lst->total_len += write(1, " ", 1);
		lst->width--;
	}
}

void	ft_print_zero_pad(t_stock *lst, int len)
{
	if (0 <= lst->width)
	{
		lst->precision -= len;
		while (0 < lst->precision)
		{
			lst->total_len += write(1, "0", 1);
			lst->precision--;
		}
	}
	if (lst->zero_pad == OFF)
		return ;
	while (0 < lst->width - len)
	{
		lst->total_len += write(1, "0", 1);
		lst->width--;
	}
}
