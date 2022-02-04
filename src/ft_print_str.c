/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:17 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/04 17:14:10 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static void	ft_print_space_s(t_stock *lst, int len)
{
	if (len < lst->width)
	{
		while (0 < lst->width - len)
		{
			lst->total_len += write(1, " ", 1);
			lst->width--;
		}
	}
	else if (lst->precision != OFF && lst->precision < lst->width)
	{
		while (0 < lst->width - lst->precision)
		{
			lst->total_len += write(1, " ", 1);
			lst->width--;
		}
	}
}

void	ft_print_str(t_stock *lst, char *str)
{
	int	len;

	if (!str)
	{
		lst->total_len += write(1, "(null)", 6);
		return ;
	}
	len = ft_strlen(str);
	if (lst->left_align == OFF)
		ft_print_space_s(lst, len);
	if (len <= lst->precision || lst->precision == OFF)
	{
		lst->total_len += write(1, str, len);
		lst->width -= len;
	}
	else if (lst->precision < len)
	{
		lst->total_len += write(1, str, lst->precision);
		lst->width -= lst->precision;
	}
//		if (lst->left_align == ON)
//		ft_print_space_s(lst, len);
	ft_print_left_align_space(lst);
}
