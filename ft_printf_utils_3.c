/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 18:56:49 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/25 21:07:39 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ver_precision(char *dec_str, short int dec_len)
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
}

static t_ftoa_rnd	ver_rounding(t_ftoa_rnd var)
{
	unsigned long long int	aux;
	int						size;

	if ((var.dec_int % 10) >= (unsigned)var.rnd)
		var.dec_int += 10;
	aux = var.dec_int;
	size = 1;
	while (aux /= 10)
		size++;
	aux = var.dec_part * 10;
	if ((var.dec_len == 0 && aux >= (unsigned)var.rnd) ||
		(size > var.dec_int_size + 1 && aux + 1 >= (unsigned)var.rnd))
	{
		var.dec_int = 0;
		var.int_part++;
	}
	return (var);
}

static t_ftoa_rnd	dectoulli(t_ftoa_rnd var)
{
	var.int_part = var.n;
	var.dec_part = var.n - var.int_part;
	var.dec_int = var.dec_part * ft_pow(10, var.dec_len);
	var.dec_int_size = 1;
	while ((var.dec_int) /= 10)
		(var.dec_int_size)++;
	var.dec_int = var.dec_part * ft_pow(10, var.dec_len + 1);
	var = ver_rounding(var);
	var.dec_int /= 10;
	if (var.dec_int == 0)
		var.dec_int_size = 2;
	return (var);
}

char			*ft_ftoa_rnd(double n, short int dec_len, short int rnd)
{
	t_ftoa_rnd	var;
	int			i;

	var.n = (n >= 0) ? n : -n;
	var.dec_len = dec_len;
	var.rnd = rnd;
	var = dectoulli(var);
	if (var.dec_len >= 0)
	{
		var.z0[0] = '.';
		i = 1;
		if (var.dec_int_size < dec_len + 1)
		{
			while (var.dec_int_size++ < dec_len + 1)
				var.z0[i++] = '0';
		}
		var.z0[i] = '\0';
		var.tmp = ft_ullitoa_base(var.dec_int, DIGITS);
		var.d = ft_strjoin(var.z0, var.tmp);
		ver_precision(var.d, var.dec_len);
		free(var.tmp);
	}
	if (var.dec_len == 0)
		var.d = ft_strdup("");
	var.tmp = ft_ullitoa_base(var.int_part, DIGITS);
	var.a = ft_strjoin(var.tmp, var.d);
	free(var.tmp);
	free(var.d);
	return (var.a);
}
