/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_strat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:00:00 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/09 19:04:13 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	medium_sort(t_node **a, t_node **b, t_bench *bench)
{
	int	chunk;
	int	limit;
	int	pushed;

	chunk = int_sqrt(stack_size(*a));
	limit = chunk;
	pushed = 0;
	while (*a)
	{
		if ((*a)->index < limit)
		{
			pb(a, b, bench);
			pushed++;
			if (pushed == limit)
				limit += chunk;
		}
		else
			ra(a, bench);
	}
	while (*b)
	{
		max_to_top(b, bench);
		pa(a, b, bench);
	}
}
