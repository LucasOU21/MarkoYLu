/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:03 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/16 17:58:11 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_strategy_set(t_flags *f)
{
	return (f->simple || f->medium || f->complex || f->adaptive);
}

static int	set_strategy(t_flags *f, int *field)
{
	if (is_strategy_set(f))
		return (-1);
	*field = 1;
	return (1);
}

static int	parse_flag(char *arg, t_flags *f)
{
	if (ft_strncmp(arg, "--bench", 8) == 0)
	{
		if (f->bench)
			return (-1);
		f->bench = 1;
		return (1);
	}
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (set_strategy(f, &f->simple));
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (set_strategy(f, &f->medium));
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (set_strategy(f, &f->complex));
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (set_strategy(f, &f->adaptive));
	return (0);
}

int	parse_args(int argc, char **argv, t_node **stack, t_flags *flags)
{
	int	i;
	int	r;

	i = 1;
	*stack = NULL;
	ft_bzero(flags, sizeof(t_flags));
	while (i < argc)
	{
		r = parse_flag(argv[i], flags);
		if (r < 0)
			return (error_exit(stack));
		if (r == 0 && !add_numbers(stack, argv[i]))
			return (error_exit(stack));
		i++;
	}
	return (1);
}
