/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:10:30 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/02 21:10:30 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_print_char(t_stock *lst)
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
