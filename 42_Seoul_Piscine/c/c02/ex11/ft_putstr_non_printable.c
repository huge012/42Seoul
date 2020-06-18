/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:54:35 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/02 18:13:41 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchr(char c)
{
	write(1, &c, 1);
}

void	fthex(char c)
{
	char *hex;

	hex = "0123456789abcdef";
	ft_putchr(hex[c / 16]);
	ft_putchr(hex[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 32 && str[i] <= 126)
			ft_putchr(str[i]);
		else
		{
			ft_putchr('\\');
			fthex(str[i]);
		}
		i++;
	}
}
