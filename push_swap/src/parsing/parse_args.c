/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:03 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/03 17:25:09 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// Same logic as main() in practice/old_main.c (the commented-out array test
// that was here is still in practice/old_main.c and practice/chunk_sort.c).
//
// TODO: BUG (leak) - stack_a is built here and then lost when the function
//       returns. Return it instead:  t_node *parsing_args(int argc, char **argv)
//       (and return NULL on error after ft_nodeclear(&stack_a)).
// TODO: use your ps_atoi (src/parsing/ps_atoi.c) instead of libft's ft_atoi,
//       which accepts "12abc" and overflows silently.
// TODO: an invalid number must not be skipped - the subject wants "Error\n"
//       on stderr and exit. Put that in error.c.
// TODO: check for duplicate numbers (also an "Error\n" case).
// TODO: on malloc fail, call ft_nodeclear(&stack_a) like old_main.c does.
// TODO: remove the debug printf's once it works (only ops go to stdout).
// TODO: argv like "3 2 1" (one string) - decide if you support it (ft_split).

// Obradi jedan argument koji NIJE flag:
// 1) ps_atoi proveri da je validan int (bez slova, bez overflow-a) i upise ga u num
// 2) has_duplicate proveri da broj vec nije u steku
// 3) napravi cvor i zakaci ga na kraj steka
// Vraca 1 ako je sve ok, 0 ako je bilo koja provera pala (ili malloc).
// Ne brise stek: to radi onaj ko je pozvao (parse_args preko error_exit).
static int	add_number(t_node **stack, char *arg)
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


// Prodje kroz sve argumente i napravi stek A.
// stack_a: izlaz, pokazivac na glavu steka (zato **, da main dobije rezultat)
// bench:   izlaz, 1 ako je --bench zadat, inace 0
// Vraca 1 pri uspehu, 0 pri gresci (tada je stek vec oslobodjen i
// "Error\n" ispisan, main samo treba da vrati 1).
int	parse_args(int argc, char **argv, t_node **stack_a, int *bench)
{
	int	i;

	i = 1;
	*stack_a = NULL;
	*bench = 0;
	while (i < argc)
	{
		// poredimo 8 znakova: "--bench" (7) + '\0', pa "--benchX" ne prolazi
		if (ft_strncmp(argv[i], "--bench", 8) == 0)
		{
			// drugi --bench je greska
			if (*bench)
				return (error_exit(stack_a));
			*bench = 1;
		}
		// sve ostalo mora biti validan broj
		else if (!add_number(stack_a, argv[i]))
			return (error_exit(stack_a));
		i++;
	}
	return (1);
}