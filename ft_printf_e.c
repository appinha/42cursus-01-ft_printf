/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:55:34 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/27 17:47:49 by apuchill         ###   ########.fr       */
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
	int		i;

	ft_strlcpy(fl.e, "e+00", 5);
	if (fl.point == 1 && fl.precision == 0)
		ft_strlcpy(str, "0", 2);
	else
	{
		ft_strlcpy(str, "0.", 3);
		i = 2;
		while (i <= fl.precision + 1)
			str[i++] = '0';
		str[i] = '\0';
	}
	fl.d = ft_strdup(str);
	return (fl);
}

static t_flags	get_nbr_e(t_flags fl, long double f,unsigned long long int i_part)
{
	fl.e_nbr = 0;
	if (i_part > 0 && (ft_strlcpy(fl.e, "e+", 3)))
	{
		while (i_part /= 10)
			fl.e_nbr++;
	}
	else if ((ft_strlcpy(fl.e, "e-", 3)))
	{
		while (fl.e_nbr-- > -100 && f < 0.1)
			f *= 10;
	}
	fl.tmp = ft_ullitoa_base((fl.e_nbr >= 0) ? fl.e_nbr : -fl.e_nbr, DIGITS);
	if ((ft_strlen(fl.tmp)) == 1 && (ft_strlcat(fl.e, "0", 4)))
		ft_strlcat(fl.e, fl.tmp, 5);
	else
		ft_strlcat(fl.e, fl.tmp, 5);
	free(fl.tmp);
	if (fl.e_nbr < -99)
		fl = n0_toa(fl);
	else
		fl = nbr_toa(fl);
	return (fl);
}

void			print_spec_e(int *len, t_flags fl, double n)
{
	fl.sign = (n >= 0) ? '+' : '-';
	fl.f = (n >= 0) ? n : -n;
	fl.ulli = fl.f;
	fl = get_nbr_e(fl, fl.f, fl.ulli);
	if (!(fl.d[1] == '.' || fl.d[1] == '\0'))
	{
		if (fl.e[3] == '9')
		{
			fl.e[2]++;
			fl.e[3] = '0';
		}
		else
			fl.e[3]++;
		fl.tmp = ft_substr(fl.d, 2, ft_strlen(fl.d) - 2);
		free(fl.d);
		fl.d = ft_strjoin("1", fl.tmp);
		free(fl.tmp);
	}
	fl.a = ft_strjoin(fl.d, fl.e);
	free(fl.d);
	print_flags(len, fl);
	free(fl.a);
}
