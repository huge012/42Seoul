/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:14:26 by jiyyu             #+#    #+#             */
/*   Updated: 2020/11/06 16:31:46 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*temp;

	i = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (i + 1));
	if (temp == 0)
		return (0);
	temp[i--] = '\0';
	while (i >= 0)
	{
		temp[i] = s1[i];
		i--;
	}
	return (temp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	int		i;
	char	*str;

	if (s1 == 0 && s2 == 0)
		return (0);
	else if (s1 == 0 || s2 == 0)
		return ((s1) ? ft_strdup(s1) : ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (str == 0)
		return (0);
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	i = -1;
	while (++i < len2)
		str[len1 + i] = s2[i];
	str[len1 + len2] = '\0';
	free(s1);
	return (str);
}
