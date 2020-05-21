/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 15:03:07 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/21 01:44:44 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_dectoa_ver(double f0, t_flags fl)
{
	int	aux;

	aux = f0 * 10;
	fl.size++;
	while (fl.size >= 0 && aux == 9)
	{
		f0 = f0 * 10;
		aux = f0;
		aux = aux % 10;
		if (fl.size == 1 && aux >= 5)
			fl.size--;
		fl.size--;
	}
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
	char	z0[20];
	size_t	nbr;
	int		len;

	fl = ft_dectoa_aux(n, fl, &nbr, &len);
	if (nbr == 0)
		len = 2;
	z0[0] = '.';
	z0[1] = '\0';
	if (!(fl.hash == 1 && fl.point == 1 && fl.precision == 0) &&
		len < fl.size + 1)
	{
		fl.j = 1;
		while (len++ < fl.size + 1)
			z0[fl.j++] = '0';
		z0[fl.j] = '\0';
	}
	if (fl.hash == 1 && fl.point == 1 && fl.precision == 0)
		fl.d = ft_strdup(".");
	else if (fl.hash == 0 && fl.point == 1 && fl.precision == 0)
		fl.d = ft_strdup("");
	else
		fl.d = ft_strjoin(z0, ft_ullitoa_base((unsigned long long)nbr, DIGITS));
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
	if (fl.ulli == 0 && fl.point == 1 && fl.precision == 0)
		ft_putchar_len('0', len);
}

void			print_spec_e(int *len, t_flags fl, double n)
{
	char	d[fl.precision + 3];
	char	e[3];
	int		aux;

	fl.sign = (n >= 0) ? '+' : '-';
	d[1] = '.';
	d[fl.precision + 2] = '\0';
	e[0] = '0';
	e[2] = '\0';
	//printf("[fl.precision=%i]", fl.precision);
	fl.ulli = (n >= 0) ? n : -n;
	fl.size = 1;
	while (fl.ulli /= 10)
		fl.size++;
	aux = fl.size - 1;
	//printf("[aux=%i]", aux);
	fl.j = 1;
	while (aux >= 0 && fl.j >= 0)
	{
		e[fl.j--] = aux % 10 + '0';
		aux /= 10;
	}
	//printf("[fl.size=%i]", fl.size);

	fl.ulli = (n >= 0) ? n : -n;
	if (fl.size - 1 > fl.precision)
		fl.ulli = fl.ulli / ft_pow(10, fl.size - fl.precision - 1);
	//printf("[fl.ulli=%lli]", fl.ulli);
	fl.j = fl.precision + 1;
	//printf("[fl.j=%i]", fl.j);
	while (fl.ulli > 9 && fl.j > 0)
	{
		while (fl.size++ < fl.precision + 1)
			d[fl.j--] = '0';
		d[fl.j--] = fl.ulli % 10 + '0';
		fl.ulli /= 10;
	}
	//printf("[fl.ulli=%lli]", fl.ulli);
	d[0] = fl.ulli + '0';
	fl.a = ft_strjoin(d, "e+");
	fl.a = ft_strjoin(fl.a, e);
	print_flags(len, fl);
	//printf("d=\"%s\"\n", d);
	//printf("e=\"%s\"\n", e);
	//printf("%i, %c, %e", *len, fl.spe_c, n);
}
