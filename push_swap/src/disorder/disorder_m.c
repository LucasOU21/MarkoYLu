/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_m.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:49:38 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/25 17:49:39 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double disorder_m(t_node *a) {
  t_node *current;
  t_node *other;
  long mistakes;
  long total_pairs;

  mistakes = 0;
  total_pairs = 0;
  current = a;
  while (current) {
    other = current->next;
    while (other) {
      total_pairs++;
      if (current->value > other->value)
        mistakes++;
      other = other->next;
    }
    current = current->next;
  }
  if (total_pairs == 0)
    return (0.0);
  return ((double)mistakes / (double)total_pairs);
}

/*My understanding of the function is that it returns a number between 0 and 1,
thats why we use double so we can have a percentage of how sorted the stack is
if 0 it means the stack is sorted, if 1 it means its fully fucked up and needs
help fixing it

so while(current) keeps going until theres nothing basically NULL

other = current->next here to look at the next nodes so we can compare it with
current

while (other) if theres a nodes below current then we add 1 to total_pairs
and if current is bigger than other we add 1 to mistakes
then we move to the next node for other

then we move to the next node for current so we can compare it with all the
nodes below it again.

a little safe guard so if theres 0 pairs it returns 0.0.

then we return doubles casted for the percentages.

*/