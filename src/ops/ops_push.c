/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:51:22 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/29 17:25:52 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO: push does not check if *a is empty -> crash (NULL->next) when
//       stack is empty. Add a guard like you did in sa().
// TODO: the subject needs pa / pb wrappers that call push() and print
//       "pa\n" / "pb\n" (same idea as ra/rb in ops_rotate.c).
void push(t_node **a, t_node **b) {
  t_node *tmp;

  tmp = *a;
  *a = (*a)->next;
  tmp->next = (*b);
  *b = tmp;
}
