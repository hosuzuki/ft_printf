/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:10:30 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/04 17:08:46 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_print_char(t_stock *lst, int c)
{
	if (lst->left_align == OFF)
		ft_print_space(lst, 1);
	lst->total_len += write(1, &c, 1);
	lst->width -= 1;
	//	if (lst->left_align == ON)
//		ft_print_space(lst, 1);
	ft_print_left_align_space(lst);
}
