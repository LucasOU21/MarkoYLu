/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 19:53:27 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 19:54:31 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	ptrd = (unsigned char *)dest;
	ptrs = (unsigned char *)src;
	if (dest == NULL || src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ptrd[i] = ptrs[i];
		i++;
	}
	return (dest);
}

/*
memory copy is copying some bytes from one to other place
const void *src - const stands for DO NOT CHANGE src just red it 

*/
/*

int main(){

	char name[] = "marko mitrovic";

	char newname[25];

	printf("Now name is here: %s\n", (char *)name);

	ft_memcpy(newname, name, 5);

	printf("After memcpy name is here: %s\n", (char *)newname);

}
	*/