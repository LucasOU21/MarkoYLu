/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:53:52 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:53:53 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		uc;
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (uc == ptr[i])
		{
			return ((void *)&ptr[i]);
		}
		i++;
	}
	return (NULL);
}

/*

int main(){
	char s1[] = "Markovic";

	printf("This function compares n bytes of %s\n after function
	 %p\n", s1, ft_memchr(s1, 'k', 5));
	int i;
	i = 0;
	while (s1[i] != '\0')
	{
		printf("Adress: %p, Letter %c\n", (void *)&s1[i], s1[i]);
		i++;
	}
	printf("Adress: %p, letter : \\0 (kraj stringa)\n", (void *)&s1[i]);
	return (0);
}
	*/

/*
it is almost identical like strchr but it doesnt stop on \0
it is iterratign through memory withouth stoppin, only on c number of bytes
because it works with (pictures, files...)
const void s[.n] - is new sintax same as const void *s
Pošto je s tipa void * (univerzalni pointer), 
sa njim ne možeš da radiš aritmetiku 
niti da koristiš s[i]. Moraš na početku da napraviš 
novi pointer tipa unsigned char *ptr 
i dodeliš mu vrednost s.
last print is for printing adress of '\0' character
*/