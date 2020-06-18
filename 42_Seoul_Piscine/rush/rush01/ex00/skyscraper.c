/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 18:07:57 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/07 21:39:33 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_skyscraper(int box[][4], int *condition);

int		check_line(int box[][4], int i, int j)
{
	int compare_index;

	compare_index = 0;
	while (compare_index < i)
	{
		if (box[compare_index][j] == box[i][j])
			return (0);
		compare_index++;
	}
	compare_index = 0;
	while (compare_index < j)
	{
		if (box[i][compare_index] == box[i][j])
			return (0);
		compare_index++;
	}
	return (1);
}

int		skyscraper(int box[][4], int *condition, int i, int j)
{
	int box_heigit;
	int is_end;

	box_heigit = 0;
	is_end = 0;
	if (i == 4)
	{
		if (check_skyscraper(box, condition) == 1)
			return (1);
		return (0);
	}
	while (box_heigit++ < 4)
	{
		if (is_end == 1)
			return (is_end);
		box[i][j] = box_heigit;
		if (check_line(box, i, j) == 1)
		{
			if (j == 3)
				is_end = skyscraper(box, condition, i + 1, 0);
			else
				is_end = skyscraper(box, condition, i, j + 1);
		}
	}
	return (is_end);
}
