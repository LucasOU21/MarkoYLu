/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strat_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:42:42 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/09 19:08:02 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	int_sqrt(int n)
{
	int	root;

	root = 1;
	while (root * root < n)
		root++;
	return (root);
}

int	max_position(t_node *b)
{
	int	pos;
	int	max_pos;
	int	max;

	pos = 0;
	max_pos = 0;
	max = -1;
	while (b)
	{
		if (b->index > max)
		{
			max = b->index;
			max_pos = pos;
		}
		pos++;
		b = b->next;
	}
	return (max_pos);
}


void	max_to_top(t_node **b, t_bench *bench)
{
	int	pos;
	int	size;

	pos = max_position(*b);
	size = stack_size(*b);
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			rb(b, bench);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rrb(b, bench);
			pos++;
		}
	}
}

void	bring_to_top(t_node **a, int pos, int size, t_bench *bench)
{
	if (pos <= size / 2)
	{
		while (pos > 0)
		{
			ra(a, bench);
			pos--;
		}
	}
	else
	{
		while (pos < size)
		{
			rra(a, bench);
			pos++;
		}
	}
}
