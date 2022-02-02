/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/02 21:10:30 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_print_space_ad(t_stock *lst, int len)
{
	if (lst->width > 0)
	{
		while (lst->width - len > 0)
		{
			write(1, " ", 1);
			lst->width--;
			lst->total_len++;
		}
	}
}

static char	*ft_dtoa(size_t	nbr, char	*base, size_t len)
{
	static size_t	i;
	static char		res[20];

	res[0] = '0';
	res[1] = 'x';
	i = 2;
	if (nbr < 0)
	{
		res[i++] = '-';
		ft_dtoa(-nbr, base, len);
		return (res);
	}
	else
	{
		if (nbr >= len)
		{
			ft_dtoa(nbr / len, base, len);
		}
		res[i++] = base[nbr % len];
		res[i] = '\0';
		return (res);
	}
}

void	ft_print_address(t_stock *lst, size_t address)
{
	int		len;
	char	*add;

	if (lst->zero_pad == ON || lst->hash == ON
		|| lst->sign != OFF || lst->precision != OFF)
	{
		lst->status = ERROR;
		return ;
	}
	add = ft_dtoa(address, "0123456789abcdef", 16);
	len = ft_strlen(add);
	if (lst->left_align == OFF)
	{
		ft_print_space_ad(lst, len);
		lst->total_len += write(1, add, len);
	}
	else
	{
		lst->total_len += write(1, add, len);
		ft_print_space_ad(lst, len);
	}
}
