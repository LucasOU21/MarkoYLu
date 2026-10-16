/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:54:22 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:54:22 by mmitrovi         ###   ########.fr       */
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

/*
memset - memory set 
it is universal ptr - void * function. 
uses void *b, and input some characters int c
usually 0 or \0 to clean the memory on that location 
for as many places as we input in size_t (size type) 
unsigned integer data type represent the size of any object in bytes
we have raturnning void pointer (void *) as function 
just because they wanted to put it in printf and you could see in one line 
to make it shorter insted on two lines
*/
/*
int main(){

	char ime[] = "MITROVICMARKO";
	int i;



	printf("This is before memset: %s\n", ime);

	ft_memset(ime + 5, 0, 3);
	printf("This is after memset: %s\n", ime);

	i = 0;
	while (i < 14)
	{
		printf("Position %d: ASCII is %d\n", i, ime[i]);
		printf("Position %d: character is %c\n", i, ime[i]);
		i++;
	}
	return(0);
}
	*/