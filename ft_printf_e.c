/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:55:34 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/26 23:34:32 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	nbr_toa(t_flags fl)
{
	if (fl.e_nbr > 0)
		fl.fe = fl.f / ft_pow(10, fl.e_nbr);
	if (fl.e_nbr == 0)
		fl.fe = fl.f;
	if (fl.e_nbr < 0)
		fl.fe = fl.f * ft_pow(10, -fl.e_nbr);
	fl.d = ft_ftoa_rnd(fl.fe, fl.precision, 5);
	fl.j = ft_strlen(fl.a);
	while (--fl.j >= 0)
	{
		if (fl.d[fl.j] == '.' && fl.j >= 2)
		{
			fl.d[fl.j] = fl.d[fl.j - 1];
			fl.d[fl.j - 1] = '.';
		}
	}
	return (fl);
}

static t_flags	n0_toa(t_flags fl)
{
	char	str[fl.precision + 3];
	int 	i;

	fl.e[1] = '+';
	fl.e[2] = '0';
	fl.e[3] = '0';
	if (fl.point == 1 && fl.precision == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		str[0] = '0';
		str[1] = '.';
		i = 2;
		while (i <= fl.precision + 1)
			str[i++] = '0';
		str[i] = '\0';
	}
	fl.d = ft_strdup(str);
	return (fl);
}

static t_flags	e_toa(t_flags fl)
{
	int		e_nbr_pos;

	e_nbr_pos = (fl.e_nbr >= 0) ? fl.e_nbr : -fl.e_nbr;
	fl.tmp = ft_ullitoa_base(e_nbr_pos, DIGITS);
	fl.e[0] = 'e';
	if (e_nbr_pos > 9)
	{
		fl.e[2] = fl.tmp[0];
		fl.e[3] = fl.tmp[1];
	}
	else
	{
		fl.e[2] = '0';
		fl.e[3] = fl.tmp[0];
	}
	fl.e[4] = '\0';
	free(fl.tmp);
	return (fl);
}

static t_flags	ft_etoa(t_flags fl, long double f,
							unsigned long long int int_part)
{
	fl.e_nbr = 0;
	if (int_part > 0)
	{
		fl.e[1] = '+';
		while (int_part /= 10)
			fl.e_nbr++;
	}
	else
	{
		fl.e[1] = '-';
		while (int_part == 0 && (fl.e_nbr)-- > -100)
		{
			f *= 10;
			int_part = f;
		}
	}
	fl = e_toa(fl);
	if (fl.e_nbr < -99)
		fl = n0_toa(fl);
	else
		fl = nbr_toa(fl);
	fl.a = ft_strjoin(fl.d, fl.e);
	free(fl.d);
	return (fl);
}

void			print_spec_e(int *len, t_flags fl, double n)
{
	fl.sign = (n >= 0) ? '+' : '-';
	fl.f = (n >= 0) ? n : -n;
	fl.ulli = fl.f;
	fl = ft_etoa(fl, fl.f, fl.ulli);
	print_flags(len, fl);
	free(fl.a);
}
