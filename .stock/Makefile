NAME = libftprintf.a
SRC_PATH = ./srcs/
LIBFT_PATH = ./libft/
HEADER = ./includes/
SRC_FILES =	ft_printf.c \
						

SRC = $(apprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I $(HEADER)
ARC = ar rc
RAN = ranlib
RM = rm -f
LIBFT_MAKE = make -C $(LIBFT_PATH)

$(NAME) : $(OBJ) $(LIBFT_MAKE)
#	cp $(LIBFT_PATH)libft.a $(NAME)
	$(ARC) $(NAME) $?
	$(RAN) $(NAME)

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean: 
	$(LIBFT_MAKE) clean
	$(RM) $(OBJ)

fclean : clean
	$(LIBFT_MAKE) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
