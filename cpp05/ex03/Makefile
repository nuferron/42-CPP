# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nuferron <nuferron@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 15:50:10 by nuferron          #+#    #+#              #
#    Updated: 2024/04/16 23:50:03 by nuferron         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################## COLORS ####################
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
PURPLE = \033[1;35m
CYAN = \033[1;36m
WHITE = \033[1;37m
RESET = \033[0m

################# SPECIFIC VARIABLES #####################
NAME = bureaucracy
SHARED_FILES =	Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm \
				PresidentialPardonForm Intern
SRCS = $(addsuffix .cpp,$(SHARED_FILES)) main.cpp
HEADERS = $(addsuffix .hpp,$(SHARED_FILES))
PROG = CPP05 EX03

################## COMMANDS #################
CC = c++
RM = rm -rf

################## FLAGS ###################
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -std=c++98
DEBUGFLAGS = -g -fsanitize=address
DEPFLAGS = -MMD -MP
FLAGS = ${CFLAGS} ${DEBUGFLAGS} ${DEPFLAGS}

################## COMMON VARIABLES ###################
OBJDIR = obj/
OBJS = $(addprefix ${OBJDIR}, ${SRCS:.cpp=.o})
DEP = $(OBJS:.o=.d)


all: ${NAME}

${NAME}: ${OBJS}
	${CC} $(FLAGS) $(OBJS) -o ${NAME}
	printf "${WHITE}${PROG}: ${GREEN}Binary compiled!${RESET}\n"

${OBJDIR}%.o: %.cpp Makefile
		@mkdir -p $(dir $@)
		@${CC} ${CFLAGS} ${DEPFLAGS} -c $< -o $@

run: ${NAME}
	./${NAME}


leaks: ${NAME}
	leaks -atExit -- ./${NAME}

clean:
	${RM} ${OBJDIR}

fclean: clean 
		if [ -e ${NAME} ] ; then \
			${RM} ${NAME} ; \
			printf "${WHITE}${PROG}: ${RED}All existing binaries have been deleted${RESET}\n" ; \
	else \
		printf "${WHITE}${PROG}: ${PURPLE}Already cleaned${RESET}\n" ; \
	fi

re: fclean all

-include ${DEP}

.PHONY: all clean fclean re clean
.SILENT: ${NAME} run clean fclean leaks
