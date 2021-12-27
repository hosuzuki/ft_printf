#include "ft_printf.h"

int	ft_analyze_fmt(const char *fmt, va_list *args, t_analyze *analyze);

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
	free(analyze.buffer);
	return (0);//(len);
}
