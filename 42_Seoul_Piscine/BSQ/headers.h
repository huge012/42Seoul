/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 15:22:22 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/17 22:44:28 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

typedef struct	s_map_info
{
	int		x;
	int		y;
	char	**map;
}				t_map_info;

typedef struct	s_map_con
{
	char		*firstline;
	char		space;
	char		obstacle;
	char		fill;
	t_map_info	map;
}				t_map_con;

typedef struct	s_map_square
{
	int		size;
	int		x;
	int		y;
}				t_map_square;

void			putin_firstline(char *file, t_map_con *con);
int				cnt_enter(char *file);
int				pass_firstline(char *file);
t_map_info		make_map_info(char *file, int cnt);
char			**make_map(int y, int pos, char *file);

int				open_file(char *argv);
char			*realloc_buf(char *buf, int buf_size);
char			*ft_make_file(char *file, char *buf, int f_size, int r_size);
char			*read_stdin(void);
char			*read_file(int fd);

int				ft_atoi(char *str);
int				check_char(char c);
int				check_line(char *line, int col, char obs, char empty);
int				check_matrix(t_map_info *map_info, char obs, char empty);
int				map_valid_check(t_map_con *map_con);

t_map_square	set_result(int size, int x, int y, t_map_square *result);
int				set_map_fst_line(t_map_con *con, t_map_square *rst, int *dp_tt);
int				set_dp(t_map_square now, int dp, t_map_con *con, int *dp_tt);
t_map_square	find_square(t_map_con *con, int *dp_tt);

int				ft_strlen(char *str);
void			ft_strcat(char *desti, char *src);
void			ft_strncat(char *desti, char *src, int read_size);
int				compare(int a, int b, int c);

t_map_info		fill(t_map_square square, t_map_con *con);
void			print_answer(t_map_con *con);

void			free_array(t_map_con *con);

#endif
