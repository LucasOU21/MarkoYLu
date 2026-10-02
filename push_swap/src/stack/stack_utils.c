/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:52:30 by luolivei          #+#    #+#             */
/*   Updated: 2026/09/25 17:52:31 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *ft_node_new(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
t_node *ft_nodelast(t_node *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void ft_nodeadd_back(t_node **lst, t_node *new_node)
{
    t_node *last_node;

    if (!lst || !new_node)
        return ;
    if (!*lst)
    {
        *lst = new_node;
        return ;
    }
    last_node = ft_nodelast(*lst);
    last_node->next = new_node;
}

void print_stack(t_node *stack, char *stack_name)
{
    printf("========== STACK %s ==========\n", stack_name);
    if (!stack)
    {
        printf("(empty)\n\n");
        return ;
    }
	int i = 1;
    while (stack)
    {
        printf("On position %d in stack A, is number: %d\n", i, stack->value);
        stack = stack->next;
		i++;
    }
    printf("========== END OF STACK A ==========\n\n");
}
