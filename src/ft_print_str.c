/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:17 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/07 07:14:48 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static void	ft_print_space_s(t_stock *lst, int len)
{
	if (len < lst->width)
	{
		while (0 < lst->width - len)
			ft_write(lst, " ", 1);
	}
	else if (lst->precision != OFF && lst->precision < lst->width)
	{
		while (0 < lst->width - lst->precision)
			ft_write(lst, " ", 1);
	}
}

void	ft_print_str(t_stock *lst, char *str)
{
	int	len;

	if (!str)
	{
		ft_write(lst, "(null)", 6);
		return ;
	}
	len = ft_strlen(str);
	if (lst->left_align == OFF)
		ft_print_space_s(lst, len);
	if (len <= lst->precision || lst->precision == OFF)
		ft_write(lst, str, len);
	else if (lst->precision < len)
		ft_write(lst, str, lst->precision);
	ft_print_left_align_space(lst);
}
