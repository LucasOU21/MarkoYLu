/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 13:46:15 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/10/09 19:08:53 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node *stack)
{
	t_node	*cur;
	t_node	*other;
	int		rank;

	cur = stack;
	while (cur)
	{
		rank = 0;
		other = stack;
		while (other)
		{
			if (other->value < cur->value)
				rank++;
			other = other->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}