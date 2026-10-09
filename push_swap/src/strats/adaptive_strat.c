/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_strat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:07 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/09 16:58:08 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void adaptive_sort(t_node **a, t_node **b, t_bench *bench)
{
    double disorder;

    // Prvo izračunamo nered
    disorder = disorder_m(*a);

    // Biramo algoritam na osnovu uslova zadatka
    if (disorder < 0.2)
    {
        // Low disorder: O(n)
        simple_sort(a, b, bench);
    }
    else if (disorder < 0.5)
    {
        // Medium disorder: O(n*sqrt(n)) -> Naš Chunk Sort
        medium_strat(a, b, bench);
    }
    else
    {
        // High disorder: O(n log n) -> Radix Sort ili Quick/Merge Sort za Push_swap
        radix_sort(a, b, bench);
    }
}


/*Custom adaptive algorithm (learner’s design): Design an adaptive strategy
that selects different internal methods depending on the measured disorder. You
are not constrained to any specific named algorithm; the internal techniques are
entirely up to you. However, your design must respect the following complexity
targets per regime (in the Push_swap operation model):
Low disorder: if disorder < 0.2, your chosen method must run in O(n) time.
Medium disorder: if 0.2 ≤ disorder < 0.5, your chosen method must run in
O(n
√
n) time.
High disorder: if disorder ≥ 0.5, your chosen method must run in O(n log n)
time.
You must document in your repository (e.g., README.md) the rationale for your
thresholds, the internal techniques used in each regime, and a brief complexity
argument (upper bounds) for time and space within the Push_swap model.*/


/*THE ABOVE BASICALLY MEANS

we have to create a algo to determine which method we will need to use depending from the user input
it determine what stratergy it will use from simple to complex.*/