/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 11:20:10 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/10 18:34:16 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*temp;

	i = 0;
	while (src[i] != '\0')
		i++;
	temp = (char *)malloc(i + 1);
	if (temp == 0)
		return (0);
	while (i >= 0)
	{
		temp[i] = src[i];
		i--;
	}
	return (temp);
}
