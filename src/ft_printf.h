#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define ERROR -1
#	define OFF 0
# define ON  1
# define PLUS 2
# define MINUS -2

typedef struct
{
	va_list	args;
	size_t total_len;
	//char	type;
	int status;
	int left_align;
	int zero_pad;
	int notation;
	int hash;
	int sign;
	int space;
//	int	flag;
	int width;
	int	precision;

	size_t len;
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
size_t	ft_analyze_fmt(const char *fmt, t_stock *lst);
void ft_print_str(t_stock *lst);
void ft_print_char(t_stock *lst);
void	ft_print_address(t_stock *lst, uintptr_t address);

void ft_print_decimal(t_stock *lst, int decimal);
void ft_left_align(const char *fmt, t_stock *lst, size_t *i);
void ft_zero_pad(const char *fmt, t_stock *lst, size_t *i);
void ft_sign(const char *fmt, t_stock *lst, size_t *i);
void ft_space(const char *fmt, t_stock *lst, size_t *i);
void ft_hash(const char *fmt, t_stock *lst, size_t *i);
void ft_precision(const char *fmt, t_stock *lst, size_t *i);
void ft_width(const char *fmt, t_stock *lst, size_t *i);


#endif
