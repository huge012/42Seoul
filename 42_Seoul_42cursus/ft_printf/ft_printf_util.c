/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:57:56 by jiyyu             #+#    #+#             */
/*   Updated: 2020/12/28 17:58:03 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_info(t_info *info)
{
	info->minus = 0;
	info->zero = 0;
	info->width = 0;
	info->prec = -1;
	info->type = 0;
	info->nbr_base = 10;
	info->nbr_sign = 1;
}

int		ft_nbrlen(unsigned long long nbr, t_info *info)
{
	int	i;

	if (nbr == 0 && info->prec != 0)
		return (1);
	i = 0;
	while (nbr != 0)
	{
		i++;
		nbr /= info->nbr_base;
	}
	return (i);
}

char	*ft_baseset(char type)
{
	if (type == 'u' || type == 'd' || type == 'i')
		return ("0123456789");
	else if (type == 'x' || type == 'p')
		return ("0123456789abcdef");
	else if (type == 'X')
		return ("0123456789ABCDEF");
	return (0);
}
