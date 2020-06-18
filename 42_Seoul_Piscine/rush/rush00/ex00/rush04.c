/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 11:34:03 by jiyyu             #+#    #+#             */
/*   Updated: 2020/05/30 12:44:07 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char n);

void	ck_location(int nowx, int nowy, int x, int y)
{
	char now;

	if (nowx == 1 && nowy == 1)
		now = 'A';
	else if (nowx == x && nowy == y)
	{
		if (x == 1 || y == 1)
			now = 'C';
		else
			now = 'A';
	}
	else if ((nowx == 1 && nowy == y) || (nowx == x && nowy == 1))
		now = 'C';
	else if (nowx == 1 || nowx == x || nowy == 1 || nowy == y)
		now = 'B';
	else
		now = ' ';
	ft_putchar(now);
}

void	rush(int x, int y)
{
	int nowx;
	int nowy;

	nowx = 1;
	nowy = 1;
	while (nowy <= y)
	{
		while (nowx <= x)
		{
			ck_location(nowx, nowy, x, y);
			nowx++;
		}
		ft_putchar('\n');
		nowy++;
		nowx = 1;
	}
}
