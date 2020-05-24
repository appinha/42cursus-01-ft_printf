/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:55:34 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/24 17:57:00 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ver_rounding(t_flags fl, int *size)
{
	fl.j = ft_strlen(fl.a) - *size + 1;
	while (--fl.j >= 2)
	{
		if (fl.a[fl.j] < (fl.rnd + '0'))
			break;
		if (fl.a[fl.j] >= '9' && (fl.a[fl.j] = '0'))
			fl.a[fl.j - 1] += 1;
		else
		{
			fl.a[fl.j - 1] += 1;
			break;
		}
	}
	fl.lli = fl.f0 * 10;
	if ((fl.a[1] == '.' + 1 && (fl.a[1] = '.')) ||
		(fl.point == 1 && fl.precision == 0 && (fl.lli % 10) >= fl.rnd))
	{
		printf("A");
		fl.a[0]++;
		if (fl.a[0] == '9' + 1 && (fl.a[0] = '1'))
		{
			(*size)++;
			fl.rnd = 0;
		}
	}
	return (fl);
}

static t_flags	nbrtoa(t_flags fl, int *size)
{
	fl.size = fl.precision;
	fl = ft_dectoa(fl);
	fl.a = ft_strjoin(ft_ullitoa_base(fl.ulli, DIGITS), fl.d);
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
	//printf("[size=%i]", *size);
	if (*size >= 0)
		fl = ver_rounding(fl, size);
	if (*size > 0 && fl.rnd > 0)
		fl.d = ft_substr(fl.a, 0, (ft_strlen(fl.a) - *size));
	if (*size > 0 && fl.rnd == 0)
		fl.d = ft_substr(fl.a, 0, (ft_strlen(fl.a) - *size + 1));
	if (*size <= 0)
		fl.d = ft_strdup(fl.a);
	free(fl.a);
	return (fl);
}

static t_flags	nbr0toa(t_flags fl, int *size)
{
	char	str[fl.precision + 3];

	fl.e[1] = '+';
	*size = 0;
	fl.size = fl.precision;
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
		while (fl.j <= fl.size + 1)
			str[fl.j++] = '0';
		str[fl.precision + 2] = '\0';
	}
	fl.d = ft_strdup(str);
	return (fl);
}

static t_flags	print_spec_e_aux(t_flags fl, int *size)
{
	if (fl.ulli > 0 && (fl.e[1] = '+'))
	{
		while (fl.ulli /= 10)
			(*size)++;
		fl.ulli = fl.f;
	}
	else if ((fl.e[1] = '-'))
	{
		while (fl.ulli == 0 && (*size)-- > -100)
		{
			fl.f *= 10;
			fl.ulli = fl.f;
		}
		if (*size < -99)
		{
			fl = nbr0toa(fl, size);
			return (fl);
		}
	}
	if (*size > 0)
		fl.f0 = fl.f / ft_pow(10, *size);
	if (*size == 0)
		fl.f0 = fl.f;
	if (*size < 0)
		fl.f0 = fl.f * ft_pow(10, -*size);
	fl = nbrtoa(fl, size);
	return (fl);
}

void			print_spec_e(int *len, t_flags fl, double n)
{
	int	size;

	fl.sign = (n >= 0) ? '+' : '-';
	fl.f = (n >= 0) ? n : -n;
	fl.ulli = fl.f;
	fl.e[0] = 'e';
	fl.e[4] = '\0';
	size = 0;
	fl = print_spec_e_aux(fl, &size);
	size = (size >= 0) ? size : -size;
	if (size > 9)
		fl.a = ft_ullitoa_base(size, DIGITS);
	else
		fl.a = ft_strjoin("0", ft_ullitoa_base(size, DIGITS));
	fl.e[2] = fl.a[0];
	fl.e[3] = fl.a[1];
	free(fl.a);
	fl.a = ft_strjoin(fl.d, fl.e);
	free(fl.d);
	print_flags(len, fl);
	free(fl.a);
}
