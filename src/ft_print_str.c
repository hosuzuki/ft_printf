/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:17 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/02 21:22:48 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static void	ft_print_space_s(t_stock *lst, int len)
{
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

void	ft_print_str(t_stock *lst)
{
	char	*str;
	int		len;

	str = va_arg(lst->args, char *);
	if (str == NULL)
	{
		lst->total_len += write(1, "(null)", 6);
		return ;
	}
	len = ft_strlen(str);
	if (lst->left_align == OFF)
		ft_print_space_s(lst, len);
	if (lst->precision >= len || lst->precision == OFF)
		lst->total_len += write(1, str, len);
	else if (lst->precision < len)
		lst->total_len += write(1, str, lst->precision);
	if (lst->left_align == ON)
		ft_print_space_s(lst, len);
}
