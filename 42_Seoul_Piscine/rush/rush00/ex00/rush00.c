/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 10:20:03 by jiyyu             #+#    #+#             */
/*   Updated: 2020/05/30 12:28:33 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char n);

void	ck_location(int nowx, int nowy, int x, int y)
{
	char now;

	if ((nowx == 1 && nowy == 1) || (nowx == x && nowy == y))
		now = 'o';
	else if ((nowx == x && nowy == 1) || (nowx == 1 && nowy == y))
		now = 'o';
	else if (nowx == 1 || nowx == x)
		now = '|';
	else if (nowy == 1 || nowy == y)
		now = '-';
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
