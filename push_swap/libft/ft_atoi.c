/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:35:49 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 18:36:17 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

/*
int main()
{
	char test1[] = "    42";
	printf("Test 1: Tekst: '%s' -> NUMBER: %d\n", test1, ft_atoi(test1));

	char test2[] = "\t\n  -1234abc";
	printf("Test 2: Tekst: '\\t\\n  -1234abc' -> NUMBER: %d\n", ft_atoi(test2));

	return (0);
}

*/
/*

Naziv nptr je skraćenica od "Number Pointer" (pointer na broj).

*/