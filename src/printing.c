/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:17 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/01/30 20:56:42 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void ft_print_str(t_stock *lst)
{
	char	*str;
	size_t len;

	str = va_arg(lst->args, char *);
	if (str == NULL)
	{
		lst->total_len += write(1, "(null)", 6);
		return ;
	}
	len = ft_strlen(str);
	if (lst->left_align == ON)
	{
		lst->total_len += write(1, str, len);
		ft_print_space(lst, len);
	}
	else
	{
		ft_print_space(lst, len);
		lst->total_len += write(1, str, len);
	}
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
