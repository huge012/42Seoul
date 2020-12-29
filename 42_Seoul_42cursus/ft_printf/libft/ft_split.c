/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 14:53:50 by jiyyu             #+#    #+#             */
/*   Updated: 2020/07/08 17:07:24 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cntstr(char const *s, char c)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				cnt++;
		}
		i++;
	}
	return (cnt);
}

static void		ft_freestr(char **strs, size_t i)
{
	size_t j;

	j = 0;
	while (j < i)
	{
		free(strs[j]);
		j++;
	}
	free(strs);
}

static char		**split(char const *s, char c, char **strs, size_t cnt)
{
	size_t len;
	size_t i;
	size_t j;

	i = -1;
	while (++i < cnt)
	{
		len = 0;
		j = -1;
		while (s[0] == c && s[0] != '\0')
			s++;
		while (s[len] != c && s[len] != '\0')
			len++;
		if (!(strs[i] = (char *)malloc(sizeof(char) * (len + 1))))
		{
			ft_freestr(strs, i);
			return (0);
		}
		while (++j < len)
			strs[i][j] = s[j];
		strs[i][j] = '\0';
		s = s + len;
	}
	strs[i] = 0;
	return (strs);
}

char			**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	char	**strs;

	cnt = ft_cntstr(s, c);
	strs = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (strs == 0)
		return (0);
	i = 0;
	strs = split(s, c, strs, cnt);
	return (strs);
}
