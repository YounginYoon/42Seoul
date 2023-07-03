/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youyoon <youyoon@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 22:13:57 by youyoon           #+#    #+#             */
/*   Updated: 2022/11/21 16:56:58 by youyoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*node;
	void	*tmp;

	newlist = 0;
	if (lst)
	{
		while (lst)
		{
			tmp = f(lst->content);
			node = ft_lstnew(tmp);
			if (!node)
			{
				del(tmp);
				ft_lstclear(&newlist, del);
				return (0);
			}
			ft_lstadd_back(&newlist, node);
			lst = lst->next;
		}
		return (newlist);
	}
	return (0);
}
