/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:18:55 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 16:37:32 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*node;

	if (lst != NULL)
	{
		node = *lst;
		while (node != NULL)
		{
			next_node = node->next;
			ft_lstdelone(node, del);
			node = next_node;
		}
		*lst = NULL;
	}
}
