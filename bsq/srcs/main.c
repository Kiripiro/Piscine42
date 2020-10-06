/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:27:28 by atourret          #+#    #+#             */
/*   Updated: 2020/09/30 20:19:15 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		error(int retour)
{
	if (retour == 2)
	{
		write(1, "map error\n", 10);
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		launcher_stdin();
	if (ac >= 2)
	{
		while (av[i])
		{
			launcher_arg(av, i);
			if (ac > 2)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
