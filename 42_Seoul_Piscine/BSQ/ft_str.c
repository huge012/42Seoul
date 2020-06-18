/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yyoo <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 17:57:05 by yyoo              #+#    #+#             */
/*   Updated: 2020/06/17 19:14:40 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

void	ft_strcat(char *desti, char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (desti[i] != '\0')
		i++;
	while (src[j] != '\0')
		desti[i++] = src[j++];
	desti[i] = '\0';
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int		i;
	unsigned int		size;

	size = ft_strlen(dest);
	i = 0;
	while (*(src + i) != '\0' && i < nb)
	{
		*(dest + size + i) = *(src + i);
		i++;
	}
	*(dest + size + i) = '\0';
	return (dest);
}

int		compare(int a, int b, int c)
{
	a = a < b ? a : b;
	return (a < c ? a + 1 : c + 1);
}
