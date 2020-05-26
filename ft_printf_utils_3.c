/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 18:56:49 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/26 19:29:38 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ver_precision(char *dec_str, short int dec_len)
{
	size_t	strlen;
	int		diff;
	char	*tmp;

	strlen = ft_strlen(dec_str);
	diff = strlen - 1 - (size_t)dec_len;
	if (dec_len > 0 && diff > 0)
	{
		tmp = ft_substr(dec_str, diff + 1, dec_len + 1);
		free(dec_str);
		dec_str = ft_strjoin(".", tmp);
		free(tmp);
	}
	return (dec_str);
}

static t_ftoa	dectoa(t_ftoa var)
{
	int		i;
	char	z0[20];
	char	*tmp;

	z0[0] = '.';
	i = 1;
	if (var.dectoint_size < var.dec_len + 1)
	{
		while (var.dectoint_size++ < var.dec_len + 1)
			z0[i++] = '0';
	}
	z0[i] = '\0';
	tmp = ft_ullitoa_base(var.dectoint, DIGITS);
	var.d = ft_strjoin(z0, tmp);
	var.d = ver_precision(var.d, var.dec_len);
	free(tmp);
	return (var);
}

static t_ftoa	ver_rounding(t_ftoa var)
{
	unsigned long long int	aux_int;
	long double				aux_dbl;
	int						size;

	aux_dbl = var.dec_part * ft_pow(10, var.dec_len);
	aux_dbl -= var.dectoint;
	if (aux_dbl >= var.rnd)
		var.dectoint += 1;
	aux_int = var.dectoint;
	size = 1;
	while (aux_int /= 10)
		size++;
	aux_int = var.dec_part * 10;
	if ((var.dec_len == 0 && aux_int >= (unsigned)var.rnd) ||
		(size > var.dectoint_size + 1 && aux_int + 1 >= (unsigned)var.rnd))
	{
		var.dectoint = 0;
		var.int_part++;
	}
	return (var);
}

static t_ftoa	dectoulli(t_ftoa var)
{
	var.int_part = var.n;
	var.dec_part = var.n - var.int_part;
	var.dectoint = var.dec_part * ft_pow(10, var.dec_len);
	var.dectoint_size = 1;
	while ((var.dectoint) /= 10)
		(var.dectoint_size)++;
	var.dectoint = var.dec_part * ft_pow(10, var.dec_len);
	var = ver_rounding(var);
	if (var.dectoint == 0)
		var.dectoint_size = 2;
	return (var);
}

char			*ft_ftoa_rnd(long double n, short int dec_len, short int rnd)
{
	t_ftoa	var;
	char	*tmp;

	var.n = (n >= 0) ? n : -n;
	var.dec_len = dec_len;
	var.rnd = rnd / 10;
	var = dectoulli(var);
	if (var.dec_len > 0)
		var = dectoa(var);
	else
		var.d = ft_strdup("");
	tmp = ft_ullitoa_base(var.int_part, DIGITS);
	var.a = ft_strjoin(tmp, var.d);
	free(tmp);
	free(var.d);
	return (var.a);
}
