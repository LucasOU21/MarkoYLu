/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:56:27 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:56:28 by mmitrovi         ###   ########.fr       */
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
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc((len + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
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