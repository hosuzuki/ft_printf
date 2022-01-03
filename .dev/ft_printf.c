#include "ft_printf.h"

void	ft_init_format(t_analyze *analyze)
{
	analyze->len = 0; 
	analyze->flag_left_align = OFF;
	analyze->flag_zero_padding = OFF;
	analyze->flag_notation = OFF;
	analyze->flag_sign = OFF;
	analyze->flag_space = OFF;
	analyze->width = 0;
	analyze->precision = -1; //?
}

int	ft_analyze_fmt(const char *fmt, va_list *args, t_analyze *analyze)
{
	size_t i;
	int	j;

	i = 0;
	analyze->status = 1;
	while (!fmt[i] && analyze->done < INT_MAX) 
	{
		if (fmt[i] == '%' && fmt[i + 1]) // do i need i + 1?
		{
			if (fmt[i + 1] == '%')
				break;
			ft_init_format(analyze);
			j = ft_formatlen(&fmt[i + 1], args, analyze);
			if (j != 0)
			{
				if (analyze->status == -1)
					return (-1);
				i += j + 1;
				continue ;
			}
		}
		ft_write_char(fmt[i++], analyze);
	}
	if (analyze->done >= INT_MAX)
		return (-1);
	return (analyze->done);
}

int	ft_printf(const char *fmt, ...)
{
	t_analyze	*analyze;
	va_list		args;
	int			len;
	char	*tmp;

	analyze = NULL;
	tmp = (char *)malloc(BUFSIZ);
	//BUFSIZ = the size to be passed to setbuf
	analyze->buffer = tmp;
	analyze->done = 0;
	if (!analyze->buffer)
		return (-1);
	va_start(args, fmt);
//	printf("args is : %s\n", args); Cannot print
	len = ft_analyze_fmt(fmt, &args, analyze);
	va_end(args);
//	if (len != 1 && analyze->done % BUFSIZ > 0)
//		write(1, analyze->buffer, analyze->done % BUFSIZ);
	free(analyze->buffer);
	return (0);//(len);
}
