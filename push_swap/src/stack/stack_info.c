/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 14:21:22 by mmitrovi          #+#    #+#             */
/*   Updated: 2026/10/04 14:27:51 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Vraca 1 ako je stek sortiran rastuce od vrha prema dnu, inace 0.
// Prazan stek i stek sa 1 elementom su sortirani (nema sta da se poredi).
// Poredi value (ne index), ali bi radilo i sa index jer je redosled isti.
int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)   // prvi par van redosleda -> nije sortiran
			return (0);
		a = a->next;
	}
	return (1);
}

// Vraca broj cvorova u steku. Prazan stek vraca 0.
// Radix ovo treba da zna koliko bita da obradi i koliko puta da ponovi petlju.
int	stack_size(t_node *a)
{
	int	n;

	n = 0;
	while (a)
	{
		n++;
		a = a->next;
	}
	return (n);
}