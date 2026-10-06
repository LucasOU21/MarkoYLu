/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:51:22 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/05 17:10:03 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void push(t_node **src, t_node **dst) {
  t_node *tmp;

  if (!*src)
    return;
  tmp = *src;
  *src = (*src)->next;
  tmp->next = *dst;
  *dst = tmp;
}


void	pa(t_node **a, t_node **b, t_bench *bench)
{
	push(b, a);
	write(1, "pa\n", 3);
	bench->pa++;
}

void	pb(t_node **a, t_node **b, t_bench *bench)
{
	push(a, b);
	write(1, "pb\n", 3);
	bench->pb++;
}

/* OLD PA i PB

void pa(t_node **a, t_node **b) {
  push(b, a);
  write(1, "pa\n", 3);
}

void pb(t_node **a, t_node **b) {
  push(a, b);
  write(1, "pb\n", 3);
} */