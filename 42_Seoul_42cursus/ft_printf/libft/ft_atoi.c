/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 16:24:59 by jiyyu             #+#    #+#             */
/*   Updated: 2020/07/15 16:30:44 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_over_range(unsigned long long num, int neg)
{
	if (num > 9223372036854775807 && neg == 1)
		return (-1);
	else if (num > 9223372036854775807 && neg == -1)
		return (0);
	else
		return ((int)num * neg);
}

int			ft_atoi(const char *str)
{
	int					i;
	unsigned long long	num;
	int					neg;

	i = 0;
	num = 0;
	neg = 1;
	if (str[i] == '\0')
		return (num);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (check_over_range(num, neg));
}
