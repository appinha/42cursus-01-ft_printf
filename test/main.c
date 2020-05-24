/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 17:31:43 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/24 12:35:33 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>

#define MAIN_1(string)		"\033[1m\033[38;5;199m" string "\033[0m"
#define MAIN_2(string)		"\033[35m" string "\033[0m"
#define HEADER_1(string)	"\033[38;5;43m" string "\033[0m"
#define HEADER_2(string)	"\033[38;5;75m" string "\033[0m"
#define HIGHLIGHT(string)	"\033[38;5;191m" string "\033[0m"

#define INPUT_1	"%f", (double)340282346638528859811704183484516925440
#define INPUT_2	"%e", -5.9999999
#define INPUT_3	"%.7e", 23.375094499
#define INPUT_4	"%.7e", -56.2012685
#define INPUT_5	"%.7e", 43.43999949

/*
#define INPUT_1	"%f", 3.9999999
#define INPUT_2	"%f", -5.9999999
#define INPUT_3	"%e", (double)INT_MAX
#define INPUT_4	"%e", (double)INT_MIN
#define INPUT_5	"%e", (double)INT_MIN - 1
*/
int		main(void)
{
	int		len;
	char	*p1;
	int		n1;
	int		n2;
	int		n3;
	double	dbl1 = 123456789.0;
	double	mod = 10.0;
	double	res;

	printf("FLT_MAX     :   %.7f\n", (float)FLT_MAX);
	printf("FLT_MAX     :   %.7f\n", (float)340282346638528859811704183484516925440);

	res = ft_fmod(34028234663852885981170418348451692544, mod);
	printf("\n• ft_fmod(dbl, mod) = %f\n", res);

	printf(MAIN_2("\n=== • printf compare • ===\n") "\n");

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
