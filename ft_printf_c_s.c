/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:36:54 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/16 23:22:08 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void print_padding(int *len, t_flags fl)
{
	while(fl.width > fl.precision)
	{
		ft_putchar_len(' ', len);
		fl.width--;
	}
}

void	print_spec_c(int *len, t_flags fl, char c)
{
	fl.precision = 1;
	if (fl.minus == 0)
		print_padding(len, fl);
	ft_putchar_len(c, len);
	if (fl.minus == 1)
		print_padding(len, fl);
}

void	print_spec_s(int *len, t_flags fl, char *s)
{
	int s_len;

	s_len = 0;
	if (s == NULL)
		s = "(null)";
	else
		s_len = ft_strlen(s);
	if ((fl.point == 1 && fl.precision > s_len) || fl.point == 0)
		fl.precision = s_len;
	if (fl.minus == 0)
		print_padding(len, fl);
	ft_putcstr_len(s, len, fl.precision);
	if (fl.minus == 1)
		print_padding(len, fl);
}
