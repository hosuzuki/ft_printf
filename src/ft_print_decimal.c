/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/04 17:13:03 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_print_decimal(t_stock *lst, int decimal)
{
	int		len;
	char	*res;

	res = ft_itoa(decimal);
	len = ft_strlen(res);
	if (decimal < 0)
		lst->sign = MINUS;
	if (lst->left_align == OFF)
		ft_print_wid_pre(lst, len);
	else if (lst->sign != MINUS)
		ft_print_space(lst, len);
	ft_print_sign(lst);
	ft_print_zero_pad(lst, len);
	if (res[0] == '-')
	{
		lst->total_len += write(1, res + 1, len - 1);
		lst->width -= (len - 1);
	}
	else
	{
		lst->total_len += write(1, res, len);
		lst->width -= len;
	}
	ft_print_left_align_space(lst);
	free (res);
}
