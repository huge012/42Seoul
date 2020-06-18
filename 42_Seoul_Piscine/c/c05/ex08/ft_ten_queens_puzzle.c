/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 19:57:32 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/07 16:48:03 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		isok(int i, int *chess)
{
	int j;

	j = 0;
	while (j < i)
	{
		if (chess[j] == chess[i])
			return (0);
		else if (chess[i] - chess[j] == i - j || chess[i] - chess[j] == j - i)
			return (0);
		j++;
	}
	return (1);
}

void	printqueen(int *chess)
{
	int i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(chess[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int		queen(int i, int *chess)
{
	int j;
	int n;

	j = 0;
	n = 0;
	if (i == 10)
	{
		printqueen(chess);
		return (1);
	}
	while (j < 10)
	{
		chess[i] = j;
		if (isok(i, chess) == 1)
			n = n + queen(i + 1, chess);
		j++;
	}
	return (n);
}

int		ft_ten_queens_puzzle(void)
{
	int chess[10];
	int n;

	n = queen(0, chess);
	return (n);
}
