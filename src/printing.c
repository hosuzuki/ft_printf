/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:17 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/01 18:52:17 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static void ft_print_space_s(t_stock *lst, int len)
{
//	if (lst->sign != OFF)
//		lst->width--;
//	if (len == 0)
//		return;
	if (lst->space == OFF)
		return;
	if (lst->width > len)
	{
		while (lst->width - len > 0)
		{
			lst->total_len += write(1, " ", 1);
			lst->width--;
		}
	}
	else if (lst->precision != OFF && lst->width > lst->precision)
	{
		while (lst->width - lst->precision > 0)
		{
			lst->total_len += write(1, " ", 1);
			lst->width--;
		}
	}
}

void ft_print_str(t_stock *lst)
{
	char	*str;
	int len;

	str = va_arg(lst->args, char *);
	if (str == NULL)
	{
		lst->total_len += write(1, "(null)", 6);
		return ;
	}
	len = ft_strlen(str);
//	if (len == 0)
	//	return;
	if (lst->left_align == OFF)
		ft_print_space_s(lst, len);
//	if (lst->precision == 0)
		
	if (lst->precision >= len || lst->precision == OFF)
		lst->total_len += write(1, str, len);
	else if (lst->precision < len)
		lst->total_len += write(1, str, lst->precision);
//	else if (lst->precision > len)
//		lst->total_len += write(1, str, len);
	if (lst->left_align == ON)
		ft_print_space_s(lst, len);
}

void ft_print_char(t_stock *lst)
{
	int	c;
	
	c = va_arg(lst->args, int);
	if (lst->left_align == ON)
	{
		lst->total_len += write(1, &c, 1);
		ft_print_space(lst, 1);
	}
	else
	{
		ft_print_space(lst, 1);
		lst->total_len += write(1, &c, 1);
	}
}

/*void ft_print_p(t_stock *lst)
{

static int	hex_len(uintptr_t dec)
{
	int	len;

	len = 0;
	while (dec >= 16)
	{
		len ++;
		dec /= 16;
	}
	len ++;
	return (len);
}
*/
