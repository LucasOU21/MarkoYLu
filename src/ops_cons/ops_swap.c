/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:51:24 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/26 14:43:53 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void sa(t_stack **a)
{
    t_stack *tmp;

    if (!*a || !(*a)->next)   // ako stack ima 0 ili 1 element, nema šta da se menja
        return;

    tmp = *a;                 // tmp čuva prvi element
    *a = (*a)->next;          // vrh stack-a postaje DRUGI element
    tmp->next = (*a)->next;   // stari prvi element sad pokazuje na TREĆI element
    (*a)->next = tmp;         // novi vrh (bivši drugi) sad pokazuje na bivši prvi
}

void sb(t_stack **a)
{
    t_stack *tmp;

    if (!*a || !(*a)->next)   // ako stack ima 0 ili 1 element, nema šta da se menja
        return;

    tmp = *a;                 // tmp čuva prvi element
    *a = (*a)->next;          // vrh stack-a postaje DRUGI element
    tmp->next = (*a)->next;   // stari prvi element sad pokazuje na TREĆI element
    (*a)->next = tmp;         // novi vrh (bivši drugi) sad pokazuje na bivši prvi
}

