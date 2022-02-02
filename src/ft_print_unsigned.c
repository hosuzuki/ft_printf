/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:16 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/02 21:10:31 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static int	count_digits(long n)
{
	int	i;

	i = 1;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	to_alpha(char *res, long n, int *i)
{
	if (n == INT_MIN)
	{
		to_alpha(res, n / 10, i);
		res[(*i)++] = '8';
	}
	else if (n < 0)
	{
		res[(*i)++] = '-';
		to_alpha(res, -n, i);
	}
	else if (n > 9)
	{
		to_alpha(res, n / 10, i);
		to_alpha(res, n % 10, i);
	}
	else
		res[(*i)++] = '0' + n;
}

char	*ft_itoa_unsigned(long n)
{
	int		len;
	char	*res;
	int		i;

	len = count_digits(n);
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	to_alpha(res, n, &i);
	res[i] = '\0';
	return (res);
}

void	ft_print_unsigned(t_stock *lst, unsigned int un_signed)
{
	int		len;
	long	tmp;
	char	*res;

	tmp = (long)un_signed;
	len = 1;
	while (10 <= tmp)
	{
		tmp = tmp / 10;
		len++;
	}
	res = ft_itoa_unsigned((long)un_signed);
	if (lst->left_align == OFF)
		ft_print_space(lst, len);
	ft_print_sign(lst);
	ft_print_zero_pad(lst, len);
	write(1, res, len);
	lst->total_len += len;
	ft_print_left_align(lst, len);
	free (res);
}
