/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:05:58 by jiyyu             #+#    #+#             */
/*   Updated: 2020/07/15 15:58:23 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*temp;

	i = 0;
	while (s1[i] != '\0')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (temp == 0)
		return (0);
	temp[i--] = '\0';
	while (i >= 0)
	{
		temp[i] = *(char *)(s1 + i);
		i--;
	}
	return (temp);
}
