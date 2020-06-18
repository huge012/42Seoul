/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 11:39:37 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/10 18:33:20 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *num;
	int len;

	if (min >= max)
		return (0);
	len = max - min;
	num = (int *)malloc(sizeof(int) * len);
	if (num == 0)
		return (0);
	while (max > min && len > 0)
		num[--len] = --max;
	return (num);
}
