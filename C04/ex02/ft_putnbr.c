/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 10:19:19 by atourret          #+#    #+#             */
/*   Updated: 2020/09/17 20:02:35 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	result;

	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	result = nb;
	if (result >= 10)
		ft_putnbr(result / 10);
	ft_putchar('0' + result % 10);
}
