/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:31:43 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/20 20:06:14 by apuchill         ###   ########.fr       */
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

#define INPUT_1	"Hello,%n world!", &n1
#define INPUT_2	"n1=%i", n1
#define INPUT_3	"%n0123%n456789%n", &n1, &n2, &n3
#define INPUT_4	"n1=%i, n2=%i, n3=%i", n1, n2, n3
#define INPUT_5	"%f", 7.3

int		main(void)
{
	int		len;
	char	*p1;
	int		n1;
	int		n2;
	int		n3;
	double	d1;

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
