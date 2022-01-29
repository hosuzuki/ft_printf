#include "ft_printf.h"
#include "libft.h"

void ft_print_space_ad(t_stock *lst, int len)
{
	if (lst->width > 0)
	{
		while (lst->width - len > 0)
		{
			write(1, " ", 1);
			lst->width--;
			lst->total_len++;
		}
	}
}

static ssize_t	ft_putnbr_base_r(size_t	nbr, char	*base, size_t len)
{
	static ssize_t total;
	
	total = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		total++;
		ft_putnbr_base_r(-nbr, base, len);
	}
	else
	{
		if (nbr >= len)
		{
			ft_putnbr_base_r(nbr / len, base, len);
		}
		write(1, &base[nbr % len], 1);
		total++;
		return (total);
	}
	return (-1);
}

void	ft_print_address(t_stock *lst, size_t address)
{
	if (lst->zero_pad == ON || lst->hash == ON ||
			lst->sign != OFF || lst->precision != OFF)
	{
		lst->status = ERROR;
		return ;
	}
	if (lst->left_align == OFF)
	{
		ft_print_space_ad(lst, 11);
		lst->total_len += write(1, "0x", 2);
		lst->total_len += ft_putnbr_base_r(address, "0123456789abcdef", 16);
	}
	else
	{
		lst->total_len += write(1, "0x", 2);
		lst->total_len += ft_putnbr_base_r(address, "0123456789abcdef", 16);
		ft_print_space_ad(lst, 11);
	}
}
