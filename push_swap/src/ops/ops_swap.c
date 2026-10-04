/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:51:24 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/29 17:39:04 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_node **s)
{
	t_node	*tmp;

	if (!*s || !(*s)->next)   // ako stack ima 0 ili 1 element, nema šta da se menja
		return ;
	tmp = *s;                 // tmp čuva prvi element
	*s = (*s)->next;          // vrh stack-a postaje DRUGI element
	tmp->next = (*s)->next;   // stari prvi element sad pokazuje na TREĆI element
	(*s)->next = tmp;         // novi vrh (bivši drugi) sad pokazuje na bivši prvi
}

void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
