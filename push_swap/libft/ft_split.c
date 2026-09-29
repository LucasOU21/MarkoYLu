/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:03:47 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 20:05:19 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while(*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{

	char	**tab;
	int	i;
	int	len;

	if (s == NULL)
		return (NULL);
	tab = malloc((count_words(s, c) + 1) *sizeof(char *));
	if(tab == NULL)
		return(NULL);
	i = 0;
	while (s[0] != '\0')
	{
		while(s[0] != '\0' && s[0] == c)
			s++;
		if(s[0] != '\0')
		{
			len = 0;
			while (s[len] != '\0' && s[len] != c)
			len++;
			tab[i] = ft_substr(s, 0, len);
			i++;

			s = s + len;
		}
	}
	tab[i] = NULL;
	return (tab);
}

/*
int main()
{
	char s[] = " this   is  new string  ";
	char c = ' ';
	char **result;
	int i;

	result = ft_split(s, c);

	if (result == NULL)
		return (1);

	i = 0; 
	while (result[i] != NULL)
	{ 
		printf("Word on index %d: %s \n", i, result[i]);
		i++;
	}

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	
	return (0);

}



*/





