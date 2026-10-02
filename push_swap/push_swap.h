/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:20 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/02 18:55:41 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>


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
}

void insertion_sort(int arr[], int N);
void selection_sort(int arr[], int N);
void chunk_sort(int arr[], int len, int num_chunks);
void sa(t_stack **a);
void sb(t_stack **a);
t_stack *create_node(int value);
void print_stack(t_stack *stack);
void push(t_stack **a, t_stack **b);
void rotate(t_stack **a);
void ra(t_stack **a);
void rb(t_stack **a);
void rr(t_stack **a, t_stack **b);
int	parsing_args(int argc, char **argv);

#endif
