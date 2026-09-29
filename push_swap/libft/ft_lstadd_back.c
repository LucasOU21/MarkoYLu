/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:52:27 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 18:54:02 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_node;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_node = ft_lstlast(*lst);
	last_node->next = new;
}

/*
In main.c: Imaš t_list *head. 
Da bi ga poslao funkciji sa **, pišeš &head.

U ft_lstadd_back: Imaš t_list **lst. 
Da bi ga poslao funkciji sa * (kao ft_lstlast), pišeš *lst.
*/
/*
int	main(void)
{
	t_list	*head;
	t_list	*node1;
	t_list	*node2;

	head = NULL; // Lista je na početku PRAZNA

	// 1. Pravimo dva čvora pomoću ft_lstnew
	node1 = ft_lstnew("Prvi");
	node2 = ft_lstnew("Drugi");

	// 2. Dodajemo prvi čvor na kraj 
	(pošto je lista bila prazna, on postaje i početak)
	ft_lstadd_back(&head, node1);

	// 3. Dodajemo drugi čvor na kraj
	ft_lstadd_back(&head, node2);

	// Prikazujemo da vidimo da li je "Drugi" stvarno otišao na kraj
	printf("Head node   : %s\n", (char *)head->content);
	printf("Second node : %s\n", (char *)head->next->content);

	// Oslobađamo memoriju
	free(node1);
	free(node2);

	return (0);
}
	*/