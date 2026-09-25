/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:47:46 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 18:48:27 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*

int main()
{
	printf( "Is it printable 1 %d\n", ft_isprint(37));
	printf( "Is it printable 0 %d\n", ft_isprint(25));
	printf( "Is it printable 1 %d\n", ft_isprint(82));
	printf( "Is it printable 0 %d\n", ft_isprint(127));
	return(1);
}
	*/
