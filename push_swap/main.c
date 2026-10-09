/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:38:12 by marko             #+#    #+#             */
/*   Updated: 2026/10/09 19:25:18 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_strategy(t_flags *flags, double disorder)
{
	if (flags->simple)
		return ("Simple / O(n^2)");
	if (flags->medium)
		return ("Medium / O(n sqrt(n))");
	if (flags->complex)
		return ("Complex / O(n log n)");
	if (disorder < 0.2)
		return ("Adaptive / O(n)");
	if (disorder < 0.5)
		return ("Adaptive / O(n sqrt(n))");
	return ("Adaptive / O(n log n)");
}

static void	run_sort(t_node **a, t_node **b, t_flags *flags, t_bench *bench)
{
	if (is_sorted(*a))
		return ;
	if (flags->simple)
		simple_sort(a, b, bench);
	else if (flags->medium)
		medium_sort(a, b, bench);
	else if (flags->complex)
		k_sort(a, b, bench);
	else
		adaptive_sort(a, b, bench);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	t_flags	flags;
	t_bench	bench;
	double	disorder;

	if (argc < 2)
		return (0);
	b = NULL;
	if (!parse_args(argc, argv, &a, &flags))
		return (1);
	bench_init(&bench);
	assign_index(a);
	disorder = disorder_m(a);
	run_sort(&a, &b, &flags, &bench);
	if (flags.bench)
		bench_print(&bench, disorder, get_strategy(&flags, disorder));
	ft_nodeclear(&a);
	ft_nodeclear(&b);
	return (0);
}
