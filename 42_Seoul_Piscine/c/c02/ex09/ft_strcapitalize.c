/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:48:38 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/01 16:21:32 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;
	int cap;

	i = 0;
	cap = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || (str[i] > '9' && str[i] < 'A'))
			cap = 0;
		else if ((str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			cap = 0;
		else if (str[i] >= 'A' && str[i] <= 'Z' && cap == 1)
			str[i] = str[i] + 32;
		else if (str[i] >= 'a' && str[i] <= 'z' && cap == 0)
		{
			str[i] = str[i] - 32;
			cap = 1;
		}
		else
			cap = 1;
		i++;
	}
	return (str);
}
