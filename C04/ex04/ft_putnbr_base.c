/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 17:23:38 by atourret          #+#    #+#             */
/*   Updated: 2020/09/17 10:34:26 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int		verif_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (base[++i])
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
	}
	return (i);
}

void				ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nb;
	unsigned int	i;

	i = verif_base(base);
	if (i < 2)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nb = nbr * -1;
	}
	else
		nb = nbr;
	if (nb >= i)
		ft_putnbr_base((nb / i), base);
	ft_putchar(base[nb % i]);
}
