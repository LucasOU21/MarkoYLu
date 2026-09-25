/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:37:24 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 18:38:51 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}

/*
bzero - byte zero  set bytes to zero
Same as memset, but it just put 0 \0 on n places 
size_t is size type unsigned integer data type represent
 the size of any object in bytes
*/
/*
int main()
{
	unsigned char ime[] = "Marko Mitrovic";

	printf("This is sentence before bzero: %s\n", ime);
	ft_bzero(ime, 3);
	printf("This is sentence after bzero: %s\n", ime);

	int i;
	i = 0;
	while(i < 15){
		printf("On position %d is letter: %d\n", i, ime[i]);
		i++;

	}

return(0);


}
*/