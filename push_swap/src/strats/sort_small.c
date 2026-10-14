/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:07 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/14 21:00:41 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void sort_two(t_node **a, t_bench *bench)
{
    if ((*a)->value > (*a)->next->value)
        sa(a, bench);
}

void sort_three(t_node **a, t_bench *bench)
{
    int first = (*a)->value;
    int second = (*a)->next->value;
    int third = (*a)->next->next->value;

    if (first > second && second < third && first < third)
        sa(a, bench);
	else if (first > second && second > third)
    {
        sa(a, bench);
        rra(a, bench);
    }
    else if (first > second && second < third && first > third)
        ra(a, bench);
    else if (first < second && second > third && first < third)
    {
        rra(a, bench);
        sa(a, bench);
    }
    else if (first < second && second > third && first > third)
        rra(a, bench);
}

void sort_small(t_node **a, t_node **b, t_bench *bench)
{
    // Možeš pronaći najmanji element, prebaciti ga u B (pb), 
    // pa ponoviti dok ne ostane 3 elementa u A.
    while (stack_size(*a) > 3)
    {
        // Funkcija koja nalazi najmanji i stavlja ga na vrh stacka A, pa radi pb
        push_smallest_to_b(a, b, bench); 
    }
    
    // Sada su u A samo 3 broja, sortiraj ih:
    sort_three(a, bench);
    
    // Vrati elemente iz B nazad u A:
    while (stack_size(*b) > 0)
    {
        pa(a, b, bench);
    }
}


int get_min_position(t_node *a)
{
    int min_val;
    int min_pos;
    int i;

    if (!a)
        return (0);
    min_val = a->value;
    min_pos = 0;
    i = 0;
    while (a)
    {
        if (a->value < min_val)
        {
            min_val = a->value;
            min_pos = i;
        }
        a = a->next;
        i++;
    }
    return (min_pos);
}

// Funkcija koja nalazi najmanji, rotira stack da on dođe na vrh, i gurne ga u B
void push_smallest_to_b(t_node **a, t_node **b, t_bench *bench)
{
    int min_pos;
    int size;

    min_pos = get_min_position(*a);
    size = stack_size(*a);
    
    // Ako je najmanji element u prvoj polovini stacka, rotiramo naviše (ra)
    if (min_pos <= size / 2)
    {
        while (min_pos > 0)
        {
            ra(a, bench);
            min_pos--;
        }
    }
    // Ako je u drugoj polovini, rotiramo naniže (rra) da brže stigne na vrh
    else
    {
        while (min_pos < size)
        {
            rra(a, bench);
            min_pos++;
        }
    }
    // Kada je najmanji na vrhu, prebacimo ga u B
    pb(a, b, bench);
}