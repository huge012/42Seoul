/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 16:00:34 by jiyyu             #+#    #+#             */
/*   Updated: 2020/06/07 16:19:26 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_prime(int nb)
{
	int i;

	i = 2;
	if (nb < 2)
		return (0);
	else if (nb == 2)
		return (1);
	while (i <= nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	while (nb <= 2147483647)
	{
		if (ft_check_prime(nb) == 1)
			return (nb);
		nb++;
	}
	return (nb);
}
