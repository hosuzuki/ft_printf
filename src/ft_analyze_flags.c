/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/16 07:47:01 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

void	ft_hash(t_stock *lst, size_t *i)
{
	(*i)++;
	lst->hash = ON;
}

void	ft_space(t_stock *lst, size_t *i)
{
	(*i)++;
	lst->space = ON;
}

void	ft_sign(t_stock *lst, size_t *i)
{
	(*i)++;
	lst->sign = PLUS;
}

void	ft_zero_pad(t_stock *lst, size_t *i)
{
	(*i)++;
	lst->zero_pad = ON;
}

void	ft_left_align(t_stock *lst, size_t *i)
{
	(*i)++;
	lst->left_align = ON;
}
