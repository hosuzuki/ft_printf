#include "ft_printf.h"

int	parse(const char *format, va_list *args, t_parsed *parsed);

int	ft_printf(const char *format, ...)
{
	t_parsed	parsed;
	va_list		args;
//	int			len;

	parsed.buffer = (char *)malloc(BUFSIZ);
	parsed.done = 0;
	if (!parsed.buffer)
		return (-1);
	va_start(args, format);
	printf("args is : %s\n", args);
	//len = parse(format, &args, &parsed);
	va_end(args);
//	if (len != 1 && parsed.done % BUFSIZ > 0)
//		write(1, parsed.buffer, parsed.done % BUFSIZ);
	free(parsed.buffer);
	return (0);//(len);
}
