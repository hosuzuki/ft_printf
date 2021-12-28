static int	ft_istype(const char fmt, va_list *args, t_analyze *analyze)
{
	analyze->type = fmt;
	if (fmt == 'c')
		ft_print_char(va_arg(*args, int), analyze);
/*	else if (fmt == 's')
		print_string(va_arg(*args, char *), analyze);
	else if (fmt == 'p')
		print_address(va_arg(*args, uintptr_t), analyze);
	else if (fmt == 'd' || fmt == 'i')
		print_integer(va_arg(*args, int), analyze);
	else if (fmt == 'f')
		print_double(va_arg(*args, double), analyze);
	else if (fmt == 'u')
		print_unsigned(va_arg(*args, unsigned int), analyze);
	else if (fmt == 'x' || fmt == 'X')
		print_hex(va_arg(*args, unsigned int), analyze);
	else if (fmt == '%')
		print_percent(analyze);
*/
	else
		return (0);
	return (1);
}

static int	ft_save_digit(const char *fmt, int *i, va_list *args)
{
	int	digit; // why int?

	digit = 0;
	if (fmt[*i] == '*')
	{
		(*i)++;
		return (va_arg(args, int));
	}
	while (ft_isdigit(fmt[*i]))
	{
		digit *= 10;
		digit += fmt[(*i)++] - '0';
	}
	return (digit);
}

static int	ft_isflag(const char fmt, t_analyze *analyze)
{
	if (fmt == '-')
		analyze->flag_left_align = 1; //chang it to ON?
	else if (fmt == '0')
		analyze->flag_zero_padding = 1;
	else if (fmt == '#')
		analyze->flag_notation = 1;
	else if (fmt == '+')
		analyze->flag_sign = 1;
	else if (fmt == ' ')
		analyze->flag_space = 1;
	else
		return (0);
	return (1);
}

static int	ft_formatlen(const char *fmt, va_list *args, t_analyze *analyze)
{
	int	i;

	i = 0;
	while (ft_isflag(fmt[i], analyze))
		i++;
	analyze->width = ft_save_digit(fmt, &i, args);
	if (fmt[i] == '.')
	{
		i++;
		analyze->precision = ft_save_digit(fmt, &i, args);
	}
	if (ft_istype(fmt[i], args, analyze))
		return (i + 1);
	return (0);
}
