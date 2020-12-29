/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 15:16:09 by jiyyu             #+#    #+#             */
/*   Updated: 2020/07/02 15:24:56 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t dst_size;
	size_t src_size;

	i = 0;
	dst_size = 0;
	src_size = 0;
	while (dst[dst_size] != '\0')
		dst_size++;
	while (src[src_size] != '\0')
		src_size++;
	if (dstsize <= dst_size)
		return (src_size + dstsize);
	while (i + 1 < dstsize - dst_size && src[i] != '\0')
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	dst[dst_size + i] = '\0';
	return (src_size + dst_size);
}
