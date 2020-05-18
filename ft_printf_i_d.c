/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 13:25:14 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/18 02:39:25 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_ullitoa(unsigned long long n)
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

static void	print_flags(int *len, t_flags fl)
{
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
		while (fl.precision > fl.size)
		{
			ft_putchar_len('0', len);
			fl.precision--;
		}
	}
}

void		print_spec_i_d(int *len, t_flags fl, long long int n)
{
	unsigned long long	nbr;
	char				*a;

	//printf("[•]");
	fl.sign = (n >= 0) ? '+' : '-';
	nbr = (n >= 0) ? n : -n;
	a = ft_ullitoa(nbr);
	fl.size = ft_strlen(a);
	if (n == 0 && fl.point == 1 && fl.precision == 0)
		fl.width++;
	print_flags(len, fl);
	if (!(n == 0 && fl.point == 1 && fl.precision == 0))
		ft_putcstr_len(a, len, ft_strlen(a));
	if (fl.minus == 1)
		print_width(len, fl);
}
