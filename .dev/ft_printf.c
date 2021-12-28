#include "ft_printf.h"

void	ft_init_format(t_analyze *analyze)
{
	analyze->len = 0;
	analyze->left_align = 0;
	analyze->zero_padding = 0;
	analyze->prefix_notation = 0;
	analyze->prefix_sign = 0;
	analyze->prefix_space = 0;
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
			ft_init_format(analyze);
			j = ft_isformat(&fmt[i + 1], args, analyze);
			if (j != 0)
			{
				if (analyze->status == -1)
					return (-1);
				i += j;
				//i += j + 1;
				//continue ;
			}
		}
		i++;
//		push_char_to_analyze(fmt[i++], analyze);
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

	analyze->buffer = (char *)malloc(BUFSIZ);
	//BUFSIZ = the size to be passed to setbuf
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
