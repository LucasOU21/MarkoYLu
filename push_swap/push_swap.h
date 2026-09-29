/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:20 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/29 17:06:40 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <stdlib.h>


typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
} t_stack;


void insertion_sort(int arr[], int N);
void selection_sort(int arr[], int N);
void chunk_sort(int arr[], int len, int num_chunks);
void sa(t_stack **a);
void sb(t_stack **a);
t_stack *create_node(int value);
void print_stack(t_stack *stack);
void push(t_stack **a, t_stack **b);
void rotate(t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **a);
void	rr(t_stack **a, t_stack **b);


#endif
