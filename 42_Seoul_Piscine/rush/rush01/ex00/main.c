/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/06 18:18:22 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/07 21:31:29 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		skyscraper(int box[][4], int *condition, int i, int j);
int		set_condition(char *input_value, int *condition);

int		main(int argc, char **argv)
{
	int box[4][4];
	int condition[16];
	int is_valid_con;
	int is_end;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	is_valid_con = set_condition(argv[1], condition);
	if (is_valid_con == 0)
		write(1, "Error\n", 6);
	else
	{
		is_end = skyscraper(box, condition, 0, 0);
		if (is_end == 0)
			write(1, "Error\n", 6);
	}
}
