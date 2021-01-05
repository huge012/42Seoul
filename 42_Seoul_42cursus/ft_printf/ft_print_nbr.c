/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:16:49 by jiyyu             #+#    #+#             */
/*   Updated: 2021/01/04 23:20:26 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_pointer_prefix(char **buf)
{
	if ((*buf = ft_strjoin("0x", *buf, 2)) == 0)
		return (-1);
	return (ft_strlen(*buf));
}

int	len_minus(t_info *info, char **buf)
{
	int	len_to_add;

	len_to_add = 0;
	if ((info->type == 'i' || info->type == 'd') &&
		info->zero == 0 && info->nbr_sign == -1)
	{
		if ((*buf = ft_strjoin("-", *buf, 2)) == 0)
			return (-1);
		len_to_add = 1;
	}
	return (len_to_add);
}

int	put_minus(int buf_len, t_info *info, char **buf)
{
	int len_to_add;

	len_to_add = 0;
	if (info->nbr_sign == -1 && info->zero == 1)
	{
		if (buf_len >= info->width)
		{
			if ((*buf = ft_strjoin("-", *buf, 2)) == 0)
				return (-1);
			len_to_add = 1;
		}
		else if (buf_len < info->width)
			*buf[0] = '-';
	}
	return (len_to_add);
}

int	put_prec_str(unsigned long long nbr, t_info *info, char **buf)
{
	int	buf_len;
	int	ret;
	int	i;

	buf_len = ft_nbrlen(nbr, info);
	ret = (info->prec > buf_len) ? info->prec : buf_len;
	if (!(*buf = (char *)malloc(sizeof(char) * ret + 1)))
		return (-1);
	i = 0;
	(*buf)[ret] = '\0';
	while (buf_len + i < ret)
		(*buf)[i++] = '0';
	i = 1;
	if (nbr == 0 && info->prec != 0)
		(*buf)[ret - i] = '0';
	while (nbr)
	{
		(*buf)[ret - i] = ft_baseset(info->type)[nbr % info->nbr_base];
		nbr /= info->nbr_base;
		i++;
	}
	if ((buf_len = len_minus(info, buf)) == -1)
		return (-1);
	return (ret + buf_len);
}

int	ft_print_nbr(unsigned long long nbr, t_info *info)
{
	char	*buf;
	int		buf_len;
	int		ret;
	int		temp;

	if (info->type == 'x' || info->type == 'X' || info->type == 'p')
		info->nbr_base = 16;
	if ((info->type == 'd' || info->type == 'i') && (int)nbr < 0)
	{
		info->nbr_sign = -1;
		nbr = -nbr;
	}
	buf_len = put_prec_str(nbr, info, &buf);
	if (info->type == 'p')
		buf_len = put_pointer_prefix(&buf);
	if (((ret = put_width_str(&buf, info)) != -1)
			&& ((temp = put_minus(buf_len, info, &buf)) != -1))
	{
		ft_putstr(buf);
		ret += temp;
	}
	else
		ret = -1;
	free(buf);
	return (ret);
}
