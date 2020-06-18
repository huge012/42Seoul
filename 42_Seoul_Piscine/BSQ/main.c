/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:45:37 by yyoo              #+#    #+#             */
/*   Updated: 2020/06/17 22:46:26 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int		bsq(t_map_con *con)
{
	int				*dp_tt;
	t_map_square	square;

	dp_tt = (int *)malloc(sizeof(int) * (con->map.x + 1));
	if (!dp_tt)
		return (0);
	dp_tt[con->map.x] = 0;
	square = find_square(con, dp_tt);
	if (square.size == -1)
		write(1, "map error\n", 10);
	else if (square.size == 0)
		print_answer(con);
	else
	{
		con->map = fill(square, con);
		print_answer(con);
	}
	free(dp_tt);
	return (1);
}

void	parse_stdin(void)
{
	t_map_con	con;
	char		*buffer;
	int			pos;

	buffer = read_stdin();
	if (buffer == NULL)
		write(1, "map error\n", 10);
	else
	{
		con.map = make_map_info(buffer, cnt_enter(buffer));
		pos = pass_firstline(buffer);
		putin_firstline(buffer, &con);
		free(buffer);
		if (map_valid_check(&con))
			bsq(&con);
		else
			write(1, "map error\n", 10);
		free_array(&con);
	}
}

void	parse_file(char *argv)
{
	t_map_con	con;
	int			fd;
	char		*buffer;
	int			pos;

	fd = open_file(argv);
	if (fd == 0)
		write(1, "map error\n", 10);
	else
	{
		buffer = read_file(fd);
		con.map = make_map_info(buffer, cnt_enter(buffer));
		pos = pass_firstline(buffer);
		putin_firstline(buffer, &con);
		free(buffer);
		if (map_valid_check(&con))
			bsq(&con);
		else
			write(1, "map error\n", 10);
		free_array(&con);
	}
}

int		main(int argc, char **argv)
{
	int i;

	if (argc == 1)
	{
		parse_stdin();
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		parse_file(argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
