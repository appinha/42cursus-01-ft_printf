/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:24:53 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/17 00:37:44 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t l;

	if (!s)
		return (0);
	l = 0;
	while (s[l] != 0)
		l++;
	return (l);
}

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putcstr_len(char *s, int *len, int size)
{
	int i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] && i < size)
		{
			ft_putchar_len(s[i], len);
			i++;
		}
	}
}

int		ft_strchr_01(char *s, char c)
{
	int i;

	i = 0;
	//printf("  > ft_strchr_01 • s: \"%s\"\n", s);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	//printf("  > ft_strchr_01 • return (0)\n");
	return (0);
}
