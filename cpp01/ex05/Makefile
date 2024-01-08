RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
RESET = \033[0m

NAME = complain
SRCS = main.cpp Harl.cpp
PROG = CPP01 EX05

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-Wno-unused-value

%.o: %.cpp Makefile
		@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} $(CFLAGS) $(OBJS) -o ${NAME}
	printf "${WHITE}${PROG}: ${GREEN}Binary compiled!${RESET}\n"

run: ${NAME}
	./${NAME}

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
.SILENT: ${NAME} run clean fclean
