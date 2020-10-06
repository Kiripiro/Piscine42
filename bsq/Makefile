SRCS	= ./srcs/main.c ./srcs/check_map_error.c ./srcs/display.c ./srcs/ft.c ./srcs/ft2.c ./srcs/algo.c ./srcs/parsing.c ./srcs/launcher.c

INCS	= includes/

OBJS	= ${SRCS:.c=.o}

NAME	= bsq

CC		= gcc
RM		= rm -f

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}:	${OBJS}
			${CC} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
