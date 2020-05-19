/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_iduxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 13:25:14 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/19 12:15:28 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_ullitoa_base(unsigned long long int n, char *base)
{
	char					*a;
	unsigned long long int	nbr;
	size_t					size;
	int						b_len;

	b_len = ft_strlen(base);
	nbr = n;
	size = 1;
	while (n /= b_len)
		size++;
	if (!(a = (char *)malloc(size + 1)))
		return (0);
	a[size--] = '\0';
	while (nbr > 0)
	{
		a[size--] = base[nbr % b_len];
		nbr /= b_len;
	}
	if (size == 0 && a[1] == '\0')
		a[0] = '0';
	return (a);
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

static void	print_flags(int *len, t_flags fl)
{
	fl.size = ft_strlen(fl.a);
	if (fl.ulli == 0 && fl.point == 1 && fl.precision == 0)
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
	if (!(fl.ulli == 0 && fl.point == 1 && fl.precision == 0))
		ft_putcstr_len(fl.a, len, ft_strlen(fl.a));
	if (fl.minus == 1)
		print_width(len, fl);
}

void		print_spec_i_d_u(int *len, t_flags fl, va_list args)
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

void		print_spec_x_X(int *len, t_flags fl, va_list args)
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
	if (fl.hash == 1 && fl.spe_c == 'x')
		fl.a = ft_strjoin("0x", fl.a);
	if (fl.hash == 1 && fl.spe_c == 'X')
		fl.a = ft_strjoin("0X", fl.a);
	print_flags(len, fl);
}
