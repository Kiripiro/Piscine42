/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 11:57:09 by atourret          #+#    #+#             */
/*   Updated: 2020/09/20 11:13:07 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 3;
	if (nb <= 3)
		return (nb == 3 ? 3 : 2);
	if (nb % 2 == 0)
		nb++;
	while (nb % i != 0)
		i += 2;
	return (i == nb ? nb : ft_find_next_prime(nb + 2));
}