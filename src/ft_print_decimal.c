/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/02 21:10:30 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static int	ft_decimal_len(long long tmp)
{
	int	len;

	len = 1;
	while (10 <= tmp)
	{
		tmp /= 10;
		len++;
	}
	return (len);
}

void	ft_print_decimal(t_stock *lst, int decimal)
{
	int			len;
	long long	tmp;
	char		*res;

	tmp = (long long)decimal;
	if (decimal < 0)
	{
		lst->sign = MINUS;
		tmp *= -1;
	}
	len = ft_decimal_len(tmp);
	res = ft_itoa(decimal);
	if (lst->left_align == OFF)
		ft_print_space(lst, len);
	ft_print_sign(lst);
	ft_print_zero_pad(lst, len);
	if (res[0] == '-')
		lst->total_len += write(1, res + 1, len);
	else
		lst->total_len += write(1, res, len);
	ft_print_left_align(lst, len);
	free (res);
}
