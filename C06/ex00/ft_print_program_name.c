/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:48:49 by atourret          #+#    #+#             */
/*   Updated: 2020/09/18 09:50:46 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	int	i;

	i = -1;
	if (argc < 2)
	{
		while (argv[0][++i])
			write(1, &argv[0][i], 1);
	}
	write(1, "\n", 1);
}
