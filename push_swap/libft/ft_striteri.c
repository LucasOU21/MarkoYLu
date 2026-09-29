/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:10:04 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 20:11:42 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/*
diference between strmapi and striteri is basically this: 
if (s == NULL || f == NULL)
		return (NULL);
		this is void function so it need just RETURN  empty no values

	also additional function is void, 
	and argument in that function has a pointer char* (here)
	so that is why in my test func i am using *c
	no need for malloc, because I am changing the original string

	always cheching are pointers pointing an empty space in memory or no! 
	(s == NULL || f == NULL) -> just for pointers, 
	ONLY they can point in empty space!

*/
/* TESTTESTTESTTESTTTTTTTTTTTTTTTT
void	my_test_func(unsigned int i, char *c)
{
	if (i % 2 == 0 && (*c >= 'a' && *c <= 'z'))
		*c = *c - 32;
}
*/
/*
// 3. MAIN ZA TEST
int	main(void)
{
	//char	*text = "hello world"; // 
	this text is just for reading needs [] to be able to change it
	char	text[] = "hello world";
	
	printf("Before: %s\n", text);

	ft_striteri(text, my_test_func);

	
	printf("After: %s\n", text);

	return (0);
}
	*/