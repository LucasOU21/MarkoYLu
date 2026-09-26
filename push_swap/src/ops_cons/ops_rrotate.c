/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:51:18 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/25 19:10:56 by mmitrovi         ###   ########.fr       */
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


n3 n2 n1 

tmp = *a;      tmp = n3 
*a = (*a)->next;     n3 = n2
tmp->next = (*a)->next;   n3 = n1 
(*a)->next = tmp;        n2 = n3 

a = 2 point to n

a