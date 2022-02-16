/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/16 16:44:42 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static void	ft_print_wp_space(t_stock *lst, size_t len)
{
	long long	tmp;

	tmp = 0;
//	if (lst->sign != OFF)
//		tmp++;
	if (lst->zero_pad == ON && lst->width < lst->precision) 
		return ;
	if (lst->zero_pad == ON && lst->precision < 0)
		return ;
	//	else if (len < lst->width && lst->zero_pad == OFF)
//	if (len < lst->width && lst->zero_pad == OFF)
	if ((long long)len < lst->width)
	{
		if (0 < lst->precision && 0 < lst->width - lst->precision && lst->sign == MINUS)
		 tmp += lst->width - lst->precision;
//		if (lst->precision < (long long)len)
//			tmp += len;
		else if (0 < lst->precision && (long long)len < lst->precision)
			tmp += lst ->precision;
		else
			tmp += len;
		while (0 < lst->width - tmp)
			ft_write(lst, " ", 1);
	}
//	else if (0 < lst->precision && lst->precision < lst->width)
	else if (0 < lst->precision && lst->precision < lst->width && (long long)len < lst->width)
	{
//		if (lst->sign == MINUS)
	//		tmp++;
		tmp += lst->precision;
		while (0 < lst->width - tmp)
			ft_write(lst, " ", 1);
	}
}

void	ft_print_decimal(t_stock *lst, int decimal)
{
	size_t	len;
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
	if (lst->left_align == OFF && lst->precision < lst->width)
		ft_print_wp_space(lst, len);
	ft_print_sign(lst);

//if (lst->width <= lst->precision)
//	if (lst->left_align == OFF || lst->width <= lst->precision)
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
