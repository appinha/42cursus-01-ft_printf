/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:36:54 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/15 12:40:49 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static void print_minus()
{
	while(fl.width - 1 > fl.)
}
*/
void	print_spec_c(int *len, t_flags fl, char c)
{
	if (fl.minus == 1)
	{
		ft_putchar_len(c, len);
		//tamanho = print_just(fl) + tamanho;
	}
	else
	{
		//tamanho = print_just(fl);
		ft_putchar_len(c, len);
	}
}

void	print_spec_s(int *len, t_flags fl, char *s)
{
	if (s == NULL)
		s = "(null)";
	if (fl.minus == 1)
	{
		ft_putstr_len(s, len);
		//tamanho = print_just(fl) + tamanho;
	}
	else
	{
		//tamanho = print_just(fl);
		ft_putstr_len(s, len);
	}
}
