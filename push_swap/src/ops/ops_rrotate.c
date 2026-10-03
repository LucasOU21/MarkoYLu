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

// TODO: BUG - this does the SAME thing as rotate() (top goes to bottom).
//       Reverse rotate must do the opposite: the LAST node becomes the top.
//       Hint: walk to the node BEFORE the last, set its next to NULL,
//       and make the old last point to *a.
// TODO: add rra / rrb / rrr wrappers that print "rra\n" / "rrb\n" / "rrr\n".
void rrotate(t_node **a)
{
    t_node *last;
	t_node *prev;
	
	last = *a;
	prev = (*a)->next;

	while (last->next != NULL)
		last = last->next;

	last->next = *a;
	last->next->next = NULL;
	*a = prev;
}
/*

========================= LUCAS ==================== READ THIS =====================

so I saved first and second position before the loop 
after loop i harcoded last next to be a (INSTED OF NULL)
and I hardcoded last next next to be the NULL 

then I just addedd to first position of our list previusly saved second position! 
I dont know who the did it becuase theu did it differently 

*/
