/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:52:59 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:53:00 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

/* 
I am not changing who is first in line - 
I am just adding A POINTER to next one in line (first line of core)
just adding the pointer that is under data that follows the data 
with second line, I am changing that pointer, to points to new (FIRST in line)
So just switching pointers 

*/
/*

int	main(void)
{
	t_list	*head; // Pokazivač na početak naše liste
	t_list	*node1;
	t_list	*node2;

	// 1. Pravimo PRVI čvor sa tekstom "Drugi" (jer ćemo iza njega ubaciti nov)
	node1 = ft_lstnew("Drugi");
	head = node1; // Trenutno je node1 sam u listi, pa je on i početak (head)

	// 2. Pravimo DRUGI čvor sa tekstom "Prvi"
	node2 = ft_lstnew("Prvi");

	// 3. Ubacujemo node2 na sam POČETAK liste!
	// Šaljemo &head (adresu pokazivača) jer funkcija prima t_list **
	ft_lstadd_front(&head, node2);

	// 4. Prikazujemo listu da vidimo redosled
	printf("\n================ STANJE LISTE ================\n");
	printf("1. Prvi čvor u listi (head) : %s\n", (char *)head->content);
	printf("2. Sledeći čvor (head->next): %s\n", (char *)head->next->content);
	printf("==============================================\n\n");

	// 5. Oslobađamo memoriju za oba alocirana čvora
	free(node1);
	free(node2);

	return (0);
}

*/