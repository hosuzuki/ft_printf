#include "ft_printf.h"

int main(void)
{
	//ft_printf("s is : %s\n", "abcde");
	//ft_printf("a");

	ft_printf("[%-10d]\n", 1);
	printf("[%-10d]\n", 1);
	ft_printf("[%010d]\n", 1);
	printf("[%010d]\n", 1);

	/*
	ft_printf("%+d\n", 1);
	printf("%+d\n", 1);
	ft_printf("%+d\n", 0);
	printf("%+d\n", 0);

	ft_printf("[% d\n]", 1);
	printf("[% d\n]", 1);
*/
	return (0);
}
