/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:20 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/03 17:36:15 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// This is what the stack is made
typedef struct s_node {
  int value;           // the number from argv
  struct s_node *next; // the node below it, NULL for the bottom
} t_node;

/*A stack is basically a pointer to the top of the stack nothing else*/
// This is just a struct to have a pointer to both stacks, called context
typedef struct s_ps {
  t_node *a;
  t_node *b;
  int size;
  /*Still mising other info*/
  // TODO: bench needs a counter here later, e.g. int op_count;
} t_ps;

/* ---------- src/stack/ ---------- */
t_node *ft_node_new(int value);
t_node *ft_nodelast(t_node *lst);
void ft_nodeadd_back(t_node **lst, t_node *new_node);
void ft_nodedelone(t_node *node);
void ft_nodeclear(t_node **lst);
void print_stack(t_node *stack, char *stack_name);

/* ---------- src/parsing/ ---------- */
int	ps_atoi(const char *nptr );
int	parse_args(int argc, char **argv, t_node **stack_a, int *bench);
int	error_exit(t_node **stack);
/* ---------- src/ops/ ---------- */
void sa(t_node **a);
void sb(t_node **a);
void push(t_node **a, t_node **b);
void rotate(t_node **a);
void ra(t_node **a);
void rb(t_node **a);
void rr(t_node **a, t_node **b);
void rrotate(t_node **a);
// TODO: pa, pb, ss, rra, rrb, rrr when you write them

/* ---------- src/strats/ src/disorder/ src/bench/ ---------- */
// TODO: add prototypes as you write these files

// The array sorts (insertion/selection/chunk/radix) moved to practice/.
// They sort arrays, not stacks, so they are not part of the program.

#endif
