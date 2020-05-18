/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:12:29 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/18 01:47:45 by apuchill         ###   ########.fr       */
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
** Reference: http://www.cplusplus.com/reference/cstdio/printf/
*/

typedef struct	s_flags
{
	char	spe_c;
	char	pad_c;
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		width;
	int		point;
	int		precision;
	int		length;
	int		size;
	int		sign;
}				t_flags;

/*
** MACROS
*/

# define FLAGS		"-+#0 "
# define DIGITS		"0123456789"
# define LENGTH		"lh"
# define ALL_FL		"-+#0 *.0123456789lh"
# define SPECS		"cspdiuxX%"

# define SPECS_B	"nfge"
# define FLAGS_M	"-0.*123456789"
# define FLAGS_B	"l ll h hh # +"

# define HEXA_LOW	"0123456789abcdef"
# define HEXA_UP	"0123456789ABCDEF"

/*
** MAIN FUNCTIONS
*/

int				ft_printf(const char *str, ...);
void			print_spec_c(int *len, t_flags fl, char c);
void			print_spec_s(int *len, t_flags fl, char *s);
void			print_spec_i_d(int *len, t_flags fl, long long int n);

/*
** UTILS FUNCTIONS
*/

size_t			ft_strlen(const char *s);
void			ft_putchar_len(char c, int *len);
void			ft_putcstr_len(char *s, int *len, int size);
int				ft_strchr_01(char *s, char c);

#endif
