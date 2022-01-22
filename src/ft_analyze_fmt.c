#include "ft_printf.h"
#include "libft.h"

void ft_write_fmt(const char *fmt, size_t i)
{
	write(1, &fmt[i], 1);
}
void	ft_analyze_speci(const char *fmt, t_stock lst, va_list args, size_t i)
{
	if (fmt[i] == 's')
		ft_print_str(lst, args);
	else if (fmt[i] == 'c')
		ft_print_char(lst, args);
	else if (fmt[i] == 'p')
		ft_print_address(lst, va_arg(args, uintptr_t));
}

void ft_analyze_flag(const char *fmt, t_stock lst, va_list args, size_t i)
{
	if (fmt[i] == '-')
	{
		i++;

	if (fmt[i] == '0')
	if (fmt[i] == '.')
	if (fmt[i] == ' ')
	if (fmt[i] == '#')
	if (fmt[i] == '+')

}

void ft_analyze_fmt(const char *fmt, t_stock lst, va_list args)
{
	size_t i;
	size_t len_fmt;

	len_fmt = ft_strlen(fmt);
	i = 0;
	while (i < len_fmt)
	{
		if (fmt[i] == '%')
		{
			ft_analyze_flag(fmt, lst, args, ++i);
			ft_analyze_speci(fmt, lst, args, ++i);
		}
		else
		{
			ft_wirte_fmt(fmt, i);
			lst.total_len++;
		}
		i++;
	}
}
