/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:36:03 by abonnel           #+#    #+#             */
/*   Updated: 2020/09/30 22:02:34 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		only_obs_or_empty(t_info *t_data)
{
	int			i;

	i = 0;
	if ((*t_data).map[0] == '\0' || t_data->map[0] == '\n')
		return (2);
	if (t_data->map[0] == t_data->obs && t_data->map[1] == '\0')
		return (2);
	while (t_data->map[i] == t_data->obs || t_data->map[i] == '\n')
	{
		if (t_data->map[i] == '\0')
			return (2);
		i++;
	}
	return (0);
}

int		check_c_in_map(t_info *t_data)
{
	char		charset[5];
	int			i;

	charset[0] = (*t_data).obs;
	charset[1] = (*t_data).emp;
	charset[2] = (*t_data).full;
	charset[3] = '\n';
	charset[4] = '\0';
	i = 0;
	while ((*t_data).map[i])
	{
		if (is_charset((*t_data).map[i], charset) != 0)
			return (2);
		i++;
	}
	if (!(ft_str_is_printable(charset)))
		return (2);
	if (!(ft_str_is_printable(t_data->map)))
		return (2);
	return (0);
}

int		char_are_valid(t_info *t_data)
{
	if ((*t_data).emp == 0 || (*t_data).obs == 0 || (*t_data).full == 0)
		return (2);
	if ((*t_data).emp == (*t_data).obs || (*t_data).emp == (*t_data).full
			|| (*t_data).full == (*t_data).obs)
		return (2);
	return (0);
}

int		has_newline(t_info *t_data)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < (*t_data).y)
	{
		if ((*t_data).map[(*t_data).x - 1 + j] != '\n')
			return (2);
		j += (*t_data).x;
		i++;
	}
	return (0);
}
