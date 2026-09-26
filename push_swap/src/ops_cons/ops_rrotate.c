/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:51:18 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/26 19:38:10 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:51:20 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/26 17:57:34 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
} t_stack;

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


void rrotate(t_stack **a)
{
    t_stack *last;
	t_stack *prev;
	
	last = *a;
	prev = (*a)->next;

	while (last->next != NULL)
		last = last->next;

	last->next = *a;
	last->next->next = NULL;
	*a = prev;
}
/*

========================= LUCAS ==================== READ THIS =====================

so I saved first and second position before the loop 
after loop i harcoded last next to be a (INSTED OF NULL)
and I hardcoded last next next to be the NULL 

then I just addedd to first position of our list previusly saved second position! 
I dont know who the did it becuase theu did it differently 

*/

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
	rrotate(&a);

    printf("--- A stak after rotate ---\n\n");
    print_stack(a);
	//printf("--- B stack after rotate ---\n");
	//print_stack(b);

    return (0);
}