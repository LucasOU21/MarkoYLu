/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 19:48:39 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 19:49:38 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		counter++;
		lst = lst-> next;
	}
	return (counter);
}

/*
if (!lst)
{
return (counter);
}
I dont need this, becuase if list is empty 
while will return counter that is actually 0;
*/

/*

int	main(void)
{
	t_list	*head;
	t_list	*node2;
	t_list	*node3;
	int		size;

	// Create 3 nodes
	head = ft_lstnew("First node");
	node2 = ft_lstnew("Second node");
	node3 = ft_lstnew("Third node");

	// Link them together: head -> node2 -> node3 -> NULL
	head->next = node2;
	node2->next = node3;

	// Call your function to count nodes
	size = ft_lstsize(head);

	// Print the result
	printf("Number of nodes in the list: %d\n", size);

	// Free memory
	free(head);
	free(node2);
	free(node3);

	return (0);
}
*/
