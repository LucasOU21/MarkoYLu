/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:51:18 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/01 12:17:10 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rrotate(t_node **s)
{
	t_node	*last;
	t_node	*prev;

	if (!*s || !(*s)->next)
		return ;
	prev = *s;
	last = (*s)->next;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *s;
	*s = last;
}

void	rra(t_node **a, t_bench *bench)
{
	rrotate(a);
	write(1, "rra\n", 4);
	bench->rra++;
}

void	rrb(t_node **b, t_bench *bench)
{
	rrotate(b);
	write(1, "rrb\n", 4);
	bench->rrb++;
}

void	rrr(t_node **a, t_node **b, t_bench *bench)
{
	rrotate(a);
	rrotate(b);
	write(1, "rrr\n", 4);
	bench->rrr++;
}
