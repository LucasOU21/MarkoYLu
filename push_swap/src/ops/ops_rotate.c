/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:51:20 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/05 17:10:16 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **s)
{
	t_node	*first;
	t_node	*last;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	*s = first->next;
	last = ft_nodelast(*s);
	last->next = first;
	first->next = NULL;
}

void	ra(t_node **a, t_bench *bench)
{
	rotate(a);
	write(1, "ra\n", 3);
	bench->ops[OP_RA]++;        // NOVO
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
