/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:51:24 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/09 19:09:17 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **s)
{
	t_node	*tmp;

	if (!*s || !(*s)->next)
		return ;
	tmp = *s;
	*s = (*s)->next;
	tmp->next = (*s)->next;
	(*s)->next = tmp;
}

void	sa(t_node **a, t_bench *bench)
{
	swap(a);
	write(1, "sa\n", 3);
	bench->sa++;
}

void	sb(t_node **b, t_bench *bench)
{
	swap(b);
	write(1, "sb\n", 3);
	bench->sb++;
}

void	ss(t_node **a, t_node **b, t_bench *bench)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	bench->ss++;
}
