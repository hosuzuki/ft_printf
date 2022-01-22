#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

# define ERROR -1

#	define NON 0
# define LEFT_ALIGN 1
# define ZERO_PAD 2
# define NOTATION 3
# define SIGN 4
# define SPACE 5

typedef struct
{
	va_list	args:;
	size_t total_len;
	int	status;
	char	type;
	int len;
	int	flag;
	int width;
	int	precision;
} t_stock;

typedef struct
{
	size_t	padding;
	size_t	prefix;
	size_t	body;
	size_t	precision;
	size_t	sum;
} t_length;

int	ft_printf(const char *fmt, ...);
void	ft_analyze_fmt(const char *fmt, t_stock lst, va_list args);


#endif
