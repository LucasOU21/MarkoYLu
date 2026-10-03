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

// TODO: sa and sb are the same code twice. Make one swap(t_node **s) and
//       sa / sb / ss wrappers that call it and print "sa", "sb", "ss"
//       (same pattern as rotate + ra/rb/rr).

void sa(t_node **a)
{
    t_node *tmp;

    if (!*a || !(*a)->next)   // ako stack ima 0 ili 1 element, nema šta da se menja
        return;

    tmp = *a;                 // tmp čuva prvi element
    *a = (*a)->next;          // vrh stack-a postaje DRUGI element
    tmp->next = (*a)->next;   // stari prvi element sad pokazuje na TREĆI element
    (*a)->next = tmp;         // novi vrh (bivši drugi) sad pokazuje na bivši prvi
}

void sb(t_node **a)
{
    t_node *tmp;

    if (!*a || !(*a)->next)   // ako stack ima 0 ili 1 element, nema šta da se menja
        return;

    tmp = *a;                 // tmp čuva prvi element
    *a = (*a)->next;          // vrh stack-a postaje DRUGI element
    tmp->next = (*a)->next;   // stari prvi element sad pokazuje na TREĆI element
    (*a)->next = tmp;         // novi vrh (bivši drugi) sad pokazuje na bivši prvi
}

