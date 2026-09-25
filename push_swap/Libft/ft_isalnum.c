/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:43:21 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 18:45:02 by marko            ###   ########.fr       */
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