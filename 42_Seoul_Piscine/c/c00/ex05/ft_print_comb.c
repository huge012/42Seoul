/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 19:51:47 by jiyyu             #+#    #+#             */
/*   Updated: 2020/05/28 20:57:06 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int f, int s, int t)
{
	write(1, &f, 1);
	write(1, &s, 1);
	write(1, &t, 1);
	if (f < '7')
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb(void)
{
	char num1;
	char num2;
	char num3;

	num1 = '0';
	num2 = '1';
	num3 = '2';
	while (num1 < '7')
	{
		while (num2 <= '8')
		{
			while (num3 <= '9')
			{
				ft_putchar(num1, num2, num3);
				num3++;
			}
			num2++;
			num3 = num2 + 1;
		}
		num1++;
		num2 = num1 + 1;
		num3 = num2 + 1;
	}
	ft_putchar(num1, num2, num3);
}
