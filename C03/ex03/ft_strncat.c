/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 16:25:41 by atourret          #+#    #+#             */
/*   Updated: 2020/09/14 08:51:12 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int n)
{
	unsigned int		i;
	int					j;

	j = ft_strlen(dest);
	i = -1;
	while (src[++i] && i < n)
		dest[j + i] = src[i];
	dest[j + i] = '\0';
	return (dest);
}
