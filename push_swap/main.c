/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:38:12 by marko             #+#    #+#             */
/*   Updated: 2026/10/04 13:53:07 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/libft.h"
# include "push_swap.h"

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


// TODO: the path to follow, one step at a time:
//   1. stack_a = parsing_args(argc, argv);   (src/parsing/)  <- you are here
//   2. if stack_a is already sorted -> free and return (print nothing)
//   3. measure disorder                       (src/disorder/)
//   4. pick + run a strategy                  (src/strats/)
//   5. if --bench: print op count to stderr   (src/bench/)
//   6. ft_nodeclear(&stack_a); ft_nodeclear(&stack_b);
//
// FOR NOW main() is a TEST of step 1 (parsing). Try:
//   make && ./push_swap 5 -3 0 12abc 2147483648 --bench
// Replace it with the real steps above once parsing works.

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_flags	flags;

	if (argc < 2)
		return (0);
	printf("====== Checking ATOI ======\n");
	if (!parse_args(argc, argv, &stack_a, &flags))
		return (1);
	assign_index(stack_a);      // NOVO: bez ovoga svi indexi ostaju 0

	printf("bench=%d simple=%d medium=%d complex=%d\n",
		flags.bench, flags.simple, flags.medium, flags.complex);
	print_stack(stack_a, "A");
	ft_nodeclear(&stack_a);
		

	print_stack(stack_a, "A");

	
	return (0);
}