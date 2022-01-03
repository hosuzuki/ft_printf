#include "ft_printf.h"
#include "ft_double.h"

static int	ft_isint(char type)
{
	return (type == 'd' || type == 'i' || type == 'o' || \
			type == 'u' || type == 'x' || type == 'X');
}

static int	ft_isdouble(char type)
{
	return (type == 'a' || type == 'A' || \
			type == 'e' || type == 'E' || \
			type == 'f' || type == 'F');
}

static void	ft_save_length(t_length *length, t_analyze *analyze)
{
	length->body = analyze->len;//do i need this?
	length->precision = 0;
	if ((ft_isint(analyze->type) || analyze->type == 'p') \
		&& analyze->precision >= 0)
	{
		analyze->flag_zero_padding = 0;// do i need this?
		if (analyze->precision > analyze->len)
			length->precision = analyze->precision - analyze->len;
	}
	else if (ft_isdouble(analyze->type) && analyze->precision > DECIMAL_DIGIT)
		length->precision = analyze->precision - DECIMAL_DIGIT;
	length->sum = length->prefix + length->body + length->precision;
	length->padding = 0;
	if ((size_t)analyze->width > length->sum)
		length->padding = analyze->width - length->sum;
	length->sum += length->padding;
}

int	ft_push(t_analyze *analyze, char *prefix, char *body)
{
	t_length	*length;

	(void)body;
	length = NULL;
	length->prefix = ft_strlen(prefix);
	ft_save_length(length, analyze);
	if (analyze->done + length->sum >= INT_MAX)
		return (-1);
/*	if (!analyze->left_align && !analyze->flag_zero_padding && length->padding >= 0)
		space_padding(length.padding, analyze);
	push_to_analyze(prefix, length.prefix, analyze);
	if (!analyze.left_align && analyze.flag_zero_padding && length.padding >= 0)
		flag_zero_padding(length.padding, analyze);
	if ((is_integer(analyze.type) || analyze.type == 'p') \
		&& length.precision >= 0)
		flag_zero_padding(length.precision, analyze);
	push_to_analyze(body, length.body, analyze);
	if (is_double(analyze.type))
		flag_zero_padding(length.precision, analyze);
	if (analyze.left_align && length.padding >= 0)
		space_padding(length.padding, analyze);
*/
	return (1);
}
