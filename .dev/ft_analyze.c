static int	is_format(const char *input, va_list *args, t_analyze *analyze)
{
	int	done;

	done = 0;
	while (is_flags(input[done], analyze))
		done++;
	analyze.width = get_digit(input, &done, args);
	if (input[done] == '.')
	{
		done++;
		analyze.precision = get_digit(input, &done, args);
	}
	if (is_type(input[done], args, analyze))
		return (done + 1);
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

int	ft_analyze(const char *fmt, va_list *args, t_analyze *analyze)
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

