/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 11:38:17 by jiyyu             #+#    #+#             */
/*   Updated: 2020/05/30 14:22:05 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_num(int n)
{
	int m;

	if (n < 10)
	{
		ft_putchar(n + '0');
		return ;
	}
	m = n % 10 + '0';
	print_num(n / 10);
	ft_putchar(m);
}

void	ft_putnbr(int nb)
{
	int n;

	n = nb;
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		n = nb * (-1);
	}
	print_num(n);
}
