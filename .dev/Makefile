NAME = libftprintf.a
SRC = ft_printf.c \
			ft_analyze.c \
			ft_push.c \
			ft_write.c \
			ft_print_char.c

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
