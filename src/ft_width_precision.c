/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:41:14 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/09 17:24:33 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_precision(const char *fmt, t_stock *lst, size_t *i)
{
	size_t	len;

	if (fmt[*i] != '.')
		return ;
	(*i)++;
	if (fmt[*i] == '*')
	{
		lst->precision = va_arg(lst->args, int);
		if (ERROR == ft_intmax(lst, lst->total_len, lst->precision))
			lst->status = ERROR;
		(*i)++;
		return ;
	}
	len = 0;
	while (ft_isdigit(fmt[*i]))
	{
		len = len * 10;
		len = len + (fmt[*i] - '0');
		(*i)++;
	}
	lst->precision = len;
	if (ERROR == ft_intmax(lst, lst->total_len, lst->precision))
		lst->status = ERROR;
}

void	ft_width(const char *fmt, t_stock *lst, size_t *i)
{
	size_t	len;

	if (fmt[*i] == '*')
	{
		lst->width = va_arg(lst->args, int);
		if (ERROR == ft_intmax(lst, lst->total_len, lst->width))
			lst->status = ERROR;
		(*i)++;
		return ;
	}
	len = 0;
	while (ft_isdigit(fmt[*i]))
	{
		len = len * 10;
		len = len + (fmt[*i] - '0');
		(*i)++;
	}
	lst->width = len;
	if (ERROR == ft_intmax(lst, lst->total_len, lst->width))
		lst->status = ERROR;
}
