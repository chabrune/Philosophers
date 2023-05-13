# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chabrune <charlesbrunet51220@gmail.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 18:39:02 by chabrune          #+#    #+#              #
#    Updated: 2023/05/13 15:05:10 by chabrune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#######################################################
###### ARGUMENTS

NAME    	=       philo
CFLAGS  	=       -Wextra -Wall -Werror -g3
CC      	=       gcc
RM      	=       rm -rf
OBJS    	=       $(SRCS:.c=.o)

#######################################################
###### SOURCES

SRCS       	=	philo.c \
				utils.c \
				check_error.c \
				time.c \


#######################################################
###### RULES

.c.o:
			gcc ${CFLAGS} -c $< -o $(<:.c=.o)

all:		${NAME}

${NAME}:	${OBJS}
			gcc ${CFLAGS} ${OBJS} -o ${NAME}

debug:		fclean ${OBJS}
			gcc ${CFLAGS} -fsanitize=address ${OBJS} -o ${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean re fclean