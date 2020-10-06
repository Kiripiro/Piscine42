/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 11:36:28 by abonnel           #+#    #+#             */
/*   Updated: 2020/09/30 22:40:02 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			down_n_left(t_info *t_data, int i, int nb_cps)
{
	int		forward;

	forward = 0;
	while (forward < nb_cps && i < (t_data->y * t_data->x) - 1)
	{
		i += t_data->x;
		if (i >= (t_data->y * t_data->x) - 1 || t_data->map[i] == t_data->obs)
			return (0);
		else
			forward++;
	}
	forward = 0;
	while (forward < nb_cps && t_data->map[i] != '\n' \
			&& i < (t_data->y * t_data->x) - 1)
	{
		i -= 1;
		if (t_data->map[i] == t_data->obs)
			return (0);
		else
			forward++;
	}
	return (1);
}

int			check_around(t_info *t_data, int i)
{
	int		nb_cps;
	int		b;

	if (t_data->map[i] == t_data->obs || t_data->map[i] == '\n' \
			|| i >= ((t_data->y * t_data->x) - 1))
		return (0);
	b = i;
	i++;
	nb_cps = 1;
	while (t_data->map[i] != t_data->obs && t_data->map[i] != '\n' \
			&& i < (t_data->y * t_data->x) - 1)
	{
		i = b + nb_cps;
		if (t_data->map[i] == t_data->obs || t_data->map[i] == '\n')
			return (nb_cps - 1);
		if (down_n_left(t_data, i, nb_cps) == 0)
			return (nb_cps - 1);
		nb_cps++;
	}
	return (nb_cps - 1);
}

int			simple_map(t_info *t_data)
{
	int			i;

	i = 0;
	if (t_data->pos == 0 && t_data->map[0] == t_data->obs)
	{
		while (t_data->map[i] != t_data->emp && t_data->map[i])
			i++;
		if (t_data->map[i] == t_data->emp)
			t_data->pos = i;
	}
	return (0);
}

int			ft_algo(t_info *t_data)
{
	int			i;
	int			nb_cps;

	nb_cps = 0;
	i = 0;
	t_data->max = -1;
	while ((*t_data).map[i] && i < (t_data->x * t_data->y) - 1)
	{
		nb_cps = check_around(t_data, i);
		if (nb_cps > t_data->max)
		{
			t_data->max = nb_cps;
			t_data->pos = i;
		}
		i++;
	}
	if (simple_map(t_data))
		return (2);
	display(t_data);
	free(t_data->map);
	return (0);
}
