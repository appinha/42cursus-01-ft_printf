/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp_pct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:36:54 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/30 20:41:26 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_padding(int *len, t_flags fl)
{
	while (fl.width > fl.precision)
	{
		ft_putchar_len(fl.pad_c, len);
		fl.width--;
	}
}

void		print_spec_pct(int *len, t_flags fl)
{
	if (fl.minus == 1)
		fl.pad_c = ' ';
	fl.precision = 1;
	if (fl.minus == 0)
		print_padding(len, fl);
	ft_putchar_len('%', len);
	if (fl.minus == 1)
		print_padding(len, fl);
}

void		print_spec_c(int *len, t_flags fl, char c)
{
	fl.pad_c = ' ';
	fl.precision = 1;
	if (fl.minus == 0)
		print_padding(len, fl);
	ft_putchar_len(c, len);
	if (fl.minus == 1)
		print_padding(len, fl);
}

void		print_spec_s(int *len, t_flags fl, char *s)
{
	fl.pad_c = ' ';
	if (s == NULL)
		s = "(null)";
	if (fl.precision > (int)ft_strlen(s) || fl.precision == -1)
		fl.precision = ft_strlen(s);
	if (fl.minus == 0)
		print_padding(len, fl);
	ft_putcstr_len(s, len, fl.precision);
	if (fl.minus == 1)
		print_padding(len, fl);
}

void		print_spec_p(int *len, t_flags fl, unsigned long int p)
{
	fl.sign = 'u';
	fl.print_n0 = 1;
	fl.spe_c = 'x';
	fl.hash = 1;
	fl.a = ft_ullitoa_base(p, HEXALOW);
	print_flags(len, fl);
	free(fl.a);
}
