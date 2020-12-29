/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 16:05:35 by jiyyu             #+#    #+#             */
/*   Updated: 2020/07/15 15:43:59 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *temp;

	temp = (void *)malloc(count * size);
	if (temp == 0)
		return (0);
	ft_bzero(temp, count * size);
	return (temp);
}
