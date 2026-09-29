/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_strat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:07 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/29 16:31:45 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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