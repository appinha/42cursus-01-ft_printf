/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:12:29 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/09 12:25:57 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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
	int minus;
	int zero;
	int dot;
	int star;
	int width;
}				t_flags;

/*
** MACROS
*/

# define SPECS		"cspdiuxX%"
# define SPECS_B	"nfge"
# define FLAGS		"-0.*123456789"
# define FLAGS_B	"l ll h hh # +"
# define ALL_SPEC	SPECS FLAGS
# define HEXA_LOW	"0123456789abcdef"
# define HEXA_UP	"0123456789ABCDEF"

/*
** MAIN FUNCTIONS
*/

int	ft_printf(const char *str, ...);

/*
** UTILS FUNCTIONS
*/

size_t	ft_strlen(const char *s);
void	ft_putchar(char c);
void	ft_putstr(char *s);

#endif
