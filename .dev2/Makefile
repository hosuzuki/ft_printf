NAME = libftprintf.a
SRC = ft_printf.c \
			ft_analyze_fmt.c \
			ft_flags.c \
			ft_print_address.c \
			ft_print_decimal.c \
			ft_print_unsigned.c \
			ft_print_hex.c \
			printing.c 

OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
ARC = ar rc
RAN = ranlib
RM = rm -f

$(NAME) : $(OBJ)
	cp libft.a $(NAME)
	$(ARC) $(NAME) $(OBJ)
	$(RAN) $(NAME)
	$(CC) $(CFLAGS) $(NAME) main.c

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONEY : all clean fclean re
