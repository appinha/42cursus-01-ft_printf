/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:31:43 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/18 17:40:10 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>

#define MAIN_1(string)		"\033[1m\033[38;5;199m" string "\033[0m"
#define MAIN_2(string)		"\033[35m" string "\033[0m"
#define HEADER_1(string)	"\033[38;5;43m" string "\033[0m"
#define HEADER_2(string)	"\033[38;5;75m" string "\033[0m"
#define HIGHLIGHT(string)	"\033[38;5;191m" string "\033[0m"

void	test_star(int *i, char *s)
{
	printf(MAIN_2("=== • test_star • ===\n") "\n");
	printf("original value = %i\n", *i);
	*i += 2;
	printf("changed value (1) = %i\n", *i);
	(*i)++;
	printf("changed value (2) = %i\n", *i);
	*i = 0;
	printf("s[*i] = %c\n", s[*i]);
	printf("s[(*i)++] = %c\n", s[(*i)++]);
	printf("s[*i] = %c\n", s[*i]);
}

#define INPUT	"|%3c|%-3c|%5s|%-5s|", 'A', 'B', "str", "ing"

#define INPUT_1	"%-8.5i", 34
#define INPUT_2	"%-10.5i", -216
#define INPUT_3	"%-8.5i", 0
#define INPUT_4	"%+-8.5i", 34
#define INPUT_5	"%+-10.5i", -216

int		main(void)
{
	int len;

	printf(MAIN_2("\n=== • printf compare • ===\n") "\n");

	printf(HEADER_2("• printf") "\n");
	printf(HEADER_1("• ft_printf") "\n\n");

	len = printf(INPUT_1);
	printf(HEADER_2(" (len = %i)") "\n", len);
	len = ft_printf(INPUT_1);
	printf(HEADER_1(" (len = %i)") "\n\n", len);

	len = printf(INPUT_2);
	printf(HEADER_2(" (len = %i)") "\n", len);
	len = ft_printf(INPUT_2);
	printf(HEADER_1(" (len = %i)") "\n\n", len);

	len = printf(INPUT_3);
	printf(HEADER_2(" (len = %i)") "\n", len);
	len = ft_printf(INPUT_3);
	printf(HEADER_1(" (len = %i)") "\n\n", len);

	len = printf(INPUT_4);
	printf(HEADER_2(" (len = %i)") "\n", len);
	len = ft_printf(INPUT_4);
	printf(HEADER_1(" (len = %i)") "\n\n", len);

	len = printf(INPUT_5);
	printf(HEADER_2(" (len = %i)") "\n", len);
	len = ft_printf(INPUT_5);
	printf(HEADER_1(" (len = %i)") "\n\n", len);
}
