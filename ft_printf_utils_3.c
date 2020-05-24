/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 18:56:49 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/24 19:26:25 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	ft_dectoa_ver_prec(t_flags fl)
{
	if (fl.precision > 0 && (ft_strlen(fl.d)) > (size_t)fl.precision + 1)
	{
		fl.tmp = ft_substr(fl.d, 2, ft_strlen(fl.d) - 2);
		free(fl.d);
		fl.d = ft_strjoin(".", fl.tmp);
		free(fl.tmp);
	}
	return (fl);
}

static int		ft_dectoa_ver_rnd(t_flags fl)
{
	int	aux;

	aux = fl.f * 10;
	fl.size++;
	while (fl.size >= 0 && (aux % 10) == 9)
	{
		fl.f = fl.f * 10;
		aux = fl.f;
		aux = aux % 10;
		if (fl.size == 1 && aux >= fl.rnd)
			fl.size--;
		fl.size--;
	}
	if (fl.size < 0)
		return (1);
	return (0);
}

static t_flags	ft_dectoa_aux(t_flags fl, size_t *nbr, int *len)
{
	unsigned long long int	aux;

	*nbr = (fl.f - fl.ulli) * ft_pow(10, fl.size + 1);
	aux = *nbr;
	*len = 1;
	while (aux /= 10)
		(*len)++;
	if ((*nbr % 10) >= fl.rnd)
		*nbr += 10;
	*nbr /= 10;
	aux = (fl.f * 10);
	if (ft_dectoa_ver_rnd(fl) == 1 ||
		(fl.point == 1 && fl.precision == 0 && (aux % 10) >= fl.rnd))
	{
		fl.ulli++;
		if (fl.spe_c == 'e' && fl.ulli == 10)
		{
			fl.ulli = 1;
			fl.e[3]++;
		}
		*nbr = 0;
	}
	return (fl);
}

t_flags	ft_dectoa(t_flags fl)
{
	char	z0[20];
	size_t	nbr;
	int		len;

	fl = ft_dectoa_aux(fl, &nbr, &len);
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
	fl.tmp = ft_ullitoa_base((unsigned long long)nbr, DIGITS);
	if (fl.hash == 1 && fl.point == 1 && fl.precision == 0)
		fl.d = ft_strdup(".");
	else if (fl.hash == 0 && fl.point == 1 && fl.precision == 0)
		fl.d = ft_strdup("");
	else
		fl.d = ft_strjoin(z0, fl.tmp);
	free(fl.tmp);
	fl = ft_dectoa_ver_prec(fl);
	return (fl);
}
