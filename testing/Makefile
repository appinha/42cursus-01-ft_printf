# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/06 17:29:07 by apuchill          #+#    #+#              #
#    Updated: 2021/03/07 18:43:38 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROJECT_DIR	= ../ft_printf/
LIB			= -L$(PROJECT_DIR) -lftprintf

CC		= clang
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f

NAME	= a.out

all:		$(NAME)

$(NAME):
			@make re -C $(PROJECT_DIR)
			@$(CC) $(CFLAGS) -o $(NAME) main.c $(LIB)
			@sh test_header.sh && ./$(NAME) && sh test_footer.sh
#			@echo "" && cd $(PROJECT_DIR) && make fclean

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
