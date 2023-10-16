NAME = libftprintf.a
SRC_FILES = ft_printf.c \
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
SRC_DIRECTORY = ./srcs/
SRCS = $(addprefix $(SRC_DIRECTORY), $(SRC_FILES))
OBJDIR = objs/
OBJS = $(patsubst $(SRC_DIRECTORY)%.c, $(OBJDIR)%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)
INC = includes/

# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -MMD -MP 
CFLAGS += -I $(INC)
ARC = ar rc
RAN = ranlib
RM = rm -f

GR = \033[32;1m
RE = \033[31;1m
YE = \033[33;1m
CY = \033[36;1m
RC = \033[0m

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	@printf "\n$(GR)=== Compiled ==="
	@printf "\n--- $(notdir $(SRCS))$(RC)\n"
	$(MAKE) --no-print-directory -C ./libft
	cp libft/libft.a $(NAME)
	$(ARC) $(NAME) $(OBJS)
	$(RAN) $(NAME)
	@printf "$(YE)=== Linked [$(CC)] ===\n--- $(NAME)$(RC)\n"

$(OBJDIR):
	@mkdir -p $(OBJDIR)
	@printf "$(GR)=== Compiling ... [$(CC) $(CFLAGS)] ===$(RC)\n"

$(OBJDIR)%.o: $(SRC_DIRECTORY)%.c
	@$(CC) $(CFLAGS) -c -o $@ $< $(HEAD)
	@printf "$(GR)+$(RC)"

clean:
	$(MAKE) --no-print-directory clean -C ./libft
	$(RM) -r $(OBJDIR)

fclean: clean
	$(MAKE) --no-print-directory fclean -C ./libft
	@printf "$(RE)=== Removing $(NAME) ===$(RC)\n"
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)