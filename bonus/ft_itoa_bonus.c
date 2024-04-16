/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:13:52 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/16 17:14:55 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	coutnumber(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*r;
	int		len;
	int		c;

	c = 0;
	if (n < 0)
	{
		c = 1;
		n *= -1;
	}
	len = coutnumber(n) + c;
	r = (char *)malloc(len + 1);
	if (r == NULL)
		return (NULL);
	r[len] = 0;
	while (len > 0)
	{
		r[len-- - 1] = (n % 10) + '0';
		n = n / 10;
	}
	if (c == 1)
		r[0] = '-';
	return (r);
}