/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:39:31 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 18:43:01 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *) b;
	while (i < len)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (b);
}

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