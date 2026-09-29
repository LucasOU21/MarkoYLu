/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:02:30 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 20:03:26 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
}

/*
with strlen counting how many places I have in that string. 
othervise I would need to make an while loop
there i could do write function or I could do ft_putchar_fd function


   always cheching are pointers pointing an empty space in memory or no! 
	(s == NULL || f == NULL) -> just for pointers, 
	ONLY they can point in empty space!
	
*/

/*
int main()
{
	char s[] = "Hello world!";

	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
	return (0);
}
	*/