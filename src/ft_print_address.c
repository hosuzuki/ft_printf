/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/10 15:51:59 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static void	ft_print_space_address(t_stock *lst, int len)
{
	if (lst->width > 0)
	{
		while (0 < lst->width - len)
			ft_write(lst, " ", 1);
	}
}

static char	*ft_dtoa(unsigned long long nbr, char	*base, int len)
{
	static int	i;
	static char		res[20];

	res[0] = '0';
	res[1] = 'x';
	i = 2;
	if ((unsigned long long)len <= nbr)
		ft_dtoa(nbr / len, base, len);
	res[i++] = base[nbr % len];
	res[i] = '\0';
	return (res);
}

void	ft_print_address(t_stock *lst, unsigned long long address)
{
	int	len;
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
	ft_write(lst, res, len);
	ft_print_left_align_space(lst);
}
