/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 16:58:45 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/10 20:59:49 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		find_len(long long int origin, int base_num)
{
	int len;

	len = 0;
	if (origin == 0)
		return (1);
	if (origin < 0)
	{
		len++;
		origin = origin * -1;
	}
	while (origin > 0)
	{
		origin = origin / (long long int)base_num;
		len++;
	}
	return (len);
}

char	*ft_make_str(long long int origin, char *base_to, int base_num)
{
	char	*make_num;
	int		len;

	len = find_len(origin, base_num);
	make_num = (char *)malloc(len + 1);
	if (make_num == 0)
	{
		free(make_num);
		return (0);
	}
	make_num[len--] = '\0';
	if (origin < 0)
	{
		make_num[0] = '-';
		origin = origin * -1;
	}
	else if (origin == 0)
		make_num[0] = base_to[0];
	while (origin > 0)
	{
		make_num[len--] = base_to[origin % (long long int)base_num];
		origin = origin / base_num;
	}
	return (make_num);
}
