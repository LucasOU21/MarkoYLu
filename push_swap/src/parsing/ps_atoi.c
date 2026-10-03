/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmitrovi <mmitrovi@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:03 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/03 18:41:45 by mmitrovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	read_sign(const char *s, int *i)
{
	int	sign;

	sign = 1;
	while (s[*i] == ' ' || (s[*i] >= '\t' && s[*i] <= '\r'))
		(*i)++;
	if (s[*i] == '-' || s[*i] == '+')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ps_atoi(const char *s, int *out)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = read_sign(s, &i);
	result = 0;
	if (s[i] < '0' || s[i] > '9')
		return (0);
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
		i++;
	}
	if (s[i] != '\0')
		return (0);
	*out = (int)(result * sign);
	return (1);
}