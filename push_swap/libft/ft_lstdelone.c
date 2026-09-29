/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 19:06:22 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 22:14:43 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

/* 
// This is a delete one, the delete function, 
	//as an argument in ft_lestdelone function. 
// I call del function and give argument to delete. 
// and then I delete/ free that empty/ deleted vagon. 




// Pomoćna funkcija koju ćemo proslediti kao 'del' argument.
// Njena uloga je samo da pozove free 
	// na sadržaj i ispiše poruku da vidimo da radi.


void obrisi_sadrzaj(void *content)
{
	printf("1. Funkcija 'del' oslobađa sadržaj: %s\n", (char *)content);
	free(content);
}

int main(void)
{
	// 1. Alociramo memoriju za vagon (node)
	t_list *vagon = malloc(sizeof(t_list));
	if (!vagon)
		return (1);

	// 2. Alociramo memoriju za sadržaj unutar vagona (npr. string)
	vagon->content = strdup("Poruka unutar vagona");
	vagon->next = NULL;

	printf("Stvoren vagon sa sadržajem: %s\n", (char *)vagon->content);

	// 3. Pozivamo tvoju funkciju ft_lstdelone!
	// Kao prvi argument šaljemo vagon koji želimo obrisati.
	// Kao drugi argument šaljemo NAŠU funkciju 
		//'obrisi_sadrzaj' (ili prosto 'free').
	ft_lstdelone(vagon, obrisi_sadrzaj);

	printf("2. Vagon je uspešno obrisan iz memorije!\n");

	return (0);
}
	*/