/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:03 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/04 13:40:11 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"



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

// Obradi jedan argument koji NIJE flag:
// 1) ps_atoi proveri da je validan int (bez slova, bez overflow-a) i upise ga u num
// 2) has_duplicate proveri da broj vec nije u steku
// 3) napravi cvor i zakaci ga na kraj steka
// Vraca 1 ako je sve ok, 0 ako je bilo koja provera pala (ili malloc).
// Ne brise stek: to radi onaj ko je pozvao (parse_args preko error_exit).
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
static int	check_flag(char *arg, char *name, int *seen)
{
	if (ft_strncmp(arg, name, ft_strlen(name) + 1) != 0)
		return (0);
	if (*seen)
		return (-1);
	*seen = 1;
	return (1);
}

static int	parse_flag(char *arg, t_flags *f)
{
	int	r;

	r = check_flag(arg, "--bench", &f->bench);
	if (r == 0)
		r = check_flag(arg, "--simple", &f->simple);
	if (r == 0)
		r = check_flag(arg, "--medium", &f->medium);
	if (r == 0)
		r = check_flag(arg, "--complex", &f->complex);
	return (r);
}

// Prodje kroz sve argumente i napravi stek A.
int	parse_args(int argc, char **argv, t_node **stack, t_flags *flags)
{
	int	i;
	int	r;

	i = 1;
	*stack = NULL;
	flags->bench = 0;
	flags->simple = 0;
	flags->medium = 0;
	flags->complex = 0;
	while (i < argc)
	{
		r = parse_flag(argv[i], flags);
		if (r < 0)
			return (error_exit(stack));
		if (r == 0 && !add_number(stack, argv[i]))
			return (error_exit(stack));
		i++;
	}
	return (1);
}