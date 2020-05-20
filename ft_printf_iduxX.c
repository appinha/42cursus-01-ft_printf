/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_iduxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 13:25:14 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/20 12:06:21 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spec_i_d_u(int *len, t_flags fl, va_list args)
{
	if (fl.spe_c == 'i' || fl.spe_c == 'd')
	{
		if (fl.length <= 0)
			fl.lli = va_arg(args, int);
		if (fl.length == 1)
			fl.lli = va_arg(args, long int);
		if (fl.length == 2)
			fl.lli = va_arg(args, long long int);
		fl.sign = (fl.lli >= 0) ? '+' : '-';
		fl.ulli = (fl.lli >= 0) ? fl.lli : -fl.lli;
	}
	if (fl.spe_c == 'u')
	{
		if (fl.length <= 0)
			fl.ulli = va_arg(args, unsigned int);
		if (fl.length == 1)
			fl.ulli = va_arg(args, unsigned long int);
		if (fl.length == 2)
			fl.ulli = va_arg(args, unsigned long long int);
		fl.sign = '+';
	}
	fl.a = ft_ullitoa_base(fl.ulli, "0123456789");
	print_flags(len, fl);
}

void	print_spec_x_X(int *len, t_flags fl, va_list args)
{
	if (fl.length <= 0)
		fl.ulli = va_arg(args, unsigned int);
	if (fl.length == 1)
		fl.ulli = va_arg(args, unsigned long int);
	if (fl.length == 2)
		fl.ulli = va_arg(args, unsigned long long int);
	fl.sign = '+';
	if (fl.spe_c == 'x')
		fl.a = ft_ullitoa_base(fl.ulli, "0123456789abcdef");
	if (fl.spe_c == 'X')
		fl.a = ft_ullitoa_base(fl.ulli, "0123456789ABCDEF");
	print_flags(len, fl);
}

void	print_spec_o(int *len, t_flags fl, va_list args)
{
	if (fl.length <= 0)
		fl.ulli = va_arg(args, unsigned int);
	if (fl.length == 1)
		fl.ulli = va_arg(args, unsigned long int);
	if (fl.length == 2)
		fl.ulli = va_arg(args, unsigned long long int);
	fl.sign = '+';
	fl.a = ft_ullitoa_base(fl.ulli, "01234567");
	print_flags(len, fl);
}
