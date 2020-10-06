/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:42:16 by abonnel           #+#    #+#             */
/*   Updated: 2020/09/30 19:29:36 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		is_charset(char c, char *charset)
{
	int		j;

	j = 0;
	while (c != charset[j] && charset[j])
		j++;
	if (c == charset[j])
		return (0);
	return (2);
}

int		ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		if ((str[i] >= 32) && (str[i] <= 126))
			i++;
		else
			return (2);
	return (0);
}

int		ft_atoi(char *str, int len)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && i < len - 3)
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb);
}

int		len_line(char *tab)
{
	int i;

	i = 0;
	while (tab[i] && tab[i] != '\n')
		i++;
	return (i);
}
