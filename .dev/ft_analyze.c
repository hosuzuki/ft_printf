static int	get_digit(const char *fmt, int *i, va_list *args)
{
	int	digit;

	digit = 0;
	if (fmt[*i] == '*')
	{
		(*i)++;
		return (va_arg(*args, int));
	}
	while (ft_isdigit(fmt[*i]))
	{
		digit *= 10;
		digit += fmt[(*i)++] - '0';
	}
	return (digit);
}

static int	is_flag(const char fmt, t_analyze *analyze)
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

static int	is_format(const char *fmt, va_list *args, t_analyze *analyze)
{
	int	i;

	i = 0;
	while (is_flag(fmt[i], analyze))
		i++;
	analyze->width = get_digit(fmt, &i, args);
	if (fmt[i] == '.')
	{
		i++;
		analyze->precision = get_digit(fmt, &i, args);
	}
	if (is_type(fmt[i], args, analyze))
		return (i + 1);
	return (0);
}

void	init_format(t_analyze *analyze)
{
	analyze->len = 0;
	analyze->left_align = 0;
	analyze->zero_padding = 0;
	analyze->prefix_notation = 0;
	analyze->prefix_sign = 0;
	analyze->prefix_space = 0;
	analyze->width = 0;
	analyze->precision = -1;
}

int	ft_analyze_fmt(const char *fmt, va_list *args, t_analyze *analyze)
{
	size_t i;
	int	j;

	i = 0;
	analyze->status = 1;
	while (!fmt[i] && analyze->done < INT_MAX) 
	{
		if (fmt[i] == '%' && fmt[i + 1])
		{
			init_format(analyze);
			j = is_format(&fmt[i + 1], args, analyze);
			if (j != 0)
			{
				if (analyze->status == -1)
					return (-1);
				paarse_done += j + 1;
				continue ;
			}
		}
		push_char_to_analyze(fmt[i++], analyze);
	}
	if (analyze->done >= INT_MAX)
		return (-1);
	return (analyze->done);
}

