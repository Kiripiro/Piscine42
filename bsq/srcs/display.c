/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:31:44 by atourret          #+#    #+#             */
/*   Updated: 2020/09/30 20:36:21 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display(t_info *t_data)
{
	int	i;
	int	next_line;
	int	nb_count;
	int	size;

	size = t_data->x * t_data->y;
	next_line = t_data->pos;
	nb_count = 0;
	i = -1;
	while (t_data->map[++i])
	{
		if ((i >= next_line && i <= next_line + t_data->max) \
				&& (nb_count <= t_data->max) \
				&& (t_data->map[i] != t_data->obs))
		{
			t_data->map[i] = t_data->full;
			if (i == next_line + t_data->max)
			{
				next_line += t_data->x;
				nb_count++;
			}
		}
	}
	write(1, t_data->map, size);
}
