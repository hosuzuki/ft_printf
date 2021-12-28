static int	ft_istype(const char fmt, va_list *args, t_analyze *analyze)
{
	analyze->type = fmt;
	if (fmt == 'c')
		print_char(va_arg(*args, int), parsed);
/*	else if (fmt == 's')
		print_string(va_arg(*args, char *), parsed);
	else if (fmt == 'p')
		print_address(va_arg(*args, uintptr_t), parsed);
	else if (fmt == 'd' || fmt == 'i')
		print_integer(va_arg(*args, int), parsed);
	else if (fmt == 'f')
		print_double(va_arg(*args, double), parsed);
	else if (fmt == 'u')
		print_unsigned(va_arg(*args, unsigned int), parsed);
	else if (fmt == 'x' || fmt == 'X')
		print_hex(va_arg(*args, unsigned int), parsed);
	else if (fmt == '%')
		print_percent(parsed);
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
		format->left_align = 1;
	else if (fmt == '0')
		format->zero_padding = 1;
	else if (fmt == '#')
		format->prefix_notation = 1;
	else if (fmt == '+')
		format->prefix_sign = 1;
	else if (fmt == ' ')
		format->prefix_space = 1;
	else
		return (0);
	return (1);
}

static int	ft_isformat(const char *fmt, va_list *args, t_analyze *analyze)
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
		if (fmt[i] == '%' && fmt[i + 1]) // what is the meaning of i + 1?
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

