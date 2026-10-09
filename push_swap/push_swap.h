/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:20 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/09 19:05:03 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

typedef struct s_flags
{
	int	bench;
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
}	t_flags;

// One counter per operation, for --bench.
// Every operation adds 1 to its own counter each time it runs.
typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_bench;

typedef struct s_ps
{
	t_node	*a;
	t_node	*b;
	int		size;
}	t_ps;

t_node	*ft_node_new(int value);
t_node	*ft_nodelast(t_node *lst);
void	ft_nodeadd_back(t_node **lst, t_node *new_node);
void	ft_nodedelone(t_node *node);
void	ft_nodeclear(t_node **lst);
void	assign_index(t_node *stack);
int		is_sorted(t_node *a);
int		stack_size(t_node *a);
int		ps_atoi(const char *s, int *out);
int		error_exit(t_node **stack);
int		has_duplicate(t_node *stack, int num);
int		add_number(t_node **stack, char *arg);
int		parse_args(int argc, char **argv, t_node **stack, t_flags *flags);
void	sa(t_node **a, t_bench *bench);
void	sb(t_node **b, t_bench *bench);
void	ss(t_node **a, t_node **b, t_bench *bench);
void	pa(t_node **a, t_node **b, t_bench *bench);
void	pb(t_node **a, t_node **b, t_bench *bench);
void	ra(t_node **a, t_bench *bench);
void	rb(t_node **b, t_bench *bench);
void	rr(t_node **a, t_node **b, t_bench *bench);
void	rra(t_node **a, t_bench *bench);
void	rrb(t_node **b, t_bench *bench);
void	rrr(t_node **a, t_node **b, t_bench *bench);
void	simple_sort(t_node **a, t_node **b, t_bench *bench);
void	medium_sort(t_node **a, t_node **b, t_bench *bench);
void	k_sort(t_node **a, t_node **b, t_bench *bench);
void	adaptive_sort(t_node **a, t_node **b, t_bench *bench);
double	disorder_m(t_node *a);
void	bench_init(t_bench *bench);
void	bench_print(t_bench *bench, double disorder, char *strategy);
void	bring_to_top(t_node **a, int pos, int size, t_bench *bench);
int		int_sqrt(int n);
int		max_position(t_node *b);
void	max_to_top(t_node **b, t_bench *bench);

#endif