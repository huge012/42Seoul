/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:41:55 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/02 17:37:24 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pt_add(unsigned int add)
{
	char			add_hex[16];
	char			*hex;
	unsigned int	ad;
	unsigned int	i;

	i = 0;
	hex = "0123456789abcdef";
	ad = add;
	while (ad > 0)
	{
		add_hex[i] = hex[ad % 16];
		ad = ad / 16;
		i++;
	}
	while (i < 16)
	{
		add_hex[i] = '0';
		i++;
	}
	while (i > 0)
	{
		i--;
		write(1, &add_hex[i], 1);
	}
}

void	pt_space(unsigned int i)
{
	if (i % 2 == 1)
		write(1, "  ", 2);
	else
		write(1, "     ", 5);
}

int		pt_hextxt(char *add, unsigned int s)
{
	char			*hex;
	unsigned int	i;

	i = 0;
	hex = "0123456789abcdef";
	while (i < s && i < 16)
	{
		if (add[i] == '\0')
		{
			write(1, "00", 2);
			pt_space(i + 1);
			return (1);
		}
		write(1, &hex[add[i] / 16], 1);
		write(1, &hex[add[i] % 16], 1);
		if (i % 2 && i < s)
			write(1, " ", 1);
		i++;
	}
	if (i < 16)
		pt_space(s % 16);
	return (0);
}

void	pt_txt(char *add, unsigned int s)
{
	unsigned int	i;

	i = 0;
	while (i < s && i < 16)
	{
		if (add[i] == '\0')
		{
			write(1, ".", 1);
			break ;
		}
		if (add[i] < 32 || add[i] > 126)
			write(1, ".", 1);
		else
			write(1, &add[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int i;
	unsigned int isend;

	i = 0;
	isend = 0;
	while (i < size)
	{
		pt_add((unsigned int)addr + i);
		write(1, ": ", 2);
		isend = pt_hextxt(&addr[i], size);
		pt_txt(&addr[i], size);
		if (isend == 1)
			break ;
		i += 16;
	}
	return (addr);
}
