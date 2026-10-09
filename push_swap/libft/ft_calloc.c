/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:51:59 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 14:05:28 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	totall_number_of_bytes;
	void	*ptr;

	totall_number_of_bytes = nmemb * size;
	ptr = malloc(totall_number_of_bytes);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, totall_number_of_bytes);
	return (ptr);
}

/*
int main()
{
	// Alociramo niz od 3 karaktera
	char *str = (char *)ft_calloc(3, sizeof(char));
	
	if (str != NULL)
	{
		// Štampamo vrednosti na indeksima 0, 1 i 2 da proverimo da li su nule
		printf("Indeks 0: %d\n", str[0]);
		printf("Indeks 1: %d\n", str[1]);
		printf("Indeks 2: %d\n", str[2]);
		
		free(str); // Oslobodi memoriju na kraju
	}
	return (0);
}
	*/
/*
nmemb je skraćeno od "Number of members" (ili Number of elements)
malloc ti da "prljavu" memoriju (unutra može da bude bilo kakvo đubre
 koje je ranije ostalo u RAM-u). 
 calloc kompletnu memoriju očisti i postavi na nule (0).
 Zato se i zove Calloc (Cleared Allocation).
 char *str = malloc(11 * sizeof(char)); 10 + 1
 char *str = calloc(11, sizeof(char));
*/