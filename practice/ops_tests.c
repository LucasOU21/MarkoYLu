/*
** Your test code for the operations, collected from ops_push.c, ops_rotate.c
** and ops_rrotate.c (it was copy-pasted 3 times there, which caused
** "multiple definition" errors when building everything together).
** This file is NOT part of the Makefile - it's your playground.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

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

/* debug version of sa with prints, from ops_push.c / ops_rotate.c */
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

/*
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

    printf("--- Before push ---\n");
    print_stack(a);
	print_stack(b);


    //sa(&a);
	//sa(&b);
	push(&a, &b);
	//rotate(&a);
	//rrotate(&a);

    printf("--- A stak after push ---\n");
    print_stack(a);
	printf("--- B stack after push ---\n");
	print_stack(b);

    return (0);
}*/
