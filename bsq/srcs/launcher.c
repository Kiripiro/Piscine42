/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:09:00 by atourret          #+#    #+#             */
/*   Updated: 2020/09/30 22:36:12 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_realloc(char *src)
{
	int		i;
	char	*dest;

	i = ft_strlen(src);
	if (!(dest = (char *)malloc(sizeof(char) * (i + 2047))))
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	free(src);
	return (dest);
}

char	*readstdin(t_info *t_data)
{
	int		nb;
	char	buf[2048];

	nb = 1;
	t_data->map[0] = 0;
	while (nb)
	{
		nb = read(0, buf, 2047);
		buf[nb] = 0;
		ft_strcat(t_data->map, buf);
		t_data->map = ft_realloc(t_data->map);
	}
	return (t_data->map);
}

int		launcher_stdin(void)
{
	t_info	t_data;

	if (!(t_data.map = (char *)malloc(sizeof(char) * 2048)))
		return (0);
	t_data.map = readstdin(&t_data);
	if (error(init_s(t_data.map, &t_data)))
		return (0);
	if (error(final_map(&t_data)) || error(only_obs_or_empty(&t_data)))
		return (0);
	if (error(char_are_valid(&t_data)))
		return (0);
	t_data.x = len_line(t_data.map) + 1;
	if (error(has_newline(&t_data)))
		return (0);
	if (error(check_c_in_map(&t_data)))
		return (0);
	if (error(ft_algo(&t_data)))
		return (0);
	return (0);
}

int		launcher_arg(char **av, int i)
{
	int		size;
	t_info	t_data;

	if (error(file_size(av[i])))
		return (0);
	size = file_size(av[i]);
	t_data.map = parsing(size, av[i]);
	if (error(init_s(t_data.map, &t_data)))
		return (0);
	if (error(final_map(&t_data)) || error(only_obs_or_empty(&t_data)))
		return (0);
	if (error(char_are_valid(&t_data)))
		return (0);
	t_data.x = len_line(t_data.map) + 1;
	if (error(has_newline(&t_data)))
		return (0);
	if (error(check_c_in_map(&t_data)))
		return (0);
	if (error(ft_algo(&t_data)))
		return (0);
	return (0);
}
