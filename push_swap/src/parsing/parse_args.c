/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:03 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/03 14:45:41 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// Same logic as main() in practice/old_main.c (the commented-out array test
// that was here is still in practice/old_main.c and practice/chunk_sort.c).
//
// TODO: BUG (leak) - stack_a is built here and then lost when the function
//       returns. Return it instead:  t_node *parsing_args(int argc, char **argv)
//       (and return NULL on error after ft_nodeclear(&stack_a)).
// TODO: use your ps_atoi (src/parsing/ps_atoi.c) instead of libft's ft_atoi,
//       which accepts "12abc" and overflows silently.
// TODO: an invalid number must not be skipped - the subject wants "Error\n"
//       on stderr and exit. Put that in error.c.
// TODO: check for duplicate numbers (also an "Error\n" case).
// TODO: on malloc fail, call ft_nodeclear(&stack_a) like old_main.c does.
// TODO: remove the debug printf's once it works (only ops go to stdout).
// TODO: argv like "3 2 1" (one string) - decide if you support it (ft_split).
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
	else if(ps_atoi(argv[i]) != 0)
	{
        printf("After atoi input %d is ok: %d\n", i, ft_atoi(argv[i]));
		num = ps_atoi(argv[i]);
		new_node = ft_node_new(num);
		if (!new_node)
        {
			//free(new_node);
            // Ovde bi trebalo osloboditi već dodeljenu memoriju ako malloc otkaže
            return (1);
        }
		ft_nodeadd_back(&stack_a, new_node);
		
	} else if (ps_atoi(argv[i]) == 0)
		printf("After atoi input nb:%d is rejected : %d\n", i, ps_atoi(argv[i]));

	i++;
    }
	if (flag_count == 1)
        printf("Bench mode activated!\n\n");
	
	print_stack(stack_a, "A");

	return (0);
}
