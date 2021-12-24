NAME = libftprintf.a
PRINTF = ft_printf.c \
				main.c
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARC = ar rc
RAN = ranlib
RM = rm -f

$(NAME) : $(OBJ)
	cp libft.a $(NAME)
	$(ARC) $(NAME) $?
	$(RAN) $(NAME)

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONEY : all clean fclean re
