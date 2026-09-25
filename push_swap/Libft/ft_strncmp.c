/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:17:52 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 20:18:58 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

/*
int main(){
	char s1[] = "Marko";
	char s2[] = "Marco";

	printf("this is string number compare %s and %s\n 
	after function %d\n", s1, s2, ft_strncmp(s1, s2, 4));

}


// This function just compare 2 strings for n bytes
// string number compare strncmp
// changing character to unsigned char just when deduct becuase 
// just there I am comparing 2 characters before s1 is just a pointer

*/