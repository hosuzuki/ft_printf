/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 07:14:49 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/10 07:10:10 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int	ft_intmax(t_stock *lst, long total, int len)
{
	if ((long)INT_MAX <= total + len)
	{
		lst->status = ERROR;
		return (ERROR);
	}
	return (GOOD);
}

int	ft_write(t_stock *lst, char	*content, int len)
{
	if (ERROR == ft_intmax(lst, lst->total_len, len))
		return (ERROR);
	lst->total_len += write(1, content, len);
	lst->width -= len;
	return (GOOD);
}
