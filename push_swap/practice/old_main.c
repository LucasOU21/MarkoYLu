
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:38:12 by marko             #+#    #+#             */
/*   Updated: 2026/10/01 14:10:14 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include "libft.h"
//# include "push_swap.h"

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

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

void	ft_nodedelone(t_node *node)
{
	if (!node)
		return ;
	free(node);
}

void	ft_nodeclear(t_node **lst)
{
	t_node	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_nodedelone(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void print_stack(t_node *stack, char *stack_name)
{
	int i;
    printf("========== STACK %s ==========\n", stack_name);
    if (!stack)
    {
        printf("(empty)\n\n");
        return ;
    }
	i = 0;
    while (stack)
    {
        printf("On position %d in stack %s, is number: %d\n", i, stack_name, stack->value);
        stack = stack->next;
		i++;
    }
    printf("========== END OF STACK %s ==========\n\n", stack_name);
}

int	ps_atoi(const char *s, int *out)
{
	int	i;
	int	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
	{
		i++;
	}
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
		if (s[i] < '0' || s[i] > '9')
			return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = (result * 10) + (s[i] - '0');
		// also INT MIN MAX are from limits.h lib but dont worry i will change that to numbers
		if((result * sign) > INT_MAX || (result * sign) < INT_MIN) // checking here because it is stopping overflow
			return (0);
		i++;
	}
	if (s[i] != '\0')
		return(0);
	
		*out = (int)(result * sign);
	return (1);
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

int	has_duplicate(t_node *lst, int num)
{
	while (lst)
	{
		if (lst->value == num)
			return (1);
		lst = lst->next;
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
				ft_nodeclear(&stack_a);
				write(2, "Error\n", 6);
				return (1);
			}
		}
		else
		{
			if (!ps_atoi(argv[i], &num) || has_duplicate(stack_a, num))
			{
				ft_nodeclear(&stack_a);
				write(2, "Error\n", 6);
				return (1);
			}
			new_node = ft_node_new(num);
			if (!new_node)
			{
				ft_nodeclear(&stack_a);
				return (1);
			}
			ft_nodeadd_back(&stack_a, new_node);
		}

	/*
	else if(ft_atoi(argv[i]) != 0)
	{
        printf("After atoi input %d is ok: %d\n", i, ft_atoi(argv[i]));
		num = ft_atoi(argv[i]);
		new_node = ft_node_new(num);
		if (!new_node)
        {
			//free(new_node);
            // Ovde bi trebalo osloboditi već dodeljenu memoriju ako malloc otkaže
			ft_nodeclear(&stack_a);

            return (1);
        }
		ft_nodeadd_back(&stack_a, new_node);
		
	} else if (ft_atoi(argv[i]) == 0)
		printf("After atoi input nb:%d is rejected : %d\n", i, ft_atoi(argv[i]));
		*/

	i++;
    }
	if (flag_count == 1)
        printf("Bench mode activated!\n\n");
	
	print_stack(stack_a, "A");
	ft_nodeclear(&stack_a);         // čišćenje

	print_stack(stack_a, "A");      // ispisuje (empty)
	
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
