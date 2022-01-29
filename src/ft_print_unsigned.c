#include "ft_printf.h"
#include "libft.h"

static int	count_digits(unsigned n)
{
	int	i;

	i = 1;
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	to_alpha(char *res, int n, int *i)
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

char	*ft_itoa_unsigned(unsigned int n)
{
	int		digits;
	char	*res;
	int		i;

	digits = count_digits(n);
	res = ft_calloc(digits + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	to_alpha(res, n, &i);
	res[i] = '\0';
	return (res);
}

void ft_print_unsigned(t_stock *lst, unsigned int un_signed)
{
	int len;
	unsigned int tmp;
	char	*res;

	tmp = un_signed;
	len = 1;
	while (10 < tmp)
	{
		tmp = tmp / 10;
		len++;
	}
	res = ft_itoa_unsigned(un_signed);
	if (res[0] == '-')
		lst->sign = MINUS;
	ft_print_space(lst, len);
	ft_print_sign(lst);
	ft_print_space(lst, len);
	ft_print_zero_pad(lst, len);
	if (res[0] == '-')
		write(1, ++res, len);
	else 
		write(1, res, len);
	lst->total_len += len;
	ft_print_left_align(lst, len);
}
