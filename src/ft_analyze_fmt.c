#include "ft_printf.h"
#include "libft.h"

int ft_isflag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0')
		return (1);
	else
		return (0);
}

void ft_write_fmt(const char *fmt, size_t i)
{
	write(1, &fmt[i], 1);
}
void	ft_analyze_speci(const char *fmt, t_stock *lst,  size_t i)
{
	if (fmt[i] == 's')
		ft_print_str(lst);
	else if (fmt[i] == 'c')
		ft_print_char(lst);
	else if (fmt[i] == 'p')
		ft_print_address(lst, (size_t)va_arg(lst->args, void *));
	else if (fmt[i] == 'd')
		ft_print_decimal(lst, va_arg(lst->args, int));
	else if (fmt[i] == '%')
	{
		lst->total_len++;
		write(1, "%", 1);
	}
// have to take care of "cspdiuxX% 
	
}

int ft_analyze_flag(const char *fmt, t_stock *lst, size_t *i)
{
	if (ft_isflag(fmt[*i]))
	{
		while (ft_isflag(fmt[*i]))
		{
			if (fmt[*i] == '-')
				ft_left_align(fmt, lst, i);
			else if (fmt[*i] == '0')
				ft_zero_pad(fmt, lst, i);
			else if (fmt[*i] == '+')
				ft_sign(fmt, lst, i);
			else if (fmt[*i] == ' ')
				ft_space(fmt, lst, i);
	 		else if (fmt[*i] == '#')
				ft_hash(fmt, lst, i);
			if (lst->status == ERROR)
			{
				printf("ERROR\n");
				return (ERROR);
			}
		}
	}
	else
	{
		ft_width(fmt, lst, i);
		ft_precision(fmt, lst, i);
	}
	return (0);
}

void ft_init_lst(t_stock *lst)
{
	lst->status = OFF;
	lst->left_align = OFF;
	lst->zero_pad = OFF;
//	lst->notation = OFF;
	lst->hash = OFF;
	lst->sign = OFF;
	lst->space = OFF;
	lst->width = 0;
	lst->precision = 0;
}	

size_t ft_analyze_fmt(const char *fmt, t_stock *lst)
{
	size_t i;
	size_t len_fmt;

	len_fmt = ft_strlen(fmt);
	i = 0;
	while (i < len_fmt)
	{
		ft_init_lst(lst);
		if (fmt[i] == '%')
		{
			i++;
			ft_analyze_flag(fmt, lst, &i);
			if (lst->status == ERROR)
				return (ERROR);
			ft_analyze_speci(fmt, lst, i);
			i++;
		}
		else
		{
			ft_write_fmt(fmt, i);
			lst->total_len++;
			i++;
		}
	}
	return (lst->total_len);
}
