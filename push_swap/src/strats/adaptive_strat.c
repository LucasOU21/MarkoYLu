/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_strat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:07 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/09 18:35:01 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_node **a, t_node **b, t_bench *bench)
{
	double	disorder;

	disorder = disorder_m(*a);
	if (disorder < 0.2)
		simple_sort(a, b, bench);
	else if (disorder < 0.5)
		medium_sort(a, b, bench);
	else
		k_sort(a, b, bench);
}
