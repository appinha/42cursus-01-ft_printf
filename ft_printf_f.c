/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 15:03:07 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/20 02:31:02 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
# include <inttypes.h>

static t_flags	ft_dectoa_aux(double n, t_flags fl, size_t *nbr, int *len)
{
	double	f;
	size_t	aux;

	f = (n >= 0)? n : -n;
	aux = (f - fl.ulli) * ft_pow(10, fl.size + 1);
	*nbr = aux;
	*len = 1;
	while (aux /= 10)
		(*len)++;
	if ((*nbr % 10) >= 5)
		*nbr += 10;
	*nbr /= 10;
	aux = (f * 10);
	if (((aux % 10) == 9) || (fl.precision == 0 && (aux % 10) >= 5))
	{
		fl.ulli++;
		*nbr = 0;
	}
	return (fl);
}

static t_flags	ft_dectoa(double n, t_flags fl)
{
	char	zeros[20];
	size_t	nbr;
	int		len;

	fl = ft_dectoa_aux(n, fl, &nbr, &len);
	if (nbr == 0)
		len = 2;
	zeros[0] = '.';
	zeros[1] = '\0';
	if (len < fl.size + 1)
	{
		fl.j = 1;
		while (len++ < fl.size + 1)
			zeros[fl.j++] = '0';
		zeros[fl.j] = '\0';
	}
	fl.d = ft_strjoin(zeros, ft_ullitoa_base((unsigned long long)nbr, DIGITS));
	return (fl);
}

void			print_spec_f(int *len, t_flags fl, double n)
{
	fl.sign = (n >= 0) ? '+' : '-';
	fl.ulli = (n >= 0) ? n : -n;
	if (fl.point == 0)
		fl.size = 6;
	else
		fl.size = fl.precision;
	fl = ft_dectoa(n, fl);
	fl.a = ft_ullitoa_base(fl.ulli, "0123456789");
	if (fl.sign == '-' || (fl.plus == 1 && fl.sign == '+'))
		ft_putchar_len(fl.sign, len);
	ft_putcstr_len(fl.a, len, ft_strlen(fl.a));
	if (!(fl.point == 1 && fl.precision == 0))
		ft_putcstr_len(fl.d, len, ft_strlen(fl.d));
}
