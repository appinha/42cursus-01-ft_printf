/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:10:37 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/14 23:24:33 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//static void	flag2struct(va_list args, )
static t_flags	flag2struct(char *flags, t_flags fl)
{
	fl.minus = ft_strchr_01(flags, '-');
	fl.dot = ft_strchr_01(flags, '.');
	return (fl);
}

static void		triage_specs(va_list args, int *len, char spec, char *flags)
//static void	triage_specs(int *len, char spec, char *flags)
{
	t_flags	fl;

	fl.spec = spec;
	//printf("• fl.spec = '%c'\n", fl.spec);
	//printf("• len = '%i'\n", *len);
	//fl = flag2struct(args, spec, flags);
	fl = flag2struct(flags, fl);
	//printf("• fl.minus = %i\n", fl.minus);
	//printf("• c = '%c'\n", va_arg(args, int));
	if (spec == 'c')
		print_spec_c(len, fl, va_arg(args, int));
}

static void		get_specs(va_list args, const char *format, int *len, int *i)
//static void	get_specs(const char *format, int *len, int *i)
{
	int		j;
	char 	spec;
	char	flags[1024];

	(*i)++;
	j = 0;
	spec = 0;
	while (ft_strchr_01(ALL_S_F, format[*i]))
	{
		if (ft_strchr_01(SPECS, format[*i]))
			break;
		flags[j++] = format[*i];
		(*i)++;
	}
	flags[j] = '\0';
	if (ft_strchr_01(SPECS, format[*i]))
	{
		spec = format[(*i)++];
		triage_specs(args, len, spec, flags);
		//triage_specs(len, spec, flags);
	}
	else
		(*len) = -1;
}
/*
static void	print_plain(char c, int *len)
{
	ft_putchar(c);
	(*len)++;
}
*/
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
			//print_plain(format[i++], &len);
		else
		{
			get_specs(args, format, &len, &i);
			//get_specs(format, &len, &i);
			if (len == -1)
				return (-1);
		}
	}
	va_end(args);
	return (len);
}
