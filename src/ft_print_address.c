#include "ft_printf.h"
#include "libft.h"

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

void	ft_ptr_to_ascii(uintptr_t dec, char *ascii, t_stock *lst)
{
	const char	hex[16] = "0123456789abcdef";
	int			done;

	done = lst->len;
	ascii[done--] = '\0';
	while (dec >= 16)
	{
		ascii[done] = hex[(int)(dec % 16)];
		dec /= 16;
		done --;
	}
	ascii[done--] = hex[(int)dec];
}

void	ft_print_address(t_stock *lst, uintptr_t address)
{
	char	ascii[16 + 1];

	if (!address && !lst->precision)
	{
		lst->len = 0;
		ascii[0] = '\0';
	}
	else if (!address)
	{
		lst->len = 1;
		ascii[0] = '0';
		ascii[1] = '\0';
	}
	else
	{
		lst->len = hex_len(address);
		ft_ptr_to_ascii(address, ascii, lst);
	}
//	lst->status = push(parsed, parsed->format, "0x\0", ascii);
}

