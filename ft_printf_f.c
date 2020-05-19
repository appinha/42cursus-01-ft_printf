/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 15:03:07 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/19 18:35:39 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_pot10(int x)
{
	int	n;

	if (x > 0)
	{
		n = 10;
		while (x-- > 1)
			n *= 10;
		return (n);
	}
	return(0);
}

static int		ft_dectoa_aux(double n, int size, int *len)
{
	double	f;
	int		nbr;
	int		aux;

	f = (n >= 0)? n : -n;
	aux = f;
	aux = (f - aux) * ft_pot10(size + 1);
	nbr = aux;
	*len = 1;
	while (aux /= 10)
		(*len)++;
	if ((nbr % 10) >= 5)
		nbr += 10;
	nbr /= 10;
	return (nbr);
}

static char		*ft_dectoa(double n, int size)
{
	char	*a;
	char	zeros[20];
	int		nbr;
	int		len;
	int		i;

	nbr = ft_dectoa_aux(n, size, &len);
	zeros[0] = '.';
	zeros[1] = '\0';
	if (len < size + 1)
	{
		i = 1;
		while (len++ < size + 1)
			zeros[i++] = '0';
		zeros[i] = '\0';
	}
	a = ft_strjoin(zeros, ft_ullitoa_base((unsigned long long int)nbr, DIGITS));
	return (a);
}

void		print_spec_f(int *len, t_flags fl, double n)
{
	char	*d;

	fl.sign = (n >= 0) ? '+' : '-';
	fl.ulli = (n >= 0) ? n : -n;
	if (fl.point == 0)
		fl.size = 6;
	else
		fl.size = fl.precision;
	fl.a = ft_ullitoa_base(fl.ulli, "0123456789");
	d = ft_dectoa(n, fl.size);
	if (fl.sign == '-' || (fl.plus == 1 && fl.sign == '+'))
		ft_putchar_len(fl.sign, len);
	ft_putcstr_len(fl.a, len, ft_strlen(fl.a));
	ft_putcstr_len(d, len, ft_strlen(d));
}
