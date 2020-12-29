/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:01:19 by jiyyu             #+#    #+#             */
/*   Updated: 2020/12/28 17:28:29 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int free_target)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (0);
	i = -1;
	while (++i < len1)
		str[i] = s1[i];
	if (free_target == 1 || free_target == 3)
		free(s1);
	j = 0;
	while (j < len2)
		str[i++] = s2[j++];
	if (free_target == 2 || free_target == 3)
		free(s2);
	str[i] = 0;
	return (str);
}
