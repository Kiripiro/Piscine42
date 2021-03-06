/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:07:00 by atourret          #+#    #+#             */
/*   Updated: 2020/09/14 08:59:21 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	while (str[i++])
	{
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
	}
	if (str[0] >= 97 && str[0] <= 122)
		str[0] -= 32;
	i = 1;
	while (str[i])
	{
		if ((str[i - 1] < 'a' || str[i - 1] > 'z') &&
			(str[i - 1] < 'A' || str[i - 1] > 'Z') &&
			(str[i - 1] < '0' || str[i - 1] > '9'))
			if (str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
		i++;
	}
	return (str);
}
