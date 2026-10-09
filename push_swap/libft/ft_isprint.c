/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:52:39 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:52:41 by mmitrovi         ###   ########.fr       */
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
