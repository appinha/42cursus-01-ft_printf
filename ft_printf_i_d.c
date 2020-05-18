/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 13:25:14 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/18 00:00:33 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_uitoa(unsigned int n)
{
	char	*str;
	long	nbr;
	size_t	size;

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

static void	print_precis(int *len, t_flags fl, int size)
{
	while (fl.precision > size)
	{
		ft_putchar_len('0', len);
		fl.precision--;
	}
}

static void	print_width(int *len, t_flags fl, char sign, int size)
{
	if (sign == '-' || (fl.plus == 1 && sign == '+'))
		fl.width--;
	fl.precision = (fl.precision > size) ? fl.precision : size;
	if (fl.pad_c == '0' && (fl.minus == 1 || fl.point == 1))
		fl.pad_c = ' ';
	while (fl.width > fl.precision)
	{
		ft_putchar_len(fl.pad_c, len);
		fl.width--;
	}
}

void	print_spec_i_d(int *len, t_flags fl, int n)
{
	char	*a;
	char	sign;
	int		size;

	sign = (n >= 0) ? '+' : '-';
	n = (n >= 0) ? n : -n;
	a = ft_uitoa((unsigned int)n);
	size = ft_strlen(a);
	if (fl.point == 1)
		fl.pad_c = ' ';
	if (fl.minus == 0 && fl.pad_c == ' ')
		print_width(len, fl, sign, size);
	if (sign == '-' || (fl.plus == 1 && sign == '+'))
		ft_putchar_len(sign, len);
	if (fl.minus == 0 && fl.pad_c == '0')
		print_width(len, fl, sign, size);
	if (fl.point == 1)
		print_precis(len, fl, size);
	ft_putcstr_len(a, len, ft_strlen(a));
	if (fl.minus == 1)
		print_width(len, fl, sign, size);
}
