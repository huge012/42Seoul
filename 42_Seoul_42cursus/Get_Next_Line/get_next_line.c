/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:19:51 by jiyyu             #+#    #+#             */
/*   Updated: 2020/11/11 15:36:04 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_newline(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		split_by_newline(char **str, char **line, int i)
{
	char	*temp;

	(*str)[i] = '\0';
	*line = ft_strdup(*str);
	if (*line == 0)
	{
		free(*str);
		*str = 0;
		return (-1);
	}
	if ((*str)[i + 1] != '\0')
	{
		if ((temp = ft_strdup(*str + i + 1)) == 0)
		{
			free(*str);
			*str = 0;
			free(*line);
			return (-1);
		}
	}
	else
		temp = 0;
	free(*str);
	*str = temp;
	return (1);
}

int		end_of_file(char **str, char **line, int read_size)
{
	int is_newline;

	if (read_size < 0)
	{
		if (*str != 0)
		{
			free(*str);
			*str = 0;
		}
		return (-1);
	}
	if (*str && (is_newline = ft_check_newline(*str)) >= 0)
		return (split_by_newline(str, line, is_newline));
	if (*str)
	{
		*line = *str;
		*str = 0;
		return (0);
	}
	*line = ft_strdup("");
	if (*line == 0)
		return (-1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *temp_str[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			is_newline;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		if ((temp_str[fd] = ft_strjoin(temp_str[fd], buf)) == 0)
			return (-1);
		if ((is_newline = ft_check_newline(temp_str[fd])) >= 0)
			return (split_by_newline(&temp_str[fd], line, is_newline));
	}
	return (end_of_file(&temp_str[fd], line, read_size));
}
