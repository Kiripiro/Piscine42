/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 13:43:33 by atourret          #+#    #+#             */
/*   Updated: 2020/09/14 12:12:54 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	char			*base;
	unsigned int	i;
	unsigned char	c;

	base = "0123456789abcdef";
	i = -1;
	while (str[++i])
	{
		c = str[i];
		if ((str[i] <= 31) || (str[i] == 127))
		{
			ft_putchar('\\');
			ft_putchar(base[c / 16]);
			ft_putchar(base[c % 16]);
		}
		else
			write(1, &str[i], 1);
	}
}
