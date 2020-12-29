/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 14:16:00 by jiyyu             #+#    #+#             */
/*   Updated: 2020/07/09 14:25:00 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *newlst;

	if ((newlst = (t_list *)malloc(sizeof(t_list))) == 0)
		return (0);
	newlst->content = content;
	newlst->next = 0;
	return (newlst);
}
