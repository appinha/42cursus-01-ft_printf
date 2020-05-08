# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 17:29:07 by apuchill          #+#    #+#              #
#    Updated: 2020/05/06 23:52:43 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_DIR	= ../
LIB	= ftprintf

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f

NAME	= a.out

all:		$(NAME)

$(NAME):
			@cd $(PROJECT_DIR) && make re
			@$(CC) $(CFLAGS) -o $(NAME) main.c -L$(PROJECT_DIR) -l$(LIB)
			@echo "\033[1m\033[38;5;11m \nTesting\n \033[0m"
			@./$(NAME)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
