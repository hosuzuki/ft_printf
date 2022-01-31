/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:16 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/01/31 16:17:54 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void ft_print_space_hex(t_stock *lst, int len)
{
	
	if (lst->hash == ON)
		lst->width -= 2;
	if (0 < lst->precision)
		lst->width -= lst->precision;
//	else
//		lst->width -= len;
	if (lst->width > 0 && lst->zero_pad == OFF)
	{
		while  (0 < lst->width - len)
		{
			lst->total_len += write(1, " ", 1);
			lst->width--;
		}
	}
}

static char *ft_dtoh(size_t	nbr, char	*base, size_t len)
{
	static ssize_t i;
	static char res[10];

	i = 0;
	if (nbr < 0)
	{
		res[i++] = '-';
		res[i] = '\0';
		ft_dtoh(-nbr, base, len);
		return (res);
	}
	else
	{
		if (nbr >= len)
		{
			ft_dtoh(nbr / len, base, len);
		}
		res[i++] = base[nbr % len];
		res[i] = '\0';
		return (res);
	}
}

void ft_print_zero_hex(t_stock *lst, int len)
{
	if (lst->precision > lst->width)
		 lst-> width =  lst->precision;
	if (lst->hash == ON)
		lst->width -= 2;
	while  (0 < lst->width - len)
	{
		lst->total_len += write(1, "0", 1);
		lst->width--;;
	}
}

void	ft_print_hex_cap(t_stock *lst, unsigned int decimal)
{
	int len;
	char *hex;

	if (lst->space == ON || lst->sign != OFF)
	{
		lst->status = ERROR;
		return ;
	}
	hex = ft_dtoh(decimal, "0123456789ABCDEF", 16);
	len = ft_strlen(hex);
	if (lst->left_align == OFF)
	{
		ft_print_space_hex(lst, len);
		ft_print_zero_hex(lst, len);
		if (lst->hash == ON)
		{
			lst->total_len += write(1, "0x", 2);
			lst->width -= 2;
		}
		lst->total_len += write(1, hex, len);
	}
	else
	{
		ft_print_zero_hex(lst, len);
		if (lst->hash == ON)
		{
			lst->total_len += write(1, "0x", 2);
			lst->width -= 2;
		}
		lst->total_len += write(1, hex, len);
		ft_print_space_hex(lst, len);
	}
}

void	ft_print_hex(t_stock *lst, unsigned int decimal)
{
	int len;
	char *hex;

	if (lst->space == ON || lst->sign != OFF)
	{
		lst->status = ERROR;
		return ;
	}
	hex = ft_dtoh(decimal, "0123456789abcdef", 16);
	len = ft_strlen(hex);
	if (lst->left_align == OFF)
	{
		ft_print_space_hex(lst, len);
		ft_print_zero_hex(lst, len);
		if (lst->hash == ON)
			lst->total_len += write(1, "0x", 2);
		lst->total_len += write(1, hex, len);
	}
	else
	{
		ft_print_zero_hex(lst, len);
		if (lst->hash == ON)
			lst->total_len += write(1, "0x", 2);
		lst->total_len += write(1, hex, len);
		ft_print_space_hex(lst, len);
	}
}
