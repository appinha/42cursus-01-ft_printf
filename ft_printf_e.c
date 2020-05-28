/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 23:55:34 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/27 23:00:36 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	fill_0s(t_flags fl, char *nbr)
{
	char	str[fl.precision + 3];
	size_t	strlen;
	int		i;

	strlen = ft_strlen(nbr);
	if (fl.point == 1 && fl.precision == 0)
		ft_strlcpy(str, nbr, 2);
	else
	{
		ft_strlcpy(str, nbr, strlen + 1);
		i = strlen;
		while (i <= fl.precision + 1)
			str[i++] = '0';
		str[i] = '\0';
	}
	fl.d = ft_strdup(str);
	return (fl);
}

static t_flags	get_0nbr_e(t_flags fl)
{
	ft_strlcpy(fl.e, "e-", 3);
	fl.size = 1;
	fl.d = ft_ftoa_rnd(fl.f, fl.size, 5);
	fl.j = 1;
	while (fl.d[++fl.j] != '\0' && fl.j <= 18)
	{
		if ((ft_strchr_01("123456789", fl.d[fl.j])) == 1)
			break ;
		if (fl.d[fl.j + 1] == '\0')
		{
			free(fl.d);
			fl.size++;
			fl.d = ft_ftoa_rnd(fl.f, fl.size, 5);
		}
	}
	if (fl.j > 18 && (fl.e[1] = '+'))
	{
		free(fl.d);
		fl = fill_0s(fl, "0.");
		return (fl);
	}
	fl.j = 1;
	while (fl.d[++fl.j] != '\0')
	{
		if ((ft_strchr_01("123456789", fl.d[fl.j])) == 1)
			break ;
	}
	free(fl.d);
	fl.d = ft_ftoa_rnd(fl.f, (fl.j - 1) + fl.precision, 5);
	fl.j = 1;
	while (fl.d[++fl.j] != '\0')
	{
		if (fl.d[fl.j] == '0' && (fl.d[fl.j] = '.'))
			fl.d[fl.j - 1] = '0';
		else if ((fl.d[fl.j - 1] = fl.d[fl.j]) && (fl.d[fl.j] = '.'))
			break ;
	}
	fl.e_nbr = fl.j - 1;
	fl.tmp = ft_substr(fl.d, fl.j - 1, ft_strlen(fl.d) - (fl.j - 1));
	free(fl.d);
	if (ft_strlen(fl.tmp) >= fl.strlen)
		fl.d  = ft_substr(fl.tmp, 0, fl.strlen);
	else
		fl = fill_0s(fl, fl.tmp);
	free(fl.tmp);
	return (fl);
}

static t_flags	get_nbr_e(t_flags fl, unsigned long long int i_part)
{
	ft_strlcpy(fl.e, "e+", 3);
	while (i_part /= 10)
		fl.e_nbr++;
	fl.d = ft_ftoa_rnd((fl.f / ft_pow(10, fl.e_nbr)), fl.precision, 5);
	fl.j = ft_strlen(fl.d);
	while (--fl.j >= 0)
	{
		if (fl.d[fl.j] == '.' && fl.j >= 2)
		{
			fl.d[fl.j] = fl.d[fl.j - 1];
			fl.d[fl.j - 1] = '.';
		}
	}
	if (ft_strlen(fl.d) > fl.strlen)
	{
		fl.tmp = ft_substr(fl.d, 0, fl.strlen);
		fl.e_nbr += ft_strlen(fl.d) - fl.strlen;
		free(fl.d);
		fl.d = fl.tmp;
	}
	return (fl);
}

void			print_spec_e(int *len, t_flags fl, double n)
{
	fl.sign = (n >= 0) ? '+' : '-';
	fl.f = (n >= 0) ? n : -n;
	fl.ulli = fl.f;
	fl.e_nbr = 0;
	fl.strlen = (fl.precision > 0) ? (size_t)fl.precision + 2 : 1;
	if (fl.ulli > 0)
		fl = get_nbr_e(fl, fl.ulli);
	else
		fl = get_0nbr_e(fl);
	fl.tmp = ft_ullitoa_base(fl.e_nbr, DIGITS);
	if ((ft_strlen(fl.tmp)) == 1 && (ft_strlcat(fl.e, "0", 4)))
		ft_strlcat(fl.e, fl.tmp, 5);
	else
		ft_strlcat(fl.e, fl.tmp, 5);
	free(fl.tmp);
	if (fl.hash == 1 && fl.point == 1 && fl.precision == 0)
	{
		fl.tmp = ft_strjoin(fl.d, ".");
		free(fl.d);
		fl.d = fl.tmp;
	}
	fl.a = ft_strjoin(fl.d, fl.e);
	free(fl.d);
	print_flags(len, fl);
	free(fl.a);
}
