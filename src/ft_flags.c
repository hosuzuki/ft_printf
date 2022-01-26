#include "ft_printf.h"
#include "libft.h"

void ft_space(t_stock *lst, size_t *i)
{
	if (lst->sign == ON || lst->hash == ON)
	{
		lst->status = ERROR;
		return ;
	}
	(*i)++;
	lst->space = ON;
}

void ft_sign(t_stock *lst, size_t *i)
{
	if (lst->left_align > 0)
	{
		lst->status = ERROR;
		return ;
	}
	(*i)++;
	lst->sign = ON;
}

void ft_zero_pad(const char *fmt, t_stock *lst, size_t *i)
{
	size_t len;

	if (lst->left_align > 0)
	{
		lst->status = ERROR;
		return ;
	}
	(*i)++;
	len = 0;
	while (ft_isdigit(fmt[*i]))
	{
		len *= 10;
		len += (fmt[*i] - '0');
		(*i)++;
	}
	lst->zero_pad = len;
}

void ft_left_align(const char *fmt, t_stock *lst, size_t *i)
{
	size_t len;
	
	if (lst->zero_pad == ON)
	{
		lst->status = ERROR;
		return ;
	}
	(*i)++;
	len = 0;
	while (ft_isdigit(fmt[*i]))
	{
		len = len * 10;
		len = len + (fmt[*i] - '0');
		(*i)++;
	}
	lst->left_align = len;
}
