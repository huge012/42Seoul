/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 13:37:53 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/04 14:31:06 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkbase(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		else if ((base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	findindex(char *base, char c)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	makenum(char *str, char *base, int size)
{
	int i;
	int j;
	int minus;
	int num;

	i = 0;
	minus = 0;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			minus++;
	}
	while (str[i] != '\0')
	{
		j = findindex(base, str[i++]);
		if (j < 0)
			break ;
		num = num * size + j;
	}
	if (minus % 2 == 1)
		num = num * -1;
	return (num);
}

int	ft_atoi_base(char *str, char *base)
{
	int n;
	int size;

	n = 0;
	size = checkbase(base);
	if (size < 2)
		return (0);
	n = makenum(str, base, size);
	return (n);
}
