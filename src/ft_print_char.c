/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:10:30 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/10 13:41:24 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_print_char(t_stock *lst, int c)
{
	char chara;
	
	if (lst->left_align == OFF)
		ft_print_space(lst, 1);
	chara = (char)c;
	ft_write(lst, &chara, 1);
	ft_print_left_align_space(lst);
}
