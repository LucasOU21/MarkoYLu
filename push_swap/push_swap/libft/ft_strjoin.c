/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:55:23 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:55:23 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_strings;
	int		i;
	int		j;
	char	*new_str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_strings = ft_strlen(s1) + ft_strlen(s2);
	new_str = malloc((len_strings + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}
/*

int main()
{
	char s1[] = "42 ";
	char s2[] = "Madrid";

	printf("This is join string %s, \n", ft_strjoin(s1, s2));

	return(0);
	
}

*/
