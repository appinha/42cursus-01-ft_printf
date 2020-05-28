# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/06 21:56:58 by apuchill          #+#    #+#              #
#    Updated: 2020/05/28 11:27:41 by apuchill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#CC		= gcc
CC		= clang
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f

NAME	= libftprintf.a

SRCS	= ft_printf.c ft_printf_flags.c ft_printf_csp_pct.c ft_printf_iduxo.c \
			ft_printf_f_g.c ft_printf_e.c ft_ftoa_rnd.c \
			ft_printf_utils.c ft_printf_utils_2.c ft_printf_utils_3.c

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
