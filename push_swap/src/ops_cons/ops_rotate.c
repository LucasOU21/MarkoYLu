/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:51:20 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/29 17:05:05 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
# include "push_swap.h"


t_stack *create_node(int value)
{
    t_stack *node;

    node = malloc(sizeof(t_stack));
    node->value = value;
    node->next = NULL;
    return (node);
}

void print_stack(t_stack *stack)
{
    while (stack != NULL)
    {
        printf("%d\n", stack->value);
        stack = stack->next;
    }
}

/*void sa(t_stack **a)
{
    t_stack *tmp;

    if (!*a || !(*a)->next)
        return;
    tmp = *a;
	    printf("after tmp = *a: tmp->value = %d\n", tmp->value);

    *a = (*a)->next;
	printf("after *a = (*a)->next: (*a)->value = %d\n", (*a)->value);

    tmp->next = (*a)->next;
	printf("after tmp->next = ...: tmp->next->value = %d\n", tmp->next->value);

    (*a)->next = tmp;
	    printf("after (*a)->next = tmp: (*a)->next->value = %d\n", (*a)->next->value);

}*/


void rotate(t_stack **a)
{
    t_stack *last;
	
	last = *a;

	while (last->next != NULL)
		last = last->next;
		
	last->next = *a;
	*a = (*a)->next;
	last->next->next = NULL;
}

void	ra(t_stack **a)
{
	stack_rotation(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **a)
{
	stack_rotation(a);
	write(1, "rb\n", 3);
}
void	rr(t_stack **a, t_stack **b)
{
	stack_rotation(a);
	stack_rotation(b);
	write(1, "rr\n", 3);
}

int main(void)
{
    // ručno pravimo stack 3 -> 2 -> 1, bez argumenata, da bude jednostavno
    t_stack *a;
	t_stack *b; // making stack b 

    a = create_node(3);
	b = create_node(3);

	
	b->next = create_node(2);
	b->next->next = create_node(1);
	
    a->next = create_node(2);
    a->next->next = create_node(1);

    printf("--- Before rotate ---\n");
    print_stack(a);
	//print_stack(b);


    //sa(&a);
	//sa(&b);
	//push(&a, &b);
	rotate(&a);

    printf("--- A stak after rotate ---\n\n");
    print_stack(a);
	//printf("--- B stack after rotate ---\n");
	//print_stack(b);

    return (0);
}