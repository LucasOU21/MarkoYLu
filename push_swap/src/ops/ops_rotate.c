/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:51:20 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/29 17:29:33 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: rotate does not check for an empty stack or a stack of 1 element.
void rotate(t_node **a) {
  t_node *last;

  last = *a;

  while (last->next != NULL)
    last = last->next;

  last->next = *a;
  *a = (*a)->next;
  last->next->next = NULL;
}

void ra(t_node **a) {
  rotate(a);
  write(1, "ra\n", 3);
}

void rb(t_node **a) {
  rotate(a);
  write(1, "rb\n", 3);
}
void rr(t_node **a, t_node **b) {
  rotate(a);
  rotate(b);
  write(1, "rr\n", 3);
}
