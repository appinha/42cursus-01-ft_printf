/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 15:03:07 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/20 15:13:54 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_dectoa_ver(double f0, t_flags fl)
{
	int	aux;

	aux = f0 * 10;
	//printf("[aux=%i]", aux);
	//printf("[fl.size=%i]", fl.size);
	fl.size++;
	while (fl.size >= 0 && aux == 9)
	{
		f0 = f0 * 10;
		aux = f0;
		aux = aux % 10;
		if (fl.size == 1 && aux >= 5)
			fl.size--;
		//printf("[#%i-f=%.7f-aux=%i]", fl.size, f0, aux);
		fl.size--;
	}
	//printf("(fl.size=%i)", fl.size);
	if (fl.size < 0)
		return (1);
	return (0);
}

static t_flags	ft_dectoa_aux(double n, t_flags fl, size_t *nbr, int *len)
{
	size_t	aux;

	fl.f = (n >= 0) ? n : -n;
	aux = (fl.f - fl.ulli) * ft_pow(10, fl.size + 1);
	*nbr = aux;
	*len = 1;
	while (aux /= 10)
		(*len)++;
	if ((*nbr % 10) >= 5)
		*nbr += 10;
	*nbr /= 10;
	aux = (fl.f * 10);
	//printf("(%i)", ft_dectoa_ver(f - fl.ulli, fl));
	if (ft_dectoa_ver(fl.f - fl.ulli, fl) == 1 ||
		(fl.point == 1 && fl.precision == 0 && (aux % 10) >= 5))
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
	if (!(fl.hash == 1 && fl.point == 1 && fl.precision == 0) &&
		len < fl.size + 1)
	{
		fl.j = 1;
		while (len++ < fl.size + 1)
			zeros[fl.j++] = '0';
		zeros[fl.j] = '\0';
	}
	if (fl.hash == 1 && fl.point == 1 && fl.precision == 0)
		fl.d = ft_strdup(".");
	else if (fl.hash == 0 && fl.point == 1 && fl.precision == 0)
		fl.d = ft_strdup("");
	else
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
	fl.a = ft_strjoin(ft_ullitoa_base(fl.ulli, "0123456789"), fl.d);
	print_flags(len, fl);
	/*
	if (fl.sign == '-' || (fl.plus == 1 && fl.sign == '+'))
		ft_putchar_len(fl.sign, len);
	ft_putcstr_len(fl.a, len, ft_strlen(fl.a));
	if (!(fl.point == 1 && fl.precision == 0))
		ft_putcstr_len(fl.d, len, ft_strlen(fl.d));
	if (fl.hash == 1 && fl.point == 1 && fl.precision == 0)
		ft_putchar_len('.', len);
	*/
}
