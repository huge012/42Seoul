/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/11 15:07:11 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/11 16:43:59 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void	ft_putnum(int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		ft_putnum(n * -1);
	}
	else if (n < 10)
	{
		ft_putchar('0' + n);
		return ;
	}
	ft_putnum(n / 10);
	ft_putchar(n % 10 + '0');
}

void	ft_show_tab(struct s_stock_str	*par)
{
	int i;

	i = 0;
	if (par == 0)
		return ;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		ft_putnum(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		i++;
	}
}
