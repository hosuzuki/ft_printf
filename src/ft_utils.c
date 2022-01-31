#include "ft_printf.h"
#include "../libft/libft.h"

static int	count_digits(int n)
{
	int	i;

	i = 1;
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

static void	to_alpha(char *res, long long n, int *i)
{
	if (n > 9)
	{
		to_alpha(res, n / 10, i);
		to_alpha(res, n % 10, i);
	}
	else
		res[(*i)++] = '0' + n;
}

char	*ft_itoa_l(long long  n)
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
