/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:10:37 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/09 16:51:36 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static int	ft_strchr_specs(char *s, char c)
{
	int i;

	i = 0;
	while (terms[i] != '\0')
	{
		if (terms[i == c])
			return (1);
		i++;
	}
	return (0);
}

static int	get_flags(va_list args, const char *format, int len, int *i)
{
	int j;

	j = 0;
	if (format[*i] != '%')
	{
		while (ft_strchr_specs(ALL_SPEC, format[*i]))
		{

		}
	}
	return (len);
}
*/
static int	print_simple(char c, int len)
{
	//ft_putchar(c);
	return (c + len + 1);
}

int			ft_printf(const char *format, ...)
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
			len = print_simple(format[i++], len);
		else
		{
			//len = get_flags(args, format, len, &i)
			len++;
			i += 2;
		}
	}
	va_end(args);
	return (len);
}
