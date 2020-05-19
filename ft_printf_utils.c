/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuchill <apuchill@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:24:53 by apuchill          #+#    #+#             */
/*   Updated: 2020/05/19 12:12:13 by apuchill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t l;

	if (!s)
		return (0);
	l = 0;
	while (s[l] != '\0')
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
			ft_putchar_len(s[i++], len);
	}
}

int		ft_strchr_01(char *s, char c)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i++] == c)
			return (1);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		i;
	int		j;

	if (!s1 || !s2 ||
		!(new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i] = s2[j];
		i++;
		j++;
	}
	new_str[i] = '\0';
	return (new_str);
}
