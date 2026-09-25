/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:00:05 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 20:01:08 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

/*  always cheching are pointers pointing an empty space in memory or no! 
	(s == NULL || f == NULL) -> just for 
	pointers, ONLY they can point in empty space!
	*/
/*
int main()
{
	char s[] = "Hello world!";

	ft_putendl_fd(s, 1);
	return (0);
	
}
	*/