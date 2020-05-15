/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:12:29 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/14 17:54:29 by apuchill         ###   ########.fr       */
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
	int		minus;
	int		zero;
	int		dot;
	int		star;
	int		width;
}				t_flags;

/*
** MACROS
*/

# define SPECS		"cspdiuxX%"
# define SPECS_B	"nfge"
# define FLAGS		"-0.*123456789"
# define FLAGS_B	"l ll h hh # +"
# define ALL_S_F	SPECS FLAGS
# define HEXA_LOW	"0123456789abcdef"
# define HEXA_UP	"0123456789ABCDEF"

/*
** MAIN FUNCTIONS
*/

int		ft_printf(const char *str, ...);
void	print_spec_c(int *len, t_flags fl, char c);

/*
** UTILS FUNCTIONS
*/

size_t	ft_strlen(const char *s);
void	ft_putchar_len(char c, int *len);
void	ft_putstr_len(char *s, int *len);
int		ft_strchr_01(char *s, char c);

#endif
