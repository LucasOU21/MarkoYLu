/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:03 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/02 18:53:01 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	parsing_args(int argc, char **argv)
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
        printf("Bench mode activated!\n\n");
	
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

