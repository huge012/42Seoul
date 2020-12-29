/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyyu <jiyyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 15:23:41 by jiyyu             #+#    #+#             */
/*   Updated: 2020/07/15 16:26:29 by jiyyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*makelst;

	if (f == 0)
		return (0);
	newlst = 0;
	while (lst != 0)
	{
		makelst = ft_lstnew(f(lst->content));
		if (makelst == 0)
		{
			ft_lstclear(&newlst, del);
			return (0);
		}
		ft_lstadd_back(&newlst, makelst);
		lst = lst->next;
	}
	return (newlst);
}
