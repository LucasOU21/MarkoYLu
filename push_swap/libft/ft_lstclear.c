/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:53:05 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/09/24 10:53:05 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp_next_node;

	if (lst == NULL || *lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		temp_next_node = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp_next_node;
	}
	*lst = NULL;
}

// Here I am just deleting no one car or box, but whole list. 
// declering new temporary variable  
// to hold next node, so I can delete previous ones,
// and following up to NULL value. 
// at the end, asigning NULL to
//  *lst (address of first car in memory)