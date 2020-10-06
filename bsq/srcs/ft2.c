/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:59:45 by atourret          #+#    #+#             */
/*   Updated: 2020/09/30 20:38:27 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strdup_from(char *src, int current)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[current + i])
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (src[current + i])
	{
		dest[i] = src[current + i];
		i++;
	}
	dest[i] = '\0';
	free(src);
	return (dest);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		j;

	j = ft_strlen(dest);
	i = -1;
	while (src[++i])
		dest[j + i] = src[i];
	dest[j + i] = '\0';
	return (dest);
}
