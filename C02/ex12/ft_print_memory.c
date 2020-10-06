/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 17:02:18 by atourret          #+#    #+#             */
/*   Updated: 2020/09/14 22:01:45 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	convert(char *str, int j, unsigned int size)
{
	unsigned int		i;
	char				*base;
	unsigned char		c;

	base = "0123456789abcdef";
	i = -1;
	while (++i < ((size > 16) ? 16 : size))
	{
		c = str[j];
		if ((i != 0) && (i % 2 == 0))
			write(1, " ", 1);
		write(1, &base[c / 16], 1);
		write(1, &base[c % 16], 1);
		j++;
	}
	if (i < 16)
	{
		while (i < 16)
		{
			write(1, "   ", i % 2 ? 2 : 3);
			i++;
		}
	}
	write(1, " ", 1);
}

void	ad_hex(unsigned long long nb)
{
	int		i;
	char	*base;
	char	result[16];

	base = "0123456789abcdef";
	i = 0;
	while (i < 16)
		result[i++] = '0';
	i = 0;
	while (i < 16)
	{
		result[i] = base[nb % 16];
		i++;
		nb /= 16;
	}
	i = 16;
	while (i > 0)
		write(1, &result[--i], 1);
}

void	print_str(char *str, int j, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i++ < ((size > 16) ? 16 : size))
	{
		if (!(str[j] >= ' ' && str[j] <= '~'))
			write(1, ".", 1);
		else
			write(1, &str[j], 1);
		j++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		i;
	char	*str;

	str = addr;
	if (size == 0)
		return (addr);
	i = 0;
	while (size)
	{
		ad_hex((unsigned long long)&str[i]);
		write(1, ": ", 2);
		convert(str, i, size);
		print_str(str, i, size);
		i += 16;
		size = size > 16 ? size - 16 : 0;
	}
	return (addr);
}
