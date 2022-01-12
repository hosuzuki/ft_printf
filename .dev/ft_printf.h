#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
#	include <stdarg.h> //for such as va_start
# include <stdlib.h>	//for free(), malloc
# include <limits.h> // for INT_MAX
//# include <stdint.h>

# include "libft.h"

# define ON 1
# define OFF 0

typedef struct list
{
	char		*buffer;
	size_t	done;
	int	status;
	char	type;
	int	len; //length of output
	int	flag_left_align;
	int	flag_zero_padding;
	int	flag_notation;
	int flag_sign;
	int flag_space;
	int	width;
	int	precision;
} t_analyze;

typedef struct
{
	size_t	padding;
	size_t	prefix;
	size_t	body;
	size_t	precision;
	size_t	sum;
}	t_length;

int	ft_printf(const char *fmt, ...);

//int		ft_printf(const char *input, ...);
int	ft_analyze_fmt(const char *fmt, va_list *args, t_analyze *analyze);
int	ft_formatlen(const char *fmt, va_list *args, t_analyze *analyze);
void	ft_write_char(char c, t_analyze *analyze);

void	ft_print_char(int c, t_analyze *analyze);
void	ft_print_string(char *string, t_analyze *analyze);
void	ft_print_address(uintptr_t dec, t_analyze *analyze);
void	ft_print_integer(int num, t_analyze *analyze);
void	ft_print_unsigned(unsigned int num, t_analyze *analyze);
void	ft_print_hex(unsigned int dec, t_analyze *analyze);
void	ft_print_double(double num, t_analyze *analyze);
void	ft_print_percent(t_analyze *analyze);

void	ft_push_to_analyze(char *str, int len, t_analyze *analyze);
void	ft_push_char_to_analyze(char ch, t_analyze *analyze);
void	ft_zero_padding(int size, t_analyze *analyze);
void	ft_space_padding(int size, t_analyze *analyze);

int		ft_push(t_analyze *analyze, char *prefix, char *str);
//int8_t	ft_add_prefix(t_format *format, int sign);
//void	ft_init_format(t_format *format);

#endif
