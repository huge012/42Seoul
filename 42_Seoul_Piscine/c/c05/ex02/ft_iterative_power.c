/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 17:54:31 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/05 10:36:36 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int i;
	int num;

	i = 1;
	num = 1;
	if (power < 0)
		return (0);
	while (i <= power)
	{
		num = num * nb;
		i++;
	}
	return (num);
}
