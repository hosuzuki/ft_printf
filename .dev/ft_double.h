#ifndef FT_DOUBLE_H
# define FT_DOUBLE_H

# include <math.h>
# include <float.h>
# include <stdint.h>
# include <strings.h>
# include <ft_printf.h>

# define DECIMAL_DIGIT 1074
# define INTEGER_DIGIT 308

# define EXP_BIAS 1023
# define EXP_MAX 2047

# define FRAC_BIT 52
# define EXP_BIT 11

typedef struct
{
	uint8_t		sign;
	uint16_t	exp;
	uint64_t	frac;
	int8_t		integer[INTEGER_DIGIT + 1];
	int8_t		decimal[DECIMAL_DIGIT + 1];
}	t_double;

void		array_add(int8_t *array, int8_t *n, int size);
void		array_division_by_two(int8_t *n, int size);
void		array_double(int8_t *n, int size);
t_double	ft_init_idouble(double num);
int			is_nan_or_inf(t_double *idouble, char *ascii);
void		frac_to_decimal(t_double *idouble, uint16_t exp, uint64_t frac);
void		frac_to_integer(t_double *idouble, uint16_t exp, uint64_t frac);

#endif
