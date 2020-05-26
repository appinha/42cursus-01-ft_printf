# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 17:29:07 by apuchill          #+#    #+#              #
#    Updated: 2020/05/25 21:48:32 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_DIR	= ../
LIB	= -L$(PROJECT_DIR) -lftprintf

CC		= gcc
#CFLAGS	= -Wall -Wextra -Werror -g3 -fsanitize=address
CFLAGS	= -g3 -fsanitize=address
RM		= /bin/rm -f

NAME	= a.out

all:		$(NAME)

$(NAME):
			@make rebonus -C $(PROJECT_DIR)
			@$(CC) $(CFLAGS) -o $(NAME) main.c $(LIB)
			@sh test_header.sh && ./$(NAME) && sh test_footer.sh
#			@echo "" && cd $(PROJECT_DIR) && make fclean

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
