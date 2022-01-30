#include "ft_printf.h"
#include "libft.h"

void ft_print_str(t_stock *lst)
{
	char	*str;
	size_t len;

	str = va_arg(lst->args, char *);
	len = ft_strlen(str);
	write(1, str, len);
	lst->total_len = lst->total_len + len;
}

void ft_print_char(t_stock *lst)
{
	int	c;
	
	c = va_arg(lst->args, int);
	write(1, &c, 1);
	lst->total_len++;
}

/*void ft_print_p(t_stock *lst)
{

static int	hex_len(uintptr_t dec)
{
	int	len;

	len = 0;
	while (dec >= 16)
	{
		len ++;
		dec /= 16;
	}
	len ++;
	return (len);
}
*/
