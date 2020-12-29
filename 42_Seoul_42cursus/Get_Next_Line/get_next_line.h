/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:11:01 by jiyyu             #+#    #+#             */
/*   Updated: 2020/11/09 15:58:06 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*ft_strdup(char *s1);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
int		ft_check_newline(char *str);
int		split_by_newline(char **str, char **line, int i);
int		end_of_file(char **str, char **line, int read_size);
int		get_next_line(int fd, char **line);

#endif
