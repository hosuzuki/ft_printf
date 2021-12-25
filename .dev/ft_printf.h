#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
#	include <stdarg.h> //for such as va_start
# include <stdlib.h>	//for free(), malloc

typedef struct s_format
{
	int	len;
	char	type;
	int	left_align;
	int	zero_padding;
	int	prefix_notation;
	int	prefix_sign;
	int	prefix_space;
	int	width;
	int	precision;
}	t_format;

typedef struct s_parsed
{
	char		*buffer;
	size_t	done;
	int	status;
	t_format format;
} t_parsed;

typedef struct s_push
{
	size_t	padding;
	size_t	prefix;
	size_t	body;
	size_t	precision;
	size_t	sum;
}	t_push;

int		ft_printf(const char *input, ...);
void	print_char(int c, t_parsed *parsed);
void	print_string(char *string, t_parsed *parsed);
void	print_address(uintptr_t dec, t_parsed *parsed);
void	print_integer(int num, t_parsed *parsed);
void	print_unsigned(unsigned int num, t_parsed *parsed);
void	print_hex(unsigned int dec, t_parsed *parsed);
void	print_double(double num, t_parsed *parsed);
void	print_percent(t_parsed *parsed);

#endif
