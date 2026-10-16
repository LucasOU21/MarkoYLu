/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:52:08 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:52:10 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((c >= '0' && c <= '9')
		|| (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'));
}

/*
int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z')
	|| (c >= 'A' && c <= 'Z')
	|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
	*/

/*
int main ()
{
	printf("isalnum('a') = %d\n", ft_isalnum('a'));  // 1
	printf("isalnum('1') = %d\n", ft_isalnum('1'));  // 1
	printf("isalnum('@') should return 0 = %d\n", ft_isalnum('@'));  // 0
	printf("isalnum('Z') = %d\n", ft_isalnum('Z'));  // 1
} */