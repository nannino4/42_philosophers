# -*- MakeFile -*-

NAME		=	philo

SRCS		=	\
				exit.c \
				initialization.c \
				parse.c \
				philo.c \
				utils.c \
				utils_2.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g

LIBS		=	-lpthread

RM			=	rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS}

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:	all clean fclean re
