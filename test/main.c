/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:31:43 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/27 22:46:23 by apuchill         ###   ########.fr       */
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

#define INPUT_1	"%e", 0.00000
#define INPUT_2	"%e", -0.99999949
#define INPUT_3	"%e", -0.99999949
#define INPUT_4	"%.0e", -958.125
#define INPUT_5	"%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j

int		main(void)
{
	char	*p1;
	int		len, n1, n2, n3;
	double	dbl_max = FLT_MAX;
	double	dbl = 1.025978548534310421;
	double	mod = 10.0;
	double	res;
	long double	l_dbl;

	// Hello Kitty test variables
	int		a = -4, b = 0, d = 2147483647, e = -2147483648, f = 42, g = 25;
	int		h = 4200, i = 8, j = -12, k = 123456789, l = 0, m = -12345678;
	char	c = 'a';
	char	*n = "abcdefghijklmnop", *o = "-a", *p = "-12", *q = "0";
	char	*r = "%%", *s = "-2147483648", *t = "0x12345678", *u = "-0";

	//printf("FLT_MAX     :   %.7f\n", (float)FLT_MAX);
	//printf("FLT_MAX     :   %.7f\n", dbl1 - mod);

	//res = ft_fmod(dbl1, mod);
	//printf("\n• ft_fmod(dbl, mod) = %f\n", res);

/*
	printf("- sizeof(int) = %lu\n", sizeof(int));
	printf("- sizeof(long int) = %lu\n", sizeof(long int));
	printf("- sizeof(long long int) = %lu\n", sizeof(long long int));
	printf("- sizeof(float) = %lu\n", sizeof(float));
	printf("- sizeof(double) = %lu\n", sizeof(double));
	printf("- sizeof(long double) = %lu\n", sizeof(long double));
*/
	printf(MAIN_2("\n=== • printf compare • ===\n") "\n");

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
