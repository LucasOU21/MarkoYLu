/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:38:12 by marko             #+#    #+#             */
/*   Updated: 2026/10/03 17:33:07 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//# include "libft.h"
# include "push_swap.h"

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


// TODO: the path to follow, one step at a time:
//   1. stack_a = parsing_args(argc, argv);   (src/parsing/)  <- you are here
//   2. if stack_a is already sorted -> free and return (print nothing)
//   3. measure disorder                       (src/disorder/)
//   4. pick + run a strategy                  (src/strats/)
//   5. if --bench: print op count to stderr   (src/bench/)
//   6. ft_nodeclear(&stack_a); ft_nodeclear(&stack_b);
//
// FOR NOW main() is a TEST of step 1 (parsing). Try:
//   make && ./push_swap 5 -3 0 12abc 2147483648 --bench
// Replace it with the real steps above once parsing works.

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	int		bench;

	// bez argumenata: ne radi nista i ne ispisuj nista
	if (argc < 2)
		return (0);
	// parse_args vec ispisuje Error i brise stek ako nesto ne valja
	if (!parse_args(argc, argv, &stack_a, &bench))
		return (1);
	// ovde ce ici sortiranje (koristi bench za statistiku)
	ft_nodeclear(&stack_a);
	return (0);
}