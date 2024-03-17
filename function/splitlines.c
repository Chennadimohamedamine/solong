/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   splitlines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:46:11 by mochenna          #+#    #+#             */
/*   Updated: 2024/03/16 21:59:17 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	countletter(char *s, char l)
{
	int	v[3];

	v[0] = 0;
	v[1] = 0;
	v[2] = 0;
	while (s[v[1]])
	{
		if (s[v[1]] == l)
			v[2] = 0;
		else if (!v[2])
		{
			v[2] = 1;
			v[0]++;
		}
		v[1]++;
	}
	return (v[0]);
}

char	*get_string(char *s, int *s1, char l)
{
	int		i;
	int		c;
	char	*r;

	i = 0;
	c = 0;
	while (s[i] == l)
		i++;
	while (s[i] != l && s[i])
	{
		i++;
		c++;
	}
	r = malloc(c + 1);
	i = 0;
	c = 0;
	while (s[i] == l)
		i++;
	while (s[i] != l && s[i])
		r[c++] = s[i++];
	r[c] = 0;
	*s1 = i;
	return (r);
}

char	**splitnewline(char *s, int *len, char l)
{
	char	**r;
	int		i;
	int		g;
	int		c;

	c = 0;
	i = 0;
	g = countletter(s, l);
	r = (char **)malloc((g + 1) * sizeof(char *));
	while (i < g)
	{
		r[i] = get_string(s, &c, l);
		s += c;
		i++;
	}
	r[g] = 0;
	*len = g;
	return (r);
}