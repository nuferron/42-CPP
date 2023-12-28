RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
RESET = \033[0m

NAME = megaphone
SRCS = megaphone.cpp

CC = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror #-std=c++98

%.o: %.cpp Makefile
		@${CC} ${CFLAGS} -c $< -o $@

OBJS = ${SRCS:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CC} $(CFLAGS) $(OBJS) -o ${NAME}
	printf "${WHITE}CPP00 EX00: ${GREEN}Binary compiled!${RESET}\n"

clean:
	if [ -e ${OBJS} ] ; then \
			${RM} ${OBJS} ; \
			printf "${WHITE}CPP00 EX00: ${RED}All existing objects have been deleted${RESET}\n" ; \
	fi

fclean: clean 
		if [ -e ${NAME} ] ; then \
			${RM} ${NAME} ; \
			printf "${WHITE}CPP00 EX00: ${RED}All existing binaries have been deleted${RESET}\n" ; \
	else \
		printf "${WHITE}CPP00 EX00: ${PURPLE}Already cleaned${RESET}\n" ; \
	fi

re: fclean all

.PHONY: all clean fclean re
.SILENT: fclean clean re ${NAME}