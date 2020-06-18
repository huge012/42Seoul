/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:02:30 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/10 20:53:59 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *nums;
	int len;
	int i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	nums = (int *)malloc(sizeof(int) * len);
	if (nums == 0)
		return (-1);
	i = 0;
	while (i < len)
	{
		nums[i] = min + i;
		i++;
	}
	*range = nums;
	return (len);
}
