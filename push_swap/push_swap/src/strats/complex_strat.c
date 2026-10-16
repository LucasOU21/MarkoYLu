/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_strat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:05 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/09 19:08:18 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	window_size(int n)
{
	return (int_sqrt(n) * 3 / 2);
}

static void	push_to_b(t_node **a, t_node **b, int k, t_bench *bench)
{
	int	i;

	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, bench);
			if ((*b)->next)
				rb(b, bench);
			i++;
		}
		else if ((*a)->index <= i + k)
		{
			pb(a, b, bench);
			i++;
		}
		else
			ra(a, bench);
	}
}

void	k_sort(t_node **a, t_node **b, t_bench *bench)
{
	push_to_b(a, b, window_size(stack_size(*a)), bench);
	while (*b)
	{
		max_to_top(b, bench);
		pa(a, b, bench);
	}
}
