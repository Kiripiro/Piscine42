/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 16:35:36 by atourret          #+#    #+#             */
/*   Updated: 2020/09/30 22:36:38 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_data(t_info *t_data, int len, char *fline)
{
	(*t_data).y = ft_atoi(fline, len);
	(*t_data).full = fline[len - 1];
	(*t_data).obs = fline[len - 2];
	(*t_data).emp = fline[len - 3];
	(*t_data).pos = 0;
	free(fline);
}

int		init_s(char *tab, t_info *t_data)
{
	char	*fline;
	int		i;
	int		len;

	i = -1;
	len = len_line(tab);
	if (len < 4)
		return (2);
	if (!(fline = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	while (++i < len)
		fline[i] = tab[i];
	fline[i] = 0;
	i = -1;
	while (fline[++i] && i < len - 3)
		if (!(fline[i] >= '0' && fline[i] <= '9'))
			return (2);
	i--;
	while (fline[i] == '0')
		i--;
	if (i < 0)
		return (2);
	init_data(t_data, len, fline);
	return (0);
}

char	*parsing(int size, char *av)
{
	char	*tab;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd == -1)
	{
		error(2);
		return (0);
	}
	if (!(tab = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (read(fd, tab, size) < 0)
		error(2);
	read(fd, tab, size);
	tab[size] = 0;
	close(fd);
	return (tab);
}

int		file_size(char *av)
{
	char	buf[2048];
	int		fd;
	int		i;
	int		nb;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (2);
	i = 0;
	nb = 1;
	while (nb)
	{
		nb = read(fd, buf, 2047);
		if (nb == -1)
			return (2);
		i += nb;
	}
	close(fd);
	return (i);
}

int		final_map(t_info *t_data)
{
	int		i;

	i = 0;
	while ((*t_data).map[i] != '\n')
		i++;
	(*t_data).map = ft_strdup_from((*t_data).map, i + 1);
	return (0);
}
