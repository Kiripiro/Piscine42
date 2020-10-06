/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 09:20:51 by atourret          #+#    #+#             */
/*   Updated: 2020/09/16 12:25:02 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index <= 2)
		return ((index) ? 1 : 0);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
