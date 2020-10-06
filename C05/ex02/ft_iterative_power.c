/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 13:45:58 by atourret          #+#    #+#             */
/*   Updated: 2020/09/22 13:45:22 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int		i;
	int		result;

	result = 1;
	i = 0;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (nb == 0)
		return (0);
	while (i < power)
	{
		result = result * nb;
		i++;
		printf("i: %d\n", i);
	}
	return (result);
}

int		main()
{
	printf("result: %d", ft_iterative_power(5, 5));
	return (0);
}
