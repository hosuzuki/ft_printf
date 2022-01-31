/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/01 07:23:36 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void ft_precision(const char *fmt, t_stock *lst, size_t *i)
{
	size_t len;
	
	if (fmt[*i] != '.')
		return ;
	(*i)++;
	len = 0;
	if (fmt[*i] == '*')
	{
		lst->precision = va_arg(lst->args, int);
		(*i)++;
		return ;
	}
	while (ft_isdigit(fmt[*i]))
	{
		len = len * 10;
		len = len + (fmt[*i] - '0');
		(*i)++;
	}
//	if (len != 0)
	lst->precision = len;
}

void ft_width(const char *fmt, t_stock *lst, size_t *i)
{
	size_t len;

	len = 0;
	if (fmt[*i] == '*')
	{
		lst->width = va_arg(lst->args, int);
		(*i)++;
		return ;
	}
	while (ft_isdigit(fmt[*i]))
	{
		len = len * 10;
		len = len + (fmt[*i] - '0');
		(*i)++;
	}
	lst->width = len;
}

void ft_hash(const char *fmt, t_stock *lst, size_t *i)
{
	(void)fmt;
	if (lst->sign == ON || lst->space == ON)
	{
		lst->status = ERROR;
		return ;
	}
	(*i)++;
	lst->hash = ON;
//	ft_width(fmt, lst, i);
//	ft_precision(fmt, lst, i);
}

void ft_space(const char *fmt, t_stock *lst, size_t *i)
{
	(void)fmt;
	if (lst->sign == ON || lst->hash == ON)
	{
		lst->status = ERROR;
		return ;
	}
	(*i)++;
	lst->space = ON;
//	ft_width(fmt, lst, i);
//	ft_precision(fmt, lst, i);
}

void ft_sign(const char *fmt, t_stock *lst, size_t *i)
{
	(void)fmt;
	if (lst->left_align == ON)
	{
		lst->status = ERROR;
		return ;
	}
	(*i)++;
	lst->sign = PLUS;
//	ft_width(fmt, lst, i);
//	ft_precision(fmt, lst, i);
}

void ft_zero_pad(const char *fmt, t_stock *lst, size_t *i)
{
	(void)fmt;
	if (lst->left_align == ON)
	{
		lst->status = ERROR;
		return ;
	}
	(*i)++;
	lst->zero_pad = ON;
//	ft_width(fmt, lst, i);
//	ft_precision(fmt, lst, i);
}

void ft_left_align(const char *fmt, t_stock *lst, size_t *i)
{
	(void)fmt;
	if (lst->zero_pad == ON)
	{
		lst->status = ERROR;
		return ;
	}
	(*i)++;
	lst->left_align = ON;
//	ft_width(fmt, lst, i);
//	ft_precision(fmt, lst, i);
}
