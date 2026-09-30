/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:52:30 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/25 17:52:31 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *node_new(int value) {

  t_node *node;

  node = malloc(sizeof(t_node));
  if (!node)
    return (NULL);
  node->value = value;
  node->index = -1;
  node->next = NULL;
  return (node);
}

void stack_add_back(t_node **stack, t_node *node) {
  t_node *last;

  if (!*stack) // empty stack: the node becomes the top
  {
    *stack = node;
    return;
  }
  last = *stack;
  while (last->next) // walk down to the bottom
    last = last->next;
  last->next = node;
}