/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 19:51:30 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 19:53:19 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	str1 = (const unsigned char *)s1;
	str2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}
	return (0);
}

/*

 int main(){
	char s1[] = "Markovic";
	char s2[] = "Martovic";

	printf("this is string number compare %s and %s\n after function
	 %d\n", s1, s2, ft_memcmp(s1, s2, 4));
 }
	*/
/*
 compare memory areas name 
 const void * prebačen u const unsigned char *: Odlično. 
 Pošto funkcija upoređuje sirovu memoriju bajt po bajt, morao si da 
 skloniš void i koristiš unsigned char jer je to jedini način da bezbedno
 radiš indeksiranje (str1[i]).

Nema provere za \0: Ponovo tačno! Pošto je ovo memcmp (Memory Compare), 
a ne strncmp, funkciju uopšte ne zanima gde se string završava. 
Ona slepo poredi n bajtova, makar unutra bile same nule.

Pravilan return: Vraćaš tačnu razliku str1[i] - str2[i].
*/
