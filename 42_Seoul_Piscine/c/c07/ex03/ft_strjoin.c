/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 14:23:07 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/10 18:32:34 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int		check_len(int size, char **strs)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	return (len + 1);
}

void	ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
		dest[i++] = src[j++];
	dest[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*allstr;
	int		i;
	int		len;

	if (size == 0)
	{
		allstr = (char *)malloc(0);
		return (allstr);
	}
	len = check_len(size, strs) + (size - 1) * ft_strlen(sep);
	allstr = (char *)malloc(len * sizeof(char));
	if (allstr == 0)
		return (0);
	allstr[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(allstr, strs[i]);
		if (i != size - 1)
			ft_strcat(allstr, sep);
		i++;
	}
	return (allstr);
}
