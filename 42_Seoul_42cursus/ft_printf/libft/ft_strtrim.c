/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:28:53 by jiyyu             #+#    #+#             */
/*   Updated: 2020/07/14 17:52:22 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*str;

	if (s1 == 0 || set == 0)
		return (0);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]) != 0)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]) != 0)
		end--;
	if ((str = (char *)malloc(end - start + 1)) == 0)
		return (0);
	i = 0;
	while (start + i < end)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
