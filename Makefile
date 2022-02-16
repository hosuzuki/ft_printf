NAME = libftprintf.a
SRC_F = ft_printf.c \
			ft_analyze_fmt.c \
			ft_turnon_flags.c \
			ft_save_width_preci.c \
			ft_print_address.c \
			ft_print_char.c \
			ft_print_decimal.c \
			ft_print_unsigned.c \
			ft_print_hex.c \
			ft_print_str.c \
			ft_print_flags.c \
			ft_write_utils.c
SRC_D = ./src/
SRC = $(addprefix $(SRC_D), $(SRC_F))
OBJ = $(SRC:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
HEAD = -I ./includes/
ARC = ar rc
RAN = ranlib
RM = rm -f

$(NAME) : $(OBJ)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(ARC) $(NAME) $(OBJ)
	$(RAN) $(NAME)

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) $(HEAD)

clean :
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re : fclean all

bonus :

.PHONEY : all clean fclean re bonus
