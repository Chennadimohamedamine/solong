/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:49:38 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/25 19:51:30 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_ens(char *s, char *s1)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] && s1[j] && s[i] == s1[j])
	{
		i++;
		j++;
	}
	return (s[i] - s1[j]);
}

int	all_collect(char **map)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return (c);
}

void	failure_mlx(t_solong *solong)
{
	freememory(solong->y, solong->map);
	mlx_destroy_window(solong->mlx, solong->mlx_win);
	perror("mlx is failure ");
	exit(1);
}

void	more_protaction(t_solong *solong)
{
	if (!solong->enms[0] || !solong->enms[1] || !solong->bg)
		failure_mlx(solong);
	else if (!solong->close || !solong->collect || !solong->open)
		failure_mlx(solong);
	else if (!solong->p[0] || !solong->p[1] || !solong->p[2] || !solong->p[3])
		failure_mlx(solong);
	else if (!solong->walls || !solong->p[3])
		failure_mlx(solong);
}
