/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 19:47:53 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 19:48:22 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
int	main(void)
{
	// 1. Pozivamo tvoju funkciju i kreiramo novi čvor sa tekstom "Hello 42"
	t_list	*moj_cvor;

	moj_cvor = ft_lstnew("HELLO 42!");

	// Sigurnosna provera
	if (moj_cvor == NULL)
	{
		printf("Alokacija memorije nije uspela!\n");
		return (1);
	}

	// 2. Vizuelni prikaz u terminalu
	printf("\n================ STVOREN NOVI NODE ================\n");
	printf(" Adresa samog čvora u RAM-u : %p\n", (void *)moj_cvor);
	printf("---------------------------------------------------\n");
	printf(" [content] -> Adresa: %p | Sadržaj: \"%s\"\n", 
			moj_cvor->content, (char *)moj_cvor->content);
	printf(" [next]    -> Adresa: %p | (NULL znači kraj liste)\n", 
			moj_cvor->next);
	printf("===================================================\n\n");

	// 3. OBAVEZNO: Olobađamo alociranu memoriju kada nam više ne treba
	free(moj_cvor);

	return (0);
}

*/