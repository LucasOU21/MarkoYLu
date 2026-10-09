/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:54:46 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:54:47 by mmitrovi         ###   ########.fr       */
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