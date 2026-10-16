/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:52:25 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:52:27 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*
int main()
{
	printf( "this is result for 'g' %d\n", ft_isascii('g'));
	printf( "this is result for '@' %d\n", ft_isascii('@'));
	printf( "this is result for '~' %d\n", ft_isascii('~'));
	
	
	printf( "this is result for 128: %d\n", ft_isascii(128));
	printf( "this is result for -1:  %d\n", ft_isascii(-1));
}
	*/