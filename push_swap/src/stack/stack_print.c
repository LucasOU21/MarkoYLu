/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:52:30 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/05 17:22:23 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Debug helper only - push_swap must NOT print this in the final version
// (only the operations like "sa\n", "pb\n" go to stdout).
// TODO: it always says "stack A" even when you print stack B - use stack_name.
void	print_stack(t_node *stack, char *stack_name)
{
	int	i;

	dprintf(2, "========== STACK %s ==========\n", stack_name);
	if (!stack)
	{
		dprintf(2, "(empty)\n\n");
		return ;
	}
	i = 1;
	while (stack)
	{
		dprintf(2, "pos: %d in %s: index: %d value: %d\n",
			i, stack_name, stack->index, stack->value);
		stack = stack->next;
		i++;
	}
	dprintf(2, "========== END OF STACK %s ==========\n\n", stack_name);
}
