/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:10:37 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/16 23:19:19 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		triage_specs(va_list args, int *len, t_flags fl)
{
	if (fl.spe_c == 'c')
		print_spec_c(len, fl, va_arg(args, int));
	if (fl.spe_c == 's')
		print_spec_s(len, fl, va_arg(args, char *));
}

static t_flags	treat_flags(char *flags, t_flags fl)
{
	int i;

	i = 0;
	while (flags[i] != '\0' && ft_strchr_01(FLAGS, flags[i]))
	{
		if (flags[i++] == '0')
			fl.pad_c = '0';
	}
	while (flags[i] != '\0' && ft_strchr_01(DIGITS, flags[i]))
		fl.width = 10 * fl.width + flags[i++] - '0';
	if (flags[i++] == '.')
	{
		while (flags[i] != '\0' && ft_strchr_01(DIGITS, flags[i]))
			fl.precision = 10 * fl.precision + flags[i++] - '0';
	}
	//printf("> collected flags:\n");
	//printf("  • fl.spe_c = '%c'\n", fl.spe_c);
	//printf("  • fl.pad_c = '%c'\n", fl.pad_c);
	//printf("  • fl.minus = '%i'\n", fl.minus);
	//printf("  • fl.plus = '%i'\n", fl.plus);
	//printf("  • fl.hash = '%i'\n", fl.hash);
	//printf("  • fl.space = '%i'\n", fl.space);
	//printf("  • fl.width = '%i'\n", fl.width);
	//printf("  • fl.precision = '%i'\n", fl.precision);
	return (fl);
}

static void		get_specs(va_list args, const char *format, int *len, int *i)
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
		fl = treat_flags(flags, fl);
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
				get_specs(args, format, &len, &i);
			if (len == -1)
				return (-1);
		}
	}
	va_end(args);
	return (len);
}
