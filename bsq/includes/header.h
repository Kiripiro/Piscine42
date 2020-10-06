/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 13:47:06 by atourret          #+#    #+#             */
/*   Updated: 2020/09/30 22:38:40 by abonnel          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct	s_data
{
	int		y;
	int		x;
	char	emp;
	char	obs;
	char	full;
	char	*map;
	int		max;
	int		pos;
}				t_info;

int				error(int retour);
int				error_char(char *retour);
int				is_charset(char c, char *charset);
int				ft_str_is_printable(char *str);
int				only_obs_or_empty(t_info *t_data);
int				check_c_in_map(t_info *t_data);
int				char_are_valid(t_info *t_data);
int				has_newline(t_info *t_data);
int				ft_atoi(char *str, int len);

void			display(t_info *t_data);

int				file_size(char *av);
char			*parsing(int size, char *av);

int				init_s(char *tab, t_info *t_data);
void			init_data(t_info *t_data, int len, char *fline);
int				ft_strlen(char *str);
char			*ft_strdup_from(char *src, int current);
int				final_map(t_info *t_data);
int				len_line(char *tab);
int				ft_strlen(char *str);
char			*ft_strcat(char *dest, char *src);
int				len_line(char *tab);

int				launcher_arg(char **av, int i);
int				launcher_stdin(void);
int				simple_map(t_info *t_data);
int				ft_algo(t_info *t_data);
int				down_n_left(t_info *t_data, int i, int nb_cps);

#endif
