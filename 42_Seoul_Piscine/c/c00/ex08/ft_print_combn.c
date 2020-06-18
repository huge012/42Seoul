/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 14:25:30 by jiyyu             #+#    #+#             */
/*   Updated: 2020/05/30 18:14:59 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		cntnum(int n)
{
	int m;
	int count;

	m = n;
	count = 1;
	while (m >= 10)
	{
		m = m / 10;
		count++;
	}
	return (count);
}

void	print_n(int num, int n, int cnt)
{
	char itoc;

	if (cnt != n)
	{
		itoc = '0';
		write(1, &itoc, 1);
	}
	if (num < 10)
	{
		itoc = num + '0';
		write(1, &itoc, 1);
		return ;
	}
	itoc = num % 10 + '0';
	print_n(num / 10, n, n);
	write(1, &itoc, 1);
}

int		endnum(int n)
{
	int num;
	int end;
	int i;

	num = 10 - n;
	end = 0;
	i = 0;
	while (i < n)
	{
		end = end * 10 + num;
		num++;
		i++;
	}
	return (end);
}

int		setnumber(int num, int n)
{
	int checknum;
	int num1;
	int i;

	checknum = num + 1;
	i = 1;
	num1 = checknum;
	while (i < n)
	{
		if (num1 % 10 <= (num1 / 10) % 10)
		{
			checknum++;
			num1 = checknum;
			i = 1;
		}
		else
		{
			num1 = num1 / 10;
			i++;
		}
	}
	return (checknum);
}

void	ft_print_combn(int n)
{
	int number;
	int i;
	int e;

	number = 0;
	i = 0;
	e = endnum(n);
	while (i < n)
	{
		number = number * 10 + i;
		i++;
	}
	while (number <= e)
	{
		print_n(number, n, cntnum(number));
		if (number < e)
		{
			write(1, ",", 1);
			write(1, " ", 1);
		}
		number = setnumber(number, n);
	}
}
