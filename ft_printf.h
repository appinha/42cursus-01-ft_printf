/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:12:29 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/15 14:11:18 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/*
** FLAG COLLECTION STRUCT
** '-' (minus): justification
** '0' (zero): padding
** '.' (dot): precision
** '*' (star): argument (complements other flags)
** width: min number of char to be printed
*/

typedef struct	s_flags
{
	char	spec;
	char	pad_c;
	int		minus;
	int		plus;
	int		hash;
	int		space;
	int		width;
	int		precision;
}				t_flags;

/*
** MACROS
*/

# define FLAGS		"-+#0 "
# define OTHER_SP	"*."
# define DIGITS		"0123456789"
# define LENGTH		"lh"
# define ALL_FL		FLAGS OTHER_SP DIGITS LENGTH
# define SPECS		"cspdiuxX%"

# define SPECS_B	"nfge"
# define FLAGS_M	"-0.*123456789"
# define FLAGS_B	"l ll h hh # +"

# define HEXA_LOW	"0123456789abcdef"
# define HEXA_UP	"0123456789ABCDEF"

/*
** MAIN FUNCTIONS
*/

int		ft_printf(const char *str, ...);
void	print_spec_c(int *len, t_flags fl, char c);
void	print_spec_s(int *len, t_flags fl, char *s);

/*
** UTILS FUNCTIONS
*/

size_t	ft_strlen(const char *s);
void	ft_putchar_len(char c, int *len);
void	ft_putstr_len(char *s, int *len);
int		ft_strchr_01(char *s, char c);

#endif
