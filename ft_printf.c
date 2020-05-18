/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:10:37 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/18 14:29:48 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		triage_specs(va_list args, int *len, t_flags fl)
{
	if (fl.spe_c == '%')
		print_spec_pct(len, fl);
	if (fl.spe_c == 'c')
		print_spec_c(len, fl, va_arg(args, int));
	if (fl.spe_c == 's')
		print_spec_s(len, fl, va_arg(args, char *));
	if ((fl.spe_c == 'i' || fl.spe_c == 'd') && fl.length <= 0)
		print_spec_i_d(len, fl, va_arg(args, int));
	if ((fl.spe_c == 'i' || fl.spe_c == 'd') && fl.length == 1)
		print_spec_i_d(len, fl, va_arg(args, long int));
	if ((fl.spe_c == 'i' || fl.spe_c == 'd') && fl.length == 2)
		print_spec_i_d(len, fl, va_arg(args, long long int));
}

static t_flags	treat_star(va_list args, t_flags fl)
{
	int	value;

	value = va_arg(args, int);
	fl.j++;
	if (fl.point == 0)
	{
		fl.width = (value >= 0) ? value : -value;
		fl.pad_c = (value >= 0) ? fl.pad_c : ' ';
		fl.minus = (value >= 0) ? fl.minus : 1;
	}
	if (fl.point == 1)
	{
		if (value >= 0)
			fl.precision = value;
		else
			fl.point = 0;
	}
	return (fl);
}

static t_flags	treat_flags(va_list args, t_flags fl)
{
	fl.j = 0;
	fl.pad_c = ' ';
	while (fl.set[fl.j] != '\0' && ft_strchr_01(FLAGS, fl.set[fl.j]))
	{
		if (fl.set[fl.j++] == '0')
			fl.pad_c = '0';
	}
	if (fl.set[fl.j] == '*')
		fl = treat_star(args, fl);
	while (fl.set[fl.j] != '\0' && ft_strchr_01(DIGITS, fl.set[fl.j]))
		fl.width = 10 * fl.width + fl.set[fl.j++] - '0';
	if (fl.set[fl.j] == '.')
	{
		fl.point = 1;
		if (fl.set[++fl.j] == '*')
			fl = treat_star(args, fl);
		while (fl.set[fl.j] != '\0' && ft_strchr_01(DIGITS, fl.set[fl.j]))
			fl.precision = 10 * fl.precision + fl.set[fl.j++] - '0';
	}
	while (fl.set[fl.j] != '\0' && ft_strchr_01("l", fl.set[fl.j++]))
		fl.length++;
	while (fl.set[fl.j] != '\0' && ft_strchr_01("h", fl.set[fl.j++]))
		fl.length--;
	return (fl);
}

static void		get_fspecs(va_list args, const char *format, int *len, int *i)
{
	t_flags	fl;

	fl.j = 0;
	while (ft_strchr_01(ALL_FL, format[*i]) && fl.j < 19)
		fl.set[fl.j++] = format[(*i)++];
	fl.set[fl.j] = '\0';
	if (ft_strchr_01(SPECS, format[*i]))
	{
		fl.spe_c = format[(*i)++];
		fl.minus = ft_strchr_01(fl.set, '-');
		fl.plus = ft_strchr_01(fl.set, '+');
		fl.space = ft_strchr_01(fl.set, ' ');
		fl.hash = ft_strchr_01(fl.set, '#');
		fl.width = 0;
		fl.point = 0;
		fl.precision = 0;
		fl.length = 0;
		fl = treat_flags(args, fl);
		triage_specs(args, len, fl);
	}
	else
		(*len) = -1;
}

int				ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
			ft_putchar_len(format[i++], &len);
		else
		{
			i++;
			//if (format[++i] == '%')
			//	ft_putchar_len(format[i++], &len);
			//else
				get_fspecs(args, format, &len, &i);
			if (len == -1)
				return (-1);
		}
	}
	va_end(args);
	return (len);
}
