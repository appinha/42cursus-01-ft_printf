/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_f.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 15:03:07 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/26 20:35:26 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_spec_f(int *len, t_flags fl, double n)
{
	fl.sign = (n >= 0) ? '+' : '-';
	fl.f = (n >= 0) ? n : -n;
	fl.ulli = fl.f;
	fl.a = ft_ftoa_rnd(fl.f, fl.precision, 5);
	if (fl.hash == 1 && fl.point == 1 && fl.precision == 0)
	{
		fl.tmp = ft_strjoin(fl.a, ".");
		free(fl.a);
		fl.a = fl.tmp;
	}
	print_flags(len, fl);
	free(fl.a);
	if (fl.ulli == 0 && fl.point == 1 && fl.precision == 0)
		ft_putchar_len('0', len);
}
