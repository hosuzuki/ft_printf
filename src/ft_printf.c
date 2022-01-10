#include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
	va_list args;
	char *buffer;

	va_start(args, fmt);
//	ft_analyze_fmt(fmt);
	buffer = va_arg(args, char *);
	printf("%s\n", buffer);
	va_end(args);
	return (0);
}

int main(void)
{
	ft_printf("a", "abcde");
	return (0);
}
