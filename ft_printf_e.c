/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:55:34 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/25 16:15:42 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ver_rounding(t_flags fl)
{
	fl.j = ft_strlen(fl.a) - fl.e_nbr + 1;
	while (--fl.j >= 2)
	{
		if (fl.a[fl.j] < (fl.rnd + '0'))
			break ;
		if (fl.a[fl.j] >= '9' && (fl.a[fl.j] = '0'))
			fl.a[fl.j - 1] += 1;
		else
		{
			fl.a[fl.j - 1] += 1;
			break ;
		}
	}
	fl.aux = fl.fe * 10;
	if ((fl.a[1] == '.' + 1 && (fl.a[1] = '.')) ||
		(fl.point == 1 && fl.precision == 0 && (fl.aux % 10) >= fl.rnd))
	{
		fl.a[0]++;
		if (fl.a[0] == '9' + 1 && (fl.a[0] = '1'))
		{
			fl.e_nbr++;
			fl.rnd = 0;
		}
	}
	return (fl);
}

static t_flags	nbrtoa(t_flags fl)
{
	fl = ft_dectoa(fl, fl.precision);
	fl.tmp = ft_ullitoa_base(fl.ulli, DIGITS);
	fl.a = ft_strjoin(fl.tmp, fl.d);
	free(fl.tmp);
	free(fl.d);
	fl.j = ft_strlen(fl.a);
	while (--fl.j >= 0)
	{
		if (fl.a[fl.j] == '.' && fl.j >= 2)
		{
			fl.a[fl.j] = fl.a[fl.j - 1];
			fl.a[fl.j - 1] = '.';
		}
	}
	if (fl.e_nbr >= 0)
		fl = ver_rounding(fl);
	if (fl.e_nbr > 0 && fl.rnd > 0)
		fl.d = ft_substr(fl.a, 0, (ft_strlen(fl.a) - fl.e_nbr));
	if (fl.e_nbr > 0 && fl.rnd == 0)
		fl.d = ft_substr(fl.a, 0, (ft_strlen(fl.a) - fl.e_nbr + 1));
	if (fl.e_nbr <= 0)
		fl.d = ft_strdup(fl.a);
	free(fl.a);
	return (fl);
}

static t_flags	nbr0toa(t_flags fl)
{
	char	str[fl.precision + 3];

	fl.e[1] = '+';
	fl.e_nbr = 0;
	if (fl.point == 1 && fl.precision == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	else
	{
		str[0] = '0';
		str[1] = '.';
		fl.j = 2;
		while (fl.j <= fl.precision + 1)
			str[fl.j++] = '0';
		str[fl.precision + 2] = '\0';
	}
	fl.d = ft_strdup(str);
	return (fl);
}

static t_flags	print_spec_e_aux(t_flags fl)
{
	if (fl.ulli > 0 && (fl.e[1] = '+'))
	{
		while (fl.ulli /= 10)
			(fl.e_nbr)++;
		fl.ulli = fl.f;
	}
	else if ((fl.e[1] = '-'))
	{
		while (fl.ulli == 0 && (fl.e_nbr)-- > -100)
		{
			fl.f *= 10;
			fl.ulli = fl.f;
		}
		if (fl.e_nbr < -99)
		{
			fl = nbr0toa(fl);
			return (fl);
		}
	}
	if (fl.e_nbr > 0)
		fl.fe = fl.f / ft_pow(10, fl.e_nbr);
	if (fl.e_nbr == 0)
		fl.fe = fl.f;
	if (fl.e_nbr < 0)
		fl.fe = fl.f * ft_pow(10, -fl.e_nbr);
	fl = nbrtoa(fl);
	return (fl);
}

void			print_spec_e(int *len, t_flags fl, double n)
{
	fl.sign = (n >= 0) ? '+' : '-';
	fl.f = (n >= 0) ? n : -n;
	fl.ulli = fl.f;
	fl.e[0] = 'e';
	fl.e[4] = '\0';
	fl.e_nbr = 0;
	fl = print_spec_e_aux(fl);
	fl.size = (fl.e_nbr >= 0) ? fl.e_nbr : -fl.e_nbr;
	fl.tmp = ft_ullitoa_base((fl.e_nbr >= 0) ? fl.e_nbr : -fl.e_nbr, DIGITS);
	if (fl.size > 9)
		fl.a = ft_strdup(fl.tmp);
	else
		fl.a = ft_strjoin("0", fl.tmp);
	free(fl.tmp);
	fl.e[2] = fl.a[0];
	fl.e[3] = fl.a[1];
	free(fl.a);
	fl.a = ft_strjoin(fl.d, fl.e);
	free(fl.d);
	print_flags(len, fl);
	free(fl.a);
}
