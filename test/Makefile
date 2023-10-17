SHELL = /bin/bash
NAME		= diff.txt
NAME_FT		= ft.txt
NAME_PF		= pf.txt
NAME_FT_OUT	= ft.out
NAME_PF_OUT	= pf.out
ROOTPATH	= ../
SRC			= main_42tester.c

# **************************************************************************** #

CC			= gcc
LIB			= -L ${ROOTPATH} -lftprintf
FT_FLAGS	= -w -Wall -Werror -Wextra -D PRINT="ft_printf" -g3 -fsanitize=address
PF_FLAGS	= -w -Wall -Werror -Wextra -D PRINT="printf" -g3 -fsanitize=address
DIFF		= diff

GR = \033[32;1m
RE = \033[31;1m
YE = \033[33;1m
CY = \033[36;1m
RC = \033[0m

# **************************************************************************** #

all: ${NAME}

$(NAME): libftprintfmake_re
	${CC} ${FT_FLAGS} ${SRC} -o ${NAME_FT_OUT} ${LIB} 
	${CC} ${PF_FLAGS} $(SRC) -o ${NAME_PF_OUT} ${LIB} 
	./${NAME_FT_OUT} > ${NAME_FT}
	./${NAME_PF_OUT} > ${NAME_PF}
	${shell ${DIFF} ${NAME_FT} ${NAME_PF} > ${NAME}}
	@printf "$(YE)=== Test Result Available [$(CC)] ===\n--- $(NAME)$(RC)\n"

libftprintfmake_re:
	${MAKE} -C ${ROOTPATH} re --no-print-directory 

clean:
	${MAKE} -C ${ROOTPATH} clean --no-print-directory 

fclean: clean
	${RM} ${NAME} ${NAME_FT} ${NAME_PF} ${NAME_FT_OUT} ${NAME_PF_OUT}
	@printf "$(RE)=== Removed $(NAME) ===$(RC)\n"
	${MAKE} -C ${ROOTPATH} fclean --no-print-directory 

re: fclean all

.PHONY: all clean fclean re
