/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:19:21 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/11 12:03:27 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	t_list	*new_lst;
	void	*content;

	new_lst = NULL;
	if (f)
	{
		node = lst;
		while (node)
		{
			content = f(node->content);
			new = ft_lstnew(content);
			if (!new)
			{
				ft_lstclear(&new_lst, del);
				return (NULL);
			}
			ft_lstadd_back(&new_lst, new);
			node = node->next;
		}
	}
	return (new_lst);
}
