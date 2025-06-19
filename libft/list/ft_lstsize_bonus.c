/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mateferr <mateferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 11:20:21 by mateferr          #+#    #+#             */
/*   Updated: 2025/06/02 16:37:41 by mateferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
/*
void	print_node(void *lst)
{
	if(lst)
		printf("%s\n", (char *)lst);
}

void	*newnf(void *x)
{
	x = ft_strdup("newnode");
	return (x);
}

int	main(void)
{
	t_list *node1 = ft_lstnew(ft_strdup("membro 1"));
	t_list *node2 = ft_lstnew(ft_strdup("membro 2"));
	t_list *node3 = ft_lstnew(ft_strdup("membro 3"));
	t_list *lst1 = NULL;

	ft_lstadd_back(&lst1, node2);
	ft_lstadd_front(&lst1, node1);
	ft_lstadd_back(&lst1, node3);

	ft_lstiter(lst1, print_node);

	t_list *last = ft_lstlast(lst1);

	print_node(last->content);

	t_list *lst2 = ft_lstmap(lst1,newnf,free);

	int size = ft_lstsize(lst2);

	printf("%i\n", size);

	ft_lstclear(&lst1,free);

	if(lst1 == NULL)
		printf("apagou lista\n");

	ft_lstiter(lst2, print_node);
}*/