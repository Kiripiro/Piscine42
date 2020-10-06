/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atourret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 12:28:13 by atourret          #+#    #+#             */
/*   Updated: 2020/09/18 12:48:54 by atourret         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int *board)
{
	int		i;
	char	c;

	i = -1;
	while (++i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int		check(int *board, int posq)
{
	int		n;

	n = posq - 1;
	while (n >= 0)
	{
		if (board[n] == board[posq] - (posq - n))
			return (0);
		if (board[n] == board[posq] + (posq - n))
			return (0);
		if (board[posq] == board[n])
			return (0);
		n--;
	}
	return (1);
}

int		solve(int *board, int posq, int count_solution)
{
	int		testpos;

	testpos = 0;
	while (testpos < 10)
	{
		board[posq] = testpos;
		if (check(board, posq) == 1)
		{
			if (posq < 9)
				count_solution = solve(board, posq + 1, count_solution);
			else
			{
				print(board);
				count_solution++;
			}
		}
		testpos++;
	}
	return (count_solution);
}

int		ft_ten_queens_puzzle(void)
{
	int		i;
	int		board[10];
	int		count_solution;

	count_solution = 0;
	i = -1;
	while (++i < 10)
		board[i] = 10;
	count_solution = solve(board, 0, count_solution);
	return (count_solution);
}
