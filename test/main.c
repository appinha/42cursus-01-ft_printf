/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:31:43 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/24 17:54:52 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>
# include <stdint.h>

#define MAIN_1(string)		"\033[1m\033[38;5;199m" string "\033[0m"
#define MAIN_2(string)		"\033[35m" string "\033[0m"
#define HEADER_1(string)	"\033[38;5;43m" string "\033[0m"
#define HEADER_2(string)	"\033[38;5;75m" string "\033[0m"
#define HIGHLIGHT(string)	"\033[38;5;191m" string "\033[0m"

#define INPUT_1	"this %e scientific notation", 1.5
#define INPUT_2	"%e", 7.5
#define INPUT_3	"%e", -3.85
#define INPUT_4	"%e", 573.924
#define INPUT_5	"%e", -958.125

int		main(void)
{
	int		len;
	char	*p1;
	int		n1;
	int		n2;
	int		n3;
	double	dbl_max = FLT_MAX;
	double	dbl1 = 3402823466385288598117041834845169254.0;
	double	mod = 10.0;
	double	res;

	// Hello Kitty test variables
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	//printf("FLT_MAX     :   %.7f\n", (float)FLT_MAX);
	//printf("FLT_MAX     :   %.7f\n", dbl1 - mod);

	//res = ft_fmod(dbl1, mod);
	//printf("\n• ft_fmod(dbl, mod) = %f\n", res);

	printf(MAIN_2("\n\n=== • printf compare • ===\n") "\n");

	//printf(HEADER_2("• printf") "\n");
	//printf(HEADER_1("• ft_printf") "\n\n");

	len = printf(INPUT_1);
	printf(HEADER_2(" (len = %i - printf)") "\n", len);
	len = ft_printf(INPUT_1);
	printf(HEADER_1(" (len = %i - ft_printf)") "\n\n", len);

	len = printf(INPUT_2);
	printf(HEADER_2(" (len = %i - printf)") "\n", len);
	len = ft_printf(INPUT_2);
	printf(HEADER_1(" (len = %i - ft_printf)") "\n\n", len);

	len = printf(INPUT_3);
	printf(HEADER_2(" (len = %i - printf)") "\n", len);
	len = ft_printf(INPUT_3);
	printf(HEADER_1(" (len = %i - ft_printf)") "\n\n", len);

	len = printf(INPUT_4);
	printf(HEADER_2(" (len = %i - printf)") "\n", len);
	len = ft_printf(INPUT_4);
	printf(HEADER_1(" (len = %i - ft_printf)") "\n\n", len);

	len = printf(INPUT_5);
	printf(HEADER_2(" (len = %i - printf)") "\n", len);
	len = ft_printf(INPUT_5);
	printf(HEADER_1(" (len = %i - ft_printf)") "\n\n", len);
}
