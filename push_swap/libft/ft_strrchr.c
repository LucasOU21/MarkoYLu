/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:56:12 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 14:19:45 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	letter;
	int		i;

	letter = (char)c;
	last = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == letter)
			last = (char *)&s[i];
		i++;
	}
	if (s[i] == letter)
		last = (char *)&s[i];
	return (last);
}

/*
int main(){
	char s[] = "Markokvic";
	printf("this is string %s after function %s\n", s, ft_strrchr(s, 'k'));

}
*/
/*
it is searching for the character parsed to the function,
and returning a pointer to that charachter 
(  and everything after last same character if there is anything) 
name stands for String Reverse Character
*/