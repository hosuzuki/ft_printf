/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:50:02 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/15 08:53:27 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_print_space(t_stock *lst, int len)
{
	if (lst->space == ON && len != 0)
		ft_write(lst, " ", 1);
}

void	ft_print_wid_pre(t_stock *lst, int len)
{
	long long	tmp;

	tmp = 0;
	if (lst->sign == PLUS)
		tmp++;
	if (lst->zero_pad == ON && lst->width < lst->precision) 
		return ;
	if (lst->zero_pad == ON && lst->precision < 0)
		return ;
	//	else if (len < lst->width && lst->zero_pad == OFF)
//	if (len < lst->width && lst->zero_pad == OFF)
	if (len < lst->width)
	{
		tmp += len;
		while (0 < lst->width - tmp)
			ft_write(lst, " ", 1);
	}
//	else if (0 < lst->precision && lst->precision < lst->width)
	else if (0 < lst->precision && lst->precision < lst->width && len < lst->width)
	{
		if (lst->sign == MINUS)
			tmp++;
		tmp += lst->precision;
		while (0 < lst->width - tmp)
			ft_write(lst, " ", 1);
	}
}

void	ft_print_sign(t_stock *lst)
{
	if (lst->sign == PLUS)
		ft_write(lst, "+", 1);
	else if (lst->sign == MINUS)
		ft_write(lst, "-", 1);
}

void	ft_print_left_align_space(t_stock *lst)
{
	if (lst->left_align == OFF)
		return ;
	while (0 < lst->width)
		ft_write(lst, " ", 1);
}

void	ft_print_zero_pad(t_stock *lst, int len)
{
	if (lst->sign == PLUS)
		len++;
	if (lst->sign == MINUS)
		len--;
//	if (lst->width <= 0 && lst->precision != 0)
	if (lst->width <= lst->precision)
	{
		while (0 < lst->precision - len)
		{
			ft_write(lst, "0", 1);
			lst->precision--;
		}
	}
	if (lst->zero_pad == OFF)
		return ;
	while (0 < lst->width - len)
		ft_write(lst, "0", 1);
}
