/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/14 18:10:25 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/14 18:10:29 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		find_charset(char c, char *to_find)
{
	int i;

	i = 0;
	while (to_find[i] != '\0')
	{
		if (c == to_find[i])
			return (1);
		i++;
	}
	return (0);
}

void	split(char *str, char *charset, char **answer, int answer_len)
{
	int len;
	int i;
	int j;

	i = -1;
	while (++i < answer_len)
	{
		len = 0;
		j = 0;
		while (find_charset(str[0], charset) == 1 && str[0] != '\0')
			str++;
		while (find_charset(str[len], charset) != 1 && str[len] != '\0')
			len++;
		answer[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (answer[i] == 0)
			return ;
		while (j < len)
		{
			answer[i][j] = str[j];
			j++;
		}
		answer[i][j] = '\0';
		str = str + len;
	}
	answer[i] = 0;
}

int		cnt_answer(char *str, char *charset)
{
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	while (str[i] != '\0')
	{
		if (find_charset(str[i], charset) == 0)
		{
			if (find_charset(str[i + 1], charset) == 1 || str[i + 1] == '\0')
				cnt++;
		}
		i++;
	}
	return (cnt);
}

char	**ft_split(char *str, char *charset)
{
	int		answer_len;
	char	**answer;
	int		i;

	i = 0;
	answer_len = cnt_answer(str, charset);
	answer = (char **)malloc((answer_len + 1) * sizeof(char *));
	if (answer == 0)
		return (0);
	split(str, charset, answer, answer_len);
	return (answer);
}
