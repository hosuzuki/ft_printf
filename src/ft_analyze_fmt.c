/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_fmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/02 21:10:29 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_isflag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	else
		return (0);
}

void	ft_analyze_speci(const char *fmt, t_stock *lst, size_t i)
{
	if (fmt[i] == 's')
		ft_print_str(lst);
	else if (fmt[i] == 'c')
		ft_print_char(lst);
	else if (fmt[i] == 'p')
		ft_print_address(lst, (size_t)va_arg(lst->args, void *));
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		ft_print_decimal(lst, va_arg(lst->args, int));
	else if (fmt[i] == 'u')
		ft_print_unsigned(lst, va_arg(lst->args, unsigned int));
	else if (fmt[i] == 'x')
		ft_print_hex(lst, va_arg(lst->args, int));
	else if (fmt[i] == 'X')
		ft_print_hex_cap(lst, va_arg(lst->args, int));
	else if (fmt[i] == '%')
	{
		lst->total_len++;
		write(1, "%", 1);
	}
}

void	ft_analyze_flag(const char *fmt, t_stock *lst, size_t *i)
{
	while (ft_isflag(fmt[*i]) || ft_isdigit(fmt[*i]) || fmt[*i] == '.')
	{
		if (fmt[*i] == '-')
			ft_left_align(lst, i);
		else if (fmt[*i] == '0')
			ft_zero_pad(lst, i);
		else if (fmt[*i] == '+')
			ft_sign(lst, i);
		else if (fmt[*i] == ' ')
			ft_space(lst, i);
		else if (fmt[*i] == '#')
			ft_hash(lst, i);
		ft_width(fmt, lst, i);
		ft_precision(fmt, lst, i);
	}
}

void	ft_init_lst(t_stock *lst)
{
	lst->status = OFF;
	lst->left_align = OFF;
	lst->zero_pad = OFF;
	lst->hash = OFF;
	lst->sign = OFF;
	lst->space = OFF;
	lst->width = 0;
	lst->precision = OFF;
}	

size_t	ft_analyze_fmt(const char *fmt, t_stock *lst)
{
	size_t	i;
	size_t	len_fmt;

	len_fmt = ft_strlen(fmt);
	i = 0;
	while (i < len_fmt)
	{
		ft_init_lst(lst);
		if (fmt[i] == '%')
		{
			i++;
			ft_analyze_flag(fmt, lst, &i);
			if (lst->status == ERROR)
				return (ERROR);
			ft_analyze_speci(fmt, lst, i);
			i++;
		}
		else
		{
			lst->total_len += write(1, &fmt[i], 1);
			i++;
		}
	}
	return (lst->total_len);
}
