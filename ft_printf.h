/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:12:29 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/19 15:42:39 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*
** FORMAT SPECIFIER STRUCT
** .spe_c:	specifier character - i.e. variable type (ex.: %c %s %p %d %i).
** .pad_c:	padding character - could be eiter ' ' (default) or '0' ('0' flag).
** .minus:	'-' flag - left-justifies within the given field width; right
**			justification is the default.
** .plus:	'+' flag - preceeds positive numbers with the plus sign; by default,
**			only negative numbers are preceeded with a '-' sign.
** .space:	' ' flag - a blank space is inserted before unsigned values.
** .hash:	'#' flag - for %o %x %X, preceeds not null values with 0, 0x or 0X
**			respectively; for %a %A %e %E %f %F %g %G, prints decimal point
**			even if no more digits follow. By default, if no digits follow, no
**			decimal point is printed.
** .width:	min number of characters to be printed, with blank space padding if
**			value is shorter than width.
** .point: '1' if precision is given, '0' if not.
** .precision: for %d %i %o %u %x %X, min number of digits to be printed, with
**			with 0 padding if value is shorter than precision; for %a %A %e %E
**			%f %F, number of digits to be printed after the decimal point (by
**			default, this is 6); for %g %G, max number of significants digits
**			to be printed; for %s, max number of characters to be printed (by
**			default, all characters are printed until '\0'); note: '.' = '.0'.
** .length:	modifies the length of the data type as follows:
**				| %d %i (int)	| %u %o %x %X (unsigned int)| %n (int*)		|
**			'l'	| long int		| unsigned long int			| long int*		|
**			'll'| long long int	| unsigned long long int	| long long int*|
**			'h'	| short int		| unsigned short int		| short int*	|
**			'hh	| signed char	| unsigned char				| signed char*	|
** Reference: http://www.cplusplus.com/reference/cstdio/printf/
*/

typedef struct	s_flags
{
	char					set[20];
	char					spe_c;
	char					pad_c;
	int						minus;
	int						plus;
	int						space;
	int						hash;
	int						width;
	int						point;
	int						precision;
	int						length;
	unsigned long long int	ulli;
	long long int			lli;
	int						size;
	char					sign;
	char					*a;
	int						j;
}				t_flags;

/*
** MACROS
*/

# define FLAGS		"-+#0 "
# define DIGITS		"0123456789"
# define ALL_FL		"-+#0 *.0123456789lh"
# define FSPECS		"cspdiuxX%nfge"

/*
** MAIN FUNCTIONS
*/

int				ft_printf(const char *str, ...);
void			print_spec_pct(int *len, t_flags fl);
void			print_spec_c(int *len, t_flags fl, char c);
void			print_spec_s(int *len, t_flags fl, char *s);
void			print_spec_i_d_u(int *len, t_flags fl, va_list args);
void			print_spec_x_X(int *len, t_flags fl, va_list args);
void			print_spec_p(int *len, t_flags fl, unsigned long int p);
void			print_spec_f(int *len, t_flags fl, double n);

/*
** UTILS FUNCTIONS
*/

size_t			ft_strlen(const char *s);
void			ft_putchar_len(char c, int *len);
void			ft_putcstr_len(char *s, int *len, int size);
int				ft_strchr_01(char *s, char c);
char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_ullitoa_base(unsigned long long int n, char *base);

#endif
