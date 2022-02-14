/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/14 16:48:37 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_print_decimal(t_stock *lst, int decimal)
{
	int		len;
	char	*res;

	res = ft_itoa(decimal);
	if (!res)
	{
		lst->status = ERROR;
		return ;
	}
	len = ft_strlen(res);
	if (decimal < 0)
		lst->sign = MINUS;
	if (lst->sign != MINUS)
		ft_print_space(lst, len);
	if (lst->left_align == OFF)
		ft_print_wid_pre(lst, len);
	ft_print_sign(lst);
	if (lst->left_align == OFF || lst->width <= lst->precision)
		ft_print_zero_pad(lst, len);
	if (res[0] == '-')
		ft_write(lst, res + 1, len - 1);
	else if (lst->precision != 0 || decimal != 0)
		ft_write(lst, res, len);
	if (0 < lst->width && lst->precision == 0 && decimal == 0)
		ft_write(lst, " ", 1);
	ft_print_left_align_space(lst);
	free (res);
}
