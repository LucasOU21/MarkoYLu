/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:03 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/09 18:28:14 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (r == 0)
		r = check_flag(arg, "--adaptive", &f->adaptive);
	return (r);
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
