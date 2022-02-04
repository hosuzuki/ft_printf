/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/04 14:44:01 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

/*
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
*/

void	ft_print_decimal(t_stock *lst, int decimal)
{
	int			len;
	char		*res;

	if (decimal < 0)
		lst->sign = MINUS;
	res = ft_itoa(decimal);
	len = ft_strlen(res);
	if (decimal < 0)
		len--;
	if (lst->left_align == OFF && lst->sign != MINUS)
		ft_print_space(lst, len);
	ft_print_sign(lst);
	ft_print_zero_pad(lst, len);
	if (res[0] == '-')
//	if (decimal < 0)
		lst->total_len += write(1, res + 1, len);
	else
		lst->total_len += write(1, res, len);
	ft_print_left_align_space(lst, len);
	free (res);
}
