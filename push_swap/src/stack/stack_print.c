/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:52:30 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/04 14:00:03 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Debug helper only - push_swap must NOT print this in the final version
// (only the operations like "sa\n", "pb\n" go to stdout).
// TODO: it always says "stack A" even when you print stack B - use stack_name.
void print_stack(t_node *stack, char *stack_name)
{
int	i;

	printf("========== STACK %s ==========\n", stack_name);
	if (!stack)
	{
		printf("(empty)\n\n");
		return ;
	}
	i = 1;
	while (stack)
	{
		printf("pos: %d in %s: index: %d value: %d\n",
			i, stack_name, stack->index, stack->value);
		stack = stack->next;
		i++;
	}
	printf("========== END OF STACK %s ==========\n\n", stack_name);
}
