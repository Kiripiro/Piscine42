/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 15:12:34 by atourret          #+#    #+#             */
/*   Updated: 2020/09/24 18:16:44 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (is_sep(str[i], charset) && str[i])
			i++;
		if (!(is_sep(str[i], charset)) && str[i])
		{
			count++;
			while (!(is_sep(str[i], charset)) && str[i])
				i++;
		}
	}
	return (count);
}

char	*make_tab(char *str, char *charset, int current)
{
	int		i;
	int		j;
	char	*tab;

	i = current;
	j = 0;
	while (!(is_sep(str[i], charset)) && str[i])
	{
		i++;
		j++;
	}
	if (!(tab = (char *)malloc(sizeof(char) * (j + 1))))
		return (0);
	i = current;
	j = 0;
	while ((!(is_sep(str[i], charset)) && str[i]))
	{
		tab[j] = str[i];
		i++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		nbwords;
	char	**result;

	nbwords = count_words(str, charset);
	if (!(result = (char **)malloc(sizeof(char *) * (nbwords + 1))))
		return (0);
	j = 0;
	i = 0;
	while (str[i])
	{
		while (is_sep(str[i], charset) && str[i])
			i++;
		if (!(is_sep(str[i], charset)) && str[i])
		{
			result[j] = make_tab(str, charset, i);
			while (!is_sep(str[i], charset) && str[i])
				i++;
			j++;
		}
	}
	result[j] = 0;
	return (result);
}
