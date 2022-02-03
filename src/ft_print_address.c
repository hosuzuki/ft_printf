/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/03 17:42:55 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static void	ft_print_space_address(t_stock *lst, int len)
{
	if (lst->width > 0)
	{
		while (0 < lst->width - len)
		{
			lst->total_len += write(1, " ", 1);
			lst->width--;
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
	if (len <= nbr)
		ft_dtoa(nbr / len, base, len);
	res[i++] = base[nbr % len];
	res[i] = '\0';
	return (res);
}

void	ft_print_address(t_stock *lst, size_t address)
{
	size_t	len;
	char	*res;

	if (lst->zero_pad == ON || lst->hash == ON
		|| lst->sign != OFF || lst->precision != OFF)
	{
		lst->status = ERROR;
		return ;
	}
	res = ft_dtoa(address, "0123456789abcdef", 16);
	len = ft_strlen(res);
	if (lst->left_align == OFF)
		ft_print_space_address(lst, len);
	lst->total_len += write(1, res, len);
//	if (lst->left_align == ON)
//		ft_print_space_address(lst, len);
	ft_print_left_align_space(lst, len);
}
