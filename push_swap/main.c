/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:38:12 by marko             #+#    #+#             */
/*   Updated: 2026/10/15 19:58:50 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*get_strategy(t_flags *flags, double disorder, int size)
{
	if (flags->simple)
		return ("Simple / O(n^2)");
	if (flags->medium)
		return ("Medium / O(n sqrt(n))");
	if (flags->complex)
		return ("Complex / O(n log n)");
	if (size >= 2 && size <= 5)
		return ("Adaptive / small sort (n <= 5)");
	if (size > 100 || disorder >= 0.5)
		return ("Adaptive / O(n log n)");
	if (disorder < 0.2)
		return ("Adaptive / O(n)");
	return ("Adaptive / O(n sqrt(n))");
}

static void	run_sort(t_node **a, t_node **b, t_flags *flags, t_bench *bench)
{
	int size;

	if(is_sorted(*a))
		return ;
	size = stack_size(*a);
if (flags && flags->simple)
    {
        simple_sort(a, b, bench);
        return ;
    }
    else if (flags && flags->medium)
    {
        medium_sort(a, b, bench);
        return ;
    }
    else if (flags && flags->complex)
    {
        k_sort(a, b, bench);
        return ;
    }

    if (size == 2)
        sort_two(a, bench);
    else if (size == 3)
        sort_three(a, bench);
    else if (size == 4 || size == 5)
        sort_small(a, b, bench);
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
		bench_print(&bench, disorder,
			get_strategy(&flags, disorder, stack_size(a)));
	ft_nodeclear(&a);
	ft_nodeclear(&b);
	return (0);
}
