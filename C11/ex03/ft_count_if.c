/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 13:48:24 by atourret          #+#    #+#             */
/*   Updated: 2020/09/29 14:16:47 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int	ft_test(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (i > 5)
		return (1);
	return (0);
}

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]) != 0)
			count++;
		i++;
	}
//	printf("%d\n", count);
	return (count);
}

int		main()
{
	int		(*f)(char *);
	char	*str[] = {"Bonjour", "LesAmis"};
	f = &ft_test;
	printf("%d\n", ft_count_if(str, 2, f));
}
