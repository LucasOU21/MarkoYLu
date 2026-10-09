/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_strat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:13 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/09 19:00:30 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	index_position(t_node *a, int index)
{
	int	pos;

	pos = 0;
	while (a && a->index != index)
	{
		pos++;
		a = a->next;
	}
	return (pos);
}

void	simple_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	size;
	int	i;

	size = stack_size(*a);
	i = 0;
	while (i < size - 1)
	{
		bring_to_top(a, index_position(*a, i), size - i, bench);
		pb(a, b, bench);
		i++;
	}
	while (*b)
		pa(a, b, bench);
}
