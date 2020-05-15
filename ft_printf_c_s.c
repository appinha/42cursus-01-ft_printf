/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:36:54 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/14 23:04:40 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spec_c(int *len, t_flags fl, char c)
{
	if (fl.minus == 1)
	{
		//printf("> print_spec_c IF (fl.minus == 1)");
		ft_putchar_len(c, len);
		//tamanho = print_just(fl) + tamanho;
	}
	else
	{
		//printf("> print_spec_c ELSE (fl.minus == 1)");
		//tamanho = print_just(fl);
		ft_putchar_len(c, len);
	}
}
