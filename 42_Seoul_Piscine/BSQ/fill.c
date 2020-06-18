/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:56:07 by yyoo              #+#    #+#             */
/*   Updated: 2020/06/17 20:04:48 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "headers.h"

t_map_info		fill(t_map_square square, t_map_con *con)
{
	int	i;
	int	j;

	i = 0;
	while (i < square.size)
	{
		j = 0;
		while (j < square.size)
		{
			con->map.map[square.y - i][square.x - j] = con->fill;
			j++;
		}
		i++;
	}
	return (con->map);
}

void			print_answer(t_map_con *con)
{
	int y;
	int x;

	y = 0;
	while (y < con->map.y)
	{
		x = 0;
		while (x < con->map.x)
		{
			write(1, &con->map.map[y][x], 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
