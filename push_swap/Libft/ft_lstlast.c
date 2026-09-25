/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 19:09:16 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 19:10:06 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst-> next)
	{
		lst = lst-> next;
	}
	return (lst);
}

/*
here i am checking all the way untill there is lst->next 
so when I come to the NULL while loop breaks and it gets out of it
ok
*/
/*

int	main(void)
{
	t_list	*head;
	t_list	*node2;
	t_list	*node3;
	t_list	*last_node;

	// Create 3 nodes
	head = ft_lstnew("First");
	node2 = ft_lstnew("Second");
	node3 = ft_lstnew("Third");

	// Link them: head -> node2 -> node3 -> NULL
	head->next = node2;
	node2->next = node3;

	// Get the last node
	last_node = ft_lstlast(head);

	// Print content of the returned node
	if (last_node)
		printf("Last node content: %s\n", (char *)last_node->content);
	else
		printf("List is empty!\n");

	// Free memory
	free(head);
	free(node2);
	free(node3);

	return (0);
}
	*/