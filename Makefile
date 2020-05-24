# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/06 21:56:58 by apuchill          #+#    #+#              #
#    Updated: 2020/05/24 19:06:55 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f

NAME	= libftprintf.a

SRCS	= ft_printf.c ft_printf_utils.c ft_printf_utils_2.c ft_printf_flags.c \
			ft_printf_csp_pct.c ft_printf_iduxo.c \
			ft_printf_utils_3.c ft_printf_f.c ft_printf_e.c

OBJS	= $(SRCS:.c=.o)

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)

bonus:		$(NAME)
			@ar -rcs $(NAME) $(OBJS)

clean:
			@$(RM) $(OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus
