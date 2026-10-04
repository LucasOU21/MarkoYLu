/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 13:46:15 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/10/04 13:48:49 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Svakom čvoru upiše rang (index): koliko brojeva u steku je MANJE od njega.
// Primer: vrednosti 42 -5 1000 7 0  ->  indexi 3 0 4 2 1
// Najmanji broj dobija 0, najveći n-1. Radix sort radi nad ovim, ne nad value.
// Ne menja value ni redosled čvorova, samo popunjava polje index.
// Ne treba t_node **, jer ne menjamo koji je čvor na vrhu.
void	assign_index(t_node *stack)
{
	t_node	*cur;
	t_node	*other;
	int		rank;

	cur = stack;
	while (cur)
	{
		rank = 0;
		other = stack;                 // za svaki cur krećemo od početka
		while (other)
		{
			if (other->value < cur->value)
				rank++;                // jedan manji broj više
			other = other->next;
		}
		cur->index = rank;             // upiši rang u čvor
		cur = cur->next;
	}
}