/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:38:12 by marko             #+#    #+#             */
/*   Updated: 2026/10/01 13:57:34 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include "libft.h"
//# include "push_swap.h"

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

//int operation_count = 0;

typedef struct s_node {
  int value;           // the number from argv
  struct s_node *next; // the node below it, NULL for the bottom
} t_node;


t_node *ft_node_new(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
t_node *ft_nodelast(t_node *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void ft_nodeadd_back(t_node **lst, t_node *new_node)
{
    t_node *last_node;

    if (!lst || !new_node)
        return ;
    if (!*lst)
    {
        *lst = new_node;
        return ;
    }
    last_node = ft_nodelast(*lst);
    last_node->next = new_node;
}

void print_stack(t_node *stack, char *stack_name)
{
    printf("--- Stack %s ---\n", stack_name);
    if (!stack)
    {
        printf("(empty)\n\n");
        return ;
    }
    while (stack)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
    printf("---------------\n\n");
}

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
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node *stack_a = NULL; // Pokazivač na glavu (početak) steka A
    t_node *new_node;
    int     i = 1;
    int     num;	
	int flag_count = 0;
	//char flag[] = "--bench";
	printf("====== Checking ATOI ======\n");

	while (i < argc)
{
	if (ft_strncmp(argv[i], "--bench", 8) == 0)
	{
		flag_count++;
		if (flag_count > 1)
		{
			printf("Error: Flag '--bench' is written more than once!\n");
			return (1);
		}
		printf("Your flag on position %d is: %s\n", i, argv[i]);
		
	}
	else if(ft_atoi(argv[i]) != 0)
	{
        printf("After atoi input %d is ok: %d\n", i, ft_atoi(argv[i]));
		num = ft_atoi(argv[i]);
		new_node = ft_node_new(num);
		if (!new_node)
        {
			//free(new_node);
            // Ovde bi trebalo osloboditi već dodeljenu memoriju ako malloc otkaže
            return (1);
        }
		ft_nodeadd_back(&stack_a, new_node);
		
	} else if (ft_atoi(argv[i]) == 0)
		printf("After atoi input nb:%d is rejected : %d\n", i, ft_atoi(argv[i]));

	i++;
    }
	if (flag_count == 1)
        printf("Bench mode activated!\n");
	
	print_stack(stack_a, "A");
	
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

