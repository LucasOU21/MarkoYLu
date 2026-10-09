/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:54:59 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 14:19:11 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

/*
char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (NULL);
}*/
/* 
int main(){
	char c[] = "Markovic";
	printf("this is string %s after function %s\n", c, ft_strchr(c, 'k'));

}

*/
/*
so this function returns pointer on the letter we search in the string
and in I printf it it will show from pointer untill the end of the string
return ((char *)&s[i]); - means that it returns adress of pointer
becuase whole function needs to return a pointer, 
so we retrun the address to the pointer.
Last part is to search \0 if s[i] is \0 then it will return it 
if not then we will return NULL
*/