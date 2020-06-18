/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:56:37 by yyoo              #+#    #+#             */
/*   Updated: 2020/06/17 21:48:53 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "headers.h"

void	free_array(t_map_con *con)
{
	int i;

	i = 0;
	while (con->map.map[i] != 0)
		free((con->map).map[i++]);
	free((con->map).map);
	free(con->firstline);
}
