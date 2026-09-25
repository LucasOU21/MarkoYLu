/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marko <emarkomitrovic@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:49:01 by marko             #+#    #+#             */
/*   Updated: 2026/08/21 18:52:01 by marko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;

	num = n;
	len = get_len(num);
	str = malloc ((len + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		len--;
		str[len] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}

/*

int main()
{
	int number = -555;
	char *string;

	string = ft_itoa(number);

	printf("Now printing characters %s \n", string);

	free(string);
	return(0);


} 
	*/