/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkskyscraper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 18:08:44 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/07 21:39:26 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putbox(int box[][4]);

int		check_colup(int box[][4], int j)
{
	int view;
	int high;
	int i;

	view = 0;
	high = 0;
	i = 0;
	while (i < 4)
	{
		if (high < box[i][j])
		{
			view++;
			high = box[i][j];
		}
		i++;
	}
	return (view);
}

int		check_coldown(int box[][4], int j)
{
	int view;
	int high;
	int i;

	view = 0;
	high = 0;
	i = 3;
	while (i >= 0)
	{
		if (high < box[i][j])
		{
			view++;
			high = box[i][j];
		}
		i--;
	}
	return (view);
}

int		check_rowleft(int box[][4], int i)
{
	int view;
	int high;
	int j;

	view = 0;
	high = 0;
	j = 0;
	while (j < 4)
	{
		if (high < box[i][j])
		{
			view++;
			high = box[i][j];
		}
		j++;
	}
	return (view);
}

int		check_rowright(int box[][4], int i)
{
	int view;
	int high;
	int j;

	view = 0;
	high = 0;
	j = 3;
	while (j >= 0)
	{
		if (high < box[i][j])
		{
			view++;
			high = box[i][j];
		}
		j--;
	}
	return (view);
}

int		check_skyscraper(int box[][4], int *condition)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (check_colup(box, i) != condition[i])
			return (0);
		if (check_coldown(box, i) != condition[i + 4])
			return (0);
		if (check_rowleft(box, i) != condition[i + 8])
			return (0);
		if (check_rowright(box, i) != condition[i + 12])
			return (0);
		i++;
	}
	ft_putbox(box);
	return (1);
}
