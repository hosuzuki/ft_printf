PATH		= ../
SRC		= main_42tester.c
#OBJS		= ${SRCS:.c=.o}
NAME		= diff.txt
NAME1		= ft.out
NAME2		= pf.out
CC			= gcc
LIB			= -L ${PATH} libftprintf.a
CFLAGS	= -w -Wall -Werror -Wextra -D PRINT="printf" -g3 -fsanitize=address
FTFLAGS	= -w -Wall -Werror -Wextra -D PRINT="ft_printf" -g3 -fsanitize=address
DIFF		= diff

$(NAME): libmake
			${CC} ${FTFLAGS} ${SRC} ${LIB} -o ${NAME1}
			${CC} ${CFLAGS} $(SRC) ${LIB} -o ${NAME2}
			$(DIFF) $(NAME1) $(NAME2) >> $(NAME)

libmake:
	make re -C ../ 
#			$(MAKE) -C $(PATH) re
#			$(MAKE) -C $(PATH) clean

all:		${NAME}

#clean:
#			${RM} ${OBJS}
#			${PRINTF_MAKE} clean

#fclean:		clean
#			${RM} ${NAME}
#			${PRINTF_MAKE} fclean

#re:			fclean all

.PHONY:		all clean fclean re
