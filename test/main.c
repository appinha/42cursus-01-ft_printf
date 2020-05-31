#include "../ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>

#define MAIN_1(string)		"\033[1m\033[38;5;199m" string "\033[0m"
#define MAIN_2(string)		"\033[35m" string "\033[0m"
#define HEADER_1(string)	"\033[38;5;43m" string "\033[0m"
#define HEADER_2(string)	"\033[38;5;75m" string "\033[0m"
#define HIGHLIGHT(string)	"\033[38;5;191m" string "\033[0m"

#define INPUT_1	"%5o", 12
#define INPUT_2	"%5.o", 12
#define INPUT_3	"%#5o", 12
#define INPUT_4	"%#5.o", 12
#define INPUT_5	"%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j

int		main(void)
{
	char	*p1;
	char	*str;
	int		len, n1, n2, n3;
	double	dbl_max = FLT_MAX;
	double	dbl = 1.025978548534310421;
	double	mod = 10.0;
	double	res;
	long double	l_dbl;

	//PFT Mix tests
	static unsigned int	mx_u = 235;
	static double		mx_Lf = 0.375;
	static double		mx_f = 0.625;
	static long			mx_li =  4223372036854775800;
	static long long	mx_lli = 3223372036654775200;
	static char			mx_c = 'G';
	static short		mx_hi = -3244;
	static char			mx_hhi = 'F';
	static char			*mx_s = "Hello, World!";
	static int			mx_i = 42;

	// Hello Kitty test variables
	int		a = -4, b = 0, d = 2147483647, e = -2147483648, f = 42, g = 25;
	int		h = 4200, i = 8, j = -12, k = 123456789, l = 0, m = -12345678;
	char	c = 'a';
	char	*n = "abcdefghijklmnop", *o = "-a", *p = "-12", *q = "0";
	char	*r = "%%", *s = "-2147483648", *t = "0x12345678", *u = "-0";

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
