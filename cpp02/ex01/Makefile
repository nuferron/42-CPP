# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 15:50:10 by nuferron          #+#    #+#              #
#    Updated: 2024/03/14 14:50:15 by nuferron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
RESET = \033[0m

NAME = canonical
SRCS = main.cpp Fixed.cpp
PROG = CPP02 EX01

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.cpp Makefile Fixed.hpp
		@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} $(CFLAGS) $(OBJS) -o ${NAME}
	printf "${WHITE}${PROG}: ${GREEN}Binary compiled!${RESET}\n"

run: ${NAME}
	./${NAME}

leaks: ${NAME}
	leaks -atExit -- ./${NAME}

clean:
	${RM} ${OBJS}

fclean: clean 
		if [ -e ${NAME} ] ; then \
			${RM} ${NAME} ; \
			printf "${WHITE}${PROG}: ${RED}All existing binaries have been deleted${RESET}\n" ; \
	else \
		printf "${WHITE}${PROG}: ${PURPLE}Already cleaned${RESET}\n" ; \
	fi

re: fclean all

.PHONY: all clean fclean re clean
.SILENT: ${NAME} run clean fclean leaks
