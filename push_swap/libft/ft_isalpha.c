/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:52:16 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:52:18 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/* 
int main()
{
	char test1 = 'A';
	char test2 = 'z';
	char test3 = '5';
	char test4 = '@';

	printf("Is '%c' an alphabetic character? %d\n", test1, ft_isalpha(test1));
	printf("Is '%c' an alphabetic character? %d\n", test2, ft_isalpha(test2));
	printf("Is '%c' an alphabetic character? %d\n", test3, ft_isalpha(test3));
	printf("Is '%c' an alphabetic character? %d\n", test4, ft_isalpha(test4));

	return 0;
}*/