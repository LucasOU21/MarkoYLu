/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:52:30 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/25 17:52:31 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Debug helper only - push_swap must NOT print this in the final version
// (only the operations like "sa\n", "pb\n" go to stdout).
// TODO: it always says "stack A" even when you print stack B - use stack_name.
void print_stack(t_node *stack, char *stack_name)
{
    printf("========== STACK %s ==========\n", stack_name);
    if (!stack)
    {
        printf("(empty)\n\n");
        return ;
    }
	int i = 1;
    while (stack)
    {
        printf("On position %d in stack A, is number: %d\n", i, stack->value);
        stack = stack->next;
		i++;
    }
    printf("========== END OF STACK A ==========\n\n");
}
