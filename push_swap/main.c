/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:38:12 by marko             #+#    #+#             */
/*   Updated: 2026/10/01 10:48:28 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include "libft.h"
//# include "push_swap.h"

#include <stdio.h>
#include <limits.h>

//int operation_count = 0;

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	long	result;

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
		// also INT MIN MAX are from limits.h lib but dont worry i will change that to numbers
		if((result * sign) > INT_MAX || (result * sign) < INT_MIN) // checking here because it is stopping overflow
			return (0);
		i++;
	}
	if (nptr[i] != '\0')
		return(0);
	
	return (result * sign);
}

int	main(int argc, char **argv)
{
	printf("====== Checking ATOI ======\n");

	if (argc > 1)
{
	if (ft_atoi(argv[1]) != 0)
	{
        printf("After atoi output is: %d\n", ft_atoi(argv[1]));
        return (0);
	} else
		printf("After atoi input is regected : %d\n", ft_atoi(argv[1]));
	
    } else
	{
		printf("MISTAKE: missing input number:\n");
		return (1);
	}
	
	
	/*
	int arr[] = {5, 1, 8, 3, 6};
	int num_chunks = 2;
	int len = sizeof(arr) / sizeof(arr[0]);
	int use_counter_flag = 0;

	if (argc > 1 && strcmp(argv[1], "lucas") == 0)
{
    if (use_counter_flag == 1)
    {
        printf("Mistake: flag -c written more then once\n");
        return (1);
    }
    use_counter_flag = 1;
}

	printf("====== UNSORTED ARRAY ======\n");

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
printf("\n");
	chunk_sort(arr, len, num_chunks);

	printf("====== SORTED ARRAY ======\n");

	for (int i = 0; i < len; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	if (use_counter_flag)
    printf("Number of all operation is: %d\n", operation_count);

	

	*/

	return (0);
}

