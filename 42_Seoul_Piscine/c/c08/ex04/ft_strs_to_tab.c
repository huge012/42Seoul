/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 14:09:46 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/11 17:45:00 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void				ft_strcopy(char *str, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
}

void				leak(int i, struct s_stock_str *strs)
{
	int j;

	j = 0;
	while (j <= i)
	{
		free(strs[j].copy);
		j++;
	}
	free(strs);
	strs = 0;
}

void				make_structs(int ac, char **av, struct s_stock_str *strs)
{
	int i;
	int len;

	i = 0;
	while (i < ac)
	{
		len = ft_strlen(av[i]);
		strs[i].size = len;
		strs[i].str = *(av + i);
		strs[i].copy = (char *)malloc((len + 1) * sizeof(char));
		if (strs[i].copy == 0)
		{
			leak(i, strs);
			return ;
		}
		ft_strcopy(strs[i].copy, av[i]);
		i++;
	}
	strs[i].str = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*strs;

	strs = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (strs == 0)
	{
		free(strs);
		return (0);
	}
	make_structs(ac, av, strs);
	return (strs);
}
