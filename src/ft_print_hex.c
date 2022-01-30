#include "ft_printf.h"
#include "../libft/libft.h"

void ft_print_space_hex(t_stock *lst, int len)
{
	int space_len;
	
	space_len = lst->width;
	if (lst->hash == ON)
		space_len -= 2;
	if (0 < lst->precision)
		space_len -= lst->precision;
	else
		space_len -= len;
	while  (0 < space_len)
	{
		write(1, " ", 1);
		space_len--;
		lst->total_len++;
	}
}

static char *ft_dtoh(size_t	nbr, char	*base, size_t len)
{
	static ssize_t i;
	static char res[10];

	i = 0;
	if (nbr < 0)
	{
		res[i++] = '-';
		res[i] = '\0';
		ft_dtoh(-nbr, base, len);
		return (res);
	}
	else
	{
		if (nbr >= len)
		{
			ft_dtoh(nbr / len, base, len);
		}
		res[i++] = base[nbr % len];
		res[i] = '\0';
		return (res);
	}
}

void ft_print_zero_hex(t_stock *lst, int len)
{
	int zero_len;

	zero_len = lst->precision;
	if (lst->hash == ON)
		zero_len -= 2;
	zero_len -= len;
	while  (0 < zero_len)
	{
		write(1, "0", 1);
		zero_len--;
		lst->total_len++;
	}
}

void	ft_print_hex_cap(t_stock *lst, int decimal)
{
	int len;
	char *hex;

	if (lst->space == ON || lst->sign != OFF)
	{
		lst->status = ERROR;
		return ;
	}
	hex = ft_dtoh(decimal, "0123456789ABCDEF", 16);
	len = ft_strlen(hex);
	if (lst->left_align == OFF)
	{
		ft_print_space_hex(lst, len);
		ft_print_zero_hex(lst, len);
		if (lst->hash == ON)
			lst->total_len += write(1, "0x", 2);
		lst->total_len += write(1, hex, len);
	}
	else
	{
		ft_print_zero_hex(lst, len);
		if (lst->hash == ON)
			lst->total_len += write(1, "0x", 2);
		lst->total_len += write(1, hex, len);
		ft_print_space_hex(lst, len);
	}
}

void	ft_print_hex(t_stock *lst, int decimal)
{
	int len;
	char *hex;

	if (lst->space == ON || lst->sign != OFF)
	{
		lst->status = ERROR;
		return ;
	}
	hex = ft_dtoh(decimal, "0123456789abcdef", 16);
	len = ft_strlen(hex);
	if (lst->left_align == OFF)
	{
		ft_print_space_hex(lst, len);
		ft_print_zero_hex(lst, len);
		if (lst->hash == ON)
			lst->total_len += write(1, "0x", 2);
		lst->total_len += write(1, hex, len);
	}
	else
	{
		ft_print_zero_hex(lst, len);
		if (lst->hash == ON)
			lst->total_len += write(1, "0x", 2);
		lst->total_len += write(1, hex, len);
		ft_print_space_hex(lst, len);
	}
}
