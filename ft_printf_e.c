/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:55:34 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/23 13:23:12 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	nbr0toa(t_flags fl)
{
	char	str[fl.precision + 3];

	fl.e[1] = '+';
	fl.e[2] = '0';
	fl.e[3] = '0';
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

static t_flags	nbrtoa(t_flags fl, int size)
{
	char	*aux;

	fl = ft_dectoa(fl);
	//printf("[size=%i]", size);
	aux = ft_strjoin(ft_ullitoa_base(fl.ulli, DIGITS), fl.d);
	free(fl.d);
	fl.j = ft_strlen(aux);
	while (--fl.j >= 0)
	{
		if (aux[fl.j] == '.' && fl.j >= 2)
		{
			aux[fl.j] = aux[fl.j - 1];
			aux[fl.j - 1] = '.';
		}
	}
	if (size > 0)
		fl.d = ft_substr(aux, 0, (ft_strlen(aux) - size));
	else
		fl.d = ft_strdup(aux);
	free(aux);
	return (fl);
}

static t_flags	intpart_0(t_flags fl)
{
	int		size;

	fl.e[1] = '-';
	size = 0;
	while (fl.ulli == 0 && size-- > -100)
	{
		fl.f *= 10;
		fl.ulli = fl.f;
	}
	fl.size = fl.precision;
	fl = nbrtoa(fl, size);
	if (-size > 99)
	{
		fl = nbr0toa(fl);
		return (fl);
	}
	else if (-size > 9)
		fl.a = ft_ullitoa_base(-size, DIGITS);
	else
		fl.a = ft_strjoin("0", ft_ullitoa_base(-size, DIGITS));
	fl.e[2] = fl.a[0];
	fl.e[3] = fl.a[1];
	free(fl.a);
	return (fl);
}

static t_flags	intpart_not0(t_flags fl)
{
	int	size;

	fl.e[1] = '+';
	size = 0;
	while (fl.ulli /= 10)
		size++;
	fl.ulli = fl.f;
	fl.size = fl.precision;
	fl = nbrtoa(fl, size);
	if (size > 9)
		fl.a = ft_ullitoa_base(size, DIGITS);
	else
		fl.a = ft_strjoin("0", ft_ullitoa_base(size, DIGITS));
	fl.e[2] = fl.a[0];
	fl.e[3] = fl.a[1];
	free(fl.a);
	return (fl);
}

void			print_spec_e(int *len, t_flags fl, double n)
{
	fl.rnd = 6;
	fl.sign = (n >= 0) ? '+' : '-';
	fl.f = (n >= 0) ? n : -n;
	fl.ulli = fl.f;
	fl.e[0] = 'e';
	fl.e[4] = '\0';
	if (fl.ulli > 0)
		fl = intpart_not0(fl);
	else
		fl = intpart_0(fl);
	fl.a = ft_strjoin(fl.d, fl.e);
	free(fl.d);
	fl.ulli = fl.f;
	print_flags(len, fl);
	free(fl.a);
}
