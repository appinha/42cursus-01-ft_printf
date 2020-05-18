/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i_d_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 13:25:14 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/18 19:06:12 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ullitoa(unsigned long long int n)
{
	char				*str;
	unsigned long long	nbr;
	size_t				size;

	nbr = (n > 0) ? n : -n;
	size = 1;
	while (n /= 10)
		size++;
	if (!(str = (char *)malloc(size + 1)))
		return (0);
	str[size--] = '\0';
	while (nbr > 0)
	{
		str[size--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (size == 0 && str[1] == '\0')
		str[0] = '0';
	return (str);
}

static void	print_width(int *len, t_flags fl)
{
	if (fl.sign == '-' || (fl.plus == 1 && fl.sign == '+') ||
		(fl.space == 1 && fl.plus == 0 && fl.sign == '+'))
		fl.width--;
	fl.precision = (fl.precision > fl.size) ? fl.precision : fl.size;
	if (fl.pad_c == '0' && (fl.minus == 1 || fl.point == 1))
		fl.pad_c = ' ';
	while (fl.width > fl.precision)
	{
		ft_putchar_len(fl.pad_c, len);
		fl.width--;
	}
}

static void	print_flags(int *len, t_flags fl, unsigned long long int n)
{
	fl.a = ft_ullitoa(n);
	fl.size = ft_strlen(fl.a);
	if (n == 0 && fl.point == 1 && fl.precision == 0)
		fl.width++;
	if (fl.point == 1)
		fl.pad_c = ' ';
	if (fl.minus == 0 && fl.pad_c == ' ')
		print_width(len, fl);
	if (fl.sign == '-' || (fl.plus == 1 && fl.sign == '+'))
		ft_putchar_len(fl.sign, len);
	if (fl.space == 1 && fl.plus == 0 && fl.sign == '+')
		ft_putchar_len(' ', len);
	if (fl.minus == 0 && fl.pad_c == '0')
		print_width(len, fl);
	if (fl.point == 1)
	{
		fl.j = fl.precision;
		while (fl.j-- > fl.size)
			ft_putchar_len('0', len);
	}
	if (!(n == 0 && fl.point == 1 && fl.precision == 0))
		ft_putcstr_len(fl.a, len, ft_strlen(fl.a));
	if (fl.minus == 1)
		print_width(len, fl);
}

void		print_spec_i_d_u(int *len, t_flags fl, va_list args)
{
	unsigned long long int	un;
	long long int			n;

	if (fl.spe_c == 'i' || fl.spe_c == 'd')
	{
		if (fl.length <= 0)
			n = va_arg(args, int);
		if (fl.length == 1)
			n = va_arg(args, long int);
		if (fl.length == 2)
			n = va_arg(args, long long int);
		fl.sign = (n >= 0) ? '+' : '-';
		un = (n >= 0) ? n : -n;
	}
	if (fl.spe_c == 'u')
	{
		if (fl.length <= 0)
			un = va_arg(args, unsigned int);
		if (fl.length == 1)
			un = va_arg(args, unsigned long int);
		if (fl.length == 2)
			un = va_arg(args, unsigned long long int);
		fl.sign = '+';
	}
	print_flags(len, fl, un);
}
/*
void		print_spec_i_d(int *len, t_flags fl, long long int n)
{
	unsigned long long int	nbr;

	fl.sign = (n >= 0) ? '+' : '-';
	nbr = (n >= 0) ? n : -n;
	print_flags(len, fl, nbr);
}

void		print_spec_u(int *len, t_flags fl, unsigned long long int n)
{
	fl.sign = '+';
	print_flags(len, fl, n);
}
*/
