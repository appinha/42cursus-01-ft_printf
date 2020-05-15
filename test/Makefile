# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 17:29:07 by apuchill          #+#    #+#              #
#    Updated: 2020/05/13 22:16:51 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_DIR	= ../
LIB	= ftprintf

CC		= gcc
#CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f

NAME	= a.out

all:		$(NAME)

$(NAME):
			@make -C $(PROJECT_DIR)
			@$(CC) $(CFLAGS) -o $(NAME) main.c -L$(PROJECT_DIR) -l$(LIB)
			@sh test_header.sh && ./$(NAME) && sh test_footer.sh
#			@echo "" && cd $(PROJECT_DIR) && make fclean

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
