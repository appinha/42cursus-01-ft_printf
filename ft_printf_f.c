/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 15:03:07 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/28 03:58:05 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_spec_f_e_g(int *len, t_flags fl, double n)
{
	if (fl.point == 0)
		fl.precision = 6;
	if (fl.spe_c == 'f')
	{
		fl = print_spec_f(fl, n);
		print_flags(len, fl);
		free(fl.a);
		if (fl.ulli == 0 && fl.point == 1 && fl.precision == 0)
			ft_putchar_len('0', len);
	}
	if (fl.spe_c == 'e')
	{
		fl = print_spec_e(fl, n);
		print_flags(len, fl);
		free(fl.a);
	}
	if (fl.spe_c == 'g')
	{
		fl = print_spec_g(fl, n);
		print_flags(len, fl);
		free(fl.a);
	}
}

t_flags			print_spec_f(t_flags fl, double n)
{
	fl.sign = (n >= 0) ? '+' : '-';
	fl.f = (n >= 0) ? n : -n;
	fl.ulli = fl.f;
	fl.a = ft_ftoa_rnd(fl.f, fl.precision, 5);
	if (fl.hash == 1 && fl.point == 1 && fl.precision == 0)
	{
		fl.tmp = ft_strjoin(fl.a, ".");
		free(fl.a);
		fl.a = fl.tmp;
	}
	return (fl);
}

static t_flags	rm_trailing_0s(t_flags fl)
{
	int		i;

	i = ft_strlen(fl.a);
	while (--i >= 0)
	{
		if (!(fl.a[i] == '0' || fl.a[i] == '.'))
			break ;
		else
			fl.a[i] = '\0';
	}
	return (fl);
}

t_flags			print_spec_g(t_flags fl, double n)
{
	int 	P;

	P = fl.precision;
	if (fl.point == 1 && fl.precision == 0)
		P = 1;
	if (fl.point == 1 && fl.precision > 0)
		P = fl.precision;
	fl = print_spec_e(fl, n);
	if (P > fl.e_nbr && fl.e_nbr >= -4)
	{
		fl.precision = P - (fl.e_nbr + 1);
		free(fl.a);
		fl = print_spec_f(fl, n);
		if (fl.hash == 0)
			fl = rm_trailing_0s(fl);
	}
	else
	{
		fl.precision = P - 1;
		free(fl.a);
		fl = print_spec_e(fl, n);
	}
	return (fl);
}
