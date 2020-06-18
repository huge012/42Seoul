/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 10:42:22 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/04 16:39:23 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		checkbase(char *b)
{
	int i;
	int j;

	i = 0;
	while (b[i] != '\0')
	{
		if (b[i] == '+' || b[i] == '-')
			return (0);
		j = i + 1;
		while (b[j] != '\0')
		{
			if (b[i] == b[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ptnum(long long int n, char *base, int s)
{
	if (n < 0)
	{
		write(1, "-", 1);
		ptnum(n * -1, base, s);
	}
	else
	{
		if (n < s)
		{
			write(1, base + n, 1);
			return ;
		}
		ptnum(n / s, base, s);
		ptnum(n % s, base, s);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int size;

	size = checkbase(base);
	if (size <= 1)
		return ;
	ptnum((long long int)nbr, base, size);
}
