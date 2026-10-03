/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 20:38:12 by marko             #+#    #+#             */
/*   Updated: 2026/10/03 15:02:41 by luolivei         ###   ########.fr       */
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
int main(int argc, char **argv)
{
	int	i;

	printf("====== ps_atoi on each argument ======\n");
	i = 1;
	while (i < argc)
	{
		printf("  \"%s\"  ->  %d\n", argv[i], ps_atoi(argv[i]));
		i++;
	}
	printf("\n====== parsing_args() ======\n");
	printf("parsing_args returned %d\n", parsing_args(argc, argv));
	return (0);
}