/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luolivei <luolivei@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 17:44:03 by luolivei          #+#    #+#             */
/*   Updated: 2026/10/03 15:45:34 by luolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Your own atoi from old_main.c. It's better than libft's ft_atoi for
// push_swap because it rejects "12abc" and catches int overflow.
// Renamed ft_atoi -> ps_atoi so it does not clash with the one in libft.
//
// TODO: BUG - it returns 0 for errors, so a real "0" from the user is
//       rejected too. Idea: return a status and give the number back
//       through a pointer:  int ps_atoi(const char *s, int *out);
// TODO: an empty string "" or just "-" currently returns 0 -> must be an error.
int	ps_atoi(const char *nptr)
{
	int	i;
	int	sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
		{
			sign = -1;
		}
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (result * 10) + (nptr[i] - '0');
		// also INT MIN MAX are from limits.h lib but dont worry i will change that to numbers
		if((result * sign) > INT_MAX || (result * sign) < INT_MIN) // checking here because it is stopping overflow
			return (0);
		i++;
	}
	if (nptr[i] != '\0')
		return(0);
	
	return (sign * result);
}
