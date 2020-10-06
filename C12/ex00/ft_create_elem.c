/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:45:38 by atourret          #+#    #+#             */
/*   Updated: 2020/09/25 15:09:53 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;
	if (!(elem = (t_list *)malloc(sizeof(t_list))))
		return (0);
	elem->next = 0;
	elem->data = data;
	return (elem);
}
