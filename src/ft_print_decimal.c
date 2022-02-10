/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/10 15:33:16 by hokutosuz        ###   ########.fr       */
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
	if (lst->sign != MINUS)
		ft_print_space(lst, len);
	if (lst->left_align == OFF)
		ft_print_wid_pre(lst, len);
	ft_print_sign(lst);
	ft_print_zero_pad(lst, len);
	if (res[0] == '-')
		ft_write(lst, res + 1, len - 1);
	else
		ft_write(lst, res, len);
	ft_print_left_align_space(lst);
	free (res);
}
