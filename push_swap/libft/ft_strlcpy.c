/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:15:15 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 20:39:51 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	if (destsize == 0)
		return ((size_t)ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && i < (destsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*
it is alwayse returning src which it tried to copy

*/
/*

int main (){

	char name[] = "Markovic";
	char name2[5] = "";

	printf("This is before the strlcpy: %s from %s\n", name2, name);
	//ft_strlcpy(name2, name, 0);
	printf("This is after the strlcpy 3: num is: %ld %s from %s\n",
	ft_strlcpy(name2, name, 5), name2, name);
	
	
	
	//ft_strlcpy(name2, name, 5);
	//printf("This is after the strlcpy 5: %s\n from %s\n", name, name2);
	//ft_strlcpy(name2, name, 0);
	//printf("This is after the strlcpy : %s\n from %s\n", name, name2);
	

	return(0);



}
	*/