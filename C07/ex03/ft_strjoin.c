/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 16:25:21 by atourret          #+#    #+#             */
/*   Updated: 2020/09/23 18:03:35 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		count_char(int size, char **strs)
{
	int		i;
	int		j;
	int		nbchar;

	nbchar = 0;
	j = 0;
	while (j < size)
	{
		i = 0;
		while (strs[j][i])
		{
			i++;
			nbchar++;
		}
		j++;
	}
	return (nbchar);
}

char	*ft_cat(int size, char **strs, char *sep, char *str)
{
	int		i;
	int		j;
	int		k;
	int		l;

	j = -1;
	k = 0;
	while (++j < size)
	{
		i = -1;
		while (strs[j][++i])
			str[k++] = strs[j][i];
		if (j < size - 1)
		{
			l = 0;
			while (sep[l])
			{
				str[k++] = sep[l];
				l++;
			}
		}
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		nbsep;
	int		nbchar;
	char	*str;

	nbsep = ft_strlen(sep);
	nbchar = count_char(size, strs);
	if (size <= 0)
	{
		if (!(str = (char *)malloc(sizeof(char) * 1)))
			return (0);
		str[0] = '\0';
		return (str);
	}
	if (!(str = (char *)malloc(sizeof(char) * nbchar + (nbsep * (size - 1)))))
		return (0);
	str = ft_cat(size, strs, sep, str);
	return (str);
}
