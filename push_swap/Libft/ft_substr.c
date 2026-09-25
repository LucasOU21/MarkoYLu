/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:24:26 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 20:24:57 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub = malloc(1 * sizeof(char));
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	sub = malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

/*
int	main(void)
{
	char	*str = "Hello World!";
	char	*res;

	// Extract "World" starting at index 6, length 5
	res = ft_substr(str, 6, 5);
	
	printf("Result: %s\n", res);
	
	free(res);
	return (0);
}
*/

/*
So, substr, is extracting parts of the string from original string.
with malloc, allocates memory for new string.
AFTER MALLOC ALWAYS 
if (sub == NULL)
		return (NULL);
why? because to check did malloc actually made space, maybe RAM is full.
Maybe something else didnt work, and malloc stopped working. 

*/