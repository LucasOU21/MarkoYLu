/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:56:18 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:56:18 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1) - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
		return (ft_substr(s1, 0, 0));
	return (ft_substr(s1, start, ((end - start) + 1)));
}

/*
int main()
{
	char str[] = "xxxxMarkoxxxx";
	char x[] = "x";
	char *res;

	res = ft_strtrim(str, x);
	printf("this is shorter string, %s \n", res);
	free (res);
	return (0);
}
*/