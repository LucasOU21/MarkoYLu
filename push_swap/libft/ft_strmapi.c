/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:55:50 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:55:51 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (s == NULL || f == NULL)
		return (NULL);
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
This function strmapi, accepts pointer to other test function, 
it makes new space in memory, and iterrates through the string,
after that it changes new string applying new function to each character.
*/

/*
char	my_test_func(unsigned int i, char c)
{
	if (i % 2 == 0 && (c >= 'a' && c <= 'z'))
		return (c - 32);
	return (c);
}
*/
/*
// 3. MAIN ZA TEST
int	main(void)
{
	char	*text = "hello world";
	char	*result;

	// Saljemo naš string I našu test funkciju (bez zagrada!)
	result = ft_strmapi(text, my_test_func);

	printf("Original: %s\n", text);
	printf("Changed: %s\n", result);

	free(result); // free memory
	return (0);
}

*/