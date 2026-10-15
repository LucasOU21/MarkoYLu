/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:16:00 by marko             #+#    #+#             */
/*   Updated: 2026/10/03 19:59:38 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	
	if (c[i] == '\0')
	{
		printf("Marko was right! s[i] is 0\n");
		return (0);
	}else 
	{
		printf("Marko was wrong!");
	}
	return (i);
}


int main()
{
	char a[20]="program";

	printf("length of program is: %d\n", ft_strlen(a));
	return (0);
}