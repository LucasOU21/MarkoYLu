/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pase_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:19:25 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/09 18:19:33 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(t_node **stack)
{
	if (stack)
		ft_nodeclear(stack);
	write(2, "Error\n", 6);
	return (0);
}

int	has_duplicate(t_node *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	add_number(t_node **stack, char *arg)
{
	int		num;
	t_node	*new_node;

	if (!ps_atoi(arg, &num) || has_duplicate(*stack, num))
		return (0);
	new_node = ft_node_new(num);
	if (!new_node)
		return (0);
	ft_nodeadd_back(stack, new_node);
	return (1);
}
