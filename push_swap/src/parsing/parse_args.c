/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:03 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/15 19:49:45 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int	check_flag(char *arg, char *name, int *seen)
{
	if (ft_strncmp(arg, name, ft_strlen(name) + 1) != 0)
		return (0);
	if (*seen)
		return (-1);
	*seen = 1;
	return (1);
}*/

static int is_strategy_set(t_flags *f)
{
    return (f->simple || f->medium || f->complex || f->adaptive);
}

static int parse_flag(char *arg, t_flags *f)
{
    if (ft_strncmp(arg, "--bench", 7) == 0)
    {
        if (f->bench)
            return (-1);
        f->bench = 1;
        return (1);
    }
    if (ft_strncmp(arg, "--simple", 9) == 0)
    {
        if (is_strategy_set(f))
            return (-1);
        f->simple = 1;
        return (1);
    }
    if (ft_strncmp(arg, "--medium", 9) == 0)
    {
        if (is_strategy_set(f))
            return (-1);
        f->medium = 1;
        return (1);
    }
    if (ft_strncmp(arg, "--complex", 9) == 0)
    {
        if (is_strategy_set(f))
            return (-1);
        f->complex = 1;
        return (1);
    }
    if (ft_strncmp(arg, "--adaptive", 11) == 0)
    {
        if (is_strategy_set(f))
            return (-1);
        f->adaptive = 1;
        return (1);
    }
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
		if (r == 0 && !add_number(stack, argv[i]))
			return (error_exit(stack));
		i++;
	}
	return (1);
}
