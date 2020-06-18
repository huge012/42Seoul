/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 11:14:03 by jiyyu             #+#    #+#             */
/*   Updated: 2020/05/30 12:30:27 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char n);

void	ck_location(int nowx, int nowy, int x, int y)
{
	char now;

	if ((nowx == 1 && nowy == 1) || (nowx == x && nowy == 1))
		now = 'A';
	else if ((nowx == 1 && nowy == y) || (nowx == x && nowy == y))
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
