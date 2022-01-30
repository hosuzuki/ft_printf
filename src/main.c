#include "ft_printf.h"

int main(void)
{

	ft_printf("s is : %s\n", "abcde");
	ft_printf("a\n");

	ft_printf("[%-10d]\n", 1);
	printf("[%-10d]\n", 1);
	ft_printf("[%010d]\n", 1);
	printf("[%010d]\n", 1);
	
	ft_printf("%+d\n", 1);
	printf("%+d\n", 1);
	ft_printf("%+d\n", 0);
	printf("%+d\n", 0);

	ft_printf("[% d]\n", 1);
	printf("[% d]\n", 1);
	ft_printf("[%.10d]\n", 1);
	printf("[%.10d]\n", 1);
	ft_printf("[%.10d]\n", -1);
	printf("[%.10d]\n", -1);



	ft_printf("[%+10d]\n", 123);
	printf("[%+10d]\n", 123);
	ft_printf("[%10d]\n", 123);
	printf("[%10d]\n", 123);

	char *s = "abcde";
	char *n = NULL;

	ft_printf("%p\n", s);
	printf("%p\n", s);
	ft_printf("%p\n", n);
	printf("%p\n", n);

	ft_printf("[%-15p]\n", s);
	printf("[%-15p]\n", s);
	ft_printf("[%3p]\n", s);
	printf("[%3p]\n", s);
	/*
 * ft_printf("%#p\n", s);
	printf("%#p\n", s); //reuslts in undefined behavior
	ft_printf("% p\n", s);
	printf("% p\n", s);// results in undefined behavior
	ft_printf("%0p\n", s);
	printf("%0p\n", s); //results in undefined behavior
	ft_printf("%+p\n", s);
	printf("%+p\n", s); // results in undefined behavior
*/
	ft_printf("[%20p]\n", s);
	printf("[%20p]\n", s);
//	ft_printf("[%.20p]\n", s);
//	printf("[%.20p]\n", s); // reuslts in undefined behavior
	ft_printf("%%,%d\n", 123);
	printf("%%,%d\n", 123);

	ft_printf("[%10u]\n", 1);
	printf("[%10u]\n", 1);
	ft_printf("[%10u]\n", -1);
	printf("[%10u]\n", -1);

	ft_printf("[%10x]\n", 108);
	printf("[%10x]\n", 108);
	

	ft_printf("%#x\n", 108); 
	printf("%#x\n", 108); 
//	printf("% x\n", 108);// results in undefined behavior
	ft_printf("%0x\n", 108); //results in undefined behavior
	printf("%0x\n", 108); //results in undefined behavior
//	printf("%+x\n", 108); // results in undefined behavior
	printf("%-x\n", 108);
	printf("[%-10.10x]\n", 108); //000
	printf("[%10x]\n", 108);
	printf("[%.10x]\n", 108); //000
	printf("[%-10x]\n", 108);
	printf("[%-.10x]\n", 108); // 000
	printf("[%5.10x]\n", 108); // 000
	printf("[%15.10x]\n", 108); // 000
	printf("[%-15.10x]\n", 108); // 000

	return (0);
}
