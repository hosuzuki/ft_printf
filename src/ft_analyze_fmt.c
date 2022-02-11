/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_fmt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/11 11:16:16 by hokutosuz        ###   ########.fr       */
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

int	ft_analyze_speci(const char *fmt, t_stock *lst, size_t i)
{
	if (fmt[i] == 's')
		ft_print_str(lst, va_arg(lst->args, char *));
	else if (fmt[i] == 'c')
		ft_print_char(lst, va_arg(lst->args, int));
	else if (fmt[i] == 'p')
		ft_print_address(lst, (unsigned long long)va_arg(lst->args, void *));
	else if (fmt[i] == 'd' || fmt[i] == 'i')
		ft_print_decimal(lst, va_arg(lst->args, int));
	else if (fmt[i] == 'u')
		ft_print_unsigned(lst, va_arg(lst->args, unsigned int));
	else if (fmt[i] == 'x')
		ft_print_hex(lst, va_arg(lst->args, unsigned int));
	else if (fmt[i] == 'X')
		ft_print_hex_cap(lst, va_arg(lst->args, unsigned int));
	else if (fmt[i] == '%')
		if (ERROR == ft_write(lst, "%", 1))
			return (ERROR);
	if (lst->status == ERROR)
		return (ERROR);
	return (GOOD);
}

int	ft_analyze_flag(const char *fmt, t_stock *lst, size_t *i)
{
	while (ft_isflag(fmt[*i]) || ft_isdigit(fmt[*i]) || fmt[*i] == '.'
		|| fmt[*i] == '*')
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
		if (lst->status == ERROR)
			return (ERROR);
	}
	return (GOOD);
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

int	ft_analyze_fmt(const char *fmt, t_stock *lst)
{
	size_t	i;
	int		len;

	len = ft_strlen(fmt);
	i = 0;
	while (i < (size_t)len)
	{
		ft_init_lst(lst);
		if (fmt[i] == '%')
		{
			i++;
			if (ERROR == ft_analyze_flag(fmt, lst, &i))
				return (ERROR);
			if (ERROR == ft_analyze_speci(fmt, lst, i++))
				return (ERROR);
		}
		else
		{
			if (ERROR == ft_write(lst, (char *)&fmt[i], 1))
				return (ERROR);
			i++;
		}
	}
	return ((int)lst->total_len);
}
