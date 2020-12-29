/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:08:00 by jiyyu             #+#    #+#             */
/*   Updated: 2020/07/14 18:24:58 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		cnt++;
		n *= -1;
	}
	while (n > 0)
	{
		cnt++;
		n /= 10;
	}
	return (cnt);
}

char		*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = numlen(n);
	neg = 0;
	if ((str = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	str[len--] = '\0';
	if (n < 0)
	{
		neg = 1;
		str[0] = '-';
		n *= -1;
	}
	while (len >= neg)
	{
		str[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (str);
}
