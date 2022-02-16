/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 07:14:49 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/16 08:05:01 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_intmax(t_stock *lst, size_t total, size_t len)
{
	if (len <= 0)
		return (GOOD);
	if ((size_t)INT_MAX <= total + len)
	{
		lst->status = ERROR;
		return (ERROR);
	}
	return (GOOD);
}

int	ft_write(t_stock *lst, char	*content, size_t len)
{
	if (ERROR == ft_intmax(lst, lst->total_len, len))
		return (ERROR);
	lst->total_len += write(1, content, len);
	lst->width -= len;
	return (GOOD);
}
