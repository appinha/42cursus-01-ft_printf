/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:10:37 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/18 00:58:58 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		triage_specs(va_list args, int *len, t_flags fl)
{
	if (fl.spe_c == 'c')
		print_spec_c(len, fl, va_arg(args, int));
	if (fl.spe_c == 's')
		print_spec_s(len, fl, va_arg(args, char *));
	if (fl.length <= 0 && (fl.spe_c == 'i' || fl.spe_c == 'd'))
		print_spec_i_d(len, fl, va_arg(args, int));
	if (fl.length == 1 && (fl.spe_c == 'i' || fl.spe_c == 'd'))
		print_spec_i_d(len, fl, va_arg(args, long int));
	if (fl.length == 2 && (fl.spe_c == 'i' || fl.spe_c == 'd'))
		print_spec_i_d(len, fl, va_arg(args, long long int));
}

static t_flags	treat_star(va_list args, t_flags fl, int *i)
{
	int	value;

	value = va_arg(args, int);
	(*i)++;
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

static t_flags	treat_flags(va_list args, char *flags, t_flags fl)
{
	int i;

	i = 0;
	while (flags[i] != '\0' && ft_strchr_01(FLAGS, flags[i]))
	{
		if (flags[i++] == '0')
			fl.pad_c = '0';
	}
	if (flags[i] == '*')
		fl = treat_star(args, fl, &i);
	while (flags[i] != '\0' && ft_strchr_01(DIGITS, flags[i]))
		fl.width = 10 * fl.width + flags[i++] - '0';
	if (flags[i] == '.')
	{
		fl.point = 1;
		if (flags[++i] == '*')
			fl = treat_star(args, fl, &i);
		while (flags[i] != '\0' && ft_strchr_01(DIGITS, flags[i]))
			fl.precision = 10 * fl.precision + flags[i++] - '0';
	}
	while (flags[i] != '\0' && ft_strchr_01("l", flags[i++]))
		fl.length++;
	while (flags[i] != '\0' && ft_strchr_01("h", flags[i]))
		fl.length--;
	return (fl);
}

static void		get_fspecs(va_list args, const char *format, int *len, int *i)
{
	int		j;
	char	flags[20];
	t_flags	fl;

	j = 0;
	while (ft_strchr_01(ALL_FL, format[*i]) && j < 19)
		flags[j++] = format[(*i)++];
	flags[j] = '\0';
	if (ft_strchr_01(SPECS, format[*i]))
	{
		fl.spe_c = format[(*i)++];
		fl.pad_c = ' ';
		fl.minus = ft_strchr_01(flags, '-');
		fl.plus = ft_strchr_01(flags, '+');
		fl.space = ft_strchr_01(flags, ' ');
		fl.hash = ft_strchr_01(flags, '#');
		fl.width = 0;
		fl.point = 0;
		fl.precision = 0;
		fl.length = 0;
		fl = treat_flags(args, flags, fl);
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
			if (format[++i] == '%')
				ft_putchar_len(format[i++], &len);
			else
				get_fspecs(args, format, &len, &i);
			if (len == -1)
				return (-1);
		}
	}
	va_end(args);
	return (len);
}
