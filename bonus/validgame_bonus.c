/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validgame_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochenna <mochenna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:46:54 by mochenna          #+#    #+#             */
/*   Updated: 2024/04/28 00:06:49 by mochenna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	get_positon(char **s, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'P')
			{
				*x = 1;
				break ;
			}
			j++;
		}
		if (*x == 1)
			break ;
		i++;
	}
	*x = i;
	*y = j;
}

int	check_path(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] != '1' && s[i][j] != 'F' && s[i][j] != '0'
				&& s[i][j] != 'E' && s[i][j] != 'N')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	flood_fill(char **map, int y, int x, int row)
{
	if (y < 0 || y >= ft_strlen(map[0]) || x < 0 || x >= row
		|| map[x][y] == '1' || map[x][y] == 'F' || map[x][y] == 'E')
		return ;
	map[x][y] = 'F';
	flood_fill(map, y - 1, x, row);
	flood_fill(map, y + 1, x, row);
	flood_fill(map, y, x - 1, row);
	flood_fill(map, y, x + 1, row);
}

void	invalid_game(char *s1)
{
	int		i;
	int		p[2];
	char	**map;

	i = 0;
	map = splitnewline(s1, &i, '\n');
	p[0] = 0;
	p[1] = 0;
	get_positon(map, &p[0], &p[1]);
	flood_fill(map, p[1], p[0], i);
	if (check_path(map))
		error_handling(s1, map, i);
	freememory(i, map);
}
