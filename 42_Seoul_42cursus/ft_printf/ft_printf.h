/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:17:11 by jiyyu             #+#    #+#             */
/*   Updated: 2021/01/04 22:50:39 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

# define TYPE "cspdiuxX%"

typedef struct	s_info
{
	int		minus;
	int		zero;
	int		width;
	int		prec;
	char	type;
	int		nbr_base;
	int		nbr_sign;
}				t_info;

int				ft_printf(const char *fmt, ...);
int				parse_format(va_list str, char *format);
int				check_info(va_list str, char *format, t_info *info, int i);
void			check_width_prec(va_list str,
				char *format, t_info *info, int i);
int				print_type(va_list str, t_info *info);

int				ft_print_char(int c, t_info *info);
int				put_width(int width, int len, int zero);

int				ft_print_string(char *str, t_info *info);
char			*parse_buf(char *str, int end, int len);
int				put_width_str(char **buf, t_info *info);

int				ft_print_nbr(unsigned long long nbr, t_info *info);
int				put_prec_str(unsigned long long nbr, t_info *info, char **buf);
int				put_minus(int buf_len, t_info *info, char **buf);
int				len_minus(t_info *info, char **bul);
int				put_pointer_prefix(char **buf);

void			set_info(t_info *info);
int				ft_nbrlen(unsigned long long nbr, t_info *info);
char			*ft_baseset(char type);

#endif
