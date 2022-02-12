#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <limits.h>
#include <stdio.h>

void end(void)__attribute__((destructor));

void end(void)
{
	    system("leaks a.out");
}

int main(void)
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	printf(" --- Return : %d\n", PRINT("%3i, %3d, %3d, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c, e, d)); //T6



	printf(" => %d\n", printf("%.0d", 123));
	printf(" => %d\n", ft_printf("%.0d", 123));

	printf(" => %d\n", printf("%0.d", l));
	printf(" => %d\n", ft_printf("%0.d", l));

	printf(" => %d\n", printf("%0d", l));
	printf(" => %d\n", ft_printf("%0d", l));

	printf(" => %d\n", printf("%.d", l));
	printf(" => %d\n", ft_printf("%.d", l));
	(void)r;
	(void)n;
	(void)p;
	(void)u;
	(void)g;
	(void)b;
	(void)h;
	(void)q;
	(void)o;
	(void)t;
	(void)s;
	(void)a;
	(void)f;
	return (0);
}
