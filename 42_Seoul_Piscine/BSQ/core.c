/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:45:57 by yyoo              #+#    #+#             */
/*   Updated: 2020/06/17 22:47:40 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_map_square	set_result(int size, int x, int y, t_map_square *result)
{
	if (size > result->size)
	{
		result->size = size;
		result->x = x;
		result->y = y;
	}
	return (*result);
}

int				set_map_fst_line(t_map_con *con, t_map_square *rst, int *dp_tt)
{
	int	j;

	rst->size = 0;
	rst->x = 0;
	rst->y = 0;
	j = -1;
	while (++j < con->map.x)
	{
		if (con->map.map[0][j] == con->space)
			dp_tt[j] = 1;
		else if (con->map.map[0][j] == con->obstacle)
			dp_tt[j] = 0;
		else
			return (1);
		*rst = set_result(dp_tt[j], j, 0, rst);
	}
	return (0);
}

int				set_dp(t_map_square now, int dp, t_map_con *con, int *dp_tt)
{
	if (con->map.map[now.x][now.y] == con->space && now.y == 0)
		return (1);
	else if (con->map.map[now.x][now.y] == con->space)
		return (compare(dp_tt[now.y], dp, dp_tt[now.y - 1]));
	else if (con->map.map[now.x][now.y] == con->obstacle)
		return (0);
	else
		return (-1);
}

t_map_square	return_error_bysize(int message, t_map_square result)
{
	result.size = message;
	result.x = 0;
	result.y = 0;
	return (result);
}

t_map_square	find_square(t_map_con *con, int *dp_tt)
{
	t_map_square	now;
	int				dp[2];
	t_map_square	result;

	now.x = 0;
	if (set_map_fst_line(con, &result, dp_tt))
		return (return_error_bysize(-1, result));
	while (++now.x < con->map.y && con->map.y > 1)
	{
		now.y = -1;
		dp[0] = 0;
		while (++now.y < con->map.x)
		{
			if ((dp[1] = set_dp(now, dp[0], con, dp_tt)) == -1)
				return (return_error_bysize(-1, result));
			dp_tt[now.y - 1] = dp[0];
			dp[0] = dp[1];
			if (now.y == con->map.x - 1)
				dp_tt[now.y] = dp[1];
			result = set_result(dp[1], now.y, now.x, &result);
		}
	}
	return (result);
}
