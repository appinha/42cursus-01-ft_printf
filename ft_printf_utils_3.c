/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 18:56:49 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/25 16:58:44 by apuchill         ###   ########.fr       */
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

static t_flags	ft_dectoa_rnd(t_flags fl, int dec_int_size,
					unsigned long long int *dec_int)
{
	unsigned long long int	aux;
	int						size;

	if (*dec_int > 9 && (*dec_int % 10) >= fl.rnd)
		*dec_int += 10;
	aux = *dec_int;
	size = 1;
	while (aux /= 10)
		size++;
	if (((size > dec_int_size + 1) && (aux % 10) == 0) ||
		(*dec_int <= 9 && *dec_int >= fl.rnd))
	{
		*dec_int = 0;
		fl.ulli++;
	}
	return (fl);
}

static t_flags	ft_dectoa_convrs(t_flags fl, int dec_len,
					unsigned long long int *dec_int, int *dec_int_size)
{
	*dec_int = (fl.f - fl.ulli) * ft_pow(10, dec_len);
	*dec_int_size = 1;
	while (*(dec_int) /= 10)
		(*dec_int_size)++;
	*dec_int = (fl.f - fl.ulli) * ft_pow(10, dec_len + 1);
	if (fl.spe_c == 'f')
		fl = ft_dectoa_rnd(fl, *dec_int_size, dec_int);
	*dec_int /= 10;
	if (*dec_int == 0)
		*dec_int_size = 2;
	return (fl);
}

t_flags	ft_dectoa(t_flags fl, int dec_len)
{
	unsigned long long int	dec_int;
	int						dec_int_size;
	char					z0[20];

	fl = ft_dectoa_convrs(fl, dec_len, &dec_int, &dec_int_size);
	z0[0] = '.';
	z0[1] = '\0';
	if (!(fl.hash == 1 && fl.point == 1 && fl.precision == 0) &&
		dec_int_size < dec_len + 1)
	{
		fl.j = 1;
		while (dec_int_size++ < dec_len + 1)
			z0[fl.j++] = '0';
		z0[fl.j] = '\0';
	}
	fl.tmp = ft_ullitoa_base(dec_int, DIGITS);
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
