/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:07 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/16 18:13:00 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **a, t_bench *bench)
{
	if ((*a)->value > (*a)->next->value)
		sa(a, bench);
}

void	sort_three(t_node **a, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, bench);
	else if (first > second && second > third)
	{
		sa(a, bench);
		rra(a, bench);
	}
	else if (first > second && second < third && first > third)
		ra(a, bench);
	else if (first < second && second > third && first < third)
	{
		rra(a, bench);
		sa(a, bench);
	}
	else if (first < second && second > third && first > third)
		rra(a, bench);
}

void	sort_small(t_node **a, t_node **b, t_bench *bench)
{
	while (stack_size(*a) > 3)
	{
		push_smallest_to_b(a, b, bench);
	}
	sort_three(a, bench);
	while (stack_size(*b) > 0)
	{
		pa(a, b, bench);
	}
}

int	get_min_position(t_node *a)
{
	int	min_val;
	int	min_pos;
	int	i;

	if (!a)
		return (0);
	min_val = a->value;
	min_pos = 0;
	i = 0;
	while (a)
	{
		if (a->value < min_val)
		{
			min_val = a->value;
			min_pos = i;
		}
		a = a->next;
		i++;
	}
	return (min_pos);
}

void	push_smallest_to_b(t_node **a, t_node **b, t_bench *bench)
{
	int	min_pos;
	int	size;

	min_pos = get_min_position(*a);
	size = stack_size(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(a, bench);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			rra(a, bench);
			min_pos++;
		}
	}
	pb(a, b, bench);
}
