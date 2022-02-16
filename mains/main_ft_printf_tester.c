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
	PRINT(" --- Return : %d\n", PRINT("[%0*d]\n", -4, 8)); //T23
	PRINT(" --- Return : %d\n", PRINT("[%-3.2d]\n", 8)); //T23
	PRINT(" --- Return : %d\n", PRINT("[%.*d]\n", -4, 8)); //T23
	PRINT(" --- Return : %d\n", PRINT("[%*d]\n", -4, 8)); //T23
	PRINT(" --- Return : %d\n", PRINT("[%4d]\n", -12)); //T23
	PRINT(" --- Return : %d\n", PRINT("[%10c]\n", 'b')); //T23
	PRINT("%\n");
	PRINT("%%%%%%%\n");
	return (0);
}
