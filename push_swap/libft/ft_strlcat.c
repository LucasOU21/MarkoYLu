/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:55:28 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:55:30 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	j;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (destsize <= dest_len)
		return (src_len + destsize);
	i = dest_len;
	j = 0;
	while (src[j] != '\0' && i < (destsize - 1))
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest_len + src_len);
}

/*
int main (){

	char src[] = "Markovic";
	char dest[20] = "Marko ";

	printf("This is before the strlcpy: %s from %s\n", dest, src);
	printf("This is after the strlcpy 3: num is: %ld %s from %s\n", 
	ft_strlcat(dest, src, 15), dest, src);
}
	*/
	/*
	
	const char *src -  that is locking that src just for READING,
	so dont put const char *dest because you want to use and change dest.
	you can use const char *dest for ft_strlen because
	 it is just for reading the file - string. 

*/