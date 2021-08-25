# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcefalo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/23 19:55:41 by gcefalo           #+#    #+#              #
#    Updated: 2021/08/23 19:56:00 by gcefalo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo

SRCS		=	\
				exit.c \
				initialization.c \
				parse.c \
				main.c \
				routine.c \
				utils.c \
				utils_2.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

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
